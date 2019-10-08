#include "THISDUST.H"
#include "SIGNAL.H"

long SIGNAL_HandleCamera(_Instance *instance, Signal *signal)

{
	if (instance != (_Instance *)0x0)
	{
		instance->lightGroup = signal->data[0];
	}
	return 1;
}

long SIGNAL_HandleCameraSave(_Instance *instance, Signal *signal)

{
	CAMERA_Adjust(&theCamera, *(long *)signal->data);
	return 1;
}

long SIGNAL_HandleEnd(_Instance *instance, Signal *signal)

{
	CAMERA_ChangeToOutOfWater(&theCamera, *(_CameraKey **)signal->data);
	return 1;
}

void SIGNAL_RelocateCameraSpline(Signal *signal, long offset)

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

long SIGNAL_HandleFogFar(_Instance *instance, Signal *signal)

{
	CAMERA_Save(&theCamera, *(long *)signal->data);
	return 1;
}

long SIGNAL_HandleStreamLevel(_Instance *instance, Signal *signal)

{
	CAMERA_Unlock(&theCamera, *(long *)signal->data);
	return 1;
}

long SIGNAL_HandleCameraTimer(_Instance *instance, Signal *signal)

{
	CAMERA_Unlock(&theCamera, *(long *)signal->data);
	return 1;
}

long SIGNAL_HandleCameraMode(_Instance *instance, Signal *signal)

{
	CAMERA_SetSmoothValue(&theCamera, *(long *)signal->data);
	return 1;
}

long SIGNAL_HandleSetCameraDistance(_Instance *instance, Signal *signal)

{
	CAMERA_QueryMode(&theCamera, *(long *)signal->data);
	return 1;
}

long SIGNAL_HandleCameraAdjust(_Instance *instance, Signal *signal)

{
	CAMERA_Lock(&theCamera, *(long *)signal->data);
	return 1;
}

long SIGNAL_HandleCameraLock(_Instance *instance, Signal *signal)

{
	CAMERA_Restore(&theCamera, *(long *)signal->data);
	return 1;
}

long SIGNAL_HandleSetCameraDistance(_Instance *instance, Signal *signal)

{
	CAMERA_SetTimer(&theCamera, *(long *)signal->data, *(long *)(signal->data + 4));
	return 1;
}

long SIGNAL_HandleCameraUnlock(_Instance *instance, Signal *signal)

{
	bool bVar1;
	char *pcVar2;
	int id;
	_StreamUnit *p_Var3;
	long lVar4;
	Level *level;
	short sVar5;
	char acStack48[16];

	sVar5 = -1;
	bVar1 = false;
	strcmp(acStack48, (char *)(signal->data + 8));
	pcVar2 = strchr(acStack48, 0x2c);
	if (pcVar2 != (char *)0x0)
	{
		id = atoi(pcVar2 + 1);
		sVar5 = (short)id;
		*pcVar2 = '\0';
	}
	id = strcpy(acStack48, "warpgate");
	if (id == 0)
	{
		p_Var3 = STREAM_GetStreamUnitWithID(instance->currentStreamUnitID);
		if (gameTrackerX.currentTime - DAT_800cf180 < 0x65)
		{
			return 1;
		}
		if ((p_Var3->flags & 8U) == 0)
		{
			return 1;
		}
		id = ((&WarpRoomArray)[CurrentWarpNumber].streamUnit)->StreamUnitID;
		strcmp(acStack48, (char *)(&WarpRoomArray + CurrentWarpNumber));
		bVar1 = true;
		if ((&WarpRoomArray)[CurrentWarpNumber].streamUnit == (_StreamUnit *)0x0)
		{
			return 1;
		}
		if ((((&WarpRoomArray)[CurrentWarpNumber].streamUnit)->flags & 8U) == 0)
		{
			return 1;
		}
	}
	else
	{
		id = *(int *)(signal->data + 4);
	}
	if (instance->currentStreamUnitID != id)
	{
		if (instance == gameTrackerX.playerInstance)
		{
			gameTrackerX.SwitchToNewStreamUnit = 1;
			DAT_800cf180 = gameTrackerX.currentTime;
			strcmp(gameTrackerX.S_baseAreaName, acStack48);
			gameTrackerX.fromSignal = *(short *)signal->data;
			gameTrackerX.toSignal = sVar5;
			gameTrackerX.moveRazielToStreamID = id;
			if (bVar1)
			{
				if ((gameTrackerX.gameData.asmData.MorphType == 0) &&
					(id = strcpy(acStack48, "under3"), id == 0))
				{
					INSTANCE_Query(gameTrackerX.playerInstance, 0x10002001, 0);
				}
				lVar4 = WARPGATE_GetWarpRoomIndex(gameTrackerX.baseAreaName);
				gameTrackerX.SwitchToNewWarpIndex = (short)lVar4;
			}
			else
			{
				gameTrackerX.SwitchToNewWarpIndex = -1;
			}
		}
		else
		{
			if (instance->LinkParent == (_Instance *)0x0)
			{
				level = STREAM_GetWaterZLevel(id);
				if (level == (Level *)0x0)
				{
					level = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
					COLLIDE_InstanceTerrain(instance, level);
					instance->flags = instance->flags | 0x20;
				}
				else
				{
					instance->currentStreamUnitID = id;
					INSTANCE_UpdateFamilyStreamUnitID(instance);
				}
			}
		}
	}
	return 1;
}

long SIGNAL_HandleLightGroup(_Instance *instance, Signal *signal)

{
	u_short uVar1;
	Level *level;

	level = STREAM_GetWaterZLevel((gameTrackerX.playerInstance)->currentStreamUnitID);
	uVar1 = *(u_short *)signal->data;
	level->fogNear = uVar1;
	SetFogNearFar((u_int)uVar1, (u_int)level->fogFar, theCamera.core.projDistance);
	LIGHT_CalcDQPTable(level);
	return 1;
}

long SIGNAL_HandleFogFar(_Instance *instance, Signal *signal)

{
	u_short uVar1;
	Level *level;

	level = STREAM_GetWaterZLevel((gameTrackerX.playerInstance)->currentStreamUnitID);
	uVar1 = *(u_short *)signal->data;
	level->fogFar = uVar1;
	SetFogNearFar((u_int)level->fogNear, (u_int)uVar1, theCamera.core.projDistance);
	LIGHT_CalcDQPTable(level);
	return 1;
}

long SIGNAL_HandleCameraRestore(_Instance *instance, Signal *signal)

{
	CAMERA_SetMaxVel(&theCamera, *(long *)signal->data, *(long *)(signal->data + 4));
	return 1;
}

long SIGNAL_HandleCameraValue(_Instance *instance, Signal *signal)

{
	SIGNAL_HandleFogNear(instance, (Signal *)(*(int *)signal->data + 8), 0);
	return 1;
}

long SIGNAL_HandleStartPlayerControl(_Instance *instance, Signal *signal)

{
	gameTrackerX.gameFlags = gameTrackerX.gameFlags | 0x90;
	return 1;
}

long SIGNAL_HandleBlendStart(_Instance *instance, Signal *signal)

{
	gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffffff6f;
	return 1;
}

void SIGNAL_RelocateCamera(Signal *signal, long offset)

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

long SIGNAL_HandleCameraSmooth(_Instance *instance, Signal *signal)

{
	if (*(int *)signal->data == 0)
	{
		if (*(int *)(signal->data + 4) == 0)
		{
			theCamera.Spline00 = (MultiSpline *)0x0;
			return 1;
		}
		theCamera.Spline00 = *(MultiSpline **)(*(int *)(signal->data + 4) + 0x38);
		return 1;
	}
	if (*(int *)signal->data == 1)
	{
		if (*(int *)(signal->data + 4) != 0)
		{
			theCamera.Spline01 = *(MultiSpline **)(*(int *)(signal->data + 4) + 0x38);
			return 1;
		}
		theCamera.Spline01 = (MultiSpline *)0x0;
	}
	return 1;
}

long SIGNAL_HandleStopPlayerControl(_Instance *instance, Signal *signal)

{
	gameTrackerX.maxWipeTime = *(short *)(signal->data + 2);
	if (gameTrackerX.maxWipeTime < 0)
	{
		gameTrackerX.maxWipeTime = -gameTrackerX.maxWipeTime;
	}
	gameTrackerX.wipeTime = *(short *)(signal->data + 2);
	gameTrackerX.wipeType = *(short *)signal->data;
	return 1;
}

long SIGNAL_HandleCameraSpline(_Instance *instance, Signal *signal)

{
	return 1;
}

long SIGNAL_HandleScreenWipeColor(_Instance *instance, Signal *signal)

{
	gameTrackerX.wipeColor.r = signal->data[0];
	gameTrackerX.wipeColor.g = signal->data[1];
	gameTrackerX.wipeColor.b = signal->data[2];
	return 1;
}

long SIGNAL_HandleSetSlideAngle(_Instance *instance, Signal *signal)

{
	if (instance != (_Instance *)0x0)
	{
		INSTANCE_Query(instance, 0x4000005, *(int *)signal->data);
	}
	return 1;
}

long SIGNAL_HandleResetSlideAngle(_Instance *instance, Signal *signal)

{
	if (instance != (_Instance *)0x0)
	{
		INSTANCE_Query(instance, 0x4000006, 0);
	}
	return 1;
}

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
 0x168);
	}
	return 1;
}

long SIGNAL_HandleCameraShake(_Instance *instance, Signal *signal)

{
	if (instance != (_Instance *)0x0)
	{
		CAMERA_Adjust_rotation(&theCamera, *(long *)signal->data);
	}
	return 1;
}

long SIGNAL_HandleCallSignal(_Instance *instance, Signal *signal)

{
	return 0;
}

void COLLIDE_HandleSignal(_Instance *instance, Signal *signal, long numSignals, int dontForceDoSignal)

{
	long lVar1;
	u_int uVar2;

	if (numSignals != 0)
	{
		while (true)
		{
			uVar2 = signal->id & 0x7fffffff;
			if (((((&signalInfoList)[uVar2].onlyPlayer == 0) || (instance == gameTrackerX.playerInstance)) && (((gameTrackerX.gameFlags & 0x40U) == 0 || (-1 < signal->id)))) &&
				((0x1a < uVar2 ||
				  (lVar1 = (*(&signalInfoList)[uVar2].signalHandleFunc)(instance, signal), lVar1 == 0))))
				break;
			signal = (Signal *)(&signal->id + (int)(&signalInfoList)[signal->id & 0x7fffffff].length + 1);
		}
	}
	return;
}

long SIGNAL_IsThisStreamAWarpGate(Signal *signal)

{
	char *pcVar1;
	int iVar2;
	char acStack40[32];

	strcmp(acStack40, (char *)(signal->data + 8));
	pcVar1 = strchr(acStack40, 0x2c);
	if (pcVar1 != (char *)0x0)
	{
		*pcVar1 = '\0';
	}
	iVar2 = strcpy(acStack40, "warpgate");
	return (u_int)(iVar2 == 0);
}

long SIGNAL_FindSignal(Signal *signal, long *isWarpGate)

{
	bool bVar1;
	long lVar2;
	u_int uVar3;
	long lVar4;

	lVar4 = 0;
	bVar1 = false;
	*isWarpGate = 0;
	while (true)
	{
		uVar3 = signal->id & 0x7fffffff;
		if (uVar3 == 0xf)
		{
			bVar1 = true;
		}
		else
		{
			if (uVar3 == 0x12)
			{
				bVar1 = true;
				lVar4 = 1;
				lVar2 = SIGNAL_IsThisStreamAWarpGate(signal);
				if (lVar2 != 0)
				{
					*isWarpGate = 1;
				}
			}
		}
		if (bVar1)
			break;
		signal = (Signal *)(&signal->id + (int)(&signalInfoList)[uVar3].length + 1);
	}
	return lVar4;
}

void SIGNAL_HandleFogNear(_Instance *instance, Signal *signal, int dontForceDoSignal)

{
	COLLIDE_HandleSignal(instance, signal, 1, dontForceDoSignal);
	return;
}

_MultiSignal *SIGNAL_IsStreamSignal(_MultiSignal *multiSignal, long offset)

{
	Signal *pSVar1;
	int iVar2;

	pSVar1 = multiSignal->signalList;
	iVar2 = 0;
	if (0 < multiSignal->numSignals)
	{
		do
		{
			if ((&signalInfoList)[pSVar1->id & 0x7fffffff].signalRelocateFunc != (_func_21 *)0x0)
			{
				(*(&signalInfoList)[pSVar1->id & 0x7fffffff].signalRelocateFunc)(pSVar1, offset);
			}
			iVar2 = iVar2 + 1;
			pSVar1 = (Signal *)(&pSVar1->id + (int)(&signalInfoList)[pSVar1->id & 0x7fffffff].length + 1);
		} while (iVar2 < multiSignal->numSignals);
	}
	return (_MultiSignal *)pSVar1->data;
}

_MultiSignal *SIGNAL_HandleSignal(Level *level, long id)

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
					pSVar3 = (Signal *)(&pSVar3->id + (int)(&signalInfoList)[pSVar3->id & 0x7fffffff].length + 1);
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

void SIGNAL_OutOfWater(_Instance *instance)

{
	Level *pLVar1;

	pLVar1 = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
	if ((pLVar1 != (Level *)0x0) && (pLVar1->startGoingOutOfWaterSignal != (_MultiSignal *)0x0))
	{
		SIGNAL_HandleFogNear(instance, pLVar1->startGoingOutOfWaterSignal->signalList, 0);
	}
	return;
}

void SIGNAL_InWater(_Instance *instance)

{
	Level *pLVar1;

	pLVar1 = STREAM_GetWaterZLevel(instance->currentStreamUnitID);
	if ((pLVar1 != (Level *)0x0) && (pLVar1->startGoingIntoWaterSignal != (_MultiSignal *)0x0))
	{
		SIGNAL_HandleFogNear(instance, pLVar1->startGoingIntoWaterSignal->signalList, 0);
	}
	return;
}
