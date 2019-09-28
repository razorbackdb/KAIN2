#include "THISDUST.H"
#include "SIGNAL.H"

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleLightGroup(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 76, offset 0x8001d840
/* begin block 1 */
// Start line: 152
/* end block 1 */
// End Line: 153

/* begin block 2 */
// Start line: 153
/* end block 2 */
// End Line: 154

long SIGNAL_HandleLightGroup(_Instance *instance, Signal *signal)

{
	if (instance != (_Instance *)0x0)
	{
		instance->lightGroup = signal->data[0];
	}
	return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleCameraAdjust(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 85, offset 0x8001d85c
/* begin block 1 */
// Start line: 170
/* end block 1 */
// End Line: 171

long SIGNAL_HandleCameraAdjust(_Instance *instance, Signal *signal)

{
	CAMERA_Adjust((Camera *)&theCamera, *(long *)signal->data);
	return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleCamera(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 91, offset 0x8001d884
/* begin block 1 */
// Start line: 182
/* end block 1 */
// End Line: 183

long SIGNAL_HandleCamera(_Instance *instance, Signal *signal)

{
	CAMERA_ChangeTo((Camera *)&theCamera, *(_CameraKey **)signal->data);
	return 1;
}

// decompiled code
// original method signature:
// void /*$ra*/ SIGNAL_RelocateCamera(struct Signal *signal /*$a0*/, long offset /*$a1*/)
// line 97, offset 0x8001d8ac
/* begin block 1 */
// Start line: 194
/* end block 1 */
// End Line: 195

/* begin block 2 */
// Start line: 195
/* end block 2 */
// End Line: 196

void SIGNAL_RelocateCamera(Signal *signal, long offset)

{
	int iVar1;

	iVar1 = 0;
	if (*(int *)signal->data != 0)
	{
		iVar1 = *(int *)signal->data + offset;
	}
	*(int *)signal->data = iVar1;
	return;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleCameraMode(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 102, offset 0x8001d8c8
/* begin block 1 */
// Start line: 204
/* end block 1 */
// End Line: 205

long SIGNAL_HandleCameraMode(_Instance *instance, Signal *signal)

{
	CAMERA_SetMode((Camera *)&theCamera, *(long *)signal->data);
	return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleCameraLock(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 110, offset 0x8001d8f0
/* begin block 1 */
// Start line: 220
/* end block 1 */
// End Line: 221

long SIGNAL_HandleCameraLock(_Instance *instance, Signal *signal)

{
	CAMERA_Lock((Camera *)&theCamera, *(long *)signal->data);
	return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleCameraUnlock(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 116, offset 0x8001d918
/* begin block 1 */
// Start line: 232
/* end block 1 */
// End Line: 233

long SIGNAL_HandleCameraUnlock(_Instance *instance, Signal *signal)

{
	CAMERA_Unlock((Camera *)&theCamera, *(long *)signal->data);
	return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleCameraSmooth(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 122, offset 0x8001d940
/* begin block 1 */
// Start line: 244
/* end block 1 */
// End Line: 245

long SIGNAL_HandleCameraSmooth(_Instance *instance, Signal *signal)

{
	CAMERA_SetSmoothValue((Camera *)&theCamera, *(long *)signal->data);
	return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleCameraTimer(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 128, offset 0x8001d968
/* begin block 1 */
// Start line: 256
/* end block 1 */
// End Line: 257

long SIGNAL_HandleCameraTimer(_Instance *instance, Signal *signal)

{
	CAMERA_SetTimer((Camera *)&theCamera, *(long *)signal->data);
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

long SIGNAL_HandleCameraSave(_Instance *instance, Signal *signal)

{
	CAMERA_Save((Camera *)&theCamera, *(long *)signal->data);
	return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleCameraRestore(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 140, offset 0x8001d9b8
/* begin block 1 */
// Start line: 280
/* end block 1 */
// End Line: 281

long SIGNAL_HandleCameraRestore(_Instance *instance, Signal *signal)

{
	CAMERA_Restore((Camera *)&theCamera, *(long *)signal->data);
	return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleCameraValue(struct _Instance *instance /*$a0*/, struct Signal *signal /*$v0*/)
// line 146, offset 0x8001d9e0
/* begin block 1 */
// Start line: 292
/* end block 1 */
// End Line: 293

long SIGNAL_HandleCameraValue(_Instance *instance, Signal *signal)

{
	CAMERA_SetValue((Camera *)&theCamera, *(long *)signal->data, *(long *)(signal->data + 4));
	return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleStreamLevel(struct _Instance *instance /*$s2*/, struct Signal *signal /*$s4*/)
// line 157, offset 0x8001da10
/* begin block 1 */
// Start line: 158
// Start offset: 0x8001DA10
// Variables:
// 		char areaName[16]; // stack offset -48
// 		int signalnum; // $s5
// 		char *commapos; // $s0
// 		long newStreamID; // $s1
// 		static int lastTimeCrossed; // offset 0x4
// 		long doingWarpRoom; // $s3

/* begin block 1.1 */
// Start line: 177
// Start offset: 0x8001DA8C
// Variables:
// 		struct _StreamUnit *curStreamUnit; // $v0
/* end block 1.1 */
// End offset: 0x8001DB38
// End Line: 199

/* begin block 1.2 */
// Start line: 246
// Start offset: 0x8001DBF4
/* end block 1.2 */
// End offset: 0x8001DC44
// End Line: 261
/* end block 1 */
// End offset: 0x8001DC48
// End Line: 264

/* begin block 2 */
// Start line: 314
/* end block 2 */
// End Line: 315

long SIGNAL_HandleStreamLevel(_Instance *instance, Signal *signal)

{
	char acStack48[16];

	/* WARNING: Subroutine does not return */
	strcpy(acStack48, (char *)(signal->data + 8));
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleFogNear(struct _Instance *instance /*$a0*/, struct Signal *signal /*$s0*/)
// line 267, offset 0x8001dc6c
/* begin block 1 */
// Start line: 268
// Start offset: 0x8001DC6C
// Variables:
// 		struct Level *level; // $s0
/* end block 1 */
// End offset: 0x8001DC6C
// End Line: 268

/* begin block 2 */
// Start line: 557
/* end block 2 */
// End Line: 558

/* begin block 3 */
// Start line: 562
/* end block 3 */
// End Line: 563

long SIGNAL_HandleFogNear(_Instance *instance, Signal *signal)

{
	/* WARNING: Subroutine does not return */
	STREAM_GetLevelWithID(*(long *)(DAT_800d0fd8 + 0x38));
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleFogFar(struct _Instance *instance /*$a0*/, struct Signal *signal /*$s1*/)
// line 289, offset 0x8001dcc0
/* begin block 1 */
// Start line: 290
// Start offset: 0x8001DCC0
// Variables:
// 		struct Level *level; // $s0
/* end block 1 */
// End offset: 0x8001DCC0
// End Line: 290

/* begin block 2 */
// Start line: 617
/* end block 2 */
// End Line: 618

/* begin block 3 */
// Start line: 622
/* end block 3 */
// End Line: 623

long SIGNAL_HandleFogFar(_Instance *instance, Signal *signal)

{
	/* WARNING: Subroutine does not return */
	STREAM_GetLevelWithID(*(long *)(DAT_800d0fd8 + 0x38));
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleCameraShake(struct _Instance *instance /*$a0*/, struct Signal *signal /*$v0*/)
// line 316, offset 0x8001dd1c
/* begin block 1 */
// Start line: 632
/* end block 1 */
// End Line: 633

long SIGNAL_HandleCameraShake(_Instance *instance, Signal *signal)

{
	CAMERA_SetShake((Camera *)&theCamera, *(long *)signal->data, *(long *)(signal->data + 4));
	return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleCallSignal(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 322, offset 0x8001dd4c
/* begin block 1 */
// Start line: 687
/* end block 1 */
// End Line: 688

long SIGNAL_HandleCallSignal(_Instance *instance, Signal *signal)

{
	SIGNAL_HandleSignal(instance, (Signal *)(*(int *)signal->data + 8), 0);
	return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleStopPlayerControl(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 328, offset 0x8001dd74
/* begin block 1 */
// Start line: 699
/* end block 1 */
// End Line: 700

/* begin block 2 */
// Start line: 700
/* end block 2 */
// End Line: 701

long SIGNAL_HandleStopPlayerControl(_Instance *instance, Signal *signal)

{
	DAT_800d10ec = DAT_800d10ec | 0x90;
	return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleStartPlayerControl(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 335, offset 0x8001dd8c
/* begin block 1 */
// Start line: 713
/* end block 1 */
// End Line: 714

/* begin block 2 */
// Start line: 714
/* end block 2 */
// End Line: 715

long SIGNAL_HandleStartPlayerControl(_Instance *instance, Signal *signal)

{
	DAT_800d10ec = DAT_800d10ec & 0xffffff6f;
	return 1;
}

// decompiled code
// original method signature:
// void /*$ra*/ SIGNAL_RelocateCameraSpline(struct Signal *signal /*$a0*/, long offset /*$a1*/)
// line 502, offset 0x8001ddac
/* begin block 1 */
// Start line: 1004
/* end block 1 */
// End Line: 1005

/* begin block 2 */
// Start line: 884
/* end block 2 */
// End Line: 885

void SIGNAL_RelocateCameraSpline(Signal *signal, long offset)

{
	int iVar1;

	iVar1 = 0;
	if (*(int *)(signal->data + 4) != 0)
	{
		iVar1 = *(int *)(signal->data + 4) + offset;
	}
	*(int *)(signal->data + 4) = iVar1;
	return;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleCameraSpline(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 507, offset 0x8001ddc8
/* begin block 1 */
// Start line: 893
/* end block 1 */
// End Line: 894

/* begin block 2 */
// Start line: 894
/* end block 2 */
// End Line: 895

long SIGNAL_HandleStreamLevel(_Instance *instance, Signal *signal)

{
	if (*(int *)signal->data == 0)
	{
		if (*(int *)(signal->data + 4) == 0)
		{
			DAT_800d1d90 = 0;
			return 1;
		}
		DAT_800d1d90 = *(undefined4 *)(*(int *)(signal->data + 4) + 0x38);
		return 1;
	}
	if (*(int *)signal->data == 1)
	{
		if (*(int *)(signal->data + 4) != 0)
		{
			DAT_800d1d94 = *(undefined4 *)(*(int *)(signal->data + 4) + 0x38);
			return 1;
		}
		DAT_800d1d94 = 0;
	}
	return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleScreenWipe(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 539, offset 0x8001de48
/* begin block 1 */
// Start line: 957
/* end block 1 */
// End Line: 958

/* begin block 2 */
// Start line: 958
/* end block 2 */
// End Line: 959

long SIGNAL_HandleScreenWipe(_Instance *instance, Signal *signal)

{
	DAT_800d107a = *(short *)(signal->data + 2);
	if (DAT_800d107a < 0)
	{
		DAT_800d107a = -DAT_800d107a;
	}
	DAT_800d1078 = *(undefined2 *)(signal->data + 2);
	DAT_800d107c = *(undefined2 *)signal->data;
	return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleBlendStart(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 547, offset 0x8001de80
/* begin block 1 */
// Start line: 973
/* end block 1 */
// End Line: 974

/* begin block 2 */
// Start line: 983
/* end block 2 */
// End Line: 984

long SIGNAL_HandleBlendStart(_Instance *instance, Signal *signal)

{
	return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleScreenWipeColor(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 561, offset 0x8001de88
/* begin block 1 */
// Start line: 1001
/* end block 1 */
// End Line: 1002

/* begin block 2 */
// Start line: 1002
/* end block 2 */
// End Line: 1003

long SIGNAL_HandleScreenWipeColor(_Instance *instance, Signal *signal)

{
	DAT_800d1074 = signal->data[0];
	DAT_800d1075 = signal->data[1];
	DAT_800d1076 = signal->data[2];
	return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleSetSlideAngle(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 569, offset 0x8001deb4
/* begin block 1 */
// Start line: 570
// Start offset: 0x8001DEB4
// Variables:
// 		long slideAngle; // $a2
/* end block 1 */
// End offset: 0x8001DED4
// End Line: 580

/* begin block 2 */
// Start line: 1017
/* end block 2 */
// End Line: 1018

long SIGNAL_HandleSetSlideAngle(_Instance *instance, Signal *signal)

{
	if (instance != (_Instance *)0x0)
	{
		/* WARNING: Subroutine does not return */
		INSTANCE_Post(instance, 0x4000005, *(int *)signal->data);
	}
	return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleResetSlideAngle(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 583, offset 0x8001dee4
/* begin block 1 */
// Start line: 1046
/* end block 1 */
// End Line: 1047

long SIGNAL_HandleResetSlideAngle(_Instance *instance, Signal *signal)

{
	if (instance != (_Instance *)0x0)
	{
		/* WARNING: Subroutine does not return */
		INSTANCE_Post(instance, 0x4000006, 0);
	}
	return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleSetCameraTilt(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 595, offset 0x8001df10
/* begin block 1 */
// Start line: 596
// Start offset: 0x8001DF10
// Variables:
// 		long tilt; // $v0
/* end block 1 */
// End offset: 0x8001DF8C
// End Line: 610

/* begin block 2 */
// Start line: 1070
/* end block 2 */
// End Line: 1071

long SIGNAL_HandleSetCameraTilt(_Instance *instance, Signal *signal)

{
	int iVar1;

	if (instance != (_Instance *)0x0)
	{
		iVar1 = -*(int *)signal->data % 0x168;
		if (iVar1 < 0)
		{
			iVar1 = iVar1 + 0x168;
		}
		CAMERA_Adjust_tilt((Camera *)&theCamera, (iVar1 * 0x1000) / 0x168);
	}
	return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleSetCameraDistance(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 613, offset 0x8001df9c
/* begin block 1 */
// Start line: 614
// Start offset: 0x8001DF9C
// Variables:
// 		long distance; // $a1
/* end block 1 */
// End offset: 0x8001DFBC
// End Line: 624

/* begin block 2 */
// Start line: 1107
/* end block 2 */
// End Line: 1108

long SIGNAL_HandleSetCameraDistance(_Instance *instance, Signal *signal)

{
	if (instance != (_Instance *)0x0)
	{
		CAMERA_Adjust_distance((Camera *)&theCamera, *(long *)signal->data);
	}
	return 1;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_HandleEnd(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/)
// line 744, offset 0x8001dfcc
/* begin block 1 */
// Start line: 1370
/* end block 1 */
// End Line: 1371

/* begin block 2 */
// Start line: 1371
/* end block 2 */
// End Line: 1372

long SIGNAL_HandleEnd(_Instance *instance, Signal *signal)

{
	return 0;
}

// decompiled code
// original method signature:
// void /*$ra*/ COLLIDE_HandleSignal(struct _Instance *instance /*$s3*/, struct Signal *signal /*$s0*/, long numSignals /*$a2*/, int dontForceDoSignal /*$a3*/)
// line 844, offset 0x8001dfd4
/* begin block 1 */
// Start line: 845
// Start offset: 0x8001DFD4
// Variables:
// 		long signalNumber; // $v1
/* end block 1 */
// End offset: 0x8001E0BC
// End Line: 900

/* begin block 2 */
// Start line: 1570
/* end block 2 */
// End Line: 1571

void COLLIDE_HandleSignal(_Instance *instance, Signal *signal, long numSignals, int dontForceDoSignal)

{
	long lVar1;
	uint uVar2;

	if (numSignals != 0)
	{
		while (true)
		{
			uVar2 = signal->id & 0x7fffffff;
			if ((((signalInfoList[uVar2].onlyPlayer == 0) || (instance == DAT_800d0fd8)) &&
				 (((DAT_800d10ec & 0x40) == 0 || (-1 < signal->id)))) &&
				((0x1a < uVar2 ||
				  (lVar1 = (*signalInfoList[uVar2].signalHandleFunc)(instance, signal), lVar1 == 0))))
				break;
			signal = (Signal *)(&signal->id + (int)signalInfoList[signal->id & 0x7fffffff].length + 1);
		}
	}
	return;
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_IsThisStreamAWarpGate(struct Signal *signal /*$a0*/)
// line 902, offset 0x8001e0d8
/* begin block 1 */
// Start line: 903
// Start offset: 0x8001E0D8
// Variables:
// 		long result; // $s0
// 		char areaName[32]; // stack offset -40
// 		char *commapos; // $v0
/* end block 1 */
// End offset: 0x8001E124
// End Line: 920

/* begin block 2 */
// Start line: 1686
/* end block 2 */
// End Line: 1687

long SIGNAL_IsThisStreamAWarpGate(Signal *signal)

{
	char acStack40[32];

	/* WARNING: Subroutine does not return */
	strcpy(acStack40, (char *)(signal->data + 8));
}

// decompiled code
// original method signature:
// long /*$ra*/ SIGNAL_IsStreamSignal(struct Signal *signal /*$s1*/, long *isWarpGate /*$s4*/)
// line 923, offset 0x8001e138
/* begin block 1 */
// Start line: 924
// Start offset: 0x8001E138
// Variables:
// 		long result; // $s3
// 		long done; // $s2
// 		long signalNumber; // $s0
/* end block 1 */
// End offset: 0x8001E1EC
// End Line: 966

/* begin block 2 */
// Start line: 1732
/* end block 2 */
// End Line: 1733

undefined4 SIGNAL_IsStreamSignal(Signal *param_1, undefined4 *param_2)

{
	bool bVar1;
	long lVar2;
	uint uVar3;
	undefined4 uVar4;

	uVar4 = 0;
	bVar1 = false;
	*param_2 = 0;
	while (true)
	{
		uVar3 = param_1->id & 0x7fffffff;
		if (uVar3 == 0xf)
		{
			bVar1 = true;
		}
		else
		{
			if (uVar3 == 0x12)
			{
				bVar1 = true;
				uVar4 = 1;
				lVar2 = SIGNAL_IsThisStreamAWarpGate(param_1);
				if (lVar2 != 0)
				{
					*param_2 = 1;
				}
			}
		}
		if (bVar1)
			break;
		param_1 = (Signal *)(&param_1->id + (int)*(short *)(&gp0xffff8510 + uVar3 * 0xc) + 1);
	}
	return uVar4;
}

// decompiled code
// original method signature:
// void /*$ra*/ SIGNAL_HandleSignal(struct _Instance *instance /*$a0*/, struct Signal *signal /*$a1*/, int dontForceDoSignal /*$a3*/)
// line 969, offset 0x8001e210
/* begin block 1 */
// Start line: 1831
/* end block 1 */
// End Line: 1832

void SIGNAL_HandleSignal(_Instance *instance, Signal *signal, int dontForceDoSignal)

{
	COLLIDE_HandleSignal(instance, signal, 1, dontForceDoSignal);
	return;
}

// decompiled code
// original method signature:
// struct _MultiSignal * /*$ra*/ SIGNAL_RelocateSignal(struct _MultiSignal *multiSignal /*$s4*/, long offset /*$s5*/)
// line 976, offset 0x8001e234
/* begin block 1 */
// Start line: 977
// Start offset: 0x8001E234
// Variables:
// 		int i; // $s1
// 		struct Signal *signal; // $s0
/* end block 1 */
// End offset: 0x8001E2E8
// End Line: 999

/* begin block 2 */
// Start line: 1845
/* end block 2 */
// End Line: 1846

_MultiSignal *SIGNAL_RelocateSignal(_MultiSignal *multiSignal, long offset)

{
	Signal *pSVar1;
	int iVar2;

	pSVar1 = multiSignal->signalList;
	iVar2 = 0;
	if (0 < multiSignal->numSignals)
	{
		do
		{
			if (signalInfoList[pSVar1->id & 0x7fffffff].signalRelocateFunc != (_func_18 *)0x0)
			{
				(*signalInfoList[pSVar1->id & 0x7fffffff].signalRelocateFunc)(pSVar1, offset);
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
// line 1002, offset 0x8001e310
/* begin block 1 */
// Start line: 1004
// Start offset: 0x8001E310
// Variables:
// 		int i; // $a2
// 		struct Signal *signal; // $a3
// 		struct _MultiSignal *msignal; // $v1
// 		long signalNumber; // $v1
/* end block 1 */
// End offset: 0x8001E3B8
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

_MultiSignal *SIGNAL_FindSignal(Level *level, long id)

{
	_MultiSignal *p_Var1;
	int iVar2;
	Signal *pSVar3;

	p_Var1 = level->SignalListStart;
	if (p_Var1 < level->SignalListEnd)
	{
		do
		{
			pSVar3 = p_Var1->signalList;
			if (id == (int)p_Var1->signalNum)
				break;
			iVar2 = 0;
			if (0 < p_Var1->numSignals)
			{
				do
				{
					iVar2 = iVar2 + 1;
					pSVar3 = (Signal *)(&pSVar3->id + (int)signalInfoList[pSVar3->id & 0x7fffffff].length + 1);
				} while (iVar2 < p_Var1->numSignals);
			}
			p_Var1 = (_MultiSignal *)pSVar3->data;
		} while (p_Var1 < level->SignalListEnd);
	}
	if (p_Var1 == level->SignalListEnd)
	{
		p_Var1 = (_MultiSignal *)0x0;
	}
	return p_Var1;
}

// decompiled code
// original method signature:
// void /*$ra*/ SIGNAL_OutOfWater(struct _Instance *instance /*$s0*/)
// line 1049, offset 0x8001e3c0
/* begin block 1 */
// Start line: 1050
// Start offset: 0x8001E3C0
// Variables:
// 		struct Level *level; // $v0
/* end block 1 */
// End offset: 0x8001E400
// End Line: 1060

/* begin block 2 */
// Start line: 2042
/* end block 2 */
// End Line: 2043

void SIGNAL_OutOfWater(_Instance *instance)

{
	/* WARNING: Subroutine does not return */
	STREAM_GetLevelWithID(instance->currentStreamUnitID);
}

// decompiled code
// original method signature:
// void /*$ra*/ SIGNAL_InWater(struct _Instance *instance /*$s0*/)
// line 1062, offset 0x8001e410
/* begin block 1 */
// Start line: 1063
// Start offset: 0x8001E410
// Variables:
// 		struct Level *level; // $v0
/* end block 1 */
// End offset: 0x8001E450
// End Line: 1072

/* begin block 2 */
// Start line: 2068
/* end block 2 */
// End Line: 2069

void SIGNAL_InWater(_Instance *instance)

{
	/* WARNING: Subroutine does not return */
	STREAM_GetLevelWithID(instance->currentStreamUnitID);
}
