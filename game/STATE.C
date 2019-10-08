#include "THISDUST.H"
#include "STATE.H"

void EnMessageQueue(__MessageQueue *In)

{
	In->Head = 0;
	In->Tail = 0;
	return;
}

__Event *PurgeMessageQueue(__MessageQueue *In)

{
	int iVar1;

	iVar1 = In->Head;
	if (iVar1 == In->Tail)
	{
		return (__Event *)0x0;
	}
	In->Head = iVar1 + 1;
	if (iVar1 + 1 == 0x10)
	{
		In->Head = 0;
	}
	return In->Queue + iVar1;
}

void EnMessageQueueData(__MessageQueue *In)

{
	In->Tail = 0;
	In->Head = 0;
	return;
}

__Event *PeekMessageQueue(__MessageQueue *In)

{
	if (In->Head != In->Tail)
	{
		return In->Queue + In->Head;
	}
	return (__Event *)0x0;
}

void InitMessageQueue(__MessageQueue *In, __Event *Element)

{
	DeMessageQueue(In, Element->ID, Element->Data);
	return;
}

void DeMessageQueue(__MessageQueue *In, int ID, int Data)

{
	int iVar1;

	In->Queue[In->Tail].ID = ID;
	In->Queue[In->Tail].Data = Data;
	iVar1 = In->Tail + 1;
	In->Tail = iVar1;
	if (iVar1 == 0x10)
	{
		In->Tail = 0;
	}
	iVar1 = In->Head;
	if (iVar1 == In->Tail)
	{
		do
		{
			iVar1 = iVar1 + 1;
			if (iVar1 == 0x10)
			{
				iVar1 = 0;
			}
		} while (iVar1 != In->Tail);
	}
	return;
}

void *CIRC_Alloc(int size)

{
	void *pvVar1;
	u_int uVar2;
	_BlockVramEntry *p_Var3;

	uVar2 = size + 3U & 0xfffffffc;
	p_Var3 = (_BlockVramEntry *)((int)circWhere + uVar2);
	pvVar1 = circWhere;
	if (&vramBlockList < p_Var3)
	{
		circWhere = &circBuf + uVar2;
		return &circBuf;
	}
	circWhere = p_Var3;
	return pvVar1;
}

int SetCollideInfoData(_CollideInfo *srcCI)

{
	void **ppvVar1;
	void **ppvVar2;
	_CollideInfo *p_Var3;
	void *pvVar4;
	void *pvVar5;
	void *pvVar6;

	ppvVar1 = (void **)CIRC_Alloc(0x30);
	p_Var3 = srcCI + 1;
	ppvVar2 = ppvVar1;
	do
	{
		pvVar4 = *(void **)&srcCI->flags;
		pvVar5 = srcCI->prim0;
		pvVar6 = srcCI->prim1;
		*ppvVar2 = srcCI->level;
		ppvVar2[1] = pvVar4;
		ppvVar2[2] = pvVar5;
		ppvVar2[3] = pvVar6;
		srcCI = (_CollideInfo *)&srcCI->inst0;
		ppvVar2 = ppvVar2 + 4;
	} while (srcCI != p_Var3);
	return (int)ppvVar1;
}

int SetMonsterImpaleData(_Instance *Sender, _Instance *lastHit, int Power, int knockBackDistance,
						 int knockBackFrames)

{
	_Instance **pp_Var1;

	pp_Var1 = (_Instance **)CIRC_Alloc(0x10);
	*pp_Var1 = Sender;
	pp_Var1[1] = lastHit;
	*(int *)(pp_Var1 + 3) = Power;
	*(short *)(pp_Var1 + 2) = (short)knockBackDistance;
	*(undefined2 *)((int)pp_Var1 + 10) = (short)knockBackFrames;
	return (int)pp_Var1;
}

int SetMonsterThrownData(_Instance *Sender, _Rotation *Direction, int Power)

{
	short sVar1;
	_Instance **pp_Var2;

	pp_Var2 = (_Instance **)CIRC_Alloc(0x10);
	*pp_Var2 = Sender;
	*(short *)(pp_Var2 + 1) = Direction->x;
	*(short *)((int)pp_Var2 + 6) = Direction->y;
	sVar1 = Direction->z;
	*(short *)(pp_Var2 + 3) = (short)Power;
	*(short *)(pp_Var2 + 2) = sVar1;
	return (int)pp_Var2;
}

int SetMonsterAlarmData(_Instance *sender, _Position *position, int type)

{
	short sVar1;
	_Instance **pp_Var2;

	pp_Var2 = (_Instance **)CIRC_Alloc(0xc);
	*pp_Var2 = sender;
	*(short *)(pp_Var2 + 1) = position->x;
	*(short *)((int)pp_Var2 + 6) = position->y;
	sVar1 = position->z;
	*(undefined2 *)((int)pp_Var2 + 10) = (short)type;
	*(short *)(pp_Var2 + 2) = sVar1;
	return (int)pp_Var2;
}

int SetMonsterHitData(_Instance *Sender, int x, int y, int z)

{
	_Instance **pp_Var1;

	pp_Var1 = (_Instance **)CIRC_Alloc(0xc);
	*pp_Var1 = Sender;
	*(short *)(pp_Var1 + 1) = (short)x;
	*(undefined2 *)((int)pp_Var1 + 6) = (short)y;
	*(short *)(pp_Var1 + 2) = (short)z;
	return (int)pp_Var1;
}

int SetMonsterSoulSuckData(_Instance *weapon, _Rotation *direction, _Position *position, int distance)

{
	short sVar1;
	_Instance **pp_Var2;

	pp_Var2 = (_Instance **)CIRC_Alloc(0x14);
	*pp_Var2 = weapon;
	*(short *)(pp_Var2 + 1) = direction->x;
	*(short *)((int)pp_Var2 + 6) = direction->y;
	*(short *)(pp_Var2 + 2) = direction->z;
	*(short *)(pp_Var2 + 3) = position->x;
	*(short *)((int)pp_Var2 + 0xe) = position->y;
	sVar1 = position->z;
	*(undefined2 *)((int)pp_Var2 + 0x12) = (short)distance;
	*(short *)(pp_Var2 + 4) = sVar1;
	return (int)pp_Var2;
}

int SetObjectBreakOffData(int x, int y, int PathNumber, _Instance *Force, int node)

{
	undefined2 *puVar1;

	puVar1 = (undefined2 *)CIRC_Alloc(0x10);
	*puVar1 = (short)x;
	puVar1[1] = (short)y;
	puVar1[2] = (short)PathNumber;
	*(_Instance **)(puVar1 + 4) = Force;
	puVar1[3] = (short)node;
	return (int)puVar1;
}

int SetPositionData(int x, int y, int z)

{
	undefined2 *puVar1;

	puVar1 = (undefined2 *)CIRC_Alloc(8);
	*puVar1 = (short)x;
	puVar1[1] = (short)y;
	puVar1[2] = (short)z;
	return (int)puVar1;
}

int SetPhysicsDropOffData(int UpperOffset, int LowerOffset, int x, int y, int z, int slope)

{
	undefined2 *puVar1;

	puVar1 = (undefined2 *)CIRC_Alloc(0xc);
	*puVar1 = (short)UpperOffset;
	puVar1[1] = (short)LowerOffset;
	puVar1[2] = (short)x;
	puVar1[3] = (short)y;
	puVar1[4] = (short)z;
	puVar1[5] = (short)slope;
	return (int)puVar1;
}

int SetPhysicsDropHeightData(int UpperOffset, int ForwardOffset, int AboveOffset, int x, int y, int z, _SVector *Normal1, _SVector *Normal2, _SVector *Delta)

{
	undefined2 *puVar1;

	puVar1 = (undefined2 *)CIRC_Alloc(0x24);
	*puVar1 = (short)UpperOffset;
	puVar1[1] = (short)ForwardOffset;
	puVar1[2] = (short)AboveOffset;
	puVar1[3] = (short)x;
	puVar1[4] = (short)y;
	puVar1[5] = (short)z;
	*(_SVector **)(puVar1 + 6) = Normal1;
	*(_SVector **)(puVar1 + 8) = Normal2;
	*(_SVector **)(puVar1 + 10) = Delta;
	return (int)puVar1;
}

int SetPhysicsDropOffData(int CheckDepth, _SVector *iVelocity, int SwimDepth, int WadeDepth, int TreadDepth)

{
	undefined2 *puVar1;

	puVar1 = (undefined2 *)CIRC_Alloc(0x18);
	*puVar1 = (short)CheckDepth;
	*(_SVector **)(puVar1 + 4) = iVelocity;
	puVar1[1] = (short)SwimDepth;
	puVar1[2] = (short)WadeDepth;
	puVar1[3] = (short)TreadDepth;
	return (int)puVar1;
}

int SetPhysics(int xOffset, int yOffset, int DropOffset, int slipSlope, int UpperOffset)

{
	undefined2 *puVar1;

	puVar1 = (undefined2 *)CIRC_Alloc(0xc);
	*puVar1 = (short)xOffset;
	puVar1[1] = (short)yOffset;
	puVar1[2] = (short)DropOffset;
	puVar1[3] = (short)slipSlope;
	*(int *)(puVar1 + 4) = UpperOffset;
	return (int)puVar1;
}

int SetPhysicsSwimData(int Segment, int ForwardVectorX, int ForwardVectorY, int ForwardVectorZ,
					   int DropOffset, int UpperOffset, int Height)

{
	undefined2 *puVar1;

	puVar1 = (undefined2 *)CIRC_Alloc(0x28);
	puVar1[0xc] = (short)Segment;
	*puVar1 = (short)ForwardVectorX;
	puVar1[1] = (short)ForwardVectorY;
	puVar1[2] = (short)ForwardVectorZ;
	puVar1[0xd] = (short)DropOffset;
	puVar1[0xe] = (short)UpperOffset;
	puVar1[0xf] = (short)Height;
	return (int)puVar1;
}

int SetPhysicsWallCrawlData(int Segment, int Length, int ForwardOffset, int NormalDistance)

{
	undefined2 *puVar1;

	puVar1 = (undefined2 *)CIRC_Alloc(0x2c);
	*puVar1 = (short)Segment;
	puVar1[1] = (short)Length;
	puVar1[2] = (short)ForwardOffset;
	puVar1[3] = (short)NormalDistance;
	return (int)puVar1;
}

int SetPhysicsSlideData(_Instance *instance, int segment, _SVector *posDelta, _SVector *rotDelta)

{
	_Instance **pp_Var1;
	_Instance *p_Var2;

	pp_Var1 = (_Instance **)CIRC_Alloc(0x18);
	*(int *)(pp_Var1 + 1) = segment;
	*pp_Var1 = instance;
	if (posDelta != (_SVector *)0x0)
	{
		p_Var2 = *(_Instance **)&posDelta->z;
		pp_Var1[2] = *(_Instance **)posDelta;
		pp_Var1[3] = p_Var2;
	}
	if (rotDelta != (_SVector *)0x0)
	{
		p_Var2 = *(_Instance **)&rotDelta->z;
		pp_Var1[4] = *(_Instance **)rotDelta;
		pp_Var1[5] = p_Var2;
	}
	return (int)pp_Var1;
}

int SetPhysicsEdgeData(_Position *offset, int dropOffset, int mode)

{
	short *psVar1;

	psVar1 = (short *)CIRC_Alloc(0x14);
	psVar1[4] = (short)dropOffset;
	psVar1[3] = (short)mode;
	*psVar1 = offset->x;
	psVar1[1] = offset->y;
	psVar1[2] = offset->z + 0x19;
	return (int)psVar1;
}

int SetAnimationControllerDoneData(_Instance *instance, long segment, long type, int data)

{
	_Instance **pp_Var1;

	pp_Var1 = (_Instance **)CIRC_Alloc(0x10);
	*pp_Var1 = instance;
	*(long *)(pp_Var1 + 1) = segment;
	*(long *)(pp_Var1 + 2) = type;
	*(int *)(pp_Var1 + 3) = data;
	return (int)pp_Var1;
}

int SetAnimationInstanceSwitchData(_Instance *instance, int anim, int frame, int frames, int mode)

{
	_Instance **pp_Var1;

	pp_Var1 = (_Instance **)CIRC_Alloc(0x14);
	*pp_Var1 = instance;
	*(int *)(pp_Var1 + 1) = anim;
	*(int *)(pp_Var1 + 2) = frame;
	*(int *)(pp_Var1 + 3) = frames;
	*(int *)(pp_Var1 + 4) = mode;
	return (int)pp_Var1;
}

int SetFXHitData(_Instance *hitter, int segment, int amount, int type)

{
	short sVar1;
	short *psVar2;

	psVar2 = (short *)CIRC_Alloc(0x14);
	psVar2[8] = (short)amount;
	psVar2[9] = (short)type;
	if (hitter != (_Instance *)0x0)
	{
		sVar1 = *(short *)hitter->matrix[segment].t;
		*psVar2 = sVar1;
		psVar2[4] = sVar1 - *(short *)hitter->oldMatrix[segment].t;
		sVar1 = *(short *)(hitter->matrix[segment].t + 1);
		psVar2[1] = sVar1;
		psVar2[5] = sVar1 - *(short *)(hitter->oldMatrix[segment].t + 1);
		sVar1 = *(short *)(hitter->matrix[segment].t + 2);
		psVar2[2] = sVar1;
		psVar2[6] = sVar1 - *(short *)(hitter->oldMatrix[segment].t + 2);
	}
	return (int)psVar2;
}

int SetObjectData(void *target, _SVector *angularVel, u_short type, u_short spinType, int speed,
				  int gravity, int zVel, int initialXRot)

{
	u_short uVar1;
	u_short *puVar2;
	u_char uVar3;

	puVar2 = (u_short *)CIRC_Alloc(0x1c);
	*puVar2 = type;
	puVar2[1] = spinType;
	if (target == (void *)0x0)
	{
		*puVar2 = 0;
	}
	else
	{
		switch (type)
		{
		case 1:
			*(void **)(puVar2 + 2) = target;
			break;
		case 2:
		case 4:
			uVar1 = *(u_short *)((int)target + 4);
			*(u_char *)(puVar2 + 2) = *(u_char *)target;
			puVar2[4] = uVar1;
			break;
		case 3:
			uVar3 = *(u_char *)((int)target + 4);
			*(u_char *)(puVar2 + 2) = *(u_char *)target;
			*(u_char *)(puVar2 + 4) = uVar3;
		}
	}
	if ((1 < spinType) && (spinType == 2))
	{
		if (angularVel == (_SVector *)0x0)
		{
			puVar2[1] = 0;
		}
		else
		{
			uVar3 = *(u_char *)&angularVel->z;
			*(u_char *)(puVar2 + 6) = *(u_char *)angularVel;
			*(u_char *)(puVar2 + 8) = uVar3;
		}
	}
	puVar2[10] = (u_short)speed;
	puVar2[0xb] = (u_short)gravity;
	puVar2[0xd] = (u_short)zVel;
	puVar2[0xc] = (u_short)initialXRot;
	return (int)puVar2;
}

int SetObjectThrowData(_Instance *force, short node, short distance, short animation, int frame, int type, int action)

{
	_Instance **pp_Var1;

	pp_Var1 = (_Instance **)CIRC_Alloc(0x10);
	*pp_Var1 = force;
	*(short *)(pp_Var1 + 1) = node;
	*(short *)((int)pp_Var1 + 6) = distance;
	*(short *)(pp_Var1 + 2) = animation;
	*(undefined2 *)((int)pp_Var1 + 10) = (short)frame;
	*(short *)(pp_Var1 + 3) = (short)type;
	*(undefined2 *)((int)pp_Var1 + 0xe) = (short)action;
	return (int)pp_Var1;
}

int SetControlInitHangData(_Instance *instance, long frame, long frames)

{
	_Instance **pp_Var1;

	pp_Var1 = (_Instance **)CIRC_Alloc(0xc);
	*pp_Var1 = instance;
	*(long *)(pp_Var1 + 1) = frame;
	*(long *)(pp_Var1 + 2) = frames;
	return (int)pp_Var1;
}

int SetControlInitIdleData(int mode, long frame, long frames)

{
	int *piVar1;

	piVar1 = (int *)CIRC_Alloc(0xc);
	*piVar1 = mode;
	piVar1[1] = frame;
	piVar1[2] = frames;
	return (int)piVar1;
}

int SetObjectDraftData(short force, u_short radius, u_short radiusCoef, u_short height, int maxVelocity)

{
	short *psVar1;

	psVar1 = (short *)CIRC_Alloc(10);
	*psVar1 = force;
	psVar1[1] = radius;
	psVar1[2] = radiusCoef;
	psVar1[3] = height;
	psVar1[4] = (short)maxVelocity;
	return (int)psVar1;
}

int SetObjectIdleData(_Instance *force, u_short node, u_short steps)

{
	_Instance **pp_Var1;

	pp_Var1 = (_Instance **)CIRC_Alloc(8);
	*pp_Var1 = force;
	*(u_short *)(pp_Var1 + 1) = node;
	*(u_short *)((int)pp_Var1 + 6) = steps;
	return (int)pp_Var1;
}

int SetControlSaveDataData(long length, void *data)

{
	long *plVar1;

	plVar1 = (long *)CIRC_Alloc(8);
	*plVar1 = length;
	*(void **)(plVar1 + 1) = data;
	return (int)plVar1;
}

int SetObjectAbsorbData(long mode, _Instance *instance)

{
	long *plVar1;

	plVar1 = (long *)CIRC_Alloc(8);
	*plVar1 = mode;
	*(_Instance **)(plVar1 + 1) = instance;
	return (int)plVar1;
}

int SetActionPlayHostAnimationData(_Instance *instance, _Instance *host, int newAnim, int newFrame, int frames, int mode)

{
	_Instance **pp_Var1;

	pp_Var1 = (_Instance **)CIRC_Alloc(0x18);
	*pp_Var1 = instance;
	pp_Var1[1] = host;
	*(int *)(pp_Var1 + 2) = newAnim;
	*(int *)(pp_Var1 + 3) = newFrame;
	*(int *)(pp_Var1 + 4) = frames;
	*(int *)(pp_Var1 + 5) = mode;
	return (int)pp_Var1;
}

int SetObjectBirthProjectileData(_Instance *instance, int joint, int type)

{
	_Instance **pp_Var1;

	pp_Var1 = (_Instance **)CIRC_Alloc(0x10);
	*pp_Var1 = instance;
	*(int *)(pp_Var1 + 1) = joint;
	*(int *)(pp_Var1 + 2) = type;
	pp_Var1[3] = (_Instance *)0x0;
	return (int)pp_Var1;
}

int SetShadowSegmentData(u_long total)

{
	u_long *puVar1;

	puVar1 = (u_long *)CIRC_Alloc(0xc);
	*puVar1 = total;
	return (int)puVar1;
}

void G2EmulationInstanceSwitchAnimation(void)

{
	G2AlphaTables7 = (_G2AnimAlphaTable_Type *)0x0;
	if (PTR_800d07e0 == (_G2AnimAlphaTable_Type *)0x0)
	{
		PTR_800d07e0 = (_G2AnimAlphaTable_Type *)MEMPACK_Malloc(0x12, '\x19');
		PTR_800d07e0->size = 4;
		PTR_800d07e0[1] = (_G2AnimAlphaTable_Type)0x0;
		PTR_800d07e0[2] = (_G2AnimAlphaTable_Type)0x100;
		PTR_800d07e0[3] = (_G2AnimAlphaTable_Type)0x400;
		PTR_800d07e0[4] = (_G2AnimAlphaTable_Type)0x1000;
	}
	if (PTR_800d07e4 == (_G2AnimAlphaTable_Type *)0x0)
	{
		PTR_800d07e4 = (_G2AnimAlphaTable_Type *)MEMPACK_Malloc(0x12, '\x19');
		PTR_800d07e4->size = 4;
		PTR_800d07e4[1] = (_G2AnimAlphaTable_Type)0x0;
		PTR_800d07e4[2] = (_G2AnimAlphaTable_Type)0xc00;
		PTR_800d07e4[3] = (_G2AnimAlphaTable_Type)0xf00;
		PTR_800d07e4[4] = (_G2AnimAlphaTable_Type)0x1000;
	}
	if (PTR_800d07e8 == (_G2AnimAlphaTable_Type *)0x0)
	{
		PTR_800d07e8 = (_G2AnimAlphaTable_Type *)MEMPACK_Malloc(6, '\x19');
		PTR_800d07e8->size = 1;
		PTR_800d07e8[1] = (_G2AnimAlphaTable_Type)0x1000;
	}
	if (PTR_800d07ec == (_G2AnimAlphaTable_Type *)0x0)
	{
		PTR_800d07ec = (_G2AnimAlphaTable_Type *)MEMPACK_Malloc(0x12, '\x19');
		PTR_800d07ec->size = 4;
		PTR_800d07ec[1] = (_G2AnimAlphaTable_Type)0x0;
		PTR_800d07ec[2] = (_G2AnimAlphaTable_Type)0x100;
		PTR_800d07ec[3] = (_G2AnimAlphaTable_Type)0xf00;
		PTR_800d07ec[4] = (_G2AnimAlphaTable_Type)0x1000;
	}
	if (PTR_800d07f0 == (_G2AnimAlphaTable_Type *)0x0)
	{
		PTR_800d07f0 = (_G2AnimAlphaTable_Type *)MEMPACK_Malloc(0x12, '\x19');
		PTR_800d07f0->size = 4;
		PTR_800d07f0[1] = (_G2AnimAlphaTable_Type)0x0;
		PTR_800d07f0[2] = (_G2AnimAlphaTable_Type)0x80;
		PTR_800d07f0[3] = (_G2AnimAlphaTable_Type)0x200;
		PTR_800d07f0[4] = (_G2AnimAlphaTable_Type)0x1000;
	}
	if (PTR_800d07f4 == (_G2AnimAlphaTable_Type *)0x0)
	{
		PTR_800d07f4 = (_G2AnimAlphaTable_Type *)MEMPACK_Malloc(0x12, '\x19');
		PTR_800d07f4->size = 4;
		PTR_800d07f4[1] = (_G2AnimAlphaTable_Type)0x0;
		PTR_800d07f4[2] = (_G2AnimAlphaTable_Type)0xe00;
		PTR_800d07f4[3] = (_G2AnimAlphaTable_Type)0xf80;
		PTR_800d07f4[4] = (_G2AnimAlphaTable_Type)0x1000;
	}
	return;
}

void G2EmulationSwitchAnimation(_Instance *instance)

{
	u_int uVar1;
	u_int uVar2;

	uVar2 = 0;
	if ((instance->anim).sectionCount != '\0')
	{
		uVar1 = 0;
		do
		{
			G2AnimSection_JumpToTime((instance->anim).section + uVar1);
			uVar2 = uVar2 + 1;
			uVar1 = uVar2 & 0xff;
		} while ((int)uVar2 < (int)(u_int)(instance->anim).sectionCount);
	}
	return;
}

void G2EmulationInstanceSetAnimSpeed(__CharacterState *In)

{
	G2EmulationSwitchAnimation(In->CharacterInstance);
	return;
}

void G2EmulationInstanceToInstanceSwitchAnimation(_Instance *instance, _Instance *host, int CurrentSection, int NewAnim, int NewFrame,
												  int Frames, int Mode)

{
	_G2AnimKeylist_Type *keylist;
	_G2AnimSection_Type *section;

	section = (instance->anim).section + CurrentSection;
	keylist = G2Instance_GetKeylist(host, NewAnim);
	G2AnimSection_SetAlphaTable(section, (_G2AnimAlphaTable_Type *)0x0);
	G2AnimSection_InterpToKeylistFrame(section, keylist, NewAnim, NewFrame, Frames * 0x640000 >> 0x10);
	if (Mode == 0)
	{
		G2AnimSection_SetNotRewinding(section);
	}
	else
	{
		G2Anim_SetUnpaused(section);
		if (Mode == 2)
		{
			G2Anim_SetNoLooping(section);
		}
		else
		{
			G2AnimSection_SetNoLooping(section);
		}
	}
	return;
}

void G2EmulationSwitchAnimationAlpha(_Instance *instance, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode)

{
	_G2AnimKeylist_Type *keylist;
	_G2AnimSection_Type *section;

	section = (instance->anim).section + CurrentSection;
	keylist = G2Instance_GetKeylist(instance, NewAnim);
	G2AnimSection_SetAlphaTable(section, (_G2AnimAlphaTable_Type *)0x0);
	G2AnimSection_InterpToKeylistFrame(section, keylist, NewAnim, NewFrame, Frames * 0x640000 >> 0x10);
	if (Mode == 0)
	{
		G2AnimSection_SetNotRewinding(section);
	}
	else
	{
		G2Anim_SetUnpaused(section);
		if (Mode == 2)
		{
			G2Anim_SetNoLooping(section);
		}
		else
		{
			G2AnimSection_SetNoLooping(section);
		}
	}
	return;
}

void G2EmulationSwitchAnimationCharacter(_Instance *instance, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode,
										 int AlphaTable)

{
	G2EmulationSwitchAnimationAlpha(instance, CurrentSection, NewAnim, NewFrame, Frames, Mode);
	G2AnimSection_SetAlphaTable((instance->anim).section + (CurrentSection & 0xff), (&G2AlphaTables7)[AlphaTable]);
	return;
}

void G2EmulatePlayAnimation(__CharacterState *In, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode)

{
	if (NewAnim < 0)
	{
		NewAnim = 0;
	}
	G2EmulationSwitchAnimationAlpha(In->CharacterInstance, CurrentSection, NewAnim, NewFrame, Frames, Mode);
	return;
}

void SetAnimationInstanceSwitchData(__CharacterState *In, int CurrentSection, int NewAnim, int NewFrame, int Frames, int Mode, int AlphaTable)

{
	_Instance *p_Var1;

	p_Var1 = In->CharacterInstance;
	G2EmulationSwitchAnimationAlpha(In->CharacterInstance, CurrentSection, NewAnim, NewFrame, Frames, Mode);
	G2AnimSection_SetAlphaTable((p_Var1->anim).section + (CurrentSection & 0xff), (&G2AlphaTables7)[AlphaTable]);
	return;
}

void G2EmulationInstanceSwitchAnimationAlpha(__CharacterState *In, int SlaveSectionID, int MasterSectionID, int Frames)

{
	u_short uVar1;
	int iVar2;
	int iVar3;
	_G2AnimKeylist_Type *keylist;
	_G2AnimSection_Type *section;
	_G2AnimSection_Type *section_00;
	__State *p_Var4;

	section_00 = (In->CharacterInstance->anim).section + (MasterSectionID & 0xff);
	section = (In->CharacterInstance->anim).section + (SlaveSectionID & 0xff);
	p_Var4 = In->SectionList + MasterSectionID;
	keylist = section_00->keylist;
	uVar1 = section_00->keylistID;
	iVar2 = G2AnimSection_GetKeyframeNumber(section_00);
	iVar3 = G2AnimKeylist_GetKeyframeCount(keylist);
	G2AnimSection_SetAlphaTable(section, (_G2AnimAlphaTable_Type *)0x0);
	G2AnimSection_InterpToKeylistFrame(section, keylist, (u_int)uVar1, (iVar2 + Frames) % iVar3, Frames * 0x640000 >> 0x10);
	if ((section_00->flags & 2) == 0)
	{
		G2AnimSection_SetNoLooping(section);
	}
	else
	{
		G2Anim_SetNoLooping(section);
	}
	if ((section_00->flags & 1) == 0)
	{
		G2Anim_SetUnpaused(section);
	}
	else
	{
		G2AnimSection_SetNotRewinding(section);
	}
	StateSwitchStateData(In, SlaveSectionID, (TDRFuncPtr_StateSwitchStateData2NewProcess)p_Var4->Process, 0);
	In->SectionList[SlaveSectionID].Data1 = p_Var4->Data1;
	In->SectionList[SlaveSectionID].Data2 = p_Var4->Data2;
	return;
}

void G2EmulationInstancePlayAnimation(_Instance *instance, _Instance *host, int NewAnim, int NewFrame, int Frames, int Mode)

{
	_G2AnimKeylist_Type *keylist;
	_G2Anim_Type *anim;

	keylist = G2Instance_GetKeylist(host, NewAnim);
	anim = &instance->anim;
	G2Anim_SetAlphaTable(anim, (_G2AnimAlphaTable_Type *)0x0);
	G2Anim_InterpToKeylistFrame(anim, keylist, NewAnim, NewFrame, Frames * 0x640000 >> 0x10);
	if (Mode == 0)
	{
		_G2AnimSection_TriggerEffects(anim);
	}
	else
	{
		G2Anim_SetPaused(anim);
		if (Mode == 2)
		{
			G2Anim_SetLooping(anim);
		}
		else
		{
			G2Anim_SetLooping(anim);
		}
	}
	return;
}

void G2EmulationSwitchAnimationSync(__CharacterState *In, int NewAnim, int NewFrame, int Frames, int Mode)

{
	_G2AnimKeylist_Type *keylist;
	_Instance *instance;
	_G2Anim_Type *anim;

	if (NewAnim < 0)
	{
		NewAnim = 0;
	}
	instance = In->CharacterInstance;
	keylist = G2Instance_GetKeylist(instance, NewAnim);
	anim = &instance->anim;
	G2Anim_SetAlphaTable(anim, (_G2AnimAlphaTable_Type *)0x0);
	G2Anim_InterpToKeylistFrame(anim, keylist, NewAnim, NewFrame, Frames * 0x640000 >> 0x10);
	if (Mode == 0)
	{
		_G2AnimSection_TriggerEffects(anim);
	}
	else
	{
		G2Anim_SetPaused(anim);
		if (Mode == 2)
		{
			G2Anim_SetLooping(anim);
		}
		else
		{
			G2Anim_SetLooping(anim);
		}
	}
	return;
}

void G2EmulationSwitchAnimationSync(__CharacterState *In, int NewAnim, int NewFrame, int Frames, int Mode, int AlphaTable)

{
	G2EmulationSwitchAnimationSync(In, NewAnim, NewFrame, Frames, Mode);
	G2Anim_SetAlphaTable(&In->CharacterInstance->anim, (&G2AlphaTables7)[AlphaTable]);
	return;
}

void G2EmulationInstanceToInstanceSwitchAnimationCharacter(_Instance *instance, int CurrentSection, int NewAnim, int NewFrame, int Frames)

{
	_G2AnimKeylist_Type *keylist;
	_G2AnimSection_Type *section;

	section = (instance->anim).section + (CurrentSection & 0xff);
	keylist = G2Instance_GetKeylist(instance, NewAnim);
	G2AnimSection_SetAlphaTable(section, (_G2AnimAlphaTable_Type *)0x0);
	G2AnimSection_InterpToKeylistFrame(section, keylist, NewAnim, NewFrame, Frames * 0x640000 >> 0x10);
	return;
}

void G2EmulationQueryMode(__CharacterState *In, int CurrentSection, int NewAnim, int NewFrame, int Frames)

{
	if (NewAnim < 0)
	{
		NewAnim = 0;
	}
	G2EmulationInstanceToInstanceSwitchAnimationCharacter(In->CharacterInstance, CurrentSection, NewAnim, NewFrame, Frames);
	return;
}

void G2EmulationInstanceInitSection(_Instance *instance, int CurrentSection, int Mode)

{
	_G2AnimSection_Type *section;

	section = (instance->anim).section + (CurrentSection & 0xff);
	if (Mode == 0)
	{
		G2AnimSection_SetNotRewinding(section);
	}
	else
	{
		G2Anim_SetUnpaused(section);
		if (Mode == 1)
		{
			G2AnimSection_SetNoLooping(section);
		}
		else
		{
			G2Anim_SetNoLooping(section);
		}
	}
	return;
}

void G2EmulationSetMode(__CharacterState *In, int CurrentSection, int Mode)

{
	G2EmulationInstanceInitSection(In->CharacterInstance, CurrentSection, Mode);
	return;
}

void G2EmulationSetAnimation(_Instance *instance, int CurrentSection, int speed)

{
	(instance->anim).section[CurrentSection & 0xff].speedAdjustment = speed;
	return;
}

int G2EmulationInstanceSetMode(_Instance *instance, int CurrentSection)

{
	return (u_int)(instance->anim).section[CurrentSection & 0xff].keylistID;
}

int G2EmulationQueryAnimation(__CharacterState *In, int CurrentSection)

{
	int iVar1;

	iVar1 = G2EmulationInstanceSetMode(In->CharacterInstance, CurrentSection);
	return iVar1;
}

int G2EmulationInstanceQueryAnimation(_Instance *instance, int CurrentSection)

{
	int iVar1;

	iVar1 = G2AnimSection_GetKeyframeNumber((instance->anim).section + (CurrentSection & 0xff));
	return iVar1;
}

int G2EmulationInstanceQueryLastFrame(_Instance *instance, int CurrentSection)

{
	int iVar1;

	iVar1 = _G2AnimSection_GetAnim((instance->anim).section + (CurrentSection & 0xff));
	return iVar1;
}

int G2EmulationInstanceQueryPassedFrame(_Instance *instance, int CurrentSection, int frame)

{
	_G2Bool_Enum _Var1;
	u_int uVar2;
	_G2AnimKeylist_Type *p_Var3;
	short sVar4;
	_G2AnimSection_Type *section;

	section = (instance->anim).section + (CurrentSection & 0xff);
	_Var1 = G2AnimSection_AdvanceOverInterval(section);
	uVar2 = 0;
	if ((_Var1 == G2FALSE) && (uVar2 = 1, frame != 0))
	{
		p_Var3 = G2Anim_GetKeylist(&instance->anim);
		sVar4 = (short)frame * (u_short)p_Var3->s0TailTime;
		uVar2 = 0;
		if (section->storedTime < sVar4)
		{
			uVar2 = (u_int)(section->elapsedTime < sVar4) ^ 1;
		}
	}
	return uVar2;
}

int G2EmulationQueryFrame(__CharacterState *In, int CurrentSection)

{
	int iVar1;

	iVar1 = G2EmulationInstanceQueryAnimation(In->CharacterInstance, CurrentSection);
	return iVar1;
}

int G2EmulationInstanceQueryMode(_Instance *instance, int CurrentSection)

{
	byte bVar1;
	int iVar2;

	bVar1 = (instance->anim).section[CurrentSection & 0xff].flags;
	iVar2 = 0;
	if (((bVar1 & 1) == 0) && (iVar2 = 2, (bVar1 & 2) == 0))
	{
		return 1;
	}
	return iVar2;
}

int G2EmulationInstanceSetAnimation(__CharacterState *In, int CurrentSection)

{
	int iVar1;

	iVar1 = G2EmulationInstanceQueryMode(In->CharacterInstance, CurrentSection);
	return iVar1;
}

void G2EmulationInstanceToInstanceSwitchAnimation(_Instance *instance, int CurrentSection, short Start, short End)

{
	_G2AnimSection_Type *p_Var1;

	p_Var1 = (instance->anim).section + (CurrentSection & 0xff);
	p_Var1->firstSeg = (u_char)Start;
	p_Var1->segCount = ((char)End - (u_char)Start) + '\x01';
	return;
}

void G2EmulationInstanceSetStartAndEndSegment(__CharacterState *In, int CurrentSection, short Start, short End)

{
	G2EmulationInstanceToInstanceSwitchAnimation(In->CharacterInstance, CurrentSection, Start, End);
	return;
}

void G2EmulationInit(_Instance *instance, short Total)

{
	byte bVar1;
	_G2Anim_Type *anim;

	bVar1 = (instance->anim).sectionCount;
	anim = &instance->anim;
	while ((int)(u_int)bVar1 < (int)Total)
	{
		G2Anim_AddSection(anim, 0, 0);
		bVar1 = anim->sectionCount;
	}
	MON_AnimCallback(anim, INSTANCE_DefaultAnimCallback, instance);
	return;
}

void G2EmulationInstanceSetTotalSections(__CharacterState *In, short Total)

{
	In->TotalSections = (int)Total;
	G2EmulationInit(In->CharacterInstance, Total);
	return;
}

void G2EmulationInstanceQueryFrame(_Instance *instance, int CurrentSection, void *callback, void *data)

{
	_G2AnimSection_Type *p_Var1;

	p_Var1 = (instance->anim).section + (CurrentSection & 0xff);
	p_Var1->callback = callback;
	p_Var1->callbackData = data;
	return;
}

void G2EmulationSetInterpController_Vector(_Instance *instance, long segment, long type, _G2SVector3_Type *vec, int Frames, int Data)

{
	G2EmulationSetInterpController_Vector(&instance->anim, segment & 0xffU, type & 0xffU, vec, Frames * 0x640000 >> 0x10);
	G2Anim_SetInterpController_Vector(&instance->anim, segment & 0xffU, type & 0xffU, (void *)Data);
	return;
}

void StateSwitchStateCharacterData(__CharacterState *In, int CurrentSection,
								   TDRFuncPtr_StateSwitchStateDataDefault2NewProcess NewProcess, int Data)

{
	_func_14 *p_Var1;

	p_Var1 = In->SectionList[CurrentSection].Process;
	StateSwitchStateData(In, CurrentSection, (TDRFuncPtr_StateSwitchStateData2NewProcess)NewProcess, Data);
	(*p_Var1)(In, CurrentSection, 0);
	return;
}

void StateSwitchStateDataDefault(__CharacterState *In,
								 TDRFuncPtr_StateSwitchStateCharacterDataDefault1NewProcess NewProcess, int Data)

{
	int CurrentSection;

	CurrentSection = 0;
	if (0 < In->TotalSections)
	{
		do
		{
			StateSwitchStateCharacterData(In, CurrentSection, (TDRFuncPtr_StateSwitchStateDataDefault2NewProcess)NewProcess,
										  Data);
			CurrentSection = CurrentSection + 1;
		} while (CurrentSection < In->TotalSections);
	}
	return;
}

void StateSwitchStateData(__CharacterState *In, int CurrentSection,
						  TDRFuncPtr_StateSwitchStateData2NewProcess NewProcess, int Data)

{
	__MessageQueue *In_00;

	In_00 = &In->SectionList[CurrentSection].Event;
	EnMessageQueueData(In_00);
	DeMessageQueue(In_00, (int)&DAT_00100001, Data);
	*(TDRFuncPtr_StateSwitchStateData2NewProcess *)&In->SectionList[CurrentSection].Process =
		NewProcess;
	(*NewProcess)(In, CurrentSection, 0);
	DeMessageQueue(In_00, (int)&DAT_00100004, 0);
	DeMessageQueue(In_00, (int)&DAT_00100004, 0);
	return;
}

void StateSwitchStateCharacterDataDefault(__CharacterState *In, TDRFuncPtr_StateSwitchStateCharacterData1NewProcess NewProcess,
										  int Data)

{
	int CurrentSection;

	CurrentSection = 0;
	if (0 < In->TotalSections)
	{
		do
		{
			StateSwitchStateData(In, CurrentSection, (TDRFuncPtr_StateSwitchStateData2NewProcess)NewProcess, Data);
			CurrentSection = CurrentSection + 1;
		} while (CurrentSection < In->TotalSections);
	}
	return;
}

void StateGovernState(__CharacterState *In, int Frames)

{
	u_short uVar1;
	_G2Bool_Enum _Var2;
	int iVar3;
	int iVar4;
	_G2AnimSection_Type *section;
	_G2AnimKeylist_Type *keylist;
	_G2AnimSection_Type *section_00;
	u_int uVar5;
	int iVar6;
	int iVar7;

	uVar5 = 1;
	iVar7 = 0x124;
	iVar6 = 8;
	do
	{
		if (*(int *)((int)&In->CharacterInstance + iVar6) ==
			*(int *)((int)&In->CharacterInstance + iVar7))
		{
			section = (In->CharacterInstance->anim).section + (uVar5 - 1 & 0xff);
			section_00 = (In->CharacterInstance->anim).section + (uVar5 & 0xff);
			if (((section->keylistID == section_00->keylistID) &&
				 (_Var2 = G2AnimSection_AdvanceOverInterval(section), _Var2 == G2FALSE)) &&
				(_Var2 = G2AnimSection_AdvanceOverInterval(section_00), _Var2 == G2FALSE))
			{
				iVar3 = G2AnimSection_GetKeyframeNumber(section);
				iVar4 = G2AnimSection_GetKeyframeNumber(section_00);
				if (iVar3 != iVar4)
				{
					keylist = section->keylist;
					uVar1 = section->keylistID;
					iVar3 = G2AnimSection_GetKeyframeNumber(section);
					iVar4 = G2AnimKeylist_GetKeyframeCount(keylist);
					G2AnimSection_InterpToKeylistFrame(section_00, keylist, (u_int)uVar1, (iVar3 + Frames) % iVar4,
													   Frames * 0x640000 >> 0x10);
				}
			}
		}
		iVar7 = iVar7 + 0x11c;
		uVar5 = uVar5 + 1;
		iVar6 = iVar6 + 0x11c;
	} while ((int)uVar5 < 3);
	return;
}
