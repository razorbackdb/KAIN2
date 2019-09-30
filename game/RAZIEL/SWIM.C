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

void StateHandlerInitSwim(__CharacterState *In,int CurrentSection,int Data)

{
                    /* WARNING: Subroutine does not return */
  G2EmulationSwitchAnimation(In,CurrentSection,0x3d,0,9,2);
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

void StateHandlerSwimCoil(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *p_Var2;
  int CurrentSection_00;
  undefined *puVar3;
  int NewAnim;
  __State *p_Var4;
  uint uVar5;
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
    p_Var2 = In->CharacterInstance;
    if (p_Var2->waterFace != (_TFace *)0x0) {
      CurrentSection_00 = (int)(p_Var2->splitPoint).z;
      if ((CurrentSection_00 < p_Var2->matrix[8].t[2]) ||
         (CurrentSection_00 < p_Var2->matrix[0xc].t[2])) {
        PhysicsMode = 6;
      }
    }
  }
  p_Var4 = In->SectionList + CurrentSection;
  p_Var1 = PeekMessageQueue(&p_Var4->Event);
  if (p_Var1 == (__Event *)0x0) {
    return;
  }
  puVar3 = (undefined *)p_Var1->ID;
  if (puVar3 == &DAT_00100014) {
                    /* WARNING: Subroutine does not return */
    SetControlInitIdleData(0,0,9);
  }
  if ((int)puVar3 < 0x100015) {
    if (puVar3 == (undefined *)0x100000) {
      if ((uVar5 & 0x40) == 0) {
        if (CurrentSection == 2) {
          NewAnim = 0x3d;
          local_28 = 3;
          CurrentSection_00 = 2;
          local_24 = CurrentSection;
        }
        else {
          NewAnim = 0x3f;
          local_28 = 0x10;
          local_24 = 2;
          CurrentSection_00 = CurrentSection;
        }
                    /* WARNING: Subroutine does not return */
        G2EmulationSwitchAnimation(In,CurrentSection_00,NewAnim,0,local_28,local_24);
      }
                    /* WARNING: Subroutine does not return */
      StateSwitchStateData(In,CurrentSection,StateHandlerSwimTread,0);
    }
    if ((int)puVar3 < 0x100001) {
      if (puVar3 == (undefined *)0x80000001) {
        CurrentSection_00 = G2EmulationQueryAnimation(In,CurrentSection);
        if (CurrentSection_00 != 0x43) {
                    /* WARNING: Subroutine does not return */
          G2EmulationSwitchAnimation(In,CurrentSection,0x43,0,3,1);
        }
        goto LAB_8009ea3c;
      }
      if ((((int)puVar3 < -0x7fffffff) || (puVar3 == &DAT_80000008)) || (puVar3 == &DAT_80000010))
      goto LAB_8009ea3c;
    }
    else {
      if (puVar3 == &DAT_00100004) {
        if (((Raziel.Mode & 0x40000U) == 0) && (CurrentSection == 0)) {
          CAMERA_ChangeToOutOfWater(&theCamera,In->CharacterInstance);
        }
        goto LAB_8009ea3c;
      }
      if ((int)puVar3 < 0x100005) {
        if (puVar3 == &DAT_00100001) {
          if (Raziel.Mode != 0x40000) {
            if (CurrentSection != 0) goto LAB_8009e680;
            CAMERA_ChangeToUnderWater(&theCamera,In->CharacterInstance);
          }
          if (CurrentSection == 0) {
            Raziel.Mode = 0x40000;
            ControlFlag = 0x111;
            razSetSwimVelocity(In->CharacterInstance,PlayerData->SwimPhysicsCoilVelocity,
                               PlayerData->SwimPhysicsCoilDecelerationIn);
            SetTimer(5);
          }
LAB_8009e680:
          PhysicsMode = 5;
                    /* WARNING: Subroutine does not return */
          G2EmulationSwitchAnimation(In,CurrentSection,0x41,0,9,2);
        }
      }
      else {
        if (puVar3 == &DAT_00100009) goto LAB_8009ea3c;
        if (puVar3 == &DAT_00100011) {
          CurrentSection_00 = p_Var1->Data;
          if (CurrentSection_00 == PlayerData->SwimPhysicsCoilVelocity) {
            razSetSwimVelocity(In->CharacterInstance,0,PlayerData->SwimPhysicsCoilDecelerationOut);
            CurrentSection_00 = p_Var1->Data;
          }
          if (CurrentSection_00 == PlayerData->SwimPhysicsShotVelocity) {
            razSetSwimVelocity(In->CharacterInstance,0,PlayerData->SwimPhysicsShotAccelerationOut);
          }
          goto LAB_8009ea3c;
        }
      }
    }
  }
  else {
    if (puVar3 == (undefined *)0x4010200) goto LAB_8009ea3c;
    if ((int)puVar3 < 0x4010201) {
      if (puVar3 == (undefined *)0x1000001) goto LAB_8009ea3c;
      if ((int)puVar3 < 0x1000002) {
        if (puVar3 == (undefined *)0x1000000) {
          if ((CurrentSection == 0) && ((gameTrackerX.debugFlags2 & 0x800U) != 0)) {
            LoseHealth(*(int *)(p_Var1->Data + 0xc));
          }
          goto LAB_8009ea3c;
        }
      }
      else {
        if ((puVar3 == (undefined *)0x4000001) || (puVar3 == (undefined *)0x4000004))
        goto LAB_8009ea3c;
      }
    }
    else {
      if (puVar3 == (undefined *)0x8000004) {
        razSetSwimVelocity(In->CharacterInstance,PlayerData->SwimPhysicsShotVelocity,
                           PlayerData->SwimPhysicsShotAccelerationIn);
        goto LAB_8009ea3c;
      }
      if ((int)puVar3 < 0x8000005) {
        if (puVar3 == (undefined *)0x4020000) {
          CurrentSection_00 = p_Var1->Data;
          In->SectionList[CurrentSection].Data1 = (int)*(short *)(CurrentSection_00 + 0x10);
          if ((Raziel.CurrentPlane == 1) && ((Raziel.Abilities & 0x10U) == 0)) {
            Raziel.HitPoints = 100000;
          }
          else {
            if ((*(ushort *)(CurrentSection_00 + 0x10) & 0x220) != 0) {
              if (CurrentSection != 0) {
                    /* WARNING: Subroutine does not return */
                G2EmulationSwitchAnimation(In,CurrentSection,0x23,0,0,1);
              }
              Raziel.Mode = 0x10;
              SetPhysics(In->CharacterInstance,-0x10,0,0x15,0xc3);
                    /* WARNING: Subroutine does not return */
              SteerSwitchMode(In->CharacterInstance,4);
            }
          }
          goto LAB_8009ea3c;
        }
        if (puVar3 == (undefined *)0x8000000) {
          CurrentSection_00 = G2EmulationQueryAnimation(In,CurrentSection);
          if (CurrentSection_00 == 0x43) {
LAB_8009e758:
                    /* WARNING: Subroutine does not return */
            EnMessageQueueData(&p_Var4->Defer,0x100000,0);
          }
          goto LAB_8009ea3c;
        }
      }
      else {
        if (puVar3 == (undefined *)0x20000001) goto LAB_8009ea3c;
        if (puVar3 == (undefined *)0x20000008) {
          CurrentSection_00 = G2EmulationQueryAnimation(In,CurrentSection);
          if (CurrentSection_00 != 0x43) goto LAB_8009e758;
          goto LAB_8009ea3c;
        }
      }
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
LAB_8009ea3c:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&p_Var4->Event);
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

void StateHandlerSwimTread(__CharacterState *In,int CurrentSection,int Data)

{
  RazielData *pRVar1;
  __Event *p_Var2;
  int Data_00;
  undefined *puVar3;
  undefined In_00;
  _Instance **pp_Var4;
  
  pp_Var4 = &In->CharacterInstance + CurrentSection * 0x47;
  ControlFlag = ControlFlag | 0x400;
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
                    /* WARNING: Subroutine does not return */
        G2EmulationSwitchAnimationCharacter(In,0x40,0,3,1);
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
  if (puVar3 == (undefined *)0x4000001) {
LAB_8009f0b4:
                    /* WARNING: Subroutine does not return */
    DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
  }
  In_00 = SUB41(In,0);
  if (0x4000001 < (int)puVar3) {
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
                    /* WARNING: Subroutine does not return */
          G2EmulationSwitchAnimation(In,CurrentSection,0x23,0,0,1);
        }
        if ((*(ushort *)(Data_00 + 0x10) & 0x80) != 0) {
                    /* WARNING: Subroutine does not return */
          SetControlInitIdleData(0,0,9);
        }
      }
    }
    else {
      if ((int)puVar3 < 0x4020001) {
        if (puVar3 == (undefined *)0x4010010) {
          Data_00 = p_Var2->Data;
          SetPhysics(In->CharacterInstance,0,0,0,0);
          Data_00 = SetControlInitHangData(*(_Instance **)(Data_00 + 0x18),0,3);
                    /* WARNING: Subroutine does not return */
          StateSwitchStateData(In,CurrentSection,StateHandlerHang,Data_00);
        }
      }
      else {
        if (puVar3 == (undefined *)0x8000001) {
          if (p_Var2->Data == 0x42) {
            if (pp_Var4[0x48] != (_Instance *)0x1) {
              if (((*PadData & 0x80) != 0) && (Raziel.steeringMode != 0)) {
                    /* WARNING: Subroutine does not return */
                G2EmulationSwitchAnimation(In,CurrentSection,0x3e,0,3,2);
              }
              razSetSwimVelocity(In->CharacterInstance,0,PlayerData->SwimPhysicsSurfKickDecel);
              StateHandlerInitSwim(In_00,CurrentSection,0x3d);
              return;
            }
            pp_Var4[0x48] = (_Instance *)0x0;
            razSetSwimVelocity(In->CharacterInstance,pRVar1->SwimPhysicsSurfVelocity,
                               pRVar1->SwimPhysicsSurfAccelerationIn);
          }
          else {
            if ((p_Var2->Data == 0x3e) && ((*PadData & 0x80) == 0)) {
              if (CurrentSection == 2) {
                razSetSwimVelocity(In->CharacterInstance,0,
                                   PlayerData->SwimPhysicsSurfAccelerationOut);
              }
              StateHandlerInitSwim(In_00,CurrentSection,0x3d);
              return;
            }
          }
        }
      }
    }
    goto LAB_8009f0b4;
  }
  if (puVar3 != &DAT_00100001) {
    if ((int)puVar3 < 0x100002) {
      if (puVar3 == &DAT_80000008) {
                    /* WARNING: Subroutine does not return */
        StateSwitchStateData(In,CurrentSection,StateHandlerSwimCoil,0);
      }
      if ((int)puVar3 < -0x7ffffff7) {
        if ((puVar3 == (undefined *)0x80000001) && (Raziel.steeringMode == 6)) {
          Data_00 = G2EmulationQueryAnimation(In,CurrentSection);
          if (Data_00 != 0x42) {
            if (CurrentSection == 2) {
              razSetSwimVelocity(In->CharacterInstance,PlayerData->SwimPhysicsSurfVelocity,
                                 PlayerData->SwimPhysicsSurfAccelerationIn);
            }
                    /* WARNING: Subroutine does not return */
            G2EmulationSwitchAnimation(In,CurrentSection,0x42,0,5,2);
          }
          pp_Var4[0x48] = (_Instance *)0x1;
        }
      }
      else {
        if (((puVar3 == &DAT_80000010) && ((Raziel.Mode & 0x10000000U) == 0)) &&
           (CurrentSection == 0)) {
          StateSwitchStateCharacterData(In,StateHandlerGlyphs,0);
        }
      }
    }
    else {
      if (puVar3 == &DAT_00100009) {
        if (CurrentSection == 0) {
          if (p_Var2->Data == 0) {
                    /* WARNING: Subroutine does not return */
            SteerSwitchMode(In->CharacterInstance,6);
          }
                    /* WARNING: Subroutine does not return */
          SteerSwitchMode(In->CharacterInstance,0);
        }
      }
      else {
        if ((int)puVar3 < 0x10000a) {
          if (puVar3 == &DAT_00100004) {
            if ((Raziel.Mode & 0x40000U) == 0) {
              if (CurrentSection != 0) goto LAB_8009f0b4;
              CAMERA_ChangeToOutOfWater(&theCamera,In->CharacterInstance);
            }
            if (CurrentSection == 0) {
              Raziel.passedMask = 0;
            }
          }
        }
        else {
          if (puVar3 == &DAT_00100014) {
                    /* WARNING: Subroutine does not return */
            SetControlInitIdleData(0,0,9);
          }
          if (((puVar3 == (undefined *)0x1000000) && (CurrentSection == 0)) &&
             ((gameTrackerX.debugFlags2 & 0x800U) != 0)) {
            LoseHealth(*(int *)(p_Var2->Data + 0xc));
          }
        }
      }
    }
    goto LAB_8009f0b4;
  }
  if ((Raziel.Mode & 0x40000U) == 0) {
    if (CurrentSection != 0) goto LAB_8009ec50;
    CAMERA_ChangeToUnderWater(&theCamera,In->CharacterInstance);
  }
  if (CurrentSection == 0) {
    Raziel.Mode = 0x40000;
    ControlFlag = 0x511;
    PhysicsMode = 6;
    razSetSwimVelocity(In->CharacterInstance,0,PlayerData->SwimPhysicsSurfAccelerationOut);
                    /* WARNING: Subroutine does not return */
    SteerSwitchMode(In->CharacterInstance,6);
  }
LAB_8009ec50:
  StateHandlerInitSwim(In_00,CurrentSection,0x3d);
  return;
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

void StateHandlerSwimDiveIn(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  undefined *puVar2;
  __State *p_Var3;
  
  p_Var3 = In->SectionList + CurrentSection;
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
                    /* WARNING: Subroutine does not return */
    SetControlInitIdleData(0,0,9);
  }
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
                    /* WARNING: Subroutine does not return */
          SteerSwitchMode(In->CharacterInstance,0x11);
        }
      }
      else {
        if (((puVar2 == &DAT_00100004) && ((Raziel.Mode & 0x40000U) == 0)) && (CurrentSection == 0))
        {
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
        if ((puVar2 != (undefined *)0x4020000) && (puVar2 == (undefined *)0x8000000)) {
          if ((*PadData & 0x80) != 0) {
                    /* WARNING: Subroutine does not return */
            EnMessageQueueData(&p_Var3->Defer,-0x7fffffff,0);
          }
          if (((ushort)DAT_00000010 & 0x40) == 0) {
                    /* WARNING: Subroutine does not return */
            StateSwitchStateData(In,CurrentSection,StateHandlerSwim,0);
          }
                    /* WARNING: Subroutine does not return */
          StateSwitchStateData(In,CurrentSection,StateHandlerSwimTread,0);
        }
      }
    }
  }
LAB_8009f4bc:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&p_Var3->Event);
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

void StateHandlerSwim(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int NewAnim;
  undefined *puVar2;
  _Instance *Inst;
  long adjustment;
  int NewAnim_00;
  code *NewProcess;
  int local_2c;
  __MessageQueue *In_00;
  _Instance **pp_Var3;
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
  pp_Var3 = &In->CharacterInstance + CurrentSection * 0x47;
  In_00 = &In->SectionList[CurrentSection].Event;
  p_Var1 = PeekMessageQueue(In_00);
  if (p_Var1 == (__Event *)0x0) {
    return;
  }
  puVar2 = (undefined *)p_Var1->ID;
  if (puVar2 == &DAT_00100014) {
                    /* WARNING: Subroutine does not return */
    SetControlInitIdleData(0,0,9);
  }
  if ((int)puVar2 < 0x100015) {
    if (puVar2 == &DAT_80000010) {
      if (((Raziel.Mode & 0x10000000U) == 0) && (CurrentSection == 0)) {
        StateSwitchStateCharacterData(In,StateHandlerGlyphs,0);
      }
      goto LAB_800a0144;
    }
    if ((int)puVar2 < -0x7fffffef) {
      if (puVar2 == &DAT_80000002) {
        if (CurrentSection == 1) {
          Raziel.returnState = (_func_60 *)In->SectionList[1].Process;
                    /* WARNING: Subroutine does not return */
          StateSwitchStateData(In,1,StateHandlerSoulSuck,0);
        }
        goto LAB_800a0144;
      }
      if ((int)puVar2 < -0x7ffffffd) {
        if (puVar2 == (undefined *)0x80000000) goto LAB_800a0144;
        if (puVar2 == (undefined *)0x80000001) {
          if (Raziel.steeringMode == 6) {
            NewAnim = G2EmulationQueryAnimation(In,CurrentSection);
            if (NewAnim != 0x44) {
              if (CurrentSection == 0) {
                razSetSwimVelocity(In->CharacterInstance,PlayerData->SwimPhysicsUnderKickVelocity,
                                   PlayerData->SwimPhysicsUnderKickAccel);
                Raziel.alarmTable = 0x5dc;
                (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5c98;
              }
              local_2c = 0x44;
              NewAnim = 5;
              goto LAB_8009fbfc;
            }
            pp_Var3[0x48] = (_Instance *)((uint)pp_Var3[0x48] | 1);
          }
          goto LAB_800a0144;
        }
      }
      else {
        if (puVar2 == &DAT_80000004) {
          Inst = In->CharacterInstance;
          adjustment = PlayerData->SwimPhysicsUnderStealthAdjust;
LAB_8009ff34:
                    /* WARNING: Subroutine does not return */
          G2Anim_SetSpeedAdjustment(&Inst->anim,adjustment);
        }
        if (puVar2 == &DAT_80000008) {
          NewProcess = StateHandlerSwimCoil;
          goto LAB_800a0074;
        }
      }
    }
    else {
      if (puVar2 == &DAT_00100001) {
        if (Raziel.Mode != 0x40000) {
          if (CurrentSection != 0) goto LAB_8009f8ac;
          CAMERA_ChangeToUnderWater(&theCamera,In->CharacterInstance);
        }
        if (CurrentSection == 0) {
          Raziel.Mode = 0x40000;
          Raziel.RotationSegment = 1;
          ControlFlag = 400;
                    /* WARNING: Subroutine does not return */
          SteerSwitchMode(In->CharacterInstance,6);
        }
LAB_8009f8ac:
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
                    /* WARNING: Subroutine does not return */
        G2EmulationSwitchAnimation(In,NewAnim,NewAnim_00,0,local_30,local_2c);
      }
      if ((int)puVar2 < 0x100002) {
        if (puVar2 == &DAT_80000020) {
          Inst = razGetHeldWeapon();
          if (Inst == (_Instance *)0x0) {
            NewAnim = 0x80000;
            if ((Raziel.Abilities & 4U) == 0) goto LAB_800a0144;
          }
          else {
            NewAnim = 0x800010;
          }
                    /* WARNING: Subroutine does not return */
          EnMessageQueueData(In_00,NewAnim,1);
        }
        if (puVar2 == (undefined *)0x80000) {
          if (CurrentSection == 0) {
            razLaunchForce(In->CharacterInstance);
          }
          NewProcess = StateHandlerThrow2;
          goto LAB_800a0074;
        }
      }
      else {
        if (puVar2 == &DAT_00100004) {
          if ((Raziel.Mode & 0x40000U) == 0) {
            if (CurrentSection == 0) {
                    /* WARNING: Subroutine does not return */
              G2Anim_SetSpeedAdjustment(&In->CharacterInstance->anim,0x1000);
            }
          }
          else {
            if (CurrentSection == 0) {
              Raziel.passedMask = 0;
            }
          }
          goto LAB_800a0144;
        }
        if (puVar2 == &DAT_00100009) {
          if (CurrentSection == 0) {
            if (p_Var1->Data == 0) {
                    /* WARNING: Subroutine does not return */
              SteerSwitchMode(In->CharacterInstance,6);
            }
                    /* WARNING: Subroutine does not return */
            SteerSwitchMode(In->CharacterInstance,0);
          }
          goto LAB_800a0144;
        }
      }
    }
  }
  else {
    if (puVar2 == (undefined *)0x4010200) goto LAB_800a0144;
    if ((int)puVar2 < 0x4010201) {
      if (puVar2 == (undefined *)0x1000001) goto LAB_800a0144;
      if ((int)puVar2 < 0x1000002) {
        if (puVar2 == (undefined *)0x800010) {
          NewProcess = StateHandlerThrow2;
LAB_800a0074:
                    /* WARNING: Subroutine does not return */
          StateSwitchStateData(In,CurrentSection,NewProcess,0);
        }
        if (puVar2 == (undefined *)0x1000000) {
          if ((CurrentSection == 0) && ((gameTrackerX.debugFlags2 & 0x800U) != 0)) {
            LoseHealth(*(int *)(p_Var1->Data + 0xc));
          }
          goto LAB_800a0144;
        }
      }
      else {
        if (puVar2 == (undefined *)0x2000000) {
          if (((Raziel.Senses.EngagedMask & 0x20) != 0) &&
             (Inst = razGetHeldItem(), Inst == (_Instance *)0x0)) {
            Inst = (Raziel.Senses.EngagedList[5].instance)->LinkParent;
            if (Inst == (_Instance *)0x0) {
              Raziel.Mode = 0x800;
              pp_Var3[0x47] = (_Instance *)0x0;
                    /* WARNING: Subroutine does not return */
              G2EmulationSwitchAnimation(In,CurrentSection,0xb,0,3,1);
            }
                    /* WARNING: Subroutine does not return */
            INSTANCE_Query(Inst,0);
          }
          if (((p_Var1->Data & 1U) != 0) && (Inst = razGetHeldItem(), Inst != (_Instance *)0x0)) {
            NewProcess = StateHandlerAttack2;
            goto LAB_800a0074;
          }
          goto LAB_800a0144;
        }
        if (puVar2 == (undefined *)0x4000001) goto LAB_800a0144;
      }
    }
    else {
      if (puVar2 == (undefined *)0x8000001) {
        NewAnim = p_Var1->Data;
        if ((NewAnim == 0x44) || (NewAnim == 0x42)) {
          if (((uint)pp_Var3[0x48] & 1) != 0) {
            razSetSwimVelocity(In->CharacterInstance,PlayerData->SwimPhysicsUnderKickVelocity,
                               PlayerData->SwimPhysicsUnderKickAccel);
            pp_Var3[0x48] = (_Instance *)((uint)pp_Var3[0x48] & 0xfffffffe);
            goto LAB_800a0144;
          }
          if (((*PadData & 0x80) != 0) && (Raziel.steeringMode == 6)) {
            if (CurrentSection != 2) {
              local_2c = 0x3c;
              NewAnim = 0xc;
              goto LAB_8009fbfc;
            }
            NewAnim = 0;
            goto LAB_8009fb48;
          }
          if (CurrentSection == 0) {
            razSetSwimVelocity(In->CharacterInstance,0,PlayerData->SwimPhysicsUnderDeceleration);
          }
          if (CurrentSection != 2) {
            local_2c = 0x3f;
            NewAnim = 8;
LAB_8009fbfc:
                    /* WARNING: Subroutine does not return */
            G2EmulationSwitchAnimation(In,CurrentSection,local_2c,0,NewAnim,2);
          }
        }
        else {
          if ((NewAnim == 0x3f) || ((*PadData & 0x80) != 0)) goto LAB_800a0144;
          if (CurrentSection == 0) {
            razSetSwimVelocity(In->CharacterInstance,0,PlayerData->SwimPhysicsUnderDeceleration);
          }
          if (CurrentSection != 2) {
            local_2c = 0x3f;
            NewAnim = 0x10;
            goto LAB_8009fbfc;
          }
        }
        NewAnim = 0x3d;
LAB_8009fb48:
                    /* WARNING: Subroutine does not return */
        G2EmulationSwitchAnimation(In,2,NewAnim,0,3,CurrentSection);
      }
      if ((int)puVar2 < 0x8000002) {
        if (puVar2 == (undefined *)0x4020000) {
          NewAnim = p_Var1->Data;
          if ((Raziel.CurrentPlane == 1) && ((Raziel.Abilities & 0x10U) == 0)) {
            Raziel.HitPoints = 100000;
          }
          else {
            if (CurrentSection == 0) {
              Inst = razGetHeldWeapon();
              PhysicsForceSetWater
                        (In->CharacterInstance,&In->SectionList[0].Data1,
                         (int)*(short *)(NewAnim + 0xc),PlayerData->SwimPhysicsWaterFrequency,
                         PlayerData->SwimPhysicsWaterAmplitude);
              if (*(short *)(NewAnim + 0xc) < -0x3f) {
                ControlFlag = ControlFlag & 0xfffffbff;
              }
              else {
                ControlFlag = ControlFlag | 0x400;
              }
              if (Inst != (_Instance *)0x0) {
                    /* WARNING: Subroutine does not return */
                INSTANCE_Query(Inst,4);
              }
            }
            if (((*(ushort *)(NewAnim + 0x10) & 0x200) != 0) && (CurrentSection == 0)) {
                    /* WARNING: Read-only address (ram,0x800d5e04) is written */
              ExternalForces.Friction = 0x30;
            }
            if (((*(ushort *)(NewAnim + 0x10) & 0x40) != 0) && (0 < Raziel.iVelocity.z)) {
              StateHandlerInitSwim(In,CurrentSection,Data);
            }
            if ((*(ushort *)(NewAnim + 0x10) & 0x400) != 0) {
              if (CurrentSection == 0) {
                Raziel.Mode = 0x10;
                SetExternalForce(&__Force_800d5e1c,0,0,-0x10,1,0x1000);
                In->CharacterInstance->xVel = (int)Raziel.iVelocity.x;
                In->CharacterInstance->yVel = (int)Raziel.iVelocity.y;
                In->CharacterInstance->zVel = (int)Raziel.iVelocity.z;
                    /* WARNING: Read-only address (ram,0x800d5e04) is written */
                ExternalForces.Friction = 0x38;
              }
                    /* WARNING: Subroutine does not return */
              G2EmulationSwitchAnimation(In,CurrentSection,0x23,0,0,1);
            }
            if ((*(ushort *)(NewAnim + 0x10) & 0x20) != 0) {
              Raziel.Mode = 0x100000;
                    /* WARNING: Subroutine does not return */
              G2EmulationSwitchAnimation(In,CurrentSection,0x23,0,0,1);
            }
          }
          goto LAB_800a0144;
        }
        if (puVar2 == (undefined *)0x8000000) goto LAB_800a0144;
      }
      else {
        if (puVar2 == (undefined *)0x20000001) goto LAB_800a0144;
        if ((int)puVar2 < 0x20000002) {
          if (puVar2 == (undefined *)0x8000004) {
            if ((*PadData & 0x80) == 0) {
              razSetSwimVelocity(In->CharacterInstance,0,PlayerData->SwimPhysicsUnderDeceleration);
            }
            else {
              razSetSwimVelocity(In->CharacterInstance,PlayerData->SwimPhysicsUnderVelocity,
                                 PlayerData->SwimPhysicsUnderKickDecel);
            }
            goto LAB_800a0144;
          }
        }
        else {
          if (puVar2 == (undefined *)0x20000004) {
            Inst = In->CharacterInstance;
            adjustment = 0x1000;
            goto LAB_8009ff34;
          }
        }
      }
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
LAB_800a0144:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
}





