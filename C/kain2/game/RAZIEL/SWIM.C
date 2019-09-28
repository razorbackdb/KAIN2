#include "THISDUST.H"
#include "SWIM.H"


// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerInitSwim(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$a2*/)
 // line 5, offset 0x8009eefc
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
// void /*$ra*/ StateHandlerSwimCoil(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s7*/)
 // line 54, offset 0x8009f008
	/* begin block 1 */
		// Start line: 55
		// Start offset: 0x8009F008
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		struct evPhysicsSwimData *SwimData; // $a0
	// 		int rc; // $s6
	// 		int release; // $s5

		/* begin block 1.1 */
			// Start line: 237
			// Start offset: 0x8009F688
			// Variables:
		// 		struct evMonsterHitData *data; // $v1
		/* end block 1.1 */
		// End offset: 0x8009F69C
		// End Line: 240
	/* end block 1 */
	// End offset: 0x8009F75C
	// End Line: 273

	/* begin block 2 */
		// Start line: 108
	/* end block 2 */
	// End Line: 109

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerSwimCoil(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *instance;
  int ID;
  undefined *puVar2;
  int NewAnim;
  int in_a3;
  __State *p_Var3;
  uint uVar4;
  int local_30;
  int local_2c;
  
  _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ & 0xfffffbff;
  uVar4 = In->SectionList[CurrentSection].Data1;
  if (CurrentSection == 0) {
    if (_CHAR____800d575c != 0) {
      razLaunchBubbles(3,3,1);
    }
    if ((_CHAR____800d5720 & 2) != 0) {
      razLaunchBubbles(3,6,1);
    }
    instance = In->CharacterInstance;
    if (instance->waterFace != (_TFace *)0x0) {
      ID = (int)(instance->splitPoint).z;
      if ((ID < instance->matrix[8].t[2]) || (ID < instance->matrix[0xc].t[2])) {
        PhysicsMode.next = (_BlockVramEntry *)((int)&mainMenuScreen + 2);
      }
    }
  }
  p_Var3 = In->SectionList + CurrentSection;
  p_Var1 = PeekMessageQueue(&p_Var3->Event);
  if (p_Var1 == (__Event *)0x0) {
    if ((*gameTracker._4_4_ & LONG_800cf578) == 0) {
                    /* WARNING: Subroutine does not return */
      EnMessageQueueData(&In->SectionList[CurrentSection].Defer,0x20000008,0);
    }
    return;
  }
  puVar2 = (undefined *)p_Var1->ID;
  if (puVar2 == (undefined *)0x1000000) {
    if ((CurrentSection == 0) && ((theCamera.core._212_4_ & 0x800) != 0)) {
                    /* WARNING: Subroutine does not return */
      LoseHealth(*(int *)(p_Var1->Data + 0xc));
    }
    goto LAB_8009f700;
  }
  if ((int)puVar2 < 0x1000001) {
    if (puVar2 == (undefined *)0x100000) {
      if ((uVar4 & 0x40) == 0) {
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
                    /* WARNING: Subroutine does not return */
        G2EmulationSwitchAnimation(In,ID,NewAnim,0,local_30,local_2c);
      }
      StateSwitchStateData(In,CurrentSection,StateHandlerSwimTread,0);
      if (CurrentSection != 0) goto LAB_8009f700;
      instance = In->CharacterInstance;
      ID = *(int *)(_PlayerData + 0x7c);
LAB_8009f558:
      razSetSwimVelocity(instance,0,ID);
      goto LAB_8009f700;
    }
    if ((int)puVar2 < 0x100001) {
      if (puVar2 == (undefined *)0x80000001) {
        ID = G2EmulationQueryAnimation(In,CurrentSection);
        if (ID != 0x43) {
                    /* WARNING: Subroutine does not return */
          G2EmulationSwitchAnimation(In,CurrentSection,0x43,0,3,1);
        }
        goto LAB_8009f700;
      }
      if ((((int)puVar2 < -0x7fffffff) || (puVar2 == &DAT_80000008)) || (puVar2 == &DAT_80000010))
      goto LAB_8009f700;
    }
    else {
      if (puVar2 == &DAT_00100009) goto LAB_8009f700;
      if ((int)puVar2 < 0x10000a) {
        if (puVar2 == &DAT_00100001) {
          if (_CHAR____800d5574 != 0x40000) {
            if (CurrentSection != 0) goto LAB_8009f2f4;
            CAMERA_ChangeToUnderWater((Camera *)&theCamera,In->CharacterInstance);
          }
          if (CurrentSection == 0) {
            _CHAR____800d5574 = 0x40000;
            _BlockVramEntry_800d59a0._12_4_ = 0x111;
            razSetSwimVelocity(In->CharacterInstance,*(int *)(_PlayerData + 0x68),
                               *(int *)(_PlayerData + 0x6c));
            SetTimer(5);
          }
LAB_8009f2f4:
          PhysicsMode.next = (_BlockVramEntry *)((int)&mainMenuScreen + 1);
                    /* WARNING: Subroutine does not return */
          G2EmulationSwitchAnimation(In,CurrentSection,0x41,0,9,2);
        }
        if (puVar2 == &DAT_00100004) {
          if (((_CHAR____800d5574 & 0x40000) == 0) && (CurrentSection == 0)) {
            CAMERA_ChangeToOutOfWater((Camera *)&theCamera,In->CharacterInstance);
          }
          goto LAB_8009f700;
        }
      }
      else {
        if (puVar2 == &DAT_00100011) {
          ID = p_Var1->Data;
          if (ID == *(int *)(_PlayerData + 0x68)) {
            razSetSwimVelocity(In->CharacterInstance,0,*(int *)(_PlayerData + 0x70));
            ID = p_Var1->Data;
          }
          if (ID != *(int *)(_PlayerData + 0x74)) goto LAB_8009f700;
          instance = In->CharacterInstance;
          ID = *(int *)(_PlayerData + 0x7c);
          goto LAB_8009f558;
        }
        if (puVar2 == &DAT_00100014) {
                    /* WARNING: Subroutine does not return */
          SetPhysicsWallCrawlData(0,0,9,in_a3);
        }
      }
    }
  }
  else {
    if (puVar2 == (undefined *)0x4020000) {
      ID = p_Var1->Data;
      In->SectionList[CurrentSection].Data1 = (int)*(short *)(ID + 0x10);
      if ((_CHAR____800d564c == 1) && ((_CHAR____800d561c & 0x10) == 0)) {
        _CHAR____800d5610 = 100000;
      }
      else {
        if ((*(ushort *)(ID + 0x10) & 0x220) != 0) {
          if (CurrentSection == 0) {
            _CHAR____800d5574 = 0x10;
            SetPhysics(In->CharacterInstance,-0x10,0,0x15,0xc3);
            SteerSwitchMode(In->CharacterInstance,4);
            _CHAR____800d55a4 = (int)(In->CharacterInstance->rotation).z;
            _CHAR____800d559a = (In->CharacterInstance->rotation).z;
            SetExternalForce((__Force *)&_BlockVramEntry_800d58c0.type,0,0,-0x10,1,0x1000);
            PhysicsMode.next = (_BlockVramEntry *)0x0;
          }
                    /* WARNING: Subroutine does not return */
          G2EmulationSwitchAnimation(In,CurrentSection,0x23,0,0,1);
        }
      }
      goto LAB_8009f700;
    }
    if ((int)puVar2 < 0x4020001) {
      if (puVar2 == (undefined *)0x4000001) goto LAB_8009f700;
      if ((int)puVar2 < 0x4000002) {
        if (puVar2 == (undefined *)0x1000001) goto LAB_8009f700;
      }
      else {
        if ((puVar2 == (undefined *)0x4000004) || (puVar2 == (undefined *)0x4010200))
        goto LAB_8009f700;
      }
    }
    else {
      if (puVar2 == (undefined *)0x8000004) {
        razSetSwimVelocity(In->CharacterInstance,*(int *)(_PlayerData + 0x74),
                           *(int *)(_PlayerData + 0x78));
        goto LAB_8009f700;
      }
      if ((int)puVar2 < 0x8000005) {
        if (puVar2 == (undefined *)0x8000000) {
          ID = G2EmulationQueryAnimation(In,CurrentSection);
          if (ID == 0x43) {
            ID = 0x100000;
LAB_8009f428:
                    /* WARNING: Subroutine does not return */
            EnMessageQueueData(&p_Var3->Defer,ID,0);
          }
          goto LAB_8009f700;
        }
        if (puVar2 == (undefined *)0x8000003) {
          if ((*gameTracker._4_4_ & LONG_800cf56c) != 0) {
            ID = -0x7fffffff;
            goto LAB_8009f428;
          }
          goto LAB_8009f700;
        }
      }
      else {
        if (puVar2 == (undefined *)0x20000001) goto LAB_8009f700;
        if (puVar2 == (undefined *)0x20000008) {
          ID = G2EmulationQueryAnimation(In,CurrentSection);
          if (ID != 0x43) {
            ID = G2EmulationQueryFrame(In,CurrentSection);
            if (ID < 2) {
              ID = 0x20000008;
            }
            else {
              ID = 0x100000;
            }
                    /* WARNING: Subroutine does not return */
            EnMessageQueueData(&p_Var3->Defer,ID,0);
          }
          goto LAB_8009f700;
        }
      }
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
LAB_8009f700:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&p_Var3->Event);
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerSwimTread(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$a2*/)
 // line 277, offset 0x8009f788
	/* begin block 1 */
		// Start line: 278
		// Start offset: 0x8009F788
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		struct evPhysicsSwimData *SwimData; // $s0

		/* begin block 1.1 */
			// Start line: 422
			// Start offset: 0x8009FCC8
			// Variables:
		// 		struct evPhysicsEdgeData *data; // $s0
		/* end block 1.1 */
		// End offset: 0x8009FD10
		// End Line: 428

		/* begin block 1.2 */
			// Start line: 448
			// Start offset: 0x8009FDAC
			// Variables:
		// 		struct evMonsterHitData *data; // $v1
		/* end block 1.2 */
		// End offset: 0x8009FDCC
		// End Line: 453
	/* end block 1 */
	// End offset: 0x8009FF24
	// End Line: 493

	/* begin block 2 */
		// Start line: 561
	/* end block 2 */
	// End Line: 562

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerSwimTread(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int Data_00;
  undefined *puVar2;
  int NewAnim;
  int in_a3;
  _Instance **pp_Var3;
  
  pp_Var3 = &In->CharacterInstance + CurrentSection * 0x47;
  _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x400;
  p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  Data_00 = _PlayerData;
  if (p_Var1 == (__Event *)0x0) {
    if ((CurrentSection == 1) && ((_CHAR____800d5720 & 1) != 0)) {
      razLaunchBubbles(3,1,0);
    }
    if (CurrentSection == 2) {
      if ((_CHAR____800d5720 & 2) != 0) {
        razSetSwimVelocity(In->CharacterInstance,*(int *)(_PlayerData + 0x8c),
                           *(int *)(_PlayerData + 0x90));
      }
      if ((((*gameTracker._4_4_ & LONG_800cf56c) != 0) && (_CHAR____800d559c == 6)) &&
         ((*gameTracker._4_4_ & 1) != 0)) {
        G2EmulationSwitchAnimationCharacter(In,0x40,0,3,1);
        StateSwitchStateCharacterData(In,StateHandlerSwimDiveIn,0);
        razSetSwimVelocity(In->CharacterInstance,*(int *)(_PlayerData + 0x8c),
                           *(int *)(_PlayerData + 0x90));
        _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ & 0xfffffbff;
      }
    }
    if (CurrentSection == 0) {
      if (*(int *)(_PlayerData + 0x98) < (int)_CHAR____800d5724) {
        _CHAR____800d5724 = *(short *)(_PlayerData + 0x98);
      }
      if ((int)_CHAR____800d5724 < *(int *)(_PlayerData + 0x94)) {
        _CHAR____800d5724 = *(short *)(_PlayerData + 0x94);
      }
    }
    return;
  }
  puVar2 = (undefined *)p_Var1->ID;
  if (puVar2 == (undefined *)0x4000001) goto LAB_8009fdd0;
  if (0x4000001 < (int)puVar2) {
    if (puVar2 == (undefined *)0x4020000) {
      Data_00 = p_Var1->Data;
      if ((_CHAR____800d564c == 1) && ((_CHAR____800d561c & 0x10) == 0)) {
        _CHAR____800d5610 = 100000;
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
          SetPhysicsWallCrawlData(0,0,9,in_a3);
        }
      }
LAB_8009fdd0:
                    /* WARNING: Subroutine does not return */
      DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
    }
    if ((int)puVar2 < 0x4020001) {
      if (puVar2 == (undefined *)0x4010010) {
        Data_00 = p_Var1->Data;
        SetPhysics(In->CharacterInstance,0,0,0,0);
        Data_00 = SetControlInitHangData(*(_Instance **)(Data_00 + 0x18),0,3);
        StateSwitchStateData(In,CurrentSection,StateHandlerHang,Data_00);
      }
      goto LAB_8009fdd0;
    }
    if (puVar2 != (undefined *)0x8000001) goto LAB_8009fdd0;
    if (p_Var1->Data == 0x42) {
      if (pp_Var3[0x48] == (_Instance *)0x1) {
        pp_Var3[0x48] = (_Instance *)0x0;
        razSetSwimVelocity(In->CharacterInstance,*(int *)(Data_00 + 0x80),*(int *)(Data_00 + 0x84));
        goto LAB_8009fdd0;
      }
      if (((*gameTracker._4_4_ & LONG_800cf56c) != 0) && (_CHAR____800d559c != 0)) {
                    /* WARNING: Subroutine does not return */
        G2EmulationSwitchAnimation(In,CurrentSection,0x3e,0,3,2);
      }
      razSetSwimVelocity(In->CharacterInstance,0,*(int *)(_PlayerData + 0x9c));
      NewAnim = 0x3d;
      Data_00 = 0xf;
    }
    else {
      if ((p_Var1->Data != 0x3e) || ((*gameTracker._4_4_ & LONG_800cf56c) != 0)) goto LAB_8009fdd0;
      if (CurrentSection == 2) {
        razSetSwimVelocity(In->CharacterInstance,0,*(int *)(_PlayerData + 0x88));
      }
      NewAnim = 0x3d;
      Data_00 = 0xf;
    }
    goto LAB_8009fb38;
  }
  if (puVar2 != &DAT_00100001) {
    if ((int)puVar2 < 0x100002) {
      if (puVar2 == &DAT_80000008) {
        StateSwitchStateData(In,CurrentSection,StateHandlerSwimCoil,0);
      }
      else {
        if ((int)puVar2 < -0x7ffffff7) {
          if ((puVar2 == (undefined *)0x80000001) && (_CHAR____800d559c == 6)) {
            Data_00 = G2EmulationQueryAnimation(In,CurrentSection);
            if (Data_00 != 0x42) {
              if (CurrentSection == 2) {
                razSetSwimVelocity(In->CharacterInstance,*(int *)(_PlayerData + 0x80),
                                   *(int *)(_PlayerData + 0x84));
              }
              NewAnim = 0x42;
              Data_00 = 5;
              goto LAB_8009fb38;
            }
            pp_Var3[0x48] = (_Instance *)0x1;
          }
        }
        else {
          if (((puVar2 == &DAT_80000010) && ((_CHAR____800d5574 & 0x10000000) == 0)) &&
             (CurrentSection == 0)) {
            StateSwitchStateCharacterData(In,StateHandlerGlyphs,0);
            G2EmulationSwitchAnimationCharacter(In,0x3d,0,9,2);
          }
        }
      }
    }
    else {
      if (puVar2 == &DAT_00100009) {
        if (CurrentSection == 0) {
          if (p_Var1->Data == 0) {
            SteerSwitchMode(In->CharacterInstance,6);
          }
          else {
            SteerSwitchMode(In->CharacterInstance,0);
          }
        }
      }
      else {
        if ((int)puVar2 < 0x10000a) {
          if (puVar2 == &DAT_00100004) {
            if ((_CHAR____800d5574 & 0x40000) == 0) {
              if (CurrentSection != 0) goto LAB_8009fdd0;
              CAMERA_ChangeToOutOfWater((Camera *)&theCamera,In->CharacterInstance);
            }
            if (CurrentSection == 0) {
              _CHAR____800d5720 = 0;
            }
          }
        }
        else {
          if (puVar2 == &DAT_00100014) {
                    /* WARNING: Subroutine does not return */
            SetPhysicsWallCrawlData(0,0,9,in_a3);
          }
          if (((puVar2 == (undefined *)0x1000000) && (CurrentSection == 0)) &&
             ((theCamera.core._212_4_ & 0x800) != 0)) {
                    /* WARNING: Subroutine does not return */
            LoseHealth(*(int *)(p_Var1->Data + 0xc));
          }
        }
      }
    }
    goto LAB_8009fdd0;
  }
  if ((_CHAR____800d5574 & 0x40000) == 0) {
    if (CurrentSection == 0) {
      CAMERA_ChangeToUnderWater((Camera *)&theCamera,In->CharacterInstance);
      goto LAB_8009f91c;
    }
  }
  else {
LAB_8009f91c:
    if (CurrentSection == 0) {
      _CHAR____800d5574 = 0x40000;
      _BlockVramEntry_800d59a0._12_4_ = 0x511;
      PhysicsMode.next = (_BlockVramEntry *)((int)&mainMenuScreen + 2);
      razSetSwimVelocity(In->CharacterInstance,0,*(int *)(_PlayerData + 0x88));
      SteerSwitchMode(In->CharacterInstance,6);
      _CHAR____800d5720 = 0;
    }
  }
  NewAnim = 0x3d;
  Data_00 = 9;
LAB_8009fb38:
                    /* WARNING: Subroutine does not return */
  G2EmulationSwitchAnimation(In,CurrentSection,NewAnim,0,Data_00,2);
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerSwimDiveIn(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$a2*/)
 // line 497, offset 0x8009ff50
	/* begin block 1 */
		// Start line: 498
		// Start offset: 0x8009FF50
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		struct evPhysicsSwimData *SwimData; // $s3

		/* begin block 1.1 */
			// Start line: 581
			// Start offset: 0x800A01E8
			// Variables:
		// 		struct evMonsterHitData *data; // $v1
		/* end block 1.1 */
		// End offset: 0x800A0208
		// End Line: 586
	/* end block 1 */
	// End offset: 0x800A02B8
	// End Line: 614

	/* begin block 2 */
		// Start line: 1048
	/* end block 2 */
	// End Line: 1049

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerSwimDiveIn(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  undefined *puVar2;
  int in_a3;
  __State *p_Var3;
  
  p_Var3 = In->SectionList + CurrentSection;
  p_Var1 = PeekMessageQueue(&p_Var3->Event);
  if (p_Var1 == (__Event *)0x0) {
    if (CurrentSection == 0) {
      (In->CharacterInstance->position).z = (In->CharacterInstance->position).z + -0x10;
      if ((_CHAR____800d5720 & 1) != 0) {
        if (((_CHAR____800d5720 & 2) != 0) || ((*gameTracker._4_4_ & 1) != 0)) {
          _CHAR____800d5724 = _CHAR____800d5724 + 0x30;
        }
        if (0x400 < _CHAR____800d5724) {
          PhysicsMode.next = (_BlockVramEntry *)((int)&mainMenuScreen + 1);
        }
        if ((_CHAR____800d5720 & 4) != 0) {
          razLaunchBubbles(3,1,0);
        }
      }
    }
    return;
  }
  puVar2 = (undefined *)p_Var1->ID;
  if (puVar2 == &DAT_00100014) {
                    /* WARNING: Subroutine does not return */
    SetPhysicsWallCrawlData(0,0,9,in_a3);
  }
  if ((int)puVar2 < 0x100015) {
    if ((puVar2 != (undefined *)0x100000) && (0x100000 < (int)puVar2)) {
      if (puVar2 == &DAT_00100001) {
        if (_CHAR____800d5574 != 0x40000) {
          if (CurrentSection != 0) goto LAB_800a0208;
          CAMERA_ChangeToUnderWater((Camera *)&theCamera,In->CharacterInstance);
        }
        if (CurrentSection == 0) {
          _CHAR____800d5574 = 0x40000;
          _BlockVramEntry_800d59a0._12_4_ = 0x191;
          PhysicsMode.next = (_BlockVramEntry *)((int)&mainMenuScreen + 2);
          SteerSwitchMode(In->CharacterInstance,0x11);
        }
      }
      else {
        if (((puVar2 == &DAT_00100004) && ((_CHAR____800d5574 & 0x40000) == 0)) &&
           (CurrentSection == 0)) {
          CAMERA_ChangeToOutOfWater((Camera *)&theCamera,In->CharacterInstance);
          _CHAR____800d5720 = 0;
        }
      }
    }
  }
  else {
    if (puVar2 != (undefined *)0x4010200) {
      if ((int)puVar2 < 0x4010201) {
        if (((puVar2 == (undefined *)0x1000000) && (CurrentSection == 0)) &&
           ((theCamera.core._212_4_ & 0x800) != 0)) {
                    /* WARNING: Subroutine does not return */
          LoseHealth(*(int *)(p_Var1->Data + 0xc));
        }
      }
      else {
        if (puVar2 == (undefined *)0x4020000) {
          if ((*(ushort *)(p_Var1->Data + 0x10) & 0x80) != 0) {
                    /* WARNING: Subroutine does not return */
            SetPhysicsWallCrawlData(0,0,9,in_a3);
          }
        }
        else {
          if (puVar2 == (undefined *)0x8000000) {
            if ((*gameTracker._4_4_ & LONG_800cf56c) != 0) {
                    /* WARNING: Subroutine does not return */
              EnMessageQueueData(&p_Var3->Defer,-0x7fffffff,0);
            }
            if ((DAT_00000010 & 0x40) == 0) {
              StateSwitchStateData(In,CurrentSection,StateHandlerSwim,0);
              (&In->CharacterInstance + CurrentSection * 0x47)[0x48] =
                   (_Instance *)((uint)(&In->CharacterInstance + CurrentSection * 0x47)[0x48] | 2);
            }
            else {
              StateSwitchStateData(In,CurrentSection,StateHandlerSwimTread,0);
            }
          }
        }
      }
    }
  }
LAB_800a0208:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&p_Var3->Event);
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerSwim(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s3*/, int Data /*stack 8*/)
 // line 621, offset 0x800a02dc
	/* begin block 1 */
		// Start line: 622
		// Start offset: 0x800A02DC
		// Variables:
	// 		struct __Event *Ptr; // $a0
	// 		struct evPhysicsSwimData *SwimData; // $s2
	// 		int tap; // $fp

		/* begin block 1.1 */
			// Start line: 804
			// Start offset: 0x800A0A7C
			// Variables:
		// 		struct _Instance *Inst; // $s0
		/* end block 1.1 */
		// End offset: 0x800A0B28
		// End Line: 816

		/* begin block 1.2 */
			// Start line: 948
			// Start offset: 0x800A0DE0
			// Variables:
		// 		struct evMonsterHitData *data; // $v1
		/* end block 1.2 */
		// End offset: 0x800A0DF4
		// End Line: 951
	/* end block 1 */
	// End offset: 0x800A0E28
	// End Line: 962

	/* begin block 2 */
		// Start line: 1424
	/* end block 2 */
	// End Line: 1425

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerSwim(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int NewAnim;
  undefined *puVar2;
  _Instance *Inst;
  code *NewProcess;
  long adjustment;
  int NewAnim_00;
  int in_a3;
  __MessageQueue *In_00;
  _Instance **pp_Var3;
  int local_30;
  int local_2c;
  
  if (CurrentSection == 0) {
    if (0 < In->CharacterInstance->zVel) {
      In->SectionList[0].Data2 = In->SectionList[0].Data2 | 2;
    }
    if (_CHAR____800d5584 < -0x60) {
      razLaunchBubbles(3,3,1);
    }
    if ((_CHAR____800d5720 & 1) != 0) {
      razLaunchBubbles(2,1,0);
    }
    if ((_CHAR____800d5720 & 2) != 0) {
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
    SetPhysicsWallCrawlData(0,0,9,in_a3);
  }
  if ((int)puVar2 < 0x100015) {
    if (puVar2 == &DAT_80000010) {
      if (((_CHAR____800d5574 & 0x10000000) == 0) && (CurrentSection == 0)) {
        StateSwitchStateCharacterData(In,StateHandlerGlyphs,0);
                    /* WARNING: Subroutine does not return */
        G2EmulationSwitchAnimation(In,2,0x3d,0,3,2);
      }
      goto LAB_800a0e18;
    }
    if ((int)puVar2 < -0x7fffffef) {
      if (puVar2 == &DAT_80000002) {
        if (CurrentSection == 1) {
          _CHAR____800d571c = In->SectionList[1].Process;
          StateSwitchStateData(In,1,StateHandlerSoulSuck,0);
        }
        goto LAB_800a0e18;
      }
      if ((int)puVar2 < -0x7ffffffd) {
        if (puVar2 == (undefined *)0x80000000) goto LAB_800a0e18;
        if (puVar2 == (undefined *)0x80000001) {
          if (_CHAR____800d559c == 6) {
            NewAnim = G2EmulationQueryAnimation(In,CurrentSection);
            if (NewAnim != 0x44) {
              if (CurrentSection == 0) {
                razSetSwimVelocity(In->CharacterInstance,*(int *)(_PlayerData + 0x54),
                                   *(int *)(_PlayerData + 0x58));
                _CHAR____800d5774 = 0x5dc;
                (In->CharacterInstance->anim).section[0].swAlarmTable = (short *)0x800d5774;
              }
              NewAnim = 0x44;
              local_2c = 5;
              goto LAB_800a0d80;
            }
            pp_Var3[0x48] = (_Instance *)((uint)pp_Var3[0x48] | 1);
          }
          goto LAB_800a0e18;
        }
      }
      else {
        if (puVar2 == &DAT_80000004) {
          Inst = In->CharacterInstance;
          adjustment = *(long *)(_PlayerData + 100);
LAB_800a0cdc:
                    /* WARNING: Subroutine does not return */
          G2Anim_SetSpeedAdjustment(&Inst->anim,adjustment);
        }
        if (puVar2 == &DAT_80000008) {
          if (CurrentSection != 0) goto LAB_800a0e18;
          NewAnim = G2EmulationQueryFrame(In,0);
          if (NewAnim < 2) {
                    /* WARNING: Subroutine does not return */
            EnMessageQueueData(&In->SectionList[0].Defer,(int)&DAT_80000008,0);
          }
          NewProcess = StateHandlerSwimCoil;
LAB_800a08f0:
          StateSwitchStateCharacterData(In,NewProcess,0);
          goto LAB_800a0e18;
        }
      }
    }
    else {
      if (puVar2 == &DAT_00100001) {
        if (_CHAR____800d5574 != 0x40000) {
          if (CurrentSection != 0) goto LAB_800a05f8;
          CAMERA_ChangeToUnderWater((Camera *)&theCamera,In->CharacterInstance);
        }
        if (CurrentSection == 0) {
          _CHAR____800d5574 = 0x40000;
          _CHAR____800d557c = 1;
          _BlockVramEntry_800d59a0._12_4_ = 400;
          SteerSwitchMode(In->CharacterInstance,6);
          razSetSwimVelocity(In->CharacterInstance,0,*(int *)(_PlayerData + 0x50));
                    /* WARNING: Subroutine does not return */
          G2Anim_SetSpeedAdjustment(&In->CharacterInstance->anim,0x1000);
        }
LAB_800a05f8:
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
            if ((_CHAR____800d561c & 4) == 0) goto LAB_800a0e18;
          }
          else {
            NewAnim = 0x800010;
          }
                    /* WARNING: Subroutine does not return */
          EnMessageQueueData(In_00,NewAnim,1);
        }
        if (puVar2 == (undefined *)0x80000) {
          if (CurrentSection != 0) goto LAB_800a0e18;
          razLaunchForce(In->CharacterInstance);
          NewProcess = StateHandlerThrow2;
          goto LAB_800a08f0;
        }
      }
      else {
        if (puVar2 == &DAT_00100004) {
          if ((_CHAR____800d5574 & 0x40000) == 0) {
            if (CurrentSection == 0) {
                    /* WARNING: Subroutine does not return */
              G2Anim_SetSpeedAdjustment(&In->CharacterInstance->anim,0x1000);
            }
          }
          else {
            if (CurrentSection == 0) {
              _CHAR____800d5720 = 0;
            }
          }
          goto LAB_800a0e18;
        }
        if (puVar2 == &DAT_00100009) {
          if (CurrentSection != 0) goto LAB_800a0e18;
          if (p_Var1->Data == 0) {
            SteerSwitchMode(In->CharacterInstance,6);
            goto LAB_800a0e18;
          }
          SteerSwitchMode(In->CharacterInstance,0);
LAB_800a0a10:
          razSetSwimVelocity(In->CharacterInstance,0,*(int *)(_PlayerData + 0x50));
          goto LAB_800a0e18;
        }
      }
    }
  }
  else {
    if (puVar2 == (undefined *)0x4010200) goto LAB_800a0e18;
    if ((int)puVar2 < 0x4010201) {
      if (puVar2 == (undefined *)0x1000001) goto LAB_800a0e18;
      if ((int)puVar2 < 0x1000002) {
        if (puVar2 == (undefined *)0x800010) {
          if (CurrentSection != 0) goto LAB_800a0e18;
          NewProcess = StateHandlerThrow2;
          goto LAB_800a08f0;
        }
        if (puVar2 == (undefined *)0x1000000) {
          if ((CurrentSection == 0) && ((theCamera.core._212_4_ & 0x800) != 0)) {
                    /* WARNING: Subroutine does not return */
            LoseHealth(*(int *)(p_Var1->Data + 0xc));
          }
          goto LAB_800a0e18;
        }
      }
      else {
        if (puVar2 == (undefined *)0x2000000) {
          razPickupAndGrab(In,CurrentSection);
          goto LAB_800a0e18;
        }
        if (puVar2 == (undefined *)0x4000001) goto LAB_800a0e18;
      }
    }
    else {
      if (puVar2 == (undefined *)0x8000001) {
        NewAnim = p_Var1->Data;
        if ((NewAnim == 0x44) || (NewAnim == 0x42)) {
          if (((uint)pp_Var3[0x48] & 1) != 0) {
            razSetSwimVelocity(In->CharacterInstance,*(int *)(_PlayerData + 0x54),
                               *(int *)(_PlayerData + 0x58));
            pp_Var3[0x48] = (_Instance *)((uint)pp_Var3[0x48] & 0xfffffffe);
            goto LAB_800a0e18;
          }
          if (((*gameTracker._4_4_ & LONG_800cf56c) != 0) && (_CHAR____800d559c == 6)) {
            if (CurrentSection != 2) {
              NewAnim = 0x3c;
              local_2c = 0xc;
              goto LAB_800a0d80;
            }
            NewAnim = 0;
            goto LAB_800a0894;
          }
          if (CurrentSection == 0) {
            razSetSwimVelocity(In->CharacterInstance,0,*(int *)(_PlayerData + 0x50));
          }
          if (CurrentSection != 2) {
            NewAnim = 0x3f;
            local_2c = 8;
LAB_800a0d80:
                    /* WARNING: Subroutine does not return */
            G2EmulationSwitchAnimation(In,CurrentSection,NewAnim,0,local_2c,2);
          }
        }
        else {
          if ((NewAnim == 0x3f) || ((*gameTracker._4_4_ & LONG_800cf56c) != 0)) goto LAB_800a0e18;
          if (CurrentSection == 0) {
            razSetSwimVelocity(In->CharacterInstance,0,*(int *)(_PlayerData + 0x50));
          }
          if (CurrentSection != 2) {
            NewAnim = 0x3f;
            local_2c = 0x10;
            goto LAB_800a0d80;
          }
        }
        NewAnim = 0x3d;
LAB_800a0894:
                    /* WARNING: Subroutine does not return */
        G2EmulationSwitchAnimation(In,2,NewAnim,0,3,CurrentSection);
      }
      if ((int)puVar2 < 0x8000002) {
        if (puVar2 == (undefined *)0x4020000) {
          NewAnim = p_Var1->Data;
          if ((_CHAR____800d564c == 1) && ((_CHAR____800d561c & 0x10) == 0)) {
            _CHAR____800d5610 = 100000;
          }
          else {
            if (CurrentSection == 0) {
              Inst = razGetHeldWeapon();
              PhysicsForceSetWater
                        (In->CharacterInstance,&In->SectionList[0].Data1,
                         (int)*(short *)(NewAnim + 0xc),*(int *)(_PlayerData + 0x48),
                         *(int *)(_PlayerData + 0x4c));
              if (*(short *)(NewAnim + 0xc) < -0x3f) {
                _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ & 0xfffffbff;
              }
              else {
                _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x400;
              }
              if (Inst != (_Instance *)0x0) {
                    /* WARNING: Subroutine does not return */
                INSTANCE_Query(Inst,4);
              }
            }
            if (((*(ushort *)(NewAnim + 0x10) & 0x200) != 0) && (CurrentSection == 0)) {
                    /* WARNING: Read-only address (ram,0x800d58d4) is written */
              _BlockVramEntry_800d58c0.area._0_2_ = 0x30;
            }
            if ((((*(ushort *)(NewAnim + 0x10) & 0x40) != 0) && (_CHAR____800d5574 == 0x40000)) &&
               (0 < _CHAR____800d5584)) {
              StateHandlerInitSwim(In,CurrentSection,Data);
            }
            if ((*(ushort *)(NewAnim + 0x10) & 0x400) != 0) {
              if (CurrentSection == 0) {
                _CHAR____800d5574 = 0x10;
                SetExternalForce((__Force *)&_BlockVramEntry_800d58dc.w,0,0,-0x10,1,0x1000);
                In->CharacterInstance->xVel = (int)_CHAR____800d5580;
                In->CharacterInstance->yVel = (int)_CHAR____800d5582;
                In->CharacterInstance->zVel = (int)_CHAR____800d5584;
                    /* WARNING: Read-only address (ram,0x800d58d4) is written */
                _BlockVramEntry_800d58c0.area._0_2_ = 0x38;
              }
                    /* WARNING: Subroutine does not return */
              G2EmulationSwitchAnimation(In,CurrentSection,0x23,0,0,1);
            }
            if ((*(ushort *)(NewAnim + 0x10) & 0x20) != 0) {
              _CHAR____800d5574 = 0x100000;
                    /* WARNING: Subroutine does not return */
              G2EmulationSwitchAnimation(In,CurrentSection,0x23,0,0,1);
            }
          }
          goto LAB_800a0e18;
        }
        if (puVar2 == (undefined *)0x8000000) goto LAB_800a0e18;
      }
      else {
        if (puVar2 == (undefined *)0x20000001) goto LAB_800a0e18;
        if ((int)puVar2 < 0x20000002) {
          if (puVar2 == (undefined *)0x8000004) {
            if ((*gameTracker._4_4_ & LONG_800cf56c) != 0) {
              razSetSwimVelocity(In->CharacterInstance,*(int *)(_PlayerData + 0x5c),
                                 *(int *)(_PlayerData + 0x60));
              goto LAB_800a0e18;
            }
            goto LAB_800a0a10;
          }
        }
        else {
          if (puVar2 == (undefined *)0x20000004) {
            Inst = In->CharacterInstance;
            adjustment = 0x1000;
            goto LAB_800a0cdc;
          }
        }
      }
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
LAB_800a0e18:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue((__MessageQueue *)(&In->CharacterInstance + CurrentSection * 0x47 + 3));
}





