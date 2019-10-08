#include "THISDUST.H"
#include "CINEPSX.H"

int CINE_CDIntrQuery(void)

{
	if (StCdIntrFlag != 0)
	{
		StCdIntrFlag = 0;
		return 1;
	}
	return 0;
}

u_short CINE_Pad(int pad)

{
	if (pad == 0)
	{
		return readGPBuffer1.data._0_2_;
	}
	return readGPBuffer2.data._0_2_;
}

void CINE_Play(char *strfile, u_short mask, int buffers)

{
	if (the_cine_table != (cinema_fn_table_t *)0x0)
	{
		if (the_cine_table->versionID == "May 25 1999")
		{
			(*the_cine_table->play)(strfile, (u_int)mask);
			LOAD_InitCdStreamMode();
		}
		else
		{
			printf("CINEMA : Version number is wrong. Not playing the cinematics.\n");
		}
	}
	return;
}

int CINE_Load(void)

{
	bool bVar1;
	_ObjectTracker *p_Var2;
	int iVar3;

	iVar3 = 0;
	p_Var2 = STREAM_GetObjectTracker("cinemax");
	do
	{
		bVar1 = iVar3 < 400;
		if (p_Var2->objectStatus == 2)
			break;
		iVar3 = iVar3 + 1;
		STREAM_PollLoadQueue();
		VSync(0);
		bVar1 = iVar3 < 400;
	} while (bVar1);
	if (!bVar1)
	{
		printf("cinema timeout\n");
	}
	else
	{
		the_cine_table = (cinema_fn_table_t *)p_Var2->object->relocModule;
		the_cine_tracker = p_Var2;
	}
	return (u_int)bVar1;
}

int CINE_Loaded(void)

{
	return (u_int)(the_cine_tracker != (_ObjectTracker *)0x0);
}

void CINE_Unload(void)

{
	DrawCallback(VblTick);
	the_cine_table = (cinema_fn_table_t *)0x0;
	if (the_cine_tracker != (_ObjectTracker *)0x0)
	{
		STREAM_LoadObjectReturn(the_cine_tracker);
		the_cine_tracker = (_ObjectTracker *)0x0;
	}
	return;
}

void CINE_PlayIngame(int number)

{
	int iVar1;
	char acStack32[24];

	sprintf(acStack32, "\\CHRONO%d.STR;1");
	iVar1 = CINE_Load();
	if (iVar1 != 0)
	{
		CINE_Play(acStack32, 0, 2);
		CINE_Unload();
	}
	return;
}
