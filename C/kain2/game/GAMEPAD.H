#ifndef GAMEPAD_H
#define GAMEPAD_H


extern void GAMEPAD_Commands(long (*command)[5], long (*data)[5], long pad); // 0x80031244

extern int GAMEPAD_ControllerIsDualShock(); // 0x80031600

extern int GAMEPAD_DualShockEnabled(); // 0x8003160C

extern void GAMEPAD_DisableDualShock(); // 0x80031618

extern void GAMEPAD_EnableDualShock(); // 0x80031658

extern void GAMEPAD_HandleDualShock(); // 0x8003166C

extern void GAMEPAD_Shock(int motor0_speed, int motor0_time, int motor1_speed, int motor1_time); // 0x80031764

extern void GAMEPAD_Shock0(int motor0_speed, int motor0_time); // 0x800317A8

extern void GAMEPAD_Shock1(int motor1_speed, int motor1_time); // 0x800317E4

extern void GAMEPAD_Detect(); // 0x80031820

extern void GAMEPAD_Init(); // 0x80031928

extern void PSXPAD_TranslateData(long *data, unsigned short padData, unsigned short lastData); // 0x800319B0

extern unsigned short GAMEPAD_RemapAnalogueButtons(unsigned short in); // 0x80031AD4

extern void GAMEPAD_DetectInit(); // 0x80031B20

extern void GAMEPAD_GetData(long (*data)[5]); // 0x80031B68

extern void GAMEPAD_DisplayControllerStatus(int msgY); // 0x80031FA4

extern void GAMEPAD_Process(struct GameTracker *gameTracker); // 0x80032004

extern void GAMEPAD_SaveControllers(); // 0x8003205C

extern void GAMEPAD_RestoreControllers(); // 0x800320F8


#endif
