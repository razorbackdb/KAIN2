#include "THISDUST.H"
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

void StateHandlerWallGrab(__CharacterState *In,int CurrentSection,int Data)

{
  undefined *puVar1;
  __Event *p_Var2;
  undefined *puVar3;
  
  p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var2 == (__Event *)0x0) {
    return;
  }
  puVar3 = (undefined *)p_Var2->ID;
  if (puVar3 == &DAT_00100001) {
    if (CurrentSection == 0) {
      Raziel.Mode = 0x4000000;
                    /* WARNING: Subroutine does not return */
      SteerSwitchMode(In->CharacterInstance,7);
    }
                    /* WARNING: Subroutine does not return */
    G2EmulationSwitchAnimation(In,CurrentSection,0x4b,0,3,1);
  }
  if ((int)puVar3 < 0x100002) {
    if (puVar3 == &DAT_80000008) goto LAB_800a039c;
    if ((int)puVar3 < -0x7ffffff7) {
      if (puVar3 == (undefined *)0x80000000) goto LAB_800a039c;
    }
    else {
      puVar1 = &DAT_80000020;
joined_r0x800a0250:
      if (puVar3 == puVar1) goto LAB_800a039c;
    }
  }
  else {
    if (puVar3 == (undefined *)0x1000001) goto LAB_800a039c;
    if ((int)puVar3 < 0x1000002) {
      puVar1 = &DAT_00100004;
      goto joined_r0x800a0250;
    }
    if (puVar3 == (undefined *)0x4010011) {
      if (((evPhysicsWallCrawlData *)p_Var2->Data)->rc == 0) {
        (In->CharacterInstance->rotation).x = 0;
        (In->CharacterInstance->rotation).y = 0;
                    /* WARNING: Subroutine does not return */
        (In->CharacterInstance->rotation).z = 0;
        SetControlInitIdleData(0,0,3);
      }
      if (CurrentSection == 0) {
        razSetWallCrawlNodes(In->CharacterInstance,(evPhysicsWallCrawlData *)p_Var2->Data);
      }
      goto LAB_800a039c;
    }
    if (puVar3 == (undefined *)0x8000000) {
                    /* WARNING: Subroutine does not return */
      StateSwitchStateData(In,CurrentSection,StateHandlerWallIdle,0);
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
LAB_800a039c:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&In->SectionList[CurrentSection].Event);
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

void StateHandlerWallIdle(__CharacterState *In,int CurrentSection,int Data)

{
  int NewAnim;
  __Event *p_Var1;
  uint uVar2;
  undefined *puVar3;
  _Instance *instance;
  int NewAnim_00;
  int local_34;
  SVECTOR aSStack48 [2];
  
  NewAnim = G2EmulationQueryAnimation(In,CurrentSection);
  if ((CurrentSection == 0) && (NewAnim == 0x68)) {
    In->CharacterInstance->tface = (_TFace *)0x0;
  }
  p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var1 == (__Event *)0x0) {
    if (((*PadData & 0x8000000fU) == 0) && ((Raziel.passedMask & 1) != 0)) {
                    /* WARNING: Subroutine does not return */
      G2EmulationSwitchAnimationCharacter(In,0x6a,0,3,1);
    }
    if (CurrentSection != 0) {
      return;
    }
    if (NewAnim == 0x91) {
      NewAnim = razSideMoveSpiderCheck(In->CharacterInstance,0x80);
    }
    else {
      if (NewAnim < 0x92) {
        if (NewAnim != 0x68) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        PHYSICS_GenericLineCheckSetup(0,0,0xa0,aSStack48);
      }
      if (NewAnim != 0x92) {
        if (NewAnim != 0x95) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        PHYSICS_GenericLineCheckSetup(0,0,0,aSStack48);
      }
      NewAnim = razSideMoveSpiderCheck(In->CharacterInstance,-0x80);
    }
    if (NewAnim == 0) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    G2EmulationSwitchAnimationCharacter(In,0x6a,0,3,1);
  }
  puVar3 = (undefined *)p_Var1->ID;
  if (puVar3 == &DAT_00100004) {
    if (CurrentSection == 0) {
      COLLIDE_SegmentCollisionOn(In->CharacterInstance,1);
    }
    goto LAB_800a0a68;
  }
  if ((int)puVar3 < 0x100005) {
    if (puVar3 == &DAT_80000008) goto LAB_800a0a68;
    if ((int)puVar3 < -0x7ffffff7) {
      if (puVar3 == (undefined *)0x80000000) goto LAB_800a0a68;
      if (puVar3 == (undefined *)0x80000001) {
LAB_800a0644:
        Raziel.Mode = 8;
        ControlFlag = ControlFlag | 0x10;
        SetPhysics(In->CharacterInstance,-0x10,0,0x28,0x9a);
                    /* WARNING: Subroutine does not return */
        G2EmulationSwitchAnimation(In,CurrentSection,0x23,0,0,1);
      }
    }
    else {
      if (puVar3 == (undefined *)0x0) goto LAB_800a0a68;
      if ((int)puVar3 < 1) {
        if (puVar3 == &DAT_80000020) goto LAB_800a0a68;
      }
      else {
        if (puVar3 == &DAT_00100001) {
          if (CurrentSection == 2) {
            NewAnim_00 = 0;
            NewAnim = 2;
            local_34 = CurrentSection;
          }
          else {
            NewAnim_00 = 0x4c;
            local_34 = 2;
            NewAnim = CurrentSection;
          }
                    /* WARNING: Subroutine does not return */
          G2EmulationSwitchAnimation(In,NewAnim,NewAnim_00,0,3,local_34);
        }
      }
    }
  }
  else {
    if (puVar3 == (undefined *)0x4010011) {
      uVar2 = ((evPhysicsWallCrawlData *)p_Var1->Data)->rc;
      if (uVar2 == 0) {
        (In->CharacterInstance->rotation).x = 0;
        (In->CharacterInstance->rotation).y = 0;
                    /* WARNING: Subroutine does not return */
        (In->CharacterInstance->rotation).z = 0;
        SetControlInitIdleData(0,0,3);
      }
      if (CurrentSection == 0) {
        if ((uVar2 & 4) != 0) {
                    /* WARNING: Subroutine does not return */
          SteerSwitchMode(In->CharacterInstance,0);
        }
        instance = In->CharacterInstance;
        if (instance->tface == instance->oldTFace) {
          razSetWallCrawlNodes(instance,(evPhysicsWallCrawlData *)p_Var1->Data);
        }
      }
      goto LAB_800a0a68;
    }
    if ((int)puVar3 < 0x4010012) {
      if (puVar3 == (undefined *)0x1000001) goto LAB_800a0a68;
      if ((int)puVar3 < 0x1000002) {
        if (puVar3 == (undefined *)0x1000000) {
          if ((CurrentSection == 0) && ((gameTrackerX.debugFlags2 & 0x800U) != 0)) {
            LoseHealth(*(int *)(p_Var1->Data + 0xc));
          }
          goto LAB_800a0644;
        }
      }
      else {
        if (puVar3 == (undefined *)0x4000004) goto LAB_800a0a68;
      }
    }
    else {
      if (puVar3 == (undefined *)0x8000001) {
        if ((CurrentSection == 0) && (NewAnim == 0x68)) {
                    /* WARNING: Subroutine does not return */
          PHYSICS_GenericLineCheckSetup(0,0,0x140,aSStack48);
        }
        goto LAB_800a0a68;
      }
      if ((int)puVar3 < 0x8000002) {
        if (puVar3 == (undefined *)0x8000000) {
          if (CurrentSection != 2) {
                    /* WARNING: Subroutine does not return */
            G2EmulationSwitchAnimation(In,CurrentSection,0x4c,0,3,2);
          }
                    /* WARNING: Subroutine does not return */
          G2EmulationSwitchAnimation(In,2,0,0,3,2);
        }
      }
      else {
        if (puVar3 == (undefined *)0x10000000) {
          if (CurrentSection != 0) goto LAB_800a0a68;
          NewAnim = G2EmulationQueryAnimation(In,0);
          local_34 = p_Var1->Data;
          if (local_34 == 0x10000002) {
            if ((NewAnim == 0x92) ||
               (NewAnim = razSideMoveSpiderCheck(In->CharacterInstance,-0x80), NewAnim != 0))
            goto LAB_800a0a68;
            NewAnim = 0x92;
          }
          else {
            if (local_34 < 0x10000003) {
              if ((local_34 == 0x10000001) && (NewAnim != 0x68)) {
                    /* WARNING: Subroutine does not return */
                PHYSICS_GenericLineCheckSetup(0,0,0xa0,aSStack48);
              }
              goto LAB_800a0a68;
            }
            if (local_34 == 0x10000003) {
              if (NewAnim != 0x95) {
                    /* WARNING: Subroutine does not return */
                PHYSICS_GenericLineCheckSetup(0,0,-0x140,aSStack48);
              }
              goto LAB_800a0a68;
            }
            if (((local_34 != 0x10000004) || (NewAnim == 0x91)) ||
               (NewAnim = razSideMoveSpiderCheck(In->CharacterInstance,0x80), NewAnim != 0))
            goto LAB_800a0a68;
            NewAnim = 0x91;
          }
          G2EmulationSwitchAnimationCharacterAlpha(In,NewAnim,0,3,1,2);
          goto LAB_800a0a68;
        }
      }
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
LAB_800a0a68:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&In->SectionList[CurrentSection].Event);
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

void StateHandlerWallDismount(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  undefined *puVar2;
  __State *p_Var3;
  
  p_Var3 = In->SectionList + CurrentSection;
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
      if (puVar2 == &DAT_80000008) goto LAB_800a0ecc;
      if ((int)puVar2 < -0x7ffffff7) {
        if (puVar2 == (undefined *)0x80000000) goto LAB_800a0ecc;
        if (puVar2 == (undefined *)0x80000001) {
                    /* WARNING: Subroutine does not return */
          EnMessageQueueData(&p_Var3->Defer,-0x7fffffff,0);
        }
      }
      else {
        if (puVar2 == &DAT_80000020) goto LAB_800a0ecc;
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
      }
    }
    else {
      if (puVar2 == (undefined *)0x4010008) goto LAB_800a0ecc;
      if ((int)puVar2 < 0x4010009) {
        if ((puVar2 == (undefined *)0x1000001) || (puVar2 == (undefined *)0x4000001))
        goto LAB_800a0ecc;
      }
      else {
        if (puVar2 == (undefined *)0x4020000) goto LAB_800a0ecc;
        if (puVar2 == (undefined *)0x8000000) {
                    /* WARNING: Subroutine does not return */
          G2EmulationSwitchAnimation(In,CurrentSection,0x24,0,4,1);
        }
      }
    }
    DefaultStateHandler(In,CurrentSection,Data);
  }
LAB_800a0ecc:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&p_Var3->Event);
}





