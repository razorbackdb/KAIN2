#include "THISDUST.H"
#include "SWIM.H"


// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerInitSwim(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$a2*/)
 // line 5, offset 0x8009e290
	/* begin block 1 */
		// Start line: 10
	/* end block 1 */
	// End Line: 11

void StateHandlerSoulSuck(__CharacterState *In,int CurrentSection,int Data)

{
  long *plVar1;
  
  G2EmulatePlayAnimation(In,CurrentSection,0x3d,0,9,2);
  StateSwitchStateData(In,CurrentSection,StateHandlerSwim,0);
  plVar1 = PadData;
  (&In->CharacterInstance + CurrentSection * 0x47)[0x48] =
       (_Instance *)((u_int)(&In->CharacterInstance + CurrentSection * 0x47)[0x48] | 2);
  if ((*plVar1 & 0x80) != 0) {
    DeMessageQueue(&In->SectionList[CurrentSection].Defer,-0x7fffffff,0);
  }
  if (CurrentSection == 2) {
    Raziel.RotationSegment = 1;
    Raziel.Mode = 0x40000;
    SteerSwitchMode(In->CharacterInstance,6);
    ControlFlag = 0x191;
    CAMERA_ChangeToUnderWater(&theCamera,In->CharacterInstance);
    ExtraRot = &ExtraRotData;
    ExtraRotData.x = 0x80;
                    /* WARNING: Read-only address (ram,0x800d5e04) is written */
    ExternalForces.Friction = 0xf80;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerSwimCoil(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s6*/)
 // line 55, offset 0x8009e3a4
	/* begin block 1 */
		// Start line: 56
		// Start offset: 0x8009E3A4
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		struct evPhysicsSwimData *SwimData; // $a0
	// 		int rc; // $s5

		/* begin block 1.1 */
			// Start line: 222
			// Start offset: 0x8009E9C0
			// Variables:
		// 		struct evMonsterHitData *data; // $v1
		/* end block 1.1 */
		// End offset: 0x8009E9D4
		// End Line: 225
	/* end block 1 */
	// End offset: 0x8009EA4C
	// End Line: 251

	/* begin block 2 */
		// Start line: 102
	/* end block 2 */
	// End Line: 103

void StateHandlerWallDismount(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *instance;
  int Data_00;
  undefined *puVar2;
  int NewAnim;
  _Instance **pp_Var3;
  __State *p_Var4;
  u_int uVar5;
  int local_28;
  int local_24;
  
  ControlFlag = ControlFlag & 0xfffffbff;
  uVar5 = In->SectionList[CurrentSection].Data1;
  if (CurrentSection == 0) {
    if (Raziel.timeAccumulator != 0) {
      razLaunchBubbles(3,3,1);
    }
    if ((Raziel.passedMask & 2) != 0) {
      razLaunchBubbles(3,6,1);
    }
    instance = In->CharacterInstance;
    if (instance->waterFace != (_TFace *)0x0) {
      Data_00 = (int)(instance->splitPoint).z;
      if ((Data_00 < instance->matrix[8].t[2]) || (Data_00 < instance->matrix[0xc].t[2])) {
        PhysicsMode = 6;
      }
    }
  }
  p_Var4 = In->SectionList + CurrentSection;
  pp_Var3 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    p_Var1 = PeekMessageQueue(&p_Var4->Event);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == &DAT_00100014) {
      Data_00 = SetControlInitIdleData(0,0,9);
      StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,Data_00);
LAB_8009ea10:
      if (CurrentSection == 0) {
        CAMERA_ChangeTo(&theCamera,In->CharacterInstance);
      }
    }
    else {
      if ((int)puVar2 < 0x100015) {
        if (puVar2 == (undefined *)0x100000) {
          if ((uVar5 & 0x40) == 0) {
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
            G2EmulatePlayAnimation(In,Data_00,NewAnim,0,local_28,local_24);
            StateSwitchStateData(In,CurrentSection,StateHandlerSwimTread,0);
            pp_Var3[0x48] = (_Instance *)((u_int)pp_Var3[0x48] | 2);
          }
          else {
            StateSwitchStateData(In,CurrentSection,StateHandlerSwim,0);
          }
          if (CurrentSection == 0) {
            instance = In->CharacterInstance;
            Data_00 = PlayerData->SwimPhysicsShotAccelerationOut;
LAB_8009e88c:
            razSetSwimVelocity(instance,0,Data_00);
          }
        }
        else {
          if ((int)puVar2 < 0x100001) {
            if (puVar2 == (undefined *)0x80000001) {
              Data_00 = G2EmulationQueryAnimation(In,CurrentSection);
              if ((Data_00 != 0x43) &&
                 (G2EmulatePlayAnimation(In,CurrentSection,0x43,0,3,1), CurrentSection == 0)) {
                Raziel.alarmTable = 300;
                (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5c98;
              }
            }
            else {
              if (((-0x80000000 < (int)puVar2) && (puVar2 != &DAT_80000008)) &&
                 (puVar2 != &DAT_80000010)) goto LAB_8009ea34;
            }
          }
          else {
            if (puVar2 == &DAT_00100004) {
              if ((Raziel.Mode & 0x40000U) == 0) goto LAB_8009ea10;
            }
            else {
              if ((int)puVar2 < 0x100005) {
                if (puVar2 != &DAT_00100001) goto LAB_8009ea34;
                if (Raziel.Mode == 0x40000) {
LAB_8009e648:
                  if (CurrentSection == 0) {
                    Raziel.Mode = 0x40000;
                    ControlFlag = 0x111;
                    razSetSwimVelocity(In->CharacterInstance,PlayerData->SwimPhysicsCoilVelocity,
                                       PlayerData->SwimPhysicsCoilDecelerationIn);
                    CAMERA_SetShake(5);
                  }
                }
                else {
                  if (CurrentSection == 0) {
                    CAMERA_ChangeToUnderWater(&theCamera,In->CharacterInstance);
                    goto LAB_8009e648;
                  }
                }
                PhysicsMode = 5;
                G2EmulatePlayAnimation(In,CurrentSection,0x41,0,9,2);
                pp_Var3[0x47] = (_Instance *)0x0;
                Raziel.passedMask = 0;
              }
              else {
                if (puVar2 != &DAT_00100009) {
                  if (puVar2 != &DAT_00100011) goto LAB_8009ea34;
                  Data_00 = p_Var1->Data;
                  if (Data_00 == PlayerData->SwimPhysicsCoilVelocity) {
                    razSetSwimVelocity(In->CharacterInstance,0,
                                       PlayerData->SwimPhysicsCoilDecelerationOut);
                    Data_00 = p_Var1->Data;
                  }
                  if (Data_00 == PlayerData->SwimPhysicsShotVelocity) {
                    instance = In->CharacterInstance;
                    Data_00 = PlayerData->SwimPhysicsShotAccelerationOut;
                    goto LAB_8009e88c;
                  }
                }
              }
            }
          }
        }
      }
      else {
        if (puVar2 != (undefined *)0x4010200) {
          if ((int)puVar2 < 0x4010201) {
            if (puVar2 != (undefined *)0x1000001) {
              if ((int)puVar2 < 0x1000002) {
                if (puVar2 == (undefined *)0x1000000) {
                  if ((CurrentSection == 0) && ((gameTrackerX.debugFlags2 & 0x800U) != 0)) {
                    LoseHealth(*(int *)(p_Var1->Data + 0xc));
                  }
                }
                else {
LAB_8009ea34:
                  StateHandlerDragObject(In,CurrentSection,Data);
                }
              }
              else {
                if ((puVar2 != (undefined *)0x4000001) && (puVar2 != (undefined *)0x4000004))
                goto LAB_8009ea34;
              }
            }
          }
          else {
            if (puVar2 == (undefined *)0x8000004) {
              razSetSwimVelocity(In->CharacterInstance,PlayerData->SwimPhysicsShotVelocity,
                                 PlayerData->SwimPhysicsShotAccelerationIn);
            }
            else {
              if ((int)puVar2 < 0x8000005) {
                if (puVar2 == (undefined *)0x4020000) {
                  Data_00 = p_Var1->Data;
                  pp_Var3[0x47] = (_Instance *)(int)*(short *)(Data_00 + 0x10);
                  if ((Raziel.CurrentPlane == 1) && ((Raziel.Abilities & 0x10U) == 0)) {
                    Raziel.HitPoints = 100000;
                  }
                  else {
                    if ((*(ushort *)(Data_00 + 0x10) & 0x220) != 0) {
                      if (CurrentSection == 0) {
                        Raziel.Mode = 0x10;
                        SetPhysicsGravityData(In->CharacterInstance,-0x10,0,0x15,0xc3);
                        SteerSwitchMode(In->CharacterInstance,4);
                        Raziel.steeringLockRotation = (int)(In->CharacterInstance->rotation).z;
                        Raziel.LastBearing = (In->CharacterInstance->rotation).z;
                        SetExternalTransitionForce(&ExternalForces,0,0,-0x10,1,0x1000);
                        PhysicsMode = 0;
                      }
                      G2EmulatePlayAnimation(In,CurrentSection,0x23,0,0,1);
                      StateSwitchStateData(In,CurrentSection,StateHandlerDeCompression,0);
                    }
                  }
                }
                else {
                  if (puVar2 != (undefined *)0x8000000) goto LAB_8009ea34;
                  Data_00 = G2EmulationQueryAnimation(In,CurrentSection);
                  if (Data_00 == 0x43) {
LAB_8009e758:
                    DeMessageQueue(&p_Var4->Defer,0x100000,0);
                  }
                }
              }
              else {
                if (puVar2 != (undefined *)0x20000001) {
                  if (puVar2 != (undefined *)0x20000008) goto LAB_8009ea34;
                  Data_00 = G2EmulationQueryAnimation(In,CurrentSection);
                  if (Data_00 != 0x43) goto LAB_8009e758;
                }
              }
            }
          }
        }
      }
    }
    PurgeMessageQueue(&p_Var4->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerSwimTread(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$a2*/)
 // line 255, offset 0x8009ea74
	/* begin block 1 */
		// Start line: 256
		// Start offset: 0x8009EA74
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		struct evPhysicsSwimData *SwimData; // $s0

		/* begin block 1.1 */
			// Start line: 400
			// Start offset: 0x8009EFC0
			// Variables:
		// 		struct evPhysicsEdgeData *data; // $s0
		/* end block 1.1 */
		// End offset: 0x8009F008
		// End Line: 406

		/* begin block 1.2 */
			// Start line: 425
			// Start offset: 0x8009F090
			// Variables:
		// 		struct evMonsterHitData *data; // $v1
		/* end block 1.2 */
		// End offset: 0x8009F0B0
		// End Line: 430
	/* end block 1 */
	// End offset: 0x8009F208
	// End Line: 464

	/* begin block 2 */
		// Start line: 518
	/* end block 2 */
	// End Line: 519

void StateHandlerSwim(__CharacterState *In,int CurrentSection,int Data)

{
  RazielData *pRVar1;
  __Event *p_Var2;
  int Data_00;
  undefined *puVar3;
  int NewAnim;
  code *NewProcess;
  _Instance **pp_Var4;
  
  pp_Var4 = &In->CharacterInstance + CurrentSection * 0x47;
  ControlFlag = ControlFlag | 0x400;
  do {
    p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    pRVar1 = PlayerData;
    if (p_Var2 == (__Event *)0x0) {
      if ((CurrentSection == 1) && ((Raziel.passedMask & 1) != 0)) {
        razLaunchBubbles(3,1,0);
      }
      if (CurrentSection == 2) {
        if ((Raziel.passedMask & 2) != 0) {
          razSetSwimVelocity(In->CharacterInstance,PlayerData->SwimPhysicsSurfKickVelocity,
                             PlayerData->SwimPhysicsSurfKickAccel);
        }
        if ((((*PadData & 0x80) != 0) && (Raziel.steeringMode == 6)) && ((*PadData & 1U) != 0)) {
          G2EmulationSwitchAnimationSync(In,0x40,0,3,1);
          StateSwitchStateCharacterDataDefault(In,StateHandlerDropAction,0);
          razSetSwimVelocity(In->CharacterInstance,PlayerData->SwimPhysicsSurfKickVelocity,
                             PlayerData->SwimPhysicsSurfKickAccel);
          ControlFlag = ControlFlag & 0xfffffbff;
        }
      }
      if (CurrentSection == 0) {
        if (PlayerData->SwimPhysicsSurfMaxRotation < (int)Raziel.extraRot.x) {
          Raziel.extraRot.x = *(short *)&PlayerData->SwimPhysicsSurfMaxRotation;
        }
        if ((int)Raziel.extraRot.x < PlayerData->SwimPhysicsSurfMinRotation) {
          Raziel.extraRot.x = *(short *)&PlayerData->SwimPhysicsSurfMinRotation;
        }
      }
      return;
    }
    puVar3 = (undefined *)p_Var2->ID;
    if (puVar3 == (undefined *)0x4000001) goto LAB_8009f0b4;
    if ((int)puVar3 < 0x4000002) {
      if (puVar3 != &DAT_00100001) {
        if ((int)puVar3 < 0x100002) {
          if (puVar3 == &DAT_80000008) {
            StateSwitchStateData(In,CurrentSection,StateHandlerWallDismount,0);
          }
          else {
            if ((int)puVar3 < -0x7ffffff7) {
              if ((puVar3 == (undefined *)0x80000001) && (Raziel.steeringMode == 6)) {
                Data_00 = G2EmulationQueryAnimation(In,CurrentSection);
                if (Data_00 != 0x42) {
                  if (CurrentSection == 2) {
                    razSetSwimVelocity(In->CharacterInstance,PlayerData->SwimPhysicsSurfVelocity,
                                       PlayerData->SwimPhysicsSurfAccelerationIn);
                  }
                  NewAnim = 0x42;
                  Data_00 = 5;
                  goto LAB_8009ee2c;
                }
                pp_Var4[0x48] = (_Instance *)0x1;
              }
            }
            else {
              if (((puVar3 == &DAT_80000010) && ((Raziel.Mode & 0x10000000U) == 0)) &&
                 (CurrentSection == 0)) {
                StateSwitchStateCharacterDataDefault(In,StateHandlerWallGrab,0);
              }
            }
          }
        }
        else {
          if (puVar3 == &DAT_00100009) {
            if (CurrentSection == 0) {
              if (p_Var2->Data == 0) {
                SteerSwitchMode(In->CharacterInstance,6);
              }
              else {
                SteerSwitchMode(In->CharacterInstance,0);
              }
            }
          }
          else {
            if ((int)puVar3 < 0x10000a) {
              if (puVar3 == &DAT_00100004) {
                if ((Raziel.Mode & 0x40000U) == 0) {
                  if (CurrentSection != 0) goto LAB_8009f0b4;
                  CAMERA_ChangeTo(&theCamera,In->CharacterInstance);
                }
                if (CurrentSection == 0) {
                  Raziel.passedMask = 0;
                }
              }
            }
            else {
              if (puVar3 == &DAT_00100014) {
                Data_00 = SetControlInitIdleData(0,0,9);
                StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,Data_00);
                if (CurrentSection == 0) {
                  CAMERA_ChangeTo(&theCamera,In->CharacterInstance);
                }
              }
              else {
                if (((puVar3 == (undefined *)0x1000000) && (CurrentSection == 0)) &&
                   ((gameTrackerX.debugFlags2 & 0x800U) != 0)) {
                  LoseHealth(*(int *)(p_Var2->Data + 0xc));
                }
              }
            }
          }
        }
        goto LAB_8009f0b4;
      }
      if ((Raziel.Mode & 0x40000U) == 0) {
        if (CurrentSection == 0) {
          CAMERA_ChangeToUnderWater(&theCamera,In->CharacterInstance);
          goto LAB_8009ec0c;
        }
      }
      else {
LAB_8009ec0c:
        if (CurrentSection == 0) {
          Raziel.Mode = 0x40000;
          ControlFlag = 0x511;
          PhysicsMode = 6;
          razSetSwimVelocity(In->CharacterInstance,0,PlayerData->SwimPhysicsSurfAccelerationOut);
          SteerSwitchMode(In->CharacterInstance,6);
          Raziel.passedMask = 0;
        }
      }
      NewAnim = 0x3d;
      Data_00 = 9;
LAB_8009ee2c:
      G2EmulatePlayAnimation(In,CurrentSection,NewAnim,0,Data_00,2);
    }
    else {
      if (puVar3 == (undefined *)0x4020000) {
        Data_00 = p_Var2->Data;
        if ((Raziel.CurrentPlane == 1) && ((Raziel.Abilities & 0x10U) == 0)) {
          Raziel.HitPoints = 100000;
        }
        else {
          if (CurrentSection == 2) {
            if (*(short *)(Data_00 + 0xc) != -0x60) {
              (In->CharacterInstance->position).z =
                   ((In->CharacterInstance->position).z + -0x60) - *(short *)(Data_00 + 0xc);
            }
            In->SectionList[2].Data1 = 0;
          }
          if ((*(ushort *)(Data_00 + 0x10) & 0x20) != 0) {
            G2EmulatePlayAnimation(In,CurrentSection,0x23,0,0,1);
            SteerSwitchMode(In->CharacterInstance,4);
            StateSwitchStateData(In,CurrentSection,StateHandlerGrab,0);
            SetExternalTransitionForce(&ExternalForces,0,0,-0x10,1,0x1000);
          }
          if ((*(ushort *)(Data_00 + 0x10) & 0x80) != 0) {
            Data_00 = SetControlInitIdleData(0,0,9);
            NewProcess = StateHandlerPickupObject;
            goto LAB_8009eff8;
          }
        }
      }
      else {
        if ((int)puVar3 < 0x4020001) {
          if (puVar3 == (undefined *)0x4010010) {
            Data_00 = p_Var2->Data;
            SetPhysicsGravityData(In->CharacterInstance,0,0,0,0);
            Data_00 = SetControlInitHangData(*(_Instance **)(Data_00 + 0x18),0,3);
            NewProcess = StateHandlerForcedGlide;
LAB_8009eff8:
            StateSwitchStateData(In,CurrentSection,NewProcess,Data_00);
          }
        }
        else {
          if (puVar3 == (undefined *)0x8000001) {
            if (p_Var2->Data == 0x42) {
              if (pp_Var4[0x48] == (_Instance *)0x1) {
                pp_Var4[0x48] = (_Instance *)0x0;
                razSetSwimVelocity(In->CharacterInstance,pRVar1->SwimPhysicsSurfVelocity,
                                   pRVar1->SwimPhysicsSurfAccelerationIn);
              }
              else {
                if (((*PadData & 0x80) == 0) || (Raziel.steeringMode == 0)) {
                  razSetSwimVelocity(In->CharacterInstance,0,PlayerData->SwimPhysicsSurfKickDecel);
                  NewAnim = 0x3d;
                  Data_00 = 0xf;
                  goto LAB_8009ee2c;
                }
                G2EmulatePlayAnimation(In,CurrentSection,0x3e,0,3,2);
                Raziel.passedMask = Raziel.passedMask & 0xfffffffe;
              }
              goto LAB_8009f0b4;
            }
            if ((p_Var2->Data != 0x3e) || ((*PadData & 0x80) != 0)) goto LAB_8009f0b4;
            if (CurrentSection == 2) {
              razSetSwimVelocity(In->CharacterInstance,0,PlayerData->SwimPhysicsSurfAccelerationOut)
              ;
            }
            NewAnim = 0x3d;
            Data_00 = 0xf;
            goto LAB_8009ee2c;
          }
        }
      }
    }
LAB_8009f0b4:
    PurgeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerSwimDiveIn(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$a2*/)
 // line 468, offset 0x8009f234
	/* begin block 1 */
		// Start line: 469
		// Start offset: 0x8009F234
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		struct evPhysicsSwimData *SwimData; // $s4

		/* begin block 1.1 */
			// Start line: 548
			// Start offset: 0x8009F49C
			// Variables:
		// 		struct evMonsterHitData *data; // $v1
		/* end block 1.1 */
		// End offset: 0x8009F4BC
		// End Line: 553
	/* end block 1 */
	// End offset: 0x8009F56C
	// End Line: 581

	/* begin block 2 */
		// Start line: 991
	/* end block 2 */
	// End Line: 992

void StateHandlerDropAction(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int Data_00;
  undefined *puVar2;
  __State *p_Var3;
  int iVar4;
  
  iVar4 = 0;
  p_Var3 = In->SectionList + CurrentSection;
  do {
    p_Var1 = PeekMessageQueue(&p_Var3->Event);
    if (p_Var1 == (__Event *)0x0) {
      if (CurrentSection == 0) {
        (In->CharacterInstance->position).z = (In->CharacterInstance->position).z + -0x10;
        if ((Raziel.passedMask & 1) != 0) {
          if (((Raziel.passedMask & 2) != 0) || ((*PadData & 1U) != 0)) {
            Raziel.extraRot.x = Raziel.extraRot.x + 0x30;
          }
          if (0x400 < Raziel.extraRot.x) {
            PhysicsMode = 5;
          }
          if ((Raziel.passedMask & 4) != 0) {
            razLaunchBubbles(3,1,0);
          }
        }
      }
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == &DAT_00100014) {
      Data_00 = SetControlInitIdleData(0,0,9);
      StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,Data_00);
      if (CurrentSection == 0) {
        CAMERA_ChangeTo(&theCamera,In->CharacterInstance);
      }
    }
    else {
      if ((int)puVar2 < 0x100015) {
        if ((puVar2 != (undefined *)0x100000) && (0x100000 < (int)puVar2)) {
          if (puVar2 == &DAT_00100001) {
            if (Raziel.Mode != 0x40000) {
              if (CurrentSection != 0) goto LAB_8009f4bc;
              CAMERA_ChangeToUnderWater(&theCamera,In->CharacterInstance);
            }
            if (CurrentSection == 0) {
              Raziel.Mode = 0x40000;
              ControlFlag = 0x191;
              PhysicsMode = 6;
              SteerSwitchMode(In->CharacterInstance,0x11);
            }
          }
          else {
            if (((puVar2 == &DAT_00100004) && ((Raziel.Mode & 0x40000U) == 0)) &&
               (CurrentSection == 0)) {
              CAMERA_ChangeTo(&theCamera,In->CharacterInstance);
              Raziel.passedMask = 0;
            }
          }
        }
      }
      else {
        if (puVar2 != (undefined *)0x4010200) {
          if ((int)puVar2 < 0x4010201) {
            if (((puVar2 == (undefined *)0x1000000) && (CurrentSection == 0)) &&
               ((gameTrackerX.debugFlags2 & 0x800U) != 0)) {
              LoseHealth(*(int *)(p_Var1->Data + 0xc));
            }
          }
          else {
            if (puVar2 == (undefined *)0x4020000) {
              iVar4 = p_Var1->Data;
            }
            else {
              if (puVar2 == (undefined *)0x8000000) {
                if ((*PadData & 0x80) != 0) {
                  DeMessageQueue(&p_Var3->Defer,-0x7fffffff,0);
                }
                if ((*(ushort *)(iVar4 + 0x10) & 0x40) == 0) {
                  StateSwitchStateData(In,CurrentSection,StateHandlerSwimTread,0);
                  (&In->CharacterInstance + CurrentSection * 0x47)[0x48] =
                       (_Instance *)
                       ((u_int)(&In->CharacterInstance + CurrentSection * 0x47)[0x48] | 2);
                }
                else {
                  StateSwitchStateData(In,CurrentSection,StateHandlerSwim,0);
                }
              }
            }
          }
        }
      }
    }
LAB_8009f4bc:
    PurgeMessageQueue(&p_Var3->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerSwim(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s3*/, int Data /*$fp*/)
 // line 588, offset 0x8009f590
	/* begin block 1 */
		// Start line: 589
		// Start offset: 0x8009F590
		// Variables:
	// 		struct __Event *Ptr; // $s1
	// 		struct evPhysicsSwimData *SwimData; // $s1

		/* begin block 1.1 */
			// Start line: 756
			// Start offset: 0x8009FCF0
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.1 */
		// End offset: 0x8009FD88
		// End Line: 767

		/* begin block 1.2 */
			// Start line: 893
			// Start offset: 0x800A010C
			// Variables:
		// 		struct evMonsterHitData *data; // $v1
		/* end block 1.2 */
		// End offset: 0x800A0120
		// End Line: 896
	/* end block 1 */
	// End offset: 0x800A0154
	// End Line: 907

	/* begin block 2 */
		// Start line: 1359
	/* end block 2 */
	// End Line: 1360

void StateHandlerSwimTread(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int Data_00;
  u_long uVar2;
  undefined *puVar3;
  _Instance *Inst;
  long adjustment;
  int NewAnim;
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
    if ((Raziel.passedMask & 1) != 0) {
      razLaunchBubbles(2,1,0);
    }
    if ((Raziel.passedMask & 2) != 0) {
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
    if (puVar3 == &DAT_00100014) {
      Data_00 = SetControlInitIdleData(0,0,9);
      StateSwitchStateData(In,CurrentSection,StateHandlerPickupObject,Data_00);
      if (CurrentSection == 0) {
        CAMERA_ChangeTo(&theCamera,In->CharacterInstance);
      }
    }
    else {
      if ((int)puVar3 < 0x100015) {
        if (puVar3 == &DAT_80000010) {
          if (((Raziel.Mode & 0x10000000U) == 0) && (CurrentSection == 0)) {
            StateSwitchStateCharacterDataDefault(In,StateHandlerWallGrab,0);
          }
        }
        else {
          if ((int)puVar3 < -0x7fffffef) {
            if (puVar3 == &DAT_80000002) {
              if (CurrentSection == 1) {
                Raziel.returnState = (_func_60 *)In->SectionList[1].Process;
                StateSwitchStateData(In,1,StateHandlerAttack2,0);
              }
            }
            else {
              if ((int)puVar3 < -0x7ffffffd) {
                if (puVar3 != (undefined *)0x80000000) {
                  if (puVar3 != (undefined *)0x80000001) goto LAB_800a0138;
                  if (Raziel.steeringMode == 6) {
                    Data_00 = G2EmulationQueryAnimation(In,CurrentSection);
                    if (Data_00 != 0x44) {
                      if (CurrentSection == 0) {
                        razSetSwimVelocity(In->CharacterInstance,
                                           PlayerData->SwimPhysicsUnderKickVelocity,
                                           PlayerData->SwimPhysicsUnderKickAccel);
                        Raziel.alarmTable = 0x5dc;
                        (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5c98;
                      }
                      local_2c = 0x44;
                      Data_00 = 5;
                      goto LAB_8009fbfc;
                    }
                    pp_Var4[0x48] = (_Instance *)((u_int)pp_Var4[0x48] | 1);
                  }
                }
              }
              else {
                if (puVar3 == &DAT_80000004) {
                  Inst = In->CharacterInstance;
                  adjustment = PlayerData->SwimPhysicsUnderStealthAdjust;
LAB_8009ff34:
                  G2Anim_SetSpeedAdjustment(&Inst->anim,adjustment);
                }
                else {
                  if (puVar3 != &DAT_80000008) goto LAB_800a0138;
                  NewProcess = StateHandlerWallDismount;
LAB_800a0074:
                  StateSwitchStateData(In,CurrentSection,NewProcess,0);
                }
              }
            }
          }
          else {
            if (puVar3 == &DAT_00100001) {
              if (Raziel.Mode == 0x40000) {
LAB_8009f868:
                if (CurrentSection == 0) {
                  Raziel.Mode = 0x40000;
                  Raziel.RotationSegment = 1;
                  ControlFlag = 400;
                  SteerSwitchMode(In->CharacterInstance,6);
                  razSetSwimVelocity(In->CharacterInstance,0,
                                     PlayerData->SwimPhysicsUnderDeceleration);
                  G2Anim_SetSpeedAdjustment(&In->CharacterInstance->anim,0x1000);
                }
              }
              else {
                if (CurrentSection == 0) {
                  CAMERA_ChangeToUnderWater(&theCamera,In->CharacterInstance);
                  goto LAB_8009f868;
                }
              }
              if (CurrentSection == 2) {
                NewAnim = 0x3d;
                local_30 = 3;
                Data_00 = 2;
                local_2c = CurrentSection;
              }
              else {
                NewAnim = 0x3f;
                local_30 = 0x10;
                local_2c = 2;
                Data_00 = CurrentSection;
              }
              G2EmulatePlayAnimation(In,Data_00,NewAnim,0,local_30,local_2c);
              PhysicsMode = 5;
              pp_Var4[0x47] = (_Instance *)0x0;
              pp_Var4[0x48] = (_Instance *)0x0;
              Raziel.passedMask = 0;
            }
            else {
              if ((int)puVar3 < 0x100002) {
                if (puVar3 != &DAT_80000020) {
                  if (puVar3 == (undefined *)0x80000) {
                    if (CurrentSection == 0) {
                      razLaunchForce(In->CharacterInstance);
                    }
                    NewProcess = StateHandlerWallIdle;
                    goto LAB_800a0074;
                  }
                  goto LAB_800a0138;
                }
                Inst = razGetHeldWeapon();
                if (Inst == (_Instance *)0x0) {
                  Data_00 = 0x80000;
                  if ((Raziel.Abilities & 4U) == 0) goto LAB_800a0144;
                }
                else {
                  Data_00 = 0x800010;
                }
                DeMessageQueue(In_00,Data_00,1);
              }
              else {
                if (puVar3 == &DAT_00100004) {
                  if ((Raziel.Mode & 0x40000U) == 0) {
                    if (CurrentSection != 0) goto LAB_800a0144;
                    G2Anim_SetSpeedAdjustment(&In->CharacterInstance->anim,0x1000);
                    CAMERA_ChangeTo(&theCamera,In->CharacterInstance);
                  }
                  if (CurrentSection == 0) {
                    Raziel.passedMask = 0;
                  }
                }
                else {
                  if (puVar3 != &DAT_00100009) goto LAB_800a0138;
                  if (CurrentSection == 0) {
                    if (p_Var1->Data == 0) {
                      SteerSwitchMode(In->CharacterInstance,6);
                    }
                    else {
                      SteerSwitchMode(In->CharacterInstance,0);
LAB_8009fc84:
                      razSetSwimVelocity(In->CharacterInstance,0,
                                         PlayerData->SwimPhysicsUnderDeceleration);
                    }
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
            if (puVar3 != (undefined *)0x1000001) {
              if ((int)puVar3 < 0x1000002) {
                if (puVar3 == (undefined *)0x800010) {
                  NewProcess = StateHandlerWallIdle;
                  goto LAB_800a0074;
                }
                if (puVar3 != (undefined *)0x1000000) goto LAB_800a0138;
                if ((CurrentSection == 0) && ((gameTrackerX.debugFlags2 & 0x800U) != 0)) {
                  LoseHealth(*(int *)(p_Var1->Data + 0xc));
                }
              }
              else {
                if (puVar3 == (undefined *)0x2000000) {
                  if (((Raziel.Senses.EngagedMask & 0x20) != 0) &&
                     (Inst = razGetHeldItem(), Inst == (_Instance *)0x0)) {
                    Inst = (Raziel.Senses.EngagedList[5].instance)->LinkParent;
                    if ((Inst != (_Instance *)0x0) &&
                       (uVar2 = INSTANCE_Post(Inst,0), uVar2 != 0x40000000)) goto LAB_800a0144;
                    Raziel.Mode = 0x800;
                    pp_Var4[0x47] = (_Instance *)0x0;
                    G2EmulatePlayAnimation(In,CurrentSection,0xb,0,3,1);
                    StateSwitchStateData(In,CurrentSection,StateHandlerPullSwitch,0);
                    if (CurrentSection == 0) {
                      if ((Raziel.Senses.EngagedList[5].instance)->LinkParent != (_Instance *)0x0) {
                        INSTANCE_UnlinkFromParent(Raziel.Senses.EngagedList[5].instance);
                      }
                      Data_00 = SetObjectBreakOffData(0,0,8,In->CharacterInstance,0x31);
                      INSTANCE_Query(Raziel.Senses.EngagedList[5].instance,0x800002,Data_00);
                    }
                  }
                  if (((p_Var1->Data & 1U) != 0) &&
                     (Inst = razGetHeldItem(), Inst != (_Instance *)0x0)) {
                    NewProcess = StateHandlerHang;
                    goto LAB_800a0074;
                  }
                }
                else {
                  if (puVar3 != (undefined *)0x4000001) goto LAB_800a0138;
                }
              }
            }
          }
          else {
            if (puVar3 == (undefined *)0x8000001) {
              Data_00 = p_Var1->Data;
              if ((Data_00 == 0x44) || (Data_00 == 0x42)) {
                if (((u_int)pp_Var4[0x48] & 1) == 0) {
                  if (((*PadData & 0x80) == 0) || (Raziel.steeringMode != 6)) {
                    if (CurrentSection == 0) {
                      razSetSwimVelocity(In->CharacterInstance,0,
                                         PlayerData->SwimPhysicsUnderDeceleration);
                    }
                    if (CurrentSection == 2) goto LAB_8009fb3c;
                    local_2c = 0x3f;
                    Data_00 = 8;
                  }
                  else {
                    if (CurrentSection == 2) {
                      Data_00 = 0;
                      goto LAB_8009fb48;
                    }
                    local_2c = 0x3c;
                    Data_00 = 0xc;
                  }
LAB_8009fbfc:
                  G2EmulatePlayAnimation(In,CurrentSection,local_2c,0,Data_00,2);
                }
                else {
                  razSetSwimVelocity(In->CharacterInstance,PlayerData->SwimPhysicsUnderKickVelocity,
                                     PlayerData->SwimPhysicsUnderKickAccel);
                  pp_Var4[0x48] = (_Instance *)((u_int)pp_Var4[0x48] & 0xfffffffe);
                }
              }
              else {
                if ((Data_00 != 0x3f) && ((*PadData & 0x80) == 0)) {
                  if (CurrentSection == 0) {
                    razSetSwimVelocity(In->CharacterInstance,0,
                                       PlayerData->SwimPhysicsUnderDeceleration);
                  }
                  if (CurrentSection != 2) {
                    local_2c = 0x3f;
                    Data_00 = 0x10;
                    goto LAB_8009fbfc;
                  }
LAB_8009fb3c:
                  Data_00 = 0x3d;
LAB_8009fb48:
                  G2EmulatePlayAnimation(In,2,Data_00,0,3,CurrentSection);
                }
              }
            }
            else {
              if ((int)puVar3 < 0x8000002) {
                if (puVar3 == (undefined *)0x4020000) {
                  Data_00 = p_Var1->Data;
                  if ((Raziel.CurrentPlane == 1) && ((Raziel.Abilities & 0x10U) == 0)) {
                    Raziel.HitPoints = 100000;
                  }
                  else {
                    if (CurrentSection == 0) {
                      Inst = razGetHeldWeapon();
                      PhysicsForceSetWater
                                (In->CharacterInstance,&In->SectionList[0].Data1,
                                 (int)*(short *)(Data_00 + 0xc),
                                 PlayerData->SwimPhysicsWaterFrequency,
                                 PlayerData->SwimPhysicsWaterAmplitude);
                      if (*(short *)(Data_00 + 0xc) < -0x3f) {
                        ControlFlag = ControlFlag & 0xfffffbff;
                      }
                      else {
                        ControlFlag = ControlFlag | 0x400;
                      }
                      if ((Inst != (_Instance *)0x0) && (uVar2 = INSTANCE_Post(Inst,4), uVar2 == 3))
                      {
                        local_2c = SetControlInitIdleData(0,0,9);
                        StateSwitchStateCharacterDataDefault(In,StateHandlerPickupObject,local_2c);
                      }
                    }
                    if (((*(ushort *)(Data_00 + 0x10) & 0x200) != 0) && (CurrentSection == 0)) {
                    /* WARNING: Read-only address (ram,0x800d5e04) is written */
                      ExternalForces.Friction = 0x30;
                    }
                    if (((*(ushort *)(Data_00 + 0x10) & 0x40) != 0) && (0 < Raziel.iVelocity.z)) {
                      StateHandlerSoulSuck(In,CurrentSection,Data);
                    }
                    if ((*(ushort *)(Data_00 + 0x10) & 0x400) != 0) {
                      if (CurrentSection == 0) {
                        Raziel.Mode = 0x10;
                        SetExternalTransitionForce(&__Force_800d5e1c,0,0,-0x10,1,0x1000);
                        In->CharacterInstance->xVel = (int)Raziel.iVelocity.x;
                        In->CharacterInstance->yVel = (int)Raziel.iVelocity.y;
                        In->CharacterInstance->zVel = (int)Raziel.iVelocity.z;
                    /* WARNING: Read-only address (ram,0x800d5e04) is written */
                        ExternalForces.Friction = 0x38;
                      }
                      G2EmulatePlayAnimation(In,CurrentSection,0x23,0,0,1);
                      SteerSwitchMode(In->CharacterInstance,4);
                      StateSwitchStateData(In,CurrentSection,StateHandlerGrab,0);
                    }
                    if ((*(ushort *)(Data_00 + 0x10) & 0x20) != 0) {
                      Raziel.Mode = 0x100000;
                      G2EmulatePlayAnimation(In,CurrentSection,0x23,0,0,1);
                      SteerSwitchMode(In->CharacterInstance,4);
                      StateSwitchStateData(In,CurrentSection,StateHandlerGrab,0);
                      SetExternalTransitionForce(&ExternalForces,0,0,-0x10,1,0x1000);
                    }
                  }
                }
                else {
                  if (puVar3 != (undefined *)0x8000000) goto LAB_800a0138;
                }
              }
              else {
                if (puVar3 != (undefined *)0x20000001) {
                  if ((int)puVar3 < 0x20000002) {
                    if (puVar3 == (undefined *)0x8000004) {
                      if ((*PadData & 0x80) == 0) goto LAB_8009fc84;
                      razSetSwimVelocity(In->CharacterInstance,PlayerData->SwimPhysicsUnderVelocity,
                                         PlayerData->SwimPhysicsUnderKickDecel);
                      goto LAB_800a0144;
                    }
                  }
                  else {
                    if (puVar3 == (undefined *)0x20000004) {
                      Inst = In->CharacterInstance;
                      adjustment = 0x1000;
                      goto LAB_8009ff34;
                    }
                  }
LAB_800a0138:
                  StateHandlerDragObject(In,CurrentSection,Data);
                }
              }
            }
          }
        }
      }
    }
LAB_800a0144:
    PurgeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}





