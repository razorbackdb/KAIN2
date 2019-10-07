#include "THISDUST.H"
#include "RAZIEL.H"


// decompiled code
// original method signature: 
// void /*$ra*/ InitStates(struct _Instance *PlayerInstance /*$s2*/)
 // line 186, offset 0x800a7090
	/* begin block 1 */
		// Start line: 187
		// Start offset: 0x800A7090
		// Variables:
	// 		unsigned char i; // $s1

		/* begin block 1.1 */
			// Start line: 216
			// Start offset: 0x800A7140
			// Variables:
		// 		struct _G2AnimSection_Type *animSection; // $v0
		/* end block 1.1 */
		// End offset: 0x800A7140
		// End Line: 217
	/* end block 1 */
	// End offset: 0x800A71B8
	// End Line: 228

	/* begin block 2 */
		// Start line: 372
	/* end block 2 */
	// End Line: 373

	/* begin block 3 */
		// Start line: 376
	/* end block 3 */
	// End Line: 377

void PadGetState(_Instance *PlayerInstance)

{
  _G2AnimSection_Type *p_Var1;
  u_int uVar2;
  byte bVar3;
  
  if (Raziel.footPrint == 0) {
    Raziel.footPrint = (int)PlayerInstance->object;
  }
  *(__CharacterState **)&PlayerInstance->InstanceState = &Raziel.State;
  PlayerData = (RazielData *)PlayerInstance->data;
  bVar3 = 0;
  Raziel.State.CharacterInstance = PlayerInstance;
  G2EmulationInstanceSetTotalSections(&Raziel.State,3);
  G2EmulationInstanceSetStartAndEndSegment(&Raziel.State,0,0,0xd);
  G2EmulationInstanceSetStartAndEndSegment(&Raziel.State,1,0xe,0x31);
  G2EmulationInstanceSetStartAndEndSegment(&Raziel.State,2,0x32,0x41);
  uVar2 = 0;
  do {
    p_Var1 = (PlayerInstance->anim).section + uVar2;
    p_Var1->callback = RazielAnimCallback;
    p_Var1->callbackData = (void *)0x0;
    Raziel.State.SectionList[uVar2].Process = StateHandlerPickupObject;
    EnMessageQueue(&Raziel.State.SectionList[uVar2].Event);
    EnMessageQueue(&Raziel.State.SectionList[uVar2].Defer);
    bVar3 = bVar3 + 1;
    uVar2 = (u_int)bVar3;
  } while (bVar3 < 3);
  _G2AnimSection_InterpStateToQuat((PlayerInstance->anim).section,&razInterpInfo);
  _G2AnimSection_InterpStateToQuat
            ((PlayerInstance->anim).section + 1,&_G2AnimInterpInfo_Type_800d5d10);
  _G2AnimSection_InterpStateToQuat
            ((PlayerInstance->anim).section + 2,&_G2AnimInterpInfo_Type_800d5d1c);
  Raziel.Mode = 1;
  gameTrackerX.debugFlags2 = gameTrackerX.debugFlags2 | 0x800;
  InitHealthSystem();
  debugRazielFlags1 = 0x1000000;
  Raziel.GlyphManaMax = 0x14;
  Raziel.Senses.EngagedList = &EngagedList;
  Raziel.constrictData = &constrictData;
  Raziel.dropOffHeight = 0x100;
  Raziel.GlyphManaBalls = 0;
  Raziel.Abilities = 0;
  Raziel.RotationSegment = 0;
  Raziel.extraRot.x = 0;
  Raziel.Senses.EngagedMask = 0;
  Raziel.idleInstance = (_Instance *)0x0;
  Raziel.soulReaver = (_Instance *)0x0;
  Raziel.fallZVelocity = -0x20;
  G2EmulationQueryMode(&Raziel.State,0,0,0,0);
  G2EmulationSetMode(&Raziel.State,0,2);
  G2EmulationQueryMode(&Raziel.State,1,0,0,0);
  G2EmulationSetMode(&Raziel.State,1,2);
  G2EmulationQueryMode(&Raziel.State,2,0,0,0);
  G2EmulationSetMode(&Raziel.State,2,2);
  ControlFlag = 0x519;
  PlayerInstance->maxXVel = 0x100;
  PlayerInstance->maxYVel = 0x100;
  PlayerInstance->maxZVel = 0x100;
  razSetCowlNoDraw(1);
  InitExternalForces(&ExternalForces,4);
  PhysicsMove(PlayerInstance,-0x10);
  ExtraRot = (_G2SVector3_Type *)0x0;
  CAMERA_ChangeTo(&theCamera,PlayerInstance);
  razAttachControllers();
  INSTANCE_Query(PlayerInstance,(int)&DAT_00100006,0);
  PlayerInstance->checkMask = 0x3e002e;
  PlayerInstance->flags2 = PlayerInstance->flags2 | 0x400;
  G2EmulationInstanceSwitchAnimation();
  InitGlyphSystem(PlayerInstance);
  gameTrackerX.raziel_collide_override = '\0';
  Raziel.slipSlope = 0xb50;
  Raziel.terminator = -1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateInitIdle(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Ptr /*$a2*/)
 // line 443, offset 0x800a73b0
	/* begin block 1 */
		// Start line: 444
		// Start offset: 0x800A73B0
		// Variables:
	// 		struct evControlInitIdleData *data; // $s0
	// 		struct _Instance *linkWeapon; // $a0
	/* end block 1 */
	// End offset: 0x800A763C
	// End Line: 552

	/* begin block 2 */
		// Start line: 882
	/* end block 2 */
	// End Line: 883

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
    goto LAB_800a7634;
  }
  if (NewAnim == 3) {
    NewAnim = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,100,-1,-1);
    if (NewAnim == 0) {
      return;
    }
    NewAnim = 0x8d;
    local_18 = 0;
    local_14 = 1;
    goto LAB_800a7634;
  }
  if (NewAnim == 4) {
    NewAnim = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x68,-1,-1);
    if (NewAnim == 0) {
      return;
    }
    NewAnim = 0x8e;
    local_18 = 0;
    local_14 = 1;
    goto LAB_800a7634;
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
LAB_800a7624:
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
      goto LAB_800a7624;
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
        goto LAB_800a7624;
      }
      CurrentSection = 1;
      NewAnim = 0x7f;
      local_18 = ((int *)Ptr)[2];
    }
    else {
      if (Raziel.Senses.heldClass == 3) {
        CurrentSection = 1;
        NewAnim = 0x62;
        goto LAB_800a7624;
      }
      if (Raziel.Senses.heldClass != 0x1000) {
        return;
      }
      if (*(int *)Ptr == 0) {
        G2EmulatePlayAnimation(In,1,0x75,0,((int *)Ptr)[2],2);
        razReaverPickup(0xaf0);
        return;
      }
      CurrentSection = 1;
      NewAnim = 0x89;
      local_18 = ((int *)Ptr)[2];
    }
  }
  local_14 = 2;
LAB_800a7634:
  G2EmulatePlayAnimation(In,CurrentSection,NewAnim,0,local_18,local_14);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerIdle(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$fp*/)
 // line 601, offset 0x800a7654
	/* begin block 1 */
		// Start line: 602
		// Start offset: 0x800A7654
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int Anim; // $s5
	// 		int blockForwardMotion; // $s7

		/* begin block 1.1 */
			// Start line: 749
			// Start offset: 0x800A7C34
			// Variables:
		// 		struct _Instance *heldInst; // $v0
		/* end block 1.1 */
		// End offset: 0x800A7C5C
		// End Line: 755

		/* begin block 1.2 */
			// Start line: 786
			// Start offset: 0x800A7CF4
			// Variables:
		// 		struct evPhysicsEdgeData *EdgeData; // $v0
		/* end block 1.2 */
		// End offset: 0x800A7D4C
		// End Line: 793
	/* end block 1 */
	// End offset: 0x800A7EBC
	// End Line: 849

	/* begin block 2 */
		// Start line: 1196
	/* end block 2 */
	// End Line: 1197

void StateHandlerPickupObject(__CharacterState *In,int CurrentSection,int Data)

{
  bool bVar1;
  int iVar2;
  __Event *p_Var3;
  _Instance *Inst;
  int Ptr;
  u_long uVar4;
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
          G2EmulationSwitchAnimationSync(In,0x18,0,3,1);
          COLLIDE_SegmentCollisionOn(In->CharacterInstance,1);
        }
        else {
          G2EmulationInstancePlayAnimation(In->CharacterInstance,Raziel.idleInstance,1,0,3,1);
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
              if ((Raziel.Senses.EngagedMask & 0x4000) != 0) {
                NewProcess = StateHandlerThrow2;
                goto LAB_800a7ce4;
              }
              Ptr = razPickupAndGrab(In,CurrentSection);
              if (Ptr != 0) goto LAB_800a7cd4;
            }
            else {
              if (CurrentSection == 1) {
                razReaverImbue(In->CharacterInstance,Raziel.Senses.EngagedList[0xb].instance);
              }
            }
          }
          else {
            if (Raziel.Senses.heldClass == 3) {
              Inst = razGetHeldItem();
              if ((Inst == (_Instance *)0x0) || (uVar4 = INSTANCE_Post(Inst,2), (uVar4 & 0x20) == 0)
                 ) goto LAB_800a7dd4;
              NewProcess = StateHandlerStopMove;
            }
            else {
              NewProcess = StateHandlerStopMove;
            }
LAB_800a7ce4:
            StateSwitchStateData(In,CurrentSection,NewProcess,0);
          }
        }
        else {
          if (CurrentSection == 0) {
            NewProcess = StateHandlerMove;
            goto LAB_800a7db4;
          }
        }
      }
      else {
        Raziel.Mode = 0x200;
        pp_Var6[0x47] = (_Instance *)0x0;
        G2EmulatePlayAnimation(In,CurrentSection,0x15,0,6,1);
        StateSwitchStateData(In,CurrentSection,StateHandlerLookAround,0);
        ControlFlag = ControlFlag & 0xfffffffe;
      }
    }
    else {
      if ((int)puVar5 < 0x2000001) {
        if (puVar5 == &DAT_80000002) {
          if ((CurrentSection == 0) && ((*PadData & 0x40) != 0)) {
            Raziel.returnState = (_func_60 *)0x0;
            NewProcess = StateHandlerAttack2;
LAB_800a7db4:
            StateSwitchStateCharacterDataDefault(In,NewProcess,0);
          }
        }
        else {
          if ((int)puVar5 < -0x7ffffffd) {
            if (puVar5 == (undefined *)0x80000000) {
LAB_800a7cd4:
              NewProcess = StateHandlerHang;
              goto LAB_800a7ce4;
            }
            if (puVar5 != (undefined *)0x80000001) goto LAB_800a7dc8;
            if (CurrentSection == 0) {
              Raziel.Mode = 0x10;
              ControlFlag = ControlFlag | 0x10;
              Ptr = razSwitchVAnimCharacterSingle(In->CharacterInstance,0x10,(int *)0x0,(int *)0x0);
              if (Ptr != 0) {
                G2EmulationSwitchAnimationSync(In,0x22,0,2,1);
              }
              NewProcess = StateHandlerCompression;
              goto LAB_800a7db4;
            }
          }
          else {
            if (puVar5 == &DAT_00100001) {
              if (CurrentSection == 0) {
                Raziel.Mode = 1;
                Raziel.idleCount = 0;
                ControlFlag = (int)&LAB_0002a108_1;
                PhysicsMode = 3;
                SteerSwitchMode(In->CharacterInstance,0);
                Raziel.movementMinRate = 0;
              }
              StateInitIdle(In,CurrentSection,p_Var3->Data);
            }
            else {
              if ((int)puVar5 < 0x100002) {
                if (puVar5 == &DAT_80000010) {
                  if ((CurrentSection == 0) &&
                     ((In->CharacterInstance->tface != (_TFace *)0x0 ||
                      (In->CharacterInstance->attachedID != 0)))) {
                    if ((Raziel.Mode & 0x800U) == 0) {
                      NewProcess = StateHandlerWallGrab;
                      goto LAB_800a7db4;
                    }
                    DeMessageQueue(&In->SectionList[0].Defer,(int)&DAT_80000010,0);
                  }
                }
                else {
LAB_800a7dc8:
                  StateHandlerDragObject(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar5 != &DAT_00100004) goto LAB_800a7dc8;
                if (CurrentSection == 0) {
                  razReaverPickup(0x1000);
                  razSetPauseTranslation(In->CharacterInstance);
                  goto LAB_800a78f4;
                }
              }
            }
          }
        }
      }
      else {
        if (puVar5 == (undefined *)0x4010400) {
          if ((((*(u_int *)(p_Var3->Data + 0x20) & 0x20000) != 0) && ((Raziel.Abilities & 1U) != 0))
             && (Raziel.CurrentPlane == 2)) {
            Raziel.playerEvent = Raziel.playerEvent | 0x10000;
          }
        }
        else {
          if ((int)puVar5 < 0x4010401) {
            if (0x2000002 < (int)puVar5) {
              if (puVar5 != (undefined *)0x4010080) goto LAB_800a7dc8;
              if (CurrentSection == 0) {
                if (p_Var3->Data == 0) {
                  razResetPauseTranslation(In->CharacterInstance);
                }
                else {
                  razSetPauseTranslation(In->CharacterInstance);
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
                G2EmulatePlayAnimation(In,CurrentSection,0xd7,0,3,1);
              }
              else {
                Ptr = SetControlInitIdleData(0,0,3);
                StateInitIdle(In,CurrentSection,Ptr);
                if (CurrentSection == 0) {
                  if ((Raziel.playerEventHistory & 0x10000) == 0) {
                    ControlFlag = ControlFlag & 0xffff7fff;
                  }
LAB_800a78f4:
                  COLLIDE_SegmentCollisionOff(In->CharacterInstance,1);
                }
              }
            }
            else {
              if ((int)puVar5 < 0x8000001) {
                if (puVar5 != (undefined *)0x4010401) goto LAB_800a7dc8;
                bVar1 = true;
              }
              else {
                if (puVar5 != (undefined *)0x10000000) goto LAB_800a7dc8;
                if ((*PadData & 0x200) != 0) {
LAB_800a7ad4:
                  StateSwitchStateData(In,CurrentSection,DefaultPuppetStateHandler,3);
                  goto LAB_800a7dd4;
                }
                if (-0x201 < Raziel.Bearing) {
                  if (Raziel.Bearing < 0x201) {
                    if (bVar1) goto LAB_800a7dd4;
                    if (0xfff < Raziel.Magnitude) {
                      NewProcess = StateHandlerDecodeHold;
                      goto LAB_800a7ce4;
                    }
                    goto LAB_800a7ad4;
                  }
                  if (CurrentSection == 1) {
                    if (In->CharacterInstance->LinkChild == (_Instance *)0x0) {
                      Ptr = 1;
                      Mode = CurrentSection;
                      goto LAB_800a7a88;
                    }
                  }
                  else {
                    Mode = 1;
                    Ptr = CurrentSection;
LAB_800a7a88:
                    G2EmulatePlayAnimation(In,Ptr,0x35,0,2,Mode);
                  }
                  StateSwitchStateData(In,CurrentSection,StateHandlerStartTurn,0);
                  pp_Var6[0x47] = (_Instance *)0x33;
                  goto LAB_800a7dd4;
                }
                if (CurrentSection == 1) {
                  Inst = razGetHeldWeapon();
                  Ptr = 1;
                  Mode = CurrentSection;
                  if (Inst == (_Instance *)0x0) goto LAB_800a79fc;
                }
                else {
                  Ptr = CurrentSection;
                  Mode = 1;
LAB_800a79fc:
                  G2EmulatePlayAnimation(In,Ptr,0x36,0,2,Mode);
                }
                StateSwitchStateData(In,CurrentSection,StateHandlerStartTurn,0);
                pp_Var6[0x47] = (_Instance *)0x34;
              }
            }
          }
        }
      }
    }
LAB_800a7dd4:
    PurgeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerLookAround(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s1*/, int Data /*$a2*/)
 // line 853, offset 0x800a7eec
	/* begin block 1 */
		// Start line: 854
		// Start offset: 0x800A7EEC
		// Variables:
	// 		struct __Event *Ptr; // $s0

		/* begin block 1.1 */
			// Start line: 861
			// Start offset: 0x800A7FDC
			// Variables:
		// 		struct _Instance *instance; // $s0
		/* end block 1.1 */
		// End offset: 0x800A7FDC
		// End Line: 862

		/* begin block 1.2 */
			// Start line: 873
			// Start offset: 0x800A8030
			// Variables:
		// 		struct _Instance *instance; // $s0
		/* end block 1.2 */
		// End offset: 0x800A8030
		// End Line: 874

		/* begin block 1.3 */
			// Start line: 886
			// Start offset: 0x800A8078
			// Variables:
		// 		int message; // stack offset -32
		// 		int messageData; // stack offset -28
		/* end block 1.3 */
		// End offset: 0x800A812C
		// End Line: 904
	/* end block 1 */
	// End offset: 0x800A81F4
	// End Line: 927

	/* begin block 2 */
		// Start line: 1815
	/* end block 2 */
	// End Line: 1816

void StateHandlerBlock(__CharacterState *In,int CurrentSection,int Data)

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
        DeMessageQueue(&In->SectionList[CurrentSection].Defer,0x100000,0);
      }
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == (undefined *)0x100000) {
      Data_00 = 0;
      NewProcess = Raziel.returnState;
LAB_800a8184:
      StateSwitchStateData(In,CurrentSection,NewProcess,Data_00);
    }
    else {
      if ((int)puVar2 < 0x100001) {
        if (puVar2 == (undefined *)0x40005) {
LAB_800a8174:
          Data_00 = p_Var1->Data;
          NewProcess = StateHandlerCrouch;
          goto LAB_800a8184;
        }
        if ((int)puVar2 < 0x40006) {
          if ((puVar2 == &DAT_80000020) &&
             (Data_00 = StateHandlerAutoFace(&local_20,&iStack28), Data_00 != 0)) {
            if ((local_20 == 0x80000) && (CurrentSection == 0)) {
              razLaunchForce(In->CharacterInstance);
              StateSwitchStateData(In,0,StateHandlerWallIdle,0);
            }
            StateSwitchStateData(In,CurrentSection,StateHandlerWallIdle,0);
            if ((Raziel.Senses.heldClass != 0x1000) && (Raziel.Senses.heldClass != 8)) {
              razSetFadeEffect(In->CharacterInstance->fadeValue,PlayerData->throwFadeValue,
                               (int)PlayerData->throwFadeInRate);
            }
            Raziel.returnState = StateHandlerPickupObject;
            Raziel.throwMode = 2;
          }
        }
        else {
          if (puVar2 == (undefined *)0x40025) goto LAB_800a8174;
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
            if ((puVar2 == &DAT_00100001) && (CurrentSection == 1)) {
              anim = &In->CharacterInstance->anim;
              G2Anim_DisableController(anim,0x11,0xe);
              G2Anim_DisableController(anim,0x10,0xe);
              G2Anim_DisableController(anim,0xe,0xe);
              ControlFlag = 0x8001008;
            }
          }
          else {
            if (puVar2 == (undefined *)0x1000000) {
              if (CurrentSection == 0) {
                CAMERA_StartLookaroundMode(&theCamera);
              }
              Data_00 = p_Var1->Data;
              NewProcess = StateHandlerHitReaction;
              goto LAB_800a8184;
            }
          }
        }
      }
    }
    PurgeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerCrouch(struct __CharacterState *In /*$s3*/, int CurrentSection /*$s4*/, int Data /*stack 8*/)
 // line 930, offset 0x800a8210
	/* begin block 1 */
		// Start line: 931
		// Start offset: 0x800A8210
		// Variables:
	// 		struct __Event *Ptr; // $s1
	// 		int Anim; // $s0
	// 		struct _Instance *heldInst; // $s5

		/* begin block 1.1 */
			// Start line: 1040
			// Start offset: 0x800A861C
			// Variables:
		// 		struct evObjectData *data; // $s0
		// 		int i; // $s2
		/* end block 1.1 */
		// End offset: 0x800A8704
		// End Line: 1067
	/* end block 1 */
	// End offset: 0x800A8914
	// End Line: 1122

	/* begin block 2 */
		// Start line: 1977
	/* end block 2 */
	// End Line: 1978

void StateHandlerSwimCoil(__CharacterState *In,int CurrentSection,int Data)

{
  _Instance *Inst;
  __Event *p_Var1;
  int NewAnim;
  undefined *puVar2;
  _Instance *instance;
  int Frames;
  __CharacterState *p_Var3;
  _Instance **pp_Var4;
  int local_30;
  
  Inst = razGetHeldItem();
  pp_Var4 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0) {
      if (((*PadData & 0x100) == 0) &&
         (In->SectionList[CurrentSection].Process == StateHandlerSwimCoil)) {
        DeMessageQueue(&In->SectionList[CurrentSection].Event,0x20000008,0);
      }
      return;
    }
    NewAnim = G2EmulationQueryAnimation(In,CurrentSection);
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == &DAT_00100001) {
      if (CurrentSection == 0) {
        Raziel.Mode = 0x40;
        ControlFlag = 0x40008109;
        PhysicsMode = 3;
        SteerSwitchMode(In->CharacterInstance,0);
        if (p_Var1->Data == 0) {
          NewAnim = razSwitchVAnimCharacterSingle(In->CharacterInstance,0x4c,(int *)0x0,(int *)0x0);
          if (NewAnim != 0) {
            local_30 = 2;
            NewAnim = 4;
            Frames = 8;
            goto LAB_800a843c;
          }
        }
        else {
          NewAnim = razSwitchVAnimCharacterSingle(In->CharacterInstance,0x48,(int *)0x0,(int *)0x0);
          if (NewAnim != 0) {
            local_30 = 1;
            NewAnim = 3;
            Frames = 3;
LAB_800a843c:
            G2EmulationSwitchAnimationSync(In,NewAnim,0,Frames,local_30);
          }
        }
        if (Inst != (_Instance *)0x0) {
          INSTANCE_Query(Inst,0x80002c,0);
        }
      }
      if (p_Var1->Data == 0) {
        pp_Var4[0x48] = (_Instance *)0x0;
      }
      else {
        pp_Var4[0x48] = (_Instance *)0x48;
      }
    }
    else {
      if ((int)puVar2 < 0x100002) {
        if (puVar2 != &DAT_80000004) {
          if ((int)puVar2 < -0x7ffffffb) {
            if (puVar2 == (undefined *)0x80000000) {
              if (Inst != (_Instance *)0x0) {
                razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x50,-1,-1);
                pp_Var4[0x48] = (_Instance *)0x50;
                INSTANCE_Query(Inst,0x200005,0);
              }
            }
            else {
              if (puVar2 != (undefined *)0x80000001) goto LAB_800a889c;
              if (((CurrentSection == 0) && (NewAnim != 5)) && (NewAnim != 0x55)) {
                Raziel.Mode = 0x20;
                NewAnim = razSwitchVAnimCharacterSingle
                                    (In->CharacterInstance,0x20,(int *)0x0,(int *)0x0);
                if (NewAnim != 0) {
                  G2EmulationSwitchAnimationSync(In,0x26,0,1,1);
                }
                StateSwitchStateCharacterDataDefault(In,StateHandlerCompression,0);
              }
            }
          }
          else {
            if (puVar2 == &DAT_80000010) {
              if ((CurrentSection == 0) && (In->CharacterInstance->tface != (_TFace *)0x0)) {
                DeMessageQueue(&In->SectionList[0].Defer,(int)&DAT_80000010,0);
                ControlFlag = ControlFlag | 0x800000;
              }
LAB_800a87c4:
              if (((NewAnim != 5) && (NewAnim != 0x55)) && (pp_Var4[0x48] != (_Instance *)0x50)) {
                NewAnim = SetControlInitIdleData(0,0,3);
                StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,NewAnim);
                Raziel.Mode = 0x1000000;
              }
            }
            else {
              if ((int)puVar2 < -0x7fffffef) {
                if (puVar2 != &DAT_80000008) goto LAB_800a889c;
              }
              else {
                if (puVar2 != (undefined *)0x100000) goto LAB_800a889c;
                NewAnim = SetControlInitIdleData(0,0,3);
                StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,NewAnim);
              }
            }
          }
        }
      }
      else {
        if (puVar2 != (undefined *)0x4020000) {
          if ((int)puVar2 < 0x4020001) {
            if (puVar2 == (undefined *)0x2000000) {
              if ((((Raziel.Senses.EngagedMask & 4) != 0) && (Raziel.Senses.heldClass != 3)) &&
                 ((NewAnim != 5 && (NewAnim != 0x55)))) {
                ControlFlag = ControlFlag & 0xfffffff7U | 0x8041000;
                NewAnim = 0;
                if (CurrentSection == 0) {
                  Frames = 8;
                  p_Var3 = In;
                  do {
                    p_Var3->SectionList[0].Data1 = 0;
                    EnMessageQueueData((__MessageQueue *)((int)&In->TotalSections + Frames));
                    Frames = Frames + 0x11c;
                    NewAnim = NewAnim + 1;
                    p_Var3 = (__CharacterState *)&p_Var3->SectionList[0].Data1;
                  } while (NewAnim < 3);
                  razCenterWithBlock(In->CharacterInstance,Raziel.Senses.EngagedList[2].instance,
                                     -0x8d);
                  NewAnim = SetObjectBreakOffData
                                      (-(int)Raziel.Senses.ForwardNormal.x,
                                       -(int)Raziel.Senses.ForwardNormal.y,0,(_Instance *)0x0,0);
                  INSTANCE_Query(Raziel.Senses.EngagedList[2].instance,0x800001,NewAnim);
                  Frames = 0x100000;
                  if ((*(u_int *)(NewAnim + 0xc) & 1) == 0) {
                    instance = In->CharacterInstance;
                    goto LAB_800a86b0;
                  }
                  COLLIDE_SegmentCollisionOn(In->CharacterInstance,1);
                  Frames = 0x55;
                  if ((*(u_int *)(NewAnim + 0xc) & 8) == 0) {
                    Frames = 5;
                  }
                  G2EmulationSwitchAnimationSync(In,Frames,0,0,1);
                  razSetPlayerEventHistory(2);
                }
              }
            }
            else {
              if ((int)puVar2 < 0x2000001) {
                if (puVar2 != &DAT_00100004) goto LAB_800a889c;
                if ((CurrentSection == 0) &&
                   (COLLIDE_SegmentCollisionOff(In->CharacterInstance,1), Inst != (_Instance *)0x0))
                {
                  INSTANCE_Query(Inst,0x200003,7);
                  Frames = 0x80002b;
                  instance = Inst;
LAB_800a86b0:
                  INSTANCE_Query(instance,Frames,0);
                }
              }
              else {
                if (puVar2 != (undefined *)0x4010400) goto LAB_800a889c;
              }
            }
          }
          else {
            if (puVar2 == (undefined *)0x10000000) {
              if (((Raziel.Senses.heldClass != 3) && (NewAnim != 5)) && (NewAnim != 0x55)) {
                StateSwitchStateData(In,CurrentSection,DefaultPuppetStateHandler,3);
              }
            }
            else {
              if ((int)puVar2 < 0x10000001) {
                if (puVar2 == (undefined *)0x8000000) {
                  if ((NewAnim == 5) || (NewAnim == 0x55)) {
                    NewAnim = SetControlInitIdleData(0,0,3);
                    StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,NewAnim);
                    pp_Var4[0x47] = (_Instance *)0x1;
                    ControlFlag = ControlFlag & 0xf7ffefff;
                  }
                  else {
                    if (CurrentSection == 1) {
                      if ((In->SectionList[1].Data2 == 0x50) && (Inst != (_Instance *)0x0)) {
                        INSTANCE_Query(Inst,0x800008,0);
                        razReaverOff();
                      }
                      In->SectionList[0].Data2 = 0x4c;
                      pp_Var4[0x48] = (_Instance *)0x4c;
                      instance = In->CharacterInstance;
                      In->SectionList[2].Data2 = 0x4c;
                      NewAnim = razSwitchVAnimCharacterSingle(instance,0x4c,(int *)0x0,(int *)0x0);
                      if (NewAnim != 0) {
                        G2EmulationSwitchAnimationSync(In,4,0,8,2);
                      }
                    }
                  }
                  goto LAB_800a88ac;
                }
              }
              else {
                if (puVar2 == (undefined *)0x20000008) goto LAB_800a87c4;
              }
LAB_800a889c:
              StateHandlerDragObject(In,CurrentSection,Data);
            }
          }
        }
      }
    }
LAB_800a88ac:
    PurgeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerDropAction(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$s4*/)
 // line 1125, offset 0x800a8944
	/* begin block 1 */
		// Start line: 1126
		// Start offset: 0x800A8944
		// Variables:
	// 		struct __Event *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800A8BB4
	// End Line: 1196

	/* begin block 2 */
		// Start line: 2385
	/* end block 2 */
	// End Line: 2386

void StateHandlerStumble(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *Inst;
  undefined *puVar2;
  int Data_00;
  u_long Frames;
  
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
          INSTANCE_Query(Inst,0x800008,0);
          razReaverOff();
        }
        Data_00 = SetControlInitIdleData(0,0,3);
        StateSwitchStateCharacterDataDefault(In,StateHandlerPickupObject,Data_00);
      }
    }
    else {
      if ((int)puVar2 < 0x8000001) {
        if (puVar2 != (undefined *)0x80000001) {
          if (puVar2 != &DAT_00100001) goto LAB_800a8b9c;
          Inst = razGetHeldItem();
          if ((Inst == (_Instance *)0x0) || (CurrentSection != 1)) {
            if (CurrentSection == 2) {
              SetAnimationInstanceSwitchData(In,2,0x45,0,3,1,1);
            }
            else {
              if (CurrentSection == 0) {
                SetAnimationInstanceSwitchData(In,0,3,0,3,1,1);
                Raziel.Mode = 0x40;
              }
            }
          }
          else {
            if (Raziel.Senses.heldClass == 2) {
              Data_00 = 0x69;
              Frames = 3;
LAB_800a8a94:
              G2EmulatePlayAnimation(In,1,Data_00,0,Frames,1);
            }
            else {
              if (Raziel.Senses.heldClass < 3) {
                if ((Raziel.Senses.heldClass != 0) && (Raziel.Senses.heldClass == 1)) {
                  Data_00 = 0x53;
                  Frames = 3;
                  goto LAB_800a8a94;
                }
              }
              else {
                if (Raziel.Senses.heldClass == 3) {
                  Data_00 = 99;
                  Frames = Raziel.Senses.heldClass;
                  goto LAB_800a8a94;
                }
              }
            }
            Inst = razGetHeldItem();
            INSTANCE_Query(Inst,0x80002c,0);
          }
          ControlFlag = ControlFlag | 0x40000000;
        }
      }
      else {
        if ((puVar2 != (undefined *)0x10000000) && (puVar2 != (undefined *)0x20000008)) {
LAB_800a8b9c:
          StateHandlerDragObject(In,CurrentSection,Data);
        }
      }
    }
    PurgeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerSoulSuck(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$s5*/)
 // line 1203, offset 0x800a8bd4
	/* begin block 1 */
		// Start line: 1204
		// Start offset: 0x800A8BD4
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		int Anim; // $s2

		/* begin block 1.1 */
			// Start line: 1311
			// Start offset: 0x800A909C
			// Variables:
		// 		struct evPhysicsSwimData *SwimData; // $v0
		/* end block 1.1 */
		// End offset: 0x800A90CC
		// End Line: 1318
	/* end block 1 */
	// End offset: 0x800A90E8
	// End Line: 1326

	/* begin block 2 */
		// Start line: 2550
	/* end block 2 */
	// End Line: 2551

	/* begin block 3 */
		// Start line: 2555
	/* end block 3 */
	// End Line: 2556

void StateHandlerAttack2(__CharacterState *In,int CurrentSection,int Data)

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
LAB_800a8e80:
      if (iVar1 == 0x4f) {
        G2EmulatePlayAnimation(In,CurrentSection,0x2f,0,3,1);
        EnMessageQueueData(&p_Var5->Event);
      }
      else {
        if (Raziel.returnState == (_func_60 *)0x0) {
          Data_00 = SetControlInitIdleData(0,0,3);
          NewProcess = StateHandlerPickupObject;
        }
        else {
          Data_00 = 0;
          NewProcess = Raziel.returnState;
        }
        StateSwitchStateData(In,CurrentSection,NewProcess,Data_00);
      }
      if (((Raziel.Senses.EngagedMask & 0x1000) != 0) && (CurrentSection == 0)) {
LAB_800a8f18:
        INSTANCE_Query(Raziel.Senses.EngagedList[0xc].instance,0x1000014,0);
      }
    }
    else {
      if ((int)puVar4 < 0x1000007) {
        if (puVar4 == &DAT_00100001) {
          if (CurrentSection == 0) {
            ControlFlag = 9;
            PhysicsMode = 3;
            if (((Raziel.Senses.EngagedMask & 0x1000) != 0) && (Raziel.Senses.heldClass != 3)) {
              razAlignYRotMoveInterp
                        (Raziel.Senses.EngagedList[0xc].instance,0xdc,
                         &In->CharacterInstance->position,&In->CharacterInstance->rotation,0);
              INSTANCE_Query(Raziel.Senses.EngagedList[0xc].instance,0x1000014,1);
            }
            SetAnimationInstanceSwitchData(In,0,0x4e,0,4,1,4);
          }
          if (CurrentSection == 2) {
            G2EmulatePlayAnimation(In,2,0,0,4,2);
          }
          if (CurrentSection == 1) {
            p_Var3 = razGetHeldWeapon();
            if ((p_Var3 == (_Instance *)0x0) && ((Raziel.Senses.EngagedMask & 0x1000) == 0)) {
              Data_00 = 0x4e;
            }
            else {
              Data_00 = 0x5e;
            }
            G2EmulatePlayAnimation(In,1,Data_00,0,4,1);
            Raziel.Mode = Raziel.Mode | 0x10000000;
          }
        }
        else {
          if ((int)puVar4 < 0x100002) {
            if (puVar4 != &DAT_80000010) {
LAB_800a90d0:
              StateHandlerDragObject(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar4 == &DAT_00100004) {
              if (CurrentSection == 1) {
                razSetCowlNoDraw(1);
                ControlFlag = ControlFlag & 0xffffffbf;
                Raziel.Mode = Raziel.Mode & 0xefffffff;
                if ((Raziel.Senses.EngagedMask & 0x1000) != 0) goto LAB_800a8f18;
              }
            }
            else {
              if (puVar4 != (undefined *)0x1000001) goto LAB_800a90d0;
            }
          }
        }
      }
      else {
        if (puVar4 == (undefined *)0x4020000) {
          if ((*(ushort *)(p_Var2->Data + 0x10) & 0x40) != 0) {
            StateHandlerSoulSuck(In,CurrentSection,0);
          }
        }
        else {
          if ((int)puVar4 < 0x4020001) {
            if (puVar4 == (undefined *)0x1000009) {
              NewAnim = 0x50;
              Data_00 = 2;
LAB_800a9088:
              G2EmulatePlayAnimation(In,CurrentSection,NewAnim,0,Data_00,1);
            }
            else {
              if (puVar4 != (undefined *)0x1000016) goto LAB_800a90d0;
              if (((gameTrackerX.debugFlags2 & 0x800U) != 0) && (CurrentSection == 0)) {
                GainHealth(p_Var2->Data);
                razSetPlayerEventHistory(0x1000);
              }
            }
          }
          else {
            if (puVar4 != (undefined *)0x8000000) {
              if (puVar4 == (undefined *)0x20000002) goto LAB_800a8e80;
              goto LAB_800a90d0;
            }
            if (iVar1 == 0x2f) {
              if (Raziel.returnState == (_func_60 *)0x0) {
                Data_00 = SetControlInitIdleData(0,0,3);
                NewProcess_00 = StateHandlerPickupObject;
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
              G2EmulatePlayAnimation(In,CurrentSection,0x4f,0,0,1);
            }
            if (iVar1 == 0x50) {
              if ((*PadData & 0x40) != 0) {
                NewAnim = 0x4f;
                Data_00 = 8;
                goto LAB_800a9088;
              }
              if (Raziel.returnState == (_func_60 *)0x0) {
                Data_00 = SetControlInitIdleData(0,0,3);
                StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,Data_00);
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
    PurgeMessageQueue(&p_Var5->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerStartTurn(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s3*/)
 // line 1332, offset 0x800a910c
	/* begin block 1 */
		// Start line: 1333
		// Start offset: 0x800A910C
		// Variables:
	// 		struct __Event *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800A92F0
	// End Line: 1393

	/* begin block 2 */
		// Start line: 2818
	/* end block 2 */
	// End Line: 2819

void StateHandlerStartTurn(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int Data_00;
  undefined *puVar2;
  code *NewProcess;
  
  G2EmulationQueryFrame(In,CurrentSection);
  if (Raziel.Bearing == 0) {
    DeMessageQueue(&In->SectionList[CurrentSection].Defer,0x100000,0);
  }
  do {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == (undefined *)0x100000) {
LAB_800a9220:
      if (CurrentSection == 0) {
        if ((*PadData & 0x8000000fU) == 0) {
          Data_00 = SetControlInitIdleData(0,0,3);
          StateSwitchStateCharacterDataDefault(In,StateHandlerPickupObject,Data_00);
        }
        else {
          NewProcess = StateHandlerDecodeHold;
LAB_800a92c8:
          StateSwitchStateCharacterDataDefault(In,NewProcess,0);
        }
      }
    }
    else {
      if ((int)puVar2 < 0x100001) {
        if (puVar2 == (undefined *)0x80000001) {
          if (CurrentSection == 0) {
            Raziel.Mode = 8;
            Data_00 = razSwitchVAnimCharacterSingle(In->CharacterInstance,0,(int *)0x0,(int *)0x0);
            if (Data_00 != 0) {
              G2EmulationSwitchAnimationSync(In,0x1a,0,0,1);
            }
            NewProcess = StateHandlerCompression;
            goto LAB_800a92c8;
          }
        }
        else {
          if (puVar2 == (undefined *)0x0) goto LAB_800a9220;
LAB_800a92d8:
          StateHandlerDragObject(In,CurrentSection,Data);
        }
      }
      else {
        if (puVar2 != &DAT_00100001) {
          if (puVar2 != (undefined *)0x8000000) goto LAB_800a92d8;
          goto LAB_800a9220;
        }
        if (CurrentSection == 0) {
          Raziel.Mode = 0x4000;
          ControlFlag = 0x20109;
          PhysicsMode = 3;
          SteerSwitchMode(In->CharacterInstance,1);
        }
      }
    }
    PurgeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateInitStartMove(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Frame /*$s3*/)
 // line 1397, offset 0x800a930c
	/* begin block 1 */
		// Start line: 2953
	/* end block 1 */
	// End Line: 2954

	/* begin block 2 */
		// Start line: 2956
	/* end block 2 */
	// End Line: 2957

void InitStates(__CharacterState *In,int CurrentSection,int Frame)

{
  int iVar1;
  
  if ((*PadData & 0x200) != 0) {
    StateSwitchStateData(In,CurrentSection,DefaultPuppetStateHandler,3);
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
 // line 1486, offset 0x800a93b8
	/* begin block 1 */
		// Start line: 1487
		// Start offset: 0x800A93B8
		// Variables:
	// 		struct __Event *Ptr; // $a1

		/* begin block 1.1 */
			// Start line: 1544
			// Start offset: 0x800A966C
			// Variables:
		// 		int mode; // $a0
		/* end block 1.1 */
		// End offset: 0x800A96C4
		// End Line: 1562
	/* end block 1 */
	// End offset: 0x800A99FC
	// End Line: 1654

	/* begin block 2 */
		// Start line: 3134
	/* end block 2 */
	// End Line: 3135

void StateHandlerDecodeHold(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int Data_00;
  _Instance *p_Var2;
  undefined *puVar3;
  u_int mode;
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
        if (In->SectionList[1].Process == StateHandlerDecodeHold) {
          StateSwitchStateData(In,1,DefaultPuppetStateHandler,0xb);
        }
        if (In->SectionList[2].Process == StateHandlerDecodeHold) {
          StateSwitchStateData(In,2,DefaultPuppetStateHandler,0xb);
        }
      }
      if (((Raziel.Magnitude != 0) && (Raziel.Magnitude < 0x1000)) && ((Raziel.passedMask & 1) != 0)
         ) {
        StateSwitchStateData(In,CurrentSection,DefaultPuppetStateHandler,0);
      }
      return;
    }
    puVar3 = (undefined *)p_Var1->ID;
    if (puVar3 == &DAT_00100001) {
      InitStates(In,CurrentSection,p_Var1->Data);
      In->SectionList[CurrentSection].Data2 = 1;
      if (CurrentSection == 0) {
        ControlFlag = (int)&LAB_0002a118_1;
        Raziel.Mode = Raziel.Mode & 0x200000U | 4;
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
LAB_800a9604:
          if (CurrentSection == 0) {
            if (In->CharacterInstance->tface != (_TFace *)0x0) {
              DeMessageQueue(&In->SectionList[0].Defer,p_Var1->ID,0);
              ControlFlag = ControlFlag | 0x800000;
            }
LAB_800a9640:
            if (CurrentSection == 0) {
              if (((Raziel.passedMask & 7) != 0) ||
                 (Data_00 = G2EmulationInstanceSetAnimation(In,0), Data_00 == 0)) {
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
                StateSwitchStateCharacterDataDefault(In,StateHandlerPickupObject,Data_00);
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
                if (CurrentSection == 0) {
                  NewProcess = StateHandlerHang;
LAB_800a9860:
                  StateSwitchStateCharacterDataDefault(In,NewProcess,0);
                }
              }
              else {
                if (CurrentSection != 1) goto LAB_800a9784;
                StateSwitchStateData(In,1,StateHandlerHang,10);
              }
            }
            else {
              if (puVar3 != (undefined *)0x80000001) goto LAB_800a98b4;
              if (CurrentSection == 0) {
                Raziel.Mode = 8;
                Data_00 = razSwitchVAnimCharacterSingle
                                    (In->CharacterInstance,0,(int *)0x0,(int *)0x0);
                if (Data_00 != 0) {
                  G2EmulationSwitchAnimationSync(In,0x1a,0,0,1);
                }
                StateSwitchStateCharacterDataDefault(In,StateHandlerCompression,0);
LAB_800a9734:
                ControlFlag = ControlFlag & 0xffffdfff;
              }
            }
            goto LAB_800a98c0;
          }
          if (puVar3 == &DAT_80000010) goto LAB_800a9604;
          if ((int)puVar3 < -0x7fffffef) {
            if (puVar3 == &DAT_80000004) {
              StateSwitchStateData(In,CurrentSection,DefaultPuppetStateHandler,3);
              goto LAB_800a98c0;
            }
          }
          else {
            if (puVar3 == (undefined *)0x0) goto LAB_800a9640;
          }
LAB_800a98b4:
          StateHandlerDragObject(In,CurrentSection,Data);
        }
      }
      else {
        if (puVar3 == (undefined *)0x4010401) {
          Data_00 = SetControlInitIdleData(0,5,5);
          StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,Data_00);
        }
        else {
          if ((int)puVar3 < 0x4010402) {
            if (puVar3 == (undefined *)0x4000001) {
              if ((CurrentSection == 0) && (Data_00 = G2EmulationQueryFrame(In,0), 6 < Data_00)) {
                PhysicsMode = 0;
                SetDropPhysics(In->CharacterInstance,&Raziel);
                if (In->CharacterInstance->zVel < -0x20) {
                  Data_00 = razSwitchVAnimCharacterSingle
                                      (In->CharacterInstance,0x18,(int *)0x0,(int *)0x0);
                  if (Data_00 != 0) {
                    G2EmulationSwitchAnimationSync(In,0x24,0,4,1);
                  }
                  NewProcess = StateHandlerGrab;
                  goto LAB_800a9860;
                }
              }
            }
            else {
              if ((int)puVar3 < 0x4000002) {
                if (puVar3 != (undefined *)0x2000000) goto LAB_800a98b4;
                razPickupAndGrab(In,CurrentSection);
              }
              else {
                if (puVar3 != (undefined *)0x4010080) goto LAB_800a98b4;
                if (CurrentSection != 2) {
                  G2EmulationSetMode(In,CurrentSection,(u_int)(p_Var1->Data != 0));
                }
                if (((Raziel.passedMask & 2) != 0) && ((*PadData & 0x8000000fU) != 0)) {
                  G2EmulationSetMode(In,CurrentSection,2);
                  goto LAB_800a9734;
                }
              }
            }
          }
          else {
            if ((int)puVar3 < 0x8000000) goto LAB_800a98b4;
            if ((int)puVar3 < 0x8000002) {
LAB_800a9784:
              StateSwitchStateData(In,CurrentSection,DefaultPuppetStateHandler,0);
            }
            else {
              if (puVar3 != (undefined *)0x10000000) goto LAB_800a98b4;
            }
          }
        }
      }
    }
LAB_800a98c0:
    PurgeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateInitMove(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s0*/, int Frames /*$a2*/)
 // line 1657, offset 0x800a9a1c
	/* begin block 1 */
		// Start line: 3490
	/* end block 1 */
	// End Line: 3491

	/* begin block 2 */
		// Start line: 3495
	/* end block 2 */
	// End Line: 3496

void StateInitStartMove(__CharacterState *In,int CurrentSection,int Frames)

{
  int iVar1;
  u_int uVar2;
  
  if ((*PadData & 0x200) == 0) {
    if ((*PadData & 0x100) == 0) {
      Raziel.Mode = Raziel.Mode & 0x200000U | 4;
      uVar2 = ControlFlag | 0x228119;
      ControlFlag = ControlFlag | 0x28119;
      if ((Raziel.Abilities & 0x20U) != 0) {
        ControlFlag = uVar2;
      }
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
        iVar1 = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x38,-1,-1);
        if (iVar1 != 0) {
          G2EmulatePlayAnimation(In,CurrentSection,0x4a,0,3,2);
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
      iVar1 = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x34,-1,-1);
      if (iVar1 != 0) {
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
 // line 1862, offset 0x800a9c58
	/* begin block 1 */
		// Start line: 1863
		// Start offset: 0x800A9C58
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int Anim; // $s6

		/* begin block 1.1 */
			// Start line: 1920
			// Start offset: 0x800A9FDC
			// Variables:
		// 		int data; // $a2
		/* end block 1.1 */
		// End offset: 0x800AA00C
		// End Line: 1932
	/* end block 1 */
	// End offset: 0x800AA270
	// End Line: 2012

	/* begin block 2 */
		// Start line: 3925
	/* end block 2 */
	// End Line: 3926

void DefaultPuppetStateHandler(__CharacterState *In,int CurrentSection,int Data)

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
      if ((CurrentSection == 0) && (In->SectionList[0].Process != DefaultPuppetStateHandler)) {
        razResetMotion(In->CharacterInstance);
      }
      return;
    }
    puVar5 = (undefined *)p_Var3->ID;
    if (puVar5 == (undefined *)0x0) {
LAB_800a9ec4:
      if (CurrentSection == 0) {
        if (((Raziel.steeringMode == 9) || (Raziel.steeringMode == 0xe)) ||
           (Raziel.steeringMode == 0xf)) {
          razApplyMotion(In,0);
        }
        else {
          if (((Raziel.Mode == 2) || (iVar1 == 0x7b)) || (iVar1 == 0x7c)) {
            Data_00 = SetControlInitIdleData(0,0,3);
            StateSwitchStateCharacterDataDefault(In,StateHandlerPickupObject,Data_00);
          }
          else {
            if (Raziel.Mode == 0x1000000) {
              StateSwitchStateCharacterDataDefault(In,StateHandlerSwimCoil,0);
            }
            else {
              if ((p_Var3->Data < 4) && ((ControlFlag & 0x800000U) == 0)) {
                ControlFlag = ControlFlag | 0x2000;
                if ((*PadData & 0x8000000fU) == 0) {
                  DeMessageQueue(&In->SectionList[0].Defer,0,p_Var3->Data + 1);
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
                StateSwitchStateCharacterDataDefault(In,StateHandlerSwimDiveIn,Data_00);
              }
            }
          }
        }
      }
    }
    else {
      if ((int)puVar5 < 1) {
        if (puVar5 == &DAT_80000002) {
LAB_800a9e88:
          if (CurrentSection == 0) {
            if (In->CharacterInstance->tface != (_TFace *)0x0) {
              DeMessageQueue(&In->SectionList[0].Defer,p_Var3->ID,0);
              ControlFlag = ControlFlag | 0x800000;
            }
            goto LAB_800a9ec4;
          }
        }
        else {
          if ((int)puVar5 < -0x7ffffffd) {
            if (puVar5 == (undefined *)0x80000000) {
              if ((Raziel.Mode & 2U) == 0) {
                if (pp_Var2[0x48] == (_Instance *)0x38) {
                  p_Var4 = razGetHeldItem();
                  if (p_Var4 != (_Instance *)0x0) {
                    NewProcess = StateHandlerStumble;
                    goto LAB_800aa210;
                  }
                }
                else {
                  if (CurrentSection == 1) {
                    StateSwitchStateData(In,1,StateHandlerHang,10);
                  }
                  Raziel.dropOffHeight = 200;
                  Raziel.fallZVelocity = -0x60;
                }
              }
              else {
                NewProcess = StateHandlerHang;
LAB_800aa210:
                StateSwitchStateData(In,CurrentSection,NewProcess,0);
              }
            }
            else {
              if (puVar5 != (undefined *)0x80000001) goto LAB_800aa230;
              if (CurrentSection != 0) goto LAB_800aa23c;
              if ((*PadData & 0x100) == 0) {
                Raziel.Mode = 8;
                Data_00 = razSwitchVAnimCharacterSingle
                                    (In->CharacterInstance,0,(int *)0x0,(int *)0x0);
                if (Data_00 != 0) {
                  Data_00 = 0;
                  goto LAB_800aa15c;
                }
              }
              else {
                Raziel.Mode = 0x20;
                Data_00 = razSwitchVAnimCharacterSingle
                                    (In->CharacterInstance,0x20,(int *)0x0,(int *)0x0);
                if (Data_00 != 0) {
                  Data_00 = 1;
LAB_800aa15c:
                  G2EmulationSwitchAnimationSync(In,0x1a,0,Data_00,1);
                }
              }
              StateSwitchStateCharacterDataDefault(In,StateHandlerCompression,0);
LAB_800aa178:
              ControlFlag = ControlFlag & 0xffffdfff;
            }
          }
          else {
            if (puVar5 != &DAT_80000008) {
              if ((int)puVar5 < -0x7ffffff7) {
                if (puVar5 == &DAT_80000004) {
                  if (CurrentSection != 2) {
                    local_2c = 2;
                    Data_00 = CurrentSection;
                  }
                  else {
                    Data_00 = 2;
                    local_2c = CurrentSection;
                  }
                  G2EmulatePlayAnimation(In,Data_00,(u_int)(CurrentSection != 2),0,3,local_2c);
                  Raziel.Mode = 2;
                  ControlFlag = ControlFlag | 0x2000;
                  goto LAB_800aa23c;
                }
              }
              else {
                if (puVar5 == &DAT_80000010) goto LAB_800a9e88;
              }
LAB_800aa230:
              StateHandlerDragObject(In,CurrentSection,Data);
            }
          }
        }
      }
      else {
        if (puVar5 == (undefined *)0x4010080) {
          if (CurrentSection == 0) {
            if (p_Var3->Data == 0) {
              razResetPauseTranslation(In->CharacterInstance);
            }
            else {
              razSetPauseTranslation(In->CharacterInstance);
            }
          }
        }
        else {
          if (0x4010080 < (int)puVar5) {
            if (puVar5 == (undefined *)0x20000004) {
LAB_800aa0b8:
              Raziel.Mode = 4;
              goto LAB_800aa178;
            }
            if ((int)puVar5 < 0x20000005) {
              if (puVar5 == (undefined *)0x10000000) {
                if (Raziel.Magnitude < 0x1000) {
                  StateInitStartMove(In,CurrentSection,3);
                }
                else {
                  StateInitStartMove(In,CurrentSection,0);
                }
                goto LAB_800aa23c;
              }
            }
            else {
              if (puVar5 == (undefined *)0x20000008) goto LAB_800aa0b8;
            }
            goto LAB_800aa230;
          }
          if (puVar5 == &DAT_00100004) {
            FX_EndConstrict(0,(_Instance *)0x0);
            pp_Var2[0x47] = (_Instance *)0x0;
          }
          else {
            if ((int)puVar5 < 0x100005) {
              if (puVar5 != &DAT_00100001) goto LAB_800aa230;
              pp_Var2[0x48] = (_Instance *)0xffffffff;
              StateInitStartMove(In,CurrentSection,p_Var3->Data);
              Raziel.constrictFlag = 1;
              SteerSwitchMode(In->CharacterInstance,2);
              pp_Var2[0x47] = (_Instance *)0x0;
              Raziel.passedMask = Raziel.passedMask | 0x1000;
            }
            else {
              if (puVar5 != (undefined *)0x2000000) goto LAB_800aa230;
              razPickupAndGrab(In,CurrentSection);
            }
          }
        }
      }
    }
LAB_800aa23c:
    PurgeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerStopMove(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s4*/)
 // line 2015, offset 0x800aa29c
	/* begin block 1 */
		// Start line: 2016
		// Start offset: 0x800AA29C
		// Variables:
	// 		struct __Event *Ptr; // $a1
	/* end block 1 */
	// End offset: 0x800AA5A0
	// End Line: 2108

	/* begin block 2 */
		// Start line: 4241
	/* end block 2 */
	// End Line: 4242

void StateHandlerSwimDiveIn(__CharacterState *In,int CurrentSection,int Data)

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
        anim = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x58,-1,-1);
        if (anim != 0) {
          anim = 2;
LAB_800aa43c:
          razSwitchVAnimSingle(In->CharacterInstance,CurrentSection,anim,-1,-1);
        }
      }
      else {
        if (p_Var1->Data == 0x1e) {
          anim = razSwitchVAnimGroup(In->CharacterInstance,CurrentSection,0x5c,-1,-1);
          if (anim != 0) {
            anim = 3;
            goto LAB_800aa43c;
          }
        }
        else {
          frames = 6;
LAB_800aa504:
          anim = SetControlInitIdleData(0,0,frames);
          StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,anim);
        }
      }
    }
    else {
      if ((int)puVar2 < 0x100002) {
        if (puVar2 == &DAT_80000002) {
LAB_800aa4e0:
          DeMessageQueue(&p_Var3->Defer,p_Var1->ID,0);
        }
        else {
          if ((int)puVar2 < -0x7ffffffd) {
            if (puVar2 == (undefined *)0x80000001) {
              if (CurrentSection == 0) {
                Raziel.Mode = 0x10;
                anim = razSwitchVAnimCharacterSingle(In->CharacterInstance,0,(int *)0x0,(int *)0x0);
                if (anim != 0) {
                  G2EmulationSwitchAnimationSync(In,0x1a,0,0,1);
                }
                StateSwitchStateCharacterDataDefault(In,StateHandlerCompression,0);
              }
              goto LAB_800aa590;
            }
          }
          else {
            if (puVar2 == &DAT_80000010) goto LAB_800aa4e0;
          }
LAB_800aa588:
          StateHandlerDragObject(In,CurrentSection,Data);
        }
      }
      else {
        if ((int)puVar2 < 0x8000002) {
          if (0x7ffffff < (int)puVar2) {
            frames = 5;
            goto LAB_800aa504;
          }
          if (puVar2 != (undefined *)0x4010080) goto LAB_800aa588;
          if (CurrentSection == 0) {
            if (p_Var1->Data == 0) {
              razResetPauseTranslation(In->CharacterInstance);
              anim = SetControlInitIdleData(0,0,5);
              StateSwitchStateCharacterDataDefault(In,StateHandlerPickupObject,anim);
            }
            else {
              razSetPauseTranslation(In->CharacterInstance);
            }
          }
        }
        else {
          if (puVar2 != (undefined *)0x10000000) goto LAB_800aa588;
          StateSwitchStateData(In,CurrentSection,StateHandlerDecodeHold,0);
        }
      }
    }
LAB_800aa590:
    PurgeMessageQueue(&p_Var3->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerCompression(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s4*/)
 // line 2115, offset 0x800aa5c0
	/* begin block 1 */
		// Start line: 2116
		// Start offset: 0x800AA5C0
		// Variables:
	// 		struct __Event *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800AA968
	// End Line: 2211

	/* begin block 2 */
		// Start line: 4452
	/* end block 2 */
	// End Line: 4453

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
  u_int uVar9;
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
LAB_800aa93c:
          DeMessageQueue(&p_Var2->Defer,uVar9 | 1,0);
        }
        else {
          if (-0x80000000 < (int)puVar7) {
            if (puVar7 != &DAT_00100001) goto LAB_800aa950;
            if (CurrentSection == 0) {
              ControlFlag = 0x111;
              SetExternalTransitionForce(&__Force_800d5e1c,0,0,0,1,0);
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
                if ((Raziel.Mode < 0x11) || (Raziel.Mode != 0x20)) goto LAB_800aa958;
                SteerSwitchMode(In->CharacterInstance,4);
                sVar1 = (In->CharacterInstance->rotation).z;
                p_Var8 = In->CharacterInstance;
                lVar4 = 0x15;
              }
              Raziel.steeringLockRotation = (int)sVar1;
              p_Var8->yVel = lVar4;
              _Var5 = G2Anim_DetachControllerFromSeg(&In->CharacterInstance->anim,1,0xe);
              if (_Var5 == G2FALSE) {
                G2Anim_DisableController(&In->CharacterInstance->anim,1,0xe);
              }
            }
          }
        }
      }
      else {
        if (puVar7 == (undefined *)0x8000000) {
          if (Raziel.Mode == 8) {
            if (CurrentSection == 0) {
              iVar6 = razSwitchVAnimCharacterSingle(In->CharacterInstance,4,(int *)0x0,(int *)0x0);
              if (iVar6 != 0) {
                G2EmulationSwitchAnimationSync(In,0x1b,0,0,1);
              }
              SetPhysicsGravityData(In->CharacterInstance,-0x10,0,0x53,0x9a);
            }
          }
          else {
            if (Raziel.Mode == 0x20) {
              if (CurrentSection == 0) {
                iVar6 = razSwitchVAnimCharacterSingle
                                  (In->CharacterInstance,0x24,(int *)0x0,(int *)0x0);
                if (iVar6 != 0) {
                  G2EmulationSwitchAnimationSync(In,0x27,0,0,1);
                }
                SetPhysicsGravityData(In->CharacterInstance,-0x10,0,0x15,0xc3);
                In->CharacterInstance->yVel = 0;
              }
            }
            else {
              if (CurrentSection == 0) {
                iVar6 = razSwitchVAnimCharacterSingle
                                  (In->CharacterInstance,0x14,(int *)0x0,(int *)0x0);
                if (iVar6 != 0) {
                  G2EmulationSwitchAnimationSync(In,0x23,0,0,1);
                }
                SetPhysicsGravityData(In->CharacterInstance,-0x10,0,0x28,0x9a);
                In->CharacterInstance->yVel = 0;
                if (In->SectionList[0].Data1 == 1) {
                  In->CharacterInstance->zVel = (In->CharacterInstance->zVel << 1) / 3;
                }
              }
            }
          }
          StateSwitchStateData(In,CurrentSection,StateHandlerDeCompression,0);
        }
        else {
          if ((int)puVar7 < 0x8000001) {
            if (puVar7 != (undefined *)0x4020000) {
LAB_800aa950:
              StateHandlerDragObject(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar7 != (undefined *)0x20000001) goto LAB_800aa950;
            if (CurrentSection == 0) {
              if (Raziel.Mode == 0x10) {
                In->SectionList[0].Data1 = 1;
              }
              p_Var2 = In->SectionList;
              uVar9 = 0x20000000;
              goto LAB_800aa93c;
            }
          }
        }
      }
    }
LAB_800aa958:
    PurgeMessageQueue(&p_Var10->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerJump(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s2*/, int Data /*$s6*/)
 // line 2214, offset 0x800aa988
	/* begin block 1 */
		// Start line: 2215
		// Start offset: 0x800AA988
		// Variables:
	// 		struct __Event *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800AAD9C
	// End Line: 2312

	/* begin block 2 */
		// Start line: 4673
	/* end block 2 */
	// End Line: 4674

void StateHandlerDeCompression(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int NewAnim;
  undefined *puVar2;
  __MessageQueue *In_00;
  u_int uVar3;
  int Frames;
  __State *p_Var4;
  
  p_Var4 = In->SectionList + CurrentSection;
  do {
    p_Var1 = PeekMessageQueue(&p_Var4->Event);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == (undefined *)0x1000001) goto LAB_800aad8c;
    if ((int)puVar2 < 0x1000002) {
      if (puVar2 != &DAT_80000008) {
        if ((int)puVar2 < -0x7ffffff7) {
          if (puVar2 != (undefined *)0x80000000) {
            if (puVar2 != (undefined *)0x80000001) goto LAB_800aad84;
            NewAnim = G2EmulationQueryFrame(In,CurrentSection);
            In_00 = &p_Var4->Defer;
            if (1 < NewAnim) {
              if (Raziel.Senses.heldClass != 3) {
                StateSwitchStateData(In,CurrentSection,StateHandlerIdle,0);
              }
              goto LAB_800aad8c;
            }
            uVar3 = 0x80000000;
LAB_800aad60:
            DeMessageQueue(In_00,uVar3 | 1,0);
          }
        }
        else {
          if (puVar2 != (undefined *)0x40005) {
            if ((int)puVar2 < 0x40006) {
              if (puVar2 != &DAT_80000020) {
LAB_800aad84:
                StateHandlerDragObject(In,CurrentSection,Data);
              }
            }
            else {
              if (puVar2 != &DAT_00100001) goto LAB_800aad84;
              if (CurrentSection == 0) {
                ControlFlag = 0x511;
                Raziel.alarmTable = 200;
                PhysicsMode = 0;
                (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5c98;
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
              if (puVar2 != (undefined *)0x2000000) goto LAB_800aad84;
              razPickupAndGrab(In,CurrentSection);
            }
            else {
              if (puVar2 != (undefined *)0x4010008) goto LAB_800aad84;
            }
          }
        }
        else {
          if (puVar2 == (undefined *)0x8000004) {
            ControlFlag = ControlFlag | 8;
          }
          else {
            if (0x8000004 < (int)puVar2) {
              if (puVar2 != (undefined *)0x20000001) goto LAB_800aad84;
              In->SectionList[CurrentSection].Data2 = 1;
              if (CurrentSection != 0) goto LAB_800aad8c;
              if ((Raziel.Mode == 0x10) || (Raziel.Mode == 0x20)) {
                In_00 = &In->SectionList[0].Defer;
                uVar3 = 0x20000000;
                goto LAB_800aad60;
              }
              if (In->SectionList[0].Data1 == 0) {
                NewAnim = G2EmulationQueryFrame(In,0);
                In->SectionList[0].Data1 = NewAnim + 4;
                if (NewAnim + 4 != 0) goto LAB_800aac9c;
              }
              else {
LAB_800aac9c:
                NewAnim = G2EmulationQueryFrame(In,0);
                if (In->SectionList[0].Data1 < NewAnim) {
                  SetDropPhysics(In->CharacterInstance,&Raziel);
                  NewAnim = razSwitchVAnimCharacterSingle
                                      (In->CharacterInstance,8,(int *)0x0,(int *)0x0);
                  if (NewAnim != 0) {
                    G2EmulationSwitchAnimationSync(In,0x1c,0,7,1);
                  }
                  StateSwitchStateCharacterDataDefault(In,StateHandlerGrab,In->SectionList[0].Data2)
                  ;
                  goto LAB_800aad8c;
                }
              }
              In_00 = &p_Var4->Defer;
              uVar3 = 0x20000000;
              goto LAB_800aad60;
            }
            if (puVar2 != (undefined *)0x8000000) goto LAB_800aad84;
            if (CurrentSection == 0) {
              if (Raziel.Mode == 0x10) {
                NewAnim = razSwitchVAnimCharacterSingle
                                    (In->CharacterInstance,0x18,(int *)0x0,(int *)0x0);
                if (NewAnim != 0) {
                  NewAnim = 0x24;
                  Frames = 4;
                  goto LAB_800aabf8;
                }
              }
              else {
                if (Raziel.Mode == 0x20) {
                  NewAnim = razSwitchVAnimCharacterSingle
                                      (In->CharacterInstance,0x28,(int *)0x0,(int *)0x0);
                  if (NewAnim != 0) {
                    NewAnim = 0x28;
                    Frames = 10;
LAB_800aabf8:
                    G2EmulationSwitchAnimationSync(In,NewAnim,0,Frames,1);
                  }
                }
                else {
                  NewAnim = razSwitchVAnimCharacterSingle
                                      (In->CharacterInstance,8,(int *)0x0,(int *)0x0);
                  if (NewAnim != 0) {
                    NewAnim = 0x1c;
                    Frames = 7;
                    goto LAB_800aabf8;
                  }
                }
              }
            }
            StateSwitchStateData(In,CurrentSection,StateHandlerGrab,0);
            if ((*PadData & 0x80) == 0) {
              In->SectionList[CurrentSection].Data2 = 1;
            }
          }
        }
      }
    }
LAB_800aad8c:
    PurgeMessageQueue(&p_Var4->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerFall(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s3*/, int Data /*stack 8*/)
 // line 2315, offset 0x800aadc4
	/* begin block 1 */
		// Start line: 2316
		// Start offset: 0x800AADC4
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int Moving; // $s7
	// 		int DeferFlag; // $s6
	// 		struct evPhysicsSwimData *SwimData; // $s1

		/* begin block 1.1 */
			// Start line: 2334
			// Start offset: 0x800AAE08
		/* end block 1.1 */
		// End offset: 0x800AAE3C
		// End Line: 2340
	/* end block 1 */
	// End offset: 0x800AB1C4
	// End Line: 2514

	/* begin block 2 */
		// Start line: 4913
	/* end block 2 */
	// End Line: 4914

void StateHandlerGrab(__CharacterState *In,int CurrentSection,int Data)

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
    pLVar3 = STREAM_GetWaterZLevel(In->CharacterInstance->currentStreamUnitID);
    if ((pLVar3->unitFlags & 0x1000U) != 0) {
      DeMessageQueue(&In->SectionList[0].Event,0x100000,0);
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
              if ((Raziel.Senses.heldClass != 3) && ((ControlFlag & 0x2000000U) == 0)) {
                StateSwitchStateData(In,CurrentSection,StateHandlerIdle,3);
              }
            }
            else {
              if ((-0x80000000 < (int)puVar5) && (puVar5 != &DAT_80000008)) goto LAB_800ab1a8;
            }
          }
          else {
            if (puVar5 == (undefined *)0x100000) {
              StateSwitchStateCharacterDataDefault(In,StateHandlerGlyphs,0);
            }
            else {
              if ((int)puVar5 < 0x100001) {
                if (puVar5 != (undefined *)0x40005) {
LAB_800ab1a8:
                  StateHandlerDragObject(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar5 != &DAT_00100001) goto LAB_800ab1a8;
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
                  DeMessageQueue(&p_Var7->Defer,-0x7fffffff,0);
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
            PhysicsMove(instance,-0x10);
          }
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
                if (puVar5 != (undefined *)0x2000000) goto LAB_800ab1a8;
                razPickupAndGrab(In,CurrentSection);
              }
              else {
                if (puVar5 != (undefined *)0x4010008) goto LAB_800ab1a8;
                if (bVar2) {
                  DeMessageQueue(&p_Var7->Event,0x4010008,0);
                  bVar2 = false;
                }
                else {
                  StateSwitchStateData(In,CurrentSection,StateHandlerDeCompression,Data_00);
                }
                In->SectionList[CurrentSection].Data2 = 2;
                PhysicsMode = 3;
                PhysicsMove(In->CharacterInstance,-0x10);
              }
            }
          }
          else {
            if (puVar5 == (undefined *)0x10000000) {
              Data_00 = 1;
            }
            else {
              if ((int)puVar5 < 0x10000001) {
                if (puVar5 != (undefined *)0x8000000) goto LAB_800ab1a8;
              }
              else {
                if (puVar5 != (undefined *)0x20000001) goto LAB_800ab1a8;
                if (((Raziel.Mode != 0x10) && (Raziel.Mode != 0x20)) && (CurrentSection == 0)) {
                  SetDropPhysics(In->CharacterInstance,&Raziel);
                }
              }
            }
          }
        }
      }
    }
    PurgeMessageQueue(&p_Var7->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerSlide(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s3*/)
 // line 2518, offset 0x800ab1f4
	/* begin block 1 */
		// Start line: 2519
		// Start offset: 0x800AB1F4
		// Variables:
	// 		struct __Event *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x800AB3B8
	// End Line: 2575

	/* begin block 2 */
		// Start line: 5326
	/* end block 2 */
	// End Line: 5327

void StateHandlerPuppetShow(__CharacterState *In,int CurrentSection,int Data)

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
LAB_800ab36c:
      Data_00 = SetControlInitIdleData(0,0,3);
      StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,Data_00);
    }
    else {
      if ((int)puVar2 < 0x100001) {
        if (puVar2 != &DAT_80000008) {
          if ((int)puVar2 < -0x7ffffff7) {
            if (-0x7fffffff < (int)puVar2) {
LAB_800ab3a0:
              StateHandlerDragObject(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar2 != &DAT_80000020) goto LAB_800ab3a0;
          }
        }
      }
      else {
        if (puVar2 == (undefined *)0x4010008) goto LAB_800ab36c;
        if ((int)puVar2 < 0x4010009) {
          if (puVar2 == &DAT_00100001) {
            if (CurrentSection == 0) {
              Raziel.Mode = 0x400000;
              ControlFlag = 0x509;
              PhysicsMode = 0;
              PhysicsMove(In->CharacterInstance,-0x10);
              Raziel.soundHandle =
                   SOUND_Play3dSound(&In->CharacterInstance->position,0x1e,0,0x3c,0xdac);
            }
          }
          else {
            if (puVar2 != &DAT_00100004) goto LAB_800ab3a0;
            if (Raziel.soundHandle != 0) {
              SndEndLoop(Raziel.soundHandle);
              Raziel.soundHandle = 0;
            }
          }
        }
        else {
          if ((puVar2 != (undefined *)0x4010200) && (puVar2 != (undefined *)0x20000001))
          goto LAB_800ab3a0;
        }
      }
    }
    PurgeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerBlock(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s4*/, int Data /*$s7*/)
 // line 2585, offset 0x800ab3d4
	/* begin block 1 */
		// Start line: 2586
		// Start offset: 0x800AB3D4
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		int Anim; // $s3

		/* begin block 1.1 */
			// Start line: 2624
			// Start offset: 0x800AB5CC
			// Variables:
		// 		struct _Rotation rot; // stack offset -56
		/* end block 1.1 */
		// End offset: 0x800AB5CC
		// End Line: 2625

		/* begin block 1.2 */
			// Start line: 2640
			// Start offset: 0x800AB658
		/* end block 1.2 */
		// End offset: 0x800AB658
		// End Line: 2641

		/* begin block 1.3 */
			// Start line: 2654
			// Start offset: 0x800AB6F4
			// Variables:
		// 		struct evPhysicsEdgeData *EdgeData; // $s1

			/* begin block 1.3.1 */
				// Start line: 2659
				// Start offset: 0x800AB734
				// Variables:
			// 		struct SVECTOR startVec; // stack offset -56
			// 		struct SVECTOR endVec; // stack offset -48
			/* end block 1.3.1 */
			// End offset: 0x800AB788
			// End Line: 2667
		/* end block 1.3 */
		// End offset: 0x800AB7A8
		// End Line: 2673
	/* end block 1 */
	// End offset: 0x800AB7C0
	// End Line: 2684

	/* begin block 2 */
		// Start line: 5469
	/* end block 2 */
	// End Line: 5470

void StateHandlerBreakOff(__CharacterState *In,int CurrentSection,int Data)

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
    if (puVar4 == &DAT_00100004) {
      COLLIDE_SegmentCollisionOff(In->CharacterInstance,1);
      BlockCount = 0;
      FX_EndPassthruFX(In->CharacterInstance);
    }
    else {
      if ((int)puVar4 < 0x100005) {
        if (puVar4 == (undefined *)0x0) {
          if ((CurrentSection == 0) && (iVar1 != 0x6c)) {
            Data_00 = SetControlInitIdleData(0,0,3);
            StateSwitchStateCharacterDataDefault(In,StateHandlerPickupObject,Data_00);
          }
        }
        else {
          if ((int)puVar4 < 1) {
            if (puVar4 != (undefined *)0x80000000) {
LAB_800ab7a8:
              StateHandlerDragObject(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar4 != &DAT_00100001) goto LAB_800ab7a8;
            if (CurrentSection == 0) {
              Raziel.Mode = 0x800000;
              ControlFlag = (int)&DAT_00008009;
              PhysicsMode = 3;
              SteerSwitchMode(In->CharacterInstance,0);
              G2EmulationSwitchAnimationSync(In,0x51,0,10,1);
            }
            In->SectionList[CurrentSection].Data1 = 0;
          }
        }
      }
      else {
        if (puVar4 == (undefined *)0x4010400) {
          Data_00 = p_Var2->Data;
          if ((((*(u_int *)(Data_00 + 0x20) & 0x20000) != 0) && ((Raziel.Abilities & 1U) != 0)) &&
             (Raziel.CurrentPlane == 2)) {
            PHYSICS_GenericLineCheckMask(0,0,0,&SStack56);
            PHYSICS_GenericLineCheckMask(0,-0x140,0,&SStack48);
            iVar3 = PHYSICS_CheckForValidMove(gameTrackerX.playerInstance,&SStack56,&SStack48,1);
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
            if (puVar4 != (undefined *)0x4000001) goto LAB_800ab7a8;
          }
          else {
            if (puVar4 == (undefined *)0x8000000) {
              if (CurrentSection == 0) {
                if ((iVar1 == 0x52) || (iVar1 == 0x6c)) {
                  Data_00 = SetControlInitIdleData(0,0,3);
                  StateSwitchStateCharacterDataDefault(In,StateHandlerPickupObject,Data_00);
                  if (iVar1 == 0x6c) {
                    razSetPlayerEventHistory(0x10000);
                  }
                }
                else {
                  if (In->SectionList[0].Data1 == 0) {
                    G2EmulationSwitchAnimationSync(In,0x52,0,3,1);
                    Raziel.alarmTable = 0x640;
                    (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5c98;
                  }
                  else {
                    G2EmulationSwitchAnimationSync(In,0x6c,0,5,1);
                    COLLIDE_SegmentCollisionOn(In->CharacterInstance,1);
                    razGetRotFromNormal(&Raziel.Senses.ForwardNormal,(_Rotation *)&SStack56);
                    (In->CharacterInstance->rotation).z = SStack56.vz;
                  }
                }
              }
            }
            else {
              if (puVar4 != (undefined *)0x8000004) goto LAB_800ab7a8;
              if ((Raziel.Senses.EngagedMask & 1) != 0) {
                razGetForwardNormal(In->CharacterInstance,(Raziel.Senses.EngagedList)->instance);
                SetupReaction(In->CharacterInstance,(Raziel.Senses.EngagedList)->instance);
                Data_00 = SetObjectBreakOffData
                                    (-(int)Raziel.Senses.ForwardNormal.x,
                                     -(int)Raziel.Senses.ForwardNormal.y,6,(_Instance *)0x0,0);
                INSTANCE_Query((Raziel.Senses.EngagedList)->instance,0x800000,Data_00);
              }
            }
          }
        }
      }
    }
    PurgeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerDeCompression(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s2*/, int Data /*$s5*/)
 // line 2687, offset 0x800ab7ec
	/* begin block 1 */
		// Start line: 2688
		// Start offset: 0x800AB7EC
		// Variables:
	// 		struct __Event *Ptr; // $s1

		/* begin block 1.1 */
			// Start line: 2694
			// Start offset: 0x800AB8B8
		/* end block 1.1 */
		// End offset: 0x800ABA30
		// End Line: 2733
	/* end block 1 */
	// End offset: 0x800ABB2C
	// End Line: 2773

	/* begin block 2 */
		// Start line: 5679
	/* end block 2 */
	// End Line: 5680

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
          if (instance->zVel < -0x100) goto LAB_800ab980;
          if (((Raziel.Mode & 0x10U) == 0) && (p_Var2->Data != 0)) {
            NewAnim = razSwitchVAnimCharacterSingle(instance,0xc,(int *)0x0,(int *)0x0);
            if (NewAnim != 0) {
              G2EmulationSwitchAnimationSync(In,0x1d,0,0,1);
            }
            goto LAB_800abb1c;
          }
          NewAnim = razSwitchVAnimCharacterSingle(instance,0x1c,(int *)0x0,(int *)0x0);
          if (NewAnim == 0) goto LAB_800abb1c;
          NewAnim = 0x25;
        }
        else {
LAB_800ab980:
          NewAnim = razSwitchVAnimCharacterSingle(In->CharacterInstance,0x2c,(int *)0x0,(int *)0x0);
          if (NewAnim == 0) goto LAB_800abb1c;
          NewAnim = 0x29;
        }
        G2EmulationSwitchAnimationSync(In,NewAnim,0,1,1);
      }
      else {
        pp_Var4[0x47] = (_Instance *)In->SectionList[CurrentSection + -1].Data1;
      }
    }
    else {
      if ((int)puVar3 < 0x100002) {
        if ((puVar3 != (undefined *)0x80000000) && (puVar3 != &DAT_80000020)) goto LAB_800abb14;
      }
      else {
        if (puVar3 == (undefined *)0x8000000) {
          if ((*PadData & 0x100) == 0) {
            if ((*PadData & 0x8000000fU) == 0) {
              NewAnim = SetControlInitIdleData(0,0,4);
              StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,NewAnim);
              Raziel.Mode = 1;
            }
            else {
              if (CurrentSection == 0) {
                NewAnim = G2EmulationQueryAnimation(In,0);
                if (NewAnim != 0x1d) {
                  StateSwitchStateCharacterDataDefault(In,StateHandlerDecodeHold,5);
                  pp_Var4[0x47] = (_Instance *)0x0;
                  goto LAB_800abb1c;
                }
                NewProcess = DefaultPuppetStateHandler;
                goto LAB_800abab8;
              }
            }
          }
          else {
            if (CurrentSection == 0) {
              NewProcess = StateHandlerSwimCoil;
LAB_800abab8:
              StateSwitchStateCharacterDataDefault(In,NewProcess,0);
              pp_Var4[0x47] = (_Instance *)0x0;
              goto LAB_800abb1c;
            }
          }
          pp_Var4[0x47] = (_Instance *)0x0;
        }
        else {
          if ((int)puVar3 < 0x8000001) {
            if (puVar3 == &DAT_00100004) {
              SetPhysicsGravityData(In->CharacterInstance,-0x10,0,0,0);
            }
            else {
LAB_800abb14:
              StateHandlerDragObject(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar3 != (undefined *)0x10000000) goto LAB_800abb14;
          }
        }
      }
    }
LAB_800abb1c:
    PurgeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerGlide(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s3*/, int Data /*stack 8*/)
 // line 2778, offset 0x800abb50
	/* begin block 1 */
		// Start line: 2779
		// Start offset: 0x800ABB50
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int Frame; // $fp
	// 		int Anim; // $s6
	// 		int moving; // $s7

		/* begin block 1.1 */
			// Start line: 2897
			// Start offset: 0x800AC0A8
			// Variables:
		// 		struct evObjectDraftData *draft; // $a2
		/* end block 1.1 */
		// End offset: 0x800AC108
		// End Line: 2904

		/* begin block 1.2 */
			// Start line: 2909
			// Start offset: 0x800AC130
			// Variables:
		// 		struct evPhysicsSwimData *SwimData; // $v0
		/* end block 1.2 */
		// End offset: 0x800AC1C0
		// End Line: 2922
	/* end block 1 */
	// End offset: 0x800AC280
	// End Line: 2974

	/* begin block 2 */
		// Start line: 5878
	/* end block 2 */
	// End Line: 5879

void StateHandlerIdle(__CharacterState *In,int CurrentSection,int Data)

{
  bool bVar1;
  int local_38;
  int iVar2;
  __Event *p_Var3;
  undefined *puVar4;
  u_int uVar5;
  code *NewProcess;
  short z;
  _Instance **pp_Var6;
  __State *p_Var7;
  int local_34;
  
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
          SetExternalForce(&ExternalForces,In->CharacterInstance,10,0,local_38,-0x18);
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
    if (puVar4 != (undefined *)0x4000001) {
      if ((int)puVar4 < 0x4000002) {
        if (puVar4 != &DAT_80000020) {
          if ((int)puVar4 < -0x7fffffdf) {
            if (puVar4 == &DAT_80000004) {
              if (CurrentSection == 1) {
                SetExternalForce(&ExternalForces,In->CharacterInstance,4,0,0x18,-0x18);
              }
              G2EmulatePlayAnimation(In,CurrentSection,0x11,0,5,1);
              pp_Var6[0x47] = (_Instance *)0x0;
              if (((u_int)pp_Var6[0x48] & 1) != 0) {
                razSetPlayerEventHistory(0x4000);
              }
            }
            else {
              if ((int)puVar4 < -0x7ffffffb) {
                if (puVar4 != (undefined *)0x80000000) {
LAB_800ac1c0:
                  StateHandlerDragObject(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar4 != &DAT_80000008) goto LAB_800ac1c0;
              }
            }
          }
          else {
            if (puVar4 == &DAT_00100001) {
              if (CurrentSection == 0) {
                Raziel.Mode = 0x2000;
                ControlFlag = 0x518;
                PhysicsMode = 0;
                SteerSwitchMode(In->CharacterInstance,8);
                DeInitAlgorithmicWings(In->CharacterInstance);
                if (In->CharacterInstance->zVel < 0) {
                  SetPhysicsGravityData(In->CharacterInstance,0,0,0x34,-0x18);
                }
              }
              pp_Var6[0x47] = (_Instance *)0x1;
              pp_Var6[0x48] = (_Instance *)0x0;
              G2EmulatePlayAnimation(In,CurrentSection,0x10,p_Var3->Data,5,1);
            }
            else {
              if ((int)puVar4 < 0x100002) {
                if (puVar4 != (undefined *)0x40005) goto LAB_800ac1c0;
              }
              else {
                if (puVar4 != &DAT_00100004) goto LAB_800ac1c0;
                if (CurrentSection == 0) {
                  InitAlgorithmicWings(In->CharacterInstance);
                }
              }
            }
          }
        }
      }
      else {
        if (puVar4 == (undefined *)0x8000000) {
          if (pp_Var6[0x47] != (_Instance *)0x0) {
            SetAnimationInstanceSwitchData(In,CurrentSection,0x12,0,5,1,4);
            pp_Var6[0x47] = (_Instance *)0x0;
          }
        }
        else {
          if ((int)puVar4 < 0x8000001) {
            if (puVar4 == (undefined *)0x4010008) {
              NewProcess = StateHandlerDeCompression;
LAB_800ac1b0:
              StateSwitchStateData(In,CurrentSection,NewProcess,0);
            }
            else {
              if ((int)puVar4 < 0x4010009) {
                if (puVar4 != (undefined *)0x4000007) goto LAB_800ac1c0;
                if (CurrentSection == 0) {
                  if ((int)(u_int)(ushort)((short *)p_Var3->Data)[4] < In->CharacterInstance->zVel) {
                    z = 0;
                    local_34 = 0;
                  }
                  else {
                    z = *(short *)p_Var3->Data;
                    local_34 = 0xffc;
                  }
                  SetExternalTransitionForce(&__Force_800d5e08,0,0,z,0,local_34);
                  pp_Var6[0x48] = (_Instance *)((u_int)pp_Var6[0x48] | 3);
                  Raziel.playerEvent = Raziel.playerEvent | 0x4000;
                }
              }
              else {
                if (puVar4 != (undefined *)0x4020000) goto LAB_800ac1c0;
                z = *(short *)(p_Var3->Data + 0xe);
                if (((z < 0) && (z != -0x7fff)) && (Raziel.CurrentPlane == 1)) {
                  if (CurrentSection == 0) {
                    SetPhysicsGravityData(In->CharacterInstance,-0x10,0,0,0);
                  }
                  G2EmulatePlayAnimation(In,CurrentSection,0x13,0,4,1);
                  NewProcess = StateHandlerGrab;
                  goto LAB_800ac1b0;
                }
              }
            }
          }
          else {
            if (puVar4 == (undefined *)0x10000000) {
              bVar1 = true;
              if (local_38 != 0x10) {
                if (0 < Raziel.Bearing) {
                  G2EmulatePlayAnimation(In,CurrentSection,0x2b,0,6,1);
                  pp_Var6[0x47] = (_Instance *)0x2;
                }
                if (Raziel.Bearing < 0) {
                  G2EmulatePlayAnimation(In,CurrentSection,0x2c,0,6,1);
                  pp_Var6[0x47] = (_Instance *)0x2;
                }
                bVar1 = true;
                if ((Raziel.Bearing == 0) && (pp_Var6[0x47] == (_Instance *)0x2)) {
                  G2EmulatePlayAnimation(In,CurrentSection,0x12,0,5,1);
                  pp_Var6[0x47] = (_Instance *)0x0;
                  bVar1 = true;
                }
              }
            }
            else {
              if ((int)puVar4 < 0x10000001) {
                if (puVar4 != (undefined *)0x8000003) goto LAB_800ac1c0;
                if (local_38 == 0x10) {
                  SetPhysicsGravityData(In->CharacterInstance,0,0,0x34,-0x18);
                }
              }
              else {
                if (puVar4 == (undefined *)0x20000001) {
                  if (((iVar2 < 0xd) && (local_38 == 0x10)) || ((*PadData & 0x80) != 0)) {
                    DeMessageQueue(&p_Var7->Defer,0x20000001,0);
                  }
                  else {
                    if (CurrentSection == 0) {
                      SetPhysicsGravityData(In->CharacterInstance,-0x10,0,0,0);
                      local_34 = razSwitchVAnimCharacterSingle
                                           (In->CharacterInstance,0x18,(int *)0x0,(int *)0x0);
                      if (local_34 != 0) {
                        G2EmulationSwitchAnimationSync(In,0x24,0,4,1);
                      }
                    }
                    StateSwitchStateCharacterDataDefault(In,StateHandlerGrab,0);
                  }
                }
                else {
                  if (puVar4 != (undefined *)0x20000004) goto LAB_800ac1c0;
                  if (CurrentSection == 0) {
                    SetExternalForce(&ExternalForces,In->CharacterInstance,4,0,0x34,-0x18);
                  }
                  G2EmulatePlayAnimation(In,CurrentSection,0x12,0,5,1);
                  pp_Var6[0x47] = (_Instance *)0x0;
                }
              }
            }
          }
        }
      }
    }
    PurgeMessageQueue(&p_Var7->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerHang(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$fp*/)
 // line 2977, offset 0x800ac2b0
	/* begin block 1 */
		// Start line: 2978
		// Start offset: 0x800AC2B0
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		int Anim; // $s7

		/* begin block 1.1 */
			// Start line: 2990
			// Start offset: 0x800AC470
			// Variables:
		// 		struct evControlInitHangData *data; // $s0
		/* end block 1.1 */
		// End offset: 0x800AC52C
		// End Line: 3016
	/* end block 1 */
	// End offset: 0x800AC7B4
	// End Line: 3126

	/* begin block 2 */
		// Start line: 6287
	/* end block 2 */
	// End Line: 6288

/* WARNING: Type propagation algorithm not settling */

void StateHandlerForcedGlide(__CharacterState *In,int CurrentSection,int Data)

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
            StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,CurrentSection_00);
            Raziel.Mode = 1;
            pp_Var5[0x47] = (_Instance *)0x0;
          }
          else {
            StateSwitchStateData(In,CurrentSection,StateHandlerDecodeHold,10);
            pp_Var5[0x47] = (_Instance *)0x0;
          }
        }
        else {
          if ((int)puVar3 < 0x100001) {
            if (puVar3 != &DAT_80000008) {
              if ((int)puVar3 < -0x7ffffff7) {
                if (puVar3 != (undefined *)0x80000000) goto LAB_800ac79c;
              }
              else {
                if (puVar3 != &DAT_80000020) goto LAB_800ac79c;
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
            }
            else {
              if ((int)puVar3 < 0x100005) {
                if (puVar3 != &DAT_00100001) goto LAB_800ac79c;
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
                G2EmulatePlayAnimation(In,CurrentSection,7,CurrentSection_00,(int)Frames,1);
                pp_Var5[0x47] = (_Instance *)0x0;
              }
              else {
                if (puVar3 != &DAT_00100014) goto LAB_800ac79c;
LAB_800ac730:
                if (CurrentSection == 1) {
                  SetPhysicsGravityData(In->CharacterInstance,-0x10,0,0,0);
                  CurrentSection_00 =
                       razSwitchVAnimCharacterSingle
                                 (In->CharacterInstance,0x18,(int *)0x0,(int *)0x0);
                  if (CurrentSection_00 != 0) {
                    G2EmulationSwitchAnimationSync(In,0x24,0,4,1);
                  }
                  StateSwitchStateCharacterDataDefault(In,StateHandlerGrab,0);
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
LAB_800ac79c:
                StateHandlerDragObject(In,CurrentSection,Data);
              }
            }
            else {
              if (puVar3 != (undefined *)0x4010010) goto LAB_800ac79c;
            }
          }
        }
        else {
          if (puVar3 == (undefined *)0x8000001) {
            if (pp_Var5[0x47] == (_Instance *)0x1) {
              DeMessageQueue(In_00,0x100000,0);
            }
          }
          else {
            if ((int)puVar3 < 0x8000002) {
              if (puVar3 != (undefined *)0x8000000) goto LAB_800ac79c;
              if (pp_Var5[0x47] == (_Instance *)0x1) {
                DeMessageQueue(In_00,0x100000,0);
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
                G2EmulatePlayAnimation(In,CurrentSection_00,NewAnim,0,3,local_2c);
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
                if (puVar3 != (undefined *)0x10000000) goto LAB_800ac79c;
                CurrentSection_00 = p_Var2->Data;
                if (CurrentSection_00 == 0x10000003) {
                  if (iVar1 == 6) goto LAB_800ac730;
                  CurrentSection_00 = p_Var2->Data;
                }
                if ((CurrentSection_00 == 0x10000001) || ((*PadData & 1U) != 0)) {
                  if (pp_Var5[0x47] == (_Instance *)0x0) {
                    G2EmulatePlayAnimation(In,CurrentSection,8,0,2,1);
                    EnMessageQueueData(&p_Var6->Event);
                  }
                  pp_Var5[0x47] = (_Instance *)0x1;
                }
              }
            }
          }
        }
      }
    }
    PurgeMessageQueue(&p_Var6->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerPushObject(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s5*/)
 // line 3129, offset 0x800ac7e4
	/* begin block 1 */
		// Start line: 3130
		// Start offset: 0x800AC7E4
		// Variables:
	// 		struct __Event *Ptr; // $v0

		/* begin block 1.1 */
			// Start line: 3182
			// Start offset: 0x800ACA7C
			// Variables:
		// 		struct evObjectData *data; // $s0
		/* end block 1.1 */
		// End offset: 0x800ACAD4
		// End Line: 3191
	/* end block 1 */
	// End offset: 0x800ACAF0
	// End Line: 3201

	/* begin block 2 */
		// Start line: 6598
	/* end block 2 */
	// End Line: 6599

	/* begin block 3 */
		// Start line: 6601
	/* end block 3 */
	// End Line: 6602

void StateHandlerLookAround(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int CurrentSection_00;
  undefined *puVar2;
  int NewAnim;
  int local_24;
  
  if ((Raziel.Senses.EngagedMask & 3) == 0) {
    DeMessageQueue(&In->SectionList[CurrentSection].Defer,0x100000,0);
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
          if (puVar2 != (undefined *)0x100000) goto LAB_800acad8;
          CurrentSection_00 = SetControlInitIdleData(0,0,6);
          StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,CurrentSection_00);
        }
      }
      else {
        if ((int)puVar2 < 0x8000000) {
LAB_800acad8:
          StateHandlerDragObject(In,CurrentSection,Data);
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
                G2EmulatePlayAnimation(In,CurrentSection_00,NewAnim,0,3,local_24);
                In->SectionList[CurrentSection].Data1 = 1;
                if (CurrentSection == 0) {
                  Raziel.alarmTable = 400;
                  (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5c98;
                }
              }
              else {
                CurrentSection_00 = SetControlInitIdleData(0,0,3);
                StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,CurrentSection_00);
                ControlFlag = ControlFlag | 1;
              }
            }
            else {
              StateSwitchStateData(In,CurrentSection,StateHandlerInitSwim,0);
            }
          }
          else {
            if (puVar2 != (undefined *)0x8000004) goto LAB_800acad8;
            CurrentSection_00 =
                 SetObjectBreakOffData
                           (-(int)Raziel.Senses.ForwardNormal.x,-(int)Raziel.Senses.ForwardNormal.y,
                            6,(_Instance *)0x0,0);
            INSTANCE_Query((Raziel.Senses.EngagedList)->instance,0x800000,CurrentSection_00);
            if (*(int *)(CurrentSection_00 + 0xc) == 0) {
              INSTANCE_Query(In->CharacterInstance,0x100000,0);
            }
          }
        }
      }
    }
    PurgeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerBreakOff(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s3*/, int Data /*$s7*/)
 // line 3204, offset 0x800acb14
	/* begin block 1 */
		// Start line: 3205
		// Start offset: 0x800ACB14
		// Variables:
	// 		struct __Event *Ptr; // $v0

		/* begin block 1.1 */
			// Start line: 3212
			// Start offset: 0x800ACBF0
			// Variables:
		// 		struct PhysObInteractProperties *interactProp; // $s0
		// 		struct _Instance *Inst; // $s1
		// 		int anim; // $a2
		/* end block 1.1 */
		// End offset: 0x800ACD54
		// End Line: 3255

		/* begin block 1.2 */
			// Start line: 3265
			// Start offset: 0x800ACD84
			// Variables:
		// 		struct PhysObInteractProperties *interactProp; // $v0
		// 		int action; // $s1
		// 		int condition; // $v0
		// 		struct _Instance *Inst; // $s0
		/* end block 1.2 */
		// End offset: 0x800ACE3C
		// End Line: 3296
	/* end block 1 */
	// End offset: 0x800ACE88
	// End Line: 3311

	/* begin block 2 */
		// Start line: 6759
	/* end block 2 */
	// End Line: 6760

void StateHandlerStopMove(__CharacterState *In,int CurrentSection,int Data)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  __Event *p_Var4;
  u_long uVar5;
  undefined *puVar6;
  u_int local_38;
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
    if (puVar6 != &DAT_00100004) {
      if ((int)puVar6 < 0x100005) {
        if (puVar6 != (undefined *)0x80000000) {
          if (puVar6 != &DAT_00100001) goto LAB_800ace70;
          if (CurrentSection == 0) {
            if ((Raziel.Senses.EngagedMask & 0x10) == 0) {
              force = Raziel.Senses.EngagedList[0xd].instance;
            }
            else {
              force = Raziel.Senses.EngagedList[4].instance;
            }
            uVar5 = INSTANCE_Post(force,0x15);
            if ((Raziel.Senses.EngagedMask & 0x10) == 0) {
              bVar1 = *(byte *)(uVar5 + 0x13);
            }
            else {
              bVar1 = *(byte *)(uVar5 + 0x12);
            }
            pp_Var8[0x48] = force;
            G2EmulationInstancePlayAnimation(In->CharacterInstance,force,(u_int)bVar1,0,0,1);
            if (*(byte *)(uVar5 + 0x14) != 0xff) {
              Raziel.alarmTable = (ushort)*(byte *)(uVar5 + 0x14) * 100;
              (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5c98;
            }
            uVar2 = *(ushort *)(uVar5 + 0x1c);
            local_38 = (u_int)uVar2;
            ControlFlag = 0x8041108;
            PhysicsMode = 3;
            if (uVar2 == 1) {
              distance = *(short *)(uVar5 + 0x16);
              p_Var7 = In->CharacterInstance;
              local_34 = 0;
LAB_800acd64:
              razAlignYRotMove(force,-distance,&p_Var7->position,&p_Var7->rotation,local_34);
            }
            else {
              if (uVar2 < 2) {
                if (uVar2 == 0) {
                  distance = *(short *)(uVar5 + 0x16);
                  local_38 = 3;
                  local_34 = 0;
LAB_800acd40:
                  razAlignYMoveRot(In->CharacterInstance,force,distance,'\0',local_38,local_34);
                }
              }
              else {
                if (uVar2 == 3) {
                  distance = *(short *)(uVar5 + 0x16);
                  local_34 = 0x800;
                  goto LAB_800acd40;
                }
                if (uVar2 == 4) {
                  distance = *(short *)(uVar5 + 0x16);
                  p_Var7 = In->CharacterInstance;
                  local_34 = 0x800;
                  goto LAB_800acd64;
                }
              }
            }
          }
        }
      }
      else {
        if ((int)puVar6 < 0x8000000) {
LAB_800ace70:
          StateHandlerDragObject(In,CurrentSection,Data);
        }
        else {
          if ((int)puVar6 < 0x8000002) {
            local_34 = SetControlInitIdleData(0,0,3);
            StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,local_34);
          }
          else {
            if (puVar6 != (undefined *)0x8000004) goto LAB_800ace70;
            uVar5 = INSTANCE_Post(pp_Var8[0x48],0x15);
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
              razReaverBladeOff((u_int)uVar2);
            }
            local_34 = SetObjectThrowData(force,0x31,0,0,0,0,(int)(short)uVar2);
            INSTANCE_Query(pp_Var8[0x48],0x800023,local_34);
            if (uVar2 == 1) {
              razReaverOn();
            }
          }
        }
      }
    }
    PurgeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerPullSwitch(struct __CharacterState *In /*$s4*/, int CurrentSection /*$s5*/, int Data /*stack 8*/)
 // line 3314, offset 0x800aceb4
	/* begin block 1 */
		// Start line: 3315
		// Start offset: 0x800ACEB4
		// Variables:
	// 		struct __Event *Ptr; // $s2
	// 		int switchDone; // stack offset -56
	// 		int hitPosted; // stack offset -52

		/* begin block 1.1 */
			// Start line: 3327
			// Start offset: 0x800ACFEC
			// Variables:
		// 		struct PhysObSwitchProperties *switchData; // $fp

			/* begin block 1.1.1 */
				// Start line: 3333
				// Start offset: 0x800AD01C
				// Variables:
			// 		int switchStatus; // $s1
			// 		int switchSuccess; // $s3
			// 		struct _Instance *inst; // $s2
			// 		struct PhysObSwitchProperties *switchProperties; // $s0
			// 		int extraZ; // $s6

				/* begin block 1.1.1.1 */
					// Start line: 3346
					// Start offset: 0x800AD070
				/* end block 1.1.1.1 */
				// End offset: 0x800AD0C8
				// End Line: 3358
			/* end block 1.1.1 */
			// End offset: 0x800AD1F4
			// End Line: 3407
		/* end block 1.1 */
		// End offset: 0x800AD1F4
		// End Line: 3407

		/* begin block 1.2 */
			// Start line: 3413
			// Start offset: 0x800AD204
			// Variables:
		// 		int switchStatus; // $v1
		// 		struct _Instance *inst; // $s0
		// 		struct PhysObSwitchProperties *switchProperties; // $s0
		// 		int switchClass; // $s1
		/* end block 1.2 */
		// End offset: 0x800AD388
		// End Line: 3454

		/* begin block 1.3 */
			// Start line: 3466
			// Start offset: 0x800AD400
			// Variables:
		// 		struct evMonsterHitData *data; // $s0
		/* end block 1.3 */
		// End offset: 0x800AD468
		// End Line: 3477
	/* end block 1 */
	// End offset: 0x800AD494
	// End Line: 3497

	/* begin block 2 */
		// Start line: 6995
	/* end block 2 */
	// End Line: 6996

/* WARNING: Type propagation algorithm not settling */

void StateHandlerMove(__CharacterState *In,int CurrentSection,int Data)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  ushort uVar5;
  __Event *p_Var6;
  u_long uVar7;
  u_long Data_00;
  u_long uVar8;
  u_long uVar9;
  int Data_01;
  undefined *puVar10;
  u_int NewAnim;
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
      uVar7 = INSTANCE_Post(Inst,4);
      Data_00 = INSTANCE_Post(Raziel.Senses.EngagedList[3].instance,0x17);
      uVar8 = INSTANCE_Post(Inst,5);
      if (uVar7 == 6) {
        bVar3 = true;
        if (((*PadData & 0x20) == 0) || (p_Var6->Data != 0)) {
          Data_01 = SetControlInitIdleData(0,0,3);
          StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,Data_01);
          ControlFlag = ControlFlag | 1;
          if (CurrentSection == 0) {
            INSTANCE_Query(Raziel.Senses.EngagedList[3].instance,0x800020,0);
          }
        }
        else {
LAB_800ad3ec:
          DeMessageQueue(&p_Var12->Defer,0x100000,0);
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
          CAMERA_SetShake((u_int)bVar1 + 6);
          G2EmulatePlayAnimation(In,CurrentSection,0x7b,0,6,2);
          if (CurrentSection == 0) {
            INSTANCE_Query(Raziel.Senses.EngagedList[3].instance,0x80002d,0x14);
          }
        }
        else {
          Data_01 = SetControlInitIdleData(0,0,3);
          StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,Data_01);
          ControlFlag = ControlFlag | 1;
        }
      }
    }
    else {
      if ((int)puVar10 < 0x100001) {
        if (puVar10 != &DAT_80000008) {
          if ((int)puVar10 < -0x7ffffff7) {
            if (puVar10 != (undefined *)0x80000000) {
LAB_800ad468:
              StateHandlerDragObject(In,CurrentSection,Data);
            }
          }
          else {
            if ((puVar10 != &DAT_80000010) && (puVar10 != &DAT_80000020)) goto LAB_800ad468;
          }
        }
      }
      else {
        if (puVar10 == (undefined *)0x1000000) {
          Inst = (_Instance *)p_Var6->Data;
          if (bVar3) {
            DeMessageQueue(&p_Var12->Event,0x100000,1);
          }
          if (!bVar4) {
            bVar4 = true;
            Data_01 = SetMonsterImpaleData
                                (*(_Instance **)&Inst->node,*(_Instance **)((int)&Inst->node + 4),
                                 (int)Inst->prev,(int)*(short *)&Inst->next,
                                 (int)*(short *)((int)&Inst->next + 2));
            DeMessageQueue(&p_Var12->Defer,0x1000000,Data_01);
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
                  uVar7 = INSTANCE_Post(Inst,0x17);
                  Data_00 = INSTANCE_Post(Inst,5);
                  uVar8 = INSTANCE_Post(Inst,0x1c);
                  uVar9 = INSTANCE_Post(Inst,4);
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
                    INSTANCE_Query(Inst,0x80002a,Data_00);
                  }
                  if ((Data_00 & 1) == 0) {
                    if ((Data_00 & 2) == 0) {
                      if (*(char *)(uVar7 + 0x16) != -1) {
                        NewAnim = (u_int)*(byte *)(uVar7 + 0x16);
                        goto LAB_800ad158;
                      }
                      goto LAB_800ad148;
                    }
                    if (*(char *)(uVar7 + 0x14) == -1) goto LAB_800ad148;
                    NewAnim = (u_int)*(byte *)(uVar7 + 0x14);
LAB_800ad158:
                    G2EmulationInstancePlayAnimation
                              (In->CharacterInstance,Raziel.Senses.EngagedList[3].instance,NewAnim,0
                               ,0,1);
                  }
                  else {
                    if ((Data_00 & 2) == 0) {
                      if (*(char *)(uVar7 + 0x17) != -1) {
                        NewAnim = (u_int)*(byte *)(uVar7 + 0x17);
                        goto LAB_800ad158;
                      }
                    }
                    else {
                      if (*(char *)(uVar7 + 0x15) != -1) {
                        NewAnim = (u_int)*(byte *)(uVar7 + 0x15);
                        goto LAB_800ad158;
                      }
                    }
LAB_800ad148:
                    bVar2 = false;
                  }
                  if (bVar2) {
                    razAlignYRotMove(Raziel.Senses.EngagedList[3].instance,*(short *)(uVar8 + 8),
                                     &In->CharacterInstance->position,
                                     &In->CharacterInstance->rotation,(int)sVar11);
                    INSTANCE_Query(Raziel.Senses.EngagedList[3].instance,0x800020,0);
                    uVar7 = INSTANCE_Post(Inst,4);
                    if (uVar7 == 9) {
                      razSetPlayerEventHistory(8);
                    }
                    else {
                      razSetPlayerEventHistory(4);
                    }
                  }
                  else {
                    INSTANCE_Query(In->CharacterInstance,0x100000,Data_00);
                  }
                }
              }
            }
            else {
              if (puVar10 != &DAT_00100015) goto LAB_800ad468;
              Data_01 = SetControlInitIdleData(0,0,3);
              StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,Data_01);
            }
          }
          else {
            if (puVar10 != (undefined *)0x1000001) {
              if (puVar10 != (undefined *)0x8000000) goto LAB_800ad468;
              if (CurrentSection != 2) goto LAB_800ad3ec;
              G2EmulatePlayAnimation(In,2,0,0,3,2);
            }
          }
        }
      }
    }
    PurgeMessageQueue(&p_Var12->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerDragObject(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s4*/, int Data /*$fp*/)
 // line 3500, offset 0x800ad4c4
	/* begin block 1 */
		// Start line: 3501
		// Start offset: 0x800AD4C4
		// Variables:
	// 		struct __Event *Ptr; // $s1
	// 		struct _Instance *instance; // $s3
	// 		int anim; // $s0
	// 		int hitPosted; // $s7

		/* begin block 1.1 */
			// Start line: 3544
			// Start offset: 0x800AD6D0
			// Variables:
		// 		struct evPhysicsSlideData *slideData; // stack offset -48

			/* begin block 1.1.1 */
				// Start line: 3549
				// Start offset: 0x800AD6EC
				// Variables:
			// 		struct evObjectData *data; // $s0
			/* end block 1.1.1 */
			// End offset: 0x800AD9D8
			// End Line: 3606
		/* end block 1.1 */
		// End offset: 0x800AD9D8
		// End Line: 3607

		/* begin block 1.2 */
			// Start line: 3663
			// Start offset: 0x800ADB60
			// Variables:
		// 		struct evMonsterHitData *data; // $v0
		/* end block 1.2 */
		// End offset: 0x800ADB60
		// End Line: 3664
	/* end block 1 */
	// End offset: 0x800ADBBC
	// End Line: 3678

	/* begin block 2 */
		// Start line: 7375
	/* end block 2 */
	// End Line: 7376

	/* begin block 3 */
		// Start line: 7381
	/* end block 3 */
	// End Line: 7382

/* WARNING: Type propagation algorithm not settling */

void StateHandlerInitSwim(__CharacterState *In,int CurrentSection,int Data)

{
  bool bVar1;
  __Event *p_Var2;
  int Data_00;
  u_int uVar3;
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
    DeMessageQueue(&In->SectionList[CurrentSection].Defer,0x100000,0);
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
LAB_800adb04:
      Data_00 = SetControlInitIdleData(0,0,3);
      StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,Data_00);
    }
    else {
      if ((int)puVar5 < 0x100001) {
        if (puVar5 != &DAT_80000008) {
          if ((int)puVar5 < -0x7ffffff7) {
            if (-0x7fffffff < (int)puVar5) {
LAB_800adba4:
              StateHandlerDragObject(In,CurrentSection,Data);
            }
          }
          else {
            if ((puVar5 != &DAT_80000010) && (puVar5 != &DAT_80000020)) goto LAB_800adba4;
          }
        }
      }
      else {
        if (puVar5 == (undefined *)0x8000000) {
          if (Data_00 == 0x17) {
            local_34 = SetControlInitIdleData(0,0,3);
            StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,local_34);
          }
          if (Inst == (_Instance *)0x0) goto LAB_800adb04;
          if (CurrentSection == 0) {
            INSTANCE_Query(Inst,0x800004,0);
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
          G2EmulatePlayAnimation(In,Data_00,NewAnim,0,local_38,local_34);
LAB_800adad0:
          if ((*PadData & 0x20) == 0) {
            DeMessageQueue(&p_Var6->Event,0x100000,0);
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
              G2EmulatePlayAnimation(In,CurrentSection,0x14,0,3,1);
            }
            else {
              if (puVar5 != (undefined *)0x1000000) goto LAB_800adba4;
              if (CurrentSection == 0) {
                if (Data_00 == 0x16) {
                  StateSwitchStateCharacterDataDefault(In,StateHandlerHitReaction,p_Var2->Data);
                }
                else {
                  if (!bVar1) {
                    p_Var4 = (_Instance *)p_Var2->Data;
                    bVar1 = true;
                    Data_00 = SetMonsterImpaleData
                                        (*(_Instance **)&p_Var4->node,
                                         *(_Instance **)((int)&p_Var4->node + 4),(int)p_Var4->prev,
                                         (int)*(short *)&p_Var4->next,
                                         (int)*(short *)((int)&p_Var4->next + 2));
                    DeMessageQueue(&In->SectionList[0].Defer,0x1000000,Data_00);
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
                      Data_00 = SetObjectBreakOffData
                                          (-(int)Raziel.Senses.ForwardNormal.y,
                                           (int)Raziel.Senses.ForwardNormal.x,2,(_Instance *)0x0,0);
                      INSTANCE_Query(Inst,0x800000,Data_00);
                      if ((*(u_int *)(Data_00 + 0xc) & 4) != 0) {
                        Data_00 = 0x1e;
LAB_800ad9b8:
                        G2EmulationSwitchAnimationSync(In,Data_00,0,0,1);
                        ControlFlag = ControlFlag & 0xfffffff7;
                      }
                    }
                  }
                  else {
                    if (Data_00 < 0x10000003) {
                      if (Data_00 == 0x10000001) {
                        gameTrackerX.raziel_collide_override = '\0';
                        Data_00 = SetObjectBreakOffData
                                            (-(int)Raziel.Senses.ForwardNormal.x,
                                             -(int)Raziel.Senses.ForwardNormal.y,5,(_Instance *)0x0,
                                             0);
                        INSTANCE_Query(Inst,0x800000,Data_00);
                        if ((*(u_int *)(Data_00 + 0xc) & 4) == 0) {
                          if ((*(u_int *)(Data_00 + 0xc) & 2) != 0) {
                            G2EmulationSwitchAnimationSync(In,0x17,0,3,1);
                            Data_00 = SetObjectBreakOffData
                                                (-(int)Raziel.Senses.ForwardNormal.x,
                                                 -(int)Raziel.Senses.ForwardNormal.y,6,
                                                 (_Instance *)0x0,0);
                            INSTANCE_Query(Inst,0x800000,Data_00);
                          }
                        }
                        else {
                          G2EmulatePlayAnimation(In,2,0,0,3,2);
                          G2EmulatePlayAnimation(In,0,0x2e,0,0,1);
                          Data_00 = 0x2e;
LAB_800ad8c8:
                          G2EmulatePlayAnimation(In,1,Data_00,0,0,1);
                        }
                      }
                    }
                    else {
                      if (Data_00 == 0x10000003) {
                        uVar3 = PHYSOB_CheckSlideNormal
                                          (In->CharacterInstance,(int)Raziel.Senses.ForwardNormal.x,
                                           (int)Raziel.Senses.ForwardNormal.y,apeStack48);
                        if ((uVar3 & 0x4002) == 0x4000) {
                          Data_00 = SetObjectBreakOffData
                                              ((int)Raziel.Senses.ForwardNormal.x,
                                               (int)Raziel.Senses.ForwardNormal.y,4,(_Instance *)0x0
                                               ,0);
                          INSTANCE_Query(Inst,0x800000,Data_00);
                          if ((*(u_int *)(Data_00 + 0xc) & 4) != 0) {
                            G2EmulatePlayAnimation(In,2,0,0,3,2);
                            G2EmulatePlayAnimation(In,0,0x1f,0,0,1);
                            Data_00 = 0x1f;
                            goto LAB_800ad8c8;
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
                          Data_00 = SetObjectBreakOffData
                                              ((int)Raziel.Senses.ForwardNormal.y,
                                               -(int)Raziel.Senses.ForwardNormal.x,3,
                                               (_Instance *)0x0,0);
                          INSTANCE_Query(Inst,0x800000,Data_00);
                          if ((*(u_int *)(Data_00 + 0xc) & 4) != 0) {
                            Data_00 = 0x2d;
                            goto LAB_800ad9b8;
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
                if (puVar5 != (undefined *)0x8000001) goto LAB_800adba4;
                if (((Data_00 == 0) || (Data_00 == 0x16)) || (Data_00 == 0x14)) goto LAB_800adad0;
              }
              else {
                if (puVar5 != (undefined *)0x20000000) goto LAB_800adba4;
              }
            }
          }
        }
      }
    }
    PurgeMessageQueue(&p_Var6->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerPickupObject(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$s4*/)
 // line 3681, offset 0x800adbec
	/* begin block 1 */
		// Start line: 3682
		// Start offset: 0x800ADBEC
		// Variables:
	// 		struct __Event *Ptr; // $v0

		/* begin block 1.1 */
			// Start line: 3690
			// Start offset: 0x800ADC9C
			// Variables:
		// 		long colorArray[1]; // stack offset -32
		/* end block 1.1 */
		// End offset: 0x800ADC9C
		// End Line: 3690
	/* end block 1 */
	// End offset: 0x800ADDB0
	// End Line: 3728

	/* begin block 2 */
		// Start line: 7754
	/* end block 2 */
	// End Line: 7755

void StateHandlerPullSwitch(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int Data_00;
  undefined *puVar2;
  _func_60 *NewProcess;
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
        PhysicsMode = 3;
        FX_DoInstanceOneSegmentGlowWithTime(In->CharacterInstance,0x29,local_20,1,0,0x4b,0x4b,10);
        razSetPlayerEventHistory(0x10);
      }
    }
    else {
      if ((int)puVar2 < 0x100002) {
        if (puVar2 != (undefined *)0x80000000) {
LAB_800add98:
          StateHandlerDragObject(In,CurrentSection,Data);
        }
      }
      else {
        if (puVar2 == &DAT_00100004) {
          if (CurrentSection == 1) {
            ControlFlag = ControlFlag & 0xffffefff;
            FX_UpdateGlowEffect(In->CharacterInstance,0);
          }
        }
        else {
          if (puVar2 != (undefined *)0x8000000) goto LAB_800add98;
          if (CurrentSection == 1) {
            FX_UpdateGlowEffect(In->CharacterInstance,0);
          }
          if ((Raziel.returnState == StateHandlerPickupObject) ||
             (Raziel.returnState == (_func_60 *)0x0)) {
            Data_00 = SetControlInitIdleData(0,0,3);
            NewProcess = StateHandlerPickupObject;
          }
          else {
            Data_00 = 0;
            NewProcess = Raziel.returnState;
          }
          StateSwitchStateData
                    (In,CurrentSection,(TDRFuncPtr_StateSwitchStateData2NewProcess)NewProcess,
                     Data_00);
          Raziel.returnState = (_func_60 *)0x0;
        }
      }
    }
    PurgeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerAutoFace(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*stack 8*/)
 // line 3728, offset 0x800addd0
	/* begin block 1 */
		// Start line: 3729
		// Start offset: 0x800ADDD0
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		int Frames; // $s3
	// 		int Anim; // $s2
	/* end block 1 */
	// End offset: 0x800AE4B8
	// End Line: 3931

	/* begin block 2 */
		// Start line: 7871
	/* end block 2 */
	// End Line: 7872

void StateHandlerPushObject(__CharacterState *In,int CurrentSection,int Data)

{
  int iVar1;
  __Event *p_Var2;
  int local_30;
  undefined *puVar3;
  u_int uVar4;
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
        DeMessageQueue(&In->SectionList[CurrentSection].Event,0x100000,0);
      }
      return;
    }
    puVar3 = (undefined *)p_Var2->ID;
    if (puVar3 == &DAT_00100004) {
      if (CurrentSection == 0) {
LAB_800ae058:
        razSetPauseTranslation(In->CharacterInstance);
      }
    }
    else {
      local_30 = CurrentSection;
      if ((int)puVar3 < 0x100005) {
        if (puVar3 == &DAT_80000002) {
          if (Raziel.Senses.heldClass != 3) {
            Raziel.returnState = StateHandlerPickupObject;
            NewProcess = StateHandlerAttack2;
            goto LAB_800ae420;
          }
        }
        else {
          if ((int)puVar3 < -0x7ffffffd) {
            if (puVar3 == (undefined *)0x80000000) {
              if (CurrentSection == 0) {
                StateSwitchStateCharacterDataDefault(In,StateHandlerHang,0);
              }
            }
            else {
              if (puVar3 != (undefined *)0x80000001) goto LAB_800ae450;
            }
          }
          else {
            if (puVar3 == (undefined *)0x100000) {
LAB_800ae38c:
              local_30 = SetControlInitIdleData(0,0,3);
              StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,local_30);
            }
            else {
              if ((int)puVar3 < 0x100001) {
                if (puVar3 == (undefined *)0x0) {
                  if (2 < iVar1 - 0x5bU) {
                    if (Raziel.nothingCounter == 6) goto LAB_800ae38c;
                    if (iVar1 != 0x37) {
                      local_30 = SetControlInitIdleData(1,0,6);
                      StateInitIdle(In,CurrentSection,local_30);
                    }
                  }
                }
                else {
LAB_800ae450:
                  StateHandlerDragObject(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar3 != &DAT_00100001) goto LAB_800ae450;
                ControlFlag = (int)&LAB_00012108_3;
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
                  G2EmulatePlayAnimation(In,CurrentSection,0x37,0,6,2);
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
          goto LAB_800ae37c;
        }
        if ((int)puVar3 < 0x8000001) {
          if (puVar3 == (undefined *)0x2000000) {
            NewAnim = razPickupAndGrab(In,CurrentSection);
            if (NewAnim != 0) {
              NewProcess = StateHandlerHang;
LAB_800ae420:
              StateSwitchStateData(In,local_30,NewProcess,0);
            }
          }
          else {
            if ((int)puVar3 < 0x2000001) {
              if (puVar3 != (undefined *)0x1000001) goto LAB_800ae450;
              if ((CurrentSection == 1) && (In->CharacterInstance->LinkChild != (_Instance *)0x0)) {
                p_Var2->Data = 0;
              }
              NewAnim = p_Var2->Data;
              local_30 = iVar5;
              if (NewAnim == 0x10001002) {
                if ((iVar1 != 0xf) && (iVar1 != 0x5d)) {
                  NewAnim = 0xf;
                  goto LAB_800ae37c;
                }
                if (((PadData[1] & 0x80) != 0) && (iVar1 != 0x5d)) {
                  SteerSwitchMode(In->CharacterInstance,0xe);
                  local_30 = 0x5d;
                  goto LAB_800ae294;
                }
              }
              else {
                if (NewAnim < 0x10001003) {
                  if (NewAnim == 0x10001001) {
                    if (iVar1 != 0xc) {
                      NewAnim = 0xc;
                      goto LAB_800ae37c;
                    }
                    if (((PadData[1] & 0x80) != 0) &&
                       (StateSwitchStateData(In,CurrentSection,StateHandlerHang,5),
                       CurrentSection == 2)) {
                      StateSwitchStateData(In,1,StateHandlerHang,5);
                    }
                  }
                }
                else {
                  if (NewAnim == 0x10001003) {
                    if ((iVar1 == 0xd) || (iVar1 == 0x5b)) {
                      if (((PadData[1] & 0x80) != 0) && (iVar1 != 0x5b)) {
                        SteerSwitchMode(In->CharacterInstance,0xe);
                        local_30 = 0x5b;
LAB_800ae294:
                        G2EmulatePlayAnimation(In,CurrentSection,local_30,0,0,1);
                      }
                    }
                    else {
                      NewAnim = 0xd;
LAB_800ae37c:
                      G2EmulatePlayAnimation(In,CurrentSection,NewAnim,0,local_30,2);
                    }
                  }
                  else {
                    if (NewAnim == 0x10001004) {
                      if ((iVar1 != 0xe) && (iVar1 != 0x5c)) {
                        NewAnim = 0xe;
                        goto LAB_800ae37c;
                      }
                      if (((PadData[1] & 0x80) != 0) && (iVar1 != 0x5c)) {
                        SteerSwitchMode(In->CharacterInstance,0xe);
                        local_30 = 0x5c;
                        goto LAB_800ae294;
                      }
                    }
                  }
                }
              }
            }
            else {
              if (puVar3 != (undefined *)0x4010080) goto LAB_800ae450;
              if (CurrentSection == 0) {
                if (p_Var2->Data != 0) goto LAB_800ae058;
                razResetPauseTranslation(In->CharacterInstance);
              }
            }
          }
        }
        else {
          if (puVar3 == (undefined *)0x10000000) {
            if ((ControlFlag & 2U) == 0) {
              if (CurrentSection == 0) {
                local_30 = 0;
                NewProcess = StateHandlerDecodeHold;
                goto LAB_800ae420;
              }
              DeMessageQueue(&In->SectionList[0].Event,(int)&DAT_00100005,CurrentSection);
            }
          }
          else {
            if ((int)puVar3 < 0x10000001) {
              if (puVar3 != (undefined *)0x8000003) goto LAB_800ae450;
              if (iVar1 == 0x37) {
                pp_Var6[0x47] = (_Instance *)0x1;
              }
            }
            else {
              if (puVar3 != (undefined *)0x20000004) goto LAB_800ae450;
              if (CurrentSection == 0) {
                Raziel.Senses.LastAutoFace = Raziel.Senses.EngagedList[6].instance;
              }
            }
          }
        }
      }
    }
    PurgeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerGlyphs(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s6*/)
 // line 3937, offset 0x800ae4e8
	/* begin block 1 */
		// Start line: 3938
		// Start offset: 0x800AE4E8
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int hitPosted; // $s5

		/* begin block 1.1 */
			// Start line: 4113
			// Start offset: 0x800AEB90
			// Variables:
		// 		struct _Instance *heldInst; // $s0
		/* end block 1.1 */
		// End offset: 0x800AEBC8
		// End Line: 4122

		/* begin block 1.2 */
			// Start line: 4142
			// Start offset: 0x800AEC88
			// Variables:
		// 		struct evActionPlayHostAnimationData *ptr; // $v0
		/* end block 1.2 */
		// End offset: 0x800AECCC
		// End Line: 4149

		/* begin block 1.3 */
			// Start line: 4152
			// Start offset: 0x800AECCC
			// Variables:
		// 		struct evMonsterHitData *data; // $v1
		/* end block 1.3 */
		// End offset: 0x800AED10
		// End Line: 4161
	/* end block 1 */
	// End offset: 0x800AED40
	// End Line: 4190

	/* begin block 2 */
		// Start line: 8292
	/* end block 2 */
	// End Line: 8293

/* WARNING: Type propagation algorithm not settling */

void StateHandlerWallGrab(__CharacterState *In,int CurrentSection,int Data)

{
  bool bVar1;
  __Event *p_Var2;
  _Instance *p_Var3;
  int Ptr;
  undefined *puVar4;
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
    puVar4 = (undefined *)p_Var2->ID;
    if (puVar4 == (undefined *)0x80007) {
      if (pp_Var5[0x47] != (_Instance *)0x0) {
        if (CurrentSection == 0) {
          razSwitchStringAnimation(In->CharacterInstance,0);
        }
        pp_Var5[0x47] = (_Instance *)0x0;
        if (CurrentSection == 0) {
          SOUND_PlaneShift(In->CharacterInstance);
          if ((Raziel.Mode & 0x40000U) != 0) {
            CAMERA_ChangeTo(&theCamera,In->CharacterInstance);
            SteerSwitchMode(In->CharacterInstance,6);
          }
          SteerSwitchMode(In->CharacterInstance,0);
          if ((Raziel.playerEvent & 0x2000) != 0) {
            razSetPlayerEventHistory(0x2000);
            HINT_KillSpecificHint(0x28);
          }
        }
      }
    }
    else {
      if ((int)puVar4 < 0x80008) {
        if (puVar4 == (undefined *)0x40025) {
LAB_800aed10:
          DeMessageQueue(&p_Var6->Defer,p_Var2->ID,p_Var2->Data);
        }
        else {
          if ((int)puVar4 < 0x40026) {
            if (puVar4 == &DAT_80000010) {
              if (pp_Var5[0x47] != (_Instance *)0x0) {
                if (CurrentSection == 0) {
                  In->SectionList[0].Data1 = 0;
                  INSTANCE_Query(Raziel.GlyphSystem,(int)&DAT_80000010,(int)In->CharacterInstance);
                }
                if ((Raziel.Mode & 0x40000U) == 0) {
                  Ptr = SetControlInitIdleData(0,0,3);
                  StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,Ptr);
                }
                else {
                  StateSwitchStateData(In,CurrentSection,StateHandlerSwimTread,0);
                }
              }
            }
            else {
              if ((int)puVar4 < -0x7fffffef) {
                if (puVar4 == (undefined *)0x80000000) goto LAB_800aeb78;
                if (puVar4 != &DAT_80000008) goto LAB_800aed28;
              }
              else {
                if (puVar4 == (undefined *)0x40003) {
                  p_Var3 = (_Instance *)p_Var2->Data;
                  Ptr = SetActionPlayHostAnimationData
                                  (*(_Instance **)&p_Var3->node,
                                   *(_Instance **)((int)&p_Var3->node + 4),(int)p_Var3->next,
                                   (int)p_Var3->prev,(int)p_Var3->instanceID,(int)p_Var3->flags);
                  ID = p_Var2->ID;
LAB_800aed00:
                  DeMessageQueue(&p_Var6->Defer,ID,Ptr);
                }
                else {
                  if ((int)puVar4 < 0x40004) {
                    if (puVar4 == &DAT_80000020) goto LAB_800aed30;
                  }
                  else {
                    if (puVar4 == (undefined *)0x40005) goto LAB_800aed10;
                  }
LAB_800aed28:
                  StateHandlerDragObject(In,CurrentSection,Data);
                }
              }
            }
          }
          else {
            if (puVar4 == (undefined *)0x80003) {
              if (CurrentSection == 0) {
                razSwitchStringAnimation(In->CharacterInstance,4);
                Raziel.effectsFlags = Raziel.effectsFlags | 4;
                razSetupSoundRamp(In->CharacterInstance,(_SoundRamp *)&Raziel.soundHandle,0x13,600,
                                  0x2ee,0x3c,0x78,0x32000,0xdac);
                Raziel.soundTimerData = 1;
                Raziel.soundTimerNext = 0x32000;
              }
            }
            else {
              if ((int)puVar4 < 0x80004) {
                if (puVar4 == (undefined *)0x80001) {
                  if (CurrentSection == 0) {
                    razSwitchStringAnimation(In->CharacterInstance,1);
                    Raziel.effectsFlags = Raziel.effectsFlags | 4;
                    razSetupSoundRamp(In->CharacterInstance,(_SoundRamp *)&Raziel.soundHandle,0xc,0,
                                      0x7d,0x50,0x50,0x4d000,0xdac);
                    Raziel.soundTimerData = 3;
                    Raziel.soundTimerNext = 0x4d000;
                  }
                }
                else {
                  if (puVar4 != (undefined *)0x80002) goto LAB_800aed28;
                  if (CurrentSection == 0) {
                    razSwitchStringAnimation(In->CharacterInstance,2);
                    pp_Var5[0x47] = (_Instance *)0x0;
                    goto LAB_800aed30;
                  }
                }
              }
              else {
                if (puVar4 != (undefined *)0x80005) {
                  if ((int)puVar4 < 0x80006) {
                    if (CurrentSection != 0) goto LAB_800aeacc;
                    razSwitchStringAnimation(In->CharacterInstance,5);
                    pp_Var5[0x47] = (_Instance *)0x0;
                  }
                  else {
                    if (CurrentSection != 0) goto LAB_800aeacc;
                    razSwitchStringAnimation(In->CharacterInstance,6);
                    pp_Var5[0x47] = (_Instance *)0x0;
                  }
                  goto LAB_800aed30;
                }
                if (CurrentSection == 0) {
                  razSwitchStringAnimation(In->CharacterInstance,3);
                  pp_Var5[0x47] = (_Instance *)0x0;
                  goto LAB_800aed30;
                }
              }
            }
LAB_800aeacc:
            pp_Var5[0x47] = (_Instance *)0x0;
          }
        }
      }
      else {
        if (puVar4 == (undefined *)0x2000000) {
LAB_800aeb78:
          if ((pp_Var5[0x47] != (_Instance *)0x0) && (CurrentSection == 0)) {
            INSTANCE_Query(Raziel.GlyphSystem,-0x80000000,0);
            razReaverOn();
            p_Var3 = razGetHeldItem();
            if (p_Var3 != (_Instance *)0x0) {
              razSetFadeEffect(0,0x1000,0x100);
              Raziel.throwInstance = p_Var3;
            }
            ControlFlag = ControlFlag | 0x4000;
            EnMessageQueueData(&In->SectionList[0].Event);
          }
        }
        else {
          if ((int)puVar4 < 0x2000001) {
            if (puVar4 == &DAT_00100004) {
              if (CurrentSection == 0) {
                razReaverOff();
                Ptr = GlyphIsGlyphOpen(Raziel.GlyphSystem);
                if (Ptr != 0) {
                  INSTANCE_Query(Raziel.GlyphSystem,(int)&DAT_80000010,(int)In->CharacterInstance);
                }
              }
              Raziel.invincibleTimer = 0;
            }
            else {
              if ((int)puVar4 < 0x100005) {
                if (puVar4 == (undefined *)0x100000) {
                  if (pp_Var5[0x47] == (_Instance *)0x0) {
                    if (((Raziel.Mode & 0x40000U) == 0) || (Raziel.CurrentPlane != 1)) {
                      Ptr = SetControlInitIdleData(0,0,3);
                      NewProcess = StateHandlerPickupObject;
                    }
                    else {
                      NewProcess = StateHandlerSwimTread;
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
                  if (puVar4 != &DAT_00100001) goto LAB_800aed28;
                  if (CurrentSection == 0) {
                    if (p_Var2->Data == 0) {
                      INSTANCE_Query(Raziel.GlyphSystem,(int)&DAT_80000010,
                                     (int)In->CharacterInstance);
                    }
                    Raziel.Mode = Raziel.Mode | 1;
                    ControlFlag = 0x1100008;
                    SteerSwitchMode(In->CharacterInstance,0x10);
                    razResetMotion(In->CharacterInstance);
                  }
                  pp_Var5[0x47] = (_Instance *)0x1;
                  PhysicsMode = 3;
                  if (p_Var2->Data != 0) {
                    DeMessageQueue(&p_Var6->Defer,0x80007,0);
                  }
                }
              }
              else {
                if (puVar4 != (undefined *)0x1000000) {
                  if ((int)puVar4 < 0x1000001) {
                    if (puVar4 == &DAT_00100015) goto LAB_800ae80c;
                  }
                  else {
                    if (puVar4 == (undefined *)0x1000001) goto LAB_800aed30;
                  }
                  goto LAB_800aed28;
                }
                p_Var3 = (_Instance *)p_Var2->Data;
                if (!bVar1) {
                  bVar1 = true;
                  Ptr = SetMonsterImpaleData
                                  (*(_Instance **)&p_Var3->node,
                                   *(_Instance **)((int)&p_Var3->node + 4),(int)p_Var3->prev,
                                   (int)*(short *)&p_Var3->next,
                                   (int)*(short *)((int)&p_Var3->next + 2));
                  ID = 0x1000000;
                  goto LAB_800aed00;
                }
              }
            }
          }
          else {
            if (puVar4 != (undefined *)0x4020000) {
              if ((int)puVar4 < 0x4020001) {
                if (puVar4 == (undefined *)0x4000001) {
                  if ((Raziel.Mode & 0x40000U) == 0) {
                    PhysicsMode = 0;
                    SetDropPhysics(In->CharacterInstance,&Raziel);
                  }
                }
                else {
                  if (puVar4 != (undefined *)0x4010200) goto LAB_800aed28;
                }
              }
              else {
                if (puVar4 != (undefined *)0x8000003) {
                  if ((int)puVar4 < 0x8000004) {
                    if (puVar4 == (undefined *)0x8000000) goto LAB_800ae80c;
                  }
                  else {
                    if (puVar4 == (undefined *)0x10000000) {
                      if (CurrentSection == 0) {
                        if ((*PadData & 4U) != 0) {
                          INSTANCE_Query(Raziel.GlyphSystem,0x10000004,p_Var2->Data);
                        }
                        if ((*PadData & 8U) != 0) {
                          INSTANCE_Query(Raziel.GlyphSystem,0x10000002,p_Var2->Data);
                        }
                      }
                      goto LAB_800aed30;
                    }
                  }
                  goto LAB_800aed28;
                }
LAB_800ae80c:
                if (CurrentSection == 0) {
                  CheckStringAnimation(In->CharacterInstance,p_Var2->ID);
                }
              }
            }
          }
        }
      }
    }
LAB_800aed30:
    PurgeMessageQueue(&p_Var6->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ DefaultStateHandler(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$a2*/)
 // line 4248, offset 0x800aed74
	/* begin block 1 */
		// Start line: 4249
		// Start offset: 0x800AED74
		// Variables:
	// 		struct __Event *Ptr; // $s0

		/* begin block 1.1 */
			// Start line: 4266
			// Start offset: 0x800AF000
			// Variables:
		// 		int message; // stack offset -32
		// 		int messageData; // stack offset -28
		/* end block 1.1 */
		// End offset: 0x800AF0AC
		// End Line: 4286

		/* begin block 1.2 */
			// Start line: 4452
			// Start offset: 0x800AF258
			// Variables:
		// 		struct evPhysicsGravityData *ptr; // $v1
		// 		short zRot; // $s0

			/* begin block 1.2.1 */
				// Start line: 4458
				// Start offset: 0x800AF264
				// Variables:
			// 		struct _Position pos1; // stack offset -48
			// 		struct _Position pos2; // stack offset -40
			// 		int diff; // $v0
			/* end block 1.2.1 */
			// End offset: 0x800AF334
			// End Line: 4478
		/* end block 1.2 */
		// End offset: 0x800AF334
		// End Line: 4478

		/* begin block 1.3 */
			// Start line: 4511
			// Start offset: 0x800AF3E0
			// Variables:
		// 		struct evFXHitData *BloodData; // $a0
		// 		struct _SVector Accel; // stack offset -48
		/* end block 1.3 */
		// End offset: 0x800AF3E0
		// End Line: 4512

		/* begin block 1.4 */
			// Start line: 4559
			// Start offset: 0x800AF580
			// Variables:
		// 		struct evPhysicsEdgeData *data; // $s0
		/* end block 1.4 */
		// End offset: 0x800AF5BC
		// End Line: 4565
	/* end block 1 */
	// End offset: 0x800AF664
	// End Line: 4597

	/* begin block 2 */
		// Start line: 8933
	/* end block 2 */
	// End Line: 8934

void StateHandlerDragObject(__CharacterState *In,int CurrentSection,int Data)

{
  short sVar1;
  __Event *p_Var2;
  int NewAnim;
  _G2Bool_Enum _Var3;
  undefined *puVar4;
  code *NewProcess;
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
    StateSwitchStateDataDefault(In,StateHandlerHitReaction,p_Var2->Data);
    CAMERA_StartLookaroundMode(&theCamera);
    return;
  }
  if (0x1000000 < (int)puVar4) {
    if (puVar4 == (undefined *)0x4010200) {
      NewAnim = p_Var2->Data;
      if (CurrentSection != 0) {
        return;
      }
      local_30.x = 0;
      local_30.y = 0;
      local_28.x = *(short *)(NewAnim + 4);
      local_28.y = *(short *)(NewAnim + 6);
      local_28.z = *(short *)(NewAnim + 8);
      sVar1 = MATH3D_AngleFromPosToPos((_Position *)&local_30,&local_28);
      _Var3 = G2Anim_DetachControllerFromSeg(&In->CharacterInstance->anim,1,0xe);
      if (_Var3 != G2FALSE) {
        _G2Anim_FindController(&In->CharacterInstance->anim,1,0xe);
        if (ExtraRot != (_G2SVector3_Type *)0x0) {
          (In->CharacterInstance->rotation).z = (In->CharacterInstance->rotation).z + ExtraRot->z;
        }
        ExtraRot = (_G2SVector3_Type *)0x0;
      }
      p_Var5 = In->CharacterInstance;
      NewAnim = 0x49;
      if (((int)(p_Var5->rotation).z - (int)sVar1) + 0x3ffU < 0x7ff) {
        (p_Var5->rotation).z = sVar1;
      }
      else {
        NewAnim = 0x4d;
        (p_Var5->rotation).z = sVar1 + 0x800;
      }
      G2EmulationSwitchAnimationSync(&Raziel.State,NewAnim,0,6,2);
      In = &Raziel.State;
      NewProcess = StateHandlerPuppetShow;
LAB_800af36c:
      StateSwitchStateDataDefault(In,NewProcess,0);
      return;
    }
    if ((int)puVar4 < 0x4010201) {
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
          NewAnim = razSwitchVAnimCharacterSingle(In->CharacterInstance,0x18,(int *)0x0,(int *)0x0);
          if (NewAnim != 0) {
            G2EmulationSwitchAnimationSync(In,0x24,0,4,1);
          }
          NewProcess = StateHandlerGrab;
          goto LAB_800af36c;
        }
        NewProcess = StateHandlerPushObject;
        local_1c = 0;
      }
      else {
        if (puVar4 == (undefined *)0x4010008) {
          if (PhysicsMode == 3) {
            return;
          }
          PhysicsMode = 3;
          SetPhysicsGravityData(In->CharacterInstance,-0x10,0,0,0);
          return;
        }
        if (0x4010008 < (int)puVar4) {
          if (puVar4 != (undefined *)0x4010010) {
            return;
          }
          iVar6 = p_Var2->Data;
          NewAnim = SetControlInitHangData(*(_Instance **)(iVar6 + 0x18),0,3);
          StateSwitchStateCharacterData(In,CurrentSection,StateHandlerForcedGlide,NewAnim);
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
        NewAnim = razSideMoveSpiderCheck(In->CharacterInstance,-0x80);
        if (NewAnim != 0) {
          return;
        }
        NewAnim = razSideMoveSpiderCheck(In->CharacterInstance,0x80);
        if (NewAnim != 0) {
          return;
        }
        NewProcess = StateHandlerFall;
        local_1c = 0;
      }
    }
    else {
      if (puVar4 == (undefined *)0x8000000) {
        NewAnim = SetControlInitIdleData(0,0,3);
        StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,NewAnim);
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
        NewProcess = StateHandlerBreakOff;
        local_1c = 0;
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
        NewProcess = StateHandlerWallGrab;
        local_1c = 1;
      }
    }
    goto LAB_800af65c;
  }
  if (puVar4 != (undefined *)0x40005) {
    if ((int)puVar4 < 0x40006) {
      if (puVar4 == &DAT_80000008) {
        if (CurrentSection != 0) {
          return;
        }
        StateSwitchStateDataDefault(In,StateHandlerSwimCoil,1);
        return;
      }
      if ((int)puVar4 < -0x7ffffff7) {
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
        NewProcess = StateHandlerHang;
        local_1c = 0;
      }
      else {
        if (puVar4 != &DAT_80000020) {
          if (puVar4 != (undefined *)0x40000) {
            return;
          }
          if (CurrentSection == 2) {
            G2EmulatePlayAnimation(In,2,0,0,3,2);
            return;
          }
          G2EmulatePlayAnimation(In,CurrentSection,0x17,0,3,1);
          return;
        }
        NewAnim = StateHandlerAutoFace(&local_20,&local_1c);
        if (NewAnim == 0) {
          return;
        }
        if (local_20 == 0x800010) {
          NewProcess = StateHandlerWallIdle;
          local_1c = 0;
        }
        else {
          if (local_20 == 0x1000002) {
            NewProcess = StateHandlerJump;
          }
          else {
            if (local_20 != 0x80000) {
              StateSwitchStateCharacterData(In,CurrentSection,StateHandlerHang,0);
              DeMessageQueue(&In->SectionList[CurrentSection].Defer,(int)&DAT_80000020,0);
              return;
            }
            if (CurrentSection == 0) {
              Raziel.playerEvent = Raziel.playerEvent | 0x400;
              razSetPlayerEventHistory(0x400);
              razLaunchForce(In->CharacterInstance);
            }
            NewProcess = StateHandlerWallIdle;
            local_1c = 0;
          }
        }
      }
      goto LAB_800af65c;
    }
    if (puVar4 == &DAT_00100005) {
      NewAnim = p_Var2->Data;
      if (NewAnim == 1) {
        if (In->CharacterInstance->LinkChild != (_Instance *)0x0) {
          G2EmulatePlayAnimation(In,p_Var2->Data,0x32,0,3,2);
          NewProcess = In->SectionList[CurrentSection].Process;
          local_1c = 0;
          CurrentSection = p_Var2->Data;
          goto LAB_800af65c;
        }
        NewAnim = 1;
      }
      G2EmulationInstanceSwitchAnimationAlpha(In,NewAnim,0,3);
      return;
    }
    if (0x100005 < (int)puVar4) {
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
        local_1c = 0;
        NewProcess = Raziel.returnState;
      }
      else {
        if (CurrentSection == 0) {
          Raziel.returnState = (_func_60 *)In->SectionList[0].Process;
          if (Raziel.returnState == StateHandlerAttack2) {
            Raziel.returnState = StateHandlerPickupObject;
          }
          In->SectionList[0].Data1 = Raziel.Mode;
          Raziel.Mode = 0x80000;
        }
        NewProcess = StateHandlerBlock;
        local_1c = 0;
      }
      goto LAB_800af65c;
    }
    if (puVar4 != (undefined *)0x40025) {
      if (puVar4 != (undefined *)0x100000) {
        return;
      }
      NewProcess = (code *)p_Var2->Data;
      if (NewProcess == (TDRFuncPtr_StateSwitchStateDataDefault2NewProcess)0x0) {
        return;
      }
      local_1c = 0;
      goto LAB_800af65c;
    }
  }
  local_1c = p_Var2->Data;
  NewProcess = StateHandlerCrouch;
LAB_800af65c:
  StateSwitchStateCharacterData(In,CurrentSection,NewProcess,local_1c);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ RazielAnimCallback(struct _G2Anim_Type *anim /*$s3*/, int sectionID /*$s1*/, enum _G2AnimCallbackMsg_Enum message /*$s4*/, long messageDataA /*$s5*/, long messageDataB /*stack 16*/, void *data /*stack 20*/)
 // line 4601, offset 0x800af684
	/* begin block 1 */
		// Start line: 4602
		// Start offset: 0x800AF684
		// Variables:
	// 		struct __State *pSection; // $a0
	// 		struct _G2AnimSection_Type *animSection; // $a2

		/* begin block 1.1 */
			// Start line: 4620
			// Start offset: 0x800AF74C
			// Variables:
		// 		struct evAnimationControllerDoneData *ControllerData; // $v1
		/* end block 1.1 */
		// End offset: 0x800AF7D4
		// End Line: 4636

		/* begin block 1.2 */
			// Start line: 4650
			// Start offset: 0x800AF81C
			// Variables:
		// 		struct __AlarmData *data; // $s0
		// 		struct _Instance *inst; // $a0

			/* begin block 1.2.1 */
				// Start line: 4721
				// Start offset: 0x800AFA1C
				// Variables:
			// 		int test; // $a0

				/* begin block 1.2.1.1 */
					// Start line: 4741
					// Start offset: 0x800AFA80
					// Variables:
				// 		struct _SoundRamp *soundRamp; // $t0
				/* end block 1.2.1.1 */
				// End offset: 0x800AFBA8
				// End Line: 4756
			/* end block 1.2.1 */
			// End offset: 0x800AFBA8
			// End Line: 4756
		/* end block 1.2 */
		// End offset: 0x800AFBC0
		// End Line: 4765

		/* begin block 1.3 */
			// Start line: 4769
			// Start offset: 0x800AFBC8

			/* begin block 1.3.1 */
				// Start line: 4774
				// Start offset: 0x800AFBEC
				// Variables:
			// 		struct _Instance *heldInstance; // $s0
			/* end block 1.3.1 */
			// End offset: 0x800AFC2C
			// End Line: 4780
		/* end block 1.3 */
		// End offset: 0x800AFC40
		// End Line: 4789
	/* end block 1 */
	// End offset: 0x800AFC6C
	// End Line: 4804

	/* begin block 2 */
		// Start line: 9660
	/* end block 2 */
	// End Line: 9661

/* WARNING: Type propagation algorithm not settling */

long RazielAnimCallback(_G2Anim_Type *anim,int sectionID,_G2AnimCallbackMsg_Enum message,
                       long messageDataA,long messageDataB,void *data)

{
  short sVar1;
  bool bVar2;
  evAnimationControllerDoneData *ControllerData;
  _Instance *Inst;
  u_long uVar3;
  int iVar4;
  _G2AnimSection_Type *p_Var5;
  long messageDataA_00;
  
  p_Var5 = anim->section + sectionID;
  switch(message) {
  case G2ANIM_MSG_DONE:
    DeMessageQueue(&Raziel.State.SectionList[sectionID].Event,0x8000000,(u_int)p_Var5->keylistID);
    break;
  case G2ANIM_MSG_LOOPPOINT:
    DeMessageQueue(&Raziel.State.SectionList[sectionID].Event,0x8000001,(u_int)p_Var5->keylistID);
    break;
  case G2ANIM_MSG_SECTION_INTERPDONE:
    DeMessageQueue(&Raziel.State.SectionList[sectionID].Event,0x8000003,(u_int)p_Var5->keylistID);
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
          _G2Anim_FindController
                    (&ControllerData->instance->anim,ControllerData->segment,ControllerData->type);
        }
      }
    }
    break;
  case G2ANIM_MSG_SWALARMSET:
    p_Var5->swAlarmTable = (short *)0x0;
    DeMessageQueue(&Raziel.State.SectionList[sectionID].Event,0x8000004,0);
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
          uVar3 = INSTANCE_Post(Inst,2);
          if ((uVar3 & 0x20) == 0) {
            return 0;
          }
          uVar3 = INSTANCE_Post(Inst,3);
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
    switch((int)(((u_int)*(ushort *)messageDataB - 1) * 0x10000) >> 0x10) {
    case 0:
      if (Inst == (_Instance *)0x0) {
        EnableWristCollision(gameTrackerX.playerInstance,(int)*(short *)(messageDataB + 2));
      }
      else {
        INSTANCE_Query(Inst,0x200002,(int)*(short *)(messageDataB + 2));
      }
      break;
    case 1:
      if (Inst == (_Instance *)0x0) {
        DisableWristCollision(gameTrackerX.playerInstance,(int)*(short *)(messageDataB + 2));
      }
      else {
        INSTANCE_Query(Inst,0x200003,(int)*(short *)(messageDataB + 2));
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
        INSTANCE_Query(Inst,0x200005,(int)*(short *)(messageDataB + 2));
      }
      break;
    case 9:
      if (Inst != (_Instance *)0x0) {
        INSTANCE_Query(Inst,0x200006,(int)*(short *)(messageDataB + 2));
      }
      break;
    case 10:
      sVar1 = *(short *)(messageDataB + 2);
      bVar2 = false;
      if (sVar1 == 2) {
        uVar3 = 1;
code_r0x800afa6c:
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
          if (sVar1 == 3) goto code_r0x800afa6c;
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
// unsigned long /*$ra*/ RazielQuery(struct _Instance *instance /*$s0*/, unsigned long Query /*$a1*/)
 // line 4847, offset 0x800afc94
	/* begin block 1 */
		// Start line: 4848
		// Start offset: 0x800AFC94

		/* begin block 1.1 */
			// Start line: 4910
			// Start offset: 0x800AFDA8
			// Variables:
		// 		struct _Normal *Ptr; // $a0
		/* end block 1.1 */
		// End offset: 0x800AFE50
		// End Line: 4926

		/* begin block 1.2 */
			// Start line: 4929
			// Start offset: 0x800AFE50
			// Variables:
		// 		unsigned long ability; // $s0
		/* end block 1.2 */
		// End offset: 0x800AFEC4
		// End Line: 4947

		/* begin block 1.3 */
			// Start line: 4949
			// Start offset: 0x800AFEC4
			// Variables:
		// 		struct PlayerSaveData data; // stack offset -32
		/* end block 1.3 */
		// End offset: 0x800AFF0C
		// End Line: 4966

		/* begin block 1.4 */
			// Start line: 4986
			// Start offset: 0x800AFF64
			// Variables:
		// 		struct evShadowSegmentData *shadowData; // $v0
		/* end block 1.4 */
		// End offset: 0x800AFF80
		// End Line: 4993
	/* end block 1 */
	// End offset: 0x800AFFE0
	// End Line: 5017

	/* begin block 2 */
		// Start line: 9688
	/* end block 2 */
	// End Line: 9689

u_long RazielQuery(_Instance *instance,u_long Query)

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
      return (u_long)(instance->oldMatrix + 0xf);
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
    pLVar1 = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
    iVar3 = Raziel.Abilities;
    p_Var4 = (_Instance *)(Raziel.Abilities & 0x1fc0000);
    if (((pLVar1->unitFlags & 0x800U) != 0) || (iVar2 = RAZIEL_OkToShift(), iVar2 == 0)) {
      p_Var4 = (_Instance *)(iVar3 & 0xfc0000);
    }
    if (((Raziel.Mode & 0x40000U) != 0) || (Raziel.CurrentPlane == 2)) {
      p_Var4 = (_Instance *)((u_int)p_Var4 & 0x1000000);
    }
    break;
  case 0x18:
    p_Var4 = (_Instance *)SetControlSaveDataData(0x18,local_20);
    break;
  case 0x1f:
    p_Var4 = (_Instance *)(int)Raziel.HealthBalls;
    break;
  case 0x20:
    p_Var4 = (_Instance *)(u_int)Raziel.GlyphManaBalls;
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
    p_Var4 = (_Instance *)(u_int)(Raziel.HitPoints == iVar3);
    break;
  case 0x2c:
    p_Var4 = razGetHeldItem();
    break;
  case 0x2d:
    p_Var4 = (_Instance *)(u_int)Raziel.GlyphManaMax;
    break;
  case 0x2e:
    p_Var4 = (_Instance *)Raziel.invincibleTimer;
  }
  return (u_long)p_Var4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RazielPost(struct _Instance *instance /*$s1*/, unsigned long Message /*$s2*/, unsigned long Data /*$s3*/)
 // line 5021, offset 0x800afff0
	/* begin block 1 */
		// Start line: 5022
		// Start offset: 0x800AFFF0
		// Variables:
	// 		int i; // $s0

		/* begin block 1.1 */
			// Start line: 5029
			// Start offset: 0x800B022C
		/* end block 1.1 */
		// End offset: 0x800B0268
		// End Line: 5047

		/* begin block 1.2 */
			// Start line: 5093
			// Start offset: 0x800B02E8
			// Variables:
		// 		struct PlayerSaveData *data; // $s0
		/* end block 1.2 */
		// End offset: 0x800B03A8
		// End Line: 5138

		/* begin block 1.3 */
			// Start line: 5164
			// Start offset: 0x800B045C
		/* end block 1.3 */
		// End offset: 0x800B0470
		// End Line: 5170

		/* begin block 1.4 */
			// Start line: 5190
			// Start offset: 0x800B04D4
		/* end block 1.4 */
		// End offset: 0x800B053C
		// End Line: 5206

		/* begin block 1.5 */
			// Start line: 5209
			// Start offset: 0x800B0544
			// Variables:
		// 		struct _G2AnimSection_Type *animSection; // $v0
		/* end block 1.5 */
		// End offset: 0x800B0564
		// End Line: 5214

		/* begin block 1.6 */
			// Start line: 5218
			// Start offset: 0x800B057C
			// Variables:
		// 		struct _G2AnimSection_Type *animSection; // $v0
		/* end block 1.6 */
		// End offset: 0x800B05A4
		// End Line: 5223

		/* begin block 1.7 */
			// Start line: 5280
			// Start offset: 0x800B06FC
		/* end block 1.7 */
		// End offset: 0x800B072C
		// End Line: 5287

		/* begin block 1.8 */
			// Start line: 5289
			// Start offset: 0x800B072C
		/* end block 1.8 */
		// End offset: 0x800B0758
		// End Line: 5303
	/* end block 1 */
	// End offset: 0x800B0898
	// End Line: 5338

	/* begin block 2 */
		// Start line: 10482
	/* end block 2 */
	// End Line: 10483

void RazielPost(_Instance *instance,u_long Message,u_long Data)

{
  _Instance *instance_00;
  int iVar1;
  int Data_00;
  u_int uVar2;
  u_int uVar3;
  code *NewProcess;
  u_long *puVar4;
  int CurrentSection;
  __MessageQueue *In;
  
  if ((undefined *)Message == &DAT_0010000a) {
    CurrentSection = 0;
    if (Data != 0) {
      Data_00 = 0x1e8;
      do {
        iVar1 = (int)&(instance->node).prev + Data_00;
        CurrentSection = CurrentSection + 1;
        *(u_char *)(iVar1 + 0x1c) = 0;
        *(u_char *)(iVar1 + 0x20) = 0;
        Data_00 = Data_00 + 0x30;
      } while (CurrentSection < 3);
      DeInitAlgorithmicWings(instance);
      razSetPauseTranslation(instance);
      return;
    }
    Data_00 = 0x1e8;
    do {
      iVar1 = (int)&(instance->node).prev + Data_00;
      CurrentSection = CurrentSection + 1;
      *(u_char *)(iVar1 + 0x1c) = 0x800af684;
      *(u_char *)(iVar1 + 0x20) = 0;
      Data_00 = Data_00 + 0x30;
    } while (CurrentSection < 3);
    InitAlgorithmicWings(instance);
    return;
  }
  if (&DAT_0010000a < Message) {
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
    if (Message < 0x200002) {
      if ((undefined *)Message == &DAT_00100012) {
        razReaverOn();
        Raziel.Senses.heldClass = INSTANCE_Post((_Instance *)Data,4);
        uVar3 = 0xfffff7ff;
        uVar2 = Raziel.Mode;
LAB_800b071c:
        Raziel.Mode = uVar2 & uVar3;
        return;
      }
      if (&DAT_00100012 < Message) {
        if ((undefined *)Message == &UNK_00100016) {
          razSetupSoundRamp(instance,(_SoundRamp *)&Raziel.soundHandle,0x33,-200,-200,0x78,0x78,
                            Data << 0xc,0xdac);
          Raziel.soundTimerNext = Data << 0xc;
          Raziel.soundTimerData = 0;
          return;
        }
        if (&UNK_00100016 < Message) {
          if (Message == 0x200000) {
            if ((ControlFlag & 0x40000U) == 0) {
              Raziel.Senses.EngagedMask = 0;
            }
            Raziel.Senses.Flags = Raziel.Senses.Flags & 0xffffff9f;
            return;
          }
        }
        else {
          if ((undefined *)Message == &DAT_00100013) {
            if ((_Instance *)Data == Raziel.soulReaver) {
              return;
            }
            CurrentSection = razReaverOff();
            if (CurrentSection != 0) {
              return;
            }
            Raziel.Senses.heldClass = 0;
            return;
          }
        }
      }
      else {
        if ((undefined *)Message == &DAT_00100010) {
          if (Data != 0) {
            if ((Raziel.Mode & 0x40000000U) != 0) {
              return;
            }
            Raziel.Mode = 0x40000000;
            PhysicsMove(instance,-0x10);
            CurrentSection = 0;
            do {
              Data_00 = SetControlInitIdleData(0,0,3);
              StateSwitchStateData(&Raziel.State,CurrentSection,StateHandlerPickupObject,Data_00);
              CurrentSection = CurrentSection + 1;
            } while (CurrentSection < 3);
            return;
          }
          if ((Raziel.Mode & 0x40000000U) == 0) {
            return;
          }
          uVar2 = 0xbfffffff;
          uVar3 = Raziel.Mode;
          goto LAB_800b071c;
        }
        if ((undefined *)Message == &DAT_00100011) {
          DeMessageQueue(&Raziel.State.SectionList[0].Defer,(int)&DAT_00100011,Data);
          return;
        }
      }
    }
    else {
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
          DeMessageQueue(In,0x4000001,Data);
          CurrentSection = CurrentSection + 1;
          In = (__MessageQueue *)&In[2].Queue[0].Data;
        } while (CurrentSection < 3);
        return;
      }
      if (Message < 0x4000002) {
        if (Message == 0x200004) {
          if ((ControlFlag & 0x40000000U) == 0) {
            return;
          }
          *(u_long *)&instance->collideInfo = Data;
          *(undefined2 *)(Data + 0x2c) = 0;
          RazielAdditionalCollide(instance,&gameTrackerX);
          instance_00 = razGetHeldItem();
          COLLIDE_MoveAllTransforms(instance_00,(SVECTOR *)((int)instance->collideInfo + 0x28));
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
            SOUND_PlaneShift(instance);
            return;
          }
        }
      }
    }
  }
  else {
    if (Message == 0x40012) {
      NewProcess = StateHandlerStumble;
LAB_800b0660:
      StateSwitchStateCharacterDataDefault(&Raziel.State,NewProcess,0);
      return;
    }
    if (Message < 0x40013) {
      if (Message == 0x40006) {
        DrainHealth(Data);
        return;
      }
      if (Message < 0x40007) {
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
          G2EmulationSwitchAnimationSync(&Raziel.State,0x80,0,3,1);
          NewProcess = StateHandlerCannedReaction;
          goto LAB_800b0660;
        }
      }
      else {
        if (Message == 0x4000e) {
          if (Data != 0) {
            Raziel.returnState = StateHandlerGlide;
            StateSwitchStateDataDefault(&Raziel.State,StateHandlerGlide,0);
            GAMELOOP_Reset24FPS();
            return;
          }
          Raziel.Senses.Flags = Raziel.Senses.Flags & 0xffffffef;
          ControlFlag = ControlFlag & 0xfffdffff;
          CurrentSection = SetControlInitIdleData(0,0,3);
          StateSwitchStateDataDefault(&Raziel.State,StateHandlerPickupObject,CurrentSection);
          GAMELOOP_SystemInit();
          return;
        }
        if (Message < 0x4000f) {
          if (Message == 0x40008) {
            DrainMana(Data);
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
        Raziel.forcedGlideSpeed = Data;
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
          RAZIEL_DebugManaSetMax();
          razReaverOff();
          CurrentSection = razGetReaverFromMask(Data);
          razReaverBladeOff(CurrentSection);
          return;
        }
        if (Message == 0x40019) {
          SetMana(Data);
          return;
        }
      }
      else {
        if ((undefined *)Message == &DAT_00100007) {
          puVar4 = *(u_long **)(Data + 4);
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
          if (Message == 0x40024) {
            CurrentSection = aadIsSfxTypePlayingOrRequested(1);
            if (CurrentSection != 0) {
              return;
            }
            SOUND_Play3dSound(&(gameTrackerX.playerInstance)->position,1,0,0x4b,0xdac);
            return;
          }
        }
      }
    }
  }
  CurrentSection = 0;
  In = &Raziel.State.SectionList[0].Defer;
  do {
    DeMessageQueue(In,Message,Data);
    CurrentSection = CurrentSection + 1;
    In = (__MessageQueue *)&In[2].Queue[0].Data;
  } while (CurrentSection < 3);
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ SetStates(struct _Instance *instance /*$s4*/, struct GameTracker *GT /*$s7*/, long *controlCommand /*$s6*/, int AnalogLength /*$a3*/)
 // line 5342, offset 0x800b08b4
	/* begin block 1 */
		// Start line: 5343
		// Start offset: 0x800B08B4
		// Variables:
	// 		int i; // $s1
	// 		int Event; // $s2
	// 		int Data1; // $s3
	// 		static unsigned long LastTime; // offset 0x0
	// 		struct __Event *Ptr; // $v0

		/* begin block 1.1 */
			// Start line: 5449
			// Start offset: 0x800B0AA8
			// Variables:
		// 		struct __Event *message; // $v0
		/* end block 1.1 */
		// End offset: 0x800B0BA0
		// End Line: 5487
	/* end block 1 */
	// End offset: 0x800B0EA0
	// End Line: 5601

	/* begin block 2 */
		// Start line: 11167
	/* end block 2 */
	// End Line: 11168

/* WARNING: Type propagation algorithm not settling */

int StateInitIdle(_Instance *instance,GameTracker *GT,long *controlCommand,int AnalogLength)

{
  __CharacterState *p_Var1;
  u_int Data;
  __Event *Element;
  _Instance *Target;
  int Data_00;
  __MessageQueue *In;
  __Player *p_Var2;
  int iVar3;
  
  Data = GetRCnt(0xf2000000);
  iVar3 = 0;
  Data_00 = 0;
  LastTime_360 = Data & 0xffff | gameTimer << 0x10;
  LoopCounter = LoopCounter + 1;
  gameTracker = GT;
  PadData = controlCommand;
  do {
    while( true ) {
      Element = PurgeMessageQueue((__MessageQueue *)
                                  ((int)&Raziel.State.SectionList[0].Defer.Head + Data_00));
      if (Element == (__Event *)0x0) break;
      InitMessageQueue((__MessageQueue *)((int)&Raziel.State.SectionList[0].Event.Head + Data_00),
                       Element);
    }
    iVar3 = iVar3 + 1;
    Data_00 = Data_00 + 0x11c;
  } while (iVar3 < 3);
  if ((*(int *)&instance->offset == 0) && ((instance->offset).z == 0)) {
    (instance->position).x = (instance->position).x + Raziel.collisionEdgeOffset.x;
    (instance->position).y = (instance->position).y + Raziel.collisionEdgeOffset.y;
    (instance->position).z = (instance->position).z + Raziel.collisionEdgeOffset.z;
  }
  else {
    INSTANCE_Query(instance,0x4000004,LoopCounter);
    SetImpulsePhysics(instance,&Raziel);
  }
  if (Raziel.Senses.HitMonster != (_Instance *)0x0) {
    Data_00 = SetMonsterImpaleData
                        (Raziel.Senses.HitMonster,(_Instance *)0x0,0x1000,
                         (u_int)(Raziel.attack)->knockBackDistance,
                         (u_int)(Raziel.attack)->knockBackFrames);
    INSTANCE_Query(instance,0x2000002,Data_00);
    DisableWristCollision(instance,1);
    DisableWristCollision(instance,2);
  }
  if (((gameTrackerX.playerInstance)->flags & 0x100U) == 0) {
    if ((ControlFlag & 0x800000U) == 0) {
      GetControllerMessages(controlCommand);
      while (Element = PurgeMessageQueue(&Raziel.padCommands), Element != (__Event *)0x0) {
        Data_00 = Element->ID;
        if ((Data_00 == -0x80000000) &&
           (((Raziel.Senses.EngagedMask & 0x681f) != 0 ||
            (((Raziel.Senses.EngagedMask & 0x20) != 0 &&
             (Target = razGetHeldItem(), Target == (_Instance *)0x0)))))) {
          Data_00 = 0x2000000;
        }
        iVar3 = 0;
        p_Var1 = &Raziel.State;
        if (Data_00 != 0) {
          do {
            In = &p_Var1->SectionList[0].Event;
            DeMessageQueue(In,Data_00,0);
            iVar3 = iVar3 + 1;
            p_Var1 = (__CharacterState *)(In + 2);
          } while (iVar3 < 3);
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
      iVar3 = 0;
      p_Var1 = &Raziel.State;
      do {
        In = &p_Var1->SectionList[0].Event;
        DeMessageQueue(In,Data_00,Data);
        iVar3 = iVar3 + 1;
        p_Var1 = (__CharacterState *)(In + 2);
      } while (iVar3 < 3);
    }
    else {
      PadData = (long *)0x0;
      Data_00 = 0;
      p_Var1 = &Raziel.State;
      do {
        In = &p_Var1->SectionList[0].Event;
        DeMessageQueue(In,0,0);
        Data_00 = Data_00 + 1;
        p_Var1 = (__CharacterState *)(In + 2);
      } while (Data_00 < 3);
    }
  }
  razSetPlayerEvent();
  G2EmulationInstanceSetAnimSpeed(&Raziel.State);
  p_Var2 = &Raziel;
  Data_00 = 0;
  do {
    p_Var1 = &p_Var2->State;
    p_Var2 = (__Player *)&(p_Var2->State).SectionList[0].Defer.Queue[0xf].Data;
    iVar3 = Data_00 + 1;
    (*p_Var1->SectionList[0].Process)(0x800d5748,Data_00);
    Data_00 = iVar3;
  } while (iVar3 < 3);
  if (gameTracker->cheatMode == '\x01') {
    PhysicsMode = 3;
  }
  ProcessPhysicalObject(&Raziel,&Raziel.State,0,PhysicsMode);
  if ((*PadData & 0x200) == 0) {
    Raziel.nothingCounter = Raziel.nothingCounter + 1;
    if (Raziel.nothingCounter < 6) {
      if (((Raziel.Senses.EngagedMask & 0x40) != 0) &&
         (Data_00 = 0, (Raziel.Mode & 0x2000000U) == 0)) {
        p_Var1 = &Raziel.State;
        do {
          In = &p_Var1->SectionList[0].Event;
          DeMessageQueue(In,0x1000001,0);
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
        DeMessageQueue(In,0x1000001,0);
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
      if ((Raziel.Senses.Flags & 0x10U) == 0) goto LAB_800b0e5c;
    }
    else {
      Target = Raziel.Senses.EngagedList[10].instance;
    }
    AlgorithmicNeck(instance,Target);
  }
LAB_800b0e5c:
  if (((ControlFlag & 0x200000U) != 0) && (gameTrackerX.gameFramePassed != 0)) {
    FX_ConstrictProcess();
  }
  if (Raziel.effectsFlags != 0) {
    ProcessEffects(instance);
  }
  ProcessInteractiveMusic(instance);
  ProcessSpecialAbilities(instance);
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessConstrict()
 // line 5616, offset 0x800b0ee0
	/* begin block 1 */
		// Start line: 5617
		// Start offset: 0x800B0EE0

		/* begin block 1.1 */
			// Start line: 5658
			// Start offset: 0x800B0FE4
			// Variables:
		// 		int i; // $s0

			/* begin block 1.1.1 */
				// Start line: 5706
				// Start offset: 0x800B10AC
				// Variables:
			// 		int thisIndex; // $v1
			// 		int nextIndex; // $v0
			/* end block 1.1.1 */
			// End offset: 0x800B1110
			// End Line: 5727
		/* end block 1.1 */
		// End offset: 0x800B1194
		// End Line: 5749
	/* end block 1 */
	// End offset: 0x800B1194
	// End Line: 5780

	/* begin block 2 */
		// Start line: 11801
	/* end block 2 */
	// End Line: 11802

	/* begin block 3 */
		// Start line: 11804
	/* end block 3 */
	// End Line: 11805

/* WARNING: Unknown calling convention yet parameter storage is locked */

void FX_ConstrictProcess(void)

{
  ushort uVar1;
  u_long uVar2;
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
      if (0xc7ffe < uVar2 - 1) {
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
 // line 5783, offset 0x800b11a4
	/* begin block 1 */
		// Start line: 5784
		// Start offset: 0x800B11A4
		// Variables:
	// 		int i; // $a2
	/* end block 1 */
	// End offset: 0x800B12FC
	// End Line: 5812

	/* begin block 2 */
		// Start line: 12183
	/* end block 2 */
	// End Line: 12184

	/* begin block 3 */
		// Start line: 12188
	/* end block 3 */
	// End Line: 12189

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
 // line 5812, offset 0x800b1304
	/* begin block 1 */
		// Start line: 5813
		// Start offset: 0x800B1304
		// Variables:
	// 		struct _Instance *heldInst; // $s2

		/* begin block 1.1 */
			// Start line: 5864
			// Start offset: 0x800B1438
			// Variables:
		// 		int step; // $v1
		/* end block 1.1 */
		// End offset: 0x800B1510
		// End Line: 5903
	/* end block 1 */
	// End offset: 0x800B1510
	// End Line: 5905

	/* begin block 2 */
		// Start line: 12259
	/* end block 2 */
	// End Line: 12260

void ProcessEffects(_Instance *instance)

{
  u_int uVar1;
  _Instance *p_Var2;
  int iVar3;
  int iVar4;
  _Instance *p_Var5;
  
  p_Var2 = razGetHeldItem();
  if (((Raziel.effectsFlags & 4U) != 0) &&
     (iVar3 = SOUND_UpdateSound(instance,(_SoundRamp *)&Raziel.soundHandle), iVar3 == 0)) {
    SndEndLoop(Raziel.soundHandle);
    Raziel.soundHandle = 0;
    Raziel.effectsFlags = Raziel.effectsFlags & 0xfffffffb;
  }
  if (((Raziel.effectsFlags & 8U) != 0) &&
     (iVar3 = SOUND_UpdateSound(instance,(_SoundRamp *)&Raziel.soundHandle2), iVar3 == 0)) {
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
    iVar4 = (u_int)(ushort)p_Var5->fadeValue + iVar3;
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
 // line 5909, offset 0x800b1528
	/* begin block 1 */
		// Start line: 5910
		// Start offset: 0x800B1528
		// Variables:
	// 		long hint; // $s0
	/* end block 1 */
	// End offset: 0x800B163C
	// End Line: 5965

	/* begin block 2 */
		// Start line: 12459
	/* end block 2 */
	// End Line: 12460

/* WARNING: Unknown calling convention yet parameter storage is locked */

void ProcessHints(void)

{
  long lVar1;
  
  lVar1 = HINT_GetCurrentHint();
  if ((Raziel.playerEventHistory & 0x2000) == 0) {
    if ((Raziel.playerEvent & 0x2000) == 0) {
      if (lVar1 == 0xc) {
        HINT_KillSpecificHint(0xc);
      }
    }
    else {
      if (lVar1 == -1) {
        HINT_StartHint(0xc);
      }
      if ((lVar1 == 0xc) && (Raziel.State.SectionList[0].Process == StateHandlerWallGrab)) {
        HINT_KillSpecificHint(0xc);
        HINT_StartHint(0x28);
      }
      if ((lVar1 == 0x28) && (Raziel.State.SectionList[0].Process != StateHandlerWallGrab)) {
        HINT_KillSpecificHint(0x28);
        HINT_StartHint(0xc);
      }
    }
  }
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
 // line 5970, offset 0x800b164c
	/* begin block 1 */
		// Start line: 5971
		// Start offset: 0x800B164C
		// Variables:
	// 		struct Level *level; // $s1

		/* begin block 1.1 */
			// Start line: 5988
			// Start offset: 0x800B16F8
		/* end block 1.1 */
		// End offset: 0x800B171C
		// End Line: 5995
	/* end block 1 */
	// End offset: 0x800B17E8
	// End Line: 6044

	/* begin block 2 */
		// Start line: 12581
	/* end block 2 */
	// End Line: 12582

void ProcessInteractiveMusic(_Instance *instance)

{
  Level *pLVar1;
  u_int uVar2;
  int modifier;
  
  pLVar1 = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
  RAZIEL_SetInteractiveMusic(6,pLVar1->unitFlags & 2);
  RAZIEL_SetInteractiveMusic(9,pLVar1->unitFlags & 0x200);
  RAZIEL_SetInteractiveMusic(10,pLVar1->unitFlags & 0x100);
  RAZIEL_SetInteractiveMusic(7,pLVar1->unitFlags & 0x40);
  RAZIEL_SetInteractiveMusic(8,pLVar1->unitFlags & 0x80);
  RAZIEL_SetInteractiveMusic(0xb,pLVar1->unitFlags & 0x400);
  RAZIEL_SetInteractiveMusic(0xe,pLVar1->unitFlags & 0x4000);
  if (((pLVar1->unitFlags & 2U) != 0) && ((pLVar1->unitFlags & 0xc0U) == 0)) {
    uVar2 = GAMELOOP_GetTimeOfDay();
    RAZIEL_SetInteractiveMusic(7,(u_int)((uVar2 ^ 0x76c) != 0));
    RAZIEL_SetInteractiveMusic(8,(u_int)((uVar2 ^ 0x76c) == 0));
  }
  RAZIEL_SetInteractiveMusic(0xc,(u_int)(Raziel.CurrentPlane == 2));
  RAZIEL_SetInteractiveMusic(5,Raziel.Mode & 0x40000);
  uVar2 = pLVar1->unitFlags;
  if (((uVar2 & 0x10) == 0) && ((Raziel.Mode & 0x2000000U) == 0)) {
    if (((uVar2 & 8) == 0) && ((Raziel.Senses.Flags & 0x20U) == 0)) {
      if ((uVar2 & 4) == 0) {
        modifier = 4;
        if ((uVar2 & 0x20) == 0) {
          Raziel.soundModifier = Raziel.soundModifier & 0xffffffe1;
          SOUND_ResetMusicModifier(0);
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
 // line 6048, offset 0x800b17fc
	/* begin block 1 */
		// Start line: 12737
	/* end block 1 */
	// End Line: 12738

	/* begin block 2 */
		// Start line: 12738
	/* end block 2 */
	// End Line: 12739

void ProcessTimers(_Instance *instance)

{
  _SoundRamp *sound;
  int sfx;
  int startPitch;
  int local_30;
  
  if ((0 < Raziel.timeAccumulator) &&
     (Raziel.timeAccumulator = Raziel.timeAccumulator - gameTrackerX.timeMult,
     Raziel.timeAccumulator < 1)) {
    INSTANCE_Query(instance,(int)&DAT_00100015,-Raziel.timeAccumulator);
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
    goto LAB_800b1a6c;
  case 2:
    razSetupSoundRamp(instance,(_SoundRamp *)&Raziel.soundHandle,0x13,1000,1000,0x78,0,0x3c000,0xdac
                     );
    sound = (_SoundRamp *)&Raziel.soundHandle2;
    sfx = 0x14;
    startPitch = 0x406;
    local_30 = 0x406;
    goto LAB_800b1cd0;
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
LAB_800b1a6c:
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
    local_30 = -200;
LAB_800b1cd0:
    razSetupSoundRamp(instance,sound,sfx,startPitch,local_30,0x78,0,0x3c000,0xdac);
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
 // line 6153, offset 0x800b1d1c
	/* begin block 1 */
		// Start line: 12959
	/* end block 1 */
	// End Line: 12960

	/* begin block 2 */
		// Start line: 12960
	/* end block 2 */
	// End Line: 12961

void CAMERA_SetShake(int ticks)

{
  Raziel.timeAccumulator = ticks << 0xc;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ProcessSpecialAbilities(struct _Instance *instance /*$s1*/)
 // line 6161, offset 0x800b1d2c
	/* begin block 1 */
		// Start line: 6162
		// Start offset: 0x800B1D2C
		// Variables:
	// 		unsigned long reaver; // $s0

		/* begin block 1.1 */
			// Start line: 6169
			// Start offset: 0x800B1D5C
			// Variables:
		// 		unsigned long temp; // $a0
		/* end block 1.1 */
		// End offset: 0x800B1D7C
		// End Line: 6178

		/* begin block 1.2 */
			// Start line: 6202
			// Start offset: 0x800B1DC0
			// Variables:
		// 		struct Object *soulReaverOb; // $a1

			/* begin block 1.2.1 */
				// Start line: 6206
				// Start offset: 0x800B1DD0
			/* end block 1.2.1 */
			// End offset: 0x800B1DD0
			// End Line: 6206
		/* end block 1.2 */
		// End offset: 0x800B1DD0
		// End Line: 6206

		/* begin block 1.3 */
			// Start line: 6227
			// Start offset: 0x800B1E28
			// Variables:
		// 		struct Level *level; // $a1
		/* end block 1.3 */
		// End offset: 0x800B1E8C
		// End Line: 6238
	/* end block 1 */
	// End offset: 0x800B1ED0
	// End Line: 6257

	/* begin block 2 */
		// Start line: 12975
	/* end block 2 */
	// End Line: 12976

	/* begin block 3 */
		// Start line: 12979
	/* end block 3 */
	// End Line: 12980

/* WARNING: Removing unreachable block (ram,0x800b1dd0) */

void ProcessSpecialAbilities(_Instance *instance)

{
  bool bVar1;
  u_long Data;
  Level *pLVar2;
  u_int reaverMask;
  
  if ((Raziel.Abilities & 8U) == 0) {
    if (Raziel.soulReaver != (_Instance *)0x0) {
      INSTANCE_UnlinkFromParent(Raziel.soulReaver);
      INSTANCE_NewInstance(Raziel.soulReaver);
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
          pLVar2 = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
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
            razReaverBladeOff(2);
          }
        }
      }
      else {
        INSTANCE_Query(Raziel.soulReaver,0x800103,Data);
        Raziel.currentSoulReaver = Data;
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GetControllerMessages(long *controlCommand /*$s0*/)
 // line 6291, offset 0x800b1ee4
	/* begin block 1 */
		// Start line: 6292
		// Start offset: 0x800B1EE4
	/* end block 1 */
	// End offset: 0x800B20FC
	// End Line: 6346

	/* begin block 2 */
		// Start line: 13239
	/* end block 2 */
	// End Line: 13240

int GetControllerMessages(long *controlCommand)

{
  int ID;
  undefined *ID_00;
  
  ID = -0x80000000;
  if (((controlCommand[1] & 0x20) != 0) || (ID = 0x20000000, (controlCommand[2] & 0x20) != 0)) {
    DeMessageQueue(&Raziel.padCommands,ID,0);
  }
  if ((controlCommand[1] & 0x40) == 0) {
    if ((controlCommand[2] & 0x40) != 0) {
      ID_00 = (undefined *)0x20000002;
      goto LAB_800b1f88;
    }
  }
  else {
    ID_00 = &DAT_80000002;
LAB_800b1f88:
    DeMessageQueue(&Raziel.padCommands,(int)ID_00,0);
  }
  if ((controlCommand[1] & 0x80) == 0) {
    if ((controlCommand[2] & 0x80) != 0) {
      ID = 0x20000001;
      goto LAB_800b1fd8;
    }
  }
  else {
    ID = -0x7fffffff;
LAB_800b1fd8:
    DeMessageQueue(&Raziel.padCommands,ID,0);
  }
  if ((controlCommand[1] & 0x200) == 0) {
    if ((controlCommand[2] & 0x200) != 0) {
      ID_00 = (undefined *)0x20000004;
      goto LAB_800b2028;
    }
  }
  else {
    ID_00 = &DAT_80000004;
LAB_800b2028:
    DeMessageQueue(&Raziel.padCommands,(int)ID_00,0);
  }
  if ((controlCommand[1] & 0x100) == 0) {
    if ((controlCommand[2] & 0x100) != 0) {
      ID_00 = (undefined *)0x20000008;
      goto LAB_800b2078;
    }
  }
  else {
    ID_00 = &DAT_80000008;
LAB_800b2078:
    DeMessageQueue(&Raziel.padCommands,(int)ID_00,0);
  }
  if ((controlCommand[1] & 0x10) == 0) {
    if ((controlCommand[2] & 0x10) == 0) goto LAB_800b20d0;
    ID_00 = (undefined *)0x20000020;
  }
  else {
    ID_00 = &DAT_80000020;
  }
  DeMessageQueue(&Raziel.padCommands,(int)ID_00,0);
LAB_800b20d0:
  if ((controlCommand[1] & 0x8000) != 0) {
    DeMessageQueue(&Raziel.padCommands,(int)&DAT_80000010,0);
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RazielAdditionalCollide(struct _Instance *instance /*$s2*/, struct GameTracker *gameTracker /*$s3*/)
 // line 6430, offset 0x800b2110
	/* begin block 1 */
		// Start line: 6431
		// Start offset: 0x800B2110
		// Variables:
	// 		int rc; // $s0
	// 		int Mode; // $s0
	// 		short Height; // $a1

		/* begin block 1.1 */
			// Start line: 6462
			// Start offset: 0x800B218C
		/* end block 1.1 */
		// End offset: 0x800B2234
		// End Line: 6482

		/* begin block 1.2 */
			// Start line: 6493
			// Start offset: 0x800B2274
			// Variables:
		// 		struct evPhysicsEdgeData *Data; // $s1
		/* end block 1.2 */
		// End offset: 0x800B238C
		// End Line: 6526

		/* begin block 1.3 */
			// Start line: 6544
			// Start offset: 0x800B23A0
			// Variables:
		// 		struct evPhysicsSwimData *swimData; // $s0
		// 		struct _Instance *Inst; // $s1
		/* end block 1.3 */
		// End offset: 0x800B2450
		// End Line: 6563

		/* begin block 1.4 */
			// Start line: 6665
			// Start offset: 0x800B2584
		/* end block 1.4 */
		// End offset: 0x800B25C8
		// End Line: 6670
	/* end block 1 */
	// End offset: 0x800B25C8
	// End Line: 6672

	/* begin block 2 */
		// Start line: 13578
	/* end block 2 */
	// End Line: 13579

	/* begin block 3 */
		// Start line: 13583
	/* end block 3 */
	// End Line: 13584

void MonsterAdditionalCollide(_Instance *instance,GameTracker *gameTracker)

{
  short *psVar1;
  u_int uVar2;
  int Data;
  evPhysicsEdgeData *Data_00;
  _Instance *Inst;
  u_long uVar3;
  u_int uVar4;
  ushort uVar5;
  
  uVar2 = ControlFlag & 8;
  if ((ControlFlag & 0x2000U) != 0) {
    Data = SetPhysics(0,-0x60,(int)Raziel.dropOffHeight,(int)(short)Raziel.slipSlope,0x100);
    PhysicsCheckBlockers(instance,Data,2);
  }
  if (uVar2 == 0) {
    instance->oldTFace = (_TFace *)0x0;
    instance->tface = (_TFace *)0x0;
    instance->tfaceLevel = (void *)0x0;
  }
  else {
    uVar5 = 0x80;
    if (gameTrackerX.cheatMode == '\x01') {
      uVar5 = 0x40;
    }
    Data = (u_int)uVar5 << 0x10;
    if ((int)(short)uVar5 < (int)(instance->oldPos).z - (int)(instance->position).z) {
      Data = ((u_int)(ushort)(instance->oldPos).z - (u_int)(ushort)(instance->position).z) * 0x10000;
    }
    Data = SetPhysicsDropOffData
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
              SetPhysicsDropHeightData
                        (400,-0x100,0x90,0,-0xc4,0x1f2,&Raziel.Senses.ForwardNormal,
                         &Raziel.Senses.AboveNormal,&Raziel.Senses.Delta);
    uVar2 = PhysicsCheckEdgeGrabbing(instance,gameTracker,(int)Data_00,3);
    if ((uVar2 & 6) == 6) {
      SetPhysicsGravityData(instance,0,0,0,0);
      Raziel.Senses.Flags = Raziel.Senses.Flags | 2;
      if (ExtraRot != (_G2SVector3_Type *)0x0) {
        _G2Anim_FindController(&instance->anim,1,0xe);
        psVar1 = &ExtraRot->z;
        ExtraRot = (_G2SVector3_Type *)0x0;
        (instance->rotation).z = (instance->rotation).z + *psVar1;
      }
      if (Data_00 != (evPhysicsEdgeData *)0x0) {
        PhysicsDefaultCheckSwimResponse(instance,Data_00,0);
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
    Data = SetPhysicsDropOffData((u_int)Raziel.Mode >> 0x12 & 1,&Raziel.iVelocity,0x100,0x1a0,0x70);
    WaterStatus = PhysicsCheckSwim(instance,Data,3);
    if (((*(ushort *)(Data + 0x10) & 0x10) != 0) && (Inst != (_Instance *)0x0)) {
      uVar3 = INSTANCE_Post(Inst,4);
      if (uVar3 == 3) {
        G2Anim_SetSpeedAdjustment(&instance->anim,0x800);
      }
    }
    if (((*(ushort *)(Data + 0x10) & 0x20) != 0) && (Inst != (_Instance *)0x0)) {
      uVar3 = INSTANCE_Post(Inst,4);
      if (uVar3 == 3) {
        G2Anim_SetSpeedAdjustment(&instance->anim,0x1000);
      }
    }
  }
  if ((ControlFlag & 0x8000U) != 0) {
    Data = SetPhysicsDropHeightData
                     (0x100,-0x100,0x50,0,-0x68,0,&Raziel.Senses.ForwardNormal,
                      &Raziel.Senses.AboveNormal,&Raziel.Senses.Delta);
    uVar2 = PhysicsCheckDropOff(instance,gameTracker,Data,3);
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
    uVar3 = INSTANCE_Post(Raziel.attachedPlatform,2);
    Data = 2;
    if ((uVar3 & 8) == 0) {
      Data = 0;
    }
    Data = SetPhysicsSlideData(Raziel.attachedPlatform,Data,(_SVector *)0x0,(_SVector *)0x0);
    SetPhysicsLinkedMoveData(instance,Data,5);
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GetEngageEvent(struct _Instance *instance /*$a0*/)
 // line 6673, offset 0x800b25e4
	/* begin block 1 */
		// Start line: 6674
		// Start offset: 0x800B25E4
		// Variables:
	// 		int Ability; // $v1
	/* end block 1 */
	// End offset: 0x800B262C
	// End Line: 6692

	/* begin block 2 */
		// Start line: 14086
	/* end block 2 */
	// End Line: 14087

int GetEngageEvent(_Instance *instance)

{
  u_long uVar1;
  
  if (instance != (_Instance *)0x0) {
    uVar1 = INSTANCE_Post(instance,2);
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
 // line 6695, offset 0x800b263c
	/* begin block 1 */
		// Start line: 6696
		// Start offset: 0x800B263C
		// Variables:
	// 		int FaceAngle; // $s3

		/* begin block 1.1 */
			// Start line: 6712
			// Start offset: 0x800B2680
		/* end block 1.1 */
		// End offset: 0x800B2714
		// End Line: 6721
	/* end block 1 */
	// End offset: 0x800B2714
	// End Line: 6722

	/* begin block 2 */
		// Start line: 14130
	/* end block 2 */
	// End Line: 14131

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
    Data = SetPhysicsDropHeightData
                     (400,-0x100,0x90,0,-0xc4,0x1f2,&Raziel.Senses.ForwardNormal,
                      &Raziel.Senses.AboveNormal,&Raziel.Senses.Delta);
    PhysicsCheckEdgeGrabbing(player,gameTracker,Data,1);
    Data_00 = (evPhysicsEdgeData *)
              SetPhysicsDropHeightData
                        (0,0,0,0,-0x8d,0,&Raziel.Senses.ForwardNormal,(_SVector *)0x0,
                         &Raziel.Senses.Delta);
    PhysicsDefaultCheckSwimResponse(player,Data_00,1);
  }
  (player->position).z = sVar1;
  return (int)sVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CheckHolding(struct _Instance *instance /*$a0*/)
 // line 6748, offset 0x800b2738
	/* begin block 1 */
		// Start line: 14239
	/* end block 1 */
	// End Line: 14240

	/* begin block 2 */
		// Start line: 14240
	/* end block 2 */
	// End Line: 14241

int CheckHolding(_Instance *instance)

{
  return (u_int)(instance->LinkChild != (_Instance *)0x0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ DisableWristCollision(struct _Instance *instance /*$s1*/, int Side /*$s0*/)
 // line 6754, offset 0x800b2744
	/* begin block 1 */
		// Start line: 14251
	/* end block 1 */
	// End Line: 14252

void DisableWristCollision(_Instance *instance,int Side)

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
// void /*$ra*/ EnableWristCollision(struct _Instance *instance /*$s1*/, int Side /*$s0*/)
 // line 6763, offset 0x800b2794
	/* begin block 1 */
		// Start line: 14269
	/* end block 1 */
	// End Line: 14270

void EnableWristCollision(_Instance *instance,int Side)

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
// int /*$ra*/ GetCollisionType(struct _Instance *instance /*$a0*/)
 // line 6900, offset 0x800b27e4
	/* begin block 1 */
		// Start line: 6901
		// Start offset: 0x800B27E4
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $s0
	// 		struct _HSphere *S; // $v0

		/* begin block 1.1 */
			// Start line: 6915
			// Start offset: 0x800B2820
			// Variables:
		// 		struct _Instance *inst; // $v1
		/* end block 1.1 */
		// End offset: 0x800B2820
		// End Line: 6915
	/* end block 1 */
	// End offset: 0x800B2934
	// End Line: 6957

	/* begin block 2 */
		// Start line: 14543
	/* end block 2 */
	// End Line: 14544

int GetPhysObCollisionType(_Instance *instance)

{
  int iVar1;
  _CollideInfo *collideInfo;
  
  collideInfo = (_CollideInfo *)instance->collideInfo;
  if (*(char *)((int)collideInfo->prim0 + 4) == '\t') {
    if (collideInfo->type1 == '\x03') {
      COLLIDE_GetBSPTreeFlag(collideInfo,0x800);
    }
    else {
      *(u_int *)((int)collideInfo->inst1 + 0x14) = *(u_int *)((int)collideInfo->inst1 + 0x14) | 4;
    }
  }
  if ((*(u_int *)&collideInfo->flags & 0xffff0000) == 0x1010000) {
    if ((ControlFlag & 0x1000U) == 0) {
      if ((*(char *)((int)collideInfo->prim0 + 4) != '\t') ||
         (*(char *)((int)collideInfo->prim1 + 4) != '\b')) goto LAB_800b28ec;
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
LAB_800b28ec:
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
 // line 7030, offset 0x800b2944
	/* begin block 1 */
		// Start line: 7031
		// Start offset: 0x800B2944
		// Variables:
	// 		struct Object *GlyphOb; // $a1

		/* begin block 1.1 */
			// Start line: 7036
			// Start offset: 0x800B2958
			// Variables:
		// 		struct _Instance *iGlyph; // $v0
		/* end block 1.1 */
		// End offset: 0x800B296C
		// End Line: 7045
	/* end block 1 */
	// End offset: 0x800B296C
	// End Line: 7052

	/* begin block 2 */
		// Start line: 14803
	/* end block 2 */
	// End Line: 14804

	/* begin block 3 */
		// Start line: 14806
	/* end block 3 */
	// End Line: 14807

/* WARNING: Removing unreachable block (ram,0x800b2958) */
/* WARNING: Removing unreachable block (ram,0x800b2968) */

void InitGlyphSystem(_Instance *instance)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ mdRazielProcess(struct _Instance *playerInstance /*$s0*/, struct GameTracker *gameTracker /*$s2*/, long *controlCommand /*$s1*/)
 // line 7057, offset 0x800b297c
	/* begin block 1 */
		// Start line: 14860
	/* end block 1 */
	// End Line: 14861

void mdRazielProcess(_Instance *playerInstance,GameTracker *gameTracker,long *controlCommand)

{
  ProcessTimers(playerInstance);
  razClearPlayerEvent();
  FX_ProcessRain(controlCommand);
  StateInitIdle(playerInstance,gameTracker,controlCommand,-1);
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
    _GlyphDefaultProcess(Raziel.GlyphSystem,gameTracker);
  }
  Raziel.Abilities = debugRazielFlags1;
  debugRazielFlags1 = debugRazielFlags1 | debugRazielFlags2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RazielProcess(struct _Instance *playerInstance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 7091, offset 0x800b2a38
	/* begin block 1 */
		// Start line: 7092
		// Start offset: 0x800B2A38
	/* end block 1 */
	// End offset: 0x800B2A38
	// End Line: 7092

	/* begin block 2 */
		// Start line: 14934
	/* end block 2 */
	// End Line: 14935

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
 // line 7106, offset 0x800b2a80
	/* begin block 1 */
		// Start line: 14965
	/* end block 1 */
	// End Line: 14966

void RazielInit(_Instance *instance,GameTracker *gameTracker)

{
  u_int uVar1;
  
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
  PadGetState(instance);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RazielCollide(struct _Instance *instance /*$s0*/, struct GameTracker *gameTracker /*$a1*/)
 // line 7172, offset 0x800b2b50
	/* begin block 1 */
		// Start line: 7173
		// Start offset: 0x800B2B50
		// Variables:
	// 		struct _CollideInfo *collideInfo; // $s1

		/* begin block 1.1 */
			// Start line: 7202
			// Start offset: 0x800B2BF4
			// Variables:
		// 		struct SVECTOR *offset; // $a1
		/* end block 1.1 */
		// End offset: 0x800B2CDC
		// End Line: 7223

		/* begin block 1.2 */
			// Start line: 7234
			// Start offset: 0x800B2D3C
			// Variables:
		// 		struct SVECTOR *offset; // $a1
		/* end block 1.2 */
		// End offset: 0x800B2DA4
		// End Line: 7250
	/* end block 1 */
	// End offset: 0x800B2DA4
	// End Line: 7252

	/* begin block 2 */
		// Start line: 15124
	/* end block 2 */
	// End Line: 15125

void RazielAdditionalCollide(_Instance *instance,GameTracker *gameTracker)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  void *pvVar4;
  
  pvVar4 = instance->collideInfo;
  iVar2 = GetPhysObCollisionType(instance);
  if (iVar2 != 1) {
    cVar1 = *(char *)((int)pvVar4 + 7);
    if (cVar1 == '\x01') {
      if ((**(u_int **)((int)pvVar4 + 0xc) & 0x2000) == 0) {
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
      if ((*(u_int *)((int)pvVar4 + 4) & 10) == 0) {
        if ((Raziel.Mode & 0x40000U) == 0) {
          Raziel.collisionEdgeOffset.x =
               Raziel.collisionEdgeOffset.x + *(short *)((int)pvVar3 + 0x28);
          Raziel.collisionEdgeOffset.y =
               Raziel.collisionEdgeOffset.y + *(short *)((int)pvVar3 + 0x2a);
          Raziel.collisionEdgeOffset.z =
               Raziel.collisionEdgeOffset.z + *(short *)((int)pvVar3 + 0x2c);
          return;
        }
        (instance->position).x = (instance->position).x + *(short *)((int)pvVar3 + 0x28);
        (instance->position).y = (instance->position).y + *(short *)((int)pvVar3 + 0x2a);
        (instance->position).z = (instance->position).z + *(short *)((int)pvVar3 + 0x2c);
      }
      else {
        (instance->offset).x = (instance->offset).x + *(short *)((int)pvVar3 + 0x28);
        (instance->offset).y = (instance->offset).y + *(short *)((int)pvVar3 + 0x2a);
        (instance->offset).z = (instance->offset).z + *(short *)((int)pvVar3 + 0x2c);
        (instance->position).x = (instance->position).x + *(short *)((int)pvVar3 + 0x28);
        (instance->position).y = (instance->position).y + *(short *)((int)pvVar3 + 0x2a);
        (instance->position).z = (instance->position).z + *(short *)((int)pvVar3 + 0x2c);
      }
    }
    COLLIDE_MoveAllTransforms(instance,(SVECTOR *)((int)pvVar4 + 0x28));
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_TurnHead(struct _Instance *instance /*$s2*/, short *rotx /*$s0*/, short *rotz /*$s1*/, struct GameTracker *gameTracker /*$a3*/)
 // line 7252, offset 0x800b2db8
	/* begin block 1 */
		// Start line: 7253
		// Start offset: 0x800B2DB8

		/* begin block 1.1 */
			// Start line: 7257
			// Start offset: 0x800B2DFC
			// Variables:
		// 		struct _Rotation rot; // stack offset -40
		/* end block 1.1 */
		// End offset: 0x800B2EE0
		// End Line: 7279

		/* begin block 1.2 */
			// Start line: 7282
			// Start offset: 0x800B2F08
			// Variables:
		// 		struct evActionLookAroundData data; // stack offset -32
		/* end block 1.2 */
		// End offset: 0x800B2FC8
		// End Line: 7300
	/* end block 1 */
	// End offset: 0x800B2FC8
	// End Line: 7302

	/* begin block 2 */
		// Start line: 15297
	/* end block 2 */
	// End Line: 15298

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
    *rotz = *rotz - ((short)((u_longlong)((longlong)gameTrackerX.controlData[0][3] * 0x55555556) >>
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
    *rotz = *rotz - ((short)((u_longlong)((longlong)gameTrackerX.controlData[0][3] * 0x2aaaaaab) >>
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
      CAMERA_SetLookFocusAndBase
                (&theCamera,(int)*rotx + (int)(Raziel.throwData)->coilRot,(int)*rotz);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_SetLookAround(struct _Instance *instance /*$s1*/)
 // line 7302, offset 0x800b2fe0
	/* begin block 1 */
		// Start line: 15417
	/* end block 1 */
	// End Line: 15418

void RAZIEL_SetLookAround(_Instance *instance)

{
  _G2Anim_Type *anim;
  
  anim = &instance->anim;
  G2Anim_DisableController(anim,0x11,0xe);
  G2Anim_DisableController(anim,0x10,0xe);
  G2Anim_DisableController(anim,0xe,0xe);
  INSTANCE_Query(instance,(int)&DAT_00100009,1);
  Raziel.throwXRot = 0;
  Raziel.throwZRot = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ RAZIEL_ResetLookAround(struct _Instance *instance /*$s1*/)
 // line 7331, offset 0x800b3058
	/* begin block 1 */
		// Start line: 15492
	/* end block 1 */
	// End Line: 15493

void PLAYER_ReSetLookAround(_Instance *instance)

{
  _G2Anim_Type *anim;
  
  anim = &instance->anim;
  G2Anim_InterpDisableController(anim,0x11,0xe,300);
  G2Anim_InterpDisableController(anim,0x10,0xe,300);
  G2Anim_InterpDisableController(anim,0xe,0xe,300);
  INSTANCE_Query(instance,(int)&DAT_00100009,0);
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ RAZIEL_OkToLookAround(struct _Instance *playerInstance /*$a0*/)
 // line 7354, offset 0x800b30d4
	/* begin block 1 */
		// Start line: 15550
	/* end block 1 */
	// End Line: 15551

	/* begin block 2 */
		// Start line: 15552
	/* end block 2 */
	// End Line: 15553

long PLAYER_OkToLookAround(_Instance *playerInstance)

{
  if (Raziel.State.SectionList[0].Process == StateHandlerAttack2) {
    return (u_int)((Raziel.Senses.EngagedMask & 0x1000) == 0);
  }
  if (((playerInstance->tface != (_TFace *)0x0) || (playerInstance->attachedID != 0)) &&
     ((Raziel.State.SectionList[0].Process == StateHandlerPickupObject ||
      (((Raziel.State.SectionList[0].Process == StateHandlerSwimTread ||
        (Raziel.State.SectionList[0].Process == StateHandlerSwim)) ||
       (Raziel.State.SectionList[0].Process == StateHandlerWallIdle)))))) {
    return 1;
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ TrailWaterFX(struct _Instance *instance /*$s2*/, int Segment /*$s0*/, int Bubbles /*$s7*/, int Type /*$s6*/)
 // line 7376, offset 0x800b315c
	/* begin block 1 */
		// Start line: 7377
		// Start offset: 0x800B315C
		// Variables:
	// 		struct _SVector Pos; // stack offset -88
	// 		struct _SVector Vel; // stack offset -80
	// 		struct _SVector Accl; // stack offset -72
	// 		int i; // $s4
	// 		int j; // $s1
	// 		struct Level *level; // $s5
	// 		struct __BubbleParams BP; // stack offset -64
	/* end block 1 */
	// End offset: 0x800B34B0
	// End Line: 7423

	/* begin block 2 */
		// Start line: 15594
	/* end block 2 */
	// End Line: 15595

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
  pLVar1 = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
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
            iVar2 = ((u_int)local_58.z - (u_int)*(ushort *)(instance->oldMatrix[Segment].t + 2)) +
                    iVar2 % 10;
            local_50.z = (short)iVar2;
            if (iVar2 * 0x10000 < 1) {
              local_50.z = 1;
            }
            local_40.StartScale = 0xc00;
            local_40.StartScaleRange = 0x100;
            _Stack72.z = 0;
LAB_800b3480:
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
              goto LAB_800b3480;
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





