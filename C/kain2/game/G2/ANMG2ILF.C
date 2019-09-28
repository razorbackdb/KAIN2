#include "THISDUST.H"
#include "ANMG2ILF.H"

// decompiled code
// original method signature:
// short /*$ra*/ G2Anim_GetElapsedTime(struct _G2Anim_Type *anim /*$a0*/)
// line 97, offset 0x8008fa10
/* begin block 1 */
// Start line: 100
// Start offset: 0x8008FA10
// Variables:
// 		struct _G2AnimSection_Type *section; // $v0
/* end block 1 */
// End offset: 0x8008FA10
// End Line: 104

/* begin block 2 */
// Start line: 104
/* end block 2 */
// End Line: 105

/* begin block 3 */
// Start line: 194
/* end block 3 */
// End Line: 195

/* begin block 4 */
// Start line: 106
/* end block 4 */
// End Line: 107

/* begin block 5 */
// Start line: 110
/* end block 5 */
// End Line: 111

short G2Anim_GetElapsedTime(_G2Anim_Type *anim)

{
	return anim->section[anim->masterSection].elapsedTime;
}

// decompiled code
// original method signature:
// struct _G2AnimKeylist_Type * /*$ra*/ G2Anim_GetKeylist(struct _G2Anim_Type *anim /*$a0*/)
// line 136, offset 0x8008fa34
/* begin block 1 */
// Start line: 139
// Start offset: 0x8008FA34
// Variables:
// 		struct _G2AnimSection_Type *section; // $v0
/* end block 1 */
// End offset: 0x8008FA34
// End Line: 143

/* begin block 2 */
// Start line: 272
/* end block 2 */
// End Line: 273

/* begin block 3 */
// Start line: 153
/* end block 3 */
// End Line: 154

/* begin block 4 */
// Start line: 157
/* end block 4 */
// End Line: 158

_G2AnimKeylist_Type *G2Anim_GetKeylist(_G2Anim_Type *anim)

{
	return anim->section[anim->masterSection].keylist;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_GetRootMotionOverInterval(struct _G2Anim_Type *anim /*$a0*/, short intervalStart /*$a1*/, short intervalEnd /*$a2*/, struct _G2SVector3_Type *motionVector /*$a3*/)
// line 165, offset 0x8008fa58
/* begin block 1 */
// Start line: 166
// Start offset: 0x8008FA58
/* end block 1 */
// End offset: 0x8008FA58
// End Line: 166

/* begin block 2 */
// Start line: 330
/* end block 2 */
// End Line: 331

void G2Anim_GetRootMotionOverInterval(_G2Anim_Type *anim, short intervalStart, short intervalEnd,
									  _G2SVector3_Type *motionVector)

{
	G2Anim_GetRootMotionFromTimeForDuration(anim, intervalStart,
											(short)(((uint)(ushort)intervalEnd - (uint)(ushort)intervalStart) * 0x10000 >> 0x10),
											motionVector);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_InterpToKeylistFrame(struct _G2Anim_Type *anim /*$s2*/, struct _G2AnimKeylist_Type *keylist /*$s4*/, int keylistID /*$s5*/, int targetFrame /*$s6*/, int duration /*stack 16*/)
// line 292, offset 0x8008fa88
/* begin block 1 */
// Start line: 293
// Start offset: 0x8008FA88
// Variables:
// 		int i; // $s0
/* end block 1 */
// End offset: 0x8008FB04
// End Line: 307

/* begin block 2 */
// Start line: 584
/* end block 2 */
// End Line: 585

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
		} while (iVar1 < (int)(uint)anim->sectionCount);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_SetAlphaTable(struct _G2Anim_Type *anim /*$s2*/, struct _G2AnimAlphaTable_Type *table /*$s3*/)
// line 412, offset 0x8008fb2c
/* begin block 1 */
// Start line: 413
// Start offset: 0x8008FB2C
// Variables:
// 		int i; // $s0
/* end block 1 */
// End offset: 0x8008FB80
// End Line: 422

/* begin block 2 */
// Start line: 824
/* end block 2 */
// End Line: 825

void G2Anim_SetAlphaTable(_G2Anim_Type *anim, _G2AnimAlphaTable_Type *table)

{
	if (anim->sectionCount != '\0')
	{
		/* WARNING: Subroutine does not return */
		G2AnimSection_SetAlphaTable(anim->section, table);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_SetCallback(struct _G2Anim_Type *anim /*$a0*/, TDRFuncPtr_G2Anim_SetCallback1callback callback /*$a1*/, void *data /*$a2*/)
// line 428, offset 0x8008fb9c
/* begin block 1 */
// Start line: 431
// Start offset: 0x8008FB9C
// Variables:
// 		int i; // $v1
/* end block 1 */
// End offset: 0x8008FBD0
// End Line: 439

/* begin block 2 */
// Start line: 520
/* end block 2 */
// End Line: 521

/* begin block 3 */
// Start line: 522
/* end block 3 */
// End Line: 523

/* begin block 4 */
// Start line: 527
/* end block 4 */
// End Line: 528

void G2Anim_SetCallback(_G2Anim_Type *anim, TDRFuncPtr_G2Anim_SetCallback1callback callback,
						void *data)

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
		} while (iVar1 < (int)(uint)anim->sectionCount);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_SetLooping(struct _G2Anim_Type *anim /*$s2*/)
// line 518, offset 0x8008fbd8
/* begin block 1 */
// Start line: 519
// Start offset: 0x8008FBD8
// Variables:
// 		int i; // $s0
/* end block 1 */
// End offset: 0x8008FC20
// End Line: 527

/* begin block 2 */
// Start line: 1036
/* end block 2 */
// End Line: 1037

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
			G2AnimSection_SetLooping((_G2AnimSection_Type *)(&anim->sectionCount + iVar2));
			iVar1 = iVar1 + 1;
			iVar2 = iVar2 + 0x30;
		} while (iVar1 < (int)(uint)anim->sectionCount);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_SetNoLooping(struct _G2Anim_Type *anim /*$s2*/)
// line 565, offset 0x8008fc38
/* begin block 1 */
// Start line: 566
// Start offset: 0x8008FC38
// Variables:
// 		int i; // $s0
/* end block 1 */
// End offset: 0x8008FC80
// End Line: 574

/* begin block 2 */
// Start line: 1130
/* end block 2 */
// End Line: 1131

void G2Anim_SetNoLooping(_G2Anim_Type *anim)

{
	if (anim->sectionCount != '\0')
	{
		/* WARNING: Subroutine does not return */
		G2AnimSection_SetNoLooping(anim->section);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_SetPaused(struct _G2Anim_Type *anim /*$s2*/)
// line 591, offset 0x8008fc98
/* begin block 1 */
// Start line: 592
// Start offset: 0x8008FC98
// Variables:
// 		int i; // $s0
/* end block 1 */
// End offset: 0x8008FCE0
// End Line: 600

/* begin block 2 */
// Start line: 1182
/* end block 2 */
// End Line: 1183

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
			G2AnimSection_NextKeyframe((_G2AnimSection_Type *)(&anim->sectionCount + iVar2));
			iVar1 = iVar1 + 1;
			iVar2 = iVar2 + 0x30;
		} while (iVar1 < (int)(uint)anim->sectionCount);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_SetSpeedAdjustment(struct _G2Anim_Type *anim /*$a0*/, long adjustment /*$a1*/)
// line 618, offset 0x8008fcf8
/* begin block 1 */
// Start line: 621
// Start offset: 0x8008FCF8
// Variables:
// 		int i; // $v1
/* end block 1 */
// End offset: 0x8008FD24
// End Line: 629

/* begin block 2 */
// Start line: 1236
/* end block 2 */
// End Line: 1237

/* begin block 3 */
// Start line: 750
/* end block 3 */
// End Line: 751

/* begin block 4 */
// Start line: 755
/* end block 4 */
// End Line: 756

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
		} while (iVar1 < (int)(uint)anim->sectionCount);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_SetUnpaused(struct _G2Anim_Type *anim /*$s2*/)
// line 649, offset 0x8008fd2c
/* begin block 1 */
// Start line: 650
// Start offset: 0x8008FD2C
// Variables:
// 		int i; // $s0
/* end block 1 */
// End offset: 0x8008FD74
// End Line: 658

/* begin block 2 */
// Start line: 1298
/* end block 2 */
// End Line: 1299

void G2Anim_SetUnpaused(_G2Anim_Type *anim)

{
	int iVar1;
	int iVar2;

	iVar1 = 0;
	if (anim->sectionCount != '\0')
	{
		iVar2 = 0x24;
		do
		{
			G2AnimSection_SetUnpaused((_G2AnimSection_Type *)(&anim->sectionCount + iVar2));
			iVar1 = iVar1 + 1;
			iVar2 = iVar2 + 0x30;
		} while (iVar1 < (int)(uint)anim->sectionCount);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2Anim_SwitchToKeylist(struct _G2Anim_Type *anim /*$s2*/, struct _G2AnimKeylist_Type *keylist /*$s3*/, int keylistID /*$s4*/)
// line 678, offset 0x8008fd8c
/* begin block 1 */
// Start line: 679
// Start offset: 0x8008FD8C
// Variables:
// 		int i; // $s0
/* end block 1 */
// End offset: 0x8008FDEC
// End Line: 689

/* begin block 2 */
// Start line: 1356
/* end block 2 */
// End Line: 1357

void G2Anim_SwitchToKeylist(_G2Anim_Type *anim, _G2AnimKeylist_Type *keylist, int keylistID)

{
	int iVar1;
	int iVar2;

	iVar1 = 0;
	if (anim->sectionCount != '\0')
	{
		iVar2 = 0x24;
		do
		{
			G2AnimSection_SwitchToKeylist((_G2AnimSection_Type *)(&anim->sectionCount + iVar2), keylist, keylistID);
			iVar1 = iVar1 + 1;
			iVar2 = iVar2 + 0x30;
		} while (iVar1 < (int)(uint)anim->sectionCount);
	}
	return;
}

// decompiled code
// original method signature:
// short /*$ra*/ G2AnimKeylist_GetDuration(struct _G2AnimKeylist_Type *keylist /*$a0*/)
// line 797, offset 0x8008fe0c
/* begin block 1 */
// Start line: 1594
/* end block 1 */
// End Line: 1595

/* begin block 2 */
// Start line: 962
/* end block 2 */
// End Line: 963

short G2AnimKeylist_GetDuration(_G2AnimKeylist_Type *keylist)

{
	return (short)(((uint)keylist->s0TailTime +
					(int)keylist->timePerKey * ((uint)keylist->keyCount - 1)) *
					   0x10000 >>
				   0x10);
}

// decompiled code
// original method signature:
// int /*$ra*/ G2AnimKeylist_GetKeyframeCount(struct _G2AnimKeylist_Type *keylist /*$a0*/)
// line 811, offset 0x8008fe34
/* begin block 1 */
// Start line: 986
/* end block 1 */
// End Line: 987

/* begin block 2 */
// Start line: 989
/* end block 2 */
// End Line: 990

int G2AnimKeylist_GetKeyframeCount(_G2AnimKeylist_Type *keylist)

{
	return (int)((int)keylist->timePerKey * ((uint)keylist->keyCount - 1) + -1 +
				 (uint)keylist->s0TailTime * 2) /
		   (int)(uint)keylist->s0TailTime;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2AnimSection_ClearAlarm(struct _G2AnimSection_Type *section /*$a0*/, unsigned long flag /*$a1*/)
// line 840, offset 0x8008fe6c
/* begin block 1 */
// Start line: 1044
/* end block 1 */
// End Line: 1045

/* begin block 2 */
// Start line: 1049
/* end block 2 */
// End Line: 1050

void G2Anim_SetUnpaused(_G2Anim_Type *anim)

{
	uint in_a1;

	anim->disabledBits[0] = anim->disabledBits[0] & ~in_a1;
	return;
}

// decompiled code
// original method signature:
// int /*$ra*/ G2AnimSection_GetKeyframeNumber(struct _G2AnimSection_Type *section /*$s0*/)
// line 870, offset 0x8008fe80
/* begin block 1 */
// Start line: 1740
/* end block 1 */
// End Line: 1741

int G2AnimSection_GetKeyframeNumber(_G2AnimSection_Type *section)

{
	byte bVar1;
	short sVar2;
	_G2Bool_Enum _Var3;

	_Var3 = G2AnimSection_IsInInterpolation(section);
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
	return (int)sVar2 / (int)(uint)bVar1;
}

// decompiled code
// original method signature:
// int /*$ra*/ G2AnimSection_GetStoredKeyframeNumber(struct _G2AnimSection_Type *section /*$a0*/)
// line 974, offset 0x8008fedc
/* begin block 1 */
// Start line: 1201
/* end block 1 */
// End Line: 1202

/* begin block 2 */
// Start line: 1292
/* end block 2 */
// End Line: 1293

/* begin block 3 */
// Start line: 1297
/* end block 3 */
// End Line: 1298

int G2AnimSection_GetStoredKeyframeNumber(_G2AnimSection_Type *section)

{
	return (int)section->storedTime / (int)(uint)section->keylist->s0TailTime;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2AnimSection_InterpToKeylistFrame(struct _G2AnimSection_Type *section /*$a0*/, struct _G2AnimKeylist_Type *keylist /*$a1*/, int keylistID /*$a2*/, int targetFrame /*$a3*/, int duration /*stack 16*/)
// line 1005, offset 0x8008fefc
/* begin block 1 */
// Start line: 1006
// Start offset: 0x8008FEFC
/* end block 1 */
// End offset: 0x8008FEFC
// End Line: 1006

/* begin block 2 */
// Start line: 2010
/* end block 2 */
// End Line: 2011

void G2AnimSection_InterpToKeylistFrame(_G2AnimSection_Type *section, _G2AnimKeylist_Type *keylist, int keylistID,
										int targetFrame, int duration)

{
	G2AnimSection_InterpToKeylistAtTime(section, keylist, keylistID, (short)targetFrame * (ushort)keylist->s0TailTime,
										(int)(short)duration);
	return;
}

// decompiled code
// original method signature:
// enum _G2Bool_Enum /*$ra*/ G2AnimSection_IsInInterpolation(struct _G2AnimSection_Type *section /*$a0*/)
// line 1023, offset 0x8008ff3c
/* begin block 1 */
// Start line: 1026
// Start offset: 0x8008FF3C
// Variables:
// 		struct _G2AnimInterpInfo_Type *interpInfo; // $v0
/* end block 1 */
// End offset: 0x8008FF64
// End Line: 1035

/* begin block 2 */
// Start line: 1364
/* end block 2 */
// End Line: 1365

/* begin block 3 */
// Start line: 1366
/* end block 3 */
// End Line: 1367

/* begin block 4 */
// Start line: 1370
/* end block 4 */
// End Line: 1371

_G2Bool_Enum G2AnimSection_IsInInterpolation(_G2AnimSection_Type *section)

{
	if ((section->interpInfo != (_G2AnimInterpInfo_Type *)0x0) &&
		(section->interpInfo->stateBlockList != (_G2AnimInterpStateBlock_Type *)0x0))
	{
		return 1;
	}
	return G2FALSE;
}

// decompiled code
// original method signature:
// short /*$ra*/ G2AnimSection_NextKeyframe(struct _G2AnimSection_Type *section /*$s0*/)
// line 1081, offset 0x8008ff6c
/* begin block 1 */
// Start line: 1480
/* end block 1 */
// End Line: 1481

short G2AnimSection_NextKeyframe(_G2AnimSection_Type *section)

{
	short interval;

	interval = 0;
	if ((section->flags & 1) == 0)
	{
		G2AnimSection_SetNotRewinding(section);
		interval = G2Timer_GetFrameTime();
		interval = G2AnimSection_UpdateOverInterval(section, interval);
	}
	return interval;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2AnimSection_SetAlphaTable(struct _G2AnimSection_Type *section /*$a0*/, struct _G2AnimAlphaTable_Type *table /*$a1*/)
// line 1112, offset 0x8008ffc8
/* begin block 1 */
// Start line: 2224
/* end block 1 */
// End Line: 2225

/* begin block 2 */
// Start line: 1521
/* end block 2 */
// End Line: 1522

void G2AnimSection_SetAlphaTable(_G2AnimSection_Type *section, _G2AnimAlphaTable_Type *table)

{
	if (section->interpInfo != (_G2AnimInterpInfo_Type *)0x0)
	{
		section->interpInfo->alphaTable = table;
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2AnimSection_SetInterpInfo(struct _G2AnimSection_Type *section /*$a0*/, struct _G2AnimInterpInfo_Type *newInfoPtr /*$a1*/)
// line 1162, offset 0x8008ffe4
/* begin block 1 */
// Start line: 1617
/* end block 1 */
// End Line: 1618

void G2AnimSection_SetInterpInfo(_G2AnimSection_Type *section, _G2AnimInterpInfo_Type *newInfoPtr)

{
	section->interpInfo = newInfoPtr;
	if (newInfoPtr != (_G2AnimInterpInfo_Type *)0x0)
	{
		/* WARNING: Subroutine does not return */
		memset(newInfoPtr, 0, 0xc);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2AnimSection_SetLooping(struct _G2AnimSection_Type *section /*$s0*/)
// line 1208, offset 0x80090014
/* begin block 1 */
// Start line: 2416
/* end block 1 */
// End Line: 2417

void G2AnimSection_SetLooping(_G2AnimSection_Type *section)

{
	G2Anim_SetUnpaused((_G2Anim_Type *)section);
	G2AnimSection_SetLoopRangeAll(section);
	section->flags = section->flags | 2;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2AnimSection_SetLoopRangeAll(struct _G2AnimSection_Type *section /*$s0*/)
// line 1220, offset 0x80090054
/* begin block 1 */
// Start line: 1695
/* end block 1 */
// End Line: 1696

void G2AnimSection_SetLoopRangeAll(_G2AnimSection_Type *section)

{
	short sVar1;

	section->loopStartTime = 0;
	sVar1 = G2AnimKeylist_GetDuration(section->keylist);
	section->loopEndTime = sVar1;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2AnimSection_SetNoLooping(struct _G2AnimSection_Type *section /*$a0*/)
// line 1261, offset 0x80090084
/* begin block 1 */
// Start line: 2522
/* end block 1 */
// End Line: 2523

/* begin block 2 */
// Start line: 1744
/* end block 2 */
// End Line: 1745

void G2AnimSection_SetNoLooping(_G2AnimSection_Type *section)

{
	section->flags = section->flags & 0xfd;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2AnimSection_SetNotRewinding(struct _G2AnimSection_Type *section /*$a0*/)
// line 1270, offset 0x80090098
/* begin block 1 */
// Start line: 1759
/* end block 1 */
// End Line: 1760

/* begin block 2 */
// Start line: 1762
/* end block 2 */
// End Line: 1763

void G2AnimSection_SetNotRewinding(_G2AnimSection_Type *section)

{
	section->flags = section->flags & 0xfb;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2AnimSection_SetPaused(struct _G2AnimSection_Type *section /*$a0*/)
// line 1279, offset 0x800900ac
/* begin block 1 */
// Start line: 1777
/* end block 1 */
// End Line: 1778

/* begin block 2 */
// Start line: 1780
/* end block 2 */
// End Line: 1781

short G2AnimSection_NextKeyframe(_G2AnimSection_Type *section)

{
	uint uVar1;

	uVar1 = (uint)section->flags | 1;
	section->flags = (uchar)uVar1;
	return (short)uVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2AnimSection_SetUnpaused(struct _G2AnimSection_Type *section /*$a0*/)
// line 1333, offset 0x800900c0
/* begin block 1 */
// Start line: 2666
/* end block 1 */
// End Line: 2667

/* begin block 2 */
// Start line: 1837
/* end block 2 */
// End Line: 1838

void G2AnimSection_SetUnpaused(_G2AnimSection_Type *section)

{
	section->flags = section->flags & 0xfe;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ G2AnimSection_SwitchToKeylist(struct _G2AnimSection_Type *section /*$a0*/, struct _G2AnimKeylist_Type *keylist /*$a1*/, int keylistID /*$a2*/)
// line 1344, offset 0x800900d4
/* begin block 1 */
// Start line: 1856
/* end block 1 */
// End Line: 1857

void G2AnimSection_SwitchToKeylist(_G2AnimSection_Type *section, _G2AnimKeylist_Type *keylist, int keylistID)

{
	G2AnimSection_SwitchToKeylistAtTime(section, keylist, keylistID, 0);
	return;
}
