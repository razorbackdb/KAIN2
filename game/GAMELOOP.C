#include "THISDUST.H"
#include "GAMELOOP.H"


// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_AllocStaticMemory()
 // line 129, offset 0x8002db68
	/* begin block 1 */
		// Start line: 258
	/* end block 1 */
	// End Line: 259

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_AllocStaticMemory(void)

{
  instanceList = (_InstanceList *)MEMPACK_Malloc(0x10c,'\x06');
  instancePool = (_InstancePool *)MEMPACK_Malloc(0x9bac,'\x06');
  gOt2 = (ulong **)MEMPACK_Malloc(0x34e18,'\x06');
  PTR_800d1c70 = gOt2 + 0xc00;
  primPool2 = (_PrimPool *)(gOt2 + 0x1800);
  PTR_800d1c78 = (_PrimPool *)(gOt2 + 0x75c3);
  primBase = (char *)gOt2;
  gLightInfo = (LightInfo *)MEMPACK_Malloc(0x47c,'\x06');
  memset(gLightInfo,0,0x47c);
  vertexPool = (_VertexPool *)MEMPACK_Malloc(0x18c0,'\x06');
  polytopeList = (_PolytopeList *)MEMPACK_Malloc(0x1004,'\x06');
  gFXT = (_FXTracker *)MEMPACK_Malloc(0x79a8,'\x06');
  fxTracker = gFXT;
  planningPool = MEMPACK_Malloc(3000,'\x06');
  enemyPlanPool = MEMPACK_Malloc(1000,'\x06');
  GlobalObjects = (_ObjectTracker *)MEMPACK_Malloc(0x6c0,'\x06');
  G2Anim_Install();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_InitGameTracker()
 // line 171, offset 0x8002dc64
	/* begin block 1 */
		// Start line: 172
		// Start offset: 0x8002DC64

		/* begin block 1.1 */
			// Start line: 172
			// Start offset: 0x8002DC64
			// Variables:
		// 		int i; // $t4
		/* end block 1.1 */
		// End offset: 0x8002DD3C
		// End Line: 239
	/* end block 1 */
	// End offset: 0x8002DD3C
	// End Line: 245

	/* begin block 2 */
		// Start line: 377
	/* end block 2 */
	// End Line: 378

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_InitGameTracker(void)

{
  int iVar1;
  int iVar2;
  
  gameTrackerX.GlobalObjects = GlobalObjects;
  gameTrackerX.drawTime = (ulong)planningPool;
  gameTrackerX.currentTime = (ulong)enemyPlanPool;
  gameTrackerX.vertexPool = vertexPool;
  primPool2->lastPrim = primPool2->prim + 0x5db4;
  gameTrackerX.instanceList = instanceList;
  PTR_800d1c78->lastPrim = PTR_800d1c78->prim + 0x5db4;
  gameTrackerX.lightInfo = gLightInfo;
  primPool2->nextPrim = primPool2->prim;
  gameTrackerX.instancePool = instancePool;
  PTR_800d1c78->nextPrim = PTR_800d1c78->prim;
  iVar2 = 0;
  iVar1 = 0;
  gameTrackerX.currentTimeOfDayTime = 10;
  gameTrackerX.lastLoopTime._2_2_ = 0x1000;
  gameTrackerX.lastLoopTime._0_2_ = 0;
  gameTrackerX.currentSpectralTime = 1;
  DAT_800d223c = 1;
  gameTrackerX.primPool = primPool2;
  gameTrackerX.defVVRemoveDist = (long)gOt2;
  gameTrackerX.defRemoveDist = (long)PTR_800d1c70;
  DAT_800d2240 = 1;
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
 // line 260, offset 0x8002dd64
	/* begin block 1 */
		// Start line: 741
	/* end block 1 */
	// End Line: 742

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
 // line 273, offset 0x8002dd9c
	/* begin block 1 */
		// Start line: 767
	/* end block 1 */
	// End Line: 768

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ResetGameStates(void)

{
  EVENT_Init();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_ClearGameTracker()
 // line 279, offset 0x8002ddbc
	/* begin block 1 */
		// Start line: 779
	/* end block 1 */
	// End Line: 780

	/* begin block 2 */
		// Start line: 790
	/* end block 2 */
	// End Line: 791

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ClearGameTracker(void)

{
  gameTrackerX.gameData.asmData.drawBackFaces = 0;
  gameTrackerX.gameData.asmData.MorphTime = 1000;
  gameTrackerX.frameCount = 0;
  gameTrackerX.fps30Count = 0;
  gameTrackerX.gameFlags = 0;
  gameTrackerX.currentHotSpot = 0;
  gameTrackerX.SwitchToNewStreamUnit = 0;
  gameTrackerX.globalTimeMult = 0;
  gameTrackerX.frameRateLock = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_CalcGameTime()
 // line 302, offset 0x8002ddec
	/* begin block 1 */
		// Start line: 304
		// Start offset: 0x8002DDEC
		// Variables:
	// 		long time; // $a1
	/* end block 1 */
	// End offset: 0x8002DDEC
	// End Line: 308

	/* begin block 2 */
		// Start line: 835
	/* end block 2 */
	// End Line: 836

	/* begin block 3 */
		// Start line: 836
	/* end block 3 */
	// End Line: 837

	/* begin block 4 */
		// Start line: 840
	/* end block 4 */
	// End Line: 841

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_CalcGameTime(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (gameTrackerX.currentTicks * gameTrackerX.currentTimeOfDayTime) / 60000 + 0x2d0;
  iVar1 = iVar2 / 0x3c;
  gameTrackerX.currentMaterialTime._2_2_ =
       (short)iVar1 * 0x28 +
       ((short)(iVar1 / 6 + (iVar1 >> 0x1f) >> 2) - (short)(iVar1 >> 0x1f)) * -0x960 + (short)iVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_SetGameTime(long timeOfDay /*$a1*/)
 // line 313, offset 0x8002de98
	/* begin block 1 */
		// Start line: 314
		// Start offset: 0x8002DE98
		// Variables:
	// 		long tim; // $v1
	/* end block 1 */
	// End offset: 0x8002DEF0
	// End Line: 320

	/* begin block 2 */
		// Start line: 859
	/* end block 2 */
	// End Line: 860

void GAMELOOP_SetGameTime(long timeOfDay)

{
  int iVar1;
  int iVar2;
  
  iVar1 = timeOfDay + (timeOfDay / 100) * -0x28;
  iVar2 = iVar1 + -0x2d0;
  if (iVar2 < 0) {
    iVar2 = iVar1 + 0x2d0;
  }
  gameTrackerX.spectralTimeMult = (iVar2 * 60000) / (int)gameTrackerX.currentTimeOfDayTime;
  gameTrackerX.currentMaterialTime._2_2_ = (short)timeOfDay;
  gameTrackerX.currentTicks = gameTrackerX.spectralTimeMult;
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GAMELOOP_GetTimeOfDay()
 // line 330, offset 0x8002df2c
	/* begin block 1 */
		// Start line: 332
		// Start offset: 0x8002DF2C
		// Variables:
	// 		int timeOfDay; // $v1
	/* end block 1 */
	// End offset: 0x8002DF70
	// End Line: 357

	/* begin block 2 */
		// Start line: 896
	/* end block 2 */
	// End Line: 897

	/* begin block 3 */
		// Start line: 897
	/* end block 3 */
	// End Line: 898

	/* begin block 4 */
		// Start line: 899
	/* end block 4 */
	// End Line: 900

/* WARNING: Unknown calling convention yet parameter storage is locked */

int GAMELOOP_GetTimeOfDay(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)gameTrackerX.currentMaterialTime._2_2_;
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
 // line 359, offset 0x8002df78
	/* begin block 1 */
		// Start line: 964
	/* end block 1 */
	// End Line: 965

	/* begin block 2 */
		// Start line: 966
	/* end block 2 */
	// End Line: 967

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
// void /*$ra*/ GAMELOOP_InterpTODLighting(struct Level *level /*$t0*/, short ratio /*$a1*/, int startidx /*$a2*/, short *r /*$a3*/, short *g /*stack 16*/, short *b /*stack 20*/)
 // line 388, offset 0x8002dfbc
	/* begin block 1 */
		// Start line: 389
		// Start offset: 0x8002DFBC
		// Variables:
	// 		int endidx; // $v0
	/* end block 1 */
	// End offset: 0x8002DFD4
	// End Line: 390

	/* begin block 2 */
		// Start line: 1023
	/* end block 2 */
	// End Line: 1024

	/* begin block 3 */
		// Start line: 1032
	/* end block 3 */
	// End Line: 1033

void GAMELOOP_InterpTODLighting(Level *level,short ratio,int startidx,short *r,short *g,short *b)

{
  int iVar1;
  int iVar2;
  _Terrain **pp_Var3;
  _Terrain **pp_Var4;
  
  iVar2 = startidx + 1;
  iVar1 = iVar2;
  if (iVar2 < 0) {
    iVar1 = startidx + 4;
  }
  pp_Var4 = (_Terrain **)((int)&level->terrain + startidx * 6);
  pp_Var3 = (_Terrain **)((int)&level->terrain + (iVar2 + (iVar1 >> 2) * -4) * 6);
  iVar1 = (int)ratio;
  *r = *(short *)(pp_Var4 + 0x4f) +
       (short)(iVar1 * ((int)*(short *)(pp_Var3 + 0x4f) - (int)*(short *)(pp_Var4 + 0x4f)) >> 0xc);
  *g = *(short *)((int)pp_Var4 + 0x13e) +
       (short)(iVar1 * ((int)*(short *)((int)pp_Var3 + 0x13e) -
                       (int)*(short *)((int)pp_Var4 + 0x13e)) >> 0xc);
  *b = *(short *)(pp_Var4 + 0x50) +
       (short)(iVar1 * ((int)*(short *)(pp_Var3 + 0x50) - (int)*(short *)(pp_Var4 + 0x50)) >> 0xc);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_InterpTODFogging(struct Level *level /*$t2*/, short ratio /*$a1*/, int startidx /*$t1*/, unsigned char *color /*$a3*/, unsigned short *near_dist /*stack 16*/, unsigned short *far_dist /*stack 20*/)
 // line 397, offset 0x8002e08c
	/* begin block 1 */
		// Start line: 398
		// Start offset: 0x8002E08C
		// Variables:
	// 		int endidx; // $t0
	/* end block 1 */
	// End offset: 0x8002E0A8
	// End Line: 399

	/* begin block 2 */
		// Start line: 1050
	/* end block 2 */
	// End Line: 1051

void GAMELOOP_InterpTODFogging
               (Level *level,short ratio,int startidx,uchar *color,ushort *near_dist,
               ushort *far_dist)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  _Terrain **pp_Var4;
  _Terrain **pp_Var5;
  
  iVar3 = startidx + 1;
  iVar2 = iVar3;
  if (iVar3 < 0) {
    iVar2 = startidx + 4;
  }
  iVar3 = iVar3 + (iVar2 >> 2) * -4;
  pp_Var5 = (_Terrain **)((int)&level->terrain + startidx * 3);
  pp_Var4 = (_Terrain **)((int)&level->terrain + iVar3 * 3);
  iVar2 = (int)ratio;
  *color = *(byte *)(pp_Var5 + 0x55) +
           (char)((int)(iVar2 * ((uint)*(byte *)(pp_Var4 + 0x55) - (uint)*(byte *)(pp_Var5 + 0x55)))
                 >> 0xc);
  color[1] = *(byte *)((int)pp_Var5 + 0x155) +
             (char)((int)(iVar2 * ((uint)*(byte *)((int)pp_Var4 + 0x155) -
                                  (uint)*(byte *)((int)pp_Var5 + 0x155))) >> 0xc);
  color[2] = *(byte *)((int)pp_Var5 + 0x156) +
             (char)((int)(iVar2 * ((uint)*(byte *)((int)pp_Var4 + 0x156) -
                                  (uint)*(byte *)((int)pp_Var5 + 0x156))) >> 0xc);
  uVar1 = *(ushort *)(&level->terrain + startidx + 0x58);
  *near_dist = uVar1 + (short)((int)(iVar2 * ((uint)*(ushort *)(&level->terrain + iVar3 + 0x58) -
                                             (uint)uVar1)) >> 0xc);
  uVar1 = *(ushort *)((int)(&level->terrain + startidx) + 0x162);
  *far_dist = uVar1 + (short)((int)(iVar2 * ((uint)*(ushort *)
                                                    ((int)(&level->terrain + iVar3) + 0x162) -
                                            (uint)uVar1)) >> 0xc);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_GetTimeOfDayLighting(struct Level *level /*$s1*/, short *r /*$s3*/, short *g /*$s4*/, short *b /*$s5*/, unsigned char *backColor /*stack 16*/, unsigned short *nearFog /*stack 20*/, unsigned short *farFog /*stack 24*/)
 // line 416, offset 0x8002e1a4
	/* begin block 1 */
		// Start line: 417
		// Start offset: 0x8002E1A4
		// Variables:
	// 		int timeOfDay; // $a0
	/* end block 1 */
	// End offset: 0x8002E4F4
	// End Line: 495

	/* begin block 2 */
		// Start line: 1089
	/* end block 2 */
	// End Line: 1090

void GAMELOOP_GetTimeOfDayLighting
               (Level *level,short *r,short *g,short *b,uchar *backColor,ushort *nearFog,
               ushort *farFog)

{
  int startidx;
  short ratio;
  int iVar1;
  
  if ((level->unitFlags & 2U) == 0) {
    *b = 0x1000;
    *g = 0x1000;
    *r = 0x1000;
    return;
  }
  startidx = (int)gameTrackerX.currentMaterialTime._2_2_;
  if (startidx - 0x259U < 99) {
    iVar1 = (startidx + -600) * 0x10000 >> 0x10;
    if (iVar1 < 0x1e) {
      ratio = (short)((uint)(((iVar1 * 0x1000) / 0x1e) * 0x10000) >> 0x10);
      GAMELOOP_InterpTODLighting(level,ratio,0,r,g,b);
      startidx = 0;
    }
    else {
      ratio = (short)((uint)((((startidx + -0x276) * 0x10000 >> 4) / 0x1e) * 0x10000) >> 0x10);
      GAMELOOP_InterpTODLighting(level,ratio,1,r,g,b);
      startidx = 1;
    }
  }
  else {
    if (startidx - 700U < 0x44c) {
      *r = level->TODLighting[6];
      *g = level->TODLighting[7];
      *b = level->TODLighting[8];
      *backColor = level->TODbackColor[6];
      backColor[1] = level->TODbackColor[7];
      backColor[2] = level->TODbackColor[8];
      *nearFog = level->TODfogNearFar[4];
      *farFog = level->TODfogNearFar[5];
      goto LAB_8002e494;
    }
    if (99 < startidx - 0x708U) {
      *r = level->TODLighting[0];
      *g = level->TODLighting[1];
      *b = level->TODLighting[2];
      *backColor = level->TODbackColor[0];
      backColor[1] = level->TODbackColor[1];
      backColor[2] = level->TODbackColor[2];
      *nearFog = level->TODfogNearFar[0];
      *farFog = level->TODfogNearFar[1];
      goto LAB_8002e494;
    }
    iVar1 = (int)((startidx - 0x708U) * 0x10000) >> 0x10;
    if (iVar1 < 0x1e) {
      ratio = (short)((uint)(((iVar1 * 0x1000) / 0x1e) * 0x10000) >> 0x10);
      GAMELOOP_InterpTODLighting(level,ratio,2,r,g,b);
      startidx = 2;
    }
    else {
      ratio = (short)((uint)((((startidx + -0x726) * 0x10000 >> 4) / 0x1e) * 0x10000) >> 0x10);
      GAMELOOP_InterpTODLighting(level,ratio,3,r,g,b);
      startidx = 3;
    }
  }
  GAMELOOP_InterpTODFogging(level,ratio,startidx,backColor,nearFog,farFog);
LAB_8002e494:
  level->TODRedScale = *r;
  level->TODGrnScale = *g;
  level->TODBluScale = *b;
  level->TODfogNear = *nearFog;
  level->TODfogFar = *farFog;
  level->TODbackColorR = *backColor;
  level->TODbackColorG = backColor[1];
  level->TODbackColorB = backColor[2];
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_SetLevelVmTimeOfDay(struct Level *level /*$a0*/, short r /*$a1*/, short g /*$a2*/, short b /*$a3*/)
 // line 498, offset 0x8002e520
	/* begin block 1 */
		// Start line: 1263
	/* end block 1 */
	// End Line: 1264

	/* begin block 2 */
		// Start line: 1304
	/* end block 2 */
	// End Line: 1305

void GAMELOOP_SetLevelVmTimeOfDay(Level *level,short r,short g,short b)

{
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_SetLevelTimeOfDay(struct Level *level /*$t7*/, short r /*$t9*/, short g /*$s0*/, short b /*$t8*/)
 // line 543, offset 0x8002e528
	/* begin block 1 */
		// Start line: 544
		// Start offset: 0x8002E528

		/* begin block 1.1 */
			// Start line: 547
			// Start offset: 0x8002E55C
			// Variables:
		// 		struct _Terrain *terrain; // $v0
		// 		struct _TVertex *vertex; // $t1
		// 		struct _TVertex *endvertex; // $t3

			/* begin block 1.1.1 */
				// Start line: 555
				// Start offset: 0x8002E59C
				// Variables:
			// 		short tr; // $v0
			// 		short tg; // $v1
			// 		short tb; // $a0
			/* end block 1.1.1 */
			// End offset: 0x8002E59C
			// End Line: 556
		/* end block 1.1 */
		// End offset: 0x8002E61C
		// End Line: 567
	/* end block 1 */
	// End offset: 0x8002E61C
	// End Line: 568

	/* begin block 2 */
		// Start line: 1353
	/* end block 2 */
	// End Line: 1354

void GAMELOOP_SetLevelTimeOfDay(Level *level,short r,short g,short b)

{
  ushort uVar1;
  uchar *puVar2;
  _TVertex *p_Var3;
  _TVertex *p_Var4;
  
  if ((level->unitFlags & 2U) != 0) {
    p_Var3 = level->terrain->vertexList;
    p_Var4 = p_Var3 + level->terrain->numVertices;
    if (p_Var3 != p_Var4) {
      puVar2 = &p_Var3->b0;
      do {
        uVar1 = *(ushort *)(puVar2 + -4);
        p_Var3 = p_Var3 + 1;
        puVar2[-2] = (uchar)(((uint)uVar1 & 0x1f) * 8 * (int)r >> 0xc);
        puVar2[-1] = (uchar)(((uint)(uVar1 >> 2) & 0xf8) * (int)g >> 0xc);
        *puVar2 = (uchar)(((uint)(uVar1 >> 7) & 0xf8) * (int)b >> 0xc);
        puVar2 = puVar2 + 0xc;
      } while (p_Var3 != p_Var4);
    }
    GAMELOOP_SetLevelVmTimeOfDay(level,r,g,b);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_UpdateInstanceListTimeOfDay(short ratio /*$a0*/)
 // line 573, offset 0x8002e634
	/* begin block 1 */
		// Start line: 574
		// Start offset: 0x8002E634
		// Variables:
	// 		struct _Instance *instance; // $s0

		/* begin block 1.1 */
			// Start line: 580
			// Start offset: 0x8002E684
			// Variables:
		// 		short fadeValue; // $v0
		/* end block 1.1 */
		// End offset: 0x8002E6AC
		// End Line: 583
	/* end block 1 */
	// End offset: 0x8002E6BC
	// End Line: 585

	/* begin block 2 */
		// Start line: 1443
	/* end block 2 */
	// End Line: 1444

	/* begin block 3 */
		// Start line: 1445
	/* end block 3 */
	// End Line: 1446

void GAMELOOP_UpdateInstanceListTimeOfDay(short ratio)

{
  short sVar1;
  _Instance *instance;
  
  instance = instanceList->first;
  if (instance != (_Instance *)0x0) {
    do {
      if (instance->object->id == 7) {
        sVar1 = LitShaft_GetFadeValue(instance);
        instance->fadeValue = sVar1 + (short)((0x1000 - (int)sVar1) * (int)ratio >> 0xc);
      }
      instance = instance->next;
    } while (instance != (_Instance *)0x0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_SetTODVtxColor(struct _Terrain *terrain /*$a0*/, int vidx /*$a1*/, int ratio /*$t3*/)
 // line 589, offset 0x8002e6d8
	/* begin block 1 */
		// Start line: 590
		// Start offset: 0x8002E6D8
		// Variables:
	// 		struct _TVertex *tv; // $t1
	// 		struct _MorphColor *mc; // $a0
	// 		short r; // $t0
	// 		short g; // $v1
	// 		short b; // $a1
	// 		short fixed_time; // $a3
	/* end block 1 */
	// End offset: 0x8002E82C
	// End Line: 619

	/* begin block 2 */
		// Start line: 1484
	/* end block 2 */
	// End Line: 1485

void GAMELOOP_SetTODVtxColor(_Terrain *terrain,int vidx,int ratio)

{
  ushort uVar1;
  ushort uVar2;
  _BSPNode **pp_Var3;
  uint uVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  short sVar9;
  int iVar10;
  _TVertex *p_Var11;
  
  p_Var11 = terrain->vertexList + vidx;
  pp_Var3 = (_BSPNode **)((int)&terrain->BSPTreeArray->bspRoot + vidx * 2);
  if ((int)gameTrackerX.gameData.asmData.MorphTime == 1000) {
    if (gameTrackerX.gameData.asmData.MorphType == 0) {
      uVar1 = p_Var11->rgb15;
      uVar2 = uVar1 >> 2;
      uVar6 = uVar1 >> 7;
    }
    else {
      uVar1 = *(ushort *)pp_Var3;
      uVar2 = (short)uVar1 >> 2;
      uVar6 = (short)uVar1 >> 7;
    }
    sVar9 = (short)(((uint)uVar1 & 0x1f) << 3);
    uVar2 = uVar2 & 0xf8;
    uVar6 = uVar6 & 0xf8;
  }
  else {
    sVar9 = (short)(((int)gameTrackerX.gameData.asmData.MorphTime << 0xc) / 1000);
    if (gameTrackerX.gameData.asmData.MorphType != 0) {
      sVar9 = 0x1000 - sVar9;
    }
    iVar10 = (int)sVar9;
    uVar1 = p_Var11->rgb15;
    uVar4 = (uint)*(ushort *)pp_Var3;
    uVar8 = (uint)(uVar1 >> 5) & 0x1f;
    iVar5 = uVar4 << 0x10;
    uVar7 = (uint)(uVar1 >> 10) & 0x1f;
    sVar9 = (short)((uint)uVar1 & 0x1f) * 8 +
            (short)((int)(((uVar4 & 0x1f) - ((uint)uVar1 & 0x1f)) * 8 * iVar10) >> 0xc);
    uVar2 = (short)uVar8 * 8 +
            (short)((int)(((iVar5 >> 0x12 & 0xf8U) + uVar8 * -8) * iVar10) >> 0xc);
    uVar6 = (short)uVar7 * 8 +
            (short)((int)(((iVar5 >> 0x17 & 0xf8U) + uVar7 * -8) * iVar10) >> 0xc);
  }
  p_Var11->r0 = (uchar)(sVar9 * ratio >> 0xc);
  p_Var11->g0 = (uchar)((short)uVar2 * ratio >> 0xc);
  p_Var11->b0 = (uchar)((short)uVar6 * ratio >> 0xc);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_UpdateBspListTimeOfDay(short ratio /*$a0*/)
 // line 625, offset 0x8002e878
	/* begin block 1 */
		// Start line: 626
		// Start offset: 0x8002E878
		// Variables:
	// 		int i; // stack offset -48

		/* begin block 1.1 */
			// Start line: 631
			// Start offset: 0x8002E8D4
			// Variables:
		// 		struct Level *level; // $v0
		// 		struct _Terrain *terrain; // $s4
		// 		int curTree; // $fp
		// 		struct _BSPLeaf *leaf; // $s3
		// 		struct _TFace *face; // $s0
		// 		struct _TFace *endface; // $s5
		/* end block 1.1 */
		// End offset: 0x8002E9C8
		// End Line: 659
	/* end block 1 */
	// End offset: 0x8002E9E0
	// End Line: 661

	/* begin block 2 */
		// Start line: 1575
	/* end block 2 */
	// End Line: 1576

void GAMELOOP_UpdateBspListTimeOfDay(short ratio)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  short *psVar5;
  uint uVar6;
  _Terrain *terrain;
  ushort *puVar7;
  int ratio_00;
  int iVar8;
  int iVar9;
  int local_30;
  
  ratio_00 = (int)ratio;
  local_30 = 0;
  do {
    if (StreamTracker.StreamList[local_30].used == 2) {
      terrain = (StreamTracker.StreamList[local_30].level)->terrain;
      iVar9 = 0;
      if (0 < (int)terrain->morphNormalIdx) {
        iVar8 = 0;
        do {
          iVar2 = (int)&terrain->signals->numSignals + iVar8;
          if (((*(ushort *)(iVar2 + 0x12) & 0x40) != 0) &&
             (uVar6 = *(uint *)(iVar2 + 4), uVar6 < *(uint *)(iVar2 + 8))) {
            psVar5 = (short *)(uVar6 + 0xc);
            do {
              puVar3 = *(ushort **)(psVar5 + -2);
              puVar7 = puVar3 + (int)*psVar5 * 6;
              if (puVar3 != puVar7) {
                puVar4 = puVar3 + 2;
                do {
                  uVar1 = *puVar3;
                  puVar3 = puVar3 + 6;
                  GAMELOOP_SetTODVtxColor(terrain,(uint)uVar1,ratio_00);
                  GAMELOOP_SetTODVtxColor(terrain,(uint)puVar4[-1],ratio_00);
                  uVar1 = *puVar4;
                  puVar4 = puVar4 + 6;
                  GAMELOOP_SetTODVtxColor(terrain,(uint)uVar1,ratio_00);
                } while (puVar3 != puVar7);
              }
              uVar6 = uVar6 + 0x30;
              psVar5 = psVar5 + 0x18;
            } while (uVar6 < *(uint *)((int)&terrain->signals->signalList[0].id + iVar8));
          }
          iVar9 = iVar9 + 1;
          iVar8 = iVar8 + 0x24;
        } while (iVar9 < (int)terrain->morphNormalIdx);
      }
    }
    local_30 = local_30 + 1;
  } while (local_30 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_UpdateWorldInstTimeOfDay(int timeOfDay /*$a2*/)
 // line 663, offset 0x8002ea10
	/* begin block 1 */
		// Start line: 664
		// Start offset: 0x8002EA10
		// Variables:
	// 		short ratio; // $s0
	/* end block 1 */
	// End offset: 0x8002EB30
	// End Line: 684

	/* begin block 2 */
		// Start line: 1706
	/* end block 2 */
	// End Line: 1707

void GAMELOOP_UpdateWorldInstTimeOfDay(int timeOfDay)

{
  int iVar1;
  
  if (timeOfDay - 0x259U < 99) {
    iVar1 = ((0x1a4 - (timeOfDay + (timeOfDay / 100) * -0x28)) * 0x1000) / 0x3c;
  }
  else {
    iVar1 = 0;
    if (1099 < timeOfDay - 700U) {
      if (timeOfDay - 0x708U < 100) {
        iVar1 = ((timeOfDay + (timeOfDay / 100) * -0x28 + -0x438) * 0x1000) / 0x3c;
      }
      else {
        iVar1 = 0x1000;
      }
    }
  }
  GAMELOOP_UpdateInstanceListTimeOfDay((short)iVar1);
  GAMELOOP_UpdateBspListTimeOfDay((short)((uint)((0x1000 - iVar1) * 0x10000) >> 0x10));
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GAMELOOP_TimeOfDayRatio(int timeOfDay /*$a2*/)
 // line 688, offset 0x8002eb60
	/* begin block 1 */
		// Start line: 689
		// Start offset: 0x8002EB60
		// Variables:
	// 		short ratio; // $v0
	/* end block 1 */
	// End offset: 0x8002EC54
	// End Line: 708

	/* begin block 2 */
		// Start line: 1759
	/* end block 2 */
	// End Line: 1760

int GAMELOOP_TimeOfDayRatio(int timeOfDay)

{
  short sVar1;
  int iVar2;
  
  if (timeOfDay - 0x259U < 99) {
    iVar2 = timeOfDay + (timeOfDay / 100) * -0x28 + -0x1a4;
  }
  else {
    sVar1 = 0;
    if (timeOfDay - 700U < 0x44c) goto LAB_8002ec54;
    if (99 < timeOfDay - 0x708U) {
      sVar1 = 0;
      goto LAB_8002ec54;
    }
    iVar2 = timeOfDay + (timeOfDay / 100) * -0x28 + -0x438;
  }
  sVar1 = (short)((iVar2 * 0x1000) / 0x3c);
LAB_8002ec54:
  return (int)sVar1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_InitLevelTimeOfDay(struct Level *level /*$s0*/)
 // line 712, offset 0x8002ec60
	/* begin block 1 */
		// Start line: 713
		// Start offset: 0x8002EC60
		// Variables:
	// 		short r; // stack offset -24
	// 		short g; // stack offset -22
	// 		short b; // stack offset -20
	// 		int timeOfDay; // $s1
	/* end block 1 */
	// End offset: 0x8002EC60
	// End Line: 713

	/* begin block 2 */
		// Start line: 1807
	/* end block 2 */
	// End Line: 1808

void GAMELOOP_InitLevelTimeOfDay(Level *level)

{
  int startTimeIdx;
  int timeOfDay;
  short local_18;
  short local_16;
  short local_14 [2];
  
  timeOfDay = (int)gameTrackerX.currentMaterialTime._2_2_;
  GAMELOOP_GetTimeOfDayLighting
            (level,&local_18,&local_16,local_14,&level->backColorR,&level->holdFogNear,
             &level->holdFogFar);
  GAMELOOP_SetLevelTimeOfDay(level,local_18,local_16,local_14[0]);
  GAMELOOP_UpdateWorldInstTimeOfDay(timeOfDay);
  VM_UpdateMorph(level,1);
  startTimeIdx = GAMELOOP_GetTimeOfDayIdx(timeOfDay);
  timeOfDay = GAMELOOP_TimeOfDayRatio(timeOfDay);
  VM_UpdateTimeOfDay(level,startTimeIdx,timeOfDay);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_UpdateWorldTimeOfDay()
 // line 725, offset 0x8002ed00
	/* begin block 1 */
		// Start line: 726
		// Start offset: 0x8002ED00
		// Variables:
	// 		int curTimeOfDay; // $s4
	// 		static int prevTimeOfDay; // offset 0xc

		/* begin block 1.1 */
			// Start line: 744
			// Start offset: 0x8002ED6C
			// Variables:
		// 		int i; // $s2
		// 		short r; // stack offset -32
		// 		short g; // stack offset -30
		// 		short b; // stack offset -28

			/* begin block 1.1.1 */
				// Start line: 752
				// Start offset: 0x8002ED90
				// Variables:
			// 		struct Level *level; // $s1
			/* end block 1.1.1 */
			// End offset: 0x8002EE1C
			// End Line: 764

			/* begin block 1.1.2 */
				// Start line: 773
				// Start offset: 0x8002EE58
				// Variables:
			// 		struct Level *level; // $v1
			/* end block 1.1.2 */
			// End offset: 0x8002EE7C
			// End Line: 776
		/* end block 1.1 */
		// End offset: 0x8002EE94
		// End Line: 782
	/* end block 1 */
	// End offset: 0x8002EE94
	// End Line: 783

	/* begin block 2 */
		// Start line: 1843
	/* end block 2 */
	// End Line: 1844

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_UpdateWorldTimeOfDay(void)

{
  int timeOfDay;
  int startTimeIdx;
  int ratio;
  int iVar1;
  STracker *streamUnit;
  Level *level;
  int iVar2;
  short local_20;
  short local_1e;
  short local_1c [2];
  
  if ((gameTrackerX.gameData.asmData.MorphType != 1) &&
     (gameTrackerX.gameData.asmData.MorphTime == 1000)) {
    timeOfDay = GAMELOOP_GetTimeOfDay();
    if ((timeOfDay == 0x708) || (timeOfDay == 600)) {
      timeOfDay = (int)gameTrackerX.currentMaterialTime._2_2_;
    }
    iVar2 = 0;
    if (timeOfDay != DAT_800ce4ac) {
      iVar1 = 0;
      DAT_800ce4ac = timeOfDay;
      do {
        if (*(short *)((int)&StreamTracker.StreamList[0].used + iVar1) == 2) {
          level = *(Level **)((int)&StreamTracker.StreamList[0].level + iVar1);
          GAMELOOP_GetTimeOfDayLighting
                    (level,&local_20,&local_1e,local_1c,&level->backColorR,&level->holdFogNear,
                     &level->holdFogFar);
          GAMELOOP_SetLevelTimeOfDay(level,local_20,local_1e,local_1c[0]);
          startTimeIdx = GAMELOOP_GetTimeOfDayIdx(timeOfDay);
          ratio = GAMELOOP_TimeOfDayRatio(timeOfDay);
          VM_UpdateTimeOfDay(level,startTimeIdx,ratio);
          if ((level == gameTrackerX.level) && (gameTrackerX.gameData.asmData.MorphType == 0)) {
            STREAM_SetMainFog((_StreamUnit *)
                              ((int)&StreamTracker.StreamList[0].StreamUnitID + iVar1));
          }
        }
        iVar2 = iVar2 + 1;
        iVar1 = iVar2 * 0x40;
      } while (iVar2 < 0x10);
      iVar2 = 0;
      if (gameTrackerX.gameData.asmData.MorphType == 0) {
        streamUnit = &StreamTracker;
        do {
          if ((*(short *)streamUnit->StreamList == 2) &&
             (level = *(Level **)streamUnit->StreamList, level != gameTrackerX.level)) {
            STREAM_SetStreamFog((_StreamUnit *)streamUnit,level->holdFogNear,level->holdFogFar);
          }
          iVar2 = iVar2 + 1;
          streamUnit = (STracker *)(streamUnit->StreamList + 1);
        } while (iVar2 < 0x10);
      }
      GAMELOOP_UpdateWorldInstTimeOfDay(timeOfDay);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// struct _StreamUnit * /*$ra*/ LoadLevels(char *baseAreaName /*$s4*/, struct GameTracker *gameTracker /*$s1*/)
 // line 791, offset 0x8002eeb4
	/* begin block 1 */
		// Start line: 792
		// Start offset: 0x8002EEB4
		// Variables:
	// 		struct _SVector offset; // stack offset -32
	// 		struct _StreamUnit *streamUnit; // $s0
	// 		static char oldArea[16]; // offset 0x10

		/* begin block 1.1 */
			// Start line: 834
			// Start offset: 0x8002EFC8
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
		/* end block 1.1 */
		// End offset: 0x8002EFC8
		// End Line: 834
	/* end block 1 */
	// End offset: 0x8002EFC8
	// End Line: 834

	/* begin block 2 */
		// Start line: 2006
	/* end block 2 */
	// End Line: 2007

_StreamUnit * LoadLevels(char *baseAreaName,GameTracker *gameTracker)

{
  short sVar1;
  size_t sVar2;
  _StreamUnit *streamUnit;
  short *psVar3;
  _MultiSignal *p_Var4;
  _SVector local_20;
  
  sVar2 = strlen("");
  if (sVar2 != 0) {
    STREAM_AbortAreaLoad("");
  }
  strcpy("",baseAreaName);
  LOAD_ChangeDirectory(baseAreaName);
  streamUnit = STREAM_LoadLevel(gameTracker,baseAreaName,(StreamUnitPortal *)0x0,0);
  sVar1 = streamUnit->used;
  while (sVar1 == 1) {
    STREAM_PollLoadQueue();
    if ((gameTracker->debugFlags & 0x80000U) != 0) {
      VOICEXA_Tick();
    }
    sVar1 = streamUnit->used;
  }
  p_Var4 = streamUnit->level->startUnitMainSignal;
  if ((p_Var4 != (_MultiSignal *)0x0) && (gameTracker->playerInstance != (_Instance *)0x0)) {
    p_Var4->flags = p_Var4->flags | 1;
    SIGNAL_HandleSignal(gameTracker->playerInstance,
                        streamUnit->level->startUnitMainSignal->signalList,0);
  }
  STREAM_LoadMainVram(gameTracker,baseAreaName,streamUnit);
  p_Var4 = streamUnit->level->terrain->signals;
  psVar3 = (short *)p_Var4->numSignals;
  local_20.x = -(*psVar3 + *(short *)p_Var4->signalList[0].data);
  local_20.y = -(psVar3[1] + *(short *)(p_Var4->signalList[0].data + 2));
  local_20.z = -(psVar3[2] + *(short *)(p_Var4->signalList[0].data + 4));
  PreloadAllConnectedUnits(gameTracker,streamUnit,&local_20);
  return streamUnit;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_LevelLoadAndInit(char *baseAreaName /*$s0*/, struct GameTracker *gameTracker /*$s3*/)
 // line 850, offset 0x8002f070
	/* begin block 1 */
		// Start line: 851
		// Start offset: 0x8002F070
		// Variables:
	// 		long i; // $s1
	// 		struct _StreamUnit *streamUnit; // $s2

		/* begin block 1.1 */
			// Start line: 909
			// Start offset: 0x8002F234
			// Variables:
		// 		static struct Intro intro; // offset 0x58
		/* end block 1.1 */
		// End offset: 0x8002F248
		// End Line: 932

		/* begin block 1.2 */
			// Start line: 936
			// Start offset: 0x8002F248
			// Variables:
		// 		short _x1; // $v0
		// 		short _y1; // $a0
		// 		short _z1; // $v1
		// 		struct _Position *_v0; // $v0
		// 		struct _Position *_v1; // $v1
		/* end block 1.2 */
		// End offset: 0x8002F248
		// End Line: 936
	/* end block 1 */
	// End offset: 0x8002F3F8
	// End Line: 1037

	/* begin block 2 */
		// Start line: 2137
	/* end block 2 */
	// End Line: 2138

void GAMELOOP_LevelLoadAndInit(char *baseAreaName,GameTracker *gameTracker)

{
  _InstanceList *list;
  _InstancePool *pool;
  _StreamUnit *p_Var1;
  int iVar2;
  int iVar3;
  _Instance *p_Var4;
  _MultiSignal *p_Var5;
  Level *pLVar6;
  int iVar7;
  
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
  DRAW_InitShadow();
  InsertGlobalObject("raziel",&gameTrackerX);
  InsertGlobalObject("paths",&gameTrackerX);
  InsertGlobalObject("glphicon",&gameTrackerX);
  InsertGlobalObject("sreavr",&gameTrackerX);
  InsertGlobalObject("sphere",&gameTrackerX);
  InsertGlobalObject("box",&gameTrackerX);
  InsertGlobalObject("dbg_cam",&gameTrackerX);
  p_Var1 = LoadLevels(baseAreaName,gameTracker);
  do {
    iVar2 = STREAM_PollLoadQueue();
  } while (iVar2 != 0);
  *(void **)&gameTracker->introWaitTime = (void *)0x0;
  pLVar6 = p_Var1->level;
  RENDER_currentStreamUnitID = *(short *)&gameTracker->StreamUnitID;
  fontsObject = (Object *)(void *)0x0;
  iVar2 = 0;
  if (0 < pLVar6->numIntros) {
    iVar7 = 0;
    do {
      iVar3 = strcmpi(pLVar6->introList->name + iVar7,"raziel");
      if (iVar3 == 0) {
        INSTANCE_IntroduceInstance
                  ((Intro *)(p_Var1->level->introList->name + iVar7),*(short *)&p_Var1->StreamUnitID
                  );
        break;
      }
      pLVar6 = p_Var1->level;
      iVar2 = iVar2 + 1;
      iVar7 = iVar7 + 0x4c;
    } while (iVar2 < pLVar6->numIntros);
  }
  if (iVar2 == p_Var1->level->numIntros) {
    INSTANCE_IntroduceInstance((Intro *)"raziel",*(short *)&p_Var1->StreamUnitID);
  }
  gameTracker->playerInstance->data = gameTracker->playerInstance->object->data;
  CAMERA_SetInstanceFocus(&theCamera,gameTracker->playerInstance);
  p_Var4 = gameTracker->playerInstance;
  theCamera.core.position.x = (p_Var4->position).x;
  theCamera.core.position.y = (p_Var4->position).y;
  theCamera.core.position.z = (p_Var4->position).z;
  SetFogNearFar((uint)p_Var1->level->fogNear,(uint)p_Var1->level->fogFar,0x140);
  SetFarColor(0,0,0);
  clearRect.r0 = p_Var1->level->backColorR;
                    /* WARNING: Read-only address (ram,0x800d1f9c) is written */
  clearRect.g0 = p_Var1->level->backColorG;
                    /* WARNING: Read-only address (ram,0x800d1f9d) is written */
  clearRect.b0 = p_Var1->level->backColorB;
                    /* WARNING: Read-only address (ram,0x800d1f9e) is written */
  BLK_FILL_800d1fa8.r0 = p_Var1->level->backColorR;
                    /* WARNING: Read-only address (ram,0x800d1fac) is written */
  BLK_FILL_800d1fa8.g0 = p_Var1->level->backColorG;
                    /* WARNING: Read-only address (ram,0x800d1fad) is written */
  BLK_FILL_800d1fa8.b0 = p_Var1->level->backColorB;
                    /* WARNING: Read-only address (ram,0x800d1fae) is written */
  LIGHT_InitSources(gLightInfo);
  gameTracker->wipeType = 10;
  gameTracker->hideBG = 0;
  gameTracker->wipeTime = 0x1e;
  gameTracker->maxWipeTime = 0x1e;
  p_Var5 = p_Var1->level->startSignal;
  if (p_Var5 != (_MultiSignal *)0x0) {
    p_Var5->flags = p_Var5->flags | 1;
    SIGNAL_HandleSignal(gameTracker->playerInstance,p_Var1->level->startSignal->signalList,0);
  }
  gameTracker->vblFrames = 0;
  p_Var5 = p_Var1->level->startUnitMainSignal;
  if ((p_Var5 != (_MultiSignal *)0x0) && (gameTracker->playerInstance != (_Instance *)0x0)) {
    p_Var5->flags = p_Var5->flags | 1;
    SIGNAL_HandleSignal(gameTracker->playerInstance,p_Var1->level->startUnitMainSignal->signalList,0
                       );
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_StreamLevelLoadAndInit(char *baseAreaName /*$a0*/, struct GameTracker *gameTracker /*$a1*/, int toSignalNum /*$a2*/, int fromSignalNum /*$a3*/)
 // line 1040, offset 0x8002f414
	/* begin block 1 */
		// Start line: 1041
		// Start offset: 0x8002F414
	/* end block 1 */
	// End offset: 0x8002F414
	// End Line: 1041

	/* begin block 2 */
		// Start line: 2581
	/* end block 2 */
	// End Line: 2582

void GAMELOOP_StreamLevelLoadAndInit
               (char *baseAreaName,GameTracker *gameTracker,int toSignalNum,int fromSignalNum)

{
  LoadLevels(baseAreaName,gameTracker);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_HandleScreenWipes(unsigned long **drawot /*$s4*/)
 // line 1060, offset 0x8002f434
	/* begin block 1 */
		// Start line: 1061
		// Start offset: 0x8002F434
		// Variables:
	// 		long temp; // $s0
	// 		struct _PrimPool *primPool; // $s3
	/* end block 1 */
	// End offset: 0x8002F880
	// End Line: 1408

	/* begin block 2 */
		// Start line: 2621
	/* end block 2 */
	// End Line: 2622

	/* begin block 3 */
		// Start line: 2636
	/* end block 3 */
	// End Line: 2637

void GAMELOOP_HandleScreenWipes(ulong **drawot)

{
  ushort uVar1;
  _PrimPool *primPool;
  int r;
  
  primPool = gameTrackerX.primPool;
  uVar1 = GlobalSave->flags;
  GlobalSave->flags = uVar1 & 1;
  if ((uVar1 & 1) != 0) {
    DRAW_FlatQuad((CVECTOR *)&gameTrackerX.wipeColor,0,0,0x200,0,0,0x1e,0x200,0x1e,primPool,drawot);
    DRAW_FlatQuad((CVECTOR *)&gameTrackerX.wipeColor,0,0xd2,0x200,0xd2,0,0xf0,0x200,0xf0,primPool,
                  drawot);
  }
  r = (int)gameTrackerX.wipeTime;
  if (r < 1) {
    if (r < -1) {
      if (gameTrackerX.wipeType == 10) {
        r = (int)(short)((((int)gameTrackerX.maxWipeTime + r) * 0xff) /
                        (int)gameTrackerX.maxWipeTime);
        DRAW_TranslucentQuad(0,0,0x200,0,0,0xf0,0x200,0xf0,r,r,r,2,primPool,drawot);
      }
      else {
        if (gameTrackerX.wipeType == 0xb) {
          r = (int)(short)((((int)gameTrackerX.maxWipeTime + r) * 0xff) /
                          (int)gameTrackerX.maxWipeTime);
          DRAW_TranslucentQuad(0,0,0x200,0,0,0x1e,0x200,0x1e,r,r,r,2,primPool,drawot);
          DRAW_TranslucentQuad(0,0xd2,0x200,0xd2,0,0xf0,0x200,0xf0,r,r,r,2,primPool,drawot);
          if (gameTrackerX.wipeTime == -2) {
            GlobalSave->flags = GlobalSave->flags | 1;
          }
        }
      }
      if (DAT_800d2234 != 0) {
        gameTrackerX.wipeTime = gameTrackerX.wipeTime + 1;
      }
    }
    else {
      if (r == -1) {
        if (gameTrackerX.wipeType == 0xb) {
          GlobalSave->flags = GlobalSave->flags | 1;
        }
        else {
          DRAW_FlatQuad((CVECTOR *)&gameTrackerX.wipeColor,0,0,0x200,0,0,0xf0,0x200,0xf0,primPool,
                        drawot);
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
      DRAW_TranslucentQuad(0,0,0x200,0,0,0xf0,0x200,0xf0,r,r,r,2,primPool,drawot);
    }
    else {
      if (gameTrackerX.wipeType == 0xb) {
        r = (int)(short)((r * 0xff) / (int)gameTrackerX.maxWipeTime);
        DRAW_TranslucentQuad(0,0,0x200,0,0,0x1e,0x200,0x1e,r,r,r,2,primPool,drawot);
        DRAW_TranslucentQuad(0,0xd2,0x200,0xd2,0,0xf0,0x200,0xf0,r,r,r,2,primPool,drawot);
        GlobalSave->flags = GlobalSave->flags & 0xfffe;
      }
    }
    if (DAT_800d2234 != 0) {
      gameTrackerX.wipeTime = gameTrackerX.wipeTime + -1;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ UpdateFogSettings(struct _StreamUnit *currentUnit /*$s2*/, struct Level *level /*$s0*/)
 // line 1551, offset 0x8002f8a0
	/* begin block 1 */
		// Start line: 1552
		// Start offset: 0x8002F8A0
		// Variables:
	// 		int changed; // $a2
	// 		int setflag; // $s1
	// 		int FogFar; // $a1
	// 		int FogNear; // $a0
	/* end block 1 */
	// End offset: 0x8002F9B0
	// End Line: 1599

	/* begin block 2 */
		// Start line: 3620
	/* end block 2 */
	// End Line: 3621

void UpdateFogSettings(_StreamUnit *currentUnit,Level *level)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  bVar4 = false;
  uVar1 = currentUnit->TargetFogNear;
  iVar7 = (int)(short)uVar1;
  uVar6 = (uint)level->fogNear;
  uVar2 = currentUnit->TargetFogFar;
  iVar8 = (int)(short)uVar2;
  bVar5 = false;
  if (iVar7 < (int)uVar6) {
    level->fogNear = (ushort)(uVar6 - 500);
    bVar3 = iVar7 < (int)(uVar6 - 500 & 0xffff);
LAB_8002f90c:
    bVar4 = true;
    if (!bVar3) {
      bVar5 = true;
      level->fogNear = uVar1;
    }
  }
  else {
    if ((int)uVar6 < iVar7) {
      level->fogNear = (ushort)(uVar6 + 500);
      bVar3 = (int)(uVar6 + 500 & 0xffff) < iVar7;
      goto LAB_8002f90c;
    }
    bVar5 = true;
  }
  uVar6 = (uint)level->fogFar;
  if (iVar8 < (int)uVar6) {
    level->fogFar = (ushort)(uVar6 - 500);
    bVar4 = true;
    if (iVar8 < (int)(uVar6 - 500 & 0xffff)) {
      bVar5 = false;
      goto LAB_8002f980;
    }
  }
  else {
    if (iVar8 <= (int)uVar6) goto LAB_8002f980;
    level->fogFar = (ushort)(uVar6 + 500);
    bVar4 = true;
    if ((int)(uVar6 + 500 & 0xffff) < iVar8) {
      bVar5 = false;
      goto LAB_8002f980;
    }
  }
  bVar4 = true;
  level->fogFar = uVar2;
LAB_8002f980:
  if ((bVar4) && (LIGHT_CalcDQPTable(level), bVar5)) {
    currentUnit->TargetFogNear = level->fogNear;
    currentUnit->TargetFogFar = level->fogFar;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ CheckForNoBlend(struct _ColorType *Color /*$a0*/)
 // line 1601, offset 0x8002f9c8
	/* begin block 1 */
		// Start line: 3731
	/* end block 1 */
	// End Line: 3732

	/* begin block 2 */
		// Start line: 3732
	/* end block 2 */
	// End Line: 3733

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
 // line 1611, offset 0x8002fa10
	/* begin block 1 */
		// Start line: 3751
	/* end block 1 */
	// End Line: 3752

void BlendToColor(_ColorType *target,_ColorType *current,_ColorType *dest)

{
  int iVar1;
  
  LoadAverageCol((byte *)target,(byte *)current,0x200,0xe00,(undefined *)dest);
  iVar1 = (uint)target->r - (uint)dest->r;
  if (iVar1 < 0) {
    if (4 < (int)((uint)dest->r - (uint)target->r)) goto LAB_8002faec;
  }
  else {
    if (4 < iVar1) {
      dest->code = '\0';
      return;
    }
  }
  iVar1 = (uint)target->g - (uint)dest->g;
  if (iVar1 < 0) {
    if (4 < (int)((uint)dest->g - (uint)target->g)) goto LAB_8002faec;
  }
  else {
    if (4 < iVar1) {
      dest->code = '\0';
      return;
    }
  }
  iVar1 = (uint)target->b - (uint)dest->b;
  if (iVar1 < 0) {
    if (4 < (int)((uint)dest->b - (uint)target->b)) goto LAB_8002faec;
  }
  else {
    if (4 < iVar1) {
      dest->code = '\0';
      return;
    }
  }
  *dest = *target;
LAB_8002faec:
  dest->code = '\0';
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ MainRenderLevel(struct _StreamUnit *currentUnit /*$s1*/, unsigned long **drawot /*$s7*/)
 // line 1628, offset 0x8002fb04
	/* begin block 1 */
		// Start line: 1629
		// Start offset: 0x8002FB04
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
			// Start line: 1681
			// Start offset: 0x8002FBDC
			// Variables:
		// 		int time; // $a2
		/* end block 1.1 */
		// End offset: 0x8002FC10
		// End Line: 1687

		/* begin block 1.2 */
			// Start line: 1695
			// Start offset: 0x8002FC5C
			// Variables:
		// 		int tod; // $v1
		/* end block 1.2 */
		// End offset: 0x8002FCD8
		// End Line: 1709

		/* begin block 1.3 */
			// Start line: 1781
			// Start offset: 0x8002FE5C
			// Variables:
		// 		struct _SVector tmp; // stack offset -56
		// 		struct BSPTree *bsp; // $s0
		/* end block 1.3 */
		// End offset: 0x8002FF54
		// End Line: 1833
	/* end block 1 */
	// End offset: 0x8002FF68
	// End Line: 1839

	/* begin block 2 */
		// Start line: 3786
	/* end block 2 */
	// End Line: 3787

/* WARNING: This function may have set the stack pointer */
/* WARNING: Could not reconcile some variable overlaps */

void MainRenderLevel(_StreamUnit *currentUnit,ulong **drawot)

{
  MATRIX *pMVar1;
  LightInfo *lightInfo;
  _Instance *p_Var2;
  ulong *puVar3;
  ushort uVar4;
  int unitID;
  uint uVar5;
  Level *level;
  int **ppiVar6;
  _Instance *p_Var7;
  int iVar8;
  _Terrain *terrain;
  int **local_64;
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
                    /* WARNING: Read-only address (ram,0x800d1f9c) is written */
  clearRect.g0 = level->backColorG;
                    /* WARNING: Read-only address (ram,0x800d1f9d) is written */
  clearRect.b0 = level->backColorB;
                    /* WARNING: Read-only address (ram,0x800d1f9e) is written */
  BLK_FILL_800d1fa8.r0 = level->backColorR;
                    /* WARNING: Read-only address (ram,0x800d1fac) is written */
  BLK_FILL_800d1fa8.g0 = level->backColorG;
                    /* WARNING: Read-only address (ram,0x800d1fad) is written */
  BLK_FILL_800d1fa8.b0 = level->backColorB;
                    /* WARNING: Read-only address (ram,0x800d1fae) is written */
  if ((int)gameTrackerX.gameData.asmData.MorphTime == 1000) {
    if (gameTrackerX.gameData.asmData.MorphType == 1) {
      local_30[0] = *(_ColorType *)&level->specturalColorR;
    }
    else {
      local_30[0] = *(_ColorType *)&level->backColorR;
    }
  }
  else {
    unitID = ((int)gameTrackerX.gameData.asmData.MorphTime << 0xc) / 1000;
    if (gameTrackerX.gameData.asmData.MorphType == 1) {
      unitID = 0x1000 - unitID;
    }
    LoadAverageCol(&level->specturalColorR,&level->backColorR,unitID,0x1000 - unitID,
                   (undefined *)local_30);
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
                    /* WARNING: Read-only address (ram,0x800d1f9c) is written */
  clearRect.r0 = (uchar)depthQBackColor;
                    /* WARNING: Read-only address (ram,0x800d1f9d) is written */
  clearRect.g0 = depthQBackColor._1_1_;
                    /* WARNING: Read-only address (ram,0x800d1f9e) is written */
  clearRect.b0 = depthQBackColor._2_1_;
                    /* WARNING: Read-only address (ram,0x800d1fac) is written */
  BLK_FILL_800d1fa8.r0 = (uchar)depthQBackColor;
                    /* WARNING: Read-only address (ram,0x800d1fad) is written */
  BLK_FILL_800d1fa8.g0 = depthQBackColor._1_1_;
                    /* WARNING: Read-only address (ram,0x800d1fae) is written */
  BLK_FILL_800d1fa8.b0 = depthQBackColor._2_1_;
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
  PIPE3D_InstanceListTransformAndDraw(level,&gameTrackerX,drawot,(_CameraCore_Type *)&theCamera);
  DRAW_CalculateChromeMapping(polytopeList,terrain,(_CameraCore_Type *)&theCamera,&gameTrackerX);
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
  iVar8 = 0;
  if (0 < (int)terrain->morphNormalIdx) {
    do {
      p_Var2 = gameTrackerX.gameData.asmData.lightInstances[0].lightInstance;
      ppiVar6 = (int **)((int)&terrain->signals->numSignals + iVar8);
      if ((-1 < *(short *)((int)ppiVar6 + 0x1a)) && ((*(ushort *)((int)ppiVar6 + 0x12) & 1) == 0)) {
        p_Var7 = (_Instance *)0x0;
        if ((*(ushort *)((int)ppiVar6 + 0x12) & 0x40) != 0) {
          gameTrackerX.gameData.asmData.lightInstances[0].lightInstance = (_Instance *)0x0;
          p_Var7 = p_Var2;
        }
        uVar5 = (local_60 & 0xffff) - (uint)*(ushort *)(ppiVar6 + 3);
        local_38 = -(short)uVar5;
        uVar4 = local_60._2_2_ - *(short *)((int)ppiVar6 + 0xe);
        theCamera.core.position._0_4_ = uVar5 & 0xffff | (uint)uVar4 << 0x10;
        local_36 = -uVar4;
        theCamera.core.position.z = local_5c - *(short *)(ppiVar6 + 4);
        local_34 = -theCamera.core.position.z;
        ApplyMatrix(&local_58,&local_38,(theCamera.core.wcTransform)->t);
        BSP_MarkVisibleLeaves_S(ppiVar6,(undefined4 *)&theCamera,(int *)polytopeList);
        local_64 = ppiVar6 + 3;
        puVar3 = (ulong *)(*(code *)gameTrackerX.drawDisplayPolytopeListFunc)
                                    (polytopeList,terrain,&theCamera,gameTrackerX.primPool);
        (gameTrackerX.primPool)->nextPrim = puVar3;
        if ((*(ushort *)((int)ppiVar6 + 0x12) & 0x40) != 0) {
          gameTrackerX.gameData.asmData.lightInstances[0].lightInstance = p_Var7;
        }
      }
      unitID = unitID + 1;
      iVar8 = iVar8 + 0x24;
    } while (unitID < (int)terrain->morphNormalIdx);
  }
  lightInfo = gLightInfo;
  pMVar1 = theCamera.core.wcTransform;
  unitID = (int)RENDER_currentStreamUnitID;
  theCamera.core.position._0_4_ = local_60;
  theCamera.core.position.z = local_5c;
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
  FX_DrawList(fxTracker,&gameTrackerX,(ulong **)gameTrackerX.defVVRemoveDist,
              (MATRIX *)theCamera.core.wcTransform);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ StreamIntroInstancesForUnit(struct _StreamUnit *currentUnit /*$a1*/)
 // line 1856, offset 0x80030054
	/* begin block 1 */
		// Start line: 1857
		// Start offset: 0x80030054
	/* end block 1 */
	// End offset: 0x80030084
	// End Line: 1872

	/* begin block 2 */
		// Start line: 4397
	/* end block 2 */
	// End Line: 4398

void StreamIntroInstancesForUnit(_StreamUnit *currentUnit)

{
  if (currentUnit->used == 2) {
    SBSP_IntroduceInstances(currentUnit->level->terrain,currentUnit->StreamUnitID);
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ StreamRenderLevel(struct _StreamUnit *currentUnit /*$s0*/, struct Level *mainLevel /*$a1*/, unsigned long **drawot /*$s6*/, long portalFogColor /*$s1*/)
 // line 1874, offset 0x80030094
	/* begin block 1 */
		// Start line: 1875
		// Start offset: 0x80030094
		// Variables:
	// 		struct GameTracker *gameTracker; // $s4
	// 		struct Level *level; // $s2
	// 		struct _Terrain *terrain; // $s3
	// 		int curTree; // $s1
	// 		int farplanesave; // $s7
	// 		struct _Position cam_pos_save; // stack offset -88
	// 		struct MATRIX cam_mat_save; // stack offset -80

		/* begin block 1.1 */
			// Start line: 1957
			// Start offset: 0x80030240
			// Variables:
		// 		struct _SVector tmp; // stack offset -48
		// 		struct BSPTree *bsp; // $s0
		/* end block 1.1 */
		// End offset: 0x8003030C
		// End Line: 2002
	/* end block 1 */
	// End offset: 0x80030320
	// End Line: 2011

	/* begin block 2 */
		// Start line: 4433
	/* end block 2 */
	// End Line: 4434

long StreamRenderLevel(_StreamUnit *currentUnit,Level *mainLevel,ulong **drawot,long portalFogColor)

{
  uint uVar1;
  short sVar2;
  MATRIX *pMVar3;
  long lVar4;
  LightInfo *lightInfo;
  int unitID;
  ulong *puVar5;
  ushort uVar6;
  uint uVar7;
  int **ppiVar8;
  Level *level;
  int iVar9;
  _Terrain *terrain;
  short sStack86;
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
  
  lVar4 = theCamera.core.farPlane;
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
  PIPE3D_InstanceListTransformAndDraw(level,&gameTrackerX,drawot,(_CameraCore_Type *)&theCamera);
  DRAW_CalculateChromeMapping(polytopeList,terrain,(_CameraCore_Type *)&theCamera,&gameTrackerX);
  sVar2 = theCamera.core.position.z;
  uVar1 = theCamera.core.position._0_4_;
  local_50 = *(undefined4 *)(theCamera.core.wcTransform)->m;
  local_4c = *(undefined4 *)((theCamera.core.wcTransform)->m + 2);
  local_48 = *(undefined4 *)((theCamera.core.wcTransform)->m + 4);
  local_44 = *(undefined4 *)((theCamera.core.wcTransform)->m + 6);
  local_40 = *(undefined4 *)((theCamera.core.wcTransform)->m + 8);
  local_3c = (theCamera.core.wcTransform)->t[0];
  local_38 = (theCamera.core.wcTransform)->t[1];
  local_34 = (theCamera.core.wcTransform)->t[2];
  unitID = 0;
  if (0 < (int)terrain->morphNormalIdx) {
    iVar9 = 0;
    do {
      ppiVar8 = (int **)((int)&terrain->signals->numSignals + iVar9);
      if ((-1 < *(short *)((int)ppiVar8 + 0x1a)) && ((*(ushort *)((int)ppiVar8 + 0x12) & 1) == 0)) {
        sStack86 = (short)(uVar1 >> 0x10);
        uVar7 = (uVar1 & 0xffff) - (uint)*(ushort *)(ppiVar8 + 3);
        local_30 = -(short)uVar7;
        uVar6 = sStack86 - *(short *)((int)ppiVar8 + 0xe);
        theCamera.core.position._0_4_ = uVar7 & 0xffff | (uint)uVar6 << 0x10;
        local_2e = -uVar6;
        theCamera.core.position.z = sVar2 - *(short *)(ppiVar8 + 4);
        local_2c = -theCamera.core.position.z;
        ApplyMatrix(&local_50,&local_30,(theCamera.core.wcTransform)->t);
        BSP_MarkVisibleLeaves_S(ppiVar8,(undefined4 *)&theCamera,(int *)polytopeList);
        puVar5 = (ulong *)(*(code *)gameTrackerX.drawDisplayPolytopeListFunc)
                                    (polytopeList,terrain,&theCamera,gameTrackerX.primPool,drawot,
                                     ppiVar8 + 3);
        (gameTrackerX.primPool)->nextPrim = puVar5;
      }
      unitID = unitID + 1;
      iVar9 = iVar9 + 0x24;
    } while (unitID < (int)terrain->morphNormalIdx);
  }
  lightInfo = gLightInfo;
  pMVar3 = theCamera.core.wcTransform;
  unitID = (int)RENDER_currentStreamUnitID;
  InStreamUnit = 1;
  theCamera.core.position._0_4_ = uVar1;
  theCamera.core.position.z = sVar2;
  *(undefined4 *)(theCamera.core.wcTransform)->m = local_50;
  *(undefined4 *)(pMVar3->m + 2) = local_4c;
  *(undefined4 *)(pMVar3->m + 4) = local_48;
  *(undefined4 *)(pMVar3->m + 6) = local_44;
  *(undefined4 *)(pMVar3->m + 8) = local_40;
  pMVar3->t[0] = local_3c;
  pMVar3->t[1] = local_38;
  pMVar3->t[2] = local_34;
  SBSP_IntroduceInstancesAndLights(terrain,(_CameraCore_Type *)&theCamera,lightInfo,unitID);
  theCamera.core.farPlane = lVar4;
  InStreamUnit = 0;
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_FlipScreenAndDraw(struct GameTracker *gameTracker /*$s0*/, unsigned long **drawot /*$s1*/)
 // line 2042, offset 0x800303dc
	/* begin block 1 */
		// Start line: 4922
	/* end block 1 */
	// End Line: 4923

void GAMELOOP_FlipScreenAndDraw(GameTracker *gameTracker,ulong **drawot)

{
  int iVar1;
  uint uVar2;
  
  do {
    iVar1 = CheckVolatile(gameTracker->drawTimerReturn);
  } while (iVar1 != 0);
  PutDrawEnv((undefined4 *)(&draw + gameTracker->drawPage));
  do {
    iVar1 = CheckVolatile(gameTracker->reqDisp);
  } while (iVar1 != 0);
  uVar2 = GetRCnt(0xf2000000);
  *(ulong **)&gameTracker->drawTimerReturn = &gameTracker->timeMult;
  iVar1 = (gameTracker->gameData).asmData.dispPage;
  gameTracker->usecsStartDraw = uVar2 & 0xffff | gameTimer << 0x10;
  (gameTracker->gameData).asmData.dispPage = 1 - iVar1;
  DrawOTag(drawot + 0xbff);
  ResetPrimPool();
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_SwitchTheDrawBuffer(unsigned long **drawot /*$a3*/)
 // line 2075, offset 0x800304a0
	/* begin block 1 */
		// Start line: 2076
		// Start offset: 0x800304A0

		/* begin block 1.1 */
			// Start line: 2081
			// Start offset: 0x800304BC
			// Variables:
		// 		struct BLK_FILL *blkfill; // $a0
		/* end block 1.1 */
		// End offset: 0x800304BC
		// End Line: 2081

		/* begin block 1.2 */
			// Start line: 2097
			// Start offset: 0x8003052C
			// Variables:
		// 		struct BLK_FILL *blkfill; // $v1
		/* end block 1.2 */
		// End offset: 0x80030550
		// End Line: 2099
	/* end block 1 */
	// End offset: 0x80030590
	// End Line: 2121

	/* begin block 2 */
		// Start line: 4997
	/* end block 2 */
	// End Line: 4998

void GAMELOOP_SwitchTheDrawBuffer(ulong **drawot)

{
  int iVar1;
  ulong *puVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  
  if ((gameTrackerX.gameFlags & 0x8000000U) == 0) {
    puVar2 = (gameTrackerX.primPool)->nextPrim;
    uVar3 = *(ulong *)&(&clearRect)[gameTrackerX.drawPage].r0;
    uVar4 = *(ulong *)&(&clearRect)[gameTrackerX.drawPage].x0;
    uVar5 = *(ulong *)&(&clearRect)[gameTrackerX.drawPage].w;
    *puVar2 = (&clearRect)[gameTrackerX.drawPage].tag;
    puVar2[1] = uVar3;
    puVar2[2] = uVar4;
    puVar2[3] = uVar5;
    (gameTrackerX.primPool)->nextPrim = puVar2 + 4;
    *puVar2 = (uint)drawot[0xbff] & 0xffffff | 0x3000000;
    drawot[0xbff] = (ulong *)((uint)puVar2 & 0xffffff);
  }
  else {
    *(ushort *)(gameTrackerX.forcedStartPosition._0_4_ + 10) =
         (&clearRect)[gameTrackerX.drawPage].y0;
  }
  do {
    iVar1 = DrawSync(1);
  } while (iVar1 != 0);
  if (gameTrackerX.drawTimerReturn != (long *)0x0) {
    gameTrackerX.drawTimerReturn = (long *)0x0;
    gameTrackerX.reqDisp =
         (void *)((int)gameTrackerX.disp + gameTrackerX.gameData.asmData.dispPage * 0x14);
  }
  PutDrawEnv((undefined4 *)(&draw + gameTrackerX.drawPage));
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_SetupRenderFunction(struct GameTracker *gameTracker /*$a0*/)
 // line 2128, offset 0x800305cc
	/* begin block 1 */
		// Start line: 5123
	/* end block 1 */
	// End Line: 5124

	/* begin block 2 */
		// Start line: 5138
	/* end block 2 */
	// End Line: 5139

void GAMELOOP_SetupRenderFunction(GameTracker *gameTracker)

{
  *(undefined **)&gameTracker->drawAnimatedModelFunc = &DRAW_AnimatedModel_S;
  *(undefined **)&gameTracker->drawDisplayPolytopeListFunc = &DRAW_DisplayPolytopeList_S;
  return;
}



// decompiled code
// original method signature: 
// struct _StreamUnit * /*$ra*/ GAMELOOP_GetMainRenderUnit()
 // line 2154, offset 0x800305e8
	/* begin block 1 */
		// Start line: 2155
		// Start offset: 0x800305E8
		// Variables:
	// 		struct _StreamUnit *streamUnit; // $s0

		/* begin block 1.1 */
			// Start line: 2166
			// Start offset: 0x80030618
			// Variables:
		// 		struct _Instance *focusInstance; // $s1

			/* begin block 1.1.1 */
				// Start line: 2187
				// Start offset: 0x80030678
				// Variables:
			// 		struct _StreamUnit *cameraUnit; // $v0
			/* end block 1.1.1 */
			// End offset: 0x80030694
			// End Line: 2195
		/* end block 1.1 */
		// End offset: 0x80030694
		// End Line: 2196
	/* end block 1 */
	// End offset: 0x80030698
	// End Line: 2200

	/* begin block 2 */
		// Start line: 5175
	/* end block 2 */
	// End Line: 5176

/* WARNING: Unknown calling convention yet parameter storage is locked */

_StreamUnit * GAMELOOP_GetMainRenderUnit(void)

{
  _Instance *p_Var1;
  _StreamUnit *p_Var2;
  _StreamUnit *p_Var3;
  
  p_Var1 = theCamera.focusInstance;
  if (theCamera.mode == 5) {
    p_Var2 = STREAM_WhichUnitPointerIsIn(theCamera.data.Cinematic.posSpline);
  }
  else {
    if ((theCamera.focusInstance == gameTrackerX.playerInstance) &&
       (gameTrackerX.SwitchToNewStreamUnit != 0)) {
      p_Var2 = STREAM_GetStreamUnitWithID(gameTrackerX.moveRazielToStreamID);
      if (p_Var2 == (_StreamUnit *)0x0) {
        p_Var2 = STREAM_GetStreamUnitWithID(p_Var1->currentStreamUnitID);
        return p_Var2;
      }
    }
    else {
      p_Var2 = STREAM_GetStreamUnitWithID((theCamera.focusInstance)->currentStreamUnitID);
    }
    p_Var3 = COLLIDE_CameraWithStreamSignals(&theCamera);
    if (p_Var3 != (_StreamUnit *)0x0) {
      p_Var2 = p_Var3;
    }
  }
  return p_Var2;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_DisplayFrame(struct GameTracker *gameTracker /*stack 0*/)
 // line 2205, offset 0x800306ac
	/* begin block 1 */
		// Start line: 2206
		// Start offset: 0x800306AC
		// Variables:
	// 		unsigned long **drawot; // stack offset -56
	// 		struct Level *mainLevel; // stack offset -52
	// 		struct StreamUnitPortal *streamPortal; // $fp
	// 		int numportals; // stack offset -48
	// 		int d; // $s4
	// 		struct _StreamUnit *mainStreamUnit; // $s7

		/* begin block 1.1 */
			// Start line: 2292
			// Start offset: 0x80030800
			// Variables:
		// 		struct _StreamUnit *toStreamUnit; // $s3
		// 		long toStreamUnitID; // $s6
		// 		struct StreamUnitPortal *streamPortal2; // $s0
		// 		int i; // $s1
		// 		int draw; // $s2
		// 		struct RECT cliprect; // stack offset -64
		/* end block 1.1 */
		// End offset: 0x80030A3C
		// End Line: 2397
	/* end block 1 */
	// End offset: 0x80030CC4
	// End Line: 2557

	/* begin block 2 */
		// Start line: 5280
	/* end block 2 */
	// End Line: 5281

void GAMELOOP_DisplayFrame(GameTracker *gameTracker)

{
  ushort uVar1;
  bool bVar2;
  _StreamUnit *currentUnit;
  long lVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  uint uVar8;
  ulong **polyAddr;
  uint uVar9;
  StreamUnitPortal *portal;
  STracker *currentUnit_00;
  int iVar10;
  _StreamUnit *currentUnit_01;
  int iVar11;
  ushort *puVar12;
  int iVar13;
  StreamUnitPortal *curStreamPortal;
  RECT local_40;
  ulong **local_38;
  Level *local_34;
  int local_30;
  
  local_38 = (ulong **)gameTracker->defVVRemoveDist;
  if ((gameTrackerX.gameFlags & 0x8000000U) == 0) {
    DAT_800d2230 = 0;
    gameTrackerX.displayFrameCount = gameTrackerX.displayFrameCount + 1;
    GAMELOOP_SetupRenderFunction(&gameTrackerX);
    currentUnit = GAMELOOP_GetMainRenderUnit();
    local_34 = currentUnit->level;
    if ((gameTracker->debugFlags & 4U) != 0) {
      FONT_Print("Cameraunit: %s\n");
    }
    RENDER_currentStreamUnitID = *(short *)&currentUnit->StreamUnitID;
    theCamera.core.rightX = 0x140;
    theCamera.core.leftX = 0;
    theCamera.core.topY = 0;
    theCamera.core.bottomY = 0xf0;
    CAMERA_SetViewVolume(&theCamera);
    lVar3 = MEMPACK_MemoryValidFunc((char *)local_34);
    if (lVar3 != 0) {
      if ((uint)local_34->fogFar != theCamera.core.farPlane) {
        theCamera.core.farPlane = (uint)local_34->fogFar;
      }
      if ((gameTracker->debugFlags & 0x8000U) == 0) {
        MainRenderLevel(currentUnit,local_38);
      }
    }
    piVar4 = (int *)local_34->terrain->StreamUnits;
    iVar11 = 0;
    local_30 = *piVar4;
    curStreamPortal = (StreamUnitPortal *)(piVar4 + 1);
    if (0 < local_30) {
      puVar12 = (ushort *)((int)piVar4 + 0x22);
      do {
        currentUnit_01 = *(_StreamUnit **)(puVar12 + 5);
        iVar13 = *(int *)(puVar12 + -5);
        if ((currentUnit_01 == (_StreamUnit *)0x0) ||
           (currentUnit_01->FrameCount != gameTrackerX.displayFrameCount)) {
          local_40.x = 0x200;
          local_40.y = 0xf0;
          local_40.w = -0x200;
          local_40.h = -0xf0;
          theCamera.core.rightX = 0x140;
          theCamera.core.leftX = 0;
          theCamera.core.topY = 0;
          theCamera.core.bottomY = 0xf0;
          CAMERA_SetViewVolume(&theCamera);
          iVar10 = 0;
          bVar2 = false;
          portal = (StreamUnitPortal *)((int)local_34->terrain->StreamUnits + 4);
          if (0 < local_30) {
            do {
              if ((portal->streamID == iVar13) &&
                 (iVar5 = STREAM_GetClipRect(portal,&local_40), iVar5 != 0)) {
                bVar2 = true;
              }
              iVar10 = iVar10 + 1;
              portal = portal + 1;
            } while (iVar10 < local_30);
          }
          if (bVar2) {
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
            SetRotMatrix((undefined4 *)theCamera.core.wcTransform);
            SetTransMatrix((int)theCamera.core.wcTransform);
            if ((*puVar12 & 1) == 0) {
              if ((currentUnit_01 != (_StreamUnit *)0x0) &&
                 (currentUnit_01->FrameCount != gameTrackerX.displayFrameCount)) {
                currentUnit_01->FrameCount = gameTrackerX.displayFrameCount;
                STREAM_RenderAdjacantUnit
                          (local_38,curStreamPortal,currentUnit_01,currentUnit,&local_40);
              }
            }
            else {
              if ((currentUnit->flags & 8U) == 0) {
                WARPGATE_IsItActive(currentUnit);
              }
              else {
                if (currentUnit_01 != (_StreamUnit *)0x0) {
                  if (currentUnit_01->FrameCount == gameTrackerX.displayFrameCount)
                  goto LAB_80030a40;
                  currentUnit_01->FrameCount = gameTrackerX.displayFrameCount;
                }
                STREAM_RenderWarpGate(local_38,curStreamPortal,currentUnit,&local_40);
              }
            }
          }
          else {
            if ((currentUnit_01 != (_StreamUnit *)0x0) &&
               (currentUnit_01->FrameCount != gameTrackerX.displayFrameCount)) {
              currentUnit_01->FrameCount = gameTrackerX.displayFrameCount;
              StreamIntroInstancesForUnit(currentUnit_01);
            }
          }
        }
LAB_80030a40:
        iVar11 = iVar11 + 1;
        puVar12 = puVar12 + 0x2e;
        curStreamPortal = curStreamPortal + 1;
      } while (iVar11 < local_30);
    }
    iVar11 = 0;
    currentUnit_00 = &StreamTracker;
    do {
      if ((*(short *)currentUnit_00->StreamList == 2) &&
         (*(ulong *)currentUnit_00->StreamList != gameTrackerX.displayFrameCount)) {
        *(ulong *)currentUnit_00->StreamList = gameTrackerX.displayFrameCount;
        StreamIntroInstancesForUnit((_StreamUnit *)currentUnit_00);
      }
      iVar11 = iVar11 + 1;
      currentUnit_00 = (STracker *)(currentUnit_00->StreamList + 1);
    } while (iVar11 < 0x10);
    theCamera.core.rightX = 0x140;
    theCamera.core.leftX = 0;
    theCamera.core.topY = 0;
    theCamera.core.bottomY = 0xf0;
    CAMERA_SetViewVolume(&theCamera);
    uVar1 = GlobalSave->flags;
    GlobalSave->flags = uVar1 & 1;
    if (((uVar1 & 1) == 0) &&
       (((gameTracker->wipeType != 0xb || (gameTracker->wipeTime == 0)) &&
        ((gameTracker->debugFlags2 & 0x800U) != 0)))) {
      FX_Spiral(gameTrackerX.primPool,local_38);
    }
  }
  HUD_Draw();
  DEBUG_Draw(gameTracker,local_38);
  FONT_Flush();
  GAMELOOP_SwitchTheDrawBuffer(local_38);
  uVar6 = GetRCnt(0xf2000000);
  uVar9 = gameTracker->vblFrames;
  uVar8 = gameTracker[1].gameData.asmData.lightInstances[0].r;
  gameTracker[1].gameData.asmData.drawBackFaces = uVar6 & 0xffff | gameTimer << 0x10;
  if (uVar8 < uVar9) {
    if ((ushort *)gameTracker->reqDisp != (ushort *)0x0) {
      PutDispEnv((ushort *)gameTracker->reqDisp);
      gameTracker->reqDisp = (void *)0x0;
      gameTracker->vblFrames = 0;
    }
  }
  else {
    do {
      iVar11 = CheckVolatile(gameTracker->reqDisp);
    } while (iVar11 != 0);
  }
  uVar7 = TIMER_TimeDiff(gameTracker[1].gameData.asmData.drawBackFaces);
  polyAddr = local_38 + 0xbff;
  iVar11 = (gameTracker->gameData).asmData.dispPage;
  gameTracker[1].gameData.asmData.drawBackFaces = uVar7;
  (gameTracker->gameData).asmData.dispPage = 1 - iVar11;
  DEBUG_DrawShrinkCels(polyAddr);
  GAMELOOP_HandleScreenWipes(local_38);
  uVar6 = GetRCnt(0xf2000000);
  *(ulong **)&gameTracker->drawTimerReturn = &gameTracker->timeMult;
  gameTracker->usecsStartDraw = uVar6 & 0xffff | gameTimer << 0x10;
  if ((gameTrackerX.gameFlags & 0x8000000U) != 0) {
    *gameTrackerX._500_4_ = *gameTrackerX._500_4_ | 0xffffff;
    *gameTrackerX._500_4_ = *gameTrackerX._500_4_ & 0xff000000 | (uint)polyAddr & 0xffffff;
    polyAddr = gameTrackerX.forcedStartPosition._0_4_;
  }
  DrawOTag(polyAddr);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ResetPrimPool()
 // line 2560, offset 0x80030cf4
	/* begin block 1 */
		// Start line: 6209
	/* end block 1 */
	// End Line: 6210

/* WARNING: Unknown calling convention yet parameter storage is locked */

void ResetPrimPool(void)

{
  int iVar1;
  
  ResetDrawPage();
  if ((gameTrackerX.gameFlags & 0x8000000U) == 0) {
    if (gameTrackerX.primPool == primPool2) {
      gameTrackerX.primPool = PTR_800d1c78;
    }
    else {
      gameTrackerX.primPool = primPool2;
    }
    (gameTrackerX.primPool)->nextPrim = (gameTrackerX.primPool)->prim;
  }
  else {
    if (gameTrackerX.drawPage == 0) {
      iVar1 = 0xbb8c;
    }
    else {
      iVar1 = 0x1194c;
    }
    (gameTrackerX.primPool)->nextPrim = (ulong *)((int)&(gameTrackerX.primPool)->numPrims + iVar1);
  }
  (gameTrackerX.primPool)->numPrims = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SaveOT()
 // line 2588, offset 0x80030da0
	/* begin block 1 */
		// Start line: 2589
		// Start offset: 0x80030DA0
		// Variables:
	// 		struct P_TAG *tag; // $a0
	// 		struct P_TAG *last; // $s0
	// 		struct P_TAG *lastlast; // $s1
	/* end block 1 */
	// End offset: 0x80030F2C
	// End Line: 2636

	/* begin block 2 */
		// Start line: 6265
	/* end block 2 */
	// End Line: 6266

/* WARNING: Unknown calling convention yet parameter storage is locked */

void SaveOT(void)

{
  char cVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  
  DrawSync(0);
  puVar5 = (uint *)(gameTrackerX.defVVRemoveDist + 0x2ffc);
  cVar1 = *(char *)(gameTrackerX.defVVRemoveDist + 0x2fff);
  puVar7 = (uint *)0x0;
  while (cVar1 == '\0') {
    uVar4 = *puVar5;
    puVar5 = (uint *)(uVar4 & 0xffffff | 0x80000000);
    if ((uVar4 & 0xffffff) == 0xffffff) goto LAB_80030e1c;
    cVar1 = *(char *)((int)puVar5 + 3);
  }
  if ((*puVar5 & 0xffffff) == 0xffffff) {
LAB_80030e1c:
    gameTrackerX.forcedStartPosition._0_4_ = (uint *)0x0;
  }
  else {
    puVar2 = puVar5;
    puVar3 = (uint *)0x0;
    gameTrackerX.forcedStartPosition._0_4_ = puVar5;
    if ((*puVar5 & 0xffffff) != 0xffffff) {
      do {
        while (puVar6 = puVar3, puVar5 = puVar2, *(char *)((int)puVar5 + 3) != '\0') {
          if ((*puVar5 & 0xffffff) == 0xffffff) goto LAB_80030f08;
          puVar2 = (uint *)(*puVar5 & 0xffffff | 0x80000000);
          puVar3 = puVar5;
          puVar7 = puVar6;
        }
        if ((*puVar5 & 0xffffff) == 0xffffff) goto LAB_80030f08;
        cVar1 = *(char *)((int)puVar5 + 3);
        while ((cVar1 == '\0' && ((*puVar5 & 0xffffff) != 0xffffff))) {
          puVar5 = (uint *)(*puVar5 & 0xffffff | 0x80000000);
          cVar1 = *(char *)((int)puVar5 + 3);
        }
        *puVar6 = *puVar6 & 0xff000000 | (uint)puVar5 & 0xffffff;
        puVar2 = puVar5;
        puVar3 = puVar6;
      } while ((*puVar5 & 0xffffff) != 0xffffff);
      if ((*puVar5 & 0xffffff) != 0xffffff) {
        gameTrackerX._500_4_ = puVar5;
        return;
      }
    }
LAB_80030f08:
    gameTrackerX._500_4_ = puVar5;
    if (puVar7 != (uint *)0x0) {
      gameTrackerX._500_4_ = puVar7;
      *puVar7 = *puVar7 | 0xffffff;
    }
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ ResetDrawPage()
 // line 2638, offset 0x80030f40
	/* begin block 1 */
		// Start line: 2639
		// Start offset: 0x80030F40

		/* begin block 1.1 */
			// Start line: 2639
			// Start offset: 0x80030F40
			// Variables:
		// 		unsigned long **temp; // $v0
		/* end block 1.1 */
		// End offset: 0x80030F40
		// End Line: 2639
	/* end block 1 */
	// End offset: 0x80030F40
	// End Line: 2639

	/* begin block 2 */
		// Start line: 6381
	/* end block 2 */
	// End Line: 6382

/* WARNING: Unknown calling convention yet parameter storage is locked */

void ResetDrawPage(void)

{
  long lVar1;
  
  lVar1 = gameTrackerX.defRemoveDist;
  gameTrackerX.defRemoveDist = gameTrackerX.defVVRemoveDist;
  gameTrackerX.drawPage = 1 - gameTrackerX.drawPage;
  gameTrackerX.defVVRemoveDist = lVar1;
  ClearOTagR((undefined4 *)lVar1,0xc00);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_Set24FPS()
 // line 2686, offset 0x80030f80
	/* begin block 1 */
		// Start line: 6489
	/* end block 1 */
	// End Line: 6490

	/* begin block 2 */
		// Start line: 6490
	/* end block 2 */
	// End Line: 6491

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_Set24FPS(void)

{
  DAT_800d2240 = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_Reset24FPS()
 // line 2692, offset 0x80030f90
	/* begin block 1 */
		// Start line: 6501
	/* end block 1 */
	// End Line: 6502

	/* begin block 2 */
		// Start line: 6502
	/* end block 2 */
	// End Line: 6503

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_Reset24FPS(void)

{
  DAT_800d2240 = 0;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_DoTimeProcess()
 // line 2697, offset 0x80030f9c
	/* begin block 1 */
		// Start line: 2698
		// Start offset: 0x80030F9C
		// Variables:
	// 		int holdTime; // $s1

		/* begin block 1.1 */
			// Start line: 2733
			// Start offset: 0x80031080
			// Variables:
		// 		int lockRate; // $a1
		// 		unsigned long last; // $a0
		/* end block 1.1 */
		// End offset: 0x80031120
		// End Line: 2768
	/* end block 1 */
	// End offset: 0x80031178
	// End Line: 2784

	/* begin block 2 */
		// Start line: 6511
	/* end block 2 */
	// End Line: 6512

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_DoTimeProcess(void)

{
  bool bVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = TIMER_GetTimeMS();
  if ((gameTrackerX.gameFlags & 0x10000000U) == 0) {
    gameTrackerX._620_4_ = TIMER_TimeDiff(gameTrackerX.frameRateLock);
    uVar3 = GetRCnt(0xf2000000);
    gameTrackerX.frameRateLock = uVar3 & 0xffff | gameTimer << 0x10;
    if (DAT_800d223c < 1) {
      DAT_800d223c = 1;
    }
    if (2 < DAT_800d223c) {
      DAT_800d223c = 2;
    }
    if ((gameTrackerX.currentSpectralTime == 0) || ((gameTrackerX.gameFlags & 0x10000000U) != 0)) {
      if (DAT_800d223c == 1) {
        gameTrackerX.totalTime = 0x21;
      }
      else {
        if (DAT_800d223c == 2) {
          gameTrackerX.totalTime = 0x32;
        }
      }
      uVar3 = (uint)((ulonglong)(gameTrackerX.totalTime << 0xc) * 0x3e0f83e1 >> 0x20);
    }
    else {
      uVar4 = 0x21;
      if ((DAT_800d223c != 1) && (DAT_800d223c == 2)) {
        uVar4 = 0x32;
      }
      uVar3 = uVar4;
      if (gameTrackerX.totalTime != 0xffffffff) {
        uVar3 = uVar2 - gameTrackerX.globalTimeMult;
      }
      bVar1 = uVar3 < uVar4;
      if ((DAT_800d223c == 1) && (bVar1 = uVar3 < uVar4, DAT_800d2240 != 0)) {
        uVar3 = uVar3 - 9;
        bVar1 = uVar3 < uVar4;
      }
      if ((!bVar1) && (uVar4 = uVar3, 0x42 < uVar3)) {
        uVar4 = 0x42;
      }
      uVar3 = (uint)((ulonglong)(uVar4 << 0xc) * 0x3e0f83e1 >> 0x20);
      gameTrackerX.totalTime = uVar4;
    }
    gameTrackerX.idleTime = uVar3 >> 3;
    DAT_800d2234 = 0;
    DAT_800d2238 = DAT_800d2238 + gameTrackerX.idleTime;
    while (gameTrackerX.visibleInstances = gameTrackerX.idleTime, 0x1000 < DAT_800d2238) {
      DAT_800d2234 = 1;
      DAT_800d2238 = DAT_800d2238 - 0x1000;
      gameTrackerX.fps30Count = gameTrackerX.fps30Count + 1;
    }
  }
  else {
    gameTrackerX.totalTime = 0xffffffff;
  }
  gameTrackerX.globalTimeMult = uVar2;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_Process(struct GameTracker *gameTracker /*$s5*/)
 // line 2791, offset 0x80031190
	/* begin block 1 */
		// Start line: 2792
		// Start offset: 0x80031190
		// Variables:
	// 		int d; // $s2

		/* begin block 1.1 */
			// Start line: 2828
			// Start offset: 0x80031234
			// Variables:
		// 		int useTime; // $s0

			/* begin block 1.1.1 */
				// Start line: 2831
				// Start offset: 0x80031244
				// Variables:
			// 		struct Level *level; // $v0
			/* end block 1.1.1 */
			// End offset: 0x80031268
			// End Line: 2836
		/* end block 1.1 */
		// End offset: 0x80031298
		// End Line: 2841

		/* begin block 1.2 */
			// Start line: 2945
			// Start offset: 0x80031460
			// Variables:
		// 		int i; // $s0

			/* begin block 1.2.1 */
				// Start line: 2952
				// Start offset: 0x8003148C
				// Variables:
			// 		struct _SFXMkr *sfxMkr; // $a2
			/* end block 1.2.1 */
			// End offset: 0x800314DC
			// End Line: 2963
		/* end block 1.2 */
		// End offset: 0x80031508
		// End Line: 2965
	/* end block 1 */
	// End offset: 0x80031820
	// End Line: 3166

	/* begin block 2 */
		// Start line: 6716
	/* end block 2 */
	// End Line: 6717

	/* begin block 3 */
		// Start line: 6720
	/* end block 3 */
	// End Line: 6721

/* WARNING: This function may have set the stack pointer */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GAMELOOP_Process(GameTracker *gameTracker)

{
  bool bVar1;
  int iVar2;
  Level *level;
  uchar **ppuVar3;
  STracker *pSVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  
  if (gEndGameNow == 0) {
    GAMELOOP_DoTimeProcess();
    if ((gameTrackerX.gameMode != 6) && ((gameTrackerX.streamFlags & 0x100000U) == 0)) {
      MORPH_UpdateTimeMult();
      GAMELOOP_CalcGameTime();
      if ((gameTracker->gameData).asmData.MorphType == 0) {
        bVar1 = true;
        if ((gameTrackerX.playerInstance != (_Instance *)0x0) &&
           (level = STREAM_GetLevelWithID((gameTrackerX.playerInstance)->currentStreamUnitID),
           level != (Level *)0x0)) {
          bVar1 = (level->unitFlags & 0x2000U) == 0;
        }
        if (bVar1) {
          gameTracker->currentTicks = gameTracker->currentTicks + gameTracker->totalTime;
        }
        gameTracker->spectralTimeMult = gameTracker->spectralTimeMult + gameTracker->totalTime;
      }
      else {
        gameTracker->materialTimeMult = gameTracker->materialTimeMult + gameTracker->totalTime;
      }
    }
    gameTracker->numGSignals = 0;
    GAMELOOP_ChangeMode();
    ResetPrimPool();
    memset(gameTracker->overrideData,0,0x28);
    if (gameTrackerX.gameMode != 6) {
      if ((gameTrackerX.streamFlags & 0x100000U) == 0) {
        if (gameTrackerX.SwitchToNewStreamUnit == 1) {
          STREAM_MoveIntoNewStreamUnit();
        }
        if ((VRAM_NeedToUpdateMorph != 0) && (iVar2 = STREAM_IsCdBusy((long *)0x0), iVar2 == 0)) {
          VRAM_UpdateMorphPalettes();
          VRAM_NeedToUpdateMorph = 0;
        }
        if ((gameTracker->gameData).asmData.MorphTime < 1000) {
          MORPH_Continue();
        }
        if ((gameTracker->streamFlags & 0x80000U) != 0) {
          gameTracker->streamFlags = gameTracker->streamFlags & 0xfff7ffff;
          UNDERWORLD_StartProcess();
        }
      }
      if ((gameTrackerX.gameMode != 6) && ((gameTrackerX.streamFlags & 0x100000U) == 0)) {
        EVENT_DoProcess();
        pSVar4 = &StreamTracker;
        do {
          if (pSVar4->StreamList[0].used == 2) {
            if (((pSVar4->StreamList[0].level)->PuzzleInstances != (EventPointers *)0x0) &&
               (((pSVar4->StreamList[0].flags & 1U) == 0 ||
                (pSVar4->StreamList[0].StreamUnitID == gameTrackerX.StreamUnitID)))) {
              if ((gameTrackerX.debugFlags2 & 0x100U) != 0) {
                FONT_Print("Processing unit %s\n");
              }
              level = pSVar4->StreamList[0].level;
              EVENT_ProcessEvents(level->PuzzleInstances,level);
            }
            EVENT_BSPProcess(pSVar4->StreamList[0].level);
            EVENT_ResetAllOneTimeVariables();
          }
          pSVar4 = (STracker *)(pSVar4->StreamList + 1);
        } while ((int)pSVar4 < -0x7ff2d1a8);
      }
    }
    iVar7 = 0;
    pSVar4 = &StreamTracker;
    iVar2 = iVar7;
    do {
      if ((pSVar4->StreamList[0].used == 2) &&
         (iVar5 = 0, 0 < (pSVar4->StreamList[0].level)->NumberOfSFXMarkers)) {
        iVar6 = 0;
        do {
          ppuVar3 = (uchar **)
                    (*(int *)(*(int *)((int)&StreamTracker.StreamList[0].level + iVar2) + 0xec) +
                    iVar6);
          if ((ppuVar3 != (uchar **)0x0) && (*ppuVar3 != (uchar *)0x0)) {
            SOUND_ProcessInstanceSounds
                      (*ppuVar3,(SoundInstance *)(ppuVar3 + 2),(_Position *)(ppuVar3 + 5),
                       (int)ppuVar3[7],(int)ppuVar3[8],0,(long *)0x0);
          }
          iVar5 = iVar5 + 1;
          iVar6 = iVar6 + 0x24;
        } while (iVar5 < (StreamTracker.StreamList[iVar7].level)->NumberOfSFXMarkers);
      }
      iVar2 = iVar2 + 0x40;
      iVar7 = iVar7 + 1;
      pSVar4 = (STracker *)(pSVar4->StreamList + 1);
    } while (iVar7 < 0x10);
    INSTANCE_ProcessFunctions(gameTracker->instanceList);
    INSTANCE_CleanUpInstanceList(gameTracker->instanceList,0);
    INSTANCE_DeactivateFarInstances(gameTracker);
    MONAPI_ProcessGenerator();
    GAMELOOP_UpdateWorldTimeOfDay();
    _DAT_1f800000 = theCamera.core.position._0_4_;
    _DAT_1f800004 = theCamera.core._4_4_;
    StackSave = (ulong)&stack0xffffffc0;
    G2Instance_BuildTransformsForList(gameTracker->instanceList->first);
    puVar8 = (undefined *)StackSave;
    if (gameTrackerX.gameMode != 6) {
      if ((gameTrackerX.streamFlags & 0x100000U) == 0) {
        FX_ProcessList(fxTracker);
      }
      puVar8 = (undefined *)StackSave;
      if (gameTrackerX.gameMode != 6) {
        if ((gameTrackerX.streamFlags & 0x100000U) == 0) {
          VM_Tick(0x100,*(undefined *)StackSave);
          if ((gameTracker->debugFlags2 & 0x10000U) != 0) {
            FONT_Print("Military Time %04d\n",*puVar8);
          }
          iVar2 = 0;
          pSVar4 = &StreamTracker;
          do {
            if (pSVar4->StreamList[0].used == 2) {
              VM_ProcessVMObjectList_S(pSVar4->StreamList[0].level,*puVar8);
            }
            iVar2 = iVar2 + 1;
            pSVar4 = (STracker *)(pSVar4->StreamList + 1);
          } while (iVar2 < 0x10);
        }
        if ((gameTrackerX.gameMode != 6) && ((gameTrackerX.streamFlags & 0x100000U) == 0)) {
          PLANAPI_UpdatePlanningDatabase(gameTracker,gameTrackerX.playerInstance,*puVar8);
        }
      }
    }
    DEBUG_Process(gameTracker,*puVar8);
    if ((gameTrackerX.gameMode != 6) && ((gameTrackerX.streamFlags & 0x100000U) == 0)) {
      COLLIDE_InstanceList(gameTracker->instanceList,*puVar8);
      COLLIDE_InstanceListTerrain(gameTracker->instanceList,*puVar8);
    }
    INSTANCE_AdditionalCollideFunctions(instanceList,*puVar8);
    if (gameTrackerX.gameMode != 6) {
      if ((gameTrackerX.streamFlags & 0x100000U) == 0) {
        COLLIDE_InstanceListWithSignals(instanceList,*puVar8);
        INSTANCE_SpatialRelationships(instanceList,*puVar8);
        LIGHT_CalcShadowPositions(gameTracker,*puVar8);
        INSTANCE_CleanUpInstanceList(gameTracker->instanceList,0x10,*puVar8);
      }
      if ((gameTrackerX.gameMode != 6) && ((gameTrackerX.streamFlags & 0x100000U) == 0)) {
        CAMERA_Process(&theCamera,*puVar8);
      }
    }
    PIPE3D_CalculateWCTransform(&theCamera,*puVar8);
    *(undefined2 *)&(theCamera.core.wcTransform2)->field_0x12 = 0;
    PIPE3D_InvertTransform(theCamera.core.cwTransform2,theCamera.core.wcTransform2,*puVar8);
    CAMERA_CalcVVClipInfo(&theCamera,*puVar8);
    if (gameTracker->levelChange != 0) {
      gameTracker->levelChange = 0;
    }
    SAVE_IntroduceBufferIntros(*puVar8);
    if (gameTracker->levelDone == 0) {
      GAMELOOP_DisplayFrame(gameTracker,*puVar8);
    }
    else {
      ResetDrawPage(*puVar8);
    }
    gameTracker->frameCount = gameTracker->frameCount + 1;
    gameTracker->debugFlags = gameTracker->debugFlags & 0xf7ffffff;
  }
  else {
    DEBUG_ExitGame();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_ModeStartRunning()
 // line 3168, offset 0x80031848
	/* begin block 1 */
		// Start line: 7545
	/* end block 1 */
	// End Line: 7546

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ModeStartRunning(void)

{
  if (((gameTrackerX.gameMode == 4) || (gameTrackerX.gameMode == 6)) &&
     (DEBUG_ExitMenus(), gameTrackerX.gameMode == 6)) {
    currentMenu = &standardMenu;
    SOUND_ResumeAllSound();
    VOICEXA_Resume();
    printf("UNPAUSING\n");
  }
  if ((gameTrackerX.gameFlags & 0x8000000U) != 0) {
    gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xf7ffffff;
    gameTrackerX.forcedStartPosition._0_4_ = 0;
    DrawSync(0);
  }
  gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xefffffff;
  (gameTrackerX.playerInstance)->flags = (gameTrackerX.playerInstance)->flags & 0xfffffeff;
  gameTrackerX.gameMode = 0;
  INSTANCE_Post(gameTrackerX.playerInstance,0x10000a,0);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_ModeStartPause()
 // line 3196, offset 0x80031924
	/* begin block 1 */
		// Start line: 7610
	/* end block 1 */
	// End Line: 7611

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_ModeStartPause(void)

{
  gameTrackerX.gameMode = 6;
  INSTANCE_Post(gameTrackerX.playerInstance,0x10000a,1);
  currentMenu = &pauseMenu;
  menu_set(gameTrackerX.menu,menudefs_pause_menu);
  SOUND_PauseAllSound();
  VOICEXA_Pause();
  gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x18000000;
  if (gameTrackerX.primPool == primPool2) {
    gameTrackerX.primPool = PTR_800d1c78;
  }
  else {
    gameTrackerX.primPool = primPool2;
  }
  (gameTrackerX.primPool)->nextPrim = (gameTrackerX.primPool)->prim;
  (gameTrackerX.primPool)->numPrims = 0;
  SaveOT();
  printf("PAUSING\n");
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_DemoSetup()
 // line 3220, offset 0x800319ec
	/* begin block 1 */
		// Start line: 7670
	/* end block 1 */
	// End Line: 7671

	/* begin block 2 */
		// Start line: 7671
	/* end block 2 */
	// End Line: 7672

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMELOOP_DemoSetup(void)

{
  gameTrackerX.multGameTime = playerCameraMode;
  playerCameraMode = 0xd;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMELOOP_ChangeMode()
 // line 3240, offset 0x80031a04
	/* begin block 1 */
		// Start line: 3241
		// Start offset: 0x80031A04
		// Variables:
	// 		long *controlCommand; // $s0
	/* end block 1 */
	// End offset: 0x80031D5C
	// End Line: 3401

	/* begin block 2 */
		// Start line: 6477
	/* end block 2 */
	// End Line: 6478

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
        gameTrackerX._458_2_ = 1;
        INSTANCE_Post(gameTrackerX.playerInstance,0x100010,1);
        (gameTrackerX.playerInstance)->flags = (gameTrackerX.playerInstance)->flags & 0xfffff7ff;
      }
      else {
        if ((gameTrackerX.controlCommand[0][0] & 0xa02U) == 0xa02) {
          theCamera.forced_movement = 1;
          ((gameTrackerX.playerInstance)->position).z =
               ((gameTrackerX.playerInstance)->position).z + -100;
          (gameTrackerX.playerInstance)->zVel = 0;
          gameTrackerX._458_2_ = 0;
          INSTANCE_Post(gameTrackerX.playerInstance,0x100010,0);
          gameTrackerX.gameMode = 0;
        }
      }
    }
    if ((gameTrackerX.debugFlags & 0x40000U) != 0) goto LAB_80031af8;
  }
  else {
LAB_80031af8:
    if ((gameTrackerX.decoupleGame & 2U) == 0) goto LAB_80031c24;
  }
  if ((((gameTrackerX.controlCommand[0][1] & 0x60U) == 0x60) ||
      (gameTrackerX.controlCommand[0][1] == 0x1000)) &&
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
LAB_80031c24:
  if (((((gameTrackerX.controlCommand[0][1] & 0x4000U) == 0) && (gamePadControllerOut < 6)) ||
      ((gameTrackerX.gameMode != 0 || ((gameTrackerX.gameFlags & 0x80U) != 0)))) ||
     ((gameTrackerX.wipeType == 0xb && (gameTrackerX.wipeTime != 0)))) {
    if (((gameTrackerX.controlCommand[0][1] & 0x4000U) != 0) &&
       (((gameTrackerX.gameMode != 0 && ((gameTrackerX.gameFlags & 0x20000000U) == 0)) &&
        ((gameTrackerX.wipeType != 0xb || (gameTrackerX.wipeTime == 0)))))) {
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
 // line 3404, offset 0x80031d6c
	/* begin block 1 */
		// Start line: 8099
	/* end block 1 */
	// End Line: 8100

void GAMELOOP_RequestLevelChange(char *name,short number,GameTracker *gameTracker)

{
  if (gameTracker->levelChange == 0) {
    gameTracker->gameFlags = gameTracker->gameFlags | 1;
    SOUND_ResetAllSound();
    sprintf(gameTracker->baseAreaName,"%s%d");
    gameTracker->levelChange = 1;
    gameTracker->levelDone = 1;
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PSX_GameLoop(struct GameTracker *gameTracker /*$s0*/)
 // line 3426, offset 0x80031dec
	/* begin block 1 */
		// Start line: 8143
	/* end block 1 */
	// End Line: 8144

void PSX_GameLoop(GameTracker *gameTracker)

{
  GAMEPAD_Process(gameTracker);
  GAMELOOP_Process(gameTracker);
  return;
}



// decompiled code
// original method signature: 
// struct MATRIX * /*$ra*/ GAMELOOP_GetMatrices(int numMatrices /*$a0*/)
 // line 3436, offset 0x80031e18
	/* begin block 1 */
		// Start line: 3438
		// Start offset: 0x80031E18
		// Variables:
	// 		struct MATRIX *matrix; // $a1
	// 		struct _PrimPool *pool; // $v1
	/* end block 1 */
	// End offset: 0x80031E3C
	// End Line: 3455

	/* begin block 2 */
		// Start line: 8163
	/* end block 2 */
	// End Line: 8164

	/* begin block 3 */
		// Start line: 8164
	/* end block 3 */
	// End Line: 8165

	/* begin block 4 */
		// Start line: 8165
	/* end block 4 */
	// End Line: 8166

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
 // line 3460, offset 0x80031e4c
	/* begin block 1 */
		// Start line: 8213
	/* end block 1 */
	// End Line: 8214

	/* begin block 2 */
		// Start line: 8214
	/* end block 2 */
	// End Line: 8215

/* WARNING: Unknown calling convention yet parameter storage is locked */

GameTracker * GAMELOOP_GetGT(void)

{
  return &gameTrackerX;
}





