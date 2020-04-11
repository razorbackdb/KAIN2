
#include "SPIDER.H"


// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerWallGrab(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s4*/)
 // line 12, offset 0x800a0184
	/* begin block 1 */
		// Start line: 13
		// Start offset: 0x800A0184
		// Variables:
	// 		struct __Event *Ptr; // $a1

		/* begin block 1.1 */
			// Start line: 39
			// Start offset: 0x800A0318
			// Variables:
		// 		struct evPhysicsWallCrawlData *Data; // $a1
		/* end block 1.1 */
		// End offset: 0x800A0394
		// End Line: 78
	/* end block 1 */
	// End offset: 0x800A03AC
	// End Line: 91

	/* begin block 2 */
		// Start line: 24
	/* end block 2 */
	// End Line: 25

/* File: C:\kain2\game\RAZIEL\SPIDER.C */

void StateHandlerWallGrab(__CharacterState *In,int CurrentSection,int Data)

{
  undefined *puVar1;
  __Event *p_Var2;
  int Data_00;
  undefined *puVar3;
  __MessageQueue *In_00;
  
  In_00 = &In->SectionList[CurrentSection].Event;
  do {
    p_Var2 = PeekMessageQueue(In_00);
    if (p_Var2 == (__Event *)0x0) {
      return;
    }
    puVar3 = (undefined *)p_Var2->ID;
    if (puVar3 == &DAT_00100001) {
      if (CurrentSection == 0) {
        DAT_800d5aa4 = 0x4000000;
        SteerSwitchMode(In->CharacterInstance,7);
        ControlFlag = 0x80a1101;
        In->CharacterInstance->tface = (_TFace *)0x0;
        PhysicsMode = 3;
        ResetPhysics(In->CharacterInstance,-0x10);
        razReaverBladeOff();
      }
      G2EmulationSwitchAnimation(In,CurrentSection,0x4b,0,3,1);
      PurgeMessageQueue(In_00);
    }
    else {
      if ((int)puVar3 < 0x100002) {
        if (puVar3 != &DAT_80000008) {
          if ((int)puVar3 < -0x7ffffff7) {
            if (puVar3 != (undefined *)0x80000000) {
LAB_800a0394:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            puVar1 = &DAT_80000020;
joined_r0x800a0250:
            if (puVar3 != puVar1) goto LAB_800a0394;
          }
        }
      }
      else {
        if (puVar3 != (undefined *)0x1000001) {
          if ((int)puVar3 < 0x1000002) {
            puVar1 = &DAT_00100004;
            goto joined_r0x800a0250;
          }
          if (puVar3 == (undefined *)0x4010011) {
            if (((evPhysicsWallCrawlData *)p_Var2->Data)->rc == 0) {
              (In->CharacterInstance->rotation).x = 0;
              (In->CharacterInstance->rotation).y = 0;
              (In->CharacterInstance->rotation).z = 0;
              Data_00 = SetControlInitIdleData(0,0,3);
              StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
            }
            else {
              if (CurrentSection == 0) {
                razSetWallCrawlNodes(In->CharacterInstance,(evPhysicsWallCrawlData *)p_Var2->Data);
              }
            }
          }
          else {
            if (puVar3 != (undefined *)0x8000000) goto LAB_800a0394;
            StateSwitchStateData(In,CurrentSection,StateHandlerWallIdle,0);
          }
        }
      }
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerWallIdle(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s6*/)
 // line 93, offset 0x800a03cc
	/* begin block 1 */
		// Start line: 94
		// Start offset: 0x800A03CC
		// Variables:
	// 		int Anim; // $s3
	// 		struct __Event *Ptr; // $s0
	// 		struct SVECTOR startVec; // stack offset -48
	// 		struct SVECTOR endVec; // stack offset -40

		/* begin block 1.1 */
			// Start line: 135
			// Start offset: 0x800A061C
			// Variables:
		// 		struct evMonsterHitData *data; // $v1
		/* end block 1.1 */
		// End offset: 0x800A063C
		// End Line: 140

		/* begin block 1.2 */
			// Start line: 186
			// Start offset: 0x800A07C8
			// Variables:
		// 		struct evPhysicsWallCrawlData *Data; // $a1
		/* end block 1.2 */
		// End offset: 0x800A089C
		// End Line: 233

		/* begin block 1.3 */
			// Start line: 247
			// Start offset: 0x800A0918
			// Variables:
		// 		int rc; // $v1
		/* end block 1.3 */
		// End offset: 0x800A096C
		// End Line: 252

		/* begin block 1.4 */
			// Start line: 279
			// Start offset: 0x800A09EC
			// Variables:
		// 		int rc; // $v1
		/* end block 1.4 */
		// End offset: 0x800A0A40
		// End Line: 284

		/* begin block 1.5 */
			// Start line: 354
			// Start offset: 0x800A0ACC
			// Variables:
		// 		int rc; // $v1
		/* end block 1.5 */
		// End offset: 0x800A0C78
		// End Line: 401
	/* end block 1 */
	// End offset: 0x800A0C78
	// End Line: 414

	/* begin block 2 */
		// Start line: 203
	/* end block 2 */
	// End Line: 204

/* File: C:\kain2\game\RAZIEL\SPIDER.C */

void StateHandlerWallIdle(__CharacterState *In,int CurrentSection,int Data)

{
  _G2SVector3_Type *p_Var1;
  int Data_00;
  __Event *p_Var2;
  _Instance *instance;
  uint uVar3;
  undefined *puVar4;
  int Data_01;
  int NewAnim;
  int local_34;
  
  Data_00 = G2EmulationQueryAnimation(In,CurrentSection);
  if ((CurrentSection == 0) && (Data_00 == 0x68)) {
    In->CharacterInstance->tface = (_TFace *)0x0;
  }
  while (p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event), p_Var2 != (__Event *)0x0
        ) {
    puVar4 = (undefined *)p_Var2->ID;
    if (puVar4 == &DAT_00100004) {
      if (CurrentSection == 0) {
        COLLIDE_SegmentCollisionOn(In->CharacterInstance,1);
      }
    }
    else {
      if ((int)puVar4 < 0x100005) {
        if (puVar4 != &DAT_80000008) {
          if ((int)puVar4 < -0x7ffffff7) {
            if (puVar4 != (undefined *)0x80000000) {
              if (puVar4 != (undefined *)0x80000001) goto LAB_800a0a60;
LAB_800a0644:
              DAT_800d5aa4 = 8;
              ControlFlag = ControlFlag | 0x10;
              SetPhysics(In->CharacterInstance,-0x10,0,0x28,0x9a);
              G2EmulationSwitchAnimation(In,CurrentSection,0x23,0,0,1);
              StateSwitchStateData(In,CurrentSection,StateHandlerWallDismount,0);
              In->CharacterInstance->yVel = In->CharacterInstance->yVel * -2;
              In->CharacterInstance->zVel = 0;
              (In->CharacterInstance->rotation).x = 0;
              PhysicsMode = 0;
              (In->CharacterInstance->rotation).y = 0;
            }
          }
          else {
            if (puVar4 != (undefined *)0x0) {
              if ((int)puVar4 < 1) {
                if (puVar4 != &DAT_80000020) goto LAB_800a0a60;
              }
              else {
                if (puVar4 != &DAT_00100001) goto LAB_800a0a60;
                if (CurrentSection == 2) {
                  NewAnim = 0;
                  Data_01 = 2;
                  local_34 = CurrentSection;
                }
                else {
                  NewAnim = 0x4c;
                  local_34 = 2;
                  Data_01 = CurrentSection;
                }
                G2EmulationSwitchAnimation(In,Data_01,NewAnim,0,3,local_34);
                p_Var1 = ExtraRot;
                ExtraRot->x = 0;
                p_Var1->y = 0;
                p_Var1->z = 0;
                instance = In->CharacterInstance;
                instance->oldTFace = (_TFace *)0x0;
                instance->tface = (_TFace *)0x0;
                ControlFlag = ControlFlag & 0xf7ffefff;
                In->CharacterInstance->waterFace = (_TFace *)0x0;
                if (CurrentSection == 0) {
                  COLLIDE_SegmentCollisionOff(In->CharacterInstance,1);
                }
              }
            }
          }
        }
      }
      else {
        if (puVar4 == (undefined *)0x4010011) {
          uVar3 = ((evPhysicsWallCrawlData *)p_Var2->Data)->rc;
          if (uVar3 == 0) {
            (In->CharacterInstance->rotation).x = 0;
            (In->CharacterInstance->rotation).y = 0;
            (In->CharacterInstance->rotation).z = 0;
            Data_01 = SetControlInitIdleData(0,0,3);
            StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_01);
            razReaverBladeOn();
          }
          else {
            if (CurrentSection == 0) {
              if ((uVar3 & 4) == 0) {
                instance = In->CharacterInstance;
                if (instance->tface == instance->oldTFace) {
                  razSetWallCrawlNodes(instance,(evPhysicsWallCrawlData *)p_Var2->Data);
                }
              }
              else {
                SteerSwitchMode(In->CharacterInstance,0);
                Data_01 = SetControlInitHangData((_Instance *)0x0,0,3);
                StateSwitchStateCharacterData(In,StateHandlerHang,Data_01);
                razReaverBladeOn();
              }
            }
          }
        }
        else {
          if ((int)puVar4 < 0x4010012) {
            if (puVar4 != (undefined *)0x1000001) {
              if ((int)puVar4 < 0x1000002) {
                if (puVar4 == (undefined *)0x1000000) {
                  if ((CurrentSection == 0) && ((DAT_800d2190 & 0x800) != 0)) {
                    LoseHealth(*(int *)(p_Var2->Data + 0xc));
                  }
                  goto LAB_800a0644;
                }
              }
              else {
                if (puVar4 == (undefined *)0x4000004) goto LAB_800a0a68;
              }
LAB_800a0a60:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar4 == (undefined *)0x8000001) {
              if ((CurrentSection == 0) && (Data_00 == 0x68)) {
                PHYSICS_GenericLineCheckSetup(0,0,0x140,0xd0);
                PHYSICS_GenericLineCheckSetup(0,-0x140,0x140,0xd8);
                uVar3 = PHYSICS_CheckForValidMove(In->CharacterInstance,0xd0,0xd8,0);
                if ((uVar3 & 1) == 0) {
                  G2EmulationSwitchAnimationCharacter(In,0x6a,0,3,1);
                }
              }
            }
            else {
              if ((int)puVar4 < 0x8000002) {
                if (puVar4 != (undefined *)0x8000000) goto LAB_800a0a60;
                if (CurrentSection == 2) {
                  G2EmulationSwitchAnimation(In,2,0,0,3,2);
                  G2Anim_SetController_Vector
                            (&In->CharacterInstance->anim,0,0xe,(_G2SVector3_Type *)ExtraRot);
                }
                else {
                  G2EmulationSwitchAnimation(In,CurrentSection,0x4c,0,3,2);
                }
              }
              else {
                if (puVar4 != (undefined *)0x10000000) goto LAB_800a0a60;
                if (CurrentSection == 0) {
                  Data_00 = G2EmulationQueryAnimation(In,0);
                  Data_01 = p_Var2->Data;
                  if (Data_01 == 0x10000002) {
                    if ((Data_00 != 0x92) &&
                       (Data_01 = razSideMoveSpiderCheck(In->CharacterInstance,-0x80), Data_01 == 0)
                       ) {
                      Data_01 = 0x92;
                      local_34 = 1;
LAB_800a0a50:
                      G2EmulationSwitchAnimationCharacterAlpha(In,Data_01,0,3,local_34,2);
                    }
                  }
                  else {
                    if (Data_01 < 0x10000003) {
                      if ((Data_01 == 0x10000001) && (Data_00 != 0x68)) {
                        PHYSICS_GenericLineCheckSetup(0,0,0xa0,0xd0);
                        PHYSICS_GenericLineCheckSetup(0,-0x140,0xa0,0xd8);
                        uVar3 = PHYSICS_CheckForValidMove(In->CharacterInstance,0xd0,0xd8,0);
                        if (((uVar3 & 1) != 0) || (uVar3 == 0)) {
                          Data_01 = 0x68;
LAB_800a0a44:
                          local_34 = 2;
                          goto LAB_800a0a50;
                        }
                      }
                    }
                    else {
                      if (Data_01 == 0x10000003) {
                        if (Data_00 != 0x95) {
                          PHYSICS_GenericLineCheckSetup(0,0,-0x140,0xd0);
                          PHYSICS_GenericLineCheckSetup(0,-0x140,-0x140,0xd8);
                          uVar3 = PHYSICS_CheckForValidMove(In->CharacterInstance,0xd0,0xd8,0);
                          if (((uVar3 & 1) != 0) || (uVar3 == 0)) {
                            Data_01 = 0x95;
                            goto LAB_800a0a44;
                          }
                        }
                      }
                      else {
                        if (((Data_01 == 0x10000004) && (Data_00 != 0x91)) &&
                           (Data_01 = razSideMoveSpiderCheck(In->CharacterInstance,0x80),
                           Data_01 == 0)) {
                          Data_01 = 0x91;
                          local_34 = 1;
                          goto LAB_800a0a50;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_800a0a68:
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  }
  if (((*PadData & 0x8000000fU) == 0) && ((DAT_800d5c4c & 1) != 0)) {
    G2EmulationSwitchAnimationCharacter(In,0x6a,0,3,1);
    DAT_800d5c4c = 0;
  }
  if (CurrentSection != 0) {
    return;
  }
  if (Data_00 == 0x91) {
    uVar3 = razSideMoveSpiderCheck(In->CharacterInstance,0x80);
  }
  else {
    if (Data_00 < 0x92) {
      if (Data_00 != 0x68) {
        return;
      }
      PHYSICS_GenericLineCheckSetup(0,0,0xa0,0xd0);
      PHYSICS_GenericLineCheckSetup(0,-0x140,0xa0,0xd8);
      uVar3 = PHYSICS_CheckForValidMove(In->CharacterInstance,0xd0,0xd8,0);
      if ((uVar3 & 1) != 0) {
        return;
      }
    }
    else {
      if (Data_00 != 0x92) {
        if (Data_00 != 0x95) {
          return;
        }
        PHYSICS_GenericLineCheckSetup(0,0,0,0xd0);
        PHYSICS_GenericLineCheckSetup(0,0,-0x140,0xd8);
        Data_00 = PHYSICS_CheckForValidMove(In->CharacterInstance,0xd0,0xd8,0);
        if ((Data_00 != 0) || (In->CharacterInstance->waterFace != (_TFace *)0x0)) {
          Data_00 = SetControlInitIdleData(0,0,3);
          StateSwitchStateCharacterData(In,StateHandlerIdle,Data_00);
          return;
        }
        PHYSICS_GenericLineCheckSetup(0,0,-0x140,0xd0);
        PHYSICS_GenericLineCheckSetup(0,-0x140,-0x140,0xd8);
        uVar3 = PHYSICS_CheckForValidMove(In->CharacterInstance,0xd0,0xd8,0);
        if ((uVar3 & 1) != 0) {
          return;
        }
        goto LAB_800a0c64;
      }
      uVar3 = razSideMoveSpiderCheck(In->CharacterInstance,-0x80);
    }
  }
  if (uVar3 == 0) {
    return;
  }
LAB_800a0c64:
  G2EmulationSwitchAnimationCharacter(In,0x6a,0,3,1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerWallDismount(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s5*/)
 // line 417, offset 0x800a0ca0
	/* begin block 1 */
		// Start line: 418
		// Start offset: 0x800A0CA0
		// Variables:
	// 		struct __Event *Ptr; // $v0
	// 		int Frame; // $s4
	/* end block 1 */
	// End offset: 0x800A0EDC
	// End Line: 498

	/* begin block 2 */
		// Start line: 870
	/* end block 2 */
	// End Line: 871

/* File: C:\kain2\game\RAZIEL\SPIDER.C */

void StateHandlerWallDismount(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  undefined *puVar2;
  __State *p_Var3;
  
  p_Var3 = In->SectionList + CurrentSection;
  do {
    p_Var1 = PeekMessageQueue(&p_Var3->Event);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == &DAT_00100004) {
LAB_800a0e58:
      razReaverBladeOn();
    }
    else {
      if ((int)puVar2 < 0x100005) {
        if (puVar2 != &DAT_80000008) {
          if ((int)puVar2 < -0x7ffffff7) {
            if (puVar2 != (undefined *)0x80000000) {
              if (puVar2 != (undefined *)0x80000001) goto LAB_800a0ec4;
              EnMessageQueueData(&p_Var3->Defer,-0x7fffffff,0);
            }
          }
          else {
            if (puVar2 != &DAT_80000020) {
              if (puVar2 == &DAT_00100001) {
                if (CurrentSection == 0) {
                  ControlFlag = 8;
                  PhysicsMode = 0;
                  G2Anim_InterpDisableController(&In->CharacterInstance->anim,1,0x26,300);
                  G2Anim_InterpDisableController(&In->CharacterInstance->anim,0,0xe,300);
                  G2Anim_InterpDisableController(&In->CharacterInstance->anim,0,8,300);
                  G2Anim_InterpDisableController(&In->CharacterInstance->anim,0xe,0xe,300);
                  G2Anim_InterpDisableController(&In->CharacterInstance->anim,0x32,0x4c,300);
                  G2Anim_InterpDisableController(&In->CharacterInstance->anim,0x3a,0x4c,300);
                }
                goto LAB_800a0e58;
              }
LAB_800a0ec4:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
        }
      }
      else {
        if (puVar2 != (undefined *)0x4010008) {
          if ((int)puVar2 < 0x4010009) {
            if ((puVar2 != (undefined *)0x1000001) && (puVar2 != (undefined *)0x4000001))
            goto LAB_800a0ec4;
          }
          else {
            if (puVar2 != (undefined *)0x4020000) {
              if (puVar2 != (undefined *)0x8000000) goto LAB_800a0ec4;
              G2EmulationSwitchAnimation(In,CurrentSection,0x24,0,4,1);
              StateSwitchStateData(In,CurrentSection,StateHandlerFall,0);
            }
          }
        }
      }
    }
    DeMessageQueue(&p_Var3->Event);
  } while( true );
}





