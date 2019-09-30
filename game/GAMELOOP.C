#include "THISDUST.H"
#include "GAMELOOP.H"


// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_AllocStaticMemory()
 // line 139, offset 0x8002d6f8
	/* begin block 1 */
		// Start line: 278
	/* end block 1 */
	// End Line: 279

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_AllocStaticMemory(void)

{
                    /* WARNING: Subroutine does not return */
  MEMPACK_Malloc(0x10c,'\x06');
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_InitGameTracker()
 // line 185, offset 0x8002d7e8
	/* begin block 1 */
		// Start line: 186
		// Start offset: 0x8002D7E8

		/* begin block 1.1 */
			// Start line: 186
			// Start offset: 0x8002D7E8
			// Variables:
		// 		int i; // $t4
		/* end block 1.1 */
		// End offset: 0x8002D8C0
		// End Line: 260
	/* end block 1 */
	// End offset: 0x8002D8C0
	// End Line: 266

	/* begin block 2 */
		// Start line: 404
	/* end block 2 */
	// End Line: 405

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_InitGameTracker(void)

{
  int iVar1;
  int iVar2;
  
  gameTrackerX.GlobalObjects = GlobalObjects;
  gameTrackerX.planningPool = planningPool;
  gameTrackerX.enemyPlanPool = enemyPlanPool;
  gameTrackerX.vertexPool = gVertexPool;
  primPool2->lastPrim = primPool2->prim + 0x5db4;
  gameTrackerX.instanceList = instanceList;
  PTR_800d1d24->lastPrim = PTR_800d1d24->prim + 0x5db4;
  gameTrackerX.lightInfo = gLightInfo;
  primPool2->nextPrim = primPool2->prim;
  gameTrackerX.instancePool = instancePool;
  PTR_800d1d24->nextPrim = PTR_800d1d24->prim;
  iVar2 = 0;
  iVar1 = 0;
  gameTrackerX.multGameTime = 10;
  gameTrackerX.material_fadeValue = 0x1000;
  gameTrackerX.spectral_fadeValue = 0;
  gameTrackerX.decoupleGame = 1;
  gameTrackerX.frameRateLock = 1;
  gameTrackerX.primPool = primPool2;
  gameTrackerX.drawOT = gOt2;
  gameTrackerX.dispOT = PTR_800d1d1c;
  gameTrackerX.frameRate24fps = 1;
  do {
    iVar2 = iVar2 + 1;
    *(undefined2 *)((int)&(gameTrackerX.GlobalObjects)->objectStatus + iVar1) = 0;
    iVar1 = iVar1 + 0x24;
  } while (iVar2 < 0x30);
  gameTrackerX.gameData.asmData.MorphTime = 1000;
  OBTABLE_ClearObjectReferences();
  EVENT_Init();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_SystemInit(struct GameTracker *gameTracker /*$a0*/)
 // line 281, offset 0x8002d8e8
	/* begin block 1 */
		// Start line: 796
	/* end block 1 */
	// End Line: 797

void GAMELOOP_SystemInit(GameTracker *gameTracker)

{
  GAMELOOP_AllocStaticMemory();
  INSTANCE_InitInstanceList(instanceList,instancePool);
  GAMELOOP_InitGameTracker();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_ResetGameStates()
 // line 294, offset 0x8002d920
	/* begin block 1 */
		// Start line: 822
	/* end block 1 */
	// End Line: 823

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ResetGameStates(void)

{
  EVENT_Init();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_ClearGameTracker()
 // line 300, offset 0x8002d940
	/* begin block 1 */
		// Start line: 834
	/* end block 1 */
	// End Line: 835

	/* begin block 2 */
		// Start line: 845
	/* end block 2 */
	// End Line: 846

void GAMELOOP_ClearGameTracker(void)

{
  gameTrackerX.gameData.asmData.drawBackFaces = 0;
  gameTrackerX.gameData.asmData.MorphTime = 1000;
  gameTrackerX.frameCount = 0;
  gameTrackerX.fps30Count = 0;
  gameTrackerX.gameFlags = 0;
  gameTrackerX.currentHotSpot = 0;
  gameTrackerX.SwitchToNewStreamUnit = 0;
  gameTrackerX.currentTime = 0;
  gameTrackerX.currentTicks = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_CalcGameTime()
 // line 323, offset 0x8002d970
	/* begin block 1 */
		// Start line: 325
		// Start offset: 0x8002D970
		// Variables:
	// 		long time; // $a1
	/* end block 1 */
	// End offset: 0x8002D970
	// End Line: 329

	/* begin block 2 */
		// Start line: 890
	/* end block 2 */
	// End Line: 891

	/* begin block 3 */
		// Start line: 891
	/* end block 3 */
	// End Line: 892

	/* begin block 4 */
		// Start line: 895
	/* end block 4 */
	// End Line: 896

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_CalcGameTime(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (gameTrackerX.currentTimeOfDayTime * gameTrackerX.multGameTime) / 60000 + 0x2d0;
  iVar1 = iVar2 / 0x3c;
  gameTrackerX.timeOfDay =
       (short)iVar1 * 0x28 +
       ((short)(iVar1 / 6 + (iVar1 >> 0x1f) >> 2) - (short)(iVar1 >> 0x1f)) * -0x960 + (short)iVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_SetGameTime(long timeOfDay /*$a1*/)
 // line 334, offset 0x8002da1c
	/* begin block 1 */
		// Start line: 335
		// Start offset: 0x8002DA1C
		// Variables:
	// 		long tim; // $v1
	/* end block 1 */
	// End offset: 0x8002DA74
	// End Line: 341

	/* begin block 2 */
		// Start line: 914
	/* end block 2 */
	// End Line: 915

void GAMELOOP_SetGameTime(long timeOfDay)

{
  int iVar1;
  int iVar2;
  
  iVar1 = timeOfDay + (timeOfDay / 100) * -0x28;
  iVar2 = iVar1 + -0x2d0;
  if (iVar2 < 0) {
    iVar2 = iVar1 + 0x2d0;
  }
  gameTrackerX.currentMaterialTime = (iVar2 * 60000) / gameTrackerX.multGameTime;
  gameTrackerX.timeOfDay = (short)timeOfDay;
  gameTrackerX.currentTimeOfDayTime = gameTrackerX.currentMaterialTime;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GAMELOOP_GetTimeOfDay()
 // line 351, offset 0x8002dab0
	/* begin block 1 */
		// Start line: 353
		// Start offset: 0x8002DAB0
		// Variables:
	// 		int timeOfDay; // $v1
	/* end block 1 */
	// End offset: 0x8002DAF4
	// End Line: 378

	/* begin block 2 */
		// Start line: 951
	/* end block 2 */
	// End Line: 952

	/* begin block 3 */
		// Start line: 952
	/* end block 3 */
	// End Line: 953

	/* begin block 4 */
		// Start line: 954
	/* end block 4 */
	// End Line: 955

/* WARNING: Unknown calling convention yet parameter storage is locked */

int GAMELOOP_GetTimeOfDay(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)gameTrackerX.timeOfDay;
  if (iVar2 - 0x259U < 99) {
    return 600;
  }
  iVar1 = 700;
  if ((1099 < iVar2 - 700U) && (iVar1 = 0x708, 99 < iVar2 - 0x708U)) {
    return 0x76c;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GAMELOOP_GetTimeOfDayIdx(int timeOfDay /*$a0*/)
 // line 380, offset 0x8002dafc
	/* begin block 1 */
		// Start line: 1019
	/* end block 1 */
	// End Line: 1020

	/* begin block 2 */
		// Start line: 1021
	/* end block 2 */
	// End Line: 1022

int GAMELOOP_GetTimeOfDayIdx(int timeOfDay)

{
  int iVar1;
  
  if (timeOfDay - 0x259U < 99) {
    return 1;
  }
  iVar1 = 2;
  if ((1099 < timeOfDay - 700U) && (iVar1 = 3, 99 < timeOfDay - 0x708U)) {
    return 0;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GAMELOOP_WaitForLoad()
 // line 808, offset 0x8002db40
	/* begin block 1 */
		// Start line: 1477
	/* end block 1 */
	// End Line: 1478

	/* begin block 2 */
		// Start line: 1885
	/* end block 2 */
	// End Line: 1886

int GAMELOOP_WaitForLoad(void)

{
  if ((gameTrackerX.debugFlags & 0x80000U) != 0) {
    VOICEXA_Tick();
  }
                    /* WARNING: Subroutine does not return */
  STREAM_PollLoadQueue();
}



// decompiled code
// original method signature: 
// struct _StreamUnit * /*$ra*/ LoadLevels(char *baseAreaName /*$s2*/, struct GameTracker *gameTracker /*$s3*/)
 // line 825, offset 0x8002db78
	/* begin block 1 */
		// Start line: 826
		// Start offset: 0x8002DB78
		// Variables:
	// 		struct _SVector offset; // stack offset -32
	// 		struct _StreamUnit *streamUnit; // $s0
	// 		static char oldArea[16]; // offset 0xc

		/* begin block 1.1 */
			// Start line: 844
			// Start offset: 0x8002DBFC
			// Variables:
		// 		int num; // $v0
		// 		int waitFor; // $s1
		/* end block 1.1 */
		// End offset: 0x8002DC68
		// End Line: 865

		/* begin block 1.2 */
			// Start line: 888
			// Start offset: 0x8002DCE0
			// Variables:
		// 		short _x0; // $a3
		// 		short _y0; // $t0
		// 		short _z0; // $v0
		// 		short _x1; // $v1
		// 		short _y1; // $t2
		// 		short _z1; // $t1
		// 		struct _SVector *_v; // $a2
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $t1
		/* end block 1.2 */
		// End offset: 0x8002DCE0
		// End Line: 888
	/* end block 1 */
	// End offset: 0x8002DCE0
	// End Line: 892

	/* begin block 2 */
		// Start line: 1919
	/* end block 2 */
	// End Line: 1920

_StreamUnit * LoadLevels(char *baseAreaName,GameTracker *gameTracker)

{
                    /* WARNING: Subroutine does not return */
  strlen("");
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_InitStandardObjects()
 // line 897, offset 0x8002dd74
	/* begin block 1 */
		// Start line: 898
		// Start offset: 0x8002DD74
		// Variables:
	// 		static char (*sobjects[10]); // offset 0x0
	// 		int i; // $s1
	/* end block 1 */
	// End offset: 0x8002DDB8
	// End Line: 913

	/* begin block 2 */
		// Start line: 2080
	/* end block 2 */
	// End Line: 2081

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_InitStandardObjects(void)

{
  char *name;
  undefined **ppuVar1;
  uint uVar2;
  
  LOAD_DumpCurrentDir();
  uVar2 = 0;
  ppuVar1 = &PTR_s_raziel_800c8e94;
  do {
    name = *ppuVar1;
    ppuVar1 = ppuVar1 + 1;
    uVar2 = uVar2 + 1;
    InsertGlobalObject(name,&gameTrackerX);
  } while (uVar2 < 10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_LevelLoadAndInit(char *baseAreaName /*$s0*/, struct GameTracker *gameTracker /*$s3*/)
 // line 916, offset 0x8002ddcc
	/* begin block 1 */
		// Start line: 917
		// Start offset: 0x8002DDCC
		// Variables:
	// 		long i; // $s1
	// 		struct _StreamUnit *streamUnit; // $s2

		/* begin block 1.1 */
			// Start line: 995
			// Start offset: 0x8002DEFC
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $a0
		// 		short _z1; // $v1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v1
		/* end block 1.1 */
		// End offset: 0x8002DEFC
		// End Line: 995
	/* end block 1 */
	// End offset: 0x8002E0D4
	// End Line: 1098

	/* begin block 2 */
		// Start line: 2122
	/* end block 2 */
	// End Line: 2123

void GAMELOOP_LevelLoadAndInit(char *baseAreaName,GameTracker *gameTracker)

{
  _InstanceList *list;
  _InstancePool *pool;
  
  G2Anim_ResetInternalState();
  pool = instancePool;
  list = instanceList;
  gameTracker->playerInstance = (_Instance *)0x0;
  INSTANCE_InitInstanceList(list,pool);
  GAMELOOP_ClearGameTracker();
  CAMERA_Initialize(&theCamera);
  PLANAPI_InitPlanning(planningPool);
  ENMYPLAN_InitEnemyPlanPool(enemyPlanPool);
  FX_Init(fxTracker);
  WARPGATE_Init();
  DRAW_InitShadow();
  GAMELOOP_InitStandardObjects();
  LoadLevels(baseAreaName,gameTracker);
                    /* WARNING: Subroutine does not return */
  STREAM_PollLoadQueue();
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_StreamLevelLoadAndInit(char *baseAreaName /*$a0*/, struct GameTracker *gameTracker /*$a1*/, int toSignalNum /*$a2*/, int fromSignalNum /*$a3*/)
 // line 1101, offset 0x8002e0f0
	/* begin block 1 */
		// Start line: 1102
		// Start offset: 0x8002E0F0
	/* end block 1 */
	// End offset: 0x8002E0F0
	// End Line: 1102

	/* begin block 2 */
		// Start line: 2556
	/* end block 2 */
	// End Line: 2557

void GAMELOOP_StreamLevelLoadAndInit
               (char *baseAreaName,GameTracker *gameTracker,int toSignalNum,int fromSignalNum)

{
  LoadLevels(baseAreaName,gameTracker);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_SetScreenWipe(int time /*$a0*/, int maxTime /*$a1*/, int type /*$a2*/)
 // line 1120, offset 0x8002e110
	/* begin block 1 */
		// Start line: 2594
	/* end block 1 */
	// End Line: 2595

	/* begin block 2 */
		// Start line: 2595
	/* end block 2 */
	// End Line: 2596

void GAMELOOP_SetScreenWipe(int time,int maxTime,int type)

{
  gameTrackerX.wipeTime = (short)time;
  gameTrackerX.maxWipeTime = (short)maxTime;
  gameTrackerX.wipeType = (short)type;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_HandleScreenWipes(unsigned long **drawot /*$s4*/)
 // line 1128, offset 0x8002e124
	/* begin block 1 */
		// Start line: 1129
		// Start offset: 0x8002E124
		// Variables:
	// 		long temp; // $s0
	// 		struct _PrimPool *primPool; // $s3
	/* end block 1 */
	// End offset: 0x8002E570
	// End Line: 1477

	/* begin block 2 */
		// Start line: 2610
	/* end block 2 */
	// End Line: 2611

	/* begin block 3 */
		// Start line: 2625
	/* end block 3 */
	// End Line: 2626

void GAMELOOP_HandleScreenWipes(ulong **drawot)

{
  _PrimPool *primPool;
  int r;
  
  primPool = gameTrackerX.primPool;
  if ((GlobalSave->flags & 1U) != 0) {
    DRAW_FlatQuad(&gameTrackerX.wipeColor,0,0,0x200,0,0,0x1e,0x200,0x1e,gameTrackerX.primPool,drawot
                 );
    DRAW_FlatQuad(&gameTrackerX.wipeColor,0,0xd2,0x200,0xd2,0,0xf0,0x200,0xf0,primPool,drawot);
  }
  r = (int)gameTrackerX.wipeTime;
  if (r < 1) {
    if (r < -1) {
      if (gameTrackerX.wipeType == 10) {
        r = (int)(short)((((int)gameTrackerX.maxWipeTime + r + 2) * 0xff) /
                        (int)gameTrackerX.maxWipeTime);
                    /* WARNING: Subroutine does not return */
        DRAW_TranslucentQuad(0,0,0x200,0,0,0xf0,0x200,0xf0,r,r,r,2,primPool,drawot);
      }
      if (gameTrackerX.wipeType == 0xb) {
        r = (int)(short)((((int)gameTrackerX.maxWipeTime + r) * 0xff) /
                        (int)gameTrackerX.maxWipeTime);
                    /* WARNING: Subroutine does not return */
        DRAW_TranslucentQuad(0,0,0x200,0,0,0x1e,0x200,0x1e,r,r,r,2,primPool,drawot);
      }
      if (gameTrackerX.gameFramePassed != 0) {
        gameTrackerX.wipeTime = gameTrackerX.wipeTime + 1;
      }
    }
    else {
      if (r == -1) {
        if (gameTrackerX.wipeType == 0xb) {
          GlobalSave->flags = GlobalSave->flags | 1;
        }
        else {
          DRAW_FlatQuad(&gameTrackerX.wipeColor,0,0,0x200,0,0,0xf0,0x200,0xf0,primPool,drawot);
        }
      }
      else {
        theCamera.core.screenScale.z = 0x1000;
        theCamera.core.screenScale.y = 0x1000;
        theCamera.core.screenScale.x = 0x1000;
      }
    }
  }
  else {
    if (gameTrackerX.wipeType == 10) {
      r = (int)(short)((r * 0xff) / (int)gameTrackerX.maxWipeTime);
                    /* WARNING: Subroutine does not return */
      DRAW_TranslucentQuad(0,0,0x200,0,0,0xf0,0x200,0xf0,r,r,r,2,primPool,drawot);
    }
    if (gameTrackerX.wipeType == 0xb) {
      r = (int)(short)((r * 0xff) / (int)gameTrackerX.maxWipeTime);
                    /* WARNING: Subroutine does not return */
      DRAW_TranslucentQuad(0,0,0x200,0,0,0x1e,0x200,0x1e,r,r,r,2,primPool,drawot);
    }
    if (gameTrackerX.gameFramePassed != 0) {
      gameTrackerX.wipeTime = gameTrackerX.wipeTime + -1;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ UpdateFogSettings(struct _StreamUnit *currentUnit /*$s2*/, struct Level *level /*$s0*/)
 // line 1620, offset 0x8002e590
	/* begin block 1 */
		// Start line: 1621
		// Start offset: 0x8002E590
		// Variables:
	// 		int changed; // $a2
	// 		int setflag; // $s1
	// 		int FogFar; // $a1
	// 		int FogNear; // $a0
	/* end block 1 */
	// End offset: 0x8002E6A0
	// End Line: 1668

	/* begin block 2 */
		// Start line: 3611
	/* end block 2 */
	// End Line: 3612

void UpdateFogSettings(_StreamUnit *currentUnit,Level *level)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  bVar4 = false;
  uVar1 = currentUnit->TargetFogNear;
  iVar6 = (int)(short)uVar1;
  uVar5 = (uint)level->fogNear;
  uVar2 = currentUnit->TargetFogFar;
  iVar7 = (int)(short)uVar2;
  if (iVar6 < (int)uVar5) {
    level->fogNear = (ushort)(uVar5 - 500);
    bVar3 = iVar6 < (int)(uVar5 - 500 & 0xffff);
LAB_8002e5fc:
    bVar4 = true;
    if (!bVar3) {
      level->fogNear = uVar1;
      UpdateFogSettings((char)uVar1,(char)uVar2);
      return;
    }
  }
  else {
    if ((int)uVar5 < iVar6) {
      level->fogNear = (ushort)(uVar5 + 500);
      bVar3 = (int)(uVar5 + 500 & 0xffff) < iVar6;
      goto LAB_8002e5fc;
    }
  }
  uVar5 = (uint)level->fogFar;
  if (iVar7 < (int)uVar5) {
    level->fogFar = (ushort)(uVar5 - 500);
    bVar4 = true;
    if (iVar7 < (int)(uVar5 - 500 & 0xffff)) goto LAB_8002e670;
  }
  else {
    if (iVar7 <= (int)uVar5) goto LAB_8002e670;
    level->fogFar = (ushort)(uVar5 + 500);
    bVar4 = true;
    if ((int)(uVar5 + 500 & 0xffff) < iVar7) goto LAB_8002e670;
  }
  bVar4 = true;
  level->fogFar = uVar2;
LAB_8002e670:
  if (!bVar4) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  LIGHT_CalcDQPTable(level);
}



// decompiled code
// original method signature: 
// int /*$ra*/ CheckForNoBlend(struct _ColorType *Color /*$a0*/)
 // line 1670, offset 0x8002e6b8
	/* begin block 1 */
		// Start line: 3722
	/* end block 1 */
	// End Line: 3723

	/* begin block 2 */
		// Start line: 3723
	/* end block 2 */
	// End Line: 3724

int CheckForNoBlend(_ColorType *Color)

{
  int iVar1;
  
  iVar1 = 0;
  if (((Color->r < 5) && (iVar1 = 0, Color->g < 5)) && (iVar1 = 1, 4 < Color->b)) {
    iVar1 = 0;
  }
  return iVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ BlendToColor(struct _ColorType *target /*$s1*/, struct _ColorType *current /*$a1*/, struct _ColorType *dest /*$s0*/)
 // line 1680, offset 0x8002e700
	/* begin block 1 */
		// Start line: 3742
	/* end block 1 */
	// End Line: 3743

void BlendToColor(_ColorType *target,_ColorType *current,_ColorType *dest)

{
                    /* WARNING: Subroutine does not return */
  LoadAverageCol((byte *)target,(byte *)current,0x200,0xe00,(undefined *)dest);
}



// decompiled code
// original method signature: 
// void /*$ra*/ MainRenderLevel(struct _StreamUnit *currentUnit /*$s7*/, unsigned long **drawot /*$fp*/)
 // line 1697, offset 0x8002e7f4
	/* begin block 1 */
		// Start line: 1698
		// Start offset: 0x8002E7F4
		// Variables:
	// 		struct Level *level; // $s0
	// 		struct GameTracker *gameTracker; // $s5
	// 		struct _Terrain *terrain; // $s4
	// 		int curTree; // $s1
	// 		long BackColor; // stack offset -48
	// 		struct _Position cam_pos_save; // stack offset -96
	// 		struct MATRIX cam_mat_save; // stack offset -88
	// 		struct _Instance *saveLightInstance; // $s2

		/* begin block 1.1 */
			// Start line: 1750
			// Start offset: 0x8002E8D0
			// Variables:
		// 		int time; // $a2
		/* end block 1.1 */
		// End offset: 0x8002E904
		// End Line: 1756

		/* begin block 1.2 */
			// Start line: 1764
			// Start offset: 0x8002E950
			// Variables:
		// 		int tod; // $v1
		/* end block 1.2 */
		// End offset: 0x8002E9CC
		// End Line: 1778

		/* begin block 1.3 */
			// Start line: 1853
			// Start offset: 0x8002EB38
			// Variables:
		// 		struct _SVector tmp; // stack offset -56
		// 		struct BSPTree *bsp; // $s0
		/* end block 1.3 */
		// End offset: 0x8002EC30
		// End Line: 1910
	/* end block 1 */
	// End offset: 0x8002ED24
	// End Line: 1930

	/* begin block 2 */
		// Start line: 3777
	/* end block 2 */
	// End Line: 3778

/* WARNING: This function may have set the stack pointer */
/* WARNING: Could not reconcile some variable overlaps */

void MainRenderLevel(_StreamUnit *currentUnit,ulong **drawot)

{
  MATRIX *pMVar1;
  LightInfo *lightInfo;
  ushort uVar2;
  int unitID;
  uint uVar3;
  Level *level;
  int iVar4;
  int iVar5;
  _Terrain *terrain;
  undefined4 local_60;
  short local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  long local_44;
  long local_40;
  long local_3c;
  short local_38;
  short local_36;
  short local_34;
  _ColorType local_30 [2];
  
  level = currentUnit->level;
  terrain = level->terrain;
  UpdateFogSettings(currentUnit,level);
  currentUnit->FrameCount = gameTrackerX.displayFrameCount;
  SetFogNearFar((uint)level->fogNear,(uint)level->fogFar,0x140);
  SetFarColor(0,0,0);
  clearRect.r0 = level->backColorR;
                    /* WARNING: Read-only address (ram,0x800d20ac) is written */
  clearRect.g0 = level->backColorG;
                    /* WARNING: Read-only address (ram,0x800d20ad) is written */
  clearRect.b0 = level->backColorB;
                    /* WARNING: Read-only address (ram,0x800d20ae) is written */
  BLK_FILL_800d20b8.r0 = level->backColorR;
  BLK_FILL_800d20b8.g0 = level->backColorG;
  BLK_FILL_800d20b8.b0 = level->backColorB;
  if ((int)gameTrackerX.gameData.asmData.MorphTime != 1000) {
    unitID = ((int)gameTrackerX.gameData.asmData.MorphTime << 0xc) / 1000;
    if (gameTrackerX.gameData.asmData.MorphType == 1) {
      unitID = 0x1000 - unitID;
    }
                    /* WARNING: Subroutine does not return */
    LoadAverageCol(&level->specturalColorR,&level->backColorR,unitID,0x1000 - unitID,
                   (undefined *)local_30);
  }
  if (gameTrackerX.gameData.asmData.MorphType == 1) {
    local_30[0] = *(_ColorType *)&level->specturalColorR;
  }
  else {
    local_30[0] = *(_ColorType *)&level->backColorR;
  }
  BlendToColor(local_30,(_ColorType *)&currentUnit->FogColor,(_ColorType *)&currentUnit->FogColor);
  depthQBackColor = currentUnit->FogColor;
  unitID = GAMELOOP_GetTimeOfDay();
  if ((((unitID != 600) && (unitID != 0x708)) || ((level->unitFlags & 2U) == 0)) &&
     (gameTrackerX.gameData.asmData.MorphTime == 1000)) {
    depthQBackColor = depthQBackColor & 0xfff8f8f8 | 0x40404;
  }
  depthQFogStart = (uint)level->fogNear;
  depthQFogFar = (uint)level->fogFar;
  unitID = CheckForNoBlend((_ColorType *)&depthQBackColor);
  depthQBlendStart = 0xffff;
  if (unitID == 0) {
    depthQBlendStart = depthQFogStart;
  }
                    /* WARNING: Read-only address (ram,0x800d20ac) is written */
  clearRect.r0 = (uchar)depthQBackColor;
                    /* WARNING: Read-only address (ram,0x800d20ad) is written */
  clearRect.g0 = depthQBackColor._1_1_;
                    /* WARNING: Read-only address (ram,0x800d20ae) is written */
  clearRect.b0 = depthQBackColor._2_1_;
  BLK_FILL_800d20b8.r0 = (uchar)depthQBackColor;
  BLK_FILL_800d20b8.g0 = depthQBackColor._1_1_;
  BLK_FILL_800d20b8.b0 = depthQBackColor._2_1_;
  PIPE3D_AnimateTerrainTextures
            (terrain->aniList,gameTrackerX.frameCount,gameTrackerX.primPool,drawot);
  PIPE3D_AnimateTerrainTextures
            (level->bgAniList,gameTrackerX.frameCount,gameTrackerX.primPool,drawot);
  unitID = 0;
  LIGHT_Restore(gLightInfo);
  lightInfo = gLightInfo;
  gLightInfo->numSavedColors = 0;
  LIGHT_ClassifySources((_CameraCore_Type *)&theCamera,level,lightInfo);
  LIGHT_SourcesAndInstances(gLightInfo,gameTrackerX.instanceList);
  LIGHT_SourcesAndTerrain(gLightInfo,terrain);
  PIPE3D_InstanceListTransformAndDraw
            (currentUnit,&gameTrackerX,drawot,(_CameraCore_Type *)&theCamera);
  lightInfo = gLightInfo;
  pMVar1 = theCamera.core.wcTransform;
  local_60 = theCamera.core.position._0_4_;
  local_5c = theCamera.core.position.z;
  local_58 = *(undefined4 *)(theCamera.core.wcTransform)->m;
  local_54 = *(undefined4 *)((theCamera.core.wcTransform)->m + 2);
  local_50 = *(undefined4 *)((theCamera.core.wcTransform)->m + 4);
  local_4c = *(undefined4 *)((theCamera.core.wcTransform)->m + 6);
  local_48 = *(undefined4 *)((theCamera.core.wcTransform)->m + 8);
  local_44 = (theCamera.core.wcTransform)->t[0];
  local_40 = (theCamera.core.wcTransform)->t[1];
  local_3c = (theCamera.core.wcTransform)->t[2];
  iVar5 = 0;
  if (0 < terrain->numBSPTrees) {
    do {
      iVar4 = (int)&terrain->BSPTreeArray->bspRoot + iVar5;
      if ((-1 < *(short *)(iVar4 + 0x1a)) && ((*(ushort *)(iVar4 + 0x12) & 1) == 0)) {
        if ((*(ushort *)(iVar4 + 0x12) & 0x40) != 0) {
          gameTrackerX.gameData.asmData.lightInstances[0].lightInstance = (_Instance *)0x0;
        }
        local_60._2_2_ = (short)(theCamera.core.position._0_4_ >> 0x10);
        uVar3 = (theCamera.core.position._0_4_ & 0xffff) - (uint)*(ushort *)(iVar4 + 0xc);
        local_38 = -(short)uVar3;
        uVar2 = local_60._2_2_ - *(short *)(iVar4 + 0xe);
        theCamera.core.position._0_4_ = uVar3 & 0xffff | (uint)uVar2 << 0x10;
        local_36 = -uVar2;
        theCamera.core.position.z = theCamera.core.position.z - *(short *)(iVar4 + 0x10);
        local_34 = -theCamera.core.position.z;
                    /* WARNING: Subroutine does not return */
        ApplyMatrix(&local_58,&local_38,(theCamera.core.wcTransform)->t);
      }
      unitID = unitID + 1;
      iVar5 = iVar5 + 0x24;
    } while (unitID < terrain->numBSPTrees);
  }
  unitID = (int)RENDER_currentStreamUnitID;
  *(undefined4 *)(theCamera.core.wcTransform)->m = local_58;
  *(undefined4 *)(pMVar1->m + 2) = local_54;
  *(undefined4 *)(pMVar1->m + 4) = local_50;
  *(undefined4 *)(pMVar1->m + 6) = local_4c;
  *(undefined4 *)(pMVar1->m + 8) = local_48;
  pMVar1->t[0] = local_44;
  pMVar1->t[1] = local_40;
  pMVar1->t[2] = local_3c;
  SBSP_IntroduceInstancesAndLights(terrain,(_CameraCore_Type *)&theCamera,lightInfo,unitID);
  StackSave = (ulong)&stack0xffffff88;
  FX_DrawList(fxTracker,&gameTrackerX,gameTrackerX.drawOT,theCamera.core.wcTransform);
  if ((gameTrackerX.playerInstance)->currentStreamUnitID == currentUnit->StreamUnitID) {
    FX_DrawReaver(gameTrackerX.primPool,gameTrackerX.drawOT,theCamera.core.wcTransform);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StreamIntroInstancesForUnit(struct _StreamUnit *currentUnit /*$a1*/)
 // line 1937, offset 0x8002ed64
	/* begin block 1 */
		// Start line: 1938
		// Start offset: 0x8002ED64
	/* end block 1 */
	// End offset: 0x8002ED94
	// End Line: 1950

	/* begin block 2 */
		// Start line: 4417
	/* end block 2 */
	// End Line: 4418

void StreamIntroInstancesForUnit(_StreamUnit *currentUnit)

{
  if (currentUnit->used == 2) {
    SBSP_IntroduceInstances(currentUnit->level->terrain,currentUnit->StreamUnitID);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ StreamRenderLevel(struct _StreamUnit *currentUnit /*$s7*/, struct Level *mainLevel /*$a1*/, unsigned long **drawot /*$s6*/, long portalFogColor /*$s0*/)
 // line 1954, offset 0x8002eda4
	/* begin block 1 */
		// Start line: 1955
		// Start offset: 0x8002EDA4
		// Variables:
	// 		struct GameTracker *gameTracker; // $s4
	// 		struct Level *level; // $s1
	// 		struct _Terrain *terrain; // $s2
	// 		int curTree; // $s1
	// 		int farplanesave; // $fp
	// 		struct _Position cam_pos_save; // stack offset -88
	// 		struct MATRIX cam_mat_save; // stack offset -80

		/* begin block 1.1 */
			// Start line: 2037
			// Start offset: 0x8002EF3C
			// Variables:
		// 		struct _SVector tmp; // stack offset -48
		// 		struct BSPTree *bsp; // $s0
		/* end block 1.1 */
		// End offset: 0x8002F008
		// End Line: 2085

		/* begin block 1.2 */
			// Start line: 2103
			// Start offset: 0x8002F0BC
		/* end block 1.2 */
		// End offset: 0x8002F0F8
		// End Line: 2113
	/* end block 1 */
	// End offset: 0x8002F0F8
	// End Line: 2115

	/* begin block 2 */
		// Start line: 4451
	/* end block 2 */
	// End Line: 4452

/* WARNING: This function may have set the stack pointer */
/* WARNING: Could not reconcile some variable overlaps */

long StreamRenderLevel(_StreamUnit *currentUnit,Level *mainLevel,ulong **drawot,long portalFogColor)

{
  MATRIX *pMVar1;
  long lVar2;
  LightInfo *lightInfo;
  int unitID;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  Level *level;
  _Terrain *terrain;
  int iVar6;
  undefined auStack112 [24];
  undefined4 local_58;
  short local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  long local_3c;
  long local_38;
  long local_34;
  short local_30;
  short local_2e;
  short local_2c;
  
  lVar2 = theCamera.core.farPlane;
  level = currentUnit->level;
  terrain = level->terrain;
  SetFarColor(0,0,0);
  UpdateFogSettings(currentUnit,level);
  depthQFogFar = (uint)level->fogFar;
  depthQFogStart = (uint)level->fogNear;
  depthQBackColor = portalFogColor;
  currentUnit->FogColor = portalFogColor;
  theCamera.core.farPlane = depthQFogFar;
  unitID = CheckForNoBlend((_ColorType *)&depthQBackColor);
  depthQBlendStart = 0xffff;
  if (unitID == 0) {
    depthQBlendStart = depthQFogStart;
  }
  SetFogNearFar(depthQFogStart,depthQFogFar,0x140);
  PIPE3D_AnimateTerrainTextures
            (terrain->aniList,gameTrackerX.frameCount,gameTrackerX.primPool,drawot);
  PIPE3D_AnimateTerrainTextures
            (level->bgAniList,gameTrackerX.frameCount,gameTrackerX.primPool,drawot);
  LIGHT_ClassifySources((_CameraCore_Type *)&theCamera,level,gLightInfo);
  LIGHT_SourcesAndTerrain(gLightInfo,terrain);
  PIPE3D_InstanceListTransformAndDraw
            (currentUnit,&gameTrackerX,drawot,(_CameraCore_Type *)&theCamera);
  lightInfo = gLightInfo;
  pMVar1 = theCamera.core.wcTransform;
  local_58 = theCamera.core.position._0_4_;
  local_54 = theCamera.core.position.z;
  local_50 = *(undefined4 *)(theCamera.core.wcTransform)->m;
  local_4c = *(undefined4 *)((theCamera.core.wcTransform)->m + 2);
  local_48 = *(undefined4 *)((theCamera.core.wcTransform)->m + 4);
  local_44 = *(undefined4 *)((theCamera.core.wcTransform)->m + 6);
  local_40 = *(undefined4 *)((theCamera.core.wcTransform)->m + 8);
  local_3c = (theCamera.core.wcTransform)->t[0];
  local_38 = (theCamera.core.wcTransform)->t[1];
  local_34 = (theCamera.core.wcTransform)->t[2];
  unitID = 0;
  if (0 < terrain->numBSPTrees) {
    iVar6 = 0;
    do {
      iVar5 = (int)&terrain->BSPTreeArray->bspRoot + iVar6;
      if ((-1 < *(short *)(iVar5 + 0x1a)) && ((*(ushort *)(iVar5 + 0x12) & 1) == 0)) {
        local_58._2_2_ = (short)(theCamera.core.position._0_4_ >> 0x10);
        uVar4 = (theCamera.core.position._0_4_ & 0xffff) - (uint)*(ushort *)(iVar5 + 0xc);
        local_30 = -(short)uVar4;
        uVar3 = local_58._2_2_ - *(short *)(iVar5 + 0xe);
        theCamera.core.position._0_4_ = uVar4 & 0xffff | (uint)uVar3 << 0x10;
        local_2e = -uVar3;
        theCamera.core.position.z = theCamera.core.position.z - *(short *)(iVar5 + 0x10);
        local_2c = -theCamera.core.position.z;
                    /* WARNING: Subroutine does not return */
        ApplyMatrix(&local_50,&local_30,(theCamera.core.wcTransform)->t);
      }
      unitID = unitID + 1;
      iVar6 = iVar6 + 0x24;
    } while (unitID < terrain->numBSPTrees);
  }
  unitID = (int)RENDER_currentStreamUnitID;
  InStreamUnit = 1;
  *(undefined4 *)(theCamera.core.wcTransform)->m = local_50;
  *(undefined4 *)(pMVar1->m + 2) = local_4c;
  *(undefined4 *)(pMVar1->m + 4) = local_48;
  *(undefined4 *)(pMVar1->m + 6) = local_44;
  *(undefined4 *)(pMVar1->m + 8) = local_40;
  pMVar1->t[0] = local_3c;
  pMVar1->t[1] = local_38;
  pMVar1->t[2] = local_34;
  SBSP_IntroduceInstancesAndLights(terrain,(_CameraCore_Type *)&theCamera,lightInfo,unitID);
  InStreamUnit = 0;
  theCamera.core.farPlane = lVar2;
  if ((gameTrackerX.playerInstance)->currentStreamUnitID == currentUnit->StreamUnitID) {
    hackOT = drawot;
    StackSave = (ulong)auStack112;
    FX_DrawReaver(gameTrackerX.primPool,drawot,theCamera.core.wcTransform);
  }
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_FlipScreenAndDraw(struct GameTracker *gameTracker /*$s0*/, unsigned long **drawot /*$a1*/)
 // line 2139, offset 0x8002f130
	/* begin block 1 */
		// Start line: 4978
	/* end block 1 */
	// End Line: 4979

void GAMELOOP_FlipScreenAndDraw(GameTracker *gameTracker,ulong **drawot)

{
                    /* WARNING: Subroutine does not return */
  DrawOTag(drawot + 0xbff);
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_AddClearPrim(unsigned long **drawot /*$a3*/)
 // line 2171, offset 0x8002f1e8
	/* begin block 1 */
		// Start line: 2172
		// Start offset: 0x8002F1E8

		/* begin block 1.1 */
			// Start line: 2176
			// Start offset: 0x8002F1FC
			// Variables:
		// 		struct BLK_FILL *blkfill; // $a0
		/* end block 1.1 */
		// End offset: 0x8002F1FC
		// End Line: 2176

		/* begin block 1.2 */
			// Start line: 2192
			// Start offset: 0x8002F26C
			// Variables:
		// 		struct BLK_FILL *blkfill; // $v1
		/* end block 1.2 */
		// End offset: 0x8002F288
		// End Line: 2194
	/* end block 1 */
	// End offset: 0x8002F288
	// End Line: 2195

	/* begin block 2 */
		// Start line: 5049
	/* end block 2 */
	// End Line: 5050

	/* begin block 3 */
		// Start line: 5051
	/* end block 3 */
	// End Line: 5052

void GAMELOOP_AddClearPrim(ulong **drawot)

{
  ulong *puVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  
  if ((gameTrackerX.gameFlags & 0x8000000U) == 0) {
    puVar1 = (gameTrackerX.primPool)->nextPrim;
    uVar2 = *(ulong *)&(&clearRect)[gameTrackerX.drawPage].r0;
    uVar3 = *(ulong *)&(&clearRect)[gameTrackerX.drawPage].x0;
    uVar4 = *(ulong *)&(&clearRect)[gameTrackerX.drawPage].w;
    *puVar1 = (&clearRect)[gameTrackerX.drawPage].tag;
    puVar1[1] = uVar2;
    puVar1[2] = uVar3;
    puVar1[3] = uVar4;
    (gameTrackerX.primPool)->nextPrim = puVar1 + 4;
    *puVar1 = (uint)drawot[0xbff] & 0xffffff | 0x3000000;
    drawot[0xbff] = (ulong *)((uint)puVar1 & 0xffffff);
    return;
  }
  *(ushort *)&(gameTrackerX.savedOTStart)->b0 = (&clearRect)[gameTrackerX.drawPage].y0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_SwitchTheDrawBuffer(unsigned long **drawot /*$a0*/)
 // line 2197, offset 0x8002f290
	/* begin block 1 */
		// Start line: 5120
	/* end block 1 */
	// End Line: 5121

void GAMELOOP_SwitchTheDrawBuffer(ulong **drawot)

{
  GAMELOOP_AddClearPrim(drawot);
                    /* WARNING: Subroutine does not return */
  DrawSync(0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_SetupRenderFunction(struct GameTracker *gameTracker /*$a0*/)
 // line 2229, offset 0x8002f314
	/* begin block 1 */
		// Start line: 5185
	/* end block 1 */
	// End Line: 5186

	/* begin block 2 */
		// Start line: 5200
	/* end block 2 */
	// End Line: 5201

void GAMELOOP_SetupRenderFunction(GameTracker *gameTracker)

{
  *(undefined **)&gameTracker->drawAnimatedModelFunc = &DRAW_AnimatedModel_S;
  *(undefined **)&gameTracker->drawDisplayPolytopeListFunc = &DRAW_DisplayPolytopeList_S;
  return;
}



// decompiled code
// original method signature: 
// struct _StreamUnit * /*$ra*/ GAMELOOP_GetMainRenderUnit()
 // line 2255, offset 0x8002f330
	/* begin block 1 */
		// Start line: 2256
		// Start offset: 0x8002F330
		// Variables:
	// 		struct _StreamUnit *streamUnit; // $s0

		/* begin block 1.1 */
			// Start line: 2267
			// Start offset: 0x8002F360
			// Variables:
		// 		struct _Instance *focusInstance; // $s1

			/* begin block 1.1.1 */
				// Start line: 2288
				// Start offset: 0x8002F3C0
				// Variables:
			// 		struct _StreamUnit *cameraUnit; // $v0
			/* end block 1.1.1 */
			// End offset: 0x8002F3DC
			// End Line: 2296
		/* end block 1.1 */
		// End offset: 0x8002F3DC
		// End Line: 2297
	/* end block 1 */
	// End offset: 0x8002F3E0
	// End Line: 2301

	/* begin block 2 */
		// Start line: 5237
	/* end block 2 */
	// End Line: 5238

/* WARNING: Unknown calling convention yet parameter storage is locked */

_StreamUnit * GAMELOOP_GetMainRenderUnit(void)

{
  _StreamUnit *p_Var1;
  
  if (theCamera.mode == 5) {
    p_Var1 = STREAM_WhichUnitPointerIsIn(theCamera.data.Cinematic.posSpline);
    return p_Var1;
  }
  if ((theCamera.focusInstance == gameTrackerX.playerInstance) &&
     (gameTrackerX.SwitchToNewStreamUnit != 0)) {
                    /* WARNING: Subroutine does not return */
    STREAM_GetStreamUnitWithID(gameTrackerX.moveRazielToStreamID);
  }
                    /* WARNING: Subroutine does not return */
  STREAM_GetStreamUnitWithID((theCamera.focusInstance)->currentStreamUnitID);
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_DisplayFrame(struct GameTracker *gameTracker /*stack 0*/)
 // line 2306, offset 0x8002f3f4
	/* begin block 1 */
		// Start line: 2307
		// Start offset: 0x8002F3F4
		// Variables:
	// 		unsigned long **drawot; // stack offset -56
	// 		struct Level *mainLevel; // stack offset -52
	// 		struct StreamUnitPortal *streamPortal; // $fp
	// 		int numportals; // stack offset -48
	// 		int d; // $s4
	// 		struct _StreamUnit *mainStreamUnit; // $s7

		/* begin block 1.1 */
			// Start line: 2403
			// Start offset: 0x8002F5B8
			// Variables:
		// 		struct _StreamUnit *toStreamUnit; // $s3
		// 		long toStreamUnitID; // $s6
		// 		struct StreamUnitPortal *streamPortal2; // $s0
		// 		int i; // $s1
		// 		int draw; // $s2
		// 		struct RECT cliprect; // stack offset -64
		/* end block 1.1 */
		// End offset: 0x8002F7F4
		// End Line: 2508
	/* end block 1 */
	// End offset: 0x8002F9EC
	// End Line: 2613

	/* begin block 2 */
		// Start line: 5342
	/* end block 2 */
	// End Line: 5343

void GAMELOOP_DisplayFrame(GameTracker *gameTracker)

{
  bool bVar1;
  _StreamUnit *currentUnit;
  long lVar2;
  int *piVar3;
  int iVar4;
  StreamUnitPortal *portal;
  STracker *currentUnit_00;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  RECT local_40;
  ulong **local_38;
  Level *local_34;
  int local_30;
  
  local_38 = gameTracker->drawOT;
  if ((gameTrackerX.gameFlags & 0x8000000U) == 0) {
    gameTrackerX.visibleInstances = 0;
    gameTrackerX.displayFrameCount = gameTrackerX.displayFrameCount + 1;
    GAMELOOP_SetupRenderFunction(&gameTrackerX);
    if (((GlobalSave->flags & 1U) == 0) &&
       (((gameTracker->wipeType != 0xb || (gameTracker->wipeTime == 0)) &&
        ((gameTracker->debugFlags2 & 0x800U) != 0)))) {
      FX_Spiral(gameTrackerX.primPool,local_38);
    }
    HUD_Draw();
    currentUnit = GAMELOOP_GetMainRenderUnit();
    local_34 = currentUnit->level;
    if ((gameTracker->debugFlags & 4U) != 0) {
                    /* WARNING: Subroutine does not return */
      FONT_Print("Cameraunit: %s\n");
    }
    RENDER_currentStreamUnitID = *(short *)&currentUnit->StreamUnitID;
    theCamera.core.rightX = 0x140;
    theCamera.core.leftX = 0;
    theCamera.core.topY = 0;
    theCamera.core.bottomY = 0xf0;
    CAMERA_SetViewVolume(&theCamera);
    lVar2 = MEMPACK_MemoryValidFunc((char *)local_34);
    if (lVar2 != 0) {
      if ((uint)local_34->fogFar != theCamera.core.farPlane) {
        theCamera.core.farPlane = (uint)local_34->fogFar;
      }
      if ((gameTracker->debugFlags & 0x8000U) == 0) {
        MainRenderLevel(currentUnit,local_38);
      }
    }
    piVar3 = (int *)local_34->terrain->StreamUnits;
    iVar6 = 0;
    local_30 = *piVar3;
    if (0 < local_30) {
      iVar7 = (int)piVar3 + 0x22;
      do {
        currentUnit = *(_StreamUnit **)(iVar7 + 10);
        iVar8 = *(int *)(iVar7 + -10);
        if ((currentUnit == (_StreamUnit *)0x0) ||
           (currentUnit->FrameCount != gameTrackerX.displayFrameCount)) {
          local_40.x = 0x200;
          local_40.y = 0xf0;
          local_40.w = -0x200;
          local_40.h = -0xf0;
          theCamera.core.rightX = 0x140;
          theCamera.core.leftX = 0;
          theCamera.core.topY = 0;
          theCamera.core.bottomY = 0xf0;
          CAMERA_SetViewVolume(&theCamera);
          iVar5 = 0;
          bVar1 = false;
          portal = (StreamUnitPortal *)((int)local_34->terrain->StreamUnits + 4);
          if (0 < local_30) {
            do {
              if ((portal->streamID == iVar8) &&
                 (iVar4 = STREAM_GetClipRect(portal,&local_40), iVar4 != 0)) {
                bVar1 = true;
              }
              iVar5 = iVar5 + 1;
              portal = portal + 1;
            } while (iVar5 < local_30);
          }
          if (bVar1) {
            theCamera.core.leftX = (int)local_40.x * 0x140;
            if (theCamera.core.leftX < 0) {
              theCamera.core.leftX = theCamera.core.leftX + 0x1ff;
            }
            theCamera.core.topY = (int)local_40.y;
            theCamera.core.leftX = theCamera.core.leftX >> 9;
            theCamera.core.rightX = ((int)local_40.x + (int)local_40.w) * 0x140;
            if (theCamera.core.rightX < 0) {
              theCamera.core.rightX = theCamera.core.rightX + 0x1ff;
            }
            theCamera.core.rightX = theCamera.core.rightX >> 9;
            theCamera.core.bottomY = theCamera.core.topY + local_40.h;
            CAMERA_SetViewVolume(&theCamera);
                    /* WARNING: Subroutine does not return */
            SetRotMatrix((undefined4 *)theCamera.core.wcTransform);
          }
          if ((currentUnit != (_StreamUnit *)0x0) &&
             (currentUnit->FrameCount != gameTrackerX.displayFrameCount)) {
            currentUnit->FrameCount = gameTrackerX.displayFrameCount;
            StreamIntroInstancesForUnit(currentUnit);
          }
        }
        iVar6 = iVar6 + 1;
        iVar7 = iVar7 + 0x5c;
      } while (iVar6 < local_30);
    }
    iVar6 = 0;
    currentUnit_00 = &StreamTracker;
    do {
      if ((*(short *)currentUnit_00->StreamList == 2) &&
         (*(ulong *)currentUnit_00->StreamList != gameTrackerX.displayFrameCount)) {
        *(ulong *)currentUnit_00->StreamList = gameTrackerX.displayFrameCount;
        StreamIntroInstancesForUnit((_StreamUnit *)currentUnit_00);
      }
      iVar6 = iVar6 + 1;
      currentUnit_00 = (STracker *)(currentUnit_00->StreamList + 1);
    } while (iVar6 < 0x10);
    theCamera.core.rightX = 0x140;
    theCamera.core.leftX = 0;
    theCamera.core.topY = 0;
    theCamera.core.bottomY = 0xf0;
    CAMERA_SetViewVolume(&theCamera);
  }
  else {
    HUD_Draw();
  }
  DEBUG_Draw(gameTracker,local_38);
  FONT_Flush();
  GAMELOOP_SwitchTheDrawBuffer(local_38);
                    /* WARNING: Subroutine does not return */
  GetRCnt(0xf2000000);
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_DrawSavedOT(unsigned long **newOT /*$t3*/)
 // line 2619, offset 0x8002fa1c
	/* begin block 1 */
		// Start line: 2620
		// Start offset: 0x8002FA1C
		// Variables:
	// 		struct P_TAG *tag; // $a1
	// 		int y; // $a2

		/* begin block 1.1 */
			// Start line: 2628
			// Start offset: 0x8002FA84
			// Variables:
		// 		int tpage; // $v1
		/* end block 1.1 */
		// End offset: 0x8002FAAC
		// End Line: 2636

		/* begin block 1.2 */
			// Start line: 2641
			// Start offset: 0x8002FAC0
			// Variables:
		// 		int tpage; // $v1
		/* end block 1.2 */
		// End offset: 0x8002FAE8
		// End Line: 2649

		/* begin block 1.3 */
			// Start line: 2654
			// Start offset: 0x8002FAFC
		/* end block 1.3 */
		// End offset: 0x8002FB30
		// End Line: 2665
	/* end block 1 */
	// End offset: 0x8002FB54
	// End Line: 2668

	/* begin block 2 */
		// Start line: 6186
	/* end block 2 */
	// End Line: 6187

void GAMELOOP_DrawSavedOT(ulong **newOT)

{
  byte bVar1;
  short sVar2;
  ushort uVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  P_TAG *pPVar7;
  
  sVar2 = (&draw)[gameTrackerX.drawPage].ofs[1];
  pPVar7 = gameTrackerX.savedOTStart;
  if (gameTrackerX.savedOTStart != gameTrackerX.savedOTEnd) {
    do {
      bVar1 = *(byte *)((int)&pPVar7->len + 3);
      bVar5 = bVar1 & 0xfc;
      if (bVar5 == 0x34) {
        uVar3 = *(ushort *)((int)&pPVar7[2].addr + 2);
        if ((uVar3 & 0xf) < 8) {
          if (sVar2 == 0) {
            *(ushort *)((int)&pPVar7[2].addr + 2) = uVar3 & 0xffef;
          }
          else {
            *(ushort *)((int)&pPVar7[2].addr + 2) = uVar3 | 0x10;
          }
        }
      }
      else {
        if (bVar5 == 0x24) {
          uVar3 = *(ushort *)&pPVar7[1].b0;
          if ((uVar3 & 0xf) < 8) {
            if (sVar2 == 0) {
              *(ushort *)&pPVar7[1].b0 = uVar3 & 0xffef;
            }
            else {
              *(ushort *)&pPVar7[1].b0 = uVar3 | 0x10;
            }
          }
        }
        else {
          if (bVar1 == 0xe3) {
            if (sVar2 == 0) {
              uVar4 = pPVar7->len & 0xfffbffff;
              uVar6 = *(uint *)&pPVar7->r0 & 0xfffbffff;
            }
            else {
              uVar4 = pPVar7->len | 0x40000;
              uVar6 = *(uint *)&pPVar7->r0 | 0x40000;
            }
            pPVar7->len = uVar4;
            *(uint *)&pPVar7->r0 = uVar6;
          }
        }
      }
      pPVar7 = (P_TAG *)(pPVar7->addr & 0xffffff | 0x80000000);
    } while (pPVar7 != gameTrackerX.savedOTEnd);
  }
  (gameTrackerX.savedOTEnd)->addr =
       (gameTrackerX.savedOTEnd)->addr & 0xff000000 | (uint)(newOT + 0xbff) & 0xffffff;
                    /* WARNING: Subroutine does not return */
  DrawOTag(gameTrackerX.savedOTStart);
}



// decompiled code
// original method signature: 
// void /*$ra*/ ResetPrimPool()
 // line 2673, offset 0x8002fb98
	/* begin block 1 */
		// Start line: 6344
	/* end block 1 */
	// End Line: 6345

/* WARNING: Unknown calling convention yet parameter storage is locked */

void ResetPrimPool(void)

{
  undefined **ppuVar1;
  
  ResetDrawPage();
  if ((gameTrackerX.gameFlags & 0x8000000U) == 0) {
    if (gameTrackerX.primPool == primPool2) {
      gameTrackerX.primPool = PTR_800d1d24;
    }
    else {
      gameTrackerX.primPool = primPool2;
    }
    (gameTrackerX.primPool)->nextPrim = (gameTrackerX.primPool)->prim;
  }
  else {
    if (gameTrackerX.drawPage == 0) {
      ppuVar1 = (undefined **)&DAT_00008cac;
    }
    else {
      ppuVar1 = &PTR_000101dc;
    }
    (gameTrackerX.primPool)->nextPrim =
         (ulong *)((int)&(gameTrackerX.primPool)->numPrims + (int)ppuVar1);
  }
  (gameTrackerX.primPool)->numPrims = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SaveOT()
 // line 2702, offset 0x8002fc44
	/* begin block 1 */
		// Start line: 2703
		// Start offset: 0x8002FC44
		// Variables:
	// 		struct P_TAG *tag; // $a0
	// 		struct P_TAG *last; // $s0
	// 		struct P_TAG *lastlast; // $s1
	/* end block 1 */
	// End offset: 0x8002FDD0
	// End Line: 2752

	/* begin block 2 */
		// Start line: 6402
	/* end block 2 */
	// End Line: 6403

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SaveOT(void)

{
                    /* WARNING: Subroutine does not return */
  DrawSync(0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ ResetDrawPage()
 // line 2754, offset 0x8002fde4
	/* begin block 1 */
		// Start line: 2755
		// Start offset: 0x8002FDE4

		/* begin block 1.1 */
			// Start line: 2755
			// Start offset: 0x8002FDE4
			// Variables:
		// 		unsigned long **temp; // $v0
		/* end block 1.1 */
		// End offset: 0x8002FDE4
		// End Line: 2755
	/* end block 1 */
	// End offset: 0x8002FDE4
	// End Line: 2755

	/* begin block 2 */
		// Start line: 6526
	/* end block 2 */
	// End Line: 6527

/* WARNING: Unknown calling convention yet parameter storage is locked */

void ResetDrawPage(void)

{
  ulong **ppuVar1;
  
  ppuVar1 = gameTrackerX.dispOT;
  gameTrackerX.dispOT = gameTrackerX.drawOT;
  gameTrackerX.drawPage = 1 - gameTrackerX.drawPage;
  gameTrackerX.drawOT = ppuVar1;
                    /* WARNING: Subroutine does not return */
  ClearOTagR(ppuVar1,0xc00);
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_Set24FPS()
 // line 2786, offset 0x8002fe24
	/* begin block 1 */
		// Start line: 6602
	/* end block 1 */
	// End Line: 6603

	/* begin block 2 */
		// Start line: 6603
	/* end block 2 */
	// End Line: 6604

void GAMELOOP_Set24FPS(void)

{
  gameTrackerX.frameRate24fps = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_Reset24FPS()
 // line 2792, offset 0x8002fe34
	/* begin block 1 */
		// Start line: 6614
	/* end block 1 */
	// End Line: 6615

	/* begin block 2 */
		// Start line: 6615
	/* end block 2 */
	// End Line: 6616

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_Reset24FPS(void)

{
  gameTrackerX.frameRate24fps = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_DoTimeProcess()
 // line 2797, offset 0x8002fe40
	/* begin block 1 */
		// Start line: 2798
		// Start offset: 0x8002FE40
		// Variables:
	// 		int holdTime; // $s1

		/* begin block 1.1 */
			// Start line: 2833
			// Start offset: 0x8002FF24
			// Variables:
		// 		int lockRate; // $a1
		// 		unsigned long last; // $a0
		/* end block 1.1 */
		// End offset: 0x8002FFD4
		// End Line: 2876
	/* end block 1 */
	// End offset: 0x8003002C
	// End Line: 2892

	/* begin block 2 */
		// Start line: 6624
	/* end block 2 */
	// End Line: 6625

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_DoTimeProcess(void)

{
                    /* WARNING: Subroutine does not return */
  TIMER_GetTimeMS();
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_Process(struct GameTracker *gameTracker /*$s5*/)
 // line 2899, offset 0x80030044
	/* begin block 1 */
		// Start line: 2900
		// Start offset: 0x80030044
		// Variables:
	// 		int d; // $s2

		/* begin block 1.1 */
			// Start line: 2942
			// Start offset: 0x800300EC
			// Variables:
		// 		int useTime; // $s0

			/* begin block 1.1.1 */
				// Start line: 2945
				// Start offset: 0x800300FC
				// Variables:
			// 		struct Level *level; // $v0
			/* end block 1.1.1 */
			// End offset: 0x80030120
			// End Line: 2950
		/* end block 1.1 */
		// End offset: 0x80030150
		// End Line: 2955

		/* begin block 1.2 */
			// Start line: 3063
			// Start offset: 0x80030318
			// Variables:
		// 		int i; // $s0

			/* begin block 1.2.1 */
				// Start line: 3070
				// Start offset: 0x80030344
				// Variables:
			// 		struct _SFXMkr *sfxMkr; // $a2
			/* end block 1.2.1 */
			// End offset: 0x80030394
			// End Line: 3081
		/* end block 1.2 */
		// End offset: 0x800303C0
		// End Line: 3083
	/* end block 1 */
	// End offset: 0x800306E0
	// End Line: 3277

	/* begin block 2 */
		// Start line: 6845
	/* end block 2 */
	// End Line: 6846

	/* begin block 3 */
		// Start line: 6854
	/* end block 3 */
	// End Line: 6855

void GAMELOOP_Process(GameTracker *gameTracker)

{
  if (gEndGameNow != 0) {
    DEBUG_ExitGame();
    gameTracker->levelDone = 3;
    return;
  }
  GAMELOOP_DoTimeProcess();
  if ((gameTrackerX.gameMode != 6) && ((gameTrackerX.streamFlags & 0x100000U) == 0)) {
    MORPH_UpdateTimeMult();
    GAMELOOP_CalcGameTime();
    if ((gameTracker->gameData).asmData.MorphType == 0) {
      if (gameTrackerX.playerInstance != (_Instance *)0x0) {
                    /* WARNING: Subroutine does not return */
        STREAM_GetLevelWithID((gameTrackerX.playerInstance)->currentStreamUnitID);
      }
      gameTracker->currentTimeOfDayTime =
           gameTracker->currentTimeOfDayTime + gameTracker->lastLoopTime;
      gameTracker->currentMaterialTime =
           gameTracker->currentMaterialTime + gameTracker->lastLoopTime;
    }
    else {
      gameTracker->currentSpectralTime =
           gameTracker->currentSpectralTime + gameTracker->lastLoopTime;
    }
  }
  gameTracker->numGSignals = 0;
  GAMELOOP_ChangeMode();
  ResetPrimPool();
                    /* WARNING: Subroutine does not return */
  memset(gameTracker->overrideData,0,0x28);
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_ModeStartRunning()
 // line 3281, offset 0x80030708
	/* begin block 1 */
		// Start line: 7692
	/* end block 1 */
	// End Line: 7693

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ModeStartRunning(void)

{
  if (((gameTrackerX.gameMode == 4) || (gameTrackerX.gameMode == 6)) &&
     (DEBUG_ExitMenus(), gameTrackerX.gameMode == 6)) {
    currentMenu = &standardMenu;
    SOUND_ResumeAllSound();
    VOICEXA_Resume();
  }
  if ((gameTrackerX.gameFlags & 0x8000000U) != 0) {
    gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xf7ffffff;
    gameTrackerX.savedOTStart = (P_TAG *)0x0;
                    /* WARNING: Subroutine does not return */
    DrawSync(0);
  }
  gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xefffffff;
  (gameTrackerX.playerInstance)->flags = (gameTrackerX.playerInstance)->flags & 0xfffffeff;
  gameTrackerX.gameMode = 0;
  GAMEPAD_RestoreControllers();
                    /* WARNING: Subroutine does not return */
  INSTANCE_Post(gameTrackerX.playerInstance,(int)&DAT_0010000a,0);
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_ModeStartPause()
 // line 3311, offset 0x800307e0
	/* begin block 1 */
		// Start line: 7755
	/* end block 1 */
	// End Line: 7756

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ModeStartPause(void)

{
  gameTrackerX.gameMode = 6;
                    /* WARNING: Subroutine does not return */
  INSTANCE_Post(gameTrackerX.playerInstance,(int)&DAT_0010000a,1);
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_DemoSetup()
 // line 3341, offset 0x800308b4
	/* begin block 1 */
		// Start line: 7825
	/* end block 1 */
	// End Line: 7826

	/* begin block 2 */
		// Start line: 7826
	/* end block 2 */
	// End Line: 7827

void GAMELOOP_DemoSetup(void)

{
  gameTrackerX.savedPlayerCameraMode = playerCameraMode;
  playerCameraMode = 0xd;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_ChangeMode()
 // line 3361, offset 0x800308cc
	/* begin block 1 */
		// Start line: 3362
		// Start offset: 0x800308CC
		// Variables:
	// 		long *controlCommand; // $s0
	/* end block 1 */
	// End offset: 0x80030C70
	// End Line: 3529

	/* begin block 2 */
		// Start line: 6719
	/* end block 2 */
	// End Line: 6720

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ChangeMode(void)

{
  uint uVar1;
  
  if ((gameTrackerX.debugFlags & 0x40000U) == 0) {
    if ((gameTrackerX.debugFlags & 0x200000U) == 0) {
      if ((gameTrackerX.controlCommand[0][0] & 0xa01U) == 0xa01) {
        theCamera.forced_movement = 1;
        ((gameTrackerX.playerInstance)->position).z =
             ((gameTrackerX.playerInstance)->position).z + 100;
        (gameTrackerX.playerInstance)->zVel = 0;
        gameTrackerX.cheatMode = '\x01';
                    /* WARNING: Subroutine does not return */
        INSTANCE_Post(gameTrackerX.playerInstance,(int)&DAT_00100010,1);
      }
      if ((gameTrackerX.controlCommand[0][0] & 0xa02U) == 0xa02) {
        theCamera.forced_movement = 1;
        ((gameTrackerX.playerInstance)->position).z =
             ((gameTrackerX.playerInstance)->position).z + -100;
        (gameTrackerX.playerInstance)->zVel = 0;
        gameTrackerX.cheatMode = '\0';
                    /* WARNING: Subroutine does not return */
        INSTANCE_Post(gameTrackerX.playerInstance,(int)&DAT_00100010,0);
      }
    }
    if ((gameTrackerX.debugFlags & 0x40000U) != 0) goto LAB_800309c0;
  }
  else {
LAB_800309c0:
    if ((gameTrackerX.playerCheatFlags & 2U) == 0) goto LAB_80030ae4;
  }
  if (((gameTrackerX.controlCommand[0][1] & 0x60U) == 0x60) &&
     ((gameTrackerX.controlCommand[0][0] & 0xfU) == 0)) {
    if (gameTrackerX.gameMode == 0) {
      gameTrackerX.gameMode = 4;
      currentMenu = &standardMenu;
      if (gameTrackerX.sound.gVoiceOn == '\0') {
        gameTrackerX.debugFlags = gameTrackerX.debugFlags & 0xfff7ffff;
      }
      else {
        gameTrackerX.debugFlags = gameTrackerX.debugFlags | 0x80000;
      }
      if (gameTrackerX.sound.gMusicOn == '\0') {
        uVar1 = gameTrackerX.debugFlags2 & 0xffffefff;
      }
      else {
        uVar1 = gameTrackerX.debugFlags2 | 0x1000;
      }
      if (gameTrackerX.sound.gSfxOn == '\0') {
        gameTrackerX.debugFlags2 = uVar1 & 0xffffdfff;
      }
      else {
        gameTrackerX.debugFlags2 = uVar1 | 0x2000;
      }
    }
    else {
      if (gameTrackerX.gameMode == 7) {
        DEBUG_EndViewVram(&gameTrackerX);
        gameTrackerX.gameMode = 0;
      }
      else {
        GAMELOOP_ModeStartRunning();
      }
    }
  }
LAB_80030ae4:
  if ((((((gameTrackerX.controlCommand[0][1] & 0x4000U) == 0) && (gamePadControllerOut < 6)) ||
       (gameTrackerX.gameMode != 0)) || ((gameTrackerX.gameFlags & 0x80U) != 0)) ||
     ((gameTrackerX.wipeTime != 0 &&
      ((gameTrackerX.wipeType == 0xb || (gameTrackerX.wipeTime != -1)))))) {
    if ((((gameTrackerX.controlCommand[0][1] & 0x4000U) != 0) ||
        ((gameTrackerX.gameFlags & 0x40000000U) != 0)) &&
       (((gameTrackerX.gameMode != 0 && ((gameTrackerX.gameFlags & 0x20000000U) == 0)) &&
        ((gameTrackerX.wipeTime == 0 ||
         ((gameTrackerX.wipeType != 0xb && (gameTrackerX.wipeTime == -1)))))))) {
      if (((gameTrackerX.controlCommand[0][1] & 0x4000U) != 0) &&
         ((gameTrackerX.gameFlags & 0x40000000U) == 0)) {
                    /* WARNING: Subroutine does not return */
        SndPlay(5);
      }
      gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xbfffffff;
      GAMELOOP_ModeStartRunning();
    }
  }
  else {
    GAMELOOP_ModeStartPause();
  }
  if ((gameTrackerX.controlCommand[0][0] & 0x40000000U) == 0) {
    if ((gameTrackerX.controlCommand[0][2] & 0x40000000U) != 0) {
      (gameTrackerX.playerInstance)->flags = (gameTrackerX.playerInstance)->flags & 0xfffffeff;
    }
  }
  else {
    (gameTrackerX.playerInstance)->flags = (gameTrackerX.playerInstance)->flags | 0x100;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_RequestLevelChange(char *name /*$s2*/, short number /*$a1*/, struct GameTracker *gameTracker /*$s0*/)
 // line 3532, offset 0x80030c80
	/* begin block 1 */
		// Start line: 8268
	/* end block 1 */
	// End Line: 8269

void GAMELOOP_RequestLevelChange(char *name,short number,GameTracker *gameTracker)

{
  if (gameTracker->levelChange == 0) {
    gameTracker->gameFlags = gameTracker->gameFlags | 1;
    SOUND_ResetAllSound();
                    /* WARNING: Subroutine does not return */
    sprintf(gameTracker->baseAreaName,"%s%d");
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PSX_GameLoop(struct GameTracker *gameTracker /*$s0*/)
 // line 3554, offset 0x80030d00
	/* begin block 1 */
		// Start line: 8312
	/* end block 1 */
	// End Line: 8313

void PSX_GameLoop(GameTracker *gameTracker)

{
  GAMEPAD_Process(gameTracker);
  GAMELOOP_Process(gameTracker);
  return;
}



// decompiled code
// original method signature: 
// struct MATRIX * /*$ra*/ GAMELOOP_GetMatrices(int numMatrices /*$a0*/)
 // line 3564, offset 0x80030d2c
	/* begin block 1 */
		// Start line: 3566
		// Start offset: 0x80030D2C
		// Variables:
	// 		struct MATRIX *matrix; // $a1
	// 		struct _PrimPool *pool; // $v1
	/* end block 1 */
	// End offset: 0x80030D50
	// End Line: 3583

	/* begin block 2 */
		// Start line: 8332
	/* end block 2 */
	// End Line: 8333

	/* begin block 3 */
		// Start line: 8333
	/* end block 3 */
	// End Line: 8334

	/* begin block 4 */
		// Start line: 8334
	/* end block 4 */
	// End Line: 8335

MATRIX * GAMELOOP_GetMatrices(int numMatrices)

{
  MATRIX *pMVar1;
  MATRIX *pMVar2;
  
  pMVar2 = (MATRIX *)(gameTrackerX.primPool)->nextPrim;
  pMVar1 = pMVar2 + numMatrices;
  if (pMVar1 < (MATRIX *)(gameTrackerX.primPool)->lastPrim) {
    *(MATRIX **)&(gameTrackerX.primPool)->nextPrim = pMVar1;
    return pMVar2;
  }
  return (MATRIX *)0x0;
}



// decompiled code
// original method signature: 
// struct GameTracker * /*$ra*/ GAMELOOP_GetGT()
 // line 3588, offset 0x80030d60
	/* begin block 1 */
		// Start line: 8382
	/* end block 1 */
	// End Line: 8383

	/* begin block 2 */
		// Start line: 8383
	/* end block 2 */
	// End Line: 8384

/* WARNING: Unknown calling convention yet parameter storage is locked */

GameTracker * GAMELOOP_GetGT(void)

{
  return &gameTrackerX;
}





