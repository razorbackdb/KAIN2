#ifndef KAIN2_MONOLITHIC_HEADER
#define KAIN2_MONOLITHIC_HEADER

/* Begin enums */

enum _G2Bool_Enum // Hashcode: 0x6B6BC2D2 (dec: 1802224338)
{
	G2FALSE = 0,
};

enum DEBUG_LINE_TYPE // Hashcode: 0x48268EA1 (dec: 1210486433)
{
	DEBUG_LINE_TYPE_BIT = 0,
	DEBUG_LINE_TYPE_LONG = 1,
	DEBUG_LINE_TYPE_ACTION = 2,
	DEBUG_LINE_TYPE_ACTION_WITH_LINE = 3,
	DEBUG_LINE_TYPE_MENU = 4,
	DEBUG_LINE_TYPE_ENDLIST = 5,
	DEBUG_LINE_TYPE_FORMAT = 6,
	DEBUG_LINE_TYPE_INFO = 7,
};

enum option_ctrl_t // Hashcode: 0xD9B3C651 (dec: -642529711)
{
	option_ctrl_bogus = 0,
	option_ctrl_none = 1,
	option_ctrl_select = 2,
	option_ctrl_left = 3,
	option_ctrl_right = 4,
	option_ctrl_num_states = 5,
};

enum _G2AnimCallbackMsg_Enum // Hashcode: 0x2CDF3E2D (dec: 752827949)
{
	G2ANIM_MSG_DONE = 1,
	G2ANIM_MSG_LOOPPOINT = 2,
	G2ANIM_MSG_SECTION_INTERPDONE = 3,
	G2ANIM_MSG_SEGCTRLR_INTERPDONE = 4,
	G2ANIM_MSG_SWALARMSET = 5,
	G2ANIM_MSG_PLAYEFFECT = 6,
};

enum MATH3D_AXIS // Hashcode: 0x977BA192 (dec: -1753505390)
{
	AXIS_X = 0,
	AXIS_Y = 1,
	AXIS_Z = 2,
	AXIS_NEG_X = 3,
	AXIS_NEG_Y = 4,
	AXIS_NEG_Z = 5,
};

enum MonsterAnim // Hashcode: 0x83186B1F (dec: -2095551713)
{
	MONSTER_ANIM_HIT1 = 0,
	MONSTER_ANIM_HIT2 = 1,
	MONSTER_ANIM_WALK = 2,
	MONSTER_ANIM_RUN = 3,
	MONSTER_ANIM_GRABBED = 4,
	MONSTER_ANIM_STUNNED = 5,
	MONSTER_ANIM_JUMPFORWARD = 6,
	MONSTER_ANIM_JUMPBACK = 7,
	MONSTER_ANIM_JUMPLEFT = 8,
	MONSTER_ANIM_JUMPRIGHT = 9,
	MONSTER_ANIM_STANCE_HEALTHY = 10,
	MONSTER_ANIM_STANCE_VULNERABLE = 11,
	MONSTER_ANIM_STUNNED_RECOVERY = 12,
	MONSTER_ANIM_IMPALED = 13,
	MONSTER_ANIM_STRUGGLE = 14,
	MONSTER_ANIM_BREAKHOLD = 15,
	MONSTER_ANIM_THROWN = 16,
	MONSTER_ANIM_IMPACT = 17,
	MONSTER_ANIM_LANDONFEET = 18,
	MONSTER_ANIM_FALL = 19,
	MONSTER_ANIM_BREAKFALL = 20,
	MONSTER_ANIM_SPINLAND = 21,
	MONSTER_ANIM_IMPALEDEATH = 22,
	MONSTER_ANIM_GETUP = 23,
	MONSTER_ANIM_GENERALDEATH = 24,
	MONSTER_ANIM_MISSILEIMPALEDEATH = 25,
	MONSTER_ANIM_SURPRISED = 26,
	MONSTER_ANIM_AGONY = 27,
	MONSTER_ANIM_PUPATE = 28,
	MONSTER_ANIM_NOTICE = 29,
	MONSTER_ANIM_SOULSUCK = 30,
	MONSTER_ANIM_IMPALEHORZ = 31,
	MONSTER_ANIM_IMPALEVERT = 32,
	MONSTER_ANIM_SOULOUTGRND = 33,
	MONSTER_ANIM_SOULOUTHORZ = 34,
	MONSTER_ANIM_SOULOUTVERT = 35,
	MONSTER_ANIM_FALLOVER = 36,
	MONSTER_ANIM_EMBRACE = 37,
	MONSTER_ANIM_SHOVE = 38,
	MONSTER_ANIM_FLIPSWITCH = 39,
	MONSTER_ANIM_EVADELEFT = 40,
	MONSTER_ANIM_EVADERIGHT = 41,
	MONSTER_ANIM_ALARM = 42,
	MONSTER_ANIM_DEAF = 43,
	MONSTER_ANIM_BLIND = 44,
	MONSTER_ANIM_SUCKED = 45,
	MONSTER_NUM_ANIMS = 46,
};

enum MonsterState // Hashcode: 0xE3AB5DCC (dec: -475308596)
{
	MONSTER_STATE_BIRTH = 0,
	MONSTER_STATE_PURSUE = 1,
	MONSTER_STATE_IDLE = 2,
	MONSTER_STATE_MISSILEHIT = 3,
	MONSTER_STATE_FALL = 4,
	MONSTER_STATE_WANDER = 5,
	MONSTER_STATE_ATTACK = 6,
	MONSTER_STATE_IMPALEDEATH = 7,
	MONSTER_STATE_HIT = 8,
	MONSTER_STATE_STUNNED = 9,
	MONSTER_STATE_GRABBED = 10,
	MONSTER_STATE_THROWN = 11,
	MONSTER_STATE_IMPACT = 12,
	MONSTER_STATE_COMBAT = 13,
	MONSTER_STATE_BREAKHOLD = 14,
	MONSTER_STATE_LANDONFEET = 15,
	MONSTER_STATE_GENERALDEATH = 16,
	MONSTER_STATE_ENVIRONMENTDAMAGE = 17,
	MONSTER_STATE_LANDINWATER = 18,
	MONSTER_STATE_FLEE = 19,
	MONSTER_STATE_HIDE = 20,
	MONSTER_STATE_SURPRISEATTACK = 21,
	MONSTER_STATE_PARRY = 22,
	MONSTER_STATE_DEAD = 23,
	MONSTER_STATE_SURPRISED = 24,
	MONSTER_STATE_NOTICE = 25,
	MONSTER_STATE_PUPATE = 26,
	MONSTER_STATE_EMBRACE = 27,
	MONSTER_STATE_PROJECTILE = 28,
	MONSTER_STATE_TERRAINIMPALEDEATH = 29,
	MONSTER_STATE_PETRIFIED = 30,
	MONSTER_NUM_STATES = 31,
};

enum language_t // Hashcode: 0x27BB4D8F (dec: 666586511)
{
	language_default = -1,
	language_english = 0,
	language_french = 1,
	language_german = 2,
	language_italian = 3,
	language_spanish = 4,
	language_num_states = 5,
};

enum localstr_t // Hashcode: 0x72299945 (dec: 1915328837)
{
	LOCALSTR_BOGUS = 0,
	LOCALSTR_format_card = 1,
	LOCALSTR_accessing_card = 2,
	LOCALSTR_back = 3,
	LOCALSTR_cancel = 4,
	LOCALSTR_choose_load_file = 5,
	LOCALSTR_choose_save_file = 6,
	LOCALSTR_confirm = 7,
	LOCALSTR_continue = 8,
	LOCALSTR_controller = 9,
	LOCALSTR_create_file = 10,
	LOCALSTR_creating = 11,
	LOCALSTR_demos = 12,
	LOCALSTR_do_not_remove_card = 13,
	LOCALSTR_done = 14,
	LOCALSTR_exit_game = 15,
	LOCALSTR_formatting = 16,
	LOCALSTR_go_back = 17,
	LOCALSTR_insert_card = 18,
	LOCALSTR_insert_card_free = 19,
	LOCALSTR_invalid_card = 20,
	LOCALSTR_load_failed = 21,
	LOCALSTR_load_game = 22,
	LOCALSTR_loading = 23,
	LOCALSTR_music = 24,
	LOCALSTR_new_game = 25,
	LOCALSTR_no = 26,
	LOCALSTR_no_card = 27,
	LOCALSTR_card_full = 28,
	LOCALSTR_card_not_enough_blocks = 29,
	LOCALSTR_ok = 30,
	LOCALSTR_options = 31,
	LOCALSTR_overwrite_game = 32,
	LOCALSTR_paused = 33,
	LOCALSTR_press_start = 34,
	LOCALSTR_query_format_card = 35,
	LOCALSTR_query_overwrite = 36,
	LOCALSTR_query_quit = 37,
	LOCALSTR_quit_game = 38,
	LOCALSTR_resume_game = 39,
	LOCALSTR_save_failed = 40,
	LOCALSTR_save_game = 41,
	LOCALSTR_save_ok = 42,
	LOCALSTR_saving = 43,
	LOCALSTR_sound = 44,
	LOCALSTR_start_game = 45,
	LOCALSTR_start_new_game = 46,
	LOCALSTR_try_card_again = 47,
	LOCALSTR_unformatted_card = 48,
	LOCALSTR_vibration_off = 49,
	LOCALSTR_vibration_on = 50,
	LOCALSTR_voice = 51,
	LOCALSTR_warning_one = 52,
	LOCALSTR_warning_two = 53,
	LOCALSTR_yes = 54,
	LOCALSTR_Hint0 = 55,
	LOCALSTR_Hint1 = 56,
	LOCALSTR_Hint2 = 57,
	LOCALSTR_Hint3 = 58,
	LOCALSTR_Hint4 = 59,
	LOCALSTR_Hint5 = 60,
	LOCALSTR_Hint6 = 61,
	LOCALSTR_Hint7 = 62,
	LOCALSTR_Hint8 = 63,
	LOCALSTR_Hint9 = 64,
	LOCALSTR_Hint10 = 65,
	LOCALSTR_Hint11 = 66,
	LOCALSTR_Hint12 = 67,
	LOCALSTR_Hint13 = 68,
	LOCALSTR_Hint14 = 69,
	LOCALSTR_Hint15 = 70,
	LOCALSTR_Hint16 = 71,
	LOCALSTR_Hint17 = 72,
	LOCALSTR_Hint18 = 73,
	LOCALSTR_Hint19 = 74,
	LOCALSTR_Hint20 = 75,
	LOCALSTR_Hint21 = 76,
	LOCALSTR_Hint22 = 77,
	LOCALSTR_Hint23 = 78,
	LOCALSTR_Hint24 = 79,
	LOCALSTR_Hint25 = 80,
	LOCALSTR_Hint26 = 81,
	LOCALSTR_Hint27 = 82,
	LOCALSTR_Hint28 = 83,
	LOCALSTR_Hint29 = 84,
	LOCALSTR_Hint30 = 85,
	LOCALSTR_Hint31 = 86,
	LOCALSTR_Hint32 = 87,
	LOCALSTR_Hint33 = 88,
	LOCALSTR_Hint34 = 89,
	LOCALSTR_Hint35 = 90,
	LOCALSTR_Hint36 = 91,
	LOCALSTR_Hint37 = 92,
	LOCALSTR_Hint38 = 93,
	LOCALSTR_Hint39 = 94,
	LOCALSTR_Hint40 = 95,
	LOCALSTR_Hint41 = 96,
	LOCALSTR_Hint42 = 97,
	LOCALSTR_Hint43 = 98,
	LOCALSTR_Hint44 = 99,
	LOCALSTR_Hint45 = 100,
	LOCALSTR_Hint46 = 101,
	LOCALSTR_Hint47 = 102,
	LOCALSTR_Hint48 = 103,
	LOCALSTR_Hint49 = 104,
	LOCALSTR_Hint50 = 105,
	LOCALSTR_Hint51 = 106,
	LOCALSTR_Hint52 = 107,
	LOCALSTR_EndOfHintStrings = 108,
	LOCALSTR_no_controller = 109,
	LOCALSTR_NUM_ITEMS = 110,
};

enum menu_ctrl_t // Hashcode: 0x75DFBC77 (dec: 1977597047)
{
	menu_ctrl_none = 0,
	menu_ctrl_up = 1,
	menu_ctrl_down = 2,
	menu_ctrl_left = 3,
	menu_ctrl_right = 4,
	menu_ctrl_engage = 5,
	menu_ctrl_cancel = 6,
	menu_ctrl_start = 7,
	menu_ctrl_num_items = 8,
};

enum menu_sound_t // Hashcode: 0x54A9956B (dec: 1420399979)
{
	menu_sound_none = 0,
	menu_sound_default = 1,
	menu_sound_select = 2,
	menu_sound_adjust = 3,
	menu_sound_engage = 4,
	menu_sound_pop = 5,
};

enum sfx_t // Hashcode: 0x31566481 (dec: 827745409)
{
	sfx_sound = 0,
	sfx_music = 1,
	sfx_voice = 2,
	sfx_error = 3,
};

enum mcpsx_err_t // Hashcode: 0xC2F69F4D (dec: -1024024755)
{
	mcpsx_err_none = 0,
	mcpsx_err_card_not_exist = 1,
	mcpsx_err_card_invalid = 2,
	mcpsx_err_new_card = 3,
	mcpsx_err_not_format = 4,
	mcpsx_err_file_not_exist = 5,
	mcpsx_err_already_exists = 6,
	mcpsx_err_block_full = 7,
	mcpsx_err_busy = 8,
	mcpsx_err_num_items = 9,
};

enum mcpsx_func_t // Hashcode: 0x77941B5D (dec: 2006195037)
{
	func_none = 0,
	func_exist = 1,
	func_accept = 2,
	func_read_file = 3,
	func_write_file = 4,
	func_create_file = 5,
	func_delete_file = 6,
	func_format = 7,
	func_unformat = 8,
	func_directory = 9,
	func_num_items = 10,
};

enum mcpsx_sync_t // Hashcode: 0x3FD7A182 (dec: 1071096194)
{
	sync_idle = -1,
	sync_busy = 0,
	sync_done = 1,
	sync_func = 2,
	sync_num_items = 3,
};

enum mcpsx_mode_t // Hashcode: 0xD6CC679E (dec: -691247202)
{
	mode_bogus = 0,
	mode_initialized = 1,
	mode_running = 2,
	mode_terminated = 3,
	mode_num_items = 4,
};

enum state_t // Hashcode: 0x02A3BAF4 (dec: 44284660)
{
	fsmcard_card_not_exist = 0,
	fsmcard_card_invalid = 1,
	fsmcard_not_format = 2,
	fsmcard_new_card = 3,
	fsmcard_directory = 4,
	fsmcard_ready = 5,
	fsmcard_format = 6,
	fsmcard_unformat = 7,
	fsmcard_delete = 8,
	fsmcard_create = 9,
	fsmcard_write = 10,
	fsmcard_read = 11,
	fsmcard_error = 12,
	fsmcard_num_items = 13,
};

enum mcard_status_t // Hashcode: 0x4476947B (dec: 1148621947)
{
	mcard_status_card_not_exist = 0,
	mcard_status_card_invalid = 1,
	mcard_status_not_format = 2,
	mcard_status_new_card = 3,
	mcard_status_ready = 4,
	mcard_status_accessing = 5,
	mcard_status_error = 6,
	mcard_status_num_items = 7,
};

enum fsm_t // Hashcode: 0x4CB15FCA (dec: 1286692810)
{
	fsm_card_not_exist = 0,
	fsm_card_invalid = 1,
	fsm_not_format = 2,
	fsm_new_card = 3,
	fsm_ready = 4,
	fsm_format = 5,
	fsm_start = 6,
	fsm_loading = 7,
	fsm_query_overwrite = 8,
	fsm_overwrite = 9,
	fsm_saving = 10,
	fsm_create = 11,
	fsm_save_complete = 12,
	fsm_num_items = 13,
};
/* End enums */

/* Begin structs */

struct TCB // hashcode: 0x6A70BBF4 (dec: 1785773044)
{
	long status; // size=0, offset=0
	long mode; // size=0, offset=4
	unsigned long reg[40]; // size=160, offset=8
	long system[6]; // size=24, offset=168
};

struct EXEC // hashcode: 0x4291A2AD (dec: 1116840621)
{
	unsigned long pc0; // size=0, offset=0
	unsigned long gp0; // size=0, offset=4
	unsigned long t_addr; // size=0, offset=8
	unsigned long t_size; // size=0, offset=12
	unsigned long d_addr; // size=0, offset=16
	unsigned long d_size; // size=0, offset=20
	unsigned long b_addr; // size=0, offset=24
	unsigned long b_size; // size=0, offset=28
	unsigned long s_addr; // size=0, offset=32
	unsigned long s_size; // size=0, offset=36
	unsigned long sp; // size=0, offset=40
	unsigned long fp; // size=0, offset=44
	unsigned long gp; // size=0, offset=48
	unsigned long ret; // size=0, offset=52
	unsigned long base; // size=0, offset=56
};

struct DIRENTRY // hashcode: 0xD989A944 (dec: -645289660)
{
	char name[20]; // size=20, offset=0
	long attr; // size=0, offset=20
	long size; // size=0, offset=24
	struct DIRENTRY *next; // size=40, offset=28
	long head; // size=0, offset=32
	char system[4]; // size=4, offset=36
};

struct MATRIX // hashcode: 0x610186A2 (dec: 1627489954)
{
	short m[3][3]; // size=18, offset=0
	long t[3]; // size=12, offset=20
};

struct VECTOR // hashcode: 0xE0DB0D68 (dec: -522515096)
{
	long vx; // size=0, offset=0
	long vy; // size=0, offset=4
	long vz; // size=0, offset=8
	long pad; // size=0, offset=12
};

struct SVECTOR // hashcode: 0x55473CEB (dec: 1430732011)
{
	short vx; // size=0, offset=0
	short vy; // size=0, offset=2
	short vz; // size=0, offset=4
	short pad; // size=0, offset=6
};

struct CVECTOR // hashcode: 0xDE4B0C81 (dec: -565506943)
{
	unsigned char r; // size=0, offset=0
	unsigned char g; // size=0, offset=1
	unsigned char b; // size=0, offset=2
	unsigned char cd; // size=0, offset=3
};

struct DVECTOR // hashcode: 0x5BF12E56 (dec: 1542532694)
{
	short vx; // size=0, offset=0
	short vy; // size=0, offset=2
};

struct RVECTOR // hashcode: 0xEC34D5C3 (dec: -332081725)
{
	struct SVECTOR v; // size=8, offset=0
	unsigned char uv[2]; // size=2, offset=8
	unsigned short pad; // size=0, offset=10
	struct CVECTOR c; // size=4, offset=12
	struct DVECTOR sxy; // size=4, offset=16
	unsigned long sz; // size=0, offset=20
};

struct CRVECTOR3 // hashcode: 0x9A564233 (dec: -1705622989)
{
	struct RVECTOR r01; // size=24, offset=0
	struct RVECTOR r12; // size=24, offset=24
	struct RVECTOR r20; // size=24, offset=48
	struct RVECTOR *r0; // size=24, offset=72
	struct RVECTOR *r1; // size=24, offset=76
	struct RVECTOR *r2; // size=24, offset=80
	unsigned long *rtn; // size=0, offset=84
};

struct CRVECTOR4 // hashcode: 0x56AED614 (dec: 1454298644)
{
	struct RVECTOR r01; // size=24, offset=0
	struct RVECTOR r02; // size=24, offset=24
	struct RVECTOR r31; // size=24, offset=48
	struct RVECTOR r32; // size=24, offset=72
	struct RVECTOR rc; // size=24, offset=96
	struct RVECTOR *r0; // size=24, offset=120
	struct RVECTOR *r1; // size=24, offset=124
	struct RVECTOR *r2; // size=24, offset=128
	struct RVECTOR *r3; // size=24, offset=132
	unsigned long *rtn; // size=0, offset=136
};

struct RECT // hashcode: 0xDFC821CB (dec: -540532277)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short w; // size=0, offset=4
	short h; // size=0, offset=6
};

struct DR_ENV // hashcode: 0xD77E7FD5 (dec: -679575595)
{
	unsigned long tag; // size=0, offset=0
	unsigned long code[15]; // size=60, offset=4
};

struct P_TAG // hashcode: 0x962C4103 (dec: -1775484669)
{
	unsigned int addr; // size=24, offset=0
	unsigned int len; // size=8, offset=24
	unsigned char r0; // size=0, offset=4
	unsigned char g0; // size=0, offset=5
	unsigned char b0; // size=0, offset=6
	unsigned char code; // size=0, offset=7
};

struct CdlLOC // hashcode: 0x449289F8 (dec: 1150454264)
{
	unsigned char minute; // size=0, offset=0
	unsigned char second; // size=0, offset=1
	unsigned char sector; // size=0, offset=2
	unsigned char track; // size=0, offset=3
};

struct LightInstance // hashcode: 0xB8D5E61F (dec: -1193941473)
{
	struct _Instance *lightInstance; // size=0, offset=0
	long r; // size=0, offset=4
	long g; // size=0, offset=8
	long b; // size=0, offset=12
	short radius; // size=0, offset=16
	unsigned char segment; // size=0, offset=18
	unsigned char flags; // size=0, offset=19
};

struct _Instance // hashcode: 0x699A5B3D (dec: 1771723581)
{
	struct NodeType node; // size=8, offset=0
	struct _Instance *next; // size=664, offset=8
	struct _Instance *prev; // size=664, offset=12
	long instanceID; // size=0, offset=16
	long flags; // size=0, offset=20
	long flags2; // size=0, offset=24
	struct Object *object; // size=76, offset=28
	struct Intro *intro; // size=0, offset=32
	void *data; // size=0, offset=36
	void *introData; // size=0, offset=40
	struct _Instance *parent; // size=664, offset=44
	long introNum; // size=0, offset=48
	long birthStreamUnitID; // size=0, offset=52
	long currentStreamUnitID; // size=0, offset=56
	long introUniqueID; // size=0, offset=60
	struct MATRIX *matrix; // size=32, offset=64
	struct MATRIX *oldMatrix; // size=32, offset=68
	struct SoundInstance soundInstanceTbl[4]; // size=12, offset=72
	unsigned long maxCheckDistance; // size=0, offset=84
	unsigned long checkMask; // size=0, offset=88
	struct _Position position; // size=6, offset=92
	unsigned char lightGroup; // size=0, offset=98
	struct _Position oldPos; // size=6, offset=100
	unsigned char spectralLightGroup; // size=0, offset=106
	short currentTextureAnimFrame; // size=0, offset=108
	struct _Position initialPos; // size=6, offset=110
	struct _Rotation rotation; // size=8, offset=116
	struct _Rotation oldRotation; // size=8, offset=124
	struct _SVector scale; // size=8, offset=132
	long attachedID; // size=0, offset=140
	long attachedSegment; // size=0, offset=144
	struct MATRIX relativeMatrix; // size=32, offset=148
	struct _TFace *tface; // size=12, offset=180
	struct _TFace *oldTFace; // size=12, offset=184
	void *tfaceLevel; // size=0, offset=188
	void *collideInfo; // size=0, offset=192
	long bspTree; // size=0, offset=196
	short cachedTFace; // size=0, offset=200
	short cachedBSPTree; // size=0, offset=202
	struct _Normal oldWNormal; // size=8, offset=204
	struct _Normal wNormal; // size=8, offset=212
	struct _SVector offset; // size=8, offset=220
	void *dsignal; // size=0, offset=228
	void *shadow0; // size=0, offset=232
	void *shadow1; // size=0, offset=236
	void *extraLight; // size=0, offset=240
	struct _Position extraLightDir; // size=6, offset=244
	short extraLightScale; // size=0, offset=250
	struct _HModel *hModelList; // size=8, offset=252
	short fadeValue; // size=0, offset=256
	short lightMatrix; // size=0, offset=258
	void (*processFunc)(); // size=0, offset=260
	void (*collideFunc)(); // size=0, offset=264
	void (*additionalCollideFunc)(); // size=0, offset=268
	void *additionalDrawFunc; // size=0, offset=272
	unsigned long (*queryFunc)(); // size=0, offset=276
	void (*messageFunc)(); // size=0, offset=280
	struct _Position shadowPosition; // size=6, offset=284
	short currentModel; // size=0, offset=290
	struct _TFace *waterFace; // size=12, offset=292
	struct _TFace *oldWaterFace; // size=12, offset=296
	struct _Terrain *waterFaceTerrain; // size=0, offset=300
	struct _PlaneConstants halvePlane; // size=12, offset=304
	struct _SVector splitPoint; // size=8, offset=316
	struct _Instance *LinkParent; // size=664, offset=324
	struct _Instance *LinkChild; // size=664, offset=328
	struct _Instance *LinkSibling; // size=664, offset=332
	long ParentLinkNode; // size=0, offset=336
	void *InstanceState; // size=0, offset=340
	char introName[16]; // size=16, offset=344
	void *extraData; // size=0, offset=360
	short constrictAngle; // size=0, offset=364
	short petrifyValue; // size=0, offset=366
	long xVel; // size=0, offset=368
	long yVel; // size=0, offset=372
	long zVel; // size=0, offset=376
	long xAccl; // size=0, offset=380
	long yAccl; // size=0, offset=384
	long zAccl; // size=0, offset=388
	long maxXVel; // size=0, offset=392
	long maxYVel; // size=0, offset=396
	long maxZVel; // size=0, offset=400
	long currentMainState; // size=0, offset=404
	long currentSubState; // size=0, offset=408
	long work0; // size=0, offset=412
	long work1; // size=0, offset=416
	long work2; // size=0, offset=420
	long work3; // size=0, offset=424
	long work4; // size=0, offset=428
	long work5; // size=0, offset=432
	long work6; // size=0, offset=436
	long work7; // size=0, offset=440
	long work8; // size=0, offset=444
	long work9; // size=0, offset=448
	struct _G2Anim_Type anim; // size=180, offset=452
	enum _G2Bool_Enum (*rebuildCallback)(); // size=4, offset=632
	short splineFlags; // size=0, offset=636
	short targetFrame; // size=0, offset=638
	short clipBeg; // size=0, offset=640
	short clipEnd; // size=0, offset=642
	struct EventAliasCommandStruct aliasCommand; // size=12, offset=644
	long light_color; // size=0, offset=656
	struct CVECTOR *perVertexColor; // size=4, offset=660
};

struct _GameTrackerASMData_Type // hashcode: 0x28F0BFB9 (dec: 686866361)
{
	long drawBackFaces; // size=0, offset=0
	long dispPage; // size=0, offset=4
	short MorphTime; // size=0, offset=8
	short MorphType; // size=0, offset=10
	struct LightInstance lightInstances[1]; // size=20, offset=12
};

struct _GameData_Type // hashcode: 0xE05EBAD0 (dec: -530662704)
{
	struct _GameTrackerASMData_Type asmData; // size=32, offset=0
};

struct NodeType // hashcode: 0x5BF613D7 (dec: 1542853591)
{
	struct NodeType *prev; // size=8, offset=0
	struct NodeType *next; // size=8, offset=4
};

struct TextureFT3 // hashcode: 0x2D2801D6 (dec: 757596630)
{
	unsigned char u0; // size=0, offset=0
	unsigned char v0; // size=0, offset=1
	unsigned short clut; // size=0, offset=2
	unsigned char u1; // size=0, offset=4
	unsigned char v1; // size=0, offset=5
	unsigned short tpage; // size=0, offset=6
	unsigned char u2; // size=0, offset=8
	unsigned char v2; // size=0, offset=9
	unsigned short attr; // size=0, offset=10
};

struct TextureMT3 // hashcode: 0xC9D0A5B9 (dec: -909072967)
{
	unsigned char u0; // size=0, offset=0
	unsigned char v0; // size=0, offset=1
	unsigned short clut; // size=0, offset=2
	unsigned char u1; // size=0, offset=4
	unsigned char v1; // size=0, offset=5
	unsigned short tpage; // size=0, offset=6
	unsigned char u2; // size=0, offset=8
	unsigned char v2; // size=0, offset=9
	char pad1; // size=0, offset=10
	char sortPush; // size=0, offset=11
	long color; // size=0, offset=12
};

struct AniTexInfo // hashcode: 0x907C013D (dec: -1870921411)
{
	struct TextureMT3 *texture; // size=16, offset=0
	long numFrames; // size=0, offset=4
	long speed; // size=0, offset=8
};

struct AniTex // hashcode: 0xE4DA2729 (dec: -455465175)
{
	long numAniTextues; // size=0, offset=0
	struct AniTexInfo aniTexInfo; // size=12, offset=4
};

struct DrMoveAniTexSrcInfo // hashcode: 0x4AD6E543 (dec: 1255597379)
{
	short pixSrcX; // size=0, offset=0
	short pixSrcY; // size=0, offset=2
	short clutSrcX; // size=0, offset=4
	short clutSrcY; // size=0, offset=6
};

struct DrMoveAniTexDestInfo // hashcode: 0xF3A982EE (dec: -206994706)
{
	short pixDstX; // size=0, offset=0
	short pixDstY; // size=0, offset=2
	short pixW; // size=0, offset=4
	short pixH; // size=0, offset=6
	short clutDstX; // size=0, offset=8
	short clutDstY; // size=0, offset=10
	short clutW; // size=0, offset=12
	short clutH; // size=0, offset=14
	short pixCurrentX; // size=0, offset=16
	short pixCurrentY; // size=0, offset=18
	short clutCurrentX; // size=0, offset=20
	short clutCurrentY; // size=0, offset=22
	long numFrames; // size=0, offset=24
	long speed; // size=0, offset=28
	struct DrMoveAniTexSrcInfo frame; // size=8, offset=32
};

struct DrMoveAniTex // hashcode: 0x0820A5D4 (dec: 136357332)
{
	long numAniTextues; // size=0, offset=0
	struct DrMoveAniTexDestInfo *aniTexInfo; // size=40, offset=4
};

struct MemHeader // hashcode: 0xDAEE4890 (dec: -621918064)
{
	unsigned short magicNumber; // size=0, offset=0
	unsigned char memStatus; // size=0, offset=2
	unsigned char memType; // size=0, offset=3
	unsigned long memSize; // size=0, offset=4
};

struct _G2SVector3_Type // hashcode: 0x60FF7CCD (dec: 1627356365)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
};

struct _G2LVector3_Type // hashcode: 0xD8D79EE7 (dec: -656957721)
{
	long x; // size=0, offset=0
	long y; // size=0, offset=4
	long z; // size=0, offset=8
};

struct _G2Matrix_Type // hashcode: 0x647D6F57 (dec: 1685942103)
{
	short rotScale[3][3]; // size=18, offset=0
	short scaleFlag; // size=0, offset=18
	struct _G2LVector3_Type trans; // size=12, offset=20
};

struct _G2Quat_Type // hashcode: 0xC71F9EB1 (dec: -954229071)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short w; // size=0, offset=6
};

struct _G2AnimQuatInfo_Type // hashcode: 0x5A520473 (dec: 1515324531)
{
	struct _G2Quat_Type srcQuat; // size=8, offset=0
	struct _G2Quat_Type destQuat; // size=8, offset=8
	struct _G2SVector3_Type srcScale; // size=6, offset=16
	struct _G2SVector3_Type destScale; // size=6, offset=22
	struct _G2SVector3_Type srcTrans; // size=6, offset=28
	struct _G2SVector3_Type destTrans; // size=6, offset=34
};

struct _G2AnimAlphaTable_Type // hashcode: 0x2288BF48 (dec: 579387208)
{
	unsigned short size; // size=0, offset=0
	long data[0]; // size=0, offset=4
};

struct _G2AnimInterpStateBlock_Type // hashcode: 0xFB03DD89 (dec: -83632759)
{
	struct _G2AnimInterpStateBlock_Type *next; // size=164, offset=0
	struct _G2AnimQuatInfo_Type quatInfo[4]; // size=160, offset=4
};

struct _G2AnimInterpInfo_Type // hashcode: 0xAE13EB6F (dec: -1374426257)
{
	short duration; // size=0, offset=0
	short targetTime; // size=0, offset=2
	struct _G2AnimAlphaTable_Type *alphaTable; // size=4, offset=4
	struct _G2AnimInterpStateBlock_Type *stateBlockList; // size=164, offset=8
};

struct _G2AnimChanStatus_Type // hashcode: 0x575B81AB (dec: 1465614763)
{
	short keyData; // size=0, offset=0
	short index; // size=0, offset=2
};

struct _G2AnimChanStatusBlock_Type // hashcode: 0xC6C09C4F (dec: -960455601)
{
	struct _G2AnimChanStatusBlock_Type *next; // size=36, offset=0
	struct _G2AnimChanStatus_Type chunks[8]; // size=32, offset=4
};

struct _G2AnimFxHeader_Type // hashcode: 0xA004B4ED (dec: -1610304275)
{
	unsigned char sizeAndSection; // size=0, offset=0
	char type; // size=0, offset=1
	unsigned short keyframeID; // size=0, offset=2
};

struct _G2AnimKeylist_Type // hashcode: 0x87A15165 (dec: -2019471003)
{
	unsigned char sectionCount; // size=0, offset=0
	unsigned char s0TailTime; // size=0, offset=1
	unsigned char s1TailTime; // size=0, offset=2
	unsigned char s2TailTime; // size=0, offset=3
	unsigned short keyCount; // size=0, offset=4
	short timePerKey; // size=0, offset=6
	unsigned short pad00; // size=0, offset=8
	short pad01; // size=0, offset=10
	unsigned short pad10; // size=0, offset=12
	short pad11; // size=0, offset=14
	struct _G2AnimFxHeader_Type *fxList; // size=4, offset=16
	unsigned short (*sectionData[0]); // size=0, offset=20
};

struct _G2AnimSection_Type // hashcode: 0xFC80328C (dec: -58707316)
{
	unsigned char flags; // size=0, offset=0
	unsigned char sectionID; // size=0, offset=1
	unsigned char firstSeg; // size=0, offset=2
	unsigned char segCount; // size=0, offset=3
	short elapsedTime; // size=0, offset=4
	short storedTime; // size=0, offset=6
	short loopStartTime; // size=0, offset=8
	short loopEndTime; // size=0, offset=10
	short *swAlarmTable; // size=0, offset=12
	long speedAdjustment; // size=0, offset=16
	unsigned short keylistID; // size=0, offset=20
	unsigned long alarmFlags; // size=0, offset=24
	long (*callback)(); // size=0, offset=28
	void *callbackData; // size=0, offset=32
	struct _G2AnimKeylist_Type *keylist; // size=20, offset=36
	struct _G2AnimChanStatusBlock_Type *chanStatusBlockList; // size=36, offset=40
	struct _G2AnimInterpInfo_Type *interpInfo; // size=12, offset=44
};

struct _G2Anim_Type // hashcode: 0xF35FCCD2 (dec: -211825454)
{
	unsigned char sectionCount; // size=0, offset=0
	unsigned char masterSection; // size=0, offset=1
	unsigned short controllerList; // size=0, offset=2
	unsigned short disabledControllerList; // size=0, offset=4
	unsigned short pad; // size=0, offset=6
	struct _G2SVector3_Type rootTrans; // size=6, offset=8
	unsigned short flags; // size=0, offset=14
	struct _Model *modelData; // size=0, offset=16
	struct _G2Matrix_Type *segMatrices; // size=32, offset=20
	unsigned long disabledBits[3]; // size=12, offset=24
	struct _G2AnimSection_Type section[3]; // size=144, offset=36
};

struct _Model // hashcode: 0x9BCE1D24 (dec: -1680990940)
{
	long numVertices; // size=0, offset=0
	struct _MVertex *vertexList; // size=8, offset=4
	long numNormals; // size=0, offset=8
	struct _SVectorNoPad *normalList; // size=6, offset=12
	long numFaces; // size=0, offset=16
	struct _MFace *faceList; // size=12, offset=20
	long numSegments; // size=0, offset=24
	struct _Segment *segmentList; // size=24, offset=28
	struct AniTex *aniTextures; // size=16, offset=32
	short maxRad; // size=0, offset=36
	short pad; // size=0, offset=38
	long maxRadSq; // size=0, offset=40
	struct MultiSpline *multiSpline; // size=0, offset=44
	struct TextureMT3 *startTextures; // size=16, offset=48
	struct TextureMT3 *endTextures; // size=16, offset=52
};

struct _SVector // hashcode: 0x73B07C09 (dec: 1940945929)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short pad; // size=0, offset=6
};

struct _SVectorNoPad // hashcode: 0xA6EDBBC6 (dec: -1494369338)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
};

struct _Position // hashcode: 0x2523C22F (dec: 623100463)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
};

struct _Rotation // hashcode: 0x5A40CBB0 (dec: 1514195888)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short pad; // size=0, offset=6
};

struct _Normal // hashcode: 0xC59D5A5B (dec: -979543461)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short pad; // size=0, offset=6
};

struct _PlaneConstants // hashcode: 0xE1AAD777 (dec: -508897417)
{
	short a; // size=0, offset=0
	short b; // size=0, offset=2
	short c; // size=0, offset=4
	short flags; // size=0, offset=6
	long d; // size=0, offset=8
};

struct _Vertex // hashcode: 0x97101469 (dec: -1760553879)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
};

struct _Face // hashcode: 0x8775891B (dec: -2022340325)
{
	unsigned short v0; // size=0, offset=0
	unsigned short v1; // size=0, offset=2
	unsigned short v2; // size=0, offset=4
};

struct _MVertex // hashcode: 0x2B95C05B (dec: 731234395)
{
	struct _Vertex vertex; // size=6, offset=0
	unsigned short normal; // size=0, offset=6
};

struct _MFace // hashcode: 0xB75C604D (dec: -1218682803)
{
	struct _Face face; // size=6, offset=0
	unsigned char normal; // size=0, offset=6
	unsigned char flags; // size=0, offset=7
	long color; // size=0, offset=8
};

struct _RGBAColor // hashcode: 0xF7174D90 (dec: -149467760)
{
	unsigned char r; // size=0, offset=0
	unsigned char g; // size=0, offset=1
	unsigned char b; // size=0, offset=2
	unsigned char a; // size=0, offset=3
};

struct _PVertex // hashcode: 0x4AC0ECE8 (dec: 1254157544)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	long otz; // size=0, offset=4
};

struct _VertexPool // hashcode: 0x98F8C96E (dec: -1728525970)
{
	struct _PVertex vertex[528]; // size=4224, offset=0
	struct CVECTOR color[528]; // size=2112, offset=4224
};

struct _PrimPool // hashcode: 0x9529B283 (dec: -1792429437)
{
	long numPrims; // size=0, offset=0
	unsigned long *nextPrim; // size=0, offset=4
	unsigned long *lastPrim; // size=0, offset=8
	unsigned long prim[24000]; // size=96000, offset=12
};

struct _Sphere // hashcode: 0x361BDD31 (dec: 907795761)
{
	struct _Position position; // size=6, offset=0
	unsigned short radius; // size=0, offset=6
	unsigned long radiusSquared; // size=0, offset=8
};

struct _Sphere_noSq // hashcode: 0xA031058C (dec: -1607400052)
{
	struct _Position position; // size=6, offset=0
	unsigned short radius; // size=0, offset=6
};

struct _CameraKey // hashcode: 0xB9E6B724 (dec: -1176062172)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short id; // size=0, offset=6
	short rx; // size=0, offset=8
	short ry; // size=0, offset=10
	short rz; // size=0, offset=12
	short flags; // size=0, offset=14
	short tx; // size=0, offset=16
	short ty; // size=0, offset=18
	short tz; // size=0, offset=20
	short pad; // size=0, offset=22
};

struct Object // hashcode: 0xEC12E9AC (dec: -334304852)
{
	long oflags; // size=0, offset=0
	short id; // size=0, offset=4
	short sfxFileHandle; // size=0, offset=6
	short numModels; // size=0, offset=8
	short numAnims; // size=0, offset=10
	struct _Model **modelList; // size=56, offset=12
	struct _G2AnimKeylist_Type **animList; // size=20, offset=16
	short introDist; // size=0, offset=20
	short vvIntroDist; // size=0, offset=22
	short removeDist; // size=0, offset=24
	short vvRemoveDist; // size=0, offset=26
	void *data; // size=0, offset=28
	char *script; // size=0, offset=32
	char *name; // size=0, offset=36
	unsigned char *soundData; // size=0, offset=40
	long oflags2; // size=0, offset=44
	short sectionA; // size=0, offset=48
	short sectionB; // size=0, offset=50
	short sectionC; // size=0, offset=52
	short numberOfEffects; // size=0, offset=54
	struct ObjectEffect *effectList; // size=4, offset=56
	unsigned long *relocList; // size=0, offset=60
	void *relocModule; // size=0, offset=64
	struct VramSize vramSize; // size=8, offset=68
};

struct _BVertex // hashcode: 0xADD3BD2F (dec: -1378632401)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short pad; // size=0, offset=6
};

struct _BFace // hashcode: 0x69100F99 (dec: 1762660249)
{
	short v0; // size=0, offset=0
	short v1; // size=0, offset=2
	short v2; // size=0, offset=4
	short pad; // size=0, offset=6
	struct TextureFT3 *texture; // size=12, offset=8
};

struct _BGObject // hashcode: 0xEC69FB30 (dec: -328598736)
{
	short flags; // size=0, offset=0
	short numFaces; // size=0, offset=2
	struct _BVertex *vertexList; // size=8, offset=4
	struct _BFace *faceList; // size=12, offset=8
	short x; // size=0, offset=12
	short y; // size=0, offset=14
	short z; // size=0, offset=16
	short radius; // size=0, offset=18
	long numVertices; // size=0, offset=20
};

struct Signal // hashcode: 0xA0225F88 (dec: -1608360056)
{
	long id; // size=0, offset=0
	union {
		struct {
			union {
				long l; // size=0, offset=0
				short s[2]; // size=4, offset=0
				char c[4]; // size=4, offset=0
			} size; // size=4, offset=0, found in object files: player.o, player.o
		} misc; // size=12, offset=0, found in object files: player.o, player.o
		struct _CameraKey *cameraKey; // size=24, offset=0
		struct {
			short x; // size=0, offset=0
			short y; // size=0, offset=2
			short z; // size=0, offset=4
			short zrot; // size=0, offset=6
			struct _SVector offset; // size=8, offset=8
		} teleport; // size=16, offset=0, found in object files: player.o, player.o
		struct {
			long index; // size=0, offset=0
			long value; // size=0, offset=4
		} cameraValue; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			long index; // size=0, offset=0
			long value; // size=0, offset=4
		} miscValue; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			long index; // size=0, offset=0
			long value; // size=0, offset=4
		} logicValue; // size=8, offset=0, found in object files: player.o, player.o
		long timer; // size=0, offset=0
		long times; // size=0, offset=0
		long lightGroup; // size=0, offset=0
		long farPlane; // size=0, offset=0
		long cameraAdjust; // size=0, offset=0
		long cameraMode; // size=0, offset=0
		long cameraLock; // size=0, offset=0
		long cameraUnlock; // size=0, offset=0
		long cameraSmooth; // size=0, offset=0
		long cameraTimer; // size=0, offset=0
		struct {
			long time; // size=0, offset=0
			long scale; // size=0, offset=4
		} cameraShake; // size=8, offset=0, found in object files: player.o, player.o
		long cameraSave; // size=0, offset=0
		long cameraRestore; // size=0, offset=0
		struct _BGObject *bgObject; // size=24, offset=0
		long value[2]; // size=8, offset=0
		struct {
			long action; // size=0, offset=0
			long value[2]; // size=8, offset=4
		} sound; // size=12, offset=0, found in object files: player.o, player.o
		void *intro; // size=0, offset=0
		long deathZ; // size=0, offset=0
		struct {
			void *intro; // size=0, offset=0
			void *data; // size=0, offset=4
		} dsignal; // size=8, offset=0, found in object files: player.o, player.o
		void *mirror; // size=0, offset=0
		long fogNear; // size=0, offset=0
		long fogFar; // size=0, offset=0
		struct {
			void *intro; // size=0, offset=0
			long frame; // size=0, offset=4
		} gotoFrame; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			void *intro; // size=0, offset=0
			long model; // size=0, offset=4
		} changeModel; // size=8, offset=0, found in object files: player.o, player.o
		void *vmObject; // size=0, offset=0
		struct {
			unsigned char target; // size=0, offset=0
			unsigned char source1; // size=0, offset=1
			unsigned char source2; // size=0, offset=2
			unsigned char pad; // size=0, offset=3
			struct Signal *gotoLabel; // size=0, offset=4
		} logic; // size=8, offset=0, found in object files: player.o, player.o
		void *callSignal; // size=0, offset=0
		struct _SVector offset; // size=8, offset=0
		struct Signal *gotoLabel; // size=0, offset=0
		struct Signal *gosubLabel; // size=0, offset=0
		struct {
			long timer; // size=0, offset=0
			long action; // size=0, offset=4
		} control; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			short index; // size=0, offset=0
			short z; // size=0, offset=2
			struct MultiSignal *upSignal; // size=0, offset=4
			struct MultiSignal *downSignal; // size=0, offset=8
		} zSignal; // size=12, offset=0, found in object files: player.o, player.o
		struct {
			long currentnum; // size=0, offset=0
			long streamID; // size=0, offset=4
			char toname[16]; // size=16, offset=8
		} StreamLevel; // size=24, offset=0, found in object files: player.o, player.o
		struct {
			char num; // size=0, offset=0
			char vel; // size=0, offset=1
			short misc; // size=0, offset=2
			char flags; // size=0, offset=4
			char timeToLive; // size=0, offset=5
			short dummy2; // size=0, offset=6
			struct Object *object; // size=0, offset=8
		} shards; // size=12, offset=0, found in object files: player.o, player.o
		struct {
			long index; // size=0, offset=0
			void *intro; // size=0, offset=4
		} cameraSpline; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			short type; // size=0, offset=0
			short time; // size=0, offset=2
		} screenWipe; // size=4, offset=0, found in object files: player.o, player.o
		long voiceSitId; // size=0, offset=0
		struct {
			long time; // size=0, offset=0
			void *intro; // size=0, offset=4
		} introFX; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			void *intro; // size=0, offset=0
			struct Signal *gotoLabel; // size=0, offset=4
		} introActive; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			char world[9]; // size=9, offset=0
			char level[9]; // size=9, offset=9
		} levelChange; // size=18, offset=0, found in object files: player.o, player.o
		long blendStart; // size=0, offset=0
		struct {
			struct Signal *signal; // size=0, offset=0
			long times; // size=0, offset=4
		} setTimes; // size=8, offset=0, found in object files: player.o, player.o
		struct {
			unsigned char r; // size=0, offset=0
			unsigned char g; // size=0, offset=1
			unsigned char b; // size=0, offset=2
			unsigned char pad; // size=0, offset=3
		} color; // size=4, offset=0, found in object files: player.o, player.o
		struct {
			short x; // size=0, offset=0
			short y; // size=0, offset=2
			short time; // size=0, offset=4
			short index; // size=0, offset=6
			char *text; // size=0, offset=8
		} print; // size=12, offset=0, found in object files: player.o, player.o
		long slideAngle; // size=0, offset=0
	} data; // size=24, offset=4, found in object files: player.o, player.o
};

struct _MultiSignal // hashcode: 0x0620B768 (dec: 102807400)
{
	long numSignals; // size=0, offset=0
	short signalNum; // size=0, offset=4
	short flags; // size=0, offset=6
	struct Signal signalList[32]; // size=896, offset=8
};

struct _HFace // hashcode: 0x30CA5CA6 (dec: 818568358)
{
	short v0; // size=0, offset=0
	short v1; // size=0, offset=2
	short v2; // size=0, offset=4
	unsigned char attr; // size=0, offset=6
	char pad; // size=0, offset=7
	unsigned short normal; // size=0, offset=8
	unsigned short n0; // size=0, offset=10
};

struct _HSphere // hashcode: 0x8E7B7191 (dec: -1904512623)
{
	long attr; // size=0, offset=0
	unsigned char id; // size=0, offset=4
	unsigned char rank; // size=0, offset=5
	short pad; // size=0, offset=6
	struct _Position position; // size=6, offset=8
	unsigned short radius; // size=0, offset=14
	unsigned long radiusSquared; // size=0, offset=16
};

struct _HBox // hashcode: 0x47CD8BDA (dec: 1204653018)
{
	short flags; // size=0, offset=0
	unsigned char id; // size=0, offset=2
	unsigned char rank; // size=0, offset=3
	short minX; // size=0, offset=4
	short minY; // size=0, offset=6
	short minZ; // size=0, offset=8
	short maxX; // size=0, offset=10
	short maxY; // size=0, offset=12
	short maxZ; // size=0, offset=14
	short refMinX; // size=0, offset=16
	short refMinY; // size=0, offset=18
	short refMinZ; // size=0, offset=20
	short refMaxX; // size=0, offset=22
	short refMaxY; // size=0, offset=24
	short refMaxZ; // size=0, offset=26
};

struct _HPrim // hashcode: 0x988F5E11 (dec: -1735434735)
{
	unsigned char hpFlags; // size=0, offset=0
	unsigned char withFlags; // size=0, offset=1
	unsigned char type; // size=0, offset=2
	unsigned char segment; // size=0, offset=3
	union {
		struct _HSphere *hsphere; // size=20, offset=0
		struct _HBox *hbox; // size=28, offset=0
		struct _HFace *hface; // size=12, offset=0
	} data; // size=4, offset=4, found in object files: player.o, player.o
};

struct _HModel // hashcode: 0xBC680356 (dec: -1134034090)
{
	struct _HPrim *hPrimList; // size=8, offset=0
	long numHPrims; // size=0, offset=4
};

struct _HInfo // hashcode: 0x6AC9807F (dec: 1791590527)
{
	long numHFaces; // size=0, offset=0
	struct _HFace *hfaceList; // size=12, offset=4
	long numHSpheres; // size=0, offset=8
	struct _HSphere *hsphereList; // size=20, offset=12
	long numHBoxes; // size=0, offset=16
	struct _HBox *hboxList; // size=28, offset=20
};

struct _Segment // hashcode: 0x2F06BF28 (dec: 788971304)
{
	long flags; // size=0, offset=0
	short firstTri; // size=0, offset=4
	short lastTri; // size=0, offset=6
	short firstVertex; // size=0, offset=8
	short lastVertex; // size=0, offset=10
	short px; // size=0, offset=12
	short py; // size=0, offset=14
	short pz; // size=0, offset=16
	short parent; // size=0, offset=18
	struct _HInfo *hInfo; // size=24, offset=20
};

struct MultiSpline // hashcode: 0x2823B2CF (dec: 673428175)
{
	struct Spline *positional; // size=8, offset=0
	struct RSpline *rotational; // size=8, offset=4
	struct Spline *scaling; // size=8, offset=8
	struct Spline *color; // size=8, offset=12
	struct SplineDef curPositional; // size=8, offset=16
	struct SplineDef curRotational; // size=8, offset=24
	struct SplineDef curScaling; // size=8, offset=32
	struct SplineDef curColor; // size=8, offset=40
	struct MATRIX curRotMatrix; // size=32, offset=48
};

struct SoundInstance // hashcode: 0xFF235679 (dec: -14461319)
{
	unsigned char channel; // size=0, offset=0
	unsigned char state; // size=0, offset=1
	unsigned char delay; // size=0, offset=2
};

struct ObjectEffect // hashcode: 0x2892438D (dec: 680674189)
{
	unsigned char effectNumber; // size=0, offset=0
	unsigned char modifierList[3]; // size=3, offset=1
};

struct VramSize // hashcode: 0xD96A55BF (dec: -647342657)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short w; // size=0, offset=4
	short h; // size=0, offset=6
};

struct _TFace // hashcode: 0x85FE430F (dec: -2046934257)
{
	struct _Face face; // size=6, offset=0
	unsigned char attr; // size=0, offset=6
	char sortPush; // size=0, offset=7
	unsigned short normal; // size=0, offset=8
	unsigned short textoff; // size=0, offset=10
};

struct _TVertex // hashcode: 0x0883ABD5 (dec: 142846933)
{
	struct _Vertex vertex; // size=6, offset=0
	unsigned short rgb15; // size=0, offset=6
	unsigned char r0; // size=0, offset=8
	unsigned char g0; // size=0, offset=9
	unsigned char b0; // size=0, offset=10
	unsigned char code; // size=0, offset=11
};

struct EventAliasCommandStruct // hashcode: 0xB6EF2AF6 (dec: -1225839882)
{
	struct _Instance *hostInstance; // size=0, offset=0
	short newanim; // size=0, offset=4
	short newframe; // size=0, offset=6
	short interpframes; // size=0, offset=8
	short speed; // size=0, offset=10
};

struct Intro // hashcode: 0x796E766D (dec: 2037282413)
{
	char name[16]; // size=16, offset=0
	long intronum; // size=0, offset=16
	long UniqueID; // size=0, offset=20
	struct _Rotation rotation; // size=8, offset=24
	struct _Position position; // size=6, offset=32
	short maxRad; // size=0, offset=38
	long maxRadSq; // size=0, offset=40
	long flags; // size=0, offset=44
	void *data; // size=0, offset=48
	struct _Instance *instance; // size=664, offset=52
	struct MultiSpline *multiSpline; // size=0, offset=56
	void *dsignal; // size=0, offset=60
	short specturalLightGroup; // size=0, offset=64
	short meshColor; // size=0, offset=66
	struct _Position spectralPosition; // size=6, offset=68
	short spad; // size=0, offset=74
};

struct _Terrain // hashcode: 0x5D541B4E (dec: 1565793102)
{
	short UnitChangeFlags; // size=0, offset=0
	short spad; // size=0, offset=2
	long lpad2; // size=0, offset=4
	long numIntros; // size=0, offset=8
	struct Intro *introList; // size=76, offset=12
	long numVertices; // size=0, offset=16
	long numFaces; // size=0, offset=20
	long numNormals; // size=0, offset=24
	struct _TVertex *vertexList; // size=12, offset=28
	struct _TFace *faceList; // size=12, offset=32
	struct _Normal *normalList; // size=8, offset=36
	struct DrMoveAniTex *aniList; // size=8, offset=40
	long pad; // size=0, offset=44
	void *StreamUnits; // size=0, offset=48
	struct TextureFT3 *StartTextureList; // size=12, offset=52
	struct TextureFT3 *EndTextureList; // size=12, offset=56
	struct _MorphVertex *MorphDiffList; // size=14, offset=60
	struct _MorphColor *MorphColorList; // size=2, offset=64
	long numBSPTrees; // size=0, offset=68
	struct BSPTree *BSPTreeArray; // size=36, offset=72
	short *morphNormalIdx; // size=0, offset=76
	struct _MultiSignal *signals; // size=904, offset=80
};

struct _InstancePool // hashcode: 0xC591AB92 (dec: -980309102)
{
	long nextInstanceID; // size=0, offset=0
	long numFreeInstances; // size=0, offset=4
	struct _Instance instance[60]; // size=39840, offset=8
	struct _Instance *first_free; // size=664, offset=39848
};

struct _InstanceList // hashcode: 0x7594B1C7 (dec: 1972679111)
{
	long numInstances; // size=0, offset=0
	struct _Instance *first; // size=664, offset=4
	struct _InstancePool *pool; // size=39852, offset=8
	struct NodeType group[32]; // size=256, offset=12
};

struct _ObjectTracker // hashcode: 0xFE4678BF (dec: -28936001)
{
	char name[16]; // size=16, offset=0
	struct Object *object; // size=76, offset=16
	short objectStatus; // size=0, offset=20
	short numInUse; // size=0, offset=22
	void *vramBlock; // size=0, offset=24
	char numObjectsUsing; // size=0, offset=28
	char objectsUsing[7]; // size=7, offset=29
};

struct _BoundingBox // hashcode: 0x2183782B (dec: 562264107)
{
	short minX; // size=0, offset=0
	short minY; // size=0, offset=2
	short minZ; // size=0, offset=4
	short maxX; // size=0, offset=6
	short maxY; // size=0, offset=8
	short maxZ; // size=0, offset=10
};

struct CDLight // hashcode: 0xD90757B8 (dec: -653830216)
{
	struct NodeType node; // size=8, offset=0
	unsigned char r; // size=0, offset=8
	unsigned char g; // size=0, offset=9
	unsigned char b; // size=0, offset=10
	unsigned char flags; // size=0, offset=11
	struct _Sphere sphere; // size=12, offset=12
};

struct _BSPNode // hashcode: 0x60C20F69 (dec: 1623330665)
{
	struct _Sphere_noSq sphere; // size=8, offset=0
	short a; // size=0, offset=8
	short b; // size=0, offset=10
	short c; // size=0, offset=12
	short flags; // size=0, offset=14
	long d; // size=0, offset=16
	void *front; // size=0, offset=20
	void *back; // size=0, offset=24
	struct _Sphere_noSq spectralSphere; // size=8, offset=28
	short front_spectral_error; // size=0, offset=36
	short back_spectral_error; // size=0, offset=38
	short front_material_error; // size=0, offset=40
	short back_material_error; // size=0, offset=42
};

struct _BSPLeaf // hashcode: 0xB2C1AC71 (dec: -1295930255)
{
	struct _Sphere_noSq sphere; // size=8, offset=0
	struct _TFace *faceList; // size=12, offset=8
	short numFaces; // size=0, offset=12
	short flags; // size=0, offset=14
	struct _BoundingBox box; // size=12, offset=16
	struct _BoundingBox spectralBox; // size=12, offset=28
	struct _Sphere_noSq spectralSphere; // size=8, offset=40
};

struct _MorphVertex // hashcode: 0xAAB8DABE (dec: -1430725954)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short vindex; // size=0, offset=6
	short hx; // size=0, offset=8
	short hy; // size=0, offset=10
	short hz; // size=0, offset=12
};

struct _MorphColor // hashcode: 0xA6BA0326 (dec: -1497758938)
{
	short morphColor15; // size=0, offset=0
};

struct Level // hashcode: 0x012B0198 (dec: 19595672)
{
	struct _Terrain *terrain; // size=84, offset=0
	struct LightList *lightList; // size=12, offset=4
	long numVMObjects; // size=0, offset=8
	struct _VMObject *vmobjectList; // size=60, offset=12
	long numSpotLights; // size=0, offset=16
	struct SpotLight *spotLightList; // size=40, offset=20
	long numPointLights; // size=0, offset=24
	struct PointLight *pointLightList; // size=24, offset=28
	long numSpotSpecturalLights; // size=0, offset=32
	struct SpotLight *spotSpecturalLightList; // size=40, offset=36
	long numPointSpecturalLights; // size=0, offset=40
	struct PointLight *pointSpecturalLightList; // size=24, offset=44
	long numBGObjects; // size=0, offset=48
	struct _BGObject *bgObjectList; // size=24, offset=52
	long waterZLevel; // size=0, offset=56
	unsigned char backColorR; // size=0, offset=60
	unsigned char backColorG; // size=0, offset=61
	unsigned char backColorB; // size=0, offset=62
	unsigned char cpad1; // size=0, offset=63
	unsigned char specturalColorR; // size=0, offset=64
	unsigned char specturalColorG; // size=0, offset=65
	unsigned char specturalColorB; // size=0, offset=66
	unsigned char cpad2; // size=0, offset=67
	unsigned short fogFar; // size=0, offset=68
	unsigned short fogNear; // size=0, offset=70
	unsigned short spectralFogFar; // size=0, offset=72
	unsigned short spectralFogNear; // size=0, offset=74
	unsigned short waterFogFar; // size=0, offset=76
	unsigned short waterFogNear; // size=0, offset=78
	long depthQBlendStart; // size=0, offset=80
	struct LightList *spectrallightList; // size=12, offset=84
	long numCameras; // size=0, offset=88
	void *cameraList; // size=0, offset=92
	long bspPlaneError; // size=0, offset=96
	long numVGroups; // size=0, offset=100
	struct _VGroup *vGroupList; // size=12, offset=104
	long deathZ; // size=0, offset=108
	long flags; // size=0, offset=112
	struct _MultiSignal *startSignal; // size=904, offset=116
	long numIntros; // size=0, offset=120
	struct Intro *introList; // size=76, offset=124
	struct DrMoveAniTex *bgAniList; // size=8, offset=128
	long numHotSpots; // size=0, offset=132
	struct _HotSpot *hotSpotList; // size=8, offset=136
	void *objectNameList; // size=0, offset=140
	long depthQFogStart; // size=0, offset=144
	long morphLastStep; // size=0, offset=148
	char *worldName; // size=0, offset=152
	struct VramSize vramSize; // size=8, offset=156
	unsigned short holdFogFar; // size=0, offset=164
	unsigned short holdFogNear; // size=0, offset=166
	long numberEnemyUnits; // size=0, offset=168
	char **enemyUnitsNames; // size=0, offset=172
	long **timesSignalList; // size=0, offset=176
	struct _MultiSignal *spectralSignal; // size=904, offset=180
	struct _MultiSignal *materialSignal; // size=904, offset=184
	struct _MultiSignal *startUnitLoadedSignal; // size=904, offset=188
	struct _MultiSignal *startUnitMainSignal; // size=904, offset=192
	struct _MultiSignal *startGoingIntoWaterSignal; // size=904, offset=196
	struct _MultiSignal *startGoingOutOfWaterSignal; // size=904, offset=200
	long unitFlags; // size=0, offset=204
	struct _MultiSignal *SignalListStart; // size=904, offset=208
	struct _MultiSignal *SignalListEnd; // size=904, offset=212
	long numBSPLeaves; // size=0, offset=216
	struct EventPointers *PuzzleInstances; // size=0, offset=220
	long NumberOfPlanMarkers; // size=0, offset=224
	struct _PlanMkr *PlanMarkerList; // size=8, offset=228
	long NumberOfSFXMarkers; // size=0, offset=232
	struct _SFXMkr *SFXMarkerList; // size=36, offset=236
	unsigned long versionNumber; // size=0, offset=240
	char *dynamicMusicName; // size=0, offset=244
	long streamUnitID; // size=0, offset=248
	struct TClassAttr tClassAttr[16]; // size=64, offset=252
	short TODLighting[4][3]; // size=24, offset=316
	unsigned char TODbackColor[4][3]; // size=12, offset=340
	unsigned short TODfogNearFar[4][2]; // size=16, offset=352
	short TODRedScale; // size=0, offset=368
	short TODGrnScale; // size=0, offset=370
	short TODBluScale; // size=0, offset=372
	short TODfogNear; // size=0, offset=374
	short TODfogFar; // size=0, offset=376
	short short_pad; // size=0, offset=378
	unsigned char TODbackColorR; // size=0, offset=380
	unsigned char TODbackColorG; // size=0, offset=381
	unsigned char TODbackColorB; // size=0, offset=382
	unsigned char cpad3; // size=0, offset=383
	struct LightGroup *razielLightGroup; // size=64, offset=384
	struct LightGroup *razielSpectralLightGroup; // size=64, offset=388
};

struct _SavedCinematic // hashcode: 0x1E29151B (dec: 506008859)
{
	struct _Position position; // size=6, offset=0
	struct _Position focusPoint; // size=6, offset=6
	struct _Position base; // size=6, offset=12
	struct _Position targetPos; // size=6, offset=18
	struct _Position targetFocusPoint; // size=6, offset=24
	struct _Position targetBase; // size=6, offset=30
	struct _Rotation baseRot; // size=8, offset=36
	struct _Rotation focusRotation; // size=8, offset=44
	struct _Rotation targetFocusRotation; // size=8, offset=52
	short focusDistance; // size=0, offset=60
	short targetFocusDistance; // size=0, offset=62
	struct _SVector focusPointVel; // size=8, offset=64
	struct _SVector focusPointAccl; // size=8, offset=72
	struct _SVector baseVel; // size=8, offset=80
	struct _SVector baseAccl; // size=8, offset=88
	long maxVel; // size=0, offset=96
	struct MultiSpline *posSpline; // size=0, offset=100
	struct MultiSpline *targetSpline; // size=0, offset=104
	struct Level *level; // size=0, offset=108
};

struct BSPTree // hashcode: 0x17800192 (dec: 394264978)
{
	struct _BSPNode *bspRoot; // size=44, offset=0
	struct _BSPLeaf *startLeaves; // size=48, offset=4
	struct _BSPLeaf *endLeaves; // size=48, offset=8
	struct _Position globalOffset; // size=6, offset=12
	short flags; // size=0, offset=18
	struct _Position localOffset; // size=6, offset=20
	short ID; // size=0, offset=26
	long splineID; // size=0, offset=28
	struct _Instance *instanceSpline; // size=664, offset=32
};

struct LightGroup // hashcode: 0xBB5FF847 (dec: -1151338425)
{
	struct MATRIX lightMatrix; // size=32, offset=0
	struct MATRIX colorMatrix; // size=32, offset=32
};

struct LightList // hashcode: 0xC8448BB7 (dec: -935031881)
{
	struct CVECTOR ambient; // size=4, offset=0
	long numLightGroups; // size=0, offset=4
	struct LightGroup *lightGroupList; // size=64, offset=8
};

struct PointLight // hashcode: 0xFEFDD2F2 (dec: -16919822)
{
	struct NodeType node; // size=8, offset=0
	unsigned char r; // size=0, offset=8
	unsigned char g; // size=0, offset=9
	unsigned char b; // size=0, offset=10
	unsigned char flags; // size=0, offset=11
	struct _Position position; // size=6, offset=12
	short radius; // size=0, offset=18
	long radiusSquared; // size=0, offset=20
};

struct SpotLight // hashcode: 0xEF8B4C2E (dec: -276083666)
{
	struct NodeType node; // size=8, offset=0
	unsigned char r; // size=0, offset=8
	unsigned char g; // size=0, offset=9
	unsigned char b; // size=0, offset=10
	unsigned char flags; // size=0, offset=11
	struct _Position centroid; // size=6, offset=12
	short radius; // size=0, offset=18
	long radiusSquared; // size=0, offset=20
	struct _Position position; // size=6, offset=24
	struct _Position direction; // size=6, offset=30
	short cosFalloffAngle; // size=0, offset=36
	short attenuationScale; // size=0, offset=38
};

struct LightInfo // hashcode: 0x2A95530E (dec: 714429198)
{
	long numPointLights; // size=0, offset=0
	struct PointLight pointLightPool[32]; // size=768, offset=4
	struct NodeType usedPointLightList; // size=8, offset=772
	struct NodeType freePointLightList; // size=8, offset=780
	struct NodeType activePointLightList; // size=8, offset=788
	long numSpotLights; // size=0, offset=796
	struct SpotLight spotLightPool[8]; // size=320, offset=800
	struct NodeType usedSpotLightList; // size=8, offset=1120
	struct NodeType freeSpotLightList; // size=8, offset=1128
	struct NodeType activeSpotLightList; // size=8, offset=1136
	long numSavedColors; // size=0, offset=1144
};

struct _VMOffset // hashcode: 0x680AC445 (dec: 1745536069)
{
	short dx; // size=0, offset=0
	short dy; // size=0, offset=2
	short dz; // size=0, offset=4
};

struct _VMColorOffset // hashcode: 0xFD3FB530 (dec: -46156496)
{
	char dr; // size=0, offset=0
	char dg; // size=0, offset=1
	char db; // size=0, offset=2
};

struct _VMInterpolated // hashcode: 0x3A40B5C0 (dec: 977319360)
{
	short tvIdx; // size=0, offset=0
	short startIdx; // size=0, offset=2
	short endIdx; // size=0, offset=4
	short time; // size=0, offset=6
};

struct _VMOffsetTable // hashcode: 0xE4A13881 (dec: -459196287)
{
	long numVMOffsets; // size=0, offset=0
	union {
		struct _VMOffset moveOffsets; // size=6, offset=0
		struct _VMColorOffset colorOffsets; // size=3, offset=0
	} offsets; // size=6, offset=4, found in object files: player.o, player.o
};

struct _VMObject // hashcode: 0x436E75EB (dec: 1131312619)
{
	unsigned short flags; // size=0, offset=0
	short bspIdx; // size=0, offset=2
	short materialIdx; // size=0, offset=4
	short spectralIdx; // size=0, offset=6
	short currentIdx; // size=0, offset=8
	short timeScale; // size=0, offset=10
	long timer; // size=0, offset=12
	struct _Position position; // size=6, offset=16
	short radius; // size=0, offset=22
	long radiusSquared; // size=0, offset=24
	long numVMOffsetTables; // size=0, offset=28
	struct _VMOffsetTable **vmoffsetTableList; // size=12, offset=32
	struct _VMOffsetTable *curVMOffsetTable; // size=12, offset=36
	long numVMVertices; // size=0, offset=40
	void *vmvertexList; // size=0, offset=44
	long numVMInterpolated; // size=0, offset=48
	struct _VMInterpolated *vminterpolatedList; // size=8, offset=52
	char *name; // size=0, offset=56
};

struct _VGroup // hashcode: 0x4421FB39 (dec: 1143077689)
{
	long id; // size=0, offset=0
	long numVertices; // size=0, offset=4
	struct _TVertex **vertexList; // size=12, offset=8
};

struct _HotSpot // hashcode: 0x6EC4F776 (dec: 1858402166)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short id; // size=0, offset=6
};

struct _PlanMkr // hashcode: 0xBC0DD043 (dec: -1139945405)
{
	struct _Position pos; // size=6, offset=0
	short id; // size=0, offset=6
};

struct _SFXMkr // hashcode: 0x74BB4848 (dec: 1958430792)
{
	unsigned char *soundData; // size=0, offset=0
	long uniqueID; // size=0, offset=4
	struct SoundInstance sfxTbl[4]; // size=12, offset=8
	struct _Position pos; // size=6, offset=20
	short pad; // size=0, offset=26
	long livesInOnePlace; // size=0, offset=28
	long inSpectral; // size=0, offset=32
};

struct TClassAttr // hashcode: 0x4DC02369 (dec: 1304437609)
{
	short flags; // size=0, offset=0
	unsigned short sound; // size=0, offset=2
};

struct _ColorType // hashcode: 0x440E837C (dec: 1141801852)
{
	unsigned char r; // size=0, offset=0
	unsigned char g; // size=0, offset=1
	unsigned char b; // size=0, offset=2
	unsigned char code; // size=0, offset=3
};

struct _CameraCore_Type // hashcode: 0xD341D51C (dec: -750660324)
{
	struct _Position position; // size=6, offset=0
	short pad1; // size=0, offset=6
	struct MATRIX vvNormalWorVecMat[2]; // size=64, offset=8
	long vvPlaneConsts[6]; // size=24, offset=72
	struct MATRIX *wcTransform; // size=32, offset=96
	long farPlane; // size=0, offset=100
	long projDistance; // size=0, offset=104
	long nearPlane; // size=0, offset=108
	struct MATRIX *wcTransform2; // size=32, offset=112
	struct MATRIX *cwTransform2; // size=32, offset=116
	struct _Normal viewVolumeNormal[5]; // size=40, offset=120
	int leftX; // size=0, offset=160
	int rightX; // size=0, offset=164
	int topY; // size=0, offset=168
	int bottomY; // size=0, offset=172
	struct _Rotation rotation; // size=8, offset=176
	short pad2; // size=0, offset=184
	struct _SVector screenScale; // size=8, offset=186
	short pad3; // size=0, offset=194
	struct _Position debugPos; // size=6, offset=196
	short pad4; // size=0, offset=202
	struct _Rotation debugRot; // size=8, offset=204
	short pad5; // size=0, offset=212
	struct _Position nondebugPos; // size=6, offset=214
	short pad6; // size=0, offset=220
};

struct PLAYER_114fake // hashcode: 0x5A1E67AD (dec: 1511942061)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: player.o, player.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: player.o, player.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: player.o, player.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: player.o, player.o
};

struct SpuVolume // hashcode: 0x1BD13981 (dec: 466696577)
{
	short left; // size=0, offset=0
	short right; // size=0, offset=2
};

struct SpuExtAttr // hashcode: 0x0A5C9682 (dec: 173840002)
{
	struct SpuVolume volume; // size=4, offset=0
	long reverb; // size=0, offset=4
	long mix; // size=0, offset=8
};

struct SpuStVoiceAttr // hashcode: 0xACA70F9A (dec: -1398337638)
{
	char status; // size=0, offset=0
	char pad1; // size=0, offset=1
	char pad2; // size=0, offset=2
	char pad3; // size=0, offset=3
	long last_size; // size=0, offset=4
	unsigned long buf_addr; // size=0, offset=8
	unsigned long data_addr; // size=0, offset=12
};

struct AadSoundBankHdr // hashcode: 0xC23EC82F (dec: -1036072913)
{
	unsigned long bankID; // size=0, offset=0
	unsigned long headerSize; // size=0, offset=4
	int bankVersion; // size=0, offset=8
	int numPrograms; // size=0, offset=12
	int numTones; // size=0, offset=16
	int numWaves; // size=0, offset=20
	int numSequences; // size=0, offset=24
	int numLabels; // size=0, offset=28
	int reverbMode; // size=0, offset=32
	int reverbDepth; // size=0, offset=36
};

struct AadProgramAtr // hashcode: 0x6EE3A213 (dec: 1860411923)
{
	unsigned short numTones; // size=0, offset=0
	unsigned short firstTone; // size=0, offset=2
	unsigned char volume; // size=0, offset=4
	unsigned char panPosition; // size=0, offset=5
	unsigned short unused; // size=0, offset=6
};

struct AadToneAtr // hashcode: 0xD710C19D (dec: -686767715)
{
	unsigned char priority; // size=0, offset=0
	unsigned char parentProgram; // size=0, offset=1
	unsigned char volume; // size=0, offset=2
	unsigned char panPosition; // size=0, offset=3
	unsigned char centerNote; // size=0, offset=4
	char centerFine; // size=0, offset=5
	unsigned char minNote; // size=0, offset=6
	unsigned char maxNote; // size=0, offset=7
	unsigned char mode; // size=0, offset=8
	unsigned char pitchBendMax; // size=0, offset=9
	unsigned short adsr1; // size=0, offset=10
	unsigned short adsr2; // size=0, offset=12
	short waveIndex; // size=0, offset=14
};

struct _AadDynSfxFileHdr // hashcode: 0xE665347E (dec: -429575042)
{
	unsigned long snfID; // size=0, offset=0
	unsigned short snfVersion; // size=0, offset=4
	unsigned short uniqueID; // size=0, offset=6
	unsigned short handle; // size=0, offset=8
	unsigned short numSfxInFile; // size=0, offset=10
	struct _AadDynSfxFileHdr *prevDynSfxFile; // size=20, offset=12
	struct _AadDynSfxFileHdr *nextDynSfxFile; // size=20, offset=16
};

struct AadDynSfxAttr // hashcode: 0x0D1EC8D5 (dec: 220121301)
{
	unsigned short sfxID; // size=0, offset=0
	unsigned short waveID; // size=0, offset=2
	struct AadToneAtr toneAttr; // size=16, offset=4
	unsigned long waveSize; // size=0, offset=20
};

struct AadTempoCounter // hashcode: 0x4FFB42C2 (dec: 1341866690)
{
	unsigned long currentTick; // size=0, offset=0
	unsigned long currentError; // size=0, offset=4
	unsigned long tickTimeFixed; // size=0, offset=8
	unsigned long errorPerUpdate; // size=0, offset=12
	unsigned short ticksPerUpdate; // size=0, offset=16
	unsigned short ppqn; // size=0, offset=18
	unsigned long quarterNoteTime; // size=0, offset=20
};

struct AadSeqEvent // hashcode: 0xAC01768D (dec: -1409190259)
{
	unsigned long deltaTime; // size=0, offset=0
	unsigned char track; // size=0, offset=4
	unsigned char statusByte; // size=0, offset=5
	char dataByte[6]; // size=6, offset=6
};

struct _AadSequenceSlot // hashcode: 0xBB2DC343 (dec: -1154628797)
{
	struct AadTempoCounter tempo; // size=24, offset=0
	struct AadSeqEvent eventQueue[4][16]; // size=768, offset=24
	unsigned char eventIn[16]; // size=16, offset=792
	unsigned char eventOut[16]; // size=16, offset=808
	unsigned char eventsInQueue[16]; // size=16, offset=824
	unsigned char (*sequencePosition[16]); // size=64, offset=840
	unsigned long lastEventExecutedTime[16]; // size=64, offset=904
	unsigned char runningStatus[16]; // size=16, offset=968
	unsigned char trackFlags[16]; // size=16, offset=984
	unsigned char (*loopSequencePosition[4][16]); // size=256, offset=1000
	unsigned char loopCurrentNestLevel[16]; // size=16, offset=1256
	unsigned char loopCounter[4][16]; // size=64, offset=1272
	struct _AadSequenceSlot *selectedSlotPtr; // size=1488, offset=1336
	unsigned char selectedSlotNum; // size=0, offset=1340
	unsigned char selectedChannel; // size=0, offset=1341
	unsigned char sequenceNumberAssigned; // size=0, offset=1342
	unsigned char thisSlotNumber; // size=0, offset=1343
	unsigned short status; // size=0, offset=1344
	unsigned short channelMute; // size=0, offset=1346
	unsigned short delayedMuteMode; // size=0, offset=1348
	unsigned short delayedMuteCmds; // size=0, offset=1350
	unsigned short delayedUnMuteCmds; // size=0, offset=1352
	unsigned short unused; // size=0, offset=1354
	unsigned short enableSustainUpdate; // size=0, offset=1356
	unsigned short ignoreTranspose; // size=0, offset=1358
	unsigned char slotFlags; // size=0, offset=1360
	unsigned char slotID; // size=0, offset=1361
	unsigned char slotVolume; // size=0, offset=1362
	unsigned char slotPan; // size=0, offset=1363
	int *masterVolPtr; // size=0, offset=1364
	int selectedDynamicBank; // size=0, offset=1368
	int sequenceAssignedDynamicBank; // size=0, offset=1372
	unsigned char currentDynamicBank[16]; // size=16, offset=1376
	unsigned short pitchWheel[16]; // size=32, offset=1392
	unsigned char currentProgram[16]; // size=16, offset=1424
	unsigned char volume[16]; // size=16, offset=1440
	unsigned char panPosition[16]; // size=16, offset=1456
	char transpose[16]; // size=16, offset=1472
};

struct AadSfxCommand // hashcode: 0x3310EEED (dec: 856747757)
{
	unsigned char statusByte; // size=0, offset=0
	unsigned char dataByte[3]; // size=3, offset=1
	unsigned long ulongParam; // size=0, offset=4
	short shortParam; // size=0, offset=8
	unsigned short unused; // size=0, offset=10
};

struct AadSfxSlot // hashcode: 0xC604B7C8 (dec: -972769336)
{
	struct AadSfxCommand commandQueue[32]; // size=384, offset=0
	unsigned char commandIn; // size=0, offset=384
	unsigned char commandOut; // size=0, offset=385
	unsigned short commandsInQueue; // size=0, offset=386
	unsigned short handleCounter; // size=0, offset=388
	unsigned char sfxVolume; // size=0, offset=390
	unsigned char sfxPan; // size=0, offset=391
};

struct AadSynthVoice // hashcode: 0x9E515E00 (dec: -1638834688)
{
	unsigned long voiceMask; // size=0, offset=0
	unsigned long handle; // size=0, offset=4
	unsigned char voiceID; // size=0, offset=8
	unsigned char priority; // size=0, offset=9
	unsigned char note; // size=0, offset=10
	unsigned char unused; // size=0, offset=11
	unsigned char program; // size=0, offset=12
	unsigned char baseProg; // size=0, offset=13
	unsigned char volume; // size=0, offset=14
	unsigned char updateVol; // size=0, offset=15
	unsigned char pan; // size=0, offset=16
	unsigned char voiceNum; // size=0, offset=17
	unsigned short flags; // size=0, offset=18
	struct AadToneAtr *toneAtr; // size=16, offset=20
	struct AadProgramAtr *progAtr; // size=8, offset=24
};

struct AadDynamicLoadRequest // hashcode: 0x0D83C683 (dec: 226739843)
{
	int type; // size=0, offset=0
	int handle; // size=0, offset=4
	long directoryID; // size=0, offset=8
	long flags; // size=0, offset=12
	char fileName[12]; // size=12, offset=16
};

struct AadDynamicBankLoadInfo // hashcode: 0x602A9BB4 (dec: 1613405108)
{
	char sndFileName[32]; // size=32, offset=0
	char smpFileName[32]; // size=32, offset=32
	int dynamicBankIndex; // size=0, offset=64
	int loadOption; // size=0, offset=68
	void (*userCallbackProc)(); // size=0, offset=72
	unsigned long sramDataSize; // size=0, offset=76
	unsigned long nextSramAddr; // size=0, offset=80
	unsigned long flags; // size=0, offset=84
};

struct AadDynamicSfxLoadInfo // hashcode: 0x3B60E6CD (dec: 996206285)
{
	char snfFileName[40]; // size=40, offset=0
	char smfFileName[40]; // size=40, offset=40
	int fileHandle; // size=0, offset=80
	long directoryID; // size=0, offset=84
	long loadFlags; // size=0, offset=88
	long flags; // size=0, offset=92
	int smfLoadingState; // size=0, offset=96
	unsigned long bytesToLoad; // size=0, offset=100
	int numSfxToLoad; // size=0, offset=104
	int error; // size=0, offset=108
	unsigned long waveTransferAddr; // size=0, offset=112
	unsigned long totalSramUsed; // size=0, offset=116
	struct _AadDynSfxFileHdr *snfFile; // size=20, offset=120
	struct AadDynSfxAttr attr; // size=24, offset=124
};

struct AadNewSramBlockDesc // hashcode: 0xB90B8C61 (dec: -1190425503)
{
	unsigned short waveID; // size=0, offset=0
	unsigned short address; // size=0, offset=2
	unsigned short size; // size=0, offset=4
	unsigned char prevIndex; // size=0, offset=6
	unsigned char nextIndex; // size=0, offset=7
};

struct AadLoadedSfxToneAttr // hashcode: 0x411CE706 (dec: 1092413190)
{
	unsigned short referenceCount; // size=0, offset=0
	unsigned short waveID; // size=0, offset=2
	struct AadToneAtr toneAttr; // size=16, offset=4
};

struct AadLoadedSfxWaveAttr // hashcode: 0x027C2776 (dec: 41690998)
{
	unsigned short referenceCount; // size=0, offset=0
	unsigned char unused; // size=0, offset=2
	unsigned char sramHandle; // size=0, offset=3
};

struct AadSramDefragInfo // hashcode: 0x7F0485FB (dec: 2131002875)
{
	int status; // size=0, offset=0
	unsigned char *fragBuffer; // size=0, offset=4
	int masterListEntry; // size=0, offset=8
	int waveID; // size=0, offset=12
	unsigned long destSramAddr; // size=0, offset=16
	unsigned long srcSramAddr; // size=0, offset=20
	unsigned long moveSize; // size=0, offset=24
	unsigned long readSize; // size=0, offset=28
};

struct AadVolFader // hashcode: 0x25336B83 (dec: 624126851)
{
	int volumeStep; // size=0, offset=0
	int targetVolume; // size=0, offset=4
	void (*fadeCompleteCallback)(); // size=0, offset=8
};

struct gSoundData // hashcode: 0x5C7065D7 (dec: 1550869975)
{
	unsigned long gMasterVol; // size=0, offset=0
	unsigned long gMusicVol; // size=0, offset=4
	unsigned long gSfxVol; // size=0, offset=8
	unsigned long gVoiceVol; // size=0, offset=12
	char gSfxOn; // size=0, offset=16
	char gMusicOn; // size=0, offset=17
	char gVoiceOn; // size=0, offset=18
	char soundsLoaded; // size=0, offset=19
};

struct GameTracker // hashcode: 0x1AD7FFD8 (dec: 450363352)
{
	struct _GameData_Type gameData; // size=32, offset=0
	struct menu_t *menu; // size=0, offset=32
	struct memcard_t *memcard; // size=0, offset=36
	struct Level *level; // size=392, offset=40
	struct _Instance *playerInstance; // size=664, offset=44
	long drawPage; // size=0, offset=48
	struct _InstanceList *instanceList; // size=268, offset=52
	struct _InstancePool *instancePool; // size=39852, offset=56
	struct _VertexPool *vertexPool; // size=6336, offset=60
	struct _PrimPool *primPool; // size=96012, offset=64
	struct _ObjectTracker *GlobalObjects; // size=36, offset=68
	long controlCommand[2][5]; // size=40, offset=72
	long controlData[2][5]; // size=40, offset=112
	long overrideData[2][5]; // size=40, offset=152
	long debugFlags; // size=0, offset=192
	long debugFlags2; // size=0, offset=196
	struct CVECTOR wipeColor; // size=4, offset=200
	short wipeTime; // size=0, offset=204
	short maxWipeTime; // size=0, offset=206
	short wipeType; // size=0, offset=208
	short numGSignals; // size=0, offset=210
	void (*gSignal[16]); // size=64, offset=212
	struct LightInfo *lightInfo; // size=1148, offset=276
	void *reqDisp; // size=0, offset=280
	long *drawTimerReturn; // size=0, offset=284
	long usecsStartDraw; // size=0, offset=288
	void *disp; // size=0, offset=292
	unsigned long displayFrameCount; // size=0, offset=296
	unsigned long frameCount; // size=0, offset=300
	unsigned long fps30Count; // size=0, offset=304
	unsigned long vblFrames; // size=0, offset=308
	unsigned long vblCount; // size=0, offset=312
	long numMatrices; // size=0, offset=316
	long gameFlags; // size=0, offset=320
	long streamFlags; // size=0, offset=324
	void *drawNonAnimatedSegmentFunc; // size=0, offset=328
	void *drawAnimatedModelFunc; // size=0, offset=332
	void *drawDisplayPolytopeListFunc; // size=0, offset=336
	void *drawBgFunc; // size=0, offset=340
	struct Level *mainDrawUnit; // size=392, offset=344
	char baseAreaName[16]; // size=16, offset=348
	short levelDone; // size=0, offset=364
	short levelChange; // size=0, offset=366
	short hideBG; // size=0, offset=368
	short gameMode; // size=0, offset=370
	long currentHotSpot; // size=0, offset=372
	long StreamUnitID; // size=0, offset=376
	short SwitchToNewStreamUnit; // size=0, offset=380
	short SwitchToNewWarpIndex; // size=0, offset=382
	char S_baseAreaName[16]; // size=16, offset=384
	short toSignal; // size=0, offset=400
	short fromSignal; // size=0, offset=402
	char LastSignal; // size=0, offset=404
	short StreamNormalA; // size=0, offset=406
	short StreamNormalB; // size=0, offset=408
	short StreamNormalC; // size=0, offset=410
	long StreamNormalD; // size=0, offset=412
	long moveRazielToStreamID; // size=0, offset=416
	struct _ColorType animObjLine; // size=4, offset=420
	struct _ColorType animObjShade; // size=4, offset=424
	long introFXTime; // size=0, offset=428
	long maxIntroFXTime; // size=0, offset=432
	struct gSoundData sound; // size=20, offset=436
	short controllerMode; // size=0, offset=456
	unsigned char plan_collide_override; // size=0, offset=458
	unsigned char cheatMode; // size=0, offset=459
	char currentLvl; // size=0, offset=460
	char lastLvl; // size=0, offset=461
	struct Object *introFX; // size=76, offset=464
	struct Intro *introFXIntro; // size=76, offset=468
	unsigned long **drawOT; // size=0, offset=472
	unsigned long **dispOT; // size=0, offset=476
	struct P_TAG *savedOTStart; // size=8, offset=480
	struct P_TAG *savedOTEnd; // size=8, offset=484
	long introWaitTime; // size=0, offset=488
	long mirrorZPush; // size=0, offset=492
	long defVVRemoveDist; // size=0, offset=496
	long defRemoveDist; // size=0, offset=500
	struct _Position forcedStartPosition; // size=6, offset=504
	short hudCollDisplay; // size=0, offset=510
	long primMemUsed; // size=0, offset=512
	char demoMode; // size=0, offset=516
	char setDemoMode; // size=0, offset=517
	char demoIndex; // size=0, offset=518
	char demoEnabled; // size=0, offset=519
	long cheatTimerCount; // size=0, offset=520
	long playerCheatFlags; // size=0, offset=524
	long savedPlayerCameraMode; // size=0, offset=528
	long debugDrawFlags; // size=0, offset=532
	void *planningPool; // size=0, offset=536
	void *enemyPlanPool; // size=0, offset=540
	unsigned char block_collide_override; // size=0, offset=544
	unsigned char raziel_collide_override; // size=0, offset=545
	short timeOfDay; // size=0, offset=546
	long decoupleGame; // size=0, offset=548
	long multGameTime; // size=0, offset=552
	short spectral_fadeValue; // size=0, offset=556
	short material_fadeValue; // size=0, offset=558
	unsigned long drawTime; // size=0, offset=560
	unsigned long currentTime; // size=0, offset=564
	unsigned long currentMaterialTime; // size=0, offset=568
	unsigned long currentSpectralTime; // size=0, offset=572
	unsigned long currentTimeOfDayTime; // size=0, offset=576
	unsigned long lastLoopTime; // size=0, offset=580
	unsigned long timeMult; // size=0, offset=584
	unsigned long globalTimeMult; // size=0, offset=588
	unsigned long spectralTimeMult; // size=0, offset=592
	unsigned long materialTimeMult; // size=0, offset=596
	unsigned long currentTicks; // size=0, offset=600
	unsigned long totalTime; // size=0, offset=604
	unsigned long idleTime; // size=0, offset=608
	long visibleInstances; // size=0, offset=612
	int gameFramePassed; // size=0, offset=616
	unsigned long timeSinceLastGameFrame; // size=0, offset=620
	long frameRateLock; // size=0, offset=624
	short frameRate24fps; // size=0, offset=628
};

struct Spline // hashcode: 0xFB3D5813 (dec: -79865837)
{
	struct SplineKey *key; // size=32, offset=0
	short numkeys; // size=0, offset=4
	unsigned char type; // size=0, offset=6
	unsigned char flags; // size=0, offset=7
};

struct vecS // hashcode: 0xE2BAF7F0 (dec: -491063312)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
};

struct vecL // hashcode: 0x25DC6B01 (dec: 635202305)
{
	long x; // size=0, offset=0
	long y; // size=0, offset=4
	long z; // size=0, offset=8
};

struct SplineRotKey // hashcode: 0x89B84640 (dec: -1984412096)
{
	short count; // size=0, offset=0
	struct _G2Quat_Type q; // size=8, offset=2
};

struct RSpline // hashcode: 0x89BF98FB (dec: -1983932165)
{
	struct SplineRotKey *key; // size=10, offset=0
	short numkeys; // size=0, offset=4
	unsigned char type; // size=0, offset=6
	unsigned char flags; // size=0, offset=7
};

struct SplineKey // hashcode: 0x5B2BCE9C (dec: 1529597596)
{
	short count; // size=0, offset=0
	struct vecS point; // size=6, offset=2
	struct vecL dd; // size=12, offset=8
	struct vecL ds; // size=12, offset=20
};

struct SplineDef // hashcode: 0xAFF0503D (dec: -1343205315)
{
	short currkey; // size=0, offset=0
	unsigned short denomFlag; // size=0, offset=2
	long fracCurr; // size=0, offset=4
};

struct _HVertex // hashcode: 0x94027FD2 (dec: -1811775534)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short normal; // size=0, offset=6
	long pad; // size=0, offset=8
};

struct _MONAPI_Regenerator // hashcode: 0x1A0CA094 (dec: 437035156)
{
	unsigned long regenTime; // size=0, offset=0
	short introUniqueID; // size=0, offset=4
	short streamUnitID; // size=0, offset=6
};

struct __Event // hashcode: 0x8E99005C (dec: -1902575524)
{
	int ID; // size=0, offset=0
	int Data; // size=0, offset=4
};

struct __MessageQueue // hashcode: 0x29211D95 (dec: 690036117)
{
	int Head; // size=0, offset=0
	int Tail; // size=0, offset=4
	struct __Event Queue[16]; // size=128, offset=8
};

struct __State // hashcode: 0xFBE6882E (dec: -68777938)
{
	void (*Process)(); // size=0, offset=0
	struct __MessageQueue Event; // size=136, offset=4
	struct __MessageQueue Defer; // size=136, offset=140
	int Data1; // size=0, offset=276
	int Data2; // size=0, offset=280
};

struct POLY_F4 // hashcode: 0x4777CA51 (dec: 1199032913)
{
	unsigned long tag; // size=0, offset=0
	unsigned char r0; // size=0, offset=4
	unsigned char g0; // size=0, offset=5
	unsigned char b0; // size=0, offset=6
	unsigned char code; // size=0, offset=7
	short x0; // size=0, offset=8
	short y0; // size=0, offset=10
	short x1; // size=0, offset=12
	short y1; // size=0, offset=14
	short x2; // size=0, offset=16
	short y2; // size=0, offset=18
	short x3; // size=0, offset=20
	short y3; // size=0, offset=22
};

struct _SmallRotation // hashcode: 0xD53F9CB5 (dec: -717251403)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
};

struct EventPointers // hashcode: 0x8D42C18A (dec: -1925004918)
{
	long numPuzzles; // size=0, offset=0
	struct Event (*eventInstances[1]); // size=4, offset=4
};

struct Camera // hashcode: 0x71DC3ACD (dec: 1910258381)
{
	struct _CameraCore_Type core; // size=224, offset=0
	long shake; // size=0, offset=224
	short shakeFrame; // size=0, offset=228
	short shakeScale; // size=0, offset=230
	long flags; // size=0, offset=232
	long lock; // size=0, offset=236
	short mode; // size=0, offset=240
	short state; // size=0, offset=242
	short posState; // size=0, offset=244
	short rotState; // size=0, offset=246
	short tiltState; // size=0, offset=248
	short distanceState; // size=0, offset=250
	short lagZ; // size=0, offset=252
	short tilt; // size=0, offset=254
	struct _Position focusPoint; // size=6, offset=256
	short focusDistance; // size=0, offset=262
	struct _Instance *focusInstance; // size=664, offset=264
	struct _Position oldFocusInstancePos; // size=6, offset=268
	struct _Position newFocusInstancePos; // size=6, offset=274
	struct _Rotation oldFocusInstanceRot; // size=8, offset=280
	struct _Rotation newFocusInstanceRot; // size=8, offset=288
	struct _SVector focusInstanceVelVec; // size=8, offset=296
	struct _Position focusLeadPivot; // size=6, offset=304
	struct _Position focusOffset; // size=6, offset=310
	struct _Rotation focusRotation; // size=8, offset=316
	short tiltVel; // size=0, offset=324
	short tiltAccl; // size=0, offset=326
	struct _SVector positionVel; // size=8, offset=328
	struct _SVector positionAccl; // size=8, offset=336
	struct _SVector focusPointVel; // size=8, offset=344
	struct _SVector focusPointAccl; // size=8, offset=352
	short focusDistanceVel; // size=0, offset=360
	short focusDistanceAccl; // size=0, offset=362
	struct _SVector focusRotVel; // size=8, offset=364
	struct _SVector focusRotAccl; // size=8, offset=372
	struct _SVector maxFocusVel; // size=8, offset=380
	struct _SVector rotationVel; // size=8, offset=388
	struct _SVector rotationAccl; // size=8, offset=396
	short maxVel; // size=0, offset=404
	short maxRot; // size=0, offset=406
	struct _Position targetPos; // size=6, offset=408
	short targetTilt; // size=0, offset=414
	struct _Rotation targetRotation; // size=8, offset=416
	short targetFocusDistance; // size=0, offset=424
	struct _Position targetFocusPoint; // size=6, offset=426
	short collisionTargetFocusDistance; // size=0, offset=432
	struct _Rotation targetFocusRotation; // size=8, offset=434
	short tfaceTilt; // size=0, offset=442
	struct _Rotation collisionTargetFocusRotation; // size=8, offset=444
	short smooth; // size=0, offset=452
	struct _CameraKey *cameraKey; // size=24, offset=456
	struct _Sphere focusSphere; // size=12, offset=460
	struct _Sphere smallBaseSphere; // size=12, offset=472
	struct _Sphere posSphere; // size=12, offset=484
	short lookTimer; // size=0, offset=496
	short lookSavedMode; // size=0, offset=498
	short presetIndex; // size=0, offset=500
	short presetFocusDistance[3]; // size=6, offset=502
	long minFocusDistance; // size=0, offset=508
	long maxFocusDistance; // size=0, offset=512
	long minTilt; // size=0, offset=516
	long maxTilt; // size=0, offset=520
	long pad[3]; // size=12, offset=524
	long minXYDist; // size=0, offset=536
	long maxXYDist; // size=0, offset=540
	long oppositeError; // size=0, offset=544
	long tempsplinePointAhead; // size=0, offset=548
	long noTeleport; // size=0, offset=552
	long focusDistanceList[3][3]; // size=36, offset=556
	long tiltList[3][3]; // size=36, offset=592
	long cineControl; // size=0, offset=628
	short stack; // size=0, offset=632
	short targetStack; // size=0, offset=634
	long savedMode[3]; // size=12, offset=636
	long savedTargetFocusDistance[3]; // size=12, offset=648
	struct _Rotation savedFocusRotation; // size=8, offset=660
	short savedFocusDistance; // size=0, offset=668
	short signalFocusDistance; // size=0, offset=670
	struct _SavedCinematic savedCinematic[3]; // size=336, offset=672
	struct _Rotation savedfocusRotation; // size=8, offset=1008
	struct _Position signalPos; // size=6, offset=1016
	short pad11; // size=0, offset=1022
	struct _Rotation signalRot; // size=8, offset=1024
	short forced_movement; // size=0, offset=1032
	short last_forced_movement; // size=0, offset=1034
	short rotDirection; // size=0, offset=1036
	unsigned long lastModTime; // size=0, offset=1040
	struct _Rotation lookRot; // size=8, offset=1044
	struct MultiSpline *Spline00; // size=0, offset=1052
	struct MultiSpline *Spline01; // size=0, offset=1056
	struct {
		struct {
			struct MultiSpline *posSpline; // size=0, offset=0
			struct MultiSpline *targetSpline; // size=0, offset=4
			struct _SVector lastSplinePos; // size=8, offset=8
			short splinePointAhead; // size=0, offset=16
			short cinema_done; // size=0, offset=18
			int splinecam_currkey; // size=0, offset=20
			int splinecam_helpkey; // size=0, offset=24
		} Cinematic; // size=28, offset=0, found in object files: debug.o, debug.o
		struct {
			struct _Position offset; // size=6, offset=0
			struct _Rotation rotation; // size=8, offset=6
			long focusDistance; // size=0, offset=16
		} Idle; // size=20, offset=28, found in object files: debug.o, debug.o
		struct {
			struct _TFace *tface; // size=12, offset=0
			struct _TFace *oldTFace; // size=12, offset=4
			struct _SVector oldTargetRot; // size=8, offset=8
			long timer; // size=0, offset=16
			struct _SVector oldFocusInstancePos; // size=8, offset=20
		} Behind; // size=28, offset=48, found in object files: debug.o, debug.o
		struct {
			long stopTimer; // size=0, offset=0
			long stopHit; // size=0, offset=4
			struct _TFace *tface; // size=12, offset=8
			struct _TFace *oldTFace; // size=12, offset=12
			long hit; // size=0, offset=16
		} Follow; // size=20, offset=76, found in object files: debug.o, debug.o
	} data; // size=96, offset=1060, found in object files: debug.o, debug.o
	long cuckooTimer; // size=0, offset=1156
	short teleportZRot; // size=0, offset=1160
	short extraZRot; // size=0, offset=1162
	short extraXRot; // size=0, offset=1164
	short leftTimer; // size=0, offset=1166
	short rightTimer; // size=0, offset=1168
	short collideRotControl; // size=0, offset=1170
	short collision_lastPush; // size=0, offset=1172
	short collision_timer; // size=0, offset=1174
	unsigned long prev_instance_mode; // size=0, offset=1176
	unsigned long instance_mode; // size=0, offset=1180
	long instance_xyvel; // size=0, offset=1184
	long instance_prev_xyvel; // size=0, offset=1188
	struct _Position real_focuspoint; // size=6, offset=1192
	short always_rotate_flag; // size=0, offset=1198
	short follow_flag; // size=0, offset=1200
	short actual_x_rot; // size=0, offset=1202
	short actual_vel_x; // size=0, offset=1204
	short actual_acc_x; // size=0, offset=1206
	short x_rot_change; // size=0, offset=1208
	short focuspoint_fallz; // size=0, offset=1210
	short lead_angle; // size=0, offset=1212
	short lead_vel; // size=0, offset=1214
	short lead_accl; // size=0, offset=1216
	short lead_timer; // size=0, offset=1218
};

struct DebugMenuLine // hashcode: 0xA95B3709 (dec: -1453639927)
{
	enum DEBUG_LINE_TYPE type; // size=4, offset=0
	long lower; // size=0, offset=4
	long upper; // size=0, offset=8
	char *text; // size=0, offset=12
	long *var_address; // size=0, offset=16
	long bit_mask; // size=0, offset=20
};

struct _ButtonTexture // hashcode: 0xF98FC03F (dec: -108019649)
{
	short tpage; // size=0, offset=0
	short clut; // size=0, offset=2
	short textureW; // size=0, offset=4
	short textureH; // size=0, offset=6
	struct _BlockVramEntry *vramBlock; // size=0, offset=8
	long xshift; // size=0, offset=12
};

struct _BlockVramEntry // hashcode: 0x13235498 (dec: 321082520)
{
	struct _BlockVramEntry *next; // size=28, offset=0
	unsigned char type; // size=0, offset=4
	unsigned char flags; // size=0, offset=5
	short time; // size=0, offset=6
	long ID; // size=0, offset=8
	short x; // size=0, offset=12
	short y; // size=0, offset=14
	short w; // size=0, offset=16
	short h; // size=0, offset=18
	long area; // size=0, offset=20
	union {
		struct _StreamUnit *streamUnit; // size=64, offset=0
		struct _ObjectTracker *streamObject; // size=36, offset=0
		struct _ButtonTexture *button; // size=16, offset=0
	} udata; // size=4, offset=24, found in object files: debug.o, debug.o
};

struct FontChar // hashcode: 0xDB3B12BF (dec: -616885569)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	char c; // size=0, offset=4
	char color; // size=0, offset=5
};

struct _BigFileEntry // hashcode: 0x1CD70C00 (dec: 483855360)
{
	long fileHash; // size=0, offset=0
	long fileLen; // size=0, offset=4
	long filePos; // size=0, offset=8
	long checkSumFull; // size=0, offset=12
};

struct _BigFileDirEntry // hashcode: 0x6997130A (dec: 1771508490)
{
	short streamUnitID; // size=0, offset=0
	short numFiles; // size=0, offset=2
	long subDirOffset; // size=0, offset=4
};

struct _BigFileDir // hashcode: 0xB00EFBC4 (dec: -1341195324)
{
	long numFiles; // size=0, offset=0
	struct _BigFileEntry fileList[0]; // size=0, offset=4
};

struct _BigFile // hashcode: 0x80BCE80A (dec: -2135103478)
{
	long bigfileBaseOffset; // size=0, offset=0
	struct _BigFileDir *rootDir; // size=4, offset=4
	struct _BigFileDir *currentDir; // size=4, offset=8
	struct _BigFileDir *cachedDir; // size=4, offset=12
	long currentDirID; // size=0, offset=16
	long cachedDirID; // size=0, offset=20
	long searchDirID; // size=0, offset=24
	long numSubDirs; // size=0, offset=28
	struct _BigFileDirEntry *subDirList; // size=8, offset=32
};

struct _NonBlockLoadEntry // hashcode: 0x0055D133 (dec: 5624115)
{
	long fileHash; // size=0, offset=0
	long dirHash; // size=0, offset=4
	long filePos; // size=0, offset=8
	long *loadAddr; // size=0, offset=12
	long loadSize; // size=0, offset=16
	long checksum; // size=0, offset=20
	long checksumType; // size=0, offset=24
	long memType; // size=0, offset=28
	long posInFile; // size=0, offset=32
	void *retFunc; // size=0, offset=36
	void *retData; // size=0, offset=40
	void *retData2; // size=0, offset=44
	void **retPointer; // size=0, offset=48
	char fileName[48]; // size=48, offset=52
};

struct _ReadQueueEntry // hashcode: 0xCD6A97EC (dec: -848652308)
{
	long readStartPos; // size=0, offset=0
	long readSize; // size=0, offset=4
	long readCurSize; // size=0, offset=8
	void *readStartDest; // size=0, offset=12
	void *readCurDest; // size=0, offset=16
	long readStatus; // size=0, offset=20
	long checksum; // size=0, offset=24
	long checksumType; // size=0, offset=28
	void *retFunc; // size=0, offset=32
	void *retData; // size=0, offset=36
	void *retData2; // size=0, offset=40
};

struct _FX_MATRIX // hashcode: 0x835750F4 (dec: -2091429644)
{
	struct NodeType node; // size=8, offset=0
	long flags; // size=0, offset=8
	struct MATRIX lwTransform; // size=32, offset=12
};

struct _FX_PRIM // hashcode: 0x3BC7DC27 (dec: 1002953767)
{
	struct NodeType node; // size=8, offset=0
	struct TextureMT3 *texture; // size=16, offset=8
	long flags; // size=0, offset=12
	long timeToLive; // size=0, offset=16
	void *process; // size=0, offset=20
	struct _FX_MATRIX *matrix; // size=44, offset=24
	long color; // size=0, offset=28
	long startColor; // size=0, offset=32
	long endColor; // size=0, offset=36
	short colorFadeValue; // size=0, offset=40
	short colorFadeStep; // size=0, offset=42
	struct _Position position; // size=6, offset=44
	short fadeStep; // size=0, offset=50
	short fadeValue[4]; // size=8, offset=52
	struct _Position v0; // size=6, offset=60
	short work0; // size=0, offset=66
	struct _Position v1; // size=6, offset=68
	short work1; // size=0, offset=74
	struct _Position v2; // size=6, offset=76
	short work2; // size=0, offset=82
	struct _Position v3; // size=6, offset=84
	short work3; // size=0, offset=90
	union {
		struct {
			struct _Instance *parent; // size=664, offset=0
			long segment; // size=0, offset=4
		} flame; // size=8, offset=0, found in object files: debug.o, debug.o
		struct {
			short xVel; // size=0, offset=0
			short yVel; // size=0, offset=2
			short zVel; // size=0, offset=4
			short xAccl; // size=0, offset=6
			short yAccl; // size=0, offset=8
			short zAccl; // size=0, offset=10
		} phys; // size=12, offset=0, found in object files: debug.o, debug.o
	} duo; // size=12, offset=92, found in object files: debug.o, debug.o
	struct {
		struct TextureMT3 *texMem; // size=16, offset=0
		struct AniTex *aniTextures; // size=16, offset=4
		short curFrame; // size=0, offset=8
	} ani; // size=12, offset=104, found in object files: debug.o, debug.o
};

struct BASIC_LINE_G2 // hashcode: 0x790F383C (dec: 2031040572)
{
	unsigned char r0; // size=0, offset=0
	unsigned char g0; // size=0, offset=1
	unsigned char b0; // size=0, offset=2
	unsigned char code; // size=0, offset=3
	short x0; // size=0, offset=4
	short y0; // size=0, offset=6
	unsigned char r1; // size=0, offset=8
	unsigned char g1; // size=0, offset=9
	unsigned char b1; // size=0, offset=10
	unsigned char p1; // size=0, offset=11
	short x1; // size=0, offset=12
	short y1; // size=0, offset=14
};

struct _BASIC_G4 // hashcode: 0x4AEC9AD6 (dec: 1257020118)
{
	unsigned char r0; // size=0, offset=0
	unsigned char g0; // size=0, offset=1
	unsigned char b0; // size=0, offset=2
	unsigned char code; // size=0, offset=3
	short x0; // size=0, offset=4
	short y0; // size=0, offset=6
	unsigned char r1; // size=0, offset=8
	unsigned char g1; // size=0, offset=9
	unsigned char b1; // size=0, offset=10
	unsigned char pad1; // size=0, offset=11
	short x1; // size=0, offset=12
	short y1; // size=0, offset=14
	unsigned char r2; // size=0, offset=16
	unsigned char g2; // size=0, offset=17
	unsigned char b2; // size=0, offset=18
	unsigned char pad2; // size=0, offset=19
	short x2; // size=0, offset=20
	short y2; // size=0, offset=22
	unsigned char r3; // size=0, offset=24
	unsigned char g3; // size=0, offset=25
	unsigned char b3; // size=0, offset=26
	unsigned char pad3; // size=0, offset=27
	short x3; // size=0, offset=28
	short y3; // size=0, offset=30
};

struct _BASIC_F4 // hashcode: 0x49753F54 (dec: 1232420692)
{
	unsigned char r0; // size=0, offset=0
	unsigned char g0; // size=0, offset=1
	unsigned char b0; // size=0, offset=2
	unsigned char code; // size=0, offset=3
	short x0; // size=0, offset=4
	short y0; // size=0, offset=6
	short x1; // size=0, offset=8
	short y1; // size=0, offset=10
	short x2; // size=0, offset=12
	short y2; // size=0, offset=14
	short x3; // size=0, offset=16
	short y3; // size=0, offset=18
};

struct __BubbleParams // hashcode: 0x95A48FCE (dec: -1784377394)
{
	short DisperseFrames; // size=0, offset=0
	short KillScale; // size=0, offset=2
	short MinSplashSize; // size=0, offset=4
	short MaxSpeed; // size=0, offset=6
	short MaxSpeedRange; // size=0, offset=8
	short ScaleRate; // size=0, offset=10
	short ScaleRateRange; // size=0, offset=12
	short StartScale; // size=0, offset=14
	short StartScaleRange; // size=0, offset=16
	short UniqueBubbles; // size=0, offset=18
};

struct _GenericParticleParams // hashcode: 0x1C1255FF (dec: 470963711)
{
	short size; // size=0, offset=0
	unsigned char StartOnInit; // size=0, offset=2
	unsigned char type; // size=0, offset=3
	short birthRadius; // size=0, offset=4
	char startSegment; // size=0, offset=6
	char endSegment; // size=0, offset=7
	struct _Position direction; // size=6, offset=8
	unsigned char spectral_colorize; // size=0, offset=14
	unsigned char absolute_direction; // size=0, offset=15
	char accx; // size=0, offset=16
	char accy; // size=0, offset=17
	char accz; // size=0, offset=18
	char useInstanceModel; // size=0, offset=19
	unsigned char startColor_red; // size=0, offset=20
	unsigned char startColor_green; // size=0, offset=21
	unsigned char startColor_blue; // size=0, offset=22
	char model; // size=0, offset=23
	unsigned char endColor_red; // size=0, offset=24
	unsigned char endColor_green; // size=0, offset=25
	unsigned char endColor_blue; // size=0, offset=26
	char texture; // size=0, offset=27
	short lifeTime; // size=0, offset=28
	unsigned char primLifeTime; // size=0, offset=30
	char use_child; // size=0, offset=31
	short startFadeValue; // size=0, offset=32
	short fadeStep; // size=0, offset=34
	char numberBirthParticles; // size=0, offset=36
	char z_undulation_mode; // size=0, offset=37
	short scaleSpeed; // size=0, offset=38
	struct _Position offset; // size=6, offset=40
	short startScale; // size=0, offset=46
};

struct _GenericRibbonParams // hashcode: 0x8D0DEAF5 (dec: -1928467723)
{
	char id; // size=0, offset=0
	char StartOnInit; // size=0, offset=1
	char startSegment; // size=0, offset=2
	char endSegment; // size=0, offset=3
	char type; // size=0, offset=4
	char use_child; // size=0, offset=5
	short ribbonLifeTime; // size=0, offset=6
	short faceLifeTime; // size=0, offset=8
	short startFadeValue; // size=0, offset=10
	long startColor; // size=0, offset=12
	long endColor; // size=0, offset=16
};

struct _GenericGlowParams // hashcode: 0xCB7D507A (dec: -880979846)
{
	char StartOnInit; // size=0, offset=0
	unsigned char segment; // size=0, offset=1
	unsigned char segmentEnd; // size=0, offset=2
	char numSegments; // size=0, offset=3
	unsigned char color_num; // size=0, offset=4
	char use_child; // size=0, offset=5
	unsigned char numColors; // size=0, offset=6
	char id; // size=0, offset=7
	long atuColorCycleRate; // size=0, offset=8
	short width; // size=0, offset=12
	short height; // size=0, offset=14
	long lifetime; // size=0, offset=16
	short fadein_time; // size=0, offset=20
	short fadeout_time; // size=0, offset=22
};

struct _GenericLightningParams // hashcode: 0x2D05BEC5 (dec: 755351237)
{
	char type; // size=0, offset=0
	char use_child; // size=0, offset=1
	short lifeTime; // size=0, offset=2
	short deg; // size=0, offset=4
	short deg_inc; // size=0, offset=6
	struct _Position start_offset; // size=6, offset=8
	char startSeg; // size=0, offset=14
	char endSeg; // size=0, offset=15
	struct _Position end_offset; // size=6, offset=16
	char matrixSeg; // size=0, offset=22
	unsigned char segs; // size=0, offset=23
	short width; // size=0, offset=24
	short small_width; // size=0, offset=26
	short sine_size; // size=0, offset=28
	short variation; // size=0, offset=30
	long color; // size=0, offset=32
	long glow_color; // size=0, offset=36
};

struct _GenericBlastringParams // hashcode: 0x40C5E9AC (dec: 1086712236)
{
	char type; // size=0, offset=0
	char use_child; // size=0, offset=1
	short lifeTime; // size=0, offset=2
	struct _Position offset; // size=6, offset=4
	short matrixSeg; // size=0, offset=10
	char segment; // size=0, offset=12
	char sortInWorld; // size=0, offset=13
	short radius; // size=0, offset=14
	short size1; // size=0, offset=16
	short size2; // size=0, offset=18
	short endRadius; // size=0, offset=20
	short colorchange_radius; // size=0, offset=22
	int vel; // size=0, offset=24
	int accl; // size=0, offset=28
	short height1; // size=0, offset=32
	short height2; // size=0, offset=34
	short height3; // size=0, offset=36
	short predator_offset; // size=0, offset=38
	long startColor; // size=0, offset=40
	long endColor; // size=0, offset=44
};

struct _GenericFlashParams // hashcode: 0xD1187CAC (dec: -786924372)
{
	short type; // size=0, offset=0
	short timeToColor; // size=0, offset=2
	long color; // size=0, offset=4
	short timeAtColor; // size=0, offset=8
	short timeFromColor; // size=0, offset=10
};

struct _StreamUnit // hashcode: 0x8DBD8F8C (dec: -1916956788)
{
	long StreamUnitID; // size=0, offset=0
	short used; // size=0, offset=4
	short flags; // size=0, offset=6
	struct Level *level; // size=392, offset=8
	char baseAreaName[16]; // size=16, offset=12
	short toSignal; // size=0, offset=28
	short fromSignal; // size=0, offset=30
	long FrameCount; // size=0, offset=32
	short eventVariables[6]; // size=12, offset=36
	long FogColor; // size=0, offset=48
	short UnitFogFar; // size=0, offset=52
	short UnitFogNear; // size=0, offset=54
	short TargetFogFar; // size=0, offset=56
	short TargetFogNear; // size=0, offset=58
	short sfxFileHandle; // size=0, offset=60
	short pad; // size=0, offset=62
};

struct XAFileInfo // hashcode: 0x146DFE7F (dec: 342752895)
{
	int startPos; // size=0, offset=0
};

struct CdCommand // hashcode: 0xA5C7C0A4 (dec: -1513635676)
{
	unsigned short flags; // size=0, offset=0
	unsigned char unused; // size=0, offset=2
	unsigned char cdCommand; // size=0, offset=3
	unsigned char cdCmdParam[4]; // size=4, offset=4
};

struct VoiceCommand // hashcode: 0x5FD3C645 (dec: 1607714373)
{
	unsigned char voiceCmd; // size=0, offset=0
	unsigned char nextVoiceStatus; // size=0, offset=1
	unsigned short voiceCmdParam; // size=0, offset=2
};

struct _LoadQueueEntry // hashcode: 0xFCC91BD2 (dec: -53929006)
{
	struct _LoadQueueEntry *next; // size=112, offset=0
	short status; // size=0, offset=4
	char relocateBinary; // size=0, offset=6
	char mempackUsed; // size=0, offset=7
	struct _NonBlockLoadEntry loadEntry; // size=100, offset=8
	long endLoadTime; // size=0, offset=108
};

struct SavedBasic // hashcode: 0x029C9345 (dec: 43815749)
{
	unsigned char savedID; // size=0, offset=0
	unsigned char shiftedSaveSize; // size=0, offset=1
};

struct _SavedIntro // hashcode: 0xBA6B9291 (dec: -1167355247)
{
	unsigned char savedID; // size=0, offset=0
	unsigned char shiftedSaveSize; // size=0, offset=1
	unsigned char lightGroup; // size=0, offset=2
	unsigned char specturalLightGroup; // size=0, offset=3
	char name[8]; // size=8, offset=4
	short introUniqueID; // size=0, offset=12
	short streamUnitID; // size=0, offset=14
	short birthUnitID; // size=0, offset=16
	unsigned short attachedUniqueID; // size=0, offset=18
	struct _SmallRotation smallRotation; // size=6, offset=20
	struct _Position position; // size=6, offset=26
	long flags; // size=0, offset=32
	long flags2; // size=0, offset=36
};

struct SavedEvent // hashcode: 0xAAD4BDF2 (dec: -1428898318)
{
	unsigned char savedID; // size=0, offset=0
	unsigned char shiftedSaveSize; // size=0, offset=1
	short areaID; // size=0, offset=2
	short eventNumber; // size=0, offset=4
	short eventVariables[5]; // size=10, offset=6
};

struct SavedBspTree // hashcode: 0xC0C9F01C (dec: -1060507620)
{
	struct _Position localOffset; // size=6, offset=0
	unsigned char importantFlagsSaved; // size=0, offset=6
	unsigned char bspIndex; // size=0, offset=7
};

struct EventBasicObject // hashcode: 0x02440FE4 (dec: 38014948)
{
	short id; // size=0, offset=0
};

struct EventWildCardObject // hashcode: 0xBF1E373D (dec: -1088538819)
{
	short id; // size=0, offset=0
	short spad; // size=0, offset=2
	long unitID; // size=0, offset=4
	char *objectName; // size=0, offset=8
};

struct Event // hashcode: 0x001DBFE7 (dec: 1949671)
{
	short eventNumber; // size=0, offset=0
	short numInstances; // size=0, offset=2
	unsigned char numActions; // size=0, offset=4
	unsigned char processingPuppetShow; // size=0, offset=5
	short eventVariables[5]; // size=10, offset=6
	struct EventBasicObject **instanceList; // size=2, offset=16
	struct ScriptPCode **conditionalList; // size=8, offset=20
	struct ScriptPCode **actionList; // size=8, offset=24
};

struct ScriptPCode // hashcode: 0x05D75C5A (dec: 97999962)
{
	unsigned short sizeOfPcodeStream; // size=0, offset=0
	unsigned short conditionBits; // size=0, offset=2
	short *data; // size=0, offset=4
};

struct InstanceSpline // hashcode: 0x5B28EE39 (dec: 1529409081)
{
	struct _Instance *instance; // size=664, offset=0
	struct MultiSpline *spline; // size=80, offset=4
	long attribute; // size=0, offset=8
	long isParent; // size=0, offset=12
	long isClass; // size=0, offset=16
	long splineFlags; // size=0, offset=20
};

struct Vector3d // hashcode: 0xAB88D964 (dec: -1417094812)
{
	short vx; // size=0, offset=0
	short vy; // size=0, offset=2
	short vz; // size=0, offset=4
	short pad1; // size=0, offset=6
	short errorx; // size=0, offset=8
	short errory; // size=0, offset=10
	short errorz; // size=0, offset=12
	short pad2; // size=0, offset=14
	long streamUnitID; // size=0, offset=16
};

struct Rotation3d // hashcode: 0x120185DB (dec: 302089691)
{
	short vx; // size=0, offset=0
	short vy; // size=0, offset=2
	short vz; // size=0, offset=4
	short pad1; // size=0, offset=6
	short errorx; // size=0, offset=8
	short errory; // size=0, offset=10
	short errorz; // size=0, offset=12
	short pad2; // size=0, offset=14
	long attribute; // size=0, offset=16
};

struct InstanceObject // hashcode: 0x95FDE2A2 (dec: -1778523486)
{
	struct _Instance *instance; // size=664, offset=0
	long attribute; // size=0, offset=4
};

struct EventObject // hashcode: 0x4F1FAC97 (dec: 1327475863)
{
	struct Event *event; // size=28, offset=0
	long attribute; // size=0, offset=4
};

struct SavedEventObject // hashcode: 0x58ADC702 (dec: 1487783682)
{
	struct SavedBasic *savedEvent; // size=2, offset=0
	long attribute; // size=0, offset=4
	long areaID; // size=0, offset=8
	long eventNumber; // size=0, offset=12
};

struct GameObject // hashcode: 0x448B3FF6 (dec: 1149976566)
{
	long attribute; // size=0, offset=0
};

struct SignalObject // hashcode: 0x5BC697E8 (dec: 1539741672)
{
	struct _MultiSignal *msignal; // size=904, offset=0
	long attribute; // size=0, offset=4
};

struct IntroObject // hashcode: 0x528FAC37 (dec: 1385147447)
{
	struct Intro *intro; // size=76, offset=0
	long attribute; // size=0, offset=4
};

struct InstanceAnimate // hashcode: 0xED4107B2 (dec: -314505294)
{
	struct _Instance *instance; // size=664, offset=0
	long attribute; // size=0, offset=4
};

struct InstanceAnimateTexture // hashcode: 0xDD936D48 (dec: -577540792)
{
	struct _Instance *instance; // size=664, offset=0
	struct AniTex *aniTextures; // size=16, offset=4
	long attribute; // size=0, offset=8
};

struct ListObject // hashcode: 0x1CBB87EA (dec: 482052074)
{
	struct EventWildCardObject *eventInstance; // size=12, offset=0
	long attribute[5]; // size=20, offset=4
	long numberOfAttributes; // size=0, offset=24
	long lineID; // size=0, offset=28
};

struct SubListObject // hashcode: 0x697AE038 (dec: 1769660472)
{
	struct _Instance **instanceList; // size=664, offset=0
	long numberOfInstances; // size=0, offset=4
	long numberOfAttributes; // size=0, offset=8
	long attribute[5]; // size=20, offset=12
};

struct TGroupObject // hashcode: 0xDC675420 (dec: -597208032)
{
	struct BSPTree *bspTree; // size=36, offset=0
	struct _StreamUnit *streamUnit; // size=64, offset=4
	long attribute; // size=0, offset=8
	short arg[2]; // size=4, offset=12
};

struct ConstrictInfo // hashcode: 0x0362FA81 (dec: 56818305)
{
	struct _Instance *instance; // size=664, offset=0
	long attribute; // size=0, offset=4
};

struct CameraObject // hashcode: 0xAE75F471 (dec: -1368001423)
{
	struct Camera *camera; // size=1220, offset=0
	long frames; // size=0, offset=4
	long attribute; // size=0, offset=8
};

struct EventVmObject // hashcode: 0x2E9DDC2B (dec: 782097451)
{
	struct _VMObject *vmObjectPtr; // size=60, offset=0
	struct Level *level; // size=392, offset=4
	long attribute; // size=0, offset=8
};

struct AreaObject // hashcode: 0xC3E7BB5C (dec: -1008223396)
{
	struct _StreamUnit *streamUnit; // size=64, offset=0
	long attribute; // size=0, offset=4
	long unitID; // size=0, offset=8
};

struct SoundObject // hashcode: 0x12E32363 (dec: 316875619)
{
	short flags; // size=0, offset=0
	short attribute; // size=0, offset=2
	long soundNumber; // size=0, offset=4
	long value; // size=0, offset=8
	long duration; // size=0, offset=12
	union {
		struct _Instance *instance; // size=664, offset=0
		struct _SFXMkr *sfxMarker; // size=36, offset=0
	} data; // size=4, offset=16, found in object files: debug.o, debug.o
};

struct StackType // hashcode: 0xFD471538 (dec: -45673160)
{
	long id; // size=0, offset=0
	union {
		struct {
			long instanceNumber; // size=0, offset=0
			long attribute; // size=0, offset=4
		} Object; // size=8, offset=0, found in object files: debug.o, debug.o
		struct {
			struct _SavedIntro *intro; // size=40, offset=0
			long attribute; // size=0, offset=4
		} SavedIntroObject; // size=8, offset=0, found in object files: debug.o, debug.o
		struct InstanceSpline instanceSpline; // size=24, offset=0
		struct {
			long currentNumber; // size=0, offset=0
			long error; // size=0, offset=4
			short flags; // size=0, offset=8
		} Number; // size=12, offset=0, found in object files: debug.o, debug.o
		struct {
			short vx; // size=0, offset=0
			short vy; // size=0, offset=2
		} Vector2d; // size=4, offset=0, found in object files: debug.o, debug.o
		struct {
			char *pointer; // size=0, offset=0
		} CharPointer; // size=4, offset=0, found in object files: debug.o, debug.o
		struct {
			short *pointer; // size=0, offset=0
		} ShortPointer; // size=4, offset=0, found in object files: debug.o, debug.o
		struct {
			long *pointer; // size=0, offset=0
		} LongPointer; // size=4, offset=0, found in object files: debug.o, debug.o
		struct AreaObject areaObject; // size=12, offset=0
		struct InstanceObject instanceObject; // size=8, offset=0
		struct Vector3d vector3d; // size=20, offset=0
		struct Rotation3d rotation3d; // size=20, offset=0
		struct SignalObject signalObject; // size=8, offset=0
		struct EventObject eventObject; // size=8, offset=0
		struct GameObject gameObject; // size=4, offset=0
		struct ListObject listObject; // size=32, offset=0
		struct IntroObject introObject; // size=8, offset=0
		struct InstanceAnimate instanceAnimate; // size=8, offset=0
		struct InstanceAnimateTexture instanceAniTexture; // size=12, offset=0
		struct SavedEventObject savedEventObject; // size=16, offset=0
		struct SubListObject subListObject; // size=32, offset=0
		struct TGroupObject terrainGroup; // size=16, offset=0
		struct ConstrictInfo constrictInfo; // size=8, offset=0
		struct CameraObject cameraObject; // size=12, offset=0
		struct EventVmObject vmObject; // size=12, offset=0
		struct SoundObject soundObject; // size=20, offset=0
	} data; // size=32, offset=4, found in object files: debug.o, debug.o
};

struct __ReaverSaveDat // hashcode: 0x6C072417 (dec: 1812407319)
{
	unsigned long pad; // size=0, offset=0
};

struct debug_dispatch_t // hashcode: 0x27FCED60 (dec: 670887264)
{
	enum DEBUG_LINE_TYPE type; // size=4, offset=0
	void (*fn)(); // size=0, offset=4
};

struct debug_format_t // hashcode: 0x6E2CC554 (dec: 1848427860)
{
	int xpos; // size=0, offset=0
	int ypos; // size=0, offset=4
	int is_centered; // size=0, offset=8
};

struct POLY_GT3 // hashcode: 0xD669B49A (dec: -697715558)
{
	unsigned long tag; // size=0, offset=0
	unsigned char r0; // size=0, offset=4
	unsigned char g0; // size=0, offset=5
	unsigned char b0; // size=0, offset=6
	unsigned char code; // size=0, offset=7
	short x0; // size=0, offset=8
	short y0; // size=0, offset=10
	unsigned char u0; // size=0, offset=12
	unsigned char v0; // size=0, offset=13
	unsigned short clut; // size=0, offset=14
	unsigned char r1; // size=0, offset=16
	unsigned char g1; // size=0, offset=17
	unsigned char b1; // size=0, offset=18
	unsigned char p1; // size=0, offset=19
	short x1; // size=0, offset=20
	short y1; // size=0, offset=22
	unsigned char u1; // size=0, offset=24
	unsigned char v1; // size=0, offset=25
	unsigned short tpage; // size=0, offset=26
	unsigned char r2; // size=0, offset=28
	unsigned char g2; // size=0, offset=29
	unsigned char b2; // size=0, offset=30
	unsigned char p2; // size=0, offset=31
	short x2; // size=0, offset=32
	short y2; // size=0, offset=34
	unsigned char u2; // size=0, offset=36
	unsigned char v2; // size=0, offset=37
	unsigned short pad2; // size=0, offset=38
};

struct POLY_GT4 // hashcode: 0xF09EF1FF (dec: -258018817)
{
	unsigned long tag; // size=0, offset=0
	unsigned char r0; // size=0, offset=4
	unsigned char g0; // size=0, offset=5
	unsigned char b0; // size=0, offset=6
	unsigned char code; // size=0, offset=7
	short x0; // size=0, offset=8
	short y0; // size=0, offset=10
	unsigned char u0; // size=0, offset=12
	unsigned char v0; // size=0, offset=13
	unsigned short clut; // size=0, offset=14
	unsigned char r1; // size=0, offset=16
	unsigned char g1; // size=0, offset=17
	unsigned char b1; // size=0, offset=18
	unsigned char p1; // size=0, offset=19
	short x1; // size=0, offset=20
	short y1; // size=0, offset=22
	unsigned char u1; // size=0, offset=24
	unsigned char v1; // size=0, offset=25
	unsigned short tpage; // size=0, offset=26
	unsigned char r2; // size=0, offset=28
	unsigned char g2; // size=0, offset=29
	unsigned char b2; // size=0, offset=30
	unsigned char p2; // size=0, offset=31
	short x2; // size=0, offset=32
	short y2; // size=0, offset=34
	unsigned char u2; // size=0, offset=36
	unsigned char v2; // size=0, offset=37
	unsigned short pad2; // size=0, offset=38
	unsigned char r3; // size=0, offset=40
	unsigned char g3; // size=0, offset=41
	unsigned char b3; // size=0, offset=42
	unsigned char p3; // size=0, offset=43
	short x3; // size=0, offset=44
	short y3; // size=0, offset=46
	unsigned char u3; // size=0, offset=48
	unsigned char v3; // size=0, offset=49
	unsigned short pad3; // size=0, offset=50
};

struct _Vector // hashcode: 0x185ABB69 (dec: 408599401)
{
	long x; // size=0, offset=0
	long y; // size=0, offset=4
	long z; // size=0, offset=8
};

struct _PFace // hashcode: 0xB584310A (dec: -1249627894)
{
	unsigned long *tag; // size=0, offset=0
	unsigned char r0; // size=0, offset=4
	unsigned char g0; // size=0, offset=5
	unsigned char b0; // size=0, offset=6
	unsigned char code; // size=0, offset=7
	short x0; // size=0, offset=8
	short y0; // size=0, offset=10
	unsigned char u0; // size=0, offset=12
	unsigned char v0; // size=0, offset=13
	short clut; // size=0, offset=14
	short x1; // size=0, offset=16
	short y1; // size=0, offset=18
	unsigned char u1; // size=0, offset=20
	unsigned char v1; // size=0, offset=21
	unsigned short tpage; // size=0, offset=22
	short x2; // size=0, offset=24
	short y2; // size=0, offset=26
	unsigned char u2; // size=0, offset=28
	unsigned char v2; // size=0, offset=29
	short pad1; // size=0, offset=30
	long pad2; // size=0, offset=32
	long pad3; // size=0, offset=36
};

struct _PolytopeList // hashcode: 0x29C18E10 (dec: 700550672)
{
	long numPolytopes; // size=0, offset=0
	void (*polytope[1024]); // size=4096, offset=4
};

struct DRAW_109fake // hashcode: 0x6C06A294 (dec: 1812374164)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: draw.o, draw.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: draw.o, draw.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: draw.o, draw.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: draw.o, draw.o
};

struct UVTYPE // hashcode: 0xF3221407 (dec: -215870457)
{
	unsigned char u; // size=0, offset=0
	unsigned char v; // size=0, offset=1
	short pad; // size=0, offset=2
};

struct POLY_G3_SEMITRANS // hashcode: 0xF5BC152A (dec: -172223190)
{
	unsigned long tag; // size=0, offset=0
	unsigned long dr_tpage; // size=0, offset=4
	unsigned char r0; // size=0, offset=8
	unsigned char g0; // size=0, offset=9
	unsigned char b0; // size=0, offset=10
	unsigned char code; // size=0, offset=11
	short x0; // size=0, offset=12
	short y0; // size=0, offset=14
	unsigned char r1; // size=0, offset=16
	unsigned char g1; // size=0, offset=17
	unsigned char b1; // size=0, offset=18
	unsigned char pad1; // size=0, offset=19
	short x1; // size=0, offset=20
	short y1; // size=0, offset=22
	unsigned char r2; // size=0, offset=24
	unsigned char g2; // size=0, offset=25
	unsigned char b2; // size=0, offset=26
	unsigned char pad2; // size=0, offset=27
	short x2; // size=0, offset=28
	short y2; // size=0, offset=30
};

struct _POLY_NG4 // hashcode: 0x3EC03DC8 (dec: 1052786120)
{
	unsigned long tag; // size=0, offset=0
	unsigned long drawTPage1; // size=0, offset=4
	struct _BASIC_G4 p1; // size=32, offset=8
};

struct _GT3ZVertexD3D_Type // hashcode: 0x83E63288 (dec: -2082065784)
{
	float x; // size=0, offset=0
	float y; // size=0, offset=4
	float z; // size=0, offset=8
	float rhw; // size=0, offset=12
	unsigned int rgba; // size=0, offset=16
	float u; // size=0, offset=20
	float v; // size=0, offset=24
};

struct SP_SUBDIV_STRUCT // hashcode: 0x409957AF (dec: 1083791279)
{
	struct _SVector vertex0; // size=8, offset=0
	struct _SVector vertex1; // size=8, offset=8
	struct _SVector vertex2; // size=8, offset=16
	struct SVECTOR face_v0; // size=8, offset=24
	struct SVECTOR face_v1; // size=8, offset=32
	struct SVECTOR face_v2; // size=8, offset=40
	struct SVECTOR face_v01; // size=8, offset=48
	struct SVECTOR face_v12; // size=8, offset=56
	struct SVECTOR face_v20; // size=8, offset=64
	struct UVTYPE face_uv0; // size=4, offset=72
	struct UVTYPE face_uv1; // size=4, offset=76
	struct UVTYPE face_uv2; // size=4, offset=80
	struct UVTYPE face_uv01; // size=4, offset=84
	struct UVTYPE face_uv12; // size=4, offset=88
	struct UVTYPE face_uv20; // size=4, offset=92
	struct _ColorType color0; // size=4, offset=96
	struct _ColorType color1; // size=4, offset=100
	struct _ColorType color2; // size=4, offset=104
	struct _ColorType color01; // size=4, offset=108
	struct _ColorType color12; // size=4, offset=112
	struct _ColorType color20; // size=4, offset=116
	struct _Vector out[4]; // size=48, offset=120
	long color[4]; // size=16, offset=168
	long texinfo[3]; // size=12, offset=184
	struct DVECTOR sxy[4]; // size=16, offset=196
};

struct POLY_FT4 // hashcode: 0xF9F847B2 (dec: -101169230)
{
	unsigned long tag; // size=0, offset=0
	unsigned char r0; // size=0, offset=4
	unsigned char g0; // size=0, offset=5
	unsigned char b0; // size=0, offset=6
	unsigned char code; // size=0, offset=7
	short x0; // size=0, offset=8
	short y0; // size=0, offset=10
	unsigned char u0; // size=0, offset=12
	unsigned char v0; // size=0, offset=13
	unsigned short clut; // size=0, offset=14
	short x1; // size=0, offset=16
	short y1; // size=0, offset=18
	unsigned char u1; // size=0, offset=20
	unsigned char v1; // size=0, offset=21
	unsigned short tpage; // size=0, offset=22
	short x2; // size=0, offset=24
	short y2; // size=0, offset=26
	unsigned char u2; // size=0, offset=28
	unsigned char v2; // size=0, offset=29
	unsigned short pad1; // size=0, offset=30
	short x3; // size=0, offset=32
	short y3; // size=0, offset=34
	unsigned char u3; // size=0, offset=36
	unsigned char v3; // size=0, offset=37
	unsigned short pad2; // size=0, offset=38
};

struct FontTracker // hashcode: 0x22F7B28C (dec: 586658444)
{
	struct FontChar font_buffer[256]; // size=1536, offset=0
	long font_xpos; // size=0, offset=1536
	long font_ypos; // size=0, offset=1540
	long font_buffIndex; // size=0, offset=1544
	short font_tpage; // size=0, offset=1548
	short font_clut; // size=0, offset=1550
	short font_vramU; // size=0, offset=1552
	short font_vramV; // size=0, offset=1554
	short font_width; // size=0, offset=1556
	short sprite_sort_push; // size=0, offset=1558
	short font_vramX; // size=0, offset=1560
	short font_vramY; // size=0, offset=1562
	char color_global; // size=0, offset=1564
	char color_local; // size=0, offset=1565
};

struct FONT_117fake // hashcode: 0x6359F658 (dec: 1666840152)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: font.o, font.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: font.o, font.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: font.o, font.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: font.o, font.o
};

struct font_color_t // hashcode: 0x4612A44B (dec: 1175626827)
{
	int r; // size=0, offset=0
	int g; // size=0, offset=4
	int b; // size=0, offset=8
};

struct FontPos // hashcode: 0x5BE713A2 (dec: 1541870498)
{
	char x; // size=0, offset=0
	char y; // size=0, offset=1
	char w; // size=0, offset=2
	char h; // size=0, offset=3
};

struct GAMEPAD_114fake // hashcode: 0x085EF045 (dec: 140439621)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: gamepad.o, gamepad.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: gamepad.o, gamepad.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: gamepad.o, gamepad.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: gamepad.o, gamepad.o
};

struct JoypadMappingStruct // hashcode: 0x2D052501 (dec: 755311873)
{
	unsigned short psxData; // size=0, offset=0
	unsigned short translation; // size=0, offset=2
};

struct AnalogueData // hashcode: 0xBA98F400 (dec: -1164381184)
{
	unsigned short pad; // size=0, offset=0
	unsigned char xR; // size=0, offset=2
	unsigned char yR; // size=0, offset=3
	unsigned char xL; // size=0, offset=4
	unsigned char yL; // size=0, offset=5
};

struct ControllerPacket // hashcode: 0x786834C5 (dec: 2020095173)
{
	unsigned char transStatus; // size=0, offset=0
	unsigned char dataFormat; // size=0, offset=1
	union {
		unsigned short pad; // size=0, offset=0
		unsigned short multitap[16]; // size=32, offset=0
		unsigned short mouse[2]; // size=4, offset=0
		unsigned short negcon[3]; // size=6, offset=0
		struct AnalogueData analogue; // size=6, offset=0
	} data; // size=32, offset=2, found in object files: gamepad.o, gamepad.o
};

struct _G2EulerAngles_Type // hashcode: 0x3AA6C799 (dec: 984008601)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short order; // size=0, offset=6
};

struct _InstanceHandle // hashcode: 0xB737FB0B (dec: -1221068021)
{
	struct _Instance *instance; // size=664, offset=0
	long instanceID; // size=0, offset=4
};

struct evCollideInstanceStatsData // hashcode: 0x72E441C9 (dec: 1927561673)
{
	struct _Instance *instance; // size=664, offset=0
	unsigned long distance; // size=0, offset=4
	struct _SVector relativePosition; // size=8, offset=8
	long xyDistance; // size=0, offset=16
	long zDelta; // size=0, offset=20
};

struct INICommand // hashcode: 0x8BE1B64A (dec: -1948142006)
{
	short command; // size=0, offset=0
	short numParameters; // size=0, offset=2
	long parameter[0]; // size=0, offset=4
};

struct PhysObProperties // hashcode: 0x9B19BD7B (dec: -1692811909)
{
	unsigned short version; // size=0, offset=0
	unsigned short family; // size=0, offset=2
	unsigned short ID; // size=0, offset=4
	unsigned short Type; // size=0, offset=6
};

struct PhysObSplinter // hashcode: 0x778EFC18 (dec: 2005859352)
{
	long numSplintData; // size=0, offset=0
	void *splinterData; // size=0, offset=4
};

struct PhysObWeaponAttributes // hashcode: 0xC7D41523 (dec: -942402269)
{
	long Damage; // size=0, offset=0
	long AltDamage; // size=0, offset=4
	short knockBackDistance; // size=0, offset=8
	char knockBackFrames; // size=0, offset=10
	char dropSound; // size=0, offset=11
	char Class; // size=0, offset=12
	char ThrowSphere; // size=0, offset=13
	char LeftHandSphere; // size=0, offset=14
	char RightHandSphere; // size=0, offset=15
	struct _PhysObLight *Light; // size=0, offset=16
	struct PhysObSplinter splinter; // size=8, offset=20
};

struct _PhysObLight // hashcode: 0x9539F3EC (dec: -1791364116)
{
	unsigned char length; // size=0, offset=0
	unsigned char segment; // size=0, offset=1
	short speed; // size=0, offset=2
	struct LightTableEntry *lightTable; // size=8, offset=4
};

struct __PhysObProjectileData // hashcode: 0x78BFDD35 (dec: 2025839925)
{
	char model; // size=0, offset=0
	char startAnim; // size=0, offset=1
	char loopAnim; // size=0, offset=2
	char endAnim; // size=0, offset=3
	long flags; // size=0, offset=4
	struct PhysObWeaponAttributes *weapon; // size=28, offset=8
};

struct SwitchData // hashcode: 0x55A03B27 (dec: 1436564263)
{
	short state; // size=0, offset=0
	short accumulator; // size=0, offset=2
};

struct LightTableEntry // hashcode: 0x2683A29E (dec: 646161054)
{
	short r; // size=0, offset=0
	short g; // size=0, offset=2
	short b; // size=0, offset=4
	short radius; // size=0, offset=6
};

struct SavedIntroSmall // hashcode: 0x06694D7D (dec: 107564413)
{
	unsigned char savedID; // size=0, offset=0
	unsigned char shiftedSaveSize; // size=0, offset=1
	short introUniqueID; // size=0, offset=2
};

struct SavedIntroSpline // hashcode: 0x9450836D (dec: -1806662803)
{
	unsigned char savedID; // size=0, offset=0
	unsigned char shiftedSaveSize; // size=0, offset=1
	short introUniqueID; // size=0, offset=2
	short splineFlags; // size=0, offset=4
	short splineKeyFrame; // size=0, offset=6
	short splineClipBeg; // size=0, offset=8
	short splineClipEnd; // size=0, offset=10
};

struct _SavedIntroWithIntro // hashcode: 0x576A504B (dec: 1466585163)
{
	unsigned char savedID; // size=0, offset=0
	unsigned char shiftedSaveSize; // size=0, offset=1
	unsigned short attachedUniqueID; // size=0, offset=2
	short introOffset; // size=0, offset=4
	short birthUnitID; // size=0, offset=6
	short introUniqueID; // size=0, offset=8
	unsigned char lightGroup; // size=0, offset=10
	unsigned char specturalLightGroup; // size=0, offset=11
	long flags; // size=0, offset=12
	long flags2; // size=0, offset=16
	struct _SmallRotation smallRotation; // size=6, offset=20
	struct _Position position; // size=6, offset=26
};

struct _PCollideInfo // hashcode: 0x79A03A2A (dec: 2040543786)
{
	short type; // size=0, offset=0
	short segment; // size=0, offset=2
	void *prim; // size=0, offset=4
	struct _Instance *inst; // size=0, offset=8
	struct SVECTOR wNormal; // size=8, offset=12
	struct SVECTOR *newPoint; // size=8, offset=20
	struct SVECTOR *oldPoint; // size=8, offset=24
	struct SVECTOR cldPoint; // size=8, offset=28
	long collideType; // size=0, offset=36
	struct _Instance *instance; // size=0, offset=40
};

struct CameraCollisionInfo // hashcode: 0x846E2C79 (dec: -2073154439)
{
	struct _TFace (*tfaceList[5]); // size=20, offset=0
	struct _Terrain (*tfaceTerrain[5]); // size=20, offset=20
	short bspTree[6]; // size=12, offset=40
	short lengthList[6]; // size=12, offset=52
	long flags; // size=0, offset=64
	long line; // size=0, offset=68
	long numCollided; // size=0, offset=72
	long lenCenterToExtend; // size=0, offset=76
	struct _Sphere *start; // size=12, offset=80
	struct _Sphere *end; // size=12, offset=84
	long cldLines; // size=0, offset=88
};

struct _LCollideInfo // hashcode: 0x61DF7B43 (dec: 1642036035)
{
	struct _TFace *tface; // size=12, offset=0
	struct _Terrain *terrain; // size=84, offset=4
	int curTree; // size=0, offset=8
};

struct LIGHT3D_109fake // hashcode: 0x728B1A96 (dec: 1921718934)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: light3d.o, light3d.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: light3d.o, light3d.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: light3d.o, light3d.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: light3d.o, light3d.o
};

struct LIGHT3D_224fake // hashcode: 0xD1FB8CE9 (dec: -772043543)
{
	long m[5]; // size=20, offset=0
};

struct CdlFILE // hashcode: 0x93E9031B (dec: -1813445861)
{
	struct CdlLOC pos; // size=4, offset=0
	unsigned long size; // size=0, offset=4
	char name[16]; // size=16, offset=8
};

struct LOAD3D_114fake // hashcode: 0xEA575137 (dec: -363376329)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: load3d.o, load3d.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: load3d.o, load3d.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: load3d.o, load3d.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: load3d.o, load3d.o
};

struct _LoadStatus // hashcode: 0xB5ACA7CD (dec: -1246976051)
{
	struct _ReadQueueEntry currentQueueFile; // size=44, offset=0
	long state; // size=0, offset=44
	long bytesTransferred; // size=0, offset=48
	long lastCheckPos; // size=0, offset=52
	long cdWaitTime; // size=0, offset=56
	unsigned char *compSrcAddr; // size=0, offset=60
	unsigned char *compDstAddr; // size=0, offset=64
	long compControlbits; // size=0, offset=68
	long compControl; // size=0, offset=72
	long compEndBytes; // size=0, offset=76
	long decompressLen; // size=0, offset=80
	long checksum; // size=0, offset=84
	long *checkAddr; // size=0, offset=88
	struct _BigFile bigFile; // size=36, offset=92
	void *buffer1; // size=0, offset=128
	void *buffer2; // size=0, offset=132
	int changeDir; // size=0, offset=136
	long endLoadTime; // size=0, offset=140
	long currentDirLoading; // size=0, offset=144
	long currentSector; // size=0, offset=148
	long sectorTime; // size=0, offset=152
	long seekTime; // size=0, offset=156
};

struct RedirectList // hashcode: 0x638D8352 (dec: 1670218578)
{
	long numPointers; // size=0, offset=0
	long *data; // size=0, offset=4
};

struct DRAWENV // hashcode: 0x6012ACC1 (dec: 1611836609)
{
	struct RECT clip; // size=8, offset=0
	short ofs[2]; // size=4, offset=8
	struct RECT tw; // size=8, offset=12
	unsigned short tpage; // size=0, offset=20
	unsigned char dtd; // size=0, offset=22
	unsigned char dfe; // size=0, offset=23
	unsigned char isbg; // size=0, offset=24
	unsigned char r0; // size=0, offset=25
	unsigned char g0; // size=0, offset=26
	unsigned char b0; // size=0, offset=27
	struct DR_ENV dr_env; // size=64, offset=28
};

struct DISPENV // hashcode: 0xF5F0EB6A (dec: -168760470)
{
	struct RECT disp; // size=8, offset=0
	struct RECT screen; // size=8, offset=8
	unsigned char isinter; // size=0, offset=16
	unsigned char isrgb24; // size=0, offset=17
	unsigned char pad0; // size=0, offset=18
	unsigned char pad1; // size=0, offset=19
};

struct BLK_FILL // hashcode: 0x17977E9C (dec: 395804316)
{
	unsigned long tag; // size=0, offset=0
	unsigned char r0; // size=0, offset=4
	unsigned char g0; // size=0, offset=5
	unsigned char b0; // size=0, offset=6
	unsigned char code; // size=0, offset=7
	unsigned short x0; // size=0, offset=8
	unsigned short y0; // size=0, offset=10
	unsigned short w; // size=0, offset=12
	unsigned short h; // size=0, offset=14
};

struct MAIN_114fake // hashcode: 0x56DB6050 (dec: 1457217616)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: main.o, main.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: main.o, main.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: main.o, main.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: main.o, main.o
};

struct MainTracker // hashcode: 0x17FC94E6 (dec: 402429158)
{
	long mainState; // size=0, offset=0
	long previousState; // size=0, offset=4
	long movieNum; // size=0, offset=8
	long done; // size=0, offset=12
};

struct POLY_F4_SEMITRANS // hashcode: 0x21569974 (dec: 559323508)
{
	unsigned long tag; // size=0, offset=0
	unsigned long dr_tpage; // size=0, offset=4
	unsigned char r0; // size=0, offset=8
	unsigned char g0; // size=0, offset=9
	unsigned char b0; // size=0, offset=10
	unsigned char code; // size=0, offset=11
	short x0; // size=0, offset=12
	short y0; // size=0, offset=14
	short x1; // size=0, offset=16
	short y1; // size=0, offset=18
	short x2; // size=0, offset=20
	short y2; // size=0, offset=22
	short x3; // size=0, offset=24
	short y3; // size=0, offset=26
};

struct InterfaceItem // hashcode: 0xE1D09348 (dec: -506424504)
{
	char name[48]; // size=48, offset=0
	unsigned short timeout; // size=0, offset=48
	unsigned short buttonTimeout; // size=0, offset=50
	short itemType; // size=0, offset=52
	short nextItem; // size=0, offset=54
};

struct _FXTracker // hashcode: 0x0266917A (dec: 40276346)
{
	struct _FX_MATRIX matrixPool[32]; // size=1408, offset=0
	struct NodeType usedMatrixList; // size=8, offset=1408
	struct NodeType freeMatrixList; // size=8, offset=1416
	struct _FX_PRIM primPool[256]; // size=29696, offset=1424
	struct NodeType usedPrimList; // size=8, offset=31120
	struct NodeType usedPrimListSprite; // size=8, offset=31128
	struct NodeType freePrimList; // size=8, offset=31136
};

struct StreamUnitPortal // hashcode: 0x0043F5F1 (dec: 4453873)
{
	char tolevelname[16]; // size=16, offset=0
	long MSignalID; // size=0, offset=16
	long streamID; // size=0, offset=20
	short minx; // size=0, offset=24
	short miny; // size=0, offset=26
	short minz; // size=0, offset=28
	short flags; // size=0, offset=30
	short maxx; // size=0, offset=32
	short maxy; // size=0, offset=34
	short maxz; // size=0, offset=36
	short pad2; // size=0, offset=38
	struct _StreamUnit *toStreamUnit; // size=64, offset=40
	struct _SVector t1[3]; // size=24, offset=44
	struct _SVector t2[3]; // size=24, offset=68
};

struct SIGNAL_109fake // hashcode: 0x06600965 (dec: 106957157)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: signal.o, signal.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: signal.o, signal.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: signal.o, signal.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: signal.o, signal.o
};

struct SignalInfo // hashcode: 0xDE5780B2 (dec: -564690766)
{
	long (*signalHandleFunc)(); // size=0, offset=0
	short length; // size=0, offset=4
	short onlyPlayer; // size=0, offset=6
	void (*signalRelocateFunc)(); // size=0, offset=8
};

struct _Triangle2D // hashcode: 0xA03A8106 (dec: -1606778618)
{
	short x0; // size=0, offset=0
	short y0; // size=0, offset=2
	short x1; // size=0, offset=4
	short y1; // size=0, offset=6
	short x2; // size=0, offset=8
	short y2; // size=0, offset=10
};

struct _HNormal // hashcode: 0xCBA3A7F2 (dec: -878467086)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short pad; // size=0, offset=6
};

struct _HFaceInfo // hashcode: 0x2DFC4DF4 (dec: 771509748)
{
	long flags; // size=0, offset=0
	long attr; // size=0, offset=4
	struct _HFace *hface; // size=12, offset=8
	struct _SVector normal; // size=8, offset=12
	struct _HVertex *vertex0; // size=12, offset=20
	struct _HVertex *vertex1; // size=12, offset=24
	struct _HVertex *vertex2; // size=12, offset=28
};

struct _CollideInfo // hashcode: 0x3975D4B8 (dec: 964023480)
{
	void *level; // size=0, offset=0
	char flags; // size=0, offset=4
	char segment; // size=0, offset=5
	char type0; // size=0, offset=6
	char type1; // size=0, offset=7
	void *prim0; // size=0, offset=8
	void *prim1; // size=0, offset=12
	void *inst0; // size=0, offset=16
	void *inst1; // size=0, offset=20
	struct SVECTOR point0; // size=8, offset=24
	struct SVECTOR point1; // size=8, offset=32
	struct _Position offset; // size=6, offset=40
	short bspID; // size=0, offset=46
};

struct SCollideInfo // hashcode: 0x54CCE757 (dec: 1422714711)
{
	struct _Sphere *sphere; // size=12, offset=0
	struct SVECTOR *oldPos; // size=8, offset=4
	void (*collideFunc)(); // size=0, offset=8
	long id; // size=0, offset=12
	long segment; // size=0, offset=16
	struct _Instance *instance; // size=664, offset=20
	void *prim; // size=0, offset=24
};

struct PandTScratch // hashcode: 0xD20EDCFF (dec: -770777857)
{
	struct MATRIX posMatrix; // size=32, offset=0
	struct _SVector normal; // size=8, offset=32
	struct _Vector dpv; // size=12, offset=40
	struct _SVector planePoint; // size=8, offset=52
	long ignore_attr; // size=0, offset=60
	long accept_attr; // size=0, offset=64
	short *backface_flag; // size=0, offset=68
	struct _SVector newPos; // size=8, offset=72
	struct _SVector oldPos; // size=8, offset=80
	int flags; // size=0, offset=88
	int i; // size=0, offset=92
	int slack; // size=0, offset=96
	long in_spectral; // size=0, offset=100
	short *normalList; // size=0, offset=104
	struct _TVertex *vertexList; // size=12, offset=108
	struct _TFace *result; // size=12, offset=112
	struct _SVector line; // size=8, offset=116
};

struct COLLIDE_253fake // hashcode: 0x078F5C54 (dec: 126835796)
{
	long m[3]; // size=12, offset=0
};

struct SandHFScratch // hashcode: 0x60F11A33 (dec: 1626413619)
{
	struct _SVector normal; // size=8, offset=0
	struct MATRIX posMatrix; // size=32, offset=8
	struct _Vector dpv; // size=12, offset=40
	struct _SVector triPoint; // size=8, offset=52
	struct _SVector planePoint; // size=8, offset=60
};

struct SandTScratch // hashcode: 0xE4056CC1 (dec: -469406527)
{
	struct MATRIX posMatrix; // size=32, offset=0
	struct _Vector dpv; // size=12, offset=32
	struct _HNormal *normalList; // size=8, offset=44
	struct _CollideInfo collideInfo; // size=48, offset=48
	struct _HFaceInfo hfaceInfo; // size=32, offset=96
	struct _SVector midPoint; // size=8, offset=128
	struct _SVector spherePos; // size=8, offset=136
	void (*collideFunc)(); // size=0, offset=144
	struct _Instance *instance; // size=664, offset=148
	long edge; // size=0, offset=152
	long in_spectral; // size=0, offset=156
	struct _SVector oldPos; // size=8, offset=160
	void *prim; // size=0, offset=168
	struct _SVector normal; // size=8, offset=172
	struct _Sphere sphere; // size=12, offset=180
	short result; // size=0, offset=192
	short i; // size=0, offset=194
	long collide_ignoreAttr; // size=0, offset=196
	long collide_acceptAttr; // size=0, offset=200
	long midRadius; // size=0, offset=204
	struct _TVertex *vertexList; // size=12, offset=208
};

struct IandTScratch // hashcode: 0x4C35D3C8 (dec: 1278596040)
{
	struct MATRIX posMatrix; // size=32, offset=0
	struct _SVector normal; // size=8, offset=32
	struct _Vector dpv; // size=12, offset=40
	struct _SVector planePoint; // size=8, offset=52
	struct _SVector line; // size=8, offset=60
	struct _SVector oldPos; // size=8, offset=68
	struct _SVector newPos; // size=8, offset=76
	int i; // size=0, offset=84
	long in_spectral; // size=0, offset=88
	short *normalList; // size=0, offset=92
	struct _TVertex *vertexList; // size=12, offset=96
};

struct PandTFScratch // hashcode: 0x0AE02FA7 (dec: 182464423)
{
	struct MATRIX posMatrix; // size=32, offset=0
	struct _SVector planePoint; // size=8, offset=32
	struct _SVector newPos; // size=8, offset=40
	struct _SVector oldPos; // size=8, offset=48
	struct _SVector normal; // size=8, offset=56
	struct _Vector dpv; // size=12, offset=64
};

struct VM_109fake // hashcode: 0x06890A7C (dec: 109644412)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: vm.o, vm.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: vm.o, vm.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: vm.o, vm.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: vm.o, vm.o
};

struct POLY_FT3 // hashcode: 0x0A08FE0D (dec: 168361485)
{
	unsigned long tag; // size=0, offset=0
	unsigned char r0; // size=0, offset=4
	unsigned char g0; // size=0, offset=5
	unsigned char b0; // size=0, offset=6
	unsigned char code; // size=0, offset=7
	short x0; // size=0, offset=8
	short y0; // size=0, offset=10
	unsigned char u0; // size=0, offset=12
	unsigned char v0; // size=0, offset=13
	unsigned short clut; // size=0, offset=14
	short x1; // size=0, offset=16
	short y1; // size=0, offset=18
	unsigned char u1; // size=0, offset=20
	unsigned char v1; // size=0, offset=21
	unsigned short tpage; // size=0, offset=22
	short x2; // size=0, offset=24
	short y2; // size=0, offset=26
	unsigned char u2; // size=0, offset=28
	unsigned char v2; // size=0, offset=29
	unsigned short pad1; // size=0, offset=30
};

struct _Mirror // hashcode: 0x4826C54C (dec: 1210500428)
{
	short a; // size=0, offset=0
	short b; // size=0, offset=2
	short c; // size=0, offset=4
	short d; // size=0, offset=6
};

struct PIPE3D_109fake // hashcode: 0x45605C15 (dec: 1163942933)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: pipe3d.o, pipe3d.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: pipe3d.o, pipe3d.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: pipe3d.o, pipe3d.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: pipe3d.o, pipe3d.o
};

struct _FXHalvePlane // hashcode: 0x4C43EE4C (dec: 1279520332)
{
	void *next; // size=0, offset=0
	void *continue_process; // size=0, offset=4
	struct _Instance *instance; // size=664, offset=8
	unsigned char effectType; // size=0, offset=12
	unsigned char type; // size=0, offset=13
	short lifeTime; // size=0, offset=14
	long diffTime; // size=0, offset=16
	struct _PlaneConstants ringPlane; // size=12, offset=20
	long currentColor; // size=0, offset=32
	long *colorArray; // size=0, offset=36
	short numColors; // size=0, offset=40
	short colorBlendLife; // size=0, offset=42
};

struct _FXGlowEffect // hashcode: 0xE65C96B4 (dec: -430139724)
{
	void *next; // size=0, offset=0
	void *continue_process; // size=0, offset=4
	struct _Instance *instance; // size=664, offset=8
	unsigned char effectType; // size=0, offset=12
	unsigned char type; // size=0, offset=13
	short lifeTime; // size=0, offset=14
	unsigned long diffTime; // size=0, offset=16
	long *colorArray; // size=0, offset=20
	long currentColor; // size=0, offset=24
	short numColors; // size=0, offset=28
	short colorBlendCycle; // size=0, offset=30
	short width; // size=0, offset=32
	short height; // size=0, offset=34
	unsigned char numSegments; // size=0, offset=36
	unsigned char SegmentInc; // size=0, offset=37
	short segment; // size=0, offset=38
	short fadein_time; // size=0, offset=40
	short fadeout_time; // size=0, offset=42
};

struct PIPE3D_234fake // hashcode: 0x4EE49282 (dec: 1323602562)
{
	long m[3]; // size=12, offset=0
};

struct PIPE3D_235fake // hashcode: 0x0036719D (dec: 3568029)
{
	long m[5]; // size=20, offset=0
};

struct TransformAnimatedInstanceVerticesWork_t // hashcode: 0x182E453B (dec: 405685563)
{
	struct MATRIX scTransform; // size=32, offset=0
	struct MATRIX mirrorMatrix; // size=32, offset=32
	struct MATRIX llm; // size=32, offset=64
	struct _Vector vector; // size=12, offset=96
};

struct SCRIPT_114fake // hashcode: 0x91F9F0D6 (dec: -1845890858)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: script.o, script.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: script.o, script.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: script.o, script.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: script.o, script.o
};

struct GenericTune // hashcode: 0x31A613AD (dec: 832967597)
{
	long flags; // size=0, offset=0
	void *shatterData; // size=0, offset=4
};

struct FXSplinter // hashcode: 0x08C79190 (dec: 147296656)
{
	short flags; // size=0, offset=0
	short soundFx; // size=0, offset=2
	short chunkVelXY; // size=0, offset=4
	short chunkVelZ; // size=0, offset=6
	short chunkVelRng; // size=0, offset=8
	short triVelRng; // size=0, offset=10
	short lifetime; // size=0, offset=12
	short faceLimit; // size=0, offset=14
	short rotRateRng; // size=0, offset=16
	short gravityZ; // size=0, offset=18
};

struct TIMER_109fake // hashcode: 0x57CEB965 (dec: 1473165669)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: timer.o, timer.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: timer.o, timer.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: timer.o, timer.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: timer.o, timer.o
};

struct _SBSPLeaf // hashcode: 0x52632806 (dec: 1382230022)
{
	struct _Sphere_noSq sphere; // size=8, offset=0
	struct Intro **introList; // size=76, offset=8
	short numIntros; // size=0, offset=12
	short flags; // size=0, offset=14
	struct CDLight **lightList; // size=24, offset=16
	short numLights; // size=0, offset=20
	short pad; // size=0, offset=22
};

struct BSP_109fake // hashcode: 0x4DD8B406 (dec: 1306047494)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: bsp.o, bsp.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: bsp.o, bsp.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: bsp.o, bsp.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: bsp.o, bsp.o
};

struct BSPScratch // hashcode: 0x4C6E5656 (dec: 1282299478)
{
	struct MATRIX vv[2]; // size=64, offset=0
	struct MATRIX camMatrix; // size=32, offset=64
	struct VECTOR dpv[3]; // size=48, offset=96
	long d[6]; // size=24, offset=144
	struct MATRIX boundMatrix; // size=32, offset=168
	long in_spectral; // size=0, offset=200
};

struct _ObjectOwnerInfo // hashcode: 0xC8D6F6EF (dec: -925436177)
{
	long magicnum; // size=0, offset=0
	short animID; // size=0, offset=4
	char objectName[0]; // size=0, offset=6
};

struct OBTABLE_114fake // hashcode: 0x59F65C69 (dec: 1509317737)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: obtable.o, obtable.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: obtable.o, obtable.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: obtable.o, obtable.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: obtable.o, obtable.o
};

struct ObjectAccess // hashcode: 0x5B1D3792 (dec: 1528641426)
{
	char *objectName; // size=0, offset=0
	void *object; // size=0, offset=4
};

struct OBTABLE2_114fake // hashcode: 0xB85923E0 (dec: -1202117664)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: obtable2.o, obtable2.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: obtable2.o, obtable2.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: obtable2.o, obtable2.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: obtable2.o, obtable2.o
};

struct ObjectFunc // hashcode: 0x482CB050 (dec: 1210888272)
{
	char *scriptName; // size=0, offset=0
	void (*initFunc)(); // size=0, offset=4
	void (*processFunc)(); // size=0, offset=8
	void (*collideFunc)(); // size=0, offset=12
	unsigned long (*queryFunc)(); // size=0, offset=16
	void (*messageFunc)(); // size=0, offset=20
	void (*additionalCollideFunc)(); // size=0, offset=24
	void (*relocateTuneFunc)(); // size=0, offset=28
	void (*relocateInstObFunc)(); // size=0, offset=32
};

struct GENERIC_114fake // hashcode: 0x1E3C81CA (dec: 507281866)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: generic.o, generic.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: generic.o, generic.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: generic.o, generic.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: generic.o, generic.o
};

struct evAnimationInstanceSwitchData // hashcode: 0x76923567 (dec: 1989293415)
{
	struct _Instance *instance; // size=664, offset=0
	int anim; // size=0, offset=4
	int frame; // size=0, offset=8
	int frames; // size=0, offset=12
	int mode; // size=0, offset=16
};

struct evControlSaveDataData // hashcode: 0xF536CC5D (dec: -180958115)
{
	long length; // size=0, offset=0
	void *data; // size=0, offset=4
};

struct SOUND_114fake // hashcode: 0x2F8A9789 (dec: 797611913)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: sound.o, sound.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: sound.o, sound.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: sound.o, sound.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: sound.o, sound.o
};

struct AadInitAttr // hashcode: 0x1ECF2844 (dec: 516892740)
{
	int updateMode; // size=0, offset=0
	int numSlots; // size=0, offset=4
	void (*nonBlockLoadProc)(); // size=0, offset=8
	void (*nonBlockBufferedLoadProc)(); // size=0, offset=12
	void (**memoryMallocProc)(); // size=0, offset=16
	void (*memoryFreeProc)(); // size=0, offset=20
};

struct ObjectPeriodicSound // hashcode: 0xECB7125A (dec: -323546534)
{
	unsigned char type; // size=0, offset=0
	unsigned char numSfxIDs; // size=0, offset=1
	unsigned char soundInst; // size=0, offset=2
	unsigned char flags; // size=0, offset=3
	unsigned short minVolDistance; // size=0, offset=4
	short pitch; // size=0, offset=6
	unsigned short pitchVariation; // size=0, offset=8
	unsigned char maxVolume; // size=0, offset=10
	unsigned char maxVolVariation; // size=0, offset=11
	unsigned char initialDelay; // size=0, offset=12
	unsigned char initialDelayVariation; // size=0, offset=13
	unsigned char onTime; // size=0, offset=14
	unsigned char onTimeVariation; // size=0, offset=15
	unsigned char offTime; // size=0, offset=16
	unsigned char offTimeVariation; // size=0, offset=17
};

struct ObjectEventSound // hashcode: 0x98471ED6 (dec: -1740169514)
{
	unsigned char type; // size=0, offset=0
	unsigned char numSfxIDs; // size=0, offset=1
	unsigned char soundInst; // size=0, offset=2
	unsigned char flags; // size=0, offset=3
	unsigned short minVolDistance; // size=0, offset=4
	short pitch; // size=0, offset=6
	unsigned short pitchVariation; // size=0, offset=8
	unsigned char maxVolume; // size=0, offset=10
	unsigned char maxVolVariation; // size=0, offset=11
	unsigned char initialDelay; // size=0, offset=12
	unsigned char initialDelayVariation; // size=0, offset=13
};

struct ObjectOneShotSound // hashcode: 0xF0C5CF7C (dec: -255471748)
{
	unsigned char type; // size=0, offset=0
	unsigned char numSfxIDs; // size=0, offset=1
	unsigned char soundInst; // size=0, offset=2
	unsigned char flags; // size=0, offset=3
	unsigned short minVolDistance; // size=0, offset=4
	short pitch; // size=0, offset=6
	unsigned short pitchVariation; // size=0, offset=8
	unsigned char maxVolume; // size=0, offset=10
	unsigned char maxVolVariation; // size=0, offset=11
	unsigned char initialDelay; // size=0, offset=12
	unsigned char initialDelayVariation; // size=0, offset=13
};

struct SoundEffectChannel // hashcode: 0x46536DE6 (dec: 1179872742)
{
	unsigned char inUse; // size=0, offset=0
	unsigned char unused; // size=0, offset=1
	unsigned short unused1; // size=0, offset=2
	unsigned long handle; // size=0, offset=4
	short volume; // size=0, offset=8
	short volumeChangeTime; // size=0, offset=10
	short volumeChangeTimeSave; // size=0, offset=12
	short volumeChangePerUpdate; // size=0, offset=14
	short volumeChangeSign; // size=0, offset=16
	short volumeChangeErrPerUpdate; // size=0, offset=18
	short volumeChangeError; // size=0, offset=20
	short pitch; // size=0, offset=22
	short pitchChangeTime; // size=0, offset=24
	short pitchChangeTimeSave; // size=0, offset=26
	short pitchChangePerUpdate; // size=0, offset=28
	short pitchChangeSign; // size=0, offset=30
	short pitchChangeErrPerUpdate; // size=0, offset=32
	short pitchChangeError; // size=0, offset=34
};

struct DR_TPAGE // hashcode: 0xE20E8F38 (dec: -502362312)
{
	unsigned long tag; // size=0, offset=0
	unsigned long code[1]; // size=4, offset=4
};

struct FX_109fake // hashcode: 0x270E0770 (dec: 655230832)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: fx.o, fx.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: fx.o, fx.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: fx.o, fx.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: fx.o, fx.o
};

struct _POLY_SG4 // hashcode: 0x280B941B (dec: 671847451)
{
	unsigned long tag; // size=0, offset=0
	unsigned long drawTPage1; // size=0, offset=4
	struct _BASIC_G4 p1; // size=32, offset=8
	unsigned long drawTPage2; // size=0, offset=40
	struct _BASIC_F4 p2; // size=20, offset=44
};

struct _FXGeneralEffect // hashcode: 0xD9E1BDC0 (dec: -639517248)
{
	void *next; // size=0, offset=0
	void *continue_process; // size=0, offset=4
	struct _Instance *instance; // size=664, offset=8
	unsigned char effectType; // size=0, offset=12
	unsigned char type; // size=0, offset=13
	short lifeTime; // size=0, offset=14
};

struct _FXRibbon // hashcode: 0x59C68DE1 (dec: 1506184673)
{
	void *next; // size=0, offset=0
	void *continue_process; // size=0, offset=4
	struct _Instance *instance; // size=664, offset=8
	unsigned char effectType; // size=0, offset=12
	unsigned char type; // size=0, offset=13
	short lifeTime; // size=0, offset=14
	short numberVerts; // size=0, offset=16
	short endIndex; // size=0, offset=18
	struct SVECTOR *vertexPool; // size=8, offset=20
	short startSegment; // size=0, offset=24
	short endSegment; // size=0, offset=26
	long startColor; // size=0, offset=28
	long endColor; // size=0, offset=32
	short colorStepValue; // size=0, offset=36
	short faceLifeTime; // size=0, offset=38
	short startFadeValue; // size=0, offset=40
	short fadeStep; // size=0, offset=42
};

struct _FXParticle // hashcode: 0x48F39FD8 (dec: 1223925720)
{
	void *next; // size=0, offset=0
	void *continue_process; // size=0, offset=4
	struct _Instance *instance; // size=664, offset=8
	unsigned char effectType; // size=0, offset=12
	unsigned char type; // size=0, offset=13
	short lifeTime; // size=0, offset=14
	struct TextureMT3 *texture; // size=16, offset=16
	void *fxprim_modify_process; // size=0, offset=20
	void *fxprim_process; // size=0, offset=24
	short size; // size=0, offset=28
	short primLifeTime; // size=0, offset=30
	short birthRadius; // size=0, offset=32
	short scaleSpeed; // size=0, offset=34
	struct _Position direction; // size=6, offset=36
	unsigned short flag_bits; // size=0, offset=42
	struct _Position acceleration; // size=6, offset=44
	short startScale; // size=0, offset=50
	struct _Position offset; // size=6, offset=52
	char startSegment; // size=0, offset=58
	char z_undulate; // size=0, offset=59
	long startColor; // size=0, offset=60
	long endColor; // size=0, offset=64
	short colorStepValue; // size=0, offset=68
	char numberBirthParticles; // size=0, offset=70
	char endSegment; // size=0, offset=71
	short startFadeValue; // size=0, offset=72
	short fadeStep; // size=0, offset=74
};

struct _FXLightBeam // hashcode: 0xD46629B3 (dec: -731502157)
{
	void *next; // size=0, offset=0
	void *continue_process; // size=0, offset=4
	struct _Instance *instance; // size=664, offset=8
	unsigned char effectType; // size=0, offset=12
	unsigned char type; // size=0, offset=13
	short lifeTime; // size=0, offset=14
	short startSeg; // size=0, offset=16
	short endSeg; // size=0, offset=18
	long color; // size=0, offset=20
};

struct _FXBlastringEffect // hashcode: 0x412A2A17 (dec: 1093282327)
{
	void *next; // size=0, offset=0
	void *continue_process; // size=0, offset=4
	struct _Instance *instance; // size=664, offset=8
	unsigned char effectType; // size=0, offset=12
	unsigned char type; // size=0, offset=13
	short lifeTime; // size=0, offset=14
	struct _SVector position; // size=8, offset=16
	struct MATRIX matrix; // size=32, offset=24
	short segment; // size=0, offset=56
	short pad; // size=0, offset=58
	int radius; // size=0, offset=60
	int size1; // size=0, offset=64
	int size2; // size=0, offset=68
	int startRadius; // size=0, offset=72
	int endRadius; // size=0, offset=76
	int colorchange_radius; // size=0, offset=80
	int vel; // size=0, offset=84
	int accl; // size=0, offset=88
	int height1; // size=0, offset=92
	int height2; // size=0, offset=96
	int height3; // size=0, offset=100
	short predator_offset; // size=0, offset=104
	short sortInWorld; // size=0, offset=106
	long color; // size=0, offset=108
	long startColor; // size=0, offset=112
	long endColor; // size=0, offset=116
};

struct _FXForceFieldEffect // hashcode: 0xDC625742 (dec: -597534910)
{
	void *next; // size=0, offset=0
	void *continue_process; // size=0, offset=4
	struct _Instance *instance; // size=664, offset=8
	unsigned char effectType; // size=0, offset=12
	unsigned char type; // size=0, offset=13
	short lifeTime; // size=0, offset=14
	struct _SVector offset; // size=8, offset=16
	short size; // size=0, offset=24
	short size_diff; // size=0, offset=26
	short size_change; // size=0, offset=28
	short deg; // size=0, offset=30
	short deg_change; // size=0, offset=32
	short start_fade; // size=0, offset=34
	short end_fade; // size=0, offset=36
	long color; // size=0, offset=40
};

struct _FXLightning // hashcode: 0xB826B760 (dec: -1205422240)
{
	void *next; // size=0, offset=0
	void *continue_process; // size=0, offset=4
	struct _Instance *instance; // size=664, offset=8
	unsigned char effectType; // size=0, offset=12
	unsigned char type; // size=0, offset=13
	short lifeTime; // size=0, offset=14
	short deg; // size=0, offset=16
	short deg_inc; // size=0, offset=18
	struct _Position start_offset; // size=6, offset=20
	short startSeg; // size=0, offset=26
	struct _Instance *end_instance; // size=664, offset=28
	struct _Position end_offset; // size=6, offset=32
	short endSeg; // size=0, offset=38
	short matrixSeg; // size=0, offset=40
	short width; // size=0, offset=42
	short small_width; // size=0, offset=44
	short segs; // size=0, offset=46
	short sine_size; // size=0, offset=48
	short variation; // size=0, offset=50
	long color; // size=0, offset=52
	long glow_color; // size=0, offset=56
};

struct _FXFlash // hashcode: 0x9AC817EF (dec: -1698162705)
{
	void *next; // size=0, offset=0
	void *continue_process; // size=0, offset=4
	struct _Instance *instance; // size=664, offset=8
	unsigned char effectType; // size=0, offset=12
	unsigned char type; // size=0, offset=13
	short lifeTime; // size=0, offset=14
	long timeToColor; // size=0, offset=16
	long timeAtColor; // size=0, offset=20
	long timeFromColor; // size=0, offset=24
	long currentTime; // size=0, offset=28
	long color; // size=0, offset=32
};

struct GenericFXObject // hashcode: 0x47E9C847 (dec: 1206503495)
{
	struct _GenericParticleParams *ParticleList; // size=48, offset=0
	struct _GenericRibbonParams *RibbonList; // size=20, offset=4
	struct _GenericGlowParams *GlowList; // size=24, offset=8
	struct _GenericLightningParams *LightningList; // size=40, offset=12
	struct _GenericBlastringParams *BlastList; // size=48, offset=16
	struct _GenericFlashParams *FlashList; // size=12, offset=20
	long *ColorList; // size=0, offset=24
};

struct evObjectDraftData // hashcode: 0xBDF4464C (dec: -1108064692)
{
	short force; // size=0, offset=0
	unsigned short radius; // size=0, offset=2
	unsigned short radiusCoef; // size=0, offset=4
	unsigned short height; // size=0, offset=6
	unsigned short maxVelocity; // size=0, offset=8
};

struct _GlyphTuneData // hashcode: 0xF890CE90 (dec: -124727664)
{
	short glyph_size; // size=0, offset=0
	short glyph_darkness; // size=0, offset=2
	char glyph_costs[8]; // size=8, offset=4
	short glyph_range[8]; // size=16, offset=12
	long color_array[28]; // size=112, offset=28
};

struct __ReaverData // hashcode: 0xBB4372C7 (dec: -1153207609)
{
	char ReaverPickedUp; // size=0, offset=0
	char ReaverOn; // size=0, offset=1
	short ReaverSize; // size=0, offset=2
	short CurrentReaver; // size=0, offset=4
	short ReaverDeg; // size=0, offset=6
	long ReaverChargeTime; // size=0, offset=8
	long ReaverShockAmount; // size=0, offset=12
	long ReaverGlowColor; // size=0, offset=16
	long ReaverBladeColor; // size=0, offset=20
	long ReaverBladeGlowColor; // size=0, offset=24
	short ReaverScale; // size=0, offset=28
	short ReaverTargetScale; // size=0, offset=30
	struct __ReaverSaveDat saveData; // size=4, offset=32
};

struct __ReaverTuneData // hashcode: 0xD790EF64 (dec: -678367388)
{
	unsigned long spectralGlowColor; // size=0, offset=0
	unsigned long materialGlowColor; // size=0, offset=4
	unsigned long sunlightGlowColor; // size=0, offset=8
	unsigned long waterGlowColor; // size=0, offset=12
	unsigned long stoneGlowColor; // size=0, offset=16
	unsigned long fireGlowColor; // size=0, offset=20
	unsigned long spiritGlowColor; // size=0, offset=24
	unsigned long soundGlowColor; // size=0, offset=28
	unsigned long spectralInnerColor; // size=0, offset=32
	unsigned long materialInnerColor; // size=0, offset=36
	unsigned long sunlightInnerColor; // size=0, offset=40
	unsigned long waterInnerColor; // size=0, offset=44
	unsigned long stoneInnerColor; // size=0, offset=48
	unsigned long fireInnerColor; // size=0, offset=52
	unsigned long spiritInnerColor; // size=0, offset=56
	unsigned long soundInnerColor; // size=0, offset=60
	unsigned long spectralInnerGlowColor; // size=0, offset=64
	unsigned long materialInnerGlowColor; // size=0, offset=68
	unsigned long sunlightInnerGlowColor; // size=0, offset=72
	unsigned long waterInnerGlowColor; // size=0, offset=76
	unsigned long stoneInnerGlowColor; // size=0, offset=80
	unsigned long fireInnerGlowColor; // size=0, offset=84
	unsigned long spiritInnerGlowColor; // size=0, offset=88
	unsigned long soundInnerGlowColor; // size=0, offset=92
	unsigned long icon_colors[24]; // size=96, offset=96
};

struct _POLY_TF4 // hashcode: 0x7EF8BC11 (dec: 2130230289)
{
	unsigned long tag; // size=0, offset=0
	unsigned long drawTPage; // size=0, offset=4
	struct _BASIC_F4 p1; // size=20, offset=8
};

struct _POLY_2G4 // hashcode: 0x0EC3C00F (dec: 247709711)
{
	unsigned long tag; // size=0, offset=0
	struct _BASIC_G4 p1; // size=32, offset=4
	struct _BASIC_G4 p2; // size=32, offset=36
};

struct _POLY_2G4T // hashcode: 0xC66905DE (dec: -966195746)
{
	unsigned long tag; // size=0, offset=0
	unsigned long drawTPage1; // size=0, offset=4
	struct _BASIC_G4 p1; // size=32, offset=8
	struct _BASIC_G4 p2; // size=32, offset=40
};

struct AadVolume // hashcode: 0xAF7F90F1 (dec: -1350594319)
{
	short left; // size=0, offset=0
	short right; // size=0, offset=2
};

struct NewMemTracker // hashcode: 0x07472B56 (dec: 122104662)
{
	struct MemHeader *rootNode; // size=8, offset=0
	unsigned long totalMemory; // size=0, offset=4
	unsigned long currentMemoryUsed; // size=0, offset=8
	char *lastMemoryAddress; // size=0, offset=12
	long doingGarbageCollection; // size=0, offset=16
};

struct AadSequenceHdr // hashcode: 0x9C79F48E (dec: -1669729138)
{
	unsigned long sequenceID; // size=0, offset=0
	unsigned long quarterNoteTime; // size=0, offset=4
	unsigned short ppqn; // size=0, offset=8
	unsigned short version; // size=0, offset=10
	unsigned short numTracks; // size=0, offset=12
	unsigned short unused; // size=0, offset=14
};

struct AadMemoryStruct // hashcode: 0xCE12B6A3 (dec: -837634397)
{
	unsigned long updateCounter; // size=0, offset=0
	int numSlots; // size=0, offset=4
	int updateMode; // size=0, offset=8
	int masterVolume; // size=0, offset=12
	struct AadVolFader masterVolFader; // size=12, offset=16
	int sfxMasterVol; // size=0, offset=28
	int musicMasterVol; // size=0, offset=32
	int flags; // size=0, offset=36
	struct AadVolFader musicMasterVolFader; // size=12, offset=40
	struct _AadSequenceSlot (*sequenceSlots[8]); // size=32, offset=52
	struct AadSfxSlot sfxSlot; // size=392, offset=84
	struct AadSynthVoice synthVoice[24]; // size=672, offset=476
	char voiceStatus[24]; // size=24, offset=1148
	unsigned short voicePitchSave[24]; // size=48, offset=1172
	unsigned long voiceKeyOffRequest; // size=0, offset=1220
	unsigned long voiceKeyOnRequest; // size=0, offset=1224
	unsigned long voiceReverbRequest; // size=0, offset=1228
	struct AadSoundBankHdr (*dynamicSoundBankHdr[2]); // size=8, offset=1232
	struct AadProgramAtr (*dynamicProgramAtr[2]); // size=8, offset=1240
	struct AadToneAtr (*dynamicToneAtr[2]); // size=8, offset=1248
	unsigned long (*dynamicWaveAddr[2]); // size=8, offset=1256
	unsigned char (**dynamicSequenceAddressTbl[2]); // size=8, offset=1264
	unsigned long (*dynamicSequenceLabelOffsetTbl[2]); // size=8, offset=1272
	int dynamicBankStatus[2]; // size=8, offset=1280
	unsigned char (*dynamicSoundBankData[2]); // size=8, offset=1288
	unsigned long dynamicSoundBankSramData[2]; // size=8, offset=1296
	struct AadDynamicLoadRequest loadRequestQueue[16]; // size=448, offset=1304
	struct AadDynamicBankLoadInfo dynamicBankLoadInfo; // size=88, offset=1752
	void (*nonBlockLoadProc)(); // size=0, offset=1840
	void (*nonBlockBufferedLoadProc)(); // size=0, offset=1844
	void (**memoryMallocProc)(); // size=0, offset=1848
	void (*memoryFreeProc)(); // size=0, offset=1852
	int nextLoadReqIn; // size=0, offset=1856
	int nextLoadReqOut; // size=0, offset=1860
	int numLoadReqsQueued; // size=0, offset=1864
	struct AadDynamicSfxLoadInfo dynamicSfxLoadInfo; // size=148, offset=1868
	struct _AadDynSfxFileHdr *firstDynSfxFile; // size=20, offset=2016
	int nextFileHandle; // size=0, offset=2020
	struct AadSramDefragInfo sramDefragInfo; // size=32, offset=2024
	unsigned char sfxToneMasterList[512]; // size=512, offset=2056
	unsigned char sfxWaveMasterList[512]; // size=512, offset=2568
	struct AadLoadedSfxToneAttr sfxToneAttrTbl[128]; // size=2560, offset=3080
	struct AadLoadedSfxWaveAttr sfxWaveAttrTbl[120]; // size=480, offset=5640
	int nextToneIndex; // size=0, offset=6120
	int nextWaveIndex; // size=0, offset=6124
	struct AadNewSramBlockDesc sramDescriptorTbl[128]; // size=1024, offset=6128
	int nextSramDescIndex; // size=0, offset=7152
	int firstSramBlockDescIndex; // size=0, offset=7156
	void (*controller11Callback)(); // size=0, offset=7160
	void (*endSequenceCallback)(); // size=0, offset=7164
	long controller11CallbackData; // size=0, offset=7168
	long endSequenceCallbackData; // size=0, offset=7172
	unsigned char userVariables[128]; // size=128, offset=7176
};

struct AadTempo // hashcode: 0x6D23769D (dec: 1831040669)
{
	unsigned long quarterNoteTime; // size=0, offset=0
	int ppqn; // size=0, offset=4
};

struct AadSlotAttributes // hashcode: 0x454AA01E (dec: 1162518558)
{
	int sequenceNumberAssigned; // size=0, offset=0
	int sequenceAssignedDynamicBank; // size=0, offset=4
	int playingStatus; // size=0, offset=8
	int channelMute; // size=0, offset=12
	int slotVolume; // size=0, offset=16
	int slotPan; // size=0, offset=20
	int eventsInQueue[16]; // size=64, offset=24
};

struct AADLIB_152fake // hashcode: 0xBFBF34F1 (dec: -1077988111)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: aadlib.o, aadlib.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: aadlib.o, aadlib.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: aadlib.o, aadlib.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: aadlib.o, aadlib.o
};

struct SpuVoiceAttr // hashcode: 0x72F4027F (dec: 1928594047)
{
	unsigned long voice; // size=0, offset=0
	unsigned long mask; // size=0, offset=4
	struct SpuVolume volume; // size=4, offset=8
	struct SpuVolume volmode; // size=4, offset=12
	struct SpuVolume volumex; // size=4, offset=16
	unsigned short pitch; // size=0, offset=20
	unsigned short note; // size=0, offset=22
	unsigned short sample_note; // size=0, offset=24
	short envx; // size=0, offset=26
	unsigned long addr; // size=0, offset=28
	unsigned long loop_addr; // size=0, offset=32
	long a_mode; // size=0, offset=36
	long s_mode; // size=0, offset=40
	long r_mode; // size=0, offset=44
	unsigned short ar; // size=0, offset=48
	unsigned short dr; // size=0, offset=50
	unsigned short sr; // size=0, offset=52
	unsigned short rr; // size=0, offset=54
	unsigned short sl; // size=0, offset=56
	unsigned short adsr1; // size=0, offset=58
	unsigned short adsr2; // size=0, offset=60
};

struct POLY_G4 // hashcode: 0xC4DFE412 (dec: -991960046)
{
	unsigned long tag; // size=0, offset=0
	unsigned char r0; // size=0, offset=4
	unsigned char g0; // size=0, offset=5
	unsigned char b0; // size=0, offset=6
	unsigned char code; // size=0, offset=7
	short x0; // size=0, offset=8
	short y0; // size=0, offset=10
	unsigned char r1; // size=0, offset=12
	unsigned char g1; // size=0, offset=13
	unsigned char b1; // size=0, offset=14
	unsigned char pad1; // size=0, offset=15
	short x1; // size=0, offset=16
	short y1; // size=0, offset=18
	unsigned char r2; // size=0, offset=20
	unsigned char g2; // size=0, offset=21
	unsigned char b2; // size=0, offset=22
	unsigned char pad2; // size=0, offset=23
	short x2; // size=0, offset=24
	short y2; // size=0, offset=26
	unsigned char r3; // size=0, offset=28
	unsigned char g3; // size=0, offset=29
	unsigned char b3; // size=0, offset=30
	unsigned char pad3; // size=0, offset=31
	short x3; // size=0, offset=32
	short y3; // size=0, offset=34
};

struct DR_AREA // hashcode: 0x89605187 (dec: -1990176377)
{
	unsigned long tag; // size=0, offset=0
	unsigned long code[2]; // size=8, offset=4
};

struct evPositionData // hashcode: 0x30848F46 (dec: 813993798)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short z; // size=0, offset=4
	short pad; // size=0, offset=6
};

struct STracker // hashcode: 0xC37622E2 (dec: -1015667998)
{
	struct _StreamUnit StreamList[16]; // size=1024, offset=0
};

struct FaceExtents // hashcode: 0x33048CD4 (dec: 855936212)
{
	long smallx; // size=0, offset=0
	long bigx; // size=0, offset=4
	long smally; // size=0, offset=8
	long bigy; // size=0, offset=12
	long smallz; // size=0, offset=16
	long bigz; // size=0, offset=20
};

struct WarpRoom // hashcode: 0x8963873E (dec: -1989966018)
{
	char name[16]; // size=16, offset=0
	struct _StreamUnit *streamUnit; // size=64, offset=16
};

struct PlanningNode // hashcode: 0x22DBD3C1 (dec: 584831937)
{
	struct _Position pos; // size=6, offset=0
	unsigned short flags; // size=0, offset=6
	unsigned long connectionStatus; // size=0, offset=8
	unsigned long connections; // size=0, offset=12
	unsigned short cost; // size=0, offset=16
	unsigned short parent; // size=0, offset=18
	unsigned short nodeType; // size=0, offset=20
	unsigned short id; // size=0, offset=22
	long streamUnitID; // size=0, offset=24
};

struct VramBuffer // hashcode: 0xF0C9293E (dec: -255252162)
{
	long flags; // size=0, offset=0
	short x; // size=0, offset=4
	short y; // size=0, offset=6
	short w; // size=0, offset=8
	short h; // size=0, offset=10
	short yOffset; // size=0, offset=12
	short lengthOfLeftOverData; // size=0, offset=14
	short *lineOverFlow; // size=0, offset=16
};

struct STREAM_289fake // hashcode: 0xE57F8529 (dec: -444627671)
{
	int warpgate_in_use; // size=0, offset=0
	char loading; // size=0, offset=4
	char blocked; // size=0, offset=5
	short fadeValue; // size=0, offset=6
	long curTime; // size=0, offset=8
	long maxTime; // size=0, offset=12
	struct _Instance *warpFaceInstance; // size=664, offset=16
};

struct PHYSOBS_109fake // hashcode: 0xAC62A192 (dec: -1402822254)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: PhysObs.o, PhysObs.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: PhysObs.o, PhysObs.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: PhysObs.o, PhysObs.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: PhysObs.o, PhysObs.o
};

struct evObjectData // hashcode: 0xD31AB4FF (dec: -753224449)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	short PathNumber; // size=0, offset=4
	short LinkNode; // size=0, offset=6
	struct _Instance *Force; // size=664, offset=8
	int rc; // size=0, offset=12
};

struct evPhysicsGravityData // hashcode: 0x21646503 (dec: 560227587)
{
	short UpperOffset; // size=0, offset=0
	short LowerOffset; // size=0, offset=2
	short x; // size=0, offset=4
	short y; // size=0, offset=6
	short z; // size=0, offset=8
	short slipSlope; // size=0, offset=10
};

struct evPhysicsSlideData // hashcode: 0x77FBC416 (dec: 2012988438)
{
	struct _SVector ForwardVector; // size=8, offset=0
	struct _SVector ForwardNormal; // size=8, offset=8
	struct _SVector DropNormal; // size=8, offset=16
	short Segment; // size=0, offset=24
	short DropOffset; // size=0, offset=26
	short UpperOffset; // size=0, offset=28
	short Height; // size=0, offset=30
	struct _Instance *UpperInstance; // size=664, offset=32
	int Dot; // size=0, offset=36
};

struct evObjectThrowData // hashcode: 0x4D2643FB (dec: 1294353403)
{
	short type; // size=0, offset=0
	short spinType; // size=0, offset=2
	union {
		struct _Instance *target; // size=664, offset=0
		struct _Position position; // size=6, offset=0
		struct _Rotation direction; // size=8, offset=0
		struct _Position throwVector; // size=6, offset=0
	} data; // size=8, offset=4, found in object files: PhysObs.o, PhysObs.o
	struct _SVector angularVel; // size=8, offset=12
	unsigned short speed; // size=0, offset=20
	short gravity; // size=0, offset=22
	short initialXRot; // size=0, offset=24
	short zVel; // size=0, offset=26
};

struct evObjectBirthProjectileData // hashcode: 0x7ED94533 (dec: 2128168243)
{
	struct _Instance *instance; // size=664, offset=0
	int joint; // size=0, offset=4
	int type; // size=0, offset=8
	struct _Instance *birthInstance; // size=664, offset=12
};

struct PhysObWeaponProperties // hashcode: 0xE4A47141 (dec: -458985151)
{
	struct PhysObProperties Properties; // size=8, offset=0
	struct PhysObWeaponAttributes WeaponAttributes; // size=28, offset=8
};

struct PhysObInteractProperties // hashcode: 0x5CAA78AA (dec: 1554675882)
{
	struct PhysObProperties Properties; // size=8, offset=0
	unsigned short conditions; // size=0, offset=8
	unsigned short auxConditions; // size=0, offset=10
	unsigned short action; // size=0, offset=12
	unsigned short auxAction; // size=0, offset=14
	unsigned char startAnim; // size=0, offset=16
	unsigned char endAnim; // size=0, offset=17
	unsigned char razielAnim; // size=0, offset=18
	unsigned char razielAuxAnim; // size=0, offset=19
	unsigned char frame; // size=0, offset=20
	unsigned char startAnimMode; // size=0, offset=21
	unsigned short distance; // size=0, offset=22
	unsigned short newType; // size=0, offset=24
	unsigned short newClass; // size=0, offset=26
	unsigned short mode; // size=0, offset=28
	unsigned short engageXYDistance; // size=0, offset=30
	short engageZMinDelta; // size=0, offset=32
	short engageZMaxDelta; // size=0, offset=34
	unsigned char engageYCone; // size=0, offset=36
	unsigned char engageZCone; // size=0, offset=37
	unsigned short pad; // size=0, offset=38
	struct PhysObWeaponAttributes *weapon; // size=28, offset=40
};

struct __PhysObProjectileProperties // hashcode: 0x245F8F39 (dec: 610242361)
{
	struct PhysObProperties Properties; // size=8, offset=0
	long totalProjectiles; // size=0, offset=8
	struct __PhysObProjectileData *data; // size=12, offset=12
};

struct PhysObDraftProperties // hashcode: 0x6B9FEB6D (dec: 1805642605)
{
	struct PhysObProperties Properties; // size=8, offset=0
	short force; // size=0, offset=8
	unsigned short radius; // size=0, offset=10
	unsigned short radiusCoef; // size=0, offset=12
	short maxVelocity; // size=0, offset=14
	unsigned long height; // size=0, offset=16
};

struct PhysObSwitchProperties // hashcode: 0xCADB5288 (dec: -891596152)
{
	struct PhysObProperties Properties; // size=8, offset=0
	short Distance; // size=0, offset=8
	short Class; // size=0, offset=10
	unsigned char onAnim; // size=0, offset=12
	unsigned char offAnim; // size=0, offset=13
	unsigned char failedOnAnim; // size=0, offset=14
	unsigned char enableAnim; // size=0, offset=15
	unsigned char shutAnim; // size=0, offset=16
	unsigned char onWalkTimer; // size=0, offset=17
	unsigned char offWalkTimer; // size=0, offset=18
	unsigned char walkMode; // size=0, offset=19
	unsigned char razielOnAnim; // size=0, offset=20
	unsigned char razielOffAnim; // size=0, offset=21
	unsigned char razielFailedOnAnim; // size=0, offset=22
	unsigned char razielEnableAnim; // size=0, offset=23
	unsigned char startMode; // size=0, offset=24
	unsigned char startAnim; // size=0, offset=25
	unsigned short engageXYDistance; // size=0, offset=26
	char engageZMinDelta; // size=0, offset=28
	char engageZMaxDelta; // size=0, offset=29
	unsigned char engageYCone; // size=0, offset=30
	unsigned char engageZCone; // size=0, offset=31
};

struct PhysObCollectibleProperties // hashcode: 0x0CD8F6CF (dec: 215545551)
{
	struct PhysObProperties Properties; // size=8, offset=0
	short collectClass; // size=0, offset=8
	short collectValue; // size=0, offset=10
	unsigned long distance; // size=0, offset=12
	unsigned char idleAnim; // size=0, offset=16
	unsigned char collectAnim; // size=0, offset=17
	unsigned short spatialNode; // size=0, offset=18
};

struct PhysObAnimatedProperties // hashcode: 0xA33AEFDC (dec: -1556418596)
{
	struct PhysObProperties Properties; // size=8, offset=0
	unsigned short flags; // size=0, offset=8
	unsigned short pad; // size=0, offset=10
};

struct PhysObData // hashcode: 0x3CB62FFA (dec: 1018572794)
{
	long Mode; // size=0, offset=0
	short xForce; // size=0, offset=4
	short yForce; // size=0, offset=6
	struct _Instance *Force; // size=664, offset=8
	short LinkNode; // size=0, offset=12
	short px; // size=0, offset=14
	short py; // size=0, offset=16
	short pz; // size=0, offset=18
	short rx1; // size=0, offset=20
	short ry1; // size=0, offset=22
	short rz1; // size=0, offset=24
	short Segment1; // size=0, offset=26
	short rx2; // size=0, offset=28
	short ry2; // size=0, offset=30
	short rz2; // size=0, offset=32
	short Segment2; // size=0, offset=34
	short Steps; // size=0, offset=36
	short Step; // size=0, offset=38
	short PathNumber; // size=0, offset=40
	short Pad1; // size=0, offset=42
	struct _HInfo *RightCollision; // size=24, offset=44
	struct _HInfo *LeftCollision; // size=24, offset=48
	short burnAmpl; // size=0, offset=52
	short throwFlags; // size=0, offset=54
	short initialXRot; // size=0, offset=56
	short xRotVel; // size=0, offset=58
	short yRotVel; // size=0, offset=60
	short zRotVel; // size=0, offset=62
	struct _Instance *throwingInstance; // size=664, offset=64
	int physObTimer; // size=0, offset=68
};

struct BreakOffData // hashcode: 0x505ED2BD (dec: 1348391613)
{
	short NewType; // size=0, offset=0
	short NewClass; // size=0, offset=2
};

struct ProjectileData // hashcode: 0x3D394AEE (dec: 1027164910)
{
	int Type; // size=0, offset=0
};

struct _PhysObSaveData // hashcode: 0x68509DE4 (dec: 1750113764)
{
	struct SwitchData switchData; // size=4, offset=0
	long Mode; // size=0, offset=4
};

struct SCRIPT2_114fake // hashcode: 0x543A9F47 (dec: 1413128007)
{
	struct {
		struct MultiSpline *posSpline; // size=80, offset=0
		struct MultiSpline *targetSpline; // size=80, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: script2.o, script2.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: script2.o, script2.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: script2.o, script2.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: script2.o, script2.o
};

struct LitShaftProperties // hashcode: 0xEB854ABA (dec: -343586118)
{
	short fadeValue; // size=0, offset=0
	short pad; // size=0, offset=2
};

struct SavedEventSmallVars // hashcode: 0x4F21E3CB (dec: 1327621067)
{
	unsigned char savedID; // size=0, offset=0
	unsigned char shiftedSaveSize; // size=0, offset=1
	short areaID; // size=0, offset=2
	char eventNumber; // size=0, offset=4
	char eventVariables[5]; // size=5, offset=5
};

struct WaterLevelProcess // hashcode: 0xDBFF4FF7 (dec: -604024841)
{
	long flags; // size=0, offset=0
	struct BSPTree *bspTree; // size=36, offset=4
	struct _StreamUnit *streamUnit; // size=0, offset=8
	short oldWaterZ; // size=0, offset=12
	short oldGlobalOffset; // size=0, offset=14
	short zValueFrom; // size=0, offset=16
	short zValueTo; // size=0, offset=18
	long maxSteps; // size=0, offset=20
	long curStep; // size=0, offset=24
};

struct EventInstanceObject // hashcode: 0x31AB53D9 (dec: 833311705)
{
	short id; // size=0, offset=0
	short flags; // size=0, offset=2
	long unitID; // size=0, offset=4
	long introUniqueID; // size=0, offset=8
	struct _Instance *instance; // size=664, offset=12
	union {
		struct Intro *intro; // size=76, offset=0
		struct _SFXMkr *sfxMarker; // size=36, offset=0
	} data; // size=4, offset=16, found in object files: event.o, event.o
};

struct EventEventObject // hashcode: 0x3259585A (dec: 844716122)
{
	short id; // size=0, offset=0
	short eventNumber; // size=0, offset=2
	long unitID; // size=0, offset=4
	struct Event *event; // size=0, offset=8
};

struct EventTGroupObject // hashcode: 0xF6A4A3D3 (dec: -156982317)
{
	short id; // size=0, offset=0
	short tgroupNumber; // size=0, offset=2
	long unitID; // size=0, offset=4
	struct BSPTree *bspTree; // size=36, offset=8
	struct _StreamUnit *stream; // size=0, offset=12
};

struct _PCodeStack // hashcode: 0x792404F9 (dec: 2032403705)
{
	long topOfStack; // size=0, offset=0
	struct StackType stack[32]; // size=1152, offset=4
};

struct EventTimer // hashcode: 0x49CEB070 (dec: 1238282352)
{
	long flags; // size=1, offset=0
	long time; // size=31, offset=1
	struct Event *event; // size=28, offset=4
	struct ScriptPCode *actionScript; // size=8, offset=8
	short *scriptPos; // size=0, offset=12
	struct Level *level; // size=392, offset=16
	long nextEventIndex; // size=0, offset=20
};

struct SignalResetStruct // hashcode: 0xF7BB5F2D (dec: -138715347)
{
	struct _MultiSignal *mSignal; // size=904, offset=0
	long timeLeft; // size=0, offset=4
};

struct HintSystemStruct // hashcode: 0xAE4602C6 (dec: -1371143482)
{
	short flags; // size=0, offset=0
	short hintNumber; // size=0, offset=2
	short stringNumber; // size=0, offset=4
	short pad; // size=0, offset=6
	long fadeTimer; // size=0, offset=8
	long spawningUnitID; // size=0, offset=12
};

struct STRMLOAD_116fake // hashcode: 0x5BA51FED (dec: 1537548269)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: strmload.o, strmload.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: strmload.o, strmload.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: strmload.o, strmload.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: strmload.o, strmload.o
};

struct PHYSICS_109fake // hashcode: 0x5EA21869 (dec: 1587681385)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: physics.o, physics.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: physics.o, physics.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: physics.o, physics.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: physics.o, physics.o
};

struct evPhysicsDropOffData // hashcode: 0x35127EA8 (dec: 890404520)
{
	short xOffset; // size=0, offset=0
	short yOffset; // size=0, offset=2
	short DropOffset; // size=0, offset=4
	short slipSlope; // size=0, offset=6
	int UpperOffset; // size=0, offset=8
};

struct evPhysicsEdgeData // hashcode: 0x323073DA (dec: 842036186)
{
	short UpperOffset; // size=0, offset=0
	short ForwardOffset; // size=0, offset=2
	short AboveOffset; // size=0, offset=4
	short XDistance; // size=0, offset=6
	short YDistance; // size=0, offset=8
	short ZDistance; // size=0, offset=10
	struct _SVector *Normal1; // size=8, offset=12
	struct _SVector *Normal2; // size=8, offset=16
	struct _SVector *Delta; // size=8, offset=20
	struct _Instance *instance; // size=664, offset=24
	int zRot; // size=0, offset=28
	int rc; // size=0, offset=32
};

struct evPhysicsWallCrawlData // hashcode: 0x3F532F62 (dec: 1062416226)
{
	short Segment; // size=0, offset=0
	short Length; // size=0, offset=2
	short ForwardOffset; // size=0, offset=4
	short NormalDistance; // size=0, offset=6
	struct _SVector DropNormal; // size=8, offset=8
	struct _SVector ForwardNormal; // size=8, offset=16
	struct _Position NewPosition; // size=6, offset=24
	struct _Rotation DropRotation; // size=8, offset=30
	short ForwardXRotation; // size=0, offset=38
	int rc; // size=0, offset=40
};

struct evPhysicsSwimData // hashcode: 0x04C82589 (dec: 80225673)
{
	short CheckDepth; // size=0, offset=0
	short SwimDepth; // size=0, offset=2
	short WadeDepth; // size=0, offset=4
	short TreadDepth; // size=0, offset=6
	struct _SVector *iVelocity; // size=8, offset=8
	short Depth; // size=0, offset=12
	short WaterDepth; // size=0, offset=14
	short rc; // size=0, offset=16
	short pad; // size=0, offset=18
	int WaterLevel; // size=0, offset=20
};

struct evPhysicsDropHeightData // hashcode: 0xC6B94AD5 (dec: -960935211)
{
	struct _Position origin; // size=6, offset=0
	short mode; // size=0, offset=6
	short DropOffset; // size=0, offset=8
	short result; // size=0, offset=10
	struct BSPTree *bsp; // size=36, offset=12
	struct _TFace *tface; // size=12, offset=16
};

struct evPhysicsLinkedMoveData // hashcode: 0xCF7D1718 (dec: -813885672)
{
	struct _Instance *instance; // size=664, offset=0
	int segment; // size=0, offset=4
	struct _SVector posDelta; // size=8, offset=8
	struct _SVector rotDelta; // size=8, offset=16
};

struct REAVER_114fake // hashcode: 0xCC1F1DCE (dec: -870375986)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: reaver.o, reaver.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: reaver.o, reaver.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: reaver.o, reaver.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: reaver.o, reaver.o
};

struct HUNTER_114fake // hashcode: 0x7F88C438 (dec: 2139669560)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: hunter.o, hunter.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: hunter.o, hunter.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: hunter.o, hunter.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: hunter.o, hunter.o
};

struct _MonsterAnim // hashcode: 0x1F91FAC1 (dec: 529660609)
{
	unsigned short velocity; // size=0, offset=0
	unsigned short distance; // size=0, offset=2
	unsigned short playSpeed; // size=0, offset=4
	unsigned char interpFrames; // size=0, offset=6
	unsigned char startFrame; // size=0, offset=7
	unsigned char interpOut; // size=0, offset=8
	unsigned char alphaTable; // size=0, offset=9
	unsigned char alphaTableOut; // size=0, offset=10
	unsigned char controllingSection; // size=0, offset=11
	char index[3]; // size=3, offset=12
	char pad; // size=0, offset=15
};

struct _MonsterIdle // hashcode: 0xB6F7C2C9 (dec: -1225276727)
{
	char anim; // size=0, offset=0
	char alertMod; // size=0, offset=1
	char probability; // size=0, offset=2
	char pad; // size=0, offset=3
};

struct _MonsterBehavior // hashcode: 0x6A9AC6A2 (dec: 1788528290)
{
	char alertness; // size=0, offset=0
	char idleFreq; // size=0, offset=1
	char numIdles; // size=0, offset=2
	char idleList[5]; // size=5, offset=3
};

struct _MonsterSenses // hashcode: 0x0E788F78 (dec: 242782072)
{
	short sightArc; // size=0, offset=0
	short sightRadius; // size=0, offset=2
	short sightElevation; // size=0, offset=4
	short soundArc; // size=0, offset=6
	short soundRadius; // size=0, offset=8
	short soundElevation; // size=0, offset=10
	unsigned short scentRadius; // size=0, offset=12
	short alarmRadius; // size=0, offset=14
	unsigned short allyRadius; // size=0, offset=16
};

struct _MonsterAllegiances // hashcode: 0x2480BBC8 (dec: 612416456)
{
	unsigned long enemies; // size=0, offset=0
	unsigned long allies; // size=0, offset=4
	unsigned long food; // size=0, offset=8
	unsigned long gods; // size=0, offset=12
};

struct _MonsterAttackAttributes // hashcode: 0x174EF7FB (dec: 391051259)
{
	short attackRange; // size=0, offset=0
	short attackHeight; // size=0, offset=2
	short knockBackDistance; // size=0, offset=4
	char knockBackDuration; // size=0, offset=6
	char damage; // size=0, offset=7
	char sphereSegment; // size=0, offset=8
	char sphereOnFrame; // size=0, offset=9
	char sphereOnAnim; // size=0, offset=10
	char sphereOffFrame; // size=0, offset=11
	char sphereOffAnim; // size=0, offset=12
	char turnFrames; // size=0, offset=13
	char numAnims; // size=0, offset=14
	char attackProbability[12]; // size=12, offset=15
	char animList[5]; // size=5, offset=27
};

struct _MonsterMissile // hashcode: 0xE8135188 (dec: -401387128)
{
	unsigned short speed; // size=0, offset=0
	unsigned short range; // size=0, offset=2
	unsigned char frame; // size=0, offset=4
	unsigned char anim; // size=0, offset=5
	unsigned char segment; // size=0, offset=6
	unsigned char damage; // size=0, offset=7
	unsigned char type; // size=0, offset=8
	unsigned char graphic; // size=0, offset=9
	char gravity; // size=0, offset=10
	char reload; // size=0, offset=11
	char fireChance; // size=0, offset=12
	unsigned char numAnims; // size=0, offset=13
	char animList[2]; // size=2, offset=14
};

struct _MonsterCombatAttributes // hashcode: 0x43748B8B (dec: 1131711371)
{
	short stunTime; // size=0, offset=0
	short damageTime; // size=0, offset=2
	short recovery; // size=0, offset=4
	short surpriseTime; // size=0, offset=6
	short grabTime; // size=0, offset=8
	short combatRange; // size=0, offset=10
	short surpriseRange; // size=0, offset=12
	short allyRange; // size=0, offset=14
	short enemyAttackRange; // size=0, offset=16
	short suckPower; // size=0, offset=18
	short suckRange; // size=0, offset=20
	short suckTime; // size=0, offset=22
	char hitPoints; // size=0, offset=24
	char numAttacks; // size=0, offset=25
	char missileAttack; // size=0, offset=26
	char ambushAttack; // size=0, offset=27
	char evadeProbability[12]; // size=12, offset=28
	char attackList[1]; // size=1, offset=40
};

struct _MonsterSubAttributes // hashcode: 0x20DEB0B2 (dec: 551465138)
{
	char *animList; // size=0, offset=0
	struct _MonsterSenses *senses; // size=18, offset=4
	struct _MonsterCombatAttributes *combatAttributes; // size=42, offset=8
	struct _MonsterAllegiances *allegiances; // size=16, offset=12
	char *behaviorList; // size=0, offset=16
	short scale; // size=0, offset=20
	short fallDistance; // size=0, offset=22
	short defAmbushRange; // size=0, offset=24
	short fleeRange; // size=0, offset=26
	short speedPivotTurn; // size=0, offset=28
	short speedWalkTurn; // size=0, offset=30
	short speedRunTurn; // size=0, offset=32
	short speedFleeTurn; // size=0, offset=34
	short forgetTime; // size=0, offset=36
	unsigned char modelNum; // size=0, offset=38
	unsigned char physAbility; // size=0, offset=39
	unsigned char stunnable; // size=0, offset=40
	unsigned char grabable; // size=0, offset=41
	unsigned char numSections; // size=0, offset=42
	unsigned char sectionEnd[3]; // size=3, offset=43
	short defPlayerAttitude; // size=0, offset=46
	short defWanderRange; // size=0, offset=48
	short defGuardRange; // size=0, offset=50
	unsigned char defInitialBehavior; // size=0, offset=52
	unsigned char defTriggeredBehavior; // size=0, offset=53
	char defActiveBehavior; // size=0, offset=54
	unsigned char defSpectral; // size=0, offset=55
	unsigned char sunVuln; // size=0, offset=56
	unsigned char fireVuln; // size=0, offset=57
	unsigned char waterVuln; // size=0, offset=58
	unsigned char impaleVuln; // size=0, offset=59
	unsigned char soundVuln; // size=0, offset=60
	unsigned char weaponVuln; // size=0, offset=61
	unsigned char missileVuln; // size=0, offset=62
	unsigned char bruiseRed; // size=0, offset=63
	unsigned char bruiseGreen; // size=0, offset=64
	unsigned char bruiseBlue; // size=0, offset=65
	short minSpikeRange; // size=0, offset=66
	short maxSpikeRange; // size=0, offset=68
	short maxSpikeAngle; // size=0, offset=70
	short minSpikeHorzSpeed; // size=0, offset=72
	short maxSpikeHorzSpeed; // size=0, offset=74
	short maxSpikeVertSpeed; // size=0, offset=76
	short upOnGroundOffset; // size=0, offset=78
	short downOnGroundOffset; // size=0, offset=80
};

struct _MonsterAttributes // hashcode: 0x022282CE (dec: 35816142)
{
	unsigned long magicnum; // size=0, offset=0
	void *tunData; // size=0, offset=4
	char *auxAnimList; // size=0, offset=8
	char *ambientAnimList; // size=0, offset=12
	long whatAmI; // size=0, offset=16
	char numAuxAnims; // size=0, offset=20
	char numAmbientAnims; // size=0, offset=21
	unsigned char defaultAge; // size=0, offset=22
	char pupateObject; // size=0, offset=23
	unsigned char damageFXSegment; // size=0, offset=24
	unsigned char headSegment; // size=0, offset=25
	unsigned char neckSegment; // size=0, offset=26
	unsigned char leftShoulderSegment; // size=0, offset=27
	unsigned char rightShoulderSegment; // size=0, offset=28
	unsigned char waistSegment; // size=0, offset=29
	unsigned char leftKneeSegment; // size=0, offset=30
	unsigned char rightKneeSegment; // size=0, offset=31
	unsigned char leftFootSegment; // size=0, offset=32
	unsigned char rightFootSegment; // size=0, offset=33
	unsigned char spineSegment; // size=0, offset=34
	unsigned char leftWeaponSegment; // size=0, offset=35
	unsigned char rightWeaponSegment; // size=0, offset=36
	unsigned char grabSegment; // size=0, offset=37
	unsigned char bloodImpaleFrame; // size=0, offset=38
	unsigned char bloodConeFrame; // size=0, offset=39
	char numSubAttributes; // size=0, offset=40
	char numCombatAttributes; // size=0, offset=41
	char numAttackAttributes; // size=0, offset=42
	char numMissiles; // size=0, offset=43
	char numAnims; // size=0, offset=44
	char numIdles; // size=0, offset=45
	char numBehaviors; // size=0, offset=46
	char numShatters; // size=0, offset=47
	struct _MonsterSubAttributes **subAttributesList; // size=84, offset=48
	struct _MonsterCombatAttributes **combatAttributesList; // size=42, offset=52
	struct _MonsterAttackAttributes *attackAttributesList; // size=32, offset=56
	struct _MonsterMissile *missileList; // size=16, offset=60
	struct _MonsterAnim *animList; // size=16, offset=64
	struct _MonsterIdle *idleList; // size=4, offset=68
	struct _MonsterBehavior *behaviorList; // size=8, offset=72
	void *shatterList; // size=0, offset=76
};

struct _MonsterVars // hashcode: 0x889ABAF8 (dec: -2003125512)
{
	unsigned long mvFlags; // size=0, offset=0
	unsigned long auxFlags; // size=0, offset=4
	struct __MessageQueue messageQueue; // size=136, offset=8
	struct _MonsterIR *monsterIRList; // size=0, offset=144
	struct _G2AnimInterpInfo_Type interpInfo[3]; // size=36, offset=148
	struct _MonsterAttackAttributes *attackType; // size=32, offset=184
	struct _MonsterAnim *anim; // size=16, offset=188
	void *messageData; // size=0, offset=192
	struct _MonsterIR *enemy; // size=0, offset=196
	struct _MonsterIR *leader; // size=0, offset=200
	struct _MonsterIR *ally; // size=0, offset=204
	struct _Instance *held; // size=664, offset=208
	long heldID; // size=0, offset=212
	long soulID; // size=0, offset=216
	void *effect; // size=0, offset=220
	unsigned long radarMap; // size=0, offset=224
	unsigned long radarCounter; // size=0, offset=228
	short radarDistance[16]; // size=32, offset=232
	unsigned long mode; // size=0, offset=264
	unsigned long damageTimer; // size=0, offset=268
	unsigned long stunTimer; // size=0, offset=272
	unsigned long generalTimer; // size=0, offset=276
	unsigned long effectTimer; // size=0, offset=280
	struct _Position *lookAtPos; // size=6, offset=284
	struct _Position destination; // size=6, offset=288
	short speed; // size=0, offset=294
	struct _Position lastValidPos; // size=6, offset=296
	struct _Position lookAtPosData; // size=6, offset=302
	short fleeMarker; // size=0, offset=308
	short wanderRange; // size=0, offset=310
	short guardRange; // size=0, offset=312
	short ambushRange; // size=0, offset=314
	short ambushArc; // size=0, offset=316
	short ambushElevation; // size=0, offset=318
	short hitPoints; // size=0, offset=320
	short maxHitPoints; // size=0, offset=322
	short soulJuice; // size=0, offset=324
	short regenTime; // size=0, offset=326
	short mainColorVertex; // size=0, offset=328
	short lookAngleX; // size=0, offset=330
	short lookAngleZ; // size=0, offset=332
	unsigned short avoidMask; // size=0, offset=334
	unsigned short damageType; // size=0, offset=336
	char ambushMarker; // size=0, offset=338
	char ambushJumpType; // size=0, offset=339
	unsigned char causeOfDeath; // size=0, offset=340
	char previousMainState; // size=0, offset=341
	unsigned char behaviorState; // size=0, offset=342
	unsigned char initialBehavior; // size=0, offset=343
	unsigned char triggeredBehavior; // size=0, offset=344
	char activeBehavior; // size=0, offset=345
	unsigned char age; // size=0, offset=346
	char attackState; // size=0, offset=347
	unsigned char ambient; // size=0, offset=348
	char alertness; // size=0, offset=349
	char alertCount; // size=0, offset=350
	char senseIndex; // size=0, offset=351
	char lastSideMove; // size=0, offset=352
	char chance; // size=0, offset=353
	char pathSlotID; // size=0, offset=354
	struct _MonsterSubAttributes *subAttr; // size=84, offset=356
	struct _MonsterIR *freeIRs; // size=0, offset=360
	void *extraVars; // size=0, offset=364
	short validUnits[10]; // size=20, offset=368
	short patrolMarkers[12]; // size=24, offset=388
	short *currentMarker; // size=0, offset=412
	long terrainImpaleID; // size=0, offset=416
	short targetFade; // size=0, offset=420
	short fadeRate; // size=0, offset=422
};

struct _MonsterIR // hashcode: 0xBA5CB169 (dec: -1168330391)
{
	struct _MonsterIR *next; // size=36, offset=0
	struct _Instance *instance; // size=664, offset=4
	long handle; // size=0, offset=8
	struct _SVector relativePosition; // size=8, offset=12
	short distance; // size=0, offset=20
	unsigned short mirFlags; // size=0, offset=22
	unsigned short mirConditions; // size=0, offset=24
	unsigned long forgetTimer; // size=0, offset=28
	unsigned long idleTime; // size=0, offset=32
};

struct burntTuneType // hashcode: 0xC8EEBBAF (dec: -923878481)
{
	int burntDist; // size=0, offset=0
	int fadeDelta; // size=0, offset=4
};

struct _MonsterState // hashcode: 0x63242942 (dec: 1663314242)
{
	void (*entryFunction)(); // size=0, offset=0
	void (*stateFunction)(); // size=0, offset=4
};

struct _MonsterStateChoice // hashcode: 0x4DA4D5F2 (dec: 1302648306)
{
	int state; // size=0, offset=0
	struct _MonsterState functions; // size=8, offset=4
};

struct _MonsterFunctionTable // hashcode: 0xA7CE8FD0 (dec: -1479634992)
{
	void (*initFunc)(); // size=0, offset=0
	void (*cleanUpFunc)(); // size=0, offset=4
	void (*damageEffectFunc)(); // size=0, offset=8
	unsigned long (*queryFunc)(); // size=0, offset=12
	void (*messageFunc)(); // size=0, offset=16
	struct _MonsterStateChoice *stateFuncs; // size=12, offset=20
	char *versionID; // size=0, offset=24
	char *localVersionID; // size=0, offset=28
};

struct _HunterVars // hashcode: 0x432C354E (dec: 1126970702)
{
	short startIdx; // size=0, offset=0
	short endIdx; // size=0, offset=2
	int rem_time; // size=0, offset=4
	int timer; // size=0, offset=8
	short angles[16]; // size=32, offset=12
};

struct _HunterAttributes // hashcode: 0x46CBFAC6 (dec: 1187773126)
{
	int timeToFire; // size=0, offset=0
};

struct MISSILE_114fake // hashcode: 0xEFEC1245 (dec: -269741499)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: missile.o, missile.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: missile.o, missile.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: missile.o, missile.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: missile.o, missile.o
};

struct MissileGraphics // hashcode: 0x89A590FC (dec: -1985638148)
{
	unsigned char object; // size=0, offset=0
	unsigned char model; // size=0, offset=1
};

struct MONAPI_114fake // hashcode: 0x2D4C9F6F (dec: 759996271)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: monapi.o, monapi.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: monapi.o, monapi.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: monapi.o, monapi.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: monapi.o, monapi.o
};

struct evMonsterHitTerrainData // hashcode: 0xC63DE155 (dec: -969023147)
{
	struct _TFace *tface; // size=12, offset=0
	struct _Normal normal; // size=8, offset=4
	short faceFlags; // size=0, offset=12
};

struct evMonsterHitObjectData // hashcode: 0xD0782913 (dec: -797431533)
{
	struct _Instance *instance; // size=664, offset=0
	int hitType; // size=0, offset=4
};

struct evShadowSegmentData // hashcode: 0xB914F0A8 (dec: -1189810008)
{
	unsigned long totalShadowSegments; // size=0, offset=0
	unsigned short shadowSegments[4]; // size=8, offset=4
};

struct _MonsterSaveInfo // hashcode: 0x4394F64B (dec: 1133835851)
{
	long mvFlags; // size=0, offset=0
	long auxFlags; // size=0, offset=4
	short soulID; // size=0, offset=8
	short soulJuice; // size=0, offset=10
	unsigned int age; // size=3, offset=96
	unsigned int state; // size=6, offset=99
	unsigned int behaviorState; // size=5, offset=105
	unsigned int anim; // size=6, offset=110
	unsigned int causeOfDeath; // size=3, offset=116
};

struct RAZCNTRL_109fake // hashcode: 0xB11AF26C (dec: -1323634068)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: razcntrl.o, razcntrl.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: razcntrl.o, razcntrl.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: razcntrl.o, razcntrl.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: razcntrl.o, razcntrl.o
};

struct STATE_109fake // hashcode: 0x501F7359 (dec: 1344238425)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: state.o, state.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: state.o, state.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: state.o, state.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: state.o, state.o
};

struct __CharacterState // hashcode: 0x2A1FEF6F (dec: 706735983)
{
	struct _Instance *CharacterInstance; // size=664, offset=0
	int TotalSections; // size=0, offset=4
	struct __State SectionList[3]; // size=852, offset=8
};

struct evMonsterHitData // hashcode: 0x092F9EE8 (dec: 154115816)
{
	struct _Instance *sender; // size=664, offset=0
	struct _Instance *lastHit; // size=664, offset=4
	short knockBackDistance; // size=0, offset=8
	short knockBackDuration; // size=0, offset=10
	long power; // size=0, offset=12
};

struct evMonsterThrownData // hashcode: 0x1D16312B (dec: 487993643)
{
	struct _Instance *sender; // size=664, offset=0
	struct _Rotation direction; // size=8, offset=4
	short power; // size=0, offset=12
};

struct evMonsterAlarmData // hashcode: 0x9929796C (dec: -1725335188)
{
	struct _Instance *sender; // size=664, offset=0
	struct _Position position; // size=6, offset=4
	short type; // size=0, offset=10
};

struct evMonsterSoulSuckData // hashcode: 0x2C84DFED (dec: 746905581)
{
	struct _Instance *sender; // size=664, offset=0
	struct _Position Destination; // size=6, offset=4
};

struct evFXHitData // hashcode: 0x20928078 (dec: 546472056)
{
	struct _SVector location; // size=8, offset=0
	struct _SVector velocity; // size=8, offset=8
	short amount; // size=0, offset=16
	short type; // size=0, offset=18
};

struct evAnimationControllerDoneData // hashcode: 0x57184154 (dec: 1461207380)
{
	struct _Instance *instance; // size=664, offset=0
	long segment; // size=0, offset=4
	long type; // size=0, offset=8
	int data; // size=0, offset=12
};

struct evMonsterImpaleData // hashcode: 0x7630398D (dec: 1982871949)
{
	struct _Instance *weapon; // size=664, offset=0
	struct _Rotation direction; // size=8, offset=4
	struct _Position position; // size=6, offset=12
	short distance; // size=0, offset=18
};

struct evObjectBreakOffData // hashcode: 0xA485323A (dec: -1534774726)
{
	struct _Instance *force; // size=664, offset=0
	unsigned short node; // size=0, offset=4
	short distance; // size=0, offset=6
	unsigned short animation; // size=0, offset=8
	unsigned short frame; // size=0, offset=10
	unsigned short type; // size=0, offset=12
	unsigned short action; // size=0, offset=14
};

struct evObjectAbsorbData // hashcode: 0x91CFEDF3 (dec: -1848644109)
{
	struct _Instance *force; // size=664, offset=0
	unsigned short node; // size=0, offset=4
	unsigned short steps; // size=0, offset=6
};

struct evObjectIdleData // hashcode: 0xC1DDB451 (dec: -1042434991)
{
	long mode; // size=0, offset=0
	struct _Instance *instance; // size=664, offset=4
};

struct evControlInitHangData // hashcode: 0xF53D826A (dec: -180518294)
{
	struct _Instance *instance; // size=664, offset=0
	int frame; // size=0, offset=4
	int frames; // size=0, offset=8
};

struct evControlInitIdleData // hashcode: 0x606D83FB (dec: 1617789947)
{
	int mode; // size=0, offset=0
	int frame; // size=0, offset=4
	int frames; // size=0, offset=8
};

struct evActionLookAroundData // hashcode: 0xF3338905 (dec: -214726395)
{
	short *rotx; // size=0, offset=0
	short *rotz; // size=0, offset=4
	short minx; // size=0, offset=8
	short maxx; // size=0, offset=10
	short minz; // size=0, offset=12
	short maxz; // size=0, offset=14
};

struct evActionPlayHostAnimationData // hashcode: 0xD2499380 (dec: -766930048)
{
	struct _Instance *instance; // size=664, offset=0
	struct _Instance *host; // size=664, offset=4
	int newAnim; // size=0, offset=8
	int newFrame; // size=0, offset=12
	int frames; // size=0, offset=16
	int mode; // size=0, offset=20
};

struct VRAM_114fake // hashcode: 0x27F2E795 (dec: 670230421)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: vram.o, vram.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: vram.o, vram.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: vram.o, vram.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: vram.o, vram.o
};

struct GLYPH_114fake // hashcode: 0x056239F4 (dec: 90323444)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: glyph.o, glyph.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: glyph.o, glyph.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: glyph.o, glyph.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: glyph.o, glyph.o
};

struct __GlyphData // hashcode: 0x4ADB7C10 (dec: 1255898128)
{
	void (*process)(); // size=0, offset=0
	struct __MessageQueue messages; // size=136, offset=4
	short selectedGlyph; // size=0, offset=140
	short glyph_open; // size=0, offset=142
	short glyph_time; // size=0, offset=144
	short glyph_radius; // size=0, offset=146
	short glyph_scale; // size=0, offset=148
	short glyph_rotation; // size=0, offset=150
	short target_glyph_rotation; // size=0, offset=152
	short glyph_movement; // size=0, offset=154
};

struct HUMAN_114fake // hashcode: 0x97ACFB2B (dec: -1750271189)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: human.o, human.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: human.o, human.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: human.o, human.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: human.o, human.o
};

struct MONMSG_114fake // hashcode: 0xE4C8644A (dec: -456629174)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: monmsg.o, monmsg.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: monmsg.o, monmsg.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: monmsg.o, monmsg.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: monmsg.o, monmsg.o
};

struct MONSENSE_114fake // hashcode: 0xA89B14AF (dec: -1466231633)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: monsense.o, monsense.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: monsense.o, monsense.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: monsense.o, monsense.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: monsense.o, monsense.o
};

struct evPhysicsLOSData // hashcode: 0x7EDD9F1E (dec: 2128453406)
{
	struct _Position destination; // size=6, offset=0
	short arc; // size=0, offset=6
	struct _Position origin; // size=6, offset=8
	short flags; // size=0, offset=14
	short result; // size=0, offset=16
};

struct RadarInfo // hashcode: 0x408EAC8A (dec: 1083092106)
{
	short angle; // size=0, offset=0
	short x; // size=0, offset=2
	short y; // size=0, offset=4
};

struct MONSTER_114fake // hashcode: 0x06BB6B91 (dec: 112946065)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: monster.o, monster.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: monster.o, monster.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: monster.o, monster.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: monster.o, monster.o
};

struct burntMessType // hashcode: 0x46AC8451 (dec: 1185711185)
{
	int closestvert; // size=0, offset=0
	int closestdist; // size=0, offset=4
	int closestseg; // size=0, offset=8
	struct burntTuneType *burntTune; // size=8, offset=12
};

struct bloodyMessType // hashcode: 0x1A47EDAE (dec: 440921518)
{
	int closestvert; // size=0, offset=0
	int closestdist; // size=0, offset=4
	int closestseg; // size=0, offset=8
	int bloodiedAVert; // size=0, offset=12
	int bloodIntensity; // size=0, offset=16
};

struct MONLIB_114fake // hashcode: 0x2D11AA47 (dec: 756132423)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: monlib.o, monlib.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: monlib.o, monlib.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: monlib.o, monlib.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: monlib.o, monlib.o
};

struct VWRAITH_114fake // hashcode: 0xE9D3C0E5 (dec: -371998491)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: vwraith.o, vwraith.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: vwraith.o, vwraith.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: vwraith.o, vwraith.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: vwraith.o, vwraith.o
};

struct SKINNER_114fake // hashcode: 0xF45A574D (dec: -195406003)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: skinner.o, skinner.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: skinner.o, skinner.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: skinner.o, skinner.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: skinner.o, skinner.o
};

struct SLUAGH_114fake // hashcode: 0xA6FEDE4C (dec: -1493246388)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: sluagh.o, sluagh.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: sluagh.o, sluagh.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: sluagh.o, sluagh.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: sluagh.o, sluagh.o
};

struct SOUL_114fake // hashcode: 0x6FDC36FD (dec: 1876702973)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: soul.o, soul.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: soul.o, soul.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: soul.o, soul.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: soul.o, soul.o
};

struct MONTABLE_109fake // hashcode: 0x31ACF2E9 (dec: 833417961)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: montable.o, montable.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: montable.o, montable.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: montable.o, montable.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: montable.o, montable.o
};

struct MONTABLE_202fake // hashcode: 0xA824099F (dec: -1474033249)
{
	long whatAmI; // size=0, offset=0
	struct _MonsterFunctionTable *table; // size=32, offset=4
};

struct MORLOCK_114fake // hashcode: 0x306A5CFF (dec: 812276991)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: morlock.o, morlock.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: morlock.o, morlock.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: morlock.o, morlock.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: morlock.o, morlock.o
};

struct INSTNCG2_109fake // hashcode: 0xE028B20F (dec: -534203889)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: InstncG2.o, InstncG2.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: InstncG2.o, InstncG2.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: InstncG2.o, InstncG2.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: InstncG2.o, InstncG2.o
};

struct MATRIXG2_109fake // hashcode: 0x7BD4E676 (dec: 2077550198)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: MatrixG2.o, MatrixG2.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: MatrixG2.o, MatrixG2.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: MatrixG2.o, MatrixG2.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: MatrixG2.o, MatrixG2.o
};

struct _G2PoolMemPool_Type // hashcode: 0xAAA369CB (dec: -1432131125)
{
	unsigned short blockSize; // size=0, offset=0
	unsigned short stackTop; // size=0, offset=2
	unsigned short stackSize; // size=0, offset=4
	unsigned short *stack; // size=0, offset=8
	struct _G2PoolMem_Type *blockPool; // size=0, offset=12
};

struct TIMERG2_109fake // hashcode: 0xDE8B092D (dec: -561313491)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: TimerG2.o, TimerG2.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: TimerG2.o, TimerG2.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: TimerG2.o, TimerG2.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: TimerG2.o, TimerG2.o
};

struct _G2AppDataVM_Type // hashcode: 0x20DE3C90 (dec: 551435408)
{
	int argc; // size=0, offset=0
	int *argv; // size=0, offset=4
};

struct WORSHIP_114fake // hashcode: 0xF64E4032 (dec: -162643918)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: worship.o, worship.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: worship.o, worship.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: worship.o, worship.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: worship.o, worship.o
};

struct MBMISS_114fake // hashcode: 0x8312595A (dec: -2095949478)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: mbmiss.o, mbmiss.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: mbmiss.o, mbmiss.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: mbmiss.o, mbmiss.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: mbmiss.o, mbmiss.o
};

struct _walbossAttributes // hashcode: 0x4D86CADC (dec: 1300679388)
{
	unsigned char segmentToAttach; // size=0, offset=0
	unsigned char frameToBirth; // size=0, offset=1
	unsigned char frameToExpel; // size=0, offset=2
	unsigned char maxEggHits; // size=0, offset=3
	short maxAngle; // size=0, offset=4
	short timeForHitAgony; // size=0, offset=6
	short segmentForBodyTwist; // size=0, offset=8
	short timeToThornPrep; // size=0, offset=10
	short timeToThornPoke; // size=0, offset=12
	short timeToEggThrob; // size=0, offset=14
	short timeToEggExplode; // size=0, offset=16
	short razielStunTime; // size=0, offset=18
	short eggIgniteDist; // size=0, offset=20
	short junk; // size=0, offset=22
	struct {
		short plusDelta; // size=0, offset=0
		short minusDelta; // size=0, offset=2
		short validAtHitPoint; // size=0, offset=4
	} attackDeltas; // size=0, offset=24, found in object files: mbmiss.o, mbmiss.o
};

struct _G2AnimController_Type // hashcode: 0x1C5BE24C (dec: 475783756)
{
	unsigned short next; // size=0, offset=0
	unsigned char type; // size=0, offset=2
	unsigned char segNumber; // size=0, offset=3
	void *callbackData; // size=0, offset=4
	unsigned short flags; // size=0, offset=8
	short duration; // size=0, offset=10
	short elapsedTime; // size=0, offset=12
	struct _G2AnimAlphaTable_Type *alphaTable; // size=4, offset=16
	union {
		struct {
			unsigned long (*function)(); // size=0, offset=0
			void *fnData; // size=0, offset=4
		} callback; // size=8, offset=0, found in object files: AnimG2.o, AnimG2.o
		struct {
			struct _G2SVector3_Type base; // size=6, offset=0
			struct _G2SVector3_Type offset; // size=6, offset=6
		} vector; // size=12, offset=0, found in object files: AnimG2.o, AnimG2.o
		struct {
			struct _G2Quat_Type src; // size=8, offset=0
			struct _G2Quat_Type dest; // size=8, offset=8
		} quat; // size=16, offset=0, found in object files: AnimG2.o, AnimG2.o
	} data; // size=16, offset=20, found in object files: AnimG2.o, AnimG2.o
};

struct ANIMG2_109fake // hashcode: 0x059750A0 (dec: 93802656)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: AnimG2.o, AnimG2.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: AnimG2.o, AnimG2.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: AnimG2.o, AnimG2.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: AnimG2.o, AnimG2.o
};

struct _G2AnimSegKeyflagInfo_Type // hashcode: 0x41B98667 (dec: 1102677607)
{
	unsigned long *stream; // size=0, offset=0
	unsigned long flags; // size=0, offset=4
	int bitCount; // size=0, offset=8
};

struct _G2AnimDecompressChannelInfo_Type // hashcode: 0x830C5BAF (dec: -2096342097)
{
	struct _G2AnimKeylist_Type *keylist; // size=20, offset=0
	unsigned short *chanData; // size=0, offset=4
	int storedKey; // size=0, offset=8
	int targetKey; // size=0, offset=12
};

struct _G2AnimSegValue_Type // hashcode: 0x84C635B4 (dec: -2067384908)
{
	union {
		struct _G2SVector3_Type rot; // size=6, offset=0
		struct _G2Quat_Type quat; // size=8, offset=0
	} rotQuat; // size=8, offset=0, found in object files: AnimG2.o, AnimG2.o
	struct _G2SVector3_Type scale; // size=6, offset=8
	unsigned short pad; // size=0, offset=14
	struct _G2SVector3_Type trans; // size=6, offset=16
	unsigned short bIsQuat; // size=0, offset=22
};

struct _G2AnimChanStatusBlockPool_Type // hashcode: 0x471734BC (dec: 1192703164)
{
	unsigned short blockSize; // size=0, offset=0
	unsigned short stackTop; // size=0, offset=2
	unsigned short stackSize; // size=0, offset=4
	unsigned short *stack; // size=0, offset=8
	struct _G2AnimChanStatusBlock_Type *blockPool; // size=36, offset=12
};

struct _G2AnimControllerPool_Type // hashcode: 0xA792BA9C (dec: -1483556196)
{
	unsigned short blockSize; // size=0, offset=0
	unsigned short stackTop; // size=0, offset=2
	unsigned short stackSize; // size=0, offset=4
	unsigned short *stack; // size=0, offset=8
	struct _G2AnimController_Type *blockPool; // size=36, offset=12
};

struct _G2AnimInterpStateBlockPool_Type // hashcode: 0x2EA58E03 (dec: 782601731)
{
	unsigned short blockSize; // size=0, offset=0
	unsigned short stackTop; // size=0, offset=2
	unsigned short stackSize; // size=0, offset=4
	unsigned short *stack; // size=0, offset=8
	struct _G2AnimInterpStateBlock_Type *blockPool; // size=164, offset=12
};

struct ENMYPLAN_114fake // hashcode: 0x88AD0E88 (dec: -2001924472)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: enmyplan.o, enmyplan.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: enmyplan.o, enmyplan.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: enmyplan.o, enmyplan.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: enmyplan.o, enmyplan.o
};

struct EnemyPlanData // hashcode: 0xC8B9DD68 (dec: -927343256)
{
	unsigned char nodeSkipArray[8]; // size=8, offset=0
	unsigned char nodeTypeArray[8]; // size=8, offset=8
	struct _Position wayPointArray[8]; // size=48, offset=16
	short goalUnitID; // size=0, offset=64
	unsigned char numWayPoints; // size=0, offset=66
};

struct EnemyPlanSlotData // hashcode: 0x9890B30F (dec: -1735347441)
{
	char slotInUse; // size=0, offset=0
	char state; // size=0, offset=1
	char wayPointBeingServoedTo; // size=0, offset=2
	struct _Position startPos; // size=6, offset=4
	struct _Position goalPos; // size=6, offset=10
	struct _Position oldCurrentPos; // size=6, offset=16
	struct EnemyPlanData planData; // size=68, offset=22
	char targetType; // size=0, offset=90
	short timer; // size=0, offset=92
};

struct PLAN_114fake // hashcode: 0x53FAB65F (dec: 1408939615)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: plan.o, plan.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: plan.o, plan.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: plan.o, plan.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: plan.o, plan.o
};

struct _PlanCollideInfo // hashcode: 0xE5C119C1 (dec: -440329791)
{
	long StreamUnitID; // size=0, offset=0
	struct _TFace *tFace; // size=12, offset=4
	struct _Position collidePos; // size=6, offset=8
};

struct PLANAPI_150fake // hashcode: 0x36C47FB3 (dec: 918847411)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: planapi.o, planapi.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: planapi.o, planapi.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: planapi.o, planapi.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: planapi.o, planapi.o
};

struct PoolManagementData // hashcode: 0x706DC5B2 (dec: 1886242226)
{
	char state; // size=0, offset=0
	unsigned char numNodesInPool; // size=0, offset=1
	struct _Position playerPosAtLastPlanMkrUpdate; // size=6, offset=2
	struct PlanningNode *expansionNode1; // size=28, offset=8
	struct PlanningNode *expansionNode2; // size=28, offset=12
	unsigned short (*distanceMatrix)[32]; // size=4, offset=16
	unsigned short pairType; // size=0, offset=20
	struct _Position peakPos; // size=6, offset=22
	unsigned char currentNode; // size=0, offset=28
	unsigned char currentBit; // size=0, offset=29
};

struct PLANCOLL_114fake // hashcode: 0x7F92AE04 (dec: 2140319236)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: plancoll.o, plancoll.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: plancoll.o, plancoll.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: plancoll.o, plancoll.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: plancoll.o, plancoll.o
};

struct _fth // hashcode: 0xE9A0D0CA (dec: -375336758)
{
	char x; // size=0, offset=0
	char y; // size=0, offset=1
	char z; // size=0, offset=2
	char nodeType; // size=0, offset=3
};

struct PLANDRAW_114fake // hashcode: 0x7B6CCFA7 (dec: 2070728615)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: plandraw.o, plandraw.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: plandraw.o, plandraw.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: plandraw.o, plandraw.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: plandraw.o, plandraw.o
};

struct PLANOPT_150fake // hashcode: 0xA60CA98A (dec: -1509119606)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: planopt.o, planopt.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: planopt.o, planopt.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: planopt.o, planopt.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: planopt.o, planopt.o
};

struct PLANPOOL_150fake // hashcode: 0xED428F91 (dec: -314404975)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: planpool.o, planpool.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: planpool.o, planpool.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: planpool.o, planpool.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: planpool.o, planpool.o
};

struct PLANSRCH_150fake // hashcode: 0x98CB17ED (dec: -1731520531)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: plansrch.o, plansrch.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: plansrch.o, plansrch.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: plansrch.o, plansrch.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: plansrch.o, plansrch.o
};

struct CONTROL_109fake // hashcode: 0x05A1BAF2 (dec: 94485234)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: control.o, control.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: control.o, control.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: control.o, control.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: control.o, control.o
};

struct __Force // hashcode: 0xE41B2D58 (dec: -467980968)
{
	int Type; // size=0, offset=0
	struct _Vector LinearForce; // size=12, offset=4
	short Friction; // size=0, offset=16
};

struct __Idle // hashcode: 0x691BBAF7 (dec: 1763425015)
{
	unsigned char anim; // size=0, offset=0
	unsigned char frame; // size=0, offset=1
	unsigned char frames; // size=0, offset=2
	unsigned char type; // size=0, offset=3
};

struct __VAnim // hashcode: 0x89F3A8AD (dec: -1980520275)
{
	unsigned char anim0; // size=0, offset=0
	unsigned char anim1; // size=0, offset=1
	unsigned char anim2; // size=0, offset=2
	unsigned char frames; // size=0, offset=3
	unsigned char mode; // size=0, offset=4
	unsigned char alpha; // size=0, offset=5
	unsigned short frame; // size=0, offset=6
};

struct __SAnim // hashcode: 0x1C892C52 (dec: 478751826)
{
	struct __VAnim *anim; // size=8, offset=0
	struct __SAnim *nextAnim; // size=16, offset=4
	short mode; // size=0, offset=8
	short data; // size=0, offset=10
	short speedAdjust; // size=0, offset=12
	short pad; // size=0, offset=14
};

struct __AttackItem // hashcode: 0x825A3E01 (dec: -2108015103)
{
	unsigned char anim; // size=0, offset=0
	unsigned char framesIn; // size=0, offset=1
	unsigned char alphaIn; // size=0, offset=2
	unsigned char framesOut; // size=0, offset=3
	unsigned char switchDelay; // size=0, offset=4
	unsigned char ignoreDelay; // size=0, offset=5
	unsigned char segmentToGlow; // size=0, offset=6
	unsigned char startCollisionFrame; // size=0, offset=7
	unsigned char handsToCollide; // size=0, offset=8
	unsigned char endCollisionFrame; // size=0, offset=9
	unsigned char ribbonStartFrame; // size=0, offset=10
	unsigned char ribbonStartSegment; // size=0, offset=11
	unsigned char ribbonEndSegment; // size=0, offset=12
	unsigned char ribbonLifeTime; // size=0, offset=13
	unsigned char ribbonFaceLifeTime; // size=0, offset=14
	unsigned char knockBackFrames; // size=0, offset=15
	unsigned char glowFadeInFrames; // size=0, offset=16
	unsigned char glowFadeOutFrames; // size=0, offset=17
	unsigned short ribbonStartOpacity; // size=0, offset=18
	unsigned long ribbonStartColor; // size=0, offset=20
	unsigned long ribbonEndColor; // size=0, offset=24
	unsigned long glowColor; // size=0, offset=28
	unsigned short knockBackDistance; // size=0, offset=32
	unsigned short hitPowerScale; // size=0, offset=34
};

struct __ThrowItem // hashcode: 0x5817A03E (dec: 1477943358)
{
	unsigned char prepAnim; // size=0, offset=0
	unsigned char prepAnimFramesIn; // size=0, offset=1
	unsigned char prepAnimAlphaIn; // size=0, offset=2
	unsigned char coilAnim; // size=0, offset=3
	unsigned char coilAnimFramesIn; // size=0, offset=4
	unsigned char coilAnimAlphaIn; // size=0, offset=5
	unsigned char throwAnim; // size=0, offset=6
	unsigned char throwAnimFramesInFactor; // size=0, offset=7
	unsigned char throwFrameToLaunch; // size=0, offset=8
	unsigned char framesOut; // size=0, offset=9
	short launchPointX; // size=0, offset=10
	short launchPointY; // size=0, offset=12
	short launchPointZ; // size=0, offset=14
	short maxXRotation; // size=0, offset=16
	short minXRotation; // size=0, offset=18
	short maxZRotation; // size=0, offset=20
	short minZRotation; // size=0, offset=22
	short velocity; // size=0, offset=24
	short gravity; // size=0, offset=26
	short coilRot; // size=0, offset=28
	short pad; // size=0, offset=30
};

struct __EngagedInstance // hashcode: 0x2380F480 (dec: 595653760)
{
	struct _Instance *instance; // size=664, offset=0
	unsigned long distance; // size=0, offset=4
};

struct __FitPoint // hashcode: 0x739C60BA (dec: 1939628218)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
};

struct __SensoryData // hashcode: 0xD9EBC207 (dec: -638860793)
{
	int Flags; // size=0, offset=0
	struct _SVector ForwardNormal; // size=8, offset=4
	struct _SVector AboveNormal; // size=8, offset=12
	struct _SVector BelowNormal; // size=8, offset=20
	struct _SVector BelowPoint; // size=8, offset=28
	struct _SVector Delta; // size=8, offset=36
	struct _Instance *HitMonster; // size=664, offset=44
	struct _Instance *CurrentAutoFace; // size=664, offset=48
	struct _Instance *LastAutoFace; // size=664, offset=52
	struct __EngagedInstance *EngagedList; // size=8, offset=56
	unsigned long EngagedMask; // size=0, offset=60
	struct _Vector lookAtPoint; // size=12, offset=64
	unsigned long heldClass; // size=0, offset=76
};

struct __Player // hashcode: 0x2DA7D2F5 (dec: 765973237)
{
	int footPrint; // size=0, offset=0
	struct __CharacterState State; // size=860, offset=4
	int Mode; // size=0, offset=864
	int Anim; // size=0, offset=868
	int RotationSegment; // size=0, offset=872
	struct _SVector iVelocity; // size=8, offset=876
	int Magnitude; // size=0, offset=884
	int input; // size=0, offset=888
	int lastInput; // size=0, offset=892
	int ZDirection; // size=0, offset=896
	short Bearing; // size=0, offset=900
	short LastBearing; // size=0, offset=902
	int steeringMode; // size=0, offset=904
	short steeringVelocity; // size=0, offset=908
	short steeringAcceleration; // size=0, offset=910
	int steeringLockRotation; // size=0, offset=912
	short movementMinRate; // size=0, offset=916
	short movementMaxRate; // size=0, offset=918
	short movementMinAnalog; // size=0, offset=920
	short movementMaxAnalog; // size=0, offset=922
	struct __SensoryData Senses; // size=80, offset=924
	struct _Instance *attachedPlatform; // size=664, offset=1004
	short dropOffHeight; // size=0, offset=1008
	short fallZVelocity; // size=0, offset=1010
	short HealthScale; // size=0, offset=1012
	short HealthBalls; // size=0, offset=1014
	int HitPoints; // size=0, offset=1016
	int DamageFrequency; // size=0, offset=1020
	int invincibleTimer; // size=0, offset=1024
	int Abilities; // size=0, offset=1028
	struct _Instance *GlyphSystem; // size=664, offset=1032
	unsigned short GlyphManaBalls; // size=0, offset=1036
	unsigned short GlyphManaMax; // size=0, offset=1038
	struct __FitPoint *constrictData; // size=4, offset=1040
	short constrictIndex; // size=0, offset=1044
	short constrictWaitIndex; // size=0, offset=1046
	struct _SVector constrictCenter; // size=8, offset=1048
	short constrictFlag; // size=0, offset=1056
	short constrictGoodCircle; // size=0, offset=1058
	unsigned long constrictXTotal; // size=0, offset=1060
	unsigned long constrictYTotal; // size=0, offset=1064
	struct _Instance *soulReaver; // size=664, offset=1068
	unsigned long currentSoulReaver; // size=0, offset=1072
	int CurrentPlane; // size=0, offset=1076
	int slipSlope; // size=0, offset=1080
	unsigned long idleCount; // size=0, offset=1084
	struct _Instance *idleInstance; // size=664, offset=1088
	struct __AttackItem *attack; // size=36, offset=1092
	int attackFlags; // size=0, offset=1096
	int currentAttack; // size=0, offset=1100
	struct _Instance *attackCurrentHit; // size=664, offset=1104
	struct _Instance *attackLastHit; // size=664, offset=1108
	struct _FXGlowEffect *glowEffect; // size=44, offset=1112
	struct _Instance *attackedBy; // size=664, offset=1116
	struct __ThrowItem *throwData; // size=32, offset=1120
	int throwMode; // size=0, offset=1124
	struct _Position throwTarget; // size=6, offset=1128
	struct _Instance *throwInstance; // size=664, offset=1136
	short throwXRot; // size=0, offset=1140
	short throwZRot; // size=0, offset=1142
	int throwReturnRot; // size=0, offset=1144
	struct __MessageQueue padCommands; // size=136, offset=1148
	void (*returnState)(); // size=0, offset=1284
	unsigned long passedMask; // size=0, offset=1288
	struct _G2SVector3_Type extraRot; // size=6, offset=1292
	int effectsFlags; // size=0, offset=1300
	short effectsFadeSource; // size=0, offset=1304
	short effectsFadeDest; // size=0, offset=1306
	int effectsFadeStep; // size=0, offset=1308
	int effectsFadeSteps; // size=0, offset=1312
	short autoFaceZone; // size=0, offset=1316
	short autoFaceAngle; // size=0, offset=1318
	int autoFaceLastRootAngle; // size=0, offset=1320
	int autoFaceRootAngle; // size=0, offset=1324
	int autoFaceTrueAngle; // size=0, offset=1328
	int autoFaceAnim; // size=0, offset=1332
	int autoFaceLastAnim; // size=0, offset=1336
	int nothingCounter; // size=0, offset=1340
	int timeAccumulator; // size=0, offset=1344
	struct _Position puppetMoveToPoint; // size=6, offset=1348
	struct _Position puppetRotToPoint; // size=6, offset=1354
	int soundModifier; // size=0, offset=1360
	short alarmTable; // size=0, offset=1364
	short terminator; // size=0, offset=1366
	short swimSpeedAdjustment; // size=0, offset=1368
	short swimTargetSpeed; // size=0, offset=1370
	unsigned long soundHandle; // size=0, offset=1372
	long soundTimer; // size=0, offset=1376
	long soundTotalTime; // size=0, offset=1380
	unsigned long soundDistance; // size=0, offset=1384
	short soundStartPitch; // size=0, offset=1388
	short soundEndPitch; // size=0, offset=1390
	short soundStartVolume; // size=0, offset=1392
	short soundEndVolume; // size=0, offset=1394
	unsigned long soundHandle2; // size=0, offset=1396
	long soundTimer2; // size=0, offset=1400
	long soundTotalTime2; // size=0, offset=1404
	unsigned long soundDistance2; // size=0, offset=1408
	short soundStartPitch2; // size=0, offset=1412
	short soundEndPitch2; // size=0, offset=1414
	short soundStartVolume2; // size=0, offset=1416
	short soundEndVolume2; // size=0, offset=1418
	long soundTimerNext; // size=0, offset=1420
	unsigned long soundTimerData; // size=0, offset=1424
	unsigned long forcedGlideSpeed; // size=0, offset=1428
	struct _SVector collisionEdgeOffset; // size=8, offset=1432
	struct __SAnim *currentSAnim; // size=16, offset=1440
	unsigned long playerEvent; // size=0, offset=1444
	unsigned long playerEventHistory; // size=0, offset=1448
	int currentHint; // size=0, offset=1452
};

struct __CannedSound // hashcode: 0x7A66CF99 (dec: 2053558169)
{
	short bank; // size=0, offset=0
	short sound; // size=0, offset=2
	short startPitch; // size=0, offset=4
	short endPitch; // size=0, offset=6
	short startVolume; // size=0, offset=8
	short endVolume; // size=0, offset=10
	long time; // size=0, offset=12
	long distance; // size=0, offset=16
};

struct __AlarmData // hashcode: 0x4506D6F6 (dec: 1158076150)
{
	short command; // size=0, offset=0
	short data; // size=0, offset=2
};

struct _SoundRamp // hashcode: 0xBD60B5A0 (dec: -1117735520)
{
	unsigned long soundHandle; // size=0, offset=0
	long soundTimer; // size=0, offset=4
	long soundTotalTime; // size=0, offset=8
	unsigned long soundDistance; // size=0, offset=12
	short soundStartPitch; // size=0, offset=16
	short soundEndPitch; // size=0, offset=18
	short soundStartVolume; // size=0, offset=20
	short soundEndVolume; // size=0, offset=22
};

struct PlayerSaveData // hashcode: 0xCBCB79F5 (dec: -875857419)
{
	unsigned long abilities; // size=0, offset=0
	unsigned long currentPlane; // size=0, offset=4
	unsigned long healthScale; // size=0, offset=8
	unsigned long healthBalls; // size=0, offset=12
	unsigned short manaBalls; // size=0, offset=16
	unsigned short manaMax; // size=0, offset=18
	unsigned long playerEventHistory; // size=0, offset=20
};

struct RazielData // hashcode: 0x59F1ED4D (dec: 1509027149)
{
	unsigned long version; // size=0, offset=0
	unsigned long nonBurningRibbonStartColor; // size=0, offset=4
	unsigned long nonBurningRibbonEndColor; // size=0, offset=8
	struct __Idle ***idleList; // size=4, offset=12
	struct __AttackItem ***attackList; // size=36, offset=16
	struct __ThrowItem **throwList; // size=32, offset=20
	struct __VAnim *virtualAnimations; // size=8, offset=24
	struct __VAnim *virtualAnimSingle; // size=8, offset=28
	struct __SAnim **stringAnimations; // size=16, offset=32
	short throwFadeValue; // size=0, offset=36
	short throwFadeInRate; // size=0, offset=38
	int throwFadeOutRate; // size=0, offset=40
	int throwManualDistance; // size=0, offset=44
	short healthMaterialRate; // size=0, offset=48
	short healthSpectralRate; // size=0, offset=50
	short healthInvinciblePostHit; // size=0, offset=52
	short healthInvinciblePostShunt; // size=0, offset=54
	short forceMinPitch; // size=0, offset=56
	short forceMaxPitch; // size=0, offset=58
	short forceMinVolume; // size=0, offset=60
	short forceMaxVolume; // size=0, offset=62
	unsigned long forceRampTime; // size=0, offset=64
	int SwimPhysicsFallDamping; // size=0, offset=68
	int SwimPhysicsWaterFrequency; // size=0, offset=72
	int SwimPhysicsWaterAmplitude; // size=0, offset=76
	int SwimPhysicsUnderDeceleration; // size=0, offset=80
	int SwimPhysicsUnderKickVelocity; // size=0, offset=84
	int SwimPhysicsUnderKickAccel; // size=0, offset=88
	int SwimPhysicsUnderVelocity; // size=0, offset=92
	int SwimPhysicsUnderKickDecel; // size=0, offset=96
	int SwimPhysicsUnderStealthAdjust; // size=0, offset=100
	int SwimPhysicsCoilVelocity; // size=0, offset=104
	int SwimPhysicsCoilDecelerationIn; // size=0, offset=108
	int SwimPhysicsCoilDecelerationOut; // size=0, offset=112
	int SwimPhysicsShotVelocity; // size=0, offset=116
	int SwimPhysicsShotAccelerationIn; // size=0, offset=120
	int SwimPhysicsShotAccelerationOut; // size=0, offset=124
	int SwimPhysicsSurfVelocity; // size=0, offset=128
	int SwimPhysicsSurfAccelerationIn; // size=0, offset=132
	int SwimPhysicsSurfAccelerationOut; // size=0, offset=136
	int SwimPhysicsSurfKickVelocity; // size=0, offset=140
	int SwimPhysicsSurfKickAccel; // size=0, offset=144
	int SwimPhysicsSurfMinRotation; // size=0, offset=148
	int SwimPhysicsSurfMaxRotation; // size=0, offset=152
	int SwimPhysicsSurfKickDecel; // size=0, offset=156
};

struct __razController // hashcode: 0xEA82ECBD (dec: -360518467)
{
	unsigned short segment; // size=0, offset=0
	unsigned short type; // size=0, offset=2
};

struct DR_STP // hashcode: 0x368DFF73 (dec: 915275635)
{
	unsigned long tag; // size=0, offset=0
	unsigned long code[2]; // size=8, offset=4
};

struct UNDRWRLD_114fake // hashcode: 0xE7FD0578 (dec: -402848392)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: undrwrld.o, undrwrld.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: undrwrld.o, undrwrld.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: undrwrld.o, undrwrld.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: undrwrld.o, undrwrld.o
};

struct UW_ScreenXY // hashcode: 0x0F0F4643 (dec: 252659267)
{
	short sx; // size=0, offset=0
	short sy; // size=0, offset=2
	short dx; // size=0, offset=4
	short dy; // size=0, offset=6
};

struct cinema_fn_table_t // hashcode: 0x788A7C81 (dec: 2022341761)
{
	int (*play)(); // size=0, offset=0
	char *versionID; // size=0, offset=4
};

struct CINEPSX_109fake // hashcode: 0x25D35CD7 (dec: 634608855)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: cinepsx.o, cinepsx.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: cinepsx.o, cinepsx.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: cinepsx.o, cinepsx.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: cinepsx.o, cinepsx.o
};

struct XAVoiceListEntry // hashcode: 0x59BCDF7A (dec: 1505550202)
{
	unsigned short length; // size=0, offset=0
};

struct LocalizationHeader // hashcode: 0x57A8366D (dec: 1470641773)
{
	enum language_t language; // size=4, offset=0
	int numXAfiles; // size=0, offset=4
	int XATableOffset; // size=0, offset=8
	int numStrings; // size=0, offset=12
};

struct menu_t // hashcode: 0xD6F54FB8 (dec: -688566344)
{
	int nmenus; // size=0, offset=0
	int nitems; // size=0, offset=4
	int nbytes; // size=0, offset=8
	struct menu_stack_t stack[5]; // size=180, offset=12
	struct menu_item_t items[12]; // size=192, offset=192
	char bytes[512]; // size=512, offset=384
	void (*drawfn)(); // size=0, offset=896
	void *opaque; // size=0, offset=900
};

struct MENU_109fake // hashcode: 0x5D7FAB9E (dec: 1568648094)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: menu.o, menu.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: menu.o, menu.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: menu.o, menu.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: menu.o, menu.o
};

struct menu_format_t // hashcode: 0x8BC6DE3A (dec: -1949901254)
{
	int xpos; // size=0, offset=0
	int ypos; // size=0, offset=4
	int lineskip; // size=0, offset=8
	int itemskip; // size=0, offset=12
	int width; // size=0, offset=16
	int center; // size=0, offset=20
	int border; // size=0, offset=24
};

struct menu_stack_t // hashcode: 0x21B48443 (dec: 565478467)
{
	int (*fn)(); // size=0, offset=0
	int index; // size=0, offset=4
	struct menu_format_t format; // size=28, offset=8
};

struct menu_item_t // hashcode: 0x29989F6E (dec: 697868142)
{
	char *text; // size=0, offset=0
	int (*fn)(); // size=0, offset=4
	long parameter; // size=0, offset=8
	long flags; // size=0, offset=12
};

struct Extents2d // hashcode: 0xDAD8D47E (dec: -623324034)
{
	int xmin; // size=0, offset=0
	int xmax; // size=0, offset=4
	int ymin; // size=0, offset=8
	int ymax; // size=0, offset=12
};

struct MENUUTIL_109fake // hashcode: 0xC7E72EBB (dec: -941150533)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: menuutil.o, menuutil.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: menuutil.o, menuutil.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: menuutil.o, menuutil.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: menuutil.o, menuutil.o
};

struct menu_sound_entry_t // hashcode: 0xC45DB178 (dec: -1000492680)
{
	enum menu_sound_t sound; // size=4, offset=0
	int sfx; // size=0, offset=4
};

struct MENUDEFS_109fake // hashcode: 0x88179D20 (dec: -2011718368)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: menudefs.o, menudefs.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: menudefs.o, menudefs.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: menudefs.o, menudefs.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: menudefs.o, menudefs.o
};

struct SavedInfoTracker // hashcode: 0x976D60AF (dec: -1754439505)
{
	char *MemoryCardBuffer; // size=0, offset=0
	char *InfoStart; // size=0, offset=4
	char *InfoEnd; // size=0, offset=8
	char *EndOfMemory; // size=0, offset=12
};

struct SavedLevel // hashcode: 0x2A96B47A (dec: 714519674)
{
	unsigned char savedID; // size=0, offset=0
	unsigned char shiftedSaveSize; // size=0, offset=1
	short areaID; // size=0, offset=2
	short waterZ; // size=0, offset=4
	short numberBSPTreesSaved; // size=0, offset=6
};

struct ActualSavedLevel // hashcode: 0x0AA7BA88 (dec: 178764424)
{
	unsigned char savedID; // size=0, offset=0
	unsigned char shiftedSaveSize; // size=0, offset=1
	short areaID; // size=0, offset=2
	short waterZ; // size=0, offset=4
	short numberBSPTreesSaved; // size=0, offset=6
	struct SavedBspTree bspTreeArray[1]; // size=8, offset=8
};

struct SavedDeadDeadBits // hashcode: 0xED4F62E0 (dec: -313564448)
{
	unsigned char savedID; // size=0, offset=0
	unsigned char shiftedSaveSize; // size=0, offset=1
	char deadDeadBits[832]; // size=832, offset=2
};

struct _GlobalSaveTracker // hashcode: 0x5CB03AB7 (dec: 1555053239)
{
	short savedID; // size=0, offset=0
	short saveSize; // size=0, offset=2
	short flags; // size=0, offset=4
	short saveVersion; // size=0, offset=6
	unsigned long currentTime; // size=0, offset=8
	short humanOpinionOfRaziel; // size=0, offset=12
	char numRegens; // size=0, offset=14
	struct _MONAPI_Regenerator regenEntries[10]; // size=80, offset=16
	struct gSoundData sound; // size=20, offset=96
	short sizeUsedInBlock; // size=0, offset=116
	short CurrentBirthID; // size=0, offset=118
};

struct CdlFILTER // hashcode: 0x4EE0EF08 (dec: 1323364104)
{
	unsigned char file; // size=0, offset=0
	unsigned char chan; // size=0, offset=1
	unsigned short pad; // size=0, offset=2
};

struct SpuCommonAttr // hashcode: 0xDDA59288 (dec: -576351608)
{
	unsigned long mask; // size=0, offset=0
	struct SpuVolume mvol; // size=4, offset=4
	struct SpuVolume mvolmode; // size=4, offset=8
	struct SpuVolume mvolx; // size=4, offset=12
	struct SpuExtAttr cd; // size=12, offset=16
	struct SpuExtAttr ext; // size=12, offset=28
};

struct VOICEXA_169fake // hashcode: 0x0FA4A0E7 (dec: 262447335)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: voicexa.o, voicexa.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: voicexa.o, voicexa.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: voicexa.o, voicexa.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: voicexa.o, voicexa.o
};

struct XAVoiceTracker // hashcode: 0x4B01AB69 (dec: 1258400617)
{
	struct CdlLOC currentPos; // size=4, offset=0
	int currentSector; // size=0, offset=4
	int endSector; // size=0, offset=8
	void (*prevCallback)(); // size=0, offset=12
	unsigned char cdResult[8]; // size=8, offset=16
	struct CdCommand cdCmdQueue[8]; // size=64, offset=24
	unsigned short requestQueue[4]; // size=8, offset=88
	struct VoiceCommand voiceCmdQueue[16]; // size=64, offset=96
	unsigned char cdCmdIn; // size=0, offset=160
	unsigned char cdCmdOut; // size=0, offset=161
	unsigned char cdCmdsQueued; // size=0, offset=162
	unsigned char reqIn; // size=0, offset=163
	unsigned char reqOut; // size=0, offset=164
	unsigned char reqsQueued; // size=0, offset=165
	unsigned char voiceCmdIn; // size=0, offset=166
	unsigned char voiceCmdOut; // size=0, offset=167
	unsigned char voiceCmdsQueued; // size=0, offset=168
	unsigned char unused1; // size=0, offset=169
	unsigned char voiceStatus; // size=0, offset=170
	unsigned char cdStatus; // size=0, offset=171
	short fileNum; // size=0, offset=172
	short unused2; // size=0, offset=174
	struct XAFileInfo xaFileInfo[30]; // size=120, offset=176
};

struct MENUFACE_109fake // hashcode: 0x6856F9CD (dec: 1750530509)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: menuface.o, menuface.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: menuface.o, menuface.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: menuface.o, menuface.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: menuface.o, menuface.o
};

struct menuface_t // hashcode: 0x747C4D13 (dec: 1954303251)
{
	short x; // size=0, offset=0
	short y; // size=0, offset=2
	char w; // size=0, offset=4
	char h; // size=0, offset=5
	char frames; // size=0, offset=6
	char curFrame; // size=0, offset=7
	char transitionDir; // size=0, offset=8
	unsigned char delay; // size=0, offset=9
	unsigned char loaded; // size=0, offset=10
	char pad; // size=0, offset=11
};

struct mcpsx_t // hashcode: 0x439C11F6 (dec: 1134301686)
{
	struct {
		enum mcpsx_mode_t mode; // size=4, offset=0
		enum mcpsx_func_t func; // size=4, offset=4
		enum mcpsx_sync_t sync; // size=4, offset=8
		enum mcpsx_err_t err; // size=4, offset=12
		int observed; // size=0, offset=16
	} state; // size=20, offset=0, found in object files: memcard.o, memcard.o
	struct {
		long channel; // size=0, offset=0
		char *filename; // size=0, offset=4
		void *buffer; // size=0, offset=8
		long offset; // size=0, offset=12
		long nbytes; // size=0, offset=16
		long nblocks; // size=0, offset=20
		struct mcpsx_directory_t *directory; // size=24, offset=24
		long *nfilesptr; // size=0, offset=28
	} params; // size=32, offset=20, found in object files: memcard.o, memcard.o
	void *opaque; // size=0, offset=52
};

struct mcpsx_directory_t // hashcode: 0x6E4A1DFB (dec: 1850351099)
{
	char name[20]; // size=20, offset=0
	int nbytes; // size=0, offset=20
};

struct mcard_t // hashcode: 0xDC887748 (dec: -595036344)
{
	struct {
		enum mcpsx_err_t err; // size=4, offset=0
		enum state_t fsm; // size=4, offset=4
		enum mcard_status_t status; // size=4, offset=8
		int not_exists; // size=0, offset=12
	} state; // size=16, offset=0, found in object files: memcard.o, memcard.o
	struct {
		long parameter; // size=0, offset=0
		long *nfilesptr; // size=0, offset=4
		struct mcpsx_directory_t *directory; // size=24, offset=8
		char *filename; // size=0, offset=12
		void *buffer; // size=0, offset=16
		int nbytes; // size=0, offset=20
		int nblocks; // size=0, offset=24
	} params; // size=28, offset=16, found in object files: memcard.o, memcard.o
	struct mcpsx_t *mcpsx; // size=56, offset=44
	void *opaque; // size=0, offset=48
};

struct mcmenu_t // hashcode: 0x33A96220 (dec: 866738720)
{
	struct {
		enum fsm_t fsm; // size=4, offset=0
		enum fsm_t fsm_prev; // size=4, offset=4
		enum mcard_status_t status; // size=4, offset=8
		int running; // size=0, offset=12
		int slot; // size=0, offset=16
	} state; // size=20, offset=0, found in object files: memcard.o, memcard.o
	struct {
		int nblocks; // size=0, offset=0
		int nbytes; // size=0, offset=4
		void *buffer; // size=0, offset=8
		struct mcpsx_directory_t directory[15]; // size=360, offset=12
		long nfiles; // size=0, offset=372
	} params; // size=376, offset=20, found in object files: memcard.o, memcard.o
	struct mcard_t *mcard; // size=52, offset=396
	void *opaque; // size=0, offset=400
};

struct mcmenu_table_t // hashcode: 0x13150B73 (dec: 320146291)
{
	int (*data_size)(); // size=0, offset=0
	void (*initialize)(); // size=0, offset=4
	void (*terminate)(); // size=0, offset=8
	void (*begin)(); // size=0, offset=12
	void (*end)(); // size=0, offset=16
	int (*set_buffer)(); // size=0, offset=20
	int (*main)(); // size=0, offset=24
	int (*pause)(); // size=0, offset=28
	char *versionID; // size=0, offset=32
};

struct MEMCARD_117fake // hashcode: 0x12F3FE32 (dec: 317980210)
{
	struct {
		struct MultiSpline *posSpline; // size=0, offset=0
		struct MultiSpline *targetSpline; // size=0, offset=4
		struct _SVector lastSplinePos; // size=8, offset=8
		short splinePointAhead; // size=0, offset=16
		short cinema_done; // size=0, offset=18
		int splinecam_currkey; // size=0, offset=20
		int splinecam_helpkey; // size=0, offset=24
	} Cinematic; // size=28, offset=0, found in object files: memcard.o, memcard.o
	struct {
		struct _Position offset; // size=6, offset=0
		struct _Rotation rotation; // size=8, offset=6
		long focusDistance; // size=0, offset=16
	} Idle; // size=20, offset=28, found in object files: memcard.o, memcard.o
	struct {
		struct _TFace *tface; // size=12, offset=0
		struct _TFace *oldTFace; // size=12, offset=4
		struct _SVector oldTargetRot; // size=8, offset=8
		long timer; // size=0, offset=16
		struct _SVector oldFocusInstancePos; // size=8, offset=20
	} Behind; // size=28, offset=48, found in object files: memcard.o, memcard.o
	struct {
		long stopTimer; // size=0, offset=0
		long stopHit; // size=0, offset=4
		struct _TFace *tface; // size=12, offset=8
		struct _TFace *oldTFace; // size=12, offset=12
		long hit; // size=0, offset=16
	} Follow; // size=20, offset=76, found in object files: memcard.o, memcard.o
};

struct memcard_t // hashcode: 0x818A1A39 (dec: -2121655751)
{
	struct Object *object; // size=76, offset=0
	struct mcmenu_table_t *table; // size=36, offset=4
	struct mcmenu_t *mcmenu; // size=404, offset=8
	short running; // size=0, offset=12
	short wrongVerison; // size=0, offset=14
};

struct MEMCARD_211fake // hashcode: 0xBCEEF4B0 (dec: -1125190480)
{
	struct mcmenu_t dummy1; // size=404, offset=0
	struct mcard_t dummy2; // size=52, offset=404
	struct mcpsx_t dummy3; // size=56, offset=456
};
/* End structs */

/* Begin unions */

union PLAYER_76fake // Hashcode: 0x35EA4737 (dec: 904546103)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: player.o, player.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: player.o, player.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: player.o, player.o
};

union PLAYER_77fake // Hashcode: 0xBB3AB3AC (dec: -1153780820)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union PLAYER_203fake // Hashcode: 0xD17F7AC6 (dec: -780174650)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union DEBUG_117fake // Hashcode: 0x8FDB6CEB (dec: -1881445141)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: debug.o, debug.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: debug.o, debug.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: debug.o, debug.o
};

union DEBUG_118fake // Hashcode: 0x9FC77C2D (dec: -1614316499)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union DEBUG_219fake // Hashcode: 0x34481CBB (dec: 877141179)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union DEBUG_255fake // Hashcode: 0xF8D3063B (dec: -120388037)
{
	struct Intro *intro; // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

union DRAW_71fake // Hashcode: 0xCB8F2557 (dec: -879811241)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: draw.o, draw.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: draw.o, draw.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: draw.o, draw.o
};

union DRAW_72fake // Hashcode: 0xC5F4FD70 (dec: -973800080)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union DRAW_207fake // Hashcode: 0x73CDE2F1 (dec: 1942872817)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union FONT_76fake // Hashcode: 0x437DBE1C (dec: 1132314140)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: font.o, font.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: font.o, font.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: font.o, font.o
};

union FONT_77fake // Hashcode: 0x41C6BBBD (dec: 1103543229)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union FONT_208fake // Hashcode: 0xF48145CB (dec: -192854581)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union GAMEPAD_76fake // Hashcode: 0xD0BD8DB9 (dec: -792883783)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: gamepad.o, gamepad.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: gamepad.o, gamepad.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: gamepad.o, gamepad.o
};

union GAMEPAD_77fake // Hashcode: 0x98D30877 (dec: -1731000201)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union GAMEPAD_194fake // Hashcode: 0x580DA0F4 (dec: 1477288180)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union INSTANCE_76fake // Hashcode: 0xD107B689 (dec: -788023671)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: instance.o, instance.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: instance.o, instance.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: instance.o, instance.o
};

union INSTANCE_77fake // Hashcode: 0xFD9D30CA (dec: -40030006)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union INSTANCE_200fake // Hashcode: 0x7AC29D26 (dec: 2059574566)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union INSTANCE_265fake // Hashcode: 0xF7C09306 (dec: -138374394)
{
	struct Intro *intro; // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

union CAMERA_71fake // Hashcode: 0xE21A8E88 (dec: -501576056)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: camera.o, camera.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: camera.o, camera.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: camera.o, camera.o
};

union CAMERA_72fake // Hashcode: 0xFAC61D0E (dec: -87679730)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union CAMERA_200fake // Hashcode: 0x0030A4BF (dec: 3187903)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union LIGHT3D_71fake // Hashcode: 0xD87B7ACC (dec: -662996276)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: light3d.o, light3d.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: light3d.o, light3d.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: light3d.o, light3d.o
};

union LIGHT3D_72fake // Hashcode: 0xDA6329A5 (dec: -631035483)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union LIGHT3D_204fake // Hashcode: 0x5C281C1C (dec: 1546132508)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union LOAD3D_76fake // Hashcode: 0x57B5CC77 (dec: 1471532151)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: load3d.o, load3d.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: load3d.o, load3d.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: load3d.o, load3d.o
};

union LOAD3D_77fake // Hashcode: 0xC3F8B662 (dec: -1007110558)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MAIN_76fake // Hashcode: 0x1BF568CD (dec: 469067981)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: main.o, main.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: main.o, main.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: main.o, main.o
};

union MAIN_77fake // Hashcode: 0xD53C177F (dec: -717482113)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MAIN_208fake // Hashcode: 0x9EDD1752 (dec: -1629677742)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union MAIN_238fake // Hashcode: 0x04937F30 (dec: 76775216)
{
	unsigned short pad; // size=0, offset=0
	unsigned short multitap[16]; // size=32, offset=0
	unsigned short mouse[2]; // size=4, offset=0
	unsigned short negcon[3]; // size=6, offset=0
	struct AnalogueData analogue; // size=6, offset=0
};

union GAMELOOP_76fake // Hashcode: 0x0A1D5C09 (dec: 169696265)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: gameloop.o, gameloop.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: gameloop.o, gameloop.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: gameloop.o, gameloop.o
};

union GAMELOOP_77fake // Hashcode: 0xF9E4B09E (dec: -102453090)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union GAMELOOP_187fake // Hashcode: 0x10E97F95 (dec: 283738005)
{
	struct Intro *intro; // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

union GAMELOOP_231fake // Hashcode: 0x20DD8088 (dec: 551387272)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union SIGNAL_71fake // Hashcode: 0x9F61980E (dec: -1620994034)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: signal.o, signal.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: signal.o, signal.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: signal.o, signal.o
};

union SIGNAL_72fake // Hashcode: 0x338DBC7B (dec: 864926843)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union SIGNAL_200fake // Hashcode: 0x3880D70E (dec: 947967758)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union COLLIDE_76fake // Hashcode: 0x002C2863 (dec: 2893923)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: collide.o, collide.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: collide.o, collide.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: collide.o, collide.o
};

union COLLIDE_77fake // Hashcode: 0xB047A37C (dec: -1337482372)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union COLLIDE_214fake // Hashcode: 0x2948D328 (dec: 692638504)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union COLLIDE_241fake // Hashcode: 0x5247E607 (dec: 1380443655)
{
	struct Intro *intro; // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

union TABLES_71fake // Hashcode: 0xA6898F50 (dec: -1500934320)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: tables.o, tables.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: tables.o, tables.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: tables.o, tables.o
};

union TABLES_72fake // Hashcode: 0xD97A777C (dec: -646285444)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union VM_71fake // Hashcode: 0x16A0D850 (dec: 379639888)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: vm.o, vm.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: vm.o, vm.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: vm.o, vm.o
};

union VM_72fake // Hashcode: 0x36AD9EA6 (dec: 917348006)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union VM_194fake // Hashcode: 0x2872D23F (dec: 678613567)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union MATH3D_76fake // Hashcode: 0x24E11B2B (dec: 618732331)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: math3d.o, math3d.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: math3d.o, math3d.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: math3d.o, math3d.o
};

union MATH3D_77fake // Hashcode: 0xA7F8464B (dec: -1476901301)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union PIPE3D_71fake // Hashcode: 0x0E8B451A (dec: 244008218)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: pipe3d.o, pipe3d.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: pipe3d.o, pipe3d.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: pipe3d.o, pipe3d.o
};

union PIPE3D_72fake // Hashcode: 0x4398960A (dec: 1134073354)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union PIPE3D_195fake // Hashcode: 0xE288BAF0 (dec: -494355728)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union SCRIPT_76fake // Hashcode: 0x29949EC3 (dec: 697605827)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: script.o, script.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: script.o, script.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: script.o, script.o
};

union SCRIPT_77fake // Hashcode: 0xFA1FDBDC (dec: -98575396)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union SCRIPT_196fake // Hashcode: 0xA4B68EB7 (dec: -1531539785)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union TIMER_71fake // Hashcode: 0xE149738D (dec: -515279987)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: timer.o, timer.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: timer.o, timer.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: timer.o, timer.o
};

union TIMER_72fake // Hashcode: 0xC10FCF1A (dec: -1055928550)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union BSP_71fake // Hashcode: 0xE095D78C (dec: -527050868)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: bsp.o, bsp.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: bsp.o, bsp.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: bsp.o, bsp.o
};

union BSP_72fake // Hashcode: 0xEA3310F9 (dec: -365752071)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union BSP_204fake // Hashcode: 0xD663D9EA (dec: -698099222)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union OBTABLE_76fake // Hashcode: 0xEF276AB0 (dec: -282629456)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: obtable.o, obtable.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: obtable.o, obtable.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: obtable.o, obtable.o
};

union OBTABLE_77fake // Hashcode: 0xF86BA2DA (dec: -127163686)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union OBTABLE_191fake // Hashcode: 0x176DC2D3 (dec: 393069267)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union OBTABLE2_76fake // Hashcode: 0xD26DD707 (dec: -764553465)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: obtable2.o, obtable2.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: obtable2.o, obtable2.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: obtable2.o, obtable2.o
};

union OBTABLE2_77fake // Hashcode: 0x0279D52B (dec: 41538859)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union OBTABLE2_204fake // Hashcode: 0x4504A907 (dec: 1157933319)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union GENERIC_76fake // Hashcode: 0xD3D6CEF0 (dec: -740897040)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: generic.o, generic.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: generic.o, generic.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: generic.o, generic.o
};

union GENERIC_77fake // Hashcode: 0x223DADFF (dec: 574467583)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union GENERIC_196fake // Hashcode: 0xDCE8D0BC (dec: -588721988)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union SOUND_76fake // Hashcode: 0xE29068DE (dec: -493852450)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: sound.o, sound.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: sound.o, sound.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: sound.o, sound.o
};

union SOUND_77fake // Hashcode: 0xA246A4AA (dec: -1572428630)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union SOUND_199fake // Hashcode: 0xDFDA0FF7 (dec: -539357193)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union SPLINE_71fake // Hashcode: 0xF82DB594 (dec: -131222124)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: spline.o, spline.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: spline.o, spline.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: spline.o, spline.o
};

union SPLINE_72fake // Hashcode: 0x0E8A2D70 (dec: 243936624)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union FX_71fake // Hashcode: 0x405FB133 (dec: 1080013107)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: fx.o, fx.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: fx.o, fx.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: fx.o, fx.o
};

union FX_72fake // Hashcode: 0xCBBB5AFB (dec: -876913925)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union FX_200fake // Hashcode: 0x0A4F1DCD (dec: 172957133)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union MEMPACK_71fake // Hashcode: 0xA3DA3C1A (dec: -1545978854)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: mempack.o, mempack.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: mempack.o, mempack.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: mempack.o, mempack.o
};

union MEMPACK_72fake // Hashcode: 0xC58A436B (dec: -980794517)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MEMPACK_183fake // Hashcode: 0xE01EE4E6 (dec: -534846234)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union MEMPACK_239fake // Hashcode: 0x5C027ADF (dec: 1543666399)
{
	struct Intro *intro; // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

union GXASSERT_76fake // Hashcode: 0xCEC89670 (dec: -825715088)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: gxassert.o, gxassert.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: gxassert.o, gxassert.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: gxassert.o, gxassert.o
};

union GXASSERT_77fake // Hashcode: 0x151F5D82 (dec: 354377090)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union AADASSRT_117fake // Hashcode: 0x2609FF4E (dec: 638189390)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: aadassrt.o, aadassrt.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: aadassrt.o, aadassrt.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: aadassrt.o, aadassrt.o
};

union AADASSRT_118fake // Hashcode: 0xA111B324 (dec: -1592675548)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union AADLIB_114fake // Hashcode: 0x040DBAB5 (dec: 68008629)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: aadlib.o, aadlib.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: aadlib.o, aadlib.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: aadlib.o, aadlib.o
};

union AADLIB_115fake // Hashcode: 0xAF321E85 (dec: -1355669883)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union AADLIB_185fake // Hashcode: 0x174B93D7 (dec: 390829015)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union STREAM_76fake // Hashcode: 0xBF63C681 (dec: -1083980159)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: stream.o, stream.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: stream.o, stream.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: stream.o, stream.o
};

union STREAM_77fake // Hashcode: 0x60D533B3 (dec: 1624585139)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union STREAM_205fake // Hashcode: 0x52E2CF92 (dec: 1390595986)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union STREAM_256fake // Hashcode: 0x98F29EDE (dec: -1728930082)
{
	struct Intro *intro; // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

union PHYSOBS_71fake // Hashcode: 0x08084D10 (dec: 134761744)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: PhysObs.o, PhysObs.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: PhysObs.o, PhysObs.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: PhysObs.o, PhysObs.o
};

union PHYSOBS_72fake // Hashcode: 0x80B804C9 (dec: -2135423799)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union SCRIPT2_71fake // Hashcode: 0xA85C31A4 (dec: -1470352988)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: script2.o, script2.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: script2.o, script2.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: script2.o, script2.o
};

union SCRIPT2_72fake // Hashcode: 0x81F9B940 (dec: -2114340544)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union SCRIPT2_198fake // Hashcode: 0x2360918D (dec: 593531277)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union EVENT_76fake // Hashcode: 0x758FC869 (dec: 1972357225)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: event.o, event.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: event.o, event.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: event.o, event.o
};

union EVENT_77fake // Hashcode: 0x761A5212 (dec: 1981436434)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union EVENT_213fake // Hashcode: 0xA01E8D12 (dec: -1608610542)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union STRMLOAD_76fake // Hashcode: 0x3E20E8B6 (dec: 1042344118)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: strmload.o, strmload.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: strmload.o, strmload.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: strmload.o, strmload.o
};

union STRMLOAD_77fake // Hashcode: 0x2458C570 (dec: 609797488)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union PHYSICS_71fake // Hashcode: 0xF46D7093 (dec: -194154349)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: physics.o, physics.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: physics.o, physics.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: physics.o, physics.o
};

union PHYSICS_72fake // Hashcode: 0x467E1F5A (dec: 1182670682)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union PHYSICS_198fake // Hashcode: 0x4E411290 (dec: 1312887440)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union REAVER_76fake // Hashcode: 0xD49683F7 (dec: -728333321)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: reaver.o, reaver.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: reaver.o, reaver.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: reaver.o, reaver.o
};

union REAVER_77fake // Hashcode: 0x7003C6FE (dec: 1879295742)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union REAVER_209fake // Hashcode: 0x1BCC68A0 (dec: 466380960)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union HUNTER_76fake // Hashcode: 0x55755889 (dec: 1433753737)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: hunter.o, hunter.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: hunter.o, hunter.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: hunter.o, hunter.o
};

union HUNTER_77fake // Hashcode: 0x7DD42307 (dec: 2111054599)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union HUNTER_188fake // Hashcode: 0xCAD1A6D9 (dec: -892229927)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union MISSILE_76fake // Hashcode: 0xCA3EAB64 (dec: -901862556)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: missile.o, missile.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: missile.o, missile.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: missile.o, missile.o
};

union MISSILE_77fake // Hashcode: 0xEB0ED212 (dec: -351350254)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MISSILE_191fake // Hashcode: 0xB9D15879 (dec: -1177462663)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union MONAPI_76fake // Hashcode: 0xC0E76B03 (dec: -1058575613)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: monapi.o, monapi.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: monapi.o, monapi.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: monapi.o, monapi.o
};

union MONAPI_77fake // Hashcode: 0x88C9805B (dec: -2000060325)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MONAPI_196fake // Hashcode: 0x080A899C (dec: 134908316)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union RAZCNTRL_71fake // Hashcode: 0xD922792C (dec: -652052180)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: razcntrl.o, razcntrl.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: razcntrl.o, razcntrl.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: razcntrl.o, razcntrl.o
};

union RAZCNTRL_72fake // Hashcode: 0x691BBC51 (dec: 1763425361)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union STATE_71fake // Hashcode: 0x6A2E7759 (dec: 1781430105)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: state.o, state.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: state.o, state.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: state.o, state.o
};

union STATE_72fake // Hashcode: 0x34A2E4FC (dec: 883090684)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union VRAM_76fake // Hashcode: 0xC9CD2FC8 (dec: -909299768)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: vram.o, vram.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: vram.o, vram.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: vram.o, vram.o
};

union VRAM_77fake // Hashcode: 0xD9EF5FC5 (dec: -638623803)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union VRAM_205fake // Hashcode: 0x34E0E051 (dec: 887152721)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union GLYPH_76fake // Hashcode: 0xC6ED8007 (dec: -957513721)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: glyph.o, glyph.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: glyph.o, glyph.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: glyph.o, glyph.o
};

union GLYPH_77fake // Hashcode: 0x8768FC78 (dec: -2023162760)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union GLYPH_209fake // Hashcode: 0x362EEEBA (dec: 909045434)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union HUMAN_76fake // Hashcode: 0xBE51ECF8 (dec: -1101927176)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: human.o, human.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: human.o, human.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: human.o, human.o
};

union HUMAN_77fake // Hashcode: 0x26E3C7DE (dec: 652462046)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union HUMAN_188fake // Hashcode: 0x38475FF8 (dec: 944201720)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union MONMSG_76fake // Hashcode: 0x00A45121 (dec: 10768673)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: monmsg.o, monmsg.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: monmsg.o, monmsg.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: monmsg.o, monmsg.o
};

union MONMSG_77fake // Hashcode: 0x97BD3215 (dec: -1749208555)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MONMSG_191fake // Hashcode: 0xAF98D580 (dec: -1348938368)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union MONSENSE_76fake // Hashcode: 0xE39EF92E (dec: -476120786)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: monsense.o, monsense.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: monsense.o, monsense.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: monsense.o, monsense.o
};

union MONSENSE_77fake // Hashcode: 0x9DA55BB1 (dec: -1650107471)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MONSENSE_191fake // Hashcode: 0x2DBBA69C (dec: 767272604)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union MONSTER_76fake // Hashcode: 0xB86A05B3 (dec: -1201011277)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: monster.o, monster.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: monster.o, monster.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: monster.o, monster.o
};

union MONSTER_77fake // Hashcode: 0xD6D0D774 (dec: -690956428)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MONSTER_208fake // Hashcode: 0xF98F7226 (dec: -108039642)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union MONLIB_76fake // Hashcode: 0xB892514A (dec: -1198370486)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: monlib.o, monlib.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: monlib.o, monlib.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: monlib.o, monlib.o
};

union MONLIB_77fake // Hashcode: 0xBE5ABAAD (dec: -1101350227)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MONLIB_202fake // Hashcode: 0xCBF5D75B (dec: -873080997)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union VWRAITH_76fake // Hashcode: 0xEFE90EB5 (dec: -269939019)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: vwraith.o, vwraith.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: vwraith.o, vwraith.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: vwraith.o, vwraith.o
};

union VWRAITH_77fake // Hashcode: 0x4E0523C5 (dec: 1308959685)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union VWRAITH_188fake // Hashcode: 0xEFE9F5D3 (dec: -269879853)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union SKINNER_76fake // Hashcode: 0x6EBE70FD (dec: 1857974525)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: skinner.o, skinner.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: skinner.o, skinner.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: skinner.o, skinner.o
};

union SKINNER_77fake // Hashcode: 0xCC387448 (dec: -868715448)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union SKINNER_208fake // Hashcode: 0x49C4E21E (dec: 1237639710)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union SLUAGH_76fake // Hashcode: 0x6107358D (dec: 1627862413)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: sluagh.o, sluagh.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: sluagh.o, sluagh.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: sluagh.o, sluagh.o
};

union SLUAGH_77fake // Hashcode: 0xCC767117 (dec: -864653033)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union SLUAGH_188fake // Hashcode: 0x1482A725 (dec: 344106789)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union SOUL_76fake // Hashcode: 0xDCA1648B (dec: -593402741)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: soul.o, soul.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: soul.o, soul.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: soul.o, soul.o
};

union SOUL_77fake // Hashcode: 0xFBE7C1C7 (dec: -68697657)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union SOUL_188fake // Hashcode: 0xBE4DF780 (dec: -1102186624)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union MONTABLE_71fake // Hashcode: 0x68B06C49 (dec: 1756392521)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: montable.o, montable.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: montable.o, montable.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: montable.o, montable.o
};

union MONTABLE_72fake // Hashcode: 0x025D1F15 (dec: 39657237)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MONTABLE_183fake // Hashcode: 0xAC387AA3 (dec: -1405584733)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union MORLOCK_76fake // Hashcode: 0x71C6C229 (dec: 1908851241)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: morlock.o, morlock.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: morlock.o, morlock.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: morlock.o, morlock.o
};

union MORLOCK_77fake // Hashcode: 0xEA4FEF4B (dec: -363860149)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MORLOCK_188fake // Hashcode: 0xE7E3581A (dec: -404531174)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union INSTNCG2_23fake // Hashcode: 0xB8E10A8F (dec: -1193211249)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: InstncG2.o, InstncG2.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: InstncG2.o, InstncG2.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: InstncG2.o, InstncG2.o
};

union INSTNCG2_72fake // Hashcode: 0x7A9509BE (dec: 2056587710)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MAING2_71fake // Hashcode: 0xE7F90A35 (dec: -403109323)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: MainG2.o, MainG2.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: MainG2.o, MainG2.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: MainG2.o, MainG2.o
};

union MAING2_72fake // Hashcode: 0x0103104A (dec: 16977994)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MATRIXG2_71fake // Hashcode: 0xF22258C6 (dec: -232630074)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: MatrixG2.o, MatrixG2.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: MatrixG2.o, MatrixG2.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: MatrixG2.o, MatrixG2.o
};

union MATRIXG2_72fake // Hashcode: 0xD9CB7EF6 (dec: -640975114)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MATRIXG2_195fake // Hashcode: 0xD0DBC9EB (dec: -790902293)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union QUATG2_71fake // Hashcode: 0xA360506F (dec: -1553969041)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: QuatG2.o, QuatG2.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: QuatG2.o, QuatG2.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: QuatG2.o, QuatG2.o
};

union QUATG2_72fake // Hashcode: 0xA575B6A7 (dec: -1519012185)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union TIMERG2_71fake // Hashcode: 0x776F5EAA (dec: 2003787434)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: TimerG2.o, TimerG2.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: TimerG2.o, TimerG2.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: TimerG2.o, TimerG2.o
};

union TIMERG2_72fake // Hashcode: 0xFC120985 (dec: -65926779)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union WORSHIP_76fake // Hashcode: 0xF27C5FD9 (dec: -226730023)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: worship.o, worship.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: worship.o, worship.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: worship.o, worship.o
};

union WORSHIP_77fake // Hashcode: 0x462A0122 (dec: 1177157922)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union WORSHIP_188fake // Hashcode: 0x18E92E88 (dec: 417934984)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union MBMISS_76fake // Hashcode: 0x53946B95 (dec: 1402235797)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: mbmiss.o, mbmiss.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: mbmiss.o, mbmiss.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: mbmiss.o, mbmiss.o
};

union MBMISS_77fake // Hashcode: 0xCA2D3391 (dec: -903007343)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MBMISS_208fake // Hashcode: 0xFD5BE4B0 (dec: -44309328)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union ANIMG2_72fake // Hashcode: 0x7B7C592B (dec: 2071746859)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union ANIMG2_195fake // Hashcode: 0xEA8F6845 (dec: -359700411)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union QUATVM_71fake // Hashcode: 0x17262097 (dec: 388374679)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: QuatVM.o, QuatVM.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: QuatVM.o, QuatVM.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: QuatVM.o, QuatVM.o
};

union QUATVM_72fake // Hashcode: 0x34C261C9 (dec: 885154249)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union ENMYPLAN_76fake // Hashcode: 0xE9A668C7 (dec: -374970169)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: enmyplan.o, enmyplan.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: enmyplan.o, enmyplan.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: enmyplan.o, enmyplan.o
};

union ENMYPLAN_77fake // Hashcode: 0x551D4A3C (dec: 1427982908)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union ENMYPLAN_211fake // Hashcode: 0xE417BCB1 (dec: -468206415)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union PLAN_76fake // Hashcode: 0xCE9883AB (dec: -828865621)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: plan.o, plan.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: plan.o, plan.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: plan.o, plan.o
};

union PLAN_77fake // Hashcode: 0x0C4334C0 (dec: 205731008)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union PLAN_211fake // Hashcode: 0x82DB1A5B (dec: -2099570085)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union PLANAPI_112fake // Hashcode: 0xD2907F83 (dec: -762282109)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: planapi.o, planapi.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: planapi.o, planapi.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: planapi.o, planapi.o
};

union PLANAPI_113fake // Hashcode: 0x86893426 (dec: -2037828570)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union PLANAPI_206fake // Hashcode: 0xB39046FE (dec: -1282390274)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union PLANCOLL_76fake // Hashcode: 0xAB708E3C (dec: -1418686916)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: plancoll.o, plancoll.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: plancoll.o, plancoll.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: plancoll.o, plancoll.o
};

union PLANCOLL_77fake // Hashcode: 0x78B21617 (dec: 2024936983)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union PLANCOLL_211fake // Hashcode: 0xD5325C83 (dec: -718119805)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union PLANDRAW_76fake // Hashcode: 0xD7D91343 (dec: -673639613)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: plandraw.o, plandraw.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: plandraw.o, plandraw.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: plandraw.o, plandraw.o
};

union PLANDRAW_77fake // Hashcode: 0x85A25521 (dec: -2052958943)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union PLANDRAW_205fake // Hashcode: 0x2338D5AB (dec: 590927275)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union PLANOPT_112fake // Hashcode: 0x17562226 (dec: 391520806)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: planopt.o, planopt.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: planopt.o, planopt.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: planopt.o, planopt.o
};

union PLANOPT_113fake // Hashcode: 0x9BEF6ACB (dec: -1678808373)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union PLANOPT_206fake // Hashcode: 0xA4C98B93 (dec: -1530295405)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union PLANPOOL_112fake // Hashcode: 0x8C0850F0 (dec: -1945612048)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: planpool.o, planpool.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: planpool.o, planpool.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: planpool.o, planpool.o
};

union PLANPOOL_113fake // Hashcode: 0x5D8C523A (dec: 1569477178)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union PLANPOOL_206fake // Hashcode: 0x72218182 (dec: 1914798466)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union PLANSRCH_112fake // Hashcode: 0x085DA94F (dec: 140355919)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: plansrch.o, plansrch.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: plansrch.o, plansrch.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: plansrch.o, plansrch.o
};

union PLANSRCH_113fake // Hashcode: 0xCF677740 (dec: -815302848)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union PLANSRCH_206fake // Hashcode: 0x9F895A4A (dec: -1618388406)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union CONTROL_71fake // Hashcode: 0xBAC0CC97 (dec: -1161769833)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: control.o, control.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: control.o, control.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: control.o, control.o
};

union CONTROL_72fake // Hashcode: 0x8151FBD6 (dec: -2125333546)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union CONTROL_198fake // Hashcode: 0xD0561BFB (dec: -799663109)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union RAZIEL_71fake // Hashcode: 0xF5DC7DCF (dec: -170099249)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: raziel.o, raziel.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: raziel.o, raziel.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: raziel.o, raziel.o
};

union RAZIEL_72fake // Hashcode: 0x146DD7CF (dec: 342742991)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union RAZIEL_198fake // Hashcode: 0x028E261B (dec: 42870299)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union RAZIEL_252fake // Hashcode: 0x5E06F769 (dec: 1577514857)
{
	struct Intro *intro; // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

union UNDRWRLD_76fake // Hashcode: 0xF6DD58D9 (dec: -153265959)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: undrwrld.o, undrwrld.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: undrwrld.o, undrwrld.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: undrwrld.o, undrwrld.o
};

union UNDRWRLD_77fake // Hashcode: 0x946A3881 (dec: -1804978047)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union UNDRWRLD_190fake // Hashcode: 0x731C1FA8 (dec: 1931222952)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union CINEPSX_71fake // Hashcode: 0x5AF21F11 (dec: 1525817105)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: cinepsx.o, cinepsx.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: cinepsx.o, cinepsx.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: cinepsx.o, cinepsx.o
};

union CINEPSX_72fake // Hashcode: 0x96706202 (dec: -1771019774)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union CINEPSX_183fake // Hashcode: 0x346C0127 (dec: 879493415)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union CINEPSX_206fake // Hashcode: 0x5F57E47D (dec: 1599595645)
{
	unsigned short pad; // size=0, offset=0
	unsigned short multitap[16]; // size=32, offset=0
	unsigned short mouse[2]; // size=4, offset=0
	unsigned short negcon[3]; // size=6, offset=0
	struct AnalogueData analogue; // size=6, offset=0
};

union MENU_71fake // Hashcode: 0x58F056C0 (dec: 1492145856)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: menu.o, menu.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: menu.o, menu.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: menu.o, menu.o
};

union MENU_72fake // Hashcode: 0x59F6497E (dec: 1509312894)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MENUUTIL_71fake // Hashcode: 0x693A731F (dec: 1765438239)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: menuutil.o, menuutil.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: menuutil.o, menuutil.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: menuutil.o, menuutil.o
};

union MENUUTIL_72fake // Hashcode: 0x30B19C0F (dec: 816946191)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MENUDEFS_71fake // Hashcode: 0xDAEFD513 (dec: -621816557)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: menudefs.o, menudefs.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: menudefs.o, menudefs.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: menudefs.o, menudefs.o
};

union MENUDEFS_72fake // Hashcode: 0x5108CB0D (dec: 1359530765)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union SAVEINFO_76fake // Hashcode: 0x23A2E82A (dec: 597878826)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: saveinfo.o, saveinfo.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: saveinfo.o, saveinfo.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: saveinfo.o, saveinfo.o
};

union SAVEINFO_77fake // Hashcode: 0x09F94700 (dec: 167331584)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union SAVEINFO_191fake // Hashcode: 0x175CF64C (dec: 391968332)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

union SAVEINFO_218fake // Hashcode: 0xC5BA13DF (dec: -977660961)
{
	struct Intro *intro; // size=76, offset=0
	struct _SFXMkr *sfxMarker; // size=36, offset=0
};

union VOICEXA_85fake // Hashcode: 0x54044FF2 (dec: 1409568754)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: voicexa.o, voicexa.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: voicexa.o, voicexa.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: voicexa.o, voicexa.o
};

union VOICEXA_86fake // Hashcode: 0x49A14AA8 (dec: 1235307176)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MENUFACE_71fake // Hashcode: 0x57020DEF (dec: 1459752431)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: menuface.o, menuface.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: menuface.o, menuface.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: menuface.o, menuface.o
};

union MENUFACE_72fake // Hashcode: 0xE5B1B023 (dec: -441339869)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MEMCARD_79fake // Hashcode: 0x8C9E31C4 (dec: -1935789628)
{
	struct {
		unsigned long (*function)(); // size=0, offset=0
		void *fnData; // size=0, offset=4
	} callback; // size=8, offset=0, found in object files: memcard.o, memcard.o
	struct {
		struct _G2SVector3_Type base; // size=6, offset=0
		struct _G2SVector3_Type offset; // size=6, offset=6
	} vector; // size=12, offset=0, found in object files: memcard.o, memcard.o
	struct {
		struct _G2Quat_Type src; // size=8, offset=0
		struct _G2Quat_Type dest; // size=8, offset=8
	} quat; // size=16, offset=0, found in object files: memcard.o, memcard.o
};

union MEMCARD_80fake // Hashcode: 0xD46E70DB (dec: -730959653)
{
	long color; // size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MEMCARD_191fake // Hashcode: 0x28D76F3F (dec: 685207359)
{
	struct _Instance *target; // size=664, offset=0
	struct _Position position; // size=6, offset=0
	struct _Rotation direction; // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};
/* End unions */

/* Begin typedefs */

typedef struct MATRIX MATRIX;

typedef struct VECTOR VECTOR;

typedef struct SVECTOR SVECTOR;

typedef struct CVECTOR CVECTOR;

typedef struct DVECTOR DVECTOR;

typedef struct RVECTOR RVECTOR;

typedef struct CRVECTOR3 CRVECTOR3;

typedef struct CRVECTOR4 CRVECTOR4;

typedef struct RECT RECT;

typedef struct DR_ENV DR_ENV;

typedef struct P_TAG P_TAG;

typedef struct CdlLOC CdlLOC;

typedef struct LightInstance LightInstance;

typedef struct _GameTrackerASMData_Type GameTrackerASMData;

typedef struct _GameData_Type GameData;

typedef struct NodeType NodeType;

typedef struct TextureFT3 TextureFT3;

typedef struct TextureMT3 TextureMT3;

typedef struct AniTexInfo AniTexInfo;

typedef struct AniTex AniTex;

typedef struct DrMoveAniTexSrcInfo DrMoveAniTexSrcInfo;

typedef struct DrMoveAniTexDestInfo DrMoveAniTexDestInfo;

typedef struct DrMoveAniTex DrMoveAniTex;

typedef struct MemHeader MemHeader;

typedef enum _G2Bool_Enum G2Bool;

typedef struct _G2SVector3_Type G2SVector3;

typedef struct _G2LVector3_Type G2LVector3;

typedef struct _G2Matrix_Type G2Matrix;

typedef struct _G2Quat_Type G2Quat;

typedef struct _G2AnimQuatInfo_Type G2AnimQuatInfo;

typedef struct _G2AnimAlphaTable_Type G2AnimAlphaTable;

typedef struct _G2AnimInterpStateBlock_Type G2AnimInterpStateBlock;

typedef struct _G2AnimInterpInfo_Type G2AnimInterpInfo;

typedef struct _G2AnimChanStatus_Type G2AnimChanStatus;

typedef struct _G2AnimChanStatusBlock_Type G2AnimChanStatusBlock;

typedef struct _G2AnimFxHeader_Type G2AnimFxHeader;

typedef struct _G2AnimKeylist_Type G2AnimKeylist;

typedef struct _G2AnimSection_Type G2AnimSection;

typedef struct _G2Anim_Type G2Anim;

typedef struct _SVector SVector;

typedef struct _SVectorNoPad SVectorNoPad;

typedef struct MATRIX Transform;

typedef struct _Position Position;

typedef struct _Rotation Rotation;

typedef struct _Normal Normal;

typedef struct _PlaneConstants PlaneConstants;

typedef struct _Vertex Vertex;

typedef struct _Face Face;

typedef struct _MVertex MVertex;

typedef struct _MFace MFace;

typedef struct _RGBAColor RGBAColor;

typedef struct _PVertex PVertex;

typedef struct _VertexPool VertexPool;

typedef struct _PrimPool PrimPool;

typedef struct _Sphere Sphere;

typedef struct _Sphere_noSq Sphere_noSq;

typedef struct _CameraKey CameraKey;

typedef struct Object Object;

typedef struct _BVertex BVertex;

typedef struct _BFace BFace;

typedef struct _BGObject BGObject;

typedef struct Signal Signal;

typedef struct _MultiSignal MultiSignal;

typedef struct _HFace HFace;

typedef struct _HSphere HSphere;

typedef struct _HBox HBox;

typedef struct _HPrim HPrim;

typedef struct _HModel HModel;

typedef struct _HInfo HInfo;

typedef struct _Segment Segment;

typedef struct MultiSpline MultiSpline;

typedef struct _Model Model;

typedef struct SoundInstance SoundInstance;

typedef struct ObjectEffect ObjectEffect;

typedef struct ObjectEffect AnimEffectData;

typedef struct VramSize VramSize;

typedef struct _TFace TFace;

typedef struct _TVertex TVertex;

typedef struct EventAliasCommandStruct EventAliasCommandStruct;

typedef struct _Instance Instance;

typedef struct _InstancePool InstancePool;

typedef struct _InstanceList InstanceList;

typedef struct _ObjectTracker ObjectTracker;

typedef struct Intro Intro;

typedef struct _BoundingBox BoundingBox;

typedef struct CDLight CDLight;

typedef struct _BSPNode BSPNode;

typedef struct _BSPNode SBSPNode;

typedef struct _BSPLeaf BSPLeaf;

typedef struct _MorphVertex MorphVertex;

typedef struct _MorphColor MorphColor;

typedef struct _SavedCinematic SavedCinematic;

typedef struct BSPTree BSPTree;

typedef struct _Terrain Terrain;

typedef struct LightGroup LightGroup;

typedef struct LightList LightList;

typedef struct PointLight PointLight;

typedef struct SpotLight SpotLight;

typedef struct LightInfo LightInfo;

typedef struct _VMOffset VMMoveOffset;

typedef struct _VMColorOffset VMColorOffset;

typedef struct _VMInterpolated VMInterpolated;

typedef struct _VMOffsetTable VMOffsetTable;

typedef struct _VMObject VMObject;

typedef struct _VGroup VGroup;

typedef struct _HotSpot HotSpot;

typedef struct _PlanMkr PlanMkr;

typedef struct _SFXMkr SFXMkr;

typedef struct TClassAttr TClassAttr;

typedef struct Level Level;

typedef struct _ColorType ColorType;

typedef struct _CameraCore_Type CameraCore;

typedef struct SpuVolume SpuVolume;

typedef struct SpuExtAttr SpuExtAttr;

typedef struct SpuStVoiceAttr SpuStVoiceAttr;

typedef struct AadSoundBankHdr AadSoundBankHdr;

typedef struct AadProgramAtr AadProgramAtr;

typedef struct AadToneAtr AadToneAtr;

typedef struct _AadDynSfxFileHdr AadDynSfxSnfFileHdr;

typedef struct AadDynSfxAttr AadDynSfxAttr;

typedef struct AadTempoCounter AadTempoCounter;

typedef struct AadSeqEvent AadSeqEvent;

typedef struct _AadSequenceSlot AadSequenceSlot;

typedef struct AadSfxCommand AadSfxCommand;

typedef struct AadSfxSlot AadSfxSlot;

typedef struct AadSynthVoice AadSynthVoice;

typedef struct AadDynamicLoadRequest AadDynamicLoadRequest;

typedef struct AadDynamicBankLoadInfo AadDynamicBankLoadInfo;

typedef struct AadDynamicSfxLoadInfo AadDynamicSfxLoadInfo;

typedef struct AadNewSramBlockDesc AadNewSramBlockDesc;

typedef struct AadLoadedSfxToneAttr AadLoadedSfxToneAttr;

typedef struct AadLoadedSfxWaveAttr AadLoadedSfxWaveAttr;

typedef struct AadSramDefragInfo AadSramDefragInfo;

typedef struct AadVolFader AadVolFader;

typedef struct gSoundData gSoundData;

typedef struct GameTracker GameTracker;

typedef struct Spline Spline;

typedef struct vecS vecS;

typedef struct vecL vecL;

typedef struct SplineRotKey SplineRotKey;

typedef struct RSpline RSpline;

typedef struct SplineKey SplineKey;

typedef struct SplineDef SplineDef;

typedef struct _HVertex HVertex;

typedef struct _MONAPI_Regenerator MONAPI_Regenerator;

typedef enum DEBUG_LINE_TYPE DEBUG_LINE_TYPE;

typedef struct __Event Message;

typedef struct __MessageQueue MessageQueue;

typedef struct __State State;

typedef unsigned char u_char;

typedef unsigned short u_short;

typedef unsigned int u_int;

typedef unsigned long u_long;

typedef unsigned short ushort;

typedef struct _physadr *physadr;

typedef long daddr_t;

typedef char *caddr_t;

typedef long *qaddr_t;

typedef unsigned long ino_t;

typedef long swblk_t;

typedef unsigned int size_t;

typedef long time_t;

typedef short dev_t;

typedef long off_t;

typedef unsigned short uid_t;

typedef unsigned short gid_t;

typedef unsigned long wchar_t;

typedef void (*CdlCB)();

typedef void *va_list;

typedef unsigned char uchar;

typedef unsigned char u_byte;

typedef unsigned char ubyte;

typedef unsigned long ulong;

typedef char int8;

typedef short int16;

typedef long int32;

typedef long int64;

typedef unsigned char uint8;

typedef unsigned short uint16;

typedef unsigned long uint32;

typedef unsigned long uint64;

typedef char BYTE;

typedef unsigned char UBYTE;

typedef unsigned long ULONG;

typedef unsigned short USHORT;

typedef unsigned long bool;

typedef long ListOrderFunc();

typedef unsigned long *OTag;

typedef unsigned char G2UInt8;

typedef unsigned short G2UInt16;

typedef unsigned long G2UInt32;

typedef char G2Int8;

typedef short G2Int16;

typedef long G2Int32;

typedef long G2fp4dot12;

typedef long G2fp8dot24;

typedef short G2TimerAtomicUnit;

typedef int G2AnimKeyframeNumber;

typedef int G2AnimKeylistID;

typedef int G2AnimSectionID;

typedef unsigned char G2AnimSegmentID;

typedef unsigned char G2AnimControllerType;

typedef unsigned short G2AnimChanMask;

typedef long (*G2AnimCallback)();

typedef unsigned long (*G2AnimControllerFn)();

typedef short G2AnimChanKeyData;

typedef short G2AnimChanFinalValue;

typedef enum _G2Bool_Enum (*G2InstanceRebuildCallback)();

typedef long lfixed;

typedef short sfixed;

typedef short MatEntry;

typedef short Fraction;

typedef long VectorCoord;

typedef short SVectorCoord;

typedef short NormalCoord;

typedef short TrigVal;

typedef short Angle;

typedef short Matrix[3][3];

typedef void InitFunc();

typedef void ProcessFunc();

typedef void CollideFunc();

typedef unsigned long QueryFunc();

typedef void MessageFunc();

typedef void RelocateTuneFunc();

typedef void (*SpuIRQCallbackProc)();

typedef void (*SpuTransferCallbackProc)();

typedef void (*SpuStCallbackProc)();

typedef int AADRESULT;

typedef int AadFileHandle;

typedef unsigned long AadChannelList;

typedef void (*AadFadeCompleteCallbackProc)();

typedef void (*AadLockVoiceCallbackProc)();

typedef void (*AadController11CallbackProc)();

typedef void (*AadEndSequenceCallbackProc)();

typedef void (*AadLoadDynamicSoundBankReturnProc)();

typedef void (*AadLoadDynamicSfxReturnProc)();

typedef void (**AadMemoryMallocProc)();

typedef void (*AadMemoryFreeProc)();

typedef void (*AadNonBlockLoadReturnProc)();

typedef void (*AadNonBlockLoadProc)();

typedef void (*AadNonBlockBufferedLoadReturnProc)();

typedef void (*AadNonBlockBufferedLoadProc)();

typedef unsigned char AadNewSramBlockHandle;

typedef unsigned long AadSfxHandle;

typedef unsigned int AadSfxToneID;

typedef void (*EndSequenceCallbackProc)();

typedef void (*Controller11CallbackProc)();

typedef unsigned long *DrawNonAnimatedSegmentFunc();

typedef unsigned long *DrawAnimatedModelFunc();

typedef unsigned long *DrawDisplayPolytopeListFunc();

typedef unsigned long *AdditionalDrawFunc();

typedef void BG_DisplayFunc();

typedef void RelocateInstObFunc();

typedef void (*VoidProc)();

typedef void (*StateHandler)();

typedef struct POLY_F4 POLY_F4;

typedef struct _SmallRotation SmallRotation;

typedef struct Camera Camera;

typedef struct DebugMenuLine DebugMenuLine;

typedef struct _ButtonTexture ButtonTexture;

typedef struct FontChar FontChar;

typedef struct _BigFileEntry BigFileEntry;

typedef struct _BigFileDirEntry BigFileDirEntry;

typedef struct _BigFileDir BigFileDir;

typedef struct _BigFile BigFile;

typedef struct _NonBlockLoadEntry NonBlockLoadEntry;

typedef struct _ReadQueueEntry ReadQueueEntry;

typedef struct _FX_MATRIX FX_MATRIX;

typedef struct _FX_PRIM FX_PRIM;

typedef struct BASIC_LINE_G2 BASIC_LINE_G2;

typedef struct _BASIC_G4 BASIC_G4;

typedef struct _BASIC_F4 BASIC_F4;

typedef struct __BubbleParams BubbleParams;

typedef struct _GenericParticleParams GenericParticleParams;

typedef struct _GenericRibbonParams GenericRibbonParams;

typedef struct _GenericGlowParams GenericGlowParams;

typedef struct _GenericLightningParams GenericLightningParams;

typedef struct _GenericBlastringParams GenericBlastringParams;

typedef struct _GenericFlashParams GenericFlashParams;

typedef struct _StreamUnit StreamUnit;

typedef struct XAFileInfo XAFileInfo;

typedef struct CdCommand CdCommand;

typedef struct VoiceCommand VoiceCommand;

typedef struct _LoadQueueEntry LoadQueueEntry;

typedef struct _BlockVramEntry BlockVramEntry;

typedef struct SavedBasic SavedBasic;

typedef struct _SavedIntro SavedIntro;

typedef struct SavedEvent SavedEvent;

typedef struct SavedBspTree SavedBspTree;

typedef struct EventBasicObject EventBasicObject;

typedef struct EventWildCardObject EventWildCardObject;

typedef struct ScriptPCode ScriptPCode;

typedef struct Event Event;

typedef struct EventPointers EventPointers;

typedef struct InstanceSpline InstanceSpline;

typedef struct Vector3d Vector3d;

typedef struct Rotation3d Rotation3d;

typedef struct InstanceObject InstanceObject;

typedef struct EventObject EventObject;

typedef struct SavedEventObject SavedEventObject;

typedef struct GameObject GameObject;

typedef struct SignalObject SignalObject;

typedef struct IntroObject IntroObject;

typedef struct InstanceAnimate InstanceAnimate;

typedef struct InstanceAnimateTexture InstanceAnimateTexture;

typedef struct ListObject ListObject;

typedef struct SubListObject SubListObject;

typedef struct TGroupObject TGroupObject;

typedef struct ConstrictInfo ConstrictInfo;

typedef struct CameraObject CameraObject;

typedef struct EventVmObject EventVmObject;

typedef struct AreaObject AreaObject;

typedef struct SoundObject SoundObject;

typedef struct StackType StackType;

typedef struct __ReaverSaveDat ReaverSaveData;

typedef enum option_ctrl_t option_ctrl_t;

typedef struct debug_dispatch_t debug_dispatch_t;

typedef struct debug_format_t debug_format_t;

typedef void FX_PRIM_MODIFY_PROCESS();

typedef void FX_PROCESS();

typedef void FX_PARTICLE_PROCESS();

typedef void FX_GENERAL_PROCESS();

typedef void FX_SETUP();

typedef long TFract;

typedef void (*LoadReturnProc)();

typedef void (*BufferedLoadReturnProc)();

typedef void option_fn_t();

typedef int menu_fn_t();

typedef void debug_dispatch_fn_t();

typedef struct POLY_GT3 POLY_GT3;

typedef struct POLY_GT4 POLY_GT4;

typedef struct _Vector Vector;

typedef struct _PFace PFace;

typedef struct _PolytopeList PolytopeList;

typedef struct UVTYPE UVTYPE;

typedef struct POLY_G3_SEMITRANS POLY_G3_SEMITRANS;

typedef struct _POLY_NG4 POLY_NG4;

typedef struct _GT3ZVertexD3D_Type GT3ZVertexD3D;

typedef struct SP_SUBDIV_STRUCT SP_SUBDIV_STRUCT;

typedef void BSPLeafFunc();

typedef void G2AppData;

typedef struct POLY_FT4 POLY_FT4;

typedef struct FontTracker FontTracker;

typedef struct font_color_t font_color_t;

typedef struct FontPos FontPos;

typedef struct JoypadMappingStruct JoypadMapping;

typedef struct AnalogueData AnalogueData;

typedef struct ControllerPacket ControllerPacket;

typedef struct _G2EulerAngles_Type G2EulerAngles;

typedef enum _G2AnimCallbackMsg_Enum G2AnimCallbackMsg;

typedef struct _InstanceHandle InstanceHandle;

typedef struct evCollideInstanceStatsData evCollideInstanceStatsData;

typedef struct INICommand INICommand;

typedef struct PhysObProperties PhysObProperties;

typedef struct PhysObSplinter PhysObSplinter;

typedef struct PhysObWeaponAttributes PhysObWeaponAttributes;

typedef struct __PhysObProjectileData PhysObProjData;

typedef struct SwitchData SwitchData;

typedef struct LightTableEntry LightTableEntry;

typedef struct _PhysObLight PhysObLight;

typedef struct SavedIntroSmall SavedIntroSmall;

typedef struct SavedIntroSpline SavedIntroSpline;

typedef struct _SavedIntroWithIntro SavedIntroWithIntro;

typedef struct _PCollideInfo PCollideInfo;

typedef struct CameraCollisionInfo CameraCollisionInfo;

typedef struct _LCollideInfo LCollideInfo;

typedef long LightFunc();

typedef struct CdlFILE CdlFILE;

typedef struct _LoadStatus LoadStatus;

typedef struct RedirectList RedirectList;

typedef struct DRAWENV DRAWENV;

typedef struct DISPENV DISPENV;

typedef struct BLK_FILL BLK_FILL;

typedef struct MainTracker MainTracker;

typedef struct POLY_F4_SEMITRANS POLY_F4_SEMITRANS;

typedef struct InterfaceItem InterfaceItem;

typedef struct _FXTracker FXTracker;

typedef struct StreamUnitPortal StreamUnitPortal;

typedef void GlyphProcessFunction();

typedef struct SignalInfo SignalInfo;

typedef void SignalGlobalValueFunc();

typedef long HandleSignalFunc();

typedef long SignalHandleFunc();

typedef void RelocateSignalFunc();

typedef struct _Triangle2D Triangle2D;

typedef struct _HNormal HNormal;

typedef struct _HFaceInfo HFaceInfo;

typedef struct _CollideInfo CollideInfo;

typedef struct SCollideInfo SCollideInfo;

typedef long CollideBoundFunc();

typedef struct POLY_FT3 POLY_FT3;

typedef struct _Mirror Mirror;

typedef struct _FXHalvePlane FXHalvePlane;

typedef struct _FXGlowEffect FXGlowEffect;

typedef struct TransformAnimatedInstanceVerticesWork_t TransformAnimatedInstanceVerticesWork_t;

typedef struct GenericTune GenericTune;

typedef struct FXSplinter FXSplinter;

typedef struct _SBSPLeaf SBSPLeaf;

typedef void asm_fn();

typedef long hook_fn_1();

typedef long hook_fn_2();

typedef long hook_fn_3();

typedef long hook_fn_4();

typedef long hook_fn_5();

typedef long hook_fn_6();

typedef long hook_fn_7();

typedef long hook_fn_8();

typedef struct _ObjectOwnerInfo ObjectOwnerInfo;

typedef struct ObjectAccess ObjectAccess;

typedef struct ObjectFunc ObjectFunc;

typedef struct evAnimationInstanceSwitchData evAnimationInstanceSwitchData;

typedef struct evControlSaveDataData evControlSaveDataData;

typedef struct AadInitAttr AadInitAttr;

typedef struct ObjectPeriodicSound ObjectPeriodicSound;

typedef struct ObjectEventSound ObjectEventSound;

typedef struct ObjectOneShotSound ObjectOneShotSound;

typedef struct SoundEffectChannel SoundEffectChannel;

typedef struct DR_TPAGE DR_TPAGE;

typedef struct _POLY_SG4 POLY_SG4;

typedef struct _FXGeneralEffect FXGeneralEffect;

typedef struct _FXRibbon FXRibbon;

typedef struct _FXParticle FXParticle;

typedef struct _FXLightBeam FXLightBeam;

typedef struct _FXBlastringEffect FXBlastringEffect;

typedef struct _FXForceFieldEffect FXForceFieldEffect;

typedef struct _FXLightning FXLightning;

typedef struct _FXFlash FXFlash;

typedef struct GenericFXObject GenericFXObject;

typedef struct evObjectDraftData evObjectDraftData;

typedef struct _GlyphTuneData GlyphTuneData;

typedef struct __ReaverData ReaverData;

typedef struct __ReaverTuneData ReaverTuneData;

typedef struct _POLY_TF4 POLY_TF4;

typedef struct _POLY_2G4 POLY_2G4;

typedef struct _POLY_2G4T POLY_2G4T;

typedef struct AadVolume AadVolume;

typedef struct NewMemTracker NewMemTracker;

typedef struct AadSequenceHdr AadSequenceHdr;

typedef struct AadMemoryStruct AadMemoryStruct;

typedef struct AadTempo AadTempo;

typedef struct AadSlotAttributes AadSlotAttributes;

typedef struct SpuVoiceAttr SpuVoiceAttr;

typedef struct POLY_G4 POLY_G4;

typedef struct DR_AREA DR_AREA;

typedef struct evPositionData evPositionData;

typedef struct STracker STracker;

typedef struct FaceExtents FaceExtents;

typedef struct WarpRoom WarpRoom;

typedef struct PlanningNode PlanningNode;

typedef struct VramBuffer VramBuffer;

typedef struct evObjectData evObjectData;

typedef struct evPhysicsGravityData evPhysicsGravityData;

typedef struct evPhysicsSlideData evPhysicsSlideData;

typedef struct evObjectThrowData evObjectThrowData;

typedef struct evObjectBirthProjectileData evObjectBirthProjectileData;

typedef struct PhysObWeaponProperties PhysObWeaponProperties;

typedef struct PhysObInteractProperties PhysObInteractProperties;

typedef struct __PhysObProjectileProperties PhysObProjectileProperties;

typedef struct PhysObDraftProperties PhysObDraftProperties;

typedef struct PhysObSwitchProperties PhysObSwitchProperties;

typedef struct PhysObCollectibleProperties PhysObCollectibleProperties;

typedef struct PhysObAnimatedProperties PhysObAnimatedProperties;

typedef struct PhysObData PhysObData;

typedef struct BreakOffData BreakOffData;

typedef struct ProjectileData ProjectileData;

typedef struct _PhysObSaveData PhysObSaveData;

typedef struct LitShaftProperties LitShaftProperties;

typedef struct SavedEventSmallVars SavedEventSmallVars;

typedef struct WaterLevelProcess WaterLevelProcess;

typedef struct EventInstanceObject EventInstanceObject;

typedef struct EventEventObject EventEventObject;

typedef struct EventTGroupObject EventTGroupObject;

typedef struct _PCodeStack PCodeStack;

typedef struct EventTimer EventTimer;

typedef struct SignalResetStruct SignalResetStruct;

typedef struct HintSystemStruct HintSystemStruct;

typedef struct evPhysicsDropOffData evPhysicsDropOffData;

typedef struct evPhysicsEdgeData evPhysicsEdgeData;

typedef struct evPhysicsWallCrawlData evPhysicsWallCrawlData;

typedef struct evPhysicsSwimData evPhysicsSwimData;

typedef struct evPhysicsDropHeightData evPhysicsDropHeightData;

typedef struct evPhysicsLinkedMoveData evPhysicsLinkedMoveData;

typedef struct _MonsterAnim MonsterAnim;

typedef struct _MonsterIdle MonsterIdle;

typedef struct _MonsterBehavior MonsterBehavior;

typedef struct _MonsterSenses MonsterSenses;

typedef struct _MonsterAllegiances MonsterAllegiances;

typedef struct _MonsterAttackAttributes MonsterAttackAttributes;

typedef struct _MonsterMissile MonsterMissile;

typedef struct _MonsterCombatAttributes MonsterCombatAttributes;

typedef struct _MonsterSubAttributes MonsterSubAttributes;

typedef struct _MonsterAttributes MonsterAttributes;

typedef struct _MonsterVars MonsterVars;

typedef struct _MonsterIR MonsterIR;

typedef struct burntTuneType burntTuneType;

typedef struct _MonsterState MonsterState;

typedef struct _MonsterStateChoice MonsterStateChoice;

typedef struct _MonsterFunctionTable MonsterFunctionTable;

typedef struct _HunterVars HunterVars;

typedef struct _HunterAttributes HunterAttributes;

typedef void (*processVert_t)();

typedef void (*MonsterFunc)();

typedef void (*MonsterDamageFunc)();

typedef struct MissileGraphics MissileGraphics;

typedef struct evMonsterHitTerrainData evMonsterHitTerrainData;

typedef struct evMonsterHitObjectData evMonsterHitObjectData;

typedef struct evShadowSegmentData evShadowSegmentData;

typedef struct _MonsterSaveInfo MonsterSaveInfo;

typedef struct __CharacterState CharacterState;

typedef struct evMonsterHitData evMonsterHitData;

typedef struct evMonsterThrownData evMonsterThrownData;

typedef struct evMonsterAlarmData evMonsterAlarmData;

typedef struct evMonsterSoulSuckData evMonsterSoulSuckData;

typedef struct evFXHitData evFXHitData;

typedef struct evAnimationControllerDoneData evAnimationControllerDoneData;

typedef struct evMonsterImpaleData evMonsterImpaleData;

typedef struct evObjectBreakOffData evObjectBreakOffData;

typedef struct evObjectAbsorbData evObjectAbsorbData;

typedef struct evObjectIdleData evObjectIdleData;

typedef struct evControlInitHangData evControlInitHangData;

typedef struct evControlInitIdleData evControlInitIdleData;

typedef struct evActionLookAroundData evActionLookAroundData;

typedef struct evActionPlayHostAnimationData evActionPlayHostAnimationData;

typedef struct __GlyphData GlyphData;

typedef struct evPhysicsLOSData evPhysicsLOSData;

typedef struct RadarInfo RadarInfo;

typedef struct burntMessType burntMessType;

typedef struct bloodyMessType bloodyMessType;

typedef struct _G2PoolMemPool_Type G2PoolMemPool;

typedef void G2PoolMem;

typedef struct _G2AppDataVM_Type G2AppDataVM;

typedef struct _walbossAttributes WalbossAttributes;

typedef struct _G2AnimController_Type G2AnimController;

typedef struct _G2AnimSegKeyflagInfo_Type G2AnimSegKeyflagInfo;

typedef struct _G2AnimDecompressChannelInfo_Type G2AnimDecompressChannelInfo;

typedef struct _G2AnimSegValue_Type G2AnimSegValue;

typedef struct _G2AnimChanStatusBlockPool_Type G2AnimChanStatusBlockPool;

typedef struct _G2AnimControllerPool_Type G2AnimControllerPool;

typedef struct _G2AnimInterpStateBlockPool_Type G2AnimInterpStateBlockPool;

typedef void (*G2AnimApplyControllerFn)();

typedef struct EnemyPlanData EnemyPlanData;

typedef struct EnemyPlanSlotData EnemyPlanSlotData;

typedef struct _PlanCollideInfo PlanCollideInfo;

typedef struct PoolManagementData PoolManagementData;

typedef struct _fth FindTerrainHit;

typedef struct __Force Force;

typedef struct __Idle Idle;

typedef struct __VAnim VAnim;

typedef struct __SAnim SAnim;

typedef struct __AttackItem AttackItem;

typedef struct __ThrowItem ThrowItem;

typedef struct __EngagedInstance EngagedInstance;

typedef struct __FitPoint FitPoint;

typedef struct __SensoryData SensoryData;

typedef struct __Player Player;

typedef struct __CannedSound CannedSound;

typedef struct __AlarmData AlarmData;

typedef struct _SoundRamp SoundRamp;

typedef struct PlayerSaveData PlayerSaveData;

typedef struct RazielData RazielData;

typedef struct __razController razController;

typedef struct DR_STP DR_STP;

typedef struct UW_ScreenXY UW_ScreenXY;

typedef struct cinema_fn_table_t cinema_fn_table_t;

typedef int PlayCinematic_t();

typedef enum language_t language_t;

typedef enum localstr_t localstr_t;

typedef struct XAVoiceListEntry XAVoiceListEntry;

typedef struct LocalizationHeader LocalizationHeader;

typedef enum menu_ctrl_t menu_ctrl_t;

typedef enum menu_sound_t menu_sound_t;

typedef struct menu_t menu_t;

typedef struct menu_format_t menu_format_t;

typedef struct menu_stack_t menu_stack_t;

typedef struct menu_item_t menu_item_t;

typedef struct Extents2d Extents2d;

typedef int menu_item_fn_t();

typedef void menu_draw_fn_t();

typedef struct menu_sound_entry_t menu_sound_entry_t;

typedef enum sfx_t sfx_t;

typedef struct SavedInfoTracker SavedInfoTracker;

typedef struct SavedLevel SavedLevel;

typedef struct ActualSavedLevel ActualSavedLevel;

typedef struct SavedDeadDeadBits SavedDeadDeadBits;

typedef struct _GlobalSaveTracker GlobalSaveTracker;

typedef struct CdlFILTER CdlFILTER;

typedef struct SpuCommonAttr SpuCommonAttr;

typedef struct XAVoiceTracker XAVoiceTracker;

typedef void (*VoiceCmdProc)();

typedef struct menuface_t menuface_t;

typedef struct mcpsx_t mcpsx_t;

typedef struct mcpsx_directory_t mcpsx_directory_t;

typedef enum mcpsx_err_t mcpsx_err_t;

typedef enum mcpsx_func_t mcpsx_func_t;

typedef enum mcpsx_sync_t mcpsx_sync_t;

typedef enum mcpsx_mode_t mcpsx_mode_t;

typedef struct mcard_t mcard_t;

typedef enum state_t fsmcard_t;

typedef enum mcard_status_t mcard_status_t;

typedef enum fsm_t fsm_t;

typedef struct mcmenu_t mcmenu_t;

typedef struct mcmenu_table_t mcmenu_table_t;

typedef struct memcard_t memcard_t;

typedef int mcard_filename_fn_t();

/* Begin typedefs which were autogenerated by TDR */

typedef int (*TDRFuncPtr_memcard_item1fn)();

typedef int (*TDRFuncPtr_menu_item_flags1fn)();

typedef int (*TDRFuncPtr_menu_item1fn)();

typedef int (*TDRFuncPtr_menu_push1fn)();

typedef int (*TDRFuncPtr_menu_set1fn)();

typedef long (*TDRFuncPtr_aadInstallUpdateFunc0updateFuncPtr)();

typedef long (*TDRFuncPtr_COLLIDE_LineWithBoxFace6collideBoundFunc)();

typedef long (*TDRFuncPtr_G2Anim_SetCallback1callback)();

typedef void (*TDRFuncPtr__FX_Build5fxSetup)();

typedef void (*TDRFuncPtr__FX_Build6fxProcess)();

typedef void (*TDRFuncPtr__FX_BuildNonSegmentedSplinters6fxSetup)();

typedef void (*TDRFuncPtr__FX_BuildNonSegmentedSplinters7fxProcess)();

typedef void (*TDRFuncPtr__FX_BuildSegmentedSplinters6fxSetup)();

typedef void (*TDRFuncPtr__FX_BuildSegmentedSplinters7fxProcess)();

typedef void (*TDRFuncPtr__FX_BuildSingleFaceWithModel6fxSetup)();

typedef void (*TDRFuncPtr__FX_BuildSingleFaceWithModel7fxProcess)();

typedef void (*TDRFuncPtr__FX_BuildSplinters6fxSetup)();

typedef void (*TDRFuncPtr__FX_BuildSplinters7fxProcess)();

typedef void (*TDRFuncPtr__GlyphSwitchProcess1process)();

typedef void (*TDRFuncPtr_aadInstallEndSequenceCallback)();

typedef void (*TDRFuncPtr_aadInstallEndSequenceCallback0callbackProc)();

typedef void (*TDRFuncPtr_aadLoadDynamicSoundBank4retProc)();

typedef void (*TDRFuncPtr_aadStartMasterVolumeFade2fadeCompleteCallback)();

typedef void (*TDRFuncPtr_aadStartMusicMasterVolFade2fadeCompleteCallback)();

typedef void (*TDRFuncPtr_FX_Build5fxSetup)();

typedef void (*TDRFuncPtr_FX_Build6fxProcess)();

typedef void (*TDRFuncPtr_FX_BuildSingleFaceWithModel6fxSetup)();

typedef void (*TDRFuncPtr_FX_BuildSingleFaceWithModel7fxProcess)();

typedef void (*TDRFuncPtr_FX_SimpleQuadSetup1fxProcess)();

typedef void (*TDRFuncPtr_MONSTER_ProcessClosestVerts2processVert_cb)();

typedef void (*TDRFuncPtr_MONTABLE_GetCleanUpFunc)();

typedef void (*TDRFuncPtr_MONTABLE_GetDamageEffectFunc)();

typedef void (*TDRFuncPtr_MONTABLE_GetInitFunc)();

typedef void (*TDRFuncPtr_StateSwitchStateCharacterData1NewProcess)();

typedef void (*TDRFuncPtr_StateSwitchStateCharacterDataDefault1NewProcess)();

typedef void (*TDRFuncPtr_StateSwitchStateData2NewProcess)();

typedef void (*TDRFuncPtr_StateSwitchStateDataDefault2NewProcess)();

/* End typedefs which were autogenerated by TDR */

/* End typedefs */

/* Begin external declarations */

extern struct DebugMenuLine mainMenu[8]; // offset 0x800C73FC


extern struct DebugMenuLine standardMenu[12]; // offset 0x800C670C


extern struct DebugMenuLine pauseMenu[7]; // offset 0x800C8B6C


extern struct DebugMenuLine goodiesMenu[17]; // offset 0x800C6A3C


extern struct DebugMenuLine debugImbueSoulReaverMenu[7]; // offset 0x800C6FAC


extern struct DebugMenuLine debugGlyphAbilitiesMenu[11]; // offset 0x800C6EA4


extern struct DebugMenuLine debugForgedAbilitiesMenu[7]; // offset 0x800C6DFC


extern struct DebugMenuLine debugSpecialAbilitiesMenu[10]; // offset 0x800C6D0C


extern struct DebugMenuLine debugHealthSystemMenu[5]; // offset 0x800C6C94


extern struct DebugMenuLine debugRazielMenu[8]; // offset 0x800C6BD4


extern struct DebugMenuLine level2SelectMenu[14]; // offset 0x800C86BC


extern struct DebugMenuLine levelSelectMenu[15]; // offset 0x800C880C


extern struct DebugMenuLine eventMenu[10]; // offset 0x800C688C


extern struct DebugMenuLine BossAreasMenu[9]; // offset 0x800C8434


extern struct DebugMenuLine saveMenu[4]; // offset 0x800C682C


extern struct DebugMenuLine mcardMenu[8]; // offset 0x800C8974


extern struct DebugMenuLine fogMenu[8]; // offset 0x800C697C


extern struct DebugMenuLine AIMenu[6]; // offset 0x800C751C


extern struct DebugMenuLine cameraMenu[4]; // offset 0x800C74BC


extern struct DebugMenuLine cheatsMenu[8]; // offset 0x800C7054


extern struct DebugMenuLine optsMenu[15]; // offset 0x800C7114


extern struct DebugMenuLine gpadConfigMenu[4]; // offset 0x800C727C


extern struct DebugMenuLine keybConfigMenu[4]; // offset 0x800C72DC


extern struct DebugMenuLine demoMenu[8]; // offset 0x800C733C


extern struct DebugMenuLine AlukaMenu[10]; // offset 0x800C75AC


extern struct DebugMenuLine AshVillageMenu[7]; // offset 0x800C769C


extern struct DebugMenuLine OracleMenu[10]; // offset 0x800C7744


extern struct DebugMenuLine PillarsMenu[6]; // offset 0x800C7834


extern struct DebugMenuLine SilencedCathedralMenu[11]; // offset 0x800C78C4


extern struct DebugMenuLine SkinnerMenu[7]; // offset 0x800C79CC


extern struct DebugMenuLine StoneMenu[5]; // offset 0x800C7A74


extern struct DebugMenuLine SunLightMenu[7]; // offset 0x800C7AEC


extern struct DebugMenuLine TombMenu[6]; // offset 0x800C7B94


extern struct DebugMenuLine WaterMenu[4]; // offset 0x800C7C24


extern struct DebugMenuLine PushMenu[10]; // offset 0x800C7C84


extern struct DebugMenuLine CityMenu[5]; // offset 0x800C7D74


extern struct DebugMenuLine CliffMenu[3]; // offset 0x800C7DEC


extern struct DebugMenuLine UnderMenu[3]; // offset 0x800C7E34


extern struct DebugMenuLine MorlockMenu[3]; // offset 0x800C7E7C


extern struct DebugMenuLine HubAMenu[5]; // offset 0x800C7EC4


extern struct DebugMenuLine HubBMenu[3]; // offset 0x800C7F3C


extern struct DebugMenuLine TrainingMenu[5]; // offset 0x800C7F84


extern struct DebugMenuLine TestMenu2[16]; // offset 0x800C7FFC


extern struct DebugMenuLine TestMenu[18]; // offset 0x800C817C


extern struct DebugMenuLine DarkEdenMenu[3]; // offset 0x800C832C


extern struct DebugMenuLine AnteRoomsMenu[8]; // offset 0x800C8374


extern struct DebugMenuLine DemoAreaMenu[10]; // offset 0x800C850C


extern struct DebugMenuLine MovieAreaMenu[8]; // offset 0x800C85FC


extern struct DebugMenuLine mcardSaveMenu[8]; // offset 0x800C8A34


extern struct DebugMenuLine pauseSaveMenu[5]; // offset 0x800C8AF4


static struct debug_dispatch_t debug_dispatch_table[5]; // offset 0x800C8C14


extern struct DebugMenuLine *currentMenu; // offset 0x800CEE98


static char pauseFormatString[20]; // offset 0x800CE2C0


static char mainFormatString[20]; // offset 0x800CE2D4


static char *the_format_string; // offset 0x800CE2E8


extern long menuPauseSel; // offset 0x800CE2EC


extern long debug_cameraMode; // offset 0x800CE2F0


extern long debugVoiceIndex; // offset 0x800CE2F4


extern unsigned long debugTimeMult; // offset 0x800CE2F8


extern long debugFogFar; // offset 0x800CE2FC


extern long debugFogNear; // offset 0x800CE300


extern long debugGameTime; // offset 0x800CE304


extern long debugFogRed; // offset 0x800CE308


extern long debugFogGrn; // offset 0x800CE30C


extern long debugFogBlu; // offset 0x800CE310


extern long debugHealthLevel; // offset 0x800CE314


static long debugMenuChoice; // offset 0x800CEE9C


static long cheatCodeStage; // offset 0x800CEEA0


static long cheatCodeLastCommand; // offset 0x800CEEA4


static long cheatCombo[4]; // offset 0x800CEEA8


extern struct DebugMenuLine *the_previous_menu; // offset 0x800CEEB8


static int cem_x_base; // offset 0x800CEEBC


static int cem_y_base; // offset 0x800CEEC0


static int cem_cursor_width; // offset 0x800CEEC4


static int cem_line_width; // offset 0x800CEEC8


static int cem_line_leading; // offset 0x800CEECC


static int cem_item_leading; // offset 0x800CEED0


extern short AXIS_LENGTH; // offset 0x800CF034


extern unsigned long debugRazielFlags1; // offset 0x800D0E68


extern unsigned long debugRazielFlags2; // offset 0x800D0E6C


extern short debugOrgFogFar; // offset 0x800D0E4C


extern short debugOrgFogNear; // offset 0x800D0E3C


extern unsigned char debugOrgFogRed; // offset 0x800D0E40


extern unsigned char debugOrgFogGrn; // offset 0x800D0E44


extern unsigned char debugOrgFogBlu; // offset 0x800D0E48


extern struct DebugMenuLine debugSoundMenu[1]; // offset 0x800D0E24


extern struct DebugMenuLine statsMenu[1]; // offset 0x800D0E50


extern long draw_belowSplit; // offset 0x800CF378


extern short forceDrawInFront; // offset 0x800CF374


extern struct SVECTOR *face_v0; // offset 0x800CF37C


extern struct SVECTOR *face_v1; // offset 0x800CF380


extern struct SVECTOR *face_v2; // offset 0x800CF384


extern struct SVECTOR *face_v01; // offset 0x800CF388


extern struct SVECTOR *face_v12; // offset 0x800CF38C


extern struct SVECTOR *face_v20; // offset 0x800CF390


extern struct UVTYPE *face_uv0; // offset 0x800CF394


extern struct UVTYPE *face_uv1; // offset 0x800CF398


extern struct UVTYPE *face_uv2; // offset 0x800CF39C


extern struct UVTYPE *face_uv01; // offset 0x800CF3A0


extern struct UVTYPE *face_uv12; // offset 0x800CF3A4


extern struct UVTYPE *face_uv20; // offset 0x800CF3A8


extern long modelDQP; // offset 0x800D1494


extern unsigned char *draw_stack; // offset 0x800D1490


extern struct SVECTOR shadow_vertices[11]; // offset 0x800D1498


static struct font_color_t the_font_color_table[3]; // offset 0x800C8C3C


extern struct FontPos fontPos[72]; // offset 0x800C8C60


extern char charMap[92][3]; // offset 0x800C8D80


extern unsigned char fontTransTable[128]; // offset 0x800CF3C4


extern struct FontTracker fontTracker; // offset 0x800D16F8


extern struct _BlockVramEntry *FONT_vramBlock; // offset 0x800D16F0


extern unsigned short SpecialFogClut; // offset 0x800D16F4


static char fp_str[512]; // offset 0x800D14F0


extern unsigned char dualshock_motors[2]; // offset 0x800C8EBC


extern unsigned char dualshock_align[6]; // offset 0x800C8EC0


static unsigned short __currentData; // offset 0x800CF4F8


static unsigned short __dataCount; // offset 0x800CF4FA


static unsigned short *__demoBufferStart; // offset 0x800CF4FC


static unsigned short *__demoBuffer; // offset 0x800CF500


static short align_flag; // offset 0x800CF504


static short dualshock_onflag; // offset 0x800CF506


static int dualShock; // offset 0x800CF508


extern unsigned short lastData[2]; // offset 0x800CF574


static int gpSaved; // offset 0x800CF584


extern int gamePadControllerOut; // offset 0x800D1E74


extern long gDummyCommand[2][2]; // offset 0x800D1E64


extern unsigned char controllerType[2]; // offset 0x800D1DCC


extern struct ControllerPacket gpbuffer1; // offset 0x800D1DD4


extern struct ControllerPacket gpbuffer2; // offset 0x800D1E1C


extern struct ControllerPacket readGPBuffer1; // offset 0x800D1DF8


extern struct ControllerPacket readGPBuffer2; // offset 0x800D1E40


static long dualshock0_time; // offset 0x800D1D68


static long dualshock1_time; // offset 0x800D1D6C


extern unsigned short psxData[2]; // offset 0x800D1DD0


static long overrideData[2][5]; // offset 0x800D1D74


static long overrideCommand[2][5]; // offset 0x800D1DA4


extern long camera_modeToIndex[15]; // offset 0x800CF110


static short shorten_count; // offset 0x800CF14C


static short shorten_flag; // offset 0x800CF14E


static short camera_still; // offset 0x800CF150


static long roll_target; // offset 0x800CF154


static long current_roll_amount; // offset 0x800CF158


static int roll_inc; // offset 0x800CF15C


static short CenterFlag; // offset 0x800CF16E


static short CameraLookStickyFlag; // offset 0x800CF170


static short panic_count; // offset 0x800CF174


extern struct Camera theCamera; // offset 0x800D0F9C


static struct MATRIX wcTransformX; // offset 0x800D0E80


static struct MATRIX wcTransform2X; // offset 0x800D0EA0


static struct MATRIX cwTransform2X; // offset 0x800D0EC0


static short combat_cam_distance; // offset 0x800D0EE0


static short combat_cam_angle; // offset 0x800D0EE2


static short combat_cam_weight; // offset 0x800D0EE4


static short combat_cam_debounce; // offset 0x800D0EE6


extern int CameraCenterDelay; // offset 0x800D1468


static struct _SVector camera_shakeOffset[16]; // offset 0x800D0EF0


static struct _SVector camera_plane; // offset 0x800D0F70


static struct _SVector left_point; // offset 0x800D0F78


static struct _SVector right_point; // offset 0x800D0F80


static short hitline_rot; // offset 0x800D0F88


static long ACE_amount; // offset 0x800D0F8C


static struct _Rotation splinecam_helprot; // offset 0x800D0F90


static short Camera_lookHeight; // offset 0x800D0F98


static short Camera_lookDist; // offset 0x800D0F9A


extern long campoint_hw; // offset 0x800D1460


extern long campoint_hh; // offset 0x800D1464


static struct LightGroup default_lightgroup; // offset 0x800CF640


extern void *light_light; // offset 0x800D1E7C


extern struct LightInfo *light_lightInfo; // offset 0x800D1E84


extern struct _Terrain *light_terrain; // offset 0x800D1E80


extern char HashExtensions[7][4]; // offset 0x800CF6F8


static struct _LoadStatus loadStatus; // offset 0x800D1E98


extern long crap1; // offset 0x800D1F38


extern int _ramsize; // offset 0x800CF75C


extern int _stacksize; // offset 0x800CF760


extern char mainOptionsInit; // offset 0x800CF764


extern short gEndGameNow; // offset 0x800CF766


extern int pcverify; // offset 0x800CF768


extern int nosound; // offset 0x800CF76C


extern int nomusic; // offset 0x800CF770


extern struct InterfaceItem InterfaceItems[5]; // offset 0x800CF774


extern long DoMainMenu; // offset 0x800CF88C


extern long mainMenuMode; // offset 0x800CF890


extern long *mainMenuScreen; // offset 0x800CF894


extern long *controlsScreen; // offset 0x800CF898


extern short mainMenuFadeInTime; // offset 0x800CF89C


extern short mainMenuFading; // offset 0x800CF89E


extern struct GameTracker gameTrackerX; // offset 0x800D20CC


extern struct DRAWENV draw[2]; // offset 0x800D1F8C


extern struct DISPENV disp[2]; // offset 0x800D1F60


extern struct BLK_FILL clearRect[2]; // offset 0x800D20A8


extern int devstation; // offset 0x800D1F88


extern unsigned long __timerEvent; // offset 0x800D20A4


extern struct MainTracker mainTrackerX; // offset 0x800D2344


extern short mainMenuTimeOut; // offset 0x800D20C8


static int mainMenuSfx; // offset 0x800D1F3C


extern struct _ButtonTexture PauseButtons[4][2]; // offset 0x800D2354


extern struct _ButtonTexture BmenuLines[3][2]; // offset 0x800D2044


extern struct _ButtonTexture BexitLine[2]; // offset 0x800D1F40


extern long cameraMode; // offset 0x800CF444


extern long playerCameraMode; // offset 0x800CF448


extern struct Object *fontsObject; // offset 0x800CF44C


extern struct _FXTracker *gFXT; // offset 0x800D1D48


extern unsigned long StackSave; // offset 0x800D1D58


static unsigned long (**gOt[2]); // offset 0x800D1D18


extern char *primBase; // offset 0x800D1D60


static struct _PrimPool (*primPool[2]); // offset 0x800D1D20


static struct _PolytopeList *gPolytopeList; // offset 0x800D1D28


static struct _InstanceList *instanceList; // offset 0x800D1D2C


static struct _InstancePool *instancePool; // offset 0x800D1D30


static struct _VertexPool *gVertexPool; // offset 0x800D1D34


static struct LightInfo *gLightInfo; // offset 0x800D1D38


extern struct _FXTracker *fxTracker; // offset 0x800D1D5C


static void *enemyPlanPool; // offset 0x800D1D3C


static void *planningPool; // offset 0x800D1D40


static struct _ObjectTracker *GlobalObjects; // offset 0x800D1D44


extern short RENDER_currentStreamUnitID; // offset 0x800D1D50


extern int InStreamUnit; // offset 0x800D1D4C


extern unsigned long **hackOT; // offset 0x800D1D54


extern long SignalEndGame; // offset 0x800CF198


extern struct SignalInfo signalInfoList[27]; // offset 0x800CF19C


extern long dyna_clddyna[8]; // offset 0x800CF2E0


extern long stat_clddyna[8]; // offset 0x800CF300


extern long dyna_cldstat[8]; // offset 0x800CF320


extern long collide_ignoreAttr; // offset 0x800CF340


extern long collide_acceptAttr; // offset 0x800CF344


extern struct _SVector collide_localPoint; // offset 0x800D147C


extern struct MATRIX *collide_lwTransform; // offset 0x800D1484


extern struct _SVector *collide_point0; // offset 0x800D146C


extern struct _SVector *collide_point1; // offset 0x800D1470


extern struct _SVector *collide_normal0; // offset 0x800D1488


extern struct _SVector *collide_normal1; // offset 0x800D148C


extern long collide_t0; // offset 0x800D1474


extern long collide_t1; // offset 0x800D1478


extern struct _Normal gNormalList[244]; // offset 0x800C90F4


extern short ecostable[3072]; // offset 0x800C9894


static long vmRealClock; // offset 0x800CFDE0


static long vmClock; // offset 0x800CFDE4


extern short identityMatrix[3][3]; // offset 0x800CFA60


extern char (*selectMenuText[5]); // offset 0x800C8EC8


extern long gTimerEnabled; // offset 0x800CFAC4


extern struct LightInfo *sbsp_lightInfo; // offset 0x800D23D4


extern struct ObjectAccess objectAccess[28]; // offset 0x800C8EDC


extern struct ObjectFunc objectFunc[8]; // offset 0x800C8FBC


extern int gSramFullAlarm; // offset 0x800CFC84


extern int musicLoadInProgress; // offset 0x800CFC88


static int gSramFullMsgCnt; // offset 0x800CFC8C


static int checkMusicDelay; // offset 0x800CFC90


static int currentMusicPlane; // offset 0x800CFC94


static int reqMusicNewPlane; // offset 0x800CFC98


static int reqMusicStartPlaneShift; // offset 0x800CFC9C


static long objectOneShotTriggerTbl[3]; // offset 0x800CFCA0


extern int gSramTotalUsed; // offset 0x800D2640


extern int gSramUsedBlocks; // offset 0x800D263C


extern int gSramTotalFree; // offset 0x800D2644


extern int gSramLargestFree; // offset 0x800D23F4


extern int gSramFreeBlocks; // offset 0x800D2638


static char currentDynamicSoundName[16]; // offset 0x800D23E4


extern struct SoundEffectChannel soundEffectChannelTbl[16]; // offset 0x800D23F8


extern char soundBuffer[13256]; // offset 0x800D6138


extern long FRAC_BITS; // offset 0x800CFD4C


static struct _FXGeneralEffect *FX_GeneralEffectTracker; // offset 0x800CFD74


static struct _FXRibbon *FX_ConstrictRibbon; // offset 0x800CFD78


static short FX_ConstrictStage; // offset 0x800CFD7C


static struct _Instance *FX_ConstrictInstance; // offset 0x800CFD80


static short snow_amount; // offset 0x800CFD84


static short rain_amount; // offset 0x800CFD86


static struct _Instance *FX_reaver_instance; // offset 0x800CFD88


static short windx; // offset 0x800CFDB0


static short windy; // offset 0x800CFDB2


static short wind_deg; // offset 0x800CFDB4


static short wind_speed; // offset 0x800CFDB6


extern long FX_ColorArray[6]; // offset 0x800CFDB8


static short Spiral_Number; // offset 0x800CFDD0


static short Spiral_Degrees; // offset 0x800CFDD2


static long Spiral_Current; // offset 0x800CFDD4


static long Spiral_Max; // offset 0x800CFDD8


static struct _Position FX_ConstrictPosition; // offset 0x800D2680


static struct _Position *FX_ConstrictPositionPtr; // offset 0x800D2688


static struct _FX_PRIM *FX_LastUsedPrim; // offset 0x800D268C


static short FX_Frames; // offset 0x800D2690


static short FX_TimeCount; // offset 0x800D2692


static struct DVECTOR Spiral_Array[65]; // offset 0x800D26A0


static struct DVECTOR Spiral_OffsetP[64]; // offset 0x800D27B0


static struct DVECTOR Spiral_OffsetM[64]; // offset 0x800D28B0


static int Spiral_Glow_X; // offset 0x800D29B0


static int Spiral_Glow_Y; // offset 0x800D29B4


static int Spiral_Glow_Size; // offset 0x800D29B8


static int Spiral_Mod; // offset 0x800D29BC


static char midiDataByteCount[8]; // offset 0x800CFF94


static struct NewMemTracker newMemTracker; // offset 0x800D29C0


extern unsigned long aadGp; // offset 0x800CB094


static unsigned short aadHblanksPerUpdate[4]; // offset 0x800CFECC


static unsigned long aadUpdateRate[4]; // offset 0x800CFED4


extern struct AadMemoryStruct *aadMem; // offset 0x800CFEE4


extern int gSramCheckRequest; // offset 0x800CFEE8


static int gDfragRequest; // offset 0x800CFEEC


static unsigned long aadReverbModeSize[10]; // offset 0x800CFF6C


static unsigned long __hblankEvent; // offset 0x800D29D4


static unsigned char *smfDataPtr; // offset 0x800D29D8


static unsigned long smfBytesLeft; // offset 0x800D29DC


static struct AadDynamicSfxLoadInfo *smfInfo; // offset 0x800D29E0


static struct AadProgramAtr aadDummySfxProgram; // offset 0x800D0158


extern unsigned short aadPitchTable[85]; // offset 0x800D0160


extern unsigned long aadStepsPerCent[85]; // offset 0x800D020C


extern short aadStepsPerSemitone[85]; // offset 0x800D0360


extern long CurrentWarpNumber; // offset 0x800D040C


extern struct WarpRoom WarpRoomArray[14]; // offset 0x800D0410


extern struct STracker StreamTracker; // offset 0x800D2A0C


extern struct STREAM_289fake WarpGateLoadInfo; // offset 0x800D29E8


extern struct _TFace *MORPH_SavedFace; // offset 0x800D2E0C


extern struct Level *MORPH_SavedLevel; // offset 0x800D29FC


extern short MORPH_Component[3]; // offset 0x800D2A00


extern short MORPH_Track[2]; // offset 0x800D2A08


static int s_zval; // offset 0x800D29E4


extern long WaitingForVoiceNumber; // offset 0x800D0774


extern long WaitingToLoadSound; // offset 0x800D0778


static short EventAbortLine; // offset 0x800D077C


static short EventJustRecievedTimer; // offset 0x800D077E


static long MoveCodeStreamExtra; // offset 0x800D0780


static long CurrentEventLine; // offset 0x800D0784


static long EventCurrentEventIndex; // offset 0x800D0788


extern long WaterInUse; // offset 0x800D078C


extern long NumSignalsToReset; // offset 0x800D0790


static struct Event *currentEventInstance; // offset 0x800D2E20


static struct ScriptPCode *currentActionScript; // offset 0x800D2E24


static short *EventAbortedPosition; // offset 0x800D2E28


extern long eventListNumInstances[20]; // offset 0x800D3104


extern struct _Instance (*eventListArray[20][10]); // offset 0x800D31E4


static struct WaterLevelProcess WaterLevelArray[5]; // offset 0x800D2E30


static struct Level *CurrentPuzzleLevel; // offset 0x800D2EBC


static struct EventTimer eventTimerArray[24]; // offset 0x800D2EC0


static long numActiveEventTimers; // offset 0x800D3100


extern struct SignalResetStruct ResetSignalArray[16]; // offset 0x800D3154


extern struct HintSystemStruct gHintSystem; // offset 0x800D31D4


static int loadBufferedFromHead; // offset 0x800D0720


static int gCurDir; // offset 0x800D0724


static struct _LoadQueueEntry *loadFree; // offset 0x800D2E10


static struct _LoadQueueEntry *loadHead; // offset 0x800D2E14


static struct _LoadQueueEntry *loadTail; // offset 0x800D2E18


static int numLoads; // offset 0x800D2E1C


static struct _LoadQueueEntry LoadQueue[40]; // offset 0x800D9500


extern struct _MonsterStateChoice HUNTER_StateChoiceTable[6]; // offset 0x800CB144


extern struct _MonsterFunctionTable HUNTER_FunctionTable; // offset 0x800D0854


static struct MissileGraphics MISSILE_objectTable[4]; // offset 0x800CB18C


extern long RazielCommands[10]; // offset 0x800D07A8


static int Pending; // offset 0x800D07D0


static int Up; // offset 0x800D07D4


static int Down; // offset 0x800D07D8


static struct _G2AnimAlphaTable_Type (*G2AlphaTables[7]); // offset 0x800D07DC


static void *circWhere; // offset 0x800D07F8


static char circBuf[4096]; // offset 0x800D3504


extern long VRAM_NeedToUpdateMorph; // offset 0x800D07FC


extern short M_TrackClutUpdate; // offset 0x800D4D38


extern struct _BlockVramEntry *openVramBlocks; // offset 0x800D4D60


extern struct _BlockVramEntry *usedVramBlocks; // offset 0x800D4D5C


extern struct _BlockVramEntry vramBlockList[75]; // offset 0x800D4504


extern long numOfBlocksUsed; // offset 0x800D4D3C


extern struct _BlockVramEntry TerrainVramBlock; // offset 0x800D4D40


static short fx_going; // offset 0x800D0814


extern struct _FXBlastringEffect *fx_blastring; // offset 0x800D0818


static short HUD_Captured; // offset 0x800D081C


static short MANNA_Position; // offset 0x800D4DEC


static short MANNA_Pos_vel; // offset 0x800D4DEE


static short glyph_time; // offset 0x800D4DF0


static short glyph_trigger; // offset 0x800D4DF2


static short glyph_cost; // offset 0x800D4DF4


static int HUD_Count; // offset 0x800D4DF8


static int blast_range; // offset 0x800D4DFC


static int fx_radius_old; // offset 0x800D4E00


static int MANNA_Pickup_Time; // offset 0x800D4E04


static short HUD_Rotation; // offset 0x800D4E08


static short HUD_Rot_vel; // offset 0x800D4E0A


static short HUD_Position; // offset 0x800D4E0C


static short HUD_Pos_vel; // offset 0x800D4E0E


static short HUD_State; // offset 0x800D4E10


static short HUD_Wait; // offset 0x800D4E12


static struct _SVector HUD_Cap_Pos; // offset 0x800D4E14


static struct _SVector HUD_Cap_Vel; // offset 0x800D4E1C


static int warpDraw; // offset 0x800D4E24


static int glowdeg; // offset 0x800D4E28


extern int hud_warp_arrow_flash; // offset 0x800D4E2C


extern struct _MonsterStateChoice HUMAN_StateChoiceTable[6]; // offset 0x800CB0FC


extern struct _MonsterFunctionTable HUMAN_FunctionTable; // offset 0x800D0828


static int gNumMonsters; // offset 0x800D0894


static struct RadarInfo radarDir[8]; // offset 0x800D0898


static unsigned char radarDirIndex[8]; // offset 0x800D08C8


static struct _MonsterVars (*monsterSenseArray[40]); // offset 0x800D4E30


static char monsterSensed[40]; // offset 0x800D4ED0


static int lastSenseFrame; // offset 0x800D4EF8


static struct burntTuneType burntTest; // offset 0x800D08D4


extern struct _MonsterStateChoice VWRAITH_StateChoiceTable[7]; // offset 0x800CB3B4


extern struct _MonsterFunctionTable VWRAITH_FunctionTable; // offset 0x800D0974


extern struct _MonsterStateChoice SKINNER_StateChoiceTable[5]; // offset 0x800CB2F4


extern struct _MonsterFunctionTable SKINNER_FunctionTable; // offset 0x800D090C


extern struct _MonsterStateChoice SLUAGH_StateChoiceTable[4]; // offset 0x800CB330


extern struct _MonsterFunctionTable SLUAGH_FunctionTable; // offset 0x800D092C


extern struct _MonsterStateChoice SOUL_StateChoiceTable[7]; // offset 0x800CB360


extern struct _MonsterFunctionTable SOUL_FunctionTable; // offset 0x800D0954


static struct MONTABLE_202fake functionChoiceTable[8]; // offset 0x800CB1BC


static struct _MonsterState DefaultStateTable[31]; // offset 0x800CB1FC


static struct _MonsterFunctionTable DefaultFunctionTable; // offset 0x800D08EC


static struct _G2AppDataVM_Type _appDataVM; // offset 0x800D56AC


extern struct _MonsterStateChoice WORSHIP_StateChoiceTable[5]; // offset 0x800CB408


extern struct _MonsterFunctionTable WORSHIP_FunctionTable; // offset 0x800D0994


static int _indexTable[16]; // offset 0x800CB444


static int _stepSizeTable[64]; // offset 0x800CB484


static struct _G2AnimChanStatusBlockPool_Type _chanStatusBlockPool; // offset 0x800D4EFC


static struct _G2AnimSegValue_Type _segValues[80]; // offset 0x800D4F0C


static struct _G2AnimControllerPool_Type _controllerPool; // offset 0x800D568C


static struct _G2AnimInterpStateBlockPool_Type _interpStateBlockPool; // offset 0x800D569C


extern struct PoolManagementData *poolManagementData; // offset 0x800D5700


static struct PoolManagementData poolManagementDataStorage; // offset 0x800D56B4


static long timerArray[10]; // offset 0x800D56D4


static long timerIndex; // offset 0x800D56FC


static struct _fth directionList[6]; // offset 0x800D09DC


static struct __Force *ExternalForces; // offset 0x800D5704


static struct MATRIX TempMat; // offset 0x800D5714


extern int LoopCounter; // offset 0x800D09F4


static int WaterStatus; // offset 0x800D09F8


static unsigned char PickupList[4]; // offset 0x800D09FC


static unsigned short cowlList[19]; // offset 0x800D0A00


extern struct __razController controllerList[24]; // offset 0x800D0A28


extern struct __CannedSound cannedSound[4]; // offset 0x800D0A88


static int AlgoControlFlag; // offset 0x800D0AD8


static int ZoneDelta; // offset 0x800D0ADC


extern struct __Idle **currentIdleList; // offset 0x800D0B68


extern int currentIdleListCount; // offset 0x800D0B6C


extern int currentIdleCount; // offset 0x800D0B70


static int BlockCount; // offset 0x800D0B74


static int LastBlock; // offset 0x800D0B78


static struct __Player Raziel; // offset 0x800D5744


static struct RazielData *PlayerData; // offset 0x800D5CF4


static struct _G2AnimInterpInfo_Type razInterpInfo[3]; // offset 0x800D5D04


static struct __FitPoint constrictData[32]; // offset 0x800D5D34


static struct MATRIX TempMat; // offset 0x800D5DB4


static struct GameTracker *gameTracker; // offset 0x800D5DD4


static long *PadData; // offset 0x800D5DD8


static struct _G2SVector3_Type ExtraRotData; // offset 0x800D5DDC


static struct _G2SVector3_Type *ExtraRot; // offset 0x800D5DE4


extern int ControlFlag; // offset 0x800D5EDC


static struct __Force ExternalForces[4]; // offset 0x800D5DF4


static int PhysicsMode; // offset 0x800D5E44


static struct __EngagedInstance EngagedList[15]; // offset 0x800D5E54


static struct _Normal Norm; // offset 0x800D5ECC


extern int AutoFaceAngle; // offset 0x800D5ED8


static int LastRC; // offset 0x800D5ED4


static struct UW_ScreenXY *ScreenMorphArray; // offset 0x800D0B88


static long UW_angle; // offset 0x800D5EE0


static long UW_scalex; // offset 0x800D5EE4


static long UW_scalexInc; // offset 0x800D5EE8


static long UW_angleInc; // offset 0x800D5EEC


static struct cinema_fn_table_t *the_cine_table; // offset 0x800CB5A8


static struct _ObjectTracker *the_cine_tracker; // offset 0x800CB5AC


extern int StCdIntrFlag; // offset 0x800DA680


static struct LocalizationHeader *LocalizationTable; // offset 0x800D0C50


static char **LocalStrings; // offset 0x800D0C54


extern struct XAVoiceListEntry *voiceList; // offset 0x800D0C58


static enum language_t the_language; // offset 0x800D612C


static struct menu_sound_entry_t the_menu_sounds[6]; // offset 0x800CB5B0


static char (*the_attract_movies[4]); // offset 0x800CB5E0


static int MAIN_XPOS; // offset 0x800D0D04


static int MAIN_YPOS; // offset 0x800D0D08


static int MAIN_WIDTH; // offset 0x800D0D0C


static int PAUSE_XPOS; // offset 0x800D0D10


static int PAUSE_YPOS; // offset 0x800D0D14


static int PAUSE_WIDTH; // offset 0x800D0D18


static int LINESKIP; // offset 0x800D0D1C


static int ITEMSKIP; // offset 0x800D0D20


static int hack_reset_attract; // offset 0x800D0D24


static int StartGameFading; // offset 0x800D0D28


static int hack_attract; // offset 0x800D0D2C


static int hack_attract_movie; // offset 0x800D0D30


extern struct DebugMenuLine mcardMenu[1]; // offset 0x18


extern struct DebugMenuLine mcardSaveMenu[1]; // offset 0x18


extern long *mainMenuScreen; // offset 0x4


extern struct _GlobalSaveTracker *GlobalSave; // offset 0x800D0B9C


static long numbufferedIntros; // offset 0x800D0BA0


static int the_header_size; // offset 0x800D0BA4


extern long SaveArraySize[10]; // offset 0x800D0BA8


static struct SavedInfoTracker savedInfoTracker; // offset 0x800D5EF0


static struct SavedBasic (*bufferSavedIntroArray[64]); // offset 0x800D5F00


extern char monVersion[12]; // offset 0x800D0C18


extern struct XAVoiceTracker voiceTracker; // offset 0x800D6004


static struct menuface_t MenuFaces[8]; // offset 0x800D0D64


static int hack_initialized; // offset 0x800D0DC4


static struct _ButtonTexture *FaceButtons; // offset 0x800D6134


extern struct mcmenu_table_t the_mcmenu_table; // offset 0x24


static struct MEMCARD_211fake gMcmenu; // offset 0x800DA684


extern struct memcard_t gMemcard; // offset 0x800DA884

/* End external declarations */

#endif
