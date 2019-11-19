#include "THISDUST.H"
#include "SPIDER.H"


// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerWallGrab(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s4*/)
 // line 12, offset 0x8009dbdc
	/* begin block 1 */
		// Start line: 13
		// Start offset: 0x8009DBDC
		// Variables:
	// 		struct __Event *Ptr; // $a1

		/* begin block 1.1 */
			// Start line: 38
			// Start offset: 0x8009DD5C
			// Variables:
		// 		struct evPhysicsWallCrawlData *Data; // $a1
		/* end block 1.1 */
		// End offset: 0x8009DDD8
		// End Line: 77
	/* end block 1 */
	// End offset: 0x8009DDF0
	// End Line: 89

	/* begin block 2 */
		// Start line: 24
	/* end block 2 */
	// End Line: 25

void StateHandlerWallGrab(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int Data_00;
  undefined *puVar2;
  __MessageQueue *In_00;
  
  In_00 = &In->SectionList[CurrentSection].Event;
  do {
    p_Var1 = PeekMessageQueue(In_00);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    puVar2 = (undefined *)p_Var1->ID;
    if (puVar2 == (undefined *)0x100001) {
      if (CurrentSection == 0) {
        Raziel.Mode = 0x4000000;
        SteerSwitchMode(In->CharacterInstance,7);
        ControlFlag = 0x80a1101;
        In->CharacterInstance->tface = (_TFace *)0x0;
        PhysicsMode = 3;
        ResetPhysics(In->CharacterInstance,-0x10);
      }
      G2EmulationSwitchAnimation(In,CurrentSection,0x4b,0,3,1);
      PurgeMessageQueue(In_00);
    }
    else {
      if ((int)puVar2 < 0x100002) {
        if (puVar2 != &DAT_80000008) {
          if ((int)puVar2 < -0x7ffffff7) {
            if (puVar2 != (undefined *)0x80000000) {
LAB_8009ddd8:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar2 != &DAT_80000020) goto LAB_8009ddd8;
          }
        }
      }
      else {
        if (puVar2 == (undefined *)0x4010011) {
          if (((evPhysicsWallCrawlData *)p_Var1->Data)->rc == 0) {
            (In->CharacterInstance->rotation).x = 0;
            (In->CharacterInstance->rotation).y = 0;
            (In->CharacterInstance->rotation).z = 0;
            Data_00 = SetControlInitIdleData(0,0,3);
            StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
          }
          else {
            if (CurrentSection == 0) {
              razSetWallCrawlNodes(In->CharacterInstance,(evPhysicsWallCrawlData *)p_Var1->Data);
            }
          }
        }
        else {
          if ((int)puVar2 < 0x4010012) {
            if (puVar2 != (undefined *)0x100004) goto LAB_8009ddd8;
          }
          else {
            if (puVar2 != (undefined *)0x8000000) goto LAB_8009ddd8;
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
 // line 91, offset 0x8009de10
	/* begin block 1 */
		// Start line: 92
		// Start offset: 0x8009DE10
		// Variables:
	// 		int Anim; // $s3
	// 		struct __Event *Ptr; // $s0
	// 		struct SVECTOR startVec; // stack offset -48
	// 		struct SVECTOR endVec; // stack offset -40

		/* begin block 1.1 */
			// Start line: 170
			// Start offset: 0x8009E19C
			// Variables:
		// 		struct evPhysicsWallCrawlData *Data; // $a1
		/* end block 1.1 */
		// End offset: 0x8009E244
		// End Line: 215

		/* begin block 1.2 */
			// Start line: 229
			// Start offset: 0x8009E2C4
			// Variables:
		// 		int rc; // $v1
		/* end block 1.2 */
		// End offset: 0x8009E318
		// End Line: 234

		/* begin block 1.3 */
			// Start line: 331
			// Start offset: 0x8009E424
			// Variables:
		// 		int rc; // $v1
		/* end block 1.3 */
		// End offset: 0x8009E57C
		// End Line: 370
	/* end block 1 */
	// End offset: 0x8009E57C
	// End Line: 383

	/* begin block 2 */
		// Start line: 199
	/* end block 2 */
	// End Line: 200

void StateHandlerWallIdle(__CharacterState *In,int CurrentSection,int Data)

{
  _G2SVector3_Type *p_Var1;
  int x;
  __Event *p_Var2;
  _Instance *instance;
  uint uVar3;
  undefined *puVar4;
  int Data_00;
  int NewAnim;
  int local_34;
  SVECTOR SStack48;
  SVECTOR SStack40;
  
  x = G2EmulationQueryAnimation(In,CurrentSection);
  if ((CurrentSection == 0) && (x == 0x69)) {
    In->CharacterInstance->tface = (_TFace *)0x0;
  }
  while (p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event), p_Var2 != (__Event *)0x0
        ) {
    puVar4 = (undefined *)p_Var2->ID;
    if (puVar4 != (undefined *)0x100004) {
      if ((int)puVar4 < 0x100005) {
        if (puVar4 != &DAT_80000008) {
          if ((int)puVar4 < -0x7ffffff7) {
            if (puVar4 != (undefined *)0x80000000) {
              if (puVar4 == (undefined *)0x80000001) goto LAB_8009e010;
              goto LAB_8009e3b8;
            }
          }
          else {
            if (puVar4 != (undefined *)0x0) {
              if ((int)puVar4 < 1) {
                if (puVar4 != &DAT_80000020) {
LAB_8009e3b8:
                  DefaultStateHandler(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar4 != (undefined *)0x100001) goto LAB_8009e3b8;
                if (CurrentSection == 2) {
                  NewAnim = 0;
                  Data_00 = 2;
                  local_34 = CurrentSection;
                }
                else {
                  NewAnim = 0x4c;
                  local_34 = 2;
                  Data_00 = CurrentSection;
                }
                G2EmulationSwitchAnimation(In,Data_00,NewAnim,0,3,local_34);
                p_Var1 = ExtraRot;
                ExtraRot->x = 0;
                p_Var1->y = 0;
                p_Var1->z = 0;
                instance = In->CharacterInstance;
                instance->oldTFace = (_TFace *)0x0;
                instance->tface = (_TFace *)0x0;
                ControlFlag = ControlFlag & 0xf7ffefff;
                In->CharacterInstance->waterFace = (_TFace *)0x0;
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
            Data_00 = SetControlInitIdleData(0,0,3);
            StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
          }
          else {
            if (CurrentSection == 0) {
              if ((uVar3 & 4) == 0) {
                razSetWallCrawlNodes(In->CharacterInstance,(evPhysicsWallCrawlData *)p_Var2->Data);
              }
              else {
                SteerSwitchMode(In->CharacterInstance,0);
                Data_00 = SetControlInitHangData((_Instance *)0x0,0,3);
                StateSwitchStateCharacterData(In,StateHandlerHang,Data_00);
              }
            }
          }
        }
        else {
          if ((int)puVar4 < 0x4010012) {
            if (puVar4 == (undefined *)0x100014) {
LAB_8009e010:
              Raziel.Mode = 8;
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
            else {
              if (puVar4 != (undefined *)0x4000004) goto LAB_8009e3b8;
            }
          }
          else {
            if (puVar4 == (undefined *)0x8000001) {
              if ((CurrentSection == 0) && (x == 0x69)) {
                PHYSICS_GenericLineCheckSetup(0,0,0x140,&SStack48);
                PHYSICS_GenericLineCheckSetup(0,-0x140,0x140,&SStack40);
                uVar3 = PHYSICS_CheckForValidMove(In->CharacterInstance,&SStack48,&SStack40,0);
                if ((uVar3 & 1) == 0) {
                  G2EmulationSwitchAnimationCharacter(In,0x6b,0,3,1);
                }
              }
            }
            else {
              if ((int)puVar4 < 0x8000002) {
                if (puVar4 != (undefined *)0x8000000) goto LAB_8009e3b8;
                if (CurrentSection == 2) {
                  G2EmulationSwitchAnimation(In,2,0,0,3,2);
                  G2Anim_SetController_Vector(&In->CharacterInstance->anim,0,0xe,ExtraRot);
                }
                else {
                  G2EmulationSwitchAnimation(In,CurrentSection,0x4c,0,3,2);
                }
              }
              else {
                if (puVar4 != (undefined *)0x10000000) goto LAB_8009e3b8;
                if (CurrentSection == 0) {
                  x = G2EmulationQueryAnimation(In,0);
                  Data_00 = p_Var2->Data;
                  if (Data_00 == 0x10000002) {
                    if ((x != 0x93) &&
                       (Data_00 = razSideMoveSpiderCheck(In->CharacterInstance,-0x80), Data_00 == 0)
                       ) {
                      Data_00 = 0x93;
                      local_34 = 1;
LAB_8009e3a8:
                      G2EmulationSwitchAnimationCharacterAlpha(In,Data_00,0,3,local_34,2);
                    }
                  }
                  else {
                    if (Data_00 < 0x10000003) {
                      if ((Data_00 == 0x10000001) && (x != 0x69)) {
                        PHYSICS_GenericLineCheckSetup(0,0,0xa0,&SStack48);
                        PHYSICS_GenericLineCheckSetup(0,-0x140,0xa0,&SStack40);
                        uVar3 = PHYSICS_CheckForValidMove
                                          (In->CharacterInstance,&SStack48,&SStack40,0);
                        if (((uVar3 & 1) != 0) || (uVar3 == 0)) {
                          Data_00 = 0x69;
LAB_8009e39c:
                          local_34 = 2;
                          goto LAB_8009e3a8;
                        }
                      }
                    }
                    else {
                      if (Data_00 == 0x10000003) {
                        if (x != 0x96) {
                          Data_00 = 0x96;
                          goto LAB_8009e39c;
                        }
                      }
                      else {
                        if (((Data_00 == 0x10000004) && (x != 0x92)) &&
                           (Data_00 = razSideMoveSpiderCheck(In->CharacterInstance,0x80),
                           Data_00 == 0)) {
                          Data_00 = 0x92;
                          local_34 = 1;
                          goto LAB_8009e3a8;
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
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  }
  if (((*PadData & 0x8000000fU) == 0) && ((Raziel.throwReturnRot & 1U) != 0)) {
    G2EmulationSwitchAnimationCharacter(In,0x6b,0,3,1);
    Raziel.throwReturnRot = 0;
  }
  if (CurrentSection != 0) {
    return;
  }
  if (x == 0x92) {
    instance = In->CharacterInstance;
    x = 0x80;
  }
  else {
    if (x < 0x93) {
      if (x != 0x69) {
        return;
      }
      PHYSICS_GenericLineCheckSetup(0,0,0xa0,&SStack48);
      PHYSICS_GenericLineCheckSetup(0,-0x140,0xa0,&SStack40);
      uVar3 = PHYSICS_CheckForValidMove(In->CharacterInstance,&SStack48,&SStack40,0);
      if ((uVar3 & 1) != 0) {
        return;
      }
      goto joined_r0x8009e4d8;
    }
    if (x != 0x93) {
      if (x != 0x96) {
        return;
      }
      PHYSICS_GenericLineCheckSetup(0,0,0,&SStack48);
      PHYSICS_GenericLineCheckSetup(0,0,-0x140,&SStack40);
      x = PHYSICS_CheckForValidMove(In->CharacterInstance,&SStack48,&SStack40,0);
      if ((x == 0) && (In->CharacterInstance->waterFace == (_TFace *)0x0)) {
        return;
      }
      x = SetControlInitIdleData(0,0,3);
      StateSwitchStateCharacterData(In,StateHandlerIdle,x);
      return;
    }
    instance = In->CharacterInstance;
    x = -0x80;
  }
  uVar3 = razSideMoveSpiderCheck(instance,x);
joined_r0x8009e4d8:
  if (uVar3 != 0) {
    G2EmulationSwitchAnimationCharacter(In,0x6b,0,3,1);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerWallDismount(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s5*/)
 // line 386, offset 0x8009e5a4
	/* begin block 1 */
		// Start line: 387
		// Start offset: 0x8009E5A4
		// Variables:
	// 		struct __Event *Ptr; // $v0
	// 		int Frame; // $s4
	/* end block 1 */
	// End offset: 0x8009E7B4
	// End Line: 463

	/* begin block 2 */
		// Start line: 807
	/* end block 2 */
	// End Line: 808

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
    if (puVar2 == (undefined *)0x100001) {
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
    }
    else {
      if ((int)puVar2 < 0x100002) {
        if (puVar2 == (undefined *)0x80000001) {
          EnMessageQueueData(&p_Var3->Defer,-0x7fffffff,0);
        }
        else {
          if (((-0x80000000 < (int)puVar2) && (puVar2 != &DAT_80000008)) &&
             (puVar2 != &DAT_80000020)) goto LAB_8009e79c;
        }
      }
      else {
        if (puVar2 != (undefined *)0x4010008) {
          if ((int)puVar2 < 0x4010009) {
            if (puVar2 != (undefined *)0x4000001) {
LAB_8009e79c:
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
          else {
            if (puVar2 != (undefined *)0x4020000) {
              if (puVar2 != (undefined *)0x8000000) goto LAB_8009e79c;
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





