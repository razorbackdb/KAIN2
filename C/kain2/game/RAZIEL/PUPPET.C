#include "THISDUST.H"
#include "PUPPET.H"


// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerPuppetShow(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s1*/, int Data /*$s4*/)
 // line 8, offset 0x8009a984
	/* begin block 1 */
		// Start line: 9
		// Start offset: 0x8009A984
		// Variables:
	// 		struct __Event *Ptr; // $s0

		/* begin block 1.1 */
			// Start line: 38
			// Start offset: 0x8009AB48
			// Variables:
		// 		struct evActionPlayHostAnimationData *data; // $v0
		/* end block 1.1 */
		// End offset: 0x8009AB48
		// End Line: 40

		/* begin block 1.2 */
			// Start line: 53
			// Start offset: 0x8009ABB8
			// Variables:
		// 		struct evAnimationInstanceSwitchData *data; // $v1
		/* end block 1.2 */
		// End offset: 0x8009ABB8
		// End Line: 55

		/* begin block 1.3 */
			// Start line: 67
			// Start offset: 0x8009AC34
			// Variables:
		// 		struct evPositionData *data; // $v0
		/* end block 1.3 */
		// End offset: 0x8009AC34
		// End Line: 67

		/* begin block 1.4 */
			// Start line: 78
			// Start offset: 0x8009AC78
			// Variables:
		// 		struct evPositionData *data; // $v0

			/* begin block 1.4.1 */
				// Start line: 78
				// Start offset: 0x8009AC78
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $a1
			// 		struct _Position *_v0; // $v0
			/* end block 1.4.1 */
			// End offset: 0x8009AC78
			// End Line: 78
		/* end block 1.4 */
		// End offset: 0x8009AC78
		// End Line: 78
	/* end block 1 */
	// End offset: 0x8009ACF4
	// End Line: 98

	/* begin block 2 */
		// Start line: 16
	/* end block 2 */
	// End Line: 17

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerPuppetShow(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *p_Var2;
  undefined2 *puVar3;
  code *pcVar4;
  int iVar5;
  
  p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var1 == (__Event *)0x0) {
    razApplyMotion(In,CurrentSection);
    return;
  }
  pcVar4 = (code *)p_Var1->ID;
  if (pcVar4 == (code *)&LAB_00040014_2) {
                    /* WARNING: Subroutine does not return */
    G2EmulationSwitchAnimation(In,CurrentSection,0x7b,0,4,2);
  }
  if ((int)pcVar4 < 0x40017) {
    if (pcVar4 == (code *)&LAB_0004000c_1) {
      if (CurrentSection == 0) {
        _CHAR____800d576a = *(undefined2 *)(p_Var1->Data + 4);
        SteerSwitchMode(In->CharacterInstance,0xd);
      }
      goto LAB_8009ace4;
    }
    if ((int)pcVar4 < 0x4000e) {
      if (pcVar4 == (code *)&DAT_00040003) {
        if (CurrentSection == 0) {
          p_Var2 = (_Instance *)p_Var1->Data;
          G2EmulationInstanceToInstanceSwitchAnimationCharacter
                    (*(_Instance **)&p_Var2->node,*(_Instance **)((int)&p_Var2->node + 4),
                     (int)p_Var2->next,(int)p_Var2->prev,(int)p_Var2->instanceID,(int)p_Var2->flags)
          ;
        }
        goto LAB_8009ace4;
      }
      if (pcVar4 == (code *)&LAB_0004000c) {
        StateSwitchStateData(In,CurrentSection,StateHandlerMoveToPosition,p_Var1->Data);
        goto LAB_8009ace4;
      }
    }
    else {
      if (pcVar4 == (code *)&LAB_00040010) {
        _CHAR____800d55b0 = _CHAR____800d55b0 & 0xffffffef;
        _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ & 0xfffdffff;
        goto LAB_8009ace4;
      }
      if (pcVar4 == (code *)&LAB_00040014) {
                    /* WARNING: Subroutine does not return */
        G2EmulationSwitchAnimation(In,CurrentSection,0,0,3,2);
      }
    }
  }
  else {
    if (pcVar4 == (code *)&DAT_00100001) {
      if (p_Var1->Data != 0) {
                    /* WARNING: Subroutine does not return */
        G2EmulationSwitchAnimation(In,CurrentSection,0,0,3,2);
      }
      _CHAR____800d5574 = 1;
      _CHAR____800d5654 = 0;
      _BlockVramEntry_800d59a0._12_4_ = 0x1020008;
      PhysicsMode.next = (_BlockVramEntry *)0x0;
      SteerSwitchMode(In->CharacterInstance,0);
      ResetPhysics(In->CharacterInstance,-0x10);
      _CHAR____800d55a8 = 0;
      if (CurrentSection == 0) {
        _CHAR____800d563a = 0;
      }
      goto LAB_8009ace4;
    }
    if ((int)pcVar4 < 0x100002) {
      if (pcVar4 == FUN_00040018) {
        if (CurrentSection == 0) {
          puVar3 = (undefined2 *)p_Var1->Data;
          _CHAR____800d5766 = *puVar3;
          _CHAR____800d5768 = puVar3[1];
          _CHAR____800d576a = puVar3[2];
          SteerSwitchMode(In->CharacterInstance,0xc);
        }
        goto LAB_8009ace4;
      }
      if (pcVar4 == (code *)0x40021) {
        _CHAR____800d55a0 = *(undefined2 *)&p_Var1->Data;
        goto LAB_8009ace4;
      }
    }
    else {
      if (pcVar4 == (code *)0x4000001) goto LAB_8009ace4;
      if ((int)pcVar4 < 0x4000002) {
        if (pcVar4 == (code *)0x1000001) goto LAB_8009ace4;
      }
      else {
        if (pcVar4 == (code *)0x8000008) {
          if (CurrentSection == 0) {
            iVar5 = p_Var1->Data;
            G2EmulationSwitchAnimationCharacter
                      (In,*(int *)(iVar5 + 4),*(int *)(iVar5 + 8),*(int *)(iVar5 + 0xc),
                       *(int *)(iVar5 + 0x10));
          }
          goto LAB_8009ace4;
        }
      }
    }
  }
  DefaultPuppetStateHandler(In,CurrentSection,Data);
LAB_8009ace4:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&In->SectionList[CurrentSection].Event);
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerMoveToPosition(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s6*/)
 // line 102, offset 0x8009ad20
	/* begin block 1 */
		// Start line: 103
		// Start offset: 0x8009AD20
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		long distance; // $s0
	// 		int motion; // $v0
	// 		int applyMotion; // $s5

		/* begin block 1.1 */
			// Start line: 113
			// Start offset: 0x8009AE2C
			// Variables:
		// 		struct evPositionData *moveToPoint; // $v0

			/* begin block 1.1.1 */
				// Start line: 115
				// Start offset: 0x8009AE2C
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $v0
			// 		struct _Position *_v0; // $s3
			/* end block 1.1.1 */
			// End offset: 0x8009AE2C
			// End Line: 115
		/* end block 1.1 */
		// End offset: 0x8009AE2C
		// End Line: 115

		/* begin block 1.2 */
			// Start line: 134
			// Start offset: 0x8009AEC8
			// Variables:
		// 		struct evPositionData *moveToPoint; // $v0

			/* begin block 1.2.1 */
				// Start line: 136
				// Start offset: 0x8009AEC8
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $v0
			/* end block 1.2.1 */
			// End offset: 0x8009AEC8
			// End Line: 136
		/* end block 1.2 */
		// End offset: 0x8009AEEC
		// End Line: 140
	/* end block 1 */
	// End offset: 0x8009AFA0
	// End Line: 174

	/* begin block 2 */
		// Start line: 217
	/* end block 2 */
	// End Line: 218

/* WARNING: Removing unreachable block (ram,0x8009afa0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerMoveToPosition(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  short *psVar2;
  _Instance *p_Var3;
  undefined *puVar4;
  short y;
  int in_a3;
  int local_28;
  int local_24;
  
  y = (short)Data;
  p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var1 == (__Event *)0x0) {
    if (CurrentSection == 0) {
      razAlignYRotInterp(In->CharacterInstance,(_Position *)&CHAR____800d5760,'\0',4);
    }
    p_Var3 = In->CharacterInstance;
                    /* WARNING: Subroutine does not return */
    MATH3D_LengthXYZ((int)(p_Var3->position).x - (int)_CHAR____800d5760,
                     (int)(p_Var3->position).y - (int)_CHAR____800d5762,
                     (int)(p_Var3->position).z - (int)_CHAR____800d5764);
  }
  puVar4 = (undefined *)p_Var1->ID;
  if (puVar4 == &DAT_00100001) {
    if (CurrentSection == 0) {
      psVar2 = (short *)p_Var1->Data;
      _CHAR____800d5760 = *psVar2;
      _CHAR____800d5762 = psVar2[1];
      _CHAR____800d5764 = psVar2[2];
      razAlignYRotInterp(In->CharacterInstance,(_Position *)&CHAR____800d5760,'\0',4);
      PhysicsMode.next = (_BlockVramEntry *)0x0;
      SteerSwitchMode(In->CharacterInstance,0);
    }
  }
  else {
    if ((int)puVar4 < 0x100002) {
      if (puVar4 == &LAB_00040014_2) {
                    /* WARNING: Subroutine does not return */
        G2EmulationSwitchAnimation(In,CurrentSection,0x7b,0,4,2);
      }
      if ((int)puVar4 < 0x40017) {
        if (puVar4 == &LAB_0004000c) {
          psVar2 = (short *)p_Var1->Data;
          _CHAR____800d5760 = *psVar2;
          _CHAR____800d5762 = psVar2[1];
          _CHAR____800d5764 = psVar2[2];
          goto LAB_8009af10;
        }
      }
      else {
        if (puVar4 == (undefined *)0x100000) {
                    /* WARNING: Subroutine does not return */
          SetPhysicsWallCrawlData(0,0,3,in_a3);
        }
      }
    }
    else {
      if (puVar4 == (undefined *)0x4000001) {
        PhysicsMode.next = (_BlockVramEntry *)0x0;
        SetExternalForce((__Force *)In->CharacterInstance,0x5214,y,(short)in_a3,local_28,local_24);
        goto LAB_8009af10;
      }
      if ((int)puVar4 < 0x4000002) {
        if (puVar4 == (undefined *)0x1000000) goto LAB_8009af10;
      }
      else {
        if ((puVar4 == (undefined *)0x4010400) || (puVar4 == (undefined *)0x4020000))
        goto LAB_8009af10;
      }
    }
    DefaultPuppetStateHandler(In,CurrentSection,Data);
  }
LAB_8009af10:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&In->SectionList[CurrentSection].Event);
}



// decompiled code
// original method signature: 
// void /*$ra*/ DefaultPuppetStateHandler(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$s2*/)
 // line 174, offset 0x8009afc8
	/* begin block 1 */
		// Start line: 175
		// Start offset: 0x8009AFC8
		// Variables:
	// 		struct __Event *Ptr; // $a1

		/* begin block 1.1 */
			// Start line: 194
			// Start offset: 0x8009B190
			// Variables:
		// 		struct evPositionData *data; // $v0
		/* end block 1.1 */
		// End offset: 0x8009B190
		// End Line: 194

		/* begin block 1.2 */
			// Start line: 201
			// Start offset: 0x8009B1A4
			// Variables:
		// 		struct evPositionData *data; // $v1

			/* begin block 1.2.1 */
				// Start line: 203
				// Start offset: 0x8009B1A4
				// Variables:
			// 		long _x1; // $a0
			// 		long _y1; // $a2
			// 		long _z1; // $a1
			// 		struct _Vector *_v0; // $v0
			/* end block 1.2.1 */
			// End offset: 0x8009B1A4
			// End Line: 203
		/* end block 1.2 */
		// End offset: 0x8009B1E4
		// End Line: 208
	/* end block 1 */
	// End offset: 0x8009B264
	// End Line: 240

	/* begin block 2 */
		// Start line: 383
	/* end block 2 */
	// End Line: 384

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void DefaultPuppetStateHandler(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *CurrentSection_00;
  undefined *puVar1;
  short *psVar2;
  int Data_00;
  
  Data_00 = Data;
  CurrentSection_00 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (CurrentSection_00 != (__Event *)0x0) {
    puVar1 = (undefined *)CurrentSection_00->ID;
    if (puVar1 == (undefined *)0x40020) {
      if (CurrentSection == 0) {
                    /* WARNING: Subroutine does not return */
        G2Anim_SetSpeedAdjustment
                  ((_G2Anim_Type *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x194),
                   CurrentSection_00->Data);
      }
    }
    else {
      if ((int)puVar1 < 0x40021) {
        if (puVar1 == &DAT_80000020) {
          return;
        }
        if ((int)puVar1 < -0x7fffffdf) {
          if (puVar1 == &DAT_80000008) {
            return;
          }
          if ((int)puVar1 < -0x7ffffff7) {
            if (puVar1 == (undefined *)0x80000000) {
              return;
            }
          }
          else {
            if (puVar1 == &DAT_80000010) {
              return;
            }
          }
        }
        else {
          if (puVar1 == &DAT_0004000b) {
            if (CurrentSection != 0) {
              return;
            }
            *(undefined2 *)(theCamera.core.vvNormalWorVecMat[1].t[0] + 0x78) =
                 *(undefined2 *)(CurrentSection_00->Data + 4);
            return;
          }
          if ((int)puVar1 < 0x4000c) {
            if (puVar1 == &DAT_0004000a) {
              RelocateTerrain((_Terrain *)theCamera.core.vvNormalWorVecMat[1].t[0],
                              (_SVector *)CurrentSection_00->Data);
              return;
            }
          }
          else {
            if (puVar1 == &LAB_0004000c_3) {
              psVar2 = (short *)CurrentSection_00->Data;
              _CHAR____800d55b0 = _CHAR____800d55b0 | 0x10;
              _CHAR____800d55f4 = (int)*psVar2;
              _CHAR____800d55f8 = (int)psVar2[1];
              _CHAR____800d55fc = (int)psVar2[2];
              _BlockVramEntry_800d59a0._12_4_ = _BlockVramEntry_800d59a0._12_4_ | 0x20000;
              return;
            }
          }
        }
      }
      else {
        if (puVar1 == (undefined *)0x1000001) {
          return;
        }
        if ((int)puVar1 < 0x1000002) {
          if (puVar1 == &DAT_00100009) {
            return;
          }
          if ((int)puVar1 < 0x10000a) {
            if (puVar1 == &DAT_00100004) {
              razResetMotion((_Instance *)theCamera.core.vvNormalWorVecMat[1].t[0]);
              return;
            }
          }
          else {
            if (puVar1 == (undefined *)0x800027) {
              StateHandlerWarpGate(In,(int)CurrentSection_00,Data_00);
              return;
            }
          }
        }
        else {
          if (puVar1 == (undefined *)0x8000000) {
            return;
          }
          if ((int)puVar1 < 0x8000001) {
            if (puVar1 == (undefined *)0x4010200) {
              return;
            }
          }
          else {
            if (puVar1 == (undefined *)0x10002001) {
              razSpectralShift();
              return;
            }
            if (puVar1 == (undefined *)0x10002002) {
              razMaterialShift();
              return;
            }
          }
        }
      }
      DefaultStateHandler(In,CurrentSection,Data);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerWarpGate(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s4*/)
 // line 243, offset 0x8009b27c
	/* begin block 1 */
		// Start line: 244
		// Start offset: 0x8009B27C
		// Variables:
	// 		struct __Event *Ptr; // $v0
	// 		int anim; // $s3

		/* begin block 1.1 */
			// Start line: 289
			// Start offset: 0x8009B58C
			// Variables:
		// 		struct _Instance *heldInst; // $v0
		/* end block 1.1 */
		// End offset: 0x8009B5E0
		// End Line: 296

		/* begin block 1.2 */
			// Start line: 302
			// Start offset: 0x8009B614
		/* end block 1.2 */
		// End offset: 0x8009B614
		// End Line: 302
	/* end block 1 */
	// End offset: 0x8009B6F0
	// End Line: 344

	/* begin block 2 */
		// Start line: 527
	/* end block 2 */
	// End Line: 528

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerWarpGate(__CharacterState *In,int CurrentSection,int Data)

{
  undefined *puVar1;
  int iVar2;
  __Event *p_Var3;
  _Instance *Inst;
  undefined *puVar4;
  int in_a3;
  __State *p_Var5;
  
  iVar2 = G2EmulationQueryAnimation(In,CurrentSection);
  p_Var5 = In->SectionList + CurrentSection;
  theCamera.positionAccl._4_4_ = theCamera.positionAccl._4_4_ | 4;
  p_Var3 = PeekMessageQueue(&p_Var5->Event);
  if (p_Var3 == (__Event *)0x0) {
    if (CurrentSection == 0) {
      razApplyMotion(In,0);
    }
    return;
  }
  puVar4 = (undefined *)p_Var3->ID;
  if (puVar4 == &DAT_00100004) goto LAB_8009b6d0;
  if ((int)puVar4 < 0x100005) {
    if (puVar4 == &DAT_80000020) goto LAB_8009b6d0;
    if ((int)puVar4 < -0x7fffffdf) {
      if (puVar4 == &DAT_80000008) goto LAB_8009b6d0;
      if (-0x7ffffff8 < (int)puVar4) {
        puVar1 = &DAT_80000010;
        goto joined_r0x8009b3bc;
      }
      if (puVar4 == (undefined *)0x80000000) goto LAB_8009b4e0;
    }
    else {
      if (puVar4 == (undefined *)0x100000) {
        iVar2 = WARPGATE_IsWarpgateActive();
        if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
          EnMessageQueueData(&p_Var5->Defer,0x100000,0);
        }
                    /* WARNING: Subroutine does not return */
        SetPhysicsWallCrawlData(0,0,3,in_a3);
      }
      if ((int)puVar4 < 0x100001) {
        puVar1 = &DAT_00040005;
joined_r0x8009b3bc:
        if (puVar4 == puVar1) goto LAB_8009b6d0;
      }
      else {
        if (puVar4 == &DAT_00100001) {
                    /* WARNING: Subroutine does not return */
          SetPhysicsWallCrawlData(0,0,3,in_a3);
        }
      }
    }
  }
  else {
    if (puVar4 == (undefined *)0x2000000) {
LAB_8009b4e0:
      if (iVar2 != 0x7b) {
                    /* WARNING: Subroutine does not return */
        EnMessageQueueData(&p_Var5->Defer,0x100000,0);
      }
      goto LAB_8009b6d0;
    }
    if ((int)puVar4 < 0x2000001) {
      if (puVar4 == &DAT_00100015) {
        if (CurrentSection == 0) {
                    /* WARNING: Subroutine does not return */
          EnMessageQueueData(&In->SectionList[0].Defer,0x100000,0);
        }
                    /* WARNING: Subroutine does not return */
        SetPhysicsWallCrawlData(0,0,3,in_a3);
      }
      if ((int)puVar4 < 0x100016) {
        puVar1 = &DAT_00100014;
        goto joined_r0x8009b3bc;
      }
      if (puVar4 == (undefined *)0x1000001) goto LAB_8009b6d0;
    }
    else {
      if (puVar4 == (undefined *)0x10000000) {
        if ((CurrentSection == 0) && (iVar2 != 0x7b)) {
          if ((*gameTracker._4_4_ & 4) != 0) {
            WARPGATE_DecrementIndex();
          }
          if ((*gameTracker._4_4_ & 8) != 0) {
            WARPGATE_IncrementIndex();
          }
          if ((*gameTracker._4_4_ & 1) != 0) {
            iVar2 = WARPGATE_IsWarpgateUsable();
            if (iVar2 == 0) {
              if (((_CHAR____800d57c8 & 0x20000) == 0) &&
                 (iVar2 = WARPGATE_IsWarpgateReady(), iVar2 != 0)) {
                LOAD_PlayXA(0xef);
                razSetPlayerEventHistory(0x20000);
              }
            }
            else {
              SetTimer(0x4b);
              Inst = razGetHeldItem();
              if (Inst != (_Instance *)0x0) {
                    /* WARNING: Subroutine does not return */
                INSTANCE_Post(Inst,0x800008,0);
              }
              G2EmulationSwitchAnimationCharacter(In,0x7b,0,6,2);
              iVar2 = WARPGATE_IsWarpgateSpectral();
              if (iVar2 != 0) {
                razSpectralShift();
              }
            }
          }
        }
        goto LAB_8009b6d0;
      }
      if ((int)puVar4 < 0x10000001) {
        if (puVar4 == (undefined *)0x8000000) goto LAB_8009b6d0;
      }
      else {
        if (((int)puVar4 < 0x10002003) && (0x10002000 < (int)puVar4)) goto LAB_8009b6d0;
      }
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
LAB_8009b6d0:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&p_Var5->Event);
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerForcedGlide(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s7*/)
 // line 348, offset 0x8009b710
	/* begin block 1 */
		// Start line: 349
		// Start offset: 0x8009B710
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int Anim; // $s6
	// 		int extraProcess; // $s4

		/* begin block 1.1 */
			// Start line: 425
			// Start offset: 0x8009BAA0
		/* end block 1.1 */
		// End offset: 0x8009BAD4
		// End Line: 431
	/* end block 1 */
	// End offset: 0x8009BAD4
	// End Line: 435

	/* begin block 2 */
		// Start line: 741
	/* end block 2 */
	// End Line: 742

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void StateHandlerForcedGlide(__CharacterState *In,int CurrentSection,int Data)

{
  int iVar1;
  __Event *p_Var2;
  undefined *puVar3;
  
  iVar1 = G2EmulationQueryAnimation(In,CurrentSection);
  p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var2 == (__Event *)0x0) {
    if (CurrentSection == 0) {
                    /* WARNING: Subroutine does not return */
      STREAM_GetLevelWithID(In->CharacterInstance->currentStreamUnitID);
    }
    return;
  }
  puVar3 = (undefined *)p_Var2->ID;
  if (puVar3 != (undefined *)0x1000001) {
    if ((int)puVar3 < 0x1000002) {
      if (puVar3 == &DAT_80000020) goto LAB_8009ba80;
      if ((int)puVar3 < -0x7fffffdf) {
        if (puVar3 == &DAT_80000004) goto LAB_8009ba80;
        if ((int)puVar3 < -0x7ffffffb) {
          if (puVar3 == (undefined *)0x80000000) goto LAB_8009ba80;
        }
        else {
          if (puVar3 == &DAT_80000008) goto LAB_8009ba80;
        }
      }
      else {
        if (puVar3 == &DAT_00100001) {
          if (CurrentSection == 0) {
            _CHAR____800d5574 = 0x2000;
            _BlockVramEntry_800d59a0._12_4_ = 0;
            PhysicsMode.next = (_BlockVramEntry *)0x0;
            SteerSwitchMode(In->CharacterInstance,0);
            DeInitAlgorithmicWings(In->CharacterInstance);
            SetExternalTransitionForce
                      ((__Force *)&_BlockVramEntry_800d58c0.type,In->CharacterInstance,4,0,0x18,
                       -0x18);
            theCamera.shake._0_2_ = 0xb;
            theCamera.core.pad6 = -10;
            theCamera.core._222_2_ = 10;
            if (0xffffffe8 < _CHAR____800d57b4) {
              _CHAR____800d57b4 = 0xffffffe8;
            }
          }
                    /* WARNING: Subroutine does not return */
          G2EmulationSwitchAnimation(In,CurrentSection,0x10,p_Var2->Data,5,1);
        }
        if ((int)puVar3 < 0x100002) {
          if (puVar3 == (undefined *)0x100000) {
            SetPhysics(In->CharacterInstance,-0x10,0,0,0);
            iVar1 = razSwitchVAnimCharacterGroup(In->CharacterInstance,0x18,(int *)0x0,(int *)0x0);
            if (iVar1 != 0) {
              G2EmulationSwitchAnimationCharacter(In,0x24,0,4,1);
            }
            StateSwitchStateCharacterData(In,StateHandlerFall,0);
            goto LAB_8009ba80;
          }
        }
        else {
          if (puVar3 == &DAT_00100004) {
            if (CurrentSection == 0) {
              InitAlgorithmicWings(In->CharacterInstance);
              theCamera.shake._0_2_ = 0xb;
              theCamera.core.pad6 = 10;
              theCamera.core._222_2_ = 10;
              _CHAR____800d57b4 = 0xffffffe8;
            }
            goto LAB_8009ba80;
          }
        }
      }
    }
    else {
      if (puVar3 == (undefined *)0x4020000) goto LAB_8009ba80;
      if ((int)puVar3 < 0x4020001) {
        if (puVar3 == (undefined *)0x4000007) goto LAB_8009ba80;
        if ((int)puVar3 < 0x4000008) {
          if (puVar3 == (undefined *)0x4000001) goto LAB_8009ba80;
        }
        else {
          if (puVar3 == (undefined *)0x4010008) {
            StateSwitchStateData(In,CurrentSection,StateHandlerDeCompression,0);
            goto LAB_8009ba80;
          }
        }
      }
      else {
        if (puVar3 == (undefined *)0x10000000) goto LAB_8009ba80;
        if ((int)puVar3 < 0x10000001) {
          if (puVar3 == (undefined *)0x8000000) {
            if (iVar1 == 0x10) {
              G2EmulationSwitchAnimationAlpha(In,CurrentSection,0x11,0,5,1,4);
              SetExternalTransitionForce
                        ((__Force *)&_BlockVramEntry_800d58c0.type,In->CharacterInstance,4,0,0,
                         _CHAR____800d57b4);
            }
            goto LAB_8009ba80;
          }
        }
        else {
          if ((puVar3 == (undefined *)0x20000001) || (puVar3 == (undefined *)0x20000004))
          goto LAB_8009ba80;
        }
      }
    }
    DefaultStateHandler(In,CurrentSection,Data);
  }
LAB_8009ba80:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&In->SectionList[CurrentSection].Event);
}





