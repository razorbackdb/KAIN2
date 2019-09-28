#include "THISDUST.H"
#include "SPIDER.H"


// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerWallGrab(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s4*/)
 // line 12, offset 0x800a0e58
	/* begin block 1 */
		// Start line: 13
		// Start offset: 0x800A0E58
		// Variables:
	// 		struct __Event *Ptr; // $a1

		/* begin block 1.1 */
			// Start line: 41
			// Start offset: 0x800A1000
			// Variables:
		// 		struct evPhysicsWallCrawlData *Data; // $a1
		/* end block 1.1 */
		// End offset: 0x800A1090
		// End Line: 81
	/* end block 1 */
	// End offset: 0x800A10A8
	// End Line: 94

	/* begin block 2 */
		// Start line: 24
	/* end block 2 */
	// End Line: 25

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerWallGrab(__CharacterState *In,int CurrentSection,int Data)

{
  undefined *puVar1;
  __Event *p_Var2;
  undefined *puVar3;
  int in_a3;
  
  p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var2 == (__Event *)0x0) {
    return;
  }
  puVar3 = (undefined *)p_Var2->ID;
  if (puVar3 == &DAT_00100001) {
    if (CurrentSection == 0) {
      _CHAR____800d5574 = 0x4000000;
      SteerSwitchMode(In->CharacterInstance,7);
      _BlockVramEntry_800d59a0._12_4_ = 0x80a1101;
      In->CharacterInstance->tface = (_TFace *)0x0;
      PhysicsMode.next = (_BlockVramEntry *)&UNK_00000003;
      ResetPhysics(In->CharacterInstance,-0x10);
      razReaverBladeOff();
    }
                    /* WARNING: Subroutine does not return */
    G2EmulationSwitchAnimation(In,CurrentSection,0x4b,0,3,1);
  }
  if ((int)puVar3 < 0x100002) {
    if (puVar3 == &DAT_80000008) goto DeInitAlgorithmicWings;
    if ((int)puVar3 < -0x7ffffff7) {
      if (puVar3 == (undefined *)0x80000000) goto DeInitAlgorithmicWings;
    }
    else {
      puVar1 = &DAT_80000020;
joined_r0x800a0f24:
      if (puVar3 == puVar1) goto DeInitAlgorithmicWings;
    }
  }
  else {
    if (puVar3 == (undefined *)0x1000001) goto DeInitAlgorithmicWings;
    if ((int)puVar3 < 0x1000002) {
      puVar1 = &DAT_00100004;
      goto joined_r0x800a0f24;
    }
    if (puVar3 == (undefined *)0x4010011) {
      if (((evPhysicsWallCrawlData *)p_Var2->Data)->rc == 0) {
        (In->CharacterInstance->rotation).x = 0;
        (In->CharacterInstance->rotation).y = 0;
                    /* WARNING: Subroutine does not return */
        (In->CharacterInstance->rotation).z = 0;
        SetPhysicsWallCrawlData(0,0,3,in_a3);
      }
      if (CurrentSection == 0) {
        razSetWallCrawlNodes(In->CharacterInstance,(evPhysicsWallCrawlData *)p_Var2->Data);
      }
      goto DeInitAlgorithmicWings;
    }
    if (puVar3 == (undefined *)0x8000000) {
      if (CurrentSection == 0) {
        StateSwitchStateCharacterData(In,StateHandlerWallIdle,0);
      }
      goto DeInitAlgorithmicWings;
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
DeInitAlgorithmicWings:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&In->SectionList[CurrentSection].Event);
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerWallIdle(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s7*/)
 // line 96, offset 0x800a10c8
	/* begin block 1 */
		// Start line: 97
		// Start offset: 0x800A10C8
		// Variables:
	// 		int Anim; // $s3
	// 		struct __Event *Ptr; // $s0
	// 		struct SVECTOR startVec; // stack offset -56
	// 		struct SVECTOR endVec; // stack offset -48
	// 		int extraProcess; // $s6

		/* begin block 1.1 */
			// Start line: 140
			// Start offset: 0x800A12FC
			// Variables:
		// 		struct evMonsterHitData *data; // $v1
		/* end block 1.1 */
		// End offset: 0x800A131C
		// End Line: 145

		/* begin block 1.2 */
			// Start line: 191
			// Start offset: 0x800A14A8
			// Variables:
		// 		struct evPhysicsWallCrawlData *Data; // $a1
		/* end block 1.2 */
		// End offset: 0x800A1574
		// End Line: 239

		/* begin block 1.3 */
			// Start line: 253
			// Start offset: 0x800A15F4
			// Variables:
		// 		int rc; // $v1
		/* end block 1.3 */
		// End offset: 0x800A1648
		// End Line: 259

		/* begin block 1.4 */
			// Start line: 288
			// Start offset: 0x800A16B4
			// Variables:
		// 		int rc; // $v1
		/* end block 1.4 */
		// End offset: 0x800A1708
		// End Line: 294

		/* begin block 1.5 */
			// Start line: 371
			// Start offset: 0x800A17E8
			// Variables:
		// 		int rc; // $v1
		/* end block 1.5 */
		// End offset: 0x800A1984
		// End Line: 416
	/* end block 1 */
	// End offset: 0x800A1984
	// End Line: 420

	/* begin block 2 */
		// Start line: 209
	/* end block 2 */
	// End Line: 210

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerWallIdle(__CharacterState *In,int CurrentSection,int Data)

{
  int Data_00;
  __Event *p_Var1;
  uint uVar2;
  undefined *puVar3;
  _Instance *instance;
  int NewAnim;
  int in_a3;
  int local_3c;
  SVECTOR aSStack56 [2];
  
  Data_00 = G2EmulationQueryAnimation(In,CurrentSection);
  p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var1 == (__Event *)0x0) {
    if (((*gameTracker._4_4_ & 0x8000000f) == 0) && ((_CHAR____800d5720 & 1) != 0)) {
      G2EmulationSwitchAnimationCharacter(In,0x6a,0,3,1);
      _CHAR____800d5720 = 0;
    }
    if (CurrentSection != 0) {
      return;
    }
    if (Data_00 == 0x91) {
      Data_00 = razSideMoveSpiderCheck(In->CharacterInstance,0x80);
    }
    else {
      if (Data_00 < 0x92) {
        if (Data_00 != 0x68) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        PHYSICS_GenericLineCheckSetup(0,0,0xa0,aSStack56);
      }
      if (Data_00 != 0x92) {
        if (Data_00 != 0x95) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        PHYSICS_GenericLineCheckSetup(0,0,0,aSStack56);
      }
      Data_00 = razSideMoveSpiderCheck(In->CharacterInstance,-0x80);
    }
    if (Data_00 != 0) {
      G2EmulationSwitchAnimationCharacter(In,0x6a,0,3,1);
    }
    return;
  }
  puVar3 = (undefined *)p_Var1->ID;
  if (puVar3 == &DAT_00100004) goto LAB_800a177c;
  if ((int)puVar3 < 0x100005) {
    if (puVar3 == &DAT_80000020) goto LAB_800a177c;
    if ((int)puVar3 < -0x7fffffdf) {
      if (puVar3 == (undefined *)0x80000001) {
LAB_800a1324:
        _CHAR____800d5574 = 8;
        _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x10;
        SetPhysics(In->CharacterInstance,-0x10,0,0x28,0x9a);
                    /* WARNING: Subroutine does not return */
        G2EmulationSwitchAnimation(In,CurrentSection,0x23,0,0,1);
      }
      if (((int)puVar3 < -0x7fffffff) || (puVar3 == &DAT_80000008)) goto LAB_800a177c;
    }
    else {
      if (puVar3 == (undefined *)0x100000) {
        if (CurrentSection == 0) {
                    /* WARNING: Subroutine does not return */
          SetPhysicsWallCrawlData(0,0,3,in_a3);
        }
        goto LAB_800a177c;
      }
      if ((int)puVar3 < 0x100001) {
        if (puVar3 == (undefined *)0x0) goto LAB_800a177c;
      }
      else {
        if (puVar3 == &DAT_00100001) {
          if (CurrentSection == 2) {
            NewAnim = 0;
            Data_00 = 2;
            local_3c = CurrentSection;
          }
          else {
            NewAnim = 0x4c;
            local_3c = 2;
            Data_00 = CurrentSection;
          }
                    /* WARNING: Subroutine does not return */
          G2EmulationSwitchAnimation(In,Data_00,NewAnim,0,3,local_3c);
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
        SetPhysicsWallCrawlData(0,0,3,in_a3);
      }
      if (CurrentSection == 0) {
        if ((uVar2 & 4) == 0) {
          razSetWallCrawlNodes(In->CharacterInstance,(evPhysicsWallCrawlData *)p_Var1->Data);
        }
        else {
          SteerSwitchMode(In->CharacterInstance,0);
          Data_00 = SetControlInitHangData((_Instance *)0x0,0,3);
          StateSwitchStateCharacterData(In,StateHandlerHang,Data_00);
          razReaverBladeOn();
        }
      }
      goto LAB_800a177c;
    }
    if ((int)puVar3 < 0x4010012) {
      if (puVar3 == (undefined *)0x1000001) goto LAB_800a177c;
      if ((int)puVar3 < 0x1000002) {
        if (puVar3 == (undefined *)0x1000000) {
          if ((CurrentSection == 0) && ((theCamera.core._212_4_ & 0x800) != 0)) {
                    /* WARNING: Subroutine does not return */
            LoseHealth(*(int *)(p_Var1->Data + 0xc));
          }
          goto LAB_800a1324;
        }
      }
      else {
        if (puVar3 == (undefined *)0x4000004) goto LAB_800a177c;
      }
    }
    else {
      if (puVar3 == (undefined *)0x8000001) {
        if ((CurrentSection == 0) && (Data_00 == 0x68)) {
                    /* WARNING: Subroutine does not return */
          PHYSICS_GenericLineCheckSetup(0,0,0x140,aSStack56);
        }
        goto LAB_800a177c;
      }
      if ((int)puVar3 < 0x8000002) {
        if (puVar3 == (undefined *)0x8000000) {
          if (CurrentSection == 2) {
                    /* WARNING: Subroutine does not return */
            G2EmulationSwitchAnimation(In,2,0,0,3,2);
          }
                    /* WARNING: Subroutine does not return */
          G2EmulationSwitchAnimation(In,CurrentSection,0x4c,0,3,2);
        }
      }
      else {
        if (puVar3 == (undefined *)0x10000000) {
          if (CurrentSection != 0) goto LAB_800a177c;
          Data_00 = G2EmulationQueryAnimation(In,0);
          local_3c = p_Var1->Data;
          if (local_3c == 0x10000002) {
            if (Data_00 == 0x92) goto LAB_800a177c;
            Data_00 = razSideMoveSpiderCheck(In->CharacterInstance,-0x80);
            local_3c = 0x1c;
            if (Data_00 != 0) goto LAB_800a177c;
            instance = In->CharacterInstance;
          }
          else {
            if (local_3c < 0x10000003) {
              if ((local_3c == 0x10000001) && (Data_00 != 0x68)) {
                    /* WARNING: Subroutine does not return */
                PHYSICS_GenericLineCheckSetup(0,0,0xa0,aSStack56);
              }
              goto LAB_800a177c;
            }
            if (local_3c == 0x10000003) {
              if (Data_00 != 0x95) {
                    /* WARNING: Subroutine does not return */
                PHYSICS_GenericLineCheckSetup(0,0,-0x140,aSStack56);
              }
              goto LAB_800a177c;
            }
            if ((local_3c != 0x10000004) || (Data_00 == 0x91)) goto LAB_800a177c;
            Data_00 = razSideMoveSpiderCheck(In->CharacterInstance,0x80);
            local_3c = 0x1b;
            if (Data_00 != 0) goto LAB_800a177c;
            instance = In->CharacterInstance;
          }
          razSwitchVAnimCharacterSingle(instance,local_3c,(int *)0x0,(int *)0x0);
          goto LAB_800a177c;
        }
      }
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
LAB_800a177c:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&In->SectionList[CurrentSection].Event);
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerWallDismount(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s5*/)
 // line 423, offset 0x800a19b0
	/* begin block 1 */
		// Start line: 424
		// Start offset: 0x800A19B0
		// Variables:
	// 		struct __Event *Ptr; // $v0
	// 		int Frame; // $s4
	/* end block 1 */
	// End offset: 0x800A1C00
	// End Line: 505

	/* begin block 2 */
		// Start line: 884
	/* end block 2 */
	// End Line: 885

void StateHandlerWallDismount(__CharacterState *param_1,int param_2,int param_3)

{
  __Event *p_Var1;
  undefined *puVar2;
  __State *p_Var3;
  
  p_Var3 = param_1->SectionList + param_2;
  p_Var1 = PeekMessageQueue(&p_Var3->Event);
  if (p_Var1 == (__Event *)0x0) {
    return;
  }
  puVar2 = (undefined *)p_Var1->ID;
  if (puVar2 == &DAT_00100004) {
LAB_800a1b68:
    razReaverBladeOn();
    param_1->CharacterInstance->flags2 = param_1->CharacterInstance->flags2 | 0x40;
  }
  else {
    if ((int)puVar2 < 0x100005) {
      if (puVar2 == &DAT_80000008) goto LAB_800a1bf0;
      if ((int)puVar2 < -0x7ffffff7) {
        if (puVar2 == (undefined *)0x80000000) goto LAB_800a1bf0;
        if (puVar2 == (undefined *)0x80000001) {
                    /* WARNING: Subroutine does not return */
          EnMessageQueueData(&p_Var3->Defer,-0x7fffffff,0);
        }
      }
      else {
        if (puVar2 == &DAT_80000020) goto LAB_800a1bf0;
        if (puVar2 == &DAT_00100001) {
          if (param_2 == 0) {
            uGpfffffef8 = 8;
            uGpfffffe60 = 0;
            G2Anim_InterpDisableController(&param_1->CharacterInstance->anim,1,0x26,300);
            G2Anim_InterpDisableController(&param_1->CharacterInstance->anim,0,0xe,300);
            G2Anim_InterpDisableController(&param_1->CharacterInstance->anim,0,8,300);
            G2Anim_InterpDisableController(&param_1->CharacterInstance->anim,0xe,0xe,300);
            G2Anim_InterpDisableController(&param_1->CharacterInstance->anim,0x32,0x4c,300);
            G2Anim_InterpDisableController(&param_1->CharacterInstance->anim,0x3a,0x4c,300);
          }
          goto LAB_800a1b68;
        }
      }
    }
    else {
      if (puVar2 == (undefined *)0x4010008) goto LAB_800a1bf0;
      if ((int)puVar2 < 0x4010009) {
        if ((puVar2 == (undefined *)0x1000001) || (puVar2 == (undefined *)0x4000001))
        goto LAB_800a1bf0;
      }
      else {
        if (puVar2 == (undefined *)0x4020000) goto LAB_800a1bf0;
        if (puVar2 == (undefined *)0x8000000) {
                    /* WARNING: Subroutine does not return */
          G2EmulationSwitchAnimation(param_1,param_2,0x24,0,4,1);
        }
      }
    }
    DefaultStateHandler(param_1,param_2,param_3);
  }
LAB_800a1bf0:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&p_Var3->Event);
}





