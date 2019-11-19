#include "THISDUST.H"
#include "GAMEPAD.H"


// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_Commands(long (*command)[5] /*$t4*/, long (*data)[5] /*$t3*/, long pad /*$a2*/)
 // line 102, offset 0x80031e5c
	/* begin block 1 */
		// Start line: 103
		// Start offset: 0x80031E5C
		// Variables:
	// 		long analogX; // $t2
	// 		long analogY; // $t1
	// 		static short lastPad[2]; // offset 0x0
	/* end block 1 */
	// End offset: 0x800321F8
	// End Line: 275

	/* begin block 2 */
		// Start line: 204
	/* end block 2 */
	// End Line: 205

void GAMEPAD_Commands(long (*command) [5],long (*data) [5],long pad)

{
  long (*palVar1) [5];
  int iVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  palVar1 = data + pad;
  (command + pad)[2] = (command + pad)[0] & ~(*palVar1)[0];
  uVar9 = (*palVar1)[3];
  uVar7 = (*palVar1)[4];
  if (((*palVar1)[0] & 1U) == 0) {
    if (((*palVar1)[0] & 2U) != 0) {
      uVar7 = 0x80;
    }
  }
  else {
    uVar7 = 0xffffff80;
  }
  if (((data + pad)[0] & 4U) == 0) {
    if (((data + pad)[0] & 8U) != 0) {
      uVar9 = 0x80;
    }
  }
  else {
    uVar9 = 0xffffff80;
  }
  if ((int)uVar7 < -0x37) {
    uVar4 = (data + pad)[0] | 1;
LAB_80031f44:
    (data + pad)[0] = uVar4;
  }
  else {
    if (0x37 < (int)uVar7) {
      uVar4 = (data + pad)[0] | 2;
      goto LAB_80031f44;
    }
  }
  if ((int)uVar9 < -0x37) {
    uVar4 = (data + pad)[0] | 4;
LAB_80031f90:
    (data + pad)[0] = uVar4;
    iVar2 = pad << 2;
  }
  else {
    iVar2 = pad * 4;
    if (0x37 < (int)uVar9) {
      uVar4 = (data + pad)[0] | 8;
      goto LAB_80031f90;
    }
  }
  iVar2 = iVar2 + pad;
  puVar6 = (uint *)(*data + iVar2);
  puVar6[1] = ~(int)*(short *)(&lastPad_24 + pad * 2) & *puVar6;
  *(short *)(&lastPad_24 + pad * 2) = *(short *)puVar6;
  puVar5 = (uint *)(*command + iVar2);
  puVar5[3] = uVar9;
  puVar5[4] = uVar7;
  if ((gameTrackerX.gameFlags & 0x10U) == 0) {
    iVar2 = 0;
    if ((gameTrackerX.gameFlags & 1U) != 0) {
      memset(gameTrackerX.controlCommand,0,0x28);
      memset(gameTrackerX.controlData,0,0x28);
      return;
    }
    puVar5[1] = ~*puVar5 & *puVar6;
    *puVar5 = *puVar6;
    iVar8 = 0;
    if ((*puVar6 & 1) == 0) {
      if ((*puVar6 & 2) != 0) {
        iVar8 = 0x80;
      }
    }
    else {
      iVar8 = -0x80;
    }
    if (((data + pad)[0] & 4U) == 0) {
      if (((data + pad)[0] & 8U) != 0) {
        iVar2 = 0x80;
      }
    }
    else {
      iVar2 = -0x80;
    }
    iVar3 = pad * 4;
    if ((iVar2 == 0) && (iVar8 == 0)) goto LAB_80032190;
    (data + pad)[3] = iVar2;
    (data + pad)[4] = iVar8;
  }
  else {
    puVar5[1] = ~*puVar5 & gameTrackerX.overrideData[iVar2];
    *puVar5 = gameTrackerX.overrideData[iVar2];
    puVar6[3] = gameTrackerX.overrideData[iVar2 + 3];
    puVar6[4] = gameTrackerX.overrideData[iVar2 + 4];
    uVar7 = 0xffffff80;
    if (((gameTrackerX.overrideData[iVar2] & 1U) != 0) ||
       (uVar7 = 0x80, (gameTrackerX.overrideData[iVar2] & 2U) != 0)) {
      puVar6[4] = uVar7;
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
  iVar3 = pad << 2;
LAB_80032190:
  puVar5 = (uint *)(*command + iVar3 + pad);
  if (((*data)[iVar3 + pad] & 0x300U) == 0x300) {
    *puVar5 = *puVar5 & 0xfffff3ff | 0x40000000;
    if ((puVar5[1] & 0xc00) != 0) {
      puVar5[1] = puVar5[1] | 0x40000000;
    }
    puVar5[1] = puVar5[1] & 0xfffff3ff;
  }
  return;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GAMEPAD_DualShockEnabled()
 // line 299, offset 0x80032208
	/* begin block 1 */
		// Start line: 614
	/* end block 1 */
	// End Line: 615

	/* begin block 2 */
		// Start line: 615
	/* end block 2 */
	// End Line: 616

/* WARNING: Unknown calling convention yet parameter storage is locked */

int GAMEPAD_DualShockEnabled(void)

{
  return (int)dualshock_onflag;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_DisableDualShock()
 // line 304, offset 0x80032214
	/* begin block 1 */
		// Start line: 624
	/* end block 1 */
	// End Line: 625

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMEPAD_DisableDualShock(void)

{
  dualshock_onflag = 0;
  UCHAR_00h_800c4f5d = '\0';
  dualshock_motors = '\0';
  dualshock1_time = 0;
  dualshock0_time = 0;
  PadSetAct(0,&dualshock_motors,2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_EnableDualShock()
 // line 314, offset 0x80032254
	/* begin block 1 */
		// Start line: 649
	/* end block 1 */
	// End Line: 650

	/* begin block 2 */
		// Start line: 650
	/* end block 2 */
	// End Line: 651

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMEPAD_EnableDualShock(void)

{
  dualshock_onflag = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_HandleDualShock()
 // line 320, offset 0x80032264
	/* begin block 1 */
		// Start line: 321
		// Start offset: 0x80032264
		// Variables:
	// 		int decrement_amount; // $s3

		/* begin block 1.1 */
			// Start line: 328
			// Start offset: 0x8003229C
			// Variables:
		// 		int timeout; // $s0
		/* end block 1.1 */
		// End offset: 0x800322D8
		// End Line: 335
	/* end block 1 */
	// End offset: 0x80032334
	// End Line: 360

	/* begin block 2 */
		// Start line: 661
	/* end block 2 */
	// End Line: 662

	/* begin block 3 */
		// Start line: 664
	/* end block 3 */
	// End Line: 665

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMEPAD_HandleDualShock(void)

{
  bool bVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = gameTrackerX.idleTime;
  if (controllerType == 's') {
    iVar4 = 0;
    if (align_flag == 0) {
      PadSetAct(0,&dualshock_motors,2);
      do {
        iVar3 = PadSetActAlign(0,"");
        bVar1 = iVar4 < 100000;
        if (iVar3 != 0) break;
        iVar4 = iVar4 + 1;
      } while (bVar1);
      align_flag = 1;
    }
  }
  else {
    align_flag = 0;
  }
  iVar4 = dualshock0_time - uVar2;
  if ((0 < dualshock0_time) && (dualshock0_time = iVar4, iVar4 < 1)) {
    dualshock0_time = 0;
    dualshock_motors = '\0';
  }
  iVar4 = dualshock1_time - uVar2;
  if ((0 < dualshock1_time) && (dualshock1_time = iVar4, iVar4 < 1)) {
    dualshock1_time = 0;
    UCHAR_00h_800c4f5d = '\0';
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_Shock(int motor0_speed /*$a0*/, int motor0_time /*$a1*/, int motor1_speed /*$a2*/, int motor1_time /*$a3*/)
 // line 366, offset 0x80032350
	/* begin block 1 */
		// Start line: 759
	/* end block 1 */
	// End Line: 760

	/* begin block 2 */
		// Start line: 761
	/* end block 2 */
	// End Line: 762

void GAMEPAD_Shock(int motor0_speed,int motor0_time,int motor1_speed,int motor1_time)

{
  if (dualshock_onflag != 0) {
    dualshock_motors = (uchar)motor0_speed;
    UCHAR_00h_800c4f5d = (uchar)motor1_speed;
    dualshock0_time = motor0_time;
    dualshock1_time = motor1_time;
    PadSetAct(0,&dualshock_motors,2);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_Shock0(int motor0_speed /*$a0*/, int motor0_time /*$a1*/)
 // line 382, offset 0x80032394
	/* begin block 1 */
		// Start line: 798
	/* end block 1 */
	// End Line: 799

	/* begin block 2 */
		// Start line: 800
	/* end block 2 */
	// End Line: 801

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
 // line 396, offset 0x800323d0
	/* begin block 1 */
		// Start line: 828
	/* end block 1 */
	// End Line: 829

	/* begin block 2 */
		// Start line: 830
	/* end block 2 */
	// End Line: 831

void GAMEPAD_Shock1(int motor1_speed,int motor1_time)

{
  if (dualshock_onflag != 0) {
    UCHAR_00h_800c4f5d = (uchar)motor1_speed;
    dualshock1_time = motor1_time;
    PadSetAct(0,&dualshock_motors,2);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_Detect()
 // line 410, offset 0x8003240c
	/* begin block 1 */
		// Start line: 411
		// Start offset: 0x8003240C
		// Variables:
	// 		int dualShock; // $s1
	// 		int padState; // $v1
	// 		int count; // $s0
	/* end block 1 */
	// End offset: 0x800324C8
	// End Line: 457

	/* begin block 2 */
		// Start line: 858
	/* end block 2 */
	// End Line: 859

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMEPAD_Detect(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  bVar1 = false;
  dualshock0_time = 0;
  dualshock1_time = 0;
  align_flag = 0;
  dualshock_onflag = 0;
LAB_80032448:
  iVar3 = 0;
LAB_8003244c:
  VSync(0);
  uVar2 = PadGetState();
  if (uVar2 == 0) goto code_r0x80032468;
  goto LAB_80032478;
code_r0x80032468:
  iVar3 = iVar3 + 1;
  if (4 < iVar3) {
LAB_80032478:
    if (uVar2 == 4) {
      bVar1 = true;
    }
    if (uVar2 != 1) {
      iVar3 = 0;
      if ((uVar2 != 4) && (uVar2 != 5)) {
        if (bVar1) goto LAB_800324a4;
        goto LAB_800324c8;
      }
      goto LAB_8003244c;
    }
    goto LAB_80032448;
  }
  goto LAB_8003244c;
  while (iVar3 < 0x1e) {
LAB_800324a4:
    VSync(0);
    uVar2 = PadGetState();
    iVar3 = iVar3 + 1;
    if (uVar2 == 6) break;
  }
LAB_800324c8:
  VSync(3);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_Init()
 // line 461, offset 0x800324f0
	/* begin block 1 */
		// Start line: 1006
	/* end block 1 */
	// End Line: 1007

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
// void /*$ra*/ GAMEPAD_FillOutDemoNames(char *baseAreaName /*$s0*/, char *demoName /*$s1*/)
 // line 501, offset 0x8003258c
	/* begin block 1 */
		// Start line: 502
		// Start offset: 0x8003258C
		// Variables:
	// 		char text[16]; // stack offset -32
	// 		char *number; // $v0
	/* end block 1 */
	// End offset: 0x800325CC
	// End Line: 511

	/* begin block 2 */
		// Start line: 1099
	/* end block 2 */
	// End Line: 1100

void GAMEPAD_FillOutDemoNames(char *baseAreaName,char *demoName)

{
  char *pcVar1;
  char acStack32 [16];
  
  strcpy(acStack32,baseAreaName);
  pcVar1 = strpbrk(acStack32,"0123456789");
  if (pcVar1 != (char *)0x0) {
    *pcVar1 = '\0';
  }
  sprintf(demoName,"\\kain2\\area\\%s\\bin\\%s.dat");
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_LoadDemo()
 // line 515, offset 0x800325f4
	/* begin block 1 */
		// Start line: 516
		// Start offset: 0x800325F4
		// Variables:
	// 		char demoFileName[80]; // stack offset -88
	/* end block 1 */
	// End offset: 0x80032650
	// End Line: 542

	/* begin block 2 */
		// Start line: 1130
	/* end block 2 */
	// End Line: 1131

	/* begin block 3 */
		// Start line: 1139
	/* end block 3 */
	// End Line: 1140

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMEPAD_LoadDemo(void)

{
  char acStack88 [80];
  
  gameTrackerX.enemyPlanPool._0_1_ = 0;
  if (gameTrackerX.enemyPlanPool._1_1_ != '\0') {
    GAMEPAD_FillOutDemoNames(gameTrackerX.baseAreaName,acStack88);
    __demoBufferStart = (ushort *)LOAD_ReadFile(acStack88,'\x11');
    __currentData = 0xffff;
    __dataCount = 0;
    gameTrackerX.enemyPlanPool._0_1_ = 1;
    gameTrackerX.enemyPlanPool._1_1_ = '\0';
    __demoBuffer = __demoBufferStart;
    GAMELOOP_DemoSetup();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PSXPAD_TranslateData(long *data /*$a0*/, unsigned short padData /*$a1*/, unsigned short lastData /*$a2*/)
 // line 544, offset 0x80032660
	/* begin block 1 */
		// Start line: 545
		// Start offset: 0x80032660
		// Variables:
	// 		int i; // $t1
	// 		struct JoypadMappingStruct table[16]; // stack offset -64

		/* begin block 1.1 */
			// Start line: 599
			// Start offset: 0x80032708
			// Variables:
		// 		unsigned short padButton; // $a3
		// 		unsigned short logicalButton; // $v1
		/* end block 1.1 */
		// End offset: 0x8003276C
		// End Line: 615
	/* end block 1 */
	// End offset: 0x8003277C
	// End Line: 616

	/* begin block 2 */
		// Start line: 1199
	/* end block 2 */
	// End Line: 1200

/* WARNING: Removing unreachable block (ram,0x80032678) */
/* WARNING: Removing unreachable block (ram,0x8003267c) */
/* WARNING: Removing unreachable block (ram,0x800326c8) */

void PSXPAD_TranslateData(long *data,ushort padData,ushort lastData)

{
  ushort uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 local_40;
  undefined4 local_3c [15];
  
  puVar4 = &local_40;
  puVar5 = &local_40;
  puVar2 = &DAT_800ce5d4;
  do {
    uVar7 = puVar2[1];
    uVar8 = puVar2[2];
    uVar9 = puVar2[3];
    *puVar4 = *puVar2;
    puVar4[1] = uVar7;
    puVar4[2] = uVar8;
    puVar4[3] = uVar9;
    puVar2 = puVar2 + 4;
    puVar4 = puVar4 + 4;
  } while (puVar2 != (undefined4 *)&lastData);
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
 // line 621, offset 0x80032784
	/* begin block 1 */
		// Start line: 623
		// Start offset: 0x80032784
	/* end block 1 */
	// End offset: 0x80032784
	// End Line: 625

	/* begin block 2 */
		// Start line: 1371
	/* end block 2 */
	// End Line: 1372

	/* begin block 3 */
		// Start line: 1372
	/* end block 3 */
	// End Line: 1373

	/* begin block 4 */
		// Start line: 1374
	/* end block 4 */
	// End Line: 1375

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
// void /*$ra*/ GAMEPAD_GetData(long (*data)[5] /*$s0*/)
 // line 635, offset 0x800327d0
	/* begin block 1 */
		// Start line: 636
		// Start offset: 0x800327D0
		// Variables:
	// 		long analogue_x; // $a0
	// 		long analogue_y; // $v1
	/* end block 1 */
	// End offset: 0x80032B98
	// End Line: 914

	/* begin block 2 */
		// Start line: 1399
	/* end block 2 */
	// End Line: 1400

/* WARNING: Removing unreachable block (ram,0x80032858) */
/* WARNING: Removing unreachable block (ram,0x80032860) */
/* WARNING: Removing unreachable block (ram,0x800328ac) */
/* WARNING: Removing unreachable block (ram,0x80032914) */
/* WARNING: Removing unreachable block (ram,0x8003291c) */
/* WARNING: Removing unreachable block (ram,0x80032968) */

void GAMEPAD_GetData(long (*data) [5])

{
  int iVar1;
  char *str;
  ControllerPacket *pCVar2;
  uint uVar3;
  ControllerPacket *pCVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  (*data)[2] = 0;
  (*data)[1] = 0;
  (*data)[0] = 0;
  (data + 1)[2] = 0;
  (data + 1)[1] = 0;
  (data + 1)[0] = 0;
  psxData = 0;
  USHORT_800d1cc6 = 0;
  (*data)[3] = 0;
  (*data)[4] = 0;
  (data + 1)[3] = 0;
  (data + 1)[4] = 0;
  GAMEPAD_HandleDualShock();
  if (((char)gameTrackerX.enemyPlanPool != '\0') && (0 < gameTrackerX.introFXTime)) {
    return;
  }
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
  *(undefined2 *)pCVar4 = readGPBuffer2.data._30_2_;
  if (gpbuffer1.transStatus == -1) {
    if ((gameTrackerX.gameMode == 0) || (gameTrackerX.gameMode == 6)) {
      gamePadControllerOut = gamePadControllerOut + 1;
      if (((gameTrackerX.gameFlags & 0x80U) == 0) && (5 < gamePadControllerOut)) {
        str = localstr_get(LOCALSTR_no_controller);
        FONT_CenterString(str,0x100,0x96);
      }
    }
  }
  else {
    if (5 < gamePadControllerOut) {
      GAMEPAD_Detect();
    }
    psxData = gpbuffer1.data._0_2_;
    gamePadControllerOut = 0;
    if (controllerType == 'S') {
      psxData = GAMEPAD_RemapAnalogueButtons(gpbuffer1.data._0_2_);
    }
    PSXPAD_TranslateData((long *)data,psxData,lastData);
    controllerType = gpbuffer1.dataFormat;
    lastData = psxData;
    if ((gpbuffer1.dataFormat == 's') || (gpbuffer1.dataFormat == 'S')) {
      uVar5 = (uint)gpbuffer1.data[4];
      uVar3 = (uint)gpbuffer1.data[5];
      if (uVar5 - 0x4a < 0x6d) {
        iVar1 = uVar5 - 0x80;
        if ((0x49 < gpbuffer1.data[5]) && (iVar1 = uVar5 - 0x80, gpbuffer1.data[5] < 0xb7)) {
          uVar5 = 0x80;
          uVar3 = 0x80;
          goto LAB_80032a78;
        }
      }
      else {
LAB_80032a78:
        iVar1 = uVar5 - 0x80;
      }
      (*data)[3] = iVar1;
      (*data)[4] = uVar3 - 0x80;
    }
  }
  if (gpbuffer2.transStatus == -1) {
    return;
  }
  USHORT_800d1cc6 = gpbuffer2.data._0_2_;
  if (UCHAR____800d1cc1 == 'S') {
    USHORT_800d1cc6 = GAMEPAD_RemapAnalogueButtons(gpbuffer2.data._0_2_);
  }
  PSXPAD_TranslateData((long *)(data + 1),USHORT_800d1cc6,USHORT_800ce616);
  UCHAR____800d1cc1 = gpbuffer2.dataFormat;
  USHORT_800ce616 = USHORT_800d1cc6;
  if ((gpbuffer2.dataFormat != 's') && (gpbuffer2.dataFormat != 'S')) {
    return;
  }
  uVar5 = (uint)gpbuffer2.data[4];
  uVar3 = (uint)gpbuffer2.data[5];
  if (uVar5 - 0x4a < 0x6d) {
    iVar1 = uVar5 - 0x80;
    if ((gpbuffer2.data[5] < 0x4a) || (iVar1 = uVar5 - 0x80, 0xb6 < gpbuffer2.data[5]))
    goto LAB_80032b8c;
    uVar5 = 0x80;
    uVar3 = 0x80;
  }
  iVar1 = uVar5 - 0x80;
LAB_80032b8c:
  (data + 1)[3] = iVar1;
  (data + 1)[4] = uVar3 - 0x80;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_Process(struct GameTracker *gameTracker /*$s1*/)
 // line 925, offset 0x80032bac
	/* begin block 1 */
		// Start line: 926
		// Start offset: 0x80032BAC

		/* begin block 1.1 */
			// Start line: 929
			// Start offset: 0x80032BD0
		/* end block 1.1 */
		// End offset: 0x80032C04
		// End Line: 933
	/* end block 1 */
	// End offset: 0x80032C04
	// End Line: 936

	/* begin block 2 */
		// Start line: 1992
	/* end block 2 */
	// End Line: 1993

void GAMEPAD_Process(GameTracker *gameTracker)

{
  int iVar1;
  long (*data) [5];
  
  if (*(char *)&gameTracker->enemyPlanPool != '\0') {
    iVar1 = FONT_GetStringWidth("DEMO MODE");
    fontTracker.font_xpos = (0x200 - iVar1) / 2;
    fontTracker.font_ypos = 0xd8;
    FONT_Print("DEMO MODE");
  }
  data = (long (*) [5])gameTracker->controlData;
  GAMEPAD_GetData(data);
  GAMEPAD_Commands((long (*) [5])gameTracker->controlCommand,data,0);
  GAMEPAD_Commands((long (*) [5])gameTracker->controlCommand,data,1);
  return;
}





