#include "THISDUST.H"
#include "SIGNAL.H"


// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleLightGroup(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 76, offset 0x8001d824
	/* begin block 1 */
		// Start line: 152
	/* end block 1 */
	// End Line: 153

	/* begin block 2 */
		// Start line: 153
	/* end block 2 */
	// End Line: 154

/* File: C:\kain2\game\SIGNAL.C */

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
 // line 85, offset 0x8001d840
	/* begin block 1 */
		// Start line: 170
	/* end block 1 */
	// End Line: 171

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleCameraAdjust(_Instance *instance,Signal *signal)

{
  CAMERA_Adjust((Camera *)&theCamera,*(long *)signal->data);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCamera(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 91, offset 0x8001d86c
	/* begin block 1 */
		// Start line: 182
	/* end block 1 */
	// End Line: 183

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleCamera(_Instance *instance,Signal *signal)

{
  CAMERA_ChangeTo((Camera *)&theCamera,*(_CameraKey **)signal->data);
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SIGNAL_RelocateCamera(struct Signal *signal /*$a0*/, long offset /*$a1*/)
 // line 97, offset 0x8001d898
	/* begin block 1 */
		// Start line: 194
	/* end block 1 */
	// End Line: 195

	/* begin block 2 */
		// Start line: 195
	/* end block 2 */
	// End Line: 196

/* File: C:\kain2\game\SIGNAL.C */

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
 // line 102, offset 0x8001d8b4
	/* begin block 1 */
		// Start line: 204
	/* end block 1 */
	// End Line: 205

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleCameraMode(_Instance *instance,Signal *signal)

{
  CAMERA_SetMode((Camera *)&theCamera,*(long *)signal->data);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCameraLock(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 110, offset 0x8001d8e0
	/* begin block 1 */
		// Start line: 220
	/* end block 1 */
	// End Line: 221

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleCameraLock(_Instance *instance,Signal *signal)

{
  CAMERA_Lock((Camera *)&theCamera,*(long *)signal->data);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCameraUnlock(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 116, offset 0x8001d90c
	/* begin block 1 */
		// Start line: 232
	/* end block 1 */
	// End Line: 233

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleCameraUnlock(_Instance *instance,Signal *signal)

{
  CAMERA_Unlock((Camera *)&theCamera,*(long *)signal->data);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCameraSmooth(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 122, offset 0x8001d938
	/* begin block 1 */
		// Start line: 244
	/* end block 1 */
	// End Line: 245

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleCameraSmooth(_Instance *instance,Signal *signal)

{
  CAMERA_SetSmoothValue((Camera *)&theCamera,*(long *)signal->data);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCameraTimer(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 128, offset 0x8001d964
	/* begin block 1 */
		// Start line: 256
	/* end block 1 */
	// End Line: 257

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleCameraTimer(_Instance *instance,Signal *signal)

{
  CAMERA_SetTimer((Camera *)&theCamera,*(long *)signal->data);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCameraSave(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 134, offset 0x8001d990
	/* begin block 1 */
		// Start line: 268
	/* end block 1 */
	// End Line: 269

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleCameraSave(_Instance *instance,Signal *signal)

{
  CAMERA_Save((Camera *)&theCamera,*(long *)signal->data);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCameraRestore(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 140, offset 0x8001d9bc
	/* begin block 1 */
		// Start line: 280
	/* end block 1 */
	// End Line: 281

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleCameraRestore(_Instance *instance,Signal *signal)

{
  CAMERA_Restore((Camera *)&theCamera,*(long *)signal->data);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCameraValue(struct _Instance *instance /*$a0*/, struct Signal *signal /*$v0*/)
 // line 146, offset 0x8001d9e8
	/* begin block 1 */
		// Start line: 292
	/* end block 1 */
	// End Line: 293

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleCameraValue(_Instance *instance,Signal *signal)

{
  CAMERA_SetValue((Camera *)&theCamera,*(long *)signal->data,*(long *)(signal->data + 4));
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleStreamLevel(struct _Instance *instance /*$s2*/, struct Signal *signal /*$s4*/)
 // line 157, offset 0x8001da1c
	/* begin block 1 */
		// Start line: 158
		// Start offset: 0x8001DA1C
		// Variables:
	// 		char areaName[16]; // stack offset -48
	// 		int signalnum; // $s5
	// 		char *commapos; // $s0
	// 		long newStreamID; // $s1
	// 		static int lastTimeCrossed; // offset 0x4
	// 		long doingWarpRoom; // $s3

		/* begin block 1.1 */
			// Start line: 177
			// Start offset: 0x8001DA98
			// Variables:
		// 		struct _StreamUnit *curStreamUnit; // $v0
		/* end block 1.1 */
		// End offset: 0x8001DB48
		// End Line: 199

		/* begin block 1.2 */
			// Start line: 246
			// Start offset: 0x8001DC0C
		/* end block 1.2 */
		// End offset: 0x8001DC54
		// End Line: 259
	/* end block 1 */
	// End offset: 0x8001DC58
	// End Line: 262

	/* begin block 2 */
		// Start line: 314
	/* end block 2 */
	// End Line: 315

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleStreamLevel(_Instance *instance,Signal *signal)

{
  bool bVar1;
  char *pcVar2;
  int id;
  _StreamUnit *p_Var3;
  long lVar4;
  Level *level;
  undefined2 uVar5;
  char acStack48 [16];
  
  uVar5 = 0xffff;
  bVar1 = false;
  strcpy();
  pcVar2 = strchr(acStack48,',');
  if (pcVar2 != (char *)0x0) {
    id = atoi(pcVar2 + 1);
    uVar5 = (undefined2)id;
    *pcVar2 = '\0';
  }
  id = strcmpi(acStack48,s_warpgate_800cf184);
  if (id == 0) {
    p_Var3 = STREAM_GetStreamUnitWithID(instance->currentStreamUnitID);
    if ((uint)(DAT_800d2300 - DAT_800cf180) < 0x65) {
      return 1;
    }
    if ((p_Var3->flags & 8U) == 0) {
      return 1;
    }
    id = **(int **)(&LAB_800d0420 + CurrentWarpNumber * 0x14);
    strcpy();
    bVar1 = true;
    if (*(int *)(&LAB_800d0420 + CurrentWarpNumber * 0x14) == 0) {
      return 1;
    }
    if ((*(ushort *)(*(int *)(&LAB_800d0420 + CurrentWarpNumber * 0x14) + 6) & 8) == 0) {
      return 1;
    }
  }
  else {
    id = *(int *)(signal->data + 4);
  }
  if (instance->currentStreamUnitID != id) {
    if (instance == DAT_800d20f8) {
      DAT_800d2248 = 1;
      DAT_800cf180 = DAT_800d2300;
      strcpy();
      DAT_800d225e = *(undefined2 *)signal->data;
      DAT_800d225c = uVar5;
      DAT_800d226c = id;
      if (bVar1) {
        if ((DAT_800d20d6 == 0) && (id = strcmpi(acStack48,s_under3_800cf190), id == 0)) {
          INSTANCE_Post(DAT_800d20f8,0x10002001,0);
        }
        lVar4 = WARPGATE_GetWarpRoomIndex(&DAT_800d2228);
        DAT_800d224a = (undefined2)lVar4;
      }
      else {
        DAT_800d224a = 0xffff;
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
 // line 265, offset 0x8001dc7c
	/* begin block 1 */
		// Start line: 266
		// Start offset: 0x8001DC7C
		// Variables:
	// 		struct Level *level; // $s0
	/* end block 1 */
	// End offset: 0x8001DC7C
	// End Line: 266

	/* begin block 2 */
		// Start line: 553
	/* end block 2 */
	// End Line: 554

	/* begin block 3 */
		// Start line: 558
	/* end block 3 */
	// End Line: 559

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleFogNear(_Instance *instance,Signal *signal)

{
  ushort uVar1;
  Level *level;
  
  level = STREAM_GetLevelWithID(*(long *)(DAT_800d20f8 + 0x38));
  uVar1 = *(ushort *)signal->data;
  level->fogNear = uVar1;
  SetFogNearFar((uint)uVar1,(uint)level->fogFar,DAT_800d1004);
  LIGHT_CalcDQPTable(level);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleFogFar(struct _Instance *instance /*$a0*/, struct Signal *signal /*$s1*/)
 // line 287, offset 0x8001dcd0
	/* begin block 1 */
		// Start line: 288
		// Start offset: 0x8001DCD0
		// Variables:
	// 		struct Level *level; // $s0
	/* end block 1 */
	// End offset: 0x8001DCD0
	// End Line: 288

	/* begin block 2 */
		// Start line: 613
	/* end block 2 */
	// End Line: 614

	/* begin block 3 */
		// Start line: 618
	/* end block 3 */
	// End Line: 619

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleFogFar(_Instance *instance,Signal *signal)

{
  ushort uVar1;
  Level *level;
  
  level = STREAM_GetLevelWithID(*(long *)(DAT_800d20f8 + 0x38));
  uVar1 = *(ushort *)signal->data;
  level->fogFar = uVar1;
  SetFogNearFar((uint)level->fogNear,(uint)uVar1,DAT_800d1004);
  LIGHT_CalcDQPTable(level);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCameraShake(struct _Instance *instance /*$a0*/, struct Signal *signal /*$v0*/)
 // line 314, offset 0x8001dd2c
	/* begin block 1 */
		// Start line: 623
	/* end block 1 */
	// End Line: 624

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleCameraShake(_Instance *instance,Signal *signal)

{
  CAMERA_SetShake((Camera *)&theCamera,*(long *)signal->data,*(long *)(signal->data + 4));
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleCallSignal(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 320, offset 0x8001dd60
	/* begin block 1 */
		// Start line: 683
	/* end block 1 */
	// End Line: 684

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleCallSignal(_Instance *instance,Signal *signal)

{
  SIGNAL_HandleSignal(instance,(Signal *)(*(int *)signal->data + 8),0);
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleStopPlayerControl(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 326, offset 0x8001dd88
	/* begin block 1 */
		// Start line: 695
	/* end block 1 */
	// End Line: 696

	/* begin block 2 */
		// Start line: 696
	/* end block 2 */
	// End Line: 697

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleStopPlayerControl(_Instance *instance,Signal *signal)

{
  DAT_800d220c = DAT_800d220c | 0x90;
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleStartPlayerControl(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 333, offset 0x8001dda0
	/* begin block 1 */
		// Start line: 709
	/* end block 1 */
	// End Line: 710

	/* begin block 2 */
		// Start line: 710
	/* end block 2 */
	// End Line: 711

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleStartPlayerControl(_Instance *instance,Signal *signal)

{
  DAT_800d220c = DAT_800d220c & 0xffffff6f;
  return 1;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SIGNAL_RelocateCameraSpline(struct Signal *signal /*$a0*/, long offset /*$a1*/)
 // line 500, offset 0x8001ddc0
	/* begin block 1 */
		// Start line: 996
	/* end block 1 */
	// End Line: 997

	/* begin block 2 */
		// Start line: 880
	/* end block 2 */
	// End Line: 881

/* File: C:\kain2\game\SIGNAL.C */

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
 // line 505, offset 0x8001dddc
	/* begin block 1 */
		// Start line: 889
	/* end block 1 */
	// End Line: 890

	/* begin block 2 */
		// Start line: 890
	/* end block 2 */
	// End Line: 891

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleCameraSpline(_Instance *instance,Signal *signal)

{
  if (*(int *)signal->data == 0) {
    if (*(int *)(signal->data + 4) == 0) {
      DAT_800d13b8 = 0;
      return 1;
    }
    DAT_800d13b8 = *(undefined4 *)(*(int *)(signal->data + 4) + 0x38);
    return 1;
  }
  if (*(int *)signal->data == 1) {
    if (*(int *)(signal->data + 4) != 0) {
      DAT_800d13bc = *(undefined4 *)(*(int *)(signal->data + 4) + 0x38);
      return 1;
    }
    DAT_800d13bc = 0;
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleScreenWipe(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 537, offset 0x8001de5c
	/* begin block 1 */
		// Start line: 953
	/* end block 1 */
	// End Line: 954

	/* begin block 2 */
		// Start line: 954
	/* end block 2 */
	// End Line: 955

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleScreenWipe(_Instance *instance,Signal *signal)

{
  DAT_800d219a = *(short *)(signal->data + 2);
  if (DAT_800d219a < 0) {
    DAT_800d219a = -DAT_800d219a;
  }
  DAT_800d2198 = *(undefined2 *)(signal->data + 2);
  LAB_800d219c = *(undefined2 *)signal->data;
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleBlendStart(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 545, offset 0x8001de94
	/* begin block 1 */
		// Start line: 969
	/* end block 1 */
	// End Line: 970

	/* begin block 2 */
		// Start line: 979
	/* end block 2 */
	// End Line: 980

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleBlendStart(_Instance *instance,Signal *signal)

{
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleScreenWipeColor(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 559, offset 0x8001de9c
	/* begin block 1 */
		// Start line: 997
	/* end block 1 */
	// End Line: 998

	/* begin block 2 */
		// Start line: 998
	/* end block 2 */
	// End Line: 999

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleScreenWipeColor(_Instance *instance,Signal *signal)

{
  DAT_800d2194 = signal->data[0];
  DAT_800d2195 = signal->data[1];
  DAT_800d2196 = signal->data[2];
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleSetSlideAngle(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 567, offset 0x8001dec8
	/* begin block 1 */
		// Start line: 568
		// Start offset: 0x8001DEC8
		// Variables:
	// 		long slideAngle; // $a2
	/* end block 1 */
	// End offset: 0x8001DEE8
	// End Line: 578

	/* begin block 2 */
		// Start line: 1013
	/* end block 2 */
	// End Line: 1014

/* File: C:\kain2\game\SIGNAL.C */

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
 // line 581, offset 0x8001def8
	/* begin block 1 */
		// Start line: 1042
	/* end block 1 */
	// End Line: 1043

/* File: C:\kain2\game\SIGNAL.C */

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
 // line 593, offset 0x8001df24
	/* begin block 1 */
		// Start line: 594
		// Start offset: 0x8001DF24
		// Variables:
	// 		long tilt; // $v0
	/* end block 1 */
	// End offset: 0x8001DFA4
	// End Line: 608

	/* begin block 2 */
		// Start line: 1066
	/* end block 2 */
	// End Line: 1067

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleSetCameraTilt(_Instance *instance,Signal *signal)

{
  int iVar1;
  
  if (instance != (_Instance *)0x0) {
    iVar1 = -*(int *)signal->data % 0x168;
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0x168;
    }
    CAMERA_Adjust_tilt((Camera *)&theCamera,(iVar1 * 0x1000) / 0x168);
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleSetCameraDistance(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 611, offset 0x8001dfb4
	/* begin block 1 */
		// Start line: 612
		// Start offset: 0x8001DFB4
		// Variables:
	// 		long distance; // $a1
	/* end block 1 */
	// End offset: 0x8001DFD8
	// End Line: 622

	/* begin block 2 */
		// Start line: 1103
	/* end block 2 */
	// End Line: 1104

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleSetCameraDistance(_Instance *instance,Signal *signal)

{
  if (instance != (_Instance *)0x0) {
    CAMERA_Adjust_distance((Camera *)&theCamera,*(long *)signal->data);
  }
  return 1;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_HandleEnd(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
 // line 742, offset 0x8001dfe8
	/* begin block 1 */
		// Start line: 1366
	/* end block 1 */
	// End Line: 1367

	/* begin block 2 */
		// Start line: 1367
	/* end block 2 */
	// End Line: 1368

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_HandleEnd(_Instance *instance,Signal *signal)

{
  return 0;
}



// decompiled code
// original method signature: 
// void /*$ra*/ COLLIDE_HandleSignal(struct _Instance *instance /*$s3*/, struct Signal *signal /*$s0*/, long numSignals /*$a2*/, int dontForceDoSignal /*$a3*/)
 // line 842, offset 0x8001dff0
	/* begin block 1 */
		// Start line: 843
		// Start offset: 0x8001DFF0
		// Variables:
	// 		long signalNumber; // $v1
	/* end block 1 */
	// End offset: 0x8001E0DC
	// End Line: 898

	/* begin block 2 */
		// Start line: 1566
	/* end block 2 */
	// End Line: 1567

/* File: C:\kain2\game\SIGNAL.C */

void COLLIDE_HandleSignal(_Instance *instance,Signal *signal,long numSignals,int dontForceDoSignal)

{
  int iVar1;
  uint uVar2;
  
  if (numSignals != 0) {
    while( true ) {
      uVar2 = signal->id & 0x7fffffff;
      if ((((signalInfoList[uVar2].onlyPlayer == 0) || (instance == DAT_800d20f8)) &&
          (((DAT_800d220c & 0x40) == 0 || (-1 < signal->id)))) &&
         ((0x1a < uVar2 ||
          (iVar1 = (*(code *)signalInfoList[uVar2].signalHandleFunc)(instance,signal), iVar1 == 0)))
         ) break;
      signal = (Signal *)(&signal->id + (int)signalInfoList[signal->id & 0x7fffffff].length + 1);
    }
  }
  return;
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_IsThisStreamAWarpGate(struct Signal *signal /*$a0*/)
 // line 900, offset 0x8001e0f8
	/* begin block 1 */
		// Start line: 901
		// Start offset: 0x8001E0F8
		// Variables:
	// 		long result; // $s0
	// 		char areaName[32]; // stack offset -40
	// 		char *commapos; // $v0
	/* end block 1 */
	// End offset: 0x8001E144
	// End Line: 918

	/* begin block 2 */
		// Start line: 1682
	/* end block 2 */
	// End Line: 1683

/* File: C:\kain2\game\SIGNAL.C */

long SIGNAL_IsThisStreamAWarpGate(Signal *signal)

{
  char *pcVar1;
  int iVar2;
  char acStack40 [32];
  
  strcpy();
  pcVar1 = strchr(acStack40,',');
  if (pcVar1 != (char *)0x0) {
    *pcVar1 = '\0';
  }
  iVar2 = strcmpi(acStack40,s_warpgate_800cf184);
  return (uint)(iVar2 == 0);
}



// decompiled code
// original method signature: 
// long /*$ra*/ SIGNAL_IsStreamSignal(struct Signal *signal /*$s1*/, long *isWarpGate /*$s4*/)
 // line 921, offset 0x8001e158
	/* begin block 1 */
		// Start line: 922
		// Start offset: 0x8001E158
		// Variables:
	// 		long result; // $s3
	// 		long done; // $s2
	// 		long signalNumber; // $s0
	/* end block 1 */
	// End offset: 0x8001E210
	// End Line: 964

	/* begin block 2 */
		// Start line: 1728
	/* end block 2 */
	// End Line: 1729

/* File: C:\kain2\game\SIGNAL.C */

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
    signal = (Signal *)(&signal->id + (int)signalInfoList[uVar3].length + 1);
  }
  return lVar4;
}



// decompiled code
// original method signature: 
// void /*$ra*/ SIGNAL_HandleSignal(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/, int dontForceDoSignal /*$a3*/)
 // line 967, offset 0x8001e234
	/* begin block 1 */
		// Start line: 1827
	/* end block 1 */
	// End Line: 1828

/* File: C:\kain2\game\SIGNAL.C */

void SIGNAL_HandleSignal(_Instance *instance,Signal *signal,int dontForceDoSignal)

{
  COLLIDE_HandleSignal(instance,signal,1,dontForceDoSignal);
  return;
}



// decompiled code
// original method signature: 
// struct _MultiSignal * /*$ra*/ SIGNAL_RelocateSignal(struct _MultiSignal *multiSignal /*$s4*/, long offset /*$s5*/)
 // line 974, offset 0x8001e258
	/* begin block 1 */
		// Start line: 975
		// Start offset: 0x8001E258
		// Variables:
	// 		int i; // $s1
	// 		struct Signal *signal; // $s0
	/* end block 1 */
	// End offset: 0x8001E310
	// End Line: 997

	/* begin block 2 */
		// Start line: 1841
	/* end block 2 */
	// End Line: 1842

/* File: C:\kain2\game\SIGNAL.C */

_MultiSignal * SIGNAL_RelocateSignal(_MultiSignal *multiSignal,long offset)

{
  Signal *pSVar1;
  int iVar2;
  
  pSVar1 = multiSignal->signalList;
  iVar2 = 0;
  if (0 < multiSignal->numSignals) {
    do {
      if ((code *)signalInfoList[pSVar1->id & 0x7fffffff].signalRelocateFunc != (code *)0x0) {
        (*(code *)signalInfoList[pSVar1->id & 0x7fffffff].signalRelocateFunc)(pSVar1,offset);
      }
      iVar2 = iVar2 + 1;
      pSVar1 = (Signal *)(&pSVar1->id + (int)signalInfoList[pSVar1->id & 0x7fffffff].length + 1);
    } while (iVar2 < multiSignal->numSignals);
  }
  return (_MultiSignal *)pSVar1->data;
}



// decompiled code
// original method signature: 
// struct _MultiSignal * /*$ra*/ SIGNAL_FindSignal(struct Level *level /*$a0*/, long id /*$a1*/)
 // line 1000, offset 0x8001e338
	/* begin block 1 */
		// Start line: 1002
		// Start offset: 0x8001E338
		// Variables:
	// 		int i; // $a2
	// 		struct Signal *signal; // $a3
	// 		struct _MultiSignal *msignal; // $v1
	// 		long signalNumber; // $v1
	/* end block 1 */
	// End offset: 0x8001E3E4
	// End Line: 1043

	/* begin block 2 */
		// Start line: 1918
	/* end block 2 */
	// End Line: 1919

	/* begin block 3 */
		// Start line: 1919
	/* end block 3 */
	// End Line: 1920

	/* begin block 4 */
		// Start line: 1925
	/* end block 4 */
	// End Line: 1926

/* File: C:\kain2\game\SIGNAL.C */

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
          pSVar3 = (Signal *)(&pSVar3->id + (int)signalInfoList[pSVar3->id & 0x7fffffff].length + 1)
          ;
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
 // line 1047, offset 0x8001e3ec
	/* begin block 1 */
		// Start line: 1048
		// Start offset: 0x8001E3EC
		// Variables:
	// 		struct Level *level; // $v0
	/* end block 1 */
	// End offset: 0x8001E42C
	// End Line: 1058

	/* begin block 2 */
		// Start line: 2038
	/* end block 2 */
	// End Line: 2039

/* File: C:\kain2\game\SIGNAL.C */

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
 // line 1060, offset 0x8001e43c
	/* begin block 1 */
		// Start line: 1061
		// Start offset: 0x8001E43C
		// Variables:
	// 		struct Level *level; // $v0
	/* end block 1 */
	// End offset: 0x8001E47C
	// End Line: 1070

	/* begin block 2 */
		// Start line: 2064
	/* end block 2 */
	// End Line: 2065

/* File: C:\kain2\game\SIGNAL.C */

void SIGNAL_InWater(_Instance *instance)

{
  Level *pLVar1;
  
  pLVar1 = STREAM_GetLevelWithID(instance->currentStreamUnitID);
  if ((pLVar1 != (Level *)0x0) && (pLVar1->startGoingIntoWaterSignal != (_MultiSignal *)0x0)) {
    SIGNAL_HandleSignal(instance,pLVar1->startGoingIntoWaterSignal->signalList,0);
  }
  return;
}





