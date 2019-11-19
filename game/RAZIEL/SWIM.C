#include "THISDUST.H"
#include "SWIM.H"


// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerInitSwim(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$a2*/)
 // line 5, offset 0x8009bfbc
	/* begin block 1 */
		// Start line: 10
	/* end block 1 */
	// End Line: 11

void StateHandlerInitSwim(__CharacterState *In,int CurrentSection,int Data)

{
  long *plVar1;
  
  G2EmulationSwitchAnimation(In,CurrentSection,0x3d,0,9,2);
  StateSwitchStateData(In,CurrentSection,StateHandlerSwimTread,0);
  plVar1 = PadData;
  (&In->CharacterInstance + CurrentSection * 0x47)[0x48] =
       (_Instance *)((uint)(&In->CharacterInstance + CurrentSection * 0x47)[0x48] | 2);
  if ((*plVar1 & 0x80) != 0) {
    EnMessageQueueData(&In->SectionList[CurrentSection].Defer,-0x7fffffff,0);
  }
  if (CurrentSection == 2) {
    Raziel.RotationSegment = 1;
    Raziel.Mode = 0x40000;
    SteerSwitchMode(In->CharacterInstance,6);
    ControlFlag = 0x191;
    CAMERA_ChangeToUnderWater(&theCamera,In->CharacterInstance);
    ExtraRot = &ExtraRotData;
    ExtraRotData.x = 0x80;
                    /* WARNING: Read-only address (ram,0x800d5c4c) is written */
    ExternalForces.Friction = 0xf80;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerSwimCoil(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$a2*/)
 // line 61, offset 0x8009c0d0
	/* begin block 1 */
		// Start line: 62
		// Start offset: 0x8009C0D0
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		struct evPhysicsSwimData *SwimData; // $a0
	// 		int rc; // $s5
	/* end block 1 */
	// End offset: 0x8009C650
	// End Line: 235

	/* begin block 2 */
		// Start line: 114
	/* end block 2 */
	// End Line: 115

void StateHandlerSwimCoil(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int Data_00;
  _Instance *instance;
  int NewAnim;
  _Instance **pp_Var2;
  __State *p_Var3;
  uint uVar4;
  int local_28;
  int local_24;
  
  ControlFlag = ControlFlag & 0xfffff7ff;
  uVar4 = In->SectionList[CurrentSection].Data1;
  if (CurrentSection == 0) {
    if (Raziel.padCommands.Queue[5].Data != 0) {
      razLaunchBubbles(3,3,1);
    }
    if ((Raziel.throwReturnRot & 2U) != 0) {
      razLaunchBubbles(3,6,1);
    }
  }
  p_Var3 = In->SectionList + CurrentSection;
  pp_Var2 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    p_Var1 = PeekMessageQueue(&p_Var3->Event);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    Data_00 = p_Var1->ID;
    if (Data_00 == 0x100014) {
      Data_00 = SetControlInitIdleData(0,0,9);
      StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
LAB_8009c624:
      if (CurrentSection == 0) {
        CAMERA_ChangeToOutOfWater(&theCamera,In->CharacterInstance);
      }
    }
    else {
      if (Data_00 < 0x100015) {
        if (Data_00 == 0x100000) {
          if ((uVar4 & 0x40) == 0) {
            if (CurrentSection == 2) {
              NewAnim = 0x3d;
              local_28 = 3;
              Data_00 = 2;
              local_24 = CurrentSection;
            }
            else {
              NewAnim = 0x3f;
              local_28 = 0x10;
              local_24 = 2;
              Data_00 = CurrentSection;
            }
            G2EmulationSwitchAnimation(In,Data_00,NewAnim,0,local_28,local_24);
            StateSwitchStateData(In,CurrentSection,StateHandlerSwim,0);
            pp_Var2[0x48] = (_Instance *)((uint)pp_Var2[0x48] | 2);
          }
          else {
            StateSwitchStateData(In,CurrentSection,StateHandlerSwimTread,0);
          }
          if (CurrentSection == 0) {
            instance = In->CharacterInstance;
            Data_00 = *(int *)(Raziel.padCommands.Queue[13].ID + 0x7c);
LAB_8009c4d0:
            razSetSwimVelocity(instance,0,Data_00);
          }
        }
        else {
          if (Data_00 < 0x100001) {
            if (((Data_00 == -0x7fffffff) &&
                (Data_00 = G2EmulationQueryAnimation(In,CurrentSection), Data_00 != 0x43)) &&
               (G2EmulationSwitchAnimation(In,CurrentSection,0x43,0,3,1), CurrentSection == 0)) {
              Raziel.padCommands.Queue[8].ID._0_2_ = 300;
              (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5b20;
            }
          }
          else {
            if (Data_00 == 0x100004) {
              if (Raziel.Mode != 0x40000) goto LAB_8009c624;
            }
            else {
              if (Data_00 < 0x100005) {
                if (Data_00 == 0x100001) {
                  if (Raziel.Mode == 0x40000) {
LAB_8009c294:
                    if (CurrentSection == 0) {
                      Raziel.Mode = 0x40000;
                      ControlFlag = 0x111;
                      razSetSwimVelocity(In->CharacterInstance,
                                         *(int *)(Raziel.padCommands.Queue[13].ID + 0x68),
                                         *(int *)(Raziel.padCommands.Queue[13].ID + 0x6c));
                      SetTimer(5);
                    }
                  }
                  else {
                    if (CurrentSection == 0) {
                      CAMERA_ChangeToUnderWater(&theCamera,In->CharacterInstance);
                      goto LAB_8009c294;
                    }
                  }
                  PhysicsMode = 5;
                  G2EmulationSwitchAnimation(In,CurrentSection,0x41,0,9,2);
                  pp_Var2[0x47] = (_Instance *)0x0;
                  Raziel.throwReturnRot = 0;
                }
              }
              else {
                if (Data_00 == 0x100011) {
                  Data_00 = p_Var1->Data;
                  if (Data_00 == *(int *)(Raziel.padCommands.Queue[13].ID + 0x68)) {
                    razSetSwimVelocity(In->CharacterInstance,0,
                                       *(int *)(Raziel.padCommands.Queue[13].ID + 0x70));
                    Data_00 = p_Var1->Data;
                  }
                  if (Data_00 == *(int *)(Raziel.padCommands.Queue[13].ID + 0x74)) {
                    instance = In->CharacterInstance;
                    Data_00 = *(int *)(Raziel.padCommands.Queue[13].ID + 0x7c);
                    goto LAB_8009c4d0;
                  }
                }
              }
            }
          }
        }
      }
      else {
        if (Data_00 == 0x4020000) {
          Data_00 = p_Var1->Data;
          pp_Var2[0x47] = (_Instance *)(int)*(short *)(Data_00 + 0x10);
          if ((Raziel.CurrentPlane == 1) && ((Raziel.Abilities & 0x10U) == 0)) {
            Raziel.HitPoints = 100000;
          }
          else {
            if ((*(ushort *)(Data_00 + 0x10) & 0x220) != 0) {
              if (CurrentSection == 0) {
                Raziel.Mode = 0x10;
                SetPhysics(In->CharacterInstance,-0x10,0,0x15,0xc3);
                SteerSwitchMode(In->CharacterInstance,4);
                Raziel.steeringLockRotation = (int)(In->CharacterInstance->rotation).z;
                Raziel.LastBearing = (In->CharacterInstance->rotation).z;
                SetExternalForce(&ExternalForces,0,0,-0x10,1,0x1000);
                PhysicsMode = 0;
              }
              G2EmulationSwitchAnimation(In,CurrentSection,0x23,0,0,1);
              StateSwitchStateData(In,CurrentSection,StateHandlerJump,0);
            }
          }
        }
        else {
          if (0x4020000 < Data_00) {
            if (Data_00 == 0x8000004) {
              razSetSwimVelocity(In->CharacterInstance,
                                 *(int *)(Raziel.padCommands.Queue[13].ID + 0x74),
                                 *(int *)(Raziel.padCommands.Queue[13].ID + 0x78));
            }
            else {
              if (Data_00 < 0x8000005) {
                if ((Data_00 == 0x8000000) &&
                   (Data_00 = G2EmulationQueryAnimation(In,CurrentSection), Data_00 == 0x43)) {
LAB_8009c3a0:
                  EnMessageQueueData(&p_Var3->Defer,0x100000,0);
                }
              }
              else {
                if ((Data_00 == 0x20000008) &&
                   (Data_00 = G2EmulationQueryAnimation(In,CurrentSection), Data_00 != 0x43))
                goto LAB_8009c3a0;
              }
            }
          }
        }
      }
    }
    DeMessageQueue(&p_Var3->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerSwimTread(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$a2*/)
 // line 239, offset 0x8009c674
	/* begin block 1 */
		// Start line: 240
		// Start offset: 0x8009C674
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		struct evPhysicsSwimData *SwimData; // $s0

		/* begin block 1.1 */
			// Start line: 371
			// Start offset: 0x8009CB6C
			// Variables:
		// 		struct evPhysicsEdgeData *data; // $s0
		/* end block 1.1 */
		// End offset: 0x8009CBB4
		// End Line: 377
	/* end block 1 */
	// End offset: 0x8009CD74
	// End Line: 426

	/* begin block 2 */
		// Start line: 482
	/* end block 2 */
	// End Line: 483

void StateHandlerSwimTread(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int Data_00;
  undefined *puVar2;
  int NewAnim;
  code *NewProcess;
  _Instance **pp_Var3;
  
  pp_Var3 = &In->CharacterInstance + CurrentSection * 0x47;
  ControlFlag = ControlFlag | 0x800;
  do {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    Data_00 = Raziel.padCommands.Queue[13].ID;
    if (p_Var1 == (__Event *)0x0) {
      if ((CurrentSection == 1) && ((Raziel.throwReturnRot & 1U) != 0)) {
        razLaunchBubbles(3,1,0);
      }
      if (CurrentSection == 2) {
        if ((Raziel.throwReturnRot & 2U) != 0) {
          razSetSwimVelocity(In->CharacterInstance,*(int *)(Raziel.padCommands.Queue[13].ID + 0x8c),
                             *(int *)(Raziel.padCommands.Queue[13].ID + 0x90));
        }
        if (((*PadData & 0x80) != 0) && ((*PadData & 1U) != 0)) {
          G2EmulationSwitchAnimationCharacter(In,0x40,0,3,1);
          StateSwitchStateCharacterData(In,StateHandlerSwimDiveIn,0);
          razSetSwimVelocity(In->CharacterInstance,*(int *)(Raziel.padCommands.Queue[13].ID + 0x8c),
                             *(int *)(Raziel.padCommands.Queue[13].ID + 0x90));
          ControlFlag = ControlFlag & 0xfffff7ff;
        }
      }
      if (CurrentSection == 0) {
        if (*(int *)(Raziel.padCommands.Queue[13].ID + 0x98) < (int)(short)Raziel.padCommands.Head)
        {
          Raziel.padCommands.Head._0_2_ = *(short *)(Raziel.padCommands.Queue[13].ID + 0x98);
        }
        if ((int)(short)Raziel.padCommands.Head < *(int *)(Raziel.padCommands.Queue[13].ID + 0x94))
        {
          Raziel.padCommands.Head._0_2_ = *(short *)(Raziel.padCommands.Queue[13].ID + 0x94);
        }
      }
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == (undefined *)0x4010008) goto LAB_8009cc30;
    if ((int)puVar2 < 0x4010009) {
      if (puVar2 != (undefined *)0x100001) {
        if ((int)puVar2 < 0x100002) {
          if (puVar2 == &DAT_80000008) {
            StateSwitchStateData(In,CurrentSection,StateHandlerSwimCoil,0);
          }
          else {
            if ((int)puVar2 < -0x7ffffff7) {
              if (puVar2 == (undefined *)0x80000001) {
                Data_00 = G2EmulationQueryAnimation(In,CurrentSection);
                if (Data_00 != 0x42) {
                  if (CurrentSection == 2) {
                    razSetSwimVelocity(In->CharacterInstance,
                                       *(int *)(Raziel.padCommands.Queue[13].ID + 0x80),
                                       *(int *)(Raziel.padCommands.Queue[13].ID + 0x84));
                  }
                  NewAnim = 0x42;
                  Data_00 = 5;
                  goto LAB_8009ca24;
                }
                pp_Var3[0x48] = (_Instance *)0x1;
              }
            }
            else {
              if (((puVar2 == &DAT_80000010) && ((Raziel.Mode & 0x10000000U) == 0)) &&
                 (CurrentSection == 0)) {
                StateSwitchStateCharacterData(In,StateHandlerGlyphs,0);
              }
            }
          }
        }
        else {
          if (puVar2 == (undefined *)0x100014) {
            Data_00 = SetControlInitIdleData(0,0,9);
            StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
            if (CurrentSection == 0) {
              CAMERA_ChangeToOutOfWater(&theCamera,In->CharacterInstance);
            }
          }
          else {
            if (((int)puVar2 < 0x100015) && (puVar2 == (undefined *)0x100004)) {
              if (Raziel.Mode != 0x40000) {
                if (CurrentSection != 0) goto LAB_8009cc30;
                CAMERA_ChangeToOutOfWater(&theCamera,In->CharacterInstance);
              }
              if (CurrentSection == 0) {
                Raziel.throwReturnRot = 0;
              }
            }
          }
        }
        goto LAB_8009cc30;
      }
      if (Raziel.Mode == 0x40000) {
LAB_8009c828:
        if (CurrentSection == 0) {
          Raziel.Mode = 0x40000;
          ControlFlag = 0x911;
          PhysicsMode = 6;
          razSetSwimVelocity(In->CharacterInstance,0,
                             *(int *)(Raziel.padCommands.Queue[13].ID + 0x88));
          SteerSwitchMode(In->CharacterInstance,6);
          Raziel.throwReturnRot = 0;
        }
      }
      else {
        if (CurrentSection == 0) {
          CAMERA_ChangeToUnderWater(&theCamera,In->CharacterInstance);
          goto LAB_8009c828;
        }
      }
      NewAnim = 0x3d;
      Data_00 = 9;
LAB_8009ca24:
      G2EmulationSwitchAnimation(In,CurrentSection,NewAnim,0,Data_00,2);
    }
    else {
      if (puVar2 != (undefined *)0x8000000) {
        if ((int)puVar2 < 0x8000001) {
          if (puVar2 != (undefined *)0x4010200) {
            if ((int)puVar2 < 0x4010201) {
              if (puVar2 == (undefined *)0x4010010) {
                Data_00 = p_Var1->Data;
                SetPhysics(In->CharacterInstance,0,0,0,0);
                Data_00 = SetControlInitHangData(*(_Instance **)(Data_00 + 0x18),0,3);
                NewProcess = StateHandlerHang;
LAB_8009cba4:
                StateSwitchStateData(In,CurrentSection,NewProcess,Data_00);
              }
            }
            else {
              if (puVar2 == (undefined *)0x4020000) {
                Data_00 = p_Var1->Data;
                if ((Raziel.CurrentPlane == 1) && ((Raziel.Abilities & 0x10U) == 0)) {
                  Raziel.HitPoints = 100000;
                }
                else {
                  if (CurrentSection == 2) {
                    if (*(short *)(Data_00 + 0xc) != -0x60) {
                      (In->CharacterInstance->position).z =
                           ((In->CharacterInstance->position).z + -0x60) - *(short *)(Data_00 + 0xc)
                      ;
                    }
                    In->SectionList[2].Data1 = 0;
                  }
                  if ((*(ushort *)(Data_00 + 0x10) & 0x20) != 0) {
                    G2EmulationSwitchAnimation(In,CurrentSection,0x23,0,0,1);
                    StateSwitchStateData(In,CurrentSection,StateHandlerFall,0);
                    SetExternalForce(&ExternalForces,0,0,-0x10,1,0x1000);
                  }
                  if ((*(ushort *)(Data_00 + 0x10) & 0x80) != 0) {
                    Data_00 = SetControlInitIdleData(0,0,9);
                    NewProcess = StateHandlerIdle;
                    goto LAB_8009cba4;
                  }
                }
              }
            }
          }
        }
        else {
          if (((puVar2 != (undefined *)0x10000000) && ((int)puVar2 < 0x10000001)) &&
             (puVar2 == (undefined *)0x8000001)) {
            if (p_Var1->Data == 0x42) {
              if (pp_Var3[0x48] == (_Instance *)0x1) {
                pp_Var3[0x48] = (_Instance *)0x0;
                razSetSwimVelocity(In->CharacterInstance,*(int *)(Data_00 + 0x80),
                                   *(int *)(Data_00 + 0x84));
              }
              else {
                if ((*PadData & 0x80) == 0) {
                  razSetSwimVelocity(In->CharacterInstance,0,
                                     *(int *)(Raziel.padCommands.Queue[13].ID + 0x9c));
                  NewAnim = 0x3d;
                  Data_00 = 0xf;
                  goto LAB_8009ca24;
                }
                G2EmulationSwitchAnimation(In,CurrentSection,0x3e,0,3,2);
                Raziel.throwReturnRot = Raziel.throwReturnRot & 0xfffffffe;
              }
              goto LAB_8009cc30;
            }
            if ((p_Var1->Data != 0x3e) || ((*PadData & 0x80) != 0)) goto LAB_8009cc30;
            if (CurrentSection == 2) {
              razSetSwimVelocity(In->CharacterInstance,0,
                                 *(int *)(Raziel.padCommands.Queue[13].ID + 0x88));
            }
            NewAnim = 0x3d;
            Data_00 = 0xf;
            goto LAB_8009ca24;
          }
        }
      }
    }
LAB_8009cc30:
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerSwimDiveIn(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$a2*/)
 // line 430, offset 0x8009cda0
	/* begin block 1 */
		// Start line: 431
		// Start offset: 0x8009CDA0
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		struct evPhysicsSwimData *SwimData; // $s4
	/* end block 1 */
	// End offset: 0x8009D084
	// End Line: 529

	/* begin block 2 */
		// Start line: 910
	/* end block 2 */
	// End Line: 911

void StateHandlerSwimDiveIn(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int Data_00;
  __State *p_Var2;
  int iVar3;
  
  iVar3 = 0;
  p_Var2 = In->SectionList + CurrentSection;
  do {
    p_Var1 = PeekMessageQueue(&p_Var2->Event);
    if (p_Var1 == (__Event *)0x0) {
      if ((CurrentSection == 0) && ((Raziel.throwReturnRot & 1U) != 0)) {
        if (((Raziel.throwReturnRot & 2U) != 0) || ((*PadData & 1U) != 0)) {
          Raziel.padCommands.Head._0_2_ = (short)Raziel.padCommands.Head + 0x30;
        }
        if (0x400 < (short)Raziel.padCommands.Head) {
          PhysicsMode = 5;
        }
        if ((Raziel.throwReturnRot & 4U) != 0) {
          razLaunchBubbles(3,1,0);
        }
      }
      return;
    }
    Data_00 = p_Var1->ID;
    if (Data_00 == 0x100004) {
      if (((Raziel.Mode & 0x40000U) == 0) && (CurrentSection == 0)) {
        CAMERA_ChangeToOutOfWater(&theCamera,In->CharacterInstance);
        Raziel.throwReturnRot = 0;
      }
    }
    else {
      if (Data_00 < 0x100005) {
        if (((Data_00 != 0x100000) && (0x100000 < Data_00)) && (Data_00 == 0x100001)) {
          if (Raziel.Mode != 0x40000) {
            if (CurrentSection != 0) goto LAB_8009cfec;
            CAMERA_ChangeToUnderWater(&theCamera,In->CharacterInstance);
          }
          if (CurrentSection == 0) {
            Raziel.Mode = 0x40000;
            ControlFlag = 0x191;
            PhysicsMode = 6;
            SteerSwitchMode(In->CharacterInstance,0x11);
          }
        }
      }
      else {
        if (Data_00 != 0x4010200) {
          if (Data_00 < 0x4010201) {
            if (Data_00 == 0x100014) {
              Data_00 = SetControlInitIdleData(0,0,9);
              StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
              if (CurrentSection == 0) {
                CAMERA_ChangeToOutOfWater(&theCamera,In->CharacterInstance);
              }
            }
          }
          else {
            if (Data_00 == 0x4020000) {
              iVar3 = p_Var1->Data;
            }
            else {
              if (Data_00 == 0x8000000) {
                if ((*PadData & 0x80) != 0) {
                  EnMessageQueueData(&p_Var2->Defer,-0x7fffffff,0);
                }
                if ((*(ushort *)(iVar3 + 0x10) & 0x40) == 0) {
                  StateSwitchStateData(In,CurrentSection,StateHandlerSwim,0);
                  (&In->CharacterInstance + CurrentSection * 0x47)[0x48] =
                       (_Instance *)
                       ((uint)(&In->CharacterInstance + CurrentSection * 0x47)[0x48] | 2);
                }
                else {
                  StateSwitchStateData(In,CurrentSection,StateHandlerSwimTread,0);
                }
              }
            }
          }
        }
      }
    }
LAB_8009cfec:
    DeMessageQueue(&p_Var2->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerSwim(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s3*/, int Data /*$fp*/)
 // line 536, offset 0x8009d0a8
	/* begin block 1 */
		// Start line: 537
		// Start offset: 0x8009D0A8
		// Variables:
	// 		struct __Event *Ptr; // $s2
	// 		struct evPhysicsSwimData *SwimData; // $s2

		/* begin block 1.1 */
			// Start line: 692
			// Start offset: 0x8009D790
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.1 */
		// End offset: 0x8009D828
		// End Line: 703
	/* end block 1 */
	// End offset: 0x8009DBAC
	// End Line: 830

	/* begin block 2 */
		// Start line: 1249
	/* end block 2 */
	// End Line: 1250

void StateHandlerSwim(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int NewAnim;
  ulong uVar2;
  undefined *puVar3;
  _Instance *Inst;
  long adjustment;
  int NewAnim_00;
  code *NewProcess;
  int local_2c;
  __MessageQueue *In_00;
  _Instance **pp_Var4;
  int local_30;
  
  if (CurrentSection == 0) {
    if (0 < In->CharacterInstance->zVel) {
      In->SectionList[0].Data2 = In->SectionList[0].Data2 | 2;
    }
    if (Raziel.iVelocity.z < -0x60) {
      razLaunchBubbles(3,3,1);
    }
    if ((Raziel.throwReturnRot & 1U) != 0) {
      razLaunchBubbles(2,1,0);
    }
    if ((Raziel.throwReturnRot & 2U) != 0) {
      razLaunchBubbles(2,1,0);
    }
  }
  pp_Var4 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    In_00 = &In->SectionList[CurrentSection].Event;
    p_Var1 = PeekMessageQueue(In_00);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    puVar3 = (undefined *)p_Var1->ID;
    if (puVar3 != (undefined *)0x100009) {
      if ((int)puVar3 < 0x10000a) {
        if (puVar3 == &DAT_80000008) {
          NewProcess = StateHandlerSwimCoil;
LAB_8009dafc:
          StateSwitchStateData(In,CurrentSection,NewProcess,0);
        }
        else {
          if ((int)puVar3 < -0x7ffffff7) {
            if (puVar3 == (undefined *)0x80000001) {
              NewAnim = G2EmulationQueryAnimation(In,CurrentSection);
              if (NewAnim != 0x44) {
                if (CurrentSection == 0) {
                  razSetSwimVelocity(In->CharacterInstance,
                                     *(int *)(Raziel.padCommands.Queue[13].ID + 0x54),
                                     *(int *)(Raziel.padCommands.Queue[13].ID + 0x58));
                  Raziel.padCommands.Queue[8].ID._0_2_ = 0x5dc;
                  (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5b20;
                }
                local_2c = 0x44;
                NewAnim = 5;
                goto LAB_8009d6d4;
              }
              pp_Var4[0x48] = (_Instance *)((uint)pp_Var4[0x48] | 1);
            }
            else {
              if (-0x80000000 < (int)puVar3) {
                if (puVar3 == &DAT_80000002) {
                  if (CurrentSection == 1) {
                    Raziel._1140_4_ = In->SectionList[1].Process;
                    StateSwitchStateData(In,1,StateHandlerSoulSuck,0);
                  }
                }
                else {
                  if (puVar3 != &DAT_80000004) goto LAB_8009db90;
                  Inst = In->CharacterInstance;
                  adjustment = *(long *)(Raziel.padCommands.Queue[13].ID + 100);
LAB_8009d9bc:
                  G2Anim_SetSpeedAdjustment(&Inst->anim,adjustment);
                }
              }
            }
          }
          else {
            if (puVar3 == (undefined *)0x80000) {
              if (CurrentSection == 1) {
                razLaunchForce(In->CharacterInstance);
                StateSwitchStateData(In,0,StateHandlerThrow2,0);
              }
              NewProcess = StateHandlerThrow2;
              goto LAB_8009dafc;
            }
            if ((int)puVar3 < 0x80001) {
              if (puVar3 == &DAT_80000010) {
                if (((Raziel.Mode & 0x10000000U) == 0) && (CurrentSection == 0)) {
                  StateSwitchStateCharacterData(In,StateHandlerGlyphs,0);
                }
              }
              else {
                if (puVar3 != &DAT_80000020) goto LAB_8009db90;
                Inst = razGetHeldWeapon();
                if (Inst == (_Instance *)0x0) {
                  NewAnim = 0x80000;
                  if ((Raziel.Abilities & 4U) == 0) goto LAB_8009db9c;
                }
                else {
                  NewAnim = 0x800010;
                }
                EnMessageQueueData(In_00,NewAnim,1);
              }
            }
            else {
              if (puVar3 == (undefined *)0x100001) {
                if (Raziel.Mode == 0x40000) {
LAB_8009d348:
                  if (CurrentSection == 0) {
                    Raziel.Mode = 0x40000;
                    Raziel.RotationSegment = 1;
                    ControlFlag = 400;
                    SteerSwitchMode(In->CharacterInstance,6);
                    razSetSwimVelocity(In->CharacterInstance,0,
                                       *(int *)(Raziel.padCommands.Queue[13].ID + 0x50));
                    G2Anim_SetSpeedAdjustment(&In->CharacterInstance->anim,0x1000);
                  }
                }
                else {
                  if (CurrentSection == 0) {
                    CAMERA_ChangeToUnderWater(&theCamera,In->CharacterInstance);
                    goto LAB_8009d348;
                  }
                }
                if (CurrentSection == 2) {
                  NewAnim_00 = 0x3d;
                  local_30 = 3;
                  NewAnim = 2;
                  local_2c = CurrentSection;
                }
                else {
                  NewAnim_00 = 0x3f;
                  local_30 = 0x10;
                  local_2c = 2;
                  NewAnim = CurrentSection;
                }
                G2EmulationSwitchAnimation(In,NewAnim,NewAnim_00,0,local_30,local_2c);
                PhysicsMode = 5;
                pp_Var4[0x47] = (_Instance *)0x0;
                pp_Var4[0x48] = (_Instance *)0x0;
                Raziel.throwReturnRot = 0;
              }
              else {
                if (puVar3 != (undefined *)0x100004) goto LAB_8009db90;
                if ((Raziel.Mode & 0x40000U) == 0) {
                  if (CurrentSection != 0) goto LAB_8009db9c;
                  G2Anim_SetSpeedAdjustment(&In->CharacterInstance->anim,0x1000);
                  CAMERA_ChangeToOutOfWater(&theCamera,In->CharacterInstance);
                }
                if (CurrentSection == 0) {
                  Raziel.throwReturnRot = 0;
                }
              }
            }
          }
        }
      }
      else {
        if (puVar3 == (undefined *)0x4020000) {
          NewAnim = p_Var1->Data;
          if ((Raziel.CurrentPlane == 1) && ((Raziel.Abilities & 0x10U) == 0)) {
            Raziel.HitPoints = 100000;
          }
          else {
            if (CurrentSection == 0) {
              Inst = razGetHeldWeapon();
              PhysicsForceSetWater
                        (In->CharacterInstance,&In->SectionList[0].Data1,
                         (int)*(short *)(NewAnim + 0xc),
                         *(int *)(Raziel.padCommands.Queue[13].ID + 0x48),
                         *(int *)(Raziel.padCommands.Queue[13].ID + 0x4c));
              if (*(short *)(NewAnim + 0xc) < -0x3f) {
                ControlFlag = ControlFlag & 0xfffff7ff;
              }
              else {
                ControlFlag = ControlFlag | 0x800;
              }
              if ((Inst != (_Instance *)0x0) && (uVar2 = INSTANCE_Query(Inst,4), uVar2 == 3)) {
                local_2c = SetControlInitIdleData(0,0,9);
                StateSwitchStateCharacterData(In,StateHandlerIdle,local_2c);
              }
            }
            if (((*(ushort *)(NewAnim + 0x10) & 0x200) != 0) && (CurrentSection == 0)) {
                    /* WARNING: Read-only address (ram,0x800d5c4c) is written */
              ExternalForces.Friction = 0x30;
            }
            if (((*(ushort *)(NewAnim + 0x10) & 0x40) != 0) && (0 < Raziel.iVelocity.z)) {
              StateHandlerInitSwim(In,CurrentSection,Data);
            }
            if ((*(ushort *)(NewAnim + 0x10) & 0x400) != 0) {
              if (CurrentSection == 0) {
                Raziel.Mode = 0x10;
                SetExternalForce(&__Force_800d5c64,0,0,-0x10,1,0x1000);
                In->CharacterInstance->xVel = (int)Raziel.iVelocity.x;
                In->CharacterInstance->yVel = (int)Raziel.iVelocity.y;
                In->CharacterInstance->zVel = (int)Raziel.iVelocity.z;
                    /* WARNING: Read-only address (ram,0x800d5c4c) is written */
                ExternalForces.Friction = 0x38;
              }
              G2EmulationSwitchAnimation(In,CurrentSection,0x23,0,0,1);
              StateSwitchStateData(In,CurrentSection,StateHandlerFall,0);
            }
            if ((*(ushort *)(NewAnim + 0x10) & 0x20) != 0) {
              Raziel.Mode = 0x100000;
              G2EmulationSwitchAnimation(In,CurrentSection,0x23,0,0,1);
              StateSwitchStateData(In,CurrentSection,StateHandlerFall,0);
              SetExternalForce(&ExternalForces,0,0,-0x10,1,0x1000);
            }
          }
        }
        else {
          if ((int)puVar3 < 0x4020001) {
            if (puVar3 != (undefined *)0x1000001) {
              if ((int)puVar3 < 0x1000002) {
                if (puVar3 == (undefined *)0x100014) {
                  NewAnim = SetControlInitIdleData(0,0,9);
                  StateSwitchStateData(In,CurrentSection,StateHandlerIdle,NewAnim);
                  if (CurrentSection == 0) {
                    CAMERA_ChangeToOutOfWater(&theCamera,In->CharacterInstance);
                  }
                }
                else {
                  if (puVar3 == (undefined *)0x800010) {
                    NewProcess = StateHandlerThrow2;
                    goto LAB_8009dafc;
                  }
LAB_8009db90:
                  DefaultStateHandler(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar3 == (undefined *)0x2000000) {
                  if (((Raziel.Senses.EngagedMask & 0x20) != 0) &&
                     (Inst = razGetHeldItem(), Inst == (_Instance *)0x0)) {
                    Inst = (Raziel.Senses.EngagedList[5].instance)->LinkParent;
                    if ((Inst != (_Instance *)0x0) &&
                       (uVar2 = INSTANCE_Query(Inst,0), uVar2 != 0x40000000)) goto LAB_8009db9c;
                    Raziel.Mode = 0x800;
                    pp_Var4[0x47] = (_Instance *)0x0;
                    G2EmulationSwitchAnimation(In,CurrentSection,0xb,0,3,1);
                    StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,0);
                    if (CurrentSection == 0) {
                      if ((Raziel.Senses.EngagedList[5].instance)->LinkParent != (_Instance *)0x0) {
                        INSTANCE_UnlinkFromParent(Raziel.Senses.EngagedList[5].instance);
                      }
                      NewAnim = SetObjectData(0,0,8,In->CharacterInstance,0x31);
                      INSTANCE_Post(Raziel.Senses.EngagedList[5].instance,0x800002,NewAnim);
                    }
                  }
                  if (((p_Var1->Data & 1U) != 0) &&
                     (Inst = razGetHeldItem(), Inst != (_Instance *)0x0)) {
                    NewProcess = StateHandlerAttack2;
                    goto LAB_8009dafc;
                  }
                }
                else {
                  if (puVar3 != (undefined *)0x4010200) goto LAB_8009db90;
                }
              }
            }
          }
          else {
            if (puVar3 == (undefined *)0x8000004) {
              if ((*PadData & 0x80) == 0) {
                razSetSwimVelocity(In->CharacterInstance,0,
                                   *(int *)(Raziel.padCommands.Queue[13].ID + 0x50));
              }
              else {
                razSetSwimVelocity(In->CharacterInstance,
                                   *(int *)(Raziel.padCommands.Queue[13].ID + 0x5c),
                                   *(int *)(Raziel.padCommands.Queue[13].ID + 0x60));
              }
            }
            else {
              if ((int)puVar3 < 0x8000005) {
                if (puVar3 != (undefined *)0x8000000) {
                  if (puVar3 != (undefined *)0x8000001) goto LAB_8009db90;
                  NewAnim = p_Var1->Data;
                  if ((NewAnim == 0x44) || (NewAnim == 0x42)) {
                    if (((uint)pp_Var4[0x48] & 1) == 0) {
                      if ((*PadData & 0x80) == 0) {
                        if (CurrentSection == 0) {
                          razSetSwimVelocity(In->CharacterInstance,0,
                                             *(int *)(Raziel.padCommands.Queue[13].ID + 0x50));
                        }
                        if (CurrentSection == 2) goto LAB_8009d620;
                        local_2c = 0x3f;
                        NewAnim = 8;
                      }
                      else {
                        if (CurrentSection == 2) {
                          NewAnim = 0;
                          goto LAB_8009d62c;
                        }
                        local_2c = 0x3c;
                        NewAnim = 0xc;
                      }
LAB_8009d6d4:
                      G2EmulationSwitchAnimation(In,CurrentSection,local_2c,0,NewAnim,2);
                    }
                    else {
                      razSetSwimVelocity(In->CharacterInstance,
                                         *(int *)(Raziel.padCommands.Queue[13].ID + 0x54),
                                         *(int *)(Raziel.padCommands.Queue[13].ID + 0x58));
                      pp_Var4[0x48] = (_Instance *)((uint)pp_Var4[0x48] & 0xfffffffe);
                    }
                  }
                  else {
                    if ((NewAnim != 0x3f) && ((*PadData & 0x80) == 0)) {
                      if (CurrentSection == 0) {
                        razSetSwimVelocity(In->CharacterInstance,0,
                                           *(int *)(Raziel.padCommands.Queue[13].ID + 0x50));
                      }
                      if (CurrentSection != 2) {
                        local_2c = 0x3f;
                        NewAnim = 0x10;
                        goto LAB_8009d6d4;
                      }
LAB_8009d620:
                      NewAnim = 0x3d;
LAB_8009d62c:
                      G2EmulationSwitchAnimation(In,2,NewAnim,0,3,CurrentSection);
                    }
                  }
                }
              }
              else {
                if (puVar3 != (undefined *)0x20000001) {
                  if (puVar3 == (undefined *)0x20000004) {
                    Inst = In->CharacterInstance;
                    adjustment = 0x1000;
                    goto LAB_8009d9bc;
                  }
                  goto LAB_8009db90;
                }
              }
            }
          }
        }
      }
    }
LAB_8009db9c:
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}





