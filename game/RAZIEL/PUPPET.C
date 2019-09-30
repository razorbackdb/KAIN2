#include "THISDUST.H"
#include "PUPPET.H"


// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerPuppetShow(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s1*/, int Data /*$s4*/)
 // line 8, offset 0x8009a0d4
	/* begin block 1 */
		// Start line: 9
		// Start offset: 0x8009A0D4
		// Variables:
	// 		struct __Event *Ptr; // $s0

		/* begin block 1.1 */
			// Start line: 37
			// Start offset: 0x8009A280
			// Variables:
		// 		struct evActionPlayHostAnimationData *data; // $v0
		/* end block 1.1 */
		// End offset: 0x8009A280
		// End Line: 39

		/* begin block 1.2 */
			// Start line: 51
			// Start offset: 0x8009A2F0
			// Variables:
		// 		struct evAnimationInstanceSwitchData *data; // $v1
		/* end block 1.2 */
		// End offset: 0x8009A2F0
		// End Line: 53

		/* begin block 1.3 */
			// Start line: 65
			// Start offset: 0x8009A36C
			// Variables:
		// 		struct evPositionData *data; // $v0
		/* end block 1.3 */
		// End offset: 0x8009A36C
		// End Line: 65

		/* begin block 1.4 */
			// Start line: 76
			// Start offset: 0x8009A3B0
			// Variables:
		// 		struct evPositionData *data; // $v0

			/* begin block 1.4.1 */
				// Start line: 76
				// Start offset: 0x8009A3B0
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $a1
			// 		struct _Position *_v0; // $v0
			/* end block 1.4.1 */
			// End offset: 0x8009A3B0
			// End Line: 76
		/* end block 1.4 */
		// End offset: 0x8009A3B0
		// End Line: 76
	/* end block 1 */
	// End offset: 0x8009A430
	// End Line: 96

	/* begin block 2 */
		// Start line: 16
	/* end block 2 */
	// End Line: 17

/* WARNING: Type propagation algorithm not settling */

void StateHandlerPuppetShow(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  _Instance *p_Var2;
  short *psVar3;
  undefined *puVar4;
  int iVar5;
  
  p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var1 == (__Event *)0x0) {
    razApplyMotion(In,CurrentSection);
    return;
  }
  puVar4 = (undefined *)p_Var1->ID;
  if (puVar4 == (undefined *)0x40016) {
                    /* WARNING: Subroutine does not return */
    G2EmulationSwitchAnimation(In,CurrentSection,0x7b,0,4,2);
  }
  if ((int)puVar4 < 0x40017) {
    if (puVar4 == (undefined *)0x4000d) {
      if (CurrentSection == 0) {
        Raziel.puppetRotToPoint.z = *(short *)(p_Var1->Data + 4);
                    /* WARNING: Subroutine does not return */
        SteerSwitchMode(In->CharacterInstance,0xd);
      }
      goto LAB_8009a420;
    }
    if ((int)puVar4 < 0x4000e) {
      if (puVar4 == (undefined *)0x40003) {
        if (CurrentSection == 0) {
          p_Var2 = (_Instance *)p_Var1->Data;
          G2EmulationInstanceToInstanceSwitchAnimationCharacter
                    (*(_Instance **)&p_Var2->node,*(_Instance **)((int)&p_Var2->node + 4),
                     (int)p_Var2->next,(int)p_Var2->prev,(int)p_Var2->instanceID,(int)p_Var2->flags)
          ;
        }
        goto LAB_8009a420;
      }
      if (puVar4 == (undefined *)0x4000c) {
                    /* WARNING: Subroutine does not return */
        StateSwitchStateData(In,CurrentSection,StateHandlerMoveToPosition,p_Var1->Data);
      }
    }
    else {
      if (puVar4 == (undefined *)0x40010) {
        Raziel.Senses.Flags = Raziel.Senses.Flags & 0xffffffef;
        ControlFlag = ControlFlag & 0xfffdffff;
        goto LAB_8009a420;
      }
      if (puVar4 == (undefined *)0x40014) {
                    /* WARNING: Subroutine does not return */
        SetControlInitIdleData(0,0,3);
      }
    }
  }
  else {
    if (puVar4 == &DAT_00100001) {
      if (p_Var1->Data != 0) {
        StateInitIdle(In,CurrentSection,p_Var1->Data);
      }
      Raziel.Mode = 1;
      Raziel.idleCount = 0;
      ControlFlag = 0x1020008;
      PhysicsMode = 0;
                    /* WARNING: Subroutine does not return */
      SteerSwitchMode(In->CharacterInstance,0);
    }
    if ((int)puVar4 < 0x100002) {
      if (puVar4 == (undefined *)0x40018) {
        if (CurrentSection == 0) {
          psVar3 = (short *)p_Var1->Data;
          Raziel.puppetRotToPoint.x = *psVar3;
          Raziel.puppetRotToPoint.y = psVar3[1];
          Raziel.puppetRotToPoint.z = psVar3[2];
                    /* WARNING: Subroutine does not return */
          SteerSwitchMode(In->CharacterInstance,0xc);
        }
        goto LAB_8009a420;
      }
      if (puVar4 == (undefined *)0x40021) {
        Raziel.steeringVelocity = *(short *)&p_Var1->Data;
        goto LAB_8009a420;
      }
    }
    else {
      if (puVar4 == (undefined *)0x4000001) goto LAB_8009a420;
      if ((int)puVar4 < 0x4000002) {
        if (puVar4 == (undefined *)0x1000001) goto LAB_8009a420;
      }
      else {
        if (puVar4 == (undefined *)0x8000008) {
          if (CurrentSection == 0) {
            iVar5 = p_Var1->Data;
                    /* WARNING: Subroutine does not return */
            G2EmulationSwitchAnimationCharacter
                      (In,*(int *)(iVar5 + 4),*(int *)(iVar5 + 8),*(int *)(iVar5 + 0xc),
                       *(int *)(iVar5 + 0x10));
          }
          goto LAB_8009a420;
        }
      }
    }
  }
  DefaultPuppetStateHandler(In,CurrentSection,Data);
LAB_8009a420:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&In->SectionList[CurrentSection].Event);
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerMoveToPosition(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s6*/)
 // line 100, offset 0x8009a45c
	/* begin block 1 */
		// Start line: 101
		// Start offset: 0x8009A45C
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		long distance; // $s0
	// 		int motion; // $v0
	// 		int applyMotion; // $s5

		/* begin block 1.1 */
			// Start line: 111
			// Start offset: 0x8009A56C
			// Variables:
		// 		struct evPositionData *moveToPoint; // $v0

			/* begin block 1.1.1 */
				// Start line: 113
				// Start offset: 0x8009A56C
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $v0
			// 		struct _Position *_v0; // $s3
			/* end block 1.1.1 */
			// End offset: 0x8009A56C
			// End Line: 113
		/* end block 1.1 */
		// End offset: 0x8009A56C
		// End Line: 113

		/* begin block 1.2 */
			// Start line: 132
			// Start offset: 0x8009A608
			// Variables:
		// 		struct evPositionData *moveToPoint; // $v0

			/* begin block 1.2.1 */
				// Start line: 134
				// Start offset: 0x8009A608
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $v0
			/* end block 1.2.1 */
			// End offset: 0x8009A608
			// End Line: 134
		/* end block 1.2 */
		// End offset: 0x8009A62C
		// End Line: 138
	/* end block 1 */
	// End offset: 0x8009A6E8
	// End Line: 172

	/* begin block 2 */
		// Start line: 213
	/* end block 2 */
	// End Line: 214

/* WARNING: Removing unreachable block (ram,0x8009a6e8) */

void StateHandlerMoveToPosition(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  short *psVar2;
  _Instance *p_Var3;
  undefined *puVar4;
  
  p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var1 == (__Event *)0x0) {
    if (CurrentSection == 0) {
      razAlignYRotInterp(In->CharacterInstance,&Raziel.puppetMoveToPoint,'\0',4);
    }
    p_Var3 = In->CharacterInstance;
                    /* WARNING: Subroutine does not return */
    MATH3D_LengthXYZ((int)(p_Var3->position).x - (int)Raziel.puppetMoveToPoint.x,
                     (int)(p_Var3->position).y - (int)Raziel.puppetMoveToPoint.y,
                     (int)(p_Var3->position).z - (int)Raziel.puppetMoveToPoint.z);
  }
  puVar4 = (undefined *)p_Var1->ID;
  if (puVar4 == &DAT_00100001) {
    if (CurrentSection == 0) {
      psVar2 = (short *)p_Var1->Data;
      Raziel.puppetMoveToPoint.x = *psVar2;
      Raziel.puppetMoveToPoint.y = psVar2[1];
      Raziel.puppetMoveToPoint.z = psVar2[2];
      razAlignYRotInterp(In->CharacterInstance,&Raziel.puppetMoveToPoint,'\0',4);
      PhysicsMode = 0;
                    /* WARNING: Subroutine does not return */
      SteerSwitchMode(In->CharacterInstance,0);
    }
  }
  else {
    if ((int)puVar4 < 0x100002) {
      if (puVar4 == (undefined *)0x40016) {
                    /* WARNING: Subroutine does not return */
        G2EmulationSwitchAnimation(In,CurrentSection,0x7b,0,4,2);
      }
      if ((int)puVar4 < 0x40017) {
        if (puVar4 == (undefined *)0x4000c) {
          psVar2 = (short *)p_Var1->Data;
          Raziel.puppetMoveToPoint.x = *psVar2;
          Raziel.puppetMoveToPoint.y = psVar2[1];
          Raziel.puppetMoveToPoint.z = psVar2[2];
          goto LAB_8009a654;
        }
      }
      else {
        if (puVar4 == (undefined *)0x100000) {
                    /* WARNING: Subroutine does not return */
          SetControlInitIdleData(0,0,3);
        }
      }
    }
    else {
      if (puVar4 == (undefined *)0x4000001) {
        PhysicsMode = 0;
        SetDropPhysics(In->CharacterInstance,&Raziel);
        goto LAB_8009a654;
      }
      if ((int)puVar4 < 0x4000002) {
        if (puVar4 == (undefined *)0x1000000) goto LAB_8009a654;
      }
      else {
        if ((puVar4 == (undefined *)0x4010400) || (puVar4 == (undefined *)0x4020000))
        goto LAB_8009a654;
      }
    }
    DefaultPuppetStateHandler(In,CurrentSection,Data);
  }
LAB_8009a654:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&In->SectionList[CurrentSection].Event);
}



// decompiled code
// original method signature: 
// void /*$ra*/ DefaultPuppetStateHandler(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$s2*/)
 // line 172, offset 0x8009a710
	/* begin block 1 */
		// Start line: 173
		// Start offset: 0x8009A710
		// Variables:
	// 		struct __Event *Ptr; // $a2

		/* begin block 1.1 */
			// Start line: 196
			// Start offset: 0x8009A858
			// Variables:
		// 		struct evPositionData *data; // $v0
		/* end block 1.1 */
		// End offset: 0x8009A858
		// End Line: 196

		/* begin block 1.2 */
			// Start line: 203
			// Start offset: 0x8009A86C
			// Variables:
		// 		struct evPositionData *data; // $v1

			/* begin block 1.2.1 */
				// Start line: 205
				// Start offset: 0x8009A86C
				// Variables:
			// 		long _x1; // $a0
			// 		long _y1; // $a2
			// 		long _z1; // $a1
			// 		struct _Vector *_v0; // $v0
			/* end block 1.2.1 */
			// End offset: 0x8009A86C
			// End Line: 205
		/* end block 1.2 */
		// End offset: 0x8009A8B0
		// End Line: 210
	/* end block 1 */
	// End offset: 0x8009A914
	// End Line: 230

	/* begin block 2 */
		// Start line: 379
	/* end block 2 */
	// End Line: 380

void DefaultPuppetStateHandler(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *Data_00;
  undefined *puVar1;
  short *psVar2;
  undefined In_00;
  
  Data_00 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (Data_00 != (__Event *)0x0) {
    puVar1 = (undefined *)Data_00->ID;
    if (puVar1 == (undefined *)0x40020) {
      if (CurrentSection == 0) {
                    /* WARNING: Subroutine does not return */
        G2Anim_SetSpeedAdjustment(&(gameTrackerX.playerInstance)->anim,Data_00->Data);
      }
    }
    else {
      In_00 = SUB41(In,0);
      if ((int)puVar1 < 0x40021) {
        if (puVar1 == (undefined *)0x4000a) {
          STREAM_SetInstancePosition
                    (&gameTrackerX,gameTrackerX.playerInstance,(evPositionData *)Data_00->Data);
        }
        else {
          if ((int)puVar1 < 0x4000b) {
            if ((puVar1 != (undefined *)0x80000000) && (puVar1 != &DAT_80000008)) {
              StateHandlerPuppetShow(In_00,CurrentSection,(int)Data_00);
              return;
            }
          }
          else {
            if (puVar1 == (undefined *)0x4000b) {
              if (CurrentSection == 0) {
                ((gameTrackerX.playerInstance)->rotation).z = *(short *)(Data_00->Data + 4);
              }
            }
            else {
              if (puVar1 != (undefined *)0x4000f) {
                StateHandlerPuppetShow(In_00,CurrentSection,(int)Data_00);
                return;
              }
              psVar2 = (short *)Data_00->Data;
              Raziel.Senses.lookAtPoint.x = (long)*psVar2;
              Raziel.Senses.lookAtPoint.y = (long)psVar2[1];
              Raziel.Senses.lookAtPoint.z = (long)psVar2[2];
              Raziel.Senses.Flags = Raziel.Senses.Flags | 0x10;
              ControlFlag = ControlFlag | 0x20000;
            }
          }
        }
      }
      else {
        if (puVar1 != (undefined *)0x1000001) {
          if ((int)puVar1 < 0x1000002) {
            if (puVar1 == &DAT_00100004) {
              razResetMotion(gameTrackerX.playerInstance);
            }
            else {
              if (puVar1 != (undefined *)0x800027) {
                StateHandlerPuppetShow(In_00,CurrentSection,(int)Data_00);
                return;
              }
              if (Data == 0) {
                ControlFlag = ControlFlag & 0xfffffff7;
              }
              else {
                ControlFlag = ControlFlag | 8;
              }
            }
          }
          else {
            if ((puVar1 != (undefined *)0x4010200) && (puVar1 != (undefined *)0x8000000)) {
              DefaultStateHandler(In,CurrentSection,Data);
            }
          }
        }
      }
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerWarpGate(struct __CharacterState *In /*$s0*/, int CurrentSection /*$s1*/, int Data /*$s4*/)
 // line 233, offset 0x8009a92c
	/* begin block 1 */
		// Start line: 234
		// Start offset: 0x8009A92C
		// Variables:
	// 		struct __Event *Ptr; // $v0
	// 		int anim; // $s3

		/* begin block 1.1 */
			// Start line: 276
			// Start offset: 0x8009AC30
			// Variables:
		// 		struct _Instance *heldInst; // $v0
		/* end block 1.1 */
		// End offset: 0x8009AC84
		// End Line: 283

		/* begin block 1.2 */
			// Start line: 288
			// Start offset: 0x8009ACA8
		/* end block 1.2 */
		// End offset: 0x8009ACA8
		// End Line: 288
	/* end block 1 */
	// End offset: 0x8009AD84
	// End Line: 329

	/* begin block 2 */
		// Start line: 507
	/* end block 2 */
	// End Line: 508

void StateHandlerWarpGate(__CharacterState *In,int CurrentSection,int Data)

{
  undefined *puVar1;
  int iVar2;
  __Event *p_Var3;
  _Instance *Inst;
  undefined *puVar4;
  __State *p_Var5;
  
  iVar2 = G2EmulationQueryAnimation(In,CurrentSection);
  p_Var5 = In->SectionList + CurrentSection;
  p_Var3 = PeekMessageQueue(&p_Var5->Event);
  if (p_Var3 == (__Event *)0x0) {
    if (CurrentSection == 0) {
      razApplyMotion(In,0);
    }
    return;
  }
  puVar4 = (undefined *)p_Var3->ID;
  if (puVar4 == &DAT_00100004) goto LAB_8009ad64;
  if ((int)puVar4 < 0x100005) {
    if (puVar4 == &DAT_80000020) goto LAB_8009ad64;
    if ((int)puVar4 < -0x7fffffdf) {
      if (puVar4 == &DAT_80000008) goto LAB_8009ad64;
      if (-0x7ffffff8 < (int)puVar4) {
        puVar1 = &DAT_80000010;
        goto joined_r0x8009aa60;
      }
      if (puVar4 == (undefined *)0x80000000) goto LAB_8009ab84;
    }
    else {
      if (puVar4 == (undefined *)0x100000) {
        iVar2 = WARPGATE_IsWarpgateActive();
        if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
          EnMessageQueueData(&p_Var5->Defer,0x100000,0);
        }
                    /* WARNING: Subroutine does not return */
        SetControlInitIdleData(0,0,3);
      }
      if ((int)puVar4 < 0x100001) {
        if (puVar4 == (undefined *)0x40005) goto LAB_8009ad64;
      }
      else {
        if (puVar4 == &DAT_00100001) {
                    /* WARNING: Subroutine does not return */
          SetControlInitIdleData(0,0,3);
        }
      }
    }
  }
  else {
    if (puVar4 == (undefined *)0x2000000) {
LAB_8009ab84:
      if (iVar2 != 0x7b) {
                    /* WARNING: Subroutine does not return */
        EnMessageQueueData(&p_Var5->Defer,0x100000,0);
      }
      goto LAB_8009ad64;
    }
    if ((int)puVar4 < 0x2000001) {
      if (puVar4 == &DAT_00100015) {
        if (CurrentSection == 0) {
                    /* WARNING: Subroutine does not return */
          EnMessageQueueData(&In->SectionList[0].Defer,0x100000,0);
        }
                    /* WARNING: Subroutine does not return */
        SetControlInitIdleData(0,0,3);
      }
      if ((int)puVar4 < 0x100016) {
        puVar1 = &DAT_00100014;
joined_r0x8009aa60:
        if (puVar4 == puVar1) goto LAB_8009ad64;
      }
      else {
        if (puVar4 == (undefined *)0x1000001) goto LAB_8009ad64;
      }
    }
    else {
      if (puVar4 == (undefined *)0x10000000) {
        if ((CurrentSection == 0) && (iVar2 != 0x7b)) {
          if ((*PadData & 4U) != 0) {
            WARPGATE_IncrementIndex();
          }
          if ((*PadData & 8U) != 0) {
            WARPGATE_DecrementIndex();
          }
          if ((*PadData & 1U) != 0) {
            iVar2 = WARPGATE_IsWarpgateUsable();
            if (iVar2 != 0) {
              SetTimer(0x4b);
              Inst = razGetHeldItem();
              if (Inst != (_Instance *)0x0) {
                    /* WARNING: Subroutine does not return */
                INSTANCE_Post(Inst,0x800008,0);
              }
                    /* WARNING: Subroutine does not return */
              G2EmulationSwitchAnimationCharacter(In,0x7b,0,6,2);
            }
            if ((Raziel.playerEventHistory & 0x20000) == 0) {
              LOAD_PlayXA(0xef);
              razSetPlayerEventHistory(0x20000);
            }
          }
        }
        goto LAB_8009ad64;
      }
      if ((int)puVar4 < 0x10000001) {
        if (puVar4 == (undefined *)0x8000000) goto LAB_8009ad64;
      }
      else {
        if (((int)puVar4 < 0x10002003) && (0x10002000 < (int)puVar4)) goto LAB_8009ad64;
      }
    }
  }
  DefaultStateHandler(In,CurrentSection,Data);
LAB_8009ad64:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&p_Var5->Event);
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerForcedGlide(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s6*/)
 // line 333, offset 0x8009ada4
	/* begin block 1 */
		// Start line: 334
		// Start offset: 0x8009ADA4
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int Anim; // $s5

		/* begin block 1.1 */
			// Start line: 342
			// Start offset: 0x8009ADE0
		/* end block 1.1 */
		// End offset: 0x8009AE18
		// End Line: 348
	/* end block 1 */
	// End offset: 0x8009B15C
	// End Line: 415

	/* begin block 2 */
		// Start line: 707
	/* end block 2 */
	// End Line: 708

void StateHandlerForcedGlide(__CharacterState *In,int CurrentSection,int Data)

{
  int iVar1;
  __Event *p_Var2;
  undefined *puVar3;
  
  iVar1 = G2EmulationQueryAnimation(In,CurrentSection);
  if (CurrentSection == 0) {
                    /* WARNING: Subroutine does not return */
    STREAM_GetLevelWithID(In->CharacterInstance->currentStreamUnitID);
  }
  p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  if (p_Var2 == (__Event *)0x0) {
    return;
  }
  puVar3 = (undefined *)p_Var2->ID;
  if (puVar3 != (undefined *)0x1000001) {
    if ((int)puVar3 < 0x1000002) {
      if (puVar3 == &DAT_80000020) goto LAB_8009b14c;
      if ((int)puVar3 < -0x7fffffdf) {
        if (puVar3 == &DAT_80000004) goto LAB_8009b14c;
        if ((int)puVar3 < -0x7ffffffb) {
          if (puVar3 == (undefined *)0x80000000) goto LAB_8009b14c;
        }
        else {
          if (puVar3 == &DAT_80000008) goto LAB_8009b14c;
        }
      }
      else {
        if (puVar3 == &DAT_00100001) {
          if (CurrentSection != 0) {
                    /* WARNING: Subroutine does not return */
            G2EmulationSwitchAnimation(In,CurrentSection,0x10,p_Var2->Data,5,1);
          }
          Raziel.Mode = 0x2000;
          ControlFlag = 0;
          PhysicsMode = 0;
                    /* WARNING: Subroutine does not return */
          SteerSwitchMode(In->CharacterInstance,0);
        }
        if ((int)puVar3 < 0x100002) {
          if (puVar3 == (undefined *)0x100000) {
            SetPhysics(In->CharacterInstance,-0x10,0,0,0);
            iVar1 = razSwitchVAnimCharacterGroup(In->CharacterInstance,0x18,(int *)0x0,(int *)0x0);
            if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
              G2EmulationSwitchAnimationCharacter(In,0x24,0,4,1);
            }
            StateSwitchStateCharacterData(In,StateHandlerFall,0);
            goto LAB_8009b14c;
          }
        }
        else {
          if (puVar3 == &DAT_00100004) {
            if (CurrentSection == 0) {
              InitAlgorithmicWings(In->CharacterInstance);
              gameTrackerX.wipeType = 0xb;
              gameTrackerX.wipeTime = 10;
              gameTrackerX.maxWipeTime = 10;
              Raziel.forcedGlideSpeed = 0xffffffe8;
            }
            goto LAB_8009b14c;
          }
        }
      }
    }
    else {
      if (puVar3 == (undefined *)0x4020000) goto LAB_8009b14c;
      if ((int)puVar3 < 0x4020001) {
        if (puVar3 == (undefined *)0x4000007) goto LAB_8009b14c;
        if ((int)puVar3 < 0x4000008) {
          if (puVar3 == (undefined *)0x4000001) goto LAB_8009b14c;
        }
        else {
          if (puVar3 == (undefined *)0x4010008) {
                    /* WARNING: Subroutine does not return */
            StateSwitchStateData(In,CurrentSection,StateHandlerDeCompression,0);
          }
        }
      }
      else {
        if (puVar3 == (undefined *)0x10000000) goto LAB_8009b14c;
        if ((int)puVar3 < 0x10000001) {
          if (puVar3 == (undefined *)0x8000000) {
            if (iVar1 == 0x10) {
              G2EmulationSwitchAnimationAlpha(In,CurrentSection,0x11,0,5,1,4);
              SetExternalTransitionForce
                        (&ExternalForces,In->CharacterInstance,4,0,0,Raziel.forcedGlideSpeed);
            }
            goto LAB_8009b14c;
          }
        }
        else {
          if ((puVar3 == (undefined *)0x20000001) || (puVar3 == (undefined *)0x20000004))
          goto LAB_8009b14c;
        }
      }
    }
    DefaultStateHandler(In,CurrentSection,Data);
  }
LAB_8009b14c:
                    /* WARNING: Subroutine does not return */
  DeMessageQueue(&In->SectionList[CurrentSection].Event);
}





