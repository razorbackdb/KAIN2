#include "THISDUST.H"
#include "GAMEPAD.H"


// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_Commands(long (*command)[5] /*$t4*/, long (*data)[5] /*$t3*/, long pad /*$a2*/)
 // line 102, offset 0x80030d70
	/* begin block 1 */
		// Start line: 103
		// Start offset: 0x80030D70
		// Variables:
	// 		long analogX; // $t2
	// 		long analogY; // $t1
	// 		static short lastPad[2]; // offset 0x0
	/* end block 1 */
	// End offset: 0x80031130
	// End Line: 280

	/* begin block 2 */
		// Start line: 204
	/* end block 2 */
	// End Line: 205

void GAMEPAD_Commands(long (*command) [5],long (*data) [5],long pad)

{
  long (*palVar1) [5];
  int iVar2;
  u_int uVar3;
  u_int *puVar4;
  u_int *puVar5;
  u_int uVar6;
  int iVar7;
  u_int uVar8;
  
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
LAB_80030e58:
    (data + pad)[0] = uVar3;
  }
  else {
    if (0x37 < (int)uVar6) {
      uVar3 = (data + pad)[0] | 2;
      goto LAB_80030e58;
    }
  }
  if ((int)uVar8 < -0x37) {
    uVar3 = (data + pad)[0] | 4;
  }
  else {
    iVar2 = pad * 4;
    if ((int)uVar8 < 0x38) goto LAB_80030eac;
    uVar3 = (data + pad)[0] | 8;
  }
  (data + pad)[0] = uVar3;
  iVar2 = pad << 2;
LAB_80030eac:
  iVar2 = iVar2 + pad;
  puVar5 = (u_int *)(*data + iVar2);
  puVar5[1] = ~(int)*(short *)(&lastPad_24 + pad * 2) & *puVar5;
  *(short *)(&lastPad_24 + pad * 2) = *(short *)puVar5;
  puVar4 = (u_int *)(*command + iVar2);
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
 // line 305, offset 0x80031140
	/* begin block 1 */
		// Start line: 626
	/* end block 1 */
	// End Line: 627

	/* begin block 2 */
		// Start line: 627
	/* end block 2 */
	// End Line: 628

/* WARNING: Unknown calling convention yet parameter storage is locked */

int GAMEPAD_ControllerIsDualShock(void)

{
  return dualShock;
}



// decompiled code
// original method signature: 
// int /*$ra*/ GAMEPAD_DualShockEnabled()
 // line 310, offset 0x8003114c
	/* begin block 1 */
		// Start line: 636
	/* end block 1 */
	// End Line: 637

	/* begin block 2 */
		// Start line: 637
	/* end block 2 */
	// End Line: 638

/* WARNING: Unknown calling convention yet parameter storage is locked */

int GAMEPAD_DualShockEnabled(void)

{
  return (int)dualshock_onflag;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_DisableDualShock()
 // line 315, offset 0x80031158
	/* begin block 1 */
		// Start line: 646
	/* end block 1 */
	// End Line: 647

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMEPAD_DisableDualShock(void)

{
  dualshock_onflag = 0;
  u_char_00h_800c8ebd = '\0';
  dualshock_motors = '\0';
  dualshock1_time = 0;
  dualshock0_time = 0;
  PadSetAct(0,&dualshock_motors,2);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_EnableDualShock()
 // line 325, offset 0x80031198
	/* begin block 1 */
		// Start line: 671
	/* end block 1 */
	// End Line: 672

	/* begin block 2 */
		// Start line: 672
	/* end block 2 */
	// End Line: 673

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMEPAD_EnableDualShock(void)

{
  dualshock_onflag = 1;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_HandleDualShock()
 // line 331, offset 0x800311a8
	/* begin block 1 */
		// Start line: 332
		// Start offset: 0x800311A8
		// Variables:
	// 		int decrement_amount; // $s3

		/* begin block 1.1 */
			// Start line: 341
			// Start offset: 0x800311EC
			// Variables:
		// 		int timeout; // $s0
		/* end block 1.1 */
		// End offset: 0x80031228
		// End Line: 348
	/* end block 1 */
	// End offset: 0x80031284
	// End Line: 373

	/* begin block 2 */
		// Start line: 683
	/* end block 2 */
	// End Line: 684

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMEPAD_HandleDualShock(void)

{
  bool bVar1;
  u_long uVar2;
  u_int uVar3;
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
    u_char_00h_800c8ebd = '\0';
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_Shock(int motor0_speed /*$a0*/, int motor0_time /*$a1*/, int motor1_speed /*$a2*/, int motor1_time /*$a3*/)
 // line 379, offset 0x800312a0
	/* begin block 1 */
		// Start line: 789
	/* end block 1 */
	// End Line: 790

	/* begin block 2 */
		// Start line: 791
	/* end block 2 */
	// End Line: 792

void GAMEPAD_Shock(int motor0_speed,int motor0_time,int motor1_speed,int motor1_time)

{
  if (dualshock_onflag != 0) {
    dualshock_motors = (u_char)motor0_speed;
    u_char_00h_800c8ebd = (u_char)motor1_speed;
    dualshock0_time = motor0_time;
    dualshock1_time = motor1_time;
    PadSetAct(0,&dualshock_motors,2);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_Shock0(int motor0_speed /*$a0*/, int motor0_time /*$a1*/)
 // line 395, offset 0x800312e4
	/* begin block 1 */
		// Start line: 828
	/* end block 1 */
	// End Line: 829

	/* begin block 2 */
		// Start line: 830
	/* end block 2 */
	// End Line: 831

void GAMEPAD_Shock0(int motor0_speed,int motor0_time)

{
  if (dualshock_onflag != 0) {
    dualshock_motors = (u_char)motor0_speed;
    dualshock0_time = motor0_time;
    PadSetAct(0,&dualshock_motors,2);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_Shock1(int motor1_speed /*$a0*/, int motor1_time /*$a1*/)
 // line 409, offset 0x80031320
	/* begin block 1 */
		// Start line: 858
	/* end block 1 */
	// End Line: 859

	/* begin block 2 */
		// Start line: 860
	/* end block 2 */
	// End Line: 861

void GAMEPAD_Shock1(int motor1_speed,int motor1_time)

{
  if (dualshock_onflag != 0) {
    u_char_00h_800c8ebd = (u_char)motor1_speed;
    dualshock1_time = motor1_time;
    PadSetAct(0,&dualshock_motors,2);
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_Detect()
 // line 423, offset 0x8003135c
	/* begin block 1 */
		// Start line: 424
		// Start offset: 0x8003135C
		// Variables:
	// 		int padState; // $v1
	// 		int count; // $s0
	/* end block 1 */
	// End offset: 0x8003141C
	// End Line: 469

	/* begin block 2 */
		// Start line: 888
	/* end block 2 */
	// End Line: 889

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMEPAD_Detect(void)

{
  u_int uVar1;
  int iVar2;
  
  dualshock0_time = 0;
  dualshock1_time = 0;
  align_flag = 0;
  dualshock_onflag = 0;
  dualShock = 0;
LAB_80031394:
  iVar2 = 0;
LAB_80031398:
  VSync(0);
  uVar1 = PadGetState();
  if (uVar1 == 0) goto code_r0x800313b4;
  goto LAB_800313c4;
code_r0x800313b4:
  iVar2 = iVar2 + 1;
  if (4 < iVar2) {
LAB_800313c4:
    if (uVar1 == 4) {
      dualShock = 1;
    }
    if (uVar1 != 1) {
      iVar2 = 0;
      if ((uVar1 != 4) && (uVar1 != 5)) {
        if (dualShock != 0) goto LAB_800313f8;
        goto LAB_8003141c;
      }
      goto LAB_80031398;
    }
    goto LAB_80031394;
  }
  goto LAB_80031398;
  while (iVar2 < 0x1e) {
LAB_800313f8:
    VSync(0);
    uVar1 = PadGetState();
    iVar2 = iVar2 + 1;
    if (uVar1 == 6) break;
  }
LAB_8003141c:
  VSync(3);
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_Init()
 // line 473, offset 0x80031440
	/* begin block 1 */
		// Start line: 1029
	/* end block 1 */
	// End Line: 1030

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
 // line 513, offset 0x800314dc
	/* begin block 1 */
		// Start line: 514
		// Start offset: 0x800314DC
		// Variables:
	// 		char text[16]; // stack offset -32
	// 		char *number; // $v0
	/* end block 1 */
	// End offset: 0x8003151C
	// End Line: 523

	/* begin block 2 */
		// Start line: 1122
	/* end block 2 */
	// End Line: 1123

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
 // line 527, offset 0x80031544
	/* begin block 1 */
		// Start line: 528
		// Start offset: 0x80031544
		// Variables:
	// 		char demoFileName[80]; // stack offset -88
	/* end block 1 */
	// End offset: 0x800315A0
	// End Line: 554

	/* begin block 2 */
		// Start line: 1153
	/* end block 2 */
	// End Line: 1154

	/* begin block 3 */
		// Start line: 1162
	/* end block 3 */
	// End Line: 1163

/* WARNING: Unknown calling convention yet parameter storage is locked */

void GAMEPAD_LoadDemo(void)

{
  char acStack88 [80];
  
  gameTrackerX.demoMode = '\0';
  if (gameTrackerX.setDemoMode != '\0') {
    GAMEPAD_FillOutDemoNames(gameTrackerX.baseAreaName,acStack88);
    __demoBufferStart = (ushort *)LOAD_ReadFile(acStack88,'\x11');
    __currentData = 0xffff;
    __dataCount = 0;
    gameTrackerX.demoMode = '\x01';
    gameTrackerX.setDemoMode = '\0';
    __demoBuffer = __demoBufferStart;
    GAMELOOP_DemoSetup();
  }
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ PSXPAD_TranslateData(long *data /*$a0*/, unsigned short padData /*$a1*/, unsigned short lastData /*$a2*/)
 // line 556, offset 0x800315b0
	/* begin block 1 */
		// Start line: 557
		// Start offset: 0x800315B0
		// Variables:
	// 		int i; // $t1
	// 		struct JoypadMappingStruct table[16]; // stack offset -64

		/* begin block 1.1 */
			// Start line: 611
			// Start offset: 0x80031658
			// Variables:
		// 		unsigned short padButton; // $a3
		// 		unsigned short logicalButton; // $v1
		/* end block 1.1 */
		// End offset: 0x800316BC
		// End Line: 627
	/* end block 1 */
	// End offset: 0x800316CC
	// End Line: 628

	/* begin block 2 */
		// Start line: 1222
	/* end block 2 */
	// End Line: 1223

/* WARNING: Removing unreachable block (ram,0x800315c8) */
/* WARNING: Removing unreachable block (ram,0x800315cc) */
/* WARNING: Removing unreachable block (ram,0x80031618) */

void PSXPAD_TranslateData(long *data,ushort padData,ushort lastData)

{
  ushort uVar1;
  undefined **ppuVar2;
  u_int uVar3;
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
  ppuVar2 = &PTR_PTR_800cf534;
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
    uVar3 = (u_int)((ushort *)puVar5)[1];
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
 // line 633, offset 0x800316d4
	/* begin block 1 */
		// Start line: 635
		// Start offset: 0x800316D4
	/* end block 1 */
	// End offset: 0x800316D4
	// End Line: 637

	/* begin block 2 */
		// Start line: 1394
	/* end block 2 */
	// End Line: 1395

	/* begin block 3 */
		// Start line: 1395
	/* end block 3 */
	// End Line: 1396

	/* begin block 4 */
		// Start line: 1397
	/* end block 4 */
	// End Line: 1398

ushort GAMEPAD_RemapAnalogueButtons(ushort in)

{
  u_int uVar1;
  
  uVar1 = ~(u_int)in;
  return ~((ushort)uVar1 & 0x61f9 |
          (ushort)((uVar1 & 0x800) << 1) | (ushort)((uVar1 & 0x400) << 5) |
          (ushort)((uVar1 & 0x200) << 1) | (ushort)((uVar1 & 0x8000) >> 6) |
          (ushort)((uVar1 & 0x1000) >> 1));
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_GetData(long (*data)[5] /*$s0*/)
 // line 647, offset 0x80031720
	/* begin block 1 */
		// Start line: 648
		// Start offset: 0x80031720
		// Variables:
	// 		long analogue_x; // $a0
	// 		long analogue_y; // $v1
	/* end block 1 */
	// End offset: 0x800319EC
	// End Line: 935

	/* begin block 2 */
		// Start line: 1422
	/* end block 2 */
	// End Line: 1423

/* WARNING: Removing unreachable block (ram,0x800317a8) */
/* WARNING: Removing unreachable block (ram,0x800317b0) */
/* WARNING: Removing unreachable block (ram,0x800317fc) */
/* WARNING: Removing unreachable block (ram,0x80031864) */
/* WARNING: Removing unreachable block (ram,0x8003186c) */
/* WARNING: Removing unreachable block (ram,0x800318b8) */

void GAMEPAD_GetData(long (*data) [5])

{
  int iVar1;
  ControllerPacket *pCVar2;
  u_int uVar3;
  ControllerPacket *pCVar4;
  u_int uVar5;
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
  USHORT_800d1dd2 = 0;
  (*data)[3] = 0;
  (*data)[4] = 0;
  (data + 1)[3] = 0;
  (data + 1)[4] = 0;
  GAMEPAD_HandleDualShock();
  if ((gameTrackerX.demoMode != '\0') && (0 < gameTrackerX.introFXTime)) {
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
    gamePadControllerOut = gamePadControllerOut + 1;
    return;
  }
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
  if ((gpbuffer1.dataFormat != 's') && (gpbuffer1.dataFormat != 'S')) {
    return;
  }
  uVar5 = (u_int)gpbuffer1.data[4];
  uVar3 = (u_int)gpbuffer1.data[5];
  if (uVar5 - 0x4a < 0x6d) {
    iVar1 = uVar5 - 0x80;
    if ((gpbuffer1.data[5] < 0x4a) || (iVar1 = uVar5 - 0x80, 0xb6 < gpbuffer1.data[5]))
    goto LAB_800319cc;
    uVar5 = 0x80;
    uVar3 = 0x80;
  }
  iVar1 = uVar5 - 0x80;
LAB_800319cc:
  (*data)[3] = iVar1;
  (*data)[4] = uVar3 - 0x80;
  return;
}



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_DisplayControllerStatus(int msgY /*$s1*/)
 // line 937, offset 0x80031a00
	/* begin block 1 */
		// Start line: 938
		// Start offset: 0x80031A00
		// Variables:
	// 		char *noCtrlStr; // $s0
	/* end block 1 */
	// End offset: 0x80031A4C
	// End Line: 946

	/* begin block 2 */
		// Start line: 2009
	/* end block 2 */
	// End Line: 2010

	/* begin block 3 */
		// Start line: 2011
	/* end block 3 */
	// End Line: 2012

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
// void /*$ra*/ GAMEPAD_Process(struct GameTracker *gameTracker /*$s1*/)
 // line 957, offset 0x80031a60
	/* begin block 1 */
		// Start line: 958
		// Start offset: 0x80031A60

		/* begin block 1.1 */
			// Start line: 961
			// Start offset: 0x80031A84
		/* end block 1.1 */
		// End offset: 0x80031AB8
		// End Line: 965
	/* end block 1 */
	// End offset: 0x80031AB8
	// End Line: 968

	/* begin block 2 */
		// Start line: 2051
	/* end block 2 */
	// End Line: 2052

void GAMEPAD_Process(GameTracker *gameTracker)

{
  int iVar1;
  long (*data) [5];
  
  if (gameTracker->demoMode != '\0') {
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



// decompiled code
// original method signature: 
// void /*$ra*/ GAMEPAD_SaveControllers()
 // line 1028, offset 0x80031afc
	/* begin block 1 */
		// Start line: 2194
	/* end block 1 */
	// End Line: 2195

	/* begin block 2 */
		// Start line: 2195
	/* end block 2 */
	// End Line: 2196

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
 // line 1035, offset 0x80031bb0
	/* begin block 1 */
		// Start line: 2208
	/* end block 1 */
	// End Line: 2209

	/* begin block 2 */
		// Start line: 2209
	/* end block 2 */
	// End Line: 2210

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
    } while (plVar3 + 4 != (long *)&UNK_800d1d94);
    lVar5 = plVar3[5];
    plVar4[4] = _UNK_800d1d94;
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
    } while (plVar3 + 4 != (long *)&UNK_800d1dc4);
    lVar5 = plVar3[5];
    plVar4[4] = _UNK_800d1dc4;
    plVar4[5] = lVar5;
    gameTrackerX.controlCommand[0][0] = gameTrackerX.controlCommand[0][0] | 0x80;
  }
  return;
}





