#include "THISDUST.H"
#include "ANMDECMP.H"

void _G2Anim_DecompressChannel_AdaptiveDelta(_G2AnimDecompressChannelInfo_Type *dcInfo, _G2AnimChanStatus_Type *status)

{
	u_short uVar1;
	u_short uVar2;
	u_short *puVar3;
	u_short uVar4;
	u_int uVar5;
	short sVar6;
	int iVar7;
	int iVar8;
	u_int uVar9;
	short sVar10;

	uVar9 = dcInfo->storedKey;
	sVar10 = status->keyData;
	sVar6 = status->index;
	iVar7 = (int)sVar6;
	puVar3 = dcInfo->chanData;
	uVar1 = dcInfo->keylist->keyCount;
	while ((int)uVar9 < dcInfo->targetKey)
	{
		uVar9 = uVar9 + 1;
		uVar5 = (int)(u_int)(puVar3 + 2)[(int)uVar9 >> 2] >> ((uVar9 & 3) << 2);
		uVar2 = *(u_short *)(&_stepSizeTable + iVar7);
		iVar8 = iVar7 + (&_indexTable)[uVar5 & 0xf];
		iVar7 = iVar8;
		if (iVar8 < 0)
		{
			iVar7 = 0;
		}
		if (0x3f < iVar8)
		{
			iVar7 = 0x3f;
		}
		sVar6 = (short)iVar7;
		uVar4 = uVar2 >> 3;
		if ((uVar5 & 4) != 0)
		{
			uVar4 = uVar2 + uVar4;
		}
		if ((uVar5 & 2) != 0)
		{
			uVar4 = uVar4 + (uVar2 >> 1);
		}
		if ((uVar5 & 1) != 0)
		{
			uVar4 = uVar4 + (uVar2 >> 2) + (uVar2 & 1);
		}
		if ((uVar5 & 8) != 0)
		{
			uVar4 = -uVar4;
		}
		sVar10 = sVar10 + uVar4;
	}
	status->index = sVar6;
	status->keyData = sVar10;
	dcInfo->chanData = puVar3 + 2 + ((int)((u_int)uVar1 + 3) >> 2);
	return;
}

void _G2Anim_DecompressChannel_Linear(_G2AnimDecompressChannelInfo_Type *dcInfo, _G2AnimChanStatus_Type *status)

{
	u_short uVar1;
	int iVar2;
	int iVar3;
	u_short *puVar4;
	int iVar5;
	u_int uVar6;

	puVar4 = dcInfo->chanData;
	iVar5 = dcInfo->targetKey;
	dcInfo->chanData = puVar4 + ((u_int)*puVar4 & 0xfff) + 1;
	uVar6 = (u_int)puVar4[1];
	uVar1 = puVar4[2];
	while (true)
	{
		iVar2 = (int)((int)(short)uVar1 & 0xf800U) >> 0xb;
		iVar3 = ((int)(short)uVar1 << 0x15) >> 0x15;
		if (iVar5 <= iVar2)
			break;
		uVar1 = puVar4[3];
		iVar5 = iVar5 - iVar2;
		uVar6 = uVar6 + iVar3;
		puVar4 = puVar4 + 1;
	}
 iVar2);
 return;
}

void _G2Anim_InitializeSegValue(_G2AnimDecompressChannelInfo_Type *dcInfo, _G2AnimChanStatus_Type *status)

{
	u_short uVar1;
	u_short *puVar2;

	puVar2 = dcInfo->chanData;
	uVar1 = dcInfo->keylist->keyCount;
	status->index = (u_short) * (byte *)puVar2;
	status->keyData = puVar2[1];
	dcInfo->chanData = puVar2 + ((int)((u_int)uVar1 + 3) >> 2) + 2;
	return;
}

void _G2Anim_DecompressChannel_Linear(_G2AnimDecompressChannelInfo_Type *dcInfo, _G2AnimChanStatus_Type *status)

{
	u_short uVar1;
	u_short *puVar2;

	puVar2 = dcInfo->chanData;
	uVar1 = *puVar2;
	status->keyData = puVar2[1];
	dcInfo->chanData = puVar2 + ((u_int)uVar1 & 0xfff) + 1;
	return;
}
