#ifndef GAMEPAD_H
#define GAMEPAD_H

extern void GAMEPAD_Commands(long (*command)[5], long (*data)[5], long pad);

extern int GAMEPAD_ControllerIsDualShock();

extern int GAMEPAD_DualShockEnabled();

extern void GAMEPAD_DisableDualShock();

extern void GAMEPAD_EnableDualShock();

extern void GAMEPAD_HandleDualShock();

extern void GAMEPAD_Shock(int motor0_speed, int motor0_time, int motor1_speed, int motor1_time);

extern void GAMEPAD_Shock0(int motor0_speed, int motor0_time);

extern void GAMEPAD_Shock1(int motor1_speed, int motor1_time);

extern void GAMEPAD_Detect();

extern void GAMEPAD_Init();

extern void GAMEPAD_FillOutDemoNames(char *baseAreaName, char *demoName);

extern void GAMEPAD_LoadDemo();

extern void PSXPAD_TranslateData(long *data, unsigned short padData, unsigned short lastData);

extern unsigned short GAMEPAD_RemapAnalogueButtons(unsigned short in);

extern void GAMEPAD_GetData(long (*data)[5]);

extern void GAMEPAD_DisplayControllerStatus(int msgY);

extern void GAMEPAD_Process(struct GameTracker *gameTracker);

extern void GAMEPAD_SaveControllers();

extern void GAMEPAD_RestoreControllers();

#endif
