#include "THISDUST.H"
#include "SIGNAL.H"


// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleLightGroup(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 76, offset 0x8001dc68
	/* begin block 1 */
		// Start line: 152
	/* end block 1 */
	// End Line: 153

	/* begin block 2 */
		// Start line: 153
	/* end block 2 */
	// End Line: 154

long SIGNAL_HandleLightGroup(_Instance *instance,Signal *signal)

{
  if (instance != (_Instance *)0x0) {
    instance->lightGroup = signal->data[0];
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCameraAdjust(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 85, offset 0x8001dc84
	/* begin block 1 */
		// Start line: 170
	/* end block 1 */
	// End Line: 171

long SIGNAL_HandleCameraAdjust(_Instance *instance,Signal *signal)

{
  CAMERA_Adjust(&theCamera,*(long *)signal->data);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCamera(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 91, offset 0x8001dcb0
	/* begin block 1 */
		// Start line: 182
	/* end block 1 */
	// End Line: 183

long SIGNAL_HandleCamera(_Instance *instance,Signal *signal)

{
  CAMERA_ChangeTo(&theCamera,*(_CameraKey **)signal->data);
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SIGNAL_RelocateCamera(struct Signal *signal /*$a0*/, long offset /*$a1*/)
 // line 97, offset 0x8001dcdc
	/* begin block 1 */
		// Start line: 194
	/* end block 1 */
	// End Line: 195

	/* begin block 2 */
		// Start line: 195
	/* end block 2 */
	// End Line: 196

void SIGNAL_RelocateCamera(Signal *signal,long offset)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(int *)signal->data != 0) {
    iVar1 = *(int *)signal->data + offset;
  }
  *(int *)signal->data = iVar1;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCameraMode(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 102, offset 0x8001dcf8
	/* begin block 1 */
		// Start line: 204
	/* end block 1 */
	// End Line: 205

long SIGNAL_HandleCameraMode(_Instance *instance,Signal *signal)

{
  CAMERA_SetMode(&theCamera,*(long *)signal->data);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCameraLock(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 110, offset 0x8001dd24
	/* begin block 1 */
		// Start line: 220
	/* end block 1 */
	// End Line: 221

long SIGNAL_HandleCameraLock(_Instance *instance,Signal *signal)

{
  CAMERA_Lock(&theCamera,*(long *)signal->data);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCameraUnlock(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 116, offset 0x8001dd50
	/* begin block 1 */
		// Start line: 232
	/* end block 1 */
	// End Line: 233

long SIGNAL_HandleCameraUnlock(_Instance *instance,Signal *signal)

{
  CAMERA_Unlock(&theCamera,*(long *)signal->data);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCameraSmooth(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 122, offset 0x8001dd7c
	/* begin block 1 */
		// Start line: 244
	/* end block 1 */
	// End Line: 245

long SIGNAL_HandleCameraSmooth(_Instance *instance,Signal *signal)

{
  CAMERA_SetSmoothValue(&theCamera,*(long *)signal->data);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCameraTimer(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 128, offset 0x8001dda8
	/* begin block 1 */
		// Start line: 256
	/* end block 1 */
	// End Line: 257

long SIGNAL_HandleCameraTimer(_Instance *instance,Signal *signal)

{
  CAMERA_SetTimer(&theCamera,*(long *)signal->data);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCameraSave(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 134, offset 0x8001ddd4
	/* begin block 1 */
		// Start line: 268
	/* end block 1 */
	// End Line: 269

long SIGNAL_HandleCameraSave(_Instance *instance,Signal *signal)

{
  CAMERA_Save(&theCamera,*(long *)signal->data);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCameraRestore(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 140, offset 0x8001de00
	/* begin block 1 */
		// Start line: 280
	/* end block 1 */
	// End Line: 281

long SIGNAL_HandleCameraRestore(_Instance *instance,Signal *signal)

{
  CAMERA_Restore(&theCamera,*(long *)signal->data);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCameraValue(struct _Instance *instance /*$a0*/, struct Signal *signal /*$v0*/)
 // line 146, offset 0x8001de2c
	/* begin block 1 */
		// Start line: 292
	/* end block 1 */
	// End Line: 293

long SIGNAL_HandleCameraValue(_Instance *instance,Signal *signal)

{
  CAMERA_SetValue(&theCamera,*(long *)signal->data,*(long *)(signal->data + 4));
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleStreamLevel(struct _Instance *instance /*$s2*/, struct Signal *signal /*$s4*/)
 // line 157, offset 0x8001de60
	/* begin block 1 */
		// Start line: 158
		// Start offset: 0x8001DE60
		// Variables:
	// 		char areaName[16]; // stack offset -48
	// 		int signalnum; // $s5
	// 		char *commapos; // $s0
	// 		long newStreamID; // $s1
	// 		static int lastTimeCrossed; // offset 0x4
	// 		long doingWarpRoom; // $s3

		/* begin block 1.1 */
			// Start line: 177
			// Start offset: 0x8001DEDC
			// Variables:
		// 		struct _StreamUnit *curStreamUnit; // $v0
		/* end block 1.1 */
		// End offset: 0x8001DF84
		// End Line: 199

		/* begin block 1.2 */
			// Start line: 246
			// Start offset: 0x8001E038
		/* end block 1.2 */
		// End offset: 0x8001E080
		// End Line: 259
	/* end block 1 */
	// End offset: 0x8001E084
	// End Line: 262

	/* begin block 2 */
		// Start line: 314
	/* end block 2 */
	// End Line: 315

long SIGNAL_HandleStreamLevel(_Instance *instance,Signal *signal)

{
  bool bVar1;
  char *pcVar2;
  int id;
  _StreamUnit *p_Var3;
  long lVar4;
  Level *level;
  short sVar5;
  char acStack48 [16];
  
  sVar5 = -1;
  bVar1 = false;
  strcpy(acStack48,(char *)(signal->data + 8));
  pcVar2 = strchr(acStack48,0x2c);
  if (pcVar2 != (char *)0x0) {
    id = atoi(pcVar2 + 1);
    sVar5 = (short)id;
    *pcVar2 = '\0';
  }
  id = strcmpi(acStack48,"warpgate");
  if (id == 0) {
    p_Var3 = STREAM_GetStreamUnitWithID(instance->currentStreamUnitID);
    if (gameTrackerX.globalTimeMult - DAT_800cddc4 < 0x65) {
      return 1;
    }
    if ((p_Var3->flags & 8U) == 0) {
      return 1;
    }
    id = ((&WarpRoomArray)[CurrentWarpNumber].streamUnit)->StreamUnitID;
    strcpy(acStack48,(char *)(&WarpRoomArray + CurrentWarpNumber));
    bVar1 = true;
    if ((((&WarpRoomArray)[CurrentWarpNumber].streamUnit)->flags & 8U) == 0) {
      return 1;
    }
  }
  else {
    id = *(int *)(signal->data + 4);
  }
  if (instance->currentStreamUnitID != id) {
    if (instance == gameTrackerX.playerInstance) {
      gameTrackerX.SwitchToNewStreamUnit = 1;
      DAT_800cddc4 = gameTrackerX.globalTimeMult;
      strcpy(gameTrackerX.S_baseAreaName,acStack48);
      gameTrackerX.fromSignal = *(short *)signal->data;
      gameTrackerX.toSignal = sVar5;
      gameTrackerX.moveRazielToStreamID = id;
      if (bVar1) {
        if ((gameTrackerX.gameData.asmData.MorphType == 0) &&
           (id = strcmpi(acStack48,"under3"), id == 0)) {
          INSTANCE_Post(gameTrackerX.playerInstance,0x10002001,0);
        }
        lVar4 = WARPGATE_GetWarpRoomIndex(gameTrackerX.baseAreaName);
        gameTrackerX.SwitchToNewWarpIndex = (short)lVar4;
      }
      else {
        gameTrackerX.SwitchToNewWarpIndex = -1;
      }
    }
    else {
      level = STREAM_GetLevelWithID(id);
      if (level == (Level *)0x0) {
        level = STREAM_GetLevelWithID(instance->currentStreamUnitID);
        SAVE_Instance(instance,level);
        instance->flags = instance->flags | 0x20;
      }
      else {
        instance->currentStreamUnitID = id;
        INSTANCE_UpdateFamilyStreamUnitID(instance);
      }
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleFogNear(struct _Instance *instance /*$a0*/, struct Signal *signal /*$s0*/)
 // line 265, offset 0x8001e0a8
	/* begin block 1 */
		// Start line: 266
		// Start offset: 0x8001E0A8
		// Variables:
	// 		struct Level *level; // $s0
	/* end block 1 */
	// End offset: 0x8001E0A8
	// End Line: 266

	/* begin block 2 */
		// Start line: 555
	/* end block 2 */
	// End Line: 556

	/* begin block 3 */
		// Start line: 560
	/* end block 3 */
	// End Line: 561

long SIGNAL_HandleFogNear(_Instance *instance,Signal *signal)

{
  ushort uVar1;
  Level *level;
  
  level = STREAM_GetLevelWithID((gameTrackerX.playerInstance)->currentStreamUnitID);
  uVar1 = *(ushort *)signal->data;
  level->fogNear = uVar1;
  SetFogNearFar((uint)uVar1,(uint)level->fogFar,theCamera.core.projDistance);
  LIGHT_CalcDQPTable(level);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleFogFar(struct _Instance *instance /*$a0*/, struct Signal *signal /*$s1*/)
 // line 287, offset 0x8001e0fc
	/* begin block 1 */
		// Start line: 288
		// Start offset: 0x8001E0FC
		// Variables:
	// 		struct Level *level; // $s0
	/* end block 1 */
	// End offset: 0x8001E0FC
	// End Line: 288

	/* begin block 2 */
		// Start line: 615
	/* end block 2 */
	// End Line: 616

	/* begin block 3 */
		// Start line: 620
	/* end block 3 */
	// End Line: 621

long SIGNAL_HandleFogFar(_Instance *instance,Signal *signal)

{
  ushort uVar1;
  Level *level;
  
  level = STREAM_GetLevelWithID((gameTrackerX.playerInstance)->currentStreamUnitID);
  uVar1 = *(ushort *)signal->data;
  level->fogFar = uVar1;
  SetFogNearFar((uint)level->fogNear,(uint)uVar1,theCamera.core.projDistance);
  LIGHT_CalcDQPTable(level);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCameraShake(struct _Instance *instance /*$a0*/, struct Signal *signal /*$v0*/)
 // line 314, offset 0x8001e158
	/* begin block 1 */
		// Start line: 623
	/* end block 1 */
	// End Line: 624

long SIGNAL_HandleCameraShake(_Instance *instance,Signal *signal)

{
  CAMERA_SetShake(&theCamera,*(long *)signal->data,*(long *)(signal->data + 4));
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCallSignal(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 320, offset 0x8001e18c
	/* begin block 1 */
		// Start line: 685
	/* end block 1 */
	// End Line: 686

long SIGNAL_HandleCallSignal(_Instance *instance,Signal *signal)

{
  SIGNAL_HandleSignal(instance,(Signal *)(*(int *)signal->data + 8),0);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleStopPlayerControl(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 326, offset 0x8001e1b4
	/* begin block 1 */
		// Start line: 697
	/* end block 1 */
	// End Line: 698

	/* begin block 2 */
		// Start line: 698
	/* end block 2 */
	// End Line: 699

long SIGNAL_HandleStopPlayerControl(_Instance *instance,Signal *signal)

{
  gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x90;
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleStartPlayerControl(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 333, offset 0x8001e1cc
	/* begin block 1 */
		// Start line: 711
	/* end block 1 */
	// End Line: 712

	/* begin block 2 */
		// Start line: 712
	/* end block 2 */
	// End Line: 713

long SIGNAL_HandleStartPlayerControl(_Instance *instance,Signal *signal)

{
  gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffffff6f;
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SIGNAL_RelocateCameraSpline(struct Signal *signal /*$a0*/, long offset /*$a1*/)
 // line 500, offset 0x8001e1ec
	/* begin block 1 */
		// Start line: 996
	/* end block 1 */
	// End Line: 997

	/* begin block 2 */
		// Start line: 882
	/* end block 2 */
	// End Line: 883

void SIGNAL_RelocateCameraSpline(Signal *signal,long offset)

{
  int iVar1;
  
  iVar1 = 0;
  if (*(int *)(signal->data + 4) != 0) {
    iVar1 = *(int *)(signal->data + 4) + offset;
  }
  *(int *)(signal->data + 4) = iVar1;
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCameraSpline(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 505, offset 0x8001e208
	/* begin block 1 */
		// Start line: 891
	/* end block 1 */
	// End Line: 892

	/* begin block 2 */
		// Start line: 892
	/* end block 2 */
	// End Line: 893

long SIGNAL_HandleCameraSpline(_Instance *instance,Signal *signal)

{
  if (*(int *)signal->data == 0) {
    if (*(int *)(signal->data + 4) == 0) {
      theCamera.Spline00 = (MultiSpline *)0x0;
      return 1;
    }
    theCamera.Spline00 = *(MultiSpline **)(*(int *)(signal->data + 4) + 0x38);
    return 1;
  }
  if (*(int *)signal->data == 1) {
    if (*(int *)(signal->data + 4) != 0) {
      theCamera.Spline01 = *(MultiSpline **)(*(int *)(signal->data + 4) + 0x38);
      return 1;
    }
    theCamera.Spline01 = (MultiSpline *)0x0;
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleScreenWipe(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 537, offset 0x8001e288
	/* begin block 1 */
		// Start line: 955
	/* end block 1 */
	// End Line: 956

	/* begin block 2 */
		// Start line: 956
	/* end block 2 */
	// End Line: 957

long SIGNAL_HandleScreenWipe(_Instance *instance,Signal *signal)

{
  gameTrackerX.maxWipeTime = *(short *)(signal->data + 2);
  if (gameTrackerX.maxWipeTime < 0) {
    gameTrackerX.maxWipeTime = -gameTrackerX.maxWipeTime;
  }
  gameTrackerX.wipeTime = *(short *)(signal->data + 2);
  gameTrackerX.wipeType = *(short *)signal->data;
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleBlendStart(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 545, offset 0x8001e2c0
	/* begin block 1 */
		// Start line: 971
	/* end block 1 */
	// End Line: 972

	/* begin block 2 */
		// Start line: 981
	/* end block 2 */
	// End Line: 982

long SIGNAL_HandleBlendStart(_Instance *instance,Signal *signal)

{
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleScreenWipeColor(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 559, offset 0x8001e2c8
	/* begin block 1 */
		// Start line: 999
	/* end block 1 */
	// End Line: 1000

	/* begin block 2 */
		// Start line: 1000
	/* end block 2 */
	// End Line: 1001

long SIGNAL_HandleScreenWipeColor(_Instance *instance,Signal *signal)

{
  gameTrackerX.wipeColor.r = signal->data[0];
  gameTrackerX.wipeColor.g = signal->data[1];
  gameTrackerX.wipeColor.b = signal->data[2];
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleSetSlideAngle(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 567, offset 0x8001e2f4
	/* begin block 1 */
		// Start line: 568
		// Start offset: 0x8001E2F4
		// Variables:
	// 		long slideAngle; // $a2
	/* end block 1 */
	// End offset: 0x8001E314
	// End Line: 578

	/* begin block 2 */
		// Start line: 1015
	/* end block 2 */
	// End Line: 1016

long SIGNAL_HandleSetSlideAngle(_Instance *instance,Signal *signal)

{
  if (instance != (_Instance *)0x0) {
    INSTANCE_Post(instance,0x4000005,*(int *)signal->data);
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleResetSlideAngle(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 581, offset 0x8001e324
	/* begin block 1 */
		// Start line: 1044
	/* end block 1 */
	// End Line: 1045

long SIGNAL_HandleResetSlideAngle(_Instance *instance,Signal *signal)

{
  if (instance != (_Instance *)0x0) {
    INSTANCE_Post(instance,0x4000006,0);
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleSetCameraTilt(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 593, offset 0x8001e350
	/* begin block 1 */
		// Start line: 594
		// Start offset: 0x8001E350
		// Variables:
	// 		long tilt; // $v0
	/* end block 1 */
	// End offset: 0x8001E3D0
	// End Line: 608

	/* begin block 2 */
		// Start line: 1068
	/* end block 2 */
	// End Line: 1069

long SIGNAL_HandleSetCameraTilt(_Instance *instance,Signal *signal)

{
  int iVar1;
  
  if (instance != (_Instance *)0x0) {
    iVar1 = -*(int *)signal->data % 0x168;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0x168;
    }
    CAMERA_Adjust_tilt(&theCamera,(iVar1 * 0x1000) / 0x168);
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleSetCameraDistance(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 611, offset 0x8001e3e0
	/* begin block 1 */
		// Start line: 612
		// Start offset: 0x8001E3E0
		// Variables:
	// 		long distance; // $a1
	/* end block 1 */
	// End offset: 0x8001E404
	// End Line: 622

	/* begin block 2 */
		// Start line: 1105
	/* end block 2 */
	// End Line: 1106

long SIGNAL_HandleSetCameraDistance(_Instance *instance,Signal *signal)

{
  if (instance != (_Instance *)0x0) {
    CAMERA_Adjust_distance(&theCamera,*(long *)signal->data);
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_ErrorNoFunction(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 741, offset 0x8001e414
	/* begin block 1 */
		// Start line: 1366
	/* end block 1 */
	// End Line: 1367

long SIGNAL_ErrorNoFunction(_Instance *instance,Signal *signal)

{
  GXFilePrint("Signal command %d has been taken out.\n");
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleEnd(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 752, offset 0x8001e448
	/* begin block 1 */
		// Start line: 1392
	/* end block 1 */
	// End Line: 1393

	/* begin block 2 */
		// Start line: 1393
	/* end block 2 */
	// End Line: 1394

long SIGNAL_HandleEnd(_Instance *instance,Signal *signal)

{
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ COLLIDE_HandleSignal(struct _Instance *instance /*$s3*/, struct Signal *signal /*$s0*/, long numSignals /*$a2*/, int dontForceDoSignal /*$a3*/)
 // line 934, offset 0x8001e450
	/* begin block 1 */
		// Start line: 935
		// Start offset: 0x8001E450
	/* end block 1 */
	// End offset: 0x8001E528
	// End Line: 965

	/* begin block 2 */
		// Start line: 1756
	/* end block 2 */
	// End Line: 1757

void COLLIDE_HandleSignal(_Instance *instance,Signal *signal,long numSignals,int dontForceDoSignal)

{
  uint uVar1;
  long lVar2;
  
  if (numSignals != 0) {
    while( true ) {
      uVar1 = signal->id & 0x7fffffff;
      if (((((&signalInfoList)[uVar1].onlyPlayer == 0) || (instance == gameTrackerX.playerInstance))
          && (((gameTrackerX.gameFlags & 0x40U) == 0 || (-1 < signal->id)))) &&
         (lVar2 = (*(&signalInfoList)[uVar1].signalHandleFunc)(instance,signal), lVar2 == 0)) break;
      signal = (Signal *)(&signal->id + (int)(&signalInfoList)[signal->id & 0x7fffffff].length + 1);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_IsThisStreamAWarpGate(struct Signal *signal /*$a0*/)
 // line 967, offset 0x8001e544
	/* begin block 1 */
		// Start line: 968
		// Start offset: 0x8001E544
		// Variables:
	// 		long result; // $s0
	// 		char areaName[32]; // stack offset -40
	// 		char *commapos; // $v0
	/* end block 1 */
	// End offset: 0x8001E590
	// End Line: 985

	/* begin block 2 */
		// Start line: 1822
	/* end block 2 */
	// End Line: 1823

long SIGNAL_IsThisStreamAWarpGate(Signal *signal)

{
  char *pcVar1;
  int iVar2;
  char acStack40 [32];
  
  strcpy(acStack40,(char *)(signal->data + 8));
  pcVar1 = strchr(acStack40,0x2c);
  if (pcVar1 != (char *)0x0) {
    *pcVar1 = '\0';
  }
  iVar2 = strcmpi(acStack40,"warpgate");
  return (uint)(iVar2 == 0);
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_IsStreamSignal(struct Signal *signal /*$s0*/, long *isWarpGate /*$s4*/)
 // line 988, offset 0x8001e5a4
	/* begin block 1 */
		// Start line: 989
		// Start offset: 0x8001E5A4
		// Variables:
	// 		long result; // $s2
	// 		long done; // $s1
	/* end block 1 */
	// End offset: 0x8001E664
	// End Line: 1020

	/* begin block 2 */
		// Start line: 1868
	/* end block 2 */
	// End Line: 1869

long SIGNAL_IsStreamSignal(Signal *signal,long *isWarpGate)

{
  bool bVar1;
  long lVar2;
  uint uVar3;
  long lVar4;
  
  lVar4 = 0;
  bVar1 = false;
  *isWarpGate = 0;
  while( true ) {
    uVar3 = signal->id & 0x7fffffff;
    if (uVar3 == 0x3c) {
      bVar1 = true;
    }
    else {
      if (uVar3 == 0x4e) {
        bVar1 = true;
        lVar4 = 1;
        lVar2 = SIGNAL_IsThisStreamAWarpGate(signal);
        if (lVar2 != 0) {
          *isWarpGate = 1;
        }
      }
    }
    if (bVar1) break;
    signal = (Signal *)(&signal->id + (int)(&signalInfoList)[signal->id & 0x7fffffff].length + 1);
  }
  return lVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SIGNAL_HandleSignal(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/, int dontForceDoSignal /*$a3*/)
 // line 1023, offset 0x8001e684
	/* begin block 1 */
		// Start line: 1944
	/* end block 1 */
	// End Line: 1945

void SIGNAL_HandleSignal(_Instance *instance,Signal *signal,int dontForceDoSignal)

{
  COLLIDE_HandleSignal(instance,signal,1,dontForceDoSignal);
  return;
}



// decompiled code
// original method signature: 
// struct _MultiSignal * /*$ra*/ SIGNAL_RelocateSignal(struct _MultiSignal *multiSignal /*$s4*/, long offset /*$s5*/)
 // line 1030, offset 0x8001e6a8
	/* begin block 1 */
		// Start line: 1031
		// Start offset: 0x8001E6A8
		// Variables:
	// 		int i; // $s1
	// 		struct Signal *signal; // $s0
	/* end block 1 */
	// End offset: 0x8001E760
	// End Line: 1053

	/* begin block 2 */
		// Start line: 1958
	/* end block 2 */
	// End Line: 1959

_MultiSignal * SIGNAL_RelocateSignal(_MultiSignal *multiSignal,long offset)

{
  Signal *pSVar1;
  int iVar2;
  
  pSVar1 = multiSignal->signalList;
  iVar2 = 0;
  if (0 < multiSignal->numSignals) {
    do {
      if ((&signalInfoList)[pSVar1->id & 0x7fffffff].signalRelocateFunc != (_func_4467 *)0x0) {
        (*(&signalInfoList)[pSVar1->id & 0x7fffffff].signalRelocateFunc)(pSVar1,offset);
      }
      iVar2 = iVar2 + 1;
      pSVar1 = (Signal *)(&pSVar1->id + (int)(&signalInfoList)[pSVar1->id & 0x7fffffff].length + 1);
    } while (iVar2 < multiSignal->numSignals);
  }
  return (_MultiSignal *)pSVar1->data;
}



// decompiled code
// original method signature: 
// struct _MultiSignal * /*$ra*/ SIGNAL_FindSignal(struct Level *level /*$a0*/, long id /*$a1*/)
 // line 1056, offset 0x8001e788
	/* begin block 1 */
		// Start line: 1058
		// Start offset: 0x8001E788
		// Variables:
	// 		int i; // $a2
	// 		struct Signal *signal; // $a3
	// 		struct _MultiSignal *msignal; // $v1
	/* end block 1 */
	// End offset: 0x8001E834
	// End Line: 1088

	/* begin block 2 */
		// Start line: 2035
	/* end block 2 */
	// End Line: 2036

	/* begin block 3 */
		// Start line: 2036
	/* end block 3 */
	// End Line: 2037

	/* begin block 4 */
		// Start line: 2041
	/* end block 4 */
	// End Line: 2042

_MultiSignal * SIGNAL_FindSignal(Level *level,long id)

{
  _MultiSignal *p_Var1;
  int iVar2;
  Signal *pSVar3;
  
  p_Var1 = level->SignalListStart;
  if (p_Var1 < level->SignalListEnd) {
    do {
      pSVar3 = p_Var1->signalList;
      if (id == (int)p_Var1->signalNum) break;
      iVar2 = 0;
      if (0 < p_Var1->numSignals) {
        do {
          iVar2 = iVar2 + 1;
          pSVar3 = (Signal *)
                   (&pSVar3->id + (int)(&signalInfoList)[pSVar3->id & 0x7fffffff].length + 1);
        } while (iVar2 < p_Var1->numSignals);
      }
      p_Var1 = (_MultiSignal *)pSVar3->data;
    } while (p_Var1 < level->SignalListEnd);
  }
  if (p_Var1 == level->SignalListEnd) {
    p_Var1 = (_MultiSignal *)0x0;
  }
  return p_Var1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SIGNAL_OutOfWater(struct _Instance *instance /*$s0*/)
 // line 1092, offset 0x8001e83c
	/* begin block 1 */
		// Start line: 1093
		// Start offset: 0x8001E83C
		// Variables:
	// 		struct Level *level; // $v0
	/* end block 1 */
	// End offset: 0x8001E87C
	// End Line: 1103

	/* begin block 2 */
		// Start line: 2113
	/* end block 2 */
	// End Line: 2114

void SIGNAL_OutOfWater(_Instance *instance)

{
  Level *pLVar1;
  
  pLVar1 = STREAM_GetLevelWithID(instance->currentStreamUnitID);
  if ((pLVar1 != (Level *)0x0) && (pLVar1->startGoingOutOfWaterSignal != (_MultiSignal *)0x0)) {
    SIGNAL_HandleSignal(instance,pLVar1->startGoingOutOfWaterSignal->signalList,0);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SIGNAL_InWater(struct _Instance *instance /*$s0*/)
 // line 1105, offset 0x8001e88c
	/* begin block 1 */
		// Start line: 1106
		// Start offset: 0x8001E88C
		// Variables:
	// 		struct Level *level; // $v0
	/* end block 1 */
	// End offset: 0x8001E8CC
	// End Line: 1115

	/* begin block 2 */
		// Start line: 2139
	/* end block 2 */
	// End Line: 2140

void SIGNAL_InWater(_Instance *instance)

{
  Level *pLVar1;
  
  pLVar1 = STREAM_GetLevelWithID(instance->currentStreamUnitID);
  if ((pLVar1 != (Level *)0x0) && (pLVar1->startGoingIntoWaterSignal != (_MultiSignal *)0x0)) {
    SIGNAL_HandleSignal(instance,pLVar1->startGoingIntoWaterSignal->signalList,0);
  }
  return;
}





