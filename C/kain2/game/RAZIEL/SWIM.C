#include "THISDUST.H"
#include "SWIM.H"


// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerInitSwim(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$a2*/)
 // line 5, offset 0x8009ee2c
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
                    /* WARNING: Read-only address (ram,0x800d7288) is written */
    ExternalForces.Friction = 0xf80;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerSwimCoil(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s7*/)
 // line 54, offset 0x8009ef38
	/* begin block 1 */
		// Start line: 55
		// Start offset: 0x8009EF38
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		struct evPhysicsSwimData *SwimData; // $a0
	// 		int rc; // $s6
	// 		int release; // $s5

		/* begin block 1.1 */
			// Start line: 237
			// Start offset: 0x8009F5B8
			// Variables:
		// 		struct evMonsterHitData *data; // $v1
		/* end block 1.1 */
		// End offset: 0x8009F5CC
		// End Line: 240
	/* end block 1 */
	// End offset: 0x8009F68C
	// End Line: 273

	/* begin block 2 */
		// Start line: 108
	/* end block 2 */
	// End Line: 109

void StateHandlerSwimCoil(__CharacterState *In,int CurrentSection,int Data)

{
  bool bVar1;
  __Event *p_Var2;
  _Instance *instance;
  int ID;
  undefined *puVar3;
  int NewAnim;
  __State *p_Var4;
  _Instance **pp_Var5;
  uint uVar6;
  int local_30;
  int local_2c;
  
  ControlFlag = ControlFlag & 0xfffffbff;
  uVar6 = In->SectionList[CurrentSection].Data1;
  bVar1 = true;
  if (CurrentSection == 0) {
    if (Raziel.timeAccumulator != 0) {
      razLaunchBubbles(3,3,1);
    }
    if ((Raziel.passedMask & 2) != 0) {
      razLaunchBubbles(3,6,1);
    }
    instance = In->CharacterInstance;
    if (instance->waterFace != (_TFace *)0x0) {
      ID = (int)(instance->splitPoint).z;
      if ((ID < instance->matrix[8].t[2]) || (ID < instance->matrix[0xc].t[2])) {
        PhysicsMode = 6;
      }
    }
  }
  p_Var4 = In->SectionList + CurrentSection;
  pp_Var5 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    p_Var2 = PeekMessageQueue(&p_Var4->Event);
    if (p_Var2 == (__Event *)0x0) {
      if ((bVar1) && ((*PadData & 0x100) == 0)) {
        EnMessageQueueData(&In->SectionList[CurrentSection].Defer,0x20000008,0);
      }
      return;
    }
    puVar3 = (undefined *)p_Var2->ID;
    if (puVar3 == (undefined *)0x1000000) {
      if ((CurrentSection == 0) && ((gameTrackerX.debugFlags2 & 0x800U) != 0)) {
        LoseHealth(*(int *)(p_Var2->Data + 0xc));
      }
    }
    else {
      if ((int)puVar3 < 0x1000001) {
        if (puVar3 == (undefined *)0x100000) {
          if ((uVar6 & 0x40) == 0) {
            if (CurrentSection == 2) {
              NewAnim = 0x3d;
              local_30 = 3;
              ID = 2;
              local_2c = CurrentSection;
            }
            else {
              NewAnim = 0x3f;
              local_30 = 0x10;
              local_2c = 2;
              ID = CurrentSection;
            }
            G2EmulationSwitchAnimation(In,ID,NewAnim,0,local_30,local_2c);
            StateSwitchStateData(In,CurrentSection,StateHandlerSwim,0);
            pp_Var5[0x48] = (_Instance *)((uint)pp_Var5[0x48] | 2);
          }
          else {
            StateSwitchStateData(In,CurrentSection,StateHandlerSwimTread,0);
          }
          if (CurrentSection == 0) {
            instance = In->CharacterInstance;
            ID = PlayerData->SwimPhysicsShotAccelerationOut;
LAB_8009f488:
            razSetSwimVelocity(instance,0,ID);
          }
        }
        else {
          if ((int)puVar3 < 0x100001) {
            if (puVar3 == (undefined *)0x80000001) {
              ID = G2EmulationQueryAnimation(In,CurrentSection);
              if ((ID != 0x43) &&
                 (G2EmulationSwitchAnimation(In,CurrentSection,0x43,0,3,1), CurrentSection == 0)) {
                Raziel.alarmTable = 300;
                (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d7124;
              }
            }
            else {
              if (((-0x80000000 < (int)puVar3) && (puVar3 != &DAT_80000008)) &&
                 (puVar3 != &DAT_80000010)) goto LAB_8009f628;
            }
          }
          else {
            if (puVar3 != &DAT_00100009) {
              if ((int)puVar3 < 0x10000a) {
                if (puVar3 == &DAT_00100001) {
                  if (Raziel.Mode == 0x40000) {
LAB_8009f1ec:
                    if (CurrentSection == 0) {
                      Raziel.Mode = 0x40000;
                      ControlFlag = 0x111;
                      razSetSwimVelocity(In->CharacterInstance,PlayerData->SwimPhysicsCoilVelocity,
                                         PlayerData->SwimPhysicsCoilDecelerationIn);
                      SetTimer(5);
                    }
                  }
                  else {
                    if (CurrentSection == 0) {
                      CAMERA_ChangeToUnderWater(&theCamera,In->CharacterInstance);
                      goto LAB_8009f1ec;
                    }
                  }
                  PhysicsMode = 5;
                  G2EmulationSwitchAnimation(In,CurrentSection,0x41,0,9,2);
                  pp_Var5[0x47] = (_Instance *)0x0;
                  Raziel.passedMask = 0;
                }
                else {
                  if (puVar3 != &DAT_00100004) goto LAB_8009f628;
                  if ((Raziel.Mode & 0x40000U) == 0) goto LAB_8009f608;
                }
              }
              else {
                if (puVar3 == &DAT_00100011) {
                  ID = p_Var2->Data;
                  if (ID == PlayerData->SwimPhysicsCoilVelocity) {
                    razSetSwimVelocity(In->CharacterInstance,0,
                                       PlayerData->SwimPhysicsCoilDecelerationOut);
                    ID = p_Var2->Data;
                  }
                  if (ID == PlayerData->SwimPhysicsShotVelocity) {
                    instance = In->CharacterInstance;
                    ID = PlayerData->SwimPhysicsShotAccelerationOut;
                    goto LAB_8009f488;
                  }
                }
                else {
                  if (puVar3 != &DAT_00100014) goto LAB_8009f628;
                  ID = SetControlInitIdleData(0,0,9);
                  StateSwitchStateData(In,CurrentSection,StateHandlerIdle,ID);
LAB_8009f608:
                  if (CurrentSection == 0) {
                    CAMERA_ChangeToOutOfWater(&theCamera,In->CharacterInstance);
                  }
                }
              }
            }
          }
        }
      }
      else {
        if (puVar3 == (undefined *)0x4020000) {
          ID = p_Var2->Data;
          pp_Var5[0x47] = (_Instance *)(int)*(short *)(ID + 0x10);
          if ((Raziel.CurrentPlane == 1) && ((Raziel.Abilities & 0x10U) == 0)) {
            Raziel.HitPoints = 100000;
          }
          else {
            if ((*(ushort *)(ID + 0x10) & 0x220) != 0) {
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
          if ((int)puVar3 < 0x4020001) {
            if (puVar3 != (undefined *)0x4000001) {
              if ((int)puVar3 < 0x4000002) {
                if (puVar3 != (undefined *)0x1000001) {
LAB_8009f628:
                  DefaultStateHandler(In,CurrentSection,Data);
                }
              }
              else {
                if ((puVar3 != (undefined *)0x4000004) && (puVar3 != (undefined *)0x4010200))
                goto LAB_8009f628;
              }
            }
          }
          else {
            if (puVar3 == (undefined *)0x8000004) {
              razSetSwimVelocity(In->CharacterInstance,PlayerData->SwimPhysicsShotVelocity,
                                 PlayerData->SwimPhysicsShotAccelerationIn);
            }
            else {
              if ((int)puVar3 < 0x8000005) {
                if (puVar3 == (undefined *)0x8000000) {
                  ID = G2EmulationQueryAnimation(In,CurrentSection);
                  if (ID == 0x43) {
                    ID = 0x100000;
LAB_8009f358:
                    EnMessageQueueData(&p_Var4->Defer,ID,0);
                  }
                }
                else {
                  if (puVar3 != (undefined *)0x8000003) goto LAB_8009f628;
                  if ((*PadData & 0x80) != 0) {
                    ID = -0x7fffffff;
                    goto LAB_8009f358;
                  }
                }
              }
              else {
                if (puVar3 != (undefined *)0x20000001) {
                  if (puVar3 != (undefined *)0x20000008) goto LAB_8009f628;
                  ID = G2EmulationQueryAnimation(In,CurrentSection);
                  if (ID != 0x43) {
                    ID = G2EmulationQueryFrame(In,CurrentSection);
                    if (ID < 2) {
                      if (!bVar1) goto LAB_8009f30c;
                      ID = 0x20000008;
                    }
                    else {
                      ID = 0x100000;
                    }
                    EnMessageQueueData(&p_Var4->Defer,ID,0);
                  }
LAB_8009f30c:
                  bVar1 = false;
                }
              }
            }
          }
        }
      }
    }
    DeMessageQueue(&p_Var4->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerSwimTread(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$a2*/)
 // line 277, offset 0x8009f6b8
	/* begin block 1 */
		// Start line: 278
		// Start offset: 0x8009F6B8
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		struct evPhysicsSwimData *SwimData; // $s0

		/* begin block 1.1 */
			// Start line: 422
			// Start offset: 0x8009FBF8
			// Variables:
		// 		struct evPhysicsEdgeData *data; // $s0
		/* end block 1.1 */
		// End offset: 0x8009FC40
		// End Line: 428

		/* begin block 1.2 */
			// Start line: 448
			// Start offset: 0x8009FCDC
			// Variables:
		// 		struct evMonsterHitData *data; // $v1
		/* end block 1.2 */
		// End offset: 0x8009FCFC
		// End Line: 453
	/* end block 1 */
	// End offset: 0x8009FE54
	// End Line: 493

	/* begin block 2 */
		// Start line: 561
	/* end block 2 */
	// End Line: 562

void StateHandlerSwimTread(__CharacterState *In,int CurrentSection,int Data)

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
          G2EmulationSwitchAnimationCharacter(In,0x40,0,3,1);
          StateSwitchStateCharacterData(In,StateHandlerSwimDiveIn,0);
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
    if (puVar3 == (undefined *)0x4000001) goto LAB_8009fd00;
    if ((int)puVar3 < 0x4000002) {
      if (puVar3 != &DAT_00100001) {
        if ((int)puVar3 < 0x100002) {
          if (puVar3 == &DAT_80000008) {
            StateSwitchStateData(In,CurrentSection,StateHandlerSwimCoil,0);
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
                  goto LAB_8009fa68;
                }
                pp_Var4[0x48] = (_Instance *)0x1;
              }
            }
            else {
              if (((puVar3 == &DAT_80000010) && ((Raziel.Mode & 0x10000000U) == 0)) &&
                 (CurrentSection == 0)) {
                StateSwitchStateCharacterData(In,StateHandlerGlyphs,0);
                G2EmulationSwitchAnimationCharacter(In,0x3d,0,9,2);
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
                  if (CurrentSection != 0) goto LAB_8009fd00;
                  CAMERA_ChangeToOutOfWater(&theCamera,In->CharacterInstance);
                }
                if (CurrentSection == 0) {
                  Raziel.passedMask = 0;
                }
              }
            }
            else {
              if (puVar3 == &DAT_00100014) {
                Data_00 = SetControlInitIdleData(0,0,9);
                StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
                if (CurrentSection == 0) {
                  CAMERA_ChangeToOutOfWater(&theCamera,In->CharacterInstance);
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
        goto LAB_8009fd00;
      }
      if ((Raziel.Mode & 0x40000U) == 0) {
        if (CurrentSection == 0) {
          CAMERA_ChangeToUnderWater(&theCamera,In->CharacterInstance);
          goto LAB_8009f84c;
        }
      }
      else {
LAB_8009f84c:
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
LAB_8009fa68:
      G2EmulationSwitchAnimation(In,CurrentSection,NewAnim,0,Data_00,2);
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
            G2EmulationSwitchAnimation(In,CurrentSection,0x23,0,0,1);
            SteerSwitchMode(In->CharacterInstance,4);
            StateSwitchStateData(In,CurrentSection,StateHandlerFall,0);
            SetExternalForce(&ExternalForces,0,0,-0x10,1,0x1000);
          }
          if ((*(ushort *)(Data_00 + 0x10) & 0x80) != 0) {
            Data_00 = SetControlInitIdleData(0,0,9);
            NewProcess = StateHandlerIdle;
            goto LAB_8009fc30;
          }
        }
      }
      else {
        if ((int)puVar3 < 0x4020001) {
          if (puVar3 == (undefined *)0x4010010) {
            Data_00 = p_Var2->Data;
            SetPhysics(In->CharacterInstance,0,0,0,0);
            Data_00 = SetControlInitHangData(*(_Instance **)(Data_00 + 0x18),0,3);
            NewProcess = StateHandlerHang;
LAB_8009fc30:
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
                  goto LAB_8009fa68;
                }
                G2EmulationSwitchAnimation(In,CurrentSection,0x3e,0,3,2);
                Raziel.passedMask = Raziel.passedMask & 0xfffffffe;
              }
              goto LAB_8009fd00;
            }
            if ((p_Var2->Data != 0x3e) || ((*PadData & 0x80) != 0)) goto LAB_8009fd00;
            if (CurrentSection == 2) {
              razSetSwimVelocity(In->CharacterInstance,0,PlayerData->SwimPhysicsSurfAccelerationOut)
              ;
            }
            NewAnim = 0x3d;
            Data_00 = 0xf;
            goto LAB_8009fa68;
          }
        }
      }
    }
LAB_8009fd00:
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerSwimDiveIn(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$a2*/)
 // line 497, offset 0x8009fe80
	/* begin block 1 */
		// Start line: 498
		// Start offset: 0x8009FE80
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		struct evPhysicsSwimData *SwimData; // $s3

		/* begin block 1.1 */
			// Start line: 581
			// Start offset: 0x800A0118
			// Variables:
		// 		struct evMonsterHitData *data; // $v1
		/* end block 1.1 */
		// End offset: 0x800A0138
		// End Line: 586
	/* end block 1 */
	// End offset: 0x800A01E8
	// End Line: 614

	/* begin block 2 */
		// Start line: 1048
	/* end block 2 */
	// End Line: 1049

void StateHandlerSwimDiveIn(__CharacterState *In,int CurrentSection,int Data)

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
      StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
      if (CurrentSection == 0) {
        CAMERA_ChangeToOutOfWater(&theCamera,In->CharacterInstance);
      }
    }
    else {
      if ((int)puVar2 < 0x100015) {
        if ((puVar2 != (undefined *)0x100000) && (0x100000 < (int)puVar2)) {
          if (puVar2 == &DAT_00100001) {
            if (Raziel.Mode != 0x40000) {
              if (CurrentSection != 0) goto LAB_800a0138;
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
              CAMERA_ChangeToOutOfWater(&theCamera,In->CharacterInstance);
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
              if ((*(ushort *)(iVar4 + 0x10) & 0x80) != 0) {
                Data_00 = SetControlInitIdleData(0,0,9);
                StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
              }
            }
            else {
              if (puVar2 == (undefined *)0x8000000) {
                if ((*PadData & 0x80) != 0) {
                  EnMessageQueueData(&p_Var3->Defer,-0x7fffffff,0);
                }
                if ((*(ushort *)(iVar4 + 0x10) & 0x40) == 0) {
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
LAB_800a0138:
    DeMessageQueue(&p_Var3->Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerSwim(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s3*/, int Data /*stack 8*/)
 // line 621, offset 0x800a020c
	/* begin block 1 */
		// Start line: 622
		// Start offset: 0x800A020C
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		struct evPhysicsSwimData *SwimData; // $s2
	// 		int tap; // $fp

		/* begin block 1.1 */
			// Start line: 804
			// Start offset: 0x800A09AC
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.1 */
		// End offset: 0x800A0A58
		// End Line: 816

		/* begin block 1.2 */
			// Start line: 948
			// Start offset: 0x800A0D10
			// Variables:
		// 		struct evMonsterHitData *data; // $v1
		/* end block 1.2 */
		// End offset: 0x800A0D24
		// End Line: 951
	/* end block 1 */
	// End offset: 0x800A0D58
	// End Line: 962

	/* begin block 2 */
		// Start line: 1424
	/* end block 2 */
	// End Line: 1425

void StateHandlerSwim(__CharacterState *In,int CurrentSection,int Data)

{
  bool bVar1;
  __Event *p_Var2;
  int Data_00;
  int local_2c;
  ulong uVar3;
  undefined *puVar4;
  _Instance *Inst;
  code *NewProcess;
  long adjustment;
  __MessageQueue *In_00;
  _Instance **pp_Var5;
  int local_30;
  int NewAnim;
  
  bVar1 = true;
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
  pp_Var5 = &In->CharacterInstance + CurrentSection * 0x47;
  do {
    In_00 = &In->SectionList[CurrentSection].Event;
    p_Var2 = PeekMessageQueue(In_00);
    if (p_Var2 == (__Event *)0x0) {
      return;
    }
    puVar4 = (undefined *)p_Var2->ID;
    if (puVar4 == &DAT_00100014) {
      Data_00 = SetControlInitIdleData(0,0,9);
      StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
      if (CurrentSection == 0) {
        CAMERA_ChangeToOutOfWater(&theCamera,In->CharacterInstance);
      }
    }
    else {
      Data_00 = CurrentSection;
      if ((int)puVar4 < 0x100015) {
        if (puVar4 == &DAT_80000010) {
          if (((Raziel.Mode & 0x10000000U) == 0) && (CurrentSection == 0)) {
            StateSwitchStateCharacterData(In,StateHandlerGlyphs,0);
            G2EmulationSwitchAnimation(In,2,0x3d,0,3,2);
            G2EmulationSwitchAnimation(In,0,0x3f,0,0x10,2);
            local_2c = 0x3f;
            NewAnim = 0x10;
            Data_00 = 1;
            goto LAB_800a0cb0;
          }
        }
        else {
          if ((int)puVar4 < -0x7fffffef) {
            if (puVar4 == &DAT_80000002) {
              if (CurrentSection == 1) {
                Raziel.returnState = (_func_60 *)In->SectionList[1].Process;
                StateSwitchStateData(In,1,StateHandlerSoulSuck,0);
              }
            }
            else {
              if ((int)puVar4 < -0x7ffffffd) {
                if (puVar4 != (undefined *)0x80000000) {
                  if (puVar4 != (undefined *)0x80000001) goto LAB_800a0d38;
                  if (Raziel.steeringMode == 6) {
                    local_2c = G2EmulationQueryAnimation(In,CurrentSection);
                    if (local_2c != 0x44) {
                      if (CurrentSection == 0) {
                        razSetSwimVelocity(In->CharacterInstance,
                                           PlayerData->SwimPhysicsUnderKickVelocity,
                                           PlayerData->SwimPhysicsUnderKickAccel);
                        Raziel.alarmTable = 0x5dc;
                        (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d7124;
                      }
                      local_2c = 0x44;
                      NewAnim = 5;
                      goto LAB_800a0cb0;
                    }
                    pp_Var5[0x48] = (_Instance *)((uint)pp_Var5[0x48] | 1);
                  }
                }
              }
              else {
                if (puVar4 == &DAT_80000004) {
                  Inst = In->CharacterInstance;
                  adjustment = PlayerData->SwimPhysicsUnderStealthAdjust;
LAB_800a0c0c:
                  G2Anim_SetSpeedAdjustment(&Inst->anim,adjustment);
                }
                else {
                  if (puVar4 != &DAT_80000008) goto LAB_800a0d38;
                  if (CurrentSection == 0) {
                    Data_00 = G2EmulationQueryFrame(In,0);
                    if (1 < Data_00) {
                      NewProcess = StateHandlerSwimCoil;
                      goto LAB_800a0820;
                    }
                    if (bVar1) {
                      bVar1 = false;
                      EnMessageQueueData(&In->SectionList[0].Defer,(int)&DAT_80000008,0);
                    }
                  }
                }
              }
            }
          }
          else {
            if (puVar4 == &DAT_00100001) {
              if (Raziel.Mode == 0x40000) {
LAB_800a04e4:
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
                  goto LAB_800a04e4;
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
              }
              G2EmulationSwitchAnimation(In,Data_00,NewAnim,0,local_30,local_2c);
              PhysicsMode = 5;
              pp_Var5[0x47] = (_Instance *)0x0;
              pp_Var5[0x48] = (_Instance *)0x0;
              Raziel.passedMask = 0;
            }
            else {
              if ((int)puVar4 < 0x100002) {
                if (puVar4 == &DAT_80000020) {
                  Inst = razGetHeldWeapon();
                  if (Inst == (_Instance *)0x0) {
                    Data_00 = 0x80000;
                    if ((Raziel.Abilities & 4U) == 0) goto LAB_800a0d48;
                  }
                  else {
                    Data_00 = 0x800010;
                  }
                  EnMessageQueueData(In_00,Data_00,1);
                }
                else {
                  if (puVar4 != (undefined *)0x80000) goto LAB_800a0d38;
                  if (CurrentSection == 0) {
                    razLaunchForce(In->CharacterInstance);
                    NewProcess = StateHandlerThrow2;
LAB_800a0820:
                    StateSwitchStateCharacterData(In,NewProcess,0);
                  }
                }
              }
              else {
                if (puVar4 == &DAT_00100004) {
                  if ((Raziel.Mode & 0x40000U) == 0) {
                    if (CurrentSection != 0) goto LAB_800a0d48;
                    G2Anim_SetSpeedAdjustment(&In->CharacterInstance->anim,0x1000);
                    CAMERA_ChangeToOutOfWater(&theCamera,In->CharacterInstance);
                  }
                  if (CurrentSection == 0) {
                    Raziel.passedMask = 0;
                  }
                }
                else {
                  if (puVar4 != &DAT_00100009) goto LAB_800a0d38;
                  if (CurrentSection == 0) {
                    if (p_Var2->Data == 0) {
                      SteerSwitchMode(In->CharacterInstance,6);
                    }
                    else {
                      SteerSwitchMode(In->CharacterInstance,0);
LAB_800a0940:
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
        if (puVar4 != (undefined *)0x4010200) {
          if ((int)puVar4 < 0x4010201) {
            if (puVar4 != (undefined *)0x1000001) {
              if ((int)puVar4 < 0x1000002) {
                if (puVar4 == (undefined *)0x800010) {
                  if (CurrentSection == 0) {
                    NewProcess = StateHandlerThrow2;
                    goto LAB_800a0820;
                  }
                }
                else {
                  if (puVar4 != (undefined *)0x1000000) goto LAB_800a0d38;
                  if ((CurrentSection == 0) && ((gameTrackerX.debugFlags2 & 0x800U) != 0)) {
                    LoseHealth(*(int *)(p_Var2->Data + 0xc));
                  }
                }
              }
              else {
                if (puVar4 == (undefined *)0x2000000) {
                  razPickupAndGrab(In,CurrentSection);
                }
                else {
                  if (puVar4 != (undefined *)0x4000001) goto LAB_800a0d38;
                }
              }
            }
          }
          else {
            if (puVar4 == (undefined *)0x8000001) {
              local_2c = p_Var2->Data;
              if ((local_2c == 0x44) || (local_2c == 0x42)) {
                if (((uint)pp_Var5[0x48] & 1) == 0) {
                  if (((*PadData & 0x80) == 0) || (Raziel.steeringMode != 6)) {
                    if (CurrentSection == 0) {
                      razSetSwimVelocity(In->CharacterInstance,0,
                                         PlayerData->SwimPhysicsUnderDeceleration);
                    }
                    if (CurrentSection == 2) goto LAB_800a07b8;
                    local_2c = 0x3f;
                    NewAnim = 8;
                  }
                  else {
                    if (CurrentSection == 2) {
                      Data_00 = 0;
                      goto LAB_800a07c4;
                    }
                    local_2c = 0x3c;
                    NewAnim = 0xc;
                  }
LAB_800a0cb0:
                  G2EmulationSwitchAnimation(In,Data_00,local_2c,0,NewAnim,2);
                }
                else {
                  razSetSwimVelocity(In->CharacterInstance,PlayerData->SwimPhysicsUnderKickVelocity,
                                     PlayerData->SwimPhysicsUnderKickAccel);
                  pp_Var5[0x48] = (_Instance *)((uint)pp_Var5[0x48] & 0xfffffffe);
                }
              }
              else {
                if ((local_2c != 0x3f) && ((*PadData & 0x80) == 0)) {
                  if (CurrentSection == 0) {
                    razSetSwimVelocity(In->CharacterInstance,0,
                                       PlayerData->SwimPhysicsUnderDeceleration);
                  }
                  if (CurrentSection != 2) {
                    local_2c = 0x3f;
                    NewAnim = 0x10;
                    goto LAB_800a0cb0;
                  }
LAB_800a07b8:
                  Data_00 = 0x3d;
LAB_800a07c4:
                  G2EmulationSwitchAnimation(In,2,Data_00,0,3,CurrentSection);
                }
              }
            }
            else {
              if ((int)puVar4 < 0x8000002) {
                if (puVar4 == (undefined *)0x4020000) {
                  Data_00 = p_Var2->Data;
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
                      if ((Inst != (_Instance *)0x0) && (uVar3 = INSTANCE_Query(Inst,4), uVar3 == 3)
                         ) {
                        CAMERA_ChangeToOutOfWater(&theCamera,In->CharacterInstance);
                        local_2c = SetControlInitIdleData(0,0,9);
                        StateSwitchStateCharacterData(In,StateHandlerIdle,local_2c);
                      }
                    }
                    if (((*(ushort *)(Data_00 + 0x10) & 0x200) != 0) && (CurrentSection == 0)) {
                    /* WARNING: Read-only address (ram,0x800d7288) is written */
                      ExternalForces.Friction = 0x30;
                    }
                    if ((((*(ushort *)(Data_00 + 0x10) & 0x40) != 0) && (Raziel.Mode == 0x40000)) &&
                       (0 < Raziel.iVelocity.z)) {
                      StateHandlerInitSwim(In,CurrentSection,Data);
                    }
                    if ((*(ushort *)(Data_00 + 0x10) & 0x400) != 0) {
                      if (CurrentSection == 0) {
                        Raziel.Mode = 0x10;
                        SetExternalForce(&__Force_800d72a0,0,0,-0x10,1,0x1000);
                        In->CharacterInstance->xVel = (int)Raziel.iVelocity.x;
                        In->CharacterInstance->yVel = (int)Raziel.iVelocity.y;
                        In->CharacterInstance->zVel = (int)Raziel.iVelocity.z;
                    /* WARNING: Read-only address (ram,0x800d7288) is written */
                        ExternalForces.Friction = 0x38;
                      }
                      G2EmulationSwitchAnimation(In,CurrentSection,0x23,0,0,1);
                      SteerSwitchMode(In->CharacterInstance,4);
                      StateSwitchStateData(In,CurrentSection,StateHandlerFall,0);
                    }
                    if ((*(ushort *)(Data_00 + 0x10) & 0x20) != 0) {
                      Raziel.Mode = 0x100000;
                      G2EmulationSwitchAnimation(In,CurrentSection,0x23,0,0,1);
                      SteerSwitchMode(In->CharacterInstance,4);
                      StateSwitchStateData(In,CurrentSection,StateHandlerFall,0);
                      SetExternalForce(&ExternalForces,0,0,-0x10,1,0x1000);
                    }
                  }
                }
                else {
                  if (puVar4 != (undefined *)0x8000000) goto LAB_800a0d38;
                }
              }
              else {
                if (puVar4 != (undefined *)0x20000001) {
                  if ((int)puVar4 < 0x20000002) {
                    if (puVar4 == (undefined *)0x8000004) {
                      if ((*PadData & 0x80) == 0) goto LAB_800a0940;
                      razSetSwimVelocity(In->CharacterInstance,PlayerData->SwimPhysicsUnderVelocity,
                                         PlayerData->SwimPhysicsUnderKickDecel);
                      goto LAB_800a0d48;
                    }
                  }
                  else {
                    if (puVar4 == (undefined *)0x20000004) {
                      Inst = In->CharacterInstance;
                      adjustment = 0x1000;
                      goto LAB_800a0c0c;
                    }
                  }
LAB_800a0d38:
                  DefaultStateHandler(In,CurrentSection,Data);
                }
              }
            }
          }
        }
      }
    }
LAB_800a0d48:
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  } while( true );
}





