#include "THISDUST.H"
#include "MAIN.H"

// _ButtonTexture @0x800D0E20, len = 0x00000010
BexitLine =
	{
		// short @0x800D0E20, len = 0x00000002
		.tpage = null,
		// short @0x800D0E22, len = 0x00000002
		.clut = null,
		// short @0x800D0E24, len = 0x00000002
		.textureW = null,
		// short @0x800D0E26, len = 0x00000002
		.textureH = null,
		// _BlockVramEntry * @0x800D0E28, len = 0x00000004
		.vramBlock = null,
		// long @0x800D0E2C, len = 0x00000004
		.xshift = null};
// _ButtonTexture @0x800D0F24, len = 0x00000010
BmenuLines =
	{
		// short @0x800D0F24, len = 0x00000002
		.tpage = null,
		// short @0x800D0F26, len = 0x00000002
		.clut = null,
		// short @0x800D0F28, len = 0x00000002
		.textureW = null,
		// short @0x800D0F2A, len = 0x00000002
		.textureH = null,
		// _BlockVramEntry * @0x800D0F2C, len = 0x00000004
		.vramBlock = null,
		// long @0x800D0F30, len = 0x00000004
		.xshift = null};
// BLK_FILL @0x800D0F88, len = 0x00000010
clearRect =
	{
		// ulong @0x800D0F88, len = 0x00000004
		.tag = null,
		// uchar @0x800D0F8C, len = 0x00000001
		.r0 = 0x00,
		// uchar @0x800D0F8D, len = 0x00000001
		.g0 = 0x00,
		// uchar @0x800D0F8E, len = 0x00000001
		.b0 = 0x00,
		// uchar @0x800D0F8F, len = 0x00000001
		.code = 0x00,
		// ushort @0x800D0F90, len = 0x00000002
		.x0 = null,
		// ushort @0x800D0F92, len = 0x00000002
		.y0 = null,
		// ushort @0x800D0F94, len = 0x00000002
		.w = null,
		// ushort @0x800D0F96, len = 0x00000002
		.h = null};
// DISPENV @0x800D0E40, len = 0x00000014
disp =
	{
		// RECT @0x800D0E40, len = 0x00000008
		.disp =
			{
				// short @0x800D0E40, len = 0x00000002
				.x = null,
				// short @0x800D0E42, len = 0x00000002
				.y = null,
				// short @0x800D0E44, len = 0x00000002
				.w = null,
				// short @0x800D0E46, len = 0x00000002
				.h = null},
		// RECT @0x800D0E48, len = 0x00000008
		.screen =
			{
				// short @0x800D0E48, len = 0x00000002
				.x = null,
				// short @0x800D0E4A, len = 0x00000002
				.y = null,
				// short @0x800D0E4C, len = 0x00000002
				.w = null,
				// short @0x800D0E4E, len = 0x00000002
				.h = null},
		// uchar @0x800D0E50, len = 0x00000001
		.isinter = 0x00,
		// uchar @0x800D0E51, len = 0x00000001
		.isrgb24 = 0x00,
		// uchar @0x800D0E52, len = 0x00000001
		.pad0 = 0x00,
		// uchar @0x800D0E53, len = 0x00000001
		.pad1 = 0x00};
// DRAWENV @0x800D0E6C, len = 0x0000005C
draw =
	{
		// RECT @0x800D0E6C, len = 0x00000008
		.clip =
			{
				// short @0x800D0E6C, len = 0x00000002
				.x = null,
				// short @0x800D0E6E, len = 0x00000002
				.y = null,
				// short @0x800D0E70, len = 0x00000002
				.w = null,
				// short @0x800D0E72, len = 0x00000002
				.h = null},
		// short[2] @0x800D0E74, len = 0x00000004
		.ofs =
			{
				null,
				null},
		// RECT @0x800D0E78, len = 0x00000008
		.tw =
			{
				// short @0x800D0E78, len = 0x00000002
				.x = null,
				// short @0x800D0E7A, len = 0x00000002
				.y = null,
				// short @0x800D0E7C, len = 0x00000002
				.w = null,
				// short @0x800D0E7E, len = 0x00000002
				.h = null},
		// ushort @0x800D0E80, len = 0x00000002
		.tpage = null,
		// uchar @0x800D0E82, len = 0x00000001
		.dtd = 0x00,
		// uchar @0x800D0E83, len = 0x00000001
		.dfe = 0x00,
		// uchar @0x800D0E84, len = 0x00000001
		.isbg = 0x00,
		// uchar @0x800D0E85, len = 0x00000001
		.r0 = 0x00,
		// uchar @0x800D0E86, len = 0x00000001
		.g0 = 0x00,
		// uchar @0x800D0E87, len = 0x00000001
		.b0 = 0x00,
		// DR_ENV @0x800D0E88, len = 0x00000040
		.dr_env =
			{
				// ulong @0x800D0E88, len = 0x00000004
				.tag = null,
				// ulong[15] @0x800D0E8C, len = 0x0000003C
				.code =
					{
						// ulong @0x800D0E8C, len = 0x00000004
						null,
						// ulong @0x800D0E90, len = 0x00000004
						null,
						// ulong @0x800D0E94, len = 0x00000004
						null,
						// ulong @0x800D0E98, len = 0x00000004
						null,
						// ulong @0x800D0E9C, len = 0x00000004
						null,
						// ulong @0x800D0EA0, len = 0x00000004
						null,
						// ulong @0x800D0EA4, len = 0x00000004
						null,
						// ulong @0x800D0EA8, len = 0x00000004
						null,
						// ulong @0x800D0EAC, len = 0x00000004
						null,
						// ulong @0x800D0EB0, len = 0x00000004
						null,
						// ulong @0x800D0EB4, len = 0x00000004
						null,
						// ulong @0x800D0EB8, len = 0x00000004
						null,
						// ulong @0x800D0EBC, len = 0x00000004
						null,
						// ulong @0x800D0EC0, len = 0x00000004
						null,
						// ulong @0x800D0EC4, len = 0x00000004
						null}}};
// GameTracker @0x800D0FAC, len = 0x00000270
gameTrackerX =
	{
		// _GameData_Type @0x800D0FAC, len = 0x00000020
		.gameData =
			{
				// _GameTrackerASMData_Type @0x800D0FAC, len = 0x00000020
				.asmData =
					{
						// long @0x800D0FAC, len = 0x00000004
						.drawBackFaces = null,
						// long @0x800D0FB0, len = 0x00000004
						.dispPage = null,
						// short @0x800D0FB4, len = 0x00000002
						.MorphTime = null,
						// short @0x800D0FB6, len = 0x00000002
						.MorphType = null,
						// LightInstance[1] @0x800D0FB8, len = 0x00000014
						.lightInstances =
							{
								// LightInstance @0x800D0FB8, len = 0x00000014
								{
									// _Instance * @0x800D0FB8, len = 0x00000004
									.lightInstance = null,
									// long @0x800D0FBC, len = 0x00000004
									.r = null,
									// long @0x800D0FC0, len = 0x00000004
									.g = null,
									// long @0x800D0FC4, len = 0x00000004
									.b = null,
									// short @0x800D0FC8, len = 0x00000002
									.radius = null,
									// uchar @0x800D0FCA, len = 0x00000001
									.segment = 0x00,
									// uchar @0x800D0FCB, len = 0x00000001
									.flags = 0x00}}}},
		// menu_t * @0x800D0FCC, len = 0x00000004
		.menu = null,
		// memcard_t * @0x800D0FD0, len = 0x00000004
		.memcard = null,
		// Level * @0x800D0FD4, len = 0x00000004
		.level = null,
		// _Instance * @0x800D0FD8, len = 0x00000004
		.playerInstance = null,
		// long @0x800D0FDC, len = 0x00000004
		.drawPage = null,
		// _InstanceList * @0x800D0FE0, len = 0x00000004
		.instanceList = null,
		// _InstancePool * @0x800D0FE4, len = 0x00000004
		.instancePool = null,
		// _VertexPool * @0x800D0FE8, len = 0x00000004
		.vertexPool = null,
		// _PrimPool * @0x800D0FEC, len = 0x00000004
		.primPool = null,
		// _ObjectTracker * @0x800D0FF0, len = 0x00000004
		.GlobalObjects = null,
		// long[2][5] @0x800D0FF4, len = 0x00000028
		.controlCommand =
			{
				// long[5] @0x800D0FF4, len = 0x00000014
				{
					null,
					null,
					null,
					null,
					null},
				// long[5] @0x800D1008, len = 0x00000014
				{
					null,
					null,
					null,
					null,
					null}},
		// long[2][5] @0x800D101C, len = 0x00000028
		.controlData =
			{
				// long[5] @0x800D101C, len = 0x00000014
				{
					null,
					null,
					null,
					null,
					null},
				// long[5] @0x800D1030, len = 0x00000014
				{
					null,
					null,
					null,
					null,
					null}},
		// long[2][5] @0x800D1044, len = 0x00000028
		.overrideData =
			{
				// long[5] @0x800D1044, len = 0x00000014
				{
					null,
					null,
					null,
					null,
					null},
				// long[5] @0x800D1058, len = 0x00000014
				{
					null,
					null,
					null,
					null,
					null}},
		// long @0x800D106C, len = 0x00000004
		.debugFlags = null,
		// long @0x800D1070, len = 0x00000004
		.debugFlags2 = null,
		// CVECTOR @0x800D1074, len = 0x00000004
		.wipeColor =
			{
				// uchar @0x800D1074, len = 0x00000001
				.r = 0x00,
				// uchar @0x800D1075, len = 0x00000001
				.g = 0x00,
				// uchar @0x800D1076, len = 0x00000001
				.b = 0x00,
				// uchar @0x800D1077, len = 0x00000001
				.cd = 0x00},
		// short @0x800D1078, len = 0x00000002
		.wipeTime = null,
		// short @0x800D107A, len = 0x00000002
		.maxWipeTime = null,
		// short @0x800D107C, len = 0x00000002
		.wipeType = null,
		// short @0x800D107E, len = 0x00000002
		.numGSignals = null,
		// _func_14 *[16] @0x800D1080, len = 0x00000040
		.gSignal =
			{
				// _func_14 * @0x800D1080, len = 0x00000004
				null,
				// _func_14 * @0x800D1084, len = 0x00000004
				null,
				// _func_14 * @0x800D1088, len = 0x00000004
				null,
				// _func_14 * @0x800D108C, len = 0x00000004
				null,
				// _func_14 * @0x800D1090, len = 0x00000004
				null,
				// _func_14 * @0x800D1094, len = 0x00000004
				null,
				// _func_14 * @0x800D1098, len = 0x00000004
				null,
				// _func_14 * @0x800D109C, len = 0x00000004
				null,
				// _func_14 * @0x800D10A0, len = 0x00000004
				null,
				// _func_14 * @0x800D10A4, len = 0x00000004
				null,
				// _func_14 * @0x800D10A8, len = 0x00000004
				null,
				// _func_14 * @0x800D10AC, len = 0x00000004
				null,
				// _func_14 * @0x800D10B0, len = 0x00000004
				null,
				// _func_14 * @0x800D10B4, len = 0x00000004
				null,
				// _func_14 * @0x800D10B8, len = 0x00000004
				null,
				// _func_14 * @0x800D10BC, len = 0x00000004
				null},
		// LightInfo * @0x800D10C0, len = 0x00000004
		.lightInfo = null,
		// void * @0x800D10C4, len = 0x00000004
		.reqDisp = null,
		// long * @0x800D10C8, len = 0x00000004
		.drawTimerReturn = null,
		// long @0x800D10CC, len = 0x00000004
		.usecsStartDraw = null,
		// void * @0x800D10D0, len = 0x00000004
		.disp = null,
		// ulong @0x800D10D4, len = 0x00000004
		.displayFrameCount = null,
		// ulong @0x800D10D8, len = 0x00000004
		.frameCount = null,
		// ulong @0x800D10DC, len = 0x00000004
		.fps30Count = null,
		// ulong @0x800D10E0, len = 0x00000004
		.vblFrames = null,
		// ulong @0x800D10E4, len = 0x00000004
		.vblCount = null,
		// long @0x800D10E8, len = 0x00000004
		.numMatrices = null,
		// long @0x800D10EC, len = 0x00000004
		.gameFlags = null,
		// long @0x800D10F0, len = 0x00000004
		.streamFlags = null,
		// void * @0x800D10F4, len = 0x00000004
		.drawNonAnimatedSegmentFunc = null,
		// void * @0x800D10F8, len = 0x00000004
		.drawAnimatedModelFunc = null,
		// void * @0x800D10FC, len = 0x00000004
		.drawDisplayPolytopeListFunc = null,
		// void * @0x800D1100, len = 0x00000004
		.drawBgFunc = null,
		// Level * @0x800D1104, len = 0x00000004
		.mainDrawUnit = null,
		// char[16] @0x800D1108, len = 0x00000010
		.baseAreaName =
			{
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00'},
		// short @0x800D1118, len = 0x00000002
		.levelDone = null,
		// short @0x800D111A, len = 0x00000002
		.levelChange = null,
		// short @0x800D111C, len = 0x00000002
		.hideBG = null,
		// short @0x800D111E, len = 0x00000002
		.gameMode = null,
		// long @0x800D1120, len = 0x00000004
		.currentHotSpot = null,
		// long @0x800D1124, len = 0x00000004
		.StreamUnitID = null,
		// short @0x800D1128, len = 0x00000002
		.SwitchToNewStreamUnit = null,
		// short @0x800D112A, len = 0x00000002
		.SwitchToNewWarpIndex = null,
		// char[16] @0x800D112C, len = 0x00000010
		.S_baseAreaName =
			{
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00'},
		// short @0x800D113C, len = 0x00000002
		.toSignal = null,
		// short @0x800D113E, len = 0x00000002
		.fromSignal = null,
		// char @0x800D1140, len = 0x00000001
		.LastSignal = 0x00,
		// short @0x800D1142, len = 0x00000002
		.StreamNormalA = null,
		// short @0x800D1144, len = 0x00000002
		.StreamNormalB = null,
		// short @0x800D1146, len = 0x00000002
		.StreamNormalC = null,
		// long @0x800D1148, len = 0x00000004
		.StreamNormalD = null,
		// long @0x800D114C, len = 0x00000004
		.moveRazielToStreamID = null,
		// _ColorType @0x800D1150, len = 0x00000004
		.animObjLine =
			{
				// uchar @0x800D1150, len = 0x00000001
				.r = 0x00,
				// uchar @0x800D1151, len = 0x00000001
				.g = 0x00,
				// uchar @0x800D1152, len = 0x00000001
				.b = 0x00,
				// uchar @0x800D1153, len = 0x00000001
				.code = 0x00},
		// _ColorType @0x800D1154, len = 0x00000004
		.animObjShade =
			{
				// uchar @0x800D1154, len = 0x00000001
				.r = 0x00,
				// uchar @0x800D1155, len = 0x00000001
				.g = 0x00,
				// uchar @0x800D1156, len = 0x00000001
				.b = 0x00,
				// uchar @0x800D1157, len = 0x00000001
				.code = 0x00},
		// long @0x800D1158, len = 0x00000004
		.maxIntroFXTime = null,
		// gSoundData @0x800D115C, len = 0x00000014
		.sound =
			{
				// ulong @0x800D115C, len = 0x00000004
				.gMasterVol = null,
				// ulong @0x800D1160, len = 0x00000004
				.gMusicVol = null,
				// ulong @0x800D1164, len = 0x00000004
				.gSfxVol = null,
				// ulong @0x800D1168, len = 0x00000004
				.gVoiceVol = null,
				// char @0x800D116C, len = 0x00000001
				.gSfxOn = 0x00,
				// char @0x800D116D, len = 0x00000001
				.gMusicOn = 0x00,
				// char @0x800D116E, len = 0x00000001
				.gVoiceOn = 0x00,
				// char @0x800D116F, len = 0x00000001
				.soundsLoaded = 0x00},
		// short @0x800D1170, len = 0x00000002
		.controllerMode = null,
		// uchar @0x800D1172, len = 0x00000001
		.plan_collide_override = 0x00,
		// uchar @0x800D1173, len = 0x00000001
		.cheatMode = 0x00,
		// char @0x800D1174, len = 0x00000001
		.currentLvl = 0x00,
		// char @0x800D1175, len = 0x00000001
		.lastLvl = 0x00,
		// Object * @0x800D1178, len = 0x00000004
		.introFX = null,
		// Intro * @0x800D117C, len = 0x00000004
		.introFXIntro = null,
		// ulong * * @0x800D1180, len = 0x00000004
		.drawOT = null,
		// ulong * * @0x800D1184, len = 0x00000004
		.dispOT = null,
		// P_TAG * @0x800D1188, len = 0x00000004
		.savedOTStart = null,
		// P_TAG * @0x800D118C, len = 0x00000004
		.savedOTEnd = null,
		// long @0x800D1190, len = 0x00000004
		.introWaitTime = null,
		// long @0x800D1194, len = 0x00000004
		.mirrorZPush = null,
		// long @0x800D1198, len = 0x00000004
		.defVVRemoveDist = null,
		// long @0x800D119C, len = 0x00000004
		.defRemoveDist = null,
		// _Position @0x800D11A0, len = 0x00000006
		.forcedStartPosition =
			{
				// short @0x800D11A0, len = 0x00000002
				.x = null,
				// short @0x800D11A2, len = 0x00000002
				.y = null,
				// short @0x800D11A4, len = 0x00000002
				.z = null},
		// short @0x800D11A6, len = 0x00000002
		.hudCollDisplay = null,
		// long @0x800D11A8, len = 0x00000004
		.primMemUsed = null,
		// long @0x800D11AC, len = 0x00000004
		.cheatTimerCount = null,
		// long @0x800D11B0, len = 0x00000004
		.playerCheatFlags = null,
		// long @0x800D11B4, len = 0x00000004
		.savedPlayerCameraMode = null,
		// long @0x800D11B8, len = 0x00000004
		.debugDrawFlags = null,
		// void * @0x800D11BC, len = 0x00000004
		.planningPool = null,
		// void * @0x800D11C0, len = 0x00000004
		.enemyPlanPool = null,
		// uchar @0x800D11C4, len = 0x00000001
		.block_collide_override = 0x00,
		// uchar @0x800D11C5, len = 0x00000001
		.raziel_collide_override = 0x00,
		// short @0x800D11C6, len = 0x00000002
		.timeOfDay = null,
		// long @0x800D11C8, len = 0x00000004
		.decoupleGame = null,
		// long @0x800D11CC, len = 0x00000004
		.multGameTime = null,
		// short @0x800D11D0, len = 0x00000002
		.spectral_fadeValue = null,
		// short @0x800D11D2, len = 0x00000002
		.material_fadeValue = null,
		// ulong @0x800D11D4, len = 0x00000004
		.drawTime = null,
		// ulong @0x800D11D8, len = 0x00000004
		.currentTime = null,
		// ulong @0x800D11DC, len = 0x00000004
		.currentMaterialTime = null,
		// ulong @0x800D11E0, len = 0x00000004
		.currentSpectralTime = null,
		// ulong @0x800D11E4, len = 0x00000004
		.currentTimeOfDayTime = null,
		// ulong @0x800D11E8, len = 0x00000004
		.lastLoopTime = null,
		// ulong @0x800D11EC, len = 0x00000004
		.timeMult = null,
		// ulong @0x800D11F0, len = 0x00000004
		.globalTimeMult = null,
		// ulong @0x800D11F4, len = 0x00000004
		.spectralTimeMult = null,
		// ulong @0x800D11F8, len = 0x00000004
		.materialTimeMult = null,
		// ulong @0x800D11FC, len = 0x00000004
		.currentTicks = null,
		// ulong @0x800D1200, len = 0x00000004
		.totalTime = null,
		// ulong @0x800D1204, len = 0x00000004
		.idleTime = null,
		// long @0x800D1208, len = 0x00000004
		.visibleInstances = null,
		// int @0x800D120C, len = 0x00000004
		.gameFramePassed = null,
		// ulong @0x800D1210, len = 0x00000004
		.timeSinceLastGameFrame = null,
		// long @0x800D1214, len = 0x00000004
		.frameRateLock = null,
		// short @0x800D1218, len = 0x00000002
		.frameRate24fps = null,
		// char @0x800D121A, len = 0x00000001
		.monster_collide_override = 0x00,
		// char @0x800D121B, len = 0x00000001
		.pad = 0x00};
// InterfaceItem @0x800CE570, len = 0x00000038
InterfaceItems =
	{
		// char[48] @0x800CE570, len = 0x00000030
		.name =
			{
		'\', 'P',
				'U',
				'B',
				'L',
				'O',
				'G',
				'O',
				'.',
				'S',
				'T',
				'R',
				';',
				'1',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00',
				'\x00'},
		// ushort @0x800CE5A0, len = 0x00000002
		.timeout = 0x0,
		// ushort @0x800CE5A2, len = 0x00000002
		.buttonTimeout = 0x0,
		// short @0x800CE5A4, len = 0x00000002
		.itemType = 0x0,
		// short @0x800CE5A6, len = 0x00000002
		.nextItem = 0x1};
// int @0x800D0E1C, len = 0x00000004
mainMenuSfx = null;
// MainTracker @0x800D121C, len = 0x00000010
mainTrackerX =
	{
		// long @0x800D121C, len = 0x00000004
		.mainState = null,
		// long @0x800D1220, len = 0x00000004
		.previousState = null,
		// long @0x800D1224, len = 0x00000004
		.movieNum = null,
		// long @0x800D1228, len = 0x00000004
		.done = null};
// _ButtonTexture @0x800D122C, len = 0x00000010
PauseButtons =
	{
		// short @0x800D122C, len = 0x00000002
		.tpage = null,
		// short @0x800D122E, len = 0x00000002
		.clut = null,
		// short @0x800D1230, len = 0x00000002
		.textureW = null,
		// short @0x800D1232, len = 0x00000002
		.textureH = null,
		// _BlockVramEntry * @0x800D1234, len = 0x00000004
		.vramBlock = null,
		// long @0x800D1238, len = 0x00000004
		.xshift = null};
// decompiled code
// original method signature:
// void /*$ra*/ ClearDisplay()
// line 136, offset 0x80037ef8
/* begin block 1 */
// Start line: 272
/* end block 1 */
// End Line: 273

/* begin block 2 */
// Start line: 274
/* end block 2 */
// End Line: 275

/* WARNING: Unknown calling convention yet parameter storage is locked */

void ClearDisplay(void)

{
	PutDrawEnv((undefined4 *)(&draw + gameTrackerX.gameData.asmData.dispPage));
	(&clearRect)[gameTrackerX.gameData.asmData.dispPage].r0 = '\0';
	(&clearRect)[gameTrackerX.gameData.asmData.dispPage].g0 = '\0';
	(&clearRect)[gameTrackerX.gameData.asmData.dispPage].b0 = '\0';
	DrawPrim((int)(&clearRect + gameTrackerX.gameData.asmData.dispPage));
	DrawSync(0);
	PutDispEnv((ushort *)(&disp + gameTrackerX.gameData.asmData.dispPage));
	SetDispMask(1);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ screen_to_vram(long *screen /*$a0*/, int buffer /*$a1*/)
// line 150, offset 0x80037fb4
/* begin block 1 */
// Start line: 302
/* end block 1 */
// End Line: 303

void screen_to_vram(long *screen, int buffer)

{
	LOAD_LoadTIM2(screen, 0, buffer << 8, 0x200, 0x100);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ show_screen(char *name /*$a0*/)
// line 159, offset 0x80037fe4
/* begin block 1 */
// Start line: 160
// Start offset: 0x80037FE4
// Variables:
// 		long *screen; // $s0
/* end block 1 */
// End offset: 0x80038018
// End Line: 167

/* begin block 2 */
// Start line: 324
/* end block 2 */
// End Line: 325

void show_screen(char *name)

{
	long *screen;

	screen = LOAD_ReadFile(name, '\v');
	if (screen != (long *)0x0)
	{
		screen_to_vram(screen, gameTrackerX.gameData.asmData.dispPage);
		MEMPACK_Free((char *)screen);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ play_movie(char *name /*$s0*/)
// line 214, offset 0x80038028
/* begin block 1 */
// Start line: 435
/* end block 1 */
// End Line: 436

void play_movie(char *name)

{
	int iVar1;

	iVar1 = CINE_Load();
	if (iVar1 != 0)
	{
		CINE_Play(name, 0xffff, 2);
		ClearDisplay();
		CINE_Unload();
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ InitMainTracker(struct MainTracker *mainTracker /*$a0*/)
// line 236, offset 0x80038070
/* begin block 1 */
// Start line: 479
/* end block 1 */
// End Line: 480

/* begin block 2 */
// Start line: 480
/* end block 2 */
// End Line: 481

void InitMainTracker(MainTracker *mainTracker)

{
	mainTracker->mainState = 0;
	mainTracker->previousState = 0;
	mainTracker->done = 0;
	return;
}

// decompiled code
// original method signature:
// char * /*$ra*/ FindTextInLine(char *search_match /*$a0*/, char *search_str /*$a1*/)
// line 243, offset 0x80038080
/* begin block 1 */
// Start line: 245
// Start offset: 0x80038080
// Variables:
// 		char *match_pos; // $a2
/* end block 1 */
// End offset: 0x800380F8
// End Line: 259

/* begin block 2 */
// Start line: 493
/* end block 2 */
// End Line: 494

/* begin block 3 */
// Start line: 494
/* end block 3 */
// End Line: 495

/* begin block 4 */
// Start line: 496
/* end block 4 */
// End Line: 497

char *FindTextInLine(char *search_match, char *search_str)

{
	byte bVar1;
	byte *pbVar2;
	byte *pbVar3;

	bVar1 = *search_str;
	if ((bVar1 != 0) && (pbVar2 = (byte *)search_match, bVar1 != 10))
	{
		while (bVar1 != 0xd)
		{
			search_str = (char *)((byte *)search_str + 1);
			pbVar3 = (byte *)search_match;
			if ((bVar1 | 0x20) == (*pbVar2 | 0x20))
			{
				pbVar3 = pbVar2 + 1;
			}
			if (*pbVar3 == 0)
			{
				return (char *)(byte *)search_str;
			}
			bVar1 = *search_str;
			if (bVar1 == 0)
			{
				return (char *)0x0;
			}
			pbVar2 = pbVar3;
			if (bVar1 == 10)
			{
				return (char *)0x0;
			}
		}
	}
	return (char *)0x0;
}

// decompiled code
// original method signature:
// void /*$ra*/ ExtractWorldName(char *worldName /*$a0*/, char *levelName /*$a1*/)
// line 261, offset 0x80038108
/* begin block 1 */
// Start line: 529
/* end block 1 */
// End Line: 530

/* begin block 2 */
// Start line: 530
/* end block 2 */
// End Line: 531

void ExtractWorldName(char *worldName, char *levelName)

{
	byte bVar1;

	bVar1 = *levelName;
	while ((bVar1 != 0x2d && (((uint)bVar1 - 0x41 < 0x1a || ((uint)bVar1 - 0x61 < 0x1a)))))
	{
		levelName = (char *)((byte *)levelName + 1);
		*worldName = bVar1;
		bVar1 = *levelName;
		worldName = (char *)((byte *)worldName + 1);
	}
	*worldName = 0;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ ExtractLevelNum(char *levelNum /*$a0*/, char *levelName /*$a1*/)
// line 270, offset 0x80038154
/* begin block 1 */
// Start line: 547
/* end block 1 */
// End Line: 548

/* begin block 2 */
// Start line: 548
/* end block 2 */
// End Line: 549

void ExtractLevelNum(char *levelNum, char *levelName)

{
	byte bVar1;

	bVar1 = *levelName;
	while (bVar1 != 0x2d)
	{
		if ((uint)bVar1 - 0x30 < 10)
			goto LAB_80038194;
		levelName = (char *)((byte *)levelName + 1);
		bVar1 = *levelName;
	}
	bVar1 = *levelName;
	while ((uint)bVar1 - 0x30 < 10)
	{
	LAB_80038194:
		bVar1 = *levelName;
		levelName = (char *)((byte *)levelName + 1);
		*levelNum = bVar1;
		bVar1 = *levelName;
		levelNum = (char *)((byte *)levelNum + 1);
	}
	*levelNum = 0;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ ProcessArgs(char *baseAreaName /*$s3*/, struct GameTracker *gameTracker /*$s2*/)
// line 368, offset 0x800381c0
/* begin block 1 */
// Start line: 369
// Start offset: 0x800381C0
// Variables:
// 		char levelNum[32]; // stack offset -88
// 		char worldName[32]; // stack offset -56
// 		long *argData; // $s1
/* end block 1 */
// End offset: 0x800383BC
// End Line: 586

/* begin block 2 */
// Start line: 736
/* end block 2 */
// End Line: 737

void ProcessArgs(char *baseAreaName, GameTracker *gameTracker)

{
	char cVar1;
	char cVar2;
	long *levelName;
	char *pcVar3;
	char acStack88[32];
	char acStack56[32];

	levelName = LOAD_ReadFile(s__kain2_game_psx_kain2_arg_800ce6d4, '\n');
	cVar2 = s_under1_800ce760[5];
	cVar1 = s_under1_800ce760[4];
	if (levelName == (long *)0x0)
	{
		*(undefined4 *)baseAreaName = s_under1_800ce760._0_4_;
		baseAreaName[4] = cVar1;
		baseAreaName[5] = cVar2;
		baseAreaName[6] = s_under1_800ce760[6];
	}
	else
	{
		ExtractWorldName(acStack56, (char *)levelName);
		ExtractLevelNum(acStack88, (char *)levelName);
		sprintf(baseAreaName, &DAT_800ce6f0);
		pcVar3 = FindTextInLine(s__NOSOUND_800ce6f8, (char *)levelName);
		if (pcVar3 != (char *)0x0)
		{
			nosound = 1;
			nomusic = 1;
		}
		pcVar3 = FindTextInLine(s__NOMUSIC_800ce704, (char *)levelName);
		if (pcVar3 != (char *)0x0)
		{
			nomusic = 1;
		}
		pcVar3 = FindTextInLine(s__TIMEOUT_800ce710, (char *)levelName);
		if (pcVar3 != (char *)0x0)
		{
			gameTracker->debugFlags = gameTracker->debugFlags | 0x20000;
		}
		pcVar3 = FindTextInLine(s__MAINMENU_800ce71c, (char *)levelName);
		if (pcVar3 != (char *)0x0)
		{
			DoMainMenu = 1;
		}
		pcVar3 = FindTextInLine(s__INSPECTRAL_800ce728, (char *)levelName);
		if (pcVar3 != (char *)0x0)
		{
			gameTrackerX.gameData.asmData.MorphType = 1;
		}
		pcVar3 = FindTextInLine(s__VOICE_800ce734, (char *)levelName);
		if (pcVar3 != (char *)0x0)
		{
			gameTracker->debugFlags = gameTracker->debugFlags | 0x80000;
		}
		pcVar3 = FindTextInLine(s__DEBUG_CD_800ce73c, (char *)levelName);
		if (pcVar3 != (char *)0x0)
		{
			gameTracker->debugFlags = gameTracker->debugFlags | 0x80000000;
		}
		pcVar3 = FindTextInLine(s__LOADGAME_800ce748, (char *)levelName);
		if (pcVar3 != (char *)0x0)
		{
			gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x200000;
		}
		pcVar3 = FindTextInLine(s__ALLWARP_800ce754, (char *)levelName);
		if (pcVar3 != (char *)0x0)
		{
			gameTrackerX.streamFlags = gameTrackerX.streamFlags | 0x400000;
		}
		gameTracker->debugFlags = gameTracker->debugFlags | 0x80000;
		MEMPACK_Free((char *)levelName);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ InitDisplay()
// line 588, offset 0x800383d8
/* begin block 1 */
// Start line: 589
// Start offset: 0x800383D8
// Variables:
// 		int i; // $a1
// 		struct RECT r; // stack offset -16
/* end block 1 */
// End offset: 0x80038510
// End Line: 650

/* begin block 2 */
// Start line: 1134
/* end block 2 */
// End Line: 1135

/* WARNING: Unknown calling convention yet parameter storage is locked */

void InitDisplay(void)

{
	BLK_FILL *pBVar1;
	int iVar2;
	undefined4 local_10;
	undefined4 local_c;

	local_10 = DAT_800ce768;
	local_c = DAT_800ce76c;
	ResetGraph(3);
	SetGraphDebug(0);
	SetDefDrawEnv((undefined2 *)&draw, 0, 0, 0x200, 0xf0);
	SetDefDispEnv((undefined2 *)&disp, 0, 0, 0x200, 0xf0);
	SetDefDrawEnv((undefined2 *)&DRAWENV_800d0ec8, 0, 0x100, 0x200, 0xf0);
	SetDefDispEnv((undefined2 *)&DISPENV_800d0e54, 0, 0x100, 0x200, 0xf0);
	iVar2 = 0;
	pBVar1 = &clearRect;
	/* WARNING: Read-only address (ram,0x800d0ede) is written */
	DRAWENV_800d0ec8.dtd = '\x01';
	/* WARNING: Read-only address (ram,0x800d0e82) is written */
	draw.dtd = '\x01';
	/* WARNING: Read-only address (ram,0x800d0edf) is written */
	DRAWENV_800d0ec8.dfe = '\x01';
	/* WARNING: Read-only address (ram,0x800d0e83) is written */
	draw.dfe = '\x01';
	/* WARNING: Read-only address (ram,0x800d0ee0) is written */
	DRAWENV_800d0ec8.isbg = '\0';
	/* WARNING: Read-only address (ram,0x800d0e84) is written */
	draw.isbg = '\0';
	/* WARNING: Read-only address (ram,0x800d0e85) is written */
	draw.r0 = '\0';
	/* WARNING: Read-only address (ram,0x800d0e86) is written */
	draw.g0 = '\0';
	/* WARNING: Read-only address (ram,0x800d0e87) is written */
	draw.b0 = '\0';
	/* WARNING: Read-only address (ram,0x800d0ee1) is written */
	DRAWENV_800d0ec8.r0 = '\0';
	/* WARNING: Read-only address (ram,0x800d0ee2) is written */
	DRAWENV_800d0ec8.g0 = '\0';
	/* WARNING: Read-only address (ram,0x800d0ee3) is written */
	DRAWENV_800d0ec8.b0 = '\0';
	do
	{
		*(undefined *)((int)&pBVar1->tag + 3) = 3;
		pBVar1->code = '\x02';
		pBVar1->x0 = 0;
		pBVar1->y0 = (ushort)(iVar2 << 8);
		pBVar1->w = 0x200;
		pBVar1->h = 0xf0;
		pBVar1->r0 = '\0';
		pBVar1->g0 = '\0';
		pBVar1->b0 = '\0';
		iVar2 = iVar2 + 1;
		pBVar1 = pBVar1 + 1;
	} while (iVar2 < 2);
	ClearDisplay();
	ClearOTagR(gameTrackerX.drawOT, 0xc00);
	ClearOTagR(gameTrackerX.dispOT, 0xc00);
	ClearImage((short *)&local_10, 0, 0xff, 0);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ StartTimer()
// line 666, offset 0x80038554
/* begin block 1 */
// Start line: 1326
/* end block 1 */
// End Line: 1327

/* WARNING: Unknown calling convention yet parameter storage is locked */

void StartTimer(void)

{
	EnterCriticalSection();
	__timerEvent = OpenEvent();
	EnableEvent();
	SetRCnt(0xf2000000, 0xffff, (uint)&DAT_00001001);
	StartRCnt(0xf2000000);
	ExitCriticalSection();
	gTimerEnabled = 1;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VblTick()
// line 739, offset 0x800385c0
/* begin block 1 */
// Start line: 1473
/* end block 1 */
// End Line: 1474

/* begin block 2 */
// Start line: 1476
/* end block 2 */
// End Line: 1477

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VblTick(void)

{
	if (devstation != 0)
	{
		trap(0x400);
	}
	gameTrackerX.vblFrames = gameTrackerX.vblFrames + 1;
	gameTrackerX.vblCount = gameTrackerX.vblCount + 1;
	if ((gameTrackerX.reqDisp != (void *)0x0) &&
		((uint)gameTrackerX.frameRateLock < gameTrackerX.vblFrames))
	{
		PutDispEnv((ushort *)gameTrackerX.reqDisp);
		gameTrackerX.reqDisp = (void *)0x0;
		gameTrackerX.vblFrames = 0;
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ DrawCallback()
// line 759, offset 0x8003862c
/* begin block 1 */
// Start line: 1520
/* end block 1 */
// End Line: 1521

/* begin block 2 */
// Start line: 1521
/* end block 2 */
// End Line: 1522

/* WARNING: Unknown calling convention yet parameter storage is locked */

void DrawCallback(void)

{
	ulong uVar1;

	if (gameTrackerX.drawTimerReturn != (long *)0x0)
	{
		uVar1 = TIMER_TimeDiff(gameTrackerX.usecsStartDraw);
		*gameTrackerX.drawTimerReturn = uVar1;
		gameTrackerX.drawTimerReturn = (long *)0x0;
		gameTrackerX.reqDisp =
			(void *)((int)gameTrackerX.disp + gameTrackerX.gameData.asmData.dispPage * 0x14);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ FadeOutSayingLoading(struct GameTracker *gameTracker /*$s1*/)
// line 770, offset 0x80038684
/* begin block 1 */
// Start line: 771
// Start offset: 0x80038684
// Variables:
// 		struct POLY_F4_SEMITRANS *transPrim; // $s2
// 		unsigned long **drawot; // $s3
// 		long fadeTime; // $s0
/* end block 1 */
// End offset: 0x800387B4
// End Line: 804

/* begin block 2 */
// Start line: 1544
/* end block 2 */
// End Line: 1545

void FadeOutSayingLoading(GameTracker *gameTracker)

{
	bool bVar1;
	int iVar2;
	undefined uVar3;
	int iVar4;
	ulong *puVar5;
	ulong **ot;

	ot = gameTracker->drawOT;
	puVar5 = gameTracker->primPool->nextPrim;
	DRAW_TranslucentQuad(0, 0, 0x200, 0, 0, 0xf0, 0x200, 0xf0, 0, 0, 0, 2, gameTracker->primPool, ot);
	iVar4 = 0x10;
	FONT_Flush();
	do
	{
		if (0xff < iVar4)
		{
			iVar4 = 0xff;
		}
		gameTracker->drawPage = 1 - gameTracker->drawPage;
		uVar3 = (undefined)iVar4;
		*(undefined *)(puVar5 + 2) = uVar3;
		*(undefined *)((int)puVar5 + 9) = uVar3;
		*(undefined *)((int)puVar5 + 10) = uVar3;
		do
		{
			iVar2 = CheckVolatile(gameTracker->drawTimerReturn);
		} while (iVar2 != 0);
		PutDrawEnv((undefined4 *)(&draw + gameTracker->drawPage));
		do
		{
			iVar2 = CheckVolatile(gameTracker->reqDisp);
		} while (iVar2 != 0);
		iVar2 = (gameTracker->gameData).asmData.dispPage;
		*(ulong **)&gameTracker->drawTimerReturn = &gameTracker->drawTime;
		(gameTracker->gameData).asmData.dispPage = 1 - iVar2;
		VSync(0);
		DrawOTag(ot + 0xbff);
		bVar1 = iVar4 != 0xff;
		iVar4 = iVar4 + 0x10;
	} while (bVar1);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ CheckForDevStation()
// line 806, offset 0x800387d4
/* begin block 1 */
// Start line: 807
// Start offset: 0x800387D4
// Variables:
// 		long *a1; // stack offset -8
// 		long *a2; // stack offset -4
/* end block 1 */
// End offset: 0x8003882C
// End Line: 832

/* begin block 2 */
// Start line: 1638
/* end block 2 */
// End Line: 1639

/* WARNING: Removing unreachable block (ram,0x8003881c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void CheckForDevStation(void)

{
	devstation = 1;
	DAT_80180000 = 0;
	_DAT_80380000 = 0x12345678;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MAIN_ShowLoadingScreen()
// line 834, offset 0x80038834
/* begin block 1 */
// Start line: 835
// Start offset: 0x80038834
// Variables:
// 		long *loadingScreen; // $s0
// 		char langChar[5]; // stack offset -88
// 		int lang; // $v0

/* begin block 1.1 */
// Start line: 856
// Start offset: 0x8003887C
// Variables:
// 		char filename[64]; // stack offset -80
/* end block 1.1 */
// End offset: 0x8003887C
// End Line: 857
/* end block 1 */
// End offset: 0x800388D0
// End Line: 877

/* begin block 2 */
// Start line: 1695
/* end block 2 */
// End Line: 1696

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_ShowLoadingScreen(void)

{
	language_t lVar1;
	long *screen;
	char *string;
	char acStack80[64];

	VSync(0);
	lVar1 = localstr_get_language();
	if (lVar1 == language_english)
	{
		string = s__kain2_game_psx_loading_tim_800ce798;
	}
	else
	{
		string = acStack80;
		sprintf(string, s__kain2_game_psx_loading_c_tim_800ce778);
	}
	screen = LOAD_ReadFile(string, '\v');
	if (screen != (long *)0x0)
	{
		screen_to_vram(screen, gameTrackerX.gameData.asmData.dispPage);
		MEMPACK_Free((char *)screen);
	}
	return;
}

// decompiled code
// original method signature:
// long * /*$ra*/ MAIN_LoadTim(char *name /*$a0*/)
// line 879, offset 0x800388e4
/* begin block 1 */
// Start line: 880
// Start offset: 0x800388E4
/* end block 1 */
// End offset: 0x800388E4
// End Line: 880

/* begin block 2 */
// Start line: 1804
/* end block 2 */
// End Line: 1805

long *MAIN_LoadTim(char *name)

{
	long *plVar1;

	plVar1 = LOAD_ReadFile(name, '\v');
	return plVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ init_menus(struct GameTracker *gt /*$s1*/)
// line 890, offset 0x80038904
/* begin block 1 */
// Start line: 891
// Start offset: 0x80038904
// Variables:
// 		struct menu_t *menu; // $s0
/* end block 1 */
// End offset: 0x80038904
// End Line: 891

/* begin block 2 */
// Start line: 1826
/* end block 2 */
// End Line: 1827

void init_menus(GameTracker *gt)

{
	ulong allocSize;
	menu_t *menu;

	allocSize = menu_data_size();
	menu = (menu_t *)MEMPACK_Malloc(allocSize, '-');
	menu_initialize(menu, gt);
	gt->menu = menu;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MAIN_DoMainInit()
// line 902, offset 0x80038950
/* begin block 1 */
// Start line: 1850
/* end block 1 */
// End Line: 1851

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_DoMainInit(void)

{
	InitDisplay();
	InitGeom();
	SetGeomOffset(0x100, 0x78);
	SetGeomScreen(0x140);
	VRAM_InitVramBlockCache();
	FONT_Init();
	gameTrackerX.reqDisp = (void *)0x0;
	VSyncCallback(VblTick);
	DrawSyncCallback(DrawCallback);
	GAMEPAD_Init();
	SOUND_Init();
	VOICEXA_Init();
	if (nosound != 0)
	{
		SOUND_SfxOff();
		gameTrackerX.sound.gSfxOn = '\0';
		gameTrackerX.sound.gVoiceOn = '\0';
	}
	if (nomusic != 0)
	{
		SOUND_MusicOff();
		gameTrackerX.sound.gMusicOn = '\0';
	}
	if ((gameTrackerX.debugFlags & 0x80000U) == 0)
	{
		gameTrackerX.sound.gVoiceOn = '\0';
	}
	init_menus(&gameTrackerX);
	SAVE_Init(&gameTrackerX);
	srand(0);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MAIN_InitVolume()
// line 949, offset 0x80038a44
/* begin block 1 */
// Start line: 1898
/* end block 1 */
// End Line: 1899

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_InitVolume(void)

{
	aadInitVolume();
	aadStartMasterVolumeFade(gameTrackerX.sound.gMasterVol, 0x100,
							 (TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback)0x0);
	gameTrackerX.sound.soundsLoaded = '\x01';
	aadSetNoUpdateMode(0);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MAIN_ResetGame()
// line 957, offset 0x80038a84
/* begin block 1 */
// Start line: 1944
/* end block 1 */
// End Line: 1945

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_ResetGame(void)

{
	GAMELOOP_SetScreenWipe(0, 0, -1);
	gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xffffff6e;
	RAZIEL_StartNewGame();
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MAIN_MainMenuInit()
// line 967, offset 0x80038ad4
/* begin block 1 */
// Start line: 968
// Start offset: 0x80038AD4

/* begin block 1.1 */
// Start line: 968
// Start offset: 0x80038AD4
// Variables:
// 		char sfxFileName[64]; // stack offset -72
/* end block 1.1 */
// End offset: 0x80038C18
// End Line: 990
/* end block 1 */
// End offset: 0x80038C18
// End Line: 995

/* begin block 2 */
// Start line: 1965
/* end block 2 */
// End Line: 1966

/* WARNING: Removing unreachable block (ram,0x80038b18) */
/* WARNING: Removing unreachable block (ram,0x80038b1c) */
/* WARNING: Removing unreachable block (ram,0x80038b68) */
/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_MainMenuInit(void)

{
	undefined4 *puVar1;
	undefined4 *puVar2;
	long lVar3;
	int iVar4;
	undefined4 *puVar5;
	undefined4 *puVar6;
	undefined4 uVar7;
	undefined4 uVar8;
	undefined4 uVar9;
	undefined4 local_48[10];
	undefined auStack32[24];

	mainMenuMode = 0;
	mainMenuTimeOut = 0;
	/* WARNING: Read-only address (ram,0x800d0f8c) is written */
	clearRect.r0 = '\0';
	/* WARNING: Read-only address (ram,0x800d0f8d) is written */
	clearRect.g0 = '\0';
	/* WARNING: Read-only address (ram,0x800d0f8e) is written */
	clearRect.b0 = '\0';
	/* WARNING: Read-only address (ram,0x800d0f9c) is written */
	BLK_FILL_800d0f98.r0 = '\0';
	/* WARNING: Read-only address (ram,0x800d0f9d) is written */
	BLK_FILL_800d0f98.g0 = '\0';
	/* WARNING: Read-only address (ram,0x800d0f9e) is written */
	BLK_FILL_800d0f98.b0 = '\0';
	puVar1 = (undefined4 *)s__kain2_sfx_object_mainmenu_mainm_800ce7d0;
	puVar2 = local_48;
	do
	{
		puVar6 = puVar2;
		puVar5 = puVar1;
		uVar7 = puVar5[1];
		uVar8 = puVar5[2];
		uVar9 = puVar5[3];
		*puVar6 = *puVar5;
		puVar6[1] = uVar7;
		puVar6[2] = uVar8;
		puVar6[3] = uVar9;
		puVar1 = puVar5 + 4;
		puVar2 = puVar6 + 4;
	} while (puVar5 + 4 != (undefined4 *)(s__kain2_sfx_object_mainmenu_mainm_800ce7d0 + 0x20));
	uVar7 = puVar5[5];
	puVar6[4] = s__kain2_sfx_object_mainmenu_mainm_800ce7d0._32_4_;
	puVar6[5] = uVar7;
	memset(auStack32, 0, 0x18);
	mainMenuSfx = 0;
	lVar3 = LOAD_DoesFileExist((char *)local_48);
	if (lVar3 != 0)
	{
		mainMenuSfx = aadLoadDynamicSfx(s_mainmenu_800ce7f8, 0, 0);
		while (iVar4 = aadGetNumLoadsQueued(), iVar4 != 0)
		{
			aadProcessLoadQueue();
		}
	}
	mainMenuScreen = MAIN_LoadTim(s__kain2_game_psx_frontend_title1__800ce804);
	VRAM_EnableTerrainArea();
	menuface_initialize();
	currentMenu = &mainMenu;
	gameTrackerX.gameMode = 4;
	menu_set(gameTrackerX.menu, menudefs_main_menu);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MAIN_FreeMainMenuStuff()
// line 1009, offset 0x80038c6c
/* begin block 1 */
// Start line: 2066
/* end block 1 */
// End Line: 2067

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_FreeMainMenuStuff(void)

{
	int iVar1;

	menuface_terminate();
	VRAM_DisableTerrainArea();
	if (mainMenuScreen != (long *)0x0)
	{
		MEMPACK_Free((char *)mainMenuScreen);
		mainMenuScreen = (long *)0x0;
	}
	aadFreeDynamicSfx(mainMenuSfx);
	while (iVar1 = aadGetNumLoadsQueued(), iVar1 != 0)
	{
		aadProcessLoadQueue();
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MAIN_StartGame()
// line 1044, offset 0x80038cdc
/* begin block 1 */
// Start line: 2136
/* end block 1 */
// End Line: 2137

/* begin block 2 */
// Start line: 2137
/* end block 2 */
// End Line: 2138

/* WARNING: Unknown calling convention yet parameter storage is locked */

void MAIN_StartGame(void)

{
	if (mainMenuFading == 0)
	{
		gameTrackerX.gameMode = 0;
		currentMenu = (DebugMenuLine *)0x0;
		mainMenuFading = 1;
		GAMELOOP_SetScreenWipe(-0x1e, 0x1e, 10);
	}
	else
	{
		mainTrackerX.mainState = 2;
		MAIN_FreeMainMenuStuff();
		gEndGameNow = 0;
		mainMenuFading = 0;
		currentMenu = &standardMenu;
	}
	return;
}

// decompiled code
// original method signature:
// long /*$ra*/ MAIN_DoMainMenu(struct GameTracker *gameTracker /*$s0*/, struct MainTracker *mainTracker /*$a1*/, long menuPos /*$a2*/)
// line 1083, offset 0x80038d48
/* begin block 1 */
// Start line: 1084
// Start offset: 0x80038D48
// Variables:
// 		unsigned long **drawot; // $s1
/* end block 1 */
// End offset: 0x80038E04
// End Line: 1172

/* begin block 2 */
// Start line: 2220
/* end block 2 */
// End Line: 2221

long MAIN_DoMainMenu(GameTracker *gameTracker, MainTracker *mainTracker, long menuPos)

{
	ulong **drawot;

	gameTrackerX.timeMult = 0x1000;
	drawot = gameTracker->drawOT;
	DrawPrim((int)(&clearRect + gameTracker->drawPage));
	GAMEPAD_Process(gameTracker);
	DEBUG_Process(gameTracker);
	if (mainMenuScreen != (long *)0x0)
	{
		screen_to_vram(mainMenuScreen, gameTracker->drawPage);
	}
	GAMELOOP_HandleScreenWipes(drawot);
	MENUFACE_RefreshFaces();
	FONT_Flush();
	mainMenuTimeOut = mainMenuTimeOut + 1;
	GAMELOOP_FlipScreenAndDraw(gameTracker, drawot);
	if ((mainMenuFading != 0) && (gameTracker->wipeTime == -1))
	{
		MAIN_StartGame();
	}
	return 0;
}

// decompiled code
// original method signature:
// int /*$ra*/ MainG2(void *appData /*$s7*/)
// line 1187, offset 0x80038e1c
/* begin block 1 */
// Start line: 1188
// Start offset: 0x80038E1C
// Variables:
// 		struct MainTracker *mainTracker; // $s2
// 		struct GameTracker *gameTracker; // $s3
// 		long menuPos; // $s5
// Labels:
//		0x00001718	exit

/* begin block 1.1 */
// Start line: 1381
// Start offset: 0x80039038
// Variables:
// 		struct InterfaceItem *item; // $s1
// 		int timer; // $s0
/* end block 1.1 */
// End offset: 0x800390E8
// End Line: 1445

/* begin block 1.2 */
// Start line: 1625
// Start offset: 0x800392A4
/* end block 1.2 */
// End offset: 0x80039390
// End Line: 1695
/* end block 1 */
// End offset: 0x80039440
// End Line: 1746

/* begin block 2 */
// Start line: 2374
/* end block 2 */
// End Line: 2375

int MainG2(void *appData)

{
	bool bVar1;
	long lVar2;
	_G2Bool_Enum _Var3;
	int iVar4;
	long menuPos;

	menuPos = 0;
	CheckForDevStation();
	mainOptionsInit = '\0';
	_Var3 = MainG2_InitEngine(appData, 0x200, 0xf0, (char *)0x0);
	if (_Var3 != G2FALSE)
	{
		MEMPACK_Init();
		LOAD_InitCd();
		StartTimer();
		STREAM_InitLoader(s__BIGFILE_DAT_1_800ce850, &DAT_800ce860);
		localstr_set_language(~language_english);
		GAMELOOP_SystemInit(&gameTrackerX);
		gameTrackerX.lastLvl = -1;
		gameTrackerX.currentLvl = -1;
		gameTrackerX.disp = &disp;
		ProcessArgs(gameTrackerX.baseAreaName, &gameTrackerX);
		InitMainTracker(&mainTrackerX);
		MAIN_DoMainInit();
		mainTrackerX.mainState = 6;
		mainTrackerX.movieNum = 0;
		do
		{
			mainTrackerX.previousState = mainTrackerX.mainState;
			switch (mainTrackerX.mainState)
			{
			case 1:
				SOUND_UpdateSound();
				if ((gameTrackerX.debugFlags & 0x80000U) != 0)
				{
					VOICEXA_Tick();
				}
				PSX_GameLoop(&gameTrackerX);
				if (gameTrackerX.levelDone != 0)
				{
					FadeOutSayingLoading(&gameTrackerX);
					aadStopAllSfx();
					STREAM_DumpAllLevels(0, 0);
					RemoveAllObjects(&gameTrackerX);
					while ((iVar4 = aadGetNumLoadsQueued(), iVar4 != 0 ||
																((aadMem->sramDefragInfo).status != 0)))
					{
						SOUND_UpdateSound();
						STREAM_PollLoadQueue();
					}
					SOUND_ShutdownMusic();
					MEMPACK_FreeByType('\x0e');
					GAMELOOP_ResetGameStates();
					MEMPACK_DoGarbageCollection();
					iVar4 = (int)gameTrackerX.levelDone;
					if (iVar4 == 2)
					{
					LAB_8003933c:
						mainTrackerX.mainState = 8;
					}
					else
					{
						if (iVar4 == 3)
						{
							mainTrackerX.mainState = 6;
							mainTrackerX.movieNum = iVar4;
						}
						else
						{
							if (iVar4 == 4)
							{
								mainTrackerX.mainState = 2;
								if ((gameTrackerX.streamFlags & 0x200000U) == 0)
								{
									SAVE_ClearMemory(&gameTrackerX);
								}
							}
							else
							{
								mainTrackerX.mainState = 2;
							}
						}
					}
				}
				break;
			case 2:
				if ((gameTrackerX.streamFlags & 0x1000000U) != 0)
				{
					play_movie((char *)&InterfaceItem_800ce5e0);
					gameTrackerX.streamFlags = gameTrackerX.streamFlags & 0xfeffffff;
				}
				if ((gameTrackerX.streamFlags & 0x200000U) != 0)
				{
					gameTrackerX.streamFlags = gameTrackerX.streamFlags & 0xffdfffff;
				}
				if (nosound == 0)
				{
					MAIN_InitVolume();
				}
				MAIN_ShowLoadingScreen();
				FONT_ReloadFont();
				DrawSync(0);
				gameTrackerX.frameCount = 0;
				STREAM_Init();
				GAMELOOP_LevelLoadAndInit(gameTrackerX.baseAreaName, &gameTrackerX);
				gameTrackerX.levelDone = 0;
				mainTrackerX.mainState = 1;
				do
				{
					iVar4 = STREAM_PollLoadQueue();
				} while (iVar4 != 0);
				gameTrackerX.vblFrames = 0;
				break;
			case 4:
				LOAD_ChangeDirectory(s_Menustuff_800ce864);
				do
				{
					lVar2 = mainTrackerX.movieNum;
					if (5 < (uint)mainTrackerX.movieNum)
						goto LAB_800390f0;
					gameTrackerX.gameFlags = gameTrackerX.gameFlags & 0xfffffffe;
					show_screen((char *)(&InterfaceItems + mainTrackerX.movieNum));
					iVar4 = 1;
					if ((&InterfaceItems)[lVar2].timeout != 0)
					{
						do
						{
							GAMEPAD_Process(&gameTrackerX);
							if (((int)(uint)(&InterfaceItems)[lVar2].buttonTimeout < iVar4) &&
								((gameTrackerX.controlCommand[0][1] & 0x80U) != 0))
								break;
							VSync(0);
							bVar1 = iVar4 < (int)(uint)(&InterfaceItems)[lVar2].timeout;
							iVar4 = iVar4 + 1;
						} while (bVar1);
					}
					mainTrackerX.movieNum = (long)(&InterfaceItems)[lVar2].nextItem;
				} while ((mainTrackerX.movieNum < 0) ||
						 ((&InterfaceItems)[mainTrackerX.movieNum].itemType == 1));
				mainTrackerX.mainState = 6;
			LAB_800390f0:
				FONT_ReloadFont();
				if (mainTrackerX.mainState != 6)
				{
					if (DoMainMenu != 0)
						goto LAB_8003933c;
					MAIN_ResetGame();
					gameTrackerX.gameMode = 0;
					mainMenuFading = 1;
					MAIN_StartGame();
				}
				break;
			case 6:
				CINE_Load();
				do
				{
					if (mainTrackerX.movieNum < 0)
						goto LAB_80038fd0;
					iVar4 = CINE_Loaded();
					if (iVar4 != 0)
					{
						CINE_Play((char *)(&InterfaceItems + mainTrackerX.movieNum), 0xffff, 2);
						ClearDisplay();
					}
					mainTrackerX.movieNum = (long)(&InterfaceItems)[mainTrackerX.movieNum].nextItem;
				} while ((&InterfaceItems)[mainTrackerX.movieNum].itemType == 0);
				mainTrackerX.mainState = 4;
			LAB_80038fd0:
				CINE_Unload();
				if (mainTrackerX.movieNum < 0)
				{
					mainTrackerX.mainState = 8;
				}
				if (nosound == 0)
				{
					SOUND_StopAllSound();
				}
				break;
			case 7:
				mainTrackerX.done = 1;
				break;
			case 8:
				gameTrackerX.gameData.asmData.MorphType = 0;
				ProcessArgs(gameTrackerX.baseAreaName, &gameTrackerX);
				MAIN_ResetGame();
				LOAD_ChangeDirectory(s_Menustuff_800ce864);
				MAIN_MainMenuInit();
				MAIN_InitVolume();
				SAVE_ClearMemory(&gameTrackerX);
				mainTrackerX.mainState = 9;
				FONT_ReloadFont();
				break;
			case 9:
				menuPos = MAIN_DoMainMenu(&gameTrackerX, &mainTrackerX, menuPos);
			}
			STREAM_PollLoadQueue();
		} while (mainTrackerX.done == 0);
		SOUND_StopAllSound();
		SOUND_Free();
		SetDispMask(0);
		DrawSync(0);
		VSync(0);
		DrawSyncCallback(0);
		VSyncCallback(0);
		EnterCriticalSection();
		StopRCnt(0xf2000000);
		DisableEvent();
		CloseEvent();
		ExitCriticalSection();
		VSync(5);
		StopCallback();
		PadStopCom();
		ResetGraph(3);
	}
	MainG2_ShutDownEngine(appData);
	return 0;
}
