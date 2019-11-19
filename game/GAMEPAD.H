#ifndef GAMEPAD_H
#define GAMEPAD_H


extern void GAMEPAD_Commands(long (*command)[5], long (*data)[5], long pad); // 0x80031E5C

extern int GAMEPAD_DualShockEnabled(); // 0x80032208

extern void GAMEPAD_DisableDualShock(); // 0x80032214

extern void GAMEPAD_EnableDualShock(); // 0x80032254

extern void GAMEPAD_HandleDualShock(); // 0x80032264

extern void GAMEPAD_Shock(int motor0_speed, int motor0_time, int motor1_speed, int motor1_time); // 0x80032350

extern void GAMEPAD_Shock0(int motor0_speed, int motor0_time); // 0x80032394

extern void GAMEPAD_Shock1(int motor1_speed, int motor1_time); // 0x800323D0

extern void GAMEPAD_Detect(); // 0x8003240C

extern void GAMEPAD_Init(); // 0x800324F0

extern void GAMEPAD_FillOutDemoNames(char *baseAreaName, char *demoName); // 0x8003258C

extern void GAMEPAD_LoadDemo(); // 0x800325F4

extern void PSXPAD_TranslateData(long *data, unsigned short padData, unsigned short lastData); // 0x80032660

extern unsigned short GAMEPAD_RemapAnalogueButtons(unsigned short in); // 0x80032784

extern void GAMEPAD_GetData(long (*data)[5]); // 0x800327D0

extern void GAMEPAD_Process(struct GameTracker *gameTracker); // 0x80032BAC


#endif
