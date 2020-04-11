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

/* File: C:\kain2\game\GAMEPAD.C */

void GAMEPAD_Commands(long (*command) [5],long (*data) [5],long pad)

{
  long (*palVar1) [5];
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  palVar1 = data + pad;
  (command + pad)[2] = (command + pad)[0] & ~(*palVar1)[0];
  uVar8 = (*palVar1)[3];
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
      uVar8 = 0x80;
    }
  }
  else {
    uVar8 = 0xffffff80;
  }
  if ((int)uVar7 < -0x37) {
    uVar3 = (data + pad)[0] | 1;
LAB_80030e58:
    (data + pad)[0] = uVar3;
  }
  else {
    if (0x37 < (int)uVar7) {
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
  iVar6 = iVar2 * 4;
  puVar5 = (uint *)(*data + iVar2);
  puVar5[1] = ~(int)*(short *)(&lastPad_24 + pad * 2) & *puVar5;
  *(short *)(&lastPad_24 + pad * 2) = *(short *)puVar5;
  puVar4 = (uint *)(*command + iVar2);
  puVar4[3] = uVar8;
  puVar4[4] = uVar7;
  if ((DAT_800d220c & 0x10) == 0) {
    iVar2 = 0;
    if ((DAT_800d220c & 1) != 0) {
      memset();
      memset();
      return;
    }
    puVar4[1] = ~*puVar4 & *puVar5;
    *puVar4 = *puVar5;
    iVar6 = 0;
    if ((*puVar5 & 1) == 0) {
      if ((*puVar5 & 2) != 0) {
        iVar6 = 0x80;
      }
    }
    else {
      iVar6 = -0x80;
    }
    if (((data + pad)[0] & 4U) == 0) {
      if (((data + pad)[0] & 8U) != 0) {
        iVar2 = 0x80;
      }
    }
    else {
      iVar2 = -0x80;
    }
    if ((iVar2 != 0) || (iVar6 != 0)) {
      (data + pad)[3] = iVar2;
      (data + pad)[4] = iVar6;
    }
  }
  else {
    puVar4[1] = ~*puVar4 & *(uint *)(&DAT_800d2164 + iVar6);
    *puVar4 = *(uint *)(&DAT_800d2164 + iVar6);
    puVar5[3] = *(uint *)(&DAT_800d2170 + iVar6);
    puVar5[4] = *(uint *)(&DAT_800d2174 + iVar6);
    uVar7 = 0xffffff80;
    if (((*(uint *)(&DAT_800d2164 + iVar6) & 1) != 0) ||
       (uVar7 = 0x80, (*(uint *)(&DAT_800d2164 + iVar6) & 2) != 0)) {
      puVar5[4] = uVar7;
    }
    if ((*(uint *)(&DAT_800d2164 + pad * 0x14) & 4) == 0) {
      if ((*(uint *)(&DAT_800d2164 + pad * 0x14) & 8) != 0) {
        (data + pad)[3] = 0x80;
      }
    }
    else {
      (data + pad)[3] = -0x80;
    }
  }
  if ((((DAT_800d218c & 0x40000) == 0) && ((DAT_800d2190 & 0x2000000) != 0)) &&
     (command = command + pad, ((data + pad)[0] & 0x300U) == 0x300)) {
    uVar7 = (*command)[1];
    (*command)[0] = (*command)[0] & 0xfffff3ffU | 0x40000000;
    if ((uVar7 & 0xc00) != 0) {
      (*command)[1] = uVar7 | 0x40000000;
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

/* File: C:\kain2\game\GAMEPAD.C */

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

/* File: C:\kain2\game\GAMEPAD.C */

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

/* File: C:\kain2\game\GAMEPAD.C */

void GAMEPAD_DisableDualShock(void)

{
  dualshock_onflag = 0;
  dualshock_motors[1] = '\0';
  dualshock_motors[0] = '\0';
  dualshock1_time = 0;
  dualshock0_time = 0;
  PadSetAct(0,dualshock_motors,2);
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

/* File: C:\kain2\game\GAMEPAD.C */

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

/* File: C:\kain2\game\GAMEPAD.C */

void GAMEPAD_HandleDualShock(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_800d2314;
  iVar2 = PadInfoMode(0,2,0);
  if (iVar2 == 0) {
    align_flag = 0;
  }
  else {
    iVar2 = 0;
    if (align_flag == 0) {
      PadSetAct(0,dualshock_motors,2);
      do {
        iVar3 = PadSetActAlign(0,dualshock_align);
        bVar1 = iVar2 < 100000;
        if (iVar3 != 0) break;
        iVar2 = iVar2 + 1;
      } while (bVar1);
      align_flag = 1;
    }
  }
  iVar2 = dualshock0_time - iVar4;
  if ((0 < dualshock0_time) && (dualshock0_time = iVar2, iVar2 < 1)) {
    dualshock0_time = 0;
    dualshock_motors[0] = '\0';
  }
  iVar4 = dualshock1_time - iVar4;
  if ((0 < dualshock1_time) && (dualshock1_time = iVar4, iVar4 < 1)) {
    dualshock1_time = 0;
    dualshock_motors[1] = '\0';
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

/* File: C:\kain2\game\GAMEPAD.C */

void GAMEPAD_Shock(int motor0_speed,int motor0_time,int motor1_speed,int motor1_time)

{
  if (dualshock_onflag != 0) {
    dualshock_motors[0] = (uchar)motor0_speed;
    dualshock_motors[1] = (uchar)motor1_speed;
    dualshock0_time = motor0_time;
    dualshock1_time = motor1_time;
    PadSetAct(0,dualshock_motors,2);
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

/* File: C:\kain2\game\GAMEPAD.C */

void GAMEPAD_Shock0(int motor0_speed,int motor0_time)

{
  if (dualshock_onflag != 0) {
    dualshock_motors[0] = (uchar)motor0_speed;
    dualshock0_time = motor0_time;
    PadSetAct(0,dualshock_motors,2);
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

/* File: C:\kain2\game\GAMEPAD.C */

void GAMEPAD_Shock1(int motor1_speed,int motor1_time)

{
  if (dualshock_onflag != 0) {
    dualshock_motors[1] = (uchar)motor1_speed;
    dualshock1_time = motor1_time;
    PadSetAct(0,dualshock_motors,2);
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

/* File: C:\kain2\game\GAMEPAD.C */

void GAMEPAD_Detect(void)

{
  int iVar1;
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
  iVar1 = PadGetState(0);
  if (iVar1 == 0) goto code_r0x800313b4;
  goto LAB_800313c4;
code_r0x800313b4:
  iVar2 = iVar2 + 1;
  if (4 < iVar2) {
LAB_800313c4:
    if (iVar1 == 4) {
      dualShock = 1;
    }
    if (iVar1 != 1) {
      iVar2 = 0;
      if ((iVar1 != 4) && (iVar1 != 5)) {
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
    iVar1 = PadGetState(0);
    iVar2 = iVar2 + 1;
    if (iVar1 == 6) break;
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

/* File: C:\kain2\game\GAMEPAD.C */

void GAMEPAD_Init(void)

{
  PadInitDirect(&readGPBuffer1,&readGPBuffer2);
  PadStartCom();
  GAMEPAD_Detect();
  memset();
  memset();
  memset();
  gpbuffer1 = 0;
  DAT_800d1dd6 = 0xffff;
  readGPBuffer1 = 0;
  DAT_800d1dfa = 0xffff;
  gpbuffer2 = 0;
  DAT_800d1e1e = 0xffff;
  readGPBuffer2 = 0;
  DAT_800d1e42 = 0xffff;
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

/* File: C:\kain2\game\GAMEPAD.C */

void GAMEPAD_FillOutDemoNames(char *baseAreaName,char *demoName)

{
  char *pcVar1;
  char acStack32 [16];
  
  strcpy();
  pcVar1 = strpbrk(acStack32,s_0123456789_800cf50c);
  if (pcVar1 != (char *)0x0) {
    *pcVar1 = '\0';
  }
  sprintf(demoName,s__kain2_area__s_bin__s_dat_800cf518,acStack32,baseAreaName);
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

/* File: C:\kain2\game\GAMEPAD.C */

void GAMEPAD_LoadDemo(void)

{
  char acStack88 [80];
  
  LAB_800d22d0 = 0;
  if (DAT_800d22d1 != '\0') {
    GAMEPAD_FillOutDemoNames(&DAT_800d2228,acStack88);
    __demoBufferStart = (ushort *)LOAD_ReadFile(acStack88,'\x11');
    __currentData = 0xffff;
    __dataCount = 0;
    LAB_800d22d0 = 1;
    DAT_800d22d1 = '\0';
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
/* File: C:\kain2\game\GAMEPAD.C */

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
  } while (ppuVar2 != (undefined **)lastData);
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

/* File: C:\kain2\game\GAMEPAD.C */

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
/* File: C:\kain2\game\GAMEPAD.C */

void GAMEPAD_GetData(long (*data) [5])

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
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
  psxData[0] = 0;
  psxData[1] = 0;
  (*data)[3] = 0;
  (*data)[4] = 0;
  (data + 1)[3] = 0;
  (data + 1)[4] = 0;
  GAMEPAD_HandleDualShock();
  if ((LAB_800d22d0 != '\0') && (0 < DAT_800d2278)) {
    return;
  }
  puVar4 = (undefined4 *)&gpbuffer1;
  puVar2 = (undefined4 *)&readGPBuffer1;
  do {
    uVar6 = puVar2[1];
    uVar7 = puVar2[2];
    uVar8 = puVar2[3];
    *puVar4 = *puVar2;
    puVar4[1] = uVar6;
    puVar4[2] = uVar7;
    puVar4[3] = uVar8;
    puVar2 = puVar2 + 4;
    puVar4 = puVar4 + 4;
  } while (puVar2 != (undefined4 *)0x800d1e18);
  *(undefined2 *)puVar4 = uRam800d1e18;
  puVar4 = (undefined4 *)&gpbuffer2;
  puVar2 = (undefined4 *)&readGPBuffer2;
  do {
    uVar6 = puVar2[1];
    uVar7 = puVar2[2];
    uVar8 = puVar2[3];
    *puVar4 = *puVar2;
    puVar4[1] = uVar6;
    puVar4[2] = uVar7;
    puVar4[3] = uVar8;
    puVar2 = puVar2 + 4;
    puVar4 = puVar4 + 4;
  } while (puVar2 != (undefined4 *)0x800d1e60);
  *(undefined2 *)puVar4 = uRam800d1e60;
  if (gpbuffer1 == -1) {
    gamePadControllerOut = gamePadControllerOut + 1;
    return;
  }
  if (5 < gamePadControllerOut) {
    GAMEPAD_Detect();
  }
  psxData[0] = DAT_800d1dd6;
  gamePadControllerOut = 0;
  if (controllerType[0] == 'S') {
    psxData[0] = GAMEPAD_RemapAnalogueButtons(DAT_800d1dd6);
  }
  PSXPAD_TranslateData((long *)data,psxData[0],lastData[0]);
  controllerType[0] = DAT_800d1dd5;
  lastData[0] = psxData[0];
  if ((DAT_800d1dd5 != 's') && (DAT_800d1dd5 != 'S')) {
    return;
  }
  uVar5 = (uint)DAT_800d1dd8._2_1_;
  uVar3 = (uint)DAT_800d1dd8._3_1_;
  if (uVar5 - 0x4a < 0x6d) {
    iVar1 = uVar5 - 0x80;
    if ((DAT_800d1dd8._3_1_ < 0x4a) || (iVar1 = uVar5 - 0x80, 0xb6 < DAT_800d1dd8._3_1_))
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

/* File: C:\kain2\game\GAMEPAD.C */

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

/* File: C:\kain2\game\GAMEPAD.C */

void GAMEPAD_Process(GameTracker *gameTracker)

{
  int iVar1;
  long (*data) [5];
  
  if (gameTracker->demoMode != '\0') {
    iVar1 = FONT_GetStringWidth(s_DEMO_MODE_800cf578);
    DAT_800d1cf8 = (0x200 - iVar1) / 2;
    DAT_800d1cfc = 0xd8;
    FONT_Print(s_DEMO_MODE_800cf578);
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

/* File: C:\kain2\game\GAMEPAD.C */

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
  plVar1 = &DAT_800d2114;
  plVar2 = overrideCommand;
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
  } while (plVar3 + 4 != (long *)0x800d2134);
  lVar5 = plVar3[5];
  plVar4[4] = lRam800d2134;
  plVar4[5] = lVar5;
  plVar1 = &DAT_800d213c;
  plVar2 = overrideData;
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
  } while (plVar3 + 4 != (long *)0x800d215c);
  lVar5 = plVar3[5];
  plVar4[4] = lRam800d215c;
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

/* File: C:\kain2\game\GAMEPAD.C */

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
    plVar1 = overrideData;
    plVar2 = &DAT_800d213c;
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
    } while (plVar3 + 4 != overrideData + 8);
    lVar5 = plVar3[5];
    plVar4[4] = overrideData[1][3];
    plVar4[5] = lVar5;
    plVar1 = overrideCommand;
    plVar2 = &DAT_800d2114;
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
    } while (plVar3 + 4 != overrideCommand + 8);
    lVar5 = plVar3[5];
    plVar4[4] = overrideCommand[1][3];
    plVar4[5] = lVar5;
    DAT_800d2114 = DAT_800d2114 | 0x80;
  }
  return;
}





