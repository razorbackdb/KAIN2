#ifndef GAMEPAD_H
#define GAMEPAD_H


extern void GAMEPAD_Commands(long (*command)[5], long (*data)[5], long pad); // 0x80030D70

extern int GAMEPAD_ControllerIsDualShock(); // 0x80031140

extern int GAMEPAD_DualShockEnabled(); // 0x8003114C

extern void GAMEPAD_DisableDualShock(); // 0x80031158

extern void GAMEPAD_EnableDualShock(); // 0x80031198

extern void GAMEPAD_HandleDualShock(); // 0x800311A8

extern void GAMEPAD_Shock(int motor0_speed, int motor0_time, int motor1_speed, int motor1_time); // 0x800312A0

extern void GAMEPAD_Shock0(int motor0_speed, int motor0_time); // 0x800312E4

extern void GAMEPAD_Shock1(int motor1_speed, int motor1_time); // 0x80031320

extern void GAMEPAD_Detect(); // 0x8003135C

extern void GAMEPAD_Init(); // 0x80031440

extern void GAMEPAD_FillOutDemoNames(char *baseAreaName, char *demoName); // 0x800314DC

extern void GAMEPAD_LoadDemo(); // 0x80031544

extern void PSXPAD_TranslateData(long *data, unsigned short padData, unsigned short lastData); // 0x800315B0

extern unsigned short GAMEPAD_RemapAnalogueButtons(unsigned short in); // 0x800316D4

extern void GAMEPAD_GetData(long (*data)[5]); // 0x80031720

extern void GAMEPAD_DisplayControllerStatus(int msgY); // 0x80031A00

extern void GAMEPAD_Process(struct GameTracker *gameTracker); // 0x80031A60

extern void GAMEPAD_SaveControllers(); // 0x80031AFC

extern void GAMEPAD_RestoreControllers(); // 0x80031BB0


#endif
