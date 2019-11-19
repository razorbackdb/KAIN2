#include "THISDUST.H"
#include "PUPPET.H"


// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerPuppetShow(struct __CharacterState *In /*$s2*/, int CurrentSection /*$s1*/, int Data /*$s4*/)
 // line 8, offset 0x800983c0
	/* begin block 1 */
		// Start line: 9
		// Start offset: 0x800983C0
		// Variables:
	// 		struct __Event *Ptr; // $s0

		/* begin block 1.1 */
			// Start line: 37
			// Start offset: 0x8009856C
			// Variables:
		// 		struct evActionPlayHostAnimationData *data; // $v0
		/* end block 1.1 */
		// End offset: 0x8009856C
		// End Line: 39

		/* begin block 1.2 */
			// Start line: 51
			// Start offset: 0x800985DC
			// Variables:
		// 		struct evAnimationInstanceSwitchData *data; // $v1
		/* end block 1.2 */
		// End offset: 0x800985DC
		// End Line: 53

		/* begin block 1.3 */
			// Start line: 65
			// Start offset: 0x80098658
			// Variables:
		// 		struct evPositionData *data; // $v0
		/* end block 1.3 */
		// End offset: 0x80098658
		// End Line: 65

		/* begin block 1.4 */
			// Start line: 76
			// Start offset: 0x8009869C
			// Variables:
		// 		struct evPositionData *data; // $v0

			/* begin block 1.4.1 */
				// Start line: 76
				// Start offset: 0x8009869C
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $a1
			// 		struct _Position *_v0; // $v0
			/* end block 1.4.1 */
			// End offset: 0x8009869C
			// End Line: 76
		/* end block 1.4 */
		// End offset: 0x8009869C
		// End Line: 76
	/* end block 1 */
	// End offset: 0x8009871C
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
  undefined2 *puVar3;
  int Ptr;
  
  do {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0) {
      razApplyMotion(In,CurrentSection);
      return;
    }
    Ptr = p_Var1->ID;
    if (Ptr == 0x40016) {
      G2EmulationSwitchAnimation(In,CurrentSection,0x7c,0,4,2);
LAB_80098630:
      StateSwitchStateData(In,CurrentSection,StateHandlerMoveToPosition,p_Var1->Data);
    }
    else {
      if (Ptr < 0x40017) {
        if (Ptr == 0x4000d) {
          if (CurrentSection == 0) {
            Raziel.padCommands.Queue[7].ID._2_2_ = *(undefined2 *)(p_Var1->Data + 4);
            SteerSwitchMode(In->CharacterInstance,0xd);
          }
        }
        else {
          if (Ptr < 0x4000e) {
            if (Ptr != 0x40003) {
              if (Ptr == 0x4000c) goto LAB_80098630;
              goto LAB_80098704;
            }
            if (CurrentSection == 0) {
              p_Var2 = (_Instance *)p_Var1->Data;
              G2EmulationInstanceToInstanceSwitchAnimationCharacter
                        (*(_Instance **)&p_Var2->node,*(_Instance **)((int)&p_Var2->node + 4),
                         (int)p_Var2->next,(int)p_Var2->prev,(int)p_Var2->instanceID,
                         (int)p_Var2->flags);
            }
          }
          else {
            if (Ptr == 0x40010) {
              Raziel.Senses.Flags = Raziel.Senses.Flags & 0xffffffef;
              ControlFlag = ControlFlag & 0xfffdffff;
            }
            else {
              if (Ptr != 0x40014) goto LAB_80098704;
              Ptr = SetControlInitIdleData(0,0,3);
              StateInitIdle(In,CurrentSection,Ptr);
            }
          }
        }
      }
      else {
        if (Ptr == 0x100001) {
          if (p_Var1->Data != 0) {
            StateInitIdle(In,CurrentSection,p_Var1->Data);
          }
          Raziel.Mode = 1;
          Raziel.idleCount = 0;
          ControlFlag = 0x1020008;
          PhysicsMode = 0;
          SteerSwitchMode(In->CharacterInstance,0);
          ResetPhysics(In->CharacterInstance,-0x10);
          Raziel.movementMinRate = 0;
          if (CurrentSection == 0) {
            Raziel.constrictGoodCircle = 0;
          }
        }
        else {
          if (Ptr < 0x100002) {
            if (Ptr == 0x40018) {
              if (CurrentSection == 0) {
                puVar3 = (undefined2 *)p_Var1->Data;
                Raziel.padCommands.Queue[6].Data._2_2_ = *puVar3;
                Raziel.padCommands.Queue[7].ID._0_2_ = puVar3[1];
                Raziel.padCommands.Queue[7].ID._2_2_ = puVar3[2];
                SteerSwitchMode(In->CharacterInstance,0xc);
              }
            }
            else {
              if (Ptr != 0x40021) goto LAB_80098704;
              Raziel.steeringVelocity = *(short *)&p_Var1->Data;
            }
          }
          else {
            if (Ptr != 0x4000001) {
              if (Ptr < 0x4000002) {
                if (Ptr != 0x1000001) {
LAB_80098704:
                  DefaultPuppetStateHandler(In,CurrentSection,Data);
                }
              }
              else {
                if (Ptr != 0x8000008) goto LAB_80098704;
                if (CurrentSection == 0) {
                  Ptr = p_Var1->Data;
                  G2EmulationSwitchAnimationCharacter
                            (In,*(int *)(Ptr + 4),*(int *)(Ptr + 8),*(int *)(Ptr + 0xc),
                             *(int *)(Ptr + 0x10));
                }
              }
            }
          }
        }
      }
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerMoveToPosition(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s6*/)
 // line 100, offset 0x80098748
	/* begin block 1 */
		// Start line: 101
		// Start offset: 0x80098748
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		long distance; // $s0
	// 		int motion; // $v0
	// 		int applyMotion; // $s5

		/* begin block 1.1 */
			// Start line: 111
			// Start offset: 0x80098858
			// Variables:
		// 		struct evPositionData *moveToPoint; // $v0

			/* begin block 1.1.1 */
				// Start line: 113
				// Start offset: 0x80098858
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $v0
			// 		struct _Position *_v0; // $s3
			/* end block 1.1.1 */
			// End offset: 0x80098858
			// End Line: 113
		/* end block 1.1 */
		// End offset: 0x80098858
		// End Line: 113

		/* begin block 1.2 */
			// Start line: 132
			// Start offset: 0x800988F4
			// Variables:
		// 		struct evPositionData *moveToPoint; // $v0

			/* begin block 1.2.1 */
				// Start line: 134
				// Start offset: 0x800988F4
				// Variables:
			// 		short _x1; // $v1
			// 		short _y1; // $a0
			// 		short _z1; // $v0
			/* end block 1.2.1 */
			// End offset: 0x800988F4
			// End Line: 134
		/* end block 1.2 */
		// End offset: 0x80098918
		// End Line: 138
	/* end block 1 */
	// End offset: 0x800989D4
	// End Line: 172

	/* begin block 2 */
		// Start line: 213
	/* end block 2 */
	// End Line: 214

void StateHandlerMoveToPosition(__CharacterState *In,int CurrentSection,int Data)

{
  bool bVar1;
  __Event *p_Var2;
  short *psVar3;
  _Instance *p_Var4;
  long lVar5;
  int Data_00;
  
  bVar1 = true;
  do {
    p_Var2 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var2 == (__Event *)0x0) {
      if (bVar1) {
        if (CurrentSection == 0) {
          razAlignYRotInterp(In->CharacterInstance,(_Position *)(Raziel.padCommands.Queue + 6),'\0',
                             4);
        }
        p_Var4 = In->CharacterInstance;
        lVar5 = MATH3D_LengthXYZ((int)(p_Var4->position).x -
                                 (int)(short)Raziel.padCommands.Queue[6].ID,
                                 (int)(p_Var4->position).y -
                                 (int)Raziel.padCommands.Queue[6].ID._2_2_,
                                 (int)(p_Var4->position).z -
                                 (int)(short)Raziel.padCommands.Queue[6].Data);
        Data_00 = razApplyMotion(In,CurrentSection);
        if ((CurrentSection == 0) && (lVar5 < Data_00 << 1)) {
          INSTANCE_Post(In->CharacterInstance,0x100000,0);
        }
      }
      return;
    }
    Data_00 = p_Var2->ID;
    if (Data_00 == 0x100001) {
      if (CurrentSection == 0) {
        psVar3 = (short *)p_Var2->Data;
        Raziel.padCommands.Queue[6].ID._0_2_ = *psVar3;
        Raziel.padCommands.Queue[6].ID._2_2_ = psVar3[1];
        Raziel.padCommands.Queue[6].Data._0_2_ = psVar3[2];
        razAlignYRotInterp(In->CharacterInstance,(_Position *)(Raziel.padCommands.Queue + 6),'\0',4)
        ;
        PhysicsMode = 0;
        SteerSwitchMode(In->CharacterInstance,0);
      }
    }
    else {
      if (Data_00 < 0x100002) {
        if (Data_00 == 0x40016) {
          G2EmulationSwitchAnimation(In,CurrentSection,0x7c,0,4,2);
LAB_800988f4:
          psVar3 = (short *)p_Var2->Data;
          Raziel.padCommands.Queue[6].ID._0_2_ = *psVar3;
          Raziel.padCommands.Queue[6].ID._2_2_ = psVar3[1];
          Raziel.padCommands.Queue[6].Data._0_2_ = psVar3[2];
        }
        else {
          if (Data_00 < 0x40017) {
            if (Data_00 == 0x4000c) goto LAB_800988f4;
          }
          else {
            if (Data_00 == 0x100000) {
              Data_00 = SetControlInitIdleData(0,0,3);
              StateSwitchStateData(In,CurrentSection,StateHandlerPuppetShow,Data_00);
              bVar1 = false;
              goto LAB_80098940;
            }
          }
LAB_80098938:
          DefaultPuppetStateHandler(In,CurrentSection,Data);
        }
      }
      else {
        if (Data_00 == 0x4000001) {
          PhysicsMode = 0;
          SetDropPhysics(In->CharacterInstance,&Raziel);
        }
        else {
          if (Data_00 < 0x4000002) {
            if (Data_00 != 0x1000000) goto LAB_80098938;
          }
          else {
            if ((Data_00 != 0x4010400) && (Data_00 != 0x4020000)) goto LAB_80098938;
          }
        }
      }
    }
LAB_80098940:
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ DefaultPuppetStateHandler(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$s2*/)
 // line 172, offset 0x800989fc
	/* begin block 1 */
		// Start line: 173
		// Start offset: 0x800989FC
		// Variables:
	// 		struct __Event *Ptr; // $a2

		/* begin block 1.1 */
			// Start line: 196
			// Start offset: 0x80098B88
			// Variables:
		// 		struct evPositionData *data; // $v0

			/* begin block 1.1.1 */
				// Start line: 196
				// Start offset: 0x80098B88
				// Variables:
			// 		short _x1; // $a0
			// 		short _y1; // $a1
			// 		short _z1; // $v0
			// 		struct _Rotation *_v0; // $v1
			/* end block 1.1.1 */
			// End offset: 0x80098B88
			// End Line: 196
		/* end block 1.1 */
		// End offset: 0x80098B88
		// End Line: 196

		/* begin block 1.2 */
			// Start line: 202
			// Start offset: 0x80098BB0
			// Variables:
		// 		struct evPositionData *data; // $v1

			/* begin block 1.2.1 */
				// Start line: 204
				// Start offset: 0x80098BB0
				// Variables:
			// 		long _x1; // $a0
			// 		long _y1; // $a2
			// 		long _z1; // $a1
			// 		struct _Vector *_v0; // $v0
			/* end block 1.2.1 */
			// End offset: 0x80098BB0
			// End Line: 204
		/* end block 1.2 */
		// End offset: 0x80098BF4
		// End Line: 209
	/* end block 1 */
	// End offset: 0x80098C58
	// End Line: 228

	/* begin block 2 */
		// Start line: 379
	/* end block 2 */
	// End Line: 380

void DefaultPuppetStateHandler(__CharacterState *In,int CurrentSection,int Data)

{
  short sVar1;
  short sVar2;
  _Instance *p_Var3;
  __Event *p_Var4;
  int Data_00;
  undefined *puVar5;
  short *psVar6;
  
  p_Var4 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
  p_Var3 = gameTrackerX.playerInstance;
  if (p_Var4 != (__Event *)0x0) {
    puVar5 = (undefined *)p_Var4->ID;
    if (puVar5 == (undefined *)0x4000f) {
      psVar6 = (short *)p_Var4->Data;
      Raziel.Senses.lookAtPoint.x = (long)*psVar6;
      Raziel.Senses.lookAtPoint.y = (long)psVar6[1];
      Raziel.Senses.lookAtPoint.z = (long)psVar6[2];
      Raziel.Senses.Flags = Raziel.Senses.Flags | 0x10;
      ControlFlag = ControlFlag | 0x20000;
    }
    else {
      if ((int)puVar5 < 0x40010) {
        if (puVar5 == (undefined *)0x4000a) {
          STREAM_SetInstancePosition
                    (&gameTrackerX,gameTrackerX.playerInstance,(evPositionData *)p_Var4->Data);
          return;
        }
        if ((int)puVar5 < 0x4000b) {
          if (puVar5 == (undefined *)0x80000000) {
            return;
          }
          if (puVar5 == &DAT_80000008) {
            return;
          }
        }
        else {
          if (puVar5 == (undefined *)0x4000b) {
            if (CurrentSection != 0) {
              return;
            }
            psVar6 = (short *)p_Var4->Data;
            sVar1 = psVar6[1];
            sVar2 = psVar6[2];
            ((gameTrackerX.playerInstance)->rotation).x = *psVar6;
            (p_Var3->rotation).y = sVar1;
            (p_Var3->rotation).z = sVar2;
            return;
          }
          if (puVar5 == (undefined *)0x4000e) {
            if (p_Var4->Data != 0) {
              return;
            }
            Data_00 = SetControlInitIdleData(0,0,3);
            StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Data_00);
            GAMELOOP_Set24FPS();
            return;
          }
        }
      }
      else {
        if (puVar5 == (undefined *)0x800027) {
          if (Data != 0) {
            ControlFlag = ControlFlag | 8;
            return;
          }
          ControlFlag = ControlFlag & 0xfffffff7;
          return;
        }
        if ((int)puVar5 < 0x800028) {
          if (puVar5 == (undefined *)0x40020) {
            if (CurrentSection != 0) {
              return;
            }
            G2Anim_SetSpeedAdjustment(&(gameTrackerX.playerInstance)->anim,p_Var4->Data);
            return;
          }
          if (puVar5 == (undefined *)0x100004) {
            razResetMotion(gameTrackerX.playerInstance);
            return;
          }
        }
        else {
          if (puVar5 == (undefined *)0x1000001) {
            return;
          }
          if (puVar5 == (undefined *)0x8000000) {
            return;
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
// void /*$ra*/ StateHandlerWarpGate(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s0*/, int Data /*$s3*/)
 // line 231, offset 0x80098c70
	/* begin block 1 */
		// Start line: 232
		// Start offset: 0x80098C70
		// Variables:
	// 		struct __Event *Ptr; // $v0
	/* end block 1 */
	// End offset: 0x80098E6C
	// End Line: 275

	/* begin block 2 */
		// Start line: 503
	/* end block 2 */
	// End Line: 504

void StateHandlerWarpGate(__CharacterState *In,int CurrentSection,int Data)

{
  __Event *p_Var1;
  int Ptr;
  
  do {
    p_Var1 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var1 == (__Event *)0x0) {
      return;
    }
    Ptr = p_Var1->ID;
    if (Ptr != 0x1000001) {
      if (Ptr < 0x1000002) {
        if (Ptr == 0x100001) {
          Ptr = SetControlInitIdleData(0,0,3);
          StateInitIdle(In,CurrentSection,Ptr);
          ControlFlag = 0x20008;
          Raziel.Mode = -0x80000000;
          PhysicsMode = 3;
          Raziel.idleCount = 0;
          if (CurrentSection == 0) {
            Raziel.padCommands.Queue[7].ID._2_2_ =
                 ((Raziel.Senses.EngagedList[0xe].instance)->rotation).z;
            SteerSwitchMode(In->CharacterInstance,0xd);
            razSetPlayerEventHistory(0x800);
          }
        }
        else {
          if (Ptr < 0x100002) {
            if (Ptr != -0x80000000) goto LAB_80098e54;
LAB_80098dcc:
            Ptr = SetControlInitIdleData(0,0,3);
            StateSwitchStateData(In,CurrentSection,StateHandlerIdle,Ptr);
          }
          else {
            if (Ptr != 0x100004) goto LAB_80098e54;
          }
        }
      }
      else {
        if (Ptr != 0x8000000) {
          if (Ptr < 0x8000001) {
            if (Ptr == 0x2000000) goto LAB_80098dcc;
          }
          else {
            if (Ptr == 0x10000000) {
              if (CurrentSection == 0) {
                if ((*PadData & 4U) != 0) {
                  WARPGATE_IncrementIndex();
                }
                if ((*PadData & 8U) != 0) {
                  WARPGATE_DecrementIndex();
                }
              }
              goto LAB_80098e5c;
            }
          }
LAB_80098e54:
          DefaultStateHandler(In,CurrentSection,Data);
        }
      }
    }
LAB_80098e5c:
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}



// decompiled code
// original method signature: 
// void /*$ra*/ StateHandlerForcedGlide(struct __CharacterState *In /*$s1*/, int CurrentSection /*$s2*/, int Data /*$s6*/)
 // line 279, offset 0x80098e88
	/* begin block 1 */
		// Start line: 280
		// Start offset: 0x80098E88
		// Variables:
	// 		struct __Event *Ptr; // $s0
	// 		int Anim; // $s5

		/* begin block 1.1 */
			// Start line: 288
			// Start offset: 0x80098EC4
		/* end block 1.1 */
		// End offset: 0x80098EFC
		// End Line: 294
	/* end block 1 */
	// End offset: 0x80099240
	// End Line: 361

	/* begin block 2 */
		// Start line: 605
	/* end block 2 */
	// End Line: 606

void StateHandlerForcedGlide(__CharacterState *In,int CurrentSection,int Data)

{
  int iVar1;
  Level *pLVar2;
  __Event *p_Var3;
  int iVar4;
  undefined *puVar5;
  
  iVar1 = G2EmulationQueryAnimation(In,CurrentSection);
  if ((CurrentSection == 0) &&
     (pLVar2 = STREAM_GetLevelWithID(In->CharacterInstance->currentStreamUnitID),
     (pLVar2->unitFlags & 0x1000U) == 0)) {
    EnMessageQueueData(&In->SectionList[0].Event,0x100000,0);
  }
  do {
    p_Var3 = PeekMessageQueue(&In->SectionList[CurrentSection].Event);
    if (p_Var3 == (__Event *)0x0) {
      return;
    }
    puVar5 = (undefined *)p_Var3->ID;
    if (puVar5 != (undefined *)0x1000001) {
      if ((int)puVar5 < 0x1000002) {
        if (puVar5 != &DAT_80000020) {
          if ((int)puVar5 < -0x7fffffdf) {
            if (puVar5 != &DAT_80000004) {
              if ((int)puVar5 < -0x7ffffffb) {
                if (puVar5 != (undefined *)0x80000000) {
LAB_80099228:
                  DefaultStateHandler(In,CurrentSection,Data);
                }
              }
              else {
                if (puVar5 != &DAT_80000008) goto LAB_80099228;
              }
            }
          }
          else {
            if (puVar5 == (undefined *)0x100001) {
              if (CurrentSection == 0) {
                Raziel.Mode = 0x2000;
                ControlFlag = 0;
                PhysicsMode = 0;
                SteerSwitchMode(In->CharacterInstance,0);
                DeInitAlgorithmicWings(In->CharacterInstance);
                SetExternalTransitionForce(&ExternalForces,In->CharacterInstance,4,0,0x18,-0x18);
                gameTrackerX.wipeType = 0xb;
                gameTrackerX.wipeTime = -10;
                gameTrackerX.maxWipeTime = 10;
                if (0xffffffe8 < (uint)Raziel.padCommands.Queue[10].ID) {
                  Raziel.padCommands.Queue[10].ID = -0x18;
                }
              }
              G2EmulationSwitchAnimation(In,CurrentSection,0x10,p_Var3->Data,5,1);
            }
            else {
              if ((int)puVar5 < 0x100002) {
                if (puVar5 != (undefined *)0x100000) goto LAB_80099228;
                SetPhysics(In->CharacterInstance,-0x10,0,0,0);
                iVar4 = razSwitchVAnimCharacterGroup
                                  (In->CharacterInstance,0x18,(int *)0x0,(int *)0x0);
                if (iVar4 != 0) {
                  G2EmulationSwitchAnimationCharacter(In,0x24,0,4,1);
                }
                StateSwitchStateCharacterData(In,StateHandlerFall,0);
              }
              else {
                if (puVar5 != (undefined *)0x100004) goto LAB_80099228;
                if (CurrentSection == 0) {
                  InitAlgorithmicWings(In->CharacterInstance);
                  gameTrackerX.wipeType = 0xb;
                  gameTrackerX.wipeTime = 10;
                  gameTrackerX.maxWipeTime = 10;
                  Raziel.padCommands.Queue[10].ID = -0x18;
                }
              }
            }
          }
        }
      }
      else {
        if (puVar5 != (undefined *)0x4020000) {
          if ((int)puVar5 < 0x4020001) {
            if (puVar5 != (undefined *)0x4000007) {
              if ((int)puVar5 < 0x4000008) {
                if (puVar5 != (undefined *)0x4000001) goto LAB_80099228;
              }
              else {
                if (puVar5 != (undefined *)0x4010008) goto LAB_80099228;
                StateSwitchStateData(In,CurrentSection,StateHandlerDeCompression,0);
              }
            }
          }
          else {
            if (puVar5 != (undefined *)0x10000000) {
              if ((int)puVar5 < 0x10000001) {
                if (puVar5 != (undefined *)0x8000000) goto LAB_80099228;
                if (iVar1 == 0x10) {
                  G2EmulationSwitchAnimationAlpha(In,CurrentSection,0x11,0,5,1,4);
                  SetExternalTransitionForce
                            (&ExternalForces,In->CharacterInstance,4,0,0,
                             Raziel.padCommands.Queue[10].ID);
                }
              }
              else {
                if ((puVar5 != (undefined *)0x20000001) && (puVar5 != (undefined *)0x20000004))
                goto LAB_80099228;
              }
            }
          }
        }
      }
    }
    DeMessageQueue(&In->SectionList[CurrentSection].Event);
  } while( true );
}





