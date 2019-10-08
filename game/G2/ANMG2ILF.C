#include "THISDUST.H"
#include "ANMG2ILF.H"

void G2Anim_EnableSegment(_G2Anim_Type *anim, int segmentID)

{
	*(u_int *)(&anim->sectionCount + (segmentID >> 5) * 4 + 0x18) =
		*(u_int *)(&anim->sectionCount + (segmentID >> 5) * 4 + 0x18) | 1 << (segmentID & 0x1fU);
	return;
}

void G2Anim_DisableSegment(_G2Anim_Type *anim, int segmentID)

{
	*(u_int *)(&anim->sectionCount + (segmentID >> 5) * 4 + 0x18) =
		*(u_int *)(&anim->sectionCount + (segmentID >> 5) * 4 + 0x18) & ~(1 << (segmentID & 0x1fU));
	return;
}

short G2Anim_GetElapsedTime(_G2Anim_Type *anim)

{
	return anim->section[anim->masterSection].elapsedTime;
}

_G2AnimKeylist_Type *G2Anim_GetKeylist(_G2Anim_Type *anim)

{
	return anim->section[anim->masterSection].keylist;
}

void G2AnimSection_UpdateOverInterval(_G2Anim_Type *anim, short intervalStart, short intervalEnd,
									  _G2SVector3_Type *motionVector)

{
	G2Anim_GetRootMotionFromTimeForDuration(anim, intervalStart,
											(short)(((u_int)(u_short)intervalEnd - (u_int)(u_short)intervalStart) * 0x10000 >> 0x10),
											motionVector);
	return;
}

void G2Anim_InterpToKeylistFrame(_G2Anim_Type *anim, _G2AnimKeylist_Type *keylist, int keylistID, int targetFrame,
								 int duration)

{
	int iVar1;
	int iVar2;

	iVar1 = 0;
	if (anim->sectionCount != '\0')
	{
		iVar2 = 0x24;
		do
		{
			G2AnimSection_InterpToKeylistFrame((_G2AnimSection_Type *)(&anim->sectionCount + iVar2), keylist, keylistID, targetFrame,
											   (int)(short)duration);
			iVar1 = iVar1 + 1;
			iVar2 = iVar2 + 0x30;
		} while (iVar1 < (int)(u_int)anim->sectionCount);
	}
	return;
}

_G2Bool_Enum G2Anim_IsSegmentEnabled(_G2Anim_Type *anim, int segmentID)

{
	int iVar1;

	if (segmentID != -1)
	{
		iVar1 = segmentID >> 5;
		do
		{
			if ((anim->disabledBits[iVar1] & 1 << (segmentID & 0x1fU)) != 0)
			{
				return G2FALSE;
			}
			segmentID = (int)anim->modelData->segmentList[segmentID].parent;
			iVar1 = segmentID >> 5;
		} while (segmentID != 0xffffffff);
	}
	return 1;
}

void G2Anim_SetAlphaTable(_G2Anim_Type *anim, _G2AnimAlphaTable_Type *table)

{
	int iVar1;
	int iVar2;

	iVar1 = 0;
	if (anim->sectionCount != '\0')
	{
		iVar2 = 0x24;
		do
		{
			G2AnimSection_SetAlphaTable((_G2AnimSection_Type *)(&anim->sectionCount + iVar2), table);
			iVar1 = iVar1 + 1;
			iVar2 = iVar2 + 0x30;
		} while (iVar1 < (int)(u_int)anim->sectionCount);
	}
	return;
}

void MON_AnimCallback(_G2Anim_Type *anim, TDRFuncPtr_G2Anim_SetCallback1callback callback, void *data)

{
	int iVar1;
	_G2Anim_Type *p_Var2;

	iVar1 = 0;
	p_Var2 = anim;
	if (anim->sectionCount != '\0')
	{
		do
		{
			*(TDRFuncPtr_G2Anim_SetCallback1callback *)&p_Var2->section[0].callback = callback;
			p_Var2->section[0].callbackData = data;
			iVar1 = iVar1 + 1;
			p_Var2 = (_G2Anim_Type *)&p_Var2->section[0].swAlarmTable;
		} while (iVar1 < (int)(u_int)anim->sectionCount);
	}
	return;
}

void G2Anim_SetLooping(_G2Anim_Type *anim)

{
	int iVar1;
	int iVar2;

	iVar1 = 0;
	if (anim->sectionCount != '\0')
	{
		iVar2 = 0x24;
		do
		{
			G2Anim_SetNoLooping((_G2AnimSection_Type *)(&anim->sectionCount + iVar2));
			iVar1 = iVar1 + 1;
			iVar2 = iVar2 + 0x30;
		} while (iVar1 < (int)(u_int)anim->sectionCount);
	}
	return;
}

void G2Anim_SetLooping(_G2Anim_Type *anim)

{
	int iVar1;
	int iVar2;

	iVar1 = 0;
	if (anim->sectionCount != '\0')
	{
		iVar2 = 0x24;
		do
		{
			G2AnimSection_SetNoLooping((_G2AnimSection_Type *)(&anim->sectionCount + iVar2));
			iVar1 = iVar1 + 1;
			iVar2 = iVar2 + 0x30;
		} while (iVar1 < (int)(u_int)anim->sectionCount);
	}
	return;
}

void _G2AnimSection_TriggerEffects(_G2Anim_Type *anim)

{
	int iVar1;
	int iVar2;

	iVar1 = 0;
	if (anim->sectionCount != '\0')
	{
		iVar2 = 0x24;
		do
		{
			G2AnimSection_SetNotRewinding((_G2AnimSection_Type *)(&anim->sectionCount + iVar2));
			iVar1 = iVar1 + 1;
			iVar2 = iVar2 + 0x30;
		} while (iVar1 < (int)(u_int)anim->sectionCount);
	}
	return;
}

void G2Anim_SetSpeedAdjustment(_G2Anim_Type *anim, long adjustment)

{
	int iVar1;
	_G2Anim_Type *p_Var2;

	iVar1 = 0;
	p_Var2 = anim;
	if (anim->sectionCount != '\0')
	{
		do
		{
			p_Var2->section[0].speedAdjustment = adjustment;
			iVar1 = iVar1 + 1;
			p_Var2 = (_G2Anim_Type *)&p_Var2->section[0].swAlarmTable;
		} while (iVar1 < (int)(u_int)anim->sectionCount);
	}
	return;
}

void G2Anim_SetPaused(_G2Anim_Type *anim)

{
	int iVar1;
	int iVar2;

	iVar1 = 0;
	if (anim->sectionCount != '\0')
	{
		iVar2 = 0x24;
		do
		{
			G2Anim_SetUnpaused((_G2AnimSection_Type *)(&anim->sectionCount + iVar2));
			iVar1 = iVar1 + 1;
			iVar2 = iVar2 + 0x30;
		} while (iVar1 < (int)(u_int)anim->sectionCount);
	}
	return;
}

void G2Anim_GetKeylist(_G2Anim_Type *anim, _G2AnimKeylist_Type *keylist, int keylistID)

{
	int iVar1;
	int iVar2;

	iVar1 = 0;
	if (anim->sectionCount != '\0')
	{
		iVar2 = 0x24;
		do
		{
			G2Anim_SwitchToKeylist((_G2AnimSection_Type *)(&anim->sectionCount + iVar2), keylist, keylistID);
			iVar1 = iVar1 + 1;
			iVar2 = iVar2 + 0x30;
		} while (iVar1 < (int)(u_int)anim->sectionCount);
	}
	return;
}

short G2AnimKeylist_GetDuration(_G2AnimKeylist_Type *keylist)

{
	return (short)(((u_int)keylist->s0TailTime +
					(int)keylist->timePerKey * ((u_int)keylist->keyCount - 1)) *
					   0x10000 >>
				   0x10);
}

int G2AnimKeylist_GetKeyframeCount(_G2AnimKeylist_Type *keylist)

{
  return (int)((int)keylist->timePerKey * ((u_int)keylist->keyCount - 1) + -1 +
 (int)(u_int)keylist->s0TailTime;
}

void G2AnimSection_SetLooping(_G2AnimSection_Type *section, u_long flag)

{
	section->alarmFlags = section->alarmFlags & ~flag;
	return;
}

int G2AnimSection_GetKeyframeNumber(_G2AnimSection_Type *section)

{
	byte bVar1;
	short sVar2;
	_G2Bool_Enum _Var3;

	_Var3 = G2AnimSection_AdvanceOverInterval(section);
	if (_Var3 == G2FALSE)
	{
		sVar2 = section->elapsedTime;
		bVar1 = section->keylist->s0TailTime;
	}
	else
	{
		sVar2 = section->interpInfo->targetTime;
		bVar1 = section->keylist->s0TailTime;
	}
	(int)(u_int) bVar1;
}

int _G2AnimSection_GetAnim(_G2AnimSection_Type *section)

{
	(int)(u_int) section->keylist->s0TailTime;
}

void G2AnimSection_InterpToKeylistFrame(_G2AnimSection_Type *section, _G2AnimKeylist_Type *keylist, int keylistID,
										int targetFrame, int duration)

{
	G2AnimSection_SwitchToKeylist(section, keylist, keylistID, (short)targetFrame * (u_short)keylist->s0TailTime,
								  (int)(short)duration);
	return;
}

_G2Bool_Enum G2AnimSection_AdvanceOverInterval(_G2AnimSection_Type *section)

{
	if ((section->interpInfo != (_G2AnimInterpInfo_Type *)0x0) &&
		(section->interpInfo->stateBlockList != (_G2AnimInterpStateBlock_Type *)0x0))
	{
		return 1;
	}
	return G2FALSE;
}

short G2AnimSection_JumpToTime(_G2AnimSection_Type *section)

{
	short interval;

	interval = 0;
	if ((section->flags & 1) == 0)
	{
		G2AnimSection_SetLoopRangeAll(section);
		interval = G2Timer_GetFrameTime();
		interval = G2AnimSection_SetInterpInfo(section, interval);
	}
	return interval;
}

void G2AnimSection_SetAlphaTable(_G2AnimSection_Type *section, _G2AnimAlphaTable_Type *table)

{
	if (section->interpInfo != (_G2AnimInterpInfo_Type *)0x0)
	{
		section->interpInfo->alphaTable = table;
	}
	return;
}

void _G2AnimSection_InterpStateToQuat(_G2AnimSection_Type *section, _G2AnimInterpInfo_Type *newInfoPtr)

{
	section->interpInfo = newInfoPtr;
	if (newInfoPtr != (_G2AnimInterpInfo_Type *)0x0)
	{
		memset(newInfoPtr, 0, 0xc);
	}
	return;
}

void G2Anim_SetNoLooping(_G2AnimSection_Type *section)

{
	G2AnimSection_SetLooping(section, 3);
	G2AnimSection_SetPaused(section);
	section->flags = section->flags | 2;
	return;
}

void G2AnimSection_SetPaused(_G2AnimSection_Type *section)

{
	short sVar1;

	section->loopStartTime = 0;
	sVar1 = G2AnimKeylist_GetDuration(section->keylist);
	section->loopEndTime = sVar1;
	return;
}

void G2AnimSection_SetNoLooping(_G2AnimSection_Type *section)

{
	section->flags = section->flags & 0xfd;
	return;
}

void G2AnimSection_SetLoopRangeAll(_G2AnimSection_Type *section)

{
	section->flags = section->flags & 0xfb;
	return;
}

void G2AnimSection_SetNotRewinding(_G2AnimSection_Type *section)

{
	section->flags = section->flags | 1;
	return;
}

void G2Anim_SetUnpaused(_G2AnimSection_Type *section)

{
	section->flags = section->flags & 0xfe;
	return;
}

void G2Anim_SwitchToKeylist(_G2AnimSection_Type *section, _G2AnimKeylist_Type *keylist, int keylistID)

{
	G2AnimSection_InterpToKeylistAtTime(section, keylist, keylistID, 0);
	return;
}
