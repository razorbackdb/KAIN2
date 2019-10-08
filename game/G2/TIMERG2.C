#include "THISDUST.H"
#include "TIMERG2.H"

short G2Timer_GetFrameTime(void)

{
	short sVar1;
	u_int uVar2;

	if (gameTrackerX.timeMult == 0)
	{
		uVar2 = 100;
	}
	else
	{
		uVar2 = gameTrackerX.timeMult * 0x19 >> 10;
	}
	sVar1 = (short)uVar2;
	if ((int)(uVar2 << 0x10) < 1)
	{
		sVar1 = 1;
	}
	return sVar1;
}
