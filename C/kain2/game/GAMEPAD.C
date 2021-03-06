#include "THISDUST.H"
#include "GAMEPAD.H"


// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_Commands(long (*command)[5] /*$t4*/, long (*data)[5] /*$t3*/, long pad /*$a2*/)
 // line 55, offset 0x80031244
	/* begin block 1 */
		// Start line: 56
		// Start offset: 0x80031244
		// Variables:
	// 		long analogX; // $t2
	// 		long analogY; // $t1
	// 		static short lastPad[2]; // offset 0x0
	/* end block 1 */
	// End offset: 0x800315F0
	// End Line: 233

	/* begin block 2 */
		// Start line: 110
	/* end block 2 */
	// End Line: 111

void GAMEPAD_Commands(long (*command) [5],long (*data) [5],long pad)

{
  long (*palVar1) [5];
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  palVar1 = data + pad;
  (command + pad)[2] = (command + pad)[0] & ~(*palVar1)[0];
  uVar8 = (*palVar1)[3];
  uVar6 = (*palVar1)[4];
  if (((*palVar1)[0] & 1U) == 0) {
    if (((*palVar1)[0] & 2U) != 0) {
      uVar6 = 0x80;
    }
  }
  else {
    uVar6 = 0xffffff80;
  }
  if (((data + pad)[0] & 4U) == 0) {
    if (((data + pad)[0] & 8U) != 0) {
      uVar8 = 0x80;
    }
  }
  else {
    uVar8 = 0xffffff80;
  }
  if ((int)uVar6 < -0x37) {
    uVar3 = (data + pad)[0] | 1;
LAB_8003132c:
    (data + pad)[0] = uVar3;
  }
  else {
    if (0x37 < (int)uVar6) {
      uVar3 = (data + pad)[0] | 2;
      goto LAB_8003132c;
    }
  }
  if ((int)uVar8 < -0x37) {
    uVar3 = (data + pad)[0] | 4;
  }
  else {
    iVar2 = pad * 4;
    if ((int)uVar8 < 0x38) goto LAB_80031380;
    uVar3 = (data + pad)[0] | 8;
  }
  (data + pad)[0] = uVar3;
  iVar2 = pad << 2;
LAB_80031380:
  iVar2 = iVar2 + pad;
  puVar5 = (uint *)(*data + iVar2);
  puVar5[1] = ~(int)*(short *)(&lastPad_24 + pad * 2) & *puVar5;
  *(short *)(&lastPad_24 + pad * 2) = *(short *)puVar5;
  puVar4 = (uint *)(*command + iVar2);
  puVar4[3] = uVar8;
  puVar4[4] = uVar6;
  if ((gameTrackerX.gameFlags & 0x10U) == 0) {
    iVar2 = 0;
    if ((gameTrackerX.gameFlags & 1U) != 0) {
      memset(gameTrackerX.controlCommand,0,0x28);
      memset(gameTrackerX.controlData,0,0x28);
      return;
    }
    puVar4[1] = ~*puVar4 & *puVar5;
    *puVar4 = *puVar5;
    iVar7 = 0;
    if ((*puVar5 & 1) == 0) {
      if ((*puVar5 & 2) != 0) {
        iVar7 = 0x80;
      }
    }
    else {
      iVar7 = -0x80;
    }
    if (((data + pad)[0] & 4U) == 0) {
      if (((data + pad)[0] & 8U) != 0) {
        iVar2 = 0x80;
      }
    }
    else {
      iVar2 = -0x80;
    }
    if ((iVar2 != 0) || (iVar7 != 0)) {
      (data + pad)[3] = iVar2;
      (data + pad)[4] = iVar7;
    }
  }
  else {
    puVar4[1] = ~*puVar4 & gameTrackerX.overrideData[iVar2];
    *puVar4 = gameTrackerX.overrideData[iVar2];
    puVar5[3] = gameTrackerX.overrideData[iVar2 + 3];
    puVar5[4] = gameTrackerX.overrideData[iVar2 + 4];
    uVar6 = 0xffffff80;
    if (((gameTrackerX.overrideData[iVar2] & 1U) != 0) ||
       (uVar6 = 0x80, (gameTrackerX.overrideData[iVar2] & 2U) != 0)) {
      puVar5[4] = uVar6;
    }
    if ((gameTrackerX.overrideData[pad * 5] & 4U) == 0) {
      if ((gameTrackerX.overrideData[pad * 5] & 8U) != 0) {
        (data + pad)[3] = 0x80;
      }
    }
    else {
      (data + pad)[3] = -0x80;
    }
  }
  if ((((gameTrackerX.debugFlags & 0x40000U) == 0) && ((gameTrackerX.debugFlags2 & 0x2000000U) != 0)
      ) && (command = command + pad, ((data + pad)[0] & 0x300U) == 0x300)) {
    uVar6 = (*command)[1];
    (*command)[0] = (*command)[0] & 0xfffff3ffU | 0x40000000;
    if ((uVar6 & 0xc00) != 0) {
      (*command)[1] = uVar6 | 0x40000000;
    }
    (*command)[1] = (*command)[1] & 0xfffff3ff;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GAMEPAD_ControllerIsDualShock()
 // line 258, offset 0x80031600
	/* begin block 1 */
		// Start line: 532
	/* end block 1 */
	// End Line: 533

	/* begin block 2 */
		// Start line: 533
	/* end block 2 */
	// End Line: 534

/* WARNING: Unknown calling convention yet parameter storage is locked */

int GAMEPAD_ControllerIsDualShock(void)

{
  return dualShock;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GAMEPAD_DualShockEnabled()
 // line 263, offset 0x8003160c
	/* begin block 1 */
		// Start line: 542
	/* end block 1 */
	// End Line: 543

	/* begin block 2 */
		// Start line: 543
	/* end block 2 */
	// End Line: 544

/* WARNING: Unknown calling convention yet parameter storage is locked */

int GAMEPAD_DualShockEnabled(void)

{
  return (int)dualshock_onflag;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_DisableDualShock()
 // line 268, offset 0x80031618
	/* begin block 1 */
		// Start line: 552
	/* end block 1 */
	// End Line: 553

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMEPAD_DisableDualShock(void)

{
  dualshock_onflag = 0;
  UCHAR_00h_800ca21d = '\0';
  dualshock_motors = '\0';
  dualshock1_time = 0;
  dualshock0_time = 0;
  PadSetAct(0,&dualshock_motors,2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_EnableDualShock()
 // line 278, offset 0x80031658
	/* begin block 1 */
		// Start line: 577
	/* end block 1 */
	// End Line: 578

	/* begin block 2 */
		// Start line: 578
	/* end block 2 */
	// End Line: 579

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMEPAD_EnableDualShock(void)

{
  align_flag = 0;
  dualshock_onflag = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_HandleDualShock()
 // line 285, offset 0x8003166c
	/* begin block 1 */
		// Start line: 286
		// Start offset: 0x8003166C
		// Variables:
	// 		int decrement_amount; // $s3

		/* begin block 1.1 */
			// Start line: 295
			// Start offset: 0x800316B0
			// Variables:
		// 		int timeout; // $s0
		/* end block 1.1 */
		// End offset: 0x800316EC
		// End Line: 302
	/* end block 1 */
	// End offset: 0x80031748
	// End Line: 327

	/* begin block 2 */
		// Start line: 591
	/* end block 2 */
	// End Line: 592

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMEPAD_HandleDualShock(void)

{
  bool bVar1;
  ulong uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = gameTrackerX.timeMult;
  uVar3 = PadInfoMode(0,2,0);
  if (uVar3 == 0) {
    align_flag = 0;
  }
  else {
    iVar5 = 0;
    if (align_flag == 0) {
      PadSetAct(0,&dualshock_motors,2);
      do {
        iVar4 = PadSetActAlign(0,"");
        bVar1 = iVar5 < 100000;
        if (iVar4 != 0) break;
        iVar5 = iVar5 + 1;
      } while (bVar1);
      align_flag = 1;
    }
  }
  iVar5 = dualshock0_time - uVar2;
  if ((0 < dualshock0_time) && (dualshock0_time = iVar5, iVar5 < 1)) {
    dualshock0_time = 0;
    dualshock_motors = '\0';
  }
  iVar5 = dualshock1_time - uVar2;
  if ((0 < dualshock1_time) && (dualshock1_time = iVar5, iVar5 < 1)) {
    dualshock1_time = 0;
    UCHAR_00h_800ca21d = '\0';
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_Shock(int motor0_speed /*$a0*/, int motor0_time /*$a1*/, int motor1_speed /*$a2*/, int motor1_time /*$a3*/)
 // line 333, offset 0x80031764
	/* begin block 1 */
		// Start line: 697
	/* end block 1 */
	// End Line: 698

	/* begin block 2 */
		// Start line: 699
	/* end block 2 */
	// End Line: 700

void GAMEPAD_Shock(int motor0_speed,int motor0_time,int motor1_speed,int motor1_time)

{
  if (dualshock_onflag != 0) {
    dualshock_motors = (uchar)motor0_speed;
    UCHAR_00h_800ca21d = (uchar)motor1_speed;
    dualshock0_time = motor0_time;
    dualshock1_time = motor1_time;
    PadSetAct(0,&dualshock_motors,2);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_Shock0(int motor0_speed /*$a0*/, int motor0_time /*$a1*/)
 // line 349, offset 0x800317a8
	/* begin block 1 */
		// Start line: 736
	/* end block 1 */
	// End Line: 737

	/* begin block 2 */
		// Start line: 738
	/* end block 2 */
	// End Line: 739

void GAMEPAD_Shock0(int motor0_speed,int motor0_time)

{
  if (dualshock_onflag != 0) {
    dualshock_motors = (uchar)motor0_speed;
    dualshock0_time = motor0_time;
    PadSetAct(0,&dualshock_motors,2);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_Shock1(int motor1_speed /*$a0*/, int motor1_time /*$a1*/)
 // line 363, offset 0x800317e4
	/* begin block 1 */
		// Start line: 766
	/* end block 1 */
	// End Line: 767

	/* begin block 2 */
		// Start line: 768
	/* end block 2 */
	// End Line: 769

void GAMEPAD_Shock1(int motor1_speed,int motor1_time)

{
  if (dualshock_onflag != 0) {
    UCHAR_00h_800ca21d = (uchar)motor1_speed;
    dualshock1_time = motor1_time;
    PadSetAct(0,&dualshock_motors,2);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_Detect()
 // line 377, offset 0x80031820
	/* begin block 1 */
		// Start line: 378
		// Start offset: 0x80031820
		// Variables:
	// 		int padState; // $v1
	// 		int count; // $s0
	// 		int count1; // $s1
	/* end block 1 */
	// End offset: 0x80031904
	// End Line: 432

	/* begin block 2 */
		// Start line: 796
	/* end block 2 */
	// End Line: 797

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMEPAD_Detect(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  dualshock0_time = 0;
  dualshock1_time = 0;
  align_flag = 0;
  dualshock_onflag = 0;
  ignoreFind = 0;
  dualShock = 0;
  do {
    iVar2 = 0;
LAB_80031860:
    do {
      VSync(0);
      uVar1 = PadGetState();
      if (uVar1 == 0) {
        iVar2 = iVar2 + 1;
        if (iVar2 < 5) goto LAB_80031860;
      }
      if (uVar1 == 4) {
        dualShock = 1;
      }
      iVar3 = iVar3 + 1;
      if (0x1e < iVar3) {
        ignoreFind = 1;
        goto LAB_800318cc;
      }
      iVar2 = 0;
    } while ((uVar1 == 1) || (uVar1 == 4));
  } while (uVar1 == 5);
LAB_800318cc:
  iVar3 = 0;
  if (dualShock != 0) {
    do {
      VSync(0);
      uVar1 = PadGetState();
      iVar3 = iVar3 + 1;
      if (uVar1 == 6) break;
    } while (iVar3 < 0x1e);
  }
  VSync(3);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_Init()
 // line 436, offset 0x80031928
	/* begin block 1 */
		// Start line: 963
	/* end block 1 */
	// End Line: 964

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMEPAD_Init(void)

{
  PadInitDirect(&readGPBuffer1,&readGPBuffer2);
  PadStartCom();
  GAMEPAD_Detect();
  memset(&gDummyCommand,0,0x10);
  memset(&readGPBuffer1,0,0x22);
  memset(&readGPBuffer2,0,0x22);
  gpbuffer1.transStatus = '\0';
  gpbuffer1.data._0_2_ = 0xffff;
  readGPBuffer1.transStatus = '\0';
  readGPBuffer1.data._0_2_ = 0xffff;
  gpbuffer2.transStatus = '\0';
  gpbuffer2.data._0_2_ = 0xffff;
  readGPBuffer2.transStatus = '\0';
  readGPBuffer2.data._0_2_ = 0xffff;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PSXPAD_TranslateData(long *data /*$a0*/, unsigned short padData /*$a1*/, unsigned short lastData /*$a2*/)
 // line 476, offset 0x800319b0
	/* begin block 1 */
		// Start line: 477
		// Start offset: 0x800319B0
		// Variables:
	// 		int i; // $t1
	// 		struct JoypadMappingStruct table[16]; // stack offset -64

		/* begin block 1.1 */
			// Start line: 531
			// Start offset: 0x80031A58
			// Variables:
		// 		unsigned short padButton; // $a3
		// 		unsigned short logicalButton; // $v1
		/* end block 1.1 */
		// End offset: 0x80031ABC
		// End Line: 547
	/* end block 1 */
	// End offset: 0x80031ACC
	// End Line: 548

	/* begin block 2 */
		// Start line: 1056
	/* end block 2 */
	// End Line: 1057

/* WARNING: Removing unreachable block (ram,0x800319c8) */
/* WARNING: Removing unreachable block (ram,0x800319cc) */
/* WARNING: Removing unreachable block (ram,0x80031a18) */

void PSXPAD_TranslateData(long *data,ushort padData,ushort lastData)

{
  ushort uVar1;
  undefined **ppuVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined4 local_40;
  undefined *local_3c [15];
  
  puVar4 = &local_40;
  puVar5 = &local_40;
  ppuVar2 = &PTR_PTR_800d07c8;
  do {
    puVar7 = ppuVar2[1];
    puVar8 = ppuVar2[2];
    puVar9 = ppuVar2[3];
    *(undefined **)puVar4 = *ppuVar2;
    *(undefined **)(puVar4 + 1) = puVar7;
    *(undefined **)(puVar4 + 2) = puVar8;
    *(undefined **)(puVar4 + 3) = puVar9;
    ppuVar2 = ppuVar2 + 4;
    puVar4 = puVar4 + 4;
  } while (ppuVar2 != (undefined **)&lastData);
  iVar6 = 0;
  do {
    uVar1 = *(ushort *)puVar5;
    uVar3 = (uint)((ushort *)puVar5)[1];
    if ((padData & uVar1) == 0) {
      *data = *data | uVar3;
      if ((lastData & uVar1) != 0) {
        data[1] = data[1] | uVar3;
      }
    }
    else {
      if ((lastData & uVar1) == 0) {
        data[2] = data[2] | uVar3;
      }
    }
    iVar6 = iVar6 + 1;
    puVar5 = (undefined4 *)((ushort *)puVar5 + 2);
  } while (iVar6 < 0x10);
  return;
}



// decompiled code
// original method signature: 
// unsigned short /*$ra*/ GAMEPAD_RemapAnalogueButtons(unsigned short in /*$a0*/)
 // line 553, offset 0x80031ad4
	/* begin block 1 */
		// Start line: 555
		// Start offset: 0x80031AD4
	/* end block 1 */
	// End offset: 0x80031AD4
	// End Line: 557

	/* begin block 2 */
		// Start line: 1228
	/* end block 2 */
	// End Line: 1229

	/* begin block 3 */
		// Start line: 1229
	/* end block 3 */
	// End Line: 1230

	/* begin block 4 */
		// Start line: 1231
	/* end block 4 */
	// End Line: 1232

ushort GAMEPAD_RemapAnalogueButtons(ushort in)

{
  uint uVar1;
  
  uVar1 = ~(uint)in;
  return ~((ushort)uVar1 & 0x61f9 |
          (ushort)((uVar1 & 0x800) << 1) | (ushort)((uVar1 & 0x400) << 5) |
          (ushort)((uVar1 & 0x200) << 1) | (ushort)((uVar1 & 0x8000) >> 6) |
          (ushort)((uVar1 & 0x1000) >> 1));
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_DetectInit()
 // line 567, offset 0x80031b20
	/* begin block 1 */
		// Start line: 568
		// Start offset: 0x80031B20
		// Variables:
	// 		int orgdualshock_onflag; // $s0
	/* end block 1 */
	// End offset: 0x80031B58
	// End Line: 574

	/* begin block 2 */
		// Start line: 1256
	/* end block 2 */
	// End Line: 1257

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMEPAD_DetectInit(void)

{
  short sVar1;
  
  sVar1 = dualshock_onflag;
  GAMEPAD_Detect();
  if ((dualShock != 0) && (sVar1 != 0)) {
    GAMEPAD_EnableDualShock();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_GetData(long (*data)[5] /*$s0*/)
 // line 576, offset 0x80031b68
	/* begin block 1 */
		// Start line: 577
		// Start offset: 0x80031B68
		// Variables:
	// 		long analogue_x; // $a0
	// 		long analogue_y; // $v1
	// 		int padState; // $v1
	/* end block 1 */
	// End offset: 0x80031F90
	// End Line: 721

	/* begin block 2 */
		// Start line: 1275
	/* end block 2 */
	// End Line: 1276

	/* begin block 3 */
		// Start line: 1289
	/* end block 3 */
	// End Line: 1290

/* WARNING: Removing unreachable block (ram,0x80031d50) */
/* WARNING: Removing unreachable block (ram,0x80031d54) */
/* WARNING: Removing unreachable block (ram,0x80031da0) */
/* WARNING: Removing unreachable block (ram,0x80031bcc) */
/* WARNING: Removing unreachable block (ram,0x80031bd0) */
/* WARNING: Removing unreachable block (ram,0x80031c1c) */
/* WARNING: Removing unreachable block (ram,0x80031c78) */
/* WARNING: Removing unreachable block (ram,0x80031c7c) */
/* WARNING: Removing unreachable block (ram,0x80031cc8) */
/* WARNING: Removing unreachable block (ram,0x80031dfc) */
/* WARNING: Removing unreachable block (ram,0x80031e00) */
/* WARNING: Removing unreachable block (ram,0x80031e4c) */

void GAMEPAD_GetData(long (*data) [5])

{
  int iVar1;
  ControllerPacket *pCVar2;
  uint uVar3;
  ControllerPacket *pCVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  iVar1 = ignoreFind;
  (*data)[2] = 0;
  (*data)[1] = 0;
  (*data)[0] = 0;
  (data + 1)[2] = 0;
  (data + 1)[1] = 0;
  (data + 1)[0] = 0;
  psxData = 0;
  USHORT_800d3066 = 0;
  (*data)[3] = 0;
  (*data)[4] = 0;
  (data + 1)[3] = 0;
  (data + 1)[4] = 0;
  if (iVar1 == 0) {
    uVar3 = PadGetState();
    if (uVar3 == 1) {
LAB_80031e9c:
      GAMEPAD_DetectInit();
    }
    else {
      if ((uVar3 != 4) && (uVar3 != 5)) {
        GAMEPAD_HandleDualShock();
        pCVar4 = &gpbuffer1;
        pCVar2 = &readGPBuffer1;
        do {
          uVar6 = *(undefined4 *)(pCVar2->data + 2);
          uVar7 = *(undefined4 *)(pCVar2->data + 6);
          uVar8 = *(undefined4 *)(pCVar2->data + 10);
          *(undefined4 *)pCVar4 = *(undefined4 *)pCVar2;
          *(undefined4 *)(pCVar4->data + 2) = uVar6;
          *(undefined4 *)(pCVar4->data + 6) = uVar7;
          *(undefined4 *)(pCVar4->data + 10) = uVar8;
          pCVar2 = (ControllerPacket *)(pCVar2->data + 0xe);
          pCVar4 = (ControllerPacket *)(pCVar4->data + 0xe);
        } while (pCVar2 != (ControllerPacket *)(readGPBuffer1.data + 0x1e));
        *(undefined2 *)pCVar4 = readGPBuffer1.data._30_2_;
        pCVar4 = &gpbuffer2;
        pCVar2 = &readGPBuffer2;
        do {
          uVar6 = *(undefined4 *)(pCVar2->data + 2);
          uVar7 = *(undefined4 *)(pCVar2->data + 6);
          uVar8 = *(undefined4 *)(pCVar2->data + 10);
          *(undefined4 *)pCVar4 = *(undefined4 *)pCVar2;
          *(undefined4 *)(pCVar4->data + 2) = uVar6;
          *(undefined4 *)(pCVar4->data + 6) = uVar7;
          *(undefined4 *)(pCVar4->data + 10) = uVar8;
          pCVar2 = (ControllerPacket *)(pCVar2->data + 0xe);
          pCVar4 = (ControllerPacket *)(pCVar4->data + 0xe);
        } while (pCVar2 != (ControllerPacket *)(readGPBuffer2.data + 0x1e));
        goto LAB_80031e84;
      }
      if (uVar3 == 1) goto LAB_80031e9c;
    }
  }
  else {
    pCVar4 = &gpbuffer1;
    pCVar2 = &readGPBuffer1;
    do {
      uVar6 = *(undefined4 *)(pCVar2->data + 2);
      uVar7 = *(undefined4 *)(pCVar2->data + 6);
      uVar8 = *(undefined4 *)(pCVar2->data + 10);
      *(undefined4 *)pCVar4 = *(undefined4 *)pCVar2;
      *(undefined4 *)(pCVar4->data + 2) = uVar6;
      *(undefined4 *)(pCVar4->data + 6) = uVar7;
      *(undefined4 *)(pCVar4->data + 10) = uVar8;
      pCVar2 = (ControllerPacket *)(pCVar2->data + 0xe);
      pCVar4 = (ControllerPacket *)(pCVar4->data + 0xe);
    } while (pCVar2 != (ControllerPacket *)(readGPBuffer1.data + 0x1e));
    *(undefined2 *)pCVar4 = readGPBuffer1.data._30_2_;
    pCVar4 = &gpbuffer2;
    pCVar2 = &readGPBuffer2;
    do {
      uVar6 = *(undefined4 *)(pCVar2->data + 2);
      uVar7 = *(undefined4 *)(pCVar2->data + 6);
      uVar8 = *(undefined4 *)(pCVar2->data + 10);
      *(undefined4 *)pCVar4 = *(undefined4 *)pCVar2;
      *(undefined4 *)(pCVar4->data + 2) = uVar6;
      *(undefined4 *)(pCVar4->data + 6) = uVar7;
      *(undefined4 *)(pCVar4->data + 10) = uVar8;
      pCVar2 = (ControllerPacket *)(pCVar2->data + 0xe);
      pCVar4 = (ControllerPacket *)(pCVar4->data + 0xe);
    } while (pCVar2 != (ControllerPacket *)(readGPBuffer2.data + 0x1e));
LAB_80031e84:
    *(undefined2 *)pCVar4 = *(undefined2 *)pCVar2;
  }
  if (gpbuffer1.transStatus == -1) {
    gamePadControllerOut = gamePadControllerOut + 1;
    return;
  }
  if (5 < gamePadControllerOut) {
    GAMEPAD_DetectInit();
  }
  psxData = gpbuffer1.data._0_2_;
  gamePadControllerOut = 0;
  if (controllerType == 'S') {
    psxData = GAMEPAD_RemapAnalogueButtons(gpbuffer1.data._0_2_);
  }
  PSXPAD_TranslateData((long *)data,psxData,lastData);
  controllerType = gpbuffer1.dataFormat;
  lastData = psxData;
  if ((gpbuffer1.dataFormat != 's') && (gpbuffer1.dataFormat != 'S')) {
    return;
  }
  uVar5 = (uint)gpbuffer1.data[4];
  uVar3 = (uint)gpbuffer1.data[5];
  if (uVar5 - 0x4a < 0x6d) {
    iVar1 = uVar5 - 0x80;
    if ((gpbuffer1.data[5] < 0x4a) || (iVar1 = uVar5 - 0x80, 0xb6 < gpbuffer1.data[5]))
    goto LAB_80031f70;
    uVar5 = 0x80;
    uVar3 = 0x80;
  }
  iVar1 = uVar5 - 0x80;
LAB_80031f70:
  (*data)[3] = iVar1;
  (*data)[4] = uVar3 - 0x80;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_DisplayControllerStatus(int msgY /*$s1*/)
 // line 723, offset 0x80031fa4
	/* begin block 1 */
		// Start line: 724
		// Start offset: 0x80031FA4
		// Variables:
	// 		char *noCtrlStr; // $s0
	/* end block 1 */
	// End offset: 0x80031FF0
	// End Line: 732

	/* begin block 2 */
		// Start line: 1590
	/* end block 2 */
	// End Line: 1591

	/* begin block 3 */
		// Start line: 1592
	/* end block 3 */
	// End Line: 1593

void GAMEPAD_DisplayControllerStatus(int msgY)

{
  char *text;
  int len;
  
  if (5 < gamePadControllerOut) {
    text = localstr_get(LOCALSTR_no_controller);
    FONT_FontPrintCentered(text,msgY);
    len = FONT_GetStringWidth(text);
    DisplayHintBox(len,msgY);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_Process(struct GameTracker *gameTracker /*$s0*/)
 // line 737, offset 0x80032004
	/* begin block 1 */
		// Start line: 1620
	/* end block 1 */
	// End Line: 1621

void GAMEPAD_Process(GameTracker *gameTracker)

{
  long (*data) [5];
  
  data = (long (*) [5])gameTracker->controlData;
  GAMEPAD_GetData(data);
  GAMEPAD_Commands((long (*) [5])gameTracker->controlCommand,data,0);
  GAMEPAD_Commands((long (*) [5])gameTracker->controlCommand,data,1);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_SaveControllers()
 // line 797, offset 0x8003205c
	/* begin block 1 */
		// Start line: 1741
	/* end block 1 */
	// End Line: 1742

	/* begin block 2 */
		// Start line: 1742
	/* end block 2 */
	// End Line: 1743

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMEPAD_SaveControllers(void)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  
  gpSaved = 1;
  plVar1 = gameTrackerX.controlCommand;
  plVar2 = &overrideCommand;
  do {
    plVar4 = plVar2;
    plVar3 = plVar1;
    lVar5 = plVar3[1];
    lVar6 = plVar3[2];
    lVar7 = plVar3[3];
    *plVar4 = *plVar3;
    plVar4[1] = lVar5;
    plVar4[2] = lVar6;
    plVar4[3] = lVar7;
    plVar1 = plVar3 + 4;
    plVar2 = plVar4 + 4;
  } while (plVar3 + 4 != gameTrackerX.controlCommand + 8);
  lVar5 = plVar3[5];
  plVar4[4] = gameTrackerX.controlCommand[1][3];
  plVar4[5] = lVar5;
  plVar1 = gameTrackerX.controlData;
  plVar2 = &overrideData;
  do {
    plVar4 = plVar2;
    plVar3 = plVar1;
    lVar5 = plVar3[1];
    lVar6 = plVar3[2];
    lVar7 = plVar3[3];
    *plVar4 = *plVar3;
    plVar4[1] = lVar5;
    plVar4[2] = lVar6;
    plVar4[3] = lVar7;
    plVar1 = plVar3 + 4;
    plVar2 = plVar4 + 4;
  } while (plVar3 + 4 != gameTrackerX.controlData + 8);
  lVar5 = plVar3[5];
  plVar4[4] = gameTrackerX.controlData[1][3];
  plVar4[5] = lVar5;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_RestoreControllers()
 // line 804, offset 0x800320f8
	/* begin block 1 */
		// Start line: 1755
	/* end block 1 */
	// End Line: 1756

	/* begin block 2 */
		// Start line: 1756
	/* end block 2 */
	// End Line: 1757

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMEPAD_RestoreControllers(void)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  
  if (gpSaved != 0) {
    gpSaved = 0;
    plVar1 = &overrideData;
    plVar2 = gameTrackerX.controlData;
    do {
      plVar4 = plVar2;
      plVar3 = plVar1;
      lVar5 = plVar3[1];
      lVar6 = plVar3[2];
      lVar7 = plVar3[3];
      *plVar4 = *plVar3;
      plVar4[1] = lVar5;
      plVar4[2] = lVar6;
      plVar4[3] = lVar7;
      plVar1 = plVar3 + 4;
      plVar2 = plVar4 + 4;
    } while (plVar3 + 4 != (long *)&UNK_800d3028);
    lVar5 = plVar3[5];
    plVar4[4] = _UNK_800d3028;
    plVar4[5] = lVar5;
    plVar1 = &overrideCommand;
    plVar2 = gameTrackerX.controlCommand;
    do {
      plVar4 = plVar2;
      plVar3 = plVar1;
      lVar5 = plVar3[1];
      lVar6 = plVar3[2];
      lVar7 = plVar3[3];
      *plVar4 = *plVar3;
      plVar4[1] = lVar5;
      plVar4[2] = lVar6;
      plVar4[3] = lVar7;
      plVar1 = plVar3 + 4;
      plVar2 = plVar4 + 4;
    } while (plVar3 + 4 != (long *)&UNK_800d3058);
    lVar5 = plVar3[5];
    plVar4[4] = _UNK_800d3058;
    plVar4[5] = lVar5;
    gameTrackerX.controlCommand[0][0] = gameTrackerX.controlCommand[0][0] | 0x80;
  }
  return;
}





