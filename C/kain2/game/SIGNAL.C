#include "THISDUST.H"
#include "SIGNAL.H"


// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleLightGroup(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 76, offset 0x8001dbf8
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
 // line 85, offset 0x8001dc14
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
 // line 91, offset 0x8001dc3c
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
 // line 97, offset 0x8001dc64
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
 // line 102, offset 0x8001dc80
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
 // line 110, offset 0x8001dca8
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
 // line 116, offset 0x8001dcd0
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
 // line 122, offset 0x8001dcf8
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
 // line 128, offset 0x8001dd20
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
 // line 134, offset 0x8001dd48
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
 // line 140, offset 0x8001dd70
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
 // line 146, offset 0x8001dd98
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
 // line 157, offset 0x8001ddc8
	/* begin block 1 */
		// Start line: 158
		// Start offset: 0x8001DDC8
		// Variables:
	// 		char areaName[16]; // stack offset -48
	// 		int signalnum; // $s5
	// 		char *commapos; // $s0
	// 		long newStreamID; // $s1
	// 		static int lastTimeCrossed; // offset 0x4
	// 		long doingWarpRoom; // $s3

		/* begin block 1.1 */
			// Start line: 177
			// Start offset: 0x8001DE44
			// Variables:
		// 		struct _StreamUnit *curStreamUnit; // $v0
		/* end block 1.1 */
		// End offset: 0x8001DEF0
		// End Line: 199

		/* begin block 1.2 */
			// Start line: 246
			// Start offset: 0x8001DFAC
		/* end block 1.2 */
		// End offset: 0x8001DFFC
		// End Line: 261
	/* end block 1 */
	// End offset: 0x8001E000
	// End Line: 264

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
    if (gameTrackerX.currentTime - DAT_800d040c < 0x65) {
      return 1;
    }
    if ((p_Var3->flags & 8U) == 0) {
      return 1;
    }
    id = ((&WarpRoomArray)[CurrentWarpNumber].streamUnit)->StreamUnitID;
    strcpy(acStack48,(char *)(&WarpRoomArray + CurrentWarpNumber));
    bVar1 = true;
    if ((&WarpRoomArray)[CurrentWarpNumber].streamUnit == (_StreamUnit *)0x0) {
      return 1;
    }
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
      DAT_800d040c = gameTrackerX.currentTime;
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
      if (instance->LinkParent == (_Instance *)0x0) {
        level = STREAM_GetLevelWithID(id);
        if (level == (Level *)0x0) {
          level = STREAM_GetLevelWithID(instance->currentStreamUnitID);
          SAVE_Instance(instance,level);
          instance->flags = instance->flags | 0x20;
        }
        else {
          instance->cachedTFace = -1;
          instance->cachedTFaceLevel = (void *)0x0;
          instance->currentStreamUnitID = id;
          INSTANCE_UpdateFamilyStreamUnitID(instance);
        }
      }
    }
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleFogNear(struct _Instance *instance /*$a0*/, struct Signal *signal /*$s0*/)
 // line 267, offset 0x8001e024
	/* begin block 1 */
		// Start line: 268
		// Start offset: 0x8001E024
		// Variables:
	// 		struct Level *level; // $s0
	/* end block 1 */
	// End offset: 0x8001E024
	// End Line: 268

	/* begin block 2 */
		// Start line: 557
	/* end block 2 */
	// End Line: 558

	/* begin block 3 */
		// Start line: 562
	/* end block 3 */
	// End Line: 563

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
 // line 289, offset 0x8001e078
	/* begin block 1 */
		// Start line: 290
		// Start offset: 0x8001E078
		// Variables:
	// 		struct Level *level; // $s0
	/* end block 1 */
	// End offset: 0x8001E078
	// End Line: 290

	/* begin block 2 */
		// Start line: 617
	/* end block 2 */
	// End Line: 618

	/* begin block 3 */
		// Start line: 622
	/* end block 3 */
	// End Line: 623

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
 // line 316, offset 0x8001e0d4
	/* begin block 1 */
		// Start line: 632
	/* end block 1 */
	// End Line: 633

long SIGNAL_HandleCameraShake(_Instance *instance,Signal *signal)

{
  CAMERA_SetShake(&theCamera,*(long *)signal->data,*(long *)(signal->data + 4));
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCallSignal(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 322, offset 0x8001e104
	/* begin block 1 */
		// Start line: 687
	/* end block 1 */
	// End Line: 688

long SIGNAL_HandleCallSignal(_Instance *instance,Signal *signal)

{
  SIGNAL_HandleSignal(instance,(Signal *)(*(int *)signal->data + 8),0);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleStopPlayerControl(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 328, offset 0x8001e12c
	/* begin block 1 */
		// Start line: 699
	/* end block 1 */
	// End Line: 700

	/* begin block 2 */
		// Start line: 700
	/* end block 2 */
	// End Line: 701

long SIGNAL_HandleStopPlayerControl(_Instance *instance,Signal *signal)

{
  gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x90;
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleStartPlayerControl(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 335, offset 0x8001e144
	/* begin block 1 */
		// Start line: 713
	/* end block 1 */
	// End Line: 714

	/* begin block 2 */
		// Start line: 714
	/* end block 2 */
	// End Line: 715

long SIGNAL_HandleStartPlayerControl(_Instance *instance,Signal *signal)

{
  gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffffff6f;
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SIGNAL_RelocateCameraSpline(struct Signal *signal /*$a0*/, long offset /*$a1*/)
 // line 502, offset 0x8001e164
	/* begin block 1 */
		// Start line: 1004
	/* end block 1 */
	// End Line: 1005

	/* begin block 2 */
		// Start line: 884
	/* end block 2 */
	// End Line: 885

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
 // line 507, offset 0x8001e180
	/* begin block 1 */
		// Start line: 893
	/* end block 1 */
	// End Line: 894

	/* begin block 2 */
		// Start line: 894
	/* end block 2 */
	// End Line: 895

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
 // line 539, offset 0x8001e200
	/* begin block 1 */
		// Start line: 957
	/* end block 1 */
	// End Line: 958

	/* begin block 2 */
		// Start line: 958
	/* end block 2 */
	// End Line: 959

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
 // line 547, offset 0x8001e238
	/* begin block 1 */
		// Start line: 973
	/* end block 1 */
	// End Line: 974

	/* begin block 2 */
		// Start line: 983
	/* end block 2 */
	// End Line: 984

long SIGNAL_HandleBlendStart(_Instance *instance,Signal *signal)

{
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleScreenWipeColor(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 561, offset 0x8001e240
	/* begin block 1 */
		// Start line: 1001
	/* end block 1 */
	// End Line: 1002

	/* begin block 2 */
		// Start line: 1002
	/* end block 2 */
	// End Line: 1003

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
 // line 569, offset 0x8001e26c
	/* begin block 1 */
		// Start line: 570
		// Start offset: 0x8001E26C
		// Variables:
	// 		long slideAngle; // $a2
	/* end block 1 */
	// End offset: 0x8001E28C
	// End Line: 580

	/* begin block 2 */
		// Start line: 1017
	/* end block 2 */
	// End Line: 1018

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
 // line 583, offset 0x8001e29c
	/* begin block 1 */
		// Start line: 1046
	/* end block 1 */
	// End Line: 1047

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
 // line 595, offset 0x8001e2c8
	/* begin block 1 */
		// Start line: 596
		// Start offset: 0x8001E2C8
		// Variables:
	// 		long tilt; // $v0
	/* end block 1 */
	// End offset: 0x8001E344
	// End Line: 610

	/* begin block 2 */
		// Start line: 1070
	/* end block 2 */
	// End Line: 1071

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
 // line 613, offset 0x8001e354
	/* begin block 1 */
		// Start line: 614
		// Start offset: 0x8001E354
		// Variables:
	// 		long distance; // $a1
	/* end block 1 */
	// End offset: 0x8001E374
	// End Line: 624

	/* begin block 2 */
		// Start line: 1107
	/* end block 2 */
	// End Line: 1108

long SIGNAL_HandleSetCameraDistance(_Instance *instance,Signal *signal)

{
  if (instance != (_Instance *)0x0) {
    CAMERA_Adjust_distance(&theCamera,*(long *)signal->data);
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleEnd(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 744, offset 0x8001e384
	/* begin block 1 */
		// Start line: 1370
	/* end block 1 */
	// End Line: 1371

	/* begin block 2 */
		// Start line: 1371
	/* end block 2 */
	// End Line: 1372

long SIGNAL_HandleEnd(_Instance *instance,Signal *signal)

{
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ COLLIDE_HandleSignal(struct _Instance *instance /*$s3*/, struct Signal *signal /*$s0*/, long numSignals /*$a2*/, int dontForceDoSignal /*$a3*/)
 // line 844, offset 0x8001e38c
	/* begin block 1 */
		// Start line: 845
		// Start offset: 0x8001E38C
		// Variables:
	// 		long signalNumber; // $v1
	/* end block 1 */
	// End offset: 0x8001E474
	// End Line: 900

	/* begin block 2 */
		// Start line: 1570
	/* end block 2 */
	// End Line: 1571

void COLLIDE_HandleSignal(_Instance *instance,Signal *signal,long numSignals,int dontForceDoSignal)

{
  long lVar1;
  uint uVar2;
  
  if (numSignals != 0) {
    while( true ) {
      uVar2 = signal->id & 0x7fffffff;
      if (((((&signalInfoList)[uVar2].onlyPlayer == 0) || (instance == gameTrackerX.playerInstance))
          && (((gameTrackerX.gameFlags & 0x40U) == 0 || (-1 < signal->id)))) &&
         ((0x1a < uVar2 ||
          (lVar1 = (*(&signalInfoList)[uVar2].signalHandleFunc)(instance,signal), lVar1 == 0))))
      break;
      signal = (Signal *)(&signal->id + (int)(&signalInfoList)[signal->id & 0x7fffffff].length + 1);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_IsThisStreamAWarpGate(struct Signal *signal /*$a0*/)
 // line 902, offset 0x8001e490
	/* begin block 1 */
		// Start line: 903
		// Start offset: 0x8001E490
		// Variables:
	// 		long result; // $s0
	// 		char areaName[32]; // stack offset -40
	// 		char *commapos; // $v0
	/* end block 1 */
	// End offset: 0x8001E4DC
	// End Line: 920

	/* begin block 2 */
		// Start line: 1686
	/* end block 2 */
	// End Line: 1687

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
// long /*$ra*/ SIGNAL_IsStreamSignal(struct Signal *signal /*$s1*/, long *isWarpGate /*$s4*/)
 // line 923, offset 0x8001e4f0
	/* begin block 1 */
		// Start line: 924
		// Start offset: 0x8001E4F0
		// Variables:
	// 		long result; // $s3
	// 		long done; // $s2
	// 		long signalNumber; // $s0
	/* end block 1 */
	// End offset: 0x8001E5A4
	// End Line: 966

	/* begin block 2 */
		// Start line: 1732
	/* end block 2 */
	// End Line: 1733

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
    if (uVar3 == 0xf) {
      bVar1 = true;
    }
    else {
      if (uVar3 == 0x12) {
        bVar1 = true;
        lVar4 = 1;
        lVar2 = SIGNAL_IsThisStreamAWarpGate(signal);
        if (lVar2 != 0) {
          *isWarpGate = 1;
        }
      }
    }
    if (bVar1) break;
    signal = (Signal *)(&signal->id + (int)(&signalInfoList)[uVar3].length + 1);
  }
  return lVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SIGNAL_HandleSignal(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/, int dontForceDoSignal /*$a3*/)
 // line 969, offset 0x8001e5c8
	/* begin block 1 */
		// Start line: 1831
	/* end block 1 */
	// End Line: 1832

void SIGNAL_HandleSignal(_Instance *instance,Signal *signal,int dontForceDoSignal)

{
  COLLIDE_HandleSignal(instance,signal,1,dontForceDoSignal);
  return;
}



// decompiled code
// original method signature: 
// struct _MultiSignal * /*$ra*/ SIGNAL_RelocateSignal(struct _MultiSignal *multiSignal /*$s4*/, long offset /*$s5*/)
 // line 976, offset 0x8001e5ec
	/* begin block 1 */
		// Start line: 977
		// Start offset: 0x8001E5EC
		// Variables:
	// 		int i; // $s1
	// 		struct Signal *signal; // $s0
	/* end block 1 */
	// End offset: 0x8001E6A0
	// End Line: 999

	/* begin block 2 */
		// Start line: 1845
	/* end block 2 */
	// End Line: 1846

_MultiSignal * SIGNAL_RelocateSignal(_MultiSignal *multiSignal,long offset)

{
  Signal *pSVar1;
  int iVar2;
  
  pSVar1 = multiSignal->signalList;
  iVar2 = 0;
  if (0 < multiSignal->numSignals) {
    do {
      if ((&signalInfoList)[pSVar1->id & 0x7fffffff].signalRelocateFunc != (_func_21 *)0x0) {
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
 // line 1002, offset 0x8001e6c8
	/* begin block 1 */
		// Start line: 1004
		// Start offset: 0x8001E6C8
		// Variables:
	// 		int i; // $a2
	// 		struct Signal *signal; // $a3
	// 		struct _MultiSignal *msignal; // $v1
	// 		long signalNumber; // $v1
	/* end block 1 */
	// End offset: 0x8001E770
	// End Line: 1045

	/* begin block 2 */
		// Start line: 1922
	/* end block 2 */
	// End Line: 1923

	/* begin block 3 */
		// Start line: 1923
	/* end block 3 */
	// End Line: 1924

	/* begin block 4 */
		// Start line: 1929
	/* end block 4 */
	// End Line: 1930

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
 // line 1049, offset 0x8001e778
	/* begin block 1 */
		// Start line: 1050
		// Start offset: 0x8001E778
		// Variables:
	// 		struct Level *level; // $v0
	/* end block 1 */
	// End offset: 0x8001E7B8
	// End Line: 1060

	/* begin block 2 */
		// Start line: 2042
	/* end block 2 */
	// End Line: 2043

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
 // line 1062, offset 0x8001e7c8
	/* begin block 1 */
		// Start line: 1063
		// Start offset: 0x8001E7C8
		// Variables:
	// 		struct Level *level; // $v0
	/* end block 1 */
	// End offset: 0x8001E808
	// End Line: 1072

	/* begin block 2 */
		// Start line: 2068
	/* end block 2 */
	// End Line: 2069

void SIGNAL_InWater(_Instance *instance)

{
  Level *pLVar1;
  
  pLVar1 = STREAM_GetLevelWithID(instance->currentStreamUnitID);
  if ((pLVar1 != (Level *)0x0) && (pLVar1->startGoingIntoWaterSignal != (_MultiSignal *)0x0)) {
    SIGNAL_HandleSignal(instance,pLVar1->startGoingIntoWaterSignal->signalList,0);
  }
  return;
}





