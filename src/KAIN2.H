#ifndef KAIN2_MONOLITHIC_HEADER
#define KAIN2_MONOLITHIC_HEADER

/* Begin enums */

enum _G2Bool_Enum // Hashcode: 0xFDD7E4E7 (dec: -36182809)
{
	G2FALSE = 0,
};

enum DEBUG_LINE_TYPE // Hashcode: 0x03F31324 (dec: 66261796)
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

enum option_ctrl_t // Hashcode: 0x33E11B37 (dec: 870390583)
{
	option_ctrl_bogus = 0,
	option_ctrl_none = 1,
	option_ctrl_select = 2,
	option_ctrl_left = 3,
	option_ctrl_right = 4,
	option_ctrl_num_states = 5,
};

enum _G2AnimCallbackMsg_Enum // Hashcode: 0xA8F4A89C (dec: -1460361060)
{
	G2ANIM_MSG_DONE = 1,
	G2ANIM_MSG_LOOPPOINT = 2,
	G2ANIM_MSG_SECTION_INTERPDONE = 3,
	G2ANIM_MSG_SEGCTRLR_INTERPDONE = 4,
	G2ANIM_MSG_SWALARMSET = 5,
	G2ANIM_MSG_PLAYEFFECT = 6,
};

enum MATH3D_AXIS // Hashcode: 0x325251CF (dec: 844255695)
{
	AXIS_X = 0,
	AXIS_Y = 1,
	AXIS_Z = 2,
	AXIS_NEG_X = 3,
	AXIS_NEG_Y = 4,
	AXIS_NEG_Z = 5,
};

enum MonsterAnim // Hashcode: 0xCB25B8B5 (dec: -886720331)
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

enum MonsterState // Hashcode: 0xD129E7A3 (dec: -785782877)
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

enum language_t // Hashcode: 0x752FDA0A (dec: 1966070282)
{
	language_default = -1,
	language_english = 0,
	language_french = 1,
	language_german = 2,
	language_italian = 3,
	language_spanish = 4,
	language_num_states = 5,
};

enum localstr_t // Hashcode: 0xA826B41B (dec: -1473858533)
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

enum menu_ctrl_t // Hashcode: 0xE0BD1E93 (dec: -524476781)
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

enum menu_sound_t // Hashcode: 0x0248C7C9 (dec: 38324169)
{
	menu_sound_none = 0,
	menu_sound_default = 1,
	menu_sound_select = 2,
	menu_sound_adjust = 3,
	menu_sound_engage = 4,
	menu_sound_pop = 5,
};

enum sfx_t // Hashcode: 0x9EDBE31D (dec: -1629756643)
{
	sfx_sound = 0,
	sfx_music = 1,
	sfx_voice = 2,
	sfx_error = 3,
};

enum bdepth // Hashcode: 0x70F5AFBC (dec: 1895149500)
{
	TIM_4BIT = 0,
	TIM_8BIT = 1,
	TIM_16BIT = 2,
};

enum mcpsx_err_t // Hashcode: 0xEE8E3374 (dec: -292670604)
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
	mcpsx_error = 9,
	mcpsx_err_num_items = 10,
};

enum mcpsx_func_t // Hashcode: 0x9BA9717E (dec: -1683394178)
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

enum mcpsx_sync_t // Hashcode: 0x89C16C20 (dec: -1983812576)
{
	sync_idle = -1,
	sync_busy = 0,
	sync_done = 1,
	sync_func = 2,
	sync_num_items = 3,
};

enum mcpsx_mode_t // Hashcode: 0xD0203678 (dec: -803195272)
{
	mode_bogus = 0,
	mode_initialized = 1,
	mode_running = 2,
	mode_terminated = 3,
	mode_num_items = 4,
};

enum state_t // Hashcode: 0x22E90AAF (dec: 585697967)
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

enum mcard_status_t // Hashcode: 0x1A4A7B37 (dec: 441088823)
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

enum fsm_t // Hashcode: 0x2B04DCAF (dec: 721738927)
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
	fsm_error = 13,
	fsm_num_items = 14,
};
/* End enums */

/* Begin structs */

struct TCB // hashcode: 0x6A70BBF4 (dec: 1785773044)
{
	long status;		   // size=0, offset=0 //  hashcode: 0x086B0C51 (dec: 141233233), parent name: 'TCB', parent hashcode: 0xFFFFFFFF (dec: -1)
	long mode;			   // size=0, offset=4 //  hashcode: 0xDA5CDBD9 (dec: -631448615), parent name: 'TCB', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long reg[40]; // size=160, offset=8 //  hashcode: 0x3A73ABEE (dec: 980659182), parent name: 'TCB', parent hashcode: 0xFFFFFFFF (dec: -1)
	long system[6];		   // size=24, offset=168 //  hashcode: 0x677F28CC (dec: 1736386764), parent name: 'TCB', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EXEC // hashcode: 0x4291A2AD (dec: 1116840621)
{
	unsigned long pc0;	// size=0, offset=0 //  hashcode: 0xE5B8530C (dec: -440904948), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long gp0;	// size=0, offset=4 //  hashcode: 0xDAFC2018 (dec: -621010920), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long t_addr; // size=0, offset=8 //  hashcode: 0x0D6CBDF7 (dec: 225230327), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long t_size; // size=0, offset=12 //  hashcode: 0x5F6A2CAA (dec: 1600793770), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long d_addr; // size=0, offset=16 //  hashcode: 0x0115E2A4 (dec: 18211492), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long d_size; // size=0, offset=20 //  hashcode: 0x3E22DED3 (dec: 1042472659), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long b_addr; // size=0, offset=24 //  hashcode: 0xEBA37B64 (dec: -341607580), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long b_size; // size=0, offset=28 //  hashcode: 0x152B199A (dec: 355146138), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long s_addr; // size=0, offset=32 //  hashcode: 0x25334277 (dec: 624116343), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long s_size; // size=0, offset=36 //  hashcode: 0x8B038609 (dec: -1962703351), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long sp;	 // size=0, offset=40 //  hashcode: 0xAADDBAD6 (dec: -1428309290), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long fp;	 // size=0, offset=44 //  hashcode: 0xF2E0481A (dec: -220182502), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long gp;	 // size=0, offset=48 //  hashcode: 0x196AF344 (dec: 426439492), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long ret;	// size=0, offset=52 //  hashcode: 0xBB7C0EB0 (dec: -1149497680), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long base;   // size=0, offset=56 //  hashcode: 0xD37F8BB6 (dec: -746615882), parent name: 'EXEC', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DIRENTRY // hashcode: 0xD989A944 (dec: -645289660)
{
	char name[20];		   // size=20, offset=0 //  hashcode: 0xA2DA0F6A (dec: -1562767510), parent name: 'DIRENTRY', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attr;			   // size=0, offset=20 //  hashcode: 0x5A6CBB0B (dec: 1517075211), parent name: 'DIRENTRY', parent hashcode: 0xFFFFFFFF (dec: -1)
	long size;			   // size=0, offset=24 //  hashcode: 0x6EA817AC (dec: 1856509868), parent name: 'DIRENTRY', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DIRENTRY *next; // size=40, offset=28 //  hashcode: 0xFB2C47E3 (dec: -80984093), parent name: 'DIRENTRY', parent hashcode: 0xFFFFFFFF (dec: -1)
	long head;			   // size=0, offset=32 //  hashcode: 0x902962D3 (dec: -1876335917), parent name: 'DIRENTRY', parent hashcode: 0xFFFFFFFF (dec: -1)
	char system[4];		   // size=4, offset=36 //  hashcode: 0x6DC6A881 (dec: 1841735809), parent name: 'DIRENTRY', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MATRIX // hashcode: 0x610186A2 (dec: 1627489954)
{
	short m[3][3]; // size=18, offset=0 //  hashcode: 0x6AA97C11 (dec: 1789492241), parent name: 'MATRIX', parent hashcode: 0xFFFFFFFF (dec: -1)
	long t[3];	 // size=12, offset=20 //  hashcode: 0xF6C8EB24 (dec: -154604764), parent name: 'MATRIX', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VECTOR // hashcode: 0xE0DB0D68 (dec: -522515096)
{
	long vx;  // size=0, offset=0 //  hashcode: 0x996D64A0 (dec: -1720884064), parent name: 'VECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	long vy;  // size=0, offset=4 //  hashcode: 0xB7193B4C (dec: -1223083188), parent name: 'VECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	long vz;  // size=0, offset=8 //  hashcode: 0x5E86BD61 (dec: 1585888609), parent name: 'VECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	long pad; // size=0, offset=12 //  hashcode: 0x0E0ECF3A (dec: 235851578), parent name: 'VECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SVECTOR // hashcode: 0x55473CEB (dec: 1430732011)
{
	short vx;  // size=0, offset=0 //  hashcode: 0x0FEA65B5 (dec: 267019701), parent name: 'SVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vy;  // size=0, offset=2 //  hashcode: 0xA5CFF704 (dec: -1513097468), parent name: 'SVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vz;  // size=0, offset=4 //  hashcode: 0xB161FAFA (dec: -1318978822), parent name: 'SVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad; // size=0, offset=6 //  hashcode: 0x343FD367 (dec: 876598119), parent name: 'SVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CVECTOR // hashcode: 0xDE4B0C81 (dec: -565506943)
{
	unsigned char r;  // size=0, offset=0 //  hashcode: 0xA80BB350 (dec: -1475628208), parent name: 'CVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;  // size=0, offset=1 //  hashcode: 0x974498FB (dec: -1757112069), parent name: 'CVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;  // size=0, offset=2 //  hashcode: 0xE728DF60 (dec: -416751776), parent name: 'CVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char cd; // size=0, offset=3 //  hashcode: 0xB1430357 (dec: -1321008297), parent name: 'CVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DVECTOR // hashcode: 0x5BF12E56 (dec: 1542532694)
{
	short vx; // size=0, offset=0 //  hashcode: 0xF310A60F (dec: -217012721), parent name: 'DVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vy; // size=0, offset=2 //  hashcode: 0x6BBA1CDB (dec: 1807359195), parent name: 'DVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RVECTOR // hashcode: 0xEC34D5C3 (dec: -332081725)
{
	struct SVECTOR v;	// size=8, offset=0 //  hashcode: 0xB7041025 (dec: -1224470491), parent name: 'RVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char uv[2]; // size=2, offset=8 //  hashcode: 0x808A12B3 (dec: -2138434893), parent name: 'RVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad;  // size=0, offset=10 //  hashcode: 0x8B27972D (dec: -1960339667), parent name: 'RVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct CVECTOR c;	// size=4, offset=12 //  hashcode: 0xDC1A314B (dec: -602263221), parent name: 'RVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DVECTOR sxy;  // size=4, offset=16 //  hashcode: 0x2BC5F879 (dec: 734394489), parent name: 'RVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long sz;	// size=0, offset=20 //  hashcode: 0x27E2CB2A (dec: 669174570), parent name: 'RVECTOR', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CRVECTOR3 // hashcode: 0x9A564233 (dec: -1705622989)
{
	struct RVECTOR r01; // size=24, offset=0 //  hashcode: 0x000D78BD (dec: 882877), parent name: 'CRVECTOR3', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR r12; // size=24, offset=24 //  hashcode: 0x826D2953 (dec: -2106775213), parent name: 'CRVECTOR3', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR r20; // size=24, offset=48 //  hashcode: 0x1F7A8086 (dec: 528121990), parent name: 'CRVECTOR3', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR *r0; // size=24, offset=72 //  hashcode: 0xF81284E1 (dec: -133004063), parent name: 'CRVECTOR3', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR *r1; // size=24, offset=76 //  hashcode: 0x51F9CE08 (dec: 1375325704), parent name: 'CRVECTOR3', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR *r2; // size=24, offset=80 //  hashcode: 0xDA788D60 (dec: -629633696), parent name: 'CRVECTOR3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long *rtn; // size=0, offset=84 //  hashcode: 0x74F8EE65 (dec: 1962471013), parent name: 'CRVECTOR3', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CRVECTOR4 // hashcode: 0x56AED614 (dec: 1454298644)
{
	struct RVECTOR r01; // size=24, offset=0 //  hashcode: 0xD4F361EF (dec: -722247185), parent name: 'CRVECTOR4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR r02; // size=24, offset=24 //  hashcode: 0x6D1A3CC4 (dec: 1830436036), parent name: 'CRVECTOR4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR r31; // size=24, offset=48 //  hashcode: 0x66AC02A0 (dec: 1722548896), parent name: 'CRVECTOR4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR r32; // size=24, offset=72 //  hashcode: 0xA93A6458 (dec: -1455791016), parent name: 'CRVECTOR4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR rc;  // size=24, offset=96 //  hashcode: 0x62654CFA (dec: 1650806010), parent name: 'CRVECTOR4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR *r0; // size=24, offset=120 //  hashcode: 0x7AAF6598 (dec: 2058315160), parent name: 'CRVECTOR4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR *r1; // size=24, offset=124 //  hashcode: 0xF9DC21B4 (dec: -103013964), parent name: 'CRVECTOR4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR *r2; // size=24, offset=128 //  hashcode: 0xDBFA7F03 (dec: -604340477), parent name: 'CRVECTOR4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RVECTOR *r3; // size=24, offset=132 //  hashcode: 0xA6596016 (dec: -1504092138), parent name: 'CRVECTOR4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long *rtn; // size=0, offset=136 //  hashcode: 0x03A50899 (dec: 61147289), parent name: 'CRVECTOR4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RECT // hashcode: 0xDFC821CB (dec: -540532277)
{
	short x; // size=0, offset=0 //  hashcode: 0x186E0F52 (dec: 409866066), parent name: 'RECT', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y; // size=0, offset=2 //  hashcode: 0x283654C7 (dec: 674649287), parent name: 'RECT', parent hashcode: 0xFFFFFFFF (dec: -1)
	short w; // size=0, offset=4 //  hashcode: 0x621DCD6A (dec: 1646120298), parent name: 'RECT', parent hashcode: 0xFFFFFFFF (dec: -1)
	short h; // size=0, offset=6 //  hashcode: 0x435C8B63 (dec: 1130138467), parent name: 'RECT', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DR_ENV // hashcode: 0xD77E7FD5 (dec: -679575595)
{
	unsigned long tag;		// size=0, offset=0 //  hashcode: 0x7FDBA6FD (dec: 2145101565), parent name: 'DR_ENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long code[15]; // size=60, offset=4 //  hashcode: 0x2B044D34 (dec: 721702196), parent name: 'DR_ENV', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct P_TAG // hashcode: 0x962C4103 (dec: -1775484669)
{
	unsigned int addr : 24; // offset=0.0 //  hashcode: 0x23A9DDAE (dec: 598334894), parent name: 'P_TAG', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned int len : 8;   // offset=3.0 //  hashcode: 0x71A373C6 (dec: 1906537414), parent name: 'P_TAG', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;		// size=0, offset=4 //  hashcode: 0xB1E724A6 (dec: -1310251866), parent name: 'P_TAG', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;		// size=0, offset=5 //  hashcode: 0xBE8E9D4B (dec: -1097949877), parent name: 'P_TAG', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;		// size=0, offset=6 //  hashcode: 0x82E3551E (dec: -2099030754), parent name: 'P_TAG', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code;		// size=0, offset=7 //  hashcode: 0x4F836FCC (dec: 1334013900), parent name: 'P_TAG', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CdlLOC // hashcode: 0x449289F8 (dec: 1150454264)
{
	unsigned char minute; // size=0, offset=0 //  hashcode: 0x78480741 (dec: 2017986369), parent name: 'CdlLOC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char second; // size=0, offset=1 //  hashcode: 0xF17180C7 (dec: -244219705), parent name: 'CdlLOC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char sector; // size=0, offset=2 //  hashcode: 0x8F8413F3 (dec: -1887169549), parent name: 'CdlLOC', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char track;  // size=0, offset=3 //  hashcode: 0x802BF1C8 (dec: -2144603704), parent name: 'CdlLOC', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LightInstance // hashcode: 0xB8D5E61F (dec: -1193941473)
{
	struct _Instance *lightInstance; // size=0, offset=0 //  hashcode: 0x4943BD3B (dec: 1229176123), parent name: 'LightInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long r;							 // size=0, offset=4 //  hashcode: 0xEF59AD24 (dec: -279335644), parent name: 'LightInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long g;							 // size=0, offset=8 //  hashcode: 0x25B68F2C (dec: 632721196), parent name: 'LightInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long b;							 // size=0, offset=12 //  hashcode: 0x0B22743C (dec: 186807356), parent name: 'LightInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short radius;					 // size=0, offset=16 //  hashcode: 0xFF2623BD (dec: -14277699), parent name: 'LightInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char segment;			 // size=0, offset=18 //  hashcode: 0xF05D456B (dec: -262322837), parent name: 'LightInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;			 // size=0, offset=19 //  hashcode: 0xA2BEECD4 (dec: -1564545836), parent name: 'LightInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct NodeType // hashcode: 0x5BF613D7 (dec: 1542853591)
{
	struct NodeType *prev; // size=8, offset=0 //  hashcode: 0x8B4DA622 (dec: -1957845470), parent name: 'NodeType', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType *next; // size=8, offset=4 //  hashcode: 0xDB8CB0B1 (dec: -611536719), parent name: 'NodeType', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SoundInstance // hashcode: 0xFF235679 (dec: -14461319)
{
	unsigned char channel; // size=0, offset=0 //  hashcode: 0x61316CDF (dec: 1630629087), parent name: 'SoundInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char state;   // size=0, offset=1 //  hashcode: 0xB9825B15 (dec: -1182639339), parent name: 'SoundInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char delay;   // size=0, offset=2 //  hashcode: 0x184E0534 (dec: 407766324), parent name: 'SoundInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _SVector // hashcode: 0x73B07C09 (dec: 1940945929)
{
	short x;   // size=0, offset=0 //  hashcode: 0x08A052A7 (dec: 144724647), parent name: '_SVector', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;   // size=0, offset=2 //  hashcode: 0x74BDBE34 (dec: 1958592052), parent name: '_SVector', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;   // size=0, offset=4 //  hashcode: 0x973AA93D (dec: -1757763267), parent name: '_SVector', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad; // size=0, offset=6 //  hashcode: 0x45EF1DAC (dec: 1173298604), parent name: '_SVector', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _SVectorNoPad // hashcode: 0xA6EDBBC6 (dec: -1494369338)
{
	short x; // size=0, offset=0 //  hashcode: 0x05A8A295 (dec: 94937749), parent name: '_SVectorNoPad', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y; // size=0, offset=2 //  hashcode: 0xD04029C5 (dec: -801101371), parent name: '_SVectorNoPad', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z; // size=0, offset=4 //  hashcode: 0x685B61F9 (dec: 1750819321), parent name: '_SVectorNoPad', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Rotation // hashcode: 0x5A40CBB0 (dec: 1514195888)
{
	short x;   // size=0, offset=0 //  hashcode: 0x33B21012 (dec: 867307538), parent name: '_Rotation', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;   // size=0, offset=2 //  hashcode: 0x900454E1 (dec: -1878764319), parent name: '_Rotation', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;   // size=0, offset=4 //  hashcode: 0x9D9370BD (dec: -1651281731), parent name: '_Rotation', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad; // size=0, offset=6 //  hashcode: 0xE7BFC418 (dec: -406862824), parent name: '_Rotation', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Normal // hashcode: 0xC59D5A5B (dec: -979543461)
{
	short x;   // size=0, offset=0 //  hashcode: 0x7473D7DA (dec: 1953748954), parent name: '_Normal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;   // size=0, offset=2 //  hashcode: 0x21D414C5 (dec: 567547077), parent name: '_Normal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;   // size=0, offset=4 //  hashcode: 0xEAE589EA (dec: -354055702), parent name: '_Normal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad; // size=0, offset=6 //  hashcode: 0x33C50399 (dec: 868549529), parent name: '_Normal', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _PlaneConstants // hashcode: 0xE1AAD777 (dec: -508897417)
{
	short a;	 // size=0, offset=0 //  hashcode: 0x1F992779 (dec: 530130809), parent name: '_PlaneConstants', parent hashcode: 0xFFFFFFFF (dec: -1)
	short b;	 // size=0, offset=2 //  hashcode: 0x6F77C59B (dec: 1870120347), parent name: '_PlaneConstants', parent hashcode: 0xFFFFFFFF (dec: -1)
	short c;	 // size=0, offset=4 //  hashcode: 0x7C10A909 (dec: 2081466633), parent name: '_PlaneConstants', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags; // size=0, offset=6 //  hashcode: 0x295E591C (dec: 694049052), parent name: '_PlaneConstants', parent hashcode: 0xFFFFFFFF (dec: -1)
	long d;		 // size=0, offset=8 //  hashcode: 0xE0DBA5D5 (dec: -522476075), parent name: '_PlaneConstants', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Vertex // hashcode: 0x97101469 (dec: -1760553879)
{
	short x; // size=0, offset=0 //  hashcode: 0xBDB7C875 (dec: -1112029067), parent name: '_Vertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y; // size=0, offset=2 //  hashcode: 0x1E17E0FD (dec: 504881405), parent name: '_Vertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z; // size=0, offset=4 //  hashcode: 0x997C0D51 (dec: -1719923375), parent name: '_Vertex', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Face // hashcode: 0x8775891B (dec: -2022340325)
{
	unsigned short v0; // size=0, offset=0 //  hashcode: 0x86B628EA (dec: -2034882326), parent name: '_Face', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short v1; // size=0, offset=2 //  hashcode: 0x2C1049EF (dec: 739265007), parent name: '_Face', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short v2; // size=0, offset=4 //  hashcode: 0x0BB6F73B (dec: 196540219), parent name: '_Face', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MVertex // hashcode: 0x2B95C05B (dec: 731234395)
{
	struct _Vertex vertex; // size=6, offset=0 //  hashcode: 0x6CC4E410 (dec: 1824842768), parent name: '_MVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short normal; // size=0, offset=6 //  hashcode: 0x690A4802 (dec: 1762281474), parent name: '_MVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MFace // hashcode: 0xB75C604D (dec: -1218682803)
{
	struct _Face face;	// size=6, offset=0 //  hashcode: 0x71B0D230 (dec: 1907413552), parent name: '_MFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char normal; // size=0, offset=6 //  hashcode: 0x9FFF9D21 (dec: -1610638047), parent name: '_MFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;  // size=0, offset=7 //  hashcode: 0x0C27CFB3 (dec: 203935667), parent name: '_MFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color;			  // size=0, offset=8 //  hashcode: 0xF15E1C0E (dec: -245490674), parent name: '_MFace', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _RGBAColor // hashcode: 0xF7174D90 (dec: -149467760)
{
	unsigned char r; // size=0, offset=0 //  hashcode: 0x30F25BDF (dec: 821189599), parent name: '_RGBAColor', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g; // size=0, offset=1 //  hashcode: 0xA1938AAA (dec: -1584166230), parent name: '_RGBAColor', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b; // size=0, offset=2 //  hashcode: 0xBCE3FD2D (dec: -1125909203), parent name: '_RGBAColor', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char a; // size=0, offset=3 //  hashcode: 0xA7DFD488 (dec: -1478503288), parent name: '_RGBAColor', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _PVertex // hashcode: 0x4AC0ECE8 (dec: 1254157544)
{
	short x;  // size=0, offset=0 //  hashcode: 0xFFCCEB52 (dec: -3347630), parent name: '_PVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;  // size=0, offset=2 //  hashcode: 0x7D8D8533 (dec: 2106426675), parent name: '_PVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	long otz; // size=0, offset=4 //  hashcode: 0x04224934 (dec: 69355828), parent name: '_PVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _VertexPool // hashcode: 0x98F8C96E (dec: -1728525970)
{
	struct _PVertex vertex[528]; // size=4224, offset=0 //  hashcode: 0xA3AEACE8 (dec: -1548833560), parent name: '_VertexPool', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct CVECTOR color[528];   // size=2112, offset=4224 //  hashcode: 0xAB87CE80 (dec: -1417163136), parent name: '_VertexPool', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _PrimPool // hashcode: 0x9529B283 (dec: -1792429437)
{
	long numPrims;			   // size=0, offset=0 //  hashcode: 0x498A21E7 (dec: 1233789415), parent name: '_PrimPool', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long *nextPrim;   // size=0, offset=4 //  hashcode: 0xAB396725 (dec: -1422301403), parent name: '_PrimPool', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long *lastPrim;   // size=0, offset=8 //  hashcode: 0x923639E4 (dec: -1841939996), parent name: '_PrimPool', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long prim[24000]; // size=96000, offset=12 //  hashcode: 0xE19E53F7 (dec: -509717513), parent name: '_PrimPool', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Position // hashcode: 0x2523C22F (dec: 623100463)
{
	short x; // size=0, offset=0 //  hashcode: 0x583D5468 (dec: 1480414312), parent name: '_Position', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y; // size=0, offset=2 //  hashcode: 0x66ACC135 (dec: 1722597685), parent name: '_Position', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z; // size=0, offset=4 //  hashcode: 0xE498BAB5 (dec: -459752779), parent name: '_Position', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Sphere // hashcode: 0x361BDD31 (dec: 907795761)
{
	struct _Position position;   // size=6, offset=0 //  hashcode: 0xE3EEA9D9 (dec: -470898215), parent name: '_Sphere', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short radius;		 // size=0, offset=6 //  hashcode: 0xB22C8E58 (dec: -1305702824), parent name: '_Sphere', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long radiusSquared; // size=0, offset=8 //  hashcode: 0xA375AC20 (dec: -1552569312), parent name: '_Sphere', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Sphere_noSq // hashcode: 0xA031058C (dec: -1607400052)
{
	struct _Position position; // size=6, offset=0 //  hashcode: 0x7F78BF7C (dec: 2138619772), parent name: '_Sphere_noSq', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short radius;	 // size=0, offset=6 //  hashcode: 0x87DD193F (dec: -2015553217), parent name: '_Sphere_noSq', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _CameraKey // hashcode: 0xB9E6B724 (dec: -1176062172)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x13BAB6BA (dec: 331003578), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0xB3884FFA (dec: -1282912262), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;	 // size=0, offset=4 //  hashcode: 0x09F28463 (dec: 166888547), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short id;	// size=0, offset=6 //  hashcode: 0x502DF9D3 (dec: 1345190355), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rx;	// size=0, offset=8 //  hashcode: 0x42907FCD (dec: 1116766157), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ry;	// size=0, offset=10 //  hashcode: 0x21990E3C (dec: 563678780), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rz;	// size=0, offset=12 //  hashcode: 0x53989B7F (dec: 1402510207), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags; // size=0, offset=14 //  hashcode: 0xE7A9FE6F (dec: -408289681), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short tx;	// size=0, offset=16 //  hashcode: 0xCC4C3A90 (dec: -867419504), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ty;	// size=0, offset=18 //  hashcode: 0x6FF95733 (dec: 1878611763), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short tz;	// size=0, offset=20 //  hashcode: 0xB3E47FE7 (dec: -1276870681), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;   // size=0, offset=22 //  hashcode: 0x0A6047E7 (dec: 174082023), parent name: '_CameraKey', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2SVector3_Type // hashcode: 0x60FF7CCD (dec: 1627356365)
{
	short x; // size=0, offset=0 //  hashcode: 0x5877A7D1 (dec: 1484236753), parent name: '_G2SVector3_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y; // size=0, offset=2 //  hashcode: 0xE07F7772 (dec: -528517262), parent name: '_G2SVector3_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z; // size=0, offset=4 //  hashcode: 0x04E69F44 (dec: 82222916), parent name: '_G2SVector3_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimSection_Type // hashcode: 0xFC80328C (dec: -58707316)
{
	unsigned char flags;									 // size=0, offset=0 //  hashcode: 0xF87764F1 (dec: -126393103), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char sectionID;								 // size=0, offset=1 //  hashcode: 0x2DF2EE39 (dec: 770895417), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char firstSeg;									 // size=0, offset=2 //  hashcode: 0xF890807D (dec: -124747651), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char segCount;									 // size=0, offset=3 //  hashcode: 0xBAF5F0E5 (dec: -1158287131), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short elapsedTime;										 // size=0, offset=4 //  hashcode: 0x613FDBCF (dec: 1631574991), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short storedTime;										 // size=0, offset=6 //  hashcode: 0xF1B1B4B2 (dec: -240012110), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short loopStartTime;									 // size=0, offset=8 //  hashcode: 0x16C94137 (dec: 382288183), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short loopEndTime;										 // size=0, offset=10 //  hashcode: 0xBFFC4220 (dec: -1073987040), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short *swAlarmTable;									 // size=0, offset=12 //  hashcode: 0x7AE0FAA5 (dec: 2061564581), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	long speedAdjustment;									 // size=0, offset=16 //  hashcode: 0xEB4F93DB (dec: -347106341), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short keylistID;								 // size=0, offset=20 //  hashcode: 0x9F1C1719 (dec: -1625549031), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long alarmFlags;								 // size=0, offset=24 //  hashcode: 0x79E79922 (dec: 2045221154), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	long (*callback)();										 // size=0, offset=28 //  hashcode: 0xCEFECCF5 (dec: -822162187), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *callbackData;										 // size=0, offset=32 //  hashcode: 0x5365FD9D (dec: 1399192989), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimKeylist_Type *keylist;					 // size=20, offset=36 //  hashcode: 0x40DB96D1 (dec: 1088132817), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimChanStatusBlock_Type *chanStatusBlockList; // size=36, offset=40 //  hashcode: 0xD1FEA901 (dec: -771839743), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimInterpInfo_Type *interpInfo;				 // size=12, offset=44 //  hashcode: 0x8472DC51 (dec: -2072847279), parent name: '_G2AnimSection_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2Anim_Type // hashcode: 0xF35FCCD2 (dec: -211825454)
{
	unsigned char sectionCount;			   // size=0, offset=0 //  hashcode: 0x6F91B40F (dec: 1871819791), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char masterSection;		   // size=0, offset=1 //  hashcode: 0x499570DE (dec: 1234530526), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short controllerList;		   // size=0, offset=2 //  hashcode: 0x462BE3AE (dec: 1177281454), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short disabledControllerList; // size=0, offset=4 //  hashcode: 0x5E72B05B (dec: 1584574555), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad;					   // size=0, offset=6 //  hashcode: 0x9E15AE52 (dec: -1642746286), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type rootTrans;	 // size=6, offset=8 //  hashcode: 0xDBBA9B2F (dec: -608527569), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short flags;				   // size=0, offset=14 //  hashcode: 0x261EE835 (dec: 639559733), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Model *modelData;			   // size=0, offset=16 //  hashcode: 0xDDBB0FAC (dec: -574943316), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Matrix_Type *segMatrices;	// size=32, offset=20 //  hashcode: 0xDF91277D (dec: -544135299), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long disabledBits[3];		   // size=12, offset=24 //  hashcode: 0x7B9833E0 (dec: 2073572320), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimSection_Type section[3]; // size=144, offset=36 //  hashcode: 0x035F348C (dec: 56571020), parent name: '_G2Anim_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EventAliasCommandStruct // hashcode: 0xB6EF2AF6 (dec: -1225839882)
{
	struct _Instance *hostInstance; // size=0, offset=0 //  hashcode: 0x95780CB0 (dec: -1787294544), parent name: 'EventAliasCommandStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	short newanim;					// size=0, offset=4 //  hashcode: 0x062156E0 (dec: 102848224), parent name: 'EventAliasCommandStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	short newframe;					// size=0, offset=6 //  hashcode: 0x6E942D47 (dec: 1855204679), parent name: 'EventAliasCommandStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	short interpframes;				// size=0, offset=8 //  hashcode: 0xD8B030B7 (dec: -659541833), parent name: 'EventAliasCommandStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	short speed;					// size=0, offset=10 //  hashcode: 0x2EF91381 (dec: 788075393), parent name: 'EventAliasCommandStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Instance // hashcode: 0x699A5B3D (dec: 1771723581)
{
	struct NodeType node;						 // size=8, offset=0 //  hashcode: 0x99208B91 (dec: -1725920367), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *next;						 // size=616, offset=8 //  hashcode: 0xB3A164B8 (dec: -1281268552), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *prev;						 // size=616, offset=12 //  hashcode: 0x42C61B4A (dec: 1120279370), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long instanceID;							 // size=0, offset=16 //  hashcode: 0xA6884804 (dec: -1501018108), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;									 // size=0, offset=20 //  hashcode: 0xD1775B28 (dec: -780707032), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags2;								 // size=0, offset=24 //  hashcode: 0x21861BFC (dec: 562437116), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object;						 // size=76, offset=28 //  hashcode: 0x1F65FB30 (dec: 526777136), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Intro *intro;						 // size=0, offset=32 //  hashcode: 0x0F03F6CB (dec: 251918027), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;									 // size=0, offset=36 //  hashcode: 0x19CC04EB (dec: 432801003), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *introData;							 // size=0, offset=40 //  hashcode: 0xA50D07DB (dec: -1525872677), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *parent;					 // size=616, offset=44 //  hashcode: 0x1BBBD8B7 (dec: 465295543), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long introNum;								 // size=0, offset=48 //  hashcode: 0x8279A896 (dec: -2105956202), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long birthStreamUnitID;						 // size=0, offset=52 //  hashcode: 0xED885CFD (dec: -309830403), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long currentStreamUnitID;					 // size=0, offset=56 //  hashcode: 0x72D30C56 (dec: 1926433878), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long introUniqueID;							 // size=0, offset=60 //  hashcode: 0x2BFA69A1 (dec: 737831329), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX *matrix;						 // size=32, offset=64 //  hashcode: 0xE317A8AB (dec: -484988757), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX *oldMatrix;					 // size=32, offset=68 //  hashcode: 0x32B1418F (dec: 850477455), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SoundInstance soundInstanceTbl[4];	// size=12, offset=72 //  hashcode: 0x6758AC4D (dec: 1733864525), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long maxCheckDistance;				 // size=0, offset=84 //  hashcode: 0x0E842D43 (dec: 243543363), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long checkMask;					 // size=0, offset=88 //  hashcode: 0xEC138633 (dec: -334264781), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position;					 // size=6, offset=92 //  hashcode: 0xD4957DF0 (dec: -728400400), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char lightGroup;					 // size=0, offset=98 //  hashcode: 0x8CAE4B99 (dec: -1934734439), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position oldPos;					 // size=6, offset=100 //  hashcode: 0x1063D144 (dec: 274977092), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char spectralLightGroup;			 // size=0, offset=106 //  hashcode: 0x8584656E (dec: -2054920850), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short currentTextureAnimFrame;				 // size=0, offset=108 //  hashcode: 0x960093A5 (dec: -1778347099), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position initialPos;				 // size=6, offset=110 //  hashcode: 0x386B385F (dec: 946550879), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation;					 // size=8, offset=116 //  hashcode: 0x74BE2D34 (dec: 1958620468), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation oldRotation;				 // size=8, offset=124 //  hashcode: 0xA1D5C67F (dec: -1579825537), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector scale;						 // size=8, offset=132 //  hashcode: 0xDA9E0E9F (dec: -627175777), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attachedID;							 // size=0, offset=140 //  hashcode: 0x9BCBC65C (dec: -1681144228), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attachedSegment;						 // size=0, offset=144 //  hashcode: 0xC10D1191 (dec: -1056108143), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX relativeMatrix;				 // size=32, offset=148 //  hashcode: 0xE3835060 (dec: -477933472), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;						 // size=12, offset=180 //  hashcode: 0x88C4C8FF (dec: -2000369409), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;					 // size=12, offset=184 //  hashcode: 0xF2256D72 (dec: -232428174), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *tfaceLevel;							 // size=0, offset=188 //  hashcode: 0x11BB7061 (dec: 297496673), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *collideInfo;							 // size=0, offset=192 //  hashcode: 0x66F9A20E (dec: 1727635982), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long bspTree;								 // size=0, offset=196 //  hashcode: 0x9EF645B5 (dec: -1628027467), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cachedTFace;							 // size=0, offset=200 //  hashcode: 0xFAF15585 (dec: -84847227), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cachedBSPTree;						 // size=0, offset=202 //  hashcode: 0xF04425B4 (dec: -263969356), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *cachedTFaceLevel;						 // size=0, offset=204 //  hashcode: 0xF192C521 (dec: -242039519), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Normal oldWNormal;					 // size=8, offset=208 //  hashcode: 0x5B7F4794 (dec: 1535068052), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Normal wNormal;						 // size=8, offset=216 //  hashcode: 0xB9F91D63 (dec: -1174856349), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset;						 // size=8, offset=224 //  hashcode: 0xE2B8BD56 (dec: -491209386), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HModel *hModelList;					 // size=8, offset=232 //  hashcode: 0xC12D7847 (dec: -1053984697), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadeValue;							 // size=0, offset=236 //  hashcode: 0x564EF969 (dec: 1448016233), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lightMatrix;							 // size=0, offset=238 //  hashcode: 0x3BCAE250 (dec: 1003151952), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*processFunc)();						 // size=0, offset=240 //  hashcode: 0x509F6C31 (dec: 1352625201), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*collideFunc)();						 // size=0, offset=244 //  hashcode: 0x590F8C01 (dec: 1494191105), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*additionalCollideFunc)();			 // size=0, offset=248 //  hashcode: 0xBD63CD14 (dec: -1117532908), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long (*queryFunc)();				 // size=0, offset=252 //  hashcode: 0x7F7E6E8A (dec: 2138992266), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*messageFunc)();						 // size=0, offset=256 //  hashcode: 0xFCD61AC7 (dec: -53077305), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position shadowPosition;			 // size=6, offset=260 //  hashcode: 0xD0781A43 (dec: -797435325), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short currentModel;							 // size=0, offset=266 //  hashcode: 0x57010A87 (dec: 1459686023), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *waterFace;					 // size=12, offset=268 //  hashcode: 0x0AC072B0 (dec: 180384432), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldWaterFace;				 // size=12, offset=272 //  hashcode: 0x2FE681B5 (dec: 803635637), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Terrain *waterFaceTerrain;			 // size=0, offset=276 //  hashcode: 0xF61F0A62 (dec: -165737886), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _PlaneConstants halvePlane;			 // size=12, offset=280 //  hashcode: 0x3436D438 (dec: 876008504), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector splitPoint;					 // size=8, offset=292 //  hashcode: 0xEAB4289D (dec: -357291875), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *LinkParent;				 // size=616, offset=300 //  hashcode: 0xA2F719D6 (dec: -1560864298), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *LinkChild;				 // size=616, offset=304 //  hashcode: 0x5DB1CE79 (dec: 1571933817), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *LinkSibling;				 // size=616, offset=308 //  hashcode: 0x92292860 (dec: -1842796448), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long ParentLinkNode;						 // size=0, offset=312 //  hashcode: 0xA312388F (dec: -1559086961), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *InstanceState;						 // size=0, offset=316 //  hashcode: 0x79B2FE86 (dec: 2041773702), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	char introName[12];							 // size=12, offset=320 //  hashcode: 0xBDFED102 (dec: -1107373822), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *extraData;							 // size=0, offset=332 //  hashcode: 0x694711D8 (dec: 1766265304), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short constrictAngle;						 // size=0, offset=336 //  hashcode: 0xB6F7367A (dec: -1225312646), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short petrifyValue;							 // size=0, offset=338 //  hashcode: 0x9B0240A1 (dec: -1694351199), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long xVel;									 // size=0, offset=340 //  hashcode: 0x42ACBBB9 (dec: 1118616505), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long yVel;									 // size=0, offset=344 //  hashcode: 0xD6EEAB82 (dec: -689001598), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long zVel;									 // size=0, offset=348 //  hashcode: 0xA21ED791 (dec: -1575037039), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long xAccl;									 // size=0, offset=352 //  hashcode: 0xF0501CF6 (dec: -263185162), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long yAccl;									 // size=0, offset=356 //  hashcode: 0xC49C9B60 (dec: -996369568), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long zAccl;									 // size=0, offset=360 //  hashcode: 0x588735F2 (dec: 1485256178), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxXVel;								 // size=0, offset=364 //  hashcode: 0x699F6B15 (dec: 1772055317), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxYVel;								 // size=0, offset=368 //  hashcode: 0xB840A661 (dec: -1203722655), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxZVel;								 // size=0, offset=372 //  hashcode: 0x237D351E (dec: 595408158), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long currentMainState;						 // size=0, offset=376 //  hashcode: 0x67C6BFB0 (dec: 1741078448), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long work0;									 // size=0, offset=380 //  hashcode: 0xDE8C79D1 (dec: -561219119), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long work1;									 // size=0, offset=384 //  hashcode: 0x1281F305 (dec: 310506245), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long work2;									 // size=0, offset=388 //  hashcode: 0xD1CF0CA9 (dec: -774959959), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long work3;									 // size=0, offset=392 //  hashcode: 0x27BB560D (dec: 666588685), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long work4;									 // size=0, offset=396 //  hashcode: 0xDFE8F832 (dec: -538380238), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long work5;									 // size=0, offset=400 //  hashcode: 0x8C138638 (dec: -1944877512), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Anim_Type anim;					 // size=180, offset=404 //  hashcode: 0xC5CB720A (dec: -976522742), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	enum _G2Bool_Enum (*rebuildCallback)();		 // size=4, offset=584 //  hashcode: 0xFE6A12C9 (dec: -26602807), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splineFlags;							 // size=0, offset=588 //  hashcode: 0x38C7970D (dec: 952604429), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short targetFrame;							 // size=0, offset=590 //  hashcode: 0xACE5BB38 (dec: -1394230472), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clipBeg;								 // size=0, offset=592 //  hashcode: 0xA006AD90 (dec: -1610175088), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clipEnd;								 // size=0, offset=594 //  hashcode: 0x834CD393 (dec: -2092117101), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct EventAliasCommandStruct aliasCommand; // size=12, offset=596 //  hashcode: 0x6CD7E213 (dec: 1826087443), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	long light_color;							 // size=0, offset=608 //  hashcode: 0xF86FC59E (dec: -126892642), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct CVECTOR *perVertexColor;				 // size=4, offset=612 //  hashcode: 0x6B4D42DF (dec: 1800225503), parent name: '_Instance', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _GameTrackerASMData_Type // hashcode: 0x28F0BFB9 (dec: 686866361)
{
	long drawBackFaces;						// size=0, offset=0 //  hashcode: 0x2855ACCA (dec: 676703434), parent name: '_GameTrackerASMData_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	long dispPage;							// size=0, offset=4 //  hashcode: 0xC14ECA9E (dec: -1051800930), parent name: '_GameTrackerASMData_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short MorphTime;						// size=0, offset=8 //  hashcode: 0x4797A3AD (dec: 1201120173), parent name: '_GameTrackerASMData_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short MorphType;						// size=0, offset=10 //  hashcode: 0x5E21D98C (dec: 1579276684), parent name: '_GameTrackerASMData_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LightInstance lightInstances[1]; // size=20, offset=12 //  hashcode: 0x7D6DD3A3 (dec: 2104349603), parent name: '_GameTrackerASMData_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _GameData_Type // hashcode: 0xE05EBAD0 (dec: -530662704)
{
	struct _GameTrackerASMData_Type asmData; // size=32, offset=0 //  hashcode: 0xC31E75FB (dec: -1021413893), parent name: '_GameData_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TextureFT3 // hashcode: 0x2D2801D6 (dec: 757596630)
{
	unsigned char u0;	 // size=0, offset=0 //  hashcode: 0x4D995D02 (dec: 1301896450), parent name: 'TextureFT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v0;	 // size=0, offset=1 //  hashcode: 0x5C499D7A (dec: 1548328314), parent name: 'TextureFT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short clut;  // size=0, offset=2 //  hashcode: 0x7B31A1EB (dec: 2066850283), parent name: 'TextureFT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u1;	 // size=0, offset=4 //  hashcode: 0x6FFCC88C (dec: 1878837388), parent name: 'TextureFT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v1;	 // size=0, offset=5 //  hashcode: 0xCD34547F (dec: -852208513), parent name: 'TextureFT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short tpage; // size=0, offset=6 //  hashcode: 0x0086BEC0 (dec: 8830656), parent name: 'TextureFT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u2;	 // size=0, offset=8 //  hashcode: 0xE6FDFD96 (dec: -419562090), parent name: 'TextureFT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v2;	 // size=0, offset=9 //  hashcode: 0x79D36CD3 (dec: 2043899091), parent name: 'TextureFT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short attr;  // size=0, offset=10 //  hashcode: 0x612E6034 (dec: 1630429236), parent name: 'TextureFT3', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TextureMT3 // hashcode: 0xC9D0A5B9 (dec: -909072967)
{
	unsigned char u0;	 // size=0, offset=0 //  hashcode: 0x7D4F5DFE (dec: 2102353406), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v0;	 // size=0, offset=1 //  hashcode: 0x9DE39147 (dec: -1646030521), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short clut;  // size=0, offset=2 //  hashcode: 0x7447FD16 (dec: 1950874902), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u1;	 // size=0, offset=4 //  hashcode: 0xE3131B99 (dec: -485287015), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v1;	 // size=0, offset=5 //  hashcode: 0x36AA29CB (dec: 917121483), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short tpage; // size=0, offset=6 //  hashcode: 0x0178C08A (dec: 24690826), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u2;	 // size=0, offset=8 //  hashcode: 0x96D670D5 (dec: -1764331307), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v2;	 // size=0, offset=9 //  hashcode: 0x33EE7C9B (dec: 871267483), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	char pad1;			  // size=0, offset=10 //  hashcode: 0x55A74212 (dec: 1437024786), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	char sortPush;		  // size=0, offset=11 //  hashcode: 0xC7CA6541 (dec: -943037119), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color;			  // size=0, offset=12 //  hashcode: 0xCEF04C6A (dec: -823112598), parent name: 'TextureMT3', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AniTexInfo // hashcode: 0x907C013D (dec: -1870921411)
{
	struct TextureMT3 *texture; // size=16, offset=0 //  hashcode: 0xEFFB17CC (dec: -268757044), parent name: 'AniTexInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numFrames;				// size=0, offset=4 //  hashcode: 0x0FA39D76 (dec: 262380918), parent name: 'AniTexInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long speed;					// size=0, offset=8 //  hashcode: 0x276B896E (dec: 661358958), parent name: 'AniTexInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AniTex // hashcode: 0xE4DA2729 (dec: -455465175)
{
	long numAniTextues;			  // size=0, offset=0 //  hashcode: 0x99F85565 (dec: -1711778459), parent name: 'AniTex', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AniTexInfo aniTexInfo; // size=12, offset=4 //  hashcode: 0x1CA1CA01 (dec: 480365057), parent name: 'AniTex', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DrMoveAniTexSrcInfo // hashcode: 0x4AD6E543 (dec: 1255597379)
{
	short pixSrcX;  // size=0, offset=0 //  hashcode: 0x413F2180 (dec: 1094656384), parent name: 'DrMoveAniTexSrcInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pixSrcY;  // size=0, offset=2 //  hashcode: 0x3030263E (dec: 808461886), parent name: 'DrMoveAniTexSrcInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clutSrcX; // size=0, offset=4 //  hashcode: 0xA579D3CE (dec: -1518742578), parent name: 'DrMoveAniTexSrcInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clutSrcY; // size=0, offset=6 //  hashcode: 0x74796042 (dec: 1954111554), parent name: 'DrMoveAniTexSrcInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DrMoveAniTexDestInfo // hashcode: 0xF3A982EE (dec: -206994706)
{
	short pixDstX;					  // size=0, offset=0 //  hashcode: 0x1033CEC8 (dec: 271830728), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pixDstY;					  // size=0, offset=2 //  hashcode: 0x6BE2A260 (dec: 1810014816), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pixW;						  // size=0, offset=4 //  hashcode: 0x45E03E34 (dec: 1172323892), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pixH;						  // size=0, offset=6 //  hashcode: 0x1769E174 (dec: 392814964), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clutDstX;					  // size=0, offset=8 //  hashcode: 0xCB8A1C1A (dec: -880141286), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clutDstY;					  // size=0, offset=10 //  hashcode: 0x482A68D9 (dec: 1210738905), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clutW;					  // size=0, offset=12 //  hashcode: 0x8AC04915 (dec: -1967109867), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clutH;					  // size=0, offset=14 //  hashcode: 0x6280EEC5 (dec: 1652616901), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pixCurrentX;				  // size=0, offset=16 //  hashcode: 0xEDA21C0C (dec: -308143092), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pixCurrentY;				  // size=0, offset=18 //  hashcode: 0xB422357D (dec: -1272826499), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clutCurrentX;				  // size=0, offset=20 //  hashcode: 0x632AD4F4 (dec: 1663751412), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clutCurrentY;				  // size=0, offset=22 //  hashcode: 0xDE48ED84 (dec: -565645948), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numFrames;					  // size=0, offset=24 //  hashcode: 0x1307837F (dec: 319259519), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long speed;						  // size=0, offset=28 //  hashcode: 0xC05E0971 (dec: -1067579023), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DrMoveAniTexSrcInfo frame; // size=8, offset=32 //  hashcode: 0xB9784A51 (dec: -1183298991), parent name: 'DrMoveAniTexDestInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DrMoveAniTex // hashcode: 0x0820A5D4 (dec: 136357332)
{
	long numAniTextues;						 // size=0, offset=0 //  hashcode: 0xDB35395F (dec: -617268897), parent name: 'DrMoveAniTex', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DrMoveAniTexDestInfo *aniTexInfo; // size=40, offset=4 //  hashcode: 0xD5502A20 (dec: -716166624), parent name: 'DrMoveAniTex', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MemHeader // hashcode: 0xDAEE4890 (dec: -621918064)
{
	unsigned short magicNumber; // size=0, offset=0 //  hashcode: 0xAEFD2C60 (dec: -1359139744), parent name: 'MemHeader', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char memStatus;	// size=0, offset=2 //  hashcode: 0xFC04094E (dec: -66844338), parent name: 'MemHeader', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char memType;		// size=0, offset=3 //  hashcode: 0x8725D009 (dec: -2027565047), parent name: 'MemHeader', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long memSize;		// size=0, offset=4 //  hashcode: 0x32D81A75 (dec: 853023349), parent name: 'MemHeader', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2LVector3_Type // hashcode: 0xD8D79EE7 (dec: -656957721)
{
	long x; // size=0, offset=0 //  hashcode: 0xA568D983 (dec: -1519855229), parent name: '_G2LVector3_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	long y; // size=0, offset=4 //  hashcode: 0x19F4A5EB (dec: 435463659), parent name: '_G2LVector3_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	long z; // size=0, offset=8 //  hashcode: 0x8EE70E23 (dec: -1897460189), parent name: '_G2LVector3_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2Matrix_Type // hashcode: 0x647D6F57 (dec: 1685942103)
{
	short rotScale[3][3];		   // size=18, offset=0 //  hashcode: 0x2C774BDD (dec: 746015709), parent name: '_G2Matrix_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short scaleFlag;			   // size=0, offset=18 //  hashcode: 0x1A7B8837 (dec: 444303415), parent name: '_G2Matrix_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2LVector3_Type trans; // size=12, offset=20 //  hashcode: 0x055DB992 (dec: 90028434), parent name: '_G2Matrix_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2Quat_Type // hashcode: 0xC71F9EB1 (dec: -954229071)
{
	short x; // size=0, offset=0 //  hashcode: 0xE241F858 (dec: -498993064), parent name: '_G2Quat_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y; // size=0, offset=2 //  hashcode: 0xE76648C7 (dec: -412727097), parent name: '_G2Quat_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z; // size=0, offset=4 //  hashcode: 0x40B7587D (dec: 1085757565), parent name: '_G2Quat_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short w; // size=0, offset=6 //  hashcode: 0x8A8835F1 (dec: -1970784783), parent name: '_G2Quat_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimQuatInfo_Type // hashcode: 0x5A520473 (dec: 1515324531)
{
	struct _G2Quat_Type srcQuat;	   // size=8, offset=0 //  hashcode: 0x7A6AA796 (dec: 2053810070), parent name: '_G2AnimQuatInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type destQuat;	  // size=8, offset=8 //  hashcode: 0x6CAE778A (dec: 1823373194), parent name: '_G2AnimQuatInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type srcScale;  // size=6, offset=16 //  hashcode: 0xD872F456 (dec: -663554986), parent name: '_G2AnimQuatInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type destScale; // size=6, offset=22 //  hashcode: 0xA4731159 (dec: -1535962791), parent name: '_G2AnimQuatInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type srcTrans;  // size=6, offset=28 //  hashcode: 0x2EA5B2E7 (dec: 782611175), parent name: '_G2AnimQuatInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type destTrans; // size=6, offset=34 //  hashcode: 0x63E9DC06 (dec: 1676270598), parent name: '_G2AnimQuatInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimAlphaTable_Type // hashcode: 0x2288BF48 (dec: 579387208)
{
	unsigned short size; // size=0, offset=0 //  hashcode: 0x375CABA1 (dec: 928820129), parent name: '_G2AnimAlphaTable_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	long data[0];		 // size=0, offset=4 //  hashcode: 0x12E4EFF6 (dec: 316993526), parent name: '_G2AnimAlphaTable_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimInterpStateBlock_Type // hashcode: 0xFB03DD89 (dec: -83632759)
{
	struct _G2AnimInterpStateBlock_Type *next; // size=164, offset=0 //  hashcode: 0x666A4BDD (dec: 1718242269), parent name: '_G2AnimInterpStateBlock_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimQuatInfo_Type quatInfo[4];   // size=160, offset=4 //  hashcode: 0xEA9207EB (dec: -359528469), parent name: '_G2AnimInterpStateBlock_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimInterpInfo_Type // hashcode: 0xAE13EB6F (dec: -1374426257)
{
	short duration;										 // size=0, offset=0 //  hashcode: 0xFA4DC0A3 (dec: -95567709), parent name: '_G2AnimInterpInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short targetTime;									 // size=0, offset=2 //  hashcode: 0x1965766E (dec: 426079854), parent name: '_G2AnimInterpInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimAlphaTable_Type *alphaTable;			 // size=4, offset=4 //  hashcode: 0xD44893E8 (dec: -733441048), parent name: '_G2AnimInterpInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimInterpStateBlock_Type *stateBlockList; // size=164, offset=8 //  hashcode: 0xBABBAB42 (dec: -1162106046), parent name: '_G2AnimInterpInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimChanStatus_Type // hashcode: 0x575B81AB (dec: 1465614763)
{
	short keyData; // size=0, offset=0 //  hashcode: 0x6B107CCF (dec: 1796242639), parent name: '_G2AnimChanStatus_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index;   // size=0, offset=2 //  hashcode: 0xEDF9A9A5 (dec: -302405211), parent name: '_G2AnimChanStatus_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimChanStatusBlock_Type // hashcode: 0xC6C09C4F (dec: -960455601)
{
	struct _G2AnimChanStatusBlock_Type *next; // size=36, offset=0 //  hashcode: 0x5C5FD595 (dec: 1549784469), parent name: '_G2AnimChanStatusBlock_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimChanStatus_Type chunks[8];  // size=32, offset=4 //  hashcode: 0x1D83554C (dec: 495146316), parent name: '_G2AnimChanStatusBlock_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimFxHeader_Type // hashcode: 0xA004B4ED (dec: -1610304275)
{
	unsigned char sizeAndSection; // size=0, offset=0 //  hashcode: 0xDD59A185 (dec: -581328507), parent name: '_G2AnimFxHeader_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	char type;					  // size=0, offset=1 //  hashcode: 0x00F2293B (dec: 15870267), parent name: '_G2AnimFxHeader_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short keyframeID;	// size=0, offset=2 //  hashcode: 0x5B00B5AA (dec: 1526773162), parent name: '_G2AnimFxHeader_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimKeylist_Type // hashcode: 0x87A15165 (dec: -2019471003)
{
	unsigned char sectionCount;			 // size=0, offset=0 //  hashcode: 0x5E5D1974 (dec: 1583159668), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char s0TailTime;			 // size=0, offset=1 //  hashcode: 0x5989B3F1 (dec: 1502196721), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char s1TailTime;			 // size=0, offset=2 //  hashcode: 0x21ED4B27 (dec: 569199399), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char s2TailTime;			 // size=0, offset=3 //  hashcode: 0xB8509689 (dec: -1202678135), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short keyCount;			 // size=0, offset=4 //  hashcode: 0x76D00229 (dec: 1993343529), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timePerKey;					 // size=0, offset=6 //  hashcode: 0xBC182987 (dec: -1139267193), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad00;				 // size=0, offset=8 //  hashcode: 0x2185428D (dec: 562381453), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad01;						 // size=0, offset=10 //  hashcode: 0x027658CB (dec: 41310411), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad10;				 // size=0, offset=12 //  hashcode: 0x6159986E (dec: 1633261678), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad11;						 // size=0, offset=14 //  hashcode: 0x6A65958A (dec: 1785042314), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimFxHeader_Type *fxList; // size=4, offset=16 //  hashcode: 0xC1F74E0C (dec: -1040757236), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short(*sectionData[0]);	 // size=0, offset=20 //  hashcode: 0xCD4909BC (dec: -850851396), parent name: '_G2AnimKeylist_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Model // hashcode: 0x9BCE1D24 (dec: -1680990940)
{
	long numVertices;				  // size=0, offset=0 //  hashcode: 0x9921215F (dec: -1725882017), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MVertex *vertexList;	  // size=8, offset=4 //  hashcode: 0x9FF4C9CC (dec: -1611347508), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numNormals;				  // size=0, offset=8 //  hashcode: 0xB84CACC2 (dec: -1202934590), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVectorNoPad *normalList; // size=6, offset=12 //  hashcode: 0xD0880622 (dec: -796391902), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numFaces;					  // size=0, offset=16 //  hashcode: 0x522BC4E3 (dec: 1378600163), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MFace *faceList;		  // size=12, offset=20 //  hashcode: 0x28E8B574 (dec: 686339444), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numSegments;				  // size=0, offset=24 //  hashcode: 0x63A67EB5 (dec: 1671855797), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Segment *segmentList;	 // size=24, offset=28 //  hashcode: 0x3EA68E82 (dec: 1051102850), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AniTex *aniTextures;		  // size=16, offset=32 //  hashcode: 0x38962AFC (dec: 949365500), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxRad;					  // size=0, offset=36 //  hashcode: 0xB96B9ACC (dec: -1184130356), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;						  // size=0, offset=38 //  hashcode: 0x0087EE79 (dec: 8908409), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxRadSq;					  // size=0, offset=40 //  hashcode: 0xE1F4BAFA (dec: -504055046), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *multiSpline;  // size=0, offset=44 //  hashcode: 0x17BA1509 (dec: 398071049), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct TextureMT3 *startTextures; // size=16, offset=48 //  hashcode: 0xF16A4447 (dec: -244693945), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct TextureMT3 *endTextures;   // size=16, offset=52 //  hashcode: 0x4F56DA2B (dec: 1331092011), parent name: '_Model', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VramSize // hashcode: 0xD96A55BF (dec: -647342657)
{
	short x; // size=0, offset=0 //  hashcode: 0x2CD17F07 (dec: 751927047), parent name: 'VramSize', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y; // size=0, offset=2 //  hashcode: 0xC9E6A47F (dec: -907631489), parent name: 'VramSize', parent hashcode: 0xFFFFFFFF (dec: -1)
	short w; // size=0, offset=4 //  hashcode: 0x7C86671F (dec: 2089183007), parent name: 'VramSize', parent hashcode: 0xFFFFFFFF (dec: -1)
	short h; // size=0, offset=6 //  hashcode: 0xD6FF3001 (dec: -687919103), parent name: 'VramSize', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct Object // hashcode: 0xEC12E9AC (dec: -334304852)
{
	long oflags;						   // size=0, offset=0 //  hashcode: 0xDA3627CB (dec: -633985077), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short id;							   // size=0, offset=4 //  hashcode: 0x59373C64 (dec: 1496792164), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sfxFileHandle;				   // size=0, offset=6 //  hashcode: 0x6C480C2C (dec: 1816661036), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numModels;					   // size=0, offset=8 //  hashcode: 0x9527F657 (dec: -1792543145), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numAnims;						   // size=0, offset=10 //  hashcode: 0x1D8EBDF4 (dec: 495894004), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Model **modelList;			   // size=56, offset=12 //  hashcode: 0x70631414 (dec: 1885541396), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimKeylist_Type **animList; // size=20, offset=16 //  hashcode: 0xA2158DDF (dec: -1575645729), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short introDist;					   // size=0, offset=20 //  hashcode: 0xB4B4CF74 (dec: -1263218828), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vvIntroDist;					   // size=0, offset=22 //  hashcode: 0x7778B825 (dec: 2004400165), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short removeDist;					   // size=0, offset=24 //  hashcode: 0xCCB7623F (dec: -860396993), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vvRemoveDist;					   // size=0, offset=26 //  hashcode: 0x17315AEB (dec: 389110507), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;							   // size=0, offset=28 //  hashcode: 0x4026883B (dec: 1076267067), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *script;						   // size=0, offset=32 //  hashcode: 0x543F7EE6 (dec: 1413447398), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *name;							   // size=0, offset=36 //  hashcode: 0xA37E2F44 (dec: -1552011452), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char *soundData;			   // size=0, offset=40 //  hashcode: 0xE70F395C (dec: -418432676), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	long oflags2;						   // size=0, offset=44 //  hashcode: 0x6283252E (dec: 1652761902), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sectionA;						   // size=0, offset=48 //  hashcode: 0x7B140262 (dec: 2064908898), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sectionB;						   // size=0, offset=50 //  hashcode: 0x96BC3E8B (dec: -1766048117), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sectionC;						   // size=0, offset=52 //  hashcode: 0xFD846DDC (dec: -41652772), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numberOfEffects;				   // size=0, offset=54 //  hashcode: 0x2E3D8DBC (dec: 775785916), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct ObjectEffect *effectList;	   // size=4, offset=56 //  hashcode: 0xDFF64033 (dec: -537509837), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long *relocList;			   // size=0, offset=60 //  hashcode: 0x58294F36 (dec: 1479102262), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *relocModule;					   // size=0, offset=64 //  hashcode: 0xC026F20D (dec: -1071189491), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct VramSize vramSize;			   // size=8, offset=68 //  hashcode: 0x31E46F0D (dec: 837054221), parent name: 'Object', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BVertex // hashcode: 0xADD3BD2F (dec: -1378632401)
{
	short x;   // size=0, offset=0 //  hashcode: 0xB6040E5B (dec: -1241248165), parent name: '_BVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;   // size=0, offset=2 //  hashcode: 0x01AEFFA3 (dec: 28245923), parent name: '_BVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;   // size=0, offset=4 //  hashcode: 0x74B349FF (dec: 1957906943), parent name: '_BVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad; // size=0, offset=6 //  hashcode: 0xCD0D01C3 (dec: -854785597), parent name: '_BVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BFace // hashcode: 0x69100F99 (dec: 1762660249)
{
	short v0;					// size=0, offset=0 //  hashcode: 0xBB1F9B80 (dec: -1155556480), parent name: '_BFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short v1;					// size=0, offset=2 //  hashcode: 0x5AEDB1C9 (dec: 1525526985), parent name: '_BFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short v2;					// size=0, offset=4 //  hashcode: 0x9CA5E9A9 (dec: -1666848343), parent name: '_BFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;					// size=0, offset=6 //  hashcode: 0x03FB21A7 (dec: 66789799), parent name: '_BFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct TextureFT3 *texture; // size=12, offset=8 //  hashcode: 0x75565B2D (dec: 1968593709), parent name: '_BFace', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BGObject // hashcode: 0xEC69FB30 (dec: -328598736)
{
	short flags;				 // size=0, offset=0 //  hashcode: 0xAD4DCD55 (dec: -1387410091), parent name: '_BGObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numFaces;				 // size=0, offset=2 //  hashcode: 0xF8DFCE4B (dec: -119550389), parent name: '_BGObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BVertex *vertexList; // size=8, offset=4 //  hashcode: 0x3A1CB45D (dec: 974959709), parent name: '_BGObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BFace *faceList;	 // size=12, offset=8 //  hashcode: 0x969F847D (dec: -1767930755), parent name: '_BGObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x;					 // size=0, offset=12 //  hashcode: 0x51D75797 (dec: 1373067159), parent name: '_BGObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;					 // size=0, offset=14 //  hashcode: 0x7ED407A3 (dec: 2127824803), parent name: '_BGObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;					 // size=0, offset=16 //  hashcode: 0xD18CDEC8 (dec: -779297080), parent name: '_BGObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short radius;				 // size=0, offset=18 //  hashcode: 0x420AA500 (dec: 1107993856), parent name: '_BGObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numVertices;			 // size=0, offset=20 //  hashcode: 0xD9D925D6 (dec: -640080426), parent name: '_BGObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct Signal // hashcode: 0xA0225F88 (dec: -1608360056)
{
	long id; // size=0, offset=0 //  hashcode: 0x6B9BBF4A (dec: 1805369162), parent name: 'Signal', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MultiSignal // hashcode: 0x0620B768 (dec: 102807400)
{
	long numSignals;			  // size=0, offset=0 //  hashcode: 0xF4A14626 (dec: -190757338), parent name: '_MultiSignal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short signalNum;			  // size=0, offset=4 //  hashcode: 0x5C48DC21 (dec: 1548278817), parent name: '_MultiSignal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;				  // size=0, offset=6 //  hashcode: 0xC0D461F2 (dec: -1059823118), parent name: '_MultiSignal', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal signalList[32]; // size=896, offset=8 //  hashcode: 0x362EB6D1 (dec: 909031121), parent name: '_MultiSignal', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _HFace // hashcode: 0x30CA5CA6 (dec: 818568358)
{
	short v0;			   // size=0, offset=0 //  hashcode: 0xFA36FB0F (dec: -97060081), parent name: '_HFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short v1;			   // size=0, offset=2 //  hashcode: 0x2D224B98 (dec: 757222296), parent name: '_HFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short v2;			   // size=0, offset=4 //  hashcode: 0xD93621E1 (dec: -650763807), parent name: '_HFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char attr;	// size=0, offset=6 //  hashcode: 0x472219A6 (dec: 1193417126), parent name: '_HFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	char pad;			   // size=0, offset=7 //  hashcode: 0xE55101B2 (dec: -447675982), parent name: '_HFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short normal; // size=0, offset=8 //  hashcode: 0xA9D1AED6 (dec: -1445876010), parent name: '_HFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short n0;	 // size=0, offset=10 //  hashcode: 0x779C9497 (dec: 2006750359), parent name: '_HFace', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _HSphere // hashcode: 0x8E7B7191 (dec: -1904512623)
{
	long attr;					 // size=0, offset=0 //  hashcode: 0xB0ACAEC1 (dec: -1330860351), parent name: '_HSphere', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char id;			 // size=0, offset=4 //  hashcode: 0x3636D2F7 (dec: 909562615), parent name: '_HSphere', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char rank;			 // size=0, offset=5 //  hashcode: 0x4B46C0C0 (dec: 1262928064), parent name: '_HSphere', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;					 // size=0, offset=6 //  hashcode: 0xE155D32D (dec: -514469075), parent name: '_HSphere', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position;   // size=6, offset=8 //  hashcode: 0xD4FA72E8 (dec: -721784088), parent name: '_HSphere', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short radius;		 // size=0, offset=14 //  hashcode: 0x93E3A271 (dec: -1813798287), parent name: '_HSphere', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long radiusSquared; // size=0, offset=16 //  hashcode: 0xDF9EB4BD (dec: -543247171), parent name: '_HSphere', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _HBox // hashcode: 0x47CD8BDA (dec: 1204653018)
{
	short flags;		// size=0, offset=0 //  hashcode: 0xEE9EA6D5 (dec: -291592491), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char id;   // size=0, offset=2 //  hashcode: 0xF5D49465 (dec: -170617755), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char rank; // size=0, offset=3 //  hashcode: 0xA2E924F3 (dec: -1561778957), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minX;			// size=0, offset=4 //  hashcode: 0xBCECC914 (dec: -1125332716), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minY;			// size=0, offset=6 //  hashcode: 0x3FC05179 (dec: 1069568377), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minZ;			// size=0, offset=8 //  hashcode: 0x3E30F2DE (dec: 1043395294), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxX;			// size=0, offset=10 //  hashcode: 0xAE66E2C3 (dec: -1368988989), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxY;			// size=0, offset=12 //  hashcode: 0x10C050B2 (dec: 281039026), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxZ;			// size=0, offset=14 //  hashcode: 0x47D12A07 (dec: 1204890119), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short refMinX;		// size=0, offset=16 //  hashcode: 0x2EE494F1 (dec: 786732273), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short refMinY;		// size=0, offset=18 //  hashcode: 0x09AFCC35 (dec: 162516021), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short refMinZ;		// size=0, offset=20 //  hashcode: 0x60F6AE5D (dec: 1626779229), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short refMaxX;		// size=0, offset=22 //  hashcode: 0xA173830B (dec: -1586265333), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short refMaxY;		// size=0, offset=24 //  hashcode: 0x0B08CF4F (dec: 185126735), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short refMaxZ;		// size=0, offset=26 //  hashcode: 0x593F988D (dec: 1497340045), parent name: '_HBox', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _HPrim // hashcode: 0x988F5E11 (dec: -1735434735)
{
	unsigned char hpFlags;   // size=0, offset=0 //  hashcode: 0xAB881355 (dec: -1417145515), parent name: '_HPrim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char withFlags; // size=0, offset=1 //  hashcode: 0xE18A5ABC (dec: -511026500), parent name: '_HPrim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;		 // size=0, offset=2 //  hashcode: 0xAE4E7EE7 (dec: -1370587417), parent name: '_HPrim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char segment;   // size=0, offset=3 //  hashcode: 0x47B85330 (dec: 1203262256), parent name: '_HPrim', parent hashcode: 0xFFFFFFFF (dec: -1)
	;						 // size=4, offset=4 //  hashcode: 0xF7F81D7D (dec: -134734467), parent name: '_HPrim', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _HModel // hashcode: 0xBC680356 (dec: -1134034090)
{
	struct _HPrim *hPrimList; // size=8, offset=0 //  hashcode: 0x9BF5B7F8 (dec: -1678395400), parent name: '_HModel', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numHPrims;			  // size=0, offset=4 //  hashcode: 0x058DBE2D (dec: 93175341), parent name: '_HModel', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _HInfo // hashcode: 0x6AC9807F (dec: 1791590527)
{
	long numHFaces;				  // size=0, offset=0 //  hashcode: 0x915BDB99 (dec: -1856250983), parent name: '_HInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HFace *hfaceList;	 // size=12, offset=4 //  hashcode: 0x52D8AD66 (dec: 1389931878), parent name: '_HInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numHSpheres;			  // size=0, offset=8 //  hashcode: 0xA035ABDE (dec: -1607095330), parent name: '_HInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HSphere *hsphereList; // size=20, offset=12 //  hashcode: 0xF7FF3A13 (dec: -134268397), parent name: '_HInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numHBoxes;				  // size=0, offset=16 //  hashcode: 0xE20B3D5D (dec: -502579875), parent name: '_HInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HBox *hboxList;		  // size=28, offset=20 //  hashcode: 0x6E61EEDA (dec: 1851911898), parent name: '_HInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Segment // hashcode: 0x2F06BF28 (dec: 788971304)
{
	long flags;			  // size=0, offset=0 //  hashcode: 0x31B05B61 (dec: 833641313), parent name: '_Segment', parent hashcode: 0xFFFFFFFF (dec: -1)
	short firstTri;		  // size=0, offset=4 //  hashcode: 0x2525E857 (dec: 623241303), parent name: '_Segment', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lastTri;		  // size=0, offset=6 //  hashcode: 0xA4768FE8 (dec: -1535733784), parent name: '_Segment', parent hashcode: 0xFFFFFFFF (dec: -1)
	short firstVertex;	// size=0, offset=8 //  hashcode: 0x8343A559 (dec: -2092718759), parent name: '_Segment', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lastVertex;	 // size=0, offset=10 //  hashcode: 0xB1F41DAC (dec: -1309401684), parent name: '_Segment', parent hashcode: 0xFFFFFFFF (dec: -1)
	short px;			  // size=0, offset=12 //  hashcode: 0x5430B013 (dec: 1412476947), parent name: '_Segment', parent hashcode: 0xFFFFFFFF (dec: -1)
	short py;			  // size=0, offset=14 //  hashcode: 0x2A80BDF3 (dec: 713080307), parent name: '_Segment', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pz;			  // size=0, offset=16 //  hashcode: 0x94F0BE47 (dec: -1796161977), parent name: '_Segment', parent hashcode: 0xFFFFFFFF (dec: -1)
	short parent;		  // size=0, offset=18 //  hashcode: 0x990CE600 (dec: -1727207936), parent name: '_Segment', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HInfo *hInfo; // size=24, offset=20 //  hashcode: 0x83DD51B5 (dec: -2082647627), parent name: '_Segment', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SplineDef // hashcode: 0x04DD5459 (dec: 81613913)
{
	short currkey;			  // size=0, offset=0 //  hashcode: 0x6FA7FC69 (dec: 1873280105), parent name: 'SplineDef', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short denomFlag; // size=0, offset=2 //  hashcode: 0x260F27CE (dec: 638527438), parent name: 'SplineDef', parent hashcode: 0xFFFFFFFF (dec: -1)
	long fracCurr;			  // size=0, offset=4 //  hashcode: 0x015C7A29 (dec: 22837801), parent name: 'SplineDef', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MultiSpline // hashcode: 0x2823B2CF (dec: 673428175)
{
	struct Spline *positional;		// size=8, offset=0 //  hashcode: 0xD111C04C (dec: -787365812), parent name: 'MultiSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RSpline *rotational;		// size=8, offset=4 //  hashcode: 0xACBF6077 (dec: -1396744073), parent name: 'MultiSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Spline *scaling;			// size=8, offset=8 //  hashcode: 0xB162004A (dec: -1318977462), parent name: 'MultiSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Spline *color;			// size=8, offset=12 //  hashcode: 0x7E26D337 (dec: 2116473655), parent name: 'MultiSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SplineDef curPositional; // size=8, offset=16 //  hashcode: 0xDA32CD3C (dec: -634204868), parent name: 'MultiSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SplineDef curRotational; // size=8, offset=24 //  hashcode: 0x90E53563 (dec: -1864026781), parent name: 'MultiSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SplineDef curScaling;	// size=8, offset=32 //  hashcode: 0x5497DB32 (dec: 1419238194), parent name: 'MultiSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SplineDef curColor;		// size=8, offset=40 //  hashcode: 0xD84C232E (dec: -666098898), parent name: 'MultiSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX curRotMatrix;		// size=32, offset=48 //  hashcode: 0x2DD49D2B (dec: 768908587), parent name: 'MultiSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ObjectEffect // hashcode: 0x2892438D (dec: 680674189)
{
	unsigned char effectNumber;	// size=0, offset=0 //  hashcode: 0x3175E9DA (dec: 829811162), parent name: 'ObjectEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char modifierList[3]; // size=3, offset=1 //  hashcode: 0xDA8EB51C (dec: -628181732), parent name: 'ObjectEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _TFace // hashcode: 0x85FE430F (dec: -2046934257)
{
	struct _Face face;		// size=6, offset=0 //  hashcode: 0xBC252B12 (dec: -1138414830), parent name: '_TFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char attr;		// size=0, offset=6 //  hashcode: 0xD33E54AE (dec: -750889810), parent name: '_TFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	char sortPush;			// size=0, offset=7 //  hashcode: 0x3C4C893F (dec: 1011648831), parent name: '_TFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short normal;  // size=0, offset=8 //  hashcode: 0x89B85E8D (dec: -1984405875), parent name: '_TFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short textoff; // size=0, offset=10 //  hashcode: 0xA1C778A0 (dec: -1580762976), parent name: '_TFace', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _TVertex // hashcode: 0x0883ABD5 (dec: 142846933)
{
	struct _Vertex vertex; // size=6, offset=0 //  hashcode: 0x5411C965 (dec: 1410451813), parent name: '_TVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short rgb15;  // size=0, offset=6 //  hashcode: 0x6A65F2DF (dec: 1785066207), parent name: '_TVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;	  // size=0, offset=8 //  hashcode: 0x89534380 (dec: -1991031936), parent name: '_TVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;	  // size=0, offset=9 //  hashcode: 0x55EB9CA8 (dec: 1441504424), parent name: '_TVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;	  // size=0, offset=10 //  hashcode: 0x419FCC84 (dec: 1100991620), parent name: '_TVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code;	// size=0, offset=11 //  hashcode: 0x081CD78E (dec: 136107918), parent name: '_TVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct Intro // hashcode: 0x796E766D (dec: 2037282413)
{
	char name[16];					   // size=16, offset=0 //  hashcode: 0xC2754532 (dec: -1032501966), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	long intronum;					   // size=0, offset=16 //  hashcode: 0xA96E7D71 (dec: -1452376719), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	long UniqueID;					   // size=0, offset=20 //  hashcode: 0x7B82EEBB (dec: 2072178363), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation;		   // size=8, offset=24 //  hashcode: 0x5F5A2464 (dec: 1599743076), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position;		   // size=6, offset=32 //  hashcode: 0x580491CB (dec: 1476694475), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxRad;					   // size=0, offset=38 //  hashcode: 0x007C5445 (dec: 8148037), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxRadSq;					   // size=0, offset=40 //  hashcode: 0x75B72979 (dec: 1974937977), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;						   // size=0, offset=44 //  hashcode: 0x8CFD65F2 (dec: -1929550350), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;						   // size=0, offset=48 //  hashcode: 0xF903CCE0 (dec: -117191456), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance;		   // size=616, offset=52 //  hashcode: 0xB1B1DF29 (dec: -1313743063), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *multiSpline;   // size=0, offset=56 //  hashcode: 0x07975918 (dec: 127359256), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *dsignal;					   // size=0, offset=60 //  hashcode: 0x91743A47 (dec: -1854653881), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	short specturalLightGroup;		   // size=0, offset=64 //  hashcode: 0x2D1DD0FE (dec: 756928766), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	short meshColor;				   // size=0, offset=66 //  hashcode: 0xA3A9A752 (dec: -1549162670), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position spectralPosition; // size=6, offset=68 //  hashcode: 0x6D5DB4B4 (dec: 1834857652), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
	short spad;						   // size=0, offset=74 //  hashcode: 0x292681F7 (dec: 690389495), parent name: 'Intro', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Terrain // hashcode: 0x5D541B4E (dec: 1565793102)
{
	short UnitChangeFlags;				 // size=0, offset=0 //  hashcode: 0x0B08990E (dec: 185112846), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	short spad;							 // size=0, offset=2 //  hashcode: 0x950AFF28 (dec: -1794441432), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	long lpad2;							 // size=0, offset=4 //  hashcode: 0xB4F2EDC0 (dec: -1259147840), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numIntros;						 // size=0, offset=8 //  hashcode: 0xCB1FC486 (dec: -887110522), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Intro *introList;			 // size=76, offset=12 //  hashcode: 0x70B2B76E (dec: 1890760558), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numVertices;					 // size=0, offset=16 //  hashcode: 0xBE68AD4D (dec: -1100436147), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numFaces;						 // size=0, offset=20 //  hashcode: 0x7A8DFBFF (dec: 2056125439), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numNormals;					 // size=0, offset=24 //  hashcode: 0x4BF4B848 (dec: 1274329160), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TVertex *vertexList;		 // size=12, offset=28 //  hashcode: 0x31755B3F (dec: 829774655), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *faceList;			 // size=12, offset=32 //  hashcode: 0xB57A4B90 (dec: -1250276464), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Normal *normalList;			 // size=8, offset=36 //  hashcode: 0x435B3ED6 (dec: 1130053334), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DrMoveAniTex *aniList;		 // size=8, offset=40 //  hashcode: 0xF9F89AB4 (dec: -101147980), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	long pad;							 // size=0, offset=44 //  hashcode: 0x2794AE3A (dec: 664055354), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *StreamUnits;					 // size=0, offset=48 //  hashcode: 0x86156EE7 (dec: -2045415705), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct TextureFT3 *StartTextureList; // size=12, offset=52 //  hashcode: 0xDFDA72D1 (dec: -539331887), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct TextureFT3 *EndTextureList;   // size=12, offset=56 //  hashcode: 0xA8C81A5C (dec: -1463281060), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MorphVertex *MorphDiffList;  // size=14, offset=60 //  hashcode: 0xEB791D80 (dec: -344384128), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MorphColor *MorphColorList;  // size=2, offset=64 //  hashcode: 0x43B6C45F (dec: 1136051295), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numBSPTrees;					 // size=0, offset=68 //  hashcode: 0xF1E1DFD1 (dec: -236855343), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct BSPTree *BSPTreeArray;		 // size=36, offset=72 //  hashcode: 0xBE28E1C4 (dec: -1104617020), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	short *morphNormalIdx;				 // size=0, offset=76 //  hashcode: 0xD7B3EF24 (dec: -676073692), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *signals;		 // size=904, offset=80 //  hashcode: 0x35619AA6 (dec: 895589030), parent name: '_Terrain', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _InstancePool // hashcode: 0xC591AB92 (dec: -980309102)
{
	long nextInstanceID;		   // size=0, offset=0 //  hashcode: 0x422FE033 (dec: 1110433843), parent name: '_InstancePool', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numFreeInstances;		   // size=0, offset=4 //  hashcode: 0x0FA0249B (dec: 262153371), parent name: '_InstancePool', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance instance[62]; // size=38192, offset=8 //  hashcode: 0xE86D66D3 (dec: -395483437), parent name: '_InstancePool', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *first_free;  // size=616, offset=38200 //  hashcode: 0x1B13C44F (dec: 454280271), parent name: '_InstancePool', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _InstanceList // hashcode: 0x7594B1C7 (dec: 1972679111)
{
	long numInstances;			// size=0, offset=0 //  hashcode: 0x21FD3B1F (dec: 570243871), parent name: '_InstanceList', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *first;	// size=616, offset=4 //  hashcode: 0x20982907 (dec: 546842887), parent name: '_InstanceList', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _InstancePool *pool; // size=38204, offset=8 //  hashcode: 0x8C8C76FB (dec: -1936951557), parent name: '_InstanceList', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType group[32];  // size=256, offset=12 //  hashcode: 0x52503FB5 (dec: 1380990901), parent name: '_InstanceList', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _ObjectTracker // hashcode: 0xFE4678BF (dec: -28936001)
{
	char name[16];		   // size=16, offset=0 //  hashcode: 0xDA8A6108 (dec: -628465400), parent name: '_ObjectTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=76, offset=16 //  hashcode: 0x31DF6E1A (dec: 836726298), parent name: '_ObjectTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short objectStatus;	// size=0, offset=20 //  hashcode: 0x9355A5CE (dec: -1823103538), parent name: '_ObjectTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numInUse;		   // size=0, offset=22 //  hashcode: 0xEF2F7994 (dec: -282101356), parent name: '_ObjectTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *vramBlock;	   // size=0, offset=24 //  hashcode: 0xD2986C96 (dec: -761762666), parent name: '_ObjectTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numObjectsUsing;  // size=0, offset=28 //  hashcode: 0xBB715EF1 (dec: -1150198031), parent name: '_ObjectTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char objectsUsing[7];  // size=7, offset=29 //  hashcode: 0x6DA2B8E6 (dec: 1839380710), parent name: '_ObjectTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BoundingBox // hashcode: 0x2183782B (dec: 562264107)
{
	short minX; // size=0, offset=0 //  hashcode: 0x10EFDC3C (dec: 284154940), parent name: '_BoundingBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minY; // size=0, offset=2 //  hashcode: 0xCD05DC81 (dec: -855253887), parent name: '_BoundingBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minZ; // size=0, offset=4 //  hashcode: 0xE20BE7A6 (dec: -502536282), parent name: '_BoundingBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxX; // size=0, offset=6 //  hashcode: 0xE90F98F4 (dec: -384853772), parent name: '_BoundingBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxY; // size=0, offset=8 //  hashcode: 0x79938292 (dec: 2039710354), parent name: '_BoundingBox', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxZ; // size=0, offset=10 //  hashcode: 0xB6C99CB2 (dec: -1228301134), parent name: '_BoundingBox', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CDLight // hashcode: 0xD90757B8 (dec: -653830216)
{
	struct NodeType node;  // size=8, offset=0 //  hashcode: 0xCE1EB76E (dec: -836847762), parent name: 'CDLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r;	   // size=0, offset=8 //  hashcode: 0xD6DF80B9 (dec: -689995591), parent name: 'CDLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;	   // size=0, offset=9 //  hashcode: 0x00FF516E (dec: 16732526), parent name: 'CDLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;	   // size=0, offset=10 //  hashcode: 0xEA975FB7 (dec: -359178313), parent name: 'CDLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;   // size=0, offset=11 //  hashcode: 0x9C721215 (dec: -1670245867), parent name: 'CDLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Sphere sphere; // size=12, offset=12 //  hashcode: 0x54A5342D (dec: 1420112941), parent name: 'CDLight', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BSPNode // hashcode: 0x60C20F69 (dec: 1623330665)
{
	struct _Sphere_noSq sphere;			// size=8, offset=0 //  hashcode: 0xBAC2A12B (dec: -1161649877), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	short a;							// size=0, offset=8 //  hashcode: 0xF3C59F98 (dec: -205152360), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	short b;							// size=0, offset=10 //  hashcode: 0xA2D863BE (dec: -1562876994), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	short c;							// size=0, offset=12 //  hashcode: 0x9FBB8919 (dec: -1615099623), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;						// size=0, offset=14 //  hashcode: 0x6808269B (dec: 1745364635), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	long d;								// size=0, offset=16 //  hashcode: 0x365C5DBE (dec: 912022974), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *front;						// size=0, offset=20 //  hashcode: 0x481B194F (dec: 1209735503), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *back;							// size=0, offset=24 //  hashcode: 0x7DB3B4E7 (dec: 2108929255), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Sphere_noSq spectralSphere; // size=8, offset=28 //  hashcode: 0x07390564 (dec: 121177444), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	short front_spectral_error;			// size=0, offset=36 //  hashcode: 0xD7F8AF74 (dec: -671568012), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	short back_spectral_error;			// size=0, offset=38 //  hashcode: 0x5A7B2876 (dec: 1518020726), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	short front_material_error;			// size=0, offset=40 //  hashcode: 0x30A887E7 (dec: 816351207), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	short back_material_error;			// size=0, offset=42 //  hashcode: 0x31DBBFDB (dec: 836485083), parent name: '_BSPNode', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BSPLeaf // hashcode: 0xB2C1AC71 (dec: -1295930255)
{
	struct _Sphere_noSq sphere;			// size=8, offset=0 //  hashcode: 0x3010FA6B (dec: 806419051), parent name: '_BSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *faceList;			// size=12, offset=8 //  hashcode: 0xEE63CD00 (dec: -295449344), parent name: '_BSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numFaces;						// size=0, offset=12 //  hashcode: 0xD5419252 (dec: -717122990), parent name: '_BSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;						// size=0, offset=14 //  hashcode: 0xB8183EC0 (dec: -1206370624), parent name: '_BSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BoundingBox box;			// size=12, offset=16 //  hashcode: 0x6CEF6C69 (dec: 1827630185), parent name: '_BSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BoundingBox spectralBox;	// size=12, offset=28 //  hashcode: 0xD6142920 (dec: -703321824), parent name: '_BSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Sphere_noSq spectralSphere; // size=8, offset=40 //  hashcode: 0xCFE97895 (dec: -806782827), parent name: '_BSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MorphVertex // hashcode: 0xAAB8DABE (dec: -1430725954)
{
	short x;	  // size=0, offset=0 //  hashcode: 0x238413F3 (dec: 595858419), parent name: '_MorphVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	  // size=0, offset=2 //  hashcode: 0xCF4775EF (dec: -817400337), parent name: '_MorphVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;	  // size=0, offset=4 //  hashcode: 0xE320E1CB (dec: -484384309), parent name: '_MorphVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vindex; // size=0, offset=6 //  hashcode: 0xEC131B3E (dec: -334292162), parent name: '_MorphVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short hx;	 // size=0, offset=8 //  hashcode: 0xA8EBCA8F (dec: -1460942193), parent name: '_MorphVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short hy;	 // size=0, offset=10 //  hashcode: 0xF284CD2F (dec: -226177745), parent name: '_MorphVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short hz;	 // size=0, offset=12 //  hashcode: 0x912B81F3 (dec: -1859419661), parent name: '_MorphVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MorphColor // hashcode: 0xA6BA0326 (dec: -1497758938)
{
	short morphColor15; // size=0, offset=0 //  hashcode: 0x785DA197 (dec: 2019402135), parent name: '_MorphColor', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TClassAttr // hashcode: 0x4DC02369 (dec: 1304437609)
{
	short flags;		  // size=0, offset=0 //  hashcode: 0x96D0AA12 (dec: -1764709870), parent name: 'TClassAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short sound; // size=0, offset=2 //  hashcode: 0xE1AEBF5E (dec: -508641442), parent name: 'TClassAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct Level // hashcode: 0x012B0198 (dec: 19595672)
{
	struct _Terrain *terrain;						 // size=84, offset=0 //  hashcode: 0x20D0F548 (dec: 550565192), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LightList *lightList;					 // size=12, offset=4 //  hashcode: 0x73C27F07 (dec: 1942126343), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numVMObjects;								 // size=0, offset=8 //  hashcode: 0x8BFE056C (dec: -1946286740), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _VMObject *vmobjectList;					 // size=60, offset=12 //  hashcode: 0xD6CF9197 (dec: -691039849), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numSpotLights;								 // size=0, offset=16 //  hashcode: 0x0A4A64C2 (dec: 172647618), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SpotLight *spotLightList;				 // size=40, offset=20 //  hashcode: 0x4D9B61A1 (dec: 1302028705), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numPointLights;							 // size=0, offset=24 //  hashcode: 0xDFF8F236 (dec: -537333194), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PointLight *pointLightList;				 // size=24, offset=28 //  hashcode: 0xAD7AC183 (dec: -1384463997), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numSpotSpecturalLights;					 // size=0, offset=32 //  hashcode: 0xF6D5857C (dec: -153778820), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SpotLight *spotSpecturalLightList;		 // size=40, offset=36 //  hashcode: 0x0E8B661D (dec: 244016669), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numPointSpecturalLights;					 // size=0, offset=40 //  hashcode: 0x79F5BC8A (dec: 2046147722), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PointLight *pointSpecturalLightList;		 // size=24, offset=44 //  hashcode: 0xBA3A3ED1 (dec: -1170587951), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numBGObjects;								 // size=0, offset=48 //  hashcode: 0x1551FC7F (dec: 357694591), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BGObject *bgObjectList;					 // size=24, offset=52 //  hashcode: 0xDCFD4D2A (dec: -587379414), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long waterZLevel;								 // size=0, offset=56 //  hashcode: 0x3E96367F (dec: 1050031743), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char backColorR;						 // size=0, offset=60 //  hashcode: 0x9DEFAA09 (dec: -1645237751), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char backColorG;						 // size=0, offset=61 //  hashcode: 0x47DE997D (dec: 1205770621), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char backColorB;						 // size=0, offset=62 //  hashcode: 0x671D6186 (dec: 1729978758), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char cpad1;							 // size=0, offset=63 //  hashcode: 0x8D5F8636 (dec: -1923119562), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char specturalColorR;					 // size=0, offset=64 //  hashcode: 0xE9BAB588 (dec: -373639800), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char specturalColorG;					 // size=0, offset=65 //  hashcode: 0x55EF1D0F (dec: 1441733903), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char specturalColorB;					 // size=0, offset=66 //  hashcode: 0x7588A244 (dec: 1971888708), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char cpad2;							 // size=0, offset=67 //  hashcode: 0xA17E2B36 (dec: -1585566922), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short fogFar;							 // size=0, offset=68 //  hashcode: 0x8793FC5D (dec: -2020344739), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short fogNear;							 // size=0, offset=70 //  hashcode: 0xA1C2D875 (dec: -1581066123), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short spectralFogFar;					 // size=0, offset=72 //  hashcode: 0x0353B049 (dec: 55816265), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short spectralFogNear;					 // size=0, offset=74 //  hashcode: 0xFBBB881A (dec: -71596006), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short waterFogFar;						 // size=0, offset=76 //  hashcode: 0xB109F8C1 (dec: -1324746559), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short waterFogNear;					 // size=0, offset=78 //  hashcode: 0x74E84A76 (dec: 1961380470), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long depthQBlendStart;							 // size=0, offset=80 //  hashcode: 0x5F9ACD11 (dec: 1603980561), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LightList *spectrallightList;			 // size=12, offset=84 //  hashcode: 0xDFEC81F3 (dec: -538148365), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numCameras;								 // size=0, offset=88 //  hashcode: 0xEC398DC4 (dec: -331772476), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *cameraList;								 // size=0, offset=92 //  hashcode: 0x4AB9BAE1 (dec: 1253685985), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long bspPlaneError;								 // size=0, offset=96 //  hashcode: 0xFA877C1D (dec: -91784163), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numVGroups;								 // size=0, offset=100 //  hashcode: 0xBC44B950 (dec: -1136346800), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _VGroup *vGroupList;						 // size=12, offset=104 //  hashcode: 0xB60A3BB4 (dec: -1240843340), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long deathZ;									 // size=0, offset=108 //  hashcode: 0x0963F7A5 (dec: 157546405), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;										 // size=0, offset=112 //  hashcode: 0xB584207B (dec: -1249632133), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *startSignal;				 // size=904, offset=116 //  hashcode: 0xF4A00A8A (dec: -190838134), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numIntros;									 // size=0, offset=120 //  hashcode: 0x5ED2BA04 (dec: 1590868484), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Intro *introList;						 // size=76, offset=124 //  hashcode: 0xD52388D0 (dec: -719091504), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DrMoveAniTex *bgAniList;					 // size=8, offset=128 //  hashcode: 0xF725CCB6 (dec: -148517706), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numHotSpots;								 // size=0, offset=132 //  hashcode: 0x351C612B (dec: 891052331), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HotSpot *hotSpotList;					 // size=8, offset=136 //  hashcode: 0xB3DC79E1 (dec: -1277396511), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *objectNameList;							 // size=0, offset=140 //  hashcode: 0xE1DB60FB (dec: -505716485), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long depthQFogStart;							 // size=0, offset=144 //  hashcode: 0x9AE3D729 (dec: -1696344279), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long morphLastStep;								 // size=0, offset=148 //  hashcode: 0xC35D3CD9 (dec: -1017299751), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *worldName;								 // size=0, offset=152 //  hashcode: 0xAD0BF68A (dec: -1391724918), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct VramSize vramSize;						 // size=8, offset=156 //  hashcode: 0x553894F9 (dec: 1429771513), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short holdFogFar;						 // size=0, offset=164 //  hashcode: 0x7F4E96CD (dec: 2135856845), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short holdFogNear;						 // size=0, offset=166 //  hashcode: 0x0D70999D (dec: 225483165), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numberEnemyUnits;							 // size=0, offset=168 //  hashcode: 0xAD4D69E8 (dec: -1387435544), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	char **enemyUnitsNames;							 // size=0, offset=172 //  hashcode: 0xFB96904A (dec: -74018742), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long **timesSignalList;							 // size=0, offset=176 //  hashcode: 0x4C9BCBCD (dec: 1285278669), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *spectralSignal;			 // size=904, offset=180 //  hashcode: 0xE709EBB5 (dec: -418780235), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *materialSignal;			 // size=904, offset=184 //  hashcode: 0x6FFEC2D2 (dec: 1878966994), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *startUnitLoadedSignal;		 // size=904, offset=188 //  hashcode: 0x8A5ACFB8 (dec: -1973760072), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *startUnitMainSignal;		 // size=904, offset=192 //  hashcode: 0xA9E87DAA (dec: -1444381270), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *startGoingIntoWaterSignal;  // size=904, offset=196 //  hashcode: 0x31016BBF (dec: 822176703), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *startGoingOutOfWaterSignal; // size=904, offset=200 //  hashcode: 0x37077710 (dec: 923236112), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long unitFlags;									 // size=0, offset=204 //  hashcode: 0x9081B794 (dec: -1870547052), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *SignalListStart;			 // size=904, offset=208 //  hashcode: 0xD3EC85DC (dec: -739473956), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MultiSignal *SignalListEnd;				 // size=904, offset=212 //  hashcode: 0xF9B37150 (dec: -105680560), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numBSPLeaves;								 // size=0, offset=216 //  hashcode: 0x9E876AA6 (dec: -1635292506), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct EventPointers *PuzzleInstances;			 // size=0, offset=220 //  hashcode: 0xAC11F995 (dec: -1408108139), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long NumberOfPlanMarkers;						 // size=0, offset=224 //  hashcode: 0x3539FD2D (dec: 892992813), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _PlanMkr *PlanMarkerList;				 // size=8, offset=228 //  hashcode: 0x7D8D32C8 (dec: 2106405576), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long NumberOfSFXMarkers;						 // size=0, offset=232 //  hashcode: 0x12E7384B (dec: 317143115), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SFXMkr *SFXMarkerList;					 // size=36, offset=236 //  hashcode: 0x6131D268 (dec: 1630655080), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long versionNumber;					 // size=0, offset=240 //  hashcode: 0x1CD00287 (dec: 483394183), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *dynamicMusicName;							 // size=0, offset=244 //  hashcode: 0xA636B923 (dec: -1506363101), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamUnitID;								 // size=0, offset=248 //  hashcode: 0x46B8847E (dec: 1186497662), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct TClassAttr tClassAttr[16];				 // size=64, offset=252 //  hashcode: 0x5BB2A8AA (dec: 1538435242), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	short TODLighting[4][3];						 // size=24, offset=316 //  hashcode: 0xE0A3FF49 (dec: -526123191), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char TODbackColor[4][3];				 // size=12, offset=340 //  hashcode: 0x81BD54B6 (dec: -2118298442), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short TODfogNearFar[4][2];				 // size=16, offset=352 //  hashcode: 0xFFDEF18D (dec: -2166387), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	short TODRedScale;								 // size=0, offset=368 //  hashcode: 0xB8579D52 (dec: -1202217646), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	short TODGrnScale;								 // size=0, offset=370 //  hashcode: 0x7FBA8576 (dec: 2142930294), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	short TODBluScale;								 // size=0, offset=372 //  hashcode: 0x813C1AB7 (dec: -2126767433), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	short TODfogNear;								 // size=0, offset=374 //  hashcode: 0x84575141 (dec: -2074652351), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	short TODfogFar;								 // size=0, offset=376 //  hashcode: 0x1340DAC3 (dec: 323017411), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	short short_pad;								 // size=0, offset=378 //  hashcode: 0x38F60ACD (dec: 955648717), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char TODbackColorR;					 // size=0, offset=380 //  hashcode: 0x666BE11F (dec: 1718346015), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char TODbackColorG;					 // size=0, offset=381 //  hashcode: 0x79B8B09D (dec: 2042146973), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char TODbackColorB;					 // size=0, offset=382 //  hashcode: 0x18DFFC08 (dec: 417332232), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char cpad3;							 // size=0, offset=383 //  hashcode: 0x4F399C1C (dec: 1329175580), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LightGroup *razielLightGroup;			 // size=64, offset=384 //  hashcode: 0x4591579D (dec: 1167153053), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LightGroup *razielSpectralLightGroup;	 // size=64, offset=388 //  hashcode: 0xDBFDF20A (dec: -604114422), parent name: 'Level', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _SavedCinematic // hashcode: 0x1E29151B (dec: 506008859)
{
	struct _Position position;			  // size=6, offset=0 //  hashcode: 0x73B9AD10 (dec: 1941548304), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position focusPoint;		  // size=6, offset=6 //  hashcode: 0xB7AD97A7 (dec: -1213360217), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position base;				  // size=6, offset=12 //  hashcode: 0xC8422881 (dec: -935188351), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position targetPos;			  // size=6, offset=18 //  hashcode: 0x4164D05D (dec: 1097125981), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position targetFocusPoint;	// size=6, offset=24 //  hashcode: 0xD276C055 (dec: -763969451), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position targetBase;		  // size=6, offset=30 //  hashcode: 0xD334350D (dec: -751553267), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation baseRot;			  // size=8, offset=36 //  hashcode: 0x1B65F18B (dec: 459665803), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation focusRotation;		  // size=8, offset=44 //  hashcode: 0x6823EBE7 (dec: 1747184615), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation targetFocusRotation; // size=8, offset=52 //  hashcode: 0x0310EEE0 (dec: 51441376), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	short focusDistance;				  // size=0, offset=60 //  hashcode: 0xF609D123 (dec: -167128797), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	short targetFocusDistance;			  // size=0, offset=62 //  hashcode: 0x7A099078 (dec: 2047447160), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector focusPointVel;		  // size=8, offset=64 //  hashcode: 0x6207E444 (dec: 1644684356), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector focusPointAccl;		  // size=8, offset=72 //  hashcode: 0x72615266 (dec: 1918980710), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector baseVel;			  // size=8, offset=80 //  hashcode: 0x63F93494 (dec: 1677276308), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector baseAccl;			  // size=8, offset=88 //  hashcode: 0xE37A8BE9 (dec: -478508055), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxVel;						  // size=0, offset=96 //  hashcode: 0x1DB96136 (dec: 498688310), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *posSpline;		  // size=0, offset=100 //  hashcode: 0x721B558C (dec: 1914393996), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline;	 // size=0, offset=104 //  hashcode: 0x7B10388D (dec: 2064660621), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Level *level;				  // size=0, offset=108 //  hashcode: 0x8D5ACA7B (dec: -1923429765), parent name: '_SavedCinematic', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSPTree // hashcode: 0x17800192 (dec: 394264978)
{
	struct _BSPNode *bspRoot;		  // size=44, offset=0 //  hashcode: 0xA143BC7A (dec: -1589396358), parent name: 'BSPTree', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BSPLeaf *startLeaves;	 // size=48, offset=4 //  hashcode: 0x3B4AFA26 (dec: 994769446), parent name: 'BSPTree', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BSPLeaf *endLeaves;		  // size=48, offset=8 //  hashcode: 0x16C6CE8D (dec: 382127757), parent name: 'BSPTree', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position globalOffset;	// size=6, offset=12 //  hashcode: 0xFCAA6A3E (dec: -55940546), parent name: 'BSPTree', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;					  // size=0, offset=18 //  hashcode: 0x2BE6C8EF (dec: 736545007), parent name: 'BSPTree', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position localOffset;	 // size=6, offset=20 //  hashcode: 0x3DCFF4CF (dec: 1037038799), parent name: 'BSPTree', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ID;						  // size=0, offset=26 //  hashcode: 0xCA22BB51 (dec: -903693487), parent name: 'BSPTree', parent hashcode: 0xFFFFFFFF (dec: -1)
	long splineID;					  // size=0, offset=28 //  hashcode: 0x6E9A6CB1 (dec: 1855614129), parent name: 'BSPTree', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instanceSpline; // size=616, offset=32 //  hashcode: 0xFECE5A33 (dec: -20030925), parent name: 'BSPTree', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LightGroup // hashcode: 0xBB5FF847 (dec: -1151338425)
{
	struct MATRIX lightMatrix; // size=32, offset=0 //  hashcode: 0x13930C8D (dec: 328404109), parent name: 'LightGroup', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX colorMatrix; // size=32, offset=32 //  hashcode: 0xF798E7DA (dec: -140974118), parent name: 'LightGroup', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LightList // hashcode: 0xC8448BB7 (dec: -935031881)
{
	struct CVECTOR ambient;			   // size=4, offset=0 //  hashcode: 0x8F106EC3 (dec: -1894748477), parent name: 'LightList', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numLightGroups;			   // size=0, offset=4 //  hashcode: 0x08D77FC0 (dec: 148340672), parent name: 'LightList', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LightGroup *lightGroupList; // size=64, offset=8 //  hashcode: 0x59BD23DD (dec: 1505567709), parent name: 'LightList', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PointLight // hashcode: 0xFEFDD2F2 (dec: -16919822)
{
	struct NodeType node;	  // size=8, offset=0 //  hashcode: 0xD7310D4F (dec: -684651185), parent name: 'PointLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r;		   // size=0, offset=8 //  hashcode: 0x72F36FB8 (dec: 1928556472), parent name: 'PointLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;		   // size=0, offset=9 //  hashcode: 0xD8A2C658 (dec: -660421032), parent name: 'PointLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;		   // size=0, offset=10 //  hashcode: 0x84A26CC4 (dec: -2069730108), parent name: 'PointLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;	   // size=0, offset=11 //  hashcode: 0x637E399B (dec: 1669216667), parent name: 'PointLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position; // size=6, offset=12 //  hashcode: 0x2C8CCB48 (dec: 747424584), parent name: 'PointLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	short radius;			   // size=0, offset=18 //  hashcode: 0xBF963819 (dec: -1080674279), parent name: 'PointLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	long radiusSquared;		   // size=0, offset=20 //  hashcode: 0xAFEA42E7 (dec: -1343601945), parent name: 'PointLight', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SpotLight // hashcode: 0xEF8B4C2E (dec: -276083666)
{
	struct NodeType node;		// size=8, offset=0 //  hashcode: 0x23129B83 (dec: 588422019), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r;			// size=0, offset=8 //  hashcode: 0x684970CA (dec: 1749643466), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;			// size=0, offset=9 //  hashcode: 0x7C4D73BD (dec: 2085450685), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;			// size=0, offset=10 //  hashcode: 0x42818A1D (dec: 1115785757), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;		// size=0, offset=11 //  hashcode: 0xC1456019 (dec: -1052418023), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position centroid;  // size=6, offset=12 //  hashcode: 0xB76C7E5B (dec: -1217626533), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	short radius;				// size=0, offset=18 //  hashcode: 0x2B82412D (dec: 729956653), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	long radiusSquared;			// size=0, offset=20 //  hashcode: 0xA24F0B01 (dec: -1571878143), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position;  // size=6, offset=24 //  hashcode: 0xCE23C8B1 (dec: -836515663), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position direction; // size=6, offset=30 //  hashcode: 0xBE36806C (dec: -1103724436), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cosFalloffAngle;		// size=0, offset=36 //  hashcode: 0xDBC14BA3 (dec: -608089181), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	short attenuationScale;		// size=0, offset=38 //  hashcode: 0xEE480CD1 (dec: -297268015), parent name: 'SpotLight', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LightInfo // hashcode: 0x2A95530E (dec: 714429198)
{
	long numPointLights;				  // size=0, offset=0 //  hashcode: 0xDC1B4D6B (dec: -602190485), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PointLight pointLightPool[32]; // size=768, offset=4 //  hashcode: 0xEF8899CD (dec: -276260403), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType usedPointLightList;   // size=8, offset=772 //  hashcode: 0x019A44AE (dec: 26887342), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType freePointLightList;   // size=8, offset=780 //  hashcode: 0x458B8326 (dec: 1166770982), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType activePointLightList; // size=8, offset=788 //  hashcode: 0xECB0B5A0 (dec: -323963488), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numSpotLights;					  // size=0, offset=796 //  hashcode: 0xD0D8B487 (dec: -791104377), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SpotLight spotLightPool[8];	// size=320, offset=800 //  hashcode: 0x3AD66BE1 (dec: 987130849), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType usedSpotLightList;	// size=8, offset=1120 //  hashcode: 0xE84038B0 (dec: -398444368), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType freeSpotLightList;	// size=8, offset=1128 //  hashcode: 0xD967C6DE (dec: -647510306), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType activeSpotLightList;  // size=8, offset=1136 //  hashcode: 0x88D898DC (dec: -1999071012), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numSavedColors;				  // size=0, offset=1144 //  hashcode: 0xB805D728 (dec: -1207576792), parent name: 'LightInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _VMOffset // hashcode: 0x680AC445 (dec: 1745536069)
{
	short dx; // size=0, offset=0 //  hashcode: 0x5505881F (dec: 1426425887), parent name: '_VMOffset', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dy; // size=0, offset=2 //  hashcode: 0xE6A62D1E (dec: -425317090), parent name: '_VMOffset', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dz; // size=0, offset=4 //  hashcode: 0x58057201 (dec: 1476751873), parent name: '_VMOffset', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _VMColorOffset // hashcode: 0xFD3FB530 (dec: -46156496)
{
	char dr; // size=0, offset=0 //  hashcode: 0xDFD0113A (dec: -540012230), parent name: '_VMColorOffset', parent hashcode: 0xFFFFFFFF (dec: -1)
	char dg; // size=0, offset=1 //  hashcode: 0x8D92E713 (dec: -1919752429), parent name: '_VMColorOffset', parent hashcode: 0xFFFFFFFF (dec: -1)
	char db; // size=0, offset=2 //  hashcode: 0xDE4E850E (dec: -565279474), parent name: '_VMColorOffset', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _VMInterpolated // hashcode: 0x3A40B5C0 (dec: 977319360)
{
	short tvIdx;	// size=0, offset=0 //  hashcode: 0x35437F10 (dec: 893615888), parent name: '_VMInterpolated', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startIdx; // size=0, offset=2 //  hashcode: 0x6C5D1F98 (dec: 1818042264), parent name: '_VMInterpolated', parent hashcode: 0xFFFFFFFF (dec: -1)
	short endIdx;   // size=0, offset=4 //  hashcode: 0x994C86FA (dec: -1723037958), parent name: '_VMInterpolated', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;		// size=0, offset=6 //  hashcode: 0xA3F349E3 (dec: -1544336925), parent name: '_VMInterpolated', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _VMOffsetTable // hashcode: 0xE4A13881 (dec: -459196287)
{
	long numVMOffsets; // size=0, offset=0 //  hashcode: 0xDB72177E (dec: -613279874), parent name: '_VMOffsetTable', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _VMObject // hashcode: 0x436E75EB (dec: 1131312619)
{
	unsigned short flags;						// size=0, offset=0 //  hashcode: 0xB184C3C4 (dec: -1316699196), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short bspIdx;								// size=0, offset=2 //  hashcode: 0x4669C93F (dec: 1181337919), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short materialIdx;							// size=0, offset=4 //  hashcode: 0x96DC66D9 (dec: -1763940647), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short spectralIdx;							// size=0, offset=6 //  hashcode: 0x7082EF29 (dec: 1887629097), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short currentIdx;							// size=0, offset=8 //  hashcode: 0xA76916F3 (dec: -1486285069), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeScale;							// size=0, offset=10 //  hashcode: 0xC88B2745 (dec: -930404539), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;									// size=0, offset=12 //  hashcode: 0x570A83D5 (dec: 1460306901), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position;					// size=6, offset=16 //  hashcode: 0x5C194B47 (dec: 1545161543), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short radius;								// size=0, offset=22 //  hashcode: 0xBB5F2233 (dec: -1151393229), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long radiusSquared;							// size=0, offset=24 //  hashcode: 0x27D209EB (dec: 668076523), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numVMOffsetTables;						// size=0, offset=28 //  hashcode: 0xA4BC0D5F (dec: -1531179681), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _VMOffsetTable **vmoffsetTableList;  // size=12, offset=32 //  hashcode: 0xB6341789 (dec: -1238100087), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _VMOffsetTable *curVMOffsetTable;	// size=12, offset=36 //  hashcode: 0xABCA43BA (dec: -1412807750), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numVMVertices;							// size=0, offset=40 //  hashcode: 0xDF2CC9C1 (dec: -550712895), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *vmvertexList;							// size=0, offset=44 //  hashcode: 0x8971902B (dec: -1989046229), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numVMInterpolated;						// size=0, offset=48 //  hashcode: 0xC1422E3D (dec: -1052627395), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _VMInterpolated *vminterpolatedList; // size=8, offset=52 //  hashcode: 0xD2BE065F (dec: -759298465), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *name;									// size=0, offset=56 //  hashcode: 0x27312B41 (dec: 657533761), parent name: '_VMObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _VGroup // hashcode: 0x4421FB39 (dec: 1143077689)
{
	long id;					  // size=0, offset=0 //  hashcode: 0x5699E95F (dec: 1452927327), parent name: '_VGroup', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numVertices;			  // size=0, offset=4 //  hashcode: 0xF2F62F3B (dec: -218747077), parent name: '_VGroup', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TVertex **vertexList; // size=12, offset=8 //  hashcode: 0x6BCA02A7 (dec: 1808401063), parent name: '_VGroup', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _HotSpot // hashcode: 0x6EC4F776 (dec: 1858402166)
{
	short x;  // size=0, offset=0 //  hashcode: 0x201A4C22 (dec: 538594338), parent name: '_HotSpot', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;  // size=0, offset=2 //  hashcode: 0x896CC5A0 (dec: -1989360224), parent name: '_HotSpot', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;  // size=0, offset=4 //  hashcode: 0x3B2B945D (dec: 992711773), parent name: '_HotSpot', parent hashcode: 0xFFFFFFFF (dec: -1)
	short id; // size=0, offset=6 //  hashcode: 0x7172621E (dec: 1903321630), parent name: '_HotSpot', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _PlanMkr // hashcode: 0xBC0DD043 (dec: -1139945405)
{
	struct _Position pos; // size=6, offset=0 //  hashcode: 0x66433A5B (dec: 1715681883), parent name: '_PlanMkr', parent hashcode: 0xFFFFFFFF (dec: -1)
	short id;			  // size=0, offset=6 //  hashcode: 0x27F924A6 (dec: 670639270), parent name: '_PlanMkr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _SFXMkr // hashcode: 0x74BB4848 (dec: 1958430792)
{
	unsigned char *soundData;		// size=0, offset=0 //  hashcode: 0xE6DD4FA6 (dec: -421703770), parent name: '_SFXMkr', parent hashcode: 0xFFFFFFFF (dec: -1)
	long uniqueID;					// size=0, offset=4 //  hashcode: 0x80069EB9 (dec: -2147049799), parent name: '_SFXMkr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SoundInstance sfxTbl[4]; // size=12, offset=8 //  hashcode: 0x58EAFA43 (dec: 1491794499), parent name: '_SFXMkr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position pos;			// size=6, offset=20 //  hashcode: 0x98E94F3D (dec: -1729540291), parent name: '_SFXMkr', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;						// size=0, offset=26 //  hashcode: 0xADB9F7C6 (dec: -1380321338), parent name: '_SFXMkr', parent hashcode: 0xFFFFFFFF (dec: -1)
	long livesInOnePlace;			// size=0, offset=28 //  hashcode: 0xFC53279B (dec: -61659237), parent name: '_SFXMkr', parent hashcode: 0xFFFFFFFF (dec: -1)
	long inSpectral;				// size=0, offset=32 //  hashcode: 0x862E6B84 (dec: -2043778172), parent name: '_SFXMkr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _ColorType // hashcode: 0x440E837C (dec: 1141801852)
{
	unsigned char r;	// size=0, offset=0 //  hashcode: 0x30691506 (dec: 812193030), parent name: '_ColorType', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;	// size=0, offset=1 //  hashcode: 0x3AC221E1 (dec: 985801185), parent name: '_ColorType', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;	// size=0, offset=2 //  hashcode: 0xDD40F703 (dec: -582945021), parent name: '_ColorType', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code; // size=0, offset=3 //  hashcode: 0x3106BA69 (dec: 822524521), parent name: '_ColorType', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _CameraCore_Type // hashcode: 0xD341D51C (dec: -750660324)
{
	struct _Position position;			// size=6, offset=0 //  hashcode: 0x04450A99 (dec: 71633561), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad1;							// size=0, offset=6 //  hashcode: 0xE3B0906D (dec: -474967955), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX vvNormalWorVecMat[2]; // size=64, offset=8 //  hashcode: 0x56099686 (dec: 1443468934), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	long vvPlaneConsts[6];				// size=24, offset=72 //  hashcode: 0x60D06D16 (dec: 1624272150), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX *wcTransform;			// size=32, offset=96 //  hashcode: 0xE6A98993 (dec: -425096813), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	long farPlane;						// size=0, offset=100 //  hashcode: 0x9590622C (dec: -1785699796), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	long projDistance;					// size=0, offset=104 //  hashcode: 0x3A7BDE22 (dec: 981196322), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	long nearPlane;						// size=0, offset=108 //  hashcode: 0x3E57CE29 (dec: 1045941801), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX *wcTransform2;		// size=32, offset=112 //  hashcode: 0x513E600B (dec: 1363042315), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX *cwTransform2;		// size=32, offset=116 //  hashcode: 0x5ABF4F26 (dec: 1522487078), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Normal viewVolumeNormal[5]; // size=40, offset=120 //  hashcode: 0xE4630ED0 (dec: -463270192), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	int leftX;							// size=0, offset=160 //  hashcode: 0x697AF9BC (dec: 1769667004), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	int rightX;							// size=0, offset=164 //  hashcode: 0x9DEC597F (dec: -1645454977), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	int topY;							// size=0, offset=168 //  hashcode: 0x23165E05 (dec: 588668421), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	int bottomY;						// size=0, offset=172 //  hashcode: 0xC95F735A (dec: -916491430), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation;			// size=8, offset=176 //  hashcode: 0x46EB939D (dec: 1189843869), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad2;							// size=0, offset=184 //  hashcode: 0x2393E6C9 (dec: 596895433), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector screenScale;		// size=8, offset=186 //  hashcode: 0x9C530D2A (dec: -1672278742), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad3;							// size=0, offset=194 //  hashcode: 0xCEF48FEB (dec: -822833173), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position debugPos;			// size=6, offset=196 //  hashcode: 0x3DBF60F3 (dec: 1035952371), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad4;							// size=0, offset=202 //  hashcode: 0x32BA2BF5 (dec: 851061749), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation debugRot;			// size=8, offset=204 //  hashcode: 0x48CEBAC9 (dec: 1221507785), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad5;							// size=0, offset=212 //  hashcode: 0x209ABA51 (dec: 547011153), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position nondebugPos;		// size=6, offset=214 //  hashcode: 0xB78E323C (dec: -1215417796), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad6;							// size=0, offset=220 //  hashcode: 0xF4FCF396 (dec: -184749162), parent name: '_CameraCore_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SpuVolume // hashcode: 0x1BD13981 (dec: 466696577)
{
	short left;  // size=0, offset=0 //  hashcode: 0xFF38BD5D (dec: -13058723), parent name: 'SpuVolume', parent hashcode: 0xFFFFFFFF (dec: -1)
	short right; // size=0, offset=2 //  hashcode: 0xC2E190AA (dec: -1025404758), parent name: 'SpuVolume', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SpuVoiceAttr // hashcode: 0x819E0A50 (dec: -2120349104)
{
	unsigned long voice;		// size=0, offset=0 //  hashcode: 0xF2AD1C4A (dec: -223536054), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long mask;			// size=0, offset=4 //  hashcode: 0x7309BDC7 (dec: 1930018247), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SpuVolume volume;	// size=4, offset=8 //  hashcode: 0xC0ED7605 (dec: -1058179579), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SpuVolume volmode;   // size=4, offset=12 //  hashcode: 0x543F4075 (dec: 1413431413), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SpuVolume volumex;   // size=4, offset=16 //  hashcode: 0x976E4CC7 (dec: -1754379065), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pitch;		// size=0, offset=20 //  hashcode: 0x0C6AC648 (dec: 208324168), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short note;		// size=0, offset=22 //  hashcode: 0x6BB3224F (dec: 1806901839), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short sample_note; // size=0, offset=24 //  hashcode: 0x3F2F9006 (dec: 1060081670), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	short envx;					// size=0, offset=26 //  hashcode: 0xCB86849F (dec: -880376673), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long addr;			// size=0, offset=28 //  hashcode: 0x7CBA62EA (dec: 2092589802), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long loop_addr;	// size=0, offset=32 //  hashcode: 0xA7451591 (dec: -1488644719), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	long a_mode;				// size=0, offset=36 //  hashcode: 0xFB2F028C (dec: -80805236), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	long s_mode;				// size=0, offset=40 //  hashcode: 0x0AEB80C8 (dec: 183206088), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	long r_mode;				// size=0, offset=44 //  hashcode: 0x4F522FF5 (dec: 1330786293), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short ar;			// size=0, offset=48 //  hashcode: 0x4D0B8D70 (dec: 1292602736), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short dr;			// size=0, offset=50 //  hashcode: 0x297C02CC (dec: 695993036), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short sr;			// size=0, offset=52 //  hashcode: 0xC0565B50 (dec: -1068082352), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short rr;			// size=0, offset=54 //  hashcode: 0x8B1E7A24 (dec: -1960936924), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short sl;			// size=0, offset=56 //  hashcode: 0xE68344D9 (dec: -427604775), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short adsr1;		// size=0, offset=58 //  hashcode: 0x480B27FA (dec: 1208690682), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short adsr2;		// size=0, offset=60 //  hashcode: 0xF0BE2BED (dec: -255972371), parent name: 'SpuVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SpuExtAttr // hashcode: 0x58B0F474 (dec: 1487991924)
{
	struct SpuVolume volume; // size=4, offset=0 //  hashcode: 0x556AA871 (dec: 1433053297), parent name: 'SpuExtAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	long reverb;			 // size=0, offset=4 //  hashcode: 0xF47F6D0F (dec: -192975601), parent name: 'SpuExtAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	long mix;				 // size=0, offset=8 //  hashcode: 0xF3E0B3BF (dec: -203377729), parent name: 'SpuExtAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SpuStVoiceAttr // hashcode: 0xAFDFBA7E (dec: -1344292226)
{
	char status;			 // size=0, offset=0 //  hashcode: 0xCD9554BD (dec: -845851459), parent name: 'SpuStVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	char pad1;				 // size=0, offset=1 //  hashcode: 0x709A532D (dec: 1889162029), parent name: 'SpuStVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	char pad2;				 // size=0, offset=2 //  hashcode: 0xAB38E2C5 (dec: -1422335291), parent name: 'SpuStVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	char pad3;				 // size=0, offset=3 //  hashcode: 0x179C76A5 (dec: 396129957), parent name: 'SpuStVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	long last_size;			 // size=0, offset=4 //  hashcode: 0x751C1280 (dec: 1964774016), parent name: 'SpuStVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long buf_addr;  // size=0, offset=8 //  hashcode: 0x3D210012 (dec: 1025572882), parent name: 'SpuStVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long data_addr; // size=0, offset=12 //  hashcode: 0x6C032923 (dec: 1812146467), parent name: 'SpuStVoiceAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadSoundBankHdr // hashcode: 0x453DB83F (dec: 1161672767)
{
	unsigned long bankID;	 // size=0, offset=0 //  hashcode: 0x09B7DDBC (dec: 163044796), parent name: 'AadSoundBankHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long headerSize; // size=0, offset=4 //  hashcode: 0xFC55B636 (dec: -61491658), parent name: 'AadSoundBankHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	int bankVersion;		  // size=0, offset=8 //  hashcode: 0x8CF91365 (dec: -1929833627), parent name: 'AadSoundBankHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	int numPrograms;		  // size=0, offset=12 //  hashcode: 0x835962F3 (dec: -2091293965), parent name: 'AadSoundBankHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	int numTones;			  // size=0, offset=16 //  hashcode: 0x9063E1F5 (dec: -1872502283), parent name: 'AadSoundBankHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	int numWaves;			  // size=0, offset=20 //  hashcode: 0x60D1EF84 (dec: 1624371076), parent name: 'AadSoundBankHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	int numSequences;		  // size=0, offset=24 //  hashcode: 0xFF862253 (dec: -7986605), parent name: 'AadSoundBankHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	int numLabels;			  // size=0, offset=28 //  hashcode: 0x9D78B4EC (dec: -1653033748), parent name: 'AadSoundBankHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	int reverbMode;			  // size=0, offset=32 //  hashcode: 0x94C063E1 (dec: -1799330847), parent name: 'AadSoundBankHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	int reverbDepth;		  // size=0, offset=36 //  hashcode: 0x99F70189 (dec: -1711865463), parent name: 'AadSoundBankHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadProgramAtr // hashcode: 0x13FC0BEF (dec: 335285231)
{
	unsigned short numTones;   // size=0, offset=0 //  hashcode: 0xF3AC8930 (dec: -206796496), parent name: 'AadProgramAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short firstTone;  // size=0, offset=2 //  hashcode: 0x400CDE3D (dec: 1074585149), parent name: 'AadProgramAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char volume;	  // size=0, offset=4 //  hashcode: 0x63A47070 (dec: 1671721072), parent name: 'AadProgramAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char panPosition; // size=0, offset=5 //  hashcode: 0x2FF7BDC2 (dec: 804765122), parent name: 'AadProgramAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short unused;	 // size=0, offset=6 //  hashcode: 0x2F4A5097 (dec: 793399447), parent name: 'AadProgramAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadToneAtr // hashcode: 0x990CD685 (dec: -1727211899)
{
	unsigned char priority;		 // size=0, offset=0 //  hashcode: 0xB812E6B9 (dec: -1206720839), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char parentProgram; // size=0, offset=1 //  hashcode: 0xDD4F94DF (dec: -581987105), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char volume;		 // size=0, offset=2 //  hashcode: 0x29997F63 (dec: 697925475), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char panPosition;   // size=0, offset=3 //  hashcode: 0xADAA1BA4 (dec: -1381360732), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char centerNote;	// size=0, offset=4 //  hashcode: 0xB8624AFE (dec: -1201517826), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	char centerFine;			 // size=0, offset=5 //  hashcode: 0x8BFDCD9C (dec: -1946301028), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char minNote;		 // size=0, offset=6 //  hashcode: 0x11F84945 (dec: 301484357), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char maxNote;		 // size=0, offset=7 //  hashcode: 0x0CFD221F (dec: 217915935), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char mode;			 // size=0, offset=8 //  hashcode: 0x5090D81D (dec: 1351669789), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pitchBendMax;  // size=0, offset=9 //  hashcode: 0x527D0476 (dec: 1383924854), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short adsr1;		 // size=0, offset=10 //  hashcode: 0xA8E0E5CC (dec: -1461656116), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short adsr2;		 // size=0, offset=12 //  hashcode: 0x641F1D73 (dec: 1679760755), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
	short waveIndex;			 // size=0, offset=14 //  hashcode: 0xE5228057 (dec: -450723753), parent name: 'AadToneAtr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _AadDynSfxFileHdr // hashcode: 0xB9609773 (dec: -1184852109)
{
	unsigned long snfID;					  // size=0, offset=0 //  hashcode: 0x727AC2FA (dec: 1920647930), parent name: '_AadDynSfxFileHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short snfVersion;				  // size=0, offset=4 //  hashcode: 0x002E56D2 (dec: 3036882), parent name: '_AadDynSfxFileHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short uniqueID;				  // size=0, offset=6 //  hashcode: 0xD10C25E1 (dec: -787733023), parent name: '_AadDynSfxFileHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short handle;					  // size=0, offset=8 //  hashcode: 0x2B693BC1 (dec: 728316865), parent name: '_AadDynSfxFileHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short numSfxInFile;			  // size=0, offset=10 //  hashcode: 0xE81F0ACB (dec: -400618805), parent name: '_AadDynSfxFileHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _AadDynSfxFileHdr *prevDynSfxFile; // size=20, offset=12 //  hashcode: 0x4CD7BEFC (dec: 1289207548), parent name: '_AadDynSfxFileHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _AadDynSfxFileHdr *nextDynSfxFile; // size=20, offset=16 //  hashcode: 0x669E3D33 (dec: 1721646387), parent name: '_AadDynSfxFileHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadDynSfxAttr // hashcode: 0x20751E4B (dec: 544546379)
{
	unsigned short sfxID;		// size=0, offset=0 //  hashcode: 0xA54FF529 (dec: -1521486551), parent name: 'AadDynSfxAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short waveID;		// size=0, offset=2 //  hashcode: 0x81E5CE63 (dec: -2115645853), parent name: 'AadDynSfxAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadToneAtr toneAttr; // size=16, offset=4 //  hashcode: 0x7B508BAC (dec: 2068876204), parent name: 'AadDynSfxAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long waveSize;		// size=0, offset=20 //  hashcode: 0x4BABDE70 (dec: 1269554800), parent name: 'AadDynSfxAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadTempoCounter // hashcode: 0x15707CC0 (dec: 359693504)
{
	unsigned long currentTick;	 // size=0, offset=0 //  hashcode: 0x8F7DC901 (dec: -1887581951), parent name: 'AadTempoCounter', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long currentError;	// size=0, offset=4 //  hashcode: 0x70723E31 (dec: 1886535217), parent name: 'AadTempoCounter', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long tickTimeFixed;   // size=0, offset=8 //  hashcode: 0x13A30D9F (dec: 329452959), parent name: 'AadTempoCounter', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long errorPerUpdate;  // size=0, offset=12 //  hashcode: 0x47423E0A (dec: 1195523594), parent name: 'AadTempoCounter', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short ticksPerUpdate; // size=0, offset=16 //  hashcode: 0x898E7763 (dec: -1987152029), parent name: 'AadTempoCounter', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short ppqn;		   // size=0, offset=18 //  hashcode: 0xB2F1CAD1 (dec: -1292776751), parent name: 'AadTempoCounter', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long quarterNoteTime; // size=0, offset=20 //  hashcode: 0x3A4ABAAA (dec: 977975978), parent name: 'AadTempoCounter', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadSeqEvent // hashcode: 0x3E306185 (dec: 1043358085)
{
	unsigned long deltaTime;  // size=0, offset=0 //  hashcode: 0x10F5D4C2 (dec: 284546242), parent name: 'AadSeqEvent', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char track;	  // size=0, offset=4 //  hashcode: 0x8C892EBE (dec: -1937166658), parent name: 'AadSeqEvent', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char statusByte; // size=0, offset=5 //  hashcode: 0x7FC4B205 (dec: 2143597061), parent name: 'AadSeqEvent', parent hashcode: 0xFFFFFFFF (dec: -1)
	char dataByte[6];		  // size=6, offset=6 //  hashcode: 0xDF2C9C66 (dec: -550724506), parent name: 'AadSeqEvent', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _AadSequenceSlot // hashcode: 0xD7421DD6 (dec: -683532842)
{
	struct AadTempoCounter tempo;				 // size=24, offset=0 //  hashcode: 0xBE75829B (dec: -1099595109), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadSeqEvent eventQueue[4][16];		 // size=768, offset=24 //  hashcode: 0x663B795A (dec: 1715173722), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char eventIn[16];					 // size=16, offset=792 //  hashcode: 0xDBC0E4FE (dec: -608115458), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char eventOut[16];					 // size=16, offset=808 //  hashcode: 0xCFC0CAF7 (dec: -809448713), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char eventsInQueue[16];			 // size=16, offset=824 //  hashcode: 0x479BB3B3 (dec: 1201386419), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char(*sequencePosition[16]);		 // size=64, offset=840 //  hashcode: 0xE71D6B69 (dec: -417502359), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long lastEventExecutedTime[16];	 // size=64, offset=904 //  hashcode: 0xC498AD8B (dec: -996627061), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char runningStatus[16];			 // size=16, offset=968 //  hashcode: 0xB66C16BB (dec: -1234430277), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char trackFlags[16];				 // size=16, offset=984 //  hashcode: 0x466441AF (dec: 1180975535), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char(*loopSequencePosition[4][16]); // size=256, offset=1000 //  hashcode: 0x88E52EBE (dec: -1998246210), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char loopCurrentNestLevel[16];		 // size=16, offset=1256 //  hashcode: 0xCCD842CB (dec: -858242357), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char loopCounter[4][16];			 // size=64, offset=1272 //  hashcode: 0xF8737FEE (dec: -126648338), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _AadSequenceSlot *selectedSlotPtr;	// size=1488, offset=1336 //  hashcode: 0x03D1C0FA (dec: 64078074), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char selectedSlotNum;				 // size=0, offset=1340 //  hashcode: 0xA4D4F054 (dec: -1529548716), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char selectedChannel;				 // size=0, offset=1341 //  hashcode: 0x86BB5B7C (dec: -2034541700), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char sequenceNumberAssigned;		 // size=0, offset=1342 //  hashcode: 0x8B72987E (dec: -1955424130), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char thisSlotNumber;				 // size=0, offset=1343 //  hashcode: 0x594404A5 (dec: 1497629861), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short status;						 // size=0, offset=1344 //  hashcode: 0x47214A2F (dec: 1193364015), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short channelMute;					 // size=0, offset=1346 //  hashcode: 0x5741AADB (dec: 1463921371), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short delayedMuteMode;				 // size=0, offset=1348 //  hashcode: 0x6448E84F (dec: 1682499663), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short delayedMuteCmds;				 // size=0, offset=1350 //  hashcode: 0xF6412225 (dec: -163503579), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short delayedUnMuteCmds;			 // size=0, offset=1352 //  hashcode: 0x56008C57 (dec: 1442876503), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short unused;						 // size=0, offset=1354 //  hashcode: 0x01607ED9 (dec: 23101145), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short enableSustainUpdate;			 // size=0, offset=1356 //  hashcode: 0x043D690B (dec: 71133451), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short ignoreTranspose;				 // size=0, offset=1358 //  hashcode: 0xB7113158 (dec: -1223610024), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char slotFlags;					 // size=0, offset=1360 //  hashcode: 0xF80B3D3E (dec: -133481154), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char slotID;						 // size=0, offset=1361 //  hashcode: 0x6106A32F (dec: 1627824943), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char slotVolume;					 // size=0, offset=1362 //  hashcode: 0x031CF4A7 (dec: 52229287), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char slotPan;						 // size=0, offset=1363 //  hashcode: 0xB2FF4622 (dec: -1291893214), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	int *masterVolPtr;							 // size=0, offset=1364 //  hashcode: 0x512CC372 (dec: 1361888114), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	int selectedDynamicBank;					 // size=0, offset=1368 //  hashcode: 0x40F02D5B (dec: 1089482075), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	int sequenceAssignedDynamicBank;			 // size=0, offset=1372 //  hashcode: 0xA42F0F60 (dec: -1540419744), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char currentDynamicBank[16];		 // size=16, offset=1376 //  hashcode: 0x8364B898 (dec: -2090551144), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pitchWheel[16];				 // size=32, offset=1392 //  hashcode: 0x8973675A (dec: -1988925606), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char currentProgram[16];			 // size=16, offset=1424 //  hashcode: 0xEF22FB55 (dec: -282920107), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char volume[16];					 // size=16, offset=1440 //  hashcode: 0x2B9A10EB (dec: 731517163), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char panPosition[16];				 // size=16, offset=1456 //  hashcode: 0x98C4B883 (dec: -1731938173), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	char transpose[16];							 // size=16, offset=1472 //  hashcode: 0x94FE096A (dec: -1795290774), parent name: '_AadSequenceSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadSfxCommand // hashcode: 0xD8F832F6 (dec: -654822666)
{
	unsigned char statusByte;  // size=0, offset=0 //  hashcode: 0x36DCA4C6 (dec: 920429766), parent name: 'AadSfxCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char dataByte[3]; // size=3, offset=1 //  hashcode: 0x131BD9FC (dec: 320592380), parent name: 'AadSfxCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long ulongParam;  // size=0, offset=4 //  hashcode: 0x65AA49C3 (dec: 1705658819), parent name: 'AadSfxCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	short shortParam;		   // size=0, offset=8 //  hashcode: 0x313D0297 (dec: 826081943), parent name: 'AadSfxCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short unused;	 // size=0, offset=10 //  hashcode: 0xC1185BDA (dec: -1055368230), parent name: 'AadSfxCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadSfxSlot // hashcode: 0x6E655A78 (dec: 1852136056)
{
	struct AadSfxCommand commandQueue[32]; // size=384, offset=0 //  hashcode: 0x4F46A043 (dec: 1330028611), parent name: 'AadSfxSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char commandIn;			   // size=0, offset=384 //  hashcode: 0x69F30E0A (dec: 1777536522), parent name: 'AadSfxSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char commandOut;			   // size=0, offset=385 //  hashcode: 0xB5A554B2 (dec: -1247456078), parent name: 'AadSfxSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short commandsInQueue;		   // size=0, offset=386 //  hashcode: 0x5AFA4919 (dec: 1526352153), parent name: 'AadSfxSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short handleCounter;		   // size=0, offset=388 //  hashcode: 0xF14464B3 (dec: -247176013), parent name: 'AadSfxSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char sfxVolume;			   // size=0, offset=390 //  hashcode: 0x54D7574F (dec: 1423398735), parent name: 'AadSfxSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char sfxPan;				   // size=0, offset=391 //  hashcode: 0x3DDC4EE8 (dec: 1037848296), parent name: 'AadSfxSlot', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadSynthVoice // hashcode: 0x12E02CA2 (dec: 316681378)
{
	unsigned long voiceMask;	   // size=0, offset=0 //  hashcode: 0xDCC4123A (dec: -591130054), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long handle;		   // size=0, offset=4 //  hashcode: 0x64780F9C (dec: 1685589916), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char voiceID;		   // size=0, offset=8 //  hashcode: 0x4086F9FB (dec: 1082587643), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char priority;		   // size=0, offset=9 //  hashcode: 0xD8DEDD66 (dec: -656482970), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char note;			   // size=0, offset=10 //  hashcode: 0x9060A2B1 (dec: -1872715087), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char unused;		   // size=0, offset=11 //  hashcode: 0xE9F05061 (dec: -370126751), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char program;		   // size=0, offset=12 //  hashcode: 0x7749D51A (dec: 2001327386), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char baseProg;		   // size=0, offset=13 //  hashcode: 0xBEDD9D70 (dec: -1092772496), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char volume;		   // size=0, offset=14 //  hashcode: 0xA167F72C (dec: -1587022036), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char updateVol;	   // size=0, offset=15 //  hashcode: 0x00F4C41F (dec: 16040991), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pan;			   // size=0, offset=16 //  hashcode: 0xE5B14075 (dec: -441368459), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char voiceNum;		   // size=0, offset=17 //  hashcode: 0x21197190 (dec: 555315600), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short flags;		   // size=0, offset=18 //  hashcode: 0xA363F1DA (dec: -1553731110), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadToneAtr *toneAtr;	// size=16, offset=20 //  hashcode: 0x49FE752B (dec: 1241412907), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadProgramAtr *progAtr; // size=8, offset=24 //  hashcode: 0xC5E67525 (dec: -974752475), parent name: 'AadSynthVoice', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadDynamicLoadRequest // hashcode: 0xBC9D60B7 (dec: -1130536777)
{
	int type;		   // size=0, offset=0 //  hashcode: 0x50BED30B (dec: 1354683147), parent name: 'AadDynamicLoadRequest', parent hashcode: 0xFFFFFFFF (dec: -1)
	int handle;		   // size=0, offset=4 //  hashcode: 0x27A9F97A (dec: 665450874), parent name: 'AadDynamicLoadRequest', parent hashcode: 0xFFFFFFFF (dec: -1)
	long directoryID;  // size=0, offset=8 //  hashcode: 0xEC1D2F0C (dec: -333631732), parent name: 'AadDynamicLoadRequest', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;		   // size=0, offset=12 //  hashcode: 0x6ACDEFF2 (dec: 1791881202), parent name: 'AadDynamicLoadRequest', parent hashcode: 0xFFFFFFFF (dec: -1)
	char fileName[12]; // size=12, offset=16 //  hashcode: 0xE0F0CC8F (dec: -521089905), parent name: 'AadDynamicLoadRequest', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadDynamicBankLoadInfo // hashcode: 0x6A3AE9FB (dec: 1782245883)
{
	char sndFileName[32];		// size=32, offset=0 //  hashcode: 0x1CDB1D29 (dec: 484121897), parent name: 'AadDynamicBankLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	char smpFileName[32];		// size=32, offset=32 //  hashcode: 0x35875704 (dec: 898062084), parent name: 'AadDynamicBankLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int dynamicBankIndex;		// size=0, offset=64 //  hashcode: 0x47E2F608 (dec: 1206056456), parent name: 'AadDynamicBankLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int loadOption;				// size=0, offset=68 //  hashcode: 0xDA81DFA7 (dec: -629022809), parent name: 'AadDynamicBankLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*userCallbackProc)(); // size=0, offset=72 //  hashcode: 0x97655251 (dec: -1754967471), parent name: 'AadDynamicBankLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long sramDataSize; // size=0, offset=76 //  hashcode: 0x9A39BB6D (dec: -1707492499), parent name: 'AadDynamicBankLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long nextSramAddr; // size=0, offset=80 //  hashcode: 0x9E5B9C2D (dec: -1638163411), parent name: 'AadDynamicBankLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long flags;		// size=0, offset=84 //  hashcode: 0x3053F3E3 (dec: 810808291), parent name: 'AadDynamicBankLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadDynamicSfxLoadInfo // hashcode: 0xEDD41D4C (dec: -304865972)
{
	char snfFileName[40];			   // size=40, offset=0 //  hashcode: 0x9109B610 (dec: -1861634544), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	char smfFileName[40];			   // size=40, offset=40 //  hashcode: 0xC747B7DF (dec: -951601185), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int fileHandle;					   // size=0, offset=80 //  hashcode: 0x1CFCEF11 (dec: 486338321), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long directoryID;				   // size=0, offset=84 //  hashcode: 0x6AE5A115 (dec: 1793433877), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long loadFlags;					   // size=0, offset=88 //  hashcode: 0xEC30FBC5 (dec: -332334139), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;						   // size=0, offset=92 //  hashcode: 0x660C73C0 (dec: 1712092096), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int smfLoadingState;			   // size=0, offset=96 //  hashcode: 0x1F3DB6BB (dec: 524138171), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long bytesToLoad;		   // size=0, offset=100 //  hashcode: 0x2F2B68D3 (dec: 791374035), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int numSfxToLoad;				   // size=0, offset=104 //  hashcode: 0xA601210F (dec: -1509875441), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int error;						   // size=0, offset=108 //  hashcode: 0x00FC95AC (dec: 16553388), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long waveTransferAddr;	// size=0, offset=112 //  hashcode: 0x4BA1390A (dec: 1268857098), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long totalSramUsed;	   // size=0, offset=116 //  hashcode: 0x65EADDD2 (dec: 1709891026), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _AadDynSfxFileHdr *snfFile; // size=20, offset=120 //  hashcode: 0x565A0AE1 (dec: 1448741601), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadDynSfxAttr attr;		   // size=24, offset=124 //  hashcode: 0xB81E0705 (dec: -1205991675), parent name: 'AadDynamicSfxLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadNewSramBlockDesc // hashcode: 0x4DF7A665 (dec: 1308075621)
{
	unsigned short waveID;   // size=0, offset=0 //  hashcode: 0xA81DBA6A (dec: -1474446742), parent name: 'AadNewSramBlockDesc', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short address;  // size=0, offset=2 //  hashcode: 0x7224FF9E (dec: 1915027358), parent name: 'AadNewSramBlockDesc', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short size;	 // size=0, offset=4 //  hashcode: 0x544CA169 (dec: 1414308201), parent name: 'AadNewSramBlockDesc', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char prevIndex; // size=0, offset=6 //  hashcode: 0x3C190D00 (dec: 1008274688), parent name: 'AadNewSramBlockDesc', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char nextIndex; // size=0, offset=7 //  hashcode: 0x08120358 (dec: 135398232), parent name: 'AadNewSramBlockDesc', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadLoadedSfxToneAttr // hashcode: 0xC1F66431 (dec: -1040817103)
{
	unsigned short referenceCount; // size=0, offset=0 //  hashcode: 0x5DB3CED7 (dec: 1572064983), parent name: 'AadLoadedSfxToneAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short waveID;		   // size=0, offset=2 //  hashcode: 0xA6197A5F (dec: -1508279713), parent name: 'AadLoadedSfxToneAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadToneAtr toneAttr;	// size=16, offset=4 //  hashcode: 0x79AD9507 (dec: 2041419015), parent name: 'AadLoadedSfxToneAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadLoadedSfxWaveAttr // hashcode: 0x3EFD9321 (dec: 1056805665)
{
	unsigned short referenceCount; // size=0, offset=0 //  hashcode: 0x961CC897 (dec: -1776498537), parent name: 'AadLoadedSfxWaveAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char unused;		   // size=0, offset=2 //  hashcode: 0x4418BAD1 (dec: 1142471377), parent name: 'AadLoadedSfxWaveAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char sramHandle;	  // size=0, offset=3 //  hashcode: 0x06F91C7C (dec: 116989052), parent name: 'AadLoadedSfxWaveAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadSramDefragInfo // hashcode: 0xB08B77B9 (dec: -1333037127)
{
	int status;					// size=0, offset=0 //  hashcode: 0x76B51AB3 (dec: 1991580339), parent name: 'AadSramDefragInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char *fragBuffer;  // size=0, offset=4 //  hashcode: 0x691D9F50 (dec: 1763549008), parent name: 'AadSramDefragInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int masterListEntry;		// size=0, offset=8 //  hashcode: 0x6A591CB1 (dec: 1784224945), parent name: 'AadSramDefragInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int waveID;					// size=0, offset=12 //  hashcode: 0xABE4150A (dec: -1411115766), parent name: 'AadSramDefragInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long destSramAddr; // size=0, offset=16 //  hashcode: 0x24139D04 (dec: 605265156), parent name: 'AadSramDefragInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long srcSramAddr;  // size=0, offset=20 //  hashcode: 0x0D31F03A (dec: 221376570), parent name: 'AadSramDefragInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long moveSize;		// size=0, offset=24 //  hashcode: 0x86191719 (dec: -2045176039), parent name: 'AadSramDefragInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long readSize;		// size=0, offset=28 //  hashcode: 0x15E10429 (dec: 367068201), parent name: 'AadSramDefragInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadVolFader // hashcode: 0x053CCA3C (dec: 87870012)
{
	int volumeStep;					// size=0, offset=0 //  hashcode: 0x5DF62C65 (dec: 1576414309), parent name: 'AadVolFader', parent hashcode: 0xFFFFFFFF (dec: -1)
	int targetVolume;				// size=0, offset=4 //  hashcode: 0x480A10C6 (dec: 1208619206), parent name: 'AadVolFader', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*fadeCompleteCallback)(); // size=0, offset=8 //  hashcode: 0xE596D469 (dec: -443100055), parent name: 'AadVolFader', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MusicLoadCmd // hashcode: 0x575883B8 (dec: 1465418680)
{
	int type; // size=0, offset=0 //  hashcode: 0xFC15F2A2 (dec: -65670494), parent name: 'MusicLoadCmd', parent hashcode: 0xFFFFFFFF (dec: -1)
	int data; // size=0, offset=4 //  hashcode: 0xCB66475B (dec: -882489509), parent name: 'MusicLoadCmd', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct gSoundData // hashcode: 0x100090FC (dec: 268472572)
{
	unsigned long gMasterVol; // size=0, offset=0 //  hashcode: 0xE5F9D1AF (dec: -436612689), parent name: 'gSoundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long gMusicVol;  // size=0, offset=4 //  hashcode: 0x166AD6C8 (dec: 376100552), parent name: 'gSoundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long gSfxVol;	// size=0, offset=8 //  hashcode: 0x51870753 (dec: 1367803731), parent name: 'gSoundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long gVoiceVol;  // size=0, offset=12 //  hashcode: 0xCC6ABF25 (dec: -865419483), parent name: 'gSoundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char gSfxOn;			  // size=0, offset=16 //  hashcode: 0xDDC3CE78 (dec: -574370184), parent name: 'gSoundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char gMusicOn;			  // size=0, offset=17 //  hashcode: 0x5A3B45CC (dec: 1513833932), parent name: 'gSoundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char gVoiceOn;			  // size=0, offset=18 //  hashcode: 0x6611B269 (dec: 1712435817), parent name: 'gSoundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char soundsLoaded;		  // size=0, offset=19 //  hashcode: 0xAB545E1A (dec: -1420534246), parent name: 'gSoundData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GameTracker // hashcode: 0x4EB3EFC5 (dec: 1320415173)
{
	struct _GameData_Type gameData;		   // size=32, offset=0 //  hashcode: 0xFB1AACBA (dec: -82137926), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct menu_t *menu;				   // size=0, offset=32 //  hashcode: 0xCB3010C7 (dec: -886042425), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct memcard_t *memcard;			   // size=0, offset=36 //  hashcode: 0xEBCB1E02 (dec: -339010046), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Level *level;				   // size=392, offset=40 //  hashcode: 0x6913D826 (dec: 1762908198), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *playerInstance;	  // size=616, offset=44 //  hashcode: 0x5C10B034 (dec: 1544597556), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long drawPage;						   // size=0, offset=48 //  hashcode: 0xB51B4E5C (dec: -1256501668), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _InstanceList *instanceList;	// size=268, offset=52 //  hashcode: 0x69147538 (dec: 1762948408), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _InstancePool *instancePool;	// size=38204, offset=56 //  hashcode: 0xBD5FAA28 (dec: -1117803992), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _VertexPool *vertexPool;		   // size=6336, offset=60 //  hashcode: 0x8B4054A1 (dec: -1958718303), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _PrimPool *primPool;			   // size=96012, offset=64 //  hashcode: 0xB64AC98F (dec: -1236612721), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _ObjectTracker *GlobalObjects;  // size=36, offset=68 //  hashcode: 0x618FCE64 (dec: 1636814436), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long controlCommand[2][5];			   // size=40, offset=72 //  hashcode: 0xDC3F5BB3 (dec: -599827533), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long controlData[2][5];				   // size=40, offset=112 //  hashcode: 0xF84CC799 (dec: -129185895), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long overrideData[2][5];			   // size=40, offset=152 //  hashcode: 0xA67495E2 (dec: -1502308894), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long debugFlags;					   // size=0, offset=192 //  hashcode: 0x4E8E6534 (dec: 1317954868), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long debugFlags2;					   // size=0, offset=196 //  hashcode: 0xD7D25762 (dec: -674080926), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct CVECTOR wipeColor;			   // size=4, offset=200 //  hashcode: 0x6E0C3FBF (dec: 1846296511), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short wipeTime;						   // size=0, offset=204 //  hashcode: 0xC7899393 (dec: -947285101), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxWipeTime;					   // size=0, offset=206 //  hashcode: 0xA3CF3BC7 (dec: -1546699833), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short wipeType;						   // size=0, offset=208 //  hashcode: 0x712767FB (dec: 1898407931), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numGSignals;					   // size=0, offset=210 //  hashcode: 0x180D2AAA (dec: 403516074), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void(*gSignal[16]);					   // size=64, offset=212 //  hashcode: 0xF9C3CFDE (dec: -104607778), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LightInfo *lightInfo;		   // size=1148, offset=276 //  hashcode: 0x4BEF4E3E (dec: 1273974334), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *reqDisp;						   // size=0, offset=280 //  hashcode: 0xCF65BCE8 (dec: -815416088), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long *drawTimerReturn;				   // size=0, offset=284 //  hashcode: 0x0B34ECC9 (dec: 188017865), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long usecsStartDraw;				   // size=0, offset=288 //  hashcode: 0xEF31F650 (dec: -281938352), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *disp;							   // size=0, offset=292 //  hashcode: 0x96EF737B (dec: -1762692229), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long displayFrameCount;	   // size=0, offset=296 //  hashcode: 0x6F32F7C8 (dec: 1865611208), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long frameCount;			   // size=0, offset=300 //  hashcode: 0x43442FB2 (dec: 1128542130), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long fps30Count;			   // size=0, offset=304 //  hashcode: 0xECF3353C (dec: -319605444), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long vblFrames;			   // size=0, offset=308 //  hashcode: 0x43EC0657 (dec: 1139541591), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long vblCount;				   // size=0, offset=312 //  hashcode: 0x4B91F163 (dec: 1267855715), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numMatrices;					   // size=0, offset=316 //  hashcode: 0x45231FD8 (dec: 1159929816), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long gameFlags;						   // size=0, offset=320 //  hashcode: 0x7268FE50 (dec: 1919483472), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamFlags;					   // size=0, offset=324 //  hashcode: 0xA0418619 (dec: -1606318567), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *drawNonAnimatedSegmentFunc;	  // size=0, offset=328 //  hashcode: 0xADFB7E10 (dec: -1376027120), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *drawAnimatedModelFunc;		   // size=0, offset=332 //  hashcode: 0xF540634C (dec: -180329652), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *drawDisplayPolytopeListFunc;	 // size=0, offset=336 //  hashcode: 0xB8F6E327 (dec: -1191779545), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *drawBgFunc;					   // size=0, offset=340 //  hashcode: 0xA1513DD8 (dec: -1588511272), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Level *mainDrawUnit;			   // size=392, offset=344 //  hashcode: 0x3E159911 (dec: 1041602833), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char baseAreaName[16];				   // size=16, offset=348 //  hashcode: 0x1E6ACC6F (dec: 510315631), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short levelDone;					   // size=0, offset=364 //  hashcode: 0xD31DA260 (dec: -753032608), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short levelChange;					   // size=0, offset=366 //  hashcode: 0x4CC31879 (dec: 1287854201), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short hideBG;						   // size=0, offset=368 //  hashcode: 0x25430AFB (dec: 625150715), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short gameMode;						   // size=0, offset=370 //  hashcode: 0x01375BDE (dec: 20405214), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long currentHotSpot;				   // size=0, offset=372 //  hashcode: 0x08449614 (dec: 138712596), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long StreamUnitID;					   // size=0, offset=376 //  hashcode: 0x6DB03675 (dec: 1840264821), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short SwitchToNewStreamUnit;		   // size=0, offset=380 //  hashcode: 0x520882B5 (dec: 1376289461), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short SwitchToNewWarpIndex;			   // size=0, offset=382 //  hashcode: 0x9CC8E654 (dec: -1664555436), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char S_baseAreaName[16];			   // size=16, offset=384 //  hashcode: 0x8DC972C8 (dec: -1916177720), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short toSignal;						   // size=0, offset=400 //  hashcode: 0x5014E082 (dec: 1343545474), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fromSignal;					   // size=0, offset=402 //  hashcode: 0x997B71C4 (dec: -1719963196), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char LastSignal;					   // size=0, offset=404 //  hashcode: 0xE50E01BB (dec: -452066885), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short StreamNormalA;				   // size=0, offset=406 //  hashcode: 0x941546B7 (dec: -1810544969), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short StreamNormalB;				   // size=0, offset=408 //  hashcode: 0x34B085B1 (dec: 883983793), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short StreamNormalC;				   // size=0, offset=410 //  hashcode: 0x39F03389 (dec: 972043145), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long StreamNormalD;					   // size=0, offset=412 //  hashcode: 0xE0637F00 (dec: -530350336), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long moveRazielToStreamID;			   // size=0, offset=416 //  hashcode: 0xEAB12346 (dec: -357489850), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _ColorType animObjLine;		   // size=4, offset=420 //  hashcode: 0x4014052B (dec: 1075053867), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _ColorType animObjShade;		   // size=4, offset=424 //  hashcode: 0x24B438FD (dec: 615790845), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxIntroFXTime;				   // size=0, offset=428 //  hashcode: 0x1496A3BD (dec: 345416637), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct gSoundData sound;			   // size=20, offset=432 //  hashcode: 0x74DE62D3 (dec: 1960731347), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short controllerMode;				   // size=0, offset=452 //  hashcode: 0xD4076C70 (dec: -737710992), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char plan_collide_override;   // size=0, offset=454 //  hashcode: 0x4E84FC8F (dec: 1317338255), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char cheatMode;			   // size=0, offset=455 //  hashcode: 0x2ECD1517 (dec: 785192215), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char currentLvl;					   // size=0, offset=456 //  hashcode: 0x3C8861C6 (dec: 1015570886), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char lastLvl;						   // size=0, offset=457 //  hashcode: 0xD320064F (dec: -752875953), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *introFX;				   // size=76, offset=460 //  hashcode: 0x55AF4BF0 (dec: 1437551600), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Intro *introFXIntro;			   // size=76, offset=464 //  hashcode: 0xD95C7B56 (dec: -648250538), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long **drawOT;				   // size=0, offset=468 //  hashcode: 0x5960E6E6 (dec: 1499522790), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long **dispOT;				   // size=0, offset=472 //  hashcode: 0x8DDF4171 (dec: -1914748559), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct P_TAG *savedOTStart;			   // size=8, offset=476 //  hashcode: 0x19505A0C (dec: 424696332), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct P_TAG *savedOTEnd;			   // size=8, offset=480 //  hashcode: 0x00BF756E (dec: 12547438), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long introWaitTime;					   // size=0, offset=484 //  hashcode: 0x0940B7E4 (dec: 155236324), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long mirrorZPush;					   // size=0, offset=488 //  hashcode: 0x41215F86 (dec: 1092706182), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long defVVRemoveDist;				   // size=0, offset=492 //  hashcode: 0xBCE12403 (dec: -1126095869), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long defRemoveDist;					   // size=0, offset=496 //  hashcode: 0x7F468407 (dec: 2135327751), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position forcedStartPosition;  // size=6, offset=500 //  hashcode: 0xC0B42A58 (dec: -1061934504), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short hudCollDisplay;				   // size=0, offset=506 //  hashcode: 0xDDF3B673 (dec: -571230605), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long primMemUsed;					   // size=0, offset=508 //  hashcode: 0xE0BEE552 (dec: -524360366), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long cheatTimerCount;				   // size=0, offset=512 //  hashcode: 0x45C2C200 (dec: 1170391552), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long playerCheatFlags;				   // size=0, offset=516 //  hashcode: 0xA33DDE98 (dec: -1556226408), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long savedPlayerCameraMode;			   // size=0, offset=520 //  hashcode: 0x42B6D10C (dec: 1119277324), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long debugDrawFlags;				   // size=0, offset=524 //  hashcode: 0x3969E52D (dec: 963241261), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *planningPool;					   // size=0, offset=528 //  hashcode: 0x9572765F (dec: -1787660705), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *enemyPlanPool;				   // size=0, offset=532 //  hashcode: 0x6BF07F6B (dec: 1810923371), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char block_collide_override;  // size=0, offset=536 //  hashcode: 0x5A773944 (dec: 1517762884), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char raziel_collide_override; // size=0, offset=537 //  hashcode: 0x5AC22135 (dec: 1522671925), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeOfDay;					   // size=0, offset=538 //  hashcode: 0x44229214 (dec: 1143116308), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long decoupleGame;					   // size=0, offset=540 //  hashcode: 0xA4A03A99 (dec: -1533003111), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long multGameTime;					   // size=0, offset=544 //  hashcode: 0xD2FADDC0 (dec: -755311168), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short spectral_fadeValue;			   // size=0, offset=548 //  hashcode: 0x8D33CA3B (dec: -1925985733), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short material_fadeValue;			   // size=0, offset=550 //  hashcode: 0x4053D11B (dec: 1079234843), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long drawTime;				   // size=0, offset=552 //  hashcode: 0x5AFC7D06 (dec: 1526496518), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long currentTime;			   // size=0, offset=556 //  hashcode: 0x73FEBC36 (dec: 1946074166), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long currentMaterialTime;	 // size=0, offset=560 //  hashcode: 0xB94ECD64 (dec: -1186017948), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long currentSpectralTime;	 // size=0, offset=564 //  hashcode: 0x2FCC0915 (dec: 801900821), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long currentTimeOfDayTime;	// size=0, offset=568 //  hashcode: 0xE531BFA3 (dec: -449724509), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long lastLoopTime;			   // size=0, offset=572 //  hashcode: 0x75EDA14A (dec: 1978507594), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long timeMult;				   // size=0, offset=576 //  hashcode: 0x9BA6BB33 (dec: -1683571917), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long globalTimeMult;		   // size=0, offset=580 //  hashcode: 0x1AE9ABE9 (dec: 451521513), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long spectralTimeMult;		   // size=0, offset=584 //  hashcode: 0xC8B619A9 (dec: -927589975), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long materialTimeMult;		   // size=0, offset=588 //  hashcode: 0xF1562EA7 (dec: -246010201), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long currentTicks;			   // size=0, offset=592 //  hashcode: 0xD0AD73C3 (dec: -793939005), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long totalTime;			   // size=0, offset=596 //  hashcode: 0x719137F7 (dec: 1905342455), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long idleTime;				   // size=0, offset=600 //  hashcode: 0xBAEBF3C3 (dec: -1158941757), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long visibleInstances;				   // size=0, offset=604 //  hashcode: 0x522F59BB (dec: 1378834875), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	int gameFramePassed;				   // size=0, offset=608 //  hashcode: 0xD6D03AA2 (dec: -690996574), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long timeSinceLastGameFrame;  // size=0, offset=612 //  hashcode: 0x046A0E92 (dec: 74059410), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frameRateLock;					   // size=0, offset=616 //  hashcode: 0x86FDE68A (dec: -2030180726), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short frameRate24fps;				   // size=0, offset=620 //  hashcode: 0x4C573F2D (dec: 1280786221), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char monster_collide_override;		   // size=0, offset=622 //  hashcode: 0xE2991E45 (dec: -493281723), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char pad;							   // size=0, offset=623 //  hashcode: 0x17FF5B97 (dec: 402611095), parent name: 'GameTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct Spline // hashcode: 0xA7B8D53F (dec: -1481059009)
{
	struct SplineKey *key; // size=32, offset=0 //  hashcode: 0xEA9B1E6B (dec: -358932885), parent name: 'Spline', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numkeys;		   // size=0, offset=4 //  hashcode: 0x305A2DA2 (dec: 811216290), parent name: 'Spline', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;	// size=0, offset=6 //  hashcode: 0xE422B7A9 (dec: -467486807), parent name: 'Spline', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;   // size=0, offset=7 //  hashcode: 0xD2B27167 (dec: -760057497), parent name: 'Spline', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct vecS // hashcode: 0xEADB8F3A (dec: -354709702)
{
	short x; // size=0, offset=0 //  hashcode: 0xE1D712EE (dec: -505998610), parent name: 'vecS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y; // size=0, offset=2 //  hashcode: 0x354AEC4E (dec: 894102606), parent name: 'vecS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z; // size=0, offset=4 //  hashcode: 0xE27947F8 (dec: -495368200), parent name: 'vecS', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct vecL // hashcode: 0x7575CB14 (dec: 1970653972)
{
	long x; // size=0, offset=0 //  hashcode: 0xB1A05BF0 (dec: -1314890768), parent name: 'vecL', parent hashcode: 0xFFFFFFFF (dec: -1)
	long y; // size=0, offset=4 //  hashcode: 0xD8547182 (dec: -665554558), parent name: 'vecL', parent hashcode: 0xFFFFFFFF (dec: -1)
	long z; // size=0, offset=8 //  hashcode: 0x0BC29D80 (dec: 197303680), parent name: 'vecL', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SplineRotKey // hashcode: 0xD2E3A87E (dec: -756832130)
{
	short count;		   // size=0, offset=0 //  hashcode: 0x4B2B0B6A (dec: 1261112170), parent name: 'SplineRotKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type q; // size=8, offset=2 //  hashcode: 0xBDD47E35 (dec: -1110147531), parent name: 'SplineRotKey', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RSpline // hashcode: 0xD9C500BD (dec: -641400643)
{
	struct SplineRotKey *key; // size=10, offset=0 //  hashcode: 0xD28D6E10 (dec: -762483184), parent name: 'RSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numkeys;			  // size=0, offset=4 //  hashcode: 0x7E35A815 (dec: 2117445653), parent name: 'RSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;		  // size=0, offset=6 //  hashcode: 0xDC28CC49 (dec: -601306039), parent name: 'RSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;	  // size=0, offset=7 //  hashcode: 0x858FC28C (dec: -2054176116), parent name: 'RSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SplineKey // hashcode: 0x5D3D994D (dec: 1564318029)
{
	short count;	   // size=0, offset=0 //  hashcode: 0x069A044D (dec: 110756941), parent name: 'SplineKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct vecS point; // size=6, offset=2 //  hashcode: 0x62EC022F (dec: 1659634223), parent name: 'SplineKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct vecL dd;	// size=12, offset=8 //  hashcode: 0xBBD5FE2F (dec: -1143603665), parent name: 'SplineKey', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct vecL ds;	// size=12, offset=20 //  hashcode: 0x7B14706A (dec: 2064937066), parent name: 'SplineKey', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _HVertex // hashcode: 0xC488A83D (dec: -997676995)
{
	short x;	  // size=0, offset=0 //  hashcode: 0xB9F1587A (dec: -1175365510), parent name: '_HVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	  // size=0, offset=2 //  hashcode: 0x4429A526 (dec: 1143579942), parent name: '_HVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;	  // size=0, offset=4 //  hashcode: 0x0F7CAAEA (dec: 259828458), parent name: '_HVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	short normal; // size=0, offset=6 //  hashcode: 0x614ADC74 (dec: 1632296052), parent name: '_HVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
	long pad;	 // size=0, offset=8 //  hashcode: 0xB54B0E9B (dec: -1253372261), parent name: '_HVertex', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MONAPI_Regenerator // hashcode: 0x37E0AA1B (dec: 937470491)
{
	unsigned long regenTime; // size=0, offset=0 //  hashcode: 0xEC2FF312 (dec: -332401902), parent name: '_MONAPI_Regenerator', parent hashcode: 0xFFFFFFFF (dec: -1)
	short introUniqueID;	 // size=0, offset=4 //  hashcode: 0xAABB76F1 (dec: -1430554895), parent name: '_MONAPI_Regenerator', parent hashcode: 0xFFFFFFFF (dec: -1)
	short streamUnitID;		 // size=0, offset=6 //  hashcode: 0xC80E291B (dec: -938596069), parent name: '_MONAPI_Regenerator', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __Event // hashcode: 0xBC16D673 (dec: -1139353997)
{
	int ID;   // size=0, offset=0 //  hashcode: 0x0BF58C0F (dec: 200641551), parent name: '__Event', parent hashcode: 0xFFFFFFFF (dec: -1)
	int Data; // size=0, offset=4 //  hashcode: 0x0EE1962C (dec: 249665068), parent name: '__Event', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __MessageQueue // hashcode: 0x473062B5 (dec: 1194353333)
{
	int Head;				  // size=0, offset=0 //  hashcode: 0x8162EC2D (dec: -2124223443), parent name: '__MessageQueue', parent hashcode: 0xFFFFFFFF (dec: -1)
	int Tail;				  // size=0, offset=4 //  hashcode: 0x005AB14A (dec: 5943626), parent name: '__MessageQueue', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __Event Queue[16]; // size=128, offset=8 //  hashcode: 0x137F4350 (dec: 327107408), parent name: '__MessageQueue', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __State // hashcode: 0xA27CC1F7 (dec: -1568882185)
{
	void (*Process)();			 // size=0, offset=0 //  hashcode: 0xC4F743A7 (dec: -990428249), parent name: '__State', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __MessageQueue Event; // size=136, offset=4 //  hashcode: 0xD1DE0AE6 (dec: -773977370), parent name: '__State', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __MessageQueue Defer; // size=136, offset=140 //  hashcode: 0x6F4D44FB (dec: 1867334907), parent name: '__State', parent hashcode: 0xFFFFFFFF (dec: -1)
	int Data1;					 // size=0, offset=276 //  hashcode: 0x50C407D0 (dec: 1355024336), parent name: '__State', parent hashcode: 0xFFFFFFFF (dec: -1)
	int Data2;					 // size=0, offset=280 //  hashcode: 0x0535811A (dec: 87392538), parent name: '__State', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct POLY_F4 // hashcode: 0xE2AC295D (dec: -492033699)
{
	unsigned long tag;  // size=0, offset=0 //  hashcode: 0x3A1ED5A5 (dec: 975099301), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;   // size=0, offset=4 //  hashcode: 0x6C46B9C5 (dec: 1816574405), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;   // size=0, offset=5 //  hashcode: 0xF44CC904 (dec: -196294396), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;   // size=0, offset=6 //  hashcode: 0xF54A3033 (dec: -179687373), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code; // size=0, offset=7 //  hashcode: 0xB3ED72A1 (dec: -1276284255), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;			// size=0, offset=8 //  hashcode: 0x0A0E8504 (dec: 168723716), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;			// size=0, offset=10 //  hashcode: 0xD678DA29 (dec: -696722903), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;			// size=0, offset=12 //  hashcode: 0x79D93CF1 (dec: 2044280049), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;			// size=0, offset=14 //  hashcode: 0xA8DD9D2F (dec: -1461871313), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;			// size=0, offset=16 //  hashcode: 0x1C3902A7 (dec: 473498279), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;			// size=0, offset=18 //  hashcode: 0x3D323DD1 (dec: 1026702801), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x3;			// size=0, offset=20 //  hashcode: 0xFC27D558 (dec: -64498344), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y3;			// size=0, offset=22 //  hashcode: 0x8C784AAE (dec: -1938273618), parent name: 'POLY_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _SmallRotation // hashcode: 0xB9CA5EE3 (dec: -1177919773)
{
	short x; // size=0, offset=0 //  hashcode: 0x6E2F6572 (dec: 1848599922), parent name: '_SmallRotation', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y; // size=0, offset=2 //  hashcode: 0xB3A85AA4 (dec: -1280812380), parent name: '_SmallRotation', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z; // size=0, offset=4 //  hashcode: 0x22FB259D (dec: 586884509), parent name: '_SmallRotation', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EventPointers // hashcode: 0x3787E212 (dec: 931652114)
{
	long numPuzzles;				  // size=0, offset=0 //  hashcode: 0x49AB248E (dec: 1235952782), parent name: 'EventPointers', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Event(*eventInstances[1]); // size=4, offset=4 //  hashcode: 0x4DBDCD5F (dec: 1304284511), parent name: 'EventPointers', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct Camera // hashcode: 0x0670C20F (dec: 108053007)
{
	struct _CameraCore_Type core;				   // size=224, offset=0 //  hashcode: 0xB71B3EC2 (dec: -1222951230), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long shake;									   // size=0, offset=224 //  hashcode: 0x1C9EF1D6 (dec: 480178646), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short shakeFrame;							   // size=0, offset=228 //  hashcode: 0x4BC89F68 (dec: 1271439208), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short shakeScale;							   // size=0, offset=230 //  hashcode: 0x37C2D6D9 (dec: 935515865), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;									   // size=0, offset=232 //  hashcode: 0xEC14ECF9 (dec: -334172935), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long lock;									   // size=0, offset=236 //  hashcode: 0x2DCAF4AA (dec: 768275626), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short mode;									   // size=0, offset=240 //  hashcode: 0x70608F8E (dec: 1885376398), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short state;								   // size=0, offset=242 //  hashcode: 0x9CC6B8A2 (dec: -1664698206), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short posState;								   // size=0, offset=244 //  hashcode: 0xDCE24ECC (dec: -589148468), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rotState;								   // size=0, offset=246 //  hashcode: 0x47D4E55E (dec: 1205134686), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short tiltState;							   // size=0, offset=248 //  hashcode: 0x3F92D74B (dec: 1066587979), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short distanceState;						   // size=0, offset=250 //  hashcode: 0x360A6442 (dec: 906650690), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lagZ;									   // size=0, offset=252 //  hashcode: 0x3928868C (dec: 958957196), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short tilt;									   // size=0, offset=254 //  hashcode: 0xF749C5D8 (dec: -146160168), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position focusPoint;				   // size=6, offset=256 //  hashcode: 0x18245CA1 (dec: 405036193), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short focusDistance;						   // size=0, offset=262 //  hashcode: 0x39F98172 (dec: 972652914), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *focusInstance;			   // size=616, offset=264 //  hashcode: 0x47F453E1 (dec: 1207194593), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position oldFocusInstancePos;		   // size=6, offset=268 //  hashcode: 0x3E9EDD49 (dec: 1050598729), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position newFocusInstancePos;		   // size=6, offset=274 //  hashcode: 0x7ECD076B (dec: 2127365995), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation oldFocusInstanceRot;		   // size=8, offset=280 //  hashcode: 0x9F92ED3A (dec: -1617760966), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation newFocusInstanceRot;		   // size=8, offset=288 //  hashcode: 0xAE8DF9E7 (dec: -1366427161), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector focusInstanceVelVec;		   // size=8, offset=296 //  hashcode: 0x401C4CFD (dec: 1075596541), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position focusLeadPivot;			   // size=6, offset=304 //  hashcode: 0x3745EF27 (dec: 927330087), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position focusOffset;				   // size=6, offset=310 //  hashcode: 0xA9FF70D2 (dec: -1442877230), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation focusRotation;				   // size=8, offset=316 //  hashcode: 0x3EBA90A1 (dec: 1052414113), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short tiltVel;								   // size=0, offset=324 //  hashcode: 0x8557FDFB (dec: -2057830917), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short tiltAccl;								   // size=0, offset=326 //  hashcode: 0x3CBC1700 (dec: 1018959616), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector positionVel;				   // size=8, offset=328 //  hashcode: 0x6AEBAB26 (dec: 1793829670), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector positionAccl;				   // size=8, offset=336 //  hashcode: 0x60585723 (dec: 1616402211), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector focusPointVel;				   // size=8, offset=344 //  hashcode: 0x15B08035 (dec: 363888693), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector focusPointAccl;				   // size=8, offset=352 //  hashcode: 0x50A539B6 (dec: 1353005494), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short focusDistanceVel;						   // size=0, offset=360 //  hashcode: 0x9E19988C (dec: -1642489716), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short focusDistanceAccl;					   // size=0, offset=362 //  hashcode: 0x456F6EE2 (dec: 1164930786), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector focusRotVel;				   // size=8, offset=364 //  hashcode: 0xE4CF75FB (dec: -456165893), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector focusRotAccl;				   // size=8, offset=372 //  hashcode: 0xD8A0DB47 (dec: -660546745), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector maxFocusVel;				   // size=8, offset=380 //  hashcode: 0x08478D36 (dec: 138906934), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector rotationVel;				   // size=8, offset=388 //  hashcode: 0xCE63F2E8 (dec: -832310552), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector rotationAccl;				   // size=8, offset=396 //  hashcode: 0x79F7325E (dec: 2046243422), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxVel;								   // size=0, offset=404 //  hashcode: 0x7346037B (dec: 1933968251), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxRot;								   // size=0, offset=406 //  hashcode: 0x53177DF1 (dec: 1394048497), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position targetPos;					   // size=6, offset=408 //  hashcode: 0x35A555D7 (dec: 900027863), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short targetTilt;							   // size=0, offset=414 //  hashcode: 0x081097A8 (dec: 135305128), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation targetRotation;			   // size=8, offset=416 //  hashcode: 0x32C0A0C5 (dec: 851484869), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short targetFocusDistance;					   // size=0, offset=424 //  hashcode: 0x75AB15D3 (dec: 1974146515), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position targetFocusPoint;			   // size=6, offset=426 //  hashcode: 0xED70C4BB (dec: -311376709), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short collisionTargetFocusDistance;			   // size=0, offset=432 //  hashcode: 0x2C156FA7 (dec: 739602343), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation targetFocusRotation;		   // size=8, offset=434 //  hashcode: 0x952ED195 (dec: -1792093803), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short tfaceTilt;							   // size=0, offset=442 //  hashcode: 0x5DD9405B (dec: 1574518875), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation collisionTargetFocusRotation; // size=8, offset=444 //  hashcode: 0x23EBBECA (dec: 602652362), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short smooth;								   // size=0, offset=452 //  hashcode: 0x9374CA20 (dec: -1821062624), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _CameraKey *cameraKey;				   // size=24, offset=456 //  hashcode: 0x8C872914 (dec: -1937299180), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Sphere focusSphere;					   // size=12, offset=460 //  hashcode: 0x5AC83249 (dec: 1523069513), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Sphere smallBaseSphere;				   // size=12, offset=472 //  hashcode: 0x4F1F228B (dec: 1327440523), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Sphere posSphere;					   // size=12, offset=484 //  hashcode: 0xCE8142E6 (dec: -830389530), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lookTimer;							   // size=0, offset=496 //  hashcode: 0x94A51721 (dec: -1801119967), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lookSavedMode;						   // size=0, offset=498 //  hashcode: 0x0F13A83B (dec: 252946491), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short presetIndex;							   // size=0, offset=500 //  hashcode: 0x6BA97F6D (dec: 1806270317), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short presetFocusDistance[3];				   // size=6, offset=502 //  hashcode: 0xB775384D (dec: -1217054643), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long minFocusDistance;						   // size=0, offset=508 //  hashcode: 0xE4CADCA9 (dec: -456467287), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxFocusDistance;						   // size=0, offset=512 //  hashcode: 0x97EFC287 (dec: -1745894777), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long minTilt;								   // size=0, offset=516 //  hashcode: 0x74EFB39D (dec: 1961866141), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxTilt;								   // size=0, offset=520 //  hashcode: 0x0556C805 (dec: 89573381), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long pad[3];								   // size=12, offset=524 //  hashcode: 0x40458686 (dec: 1078298246), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long minXYDist;								   // size=0, offset=536 //  hashcode: 0x57C53CA5 (dec: 1472543909), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxXYDist;								   // size=0, offset=540 //  hashcode: 0x9CE3FCC0 (dec: -1662780224), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long oppositeError;							   // size=0, offset=544 //  hashcode: 0x9F18649F (dec: -1625791329), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long tempsplinePointAhead;					   // size=0, offset=548 //  hashcode: 0xEE69B122 (dec: -295063262), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long noTeleport;							   // size=0, offset=552 //  hashcode: 0xD7BC9591 (dec: -675506799), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistanceList[3][3];				   // size=36, offset=556 //  hashcode: 0xB1482F87 (dec: -1320669305), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long tiltList[3][3];						   // size=36, offset=592 //  hashcode: 0xB68E94FA (dec: -1232169734), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long cineControl;							   // size=0, offset=628 //  hashcode: 0xB56E575B (dec: -1251059877), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short stack;								   // size=0, offset=632 //  hashcode: 0x02D8B44E (dec: 47756366), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short targetStack;							   // size=0, offset=634 //  hashcode: 0x0D89E34B (dec: 227140427), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long savedMode[3];							   // size=12, offset=636 //  hashcode: 0x388C6CF8 (dec: 948727032), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long savedTargetFocusDistance[3];			   // size=12, offset=648 //  hashcode: 0x338E8CFE (dec: 864980222), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation savedFocusRotation;		   // size=8, offset=660 //  hashcode: 0xCF29CEAB (dec: -819343701), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short savedFocusDistance;					   // size=0, offset=668 //  hashcode: 0x7F1EB735 (dec: 2132719413), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short signalFocusDistance;					   // size=0, offset=670 //  hashcode: 0x1D221C08 (dec: 488774664), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SavedCinematic savedCinematic[3];	  // size=336, offset=672 //  hashcode: 0x757F4CE8 (dec: 1971277032), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation savedfocusRotation;		   // size=8, offset=1008 //  hashcode: 0xCAC1F444 (dec: -893258684), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position signalPos;					   // size=6, offset=1016 //  hashcode: 0xA8C4292E (dec: -1463539410), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad11;								   // size=0, offset=1022 //  hashcode: 0xEBF5A869 (dec: -336222103), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation signalRot;					   // size=8, offset=1024 //  hashcode: 0xC048E250 (dec: -1068965296), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short forced_movement;						   // size=0, offset=1032 //  hashcode: 0x49A024F3 (dec: 1235231987), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short last_forced_movement;					   // size=0, offset=1034 //  hashcode: 0x5BA99C98 (dec: 1537842328), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rotDirection;							   // size=0, offset=1036 //  hashcode: 0xA800FFA8 (dec: -1476329560), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long lastModTime;					   // size=0, offset=1040 //  hashcode: 0x73DAD159 (dec: 1943720281), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation lookRot;					   // size=8, offset=1044 //  hashcode: 0x5F9D6287 (dec: 1604149895), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *Spline00;				   // size=0, offset=1052 //  hashcode: 0x6547B7DE (dec: 1699198942), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *Spline01;				   // size=0, offset=1056 //  hashcode: 0x2601BFFF (dec: 637648895), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
												   // size=96, offset=1060 //  hashcode: 0x8C01F486 (dec: -1946028922), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long cuckooTimer;							   // size=0, offset=1156 //  hashcode: 0x0CA6C5A1 (dec: 212256161), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short teleportZRot;							   // size=0, offset=1160 //  hashcode: 0x6C46F9E0 (dec: 1816590816), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short extraZRot;							   // size=0, offset=1162 //  hashcode: 0xC508003D (dec: -989331395), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short extraXRot;							   // size=0, offset=1164 //  hashcode: 0x5C75856E (dec: 1551205742), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short leftTimer;							   // size=0, offset=1166 //  hashcode: 0x8C9E23EF (dec: -1935793169), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rightTimer;							   // size=0, offset=1168 //  hashcode: 0xEB56484A (dec: -346666934), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short collideRotControl;					   // size=0, offset=1170 //  hashcode: 0xE88E52E6 (dec: -393325850), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short collision_lastPush;					   // size=0, offset=1172 //  hashcode: 0x8CA271EC (dec: -1935511060), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short collision_timer;						   // size=0, offset=1174 //  hashcode: 0xF59D6FB4 (dec: -174231628), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long prev_instance_mode;			   // size=0, offset=1176 //  hashcode: 0xE15BA6F0 (dec: -514087184), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long instance_mode;				   // size=0, offset=1180 //  hashcode: 0x74E9B06A (dec: 1961472106), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long instance_xyvel;						   // size=0, offset=1184 //  hashcode: 0x3F9F2BDA (dec: 1067396058), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	long instance_prev_xyvel;					   // size=0, offset=1188 //  hashcode: 0x6DF15B40 (dec: 1844534080), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position real_focuspoint;			   // size=6, offset=1192 //  hashcode: 0xF9A7AAB6 (dec: -106452298), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short always_rotate_flag;					   // size=0, offset=1198 //  hashcode: 0x2E0C5F86 (dec: 772562822), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short follow_flag;							   // size=0, offset=1200 //  hashcode: 0x8E258268 (dec: -1910144408), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short actual_x_rot;							   // size=0, offset=1202 //  hashcode: 0xE0704148 (dec: -529514168), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short actual_vel_x;							   // size=0, offset=1204 //  hashcode: 0xD4311279 (dec: -734981511), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short actual_acc_x;							   // size=0, offset=1206 //  hashcode: 0xB2CEF55C (dec: -1295059620), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x_rot_change;							   // size=0, offset=1208 //  hashcode: 0x9F1FDAE6 (dec: -1625302298), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short focuspoint_fallz;						   // size=0, offset=1210 //  hashcode: 0xF5952CF4 (dec: -174773004), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lead_angle;							   // size=0, offset=1212 //  hashcode: 0xE252596D (dec: -497919635), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lead_vel;								   // size=0, offset=1214 //  hashcode: 0xFB132107 (dec: -82632441), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lead_accl;							   // size=0, offset=1216 //  hashcode: 0xFFF4A335 (dec: -744651), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lead_timer;							   // size=0, offset=1218 //  hashcode: 0x9CFC306B (dec: -1661194133), parent name: 'Camera', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DebugMenuLine // hashcode: 0x1BD18E81 (dec: 466718337)
{
	enum DEBUG_LINE_TYPE type; // size=4, offset=0 //  hashcode: 0x6B5319F8 (dec: 1800608248), parent name: 'DebugMenuLine', parent hashcode: 0xFFFFFFFF (dec: -1)
	long lower;				   // size=0, offset=4 //  hashcode: 0x332DD11F (dec: 858640671), parent name: 'DebugMenuLine', parent hashcode: 0xFFFFFFFF (dec: -1)
	long upper;				   // size=0, offset=8 //  hashcode: 0xB9603885 (dec: -1184876411), parent name: 'DebugMenuLine', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;				   // size=0, offset=12 //  hashcode: 0xC29858D6 (dec: -1030203178), parent name: 'DebugMenuLine', parent hashcode: 0xFFFFFFFF (dec: -1)
	long *var_address;		   // size=0, offset=16 //  hashcode: 0xD7925AA2 (dec: -678274398), parent name: 'DebugMenuLine', parent hashcode: 0xFFFFFFFF (dec: -1)
	long bit_mask;			   // size=0, offset=20 //  hashcode: 0x36F209C5 (dec: 921831877), parent name: 'DebugMenuLine', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _ButtonTexture // hashcode: 0x9E750D8C (dec: -1636495988)
{
	short tpage;					   // size=0, offset=0 //  hashcode: 0x10E05350 (dec: 283136848), parent name: '_ButtonTexture', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clut;						   // size=0, offset=2 //  hashcode: 0x11AD70EE (dec: 296579310), parent name: '_ButtonTexture', parent hashcode: 0xFFFFFFFF (dec: -1)
	short textureW;					   // size=0, offset=4 //  hashcode: 0x2DDD0E2F (dec: 769461807), parent name: '_ButtonTexture', parent hashcode: 0xFFFFFFFF (dec: -1)
	short textureH;					   // size=0, offset=6 //  hashcode: 0xE6EC1033 (dec: -420736973), parent name: '_ButtonTexture', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BlockVramEntry *vramBlock; // size=0, offset=8 //  hashcode: 0xA598F210 (dec: -1516703216), parent name: '_ButtonTexture', parent hashcode: 0xFFFFFFFF (dec: -1)
	long xshift;					   // size=0, offset=12 //  hashcode: 0xE0D05F17 (dec: -523215081), parent name: '_ButtonTexture', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BlockVramEntry // hashcode: 0x24B2FBC5 (dec: 615709637)
{
	struct _BlockVramEntry *next; // size=28, offset=0 //  hashcode: 0x2B063515 (dec: 721827093), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;			  // size=0, offset=4 //  hashcode: 0xED655898 (dec: -312125288), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;		  // size=0, offset=5 //  hashcode: 0x37B0CC5B (dec: 934333531), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;					  // size=0, offset=6 //  hashcode: 0x604196BF (dec: 1614911167), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short newX;					  // size=0, offset=8 //  hashcode: 0x98FD2A6C (dec: -1728238996), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short newY;					  // size=0, offset=10 //  hashcode: 0x0C5FB18C (dec: 207597964), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x;					  // size=0, offset=12 //  hashcode: 0x97DFFDBB (dec: -1746928197), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;					  // size=0, offset=14 //  hashcode: 0xE21E64A4 (dec: -501324636), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short w;					  // size=0, offset=16 //  hashcode: 0x323945A6 (dec: 842614182), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short h;					  // size=0, offset=18 //  hashcode: 0x7DBD24C2 (dec: 2109547714), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long area;					  // size=0, offset=20 //  hashcode: 0x1410AEFB (dec: 336637691), parent name: '_BlockVramEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FontChar // hashcode: 0x5A2F9F5B (dec: 1513070427)
{
	short x;	// size=0, offset=0 //  hashcode: 0x8B5A4F5B (dec: -1957015717), parent name: 'FontChar', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	// size=0, offset=2 //  hashcode: 0x9960E669 (dec: -1721702807), parent name: 'FontChar', parent hashcode: 0xFFFFFFFF (dec: -1)
	char c;		// size=0, offset=4 //  hashcode: 0xFF90D02C (dec: -7286740), parent name: 'FontChar', parent hashcode: 0xFFFFFFFF (dec: -1)
	char color; // size=0, offset=5 //  hashcode: 0x82F3535C (dec: -2097982628), parent name: 'FontChar', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BigFileEntry // hashcode: 0xA904436B (dec: -1459338389)
{
	long fileHash;	 // size=0, offset=0 //  hashcode: 0xE98AD6B5 (dec: -376777035), parent name: '_BigFileEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long fileLen;	  // size=0, offset=4 //  hashcode: 0xD8CE80E4 (dec: -657555228), parent name: '_BigFileEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long filePos;	  // size=0, offset=8 //  hashcode: 0x24E59CE8 (dec: 619027688), parent name: '_BigFileEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long checkSumFull; // size=0, offset=12 //  hashcode: 0x0101C660 (dec: 16893536), parent name: '_BigFileEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BigFileDirEntry // hashcode: 0x7D70C603 (dec: 2104542723)
{
	short streamUnitID; // size=0, offset=0 //  hashcode: 0x86FD1308 (dec: -2030234872), parent name: '_BigFileDirEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numFiles;		// size=0, offset=2 //  hashcode: 0x78277B21 (dec: 2015853345), parent name: '_BigFileDirEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long subDirOffset;  // size=0, offset=4 //  hashcode: 0xADCD33BC (dec: -1379060804), parent name: '_BigFileDirEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BigFileDir // hashcode: 0x4E39D3E2 (dec: 1312412642)
{
	long numFiles;					  // size=0, offset=0 //  hashcode: 0xBF3883E4 (dec: -1086815260), parent name: '_BigFileDir', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BigFileEntry fileList[0]; // size=0, offset=4 //  hashcode: 0x8F247DAF (dec: -1893433937), parent name: '_BigFileDir', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BigFile // hashcode: 0x50C273F3 (dec: 1354920947)
{
	long bigfileBaseOffset;				 // size=0, offset=0 //  hashcode: 0x76905C03 (dec: 1989172227), parent name: '_BigFile', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BigFileDir *rootDir;		 // size=4, offset=4 //  hashcode: 0x348B3A13 (dec: 881539603), parent name: '_BigFile', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BigFileDir *currentDir;		 // size=4, offset=8 //  hashcode: 0x0A4EA20B (dec: 172925451), parent name: '_BigFile', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BigFileDir *cachedDir;		 // size=4, offset=12 //  hashcode: 0xD13BF95B (dec: -784598693), parent name: '_BigFile', parent hashcode: 0xFFFFFFFF (dec: -1)
	long currentDirID;					 // size=0, offset=16 //  hashcode: 0xEDDF2D37 (dec: -304141001), parent name: '_BigFile', parent hashcode: 0xFFFFFFFF (dec: -1)
	long cachedDirID;					 // size=0, offset=20 //  hashcode: 0xE3CEA1D7 (dec: -472997417), parent name: '_BigFile', parent hashcode: 0xFFFFFFFF (dec: -1)
	long searchDirID;					 // size=0, offset=24 //  hashcode: 0xD61F3273 (dec: -702598541), parent name: '_BigFile', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numSubDirs;					 // size=0, offset=28 //  hashcode: 0x951F31EA (dec: -1793117718), parent name: '_BigFile', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BigFileDirEntry *subDirList; // size=8, offset=32 //  hashcode: 0xD778D282 (dec: -679947646), parent name: '_BigFile', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _NonBlockLoadEntry // hashcode: 0x722059B4 (dec: 1914722740)
{
	long fileHash;	 // size=0, offset=0 //  hashcode: 0xC98BD924 (dec: -913581788), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long dirHash;	  // size=0, offset=4 //  hashcode: 0x6771AD6F (dec: 1735503215), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long filePos;	  // size=0, offset=8 //  hashcode: 0x69FD602E (dec: 1778212910), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long *loadAddr;	// size=0, offset=12 //  hashcode: 0xBB6A8EE5 (dec: -1150644507), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long loadSize;	 // size=0, offset=16 //  hashcode: 0xEC3F6FC9 (dec: -331386935), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long checksum;	 // size=0, offset=20 //  hashcode: 0xB11B9F6D (dec: -1323589779), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long checksumType; // size=0, offset=24 //  hashcode: 0x16DD728D (dec: 383611533), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long memType;	  // size=0, offset=28 //  hashcode: 0x89F9350E (dec: -1980156658), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long posInFile;	// size=0, offset=32 //  hashcode: 0x5C8653CB (dec: 1552307147), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long mallocFailOk; // size=0, offset=36 //  hashcode: 0x32B8DA90 (dec: 850975376), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *retFunc;	 // size=0, offset=40 //  hashcode: 0xE467DC81 (dec: -462955391), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *retData;	 // size=0, offset=44 //  hashcode: 0x8AB34B76 (dec: -1967961226), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *retData2;	// size=0, offset=48 //  hashcode: 0xDB4A56C6 (dec: -615885114), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	void **retPointer; // size=0, offset=52 //  hashcode: 0x6C0FD9BE (dec: 1812978110), parent name: '_NonBlockLoadEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _ReadQueueEntry // hashcode: 0x5360DCDA (dec: 1398856922)
{
	long readStartPos;   // size=0, offset=0 //  hashcode: 0xFBE56610 (dec: -68852208), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long readSize;		 // size=0, offset=4 //  hashcode: 0xCF2356EE (dec: -819767570), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long readCurSize;	// size=0, offset=8 //  hashcode: 0x31591E7B (dec: 827924091), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *readStartDest; // size=0, offset=12 //  hashcode: 0xEB5834E7 (dec: -346540825), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *readCurDest;   // size=0, offset=16 //  hashcode: 0x91D06F25 (dec: -1848611035), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long readStatus;	 // size=0, offset=20 //  hashcode: 0xF11CE0ED (dec: -249765651), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long checksum;		 // size=0, offset=24 //  hashcode: 0xE57C74BA (dec: -444828486), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	long checksumType;   // size=0, offset=28 //  hashcode: 0xA391B7E7 (dec: -1550731289), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *retFunc;		 // size=0, offset=32 //  hashcode: 0xD43526EE (dec: -734714130), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *retData;		 // size=0, offset=36 //  hashcode: 0x9EF32CFB (dec: -1628230405), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *retData2;		 // size=0, offset=40 //  hashcode: 0xF584EEF2 (dec: -175837454), parent name: '_ReadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FX_MATRIX // hashcode: 0x13190ADD (dec: 320408285)
{
	struct NodeType node;	  // size=8, offset=0 //  hashcode: 0x90D41827 (dec: -1865148377), parent name: '_FX_MATRIX', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;				   // size=0, offset=8 //  hashcode: 0x49496543 (dec: 1229546819), parent name: '_FX_MATRIX', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX lwTransform; // size=32, offset=12 //  hashcode: 0xF6826A43 (dec: -159225277), parent name: '_FX_MATRIX', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FX_PRIM // hashcode: 0x16BF818E (dec: 381649294)
{
	struct NodeType node;		// size=8, offset=0 //  hashcode: 0xF8DDCF96 (dec: -119681130), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct TextureMT3 *texture; // size=16, offset=8 //  hashcode: 0x08CDFFD5 (dec: 147718101), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;					// size=0, offset=12 //  hashcode: 0x26847C6F (dec: 646216815), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeToLive;			// size=0, offset=16 //  hashcode: 0x10759784 (dec: 276141956), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	short curFrame;				// size=0, offset=18 //  hashcode: 0x73C0DBD1 (dec: 1942019025), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *process;				// size=0, offset=20 //  hashcode: 0xBA24973F (dec: -1172007105), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _FX_MATRIX *matrix;  // size=44, offset=24 //  hashcode: 0x02BC91BF (dec: 45912511), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color;					// size=0, offset=28 //  hashcode: 0xF87EF425 (dec: -125897691), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	long startColor;			// size=0, offset=32 //  hashcode: 0xABC6184C (dec: -1413081012), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	long endColor;				// size=0, offset=36 //  hashcode: 0xB35D9630 (dec: -1285712336), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	short colorFadeValue;		// size=0, offset=40 //  hashcode: 0x6452F1BB (dec: 1683157435), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	short colorFadeStep;		// size=0, offset=42 //  hashcode: 0x47D9621B (dec: 1205428763), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position;  // size=6, offset=44 //  hashcode: 0xA20D9868 (dec: -1576167320), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadeStep;				// size=0, offset=50 //  hashcode: 0x0A80643A (dec: 176186426), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadeValue[4];			// size=8, offset=52 //  hashcode: 0xA96FD6FE (dec: -1452288258), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position v0;		// size=6, offset=60 //  hashcode: 0xF4FEA6D3 (dec: -184637741), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	short work0;				// size=0, offset=66 //  hashcode: 0x4A6D5875 (dec: 1248680053), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position v1;		// size=6, offset=68 //  hashcode: 0x267CCCAE (dec: 645713070), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	short work1;				// size=0, offset=74 //  hashcode: 0x53EFDEA4 (dec: 1408229028), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position v2;		// size=6, offset=76 //  hashcode: 0x02EDDAE0 (dec: 49142496), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	short work2;				// size=0, offset=82 //  hashcode: 0x585D11CF (dec: 1482494415), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position v3;		// size=6, offset=84 //  hashcode: 0x74106F93 (dec: 1947234195), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
	short work3;				// size=0, offset=90 //  hashcode: 0x06FE9AE3 (dec: 117349091), parent name: '_FX_PRIM', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BASIC_LINE_G2 // hashcode: 0x684545B2 (dec: 1749370290)
{
	unsigned char r0;   // size=0, offset=0 //  hashcode: 0x5EB3D861 (dec: 1588844641), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;   // size=0, offset=1 //  hashcode: 0xF684EACC (dec: -159061300), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;   // size=0, offset=2 //  hashcode: 0x2EF4ECD5 (dec: 787803349), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code; // size=0, offset=3 //  hashcode: 0x8D79C2E6 (dec: -1921400090), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;			// size=0, offset=4 //  hashcode: 0x95D0B537 (dec: -1781484233), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;			// size=0, offset=6 //  hashcode: 0x6F33FD3B (dec: 1865678139), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r1;   // size=0, offset=8 //  hashcode: 0xA85510EC (dec: -1470820116), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g1;   // size=0, offset=9 //  hashcode: 0x83128C78 (dec: -2095936392), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b1;   // size=0, offset=10 //  hashcode: 0x005DB8A4 (dec: 6142116), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char p1;   // size=0, offset=11 //  hashcode: 0x02FD468D (dec: 50153101), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;			// size=0, offset=12 //  hashcode: 0x4D0362E3 (dec: 1292067555), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;			// size=0, offset=14 //  hashcode: 0x0405EC9F (dec: 67497119), parent name: 'BASIC_LINE_G2', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BASIC_G4 // hashcode: 0xC15AD9EF (dec: -1051010577)
{
	unsigned char r0;   // size=0, offset=0 //  hashcode: 0xCB592A2C (dec: -883348948), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;   // size=0, offset=1 //  hashcode: 0xB30FF061 (dec: -1290801055), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;   // size=0, offset=2 //  hashcode: 0x104A1250 (dec: 273289808), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code; // size=0, offset=3 //  hashcode: 0xB8EF85FD (dec: -1192262147), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;			// size=0, offset=4 //  hashcode: 0x8116EEC2 (dec: -2129203518), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;			// size=0, offset=6 //  hashcode: 0x8B34F51E (dec: -1959463650), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r1;   // size=0, offset=8 //  hashcode: 0x8C847921 (dec: -1937475295), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g1;   // size=0, offset=9 //  hashcode: 0x7A2BA1D5 (dec: 2049679829), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b1;   // size=0, offset=10 //  hashcode: 0x22103FEC (dec: 571490284), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad1; // size=0, offset=11 //  hashcode: 0xACFA51DC (dec: -1392881188), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;			// size=0, offset=12 //  hashcode: 0xBE00444C (dec: -1107278772), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;			// size=0, offset=14 //  hashcode: 0x22121FFF (dec: 571613183), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r2;   // size=0, offset=16 //  hashcode: 0xF9881FC7 (dec: -108519481), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g2;   // size=0, offset=17 //  hashcode: 0x4989BE42 (dec: 1233763906), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b2;   // size=0, offset=18 //  hashcode: 0x5CF1B4EB (dec: 1559344363), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad2; // size=0, offset=19 //  hashcode: 0x4D854EE5 (dec: 1300582117), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;			// size=0, offset=20 //  hashcode: 0x3F5B2776 (dec: 1062938486), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;			// size=0, offset=22 //  hashcode: 0xA789DEF3 (dec: -1484136717), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r3;   // size=0, offset=24 //  hashcode: 0x2C50E986 (dec: 743500166), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g3;   // size=0, offset=25 //  hashcode: 0x07734216 (dec: 124994070), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b3;   // size=0, offset=26 //  hashcode: 0x9B89DCF1 (dec: -1685463823), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad3; // size=0, offset=27 //  hashcode: 0xC427EAB9 (dec: -1004016967), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x3;			// size=0, offset=28 //  hashcode: 0x02A50B7C (dec: 44370812), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y3;			// size=0, offset=30 //  hashcode: 0x8F68DEFC (dec: -1888952580), parent name: '_BASIC_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _BASIC_F4 // hashcode: 0x2871008E (dec: 678494350)
{
	unsigned char r0;   // size=0, offset=0 //  hashcode: 0x1F82BA0A (dec: 528661002), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;   // size=0, offset=1 //  hashcode: 0x9E777553 (dec: -1636338349), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;   // size=0, offset=2 //  hashcode: 0x68018CD6 (dec: 1744932054), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code; // size=0, offset=3 //  hashcode: 0x2D34FE58 (dec: 758447704), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;			// size=0, offset=4 //  hashcode: 0xB8F15223 (dec: -1192144349), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;			// size=0, offset=6 //  hashcode: 0x6F7CA4CC (dec: 1870439628), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;			// size=0, offset=8 //  hashcode: 0x3336ED07 (dec: 859237639), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;			// size=0, offset=10 //  hashcode: 0x46E92EF5 (dec: 1189687029), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;			// size=0, offset=12 //  hashcode: 0xAC793AF5 (dec: -1401341195), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;			// size=0, offset=14 //  hashcode: 0x6900528D (dec: 1761628813), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x3;			// size=0, offset=16 //  hashcode: 0xBB4D5F63 (dec: -1152557213), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y3;			// size=0, offset=18 //  hashcode: 0xE33041D1 (dec: -483376687), parent name: '_BASIC_F4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __BubbleParams // hashcode: 0xE483C494 (dec: -461126508)
{
	short DisperseFrames;  // size=0, offset=0 //  hashcode: 0x7969B823 (dec: 2036971555), parent name: '__BubbleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short KillScale;	   // size=0, offset=2 //  hashcode: 0xFE20574E (dec: -31434930), parent name: '__BubbleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short MinSplashSize;   // size=0, offset=4 //  hashcode: 0x46AC0D3E (dec: 1185680702), parent name: '__BubbleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short MaxSpeed;		   // size=0, offset=6 //  hashcode: 0x8A3B34FE (dec: -1975831298), parent name: '__BubbleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short MaxSpeedRange;   // size=0, offset=8 //  hashcode: 0x2C9EE7A2 (dec: 748611490), parent name: '__BubbleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ScaleRate;	   // size=0, offset=10 //  hashcode: 0xCE6112EC (dec: -832498964), parent name: '__BubbleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ScaleRateRange;  // size=0, offset=12 //  hashcode: 0xB5F64E4E (dec: -1242149298), parent name: '__BubbleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short StartScale;	  // size=0, offset=14 //  hashcode: 0xE32E4681 (dec: -483506559), parent name: '__BubbleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short StartScaleRange; // size=0, offset=16 //  hashcode: 0xBDE2BA65 (dec: -1109214619), parent name: '__BubbleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short UniqueBubbles;   // size=0, offset=18 //  hashcode: 0x59AE432F (dec: 1504592687), parent name: '__BubbleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _GenericParticleParams // hashcode: 0x7A6370AD (dec: 2053337261)
{
	short size;						  // size=0, offset=0 //  hashcode: 0x769735AB (dec: 1989621163), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char StartOnInit;		  // size=0, offset=2 //  hashcode: 0x02244A14 (dec: 35932692), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;				  // size=0, offset=3 //  hashcode: 0xDFEE5C9E (dec: -538026850), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short birthRadius;				  // size=0, offset=4 //  hashcode: 0x80AAF608 (dec: -2136279544), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char startSegment;				  // size=0, offset=6 //  hashcode: 0xF60B3966 (dec: -167036570), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char endSegment;				  // size=0, offset=7 //  hashcode: 0xC6179A37 (dec: -971531721), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position direction;		  // size=6, offset=8 //  hashcode: 0xEFE021D2 (dec: -270523950), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char spectral_colorize;  // size=0, offset=14 //  hashcode: 0xEE3E2295 (dec: -297917803), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char absolute_direction; // size=0, offset=15 //  hashcode: 0x60E25F36 (dec: 1625448246), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char accx;						  // size=0, offset=16 //  hashcode: 0x32997FDE (dec: 848920542), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char accy;						  // size=0, offset=17 //  hashcode: 0x93167049 (dec: -1827246007), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char accz;						  // size=0, offset=18 //  hashcode: 0x17D046EB (dec: 399525611), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char useInstanceModel;			  // size=0, offset=19 //  hashcode: 0x7611E55F (dec: 1980884319), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char startColor_red;	 // size=0, offset=20 //  hashcode: 0x4251EA56 (dec: 1112664662), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char startColor_green;   // size=0, offset=21 //  hashcode: 0x2EBA3CB0 (dec: 783957168), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char startColor_blue;	// size=0, offset=22 //  hashcode: 0xE68FB79B (dec: -426788965), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char model;						  // size=0, offset=23 //  hashcode: 0xF2E83972 (dec: -219661966), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char endColor_red;		  // size=0, offset=24 //  hashcode: 0x10BE5549 (dec: 280909129), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char endColor_green;	 // size=0, offset=25 //  hashcode: 0x205C44FE (dec: 542917886), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char endColor_blue;	  // size=0, offset=26 //  hashcode: 0xEEAC0638 (dec: -290716104), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char texture;					  // size=0, offset=27 //  hashcode: 0x01A20C2D (dec: 27397165), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;					  // size=0, offset=28 //  hashcode: 0x1E1A8601 (dec: 505054721), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char primLifeTime;		  // size=0, offset=30 //  hashcode: 0x431AC5CA (dec: 1125828042), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char use_child;					  // size=0, offset=31 //  hashcode: 0x8DD01033 (dec: -1915744205), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startFadeValue;			  // size=0, offset=32 //  hashcode: 0x35C5AB98 (dec: 902146968), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadeStep;					  // size=0, offset=34 //  hashcode: 0xD766C900 (dec: -681129728), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numberBirthParticles;		  // size=0, offset=36 //  hashcode: 0xF37277E3 (dec: -210602013), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char z_undulation_mode;			  // size=0, offset=37 //  hashcode: 0x75215E98 (dec: 1965121176), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short scaleSpeed;				  // size=0, offset=38 //  hashcode: 0x8E0A7667 (dec: -1911916953), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position offset;		  // size=6, offset=40 //  hashcode: 0xF5948813 (dec: -174815213), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startScale;				  // size=0, offset=46 //  hashcode: 0xEB136AFB (dec: -351048965), parent name: '_GenericParticleParams', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _GenericRibbonParams // hashcode: 0xD243E3C9 (dec: -767302711)
{
	char id;			  // size=0, offset=0 //  hashcode: 0xF6C0924F (dec: -155151793), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char StartOnInit;	 // size=0, offset=1 //  hashcode: 0x9DB08E6A (dec: -1649373590), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char startSegment;	// size=0, offset=2 //  hashcode: 0x3414A882 (dec: 873769090), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char endSegment;	  // size=0, offset=3 //  hashcode: 0xDCF6F968 (dec: -587794072), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char type;			  // size=0, offset=4 //  hashcode: 0xFF426991 (dec: -12424815), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char use_child;		  // size=0, offset=5 //  hashcode: 0x178BD049 (dec: 395038793), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ribbonLifeTime; // size=0, offset=6 //  hashcode: 0x8B80214A (dec: -1954537142), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short faceLifeTime;   // size=0, offset=8 //  hashcode: 0x6C60300A (dec: 1818243082), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startFadeValue; // size=0, offset=10 //  hashcode: 0x1E0F128D (dec: 504304269), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	long startColor;	  // size=0, offset=12 //  hashcode: 0x729295DC (dec: 1922209244), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	long endColor;		  // size=0, offset=16 //  hashcode: 0x7E8A5C8A (dec: 2122996874), parent name: '_GenericRibbonParams', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _GenericGlowParams // hashcode: 0xF67692B8 (dec: -160001352)
{
	char StartOnInit;		  // size=0, offset=0 //  hashcode: 0x6798E26C (dec: 1738072684), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char segment;	// size=0, offset=1 //  hashcode: 0x2E2C37AF (dec: 774649775), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char segmentEnd; // size=0, offset=2 //  hashcode: 0xEF814F60 (dec: -276738208), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numSegments;		  // size=0, offset=3 //  hashcode: 0x771A9BFB (dec: 1998232571), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char color_num;  // size=0, offset=4 //  hashcode: 0x2E768337 (dec: 779518775), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char use_child;			  // size=0, offset=5 //  hashcode: 0x85E1104F (dec: -2048847793), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char numColors;  // size=0, offset=6 //  hashcode: 0x7249E956 (dec: 1917446486), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char id;				  // size=0, offset=7 //  hashcode: 0x21559665 (dec: 559257189), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	long atuColorCycleRate;   // size=0, offset=8 //  hashcode: 0xFAC1DA22 (dec: -87959006), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short width;			  // size=0, offset=12 //  hashcode: 0x37CACAF1 (dec: 936037105), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short height;			  // size=0, offset=14 //  hashcode: 0xBA5C9726 (dec: -1168337114), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	long lifetime;			  // size=0, offset=16 //  hashcode: 0x962EF371 (dec: -1775307919), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadein_time;		  // size=0, offset=20 //  hashcode: 0x2A88FDC4 (dec: 713620932), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadeout_time;		  // size=0, offset=22 //  hashcode: 0xD26C8145 (dec: -764640955), parent name: '_GenericGlowParams', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _GenericLightningParams // hashcode: 0x226C68CF (dec: 577530063)
{
	char type;					   // size=0, offset=0 //  hashcode: 0xE8D53ACD (dec: -388678963), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char use_child;				   // size=0, offset=1 //  hashcode: 0x9D9FFF26 (dec: -1650458842), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;				   // size=0, offset=2 //  hashcode: 0x24B5CFF2 (dec: 615895026), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short deg;					   // size=0, offset=4 //  hashcode: 0x6D56B56F (dec: 1834399087), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short deg_inc;				   // size=0, offset=6 //  hashcode: 0x3985A90D (dec: 965060877), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position start_offset; // size=6, offset=8 //  hashcode: 0xB1D8595B (dec: -1311221413), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char startSeg;				   // size=0, offset=14 //  hashcode: 0xFF7AB124 (dec: -8736476), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char endSeg;				   // size=0, offset=15 //  hashcode: 0x827364F3 (dec: -2106366733), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position end_offset;   // size=6, offset=16 //  hashcode: 0x3317AC37 (dec: 857189431), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char matrixSeg;				   // size=0, offset=22 //  hashcode: 0x81487843 (dec: -2125957053), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char segs;			   // size=0, offset=23 //  hashcode: 0x21E594E4 (dec: 568693988), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short width;				   // size=0, offset=24 //  hashcode: 0x091CB88D (dec: 152877197), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short small_width;			   // size=0, offset=26 //  hashcode: 0x4EA21B42 (dec: 1319246658), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sine_size;			   // size=0, offset=28 //  hashcode: 0x0D9FF394 (dec: 228586388), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short variation;			   // size=0, offset=30 //  hashcode: 0x603B4311 (dec: 1614496529), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color;					   // size=0, offset=32 //  hashcode: 0xD8ED63CA (dec: -655531062), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	long glow_color;			   // size=0, offset=36 //  hashcode: 0x0C9CDF4A (dec: 211607370), parent name: '_GenericLightningParams', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _GenericBlastringParams // hashcode: 0xAB3B2462 (dec: -1422187422)
{
	char type;				  // size=0, offset=0 //  hashcode: 0x5804911E (dec: 1476694302), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char use_child;			  // size=0, offset=1 //  hashcode: 0x591DAC99 (dec: 1495116953), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;			  // size=0, offset=2 //  hashcode: 0x6BDD7B5F (dec: 1809677151), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position offset;  // size=6, offset=4 //  hashcode: 0xF5DEEA20 (dec: -169940448), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short matrixSeg;		  // size=0, offset=10 //  hashcode: 0x22F4ACF6 (dec: 586460406), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char segment;			  // size=0, offset=12 //  hashcode: 0x2FED1273 (dec: 804065907), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char sortInWorld;		  // size=0, offset=13 //  hashcode: 0x4ABB9FF5 (dec: 1253810165), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short radius;			  // size=0, offset=14 //  hashcode: 0x40C03804 (dec: 1086339076), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short size1;			  // size=0, offset=16 //  hashcode: 0x094CA7AA (dec: 156018602), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short size2;			  // size=0, offset=18 //  hashcode: 0xA2F0FBAE (dec: -1561265234), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short endRadius;		  // size=0, offset=20 //  hashcode: 0x35F4CE1F (dec: 905235999), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short colorchange_radius; // size=0, offset=22 //  hashcode: 0xC4429797 (dec: -1002268777), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	int vel;				  // size=0, offset=24 //  hashcode: 0xCC76180D (dec: -864675827), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	int accl;				  // size=0, offset=28 //  hashcode: 0x0150CE5F (dec: 22072927), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short height1;			  // size=0, offset=32 //  hashcode: 0xF071A391 (dec: -260988015), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short height2;			  // size=0, offset=34 //  hashcode: 0xB5826B69 (dec: -1249744023), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short height3;			  // size=0, offset=36 //  hashcode: 0x70AD7876 (dec: 1890416758), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char predator_offset;	 // size=0, offset=38 //  hashcode: 0x57198240 (dec: 1461289536), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	char stay_in_place;		  // size=0, offset=39 //  hashcode: 0xC0C7C4A1 (dec: -1060649823), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	long startColor;		  // size=0, offset=40 //  hashcode: 0xA0F8908C (dec: -1594322804), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	long endColor;			  // size=0, offset=44 //  hashcode: 0x41E408F1 (dec: 1105463537), parent name: '_GenericBlastringParams', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _GenericFlashParams // hashcode: 0x06D8DB60 (dec: 114875232)
{
	short type;			 // size=0, offset=0 //  hashcode: 0xC9290798 (dec: -920057960), parent name: '_GenericFlashParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeToColor;   // size=0, offset=2 //  hashcode: 0x913796F7 (dec: -1858627849), parent name: '_GenericFlashParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color;			 // size=0, offset=4 //  hashcode: 0x652FDAAD (dec: 1697634989), parent name: '_GenericFlashParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeAtColor;   // size=0, offset=8 //  hashcode: 0xEAFFB3DC (dec: -352341028), parent name: '_GenericFlashParams', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeFromColor; // size=0, offset=10 //  hashcode: 0x80A95C4E (dec: -2136384434), parent name: '_GenericFlashParams', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _StreamUnit // hashcode: 0xAC366E40 (dec: -1405718976)
{
	long StreamUnitID;		 // size=0, offset=0 //  hashcode: 0x70253426 (dec: 1881486374), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short used;				 // size=0, offset=4 //  hashcode: 0xD50A5FEF (dec: -720740369), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;			 // size=0, offset=6 //  hashcode: 0x011DF715 (dec: 18741013), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Level *level;	 // size=392, offset=8 //  hashcode: 0xC1929217 (dec: -1047358953), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	char baseAreaName[16];   // size=16, offset=12 //  hashcode: 0xEED64F14 (dec: -287944940), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short toSignal;			 // size=0, offset=28 //  hashcode: 0xE6DDB7D1 (dec: -421677103), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fromSignal;		 // size=0, offset=30 //  hashcode: 0x7F10163B (dec: 2131760699), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	long FrameCount;		 // size=0, offset=32 //  hashcode: 0xD88CC300 (dec: -661863680), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short eventVariables[6]; // size=12, offset=36 //  hashcode: 0xF6988113 (dec: -157777645), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	long FogColor;			 // size=0, offset=48 //  hashcode: 0x09AA685E (dec: 162162782), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short UnitFogFar;		 // size=0, offset=52 //  hashcode: 0x9234EEA2 (dec: -1842024798), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short UnitFogNear;		 // size=0, offset=54 //  hashcode: 0x4C147E54 (dec: 1276411476), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short TargetFogFar;		 // size=0, offset=56 //  hashcode: 0x40A0B5E0 (dec: 1084274144), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short TargetFogNear;	 // size=0, offset=58 //  hashcode: 0xB63649AD (dec: -1237956179), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sfxFileHandle;	 // size=0, offset=60 //  hashcode: 0x608568D6 (dec: 1619355862), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;				 // size=0, offset=62 //  hashcode: 0x92DF4D19 (dec: -1830859495), parent name: '_StreamUnit', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct XAFileInfo // hashcode: 0xD7260012 (dec: -685375470)
{
	int startPos; // size=0, offset=0 //  hashcode: 0x2A3E5B5E (dec: 708729694), parent name: 'XAFileInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CdCommand // hashcode: 0x042C215C (dec: 70000988)
{
	unsigned short flags;		 // size=0, offset=0 //  hashcode: 0x5EC8DC9F (dec: 1590221983), parent name: 'CdCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char unused;		 // size=0, offset=2 //  hashcode: 0x8EF2A6EE (dec: -1896700178), parent name: 'CdCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char cdCommand;	 // size=0, offset=3 //  hashcode: 0x3CE6F8AF (dec: 1021769903), parent name: 'CdCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char cdCmdParam[4]; // size=4, offset=4 //  hashcode: 0xED8E3D3D (dec: -309445315), parent name: 'CdCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VoiceCommand // hashcode: 0xEEB8F864 (dec: -289867676)
{
	unsigned char voiceCmd;		   // size=0, offset=0 //  hashcode: 0xDC3C1FDA (dec: -600039462), parent name: 'VoiceCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char nextVoiceStatus; // size=0, offset=1 //  hashcode: 0x7FED7877 (dec: 2146269303), parent name: 'VoiceCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short voiceCmdParam;  // size=0, offset=2 //  hashcode: 0x8186774D (dec: -2121894067), parent name: 'VoiceCommand', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _LoadQueueEntry // hashcode: 0xFEE70962 (dec: -18413214)
{
	struct _LoadQueueEntry *next;		 // size=64, offset=0 //  hashcode: 0xCA94D546 (dec: -896215738), parent name: '_LoadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short status;						 // size=0, offset=4 //  hashcode: 0x3756C2CB (dec: 928432843), parent name: '_LoadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	char relocateBinary;				 // size=0, offset=6 //  hashcode: 0xDCECAC2B (dec: -588469205), parent name: '_LoadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	char mempackUsed;					 // size=0, offset=7 //  hashcode: 0x33E3363C (dec: 870528572), parent name: '_LoadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _NonBlockLoadEntry loadEntry; // size=56, offset=8 //  hashcode: 0x4314A741 (dec: 1125427009), parent name: '_LoadQueueEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SavedBasic // hashcode: 0x6198E1EF (dec: 1637409263)
{
	unsigned char savedID;		   // size=0, offset=0 //  hashcode: 0x8EBF79CC (dec: -1900054068), parent name: 'SavedBasic', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char shiftedSaveSize; // size=0, offset=1 //  hashcode: 0xC0C3F48D (dec: -1060899699), parent name: 'SavedBasic', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _SavedIntro // hashcode: 0x8389D216 (dec: -2088119786)
{
	unsigned char savedID;				 // size=0, offset=0 //  hashcode: 0x9F02E82E (dec: -1627199442), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char shiftedSaveSize;		 // size=0, offset=1 //  hashcode: 0xA54C5886 (dec: -1521723258), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char lightGroup;			 // size=0, offset=2 //  hashcode: 0xE8D6B2B9 (dec: -388582727), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char specturalLightGroup;   // size=0, offset=3 //  hashcode: 0xAD9F648C (dec: -1382062964), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	char name[8];						 // size=8, offset=4 //  hashcode: 0x61579E62 (dec: 1633132130), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	short introUniqueID;				 // size=0, offset=12 //  hashcode: 0x0C1FB867 (dec: 203405415), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	short streamUnitID;					 // size=0, offset=14 //  hashcode: 0xCC8A5432 (dec: -863349710), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	short birthUnitID;					 // size=0, offset=16 //  hashcode: 0x5B1FFEF2 (dec: 1528823538), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short attachedUniqueID;	 // size=0, offset=18 //  hashcode: 0x19BFC314 (dec: 431997716), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SmallRotation smallRotation; // size=6, offset=20 //  hashcode: 0x428F595D (dec: 1116690781), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position;			 // size=6, offset=26 //  hashcode: 0xDA9008A8 (dec: -628094808), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;							 // size=0, offset=32 //  hashcode: 0xECFBE103 (dec: -319037181), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags2;						 // size=0, offset=36 //  hashcode: 0xCAE51F8F (dec: -890953841), parent name: '_SavedIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SavedEvent // hashcode: 0x429B6172 (dec: 1117479282)
{
	unsigned char savedID;		   // size=0, offset=0 //  hashcode: 0x8A4C3ABF (dec: -1974715713), parent name: 'SavedEvent', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char shiftedSaveSize; // size=0, offset=1 //  hashcode: 0xD1AA0C35 (dec: -777384907), parent name: 'SavedEvent', parent hashcode: 0xFFFFFFFF (dec: -1)
	short areaID;				   // size=0, offset=2 //  hashcode: 0x8F097B9B (dec: -1895203941), parent name: 'SavedEvent', parent hashcode: 0xFFFFFFFF (dec: -1)
	short eventNumber;			   // size=0, offset=4 //  hashcode: 0x5F844075 (dec: 1602502773), parent name: 'SavedEvent', parent hashcode: 0xFFFFFFFF (dec: -1)
	short eventVariables[5];	   // size=10, offset=6 //  hashcode: 0xEA057BFD (dec: -368739331), parent name: 'SavedEvent', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SavedBspTree // hashcode: 0x7AE7209C (dec: 2061967516)
{
	struct _Position localOffset;	  // size=6, offset=0 //  hashcode: 0x1C7CCC38 (dec: 477940792), parent name: 'SavedBspTree', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char importantFlagsSaved; // size=0, offset=6 //  hashcode: 0x4B782EA3 (dec: 1266167459), parent name: 'SavedBspTree', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char bspIndex;			   // size=0, offset=7 //  hashcode: 0x396A5643 (dec: 963270211), parent name: 'SavedBspTree', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EventBasicObject // hashcode: 0x9FC1DB2A (dec: -1614685398)
{
	short id; // size=0, offset=0 //  hashcode: 0x599099E8 (dec: 1502648808), parent name: 'EventBasicObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EventWildCardObject // hashcode: 0x24FF3630 (dec: 620705328)
{
	short id;		  // size=0, offset=0 //  hashcode: 0xA164605B (dec: -1587257253), parent name: 'EventWildCardObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short spad;		  // size=0, offset=2 //  hashcode: 0xC22B0BB2 (dec: -1037366350), parent name: 'EventWildCardObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long unitID;	  // size=0, offset=4 //  hashcode: 0xD568A87A (dec: -714561414), parent name: 'EventWildCardObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *objectName; // size=0, offset=8 //  hashcode: 0x7F4E4A77 (dec: 2135837303), parent name: 'EventWildCardObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct Event // hashcode: 0x68F4AD26 (dec: 1760865574)
{
	short eventNumber;						// size=0, offset=0 //  hashcode: 0xA0939AD4 (dec: -1600939308), parent name: 'Event', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numInstances;						// size=0, offset=2 //  hashcode: 0xFB413530 (dec: -79612624), parent name: 'Event', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char numActions;				// size=0, offset=4 //  hashcode: 0xB23399BC (dec: -1305241156), parent name: 'Event', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char processingPuppetShow;		// size=0, offset=5 //  hashcode: 0x80CE988E (dec: -2133944178), parent name: 'Event', parent hashcode: 0xFFFFFFFF (dec: -1)
	short eventVariables[5];				// size=10, offset=6 //  hashcode: 0x27BBBEAF (dec: 666615471), parent name: 'Event', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct EventBasicObject **instanceList; // size=2, offset=16 //  hashcode: 0xFD5F7979 (dec: -44074631), parent name: 'Event', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct ScriptPCode **conditionalList;   // size=8, offset=20 //  hashcode: 0xF168B7FF (dec: -244795393), parent name: 'Event', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct ScriptPCode **actionList;		// size=8, offset=24 //  hashcode: 0x5B7D28DE (dec: 1534929118), parent name: 'Event', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ScriptPCode // hashcode: 0x5E69DEB9 (dec: 1583996601)
{
	unsigned short sizeOfPcodeStream; // size=0, offset=0 //  hashcode: 0xD0F08437 (dec: -789543881), parent name: 'ScriptPCode', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short conditionBits;	 // size=0, offset=2 //  hashcode: 0x3A0C49EE (dec: 973883886), parent name: 'ScriptPCode', parent hashcode: 0xFFFFFFFF (dec: -1)
	short *data;					  // size=0, offset=4 //  hashcode: 0x1E2FCB64 (dec: 506448740), parent name: 'ScriptPCode', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct InstanceSpline // hashcode: 0x88E38857 (dec: -1998354345)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0x6A7DADBA (dec: 1786621370), parent name: 'InstanceSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *spline; // size=80, offset=4 //  hashcode: 0xC9A2D3DE (dec: -912075810), parent name: 'InstanceSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;				// size=0, offset=8 //  hashcode: 0xEAD2451D (dec: -355318499), parent name: 'InstanceSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	long isParent;				// size=0, offset=12 //  hashcode: 0xD48792E4 (dec: -729312540), parent name: 'InstanceSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	long isClass;				// size=0, offset=16 //  hashcode: 0xE362A1BC (dec: -480075332), parent name: 'InstanceSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	long splineFlags;			// size=0, offset=20 //  hashcode: 0xB815589D (dec: -1206560611), parent name: 'InstanceSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct Vector3d // hashcode: 0x10BF06FC (dec: 280954620)
{
	short vx;		   // size=0, offset=0 //  hashcode: 0x6D235E4D (dec: 1831034445), parent name: 'Vector3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vy;		   // size=0, offset=2 //  hashcode: 0x24D3E177 (dec: 617865591), parent name: 'Vector3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vz;		   // size=0, offset=4 //  hashcode: 0xFFB5E117 (dec: -4857577), parent name: 'Vector3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad1;		   // size=0, offset=6 //  hashcode: 0x825950EF (dec: -2108075793), parent name: 'Vector3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short errorx;	  // size=0, offset=8 //  hashcode: 0x59BD489F (dec: 1505577119), parent name: 'Vector3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short errory;	  // size=0, offset=10 //  hashcode: 0xB5AB181C (dec: -1247078372), parent name: 'Vector3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short errorz;	  // size=0, offset=12 //  hashcode: 0x2C5ADEBF (dec: 744152767), parent name: 'Vector3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad2;		   // size=0, offset=14 //  hashcode: 0xE5A32263 (dec: -442293661), parent name: 'Vector3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamUnitID; // size=0, offset=16 //  hashcode: 0x466D6834 (dec: 1181575220), parent name: 'Vector3d', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct Rotation3d // hashcode: 0x646160C4 (dec: 1684103364)
{
	short vx;		// size=0, offset=0 //  hashcode: 0x9D16F17A (dec: -1659440774), parent name: 'Rotation3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vy;		// size=0, offset=2 //  hashcode: 0xDCF35637 (dec: -588032457), parent name: 'Rotation3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short vz;		// size=0, offset=4 //  hashcode: 0x5913EBA4 (dec: 1494477732), parent name: 'Rotation3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad1;		// size=0, offset=6 //  hashcode: 0x17B1EBEC (dec: 397536236), parent name: 'Rotation3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short errorx;   // size=0, offset=8 //  hashcode: 0xF7FBFF34 (dec: -134480076), parent name: 'Rotation3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short errory;   // size=0, offset=10 //  hashcode: 0x4724D531 (dec: 1193596209), parent name: 'Rotation3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short errorz;   // size=0, offset=12 //  hashcode: 0x16BDF7CD (dec: 381548493), parent name: 'Rotation3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad2;		// size=0, offset=14 //  hashcode: 0xB23F50A8 (dec: -1304473432), parent name: 'Rotation3d', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute; // size=0, offset=16 //  hashcode: 0xCCAB05A4 (dec: -861207132), parent name: 'Rotation3d', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct InstanceObject // hashcode: 0xA445CB1D (dec: -1538929891)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0x6FF90A20 (dec: 1878592032), parent name: 'InstanceObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;				// size=0, offset=4 //  hashcode: 0xA54A10A6 (dec: -1521872730), parent name: 'InstanceObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EventObject // hashcode: 0x38B0B53D (dec: 951104829)
{
	struct Event *event; // size=28, offset=0 //  hashcode: 0x01BEDA5A (dec: 29284954), parent name: 'EventObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;		 // size=0, offset=4 //  hashcode: 0xD221CA88 (dec: -769537400), parent name: 'EventObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SavedEventObject // hashcode: 0xC69C23B2 (dec: -962845774)
{
	struct SavedBasic *savedEvent; // size=2, offset=0 //  hashcode: 0xFBE2452D (dec: -69057235), parent name: 'SavedEventObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;				   // size=0, offset=4 //  hashcode: 0x675EA49F (dec: 1734255775), parent name: 'SavedEventObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long areaID;				   // size=0, offset=8 //  hashcode: 0x3ECECF04 (dec: 1053740804), parent name: 'SavedEventObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long eventNumber;			   // size=0, offset=12 //  hashcode: 0xB440B43A (dec: -1270827974), parent name: 'SavedEventObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GameObject // hashcode: 0xFA1A30A9 (dec: -98946903)
{
	long attribute; // size=0, offset=0 //  hashcode: 0xB4381CAF (dec: -1271391057), parent name: 'GameObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SignalObject // hashcode: 0x42CFA9E2 (dec: 1120905698)
{
	struct _MultiSignal *msignal; // size=904, offset=0 //  hashcode: 0x103B9C59 (dec: 272342105), parent name: 'SignalObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;				  // size=0, offset=4 //  hashcode: 0x9C2D5749 (dec: -1674750135), parent name: 'SignalObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct IntroObject // hashcode: 0x13CCBC8C (dec: 332184716)
{
	struct Intro *intro; // size=76, offset=0 //  hashcode: 0x8DA7A7B6 (dec: -1918392394), parent name: 'IntroObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;		 // size=0, offset=4 //  hashcode: 0x2A3FBCF2 (dec: 708820210), parent name: 'IntroObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct InstanceAnimate // hashcode: 0x200AA21A (dec: 537567770)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0x38A9249C (dec: 950609052), parent name: 'InstanceAnimate', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;				// size=0, offset=4 //  hashcode: 0xA799B517 (dec: -1483098857), parent name: 'InstanceAnimate', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct InstanceAnimateTexture // hashcode: 0x5266C0BB (dec: 1382465723)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0x62E5A18E (dec: 1659216270), parent name: 'InstanceAnimateTexture', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AniTex *aniTextures; // size=16, offset=4 //  hashcode: 0x84E13522 (dec: -2065615582), parent name: 'InstanceAnimateTexture', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;				// size=0, offset=8 //  hashcode: 0x4220F79B (dec: 1109456795), parent name: 'InstanceAnimateTexture', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ListObject // hashcode: 0x1323C7B3 (dec: 321111987)
{
	struct EventWildCardObject *eventInstance; // size=12, offset=0 //  hashcode: 0xF56290D4 (dec: -178089772), parent name: 'ListObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute[5];						   // size=20, offset=4 //  hashcode: 0x32BE1921 (dec: 851319073), parent name: 'ListObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numberOfAttributes;				   // size=0, offset=24 //  hashcode: 0xB346ACF9 (dec: -1287213831), parent name: 'ListObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long lineID;							   // size=0, offset=28 //  hashcode: 0x0D13C584 (dec: 219399556), parent name: 'ListObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SubListObject // hashcode: 0xFDCC28E5 (dec: -36951835)
{
	struct _Instance **instanceList; // size=616, offset=0 //  hashcode: 0x85C76B77 (dec: -2050528393), parent name: 'SubListObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numberOfInstances;			 // size=0, offset=4 //  hashcode: 0xBE04F93E (dec: -1106970306), parent name: 'SubListObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numberOfAttributes;		 // size=0, offset=8 //  hashcode: 0xA3FC0F40 (dec: -1543762112), parent name: 'SubListObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute[5];				 // size=20, offset=12 //  hashcode: 0xFE76C980 (dec: -25769600), parent name: 'SubListObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TGroupObject // hashcode: 0x669B4B67 (dec: 1721453415)
{
	struct BSPTree *bspTree;		// size=36, offset=0 //  hashcode: 0xA6991537 (dec: -1499917001), parent name: 'TGroupObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _StreamUnit *streamUnit; // size=64, offset=4 //  hashcode: 0xA2A540AD (dec: -1566228307), parent name: 'TGroupObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;					// size=0, offset=8 //  hashcode: 0xD8EEA80A (dec: -655448054), parent name: 'TGroupObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short arg[2];					// size=4, offset=12 //  hashcode: 0x1E9A67D2 (dec: 513435602), parent name: 'TGroupObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ConstrictInfo // hashcode: 0xA586BA8A (dec: -1517897078)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0xD33EF9D3 (dec: -750847533), parent name: 'ConstrictInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;				// size=0, offset=4 //  hashcode: 0xC2FBDC9E (dec: -1023681378), parent name: 'ConstrictInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CameraObject // hashcode: 0xD3BF3ACE (dec: -742442290)
{
	struct Camera *camera; // size=1220, offset=0 //  hashcode: 0xE3D18800 (dec: -472807424), parent name: 'CameraObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frames;		   // size=0, offset=4 //  hashcode: 0x636CC6AA (dec: 1668073130), parent name: 'CameraObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;		   // size=0, offset=8 //  hashcode: 0x82542F73 (dec: -2108412045), parent name: 'CameraObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EventVmObject // hashcode: 0x9DE5D8F8 (dec: -1645881096)
{
	struct _VMObject *vmObjectPtr; // size=60, offset=0 //  hashcode: 0x6AC0262A (dec: 1790977578), parent name: 'EventVmObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Level *level;		   // size=392, offset=4 //  hashcode: 0xE6C15FAB (dec: -423534677), parent name: 'EventVmObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;				   // size=0, offset=8 //  hashcode: 0x1B8EACB3 (dec: 462335155), parent name: 'EventVmObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AreaObject // hashcode: 0x38AC5A77 (dec: 950819447)
{
	struct _StreamUnit *streamUnit; // size=64, offset=0 //  hashcode: 0x0F042FAF (dec: 251932591), parent name: 'AreaObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;					// size=0, offset=4 //  hashcode: 0x6305644A (dec: 1661297738), parent name: 'AreaObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long unitID;					// size=0, offset=8 //  hashcode: 0xFBD1182A (dec: -70182870), parent name: 'AreaObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SoundObject // hashcode: 0x9DA5ECE7 (dec: -1650070297)
{
	short flags;	  // size=0, offset=0 //  hashcode: 0x7AEABDDA (dec: 2062204378), parent name: 'SoundObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short attribute;  // size=0, offset=2 //  hashcode: 0xE4B04425 (dec: -458210267), parent name: 'SoundObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long soundNumber; // size=0, offset=4 //  hashcode: 0xC2DDF5C8 (dec: -1025641016), parent name: 'SoundObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value;		  // size=0, offset=8 //  hashcode: 0xFAC13733 (dec: -88000717), parent name: 'SoundObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long duration;	// size=0, offset=12 //  hashcode: 0x87824BCE (dec: -2021504050), parent name: 'SoundObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	;				  // size=4, offset=16 //  hashcode: 0x952EF9A3 (dec: -1792083549), parent name: 'SoundObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __ReaverSaveDat // hashcode: 0x18BBFFA1 (dec: 414973857)
{
	unsigned long pad; // size=0, offset=0 //  hashcode: 0x5B68CF70 (dec: 1533595504), parent name: '__ReaverSaveDat', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GameCheat // hashcode: 0x9BFF36C0 (dec: -1677773120)
{
	unsigned char cheatKeys[12]; // size=12, offset=0 //  hashcode: 0x1CB6F39E (dec: 481751966), parent name: 'GameCheat', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cheatLen;				 // size=0, offset=12 //  hashcode: 0xAA3D38CF (dec: -1438828337), parent name: 'GameCheat', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cheatStage;			 // size=0, offset=14 //  hashcode: 0x9A7B5F63 (dec: -1703190685), parent name: 'GameCheat', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct debug_dispatch_t // hashcode: 0x928EA8E4 (dec: -1836144412)
{
	enum DEBUG_LINE_TYPE type; // size=4, offset=0 //  hashcode: 0x083F990E (dec: 138385678), parent name: 'debug_dispatch_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*fn)();			   // size=0, offset=4 //  hashcode: 0xC2E34713 (dec: -1025292525), parent name: 'debug_dispatch_t', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct debug_format_t // hashcode: 0xCC4C6103 (dec: -867409661)
{
	int xpos;		 // size=0, offset=0 //  hashcode: 0xC702D854 (dec: -956114860), parent name: 'debug_format_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int ypos;		 // size=0, offset=4 //  hashcode: 0xA45DA649 (dec: -1537366455), parent name: 'debug_format_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int is_centered; // size=0, offset=8 //  hashcode: 0xBF3A21FC (dec: -1086709252), parent name: 'debug_format_t', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FXTracker // hashcode: 0xCC65A064 (dec: -865755036)
{
	struct _FX_MATRIX matrixPool[32];   // size=1408, offset=0 //  hashcode: 0x4A17E806 (dec: 1243080710), parent name: '_FXTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType usedMatrixList;		// size=8, offset=1408 //  hashcode: 0xD3E609D8 (dec: -739898920), parent name: '_FXTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType freeMatrixList;		// size=8, offset=1416 //  hashcode: 0x64490764 (dec: 1682507620), parent name: '_FXTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _FX_PRIM primPool[256];		// size=26624, offset=1424 //  hashcode: 0x0DD70DF8 (dec: 232197624), parent name: '_FXTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType usedPrimList;		// size=8, offset=28048 //  hashcode: 0x6244FD37 (dec: 1648688439), parent name: '_FXTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType usedPrimListSprite; // size=8, offset=28056 //  hashcode: 0x1339DA5E (dec: 322558558), parent name: '_FXTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct NodeType freePrimList;		// size=8, offset=28064 //  hashcode: 0x071A50C7 (dec: 119165127), parent name: '_FXTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SignalInfo // hashcode: 0x5899EF0F (dec: 1486483215)
{
	long (*signalHandleFunc)();   // size=0, offset=0 //  hashcode: 0x3FE7BEF6 (dec: 1072152310), parent name: 'SignalInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short length;				  // size=0, offset=4 //  hashcode: 0xFCEF96B2 (dec: -51407182), parent name: 'SignalInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short onlyPlayer;			  // size=0, offset=6 //  hashcode: 0xA3507863 (dec: -1555007389), parent name: 'SignalInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*signalRelocateFunc)(); // size=0, offset=8 //  hashcode: 0x3C27AA97 (dec: 1009232535), parent name: 'SignalInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Vector // hashcode: 0x5DEB6D24 (dec: 1575709988)
{
	long x; // size=0, offset=0 //  hashcode: 0x183E1804 (dec: 406722564), parent name: '_Vector', parent hashcode: 0xFFFFFFFF (dec: -1)
	long y; // size=0, offset=4 //  hashcode: 0x1A2D0179 (dec: 439157113), parent name: '_Vector', parent hashcode: 0xFFFFFFFF (dec: -1)
	long z; // size=0, offset=8 //  hashcode: 0x0AD6D16C (dec: 181850476), parent name: '_Vector', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Triangle2D // hashcode: 0xD422B451 (dec: -735923119)
{
	short x0; // size=0, offset=0 //  hashcode: 0xBEABDF2D (dec: -1096032467), parent name: '_Triangle2D', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0; // size=0, offset=2 //  hashcode: 0xEFB485B3 (dec: -273381965), parent name: '_Triangle2D', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1; // size=0, offset=4 //  hashcode: 0xB0899043 (dec: -1333161917), parent name: '_Triangle2D', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1; // size=0, offset=6 //  hashcode: 0x8A1C2EC5 (dec: -1977864507), parent name: '_Triangle2D', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2; // size=0, offset=8 //  hashcode: 0x41101274 (dec: 1091572340), parent name: '_Triangle2D', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2; // size=0, offset=10 //  hashcode: 0x4D349F22 (dec: 1295294242), parent name: '_Triangle2D', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _PCollideInfo // hashcode: 0x32613C4B (dec: 845233227)
{
	short type;					// size=0, offset=0 //  hashcode: 0xEF8B3703 (dec: -276089085), parent name: '_PCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short segment;				// size=0, offset=2 //  hashcode: 0x00BF26F3 (dec: 12527347), parent name: '_PCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *prim;					// size=0, offset=4 //  hashcode: 0xE0291278 (dec: -534179208), parent name: '_PCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *inst;		// size=0, offset=8 //  hashcode: 0x78627B5B (dec: 2019720027), parent name: '_PCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR wNormal;		// size=8, offset=12 //  hashcode: 0xFBE566D9 (dec: -68852007), parent name: '_PCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR *newPoint;   // size=8, offset=20 //  hashcode: 0x9BE54E46 (dec: -1679471034), parent name: '_PCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR *oldPoint;   // size=8, offset=24 //  hashcode: 0x69F0F58B (dec: 1777399179), parent name: '_PCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR cldPoint;	// size=8, offset=28 //  hashcode: 0xAD7D25F0 (dec: -1384307216), parent name: '_PCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long collideType;			// size=0, offset=36 //  hashcode: 0xFC1456C0 (dec: -65775936), parent name: '_PCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=0, offset=40 //  hashcode: 0xBC294D1E (dec: -1138143970), parent name: '_PCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _HNormal // hashcode: 0xC53FB2BB (dec: -985681221)
{
	short x;   // size=0, offset=0 //  hashcode: 0x6EBB74BB (dec: 1857778875), parent name: '_HNormal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;   // size=0, offset=2 //  hashcode: 0xBD0A433D (dec: -1123400899), parent name: '_HNormal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;   // size=0, offset=4 //  hashcode: 0x939F422F (dec: -1818279377), parent name: '_HNormal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad; // size=0, offset=6 //  hashcode: 0x5E8A0D7B (dec: 1586105723), parent name: '_HNormal', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _HFaceInfo // hashcode: 0x0E79FF8C (dec: 242876300)
{
	long flags;				  // size=0, offset=0 //  hashcode: 0x2A75D7F0 (dec: 712366064), parent name: '_HFaceInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attr;				  // size=0, offset=4 //  hashcode: 0x016A08BA (dec: 23726266), parent name: '_HFaceInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HFace *hface;	 // size=12, offset=8 //  hashcode: 0x95CDA75E (dec: -1781684386), parent name: '_HFaceInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector normal;   // size=8, offset=12 //  hashcode: 0x46F48ECC (dec: 1190432460), parent name: '_HFaceInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HVertex *vertex0; // size=12, offset=20 //  hashcode: 0xA1CB0E43 (dec: -1580528061), parent name: '_HFaceInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HVertex *vertex1; // size=12, offset=24 //  hashcode: 0xACA7B6A8 (dec: -1398294872), parent name: '_HFaceInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HVertex *vertex2; // size=12, offset=28 //  hashcode: 0xA446FE1C (dec: -1538851300), parent name: '_HFaceInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _CollideInfo // hashcode: 0xCA2DF5E9 (dec: -902957591)
{
	void *level;			 // size=0, offset=0 //  hashcode: 0x53119B61 (dec: 1393662817), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;				 // size=0, offset=4 //  hashcode: 0x8914986B (dec: -1995138965), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	char segment;			 // size=0, offset=5 //  hashcode: 0x011FEB8E (dec: 18869134), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	char type0;				 // size=0, offset=6 //  hashcode: 0xD68DE3DF (dec: -695344161), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	char type1;				 // size=0, offset=7 //  hashcode: 0xBB7F1B09 (dec: -1149297911), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *prim0;			 // size=0, offset=8 //  hashcode: 0xAA5BCBFE (dec: -1436824578), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *prim1;			 // size=0, offset=12 //  hashcode: 0x03D75806 (dec: 64444422), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *inst0;			 // size=0, offset=16 //  hashcode: 0xC5CD0992 (dec: -976418414), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *inst1;			 // size=0, offset=20 //  hashcode: 0x65667B20 (dec: 1701215008), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR point0;   // size=8, offset=24 //  hashcode: 0x72E2B95E (dec: 1927461214), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR point1;   // size=8, offset=32 //  hashcode: 0x822619F8 (dec: -2111432200), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position offset; // size=6, offset=40 //  hashcode: 0x869AC941 (dec: -2036676287), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short bspID;			 // size=0, offset=46 //  hashcode: 0x2B597B88 (dec: 727284616), parent name: '_CollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _LCollideInfo // hashcode: 0xCC1DB336 (dec: -870468810)
{
	struct _TFace *tface;	 // size=12, offset=0 //  hashcode: 0xF22E9888 (dec: -231827320), parent name: '_LCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Terrain *terrain; // size=84, offset=4 //  hashcode: 0x6423E187 (dec: 1680073095), parent name: '_LCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int curTree;			  // size=0, offset=8 //  hashcode: 0x8E3301AE (dec: -1909259858), parent name: '_LCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SCollideInfo // hashcode: 0x0DEAD21F (dec: 233493023)
{
	struct _Sphere *sphere;		// size=12, offset=0 //  hashcode: 0xAA4F0A39 (dec: -1437660615), parent name: 'SCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR *oldPos;		// size=8, offset=4 //  hashcode: 0x24F99E95 (dec: 620338837), parent name: 'SCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*collideFunc)();		// size=0, offset=8 //  hashcode: 0x77181FAA (dec: 1998069674), parent name: 'SCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long id;					// size=0, offset=12 //  hashcode: 0x9637A25C (dec: -1774738852), parent name: 'SCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;				// size=0, offset=16 //  hashcode: 0x6A54124B (dec: 1783894603), parent name: 'SCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=20 //  hashcode: 0x4A5BF10E (dec: 1247539470), parent name: 'SCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *prim;					// size=0, offset=24 //  hashcode: 0x43E5B881 (dec: 1139128449), parent name: 'SCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PandTScratch // hashcode: 0x53B2A743 (dec: 1404217155)
{
	struct MATRIX posMatrix;	 // size=32, offset=0 //  hashcode: 0x8C350B22 (dec: -1942680798), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector normal;		 // size=8, offset=32 //  hashcode: 0x6E267F4D (dec: 1848016717), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Vector dpv;			 // size=12, offset=40 //  hashcode: 0xB179CDE0 (dec: -1317417504), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector planePoint;  // size=8, offset=52 //  hashcode: 0x18AA988E (dec: 413833358), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long ignore_attr;			 // size=0, offset=60 //  hashcode: 0x4F4C3D07 (dec: 1330396423), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long accept_attr;			 // size=0, offset=64 //  hashcode: 0xED17D621 (dec: -317204959), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	short *backface_flag;		 // size=0, offset=68 //  hashcode: 0x0C51722D (dec: 206664237), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector newPos;		 // size=8, offset=72 //  hashcode: 0x8A99126F (dec: -1969679761), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldPos;		 // size=8, offset=80 //  hashcode: 0x0B5FA92D (dec: 190818605), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	int flags;					 // size=0, offset=88 //  hashcode: 0x9201D9FF (dec: -1845372417), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	int i;						 // size=0, offset=92 //  hashcode: 0xFCAFC877 (dec: -55588745), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	int slack;					 // size=0, offset=96 //  hashcode: 0x45CE9B94 (dec: 1171168148), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long in_spectral;			 // size=0, offset=100 //  hashcode: 0xFB76AC25 (dec: -76108763), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	short *normalList;			 // size=0, offset=104 //  hashcode: 0x9E4ABD00 (dec: -1639269120), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TVertex *vertexList; // size=12, offset=108 //  hashcode: 0x4AC836C4 (dec: 1254635204), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *result;		 // size=12, offset=112 //  hashcode: 0x451FB795 (dec: 1159706517), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector line;		 // size=8, offset=116 //  hashcode: 0x48684373 (dec: 1214792563), parent name: 'PandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SandHFScratch // hashcode: 0x31C4E20D (dec: 834986509)
{
	struct _SVector normal;		// size=8, offset=0 //  hashcode: 0x4831F9FE (dec: 1211234814), parent name: 'SandHFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX posMatrix;	// size=32, offset=8 //  hashcode: 0x9DEEB877 (dec: -1645299593), parent name: 'SandHFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Vector dpv;			// size=12, offset=40 //  hashcode: 0x44002FB1 (dec: 1140862897), parent name: 'SandHFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector triPoint;   // size=8, offset=52 //  hashcode: 0xB292B371 (dec: -1299008655), parent name: 'SandHFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector planePoint; // size=8, offset=60 //  hashcode: 0xF1325F0A (dec: -248357110), parent name: 'SandHFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SandTScratch // hashcode: 0x2773448F (dec: 661865615)
{
	struct MATRIX posMatrix;		 // size=32, offset=0 //  hashcode: 0xBECEA753 (dec: -1093753005), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Vector dpv;				 // size=12, offset=32 //  hashcode: 0x010E5E0D (dec: 17718797), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HNormal *normalList;	 // size=8, offset=44 //  hashcode: 0x5A1CC228 (dec: 1511834152), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _CollideInfo collideInfo; // size=48, offset=48 //  hashcode: 0xBAF074DC (dec: -1158646564), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HFaceInfo hfaceInfo;	 // size=32, offset=96 //  hashcode: 0x4C91B874 (dec: 1284618356), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector midPoint;		 // size=8, offset=128 //  hashcode: 0x62D6F482 (dec: 1658254466), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector spherePos;		 // size=8, offset=136 //  hashcode: 0x1568ACF1 (dec: 359181553), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*collideFunc)();			 // size=0, offset=144 //  hashcode: 0x9B900165 (dec: -1685061275), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance;		 // size=616, offset=148 //  hashcode: 0x104D52FB (dec: 273502971), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long edge;						 // size=0, offset=152 //  hashcode: 0xEC088E14 (dec: -334983660), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long in_spectral;				 // size=0, offset=156 //  hashcode: 0xFE050F7C (dec: -33222788), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldPos;			 // size=8, offset=160 //  hashcode: 0xAD81F149 (dec: -1383993015), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *prim;						 // size=0, offset=168 //  hashcode: 0x9F44C239 (dec: -1622883783), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector normal;			 // size=8, offset=172 //  hashcode: 0x614F2EFC (dec: 1632579324), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Sphere sphere;			 // size=12, offset=180 //  hashcode: 0x640A6BF9 (dec: 1678404601), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	short result;					 // size=0, offset=192 //  hashcode: 0x788973E3 (dec: 2022274019), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	short i;						 // size=0, offset=194 //  hashcode: 0xD1EA771A (dec: -773163238), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long collide_ignoreAttr;		 // size=0, offset=196 //  hashcode: 0x3E097826 (dec: 1040807974), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long collide_acceptAttr;		 // size=0, offset=200 //  hashcode: 0x958585B9 (dec: -1786411591), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long midRadius;					 // size=0, offset=204 //  hashcode: 0xBE5016E4 (dec: -1102047516), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TVertex *vertexList;	 // size=12, offset=208 //  hashcode: 0xE4499D4E (dec: -464937650), parent name: 'SandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct IandTScratch // hashcode: 0xE0F1425D (dec: -521059747)
{
	struct MATRIX posMatrix;	 // size=32, offset=0 //  hashcode: 0x51AC1CC1 (dec: 1370234049), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector normal;		 // size=8, offset=32 //  hashcode: 0x62A578B4 (dec: 1655011508), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Vector dpv;			 // size=12, offset=40 //  hashcode: 0xCBB7C3EF (dec: -877149201), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector planePoint;  // size=8, offset=52 //  hashcode: 0xA1C874EB (dec: -1580698389), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector line;		 // size=8, offset=60 //  hashcode: 0xC3A2604B (dec: -1012768693), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldPos;		 // size=8, offset=68 //  hashcode: 0x026F3513 (dec: 40842515), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector newPos;		 // size=8, offset=76 //  hashcode: 0x21C78495 (dec: 566723733), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	int i;						 // size=0, offset=84 //  hashcode: 0xCC934323 (dec: -862764253), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long in_spectral;			 // size=0, offset=88 //  hashcode: 0x6ADD46B6 (dec: 1792886454), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	short *normalList;			 // size=0, offset=92 //  hashcode: 0xE9701432 (dec: -378530766), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TVertex *vertexList; // size=12, offset=96 //  hashcode: 0x288A03AE (dec: 680133550), parent name: 'IandTScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PandTFScratch // hashcode: 0x218F0B73 (dec: 563022707)
{
	struct MATRIX posMatrix;	// size=32, offset=0 //  hashcode: 0x672A99DB (dec: 1730845147), parent name: 'PandTFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector planePoint; // size=8, offset=32 //  hashcode: 0xCE5A1EC4 (dec: -832954684), parent name: 'PandTFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector newPos;		// size=8, offset=40 //  hashcode: 0x8115F2B2 (dec: -2129268046), parent name: 'PandTFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldPos;		// size=8, offset=48 //  hashcode: 0x0C68B577 (dec: 208188791), parent name: 'PandTFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector normal;		// size=8, offset=56 //  hashcode: 0x4495546B (dec: 1150637163), parent name: 'PandTFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Vector dpv;			// size=12, offset=64 //  hashcode: 0x5FC1DAB7 (dec: 1606539959), parent name: 'PandTFScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CameraCollisionInfo // hashcode: 0x76C89E59 (dec: 1992859225)
{
	struct _TFace(*tfaceList[5]);	  // size=20, offset=0 //  hashcode: 0x74EE6417 (dec: 1961780247), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Terrain(*tfaceTerrain[5]); // size=20, offset=20 //  hashcode: 0x492EAC0A (dec: 1227795466), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short bspTree[6];				   // size=12, offset=40 //  hashcode: 0xB68473C2 (dec: -1232833598), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lengthList[6];			   // size=12, offset=52 //  hashcode: 0xEAE61A2C (dec: -354018772), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;						   // size=0, offset=64 //  hashcode: 0xD5EC9DDE (dec: -705913378), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long line;						   // size=0, offset=68 //  hashcode: 0xCA7C5922 (dec: -897820382), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long numCollided;				   // size=0, offset=72 //  hashcode: 0xCCECB82E (dec: -856901586), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long lenCenterToExtend;			   // size=0, offset=76 //  hashcode: 0xA581EBAC (dec: -1518212180), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Sphere *start;			   // size=12, offset=80 //  hashcode: 0xFA552EA4 (dec: -95080796), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Sphere *end;			   // size=12, offset=84 //  hashcode: 0x12735630 (dec: 309548592), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long cldLines;					   // size=0, offset=88 //  hashcode: 0x69BEB3C1 (dec: 1774105537), parent name: 'CameraCollisionInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct POLY_GT3 // hashcode: 0x405DA246 (dec: 1079878214)
{
	unsigned long tag;	// size=0, offset=0 //  hashcode: 0xBE8A9AB5 (dec: -1098212683), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;	 // size=0, offset=4 //  hashcode: 0x785FCCA0 (dec: 2019544224), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;	 // size=0, offset=5 //  hashcode: 0x45000AC4 (dec: 1157630660), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;	 // size=0, offset=6 //  hashcode: 0x32D9B328 (dec: 853127976), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code;   // size=0, offset=7 //  hashcode: 0xC602ED1A (dec: -972886758), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;			  // size=0, offset=8 //  hashcode: 0xBE17DBE7 (dec: -1105732633), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;			  // size=0, offset=10 //  hashcode: 0x7E684DEB (dec: 2120764907), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u0;	 // size=0, offset=12 //  hashcode: 0x3705F885 (dec: 923138181), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v0;	 // size=0, offset=13 //  hashcode: 0x2EB067DE (dec: 783312862), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short clut;  // size=0, offset=14 //  hashcode: 0x2C1AFD5D (dec: 739966301), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r1;	 // size=0, offset=16 //  hashcode: 0x1766D7B3 (dec: 392615859), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g1;	 // size=0, offset=17 //  hashcode: 0x4E858BF1 (dec: 1317374961), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b1;	 // size=0, offset=18 //  hashcode: 0xC341687C (dec: -1019123588), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char p1;	 // size=0, offset=19 //  hashcode: 0x1C6D49EC (dec: 476924396), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;			  // size=0, offset=20 //  hashcode: 0xB090760E (dec: -1332709874), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;			  // size=0, offset=22 //  hashcode: 0xFCFB8946 (dec: -50624186), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u1;	 // size=0, offset=24 //  hashcode: 0xBCABD01A (dec: -1129590758), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v1;	 // size=0, offset=25 //  hashcode: 0x6337F204 (dec: 1664610820), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short tpage; // size=0, offset=26 //  hashcode: 0x2CE813C8 (dec: 753406920), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r2;	 // size=0, offset=28 //  hashcode: 0x242D5B3B (dec: 606952251), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g2;	 // size=0, offset=29 //  hashcode: 0x496118CE (dec: 1231100110), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b2;	 // size=0, offset=30 //  hashcode: 0xE38C0927 (dec: -477361881), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char p2;	 // size=0, offset=31 //  hashcode: 0x06F0BC2F (dec: 116440111), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;			  // size=0, offset=32 //  hashcode: 0x2458A5B2 (dec: 609789362), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;			  // size=0, offset=34 //  hashcode: 0xB2E515C7 (dec: -1293609529), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u2;	 // size=0, offset=36 //  hashcode: 0x57C334DF (dec: 1472410847), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v2;	 // size=0, offset=37 //  hashcode: 0x25CA6371 (dec: 634020721), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad2;  // size=0, offset=38 //  hashcode: 0x77B6B984 (dec: 2008463748), parent name: 'POLY_GT3', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct POLY_GT4 // hashcode: 0x596BAA44 (dec: 1500228164)
{
	unsigned long tag;	// size=0, offset=0 //  hashcode: 0x03522704 (dec: 55715588), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;	 // size=0, offset=4 //  hashcode: 0xE3D60335 (dec: -472513739), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;	 // size=0, offset=5 //  hashcode: 0x31D0E196 (dec: 835772822), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;	 // size=0, offset=6 //  hashcode: 0xE1C564FC (dec: -507157252), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code;   // size=0, offset=7 //  hashcode: 0x29B920BF (dec: 699998399), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;			  // size=0, offset=8 //  hashcode: 0xB3E3D0B5 (dec: -1276915531), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;			  // size=0, offset=10 //  hashcode: 0x27B8975A (dec: 666408794), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u0;	 // size=0, offset=12 //  hashcode: 0xD17831B7 (dec: -780652105), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v0;	 // size=0, offset=13 //  hashcode: 0x35B75E85 (dec: 901209733), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short clut;  // size=0, offset=14 //  hashcode: 0xE20653F1 (dec: -502901775), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r1;	 // size=0, offset=16 //  hashcode: 0xB7E1EF91 (dec: -1209929839), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g1;	 // size=0, offset=17 //  hashcode: 0x06CF8466 (dec: 114263142), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b1;	 // size=0, offset=18 //  hashcode: 0x70AF607F (dec: 1890541695), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char p1;	 // size=0, offset=19 //  hashcode: 0x85C66D4F (dec: -2050593457), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;			  // size=0, offset=20 //  hashcode: 0x92C5AA60 (dec: -1832539552), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;			  // size=0, offset=22 //  hashcode: 0x1F4EC695 (dec: 525256341), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u1;	 // size=0, offset=24 //  hashcode: 0xE370E163 (dec: -479141533), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v1;	 // size=0, offset=25 //  hashcode: 0x1E2D57D6 (dec: 506288086), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short tpage; // size=0, offset=26 //  hashcode: 0xDEA755DE (dec: -559458850), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r2;	 // size=0, offset=28 //  hashcode: 0x890E0EDA (dec: -1995567398), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g2;	 // size=0, offset=29 //  hashcode: 0xE46825BF (dec: -462936641), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b2;	 // size=0, offset=30 //  hashcode: 0xFD4806C5 (dec: -45611323), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char p2;	 // size=0, offset=31 //  hashcode: 0x3F1E7AA4 (dec: 1058962084), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;			  // size=0, offset=32 //  hashcode: 0x997AB78C (dec: -1720010868), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;			  // size=0, offset=34 //  hashcode: 0xA2CBAA60 (dec: -1563710880), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u2;	 // size=0, offset=36 //  hashcode: 0x215E270E (dec: 559818510), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v2;	 // size=0, offset=37 //  hashcode: 0x715BFA9F (dec: 1901853343), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad2;  // size=0, offset=38 //  hashcode: 0x619FA6F2 (dec: 1637852914), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r3;	 // size=0, offset=40 //  hashcode: 0x89275E95 (dec: -1993908587), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g3;	 // size=0, offset=41 //  hashcode: 0xBA177650 (dec: -1172867504), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b3;	 // size=0, offset=42 //  hashcode: 0x9EDC1752 (dec: -1629743278), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char p3;	 // size=0, offset=43 //  hashcode: 0xF74348D0 (dec: -146585392), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x3;			  // size=0, offset=44 //  hashcode: 0x03124477 (dec: 51528823), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y3;			  // size=0, offset=46 //  hashcode: 0x7B38C10F (dec: 2067317007), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u3;	 // size=0, offset=48 //  hashcode: 0x7578E5B1 (dec: 1970857393), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v3;	 // size=0, offset=49 //  hashcode: 0xB89054C7 (dec: -1198500665), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad3;  // size=0, offset=50 //  hashcode: 0xB4A55548 (dec: -1264233144), parent name: 'POLY_GT4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _PFace // hashcode: 0xD6E8EAC4 (dec: -689378620)
{
	unsigned long *tag;   // size=0, offset=0 //  hashcode: 0x192AF2BE (dec: 422245054), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;	 // size=0, offset=4 //  hashcode: 0x2F7F2A1B (dec: 796863003), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;	 // size=0, offset=5 //  hashcode: 0x81C26D70 (dec: -2117964432), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;	 // size=0, offset=6 //  hashcode: 0xC0F21D95 (dec: -1057874539), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code;   // size=0, offset=7 //  hashcode: 0x5B0628CD (dec: 1527130317), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;			  // size=0, offset=8 //  hashcode: 0xE14504BF (dec: -515570497), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;			  // size=0, offset=10 //  hashcode: 0x0EC33AC9 (dec: 247675593), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u0;	 // size=0, offset=12 //  hashcode: 0xA1AD1942 (dec: -1582491326), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v0;	 // size=0, offset=13 //  hashcode: 0x16F38B9F (dec: 385059743), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short clut;			  // size=0, offset=14 //  hashcode: 0xAB74E3CE (dec: -1418402866), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;			  // size=0, offset=16 //  hashcode: 0xD280DE64 (dec: -763306396), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;			  // size=0, offset=18 //  hashcode: 0x65D2C543 (dec: 1708311875), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u1;	 // size=0, offset=20 //  hashcode: 0xA39FA19E (dec: -1549819490), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v1;	 // size=0, offset=21 //  hashcode: 0x3CB1CB99 (dec: 1018284953), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short tpage; // size=0, offset=22 //  hashcode: 0x5E3B370E (dec: 1580939022), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;			  // size=0, offset=24 //  hashcode: 0xEA136BBF (dec: -367825985), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;			  // size=0, offset=26 //  hashcode: 0x1C8FC847 (dec: 479184967), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u2;	 // size=0, offset=28 //  hashcode: 0xEDC8BCB2 (dec: -305611598), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v2;	 // size=0, offset=29 //  hashcode: 0xEB5E9507 (dec: -346123001), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad1;			  // size=0, offset=30 //  hashcode: 0xE97923FD (dec: -377936899), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	long pad2;			  // size=0, offset=32 //  hashcode: 0x7D8DB5DA (dec: 2106439130), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
	long pad3;			  // size=0, offset=36 //  hashcode: 0xE87F7997 (dec: -394298985), parent name: '_PFace', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _PolytopeList // hashcode: 0xAC7B9901 (dec: -1401186047)
{
	long numPolytopes;	 // size=0, offset=0 //  hashcode: 0xA5893285 (dec: -1517735291), parent name: '_PolytopeList', parent hashcode: 0xFFFFFFFF (dec: -1)
	void(*polytope[1024]); // size=4096, offset=4 //  hashcode: 0xD8FF0675 (dec: -654375307), parent name: '_PolytopeList', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct UVTYPE // hashcode: 0x7D142F71 (dec: 2098474865)
{
	unsigned char u; // size=0, offset=0 //  hashcode: 0x42B7FF60 (dec: 1119354720), parent name: 'UVTYPE', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v; // size=0, offset=1 //  hashcode: 0x35CEBD18 (dec: 902741272), parent name: 'UVTYPE', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;		 // size=0, offset=2 //  hashcode: 0xE306C083 (dec: -486096765), parent name: 'UVTYPE', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct POLY_G3_SEMITRANS // hashcode: 0x323808D7 (dec: 842533079)
{
	unsigned long tag;		// size=0, offset=0 //  hashcode: 0x2385722E (dec: 595948078), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long dr_tpage; // size=0, offset=4 //  hashcode: 0x36E96E52 (dec: 921267794), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;		// size=0, offset=8 //  hashcode: 0x8B5A1BDA (dec: -1957028902), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;		// size=0, offset=9 //  hashcode: 0xA8DEDBD1 (dec: -1461789743), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;		// size=0, offset=10 //  hashcode: 0xD8FB7C5E (dec: -654607266), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code;		// size=0, offset=11 //  hashcode: 0x58301034 (dec: 1479544884), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;				// size=0, offset=12 //  hashcode: 0x36EF830E (dec: 921666318), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;				// size=0, offset=14 //  hashcode: 0x52ACF878 (dec: 1387067512), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r1;		// size=0, offset=16 //  hashcode: 0x5397A436 (dec: 1402446902), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g1;		// size=0, offset=17 //  hashcode: 0x310AC6A8 (dec: 822789800), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b1;		// size=0, offset=18 //  hashcode: 0x2B1EF59E (dec: 723449246), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad1;		// size=0, offset=19 //  hashcode: 0xD8578E9D (dec: -665350499), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;				// size=0, offset=20 //  hashcode: 0xC06B9D52 (dec: -1066689198), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;				// size=0, offset=22 //  hashcode: 0x07095888 (dec: 118053000), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r2;		// size=0, offset=24 //  hashcode: 0xF55B169F (dec: -178579809), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g2;		// size=0, offset=25 //  hashcode: 0x329AE304 (dec: 849011460), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b2;		// size=0, offset=26 //  hashcode: 0xB4429189 (dec: -1270705783), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad2;		// size=0, offset=27 //  hashcode: 0xE3071164 (dec: -486076060), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;				// size=0, offset=28 //  hashcode: 0xE727ABBB (dec: -416830533), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;				// size=0, offset=30 //  hashcode: 0x4EF083C5 (dec: 1324385221), parent name: 'POLY_G3_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _POLY_NG4 // hashcode: 0x65B704BE (dec: 1706493118)
{
	unsigned long tag;		  // size=0, offset=0 //  hashcode: 0x786EF570 (dec: 2020537712), parent name: '_POLY_NG4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long drawTPage1; // size=0, offset=4 //  hashcode: 0x0ED930BD (dec: 249114813), parent name: '_POLY_NG4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BASIC_G4 p1;	  // size=32, offset=8 //  hashcode: 0x55A16BE7 (dec: 1436642279), parent name: '_POLY_NG4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _GT3ZVertexD3D_Type // hashcode: 0xBD55FA10 (dec: -1118438896)
{
	float x;		   // size=0, offset=0 //  hashcode: 0xC6CCF292 (dec: -959647086), parent name: '_GT3ZVertexD3D_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	float y;		   // size=0, offset=4 //  hashcode: 0x814192CB (dec: -2126409013), parent name: '_GT3ZVertexD3D_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	float z;		   // size=0, offset=8 //  hashcode: 0x454053A1 (dec: 1161843617), parent name: '_GT3ZVertexD3D_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	float rhw;		   // size=0, offset=12 //  hashcode: 0x90B9D15F (dec: -1866870433), parent name: '_GT3ZVertexD3D_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned int rgba; // size=0, offset=16 //  hashcode: 0xEE992457 (dec: -291953577), parent name: '_GT3ZVertexD3D_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	float u;		   // size=0, offset=20 //  hashcode: 0x8E3CC7EB (dec: -1908619285), parent name: '_GT3ZVertexD3D_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	float v;		   // size=0, offset=24 //  hashcode: 0xB55637B4 (dec: -1252640844), parent name: '_GT3ZVertexD3D_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SP_SUBDIV_STRUCT // hashcode: 0x4C4B55E8 (dec: 1280005608)
{
	struct _SVector vertex0;   // size=8, offset=0 //  hashcode: 0xAD86EDAD (dec: -1383666259), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector vertex1;   // size=8, offset=8 //  hashcode: 0x7EDF77A5 (dec: 2128574373), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector vertex2;   // size=8, offset=16 //  hashcode: 0x03A3D930 (dec: 61069616), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR face_v0;	// size=8, offset=24 //  hashcode: 0x5DFC25A4 (dec: 1576805796), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR face_v1;	// size=8, offset=32 //  hashcode: 0xEA9E1DCF (dec: -358736433), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR face_v2;	// size=8, offset=40 //  hashcode: 0xFB867286 (dec: -75074938), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR face_v01;   // size=8, offset=48 //  hashcode: 0x9DC75C6B (dec: -1647879061), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR face_v12;   // size=8, offset=56 //  hashcode: 0x0DBF4E53 (dec: 230641235), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR face_v20;   // size=8, offset=64 //  hashcode: 0x14CAE5FD (dec: 348841469), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct UVTYPE face_uv0;	// size=4, offset=72 //  hashcode: 0xDAA29741 (dec: -626878655), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct UVTYPE face_uv1;	// size=4, offset=76 //  hashcode: 0xD877F612 (dec: -663226862), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct UVTYPE face_uv2;	// size=4, offset=80 //  hashcode: 0xDC4339C6 (dec: -599574074), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct UVTYPE face_uv01;   // size=4, offset=84 //  hashcode: 0x83FDCA5D (dec: -2080519587), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct UVTYPE face_uv12;   // size=4, offset=88 //  hashcode: 0xC2FA948B (dec: -1023765365), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct UVTYPE face_uv20;   // size=4, offset=92 //  hashcode: 0x7EE35CF3 (dec: 2128829683), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _ColorType color0;  // size=4, offset=96 //  hashcode: 0x5FE6FE90 (dec: 1608973968), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _ColorType color1;  // size=4, offset=100 //  hashcode: 0xA81D62FF (dec: -1474469121), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _ColorType color2;  // size=4, offset=104 //  hashcode: 0x3A4832E1 (dec: 977810145), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _ColorType color01; // size=4, offset=108 //  hashcode: 0xFD683308 (dec: -43502840), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _ColorType color12; // size=4, offset=112 //  hashcode: 0x6C93B2E3 (dec: 1821618915), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _ColorType color20; // size=4, offset=116 //  hashcode: 0x3528BCF0 (dec: 891862256), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Vector out[4];	 // size=48, offset=120 //  hashcode: 0xC3320CC8 (dec: -1020130104), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color[4];			   // size=16, offset=168 //  hashcode: 0x3A3D8B36 (dec: 977111862), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	long texinfo[3];		   // size=12, offset=184 //  hashcode: 0x3137C61F (dec: 825738783), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DVECTOR sxy[4];	 // size=16, offset=196 //  hashcode: 0x1A0A4610 (dec: 436880912), parent name: 'SP_SUBDIV_STRUCT', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct CdlFILE // hashcode: 0x2EE126E0 (dec: 786507488)
{
	struct CdlLOC pos;  // size=4, offset=0 //  hashcode: 0xF29C5144 (dec: -224636604), parent name: 'CdlFILE', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long size; // size=0, offset=4 //  hashcode: 0x61EC2F6F (dec: 1642868591), parent name: 'CdlFILE', parent hashcode: 0xFFFFFFFF (dec: -1)
	char name[16];		// size=16, offset=8 //  hashcode: 0x891F2FB9 (dec: -1994444871), parent name: 'CdlFILE', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _LoadStatus // hashcode: 0x3D15BA2C (dec: 1024834092)
{
	struct _ReadQueueEntry currentQueueFile; // size=44, offset=0 //  hashcode: 0xFB0E2667 (dec: -82958745), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long state;								 // size=0, offset=44 //  hashcode: 0xAC0049D0 (dec: -1409267248), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long bytesTransferred;					 // size=0, offset=48 //  hashcode: 0x429F18E0 (dec: 1117722848), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long lastCheckPos;						 // size=0, offset=52 //  hashcode: 0xF09AE050 (dec: -258285488), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long cdWaitTime;						 // size=0, offset=56 //  hashcode: 0x3A057232 (dec: 973435442), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char *compSrcAddr;				 // size=0, offset=60 //  hashcode: 0x5C77AF7C (dec: 1551347580), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char *compDstAddr;				 // size=0, offset=64 //  hashcode: 0x3699AE45 (dec: 916041285), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long compControlbits;					 // size=0, offset=68 //  hashcode: 0xE4610A9E (dec: -463402338), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long compControl;						 // size=0, offset=72 //  hashcode: 0x80A14FC8 (dec: -2136911928), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long compEndBytes;						 // size=0, offset=76 //  hashcode: 0x4C009F1B (dec: 1275109147), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long decompressLen;						 // size=0, offset=80 //  hashcode: 0xD0DB324D (dec: -790941107), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long checksum;							 // size=0, offset=84 //  hashcode: 0x1448D12F (dec: 340316463), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long *checkAddr;						 // size=0, offset=88 //  hashcode: 0xE1734DBB (dec: -512537157), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BigFile bigFile;				 // size=36, offset=92 //  hashcode: 0x04F450D7 (dec: 83120343), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *buffer1;							 // size=0, offset=128 //  hashcode: 0x73E9A110 (dec: 1944690960), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *buffer2;							 // size=0, offset=132 //  hashcode: 0x1CCEBDD8 (dec: 483311064), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	int changeDir;							 // size=0, offset=136 //  hashcode: 0xC7D3EF81 (dec: -942411903), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long endLoadTime;						 // size=0, offset=140 //  hashcode: 0x15C7B22A (dec: 365408810), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long currentDirLoading;					 // size=0, offset=144 //  hashcode: 0x3F63342C (dec: 1063466028), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
	long currentSector;						 // size=0, offset=148 //  hashcode: 0xB681C35E (dec: -1233009826), parent name: '_LoadStatus', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RedirectList // hashcode: 0x4C185B3B (dec: 1276664635)
{
	long numPointers; // size=0, offset=0 //  hashcode: 0xCA632F37 (dec: -899469513), parent name: 'RedirectList', parent hashcode: 0xFFFFFFFF (dec: -1)
	long *data;		  // size=0, offset=4 //  hashcode: 0x37905B9C (dec: 932207516), parent name: 'RedirectList', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DRAWENV // hashcode: 0x1D93A150 (dec: 496214352)
{
	struct RECT clip;	 // size=8, offset=0 //  hashcode: 0x4C63EAC0 (dec: 1281616576), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ofs[2];		  // size=4, offset=8 //  hashcode: 0x811CCC37 (dec: -2128819145), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RECT tw;		  // size=8, offset=12 //  hashcode: 0x235C14A6 (dec: 593237158), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short tpage; // size=0, offset=20 //  hashcode: 0xE83FE25C (dec: -398466468), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char dtd;	// size=0, offset=22 //  hashcode: 0x84ED4935 (dec: -2064824011), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char dfe;	// size=0, offset=23 //  hashcode: 0x5A7DA12B (dec: 1518182699), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char isbg;   // size=0, offset=24 //  hashcode: 0xEDDCCA89 (dec: -304297335), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;	 // size=0, offset=25 //  hashcode: 0x440EF004 (dec: 1141829636), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;	 // size=0, offset=26 //  hashcode: 0x54C07503 (dec: 1421899011), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;	 // size=0, offset=27 //  hashcode: 0x192F6508 (dec: 422536456), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct DR_ENV dr_env; // size=64, offset=28 //  hashcode: 0x9CF0BBB7 (dec: -1661944905), parent name: 'DRAWENV', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DISPENV // hashcode: 0x286FCE3D (dec: 678415933)
{
	struct RECT disp;	  // size=8, offset=0 //  hashcode: 0x9E74ADCC (dec: -1636520500), parent name: 'DISPENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct RECT screen;	// size=8, offset=8 //  hashcode: 0x7ACC2C19 (dec: 2060200985), parent name: 'DISPENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char isinter; // size=0, offset=16 //  hashcode: 0xB5FC78DB (dec: -1241745189), parent name: 'DISPENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char isrgb24; // size=0, offset=17 //  hashcode: 0x61F6050C (dec: 1643513100), parent name: 'DISPENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad0;	// size=0, offset=18 //  hashcode: 0x7C32F70F (dec: 2083714831), parent name: 'DISPENV', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad1;	// size=0, offset=19 //  hashcode: 0xD0CAE7F3 (dec: -792008717), parent name: 'DISPENV', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BLK_FILL // hashcode: 0x2490546A (dec: 613438570)
{
	unsigned long tag;  // size=0, offset=0 //  hashcode: 0xC952401C (dec: -917356516), parent name: 'BLK_FILL', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;   // size=0, offset=4 //  hashcode: 0xFAAE3FCD (dec: -89243699), parent name: 'BLK_FILL', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;   // size=0, offset=5 //  hashcode: 0x5F4DC1D2 (dec: 1598931410), parent name: 'BLK_FILL', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;   // size=0, offset=6 //  hashcode: 0x90542E00 (dec: -1873531392), parent name: 'BLK_FILL', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code; // size=0, offset=7 //  hashcode: 0x299478C4 (dec: 697596100), parent name: 'BLK_FILL', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short x0;  // size=0, offset=8 //  hashcode: 0xF22C3537 (dec: -231983817), parent name: 'BLK_FILL', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short y0;  // size=0, offset=10 //  hashcode: 0xC2BAFFCC (dec: -1027932212), parent name: 'BLK_FILL', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short w;   // size=0, offset=12 //  hashcode: 0xBA30832F (dec: -1171225809), parent name: 'BLK_FILL', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short h;   // size=0, offset=14 //  hashcode: 0x404EFE45 (dec: 1078918725), parent name: 'BLK_FILL', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MainTracker // hashcode: 0x7F315B98 (dec: 2133941144)
{
	long mainState;		// size=0, offset=0 //  hashcode: 0xF9F15A02 (dec: -101623294), parent name: 'MainTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long previousState; // size=0, offset=4 //  hashcode: 0xB5EABACC (dec: -1242907956), parent name: 'MainTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long movieNum;		// size=0, offset=8 //  hashcode: 0x419E5207 (dec: 1100894727), parent name: 'MainTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long done;			// size=0, offset=12 //  hashcode: 0x56D0BE7E (dec: 1456520830), parent name: 'MainTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AnalogueData // hashcode: 0xD8EB0F12 (dec: -655683822)
{
	unsigned short pad; // size=0, offset=0 //  hashcode: 0xD8D2758E (dec: -657295986), parent name: 'AnalogueData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char xR;   // size=0, offset=2 //  hashcode: 0x84491B5B (dec: -2075583653), parent name: 'AnalogueData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char yR;   // size=0, offset=3 //  hashcode: 0xFD3E63AA (dec: -46242902), parent name: 'AnalogueData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char xL;   // size=0, offset=4 //  hashcode: 0xCC80890F (dec: -863991537), parent name: 'AnalogueData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char yL;   // size=0, offset=5 //  hashcode: 0x0BFBC8B2 (dec: 201050290), parent name: 'AnalogueData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct POLY_F4_SEMITRANS // hashcode: 0xE3D17AA2 (dec: -472810846)
{
	unsigned long tag;		// size=0, offset=0 //  hashcode: 0x98A33C45 (dec: -1734132667), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long dr_tpage; // size=0, offset=4 //  hashcode: 0x525DB744 (dec: 1381873476), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;		// size=0, offset=8 //  hashcode: 0x164D4A76 (dec: 374164086), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;		// size=0, offset=9 //  hashcode: 0xE823EDD2 (dec: -400298542), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;		// size=0, offset=10 //  hashcode: 0xDAA20371 (dec: -626916495), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code;		// size=0, offset=11 //  hashcode: 0x9151ED0C (dec: -1856901876), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;				// size=0, offset=12 //  hashcode: 0x30FCE018 (dec: 821878808), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;				// size=0, offset=14 //  hashcode: 0x48D99878 (dec: 1222219896), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;				// size=0, offset=16 //  hashcode: 0xAD46799B (dec: -1387890277), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;				// size=0, offset=18 //  hashcode: 0x13E78BD5 (dec: 333941717), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;				// size=0, offset=20 //  hashcode: 0x754F9545 (dec: 1968149829), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;				// size=0, offset=22 //  hashcode: 0xC3709566 (dec: -1016031898), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x3;				// size=0, offset=24 //  hashcode: 0x9E9C407F (dec: -1633927041), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y3;				// size=0, offset=26 //  hashcode: 0xA162D5A4 (dec: -1587358300), parent name: 'POLY_F4_SEMITRANS', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PhysObProperties // hashcode: 0xD5487B33 (dec: -716670157)
{
	unsigned short version; // size=0, offset=0 //  hashcode: 0x2CA34176 (dec: 748896630), parent name: 'PhysObProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short family;  // size=0, offset=2 //  hashcode: 0x6F0BF69D (dec: 1863055005), parent name: 'PhysObProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short ID;		// size=0, offset=4 //  hashcode: 0x37849938 (dec: 931436856), parent name: 'PhysObProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short Type;	// size=0, offset=6 //  hashcode: 0xEE4C4926 (dec: -296990426), parent name: 'PhysObProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PhysObSplinter // hashcode: 0x933D3752 (dec: -1824704686)
{
	long numSplintData; // size=0, offset=0 //  hashcode: 0x5411882A (dec: 1410435114), parent name: 'PhysObSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *splinterData; // size=0, offset=4 //  hashcode: 0xE48359E9 (dec: -461153815), parent name: 'PhysObSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PhysObWeaponAttributes // hashcode: 0x6EB0170A (dec: 1857033994)
{
	long Damage;					// size=0, offset=0 //  hashcode: 0x727AC17E (dec: 1920647550), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	long AltDamage;					// size=0, offset=4 //  hashcode: 0x38EA81C2 (dec: 954892738), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short knockBackDistance;		// size=0, offset=8 //  hashcode: 0xDD6F3323 (dec: -579914973), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char knockBackFrames;			// size=0, offset=10 //  hashcode: 0x02DEB442 (dec: 48149570), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char dropSound;					// size=0, offset=11 //  hashcode: 0xBF708F16 (dec: -1083142378), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char Class;						// size=0, offset=12 //  hashcode: 0x9BB7F572 (dec: -1682442894), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char ThrowSphere;				// size=0, offset=13 //  hashcode: 0x4E6F9541 (dec: 1315935553), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char LeftHandSphere;			// size=0, offset=14 //  hashcode: 0xA15655CE (dec: -1588177458), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char RightHandSphere;			// size=0, offset=15 //  hashcode: 0x74B7A4C7 (dec: 1958192327), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _PhysObLight *Light;		// size=0, offset=16 //  hashcode: 0x897C1792 (dec: -1988356206), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PhysObSplinter splinter; // size=8, offset=20 //  hashcode: 0x2B328C22 (dec: 724732962), parent name: 'PhysObWeaponAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _PhysObLight // hashcode: 0x873DE727 (dec: -2025986265)
{
	unsigned char length;				// size=0, offset=0 //  hashcode: 0xAD935552 (dec: -1382853294), parent name: '_PhysObLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char segment;				// size=0, offset=1 //  hashcode: 0x853546AF (dec: -2060106065), parent name: '_PhysObLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	short speed;						// size=0, offset=2 //  hashcode: 0xD42244C2 (dec: -735951678), parent name: '_PhysObLight', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct LightTableEntry *lightTable; // size=8, offset=4 //  hashcode: 0xC8B8E0B4 (dec: -927407948), parent name: '_PhysObLight', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __PhysObProjectileData // hashcode: 0x12820E13 (dec: 310513171)
{
	char model;							   // size=0, offset=0 //  hashcode: 0x1D35E28F (dec: 490070671), parent name: '__PhysObProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char startAnim;						   // size=0, offset=1 //  hashcode: 0xCB0D949B (dec: -888302437), parent name: '__PhysObProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char loopAnim;						   // size=0, offset=2 //  hashcode: 0xDDF3FABB (dec: -571213125), parent name: '__PhysObProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char endAnim;						   // size=0, offset=3 //  hashcode: 0x9C01DF96 (dec: -1677598826), parent name: '__PhysObProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;							   // size=0, offset=4 //  hashcode: 0xE0919E81 (dec: -527327615), parent name: '__PhysObProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PhysObWeaponAttributes *weapon; // size=28, offset=8 //  hashcode: 0x59204295 (dec: 1495286421), parent name: '__PhysObProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SwitchData // hashcode: 0x34EE19D8 (dec: 888019416)
{
	short state;	   // size=0, offset=0 //  hashcode: 0x493CF527 (dec: 1228731687), parent name: 'SwitchData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short accumulator; // size=0, offset=2 //  hashcode: 0x3FCA891F (dec: 1070237983), parent name: 'SwitchData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LightTableEntry // hashcode: 0x952494E4 (dec: -1792764700)
{
	short r;	  // size=0, offset=0 //  hashcode: 0x990C37A1 (dec: -1727252575), parent name: 'LightTableEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short g;	  // size=0, offset=2 //  hashcode: 0x0C60BBBC (dec: 207666108), parent name: 'LightTableEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short b;	  // size=0, offset=4 //  hashcode: 0xC9A3829B (dec: -912031077), parent name: 'LightTableEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
	short radius; // size=0, offset=6 //  hashcode: 0xFFD726CC (dec: -2677044), parent name: 'LightTableEntry', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct InterfaceItem // hashcode: 0xB8494031 (dec: -1203158991)
{
	char name[48];				  // size=48, offset=0 //  hashcode: 0x0E607344 (dec: 241201988), parent name: 'InterfaceItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short timeout;		  // size=0, offset=48 //  hashcode: 0x5186B569 (dec: 1367782761), parent name: 'InterfaceItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short buttonTimeout; // size=0, offset=50 //  hashcode: 0x63D76AFC (dec: 1675062012), parent name: 'InterfaceItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short itemType;				  // size=0, offset=52 //  hashcode: 0x232581BF (dec: 589660607), parent name: 'InterfaceItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short nextItem;				  // size=0, offset=54 //  hashcode: 0x2F319B2A (dec: 791780138), parent name: 'InterfaceItem', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct POLY_FT4 // hashcode: 0xAD2AA0E4 (dec: -1389715228)
{
	unsigned long tag;	// size=0, offset=0 //  hashcode: 0xCD016781 (dec: -855545983), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;	 // size=0, offset=4 //  hashcode: 0x4F8F7A3A (dec: 1334803002), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;	 // size=0, offset=5 //  hashcode: 0xA2B60DCB (dec: -1565127221), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;	 // size=0, offset=6 //  hashcode: 0x67B0DF2D (dec: 1739644717), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code;   // size=0, offset=7 //  hashcode: 0x85BC006C (dec: -2051276692), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;			  // size=0, offset=8 //  hashcode: 0x9B4A87E6 (dec: -1689614362), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;			  // size=0, offset=10 //  hashcode: 0x1826C8B5 (dec: 405194933), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u0;	 // size=0, offset=12 //  hashcode: 0xE5256FA6 (dec: -450531418), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v0;	 // size=0, offset=13 //  hashcode: 0xE8A116FE (dec: -392096002), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short clut;  // size=0, offset=14 //  hashcode: 0x5A0DE413 (dec: 1510859795), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;			  // size=0, offset=16 //  hashcode: 0xB9E6F988 (dec: -1176045176), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;			  // size=0, offset=18 //  hashcode: 0x7698ACCA (dec: 1989717194), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u1;	 // size=0, offset=20 //  hashcode: 0x5E0E44E2 (dec: 1577993442), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v1;	 // size=0, offset=21 //  hashcode: 0x52A2B6B2 (dec: 1386395314), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short tpage; // size=0, offset=22 //  hashcode: 0x2F3440CD (dec: 791953613), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;			  // size=0, offset=24 //  hashcode: 0x0B7CC8E1 (dec: 192727265), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;			  // size=0, offset=26 //  hashcode: 0xCE45D5BF (dec: -834284097), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u2;	 // size=0, offset=28 //  hashcode: 0x6B39DA23 (dec: 1798953507), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v2;	 // size=0, offset=29 //  hashcode: 0x759C9140 (dec: 1973195072), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad1;  // size=0, offset=30 //  hashcode: 0x5C80DFBB (dec: 1551949755), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x3;			  // size=0, offset=32 //  hashcode: 0x742248D3 (dec: 1948403923), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y3;			  // size=0, offset=34 //  hashcode: 0x91FD9D99 (dec: -1845650023), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u3;	 // size=0, offset=36 //  hashcode: 0xD546FB65 (dec: -716768411), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v3;	 // size=0, offset=37 //  hashcode: 0x14505E97 (dec: 340811415), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad2;  // size=0, offset=38 //  hashcode: 0x8EA73EA9 (dec: -1901642071), parent name: 'POLY_FT4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FontTracker // hashcode: 0xE32D3F0A (dec: -483574006)
{
	struct FontChar font_buffer[256]; // size=1536, offset=0 //  hashcode: 0x5B3A1402 (dec: 1530532866), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long font_xpos;					  // size=0, offset=1536 //  hashcode: 0xB4B93EA7 (dec: -1262928217), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long font_ypos;					  // size=0, offset=1540 //  hashcode: 0x61FDCDBC (dec: 1644023228), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long font_buffIndex;			  // size=0, offset=1544 //  hashcode: 0x221A1D70 (dec: 572136816), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short font_tpage;				  // size=0, offset=1548 //  hashcode: 0x08EFDE55 (dec: 149937749), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short font_clut;				  // size=0, offset=1550 //  hashcode: 0x415BF029 (dec: 1096544297), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short font_vramU;				  // size=0, offset=1552 //  hashcode: 0x79916141 (dec: 2039570753), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short font_vramV;				  // size=0, offset=1554 //  hashcode: 0xA7E70399 (dec: -1478032487), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short font_width;				  // size=0, offset=1556 //  hashcode: 0xCDDFDFFB (dec: -840966149), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sprite_sort_push;			  // size=0, offset=1558 //  hashcode: 0x059028D6 (dec: 93333718), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short font_vramX;				  // size=0, offset=1560 //  hashcode: 0x0100C3A0 (dec: 16827296), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	short font_vramY;				  // size=0, offset=1562 //  hashcode: 0x87B76FB5 (dec: -2018021451), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char color_global;				  // size=0, offset=1564 //  hashcode: 0x71D32916 (dec: 1909664022), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char color_local;				  // size=0, offset=1565 //  hashcode: 0x9FBB7B08 (dec: -1615103224), parent name: 'FontTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct font_color_t // hashcode: 0x5F515B79 (dec: 1599167353)
{
	int r; // size=0, offset=0 //  hashcode: 0xEC7E46C3 (dec: -327268669), parent name: 'font_color_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int g; // size=0, offset=4 //  hashcode: 0x8B5F3965 (dec: -1956693659), parent name: 'font_color_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int b; // size=0, offset=8 //  hashcode: 0xD71B4A20 (dec: -686077408), parent name: 'font_color_t', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FontPos // hashcode: 0x0084D7DD (dec: 8706013)
{
	char x; // size=0, offset=0 //  hashcode: 0xDDE4C1A3 (dec: -572210781), parent name: 'FontPos', parent hashcode: 0xFFFFFFFF (dec: -1)
	char y; // size=0, offset=1 //  hashcode: 0x291BFCEC (dec: 689700076), parent name: 'FontPos', parent hashcode: 0xFFFFFFFF (dec: -1)
	char w; // size=0, offset=2 //  hashcode: 0xF5DBD91A (dec: -170141414), parent name: 'FontPos', parent hashcode: 0xFFFFFFFF (dec: -1)
	char h; // size=0, offset=3 //  hashcode: 0xADC95CEF (dec: -1379312401), parent name: 'FontPos', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TGroupObject_alt_definition_0001 // hashcode: 0xE78E7F4B (dec: -410091701)
{
	struct BSPTree *bspTree;		// size=36, offset=0 //  hashcode: 0xE2879003 (dec: -494432253), parent name: 'TGroupObject_alt_definition_0001', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _StreamUnit *streamUnit; // size=0, offset=4 //  hashcode: 0xA83F4313 (dec: -1472249069), parent name: 'TGroupObject_alt_definition_0001', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;					// size=0, offset=8 //  hashcode: 0xE406A04F (dec: -469327793), parent name: 'TGroupObject_alt_definition_0001', parent hashcode: 0xFFFFFFFF (dec: -1)
	short arg[2];					// size=4, offset=12 //  hashcode: 0x07829358 (dec: 125997912), parent name: 'TGroupObject_alt_definition_0001', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AreaObject_alt_definition_0001 // hashcode: 0x03F64396 (dec: 66470806)
{
	struct _StreamUnit *streamUnit; // size=0, offset=0 //  hashcode: 0xA8E460B3 (dec: -1461428045), parent name: 'AreaObject_alt_definition_0001', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;					// size=0, offset=4 //  hashcode: 0x1C8DF077 (dec: 479064183), parent name: 'AreaObject_alt_definition_0001', parent hashcode: 0xFFFFFFFF (dec: -1)
	long unitID;					// size=0, offset=8 //  hashcode: 0x3E1EACDE (dec: 1042197726), parent name: 'AreaObject_alt_definition_0001', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct StreamUnitPortal // hashcode: 0x7C52D8D9 (dec: 2085804249)
{
	char tolevelname[16];			  // size=16, offset=0 //  hashcode: 0xAF64698B (dec: -1352373877), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	long MSignalID;					  // size=0, offset=16 //  hashcode: 0x67DD3149 (dec: 1742549321), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;					  // size=0, offset=20 //  hashcode: 0x89976466 (dec: -1986567066), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minx;						  // size=0, offset=24 //  hashcode: 0xD517597D (dec: -719890051), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short miny;						  // size=0, offset=26 //  hashcode: 0xC8012DFE (dec: -939446786), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minz;						  // size=0, offset=28 //  hashcode: 0xB82176A3 (dec: -1205766493), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;					  // size=0, offset=30 //  hashcode: 0x77C049D9 (dec: 2009090521), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxx;						  // size=0, offset=32 //  hashcode: 0xD5329B86 (dec: -718103674), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxy;						  // size=0, offset=34 //  hashcode: 0x9E7B3FAB (dec: -1636089941), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxz;						  // size=0, offset=36 //  hashcode: 0xB96C9A64 (dec: -1184064924), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad2;						  // size=0, offset=38 //  hashcode: 0x4444FB2F (dec: 1145371439), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _StreamUnit *toStreamUnit; // size=64, offset=40 //  hashcode: 0x2662837A (dec: 643990394), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector t1[3];			  // size=24, offset=44 //  hashcode: 0xC469BFB5 (dec: -999702603), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector t2[3];			  // size=24, offset=68 //  hashcode: 0xE7EA50BF (dec: -404074305), parent name: 'StreamUnitPortal', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct JoypadMappingStruct // hashcode: 0x312F2BE8 (dec: 825175016)
{
	unsigned short psxData;		// size=0, offset=0 //  hashcode: 0x881D51BF (dec: -2011344449), parent name: 'JoypadMappingStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short translation; // size=0, offset=2 //  hashcode: 0xA6DF2CC6 (dec: -1495323450), parent name: 'JoypadMappingStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ControllerPacket // hashcode: 0x9621B4F3 (dec: -1776175885)
{
	unsigned char transStatus; // size=0, offset=0 //  hashcode: 0xBADF7D43 (dec: -1159758525), parent name: 'ControllerPacket', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char dataFormat;  // size=0, offset=1 //  hashcode: 0x8A9C2707 (dec: -1969477881), parent name: 'ControllerPacket', parent hashcode: 0xFFFFFFFF (dec: -1)
	;						   // size=32, offset=2 //  hashcode: 0xAF56816A (dec: -1353285270), parent name: 'ControllerPacket', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2EulerAngles_Type // hashcode: 0xB3709AC5 (dec: -1284465979)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x95F20D13 (dec: -1779299053), parent name: '_G2EulerAngles_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x9118431F (dec: -1860680929), parent name: '_G2EulerAngles_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;	 // size=0, offset=4 //  hashcode: 0x13F1660C (dec: 334587404), parent name: '_G2EulerAngles_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short order; // size=0, offset=6 //  hashcode: 0x5DF97F2A (dec: 1576632106), parent name: '_G2EulerAngles_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _AnimSoundData_Type // hashcode: 0x5367FF66 (dec: 1399324518)
{
	short sfxToneID;	  // size=0, offset=0 //  hashcode: 0x268BC670 (dec: 646694512), parent name: '_AnimSoundData_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short volume;		  // size=0, offset=2 //  hashcode: 0x43A9B4B2 (dec: 1135195314), parent name: '_AnimSoundData_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitch;		  // size=0, offset=4 //  hashcode: 0x63C904E4 (dec: 1674118372), parent name: '_AnimSoundData_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minVolDistance; // size=0, offset=6 //  hashcode: 0x07E159DE (dec: 132209118), parent name: '_AnimSoundData_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _InstanceHandle // hashcode: 0xDC7D3685 (dec: -595773819)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0xC46068C7 (dec: -1000314681), parent name: '_InstanceHandle', parent hashcode: 0xFFFFFFFF (dec: -1)
	long instanceID;			// size=0, offset=4 //  hashcode: 0xBB947E30 (dec: -1147896272), parent name: '_InstanceHandle', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evCollideInstanceStatsData // hashcode: 0xD8198216 (dec: -669416938)
{
	struct _Instance *instance;		  // size=616, offset=0 //  hashcode: 0x47B4DB2E (dec: 1203034926), parent name: 'evCollideInstanceStatsData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long distance;			  // size=0, offset=4 //  hashcode: 0xDC244C48 (dec: -601600952), parent name: 'evCollideInstanceStatsData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector relativePosition; // size=8, offset=8 //  hashcode: 0xB119B40E (dec: -1323715570), parent name: 'evCollideInstanceStatsData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long xyDistance;				  // size=0, offset=16 //  hashcode: 0x2F299ABA (dec: 791255738), parent name: 'evCollideInstanceStatsData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long zDelta;					  // size=0, offset=20 //  hashcode: 0x76615985 (dec: 1986091397), parent name: 'evCollideInstanceStatsData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct INICommand // hashcode: 0x04B02DE1 (dec: 78654945)
{
	short command;		 // size=0, offset=0 //  hashcode: 0x4CE52546 (dec: 1290085702), parent name: 'INICommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numParameters; // size=0, offset=2 //  hashcode: 0x79915334 (dec: 2039567156), parent name: 'INICommand', parent hashcode: 0xFFFFFFFF (dec: -1)
	long parameter[0];   // size=0, offset=4 //  hashcode: 0x229D9C16 (dec: 580754454), parent name: 'INICommand', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SavedIntroSmall // hashcode: 0x42C7682C (dec: 1120364588)
{
	unsigned char savedID;		   // size=0, offset=0 //  hashcode: 0x20E2A9C7 (dec: 551725511), parent name: 'SavedIntroSmall', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char shiftedSaveSize; // size=0, offset=1 //  hashcode: 0xD068F0A5 (dec: -798429019), parent name: 'SavedIntroSmall', parent hashcode: 0xFFFFFFFF (dec: -1)
	short introUniqueID;		   // size=0, offset=2 //  hashcode: 0x09D334BD (dec: 164836541), parent name: 'SavedIntroSmall', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SavedIntroSpline // hashcode: 0x018B74DF (dec: 25916639)
{
	unsigned char savedID;		   // size=0, offset=0 //  hashcode: 0xCF3EDF4B (dec: -817963189), parent name: 'SavedIntroSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char shiftedSaveSize; // size=0, offset=1 //  hashcode: 0x0F13F035 (dec: 252964917), parent name: 'SavedIntroSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	short introUniqueID;		   // size=0, offset=2 //  hashcode: 0x36BAFD04 (dec: 918224132), parent name: 'SavedIntroSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splineFlags;			   // size=0, offset=4 //  hashcode: 0x4CC5C597 (dec: 1288029591), parent name: 'SavedIntroSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splineKeyFrame;		   // size=0, offset=6 //  hashcode: 0xBD2E0D77 (dec: -1121055369), parent name: 'SavedIntroSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splineClipBeg;		   // size=0, offset=8 //  hashcode: 0x3BCAE3DE (dec: 1003152350), parent name: 'SavedIntroSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splineClipEnd;		   // size=0, offset=10 //  hashcode: 0xF52B2AD1 (dec: -181720367), parent name: 'SavedIntroSpline', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _SavedIntroWithIntro // hashcode: 0xF234DCD6 (dec: -231416618)
{
	unsigned char savedID;				 // size=0, offset=0 //  hashcode: 0x8F1A8F84 (dec: -1894084732), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char shiftedSaveSize;		 // size=0, offset=1 //  hashcode: 0xCE2AEA2D (dec: -836048339), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short attachedUniqueID;	 // size=0, offset=2 //  hashcode: 0xFDA53D9F (dec: -39502433), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	short introOffset;					 // size=0, offset=4 //  hashcode: 0x7D65DBFE (dec: 2103827454), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	short birthUnitID;					 // size=0, offset=6 //  hashcode: 0xAD70F586 (dec: -1385106042), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	short introUniqueID;				 // size=0, offset=8 //  hashcode: 0xB926C30E (dec: -1188642034), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char lightGroup;			 // size=0, offset=10 //  hashcode: 0x5183D0FE (dec: 1367593214), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char specturalLightGroup;   // size=0, offset=11 //  hashcode: 0x332D1993 (dec: 858593683), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags;							 // size=0, offset=12 //  hashcode: 0xA64D47CE (dec: -1504884786), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	long flags2;						 // size=0, offset=16 //  hashcode: 0xCC6FA251 (dec: -865099183), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SmallRotation smallRotation; // size=6, offset=20 //  hashcode: 0xC4EE43EF (dec: -991018001), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position;			 // size=6, offset=26 //  hashcode: 0xC4E919F6 (dec: -991356426), parent name: '_SavedIntroWithIntro', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterAnim // hashcode: 0xF5F8CA4B (dec: -168244661)
{
	unsigned short velocity;		  // size=0, offset=0 //  hashcode: 0x4CDB0574 (dec: 1289422196), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short distance;		  // size=0, offset=2 //  hashcode: 0x1E43AADC (dec: 507751132), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short playSpeed;		  // size=0, offset=4 //  hashcode: 0x01DA6C19 (dec: 31091737), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char interpFrames;		  // size=0, offset=6 //  hashcode: 0x60D2D2BE (dec: 1624429246), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char startFrame;		  // size=0, offset=7 //  hashcode: 0x59EC2B56 (dec: 1508649814), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char interpOut;		  // size=0, offset=8 //  hashcode: 0xCBBD0416 (dec: -876805098), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char alphaTable;		  // size=0, offset=9 //  hashcode: 0xB0697BEF (dec: -1335264273), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char alphaTableOut;	  // size=0, offset=10 //  hashcode: 0x26C23E6B (dec: 650264171), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char controllingSection; // size=0, offset=11 //  hashcode: 0x4673309B (dec: 1181954203), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	char index[3];					  // size=3, offset=12 //  hashcode: 0xF2FF172A (dec: -218163414), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	char pad;						  // size=0, offset=15 //  hashcode: 0x387D5922 (dec: 947738914), parent name: '_MonsterAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterIdle // hashcode: 0x181712FA (dec: 404165370)
{
	char anim;		  // size=0, offset=0 //  hashcode: 0x11AE2EF5 (dec: 296627957), parent name: '_MonsterIdle', parent hashcode: 0xFFFFFFFF (dec: -1)
	char alertMod;	// size=0, offset=1 //  hashcode: 0x713DC824 (dec: 1899874340), parent name: '_MonsterIdle', parent hashcode: 0xFFFFFFFF (dec: -1)
	char probability; // size=0, offset=2 //  hashcode: 0xE6B270DB (dec: -424513317), parent name: '_MonsterIdle', parent hashcode: 0xFFFFFFFF (dec: -1)
	char pad;		  // size=0, offset=3 //  hashcode: 0xDF690836 (dec: -546764746), parent name: '_MonsterIdle', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterBehavior // hashcode: 0x6D7D1660 (dec: 1836914272)
{
	char alertness;   // size=0, offset=0 //  hashcode: 0x13065412 (dec: 319181842), parent name: '_MonsterBehavior', parent hashcode: 0xFFFFFFFF (dec: -1)
	char idleFreq;	// size=0, offset=1 //  hashcode: 0x7B4177C2 (dec: 2067888066), parent name: '_MonsterBehavior', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numIdles;	// size=0, offset=2 //  hashcode: 0x025D2532 (dec: 39658802), parent name: '_MonsterBehavior', parent hashcode: 0xFFFFFFFF (dec: -1)
	char idleList[5]; // size=5, offset=3 //  hashcode: 0x7B66E39F (dec: 2070340511), parent name: '_MonsterBehavior', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterSenses // hashcode: 0x1AA0E325 (dec: 446751525)
{
	short sightArc;				// size=0, offset=0 //  hashcode: 0x3BF0671D (dec: 1005610781), parent name: '_MonsterSenses', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sightRadius;			// size=0, offset=2 //  hashcode: 0x3BEA3583 (dec: 1005204867), parent name: '_MonsterSenses', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sightElevation;		// size=0, offset=4 //  hashcode: 0xF30E6844 (dec: -217159612), parent name: '_MonsterSenses', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundArc;				// size=0, offset=6 //  hashcode: 0x7BA29C99 (dec: 2074254489), parent name: '_MonsterSenses', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundRadius;			// size=0, offset=8 //  hashcode: 0x7FD08FFA (dec: 2144374778), parent name: '_MonsterSenses', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundElevation;		// size=0, offset=10 //  hashcode: 0xB92979E5 (dec: -1188464155), parent name: '_MonsterSenses', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short scentRadius; // size=0, offset=12 //  hashcode: 0x094BAEAA (dec: 155954858), parent name: '_MonsterSenses', parent hashcode: 0xFFFFFFFF (dec: -1)
	short alarmRadius;			// size=0, offset=14 //  hashcode: 0x0262C2DF (dec: 40026847), parent name: '_MonsterSenses', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short allyRadius;  // size=0, offset=16 //  hashcode: 0xA9517304 (dec: -1454279932), parent name: '_MonsterSenses', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterAllegiances // hashcode: 0x1F15B182 (dec: 521515394)
{
	unsigned long enemies; // size=0, offset=0 //  hashcode: 0x0E8A8977 (dec: 243960183), parent name: '_MonsterAllegiances', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long allies;  // size=0, offset=4 //  hashcode: 0x73836E6A (dec: 1937993322), parent name: '_MonsterAllegiances', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long food;	// size=0, offset=8 //  hashcode: 0xB2E46B0C (dec: -1293653236), parent name: '_MonsterAllegiances', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long gods;	// size=0, offset=12 //  hashcode: 0x6EAF0460 (dec: 1856963680), parent name: '_MonsterAllegiances', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterAttackAttributes // hashcode: 0x4F8BA493 (dec: 1334551699)
{
	short attackRange;			// size=0, offset=0 //  hashcode: 0xE6B47E83 (dec: -424378749), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short attackHeight;			// size=0, offset=2 //  hashcode: 0x97BC874D (dec: -1749252275), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short knockBackDistance;	// size=0, offset=4 //  hashcode: 0xE5B64C8A (dec: -441037686), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char knockBackDuration;		// size=0, offset=6 //  hashcode: 0x4EE86CFD (dec: 1323855101), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char damage;				// size=0, offset=7 //  hashcode: 0x599E155F (dec: 1503532383), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char sphereSegment;			// size=0, offset=8 //  hashcode: 0x30A0DE04 (dec: 815848964), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char sphereOnFrame;			// size=0, offset=9 //  hashcode: 0xB9755618 (dec: -1183492584), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char sphereOnAnim;			// size=0, offset=10 //  hashcode: 0xD935E51C (dec: -650779364), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char sphereOffFrame;		// size=0, offset=11 //  hashcode: 0x5D7FA242 (dec: 1568645698), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char sphereOffAnim;			// size=0, offset=12 //  hashcode: 0x8DD3EAB8 (dec: -1915491656), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char turnFrames;			// size=0, offset=13 //  hashcode: 0x34C2C2F2 (dec: 885179122), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numAnims;				// size=0, offset=14 //  hashcode: 0x7F74B567 (dec: 2138355047), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char attackProbability[12]; // size=12, offset=15 //  hashcode: 0x0376294F (dec: 58075471), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char animList[5];			// size=5, offset=27 //  hashcode: 0x6324EBDE (dec: 1663364062), parent name: '_MonsterAttackAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterMissile // hashcode: 0xC37A9403 (dec: -1015376893)
{
	unsigned short speed;   // size=0, offset=0 //  hashcode: 0x850C34BA (dec: -2062797638), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short range;   // size=0, offset=2 //  hashcode: 0xD88ACDE9 (dec: -661991959), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char frame;	// size=0, offset=4 //  hashcode: 0x52ACB26D (dec: 1387049581), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char anim;		// size=0, offset=5 //  hashcode: 0xE6ABD897 (dec: -424945513), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char segment;  // size=0, offset=6 //  hashcode: 0xC65C9D04 (dec: -967009020), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char damage;   // size=0, offset=7 //  hashcode: 0xFDD30A97 (dec: -36500841), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;		// size=0, offset=8 //  hashcode: 0xB2071A73 (dec: -1308157325), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char graphic;  // size=0, offset=9 //  hashcode: 0x6763A8B5 (dec: 1734584501), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	char gravity;			// size=0, offset=10 //  hashcode: 0x82EF177C (dec: -2098260100), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	char reload;			// size=0, offset=11 //  hashcode: 0x3465644E (dec: 879060046), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	char fireChance;		// size=0, offset=12 //  hashcode: 0x25C7BD2B (dec: 633847083), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char numAnims; // size=0, offset=13 //  hashcode: 0x00AD08FB (dec: 11340027), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
	char animList[2];		// size=2, offset=14 //  hashcode: 0xFA955D22 (dec: -90874590), parent name: '_MonsterMissile', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterCombatAttributes // hashcode: 0x1CD3787B (dec: 483620987)
{
	short stunTime;				// size=0, offset=0 //  hashcode: 0x0C9E853E (dec: 211715390), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short damageTime;			// size=0, offset=2 //  hashcode: 0x6CE699F3 (dec: 1827052019), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short recovery;				// size=0, offset=4 //  hashcode: 0x53CB5161 (dec: 1405833569), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short surpriseTime;			// size=0, offset=6 //  hashcode: 0x32D9FA2E (dec: 853146158), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short grabTime;				// size=0, offset=8 //  hashcode: 0x0B9332B8 (dec: 194196152), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short combatRange;			// size=0, offset=10 //  hashcode: 0xF083688D (dec: -259823475), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short surpriseRange;		// size=0, offset=12 //  hashcode: 0x5BEE1683 (dec: 1542329987), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short allyRange;			// size=0, offset=14 //  hashcode: 0xFC7B68B8 (dec: -59021128), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short enemyAttackRange;		// size=0, offset=16 //  hashcode: 0x0EB1D3E6 (dec: 246535142), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short enemyRunAttackRange;  // size=0, offset=18 //  hashcode: 0x87BEE73C (dec: -2017532100), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short preferredCombatRange; // size=0, offset=20 //  hashcode: 0x3485376A (dec: 881145706), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short suckPower;			// size=0, offset=22 //  hashcode: 0xB854BB6E (dec: -1202406546), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short suckRange;			// size=0, offset=24 //  hashcode: 0xF4CEC73F (dec: -187775169), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short suckTime;				// size=0, offset=26 //  hashcode: 0xE333FF9B (dec: -483131493), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char hitPoints;				// size=0, offset=28 //  hashcode: 0xF73AECDD (dec: -147133219), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numAttacks;			// size=0, offset=29 //  hashcode: 0x75EE3451 (dec: 1978545233), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char missileAttack;			// size=0, offset=30 //  hashcode: 0xA1C26E13 (dec: -1581093357), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char ambushAttack;			// size=0, offset=31 //  hashcode: 0xB3B77EDE (dec: -1279820066), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char evadeProbability[12];  // size=12, offset=32 //  hashcode: 0x0A9B842D (dec: 177964077), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char attackList[1];			// size=1, offset=44 //  hashcode: 0x08EC831D (dec: 149717789), parent name: '_MonsterCombatAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterSubAttributes // hashcode: 0xD249D756 (dec: -766912682)
{
	char *animList;									   // size=0, offset=0 //  hashcode: 0xBB4C3E8A (dec: -1152631158), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterSenses *senses;					   // size=18, offset=4 //  hashcode: 0x3D0CC33B (dec: 1024246587), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterCombatAttributes *combatAttributes; // size=46, offset=8 //  hashcode: 0xA25F0CBA (dec: -1570829126), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterAllegiances *allegiances;		   // size=16, offset=12 //  hashcode: 0x725064C5 (dec: 1917871301), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *behaviorList;								   // size=0, offset=16 //  hashcode: 0x1DECA7D4 (dec: 502048724), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short scale;									   // size=0, offset=20 //  hashcode: 0xA695EB39 (dec: -1500124359), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fallDistance;								   // size=0, offset=22 //  hashcode: 0xE5C14E93 (dec: -440316269), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short defAmbushRange;							   // size=0, offset=24 //  hashcode: 0x097DE633 (dec: 159245875), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fleeRange;								   // size=0, offset=26 //  hashcode: 0xC1FE0F42 (dec: -1040314558), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short speedPivotTurn;							   // size=0, offset=28 //  hashcode: 0x202F1177 (dec: 539955575), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short speedWalkTurn;							   // size=0, offset=30 //  hashcode: 0x76EA9ADD (dec: 1995086557), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short speedRunTurn;								   // size=0, offset=32 //  hashcode: 0x0B1E0EB6 (dec: 186519222), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short speedFleeTurn;							   // size=0, offset=34 //  hashcode: 0x4335E730 (dec: 1127606064), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short forgetTime;								   // size=0, offset=36 //  hashcode: 0x81BB331A (dec: -2118438118), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char modelNum;							   // size=0, offset=38 //  hashcode: 0xB0461FDB (dec: -1337581605), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char physAbility;						   // size=0, offset=39 //  hashcode: 0xCBD4A8C7 (dec: -875255609), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char stunnable;						   // size=0, offset=40 //  hashcode: 0x776C5289 (dec: 2003587721), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char grabable;							   // size=0, offset=41 //  hashcode: 0xE88C156E (dec: -393472658), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char numSections;						   // size=0, offset=42 //  hashcode: 0x03F046F0 (dec: 66078448), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char sectionEnd[3];					   // size=3, offset=43 //  hashcode: 0x20F5F31A (dec: 552989466), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short defPlayerAttitude;						   // size=0, offset=46 //  hashcode: 0x6B27A50A (dec: 1797760266), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short defWanderRange;							   // size=0, offset=48 //  hashcode: 0x0B5D3AFC (dec: 190659324), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short defGuardRange;							   // size=0, offset=50 //  hashcode: 0x6BB12BF4 (dec: 1806773236), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char defInitialBehavior;				   // size=0, offset=52 //  hashcode: 0x565AC0EA (dec: 1448788202), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char defTriggeredBehavior;				   // size=0, offset=53 //  hashcode: 0x1A33FEEB (dec: 439615211), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char defActiveBehavior;							   // size=0, offset=54 //  hashcode: 0x86CA4178 (dec: -2033565320), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char defSpectral;						   // size=0, offset=55 //  hashcode: 0x4B89ADAD (dec: 1267314093), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char sunVuln;							   // size=0, offset=56 //  hashcode: 0xB8A67D8B (dec: -1197048437), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char fireVuln;							   // size=0, offset=57 //  hashcode: 0xBF088A28 (dec: -1089959384), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char waterVuln;						   // size=0, offset=58 //  hashcode: 0xC1A2CAE9 (dec: -1046295831), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char impaleVuln;						   // size=0, offset=59 //  hashcode: 0x04C8BD82 (dec: 80264578), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char soundVuln;						   // size=0, offset=60 //  hashcode: 0x17C20715 (dec: 398591765), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char weaponVuln;						   // size=0, offset=61 //  hashcode: 0x0EC73D10 (dec: 247938320), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char missileVuln;						   // size=0, offset=62 //  hashcode: 0x1F5D856D (dec: 526222701), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char bruiseRed;						   // size=0, offset=63 //  hashcode: 0x80F52391 (dec: -2131418223), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char bruiseGreen;						   // size=0, offset=64 //  hashcode: 0x99364082 (dec: -1724497790), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char bruiseBlue;						   // size=0, offset=65 //  hashcode: 0xBC9CD2C4 (dec: -1130573116), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minSpikeRange;							   // size=0, offset=66 //  hashcode: 0x799CE3AD (dec: 2040325037), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxSpikeRange;							   // size=0, offset=68 //  hashcode: 0x32EAD5D1 (dec: 854250961), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxSpikeAngle;							   // size=0, offset=70 //  hashcode: 0x7844D2CE (dec: 2017776334), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minSpikeHorzSpeed;						   // size=0, offset=72 //  hashcode: 0x09AB6B78 (dec: 162229112), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxSpikeHorzSpeed;						   // size=0, offset=74 //  hashcode: 0x98E4B79B (dec: -1729841253), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxSpikeVertSpeed;						   // size=0, offset=76 //  hashcode: 0x55945492 (dec: 1435784338), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short upOnGroundOffset;							   // size=0, offset=78 //  hashcode: 0x78039E99 (dec: 2013503129), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short downOnGroundOffset;						   // size=0, offset=80 //  hashcode: 0xDEBFF149 (dec: -557846199), parent name: '_MonsterSubAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadInitAttr // hashcode: 0x0549E29A (dec: 88728218)
{
	int updateMode;						// size=0, offset=0 //  hashcode: 0xA9B4C853 (dec: -1447770029), parent name: 'AadInitAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	int numSlots;						// size=0, offset=4 //  hashcode: 0x122207D5 (dec: 304220117), parent name: 'AadInitAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*nonBlockLoadProc)();			// size=0, offset=8 //  hashcode: 0xDF629717 (dec: -547186921), parent name: 'AadInitAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*nonBlockBufferedLoadProc)(); // size=0, offset=12 //  hashcode: 0xBB250499 (dec: -1155201895), parent name: 'AadInitAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (**memoryMallocProc)();		// size=0, offset=16 //  hashcode: 0xC7A8043B (dec: -945290181), parent name: 'AadInitAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*memoryFreeProc)();			// size=0, offset=20 //  hashcode: 0x915EA09C (dec: -1856069476), parent name: 'AadInitAttr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MusicLoadInfo // hashcode: 0xC8F67C40 (dec: -923370432)
{
	int state;							 // size=0, offset=0 //  hashcode: 0x2A00FE35 (dec: 704708149), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nextState;						 // size=0, offset=4 //  hashcode: 0xF43194C2 (dec: -198077246), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int errorStatus;					 // size=0, offset=8 //  hashcode: 0x9B37669F (dec: -1690868065), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int bankLoaded;						 // size=0, offset=12 //  hashcode: 0x4CD1A67A (dec: 1288808058), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int checkMusicDelay;				 // size=0, offset=16 //  hashcode: 0xDB30728A (dec: -617581942), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int currentMusicPlane;				 // size=0, offset=20 //  hashcode: 0xC8F2EF1F (dec: -923603169), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	char currentMusicName[8];			 // size=8, offset=24 //  hashcode: 0x0207E647 (dec: 34072135), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MusicLoadCmd commandQueue[4]; // size=32, offset=32 //  hashcode: 0x7B1D43BE (dec: 2065515454), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int commandIn;						 // size=0, offset=64 //  hashcode: 0x31641503 (dec: 828642563), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int commandOut;						 // size=0, offset=68 //  hashcode: 0xDC53301D (dec: -598527971), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int numCmdsInQueue;					 // size=0, offset=72 //  hashcode: 0x63B9A61B (dec: 1673111067), parent name: 'MusicLoadInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ObjectPeriodicSound // hashcode: 0x931DBADB (dec: -1826768165)
{
	unsigned char type;					 // size=0, offset=0 //  hashcode: 0x393A6813 (dec: 960129043), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char numSfxIDs;			 // size=0, offset=1 //  hashcode: 0x81738108 (dec: -2123136760), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char soundInst;			 // size=0, offset=2 //  hashcode: 0x280FB866 (dec: 672118886), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;				 // size=0, offset=3 //  hashcode: 0xE686DB36 (dec: -427369674), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short minVolDistance;		 // size=0, offset=4 //  hashcode: 0x9BD772E3 (dec: -1680379165), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitch;						 // size=0, offset=6 //  hashcode: 0x723DE05C (dec: 1916657756), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pitchVariation;		 // size=0, offset=8 //  hashcode: 0x3A3D6B67 (dec: 977103719), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char maxVolume;			 // size=0, offset=10 //  hashcode: 0xB57FE884 (dec: -1249908604), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char maxVolVariation;		 // size=0, offset=11 //  hashcode: 0xDCB0DC38 (dec: -592389064), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char initialDelay;			 // size=0, offset=12 //  hashcode: 0xB461AA1B (dec: -1268667877), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char initialDelayVariation; // size=0, offset=13 //  hashcode: 0x1FDB5C41 (dec: 534469697), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char onTime;				 // size=0, offset=14 //  hashcode: 0x2D8144EC (dec: 763446508), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char onTimeVariation;		 // size=0, offset=15 //  hashcode: 0x1FFE0C71 (dec: 536743025), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char offTime;				 // size=0, offset=16 //  hashcode: 0x1516B274 (dec: 353809012), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char offTimeVariation;		 // size=0, offset=17 //  hashcode: 0xF6E4AC6D (dec: -152785811), parent name: 'ObjectPeriodicSound', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ObjectEventSound // hashcode: 0x02927CD2 (dec: 43154642)
{
	unsigned char type;					 // size=0, offset=0 //  hashcode: 0x375DFCA9 (dec: 928906409), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char numSfxIDs;			 // size=0, offset=1 //  hashcode: 0x083FAB7A (dec: 138390394), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char soundInst;			 // size=0, offset=2 //  hashcode: 0x236704EB (dec: 593954027), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;				 // size=0, offset=3 //  hashcode: 0xEF5B2ED2 (dec: -279236910), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short minVolDistance;		 // size=0, offset=4 //  hashcode: 0x1EC3AE50 (dec: 516140624), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitch;						 // size=0, offset=6 //  hashcode: 0x33E03EFD (dec: 870334205), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pitchVariation;		 // size=0, offset=8 //  hashcode: 0xD022F5FD (dec: -803015171), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char maxVolume;			 // size=0, offset=10 //  hashcode: 0x223D1FC1 (dec: 574431169), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char maxVolVariation;		 // size=0, offset=11 //  hashcode: 0xCCBF2380 (dec: -859888768), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char initialDelay;			 // size=0, offset=12 //  hashcode: 0x60DCB389 (dec: 1625076617), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char initialDelayVariation; // size=0, offset=13 //  hashcode: 0xDBE21D52 (dec: -605938350), parent name: 'ObjectEventSound', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ObjectOneShotSound // hashcode: 0xF16FD213 (dec: -244329965)
{
	unsigned char type;					 // size=0, offset=0 //  hashcode: 0x8D5E26FD (dec: -1923209475), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char numSfxIDs;			 // size=0, offset=1 //  hashcode: 0x8665135C (dec: -2040196260), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char soundInst;			 // size=0, offset=2 //  hashcode: 0x8CF90BB4 (dec: -1929835596), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char flags;				 // size=0, offset=3 //  hashcode: 0xA15E5E92 (dec: -1587650926), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short minVolDistance;		 // size=0, offset=4 //  hashcode: 0x4404D1BA (dec: 1141166522), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitch;						 // size=0, offset=6 //  hashcode: 0x6E71AA58 (dec: 1852942936), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pitchVariation;		 // size=0, offset=8 //  hashcode: 0x71223B0A (dec: 1898068746), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char maxVolume;			 // size=0, offset=10 //  hashcode: 0x3E5000CB (dec: 1045430475), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char maxVolVariation;		 // size=0, offset=11 //  hashcode: 0x1B9BC6EB (dec: 463193835), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char initialDelay;			 // size=0, offset=12 //  hashcode: 0xE7E8BB63 (dec: -404178077), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char initialDelayVariation; // size=0, offset=13 //  hashcode: 0x4D2C1267 (dec: 1294733927), parent name: 'ObjectOneShotSound', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SoundEffectChannel // hashcode: 0xA19502FD (dec: -1584069891)
{
	unsigned char inUse;			// size=0, offset=0 //  hashcode: 0xD6A6F070 (dec: -693702544), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char unused;			// size=0, offset=1 //  hashcode: 0xDF09456C (dec: -553040532), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short unused1;			// size=0, offset=2 //  hashcode: 0x22755B50 (dec: 578116432), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long handle;			// size=0, offset=4 //  hashcode: 0x5E541FB9 (dec: 1582571449), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short volume;					// size=0, offset=8 //  hashcode: 0x3D520CAD (dec: 1028787373), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short volumeChangeTime;			// size=0, offset=10 //  hashcode: 0xC2519EF7 (dec: -1034838281), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short volumeChangeTimeSave;		// size=0, offset=12 //  hashcode: 0xE1B1AF70 (dec: -508448912), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short volumeChangePerUpdate;	// size=0, offset=14 //  hashcode: 0x0EA7185B (dec: 245831771), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short volumeChangeSign;			// size=0, offset=16 //  hashcode: 0x0B285366 (dec: 187192166), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short volumeChangeErrPerUpdate; // size=0, offset=18 //  hashcode: 0x0B801F75 (dec: 192946037), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short volumeChangeError;		// size=0, offset=20 //  hashcode: 0x949D5B49 (dec: -1801626807), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitch;					// size=0, offset=22 //  hashcode: 0xF69E960F (dec: -157379057), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitchChangeTime;			// size=0, offset=24 //  hashcode: 0xB6DC3537 (dec: -1227082441), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitchChangeTimeSave;		// size=0, offset=26 //  hashcode: 0xBA1698F4 (dec: -1172924172), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitchChangePerUpdate;		// size=0, offset=28 //  hashcode: 0x44D22ACB (dec: 1154624203), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitchChangeSign;			// size=0, offset=30 //  hashcode: 0x4E5D20EA (dec: 1314726122), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitchChangeErrPerUpdate;  // size=0, offset=32 //  hashcode: 0x1389DFE7 (dec: 327802855), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pitchChangeError;			// size=0, offset=34 //  hashcode: 0xF1E57A16 (dec: -236619242), parent name: 'SoundEffectChannel', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _SBSPLeaf // hashcode: 0xAD21B7BA (dec: -1390299206)
{
	struct _Sphere_noSq sphere; // size=8, offset=0 //  hashcode: 0xE223E229 (dec: -500964823), parent name: '_SBSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Intro **introList;   // size=76, offset=8 //  hashcode: 0xFBCDDD26 (dec: -70394586), parent name: '_SBSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numIntros;			// size=0, offset=12 //  hashcode: 0xAA4749BA (dec: -1438168646), parent name: '_SBSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;				// size=0, offset=14 //  hashcode: 0x16B0D313 (dec: 380687123), parent name: '_SBSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct CDLight **lightList; // size=24, offset=16 //  hashcode: 0x7B3D8A98 (dec: 2067630744), parent name: '_SBSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numLights;			// size=0, offset=20 //  hashcode: 0x29713909 (dec: 695286025), parent name: '_SBSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;					// size=0, offset=22 //  hashcode: 0x4BD391E7 (dec: 1272156647), parent name: '_SBSPLeaf', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BSPScratch // hashcode: 0x17CFF45B (dec: 399504475)
{
	struct MATRIX vv[2];	   // size=64, offset=0 //  hashcode: 0xE802C4A2 (dec: -402471774), parent name: 'BSPScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX camMatrix;   // size=32, offset=64 //  hashcode: 0x56CBAA1B (dec: 1456187931), parent name: 'BSPScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct VECTOR dpv[3];	  // size=48, offset=96 //  hashcode: 0x9A0101FE (dec: -1711209986), parent name: 'BSPScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long d[6];				   // size=24, offset=144 //  hashcode: 0x6DB8C4A8 (dec: 1840825512), parent name: 'BSPScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX boundMatrix; // size=32, offset=168 //  hashcode: 0x67C3AD98 (dec: 1740877208), parent name: 'BSPScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
	long in_spectral;		   // size=0, offset=200 //  hashcode: 0x2455087B (dec: 609552507), parent name: 'BSPScratch', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _ObjectOwnerInfo // hashcode: 0x04BCED5C (dec: 79490396)
{
	long magicnum;		// size=0, offset=0 //  hashcode: 0x726D841A (dec: 1919779866), parent name: '_ObjectOwnerInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short animID;		// size=0, offset=4 //  hashcode: 0x55AD8C8A (dec: 1437437066), parent name: '_ObjectOwnerInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	char objectName[0]; // size=0, offset=6 //  hashcode: 0x6EEE7219 (dec: 1861120537), parent name: '_ObjectOwnerInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ObjectAccess // hashcode: 0x1268C513 (dec: 308856083)
{
	char *objectName; // size=0, offset=0 //  hashcode: 0x114A340C (dec: 290075660), parent name: 'ObjectAccess', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *object;	 // size=0, offset=4 //  hashcode: 0x43185517 (dec: 1125668119), parent name: 'ObjectAccess', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ObjectFunc // hashcode: 0xFDE6E2DA (dec: -35200294)
{
	char *scriptName;				 // size=0, offset=0 //  hashcode: 0xCB045881 (dec: -888907647), parent name: 'ObjectFunc', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*initFunc)();				 // size=0, offset=4 //  hashcode: 0xD2A6E2C8 (dec: -760814904), parent name: 'ObjectFunc', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*processFunc)();			 // size=0, offset=8 //  hashcode: 0xC127B5A4 (dec: -1054362204), parent name: 'ObjectFunc', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*collideFunc)();			 // size=0, offset=12 //  hashcode: 0x75BE1F0E (dec: 1975394062), parent name: 'ObjectFunc', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long (*queryFunc)();	// size=0, offset=16 //  hashcode: 0x5EB7A5BD (dec: 1589093821), parent name: 'ObjectFunc', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*messageFunc)();			 // size=0, offset=20 //  hashcode: 0xF13DEE45 (dec: -247599547), parent name: 'ObjectFunc', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*additionalCollideFunc)(); // size=0, offset=24 //  hashcode: 0x3D5BB016 (dec: 1029419030), parent name: 'ObjectFunc', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*relocateTuneFunc)();		 // size=0, offset=28 //  hashcode: 0x0937A370 (dec: 154641264), parent name: 'ObjectFunc', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*relocateInstObFunc)();	// size=0, offset=32 //  hashcode: 0xC9CD5F0A (dec: -909287670), parent name: 'ObjectFunc', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evAnimationInstanceSwitchData // hashcode: 0xEE7F2A6C (dec: -293655956)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0xAD384A7D (dec: -1388819843), parent name: 'evAnimationInstanceSwitchData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int anim;					// size=0, offset=4 //  hashcode: 0xF1A7C150 (dec: -240664240), parent name: 'evAnimationInstanceSwitchData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int frame;					// size=0, offset=8 //  hashcode: 0xE33F1D82 (dec: -482402942), parent name: 'evAnimationInstanceSwitchData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int frames;					// size=0, offset=12 //  hashcode: 0x2A2EEDC3 (dec: 707718595), parent name: 'evAnimationInstanceSwitchData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int mode;					// size=0, offset=16 //  hashcode: 0xEC030B8D (dec: -335344755), parent name: 'evAnimationInstanceSwitchData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evControlSaveDataData // hashcode: 0xA76A68A9 (dec: -1486198615)
{
	long length; // size=0, offset=0 //  hashcode: 0x34FAFAA2 (dec: 888863394), parent name: 'evControlSaveDataData', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0x33E74DD5 (dec: 870796757), parent name: 'evControlSaveDataData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GenericTune // hashcode: 0x1B714C34 (dec: 460409908)
{
	long flags;		   // size=0, offset=0 //  hashcode: 0x9FE49857 (dec: -1612408745), parent name: 'GenericTune', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *shatterData; // size=0, offset=4 //  hashcode: 0xAB87B3A7 (dec: -1417170009), parent name: 'GenericTune', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct POLY_FT3 // hashcode: 0x1FB59984 (dec: 531995012)
{
	unsigned long tag;	// size=0, offset=0 //  hashcode: 0x0FE3B4C8 (dec: 266581192), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;	 // size=0, offset=4 //  hashcode: 0xFED6AB43 (dec: -19485885), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;	 // size=0, offset=5 //  hashcode: 0x3BBC647F (dec: 1002202239), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;	 // size=0, offset=6 //  hashcode: 0xB2D6B141 (dec: -1294552767), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code;   // size=0, offset=7 //  hashcode: 0x39ACD9AD (dec: 967629229), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;			  // size=0, offset=8 //  hashcode: 0x42E46D99 (dec: 1122266521), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;			  // size=0, offset=10 //  hashcode: 0xC965A7A9 (dec: -916084823), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u0;	 // size=0, offset=12 //  hashcode: 0x3914C637 (dec: 957662775), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v0;	 // size=0, offset=13 //  hashcode: 0x39AA2222 (dec: 967451170), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short clut;  // size=0, offset=14 //  hashcode: 0x1421E8D4 (dec: 337766612), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;			  // size=0, offset=16 //  hashcode: 0x67A80957 (dec: 1739065687), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;			  // size=0, offset=18 //  hashcode: 0x4CC79D98 (dec: 1288150424), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u1;	 // size=0, offset=20 //  hashcode: 0x4DA3B20A (dec: 1302573578), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v1;	 // size=0, offset=21 //  hashcode: 0xC56186BB (dec: -983464261), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short tpage; // size=0, offset=22 //  hashcode: 0xC5F6EAAE (dec: -973673810), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;			  // size=0, offset=24 //  hashcode: 0xB73F7621 (dec: -1220577759), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;			  // size=0, offset=26 //  hashcode: 0x30C7703E (dec: 818376766), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char u2;	 // size=0, offset=28 //  hashcode: 0x66B8D180 (dec: 1723388288), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char v2;	 // size=0, offset=29 //  hashcode: 0x7674F301 (dec: 1987375873), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad1;  // size=0, offset=30 //  hashcode: 0xC54AD8A9 (dec: -984950615), parent name: 'POLY_FT3', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _Mirror // hashcode: 0x6161DBD4 (dec: 1633803220)
{
	short a; // size=0, offset=0 //  hashcode: 0xE7EA999C (dec: -404055652), parent name: '_Mirror', parent hashcode: 0xFFFFFFFF (dec: -1)
	short b; // size=0, offset=2 //  hashcode: 0xF235BF90 (dec: -231358576), parent name: '_Mirror', parent hashcode: 0xFFFFFFFF (dec: -1)
	short c; // size=0, offset=4 //  hashcode: 0x616092DD (dec: 1633719005), parent name: '_Mirror', parent hashcode: 0xFFFFFFFF (dec: -1)
	short d; // size=0, offset=6 //  hashcode: 0x9AF4CF4D (dec: -1695232179), parent name: '_Mirror', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FXHalvePlane // hashcode: 0x10EBCD5A (dec: 283888986)
{
	void *next;						  // size=0, offset=0 //  hashcode: 0xDC2D21CA (dec: -601022006), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *continue_process;			  // size=0, offset=4 //  hashcode: 0xA470B66F (dec: -1536117137), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance;		  // size=616, offset=8 //  hashcode: 0x60B8C40E (dec: 1622721550), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char effectType;		  // size=0, offset=12 //  hashcode: 0xABEFF58A (dec: -1410337398), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;				  // size=0, offset=13 //  hashcode: 0xEC38C608 (dec: -331823608), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;					  // size=0, offset=14 //  hashcode: 0x5057CEDF (dec: 1347931871), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	long diffTime;					  // size=0, offset=16 //  hashcode: 0xC54CA347 (dec: -984833209), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _PlaneConstants ringPlane; // size=12, offset=20 //  hashcode: 0x159D38D6 (dec: 362625238), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	long currentColor;				  // size=0, offset=32 //  hashcode: 0xADD90AA6 (dec: -1378284890), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	long *colorArray;				  // size=0, offset=36 //  hashcode: 0x2AD72B1E (dec: 718744350), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numColors;				  // size=0, offset=40 //  hashcode: 0x38FB83FA (dec: 956007418), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
	short colorBlendLife;			  // size=0, offset=42 //  hashcode: 0xA5AFBD2B (dec: -1515209429), parent name: '_FXHalvePlane', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FXGlowEffect // hashcode: 0xCE07D6ED (dec: -838347027)
{
	void *next;					// size=0, offset=0 //  hashcode: 0x777F7481 (dec: 2004841601), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *continue_process;		// size=0, offset=4 //  hashcode: 0x55BD79D8 (dec: 1438480856), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=8 //  hashcode: 0x6BEF8EF7 (dec: 1810861815), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char effectType;   // size=0, offset=12 //  hashcode: 0x329F814F (dec: 849314127), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;			// size=0, offset=13 //  hashcode: 0xA008D8E8 (dec: -1610032920), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;				// size=0, offset=14 //  hashcode: 0x29406ED8 (dec: 692088536), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long diffTime;		// size=0, offset=16 //  hashcode: 0x50635F30 (dec: 1348689712), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	long *colorArray;			// size=0, offset=20 //  hashcode: 0xF7D999F1 (dec: -136734223), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	long currentColor;			// size=0, offset=24 //  hashcode: 0x4FFEAC23 (dec: 1342090275), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numColors;			// size=0, offset=28 //  hashcode: 0xF2FCC473 (dec: -218315661), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short colorBlendCycle;		// size=0, offset=30 //  hashcode: 0x4611B94D (dec: 1175566669), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short width;				// size=0, offset=32 //  hashcode: 0x20FDA4D4 (dec: 553493716), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short height;				// size=0, offset=34 //  hashcode: 0x257D4FBE (dec: 628969406), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char numSegments;  // size=0, offset=36 //  hashcode: 0xC7DEE4C1 (dec: -941693759), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char SegmentInc;   // size=0, offset=37 //  hashcode: 0x6A55D8BB (dec: 1784010939), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short segment;				// size=0, offset=38 //  hashcode: 0x1770CBBF (dec: 393268159), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadein_time;			// size=0, offset=40 //  hashcode: 0x824E46D3 (dec: -2108799277), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadeout_time;			// size=0, offset=42 //  hashcode: 0xBB96D08E (dec: -1147744114), parent name: '_FXGlowEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TransformAnimatedInstanceVerticesWork_t // hashcode: 0x7584B74F (dec: 1971631951)
{
	struct MATRIX scTransform;  // size=32, offset=0 //  hashcode: 0xB2FFA2EF (dec: -1291869457), parent name: 'TransformAnimatedInstanceVerticesWork_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX mirrorMatrix; // size=32, offset=32 //  hashcode: 0xDFB5D800 (dec: -541730816), parent name: 'TransformAnimatedInstanceVerticesWork_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX llm;			// size=32, offset=64 //  hashcode: 0xCC85C1FB (dec: -863649285), parent name: 'TransformAnimatedInstanceVerticesWork_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Vector vector;		// size=12, offset=96 //  hashcode: 0x703980D9 (dec: 1882816729), parent name: 'TransformAnimatedInstanceVerticesWork_t', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FXSplinter // hashcode: 0x3E763456 (dec: 1047934038)
{
	short flags;	   // size=0, offset=0 //  hashcode: 0x289DFF38 (dec: 681443128), parent name: 'FXSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundFx;	 // size=0, offset=2 //  hashcode: 0xFFE2480E (dec: -1947634), parent name: 'FXSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
	short chunkVelXY;  // size=0, offset=4 //  hashcode: 0x341D3DEC (dec: 874331628), parent name: 'FXSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
	short chunkVelZ;   // size=0, offset=6 //  hashcode: 0xDB11C0FE (dec: -619593474), parent name: 'FXSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
	short chunkVelRng; // size=0, offset=8 //  hashcode: 0xECDB74C7 (dec: -321162041), parent name: 'FXSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
	short triVelRng;   // size=0, offset=10 //  hashcode: 0x42AB1582 (dec: 1118508418), parent name: 'FXSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifetime;	// size=0, offset=12 //  hashcode: 0xDF895D27 (dec: -544645849), parent name: 'FXSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
	short faceLimit;   // size=0, offset=14 //  hashcode: 0xAC74E668 (dec: -1401624984), parent name: 'FXSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rotRateRng;  // size=0, offset=16 //  hashcode: 0x716C95A6 (dec: 1902941606), parent name: 'FXSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
	short gravityZ;	// size=0, offset=18 //  hashcode: 0x14D4563A (dec: 349460026), parent name: 'FXSplinter', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DR_TPAGE // hashcode: 0xA93EABEF (dec: -1455510545)
{
	unsigned long tag;	 // size=0, offset=0 //  hashcode: 0x4FAD28E8 (dec: 1336748264), parent name: 'DR_TPAGE', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long code[1]; // size=4, offset=4 //  hashcode: 0x42985F7D (dec: 1117282173), parent name: 'DR_TPAGE', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _POLY_SG4 // hashcode: 0xA49EA007 (dec: -1533108217)
{
	unsigned long tag;		  // size=0, offset=0 //  hashcode: 0xD4A49BC5 (dec: -727409723), parent name: '_POLY_SG4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long drawTPage1; // size=0, offset=4 //  hashcode: 0x67D71723 (dec: 1742149411), parent name: '_POLY_SG4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BASIC_G4 p1;	  // size=32, offset=8 //  hashcode: 0xE3E208CE (dec: -471725874), parent name: '_POLY_SG4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long drawTPage2; // size=0, offset=40 //  hashcode: 0x66B726A3 (dec: 1723279011), parent name: '_POLY_SG4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BASIC_F4 p2;	  // size=20, offset=44 //  hashcode: 0xFA051EDF (dec: -100327713), parent name: '_POLY_SG4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FXGeneralEffect // hashcode: 0xC4783451 (dec: -998755247)
{
	void *next;					// size=0, offset=0 //  hashcode: 0x1F9D7D16 (dec: 530414870), parent name: '_FXGeneralEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *continue_process;		// size=0, offset=4 //  hashcode: 0xECB75CF5 (dec: -323527435), parent name: '_FXGeneralEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=8 //  hashcode: 0x7DA8E1A8 (dec: 2108219816), parent name: '_FXGeneralEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char effectType;   // size=0, offset=12 //  hashcode: 0xAD4ECC4A (dec: -1387344822), parent name: '_FXGeneralEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;			// size=0, offset=13 //  hashcode: 0xD38627FB (dec: -746182661), parent name: '_FXGeneralEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;				// size=0, offset=14 //  hashcode: 0xDDBAC6F9 (dec: -574961927), parent name: '_FXGeneralEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FXRibbon // hashcode: 0xB11070B8 (dec: -1324322632)
{
	void *next;					// size=0, offset=0 //  hashcode: 0x056D852E (dec: 91063598), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *continue_process;		// size=0, offset=4 //  hashcode: 0xACC891BA (dec: -1396141638), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=8 //  hashcode: 0xCDC03BEC (dec: -843039764), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char effectType;   // size=0, offset=12 //  hashcode: 0x0B3DCBBC (dec: 188599228), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;			// size=0, offset=13 //  hashcode: 0x1E4C8317 (dec: 508330775), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;				// size=0, offset=14 //  hashcode: 0x4495A7C7 (dec: 1150658503), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	short numberVerts;			// size=0, offset=16 //  hashcode: 0xD42D12E3 (dec: -735243549), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	short endIndex;				// size=0, offset=18 //  hashcode: 0x18F8C28B (dec: 418955915), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct SVECTOR *vertexPool; // size=8, offset=20 //  hashcode: 0xA524991C (dec: -1524328164), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startSegment;			// size=0, offset=24 //  hashcode: 0x93B4A51B (dec: -1816877797), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	short endSegment;			// size=0, offset=26 //  hashcode: 0x538DAFC5 (dec: 1401794501), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	long startColor;			// size=0, offset=28 //  hashcode: 0x4893A6A7 (dec: 1217636007), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	long endColor;				// size=0, offset=32 //  hashcode: 0x5A645082 (dec: 1516523650), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	short colorStepValue;		// size=0, offset=36 //  hashcode: 0xA4B98F84 (dec: -1531342972), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	short faceLifeTime;			// size=0, offset=38 //  hashcode: 0x5B36C1B8 (dec: 1530315192), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startFadeValue;		// size=0, offset=40 //  hashcode: 0x45149539 (dec: 1158976825), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadeStep;				// size=0, offset=42 //  hashcode: 0xCB476C14 (dec: -884511724), parent name: '_FXRibbon', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FXParticle // hashcode: 0xDD6F143E (dec: -579922882)
{
	void *next;					   // size=0, offset=0 //  hashcode: 0x461C8125 (dec: 1176273189), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *continue_process;		   // size=0, offset=4 //  hashcode: 0x839E23C7 (dec: -2086788153), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance;	// size=616, offset=8 //  hashcode: 0x840608DB (dec: -2079979301), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char effectType;	  // size=0, offset=12 //  hashcode: 0xCFAE488B (dec: -810661749), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;			   // size=0, offset=13 //  hashcode: 0x1F4BFD8C (dec: 525073804), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;				   // size=0, offset=14 //  hashcode: 0x68ECD6CB (dec: 1760351947), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct TextureMT3 *texture;	// size=16, offset=16 //  hashcode: 0xA45874DB (dec: -1537706789), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fxprim_modify_process;   // size=0, offset=20 //  hashcode: 0x2465EF96 (dec: 610660246), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fxprim_process;		   // size=0, offset=24 //  hashcode: 0x18CA35BD (dec: 415905213), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	short size;					   // size=0, offset=28 //  hashcode: 0xFB95B5AF (dec: -74074705), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	short primLifeTime;			   // size=0, offset=30 //  hashcode: 0x24ECCC15 (dec: 619498517), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	short birthRadius;			   // size=0, offset=32 //  hashcode: 0x92F5AE45 (dec: -1829392827), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	short scaleSpeed;			   // size=0, offset=34 //  hashcode: 0x4EC47547 (dec: 1321497927), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position direction;	// size=6, offset=36 //  hashcode: 0x9F67E731 (dec: -1620580559), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short flag_bits;	  // size=0, offset=42 //  hashcode: 0x68A2DE71 (dec: 1755504241), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position acceleration; // size=6, offset=44 //  hashcode: 0x314B8948 (dec: 827033928), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startScale;			   // size=0, offset=50 //  hashcode: 0xAD58E74E (dec: -1386682546), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position offset;	   // size=6, offset=52 //  hashcode: 0x92AEB6B4 (dec: -1834043724), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	char startSegment;			   // size=0, offset=58 //  hashcode: 0x85051D07 (dec: -2063262457), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	char z_undulate;			   // size=0, offset=59 //  hashcode: 0x678AEC64 (dec: 1737157732), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	long startColor;			   // size=0, offset=60 //  hashcode: 0x435F82D8 (dec: 1130332888), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	long endColor;				   // size=0, offset=64 //  hashcode: 0x47E09D6E (dec: 1205902702), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	short colorStepValue;		   // size=0, offset=68 //  hashcode: 0x3E5392D8 (dec: 1045664472), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numberBirthParticles;	 // size=0, offset=70 //  hashcode: 0x6F3CE68A (dec: 1866262154), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	char endSegment;			   // size=0, offset=71 //  hashcode: 0xCCF3E16B (dec: -856432277), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startFadeValue;		   // size=0, offset=72 //  hashcode: 0x67439963 (dec: 1732483427), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadeStep;				   // size=0, offset=74 //  hashcode: 0xC0364F05 (dec: -1070182651), parent name: '_FXParticle', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FXLightBeam // hashcode: 0xDC9CA53F (dec: -593713857)
{
	void *next;					// size=0, offset=0 //  hashcode: 0x44A4FE33 (dec: 1151663667), parent name: '_FXLightBeam', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *continue_process;		// size=0, offset=4 //  hashcode: 0x92230972 (dec: -1843197582), parent name: '_FXLightBeam', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=8 //  hashcode: 0x05586785 (dec: 89679749), parent name: '_FXLightBeam', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char effectType;   // size=0, offset=12 //  hashcode: 0x57F20C65 (dec: 1475480677), parent name: '_FXLightBeam', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;			// size=0, offset=13 //  hashcode: 0x7C9595E8 (dec: 2090178024), parent name: '_FXLightBeam', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;				// size=0, offset=14 //  hashcode: 0x85ADE82A (dec: -2052200406), parent name: '_FXLightBeam', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startSeg;				// size=0, offset=16 //  hashcode: 0x58DC47BF (dec: 1490831295), parent name: '_FXLightBeam', parent hashcode: 0xFFFFFFFF (dec: -1)
	short endSeg;				// size=0, offset=18 //  hashcode: 0x94F98912 (dec: -1795585774), parent name: '_FXLightBeam', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color;					// size=0, offset=20 //  hashcode: 0xC1C7140A (dec: -1043917814), parent name: '_FXLightBeam', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FXBlastringEffect // hashcode: 0x2F8F0E55 (dec: 797904469)
{
	void *next;					// size=0, offset=0 //  hashcode: 0xC6243C7C (dec: -970703748), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *continue_process;		// size=0, offset=4 //  hashcode: 0x2A7835E5 (dec: 712521189), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=8 //  hashcode: 0x23DBC99E (dec: 601606558), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char effectType;   // size=0, offset=12 //  hashcode: 0x9E34B068 (dec: -1640714136), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;			// size=0, offset=13 //  hashcode: 0x30795D3E (dec: 813260094), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;				// size=0, offset=14 //  hashcode: 0xEE20786D (dec: -299861907), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector position;   // size=8, offset=16 //  hashcode: 0xBCC0B3A2 (dec: -1128221790), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MATRIX matrix;		// size=32, offset=24 //  hashcode: 0xC55FBC94 (dec: -983581548), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short segment;				// size=0, offset=56 //  hashcode: 0xF1C61BBF (dec: -238675009), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;					// size=0, offset=58 //  hashcode: 0x2EE0B64B (dec: 786478667), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int radius;					// size=0, offset=60 //  hashcode: 0x64CF8E02 (dec: 1691323906), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int size1;					// size=0, offset=64 //  hashcode: 0xB13C4517 (dec: -1321450217), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int size2;					// size=0, offset=68 //  hashcode: 0x9AFB4D85 (dec: -1694806651), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int startRadius;			// size=0, offset=72 //  hashcode: 0x9D3B98A3 (dec: -1657038685), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int endRadius;				// size=0, offset=76 //  hashcode: 0x9CC01C92 (dec: -1665131374), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int colorchange_radius;		// size=0, offset=80 //  hashcode: 0x86C29E6E (dec: -2034065810), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int vel;					// size=0, offset=84 //  hashcode: 0x9D29DC6D (dec: -1658200979), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int accl;					// size=0, offset=88 //  hashcode: 0x439556F0 (dec: 1133860592), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int height1;				// size=0, offset=92 //  hashcode: 0x7EECD58E (dec: 2129450382), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int height2;				// size=0, offset=96 //  hashcode: 0x8A0CF25E (dec: -1978863010), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	int height3;				// size=0, offset=100 //  hashcode: 0x3BFF55CA (dec: 1006589386), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	char predator_offset;		// size=0, offset=104 //  hashcode: 0xB78D3ACE (dec: -1215481138), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	char predator_offset_orig;  // size=0, offset=105 //  hashcode: 0x3D3091F1 (dec: 1026593265), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	char stay_in_place;			// size=0, offset=106 //  hashcode: 0xF2E8D397 (dec: -219622505), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	char sortInWorld;			// size=0, offset=107 //  hashcode: 0x7367ABD5 (dec: 1936174037), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color;					// size=0, offset=108 //  hashcode: 0x5CC5628B (dec: 1556439691), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	long startColor;			// size=0, offset=112 //  hashcode: 0x1631300D (dec: 372322317), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	long endColor;				// size=0, offset=116 //  hashcode: 0x4A5EF841 (dec: 1247737921), parent name: '_FXBlastringEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FXForceFieldEffect // hashcode: 0x59105BC4 (dec: 1494244292)
{
	void *next;					// size=0, offset=0 //  hashcode: 0x174119ED (dec: 390142445), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *continue_process;		// size=0, offset=4 //  hashcode: 0x08938F17 (dec: 143888151), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=8 //  hashcode: 0xDCC7202B (dec: -590929877), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char effectType;   // size=0, offset=12 //  hashcode: 0x3CDA398B (dec: 1020934539), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;			// size=0, offset=13 //  hashcode: 0xBDE02CD8 (dec: -1109381928), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;				// size=0, offset=14 //  hashcode: 0x42E6C32B (dec: 1122419499), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset;		// size=8, offset=16 //  hashcode: 0xDBCD02AF (dec: -607321425), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short size;					// size=0, offset=24 //  hashcode: 0xE1B6DF4B (dec: -508108981), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short size_diff;			// size=0, offset=26 //  hashcode: 0x025CF3B0 (dec: 39646128), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short size_change;			// size=0, offset=28 //  hashcode: 0x4479F6D7 (dec: 1148843735), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short deg;					// size=0, offset=30 //  hashcode: 0xF6A65E73 (dec: -156869005), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short deg_change;			// size=0, offset=32 //  hashcode: 0x6E0D5A42 (dec: 1846368834), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short start_fade;			// size=0, offset=34 //  hashcode: 0x68397CDC (dec: 1748597980), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	short end_fade;				// size=0, offset=36 //  hashcode: 0xEE8018E4 (dec: -293594908), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color;					// size=0, offset=40 //  hashcode: 0x8BF69A1B (dec: -1946772965), parent name: '_FXForceFieldEffect', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FXLightning // hashcode: 0x552145A3 (dec: 1428243875)
{
	void *next;						// size=0, offset=0 //  hashcode: 0x0BF2E824 (dec: 200468516), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *continue_process;			// size=0, offset=4 //  hashcode: 0x3F018F8A (dec: 1057066890), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance;		// size=616, offset=8 //  hashcode: 0x9C99A12C (dec: -1667653332), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char effectType;		// size=0, offset=12 //  hashcode: 0xA004DB26 (dec: -1610294490), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;				// size=0, offset=13 //  hashcode: 0x685C87B7 (dec: 1750894519), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;					// size=0, offset=14 //  hashcode: 0xCD99C6ED (dec: -845560083), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short deg;						// size=0, offset=16 //  hashcode: 0xB2F2D26A (dec: -1292709270), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short deg_inc;					// size=0, offset=18 //  hashcode: 0x7A8649C8 (dec: 2055621064), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position start_offset;  // size=6, offset=20 //  hashcode: 0xF115235F (dec: -250272929), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short startSeg;					// size=0, offset=26 //  hashcode: 0x4098D1E8 (dec: 1083757032), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *end_instance; // size=616, offset=28 //  hashcode: 0x834A6C5E (dec: -2092274594), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position end_offset;	// size=6, offset=32 //  hashcode: 0x45F4C032 (dec: 1173667890), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short endSeg;					// size=0, offset=38 //  hashcode: 0xBAFABDF3 (dec: -1157972493), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short matrixSeg;				// size=0, offset=40 //  hashcode: 0xEDDEA2B4 (dec: -304176460), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short width;					// size=0, offset=42 //  hashcode: 0x48FED3FB (dec: 1224659963), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short small_width;				// size=0, offset=44 //  hashcode: 0x6DC83B76 (dec: 1841838966), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short segs;						// size=0, offset=46 //  hashcode: 0x74FAFA7A (dec: 1962605178), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short sine_size;				// size=0, offset=48 //  hashcode: 0xB3EB3806 (dec: -1276430330), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	short variation;				// size=0, offset=50 //  hashcode: 0x311043B5 (dec: 823149493), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color;						// size=0, offset=52 //  hashcode: 0x2D820C5D (dec: 763497565), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
	long glow_color;				// size=0, offset=56 //  hashcode: 0x1A485C97 (dec: 440949911), parent name: '_FXLightning', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _FXFlash // hashcode: 0xD3DE17A3 (dec: -740419677)
{
	void *next;					// size=0, offset=0 //  hashcode: 0x428224AC (dec: 1115825324), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *continue_process;		// size=0, offset=4 //  hashcode: 0x36996701 (dec: 916023041), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=8 //  hashcode: 0xED212D9E (dec: -316592738), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char effectType;   // size=0, offset=12 //  hashcode: 0x04D5162C (dec: 81073708), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;			// size=0, offset=13 //  hashcode: 0x640122DE (dec: 1677796062), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lifeTime;				// size=0, offset=14 //  hashcode: 0x8C1D0AF9 (dec: -1944253703), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timeToColor;			// size=0, offset=16 //  hashcode: 0xB7815216 (dec: -1216261610), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timeAtColor;			// size=0, offset=20 //  hashcode: 0x7388DCC0 (dec: 1938349248), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timeFromColor;			// size=0, offset=24 //  hashcode: 0x50A82F5E (dec: 1353199454), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
	long currentTime;			// size=0, offset=28 //  hashcode: 0xF8155FD1 (dec: -132816943), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color;					// size=0, offset=32 //  hashcode: 0x744C8B19 (dec: 1951173401), parent name: '_FXFlash', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct GenericFXObject // hashcode: 0xD22FD65C (dec: -768616868)
{
	struct _GenericParticleParams *ParticleList;   // size=48, offset=0 //  hashcode: 0x4055E7DE (dec: 1079371742), parent name: 'GenericFXObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _GenericRibbonParams *RibbonList;	   // size=20, offset=4 //  hashcode: 0xD71CD0D4 (dec: -685977388), parent name: 'GenericFXObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _GenericGlowParams *GlowList;		   // size=24, offset=8 //  hashcode: 0xE5C0539F (dec: -440380513), parent name: 'GenericFXObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _GenericLightningParams *LightningList; // size=40, offset=12 //  hashcode: 0x15F04DCE (dec: 368070094), parent name: 'GenericFXObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _GenericBlastringParams *BlastList;	 // size=48, offset=16 //  hashcode: 0x033C2825 (dec: 54274085), parent name: 'GenericFXObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _GenericFlashParams *FlashList;		   // size=12, offset=20 //  hashcode: 0x1C442A8E (dec: 474229390), parent name: 'GenericFXObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long *ColorList;							   // size=0, offset=24 //  hashcode: 0x69B3289E (dec: 1773349022), parent name: 'GenericFXObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evObjectDraftData // hashcode: 0x73C6643E (dec: 1942381630)
{
	short force;				// size=0, offset=0 //  hashcode: 0xC4B917A8 (dec: -994502744), parent name: 'evObjectDraftData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short radius;		// size=0, offset=2 //  hashcode: 0xEBB7794B (dec: -340297397), parent name: 'evObjectDraftData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short radiusCoef;  // size=0, offset=4 //  hashcode: 0x2131DB3F (dec: 556915519), parent name: 'evObjectDraftData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short height;		// size=0, offset=6 //  hashcode: 0x2A97DF9C (dec: 714596252), parent name: 'evObjectDraftData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short maxVelocity; // size=0, offset=8 //  hashcode: 0x4DDEED09 (dec: 1306455305), parent name: 'evObjectDraftData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _GlyphTuneData // hashcode: 0x14FFD660 (dec: 352310880)
{
	short glyph_size;	 // size=0, offset=0 //  hashcode: 0x07301BC5 (dec: 120593349), parent name: '_GlyphTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short glyph_darkness; // size=0, offset=2 //  hashcode: 0x7DEDCF25 (dec: 2112737061), parent name: '_GlyphTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char glyph_costs[8];  // size=8, offset=4 //  hashcode: 0xD9C04065 (dec: -641712027), parent name: '_GlyphTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short glyph_range[8]; // size=16, offset=12 //  hashcode: 0xC75EEA43 (dec: -950080957), parent name: '_GlyphTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long color_array[28]; // size=112, offset=28 //  hashcode: 0x886BB28B (dec: -2006207861), parent name: '_GlyphTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __ReaverData // hashcode: 0xD1EA4FE0 (dec: -773173280)
{
	char ReaverPickedUp;			 // size=0, offset=0 //  hashcode: 0xC8AFBCBF (dec: -928006977), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char ReaverOn;					 // size=0, offset=1 //  hashcode: 0x94D6BE07 (dec: -1797865977), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ReaverSize;				 // size=0, offset=2 //  hashcode: 0x67691978 (dec: 1734941048), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short CurrentReaver;			 // size=0, offset=4 //  hashcode: 0xB320FC9F (dec: -1289683809), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ReaverDeg;				 // size=0, offset=6 //  hashcode: 0x6B473742 (dec: 1799829314), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long ReaverChargeTime;			 // size=0, offset=8 //  hashcode: 0x31BBA4D5 (dec: 834381013), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long ReaverShockAmount;			 // size=0, offset=12 //  hashcode: 0xC7285815 (dec: -953657323), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long ReaverGlowColor;			 // size=0, offset=16 //  hashcode: 0xE6291596 (dec: -433515114), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long ReaverBladeColor;			 // size=0, offset=20 //  hashcode: 0x6E28F71B (dec: 1848178459), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long ReaverBladeGlowColor;		 // size=0, offset=24 //  hashcode: 0xEC138772 (dec: -334264462), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ReaverScale;				 // size=0, offset=28 //  hashcode: 0xEE457180 (dec: -297438848), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ReaverTargetScale;		 // size=0, offset=30 //  hashcode: 0xE77B3928 (dec: -411354840), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __ReaverSaveDat saveData; // size=4, offset=32 //  hashcode: 0xB641333A (dec: -1237241030), parent name: '__ReaverData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __ReaverTuneData // hashcode: 0xE4E74D43 (dec: -454603453)
{
	unsigned long spectralGlowColor;	  // size=0, offset=0 //  hashcode: 0xF33CF062 (dec: -214110110), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long materialGlowColor;	  // size=0, offset=4 //  hashcode: 0x493656E8 (dec: 1228297960), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long sunlightGlowColor;	  // size=0, offset=8 //  hashcode: 0x7A422364 (dec: 2051154788), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long waterGlowColor;		  // size=0, offset=12 //  hashcode: 0xD2F16E2E (dec: -755929554), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long stoneGlowColor;		  // size=0, offset=16 //  hashcode: 0x61F9544A (dec: 1643729994), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long fireGlowColor;		  // size=0, offset=20 //  hashcode: 0x5D772918 (dec: 1568090392), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long spiritGlowColor;		  // size=0, offset=24 //  hashcode: 0x8CAABE77 (dec: -1934967177), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long soundGlowColor;		  // size=0, offset=28 //  hashcode: 0xD7F99609 (dec: -671508983), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long spectralInnerColor;	 // size=0, offset=32 //  hashcode: 0x3C503C2E (dec: 1011891246), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long materialInnerColor;	 // size=0, offset=36 //  hashcode: 0x0F7982F1 (dec: 259621617), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long sunlightInnerColor;	 // size=0, offset=40 //  hashcode: 0x90116BA0 (dec: -1877906528), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long waterInnerColor;		  // size=0, offset=44 //  hashcode: 0x79CB2190 (dec: 2043355536), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long stoneInnerColor;		  // size=0, offset=48 //  hashcode: 0x05BC4B2A (dec: 96226090), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long fireInnerColor;		  // size=0, offset=52 //  hashcode: 0x1BD57E2D (dec: 466976301), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long spiritInnerColor;		  // size=0, offset=56 //  hashcode: 0x678BA871 (dec: 1737205873), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long soundInnerColor;		  // size=0, offset=60 //  hashcode: 0xFCCE42D8 (dec: -53591336), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long spectralInnerGlowColor; // size=0, offset=64 //  hashcode: 0xD7A7FCCE (dec: -676856626), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long materialInnerGlowColor; // size=0, offset=68 //  hashcode: 0x0305F378 (dec: 50721656), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long sunlightInnerGlowColor; // size=0, offset=72 //  hashcode: 0xD05F3152 (dec: -799067822), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long waterInnerGlowColor;	// size=0, offset=76 //  hashcode: 0xD44FFCAA (dec: -732955478), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long stoneInnerGlowColor;	// size=0, offset=80 //  hashcode: 0xA0F023FF (dec: -1594874881), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long fireInnerGlowColor;	 // size=0, offset=84 //  hashcode: 0xDE2F1C19 (dec: -567337959), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long spiritInnerGlowColor;   // size=0, offset=88 //  hashcode: 0x0D2BF8F3 (dec: 220985587), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long soundInnerGlowColor;	// size=0, offset=92 //  hashcode: 0x809E5545 (dec: -2137107131), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long icon_colors[24];		  // size=96, offset=96 //  hashcode: 0xC215EAF8 (dec: -1038750984), parent name: '__ReaverTuneData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _POLY_TF4 // hashcode: 0x871FC08E (dec: -2027962226)
{
	unsigned long tag;		 // size=0, offset=0 //  hashcode: 0x09B6CB48 (dec: 162974536), parent name: '_POLY_TF4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long drawTPage; // size=0, offset=4 //  hashcode: 0x500B97EB (dec: 1342937067), parent name: '_POLY_TF4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BASIC_F4 p1;	 // size=20, offset=8 //  hashcode: 0x44DA432B (dec: 1155154731), parent name: '_POLY_TF4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _POLY_2G4 // hashcode: 0x3FC1C531 (dec: 1069663537)
{
	unsigned long tag;   // size=0, offset=0 //  hashcode: 0xCBA71693 (dec: -878242157), parent name: '_POLY_2G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BASIC_G4 p1; // size=32, offset=4 //  hashcode: 0x1D50686D (dec: 491808877), parent name: '_POLY_2G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BASIC_G4 p2; // size=32, offset=36 //  hashcode: 0x6FD04F68 (dec: 1875922792), parent name: '_POLY_2G4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _POLY_2G4T // hashcode: 0xA357E01D (dec: -1554522083)
{
	unsigned long tag;		  // size=0, offset=0 //  hashcode: 0xDCE12199 (dec: -589225575), parent name: '_POLY_2G4T', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long drawTPage1; // size=0, offset=4 //  hashcode: 0x1AA0C030 (dec: 446742576), parent name: '_POLY_2G4T', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BASIC_G4 p1;	  // size=32, offset=8 //  hashcode: 0x20553C71 (dec: 542456945), parent name: '_POLY_2G4T', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _BASIC_G4 p2;	  // size=32, offset=40 //  hashcode: 0xCB2E0089 (dec: -886177655), parent name: '_POLY_2G4T', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct NewMemTracker // hashcode: 0x5C68280F (dec: 1550329871)
{
	struct MemHeader *rootNode;		 // size=8, offset=0 //  hashcode: 0x1223120A (dec: 304288266), parent name: 'NewMemTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long totalMemory;		 // size=0, offset=4 //  hashcode: 0x6AF9C2EC (dec: 1794753260), parent name: 'NewMemTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long currentMemoryUsed; // size=0, offset=8 //  hashcode: 0xB0F25C39 (dec: -1326293959), parent name: 'NewMemTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *lastMemoryAddress;		 // size=0, offset=12 //  hashcode: 0x23345FE6 (dec: 590634982), parent name: 'NewMemTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
	long doingGarbageCollection;	 // size=0, offset=16 //  hashcode: 0x4C0110B4 (dec: 1275138228), parent name: 'NewMemTracker', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadVolume // hashcode: 0xDE43B1D6 (dec: -565988906)
{
	short left;  // size=0, offset=0 //  hashcode: 0x606F3189 (dec: 1617899913), parent name: 'AadVolume', parent hashcode: 0xFFFFFFFF (dec: -1)
	short right; // size=0, offset=2 //  hashcode: 0x6938EFFF (dec: 1765339135), parent name: 'AadVolume', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadSequenceHdr // hashcode: 0x09B09BCF (dec: 162569167)
{
	unsigned long sequenceID;	  // size=0, offset=0 //  hashcode: 0xA12DD76F (dec: -1590831249), parent name: 'AadSequenceHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long quarterNoteTime; // size=0, offset=4 //  hashcode: 0x4176AE34 (dec: 1098296884), parent name: 'AadSequenceHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short ppqn;		   // size=0, offset=8 //  hashcode: 0x30D1816E (dec: 819036526), parent name: 'AadSequenceHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short version;		   // size=0, offset=10 //  hashcode: 0x462F68E0 (dec: 1177512160), parent name: 'AadSequenceHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short numTracks;	  // size=0, offset=12 //  hashcode: 0x8F81D091 (dec: -1887317871), parent name: 'AadSequenceHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short unused;		   // size=0, offset=14 //  hashcode: 0x0EAB544A (dec: 246109258), parent name: 'AadSequenceHdr', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadTempo // hashcode: 0x0AB3CE4B (dec: 179555915)
{
	unsigned long quarterNoteTime; // size=0, offset=0 //  hashcode: 0xA2F7341F (dec: -1560857569), parent name: 'AadTempo', parent hashcode: 0xFFFFFFFF (dec: -1)
	int ppqn;					   // size=0, offset=4 //  hashcode: 0x2B21DB29 (dec: 723639081), parent name: 'AadTempo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadMemoryStruct // hashcode: 0x46CEF45B (dec: 1187968091)
{
	unsigned long updateCounter;					   // size=0, offset=0 //  hashcode: 0x25EB8F48 (dec: 636194632), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int numSlots;									   // size=0, offset=4 //  hashcode: 0x6E9FBDA4 (dec: 1855962532), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int updateMode;									   // size=0, offset=8 //  hashcode: 0x24BF7ED2 (dec: 616529618), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int masterVolume;								   // size=0, offset=12 //  hashcode: 0x5A840FF8 (dec: 1518604280), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadVolFader masterVolFader;				   // size=12, offset=16 //  hashcode: 0x038FFEEF (dec: 59768559), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int sfxMasterVol;								   // size=0, offset=28 //  hashcode: 0x6158C376 (dec: 1633207158), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int musicMasterVol;								   // size=0, offset=32 //  hashcode: 0xC2BC0542 (dec: -1027865278), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int flags;										   // size=0, offset=36 //  hashcode: 0x2117E833 (dec: 555214899), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadVolFader musicMasterVolFader;			   // size=12, offset=40 //  hashcode: 0x764E7E7A (dec: 1984855674), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _AadSequenceSlot(*sequenceSlots[8]);		   // size=32, offset=52 //  hashcode: 0x1790C2ED (dec: 395363053), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadSfxSlot sfxSlot;						   // size=392, offset=84 //  hashcode: 0x3EE3983D (dec: 1055103037), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadSynthVoice synthVoice[24];			   // size=672, offset=476 //  hashcode: 0x54C580BE (dec: 1422229694), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	char voiceStatus[24];							   // size=24, offset=1148 //  hashcode: 0x6B6BCD7F (dec: 1802227071), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short voicePitchSave[24];				   // size=48, offset=1172 //  hashcode: 0x28C9AA69 (dec: 684305001), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long voiceKeyOffRequest;				   // size=0, offset=1220 //  hashcode: 0x16E1DE78 (dec: 383901304), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long voiceKeyOnRequest;				   // size=0, offset=1224 //  hashcode: 0x5A2F9046 (dec: 1513066566), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long voiceReverbRequest;				   // size=0, offset=1228 //  hashcode: 0x90421083 (dec: -1874718589), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadSoundBankHdr(*dynamicSoundBankHdr[2]);   // size=8, offset=1232 //  hashcode: 0xCF1E979C (dec: -820078692), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadProgramAtr(*dynamicProgramAtr[2]);	   // size=8, offset=1240 //  hashcode: 0x03270CED (dec: 52890861), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadToneAtr(*dynamicToneAtr[2]);			   // size=8, offset=1248 //  hashcode: 0x9AFAA5A9 (dec: -1694849623), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long(*dynamicWaveAddr[2]);				   // size=8, offset=1256 //  hashcode: 0xCFEFACEA (dec: -806376214), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char(**dynamicSequenceAddressTbl[2]);	 // size=8, offset=1264 //  hashcode: 0x796E6392 (dec: 2037277586), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long(*dynamicSequenceLabelOffsetTbl[2]);  // size=8, offset=1272 //  hashcode: 0x9D506E22 (dec: -1655673310), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int dynamicBankStatus[2];						   // size=8, offset=1280 //  hashcode: 0xA2982677 (dec: -1567086985), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char(*dynamicSoundBankData[2]);		   // size=8, offset=1288 //  hashcode: 0xA233F1A5 (dec: -1573654107), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long dynamicSoundBankSramData[2];		   // size=8, offset=1296 //  hashcode: 0x9AC2212B (dec: -1698553557), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadDynamicLoadRequest loadRequestQueue[16]; // size=448, offset=1304 //  hashcode: 0x5FAA1837 (dec: 1604982839), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadDynamicBankLoadInfo dynamicBankLoadInfo; // size=88, offset=1752 //  hashcode: 0x05106291 (dec: 84959889), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*nonBlockLoadProc)();						   // size=0, offset=1840 //  hashcode: 0x5D64DE72 (dec: 1566891634), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*nonBlockBufferedLoadProc)();				   // size=0, offset=1844 //  hashcode: 0x78C4D356 (dec: 2026165078), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (**memoryMallocProc)();					   // size=0, offset=1848 //  hashcode: 0x3AD50EC8 (dec: 987041480), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*memoryFreeProc)();						   // size=0, offset=1852 //  hashcode: 0x98F62268 (dec: -1728699800), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nextLoadReqIn;								   // size=0, offset=1856 //  hashcode: 0x93C3FEC3 (dec: -1815871805), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nextLoadReqOut;								   // size=0, offset=1860 //  hashcode: 0xB4150756 (dec: -1273690282), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int numLoadReqsQueued;							   // size=0, offset=1864 //  hashcode: 0x3E63EFA3 (dec: 1046736803), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadDynamicSfxLoadInfo dynamicSfxLoadInfo;   // size=148, offset=1868 //  hashcode: 0x15447F89 (dec: 356810633), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _AadDynSfxFileHdr *firstDynSfxFile;		   // size=20, offset=2016 //  hashcode: 0x2B7765B4 (dec: 729245108), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nextFileHandle;								   // size=0, offset=2020 //  hashcode: 0x4E4F5852 (dec: 1313822802), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadSramDefragInfo sramDefragInfo;		   // size=32, offset=2024 //  hashcode: 0x1A0EED64 (dec: 437185892), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char sfxToneMasterList[512];			   // size=512, offset=2056 //  hashcode: 0xBDFB3852 (dec: -1107609518), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char sfxWaveMasterList[512];			   // size=512, offset=2568 //  hashcode: 0x1CD55713 (dec: 483743507), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadLoadedSfxToneAttr sfxToneAttrTbl[128];   // size=2560, offset=3080 //  hashcode: 0x53E79A5F (dec: 1407687263), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadLoadedSfxWaveAttr sfxWaveAttrTbl[120];   // size=480, offset=5640 //  hashcode: 0xD46C2406 (dec: -731110394), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nextToneIndex;								   // size=0, offset=6120 //  hashcode: 0xCF2CB446 (dec: -819153850), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nextWaveIndex;								   // size=0, offset=6124 //  hashcode: 0xF4A92710 (dec: -190241008), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct AadNewSramBlockDesc sramDescriptorTbl[128]; // size=1024, offset=6128 //  hashcode: 0x3514D111 (dec: 890556689), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nextSramDescIndex;							   // size=0, offset=7152 //  hashcode: 0xA8E1C6B7 (dec: -1461598537), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	int firstSramBlockDescIndex;					   // size=0, offset=7156 //  hashcode: 0xEA340B90 (dec: -365687920), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*controller11Callback)();					   // size=0, offset=7160 //  hashcode: 0xEBBF7717 (dec: -339773673), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*endSequenceCallback)();					   // size=0, offset=7164 //  hashcode: 0x125399BC (dec: 307468732), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	long controller11CallbackData;					   // size=0, offset=7168 //  hashcode: 0x800BE034 (dec: -2146705356), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	long endSequenceCallbackData;					   // size=0, offset=7172 //  hashcode: 0xDBBD1D7D (dec: -608363139), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char userVariables[128];				   // size=128, offset=7176 //  hashcode: 0x576294DA (dec: 1466078426), parent name: 'AadMemoryStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AadSlotAttributes // hashcode: 0x7DE97E8C (dec: 2112454284)
{
	int sequenceNumberAssigned;		 // size=0, offset=0 //  hashcode: 0x083B91EB (dec: 138121707), parent name: 'AadSlotAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	int sequenceAssignedDynamicBank; // size=0, offset=4 //  hashcode: 0x0F0EBD23 (dec: 252624163), parent name: 'AadSlotAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	int playingStatus;				 // size=0, offset=8 //  hashcode: 0x186034D7 (dec: 408958167), parent name: 'AadSlotAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	int channelMute;				 // size=0, offset=12 //  hashcode: 0xB301B340 (dec: -1291734208), parent name: 'AadSlotAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	int slotVolume;					 // size=0, offset=16 //  hashcode: 0xDBC4BBB6 (dec: -607863882), parent name: 'AadSlotAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	int slotPan;					 // size=0, offset=20 //  hashcode: 0xF53CD9B4 (dec: -180561484), parent name: 'AadSlotAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	int eventsInQueue[16];			 // size=64, offset=24 //  hashcode: 0x3ED09602 (dec: 1053857282), parent name: 'AadSlotAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct POLY_G4 // hashcode: 0x82B947DC (dec: -2101786660)
{
	unsigned long tag;  // size=0, offset=0 //  hashcode: 0xC24CBE56 (dec: -1035157930), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r0;   // size=0, offset=4 //  hashcode: 0x3866D3E2 (dec: 946263010), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g0;   // size=0, offset=5 //  hashcode: 0x9A4BFB05 (dec: -1706296571), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b0;   // size=0, offset=6 //  hashcode: 0x1C32063A (dec: 473040442), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char code; // size=0, offset=7 //  hashcode: 0x772954CD (dec: 1999197389), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x0;			// size=0, offset=8 //  hashcode: 0x4463911B (dec: 1147375899), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y0;			// size=0, offset=10 //  hashcode: 0x724998C7 (dec: 1917425863), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r1;   // size=0, offset=12 //  hashcode: 0x9910D713 (dec: -1726949613), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g1;   // size=0, offset=13 //  hashcode: 0x56896334 (dec: 1451844404), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b1;   // size=0, offset=14 //  hashcode: 0x22CE5AB7 (dec: 583948983), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad1; // size=0, offset=15 //  hashcode: 0x48456F3C (dec: 1212510012), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x1;			// size=0, offset=16 //  hashcode: 0xBACE8FBF (dec: -1160867905), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y1;			// size=0, offset=18 //  hashcode: 0xAAD11BD3 (dec: -1429136429), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r2;   // size=0, offset=20 //  hashcode: 0xEDDAECB5 (dec: -304419659), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g2;   // size=0, offset=21 //  hashcode: 0xF31976B5 (dec: -216435019), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b2;   // size=0, offset=22 //  hashcode: 0xEEFE7F51 (dec: -285311151), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad2; // size=0, offset=23 //  hashcode: 0xC595D8AB (dec: -980035413), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x2;			// size=0, offset=24 //  hashcode: 0x92715D30 (dec: -1838064336), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y2;			// size=0, offset=26 //  hashcode: 0x01B18D32 (dec: 28413234), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char r3;   // size=0, offset=28 //  hashcode: 0xD7B6E1BF (dec: -675880513), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g3;   // size=0, offset=29 //  hashcode: 0x94093031 (dec: -1811337167), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b3;   // size=0, offset=30 //  hashcode: 0x61618730 (dec: 1633781552), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad3; // size=0, offset=31 //  hashcode: 0xE1B4F777 (dec: -508233865), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x3;			// size=0, offset=32 //  hashcode: 0x9EC6F39A (dec: -1631128678), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y3;			// size=0, offset=34 //  hashcode: 0x2460B56E (dec: 610317678), parent name: 'POLY_G4', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct DR_AREA // hashcode: 0xE0CED39B (dec: -523316325)
{
	unsigned long tag;	 // size=0, offset=0 //  hashcode: 0x3F19BDB7 (dec: 1058651575), parent name: 'DR_AREA', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long code[2]; // size=8, offset=4 //  hashcode: 0xAFBADC76 (dec: -1346708362), parent name: 'DR_AREA', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evPositionData // hashcode: 0x853C21E0 (dec: -2059656736)
{
	short x;   // size=0, offset=0 //  hashcode: 0x7A03B3AF (dec: 2047062959), parent name: 'evPositionData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;   // size=0, offset=2 //  hashcode: 0xF1ADA5EB (dec: -240278037), parent name: 'evPositionData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;   // size=0, offset=4 //  hashcode: 0xC344F5B7 (dec: -1018890825), parent name: 'evPositionData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad; // size=0, offset=6 //  hashcode: 0x3C48AFD6 (dec: 1011396566), parent name: 'evPositionData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct STracker // hashcode: 0xAED5E069 (dec: -1361715095)
{
	struct _StreamUnit StreamList[16]; // size=1024, offset=0 //  hashcode: 0x6C7846B6 (dec: 1819821750), parent name: 'STracker', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct FaceExtents // hashcode: 0x22E8BE79 (dec: 585678457)
{
	long smallx; // size=0, offset=0 //  hashcode: 0xD545E4F0 (dec: -716839696), parent name: 'FaceExtents', parent hashcode: 0xFFFFFFFF (dec: -1)
	long bigx;   // size=0, offset=4 //  hashcode: 0x005AEA79 (dec: 5958265), parent name: 'FaceExtents', parent hashcode: 0xFFFFFFFF (dec: -1)
	long smally; // size=0, offset=8 //  hashcode: 0xF17A5F9D (dec: -243638371), parent name: 'FaceExtents', parent hashcode: 0xFFFFFFFF (dec: -1)
	long bigy;   // size=0, offset=12 //  hashcode: 0x3FFD72CF (dec: 1073574607), parent name: 'FaceExtents', parent hashcode: 0xFFFFFFFF (dec: -1)
	long smallz; // size=0, offset=16 //  hashcode: 0xB63FACC8 (dec: -1237340984), parent name: 'FaceExtents', parent hashcode: 0xFFFFFFFF (dec: -1)
	long bigz;   // size=0, offset=20 //  hashcode: 0x59145268 (dec: 1494504040), parent name: 'FaceExtents', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WarpRoom // hashcode: 0x34E00E66 (dec: 887098982)
{
	char name[16];					// size=16, offset=0 //  hashcode: 0x76196044 (dec: 1981374532), parent name: 'WarpRoom', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _StreamUnit *streamUnit; // size=64, offset=16 //  hashcode: 0x4593671A (dec: 1167288090), parent name: 'WarpRoom', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PlanningNode // hashcode: 0xDB9F3065 (dec: -610324379)
{
	struct _Position pos;			// size=6, offset=0 //  hashcode: 0x3E6B2F48 (dec: 1047211848), parent name: 'PlanningNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short flags;			// size=0, offset=6 //  hashcode: 0xD3929A7C (dec: -745366916), parent name: 'PlanningNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long connectionStatus; // size=0, offset=8 //  hashcode: 0x76644118 (dec: 1986281752), parent name: 'PlanningNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long connections;		// size=0, offset=12 //  hashcode: 0x87CCC702 (dec: -2016622846), parent name: 'PlanningNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short cost;			// size=0, offset=16 //  hashcode: 0x381EF499 (dec: 941552793), parent name: 'PlanningNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short parent;			// size=0, offset=18 //  hashcode: 0xC8949B22 (dec: -929785054), parent name: 'PlanningNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short nodeType;		// size=0, offset=20 //  hashcode: 0x18529B78 (dec: 408066936), parent name: 'PlanningNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short id;				// size=0, offset=22 //  hashcode: 0xF24224D8 (dec: -230546216), parent name: 'PlanningNode', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamUnitID;				// size=0, offset=24 //  hashcode: 0xDCB4C975 (dec: -592131723), parent name: 'PlanningNode', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct VramBuffer // hashcode: 0x13A80E34 (dec: 329780788)
{
	long flags;					// size=0, offset=0 //  hashcode: 0x31093EAD (dec: 822689453), parent name: 'VramBuffer', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x;					// size=0, offset=4 //  hashcode: 0x4A311568 (dec: 1244730728), parent name: 'VramBuffer', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;					// size=0, offset=6 //  hashcode: 0x0487647A (dec: 75981946), parent name: 'VramBuffer', parent hashcode: 0xFFFFFFFF (dec: -1)
	short w;					// size=0, offset=8 //  hashcode: 0x86FDF24D (dec: -2030177715), parent name: 'VramBuffer', parent hashcode: 0xFFFFFFFF (dec: -1)
	short h;					// size=0, offset=10 //  hashcode: 0x127245C6 (dec: 309478854), parent name: 'VramBuffer', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yOffset;				// size=0, offset=12 //  hashcode: 0x295553FD (dec: 693457917), parent name: 'VramBuffer', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lengthOfLeftOverData; // size=0, offset=14 //  hashcode: 0x52C5052A (dec: 1388643626), parent name: 'VramBuffer', parent hashcode: 0xFFFFFFFF (dec: -1)
	short *lineOverFlow;		// size=0, offset=16 //  hashcode: 0xE16BEE5D (dec: -513020323), parent name: 'VramBuffer', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evObjectData // hashcode: 0xE261F276 (dec: -496897418)
{
	short x;				 // size=0, offset=0 //  hashcode: 0xAC9B113D (dec: -1399123651), parent name: 'evObjectData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				 // size=0, offset=2 //  hashcode: 0x6BA49AF5 (dec: 1805949685), parent name: 'evObjectData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short PathNumber;		 // size=0, offset=4 //  hashcode: 0xE2C2630A (dec: -490577142), parent name: 'evObjectData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short LinkNode;			 // size=0, offset=6 //  hashcode: 0x57841C8A (dec: 1468275850), parent name: 'evObjectData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *Force; // size=616, offset=8 //  hashcode: 0x6DCFE7C6 (dec: 1842341830), parent name: 'evObjectData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int rc;					 // size=0, offset=12 //  hashcode: 0x577775AA (dec: 1467446698), parent name: 'evObjectData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evPhysicsGravityData // hashcode: 0xD13BDF0D (dec: -784605427)
{
	short UpperOffset; // size=0, offset=0 //  hashcode: 0x80AA34B6 (dec: -2136329034), parent name: 'evPhysicsGravityData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short LowerOffset; // size=0, offset=2 //  hashcode: 0x58CCB760 (dec: 1489811296), parent name: 'evPhysicsGravityData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x;		   // size=0, offset=4 //  hashcode: 0x6B49FFEF (dec: 1800011759), parent name: 'evPhysicsGravityData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;		   // size=0, offset=6 //  hashcode: 0x99D0A2B9 (dec: -1714380103), parent name: 'evPhysicsGravityData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;		   // size=0, offset=8 //  hashcode: 0x938BFB33 (dec: -1819542733), parent name: 'evPhysicsGravityData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short slipSlope;   // size=0, offset=10 //  hashcode: 0x770C72F3 (dec: 1997304563), parent name: 'evPhysicsGravityData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evPhysicsSlideData // hashcode: 0x42A65F7B (dec: 1118199675)
{
	struct _SVector ForwardVector;   // size=8, offset=0 //  hashcode: 0x7EE84ECC (dec: 2129153740), parent name: 'evPhysicsSlideData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector ForwardNormal;   // size=8, offset=8 //  hashcode: 0xB4186BD0 (dec: -1273467952), parent name: 'evPhysicsSlideData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector DropNormal;		 // size=8, offset=16 //  hashcode: 0x2DF6C7DF (dec: 771147743), parent name: 'evPhysicsSlideData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Segment;					 // size=0, offset=24 //  hashcode: 0x861DB2C6 (dec: -2044874042), parent name: 'evPhysicsSlideData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short DropOffset;				 // size=0, offset=26 //  hashcode: 0xC7681CB6 (dec: -949478218), parent name: 'evPhysicsSlideData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short UpperOffset;				 // size=0, offset=28 //  hashcode: 0x206A612C (dec: 543842604), parent name: 'evPhysicsSlideData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Height;					 // size=0, offset=30 //  hashcode: 0x8D3098C5 (dec: -1926195003), parent name: 'evPhysicsSlideData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *UpperInstance; // size=616, offset=32 //  hashcode: 0x2CF7C96D (dec: 754436461), parent name: 'evPhysicsSlideData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int Dot;						 // size=0, offset=36 //  hashcode: 0x6F8B2A65 (dec: 1871391333), parent name: 'evPhysicsSlideData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evObjectThrowData // hashcode: 0x293A2507 (dec: 691676423)
{
	short type;					// size=0, offset=0 //  hashcode: 0x9DFD0E65 (dec: -1644360091), parent name: 'evObjectThrowData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short spinType;				// size=0, offset=2 //  hashcode: 0x58390A8C (dec: 1480133260), parent name: 'evObjectThrowData', parent hashcode: 0xFFFFFFFF (dec: -1)
	;							// size=8, offset=4 //  hashcode: 0x5EB14E82 (dec: 1588678274), parent name: 'evObjectThrowData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector angularVel; // size=8, offset=12 //  hashcode: 0x3D0514EF (dec: 1023743215), parent name: 'evObjectThrowData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short speed;		// size=0, offset=20 //  hashcode: 0x3E4CC4E0 (dec: 1045218528), parent name: 'evObjectThrowData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short gravity;				// size=0, offset=22 //  hashcode: 0x28543CD6 (dec: 676609238), parent name: 'evObjectThrowData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short initialXRot;			// size=0, offset=24 //  hashcode: 0x9F14B57D (dec: -1626032771), parent name: 'evObjectThrowData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zVel;					// size=0, offset=26 //  hashcode: 0x0FF94DE9 (dec: 267996649), parent name: 'evObjectThrowData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evObjectBirthProjectileData // hashcode: 0xAA355F00 (dec: -1439342848)
{
	struct _Instance *instance;		 // size=616, offset=0 //  hashcode: 0x3F5A997F (dec: 1062902143), parent name: 'evObjectBirthProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int joint;						 // size=0, offset=4 //  hashcode: 0xC2B85DD2 (dec: -1028104750), parent name: 'evObjectBirthProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int type;						 // size=0, offset=8 //  hashcode: 0xE3BDC8ED (dec: -474101523), parent name: 'evObjectBirthProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *birthInstance; // size=616, offset=12 //  hashcode: 0x0B5DBBAF (dec: 190692271), parent name: 'evObjectBirthProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PhysObWeaponProperties // hashcode: 0xC3612955 (dec: -1017042603)
{
	struct PhysObProperties Properties;				// size=8, offset=0 //  hashcode: 0x7D61548E (dec: 2103530638), parent name: 'PhysObWeaponProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PhysObWeaponAttributes WeaponAttributes; // size=28, offset=8 //  hashcode: 0xE16C9346 (dec: -512978106), parent name: 'PhysObWeaponProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PhysObInteractProperties // hashcode: 0x668EE420 (dec: 1720640544)
{
	struct PhysObProperties Properties;	// size=8, offset=0 //  hashcode: 0x86C9C7E7 (dec: -2033596441), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short conditions;			   // size=0, offset=8 //  hashcode: 0xABA58548 (dec: -1415215800), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short auxConditions;		   // size=0, offset=10 //  hashcode: 0xB5AFEAA2 (dec: -1246762334), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short action;				   // size=0, offset=12 //  hashcode: 0xBDCB76C7 (dec: -1110739257), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short auxAction;			   // size=0, offset=14 //  hashcode: 0x96CC8218 (dec: -1764982248), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char startAnim;			   // size=0, offset=16 //  hashcode: 0xA3FEB919 (dec: -1543587559), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char endAnim;				   // size=0, offset=17 //  hashcode: 0x9702E3C3 (dec: -1761418301), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char razielAnim;			   // size=0, offset=18 //  hashcode: 0x9CB3AEF7 (dec: -1665945865), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char razielAuxAnim;		   // size=0, offset=19 //  hashcode: 0x058E1C2B (dec: 93199403), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char frame;				   // size=0, offset=20 //  hashcode: 0xD0BBA33D (dec: -793009347), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char startAnimMode;		   // size=0, offset=21 //  hashcode: 0xC0EAC6DC (dec: -1058355492), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short distance;			   // size=0, offset=22 //  hashcode: 0x2AA022A7 (dec: 715137703), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short newType;				   // size=0, offset=24 //  hashcode: 0xFECE23C5 (dec: -20044859), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short newClass;			   // size=0, offset=26 //  hashcode: 0x26A9E0CF (dec: 648667343), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short mode;				   // size=0, offset=28 //  hashcode: 0x8E378A4F (dec: -1908962737), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short engageXYDistance;	   // size=0, offset=30 //  hashcode: 0xCBADB033 (dec: -877809613), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	short engageZMinDelta;				   // size=0, offset=32 //  hashcode: 0xCBA782E8 (dec: -878214424), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	short engageZMaxDelta;				   // size=0, offset=34 //  hashcode: 0xF81DF5C3 (dec: -132254269), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char engageYCone;			   // size=0, offset=36 //  hashcode: 0x8F6D99CF (dec: -1888642609), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char engageZCone;			   // size=0, offset=37 //  hashcode: 0x2F93B2CB (dec: 798208715), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad;					   // size=0, offset=38 //  hashcode: 0xA1554B40 (dec: -1588245696), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PhysObWeaponAttributes *weapon; // size=28, offset=40 //  hashcode: 0x67FBDF8F (dec: 1744560015), parent name: 'PhysObInteractProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __PhysObProjectileProperties // hashcode: 0x0F1971B2 (dec: 253325746)
{
	struct PhysObProperties Properties;  // size=8, offset=0 //  hashcode: 0x5F5B96BC (dec: 1599837884), parent name: '__PhysObProjectileProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	long totalProjectiles;				 // size=0, offset=8 //  hashcode: 0x428D20B7 (dec: 1116545207), parent name: '__PhysObProjectileProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __PhysObProjectileData *data; // size=12, offset=12 //  hashcode: 0xED94D8D8 (dec: -309012264), parent name: '__PhysObProjectileProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PhysObDraftProperties // hashcode: 0x734F01FC (dec: 1934557692)
{
	struct PhysObProperties Properties; // size=8, offset=0 //  hashcode: 0x45533E5A (dec: 1163083354), parent name: 'PhysObDraftProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	short force;						// size=0, offset=8 //  hashcode: 0x492FCDB4 (dec: 1227869620), parent name: 'PhysObDraftProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short radius;				// size=0, offset=10 //  hashcode: 0xF6457D4C (dec: -163218100), parent name: 'PhysObDraftProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short radiusCoef;			// size=0, offset=12 //  hashcode: 0xAB8F80E8 (dec: -1416658712), parent name: 'PhysObDraftProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxVelocity;					// size=0, offset=14 //  hashcode: 0x0835AA15 (dec: 137734677), parent name: 'PhysObDraftProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long height;				// size=0, offset=16 //  hashcode: 0x84C9764B (dec: -2067171765), parent name: 'PhysObDraftProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PhysObSwitchProperties // hashcode: 0xF10C9EBB (dec: -250831173)
{
	struct PhysObProperties Properties; // size=8, offset=0 //  hashcode: 0x93C5498D (dec: -1815787123), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Distance;						// size=0, offset=8 //  hashcode: 0x7B066DC6 (dec: 2064018886), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Class;						// size=0, offset=10 //  hashcode: 0x3E24E3BD (dec: 1042604989), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char onAnim;				// size=0, offset=12 //  hashcode: 0xA3DD9E2F (dec: -1545757137), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char offAnim;				// size=0, offset=13 //  hashcode: 0x85931857 (dec: -2053957545), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char failedOnAnim;			// size=0, offset=14 //  hashcode: 0xC8AA754D (dec: -928352947), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char enableAnim;			// size=0, offset=15 //  hashcode: 0xCC2E3EC8 (dec: -869384504), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char shutAnim;				// size=0, offset=16 //  hashcode: 0xA2F06438 (dec: -1561304008), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char onWalkTimer;			// size=0, offset=17 //  hashcode: 0xDD4C5EE1 (dec: -582197535), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char offWalkTimer;			// size=0, offset=18 //  hashcode: 0xD80FAEB0 (dec: -670060880), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char walkMode;				// size=0, offset=19 //  hashcode: 0x42027290 (dec: 1107456656), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char razielOnAnim;			// size=0, offset=20 //  hashcode: 0xCE6A7C92 (dec: -831882094), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char razielOffAnim;		// size=0, offset=21 //  hashcode: 0x12039C3C (dec: 302226492), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char razielFailedOnAnim;   // size=0, offset=22 //  hashcode: 0x99AAA8A2 (dec: -1716868958), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char razielEnableAnim;		// size=0, offset=23 //  hashcode: 0x9E36526C (dec: -1640607124), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char startMode;			// size=0, offset=24 //  hashcode: 0xA416FDA5 (dec: -1541997147), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char startAnim;			// size=0, offset=25 //  hashcode: 0x42BB1D61 (dec: 1119559009), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short engageXYDistance;	// size=0, offset=26 //  hashcode: 0xA1C176A2 (dec: -1581156702), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	char engageZMinDelta;				// size=0, offset=28 //  hashcode: 0x6C71B4DA (dec: 1819391194), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	char engageZMaxDelta;				// size=0, offset=29 //  hashcode: 0x0DE994D9 (dec: 233411801), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char engageYCone;			// size=0, offset=30 //  hashcode: 0x66C3B611 (dec: 1724102161), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char engageZCone;			// size=0, offset=31 //  hashcode: 0x739D8CF7 (dec: 1939705079), parent name: 'PhysObSwitchProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PhysObCollectibleProperties // hashcode: 0x80B1E807 (dec: -2135824377)
{
	struct PhysObProperties Properties; // size=8, offset=0 //  hashcode: 0xBF5AF1ED (dec: -1084558867), parent name: 'PhysObCollectibleProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	short collectClass;					// size=0, offset=8 //  hashcode: 0x4B50AEB3 (dec: 1263578803), parent name: 'PhysObCollectibleProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	short collectValue;					// size=0, offset=10 //  hashcode: 0xE6329995 (dec: -432891499), parent name: 'PhysObCollectibleProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long distance;				// size=0, offset=12 //  hashcode: 0xCF345A55 (dec: -818652587), parent name: 'PhysObCollectibleProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char idleAnim;				// size=0, offset=16 //  hashcode: 0xE4B7A72A (dec: -457726166), parent name: 'PhysObCollectibleProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char collectAnim;			// size=0, offset=17 //  hashcode: 0x2C995FAC (dec: 748249004), parent name: 'PhysObCollectibleProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short spatialNode;			// size=0, offset=18 //  hashcode: 0x7BC5763C (dec: 2076538428), parent name: 'PhysObCollectibleProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PhysObAnimatedProperties // hashcode: 0xC40C87E4 (dec: -1005811740)
{
	struct PhysObProperties Properties; // size=8, offset=0 //  hashcode: 0x7A4ECE28 (dec: 2051984936), parent name: 'PhysObAnimatedProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short flags;				// size=0, offset=8 //  hashcode: 0xDDB25257 (dec: -575516073), parent name: 'PhysObAnimatedProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad;					// size=0, offset=10 //  hashcode: 0x418DFA74 (dec: 1099823732), parent name: 'PhysObAnimatedProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PhysObData // hashcode: 0x95351304 (dec: -1791683836)
{
	long Mode;							// size=0, offset=0 //  hashcode: 0x92D1CB16 (dec: -1831744746), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xForce;						// size=0, offset=4 //  hashcode: 0xD241C181 (dec: -767442559), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yForce;						// size=0, offset=6 //  hashcode: 0xC4146A53 (dec: -1005295021), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *Force;			// size=616, offset=8 //  hashcode: 0x3C2BE9E5 (dec: 1009510885), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short LinkNode;						// size=0, offset=12 //  hashcode: 0x44D02815 (dec: 1154492437), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short px;							// size=0, offset=14 //  hashcode: 0x158065E1 (dec: 360736225), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short py;							// size=0, offset=16 //  hashcode: 0xDF63B7E9 (dec: -547112983), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pz;							// size=0, offset=18 //  hashcode: 0x894EDC65 (dec: -1991320475), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rx1;							// size=0, offset=20 //  hashcode: 0x6233DAF9 (dec: 1647565561), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ry1;							// size=0, offset=22 //  hashcode: 0x741102B0 (dec: 1947271856), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rz1;							// size=0, offset=24 //  hashcode: 0x60068B75 (dec: 1611041653), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Segment1;						// size=0, offset=26 //  hashcode: 0x6FA92B40 (dec: 1873357632), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rx2;							// size=0, offset=28 //  hashcode: 0x61712DC8 (dec: 1634807240), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ry2;							// size=0, offset=30 //  hashcode: 0x64697066 (dec: 1684631654), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rz2;							// size=0, offset=32 //  hashcode: 0x5DD39D89 (dec: 1574149513), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Segment2;						// size=0, offset=34 //  hashcode: 0x192E908B (dec: 422482059), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Steps;						// size=0, offset=36 //  hashcode: 0xAEB75CF5 (dec: -1363714827), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Step;							// size=0, offset=38 //  hashcode: 0xC841E577 (dec: -935205513), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short PathNumber;					// size=0, offset=40 //  hashcode: 0x6A62CADF (dec: 1784859359), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Pad1;							// size=0, offset=42 //  hashcode: 0x0FE57A14 (dec: 266697236), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HInfo *RightCollision;		// size=24, offset=44 //  hashcode: 0x924301E2 (dec: -1841102366), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _HInfo *LeftCollision;		// size=24, offset=48 //  hashcode: 0xB64AA5BE (dec: -1236621890), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short burnAmpl;						// size=0, offset=52 //  hashcode: 0xFB50C9C8 (dec: -78591544), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short throwFlags;					// size=0, offset=54 //  hashcode: 0xFE50E9B9 (dec: -28251719), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short initialXRot;					// size=0, offset=56 //  hashcode: 0x12E39695 (dec: 316905109), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short xRotVel;						// size=0, offset=58 //  hashcode: 0xAD24E6ED (dec: -1390090515), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yRotVel;						// size=0, offset=60 //  hashcode: 0x0A1DD8C2 (dec: 169728194), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zRotVel;						// size=0, offset=62 //  hashcode: 0x761F4CCE (dec: 1981762766), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *throwingInstance; // size=616, offset=64 //  hashcode: 0x3C703C83 (dec: 1013988483), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int physObTimer;					// size=0, offset=68 //  hashcode: 0x0484DD67 (dec: 75816295), parent name: 'PhysObData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct BreakOffData // hashcode: 0x47B171A7 (dec: 1202811303)
{
	short NewType;  // size=0, offset=0 //  hashcode: 0x9FF1EBD6 (dec: -1611535402), parent name: 'BreakOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short NewClass; // size=0, offset=2 //  hashcode: 0xCCC6D206 (dec: -859385338), parent name: 'BreakOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct ProjectileData // hashcode: 0x05689657 (dec: 90740311)
{
	int Type; // size=0, offset=0 //  hashcode: 0xE3E13CF4 (dec: -471778060), parent name: 'ProjectileData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _PhysObSaveData // hashcode: 0xA353E0E7 (dec: -1554784025)
{
	struct SwitchData switchData; // size=4, offset=0 //  hashcode: 0x988FF956 (dec: -1735394986), parent name: '_PhysObSaveData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long Mode;					  // size=0, offset=4 //  hashcode: 0x53246187 (dec: 1394893191), parent name: '_PhysObSaveData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __CharacterState // hashcode: 0x6C0823BB (dec: 1812472763)
{
	struct _Instance *CharacterInstance; // size=616, offset=0 //  hashcode: 0xE481146D (dec: -461302675), parent name: '__CharacterState', parent hashcode: 0xFFFFFFFF (dec: -1)
	int TotalSections;					 // size=0, offset=4 //  hashcode: 0xB75C13B1 (dec: -1218702415), parent name: '__CharacterState', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __State SectionList[3];		 // size=852, offset=8 //  hashcode: 0xC7E6FA73 (dec: -941163917), parent name: '__CharacterState', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evMonsterHitData // hashcode: 0x5BC7AF7A (dec: 1539813242)
{
	struct _Instance *sender;  // size=616, offset=0 //  hashcode: 0x3D159193 (dec: 1024823699), parent name: 'evMonsterHitData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *lastHit; // size=616, offset=4 //  hashcode: 0xA5670431 (dec: -1519975375), parent name: 'evMonsterHitData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short knockBackDistance;   // size=0, offset=8 //  hashcode: 0x2D4F32A6 (dec: 760165030), parent name: 'evMonsterHitData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short knockBackDuration;   // size=0, offset=10 //  hashcode: 0x69307B31 (dec: 1764784945), parent name: 'evMonsterHitData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long power;				   // size=0, offset=12 //  hashcode: 0xCBAD5FA4 (dec: -877830236), parent name: 'evMonsterHitData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evMonsterThrownData // hashcode: 0x1A3E9058 (dec: 440307800)
{
	struct _Instance *sender;   // size=616, offset=0 //  hashcode: 0xC492AB88 (dec: -997020792), parent name: 'evMonsterThrownData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation direction; // size=8, offset=4 //  hashcode: 0x4E9C0ED0 (dec: 1318850256), parent name: 'evMonsterThrownData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short power;				// size=0, offset=12 //  hashcode: 0xF1271F5E (dec: -249094306), parent name: 'evMonsterThrownData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evMonsterAlarmData // hashcode: 0x5CC4F325 (dec: 1556411173)
{
	struct _Instance *sender;  // size=616, offset=0 //  hashcode: 0x8D3981B3 (dec: -1925611085), parent name: 'evMonsterAlarmData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position; // size=6, offset=4 //  hashcode: 0x3F3FCE8C (dec: 1061146252), parent name: 'evMonsterAlarmData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short type;				   // size=0, offset=10 //  hashcode: 0xC2E150CC (dec: -1025421108), parent name: 'evMonsterAlarmData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evMonsterSoulSuckData // hashcode: 0x24FA0E9A (dec: 620367514)
{
	struct _Instance *sender;	 // size=616, offset=0 //  hashcode: 0x47CA7C33 (dec: 1204452403), parent name: 'evMonsterSoulSuckData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position Destination; // size=6, offset=4 //  hashcode: 0x824744FD (dec: -2109258499), parent name: 'evMonsterSoulSuckData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evPhysicsDropOffData // hashcode: 0x240C7D71 (dec: 604798321)
{
	short xOffset;	// size=0, offset=0 //  hashcode: 0xF1F18DCF (dec: -235827761), parent name: 'evPhysicsDropOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short yOffset;	// size=0, offset=2 //  hashcode: 0x8795AE40 (dec: -2020233664), parent name: 'evPhysicsDropOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short DropOffset; // size=0, offset=4 //  hashcode: 0x02B35F22 (dec: 45309730), parent name: 'evPhysicsDropOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short slipSlope;  // size=0, offset=6 //  hashcode: 0x47364B44 (dec: 1194740548), parent name: 'evPhysicsDropOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int UpperOffset;  // size=0, offset=8 //  hashcode: 0xF7C8EE4A (dec: -137826742), parent name: 'evPhysicsDropOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evPhysicsEdgeData // hashcode: 0x9E9E1CB3 (dec: -1633805133)
{
	short UpperOffset;			// size=0, offset=0 //  hashcode: 0x071D8E47 (dec: 119377479), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ForwardOffset;		// size=0, offset=2 //  hashcode: 0xCB48501E (dec: -884453346), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short AboveOffset;			// size=0, offset=4 //  hashcode: 0xCE8C0D0A (dec: -829682422), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short XDistance;			// size=0, offset=6 //  hashcode: 0xA774BC4C (dec: -1485521844), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short YDistance;			// size=0, offset=8 //  hashcode: 0x1B2E567A (dec: 456021626), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ZDistance;			// size=0, offset=10 //  hashcode: 0x4F5425E8 (dec: 1330914792), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector *Normal1;   // size=8, offset=12 //  hashcode: 0x55027A98 (dec: 1426225816), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector *Normal2;   // size=8, offset=16 //  hashcode: 0x94F33D44 (dec: -1795998396), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector *Delta;		// size=8, offset=20 //  hashcode: 0x26B7E086 (dec: 649584774), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=24 //  hashcode: 0xAD905425 (dec: -1383050203), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int zRot;					// size=0, offset=28 //  hashcode: 0x2654691D (dec: 643066141), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int rc;						// size=0, offset=32 //  hashcode: 0x526D2647 (dec: 1382884935), parent name: 'evPhysicsEdgeData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evPhysicsWallCrawlData // hashcode: 0x27DFBF06 (dec: 668974854)
{
	short Segment;				   // size=0, offset=0 //  hashcode: 0xC6427418 (dec: -968723432), parent name: 'evPhysicsWallCrawlData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Length;				   // size=0, offset=2 //  hashcode: 0x388E0813 (dec: 948832275), parent name: 'evPhysicsWallCrawlData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ForwardOffset;		   // size=0, offset=4 //  hashcode: 0x9F16BA5A (dec: -1625900454), parent name: 'evPhysicsWallCrawlData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short NormalDistance;		   // size=0, offset=6 //  hashcode: 0xB78EABDF (dec: -1215386657), parent name: 'evPhysicsWallCrawlData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector DropNormal;	// size=8, offset=8 //  hashcode: 0xFE1182E7 (dec: -32406809), parent name: 'evPhysicsWallCrawlData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector ForwardNormal; // size=8, offset=16 //  hashcode: 0x8A9BB55A (dec: -1969506982), parent name: 'evPhysicsWallCrawlData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position NewPosition;  // size=6, offset=24 //  hashcode: 0x35423783 (dec: 893532035), parent name: 'evPhysicsWallCrawlData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation DropRotation; // size=8, offset=30 //  hashcode: 0x692FBD3E (dec: 1764736318), parent name: 'evPhysicsWallCrawlData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ForwardXRotation;		   // size=0, offset=38 //  hashcode: 0xFFD8A2F4 (dec: -2579724), parent name: 'evPhysicsWallCrawlData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int rc;						   // size=0, offset=40 //  hashcode: 0x4D3CFC4C (dec: 1295842380), parent name: 'evPhysicsWallCrawlData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evPhysicsSwimData // hashcode: 0x947F2BE5 (dec: -1803605019)
{
	short CheckDepth;			// size=0, offset=0 //  hashcode: 0xC7026775 (dec: -956143755), parent name: 'evPhysicsSwimData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short SwimDepth;			// size=0, offset=2 //  hashcode: 0xB680E8CE (dec: -1233065778), parent name: 'evPhysicsSwimData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short WadeDepth;			// size=0, offset=4 //  hashcode: 0x6E0FF4FA (dec: 1846539514), parent name: 'evPhysicsSwimData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short TreadDepth;			// size=0, offset=6 //  hashcode: 0xA4DB8D00 (dec: -1529115392), parent name: 'evPhysicsSwimData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector *iVelocity; // size=8, offset=8 //  hashcode: 0x4FA3A3EA (dec: 1336124394), parent name: 'evPhysicsSwimData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Depth;				// size=0, offset=12 //  hashcode: 0x9F1499E8 (dec: -1626039832), parent name: 'evPhysicsSwimData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short WaterDepth;			// size=0, offset=14 //  hashcode: 0xC4EEE3DD (dec: -990977059), parent name: 'evPhysicsSwimData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short rc;					// size=0, offset=16 //  hashcode: 0x96AE20D1 (dec: -1766973231), parent name: 'evPhysicsSwimData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;					// size=0, offset=18 //  hashcode: 0x1FFF8FE2 (dec: 536842210), parent name: 'evPhysicsSwimData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int WaterLevel;				// size=0, offset=20 //  hashcode: 0x15E8916B (dec: 367563115), parent name: 'evPhysicsSwimData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evPhysicsDropHeightData // hashcode: 0x5DCE3926 (dec: 1573796134)
{
	struct _Position origin; // size=6, offset=0 //  hashcode: 0x58C47336 (dec: 1489269558), parent name: 'evPhysicsDropHeightData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short mode;				 // size=0, offset=6 //  hashcode: 0x8898B719 (dec: -2003257575), parent name: 'evPhysicsDropHeightData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short DropOffset;		 // size=0, offset=8 //  hashcode: 0x789522EC (dec: 2023039724), parent name: 'evPhysicsDropHeightData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short result;			 // size=0, offset=10 //  hashcode: 0x95F35881 (dec: -1779214207), parent name: 'evPhysicsDropHeightData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct BSPTree *bsp;	 // size=36, offset=12 //  hashcode: 0xDE001223 (dec: -570420701), parent name: 'evPhysicsDropHeightData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=16 //  hashcode: 0xAF928CEB (dec: -1349350165), parent name: 'evPhysicsDropHeightData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evPhysicsLinkedMoveData // hashcode: 0xB4C6EBA9 (dec: -1262031959)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0x70DBBDCF (dec: 1893449167), parent name: 'evPhysicsLinkedMoveData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int segment;				// size=0, offset=4 //  hashcode: 0xC7535325 (dec: -950840539), parent name: 'evPhysicsLinkedMoveData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector posDelta;   // size=8, offset=8 //  hashcode: 0x68F5F3AF (dec: 1760949167), parent name: 'evPhysicsLinkedMoveData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector rotDelta;   // size=8, offset=16 //  hashcode: 0x61D76E31 (dec: 1641508401), parent name: 'evPhysicsLinkedMoveData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evFXHitData // hashcode: 0x3D609E61 (dec: 1029742177)
{
	struct _SVector location; // size=8, offset=0 //  hashcode: 0x209A25E5 (dec: 546973157), parent name: 'evFXHitData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector velocity; // size=8, offset=8 //  hashcode: 0xCC8FE7F9 (dec: -862984199), parent name: 'evFXHitData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short amount;			  // size=0, offset=16 //  hashcode: 0x7849FBAF (dec: 2018114479), parent name: 'evFXHitData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short type;				  // size=0, offset=18 //  hashcode: 0x88F46757 (dec: -1997248681), parent name: 'evFXHitData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evAnimationControllerDoneData // hashcode: 0x06BA7BE4 (dec: 112884708)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0x952223E1 (dec: -1792924703), parent name: 'evAnimationControllerDoneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long segment;				// size=0, offset=4 //  hashcode: 0x351A3C8E (dec: 890911886), parent name: 'evAnimationControllerDoneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	long type;					// size=0, offset=8 //  hashcode: 0xB67CB427 (dec: -1233341401), parent name: 'evAnimationControllerDoneData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int data;					// size=0, offset=12 //  hashcode: 0x0E5E87D6 (dec: 241076182), parent name: 'evAnimationControllerDoneData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evMonsterImpaleData // hashcode: 0x6537B50B (dec: 1698149643)
{
	struct _Instance *weapon;   // size=616, offset=0 //  hashcode: 0xB70582D9 (dec: -1224375591), parent name: 'evMonsterImpaleData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation direction; // size=8, offset=4 //  hashcode: 0xEB904A47 (dec: -342865337), parent name: 'evMonsterImpaleData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position position;  // size=6, offset=12 //  hashcode: 0x364BBB3B (dec: 910932795), parent name: 'evMonsterImpaleData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short distance;				// size=0, offset=18 //  hashcode: 0x6F36A396 (dec: 1865851798), parent name: 'evMonsterImpaleData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evObjectBreakOffData // hashcode: 0xE7DCD1A1 (dec: -404958815)
{
	struct _Instance *force;  // size=616, offset=0 //  hashcode: 0xD313CAC8 (dec: -753677624), parent name: 'evObjectBreakOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short node;	  // size=0, offset=4 //  hashcode: 0xC8121721 (dec: -938338527), parent name: 'evObjectBreakOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short distance;			  // size=0, offset=6 //  hashcode: 0xDA5F713F (dec: -631279297), parent name: 'evObjectBreakOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short animation; // size=0, offset=8 //  hashcode: 0xD645CDCF (dec: -700068401), parent name: 'evObjectBreakOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short frame;	 // size=0, offset=10 //  hashcode: 0x5AFBD73B (dec: 1526454075), parent name: 'evObjectBreakOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short type;	  // size=0, offset=12 //  hashcode: 0xF86376B6 (dec: -127699274), parent name: 'evObjectBreakOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short action;	// size=0, offset=14 //  hashcode: 0xE91708A2 (dec: -384366430), parent name: 'evObjectBreakOffData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evObjectAbsorbData // hashcode: 0x1379C145 (dec: 326746437)
{
	struct _Instance *force; // size=616, offset=0 //  hashcode: 0x9AD7D097 (dec: -1697132393), parent name: 'evObjectAbsorbData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short node;	 // size=0, offset=4 //  hashcode: 0x8BC89C2E (dec: -1949787090), parent name: 'evObjectAbsorbData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short steps;	// size=0, offset=6 //  hashcode: 0x1F7E9409 (dec: 528389129), parent name: 'evObjectAbsorbData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evObjectIdleData // hashcode: 0x7C5C48CC (dec: 2086422732)
{
	long mode;					// size=0, offset=0 //  hashcode: 0xB327F483 (dec: -1289227133), parent name: 'evObjectIdleData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=4 //  hashcode: 0xFEC6B87D (dec: -20531075), parent name: 'evObjectIdleData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evControlInitHangData // hashcode: 0xA248117B (dec: -1572335237)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0x34F8F7AC (dec: 888731564), parent name: 'evControlInitHangData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int frame;					// size=0, offset=4 //  hashcode: 0x657A6A05 (dec: 1702521349), parent name: 'evControlInitHangData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int frames;					// size=0, offset=8 //  hashcode: 0xAA508410 (dec: -1437563888), parent name: 'evControlInitHangData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evControlInitIdleData // hashcode: 0xB37CA3C6 (dec: -1283677242)
{
	int mode;   // size=0, offset=0 //  hashcode: 0xF9F22FBA (dec: -101568582), parent name: 'evControlInitIdleData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int frame;  // size=0, offset=4 //  hashcode: 0x7DC2596F (dec: 2109888879), parent name: 'evControlInitIdleData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int frames; // size=0, offset=8 //  hashcode: 0x09759BA0 (dec: 158702496), parent name: 'evControlInitIdleData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evActionLookAroundData // hashcode: 0x27BD6BB6 (dec: 666725302)
{
	short *rotx; // size=0, offset=0 //  hashcode: 0xA11FA4B5 (dec: -1591761739), parent name: 'evActionLookAroundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short *rotz; // size=0, offset=4 //  hashcode: 0xE6DCB884 (dec: -421742460), parent name: 'evActionLookAroundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minx;  // size=0, offset=8 //  hashcode: 0xA53902EC (dec: -1522990356), parent name: 'evActionLookAroundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxx;  // size=0, offset=10 //  hashcode: 0x5259CA21 (dec: 1381616161), parent name: 'evActionLookAroundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minz;  // size=0, offset=12 //  hashcode: 0x6B7C257E (dec: 1803298174), parent name: 'evActionLookAroundData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxz;  // size=0, offset=14 //  hashcode: 0xA52064D0 (dec: -1524603696), parent name: 'evActionLookAroundData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evActionPlayHostAnimationData // hashcode: 0x89FEF84B (dec: -1979778997)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0xE5F64EC7 (dec: -436842809), parent name: 'evActionPlayHostAnimationData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *host;		// size=616, offset=4 //  hashcode: 0x5134C2CD (dec: 1362412237), parent name: 'evActionPlayHostAnimationData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int newAnim;				// size=0, offset=8 //  hashcode: 0x5C1D0510 (dec: 1545405712), parent name: 'evActionPlayHostAnimationData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int newFrame;				// size=0, offset=12 //  hashcode: 0x9FA43540 (dec: -1616628416), parent name: 'evActionPlayHostAnimationData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int frames;					// size=0, offset=16 //  hashcode: 0x1AEA738A (dec: 451572618), parent name: 'evActionPlayHostAnimationData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int mode;					// size=0, offset=20 //  hashcode: 0xFA1C7EED (dec: -98795795), parent name: 'evActionPlayHostAnimationData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evShadowSegmentData // hashcode: 0xE814E960 (dec: -401282720)
{
	unsigned long totalShadowSegments; // size=0, offset=0 //  hashcode: 0xE8B2B627 (dec: -390941145), parent name: 'evShadowSegmentData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short shadowSegments[4];  // size=8, offset=4 //  hashcode: 0x6E993041 (dec: 1855533121), parent name: 'evShadowSegmentData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct LitShaftProperties // hashcode: 0x6DFDA06C (dec: 1845338220)
{
	short fadeValue; // size=0, offset=0 //  hashcode: 0x7E9E7E99 (dec: 2124316313), parent name: 'LitShaftProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;		 // size=0, offset=2 //  hashcode: 0xA6D43814 (dec: -1496041452), parent name: 'LitShaftProperties', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SavedEventSmallVars // hashcode: 0xE3137261 (dec: -485264799)
{
	unsigned char savedID;		   // size=0, offset=0 //  hashcode: 0x0C9ED883 (dec: 211736707), parent name: 'SavedEventSmallVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char shiftedSaveSize; // size=0, offset=1 //  hashcode: 0x0A0D022C (dec: 168624684), parent name: 'SavedEventSmallVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short areaID;				   // size=0, offset=2 //  hashcode: 0xB6A1B5C2 (dec: -1230916158), parent name: 'SavedEventSmallVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char eventNumber;			   // size=0, offset=4 //  hashcode: 0xC306B80D (dec: -1022969843), parent name: 'SavedEventSmallVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char eventVariables[5];		   // size=5, offset=5 //  hashcode: 0x00C4D7FE (dec: 12900350), parent name: 'SavedEventSmallVars', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct WaterLevelProcess // hashcode: 0x43FF89D3 (dec: 1140820435)
{
	long flags;						// size=0, offset=0 //  hashcode: 0x65AC427B (dec: 1705788027), parent name: 'WaterLevelProcess', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct BSPTree *bspTree;		// size=36, offset=4 //  hashcode: 0x8BC295C0 (dec: -1950181952), parent name: 'WaterLevelProcess', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _StreamUnit *streamUnit; // size=0, offset=8 //  hashcode: 0x880425E2 (dec: -2012994078), parent name: 'WaterLevelProcess', parent hashcode: 0xFFFFFFFF (dec: -1)
	short oldWaterZ;				// size=0, offset=12 //  hashcode: 0x29AED2B5 (dec: 699323061), parent name: 'WaterLevelProcess', parent hashcode: 0xFFFFFFFF (dec: -1)
	short oldGlobalOffset;			// size=0, offset=14 //  hashcode: 0xDB850091 (dec: -612040559), parent name: 'WaterLevelProcess', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zValueFrom;				// size=0, offset=16 //  hashcode: 0xB6838D0C (dec: -1232892660), parent name: 'WaterLevelProcess', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zValueTo;					// size=0, offset=18 //  hashcode: 0xB553046F (dec: -1252850577), parent name: 'WaterLevelProcess', parent hashcode: 0xFFFFFFFF (dec: -1)
	long maxSteps;					// size=0, offset=20 //  hashcode: 0xC0C59FE5 (dec: -1060790299), parent name: 'WaterLevelProcess', parent hashcode: 0xFFFFFFFF (dec: -1)
	long curStep;					// size=0, offset=24 //  hashcode: 0x44F671E6 (dec: 1157001702), parent name: 'WaterLevelProcess', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EventInstanceObject // hashcode: 0xC22B6786 (dec: -1037342842)
{
	short id;					// size=0, offset=0 //  hashcode: 0x6DBCCEE0 (dec: 1841090272), parent name: 'EventInstanceObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;				// size=0, offset=2 //  hashcode: 0x4718173F (dec: 1192761151), parent name: 'EventInstanceObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long unitID;				// size=0, offset=4 //  hashcode: 0x83956E14 (dec: -2087358956), parent name: 'EventInstanceObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long introUniqueID;			// size=0, offset=8 //  hashcode: 0x1F6DC8E9 (dec: 527288553), parent name: 'EventInstanceObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance; // size=616, offset=12 //  hashcode: 0xFF6746CF (dec: -10008881), parent name: 'EventInstanceObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	;							// size=4, offset=16 //  hashcode: 0x98327B6B (dec: -1741522069), parent name: 'EventInstanceObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EventEventObject // hashcode: 0x59DD7B24 (dec: 1507687204)
{
	short id;			 // size=0, offset=0 //  hashcode: 0x9DB55121 (dec: -1649061599), parent name: 'EventEventObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short eventNumber;   // size=0, offset=2 //  hashcode: 0x53B7C129 (dec: 1404551465), parent name: 'EventEventObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long unitID;		 // size=0, offset=4 //  hashcode: 0x6F4A580F (dec: 1867143183), parent name: 'EventEventObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Event *event; // size=0, offset=8 //  hashcode: 0x69364663 (dec: 1765164643), parent name: 'EventEventObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EventTGroupObject // hashcode: 0x9ED92E4E (dec: -1629934002)
{
	short id;					// size=0, offset=0 //  hashcode: 0x79FEDB88 (dec: 2046745480), parent name: 'EventTGroupObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	short tgroupNumber;			// size=0, offset=2 //  hashcode: 0xAAC86F65 (dec: -1429704859), parent name: 'EventTGroupObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	long unitID;				// size=0, offset=4 //  hashcode: 0x3ABD6A27 (dec: 985492007), parent name: 'EventTGroupObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct BSPTree *bspTree;	// size=36, offset=8 //  hashcode: 0x89BD6506 (dec: -1984076538), parent name: 'EventTGroupObject', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _StreamUnit *stream; // size=0, offset=12 //  hashcode: 0x22B3A822 (dec: 582199330), parent name: 'EventTGroupObject', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct TGroupObject_alt_definition_0002 // hashcode: 0x2189023C (dec: 562627132)
{
	struct BSPTree *bspTree;		// size=36, offset=0 //  hashcode: 0x174C221D (dec: 390865437), parent name: 'TGroupObject_alt_definition_0002', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _StreamUnit *streamUnit; // size=0, offset=4 //  hashcode: 0x85EFE4C8 (dec: -2047875896), parent name: 'TGroupObject_alt_definition_0002', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;					// size=0, offset=8 //  hashcode: 0x34DDDEB2 (dec: 886955698), parent name: 'TGroupObject_alt_definition_0002', parent hashcode: 0xFFFFFFFF (dec: -1)
	short arg[2];					// size=4, offset=12 //  hashcode: 0x4E196F33 (dec: 1310289715), parent name: 'TGroupObject_alt_definition_0002', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct AreaObject_alt_definition_0002 // hashcode: 0x28FC6B98 (dec: 687631256)
{
	struct _StreamUnit *streamUnit; // size=0, offset=0 //  hashcode: 0x947D6C72 (dec: -1803719566), parent name: 'AreaObject_alt_definition_0002', parent hashcode: 0xFFFFFFFF (dec: -1)
	long attribute;					// size=0, offset=4 //  hashcode: 0x346DC52F (dec: 879609135), parent name: 'AreaObject_alt_definition_0002', parent hashcode: 0xFFFFFFFF (dec: -1)
	long unitID;					// size=0, offset=8 //  hashcode: 0x343D7503 (dec: 876442883), parent name: 'AreaObject_alt_definition_0002', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EventTimer // hashcode: 0xAA55BC81 (dec: -1437221759)
{
	long flags : 1;					  // offset=0.0 //  hashcode: 0xDE37D1E7 (dec: -566767129), parent name: 'EventTimer', parent hashcode: 0xFFFFFFFF (dec: -1)
	long time : 31;					  // offset=0.1 //  hashcode: 0xAD262168 (dec: -1390010008), parent name: 'EventTimer', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Event *event;			  // size=28, offset=4 //  hashcode: 0xA2F750C1 (dec: -1560850239), parent name: 'EventTimer', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct ScriptPCode *actionScript; // size=8, offset=8 //  hashcode: 0x4BDED8C7 (dec: 1272895687), parent name: 'EventTimer', parent hashcode: 0xFFFFFFFF (dec: -1)
	short *scriptPos;				  // size=0, offset=12 //  hashcode: 0x7A7D9083 (dec: 2055049347), parent name: 'EventTimer', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Level *level;			  // size=392, offset=16 //  hashcode: 0xE45C1371 (dec: -463727759), parent name: 'EventTimer', parent hashcode: 0xFFFFFFFF (dec: -1)
	long nextEventIndex;			  // size=0, offset=20 //  hashcode: 0x86965A60 (dec: -2036966816), parent name: 'EventTimer', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct SignalResetStruct // hashcode: 0x8D08210C (dec: -1928847092)
{
	struct _MultiSignal *mSignal; // size=904, offset=0 //  hashcode: 0xED2FF6E9 (dec: -315623703), parent name: 'SignalResetStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timeLeft;				  // size=0, offset=4 //  hashcode: 0x111BC0CE (dec: 287031502), parent name: 'SignalResetStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct HintSystemStruct // hashcode: 0xAD521037 (dec: -1387130825)
{
	short flags;		 // size=0, offset=0 //  hashcode: 0x1DE3DDE6 (dec: 501472742), parent name: 'HintSystemStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	short hintNumber;	// size=0, offset=2 //  hashcode: 0x7F31C941 (dec: 2133969217), parent name: 'HintSystemStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	short stringNumber;  // size=0, offset=4 //  hashcode: 0x76A79509 (dec: 1990694153), parent name: 'HintSystemStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;			 // size=0, offset=6 //  hashcode: 0xAAAC2BB9 (dec: -1431557191), parent name: 'HintSystemStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	long fadeTimer;		 // size=0, offset=8 //  hashcode: 0xF633EDDC (dec: -164368932), parent name: 'HintSystemStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
	long spawningUnitID; // size=0, offset=12 //  hashcode: 0x91F53A0D (dec: -1846199795), parent name: 'HintSystemStruct', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterAttributes // hashcode: 0x9EE88812 (dec: -1628927982)
{
	unsigned long magicnum;									// size=0, offset=0 //  hashcode: 0xC4E96AE4 (dec: -991335708), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *tunData;											// size=0, offset=4 //  hashcode: 0xDBEF3B8B (dec: -605078645), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *auxAnimList;										// size=0, offset=8 //  hashcode: 0xE1E0DD2A (dec: -505357014), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *ambientAnimList;									// size=0, offset=12 //  hashcode: 0x26CA08A4 (dec: 650774692), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	long whatAmI;											// size=0, offset=16 //  hashcode: 0x30C0439D (dec: 817906589), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numAuxAnims;										// size=0, offset=20 //  hashcode: 0x7CC394DC (dec: 2093192412), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numAmbientAnims;									// size=0, offset=21 //  hashcode: 0x4DE37AF1 (dec: 1306753777), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char defaultAge;								// size=0, offset=22 //  hashcode: 0x5B157D23 (dec: 1528134947), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char pupateObject;										// size=0, offset=23 //  hashcode: 0xCAC4E5B8 (dec: -893065800), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char damageFXSegment;							// size=0, offset=24 //  hashcode: 0x2565BDF6 (dec: 627424758), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char headSegment;								// size=0, offset=25 //  hashcode: 0xF2F283D3 (dec: -218987565), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char neckSegment;								// size=0, offset=26 //  hashcode: 0xE284B47F (dec: -494619521), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char leftShoulderSegment;						// size=0, offset=27 //  hashcode: 0x5D689B63 (dec: 1567136611), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char rightShoulderSegment;						// size=0, offset=28 //  hashcode: 0x0E7566DF (dec: 242575071), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char waistSegment;								// size=0, offset=29 //  hashcode: 0x4CB8B2E6 (dec: 1287172838), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char leftKneeSegment;							// size=0, offset=30 //  hashcode: 0x336F27CE (dec: 862922702), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char rightKneeSegment;							// size=0, offset=31 //  hashcode: 0x9ECD5B71 (dec: -1630708879), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char leftFootSegment;							// size=0, offset=32 //  hashcode: 0x4411323F (dec: 1141977663), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char rightFootSegment;							// size=0, offset=33 //  hashcode: 0x0BA0DBE9 (dec: 195091433), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char spineSegment;								// size=0, offset=34 //  hashcode: 0x9B461EB5 (dec: -1689903435), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char leftWeaponSegment;						// size=0, offset=35 //  hashcode: 0xD144BA1A (dec: -784025062), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char rightWeaponSegment;						// size=0, offset=36 //  hashcode: 0xFE53DB50 (dec: -28058800), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char grabSegment;								// size=0, offset=37 //  hashcode: 0x08EF3ABA (dec: 149895866), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char bloodImpaleFrame;							// size=0, offset=38 //  hashcode: 0x8BE5AD48 (dec: -1947882168), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char bloodConeFrame;							// size=0, offset=39 //  hashcode: 0xC1689517 (dec: -1050110697), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numSubAttributes;									// size=0, offset=40 //  hashcode: 0x4351C6AB (dec: 1129432747), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numCombatAttributes;								// size=0, offset=41 //  hashcode: 0xB48F407E (dec: -1265680258), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numAttackAttributes;								// size=0, offset=42 //  hashcode: 0xE9A32073 (dec: -375185293), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numMissiles;										// size=0, offset=43 //  hashcode: 0xD4FF4294 (dec: -721468780), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numAnims;											// size=0, offset=44 //  hashcode: 0x356455CB (dec: 895768011), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numIdles;											// size=0, offset=45 //  hashcode: 0xE2B5AD87 (dec: -491410041), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numBehaviors;										// size=0, offset=46 //  hashcode: 0x6290709C (dec: 1653633180), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	char numShatters;										// size=0, offset=47 //  hashcode: 0xDC22804F (dec: -601718705), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterSubAttributes **subAttributesList;		// size=84, offset=48 //  hashcode: 0x4FD3C7CB (dec: 1339279307), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterCombatAttributes **combatAttributesList; // size=46, offset=52 //  hashcode: 0xF19FDF39 (dec: -241180871), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterAttackAttributes *attackAttributesList;  // size=32, offset=56 //  hashcode: 0xC1CB683D (dec: -1043634115), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterMissile *missileList;					// size=16, offset=60 //  hashcode: 0x84BAFE81 (dec: -2068119935), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterAnim *animList;							// size=16, offset=64 //  hashcode: 0x6629C28F (dec: 1714012815), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterIdle *idleList;							// size=4, offset=68 //  hashcode: 0x8D836C14 (dec: -1920766956), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterBehavior *behaviorList;					// size=8, offset=72 //  hashcode: 0xB38FEB92 (dec: -1282413678), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *shatterList;										// size=0, offset=76 //  hashcode: 0x49CC490B (dec: 1238124811), parent name: '_MonsterAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterVars // hashcode: 0xEF80566F (dec: -276801937)
{
	unsigned long mvFlags;						 // size=0, offset=0 //  hashcode: 0x768E425C (dec: 1989034588), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long auxFlags;						 // size=0, offset=4 //  hashcode: 0xC8C91E15 (dec: -926343659), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __MessageQueue messageQueue;			 // size=136, offset=8 //  hashcode: 0x28863516 (dec: 679884054), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterIR *monsterIRList;			 // size=0, offset=144 //  hashcode: 0x598DE9CC (dec: 1502472652), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimInterpInfo_Type interpInfo[3]; // size=36, offset=148 //  hashcode: 0x7C0E4EB1 (dec: 2081312433), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterAttackAttributes *attackType; // size=32, offset=184 //  hashcode: 0xC0D8BCA8 (dec: -1059537752), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterAnim *anim;					 // size=16, offset=188 //  hashcode: 0x2773D794 (dec: 661903252), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *messageData;							 // size=0, offset=192 //  hashcode: 0xEC9E5567 (dec: -325167769), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterIR *enemy;					 // size=0, offset=196 //  hashcode: 0x3BB0EF54 (dec: 1001451348), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterIR *leader;					 // size=0, offset=200 //  hashcode: 0x1F24599E (dec: 522475934), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterIR *ally;					 // size=0, offset=204 //  hashcode: 0x2C60F583 (dec: 744551811), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *held;						 // size=616, offset=208 //  hashcode: 0xFD283D82 (dec: -47694462), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	long heldID;								 // size=0, offset=212 //  hashcode: 0x355E078F (dec: 895354767), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	long soulID;								 // size=0, offset=216 //  hashcode: 0xF946456F (dec: -112835217), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *effect;								 // size=0, offset=220 //  hashcode: 0x275336C8 (dec: 659764936), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short radarMap;					 // size=0, offset=224 //  hashcode: 0x7D4F2A89 (dec: 2102340233), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short radarCounter;				 // size=0, offset=226 //  hashcode: 0xCE1B227B (dec: -837082501), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short radarDistance[8];						 // size=16, offset=228 //  hashcode: 0x392F9569 (dec: 959419753), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long mode;							 // size=0, offset=244 //  hashcode: 0x32BC55DE (dec: 851203550), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long damageTimer;					 // size=0, offset=248 //  hashcode: 0x509A9B1B (dec: 1352309531), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long stunTimer;					 // size=0, offset=252 //  hashcode: 0xB51D27D5 (dec: -1256380459), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long generalTimer;					 // size=0, offset=256 //  hashcode: 0x47223912 (dec: 1193425170), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long generalTimer2;				 // size=0, offset=260 //  hashcode: 0x71DA2A3B (dec: 1910123067), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long effectTimer;					 // size=0, offset=264 //  hashcode: 0x03BB6E79 (dec: 62615161), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position *lookAtPos;				 // size=6, offset=268 //  hashcode: 0x8BE898D2 (dec: -1947690798), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short speed;								 // size=0, offset=272 //  hashcode: 0xF18FB0BC (dec: -242241348), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position destination;				 // size=6, offset=274 //  hashcode: 0xDF88008D (dec: -544735091), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fleeMarker;							 // size=0, offset=280 //  hashcode: 0x62D77D7F (dec: 1658289535), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position lastValidPos;				 // size=6, offset=282 //  hashcode: 0xF3A77350 (dec: -207129776), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short wanderRange;							 // size=0, offset=288 //  hashcode: 0xA098DAD8 (dec: -1600595240), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position lookAtPosData;				 // size=6, offset=290 //  hashcode: 0x094FC815 (dec: 156223509), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short guardRange;							 // size=0, offset=296 //  hashcode: 0xED2DB5CF (dec: -315771441), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ambushRange;							 // size=0, offset=298 //  hashcode: 0x6237C7C7 (dec: 1647822791), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ambushArc;							 // size=0, offset=300 //  hashcode: 0xB7BDC572 (dec: -1212299918), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short ambushElevation;						 // size=0, offset=302 //  hashcode: 0x42EDBDFD (dec: 1122876925), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short hitPoints;							 // size=0, offset=304 //  hashcode: 0xD6A3DA6A (dec: -693904790), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxHitPoints;							 // size=0, offset=306 //  hashcode: 0x49687BF0 (dec: 1231584240), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soulJuice;							 // size=0, offset=308 //  hashcode: 0x56A74C32 (dec: 1453804594), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short regenTime;							 // size=0, offset=310 //  hashcode: 0x8DE26D84 (dec: -1914540668), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short mainColorVertex;						 // size=0, offset=312 //  hashcode: 0x37160066 (dec: 924188774), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lookAngleX;							 // size=0, offset=314 //  hashcode: 0xBACAC2E0 (dec: -1161116960), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short lookAngleZ;							 // size=0, offset=316 //  hashcode: 0xD5B5DB53 (dec: -709502125), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short avoidMask;					 // size=0, offset=318 //  hashcode: 0x15A8504C (dec: 363352140), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short damageType;					 // size=0, offset=320 //  hashcode: 0x649FBCDE (dec: 1688190174), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char ambushMarker;							 // size=0, offset=322 //  hashcode: 0x8C3C9150 (dec: -1942187696), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char ambushJumpType;						 // size=0, offset=323 //  hashcode: 0x65C08AAB (dec: 1707117227), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char causeOfDeath;					 // size=0, offset=324 //  hashcode: 0xBB8CAC82 (dec: -1148408702), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char previousMainState;						 // size=0, offset=325 //  hashcode: 0x279A4FC0 (dec: 664424384), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char behaviorState;				 // size=0, offset=326 //  hashcode: 0xACC9242B (dec: -1396104149), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char initialBehavior;				 // size=0, offset=327 //  hashcode: 0x35828FC0 (dec: 897748928), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char triggeredBehavior;			 // size=0, offset=328 //  hashcode: 0xD31FF778 (dec: -752879752), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char activeBehavior;						 // size=0, offset=329 //  hashcode: 0x2735B770 (dec: 657831792), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char age;							 // size=0, offset=330 //  hashcode: 0xD838ACED (dec: -667374355), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char attackState;							 // size=0, offset=331 //  hashcode: 0xE635CAA3 (dec: -432682333), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char ambient;						 // size=0, offset=332 //  hashcode: 0x5BF2322A (dec: 1542599210), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char alertness;								 // size=0, offset=333 //  hashcode: 0x420D0F73 (dec: 1108152179), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char alertCount;							 // size=0, offset=334 //  hashcode: 0x9CD90F92 (dec: -1663496302), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char senseIndex;							 // size=0, offset=335 //  hashcode: 0x8B1E4B9E (dec: -1960948834), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char lastSideMove;							 // size=0, offset=336 //  hashcode: 0xB6F47FA4 (dec: -1225490524), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char chance;								 // size=0, offset=337 //  hashcode: 0x6D2778C4 (dec: 1831303364), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	char pathSlotID;							 // size=0, offset=338 //  hashcode: 0x744D9D31 (dec: 1951243569), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterSubAttributes *subAttr;		 // size=84, offset=340 //  hashcode: 0xA85C2D8E (dec: -1470354034), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterIR *freeIRs;					 // size=0, offset=344 //  hashcode: 0xABADEAB6 (dec: -1414665546), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *extraVars;							 // size=0, offset=348 //  hashcode: 0x4D5AB265 (dec: 1297789541), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short validUnits[10];						 // size=20, offset=352 //  hashcode: 0xD5CC575A (dec: -708028582), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short patrolMarkers[12];					 // size=24, offset=372 //  hashcode: 0x1C351963 (dec: 473241955), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short *currentMarker;						 // size=0, offset=396 //  hashcode: 0xC520AC5D (dec: -987714467), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	long terrainImpaleID;						 // size=0, offset=400 //  hashcode: 0xFA9EBB2E (dec: -90260690), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short targetFade;							 // size=0, offset=404 //  hashcode: 0x32F3EDF4 (dec: 854846964), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fadeRate;								 // size=0, offset=406 //  hashcode: 0x4766E253 (dec: 1197924947), parent name: '_MonsterVars', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterIR // hashcode: 0x41A7CD43 (dec: 1101516099)
{
	struct _MonsterIR *next;		  // size=36, offset=0 //  hashcode: 0xD2C1DC42 (dec: -759047102), parent name: '_MonsterIR', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *instance;		  // size=616, offset=4 //  hashcode: 0xB02F0157 (dec: -1339096745), parent name: '_MonsterIR', parent hashcode: 0xFFFFFFFF (dec: -1)
	long handle;					  // size=0, offset=8 //  hashcode: 0xE50F67BF (dec: -451975233), parent name: '_MonsterIR', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector relativePosition; // size=8, offset=12 //  hashcode: 0x6A80DE42 (dec: 1786830402), parent name: '_MonsterIR', parent hashcode: 0xFFFFFFFF (dec: -1)
	short distance;					  // size=0, offset=20 //  hashcode: 0x98B0C3D3 (dec: -1733245997), parent name: '_MonsterIR', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short mirFlags;		  // size=0, offset=22 //  hashcode: 0xC5929E47 (dec: -980246969), parent name: '_MonsterIR', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short mirConditions;	 // size=0, offset=24 //  hashcode: 0x52BD2D80 (dec: 1388129664), parent name: '_MonsterIR', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long forgetTimer;		  // size=0, offset=28 //  hashcode: 0x2EAB73D8 (dec: 782988248), parent name: '_MonsterIR', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long idleTime;			  // size=0, offset=32 //  hashcode: 0xFBBB8526 (dec: -71596762), parent name: '_MonsterIR', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct burntTuneType // hashcode: 0x127E6332 (dec: 310272818)
{
	int burntDist; // size=0, offset=0 //  hashcode: 0xA116CDEA (dec: -1592341014), parent name: 'burntTuneType', parent hashcode: 0xFFFFFFFF (dec: -1)
	int fadeDelta; // size=0, offset=4 //  hashcode: 0xE89F35CC (dec: -392219188), parent name: 'burntTuneType', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterState // hashcode: 0x1B0172BB (dec: 453079739)
{
	void (*entryFunction)(); // size=0, offset=0 //  hashcode: 0x7172E8B7 (dec: 1903356087), parent name: '_MonsterState', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*stateFunction)(); // size=0, offset=4 //  hashcode: 0xF5BF6441 (dec: -172006335), parent name: '_MonsterState', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterStateChoice // hashcode: 0xE0AABD5C (dec: -525681316)
{
	int state;						// size=0, offset=0 //  hashcode: 0x0ECAC460 (dec: 248169568), parent name: '_MonsterStateChoice', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterState functions; // size=8, offset=4 //  hashcode: 0x5C21CE6E (dec: 1545719406), parent name: '_MonsterStateChoice', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __GlyphData // hashcode: 0x9C88C1F1 (dec: -1668759055)
{
	void (*process)();				// size=0, offset=0 //  hashcode: 0x85A72949 (dec: -2052642487), parent name: '__GlyphData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __MessageQueue messages; // size=136, offset=4 //  hashcode: 0x60191D97 (dec: 1612258711), parent name: '__GlyphData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short selectedGlyph;			// size=0, offset=140 //  hashcode: 0xDC89F698 (dec: -594938216), parent name: '__GlyphData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short glyph_open;				// size=0, offset=142 //  hashcode: 0x5B86EEAE (dec: 1535569582), parent name: '__GlyphData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short glyph_time;				// size=0, offset=144 //  hashcode: 0xFE369858 (dec: -29976488), parent name: '__GlyphData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short glyph_radius;				// size=0, offset=146 //  hashcode: 0x3496F851 (dec: 882309201), parent name: '__GlyphData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short glyph_scale;				// size=0, offset=148 //  hashcode: 0xD1B74662 (dec: -776518046), parent name: '__GlyphData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short glyph_rotation;			// size=0, offset=150 //  hashcode: 0xA8AD58B4 (dec: -1465034572), parent name: '__GlyphData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short target_glyph_rotation;	// size=0, offset=152 //  hashcode: 0x55AD99DC (dec: 1437440476), parent name: '__GlyphData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short glyph_movement;			// size=0, offset=154 //  hashcode: 0x33CAF248 (dec: 868938312), parent name: '__GlyphData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterFunctionTable // hashcode: 0x82983F8D (dec: -2103951475)
{
	void (*initFunc)();						// size=0, offset=0 //  hashcode: 0xCBBC575B (dec: -876849317), parent name: '_MonsterFunctionTable', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*cleanUpFunc)();					// size=0, offset=4 //  hashcode: 0xD6170F83 (dec: -703131773), parent name: '_MonsterFunctionTable', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*damageEffectFunc)();				// size=0, offset=8 //  hashcode: 0x2E1BD309 (dec: 773575433), parent name: '_MonsterFunctionTable', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long (*queryFunc)();			// size=0, offset=12 //  hashcode: 0x782B0EDC (dec: 2016087772), parent name: '_MonsterFunctionTable', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*messageFunc)();					// size=0, offset=16 //  hashcode: 0xFF570DEC (dec: -11072020), parent name: '_MonsterFunctionTable', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _MonsterStateChoice *stateFuncs; // size=12, offset=20 //  hashcode: 0x24D95F5F (dec: 618225503), parent name: '_MonsterFunctionTable', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *versionID;						// size=0, offset=24 //  hashcode: 0x2D456AF8 (dec: 759524088), parent name: '_MonsterFunctionTable', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *localVersionID;					// size=0, offset=28 //  hashcode: 0x5E7F8D29 (dec: 1585417513), parent name: '_MonsterFunctionTable', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MissileGraphics // hashcode: 0xD28383EB (dec: -763132949)
{
	unsigned char object; // size=0, offset=0 //  hashcode: 0xA8A63A16 (dec: -1465501162), parent name: 'MissileGraphics', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char model;  // size=0, offset=1 //  hashcode: 0xE9D5230B (dec: -371907829), parent name: 'MissileGraphics', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evMonsterHitTerrainData // hashcode: 0x4CD2E030 (dec: 1288888368)
{
	struct _TFace *tface;  // size=12, offset=0 //  hashcode: 0x559AE552 (dec: 1436214610), parent name: 'evMonsterHitTerrainData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Normal normal; // size=8, offset=4 //  hashcode: 0x0B5BA367 (dec: 190554983), parent name: 'evMonsterHitTerrainData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short faceFlags;	   // size=0, offset=12 //  hashcode: 0x55ACAB8A (dec: 1437379466), parent name: 'evMonsterHitTerrainData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short bspFlags;		   // size=0, offset=14 //  hashcode: 0x04825007 (dec: 75649031), parent name: 'evMonsterHitTerrainData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evMonsterHitObjectData // hashcode: 0xB7192556 (dec: -1223088810)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0xB91B731D (dec: -1189383395), parent name: 'evMonsterHitObjectData', parent hashcode: 0xFFFFFFFF (dec: -1)
	int hitType;				// size=0, offset=4 //  hashcode: 0x23159BF2 (dec: 588618738), parent name: 'evMonsterHitObjectData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _MonsterSaveInfo // hashcode: 0x3088BC75 (dec: 814267509)
{
	long mvFlags;					// size=0, offset=0 //  hashcode: 0x5259468D (dec: 1381582477), parent name: '_MonsterSaveInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	long auxFlags;					// size=0, offset=4 //  hashcode: 0x90F2B2F1 (dec: -1863142671), parent name: '_MonsterSaveInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soulID;					// size=0, offset=8 //  hashcode: 0xD7ABD5E6 (dec: -676604442), parent name: '_MonsterSaveInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soulJuice;				// size=0, offset=10 //  hashcode: 0x3142A27D (dec: 826450557), parent name: '_MonsterSaveInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned int age : 3;			// offset=12.0 //  hashcode: 0x47266391 (dec: 1193698193), parent name: '_MonsterSaveInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned int state : 6;			// offset=12.3 //  hashcode: 0xDEA78530 (dec: -559446736), parent name: '_MonsterSaveInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned int behaviorState : 5; // offset=13.1 //  hashcode: 0x948FA7BF (dec: -1802524737), parent name: '_MonsterSaveInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned int anim : 6;			// offset=13.6 //  hashcode: 0x5CFBC032 (dec: 1560002610), parent name: '_MonsterSaveInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned int animLooping : 1;   // offset=14.4 //  hashcode: 0x9558AB72 (dec: -1789351054), parent name: '_MonsterSaveInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned int causeOfDeath : 3;  // offset=14.5 //  hashcode: 0x4A49C3FE (dec: 1246348286), parent name: '_MonsterSaveInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct evPhysicsLOSData // hashcode: 0x3AEAF56B (dec: 988476779)
{
	struct _Position destination; // size=6, offset=0 //  hashcode: 0x2194F4E1 (dec: 563410145), parent name: 'evPhysicsLOSData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short arc;					  // size=0, offset=6 //  hashcode: 0xD8A1B988 (dec: -660489848), parent name: 'evPhysicsLOSData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position origin;	  // size=6, offset=8 //  hashcode: 0x4E51F161 (dec: 1313993057), parent name: 'evPhysicsLOSData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short flags;				  // size=0, offset=14 //  hashcode: 0x0F842AAC (dec: 260319916), parent name: 'evPhysicsLOSData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short result;				  // size=0, offset=16 //  hashcode: 0xA757D920 (dec: -1487415008), parent name: 'evPhysicsLOSData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct RadarInfo // hashcode: 0xB8957CDE (dec: -1198162722)
{
	short angle; // size=0, offset=0 //  hashcode: 0x5EEC704C (dec: 1592553548), parent name: 'RadarInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short x;	 // size=0, offset=2 //  hashcode: 0x93A642D8 (dec: -1817820456), parent name: 'RadarInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=4 //  hashcode: 0xAC2AC700 (dec: -1406482688), parent name: 'RadarInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct burntMessType // hashcode: 0x8C763516 (dec: -1938410218)
{
	int closestvert;				 // size=0, offset=0 //  hashcode: 0x7811BB1D (dec: 2014427933), parent name: 'burntMessType', parent hashcode: 0xFFFFFFFF (dec: -1)
	int closestdist;				 // size=0, offset=4 //  hashcode: 0x9F84C6CF (dec: -1618688305), parent name: 'burntMessType', parent hashcode: 0xFFFFFFFF (dec: -1)
	int closestseg;					 // size=0, offset=8 //  hashcode: 0x364BCB43 (dec: 910936899), parent name: 'burntMessType', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct burntTuneType *burntTune; // size=8, offset=12 //  hashcode: 0xAE953EAA (dec: -1365950806), parent name: 'burntMessType', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct bloodyMessType // hashcode: 0x5F4737FF (dec: 1598502911)
{
	int closestvert;	// size=0, offset=0 //  hashcode: 0x6926A003 (dec: 1764139011), parent name: 'bloodyMessType', parent hashcode: 0xFFFFFFFF (dec: -1)
	int closestdist;	// size=0, offset=4 //  hashcode: 0x527A90EC (dec: 1383764204), parent name: 'bloodyMessType', parent hashcode: 0xFFFFFFFF (dec: -1)
	int closestseg;		// size=0, offset=8 //  hashcode: 0xC18D7EEF (dec: -1047691537), parent name: 'bloodyMessType', parent hashcode: 0xFFFFFFFF (dec: -1)
	int bloodiedAVert;  // size=0, offset=12 //  hashcode: 0x1B83481D (dec: 461588509), parent name: 'bloodyMessType', parent hashcode: 0xFFFFFFFF (dec: -1)
	int bloodIntensity; // size=0, offset=16 //  hashcode: 0x2B4B249C (dec: 726344860), parent name: 'bloodyMessType', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimController_Type // hashcode: 0x74838F3C (dec: 1954778940)
{
	unsigned short next;					   // size=0, offset=0 //  hashcode: 0x1B668904 (dec: 459704580), parent name: '_G2AnimController_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;						   // size=0, offset=2 //  hashcode: 0xED779F15 (dec: -310927595), parent name: '_G2AnimController_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char segNumber;				   // size=0, offset=3 //  hashcode: 0xA2FE6B4F (dec: -1560384689), parent name: '_G2AnimController_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *callbackData;						   // size=0, offset=4 //  hashcode: 0x6E2B2FA2 (dec: 1848324002), parent name: '_G2AnimController_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short flags;					   // size=0, offset=8 //  hashcode: 0x92C8626B (dec: -1832361365), parent name: '_G2AnimController_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short duration;							   // size=0, offset=10 //  hashcode: 0xBB90E2A1 (dec: -1148132703), parent name: '_G2AnimController_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	short elapsedTime;						   // size=0, offset=12 //  hashcode: 0x223F105E (dec: 574558302), parent name: '_G2AnimController_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimAlphaTable_Type *alphaTable; // size=4, offset=16 //  hashcode: 0xEC7B97FF (dec: -327444481), parent name: '_G2AnimController_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	;										   // size=16, offset=20 //  hashcode: 0x33EB88FA (dec: 871074042), parent name: '_G2AnimController_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimSegKeyflagInfo_Type // hashcode: 0x5786AAF7 (dec: 1468443383)
{
	unsigned long *stream; // size=0, offset=0 //  hashcode: 0x6858794C (dec: 1750628684), parent name: '_G2AnimSegKeyflagInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long flags;   // size=0, offset=4 //  hashcode: 0x4A587299 (dec: 1247310489), parent name: '_G2AnimSegKeyflagInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	int bitCount;		   // size=0, offset=8 //  hashcode: 0x845127C6 (dec: -2075056186), parent name: '_G2AnimSegKeyflagInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimDecompressChannelInfo_Type // hashcode: 0x9B2AEA69 (dec: -1691686295)
{
	struct _G2AnimKeylist_Type *keylist; // size=20, offset=0 //  hashcode: 0x97C53942 (dec: -1748682430), parent name: '_G2AnimDecompressChannelInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short *chanData;			 // size=0, offset=4 //  hashcode: 0xD74D584F (dec: -682796977), parent name: '_G2AnimDecompressChannelInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	int storedKey;						 // size=0, offset=8 //  hashcode: 0x8C703DC8 (dec: -1938801208), parent name: '_G2AnimDecompressChannelInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	int targetKey;						 // size=0, offset=12 //  hashcode: 0x30A5CF22 (dec: 816172834), parent name: '_G2AnimDecompressChannelInfo_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimSegValue_Type // hashcode: 0x862DA63B (dec: -2043828677)
{
	struct _G2SVector3_Type scale; // size=6, offset=8 //  hashcode: 0x947C1CE1 (dec: -1803805471), parent name: '_G2AnimSegValue_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pad;			   // size=0, offset=14 //  hashcode: 0x1E17E5F3 (dec: 504882675), parent name: '_G2AnimSegValue_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type trans; // size=6, offset=16 //  hashcode: 0x303F4D54 (dec: 809454932), parent name: '_G2AnimSegValue_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short bIsQuat;		   // size=0, offset=22 //  hashcode: 0x2DDE0F62 (dec: 769527650), parent name: '_G2AnimSegValue_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimChanStatusBlockPool_Type // hashcode: 0x795F01EF (dec: 2036269551)
{
	unsigned short blockSize;					   // size=0, offset=0 //  hashcode: 0x1DD678E4 (dec: 500594916), parent name: '_G2AnimChanStatusBlockPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short stackTop;					   // size=0, offset=2 //  hashcode: 0x64A09B0A (dec: 1688247050), parent name: '_G2AnimChanStatusBlockPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short stackSize;					   // size=0, offset=4 //  hashcode: 0xB304E082 (dec: -1291526014), parent name: '_G2AnimChanStatusBlockPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short *stack;						   // size=0, offset=8 //  hashcode: 0x1C3DA993 (dec: 473803155), parent name: '_G2AnimChanStatusBlockPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimChanStatusBlock_Type *blockPool; // size=36, offset=12 //  hashcode: 0x06A77474 (dec: 111637620), parent name: '_G2AnimChanStatusBlockPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimControllerPool_Type // hashcode: 0x7F1B4AF1 (dec: 2132495089)
{
	unsigned short blockSize;				  // size=0, offset=0 //  hashcode: 0x9DB88D3A (dec: -1648849606), parent name: '_G2AnimControllerPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short stackTop;				  // size=0, offset=2 //  hashcode: 0xA5594098 (dec: -1520877416), parent name: '_G2AnimControllerPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short stackSize;				  // size=0, offset=4 //  hashcode: 0x246980FB (dec: 610894075), parent name: '_G2AnimControllerPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short *stack;					  // size=0, offset=8 //  hashcode: 0xDBFE7326 (dec: -604081370), parent name: '_G2AnimControllerPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimController_Type *blockPool; // size=36, offset=12 //  hashcode: 0x599FE1F6 (dec: 1503650294), parent name: '_G2AnimControllerPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _G2AnimInterpStateBlockPool_Type // hashcode: 0x71F99BDD (dec: 1912183773)
{
	unsigned short blockSize;						// size=0, offset=0 //  hashcode: 0xE57DAAF1 (dec: -444749071), parent name: '_G2AnimInterpStateBlockPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short stackTop;						// size=0, offset=2 //  hashcode: 0xAF7EA68A (dec: -1350654326), parent name: '_G2AnimInterpStateBlockPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short stackSize;						// size=0, offset=4 //  hashcode: 0x81711D57 (dec: -2123293353), parent name: '_G2AnimInterpStateBlockPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short *stack;							// size=0, offset=8 //  hashcode: 0x1912A588 (dec: 420652424), parent name: '_G2AnimInterpStateBlockPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2AnimInterpStateBlock_Type *blockPool; // size=164, offset=12 //  hashcode: 0x03BA71BC (dec: 62550460), parent name: '_G2AnimInterpStateBlockPool_Type', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _walbossAttributes // hashcode: 0x300B2C35 (dec: 806038581)
{
	unsigned char segmentToAttach; // size=0, offset=0 //  hashcode: 0x8C902B70 (dec: -1936708752), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char frameToBirth;	// size=0, offset=1 //  hashcode: 0xDB6E3C5C (dec: -613532580), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char frameToExpel;	// size=0, offset=2 //  hashcode: 0xA22AF524 (dec: -1574243036), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char maxEggHits;	  // size=0, offset=3 //  hashcode: 0x32A2AEA7 (dec: 849522343), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxAngle;				   // size=0, offset=4 //  hashcode: 0x8377CDE0 (dec: -2089300512), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeForHitAgony;		   // size=0, offset=6 //  hashcode: 0x41DB7361 (dec: 1104900961), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short segmentForBodyTwist;	 // size=0, offset=8 //  hashcode: 0x264EB3FF (dec: 642692095), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeToThornPrep;		   // size=0, offset=10 //  hashcode: 0xF48F4E72 (dec: -191934862), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeToThornPoke;		   // size=0, offset=12 //  hashcode: 0x7D28407E (dec: 2099789950), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeToEggThrob;		   // size=0, offset=14 //  hashcode: 0xC58E2F7C (dec: -980537476), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timeToEggExplode;		   // size=0, offset=16 //  hashcode: 0xACC23E7F (dec: -1396556161), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short razielStunTime;		   // size=0, offset=18 //  hashcode: 0x76664F1A (dec: 1986416410), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short eggIgniteDist;		   // size=0, offset=20 //  hashcode: 0x78D81C03 (dec: 2027428867), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short angleForShortAttack;	 // size=0, offset=22 //  hashcode: 0x7B2C3115 (dec: 2066493717), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short closeAttackStart;		   // size=0, offset=24 //  hashcode: 0x5E1CBDFE (dec: 1578941950), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
	short junk;					   // size=0, offset=26 //  hashcode: 0x76D82621 (dec: 1993877025), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1) // size=0, offset=28 //  hashcode: 0xCC304422 (dec: -869252062), parent name: '_walbossAttributes', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct PoolManagementData // hashcode: 0xA005D5E0 (dec: -1610230304)
{
	char state;									   // size=0, offset=0 //  hashcode: 0x3658C5A3 (dec: 911787427), parent name: 'PoolManagementData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char numNodesInPool;				   // size=0, offset=1 //  hashcode: 0x54F91C79 (dec: 1425611897), parent name: 'PoolManagementData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position playerPosAtLastPlanMkrUpdate; // size=6, offset=2 //  hashcode: 0x617F71D7 (dec: 1635742167), parent name: 'PoolManagementData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PlanningNode *expansionNode1;		   // size=28, offset=8 //  hashcode: 0xCADB7802 (dec: -891586558), parent name: 'PoolManagementData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct PlanningNode *expansionNode2;		   // size=28, offset=12 //  hashcode: 0x50313C4B (dec: 1345403979), parent name: 'PoolManagementData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short (*distanceMatrix)[32];		   // size=4, offset=16 //  hashcode: 0x7E6AABEC (dec: 2120920044), parent name: 'PoolManagementData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short pairType;					   // size=0, offset=20 //  hashcode: 0xC2F189C1 (dec: -1024357951), parent name: 'PoolManagementData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position peakPos;					   // size=6, offset=22 //  hashcode: 0x3C40485C (dec: 1010845788), parent name: 'PoolManagementData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char currentNode;					   // size=0, offset=28 //  hashcode: 0xE1A0E5F3 (dec: -509549069), parent name: 'PoolManagementData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char currentBit;					   // size=0, offset=29 //  hashcode: 0xE53310C3 (dec: -449638205), parent name: 'PoolManagementData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EnemyPlanData // hashcode: 0xE792BD02 (dec: -409813758)
{
	unsigned char nodeSkipArray[8];	// size=8, offset=0 //  hashcode: 0x9085EAF0 (dec: -1870271760), parent name: 'EnemyPlanData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char nodeTypeArray[8];	// size=8, offset=8 //  hashcode: 0xAC92416B (dec: -1399701141), parent name: 'EnemyPlanData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position wayPointArray[8]; // size=48, offset=16 //  hashcode: 0x4245AF3A (dec: 1111863098), parent name: 'EnemyPlanData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short goalUnitID;				   // size=0, offset=64 //  hashcode: 0xD91AF375 (dec: -652545163), parent name: 'EnemyPlanData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char numWayPoints;		   // size=0, offset=66 //  hashcode: 0xBFCC8414 (dec: -1077115884), parent name: 'EnemyPlanData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _PlanCollideInfo // hashcode: 0x3B1266CC (dec: 991061708)
{
	long StreamUnitID;			 // size=0, offset=0 //  hashcode: 0x6192A9AC (dec: 1637001644), parent name: '_PlanCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tFace;		 // size=12, offset=4 //  hashcode: 0x8CA3BB83 (dec: -1935426685), parent name: '_PlanCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position collidePos; // size=6, offset=8 //  hashcode: 0xAFBB9A20 (dec: -1346659808), parent name: '_PlanCollideInfo', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct _fth // hashcode: 0xDEECEA3E (dec: -554898882)
{
	char x;		   // size=0, offset=0 //  hashcode: 0x42043A54 (dec: 1107573332), parent name: '_fth', parent hashcode: 0xFFFFFFFF (dec: -1)
	char y;		   // size=0, offset=1 //  hashcode: 0x89BD1CDF (dec: -1984095009), parent name: '_fth', parent hashcode: 0xFFFFFFFF (dec: -1)
	char z;		   // size=0, offset=2 //  hashcode: 0xDC998DDE (dec: -593916450), parent name: '_fth', parent hashcode: 0xFFFFFFFF (dec: -1)
	char nodeType; // size=0, offset=3 //  hashcode: 0xAF8D4294 (dec: -1349696876), parent name: '_fth', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct EnemyPlanSlotData // hashcode: 0xA348D4B1 (dec: -1555508047)
{
	char slotInUse;					// size=0, offset=0 //  hashcode: 0x8AA36C35 (dec: -1969001419), parent name: 'EnemyPlanSlotData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char state;						// size=0, offset=1 //  hashcode: 0xF49DE88A (dec: -190977910), parent name: 'EnemyPlanSlotData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char wayPointBeingServoedTo;	// size=0, offset=2 //  hashcode: 0xED2C4C64 (dec: -315863964), parent name: 'EnemyPlanSlotData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position startPos;		// size=6, offset=4 //  hashcode: 0x66719914 (dec: 1718720788), parent name: 'EnemyPlanSlotData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position goalPos;		// size=6, offset=10 //  hashcode: 0x063875D1 (dec: 104363473), parent name: 'EnemyPlanSlotData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position oldCurrentPos; // size=6, offset=16 //  hashcode: 0xE412310B (dec: -468569845), parent name: 'EnemyPlanSlotData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct EnemyPlanData planData;  // size=68, offset=22 //  hashcode: 0x73EFAC09 (dec: 1945086985), parent name: 'EnemyPlanSlotData', parent hashcode: 0xFFFFFFFF (dec: -1)
	char targetType;				// size=0, offset=90 //  hashcode: 0x86C9C87C (dec: -2033596292), parent name: 'EnemyPlanSlotData', parent hashcode: 0xFFFFFFFF (dec: -1)
	short timer;					// size=0, offset=92 //  hashcode: 0x8EDC2DFB (dec: -1898172933), parent name: 'EnemyPlanSlotData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __Force // hashcode: 0x2CC8F311 (dec: 751366929)
{
	int Type;					// size=0, offset=0 //  hashcode: 0x70C84DDE (dec: 1892175326), parent name: '__Force', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Vector LinearForce; // size=12, offset=4 //  hashcode: 0x3FC324EB (dec: 1069753579), parent name: '__Force', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Friction;				// size=0, offset=16 //  hashcode: 0x71E1EF58 (dec: 1910632280), parent name: '__Force', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __Idle // hashcode: 0xA4E3256E (dec: -1528617618)
{
	unsigned char anim;   // size=0, offset=0 //  hashcode: 0xD2137F84 (dec: -770474108), parent name: '__Idle', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char frame;  // size=0, offset=1 //  hashcode: 0x799C3668 (dec: 2040280680), parent name: '__Idle', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char frames; // size=0, offset=2 //  hashcode: 0x1EE54249 (dec: 518341193), parent name: '__Idle', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char type;   // size=0, offset=3 //  hashcode: 0x30265BB4 (dec: 807820212), parent name: '__Idle', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __VAnim // hashcode: 0xDC662191 (dec: -597286511)
{
	unsigned char anim0;  // size=0, offset=0 //  hashcode: 0x262CCF73 (dec: 640470899), parent name: '__VAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char anim1;  // size=0, offset=1 //  hashcode: 0x8418CDAC (dec: -2078749268), parent name: '__VAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char anim2;  // size=0, offset=2 //  hashcode: 0xE395D30D (dec: -476720371), parent name: '__VAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char frames; // size=0, offset=3 //  hashcode: 0xA5B27153 (dec: -1515032237), parent name: '__VAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char mode;   // size=0, offset=4 //  hashcode: 0xFA2911F0 (dec: -97971728), parent name: '__VAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char alpha;  // size=0, offset=5 //  hashcode: 0xD445B1D8 (dec: -733629992), parent name: '__VAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short frame; // size=0, offset=6 //  hashcode: 0x080422D7 (dec: 134488791), parent name: '__VAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __SAnim // hashcode: 0xD19E5798 (dec: -778152040)
{
	struct __VAnim *anim;	 // size=8, offset=0 //  hashcode: 0x113E71BA (dec: 289305018), parent name: '__SAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __SAnim *nextAnim; // size=16, offset=4 //  hashcode: 0x5F47203E (dec: 1598496830), parent name: '__SAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	short mode;				  // size=0, offset=8 //  hashcode: 0xB2112A3A (dec: -1307497926), parent name: '__SAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	short data;				  // size=0, offset=10 //  hashcode: 0xC8D67D04 (dec: -925467388), parent name: '__SAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	short speedAdjust;		  // size=0, offset=12 //  hashcode: 0x9080609F (dec: -1870634849), parent name: '__SAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
	short pad;				  // size=0, offset=14 //  hashcode: 0xC6D91123 (dec: -958852829), parent name: '__SAnim', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __AttackItem // hashcode: 0x6E34BA91 (dec: 1848949393)
{
	unsigned char anim;				   // size=0, offset=0 //  hashcode: 0x6768D52B (dec: 1734923563), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char framesIn;			   // size=0, offset=1 //  hashcode: 0xC1B1EE0C (dec: -1045303796), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char alphaIn;			   // size=0, offset=2 //  hashcode: 0x3FD40076 (dec: 1070858358), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char framesOut;		   // size=0, offset=3 //  hashcode: 0x62D62C80 (dec: 1658203264), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char switchDelay;		   // size=0, offset=4 //  hashcode: 0x2BE5AB37 (dec: 736471863), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char ignoreDelay;		   // size=0, offset=5 //  hashcode: 0x236077C9 (dec: 593524681), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char segmentToGlow;	   // size=0, offset=6 //  hashcode: 0x4B566E11 (dec: 1263955473), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char startCollisionFrame; // size=0, offset=7 //  hashcode: 0x1F01BA83 (dec: 520206979), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char handsToCollide;	  // size=0, offset=8 //  hashcode: 0xB323E832 (dec: -1289492430), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char endCollisionFrame;   // size=0, offset=9 //  hashcode: 0x0470BC7E (dec: 74497150), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char ribbonStartFrame;	// size=0, offset=10 //  hashcode: 0x6E8EC54B (dec: 1854850379), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char ribbonStartSegment;  // size=0, offset=11 //  hashcode: 0xE530D0E7 (dec: -449785625), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char ribbonEndSegment;	// size=0, offset=12 //  hashcode: 0x0E8F2D1D (dec: 244264221), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char ribbonLifeTime;	  // size=0, offset=13 //  hashcode: 0x1FD478D9 (dec: 534018265), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char ribbonFaceLifeTime;  // size=0, offset=14 //  hashcode: 0x70FF4D3B (dec: 1895779643), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char knockBackFrames;	 // size=0, offset=15 //  hashcode: 0x9FD021FA (dec: -1613749766), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char glowFadeInFrames;	// size=0, offset=16 //  hashcode: 0x49B0AE13 (dec: 1236315667), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char glowFadeOutFrames;   // size=0, offset=17 //  hashcode: 0x706C7C86 (dec: 1886157958), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short ribbonStartOpacity; // size=0, offset=18 //  hashcode: 0x8D640D50 (dec: -1922822832), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long ribbonStartColor;	// size=0, offset=20 //  hashcode: 0x8B36576F (dec: -1959372945), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long ribbonEndColor;	  // size=0, offset=24 //  hashcode: 0xEE5DC004 (dec: -295845884), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long glowColor;		   // size=0, offset=28 //  hashcode: 0x535BB8A4 (dec: 1398519972), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short knockBackDistance;  // size=0, offset=32 //  hashcode: 0xBD658B10 (dec: -1117418736), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short hitPowerScale;	  // size=0, offset=34 //  hashcode: 0xBFE54987 (dec: -1075492473), parent name: '__AttackItem', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __ThrowItem // hashcode: 0xABF5F7A3 (dec: -1409943645)
{
	unsigned char prepAnim;				   // size=0, offset=0 //  hashcode: 0xBE13C27E (dec: -1106001282), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char prepAnimFramesIn;		   // size=0, offset=1 //  hashcode: 0xA672A5BA (dec: -1502435910), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char prepAnimAlphaIn;		   // size=0, offset=2 //  hashcode: 0x4C22D5A2 (dec: 1277351330), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char coilAnim;				   // size=0, offset=3 //  hashcode: 0x8E112CE0 (dec: -1911477024), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char coilAnimFramesIn;		   // size=0, offset=4 //  hashcode: 0xB2751737 (dec: -1300949193), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char coilAnimAlphaIn;		   // size=0, offset=5 //  hashcode: 0xA8F88A3E (dec: -1460106690), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char throwAnim;			   // size=0, offset=6 //  hashcode: 0x015F43F7 (dec: 23020535), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char throwAnimFramesInFactor; // size=0, offset=7 //  hashcode: 0x41FEF410 (dec: 1107227664), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char throwFrameToLaunch;	  // size=0, offset=8 //  hashcode: 0x10E04183 (dec: 283132291), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char framesOut;			   // size=0, offset=9 //  hashcode: 0x77579E20 (dec: 2002230816), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short launchPointX;					   // size=0, offset=10 //  hashcode: 0xCD6A84BE (dec: -848657218), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short launchPointY;					   // size=0, offset=12 //  hashcode: 0x4B997CE0 (dec: 1268350176), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short launchPointZ;					   // size=0, offset=14 //  hashcode: 0xA0C3BAFC (dec: -1597785348), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxXRotation;					   // size=0, offset=16 //  hashcode: 0xA7991854 (dec: -1483138988), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minXRotation;					   // size=0, offset=18 //  hashcode: 0xDFEDDE75 (dec: -538059147), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short maxZRotation;					   // size=0, offset=20 //  hashcode: 0x8436C7EA (dec: -2076784662), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short minZRotation;					   // size=0, offset=22 //  hashcode: 0x157E9C51 (dec: 360619089), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short velocity;						   // size=0, offset=24 //  hashcode: 0xC3708BBE (dec: -1016034370), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short gravity;						   // size=0, offset=26 //  hashcode: 0x381F02F8 (dec: 941556472), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short coilRot;						   // size=0, offset=28 //  hashcode: 0xBF528072 (dec: -1085112206), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
	short selfAdjustingFlag;			   // size=0, offset=30 //  hashcode: 0x4307A220 (dec: 1124573728), parent name: '__ThrowItem', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __EngagedInstance // hashcode: 0x504DFFAD (dec: 1347289005)
{
	struct _Instance *instance; // size=616, offset=0 //  hashcode: 0x4F3203E5 (dec: 1328677861), parent name: '__EngagedInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long distance;		// size=0, offset=4 //  hashcode: 0x3BF42CCF (dec: 1005857999), parent name: '__EngagedInstance', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __FitPoint // hashcode: 0xFA3F31C2 (dec: -96521790)
{
	short x; // size=0, offset=0 //  hashcode: 0x0E62A52F (dec: 241345839), parent name: '__FitPoint', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y; // size=0, offset=2 //  hashcode: 0x9A12F7AB (dec: -1710032981), parent name: '__FitPoint', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __SensoryData // hashcode: 0x3A2E27FD (dec: 976103421)
{
	int Flags;							   // size=0, offset=0 //  hashcode: 0x32BB083D (dec: 851118141), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector ForwardNormal;		   // size=8, offset=4 //  hashcode: 0xD6EC8D33 (dec: -689140429), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector AboveNormal;		   // size=8, offset=12 //  hashcode: 0xC4BDD5D4 (dec: -994191916), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector BelowNormal;		   // size=8, offset=20 //  hashcode: 0x9DE81916 (dec: -1645733610), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector BelowPoint;			   // size=8, offset=28 //  hashcode: 0xF451E8C5 (dec: -195958587), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector Delta;				   // size=8, offset=36 //  hashcode: 0x56DAC50C (dec: 1457177868), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *HitMonster;		   // size=616, offset=44 //  hashcode: 0x088BC1B5 (dec: 143376821), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *CurrentAutoFace;	 // size=616, offset=48 //  hashcode: 0xDB3D5BD1 (dec: -616735791), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *LastAutoFace;		   // size=616, offset=52 //  hashcode: 0x30FEF2DE (dec: 822014686), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *Portal;			   // size=616, offset=56 //  hashcode: 0x227CE75F (dec: 578611039), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __EngagedInstance *EngagedList; // size=8, offset=60 //  hashcode: 0x9A766834 (dec: -1703516108), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long EngagedMask;			   // size=0, offset=64 //  hashcode: 0x14F31D2E (dec: 351477038), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Vector lookAtPoint;			   // size=12, offset=68 //  hashcode: 0xF1A89AC6 (dec: -240608570), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long heldClass;			   // size=0, offset=80 //  hashcode: 0x7A66A389 (dec: 2053546889), parent name: '__SensoryData', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct __Player // hashcode: 0x0712E7A5 (dec: 118679461)
{
	int footPrint;						 // size=0, offset=0 //  hashcode: 0x2D1D761F (dec: 756905503), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __CharacterState State;		 // size=860, offset=4 //  hashcode: 0x1F6F6473 (dec: 527393907), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int Mode;							 // size=0, offset=864 //  hashcode: 0xC900E96B (dec: -922687125), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int Anim;							 // size=0, offset=868 //  hashcode: 0xA60808D8 (dec: -1509422888), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int RotationSegment;				 // size=0, offset=872 //  hashcode: 0x9D1BA26F (dec: -1659133329), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector iVelocity;			 // size=8, offset=876 //  hashcode: 0x2221B914 (dec: 572635412), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int Magnitude;						 // size=0, offset=884 //  hashcode: 0x2DEA1796 (dec: 770316182), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int input;							 // size=0, offset=888 //  hashcode: 0x797F3FCC (dec: 2038382540), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int lastInput;						 // size=0, offset=892 //  hashcode: 0xDF329EA1 (dec: -550330719), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int ZDirection;						 // size=0, offset=896 //  hashcode: 0xBC8F5B30 (dec: -1131455696), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short Bearing;						 // size=0, offset=900 //  hashcode: 0xC488C97E (dec: -997668482), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short LastBearing;					 // size=0, offset=902 //  hashcode: 0xA238A9F5 (dec: -1573344779), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int steeringMode;					 // size=0, offset=904 //  hashcode: 0x7E126845 (dec: 2115135557), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short steeringVelocity;				 // size=0, offset=908 //  hashcode: 0xECE46814 (dec: -320575468), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short steeringAcceleration;			 // size=0, offset=910 //  hashcode: 0x94D6D6A5 (dec: -1797859675), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int steeringLockRotation;			 // size=0, offset=912 //  hashcode: 0xCE5A0423 (dec: -832961501), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short movementMinRate;				 // size=0, offset=916 //  hashcode: 0x73BB6D13 (dec: 1941662995), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short movementMaxRate;				 // size=0, offset=918 //  hashcode: 0xB6992ACC (dec: -1231476020), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short movementMinAnalog;			 // size=0, offset=920 //  hashcode: 0x275837D9 (dec: 660092889), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short movementMaxAnalog;			 // size=0, offset=922 //  hashcode: 0x216FB9F7 (dec: 560970231), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __SensoryData Senses;		 // size=84, offset=924 //  hashcode: 0x30C01728 (dec: 817895208), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *attachedPlatform;  // size=616, offset=1008 //  hashcode: 0x35C751F2 (dec: 902255090), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dropOffHeight;				 // size=0, offset=1012 //  hashcode: 0xA98F3A09 (dec: -1450231287), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short fallZVelocity;				 // size=0, offset=1014 //  hashcode: 0x3502EA36 (dec: 889383478), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short HealthScale;					 // size=0, offset=1016 //  hashcode: 0xC308B148 (dec: -1022840504), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short HealthBalls;					 // size=0, offset=1018 //  hashcode: 0x598F9714 (dec: 1502582548), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int HitPoints;						 // size=0, offset=1020 //  hashcode: 0x6E9298D3 (dec: 1855101139), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int DamageFrequency;				 // size=0, offset=1024 //  hashcode: 0xA51209D9 (dec: -1525544487), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int invincibleTimer;				 // size=0, offset=1028 //  hashcode: 0x6EE8824E (dec: 1860731470), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int Abilities;						 // size=0, offset=1032 //  hashcode: 0xF400554E (dec: -201304754), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *GlyphSystem;		 // size=616, offset=1036 //  hashcode: 0x30DEA6D0 (dec: 819898064), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short GlyphManaBalls;		 // size=0, offset=1040 //  hashcode: 0x8BD2B739 (dec: -1949124807), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned short GlyphManaMax;		 // size=0, offset=1042 //  hashcode: 0x35903A23 (dec: 898644515), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __FitPoint *constrictData;	// size=4, offset=1044 //  hashcode: 0x43CAF4F6 (dec: 1137374454), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short constrictIndex;				 // size=0, offset=1048 //  hashcode: 0xB5FABF6D (dec: -1241858195), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short constrictWaitIndex;			 // size=0, offset=1050 //  hashcode: 0x15A72622 (dec: 363275810), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector constrictCenter;	 // size=8, offset=1052 //  hashcode: 0xC768BA27 (dec: -949437913), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short constrictFlag;				 // size=0, offset=1060 //  hashcode: 0x8AF25BF1 (dec: -1963828239), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short constrictGoodCircle;			 // size=0, offset=1062 //  hashcode: 0x787DAE0C (dec: 2021502476), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long constrictXTotal;		 // size=0, offset=1064 //  hashcode: 0x7B7EE37F (dec: 2071913343), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long constrictYTotal;		 // size=0, offset=1068 //  hashcode: 0x87B8102C (dec: -2017980372), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *soulReaver;		 // size=616, offset=1072 //  hashcode: 0x67B08A5C (dec: 1739623004), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long currentSoulReaver;	 // size=0, offset=1076 //  hashcode: 0x72FC1275 (dec: 1929122421), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int CurrentPlane;					 // size=0, offset=1080 //  hashcode: 0xA8666835 (dec: -1469683659), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int slipSlope;						 // size=0, offset=1084 //  hashcode: 0xC5D240EF (dec: -976076561), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long idleCount;			 // size=0, offset=1088 //  hashcode: 0x51DA042F (dec: 1373242415), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *idleInstance;		 // size=616, offset=1092 //  hashcode: 0x0CF91658 (dec: 217650776), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __AttackItem *attack;		 // size=36, offset=1096 //  hashcode: 0xCAF36990 (dec: -890017392), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int attackFlags;					 // size=0, offset=1100 //  hashcode: 0x5DB3536B (dec: 1572033387), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int currentAttack;					 // size=0, offset=1104 //  hashcode: 0xB685E2CE (dec: -1232739634), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *attackCurrentHit;  // size=616, offset=1108 //  hashcode: 0x2D1E0854 (dec: 756942932), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *attackLastHit;	 // size=616, offset=1112 //  hashcode: 0x5CF7680B (dec: 1559717899), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _FXGlowEffect *glowEffect;	// size=44, offset=1116 //  hashcode: 0x1F347697 (dec: 523531927), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *attackedBy;		 // size=616, offset=1120 //  hashcode: 0xC062A5F1 (dec: -1067276815), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __ThrowItem *throwData;		 // size=32, offset=1124 //  hashcode: 0x9AA9787D (dec: -1700169603), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int throwMode;						 // size=0, offset=1128 //  hashcode: 0xE2742BB2 (dec: -495703118), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position throwTarget;		 // size=6, offset=1132 //  hashcode: 0x845893D8 (dec: -2074569768), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Instance *throwInstance;	 // size=616, offset=1140 //  hashcode: 0xE3C6B733 (dec: -473516237), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short throwXRot;					 // size=0, offset=1144 //  hashcode: 0x782B03E3 (dec: 2016084963), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short throwZRot;					 // size=0, offset=1146 //  hashcode: 0x8B0F3A73 (dec: -1961936269), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int throwReturnRot;					 // size=0, offset=1148 //  hashcode: 0x87F5ABBF (dec: -2013942849), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __MessageQueue padCommands;   // size=136, offset=1152 //  hashcode: 0x9EF4F4C2 (dec: -1628113726), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*returnState)();				 // size=0, offset=1288 //  hashcode: 0x1557F996 (dec: 358087062), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long passedMask;			 // size=0, offset=1292 //  hashcode: 0xC91EF5B0 (dec: -920717904), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type extraRot;	// size=6, offset=1296 //  hashcode: 0xA919EB9F (dec: -1457919073), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	long blankPad;						 // size=0, offset=1304 //  hashcode: 0xC8E2C15F (dec: -924663457), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int effectsFlags;					 // size=0, offset=1308 //  hashcode: 0x838678D0 (dec: -2088339248), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short effectsFadeSource;			 // size=0, offset=1312 //  hashcode: 0x8440EF21 (dec: -2076119263), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short effectsFadeDest;				 // size=0, offset=1314 //  hashcode: 0xC9DD08F1 (dec: -908261135), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int effectsFadeStep;				 // size=0, offset=1316 //  hashcode: 0x51053C65 (dec: 1359297637), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int effectsFadeSteps;				 // size=0, offset=1320 //  hashcode: 0xD7B74887 (dec: -675854201), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short autoFaceZone;					 // size=0, offset=1324 //  hashcode: 0x52D21507 (dec: 1389499655), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short autoFaceAngle;				 // size=0, offset=1326 //  hashcode: 0xDC0B489E (dec: -603240290), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int autoFaceLastRootAngle;			 // size=0, offset=1328 //  hashcode: 0x1AE52EB9 (dec: 451227321), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int autoFaceRootAngle;				 // size=0, offset=1332 //  hashcode: 0xEB1B7294 (dec: -350522732), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int autoFaceTrueAngle;				 // size=0, offset=1336 //  hashcode: 0x9779B67E (dec: -1753631106), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int autoFaceAnim;					 // size=0, offset=1340 //  hashcode: 0xA62DBB24 (dec: -1506952412), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int autoFaceLastAnim;				 // size=0, offset=1344 //  hashcode: 0x4F0F22D3 (dec: 1326392019), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nothingCounter;					 // size=0, offset=1348 //  hashcode: 0x60D0BDC3 (dec: 1624292803), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int timeAccumulator;				 // size=0, offset=1352 //  hashcode: 0x18EBFFF5 (dec: 418119669), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position puppetMoveToPoint;  // size=6, offset=1356 //  hashcode: 0xC7F832C1 (dec: -940035391), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Position puppetRotToPoint;   // size=6, offset=1362 //  hashcode: 0x07B2BAAD (dec: 129153709), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int puppetHint;						 // size=0, offset=1368 //  hashcode: 0x31BB2E54 (dec: 834350676), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int soundModifier;					 // size=0, offset=1372 //  hashcode: 0x25AE720A (dec: 632189450), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short alarmTable;					 // size=0, offset=1376 //  hashcode: 0x57829D4B (dec: 1468177739), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short terminator;					 // size=0, offset=1378 //  hashcode: 0xEEA1A58F (dec: -291396209), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short swimSpeedAdjustment;			 // size=0, offset=1380 //  hashcode: 0x25D42462 (dec: 634659938), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short swimTargetSpeed;				 // size=0, offset=1382 //  hashcode: 0x5769F143 (dec: 1466560835), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long soundHandle;			 // size=0, offset=1384 //  hashcode: 0x23DA0D32 (dec: 601492786), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	long soundTimer;					 // size=0, offset=1388 //  hashcode: 0xAB7F34B1 (dec: -1417726799), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	long soundTotalTime;				 // size=0, offset=1392 //  hashcode: 0xB8928B7D (dec: -1198355587), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long soundDistance;		 // size=0, offset=1396 //  hashcode: 0x46D67C57 (dec: 1188461655), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundStartPitch;				 // size=0, offset=1400 //  hashcode: 0x3DC68551 (dec: 1036420433), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundEndPitch;				 // size=0, offset=1402 //  hashcode: 0x13683BF7 (dec: 325598199), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundStartVolume;				 // size=0, offset=1404 //  hashcode: 0x8C774C1A (dec: -1938338790), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundEndVolume;				 // size=0, offset=1406 //  hashcode: 0xCA372314 (dec: -902356204), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long soundHandle2;			 // size=0, offset=1408 //  hashcode: 0x7BA1A411 (dec: 2074190865), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	long soundTimer2;					 // size=0, offset=1412 //  hashcode: 0x92A8D3AA (dec: -1834429526), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	long soundTotalTime2;				 // size=0, offset=1416 //  hashcode: 0x02286FF2 (dec: 36204530), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long soundDistance2;		 // size=0, offset=1420 //  hashcode: 0xC7FFDB85 (dec: -939533435), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundStartPitch2;				 // size=0, offset=1424 //  hashcode: 0xE6804946 (dec: -427800250), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundEndPitch2;				 // size=0, offset=1426 //  hashcode: 0xAEF89055 (dec: -1359441835), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundStartVolume2;			 // size=0, offset=1428 //  hashcode: 0x41229AA4 (dec: 1092786852), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	short soundEndVolume2;				 // size=0, offset=1430 //  hashcode: 0x7AF81508 (dec: 2063078664), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	long soundTimerNext;				 // size=0, offset=1432 //  hashcode: 0xA09EEC06 (dec: -1600197626), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long soundTimerData;		 // size=0, offset=1436 //  hashcode: 0x723DAC05 (dec: 1916644357), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long forcedGlideSpeed;		 // size=0, offset=1440 //  hashcode: 0x7E2767EE (dec: 2116511726), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector collisionEdgeOffset; // size=8, offset=1444 //  hashcode: 0x799B382E (dec: 2040215598), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct __SAnim *currentSAnim;		 // size=16, offset=1452 //  hashcode: 0x42E31AF8 (dec: 1122179832), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long playerEvent;			 // size=0, offset=1456 //  hashcode: 0x4C9EEDE4 (dec: 1285484004), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned long playerEventHistory;	// size=0, offset=1460 //  hashcode: 0x021A7BAC (dec: 35290028), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
	int currentHint;					 // size=0, offset=1464 //  hashcode: 0x76E0ED44 (dec: 1994452292), parent name: '__Player', parent hashcode: 0xFFFFFFFF (dec: -1)
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

typedef struct SpuVoiceAttr SpuVoiceAttr;

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

typedef struct MusicLoadCmd MusicLoadCmd;

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

typedef struct GameCheat GameCheat;

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

typedef unsigned char CheatKey;

typedef void debug_dispatch_fn_t();

typedef struct _FXTracker FXTracker;

typedef struct SignalInfo SignalInfo;

typedef void BSPLeafFunc();

typedef void SignalGlobalValueFunc();

typedef long HandleSignalFunc();

typedef long SignalHandleFunc();

typedef void RelocateSignalFunc();

typedef struct _Vector Vector;

typedef struct _Triangle2D Triangle2D;

typedef struct _PCollideInfo PCollideInfo;

typedef struct _HNormal HNormal;

typedef struct _HFaceInfo HFaceInfo;

typedef struct _CollideInfo CollideInfo;

typedef struct _LCollideInfo LCollideInfo;

typedef struct SCollideInfo SCollideInfo;

typedef long CollideBoundFunc();

typedef struct CameraCollisionInfo CameraCollisionInfo;

typedef struct POLY_GT3 POLY_GT3;

typedef struct POLY_GT4 POLY_GT4;

typedef struct _PFace PFace;

typedef struct _PolytopeList PolytopeList;

typedef struct UVTYPE UVTYPE;

typedef struct POLY_G3_SEMITRANS POLY_G3_SEMITRANS;

typedef struct _POLY_NG4 POLY_NG4;

typedef struct _GT3ZVertexD3D_Type GT3ZVertexD3D;

typedef struct SP_SUBDIV_STRUCT SP_SUBDIV_STRUCT;

typedef void G2AppData;

typedef long LightFunc();

typedef struct CdlFILE CdlFILE;

typedef struct _LoadStatus LoadStatus;

typedef struct RedirectList RedirectList;

typedef struct DRAWENV DRAWENV;

typedef struct DISPENV DISPENV;

typedef struct BLK_FILL BLK_FILL;

typedef struct MainTracker MainTracker;

typedef struct AnalogueData AnalogueData;

typedef struct POLY_F4_SEMITRANS POLY_F4_SEMITRANS;

typedef struct PhysObProperties PhysObProperties;

typedef struct PhysObSplinter PhysObSplinter;

typedef struct PhysObWeaponAttributes PhysObWeaponAttributes;

typedef struct __PhysObProjectileData PhysObProjData;

typedef struct SwitchData SwitchData;

typedef struct LightTableEntry LightTableEntry;

typedef struct _PhysObLight PhysObLight;

typedef struct InterfaceItem InterfaceItem;

typedef struct POLY_FT4 POLY_FT4;

typedef struct FontTracker FontTracker;

typedef struct font_color_t font_color_t;

typedef struct FontPos FontPos;

typedef struct StreamUnitPortal StreamUnitPortal;

typedef void GlyphProcessFunction();

typedef struct JoypadMappingStruct JoypadMapping;

typedef struct ControllerPacket ControllerPacket;

typedef struct _G2EulerAngles_Type G2EulerAngles;

typedef enum _G2AnimCallbackMsg_Enum G2AnimCallbackMsg;

typedef struct _AnimSoundData_Type AnimSoundData;

typedef struct _InstanceHandle InstanceHandle;

typedef struct evCollideInstanceStatsData evCollideInstanceStatsData;

typedef struct INICommand INICommand;

typedef struct SavedIntroSmall SavedIntroSmall;

typedef struct SavedIntroSpline SavedIntroSpline;

typedef struct _SavedIntroWithIntro SavedIntroWithIntro;

typedef struct _MonsterIdle MonsterIdle;

typedef struct _MonsterBehavior MonsterBehavior;

typedef struct _MonsterSenses MonsterSenses;

typedef struct _MonsterAllegiances MonsterAllegiances;

typedef struct _MonsterAttackAttributes MonsterAttackAttributes;

typedef struct _MonsterMissile MonsterMissile;

typedef struct _MonsterCombatAttributes MonsterCombatAttributes;

typedef struct _MonsterSubAttributes MonsterSubAttributes;

typedef void (*processVert_t)();

typedef struct AadInitAttr AadInitAttr;

typedef struct MusicLoadInfo MusicLoadInfo;

typedef struct ObjectPeriodicSound ObjectPeriodicSound;

typedef struct ObjectEventSound ObjectEventSound;

typedef struct ObjectOneShotSound ObjectOneShotSound;

typedef struct SoundEffectChannel SoundEffectChannel;

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

typedef struct GenericTune GenericTune;

typedef struct POLY_FT3 POLY_FT3;

typedef struct _Mirror Mirror;

typedef struct _FXHalvePlane FXHalvePlane;

typedef struct _FXGlowEffect FXGlowEffect;

typedef struct TransformAnimatedInstanceVerticesWork_t TransformAnimatedInstanceVerticesWork_t;

typedef struct FXSplinter FXSplinter;

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

typedef struct NewMemTracker NewMemTracker;

typedef struct AadVolume AadVolume;

typedef struct AadSequenceHdr AadSequenceHdr;

typedef struct AadTempo AadTempo;

typedef struct AadMemoryStruct AadMemoryStruct;

typedef struct AadSlotAttributes AadSlotAttributes;

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

typedef struct __CharacterState CharacterState;

typedef struct evMonsterHitData evMonsterHitData;

typedef struct evMonsterThrownData evMonsterThrownData;

typedef struct evMonsterAlarmData evMonsterAlarmData;

typedef struct evMonsterSoulSuckData evMonsterSoulSuckData;

typedef struct evPhysicsDropOffData evPhysicsDropOffData;

typedef struct evPhysicsEdgeData evPhysicsEdgeData;

typedef struct evPhysicsWallCrawlData evPhysicsWallCrawlData;

typedef struct evPhysicsSwimData evPhysicsSwimData;

typedef struct evPhysicsDropHeightData evPhysicsDropHeightData;

typedef struct evPhysicsLinkedMoveData evPhysicsLinkedMoveData;

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

typedef struct evShadowSegmentData evShadowSegmentData;

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

typedef struct _MonsterAttributes MonsterAttributes;

typedef struct _MonsterVars MonsterVars;

typedef struct _MonsterIR MonsterIR;

typedef struct burntTuneType burntTuneType;

typedef struct _MonsterStateChoice MonsterStateChoice;

typedef void (*MonsterFunc)();

typedef void (*MonsterDamageFunc)();

typedef struct __GlyphData GlyphData;

typedef struct _MonsterFunctionTable MonsterFunctionTable;

typedef struct MissileGraphics MissileGraphics;

typedef struct evMonsterHitTerrainData evMonsterHitTerrainData;

typedef struct evMonsterHitObjectData evMonsterHitObjectData;

typedef struct _MonsterSaveInfo MonsterSaveInfo;

typedef struct evPhysicsLOSData evPhysicsLOSData;

typedef struct RadarInfo RadarInfo;

typedef struct burntMessType burntMessType;

typedef struct bloodyMessType bloodyMessType;

typedef struct _G2AnimController_Type G2AnimController;

typedef struct _G2AnimSegKeyflagInfo_Type G2AnimSegKeyflagInfo;

typedef struct _G2AnimDecompressChannelInfo_Type G2AnimDecompressChannelInfo;

typedef struct _G2AnimSegValue_Type G2AnimSegValue;

typedef struct _G2AnimChanStatusBlockPool_Type G2AnimChanStatusBlockPool;

typedef struct _G2AnimControllerPool_Type G2AnimControllerPool;

typedef struct _G2AnimInterpStateBlockPool_Type G2AnimInterpStateBlockPool;

typedef void G2PoolMem;

typedef void (*G2AnimApplyControllerFn)();

typedef struct _walbossAttributes WalbossAttributes;

typedef struct PoolManagementData PoolManagementData;

typedef struct EnemyPlanData EnemyPlanData;

typedef struct _PlanCollideInfo PlanCollideInfo;

typedef struct _fth FindTerrainHit;

typedef struct _G2AppDataVM_Type G2AppDataVM;

typedef struct EnemyPlanSlotData EnemyPlanSlotData;

typedef struct _G2PoolMemPool_Type G2PoolMemPool;

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

typedef struct SavedLevel SavedLevel;

typedef struct ActualSavedLevel ActualSavedLevel;

typedef struct SavedDeadDeadBits SavedDeadDeadBits;

typedef struct _GlobalSaveTracker GlobalSaveTracker;

typedef struct CdlFILTER CdlFILTER;

typedef struct SpuCommonAttr SpuCommonAttr;

typedef struct XAVoiceListEntry XAVoiceListEntry;

typedef struct XAVoiceTracker XAVoiceTracker;

typedef void (*VoiceCmdProc)();

typedef struct cinema_fn_table_t cinema_fn_table_t;

typedef int PlayCinematic_t();

typedef enum language_t language_t;

typedef enum localstr_t localstr_t;

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

typedef enum bdepth bdepth;

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

typedef struct DR_STP DR_STP;

typedef struct UW_ScreenXY UW_ScreenXY;

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

extern struct DebugMenuLine mainMenu[8]; // offset 0x800C8418

static struct debug_dispatch_t debug_dispatch_table[5]; // offset 0x800C84D8

extern struct DebugMenuLine *currentMenu; // offset 0x800CDB3C

static char pauseFormatString[20]; // offset 0x800CDAB8

static char mainFormatString[20]; // offset 0x800CDACC

static char *the_format_string; // offset 0x800CDAE0

extern long menuPauseSel; // offset 0x800CDAE4

extern long debug_cameraMode; // offset 0x800CDAE8

extern long debugVoiceIndex; // offset 0x800CDAEC

extern unsigned long debugTimeMult; // offset 0x800CDAF0

extern long debugFogFar; // offset 0x800CDAF4

extern long debugFogNear; // offset 0x800CDAF8

extern long debugGameTime; // offset 0x800CDAFC

extern long debugFogRed; // offset 0x800CDB00

extern long debugFogGrn; // offset 0x800CDB04

extern long debugFogBlu; // offset 0x800CDB08

extern long debugHealthLevel; // offset 0x800CDB0C

extern long debugManaLevel; // offset 0x800CDB10

static long debugMenuChoice; // offset 0x800CDB40

static long cheatCodeLastCommand; // offset 0x800CDB44

static long CheatKeyMap[10]; // offset 0x800CDB48

static struct GameCheat GameCheats[23]; // offset 0x800CDB70

extern struct DebugMenuLine *the_previous_menu; // offset 0x800CDCE0

static int cem_x_base; // offset 0x800CDCE4

static int cem_y_base; // offset 0x800CDCE8

static int cem_cursor_width; // offset 0x800CDCEC

static int cem_line_width; // offset 0x800CDCF0

static int cem_line_leading; // offset 0x800CDCF4

static int cem_item_leading; // offset 0x800CDCF8

extern short AXIS_LENGTH; // offset 0x800CDE5C

extern struct DebugMenuLine standardMenu[1]; // offset 0x800CFCB0

extern struct DebugMenuLine pauseMenu[1]; // offset 0x800CFCC8

extern unsigned long debugRazielFlags1; // offset 0x800CFD40

extern unsigned long debugRazielFlags2; // offset 0x800CFD44

extern unsigned long debugRazielFlags3; // offset 0x800CFD48

extern short debugOrgFogFar; // offset 0x800CFC94

extern short debugOrgFogNear; // offset 0x800CFC54

extern unsigned char debugOrgFogRed; // offset 0x800CFC88

extern unsigned char debugOrgFogGrn; // offset 0x800CFC8C

extern unsigned char debugOrgFogBlu; // offset 0x800CFC90

extern struct DebugMenuLine goodiesMenu[1]; // offset 0x800CFBDC

extern struct DebugMenuLine debugSoundMenu[1]; // offset 0x800CFBAC

extern struct DebugMenuLine debugImbueSoulReaverMenu[1]; // offset 0x800CFD28

extern struct DebugMenuLine debugGlyphAbilitiesMenu[1]; // offset 0x800CFBC4

extern struct DebugMenuLine debugForgedAbilitiesMenu[1]; // offset 0x800CFBF4

extern struct DebugMenuLine debugSpecialAbilitiesMenu[1]; // offset 0x800CFC0C

extern struct DebugMenuLine debugHealthSystemMenu[1]; // offset 0x800CFC3C

extern struct DebugMenuLine debugRazielMenu[1]; // offset 0x800CFD4C

extern struct DebugMenuLine level2SelectMenu[1]; // offset 0x800CFD10

extern struct DebugMenuLine levelSelectMenu[1]; // offset 0x800CFCF8

extern struct DebugMenuLine statsMenu[1]; // offset 0x800CFC98

extern struct DebugMenuLine eventMenu[1]; // offset 0x800CFB64

extern struct DebugMenuLine BossAreasMenu[1]; // offset 0x800CFB7C

extern struct DebugMenuLine saveMenu[1]; // offset 0x800CFC70

extern struct DebugMenuLine mcardMenu[1]; // offset 0x800CFC24

extern struct DebugMenuLine fogMenu[1]; // offset 0x800CFC58

extern struct DebugMenuLine AIMenu[1]; // offset 0x800CFB94

extern struct DebugMenuLine cameraMenu[1]; // offset 0x800CFCE0

extern long SignalEndGame; // offset 0x800CDFBC

extern struct SignalInfo signalInfoList[27]; // offset 0x800CDFC0

extern long dyna_clddyna[8]; // offset 0x800CE104

extern long stat_clddyna[8]; // offset 0x800CE124

extern long dyna_cldstat[8]; // offset 0x800CE144

extern long collide_ignoreAttr; // offset 0x800CE164

extern long collide_acceptAttr; // offset 0x800CE168

extern struct _SVector collide_localPoint; // offset 0x800D0370

extern struct MATRIX *collide_lwTransform; // offset 0x800D0378

extern struct _SVector *collide_point0; // offset 0x800D0360

extern struct _SVector *collide_point1; // offset 0x800D0364

extern struct _SVector *collide_normal0; // offset 0x800D037C

extern struct _SVector *collide_normal1; // offset 0x800D0380

extern long collide_t0; // offset 0x800D0368

extern long collide_t1; // offset 0x800D036C

extern long camera_modeToIndex[15]; // offset 0x800CDF38

static short shorten_count; // offset 0x800CDF74

static short shorten_flag; // offset 0x800CDF76

static short camera_still; // offset 0x800CDF78

static long roll_target; // offset 0x800CDF7C

static long current_roll_amount; // offset 0x800CDF80

static int roll_inc; // offset 0x800CDF84

static short CameraLookStickyFlag; // offset 0x800CDF96

static short panic_count; // offset 0x800CDF9A

extern struct Camera theCamera; // offset 0x800CFE90

static struct MATRIX wcTransformX; // offset 0x800CFD74

static struct MATRIX wcTransform2X; // offset 0x800CFD94

static struct MATRIX cwTransform2X; // offset 0x800CFDB4

static short combat_cam_distance; // offset 0x800CFDD4

static short combat_cam_angle; // offset 0x800CFDD6

static short combat_cam_weight; // offset 0x800CFDD8

static short combat_cam_debounce; // offset 0x800CFDDA

extern int CameraCenterDelay; // offset 0x800D035C

static short CenterFlag; // offset 0x800CFDDC

static struct _SVector camera_shakeOffset[16]; // offset 0x800CFDE4

static struct _SVector camera_plane; // offset 0x800CFE64

static struct _SVector left_point; // offset 0x800CFE6C

static struct _SVector right_point; // offset 0x800CFE74

static short hitline_rot; // offset 0x800CFE7C

static long ACE_amount; // offset 0x800CFE80

static struct _Rotation splinecam_helprot; // offset 0x800CFE84

static short Camera_lookHeight; // offset 0x800CFE8C

static short Camera_lookDist; // offset 0x800CFE8E

extern long campoint_hw; // offset 0x800D0354

extern long campoint_hh; // offset 0x800D0358

extern long draw_belowSplit; // offset 0x800CE19C

extern short forceDrawInFront; // offset 0x800CE198

extern struct SVECTOR *face_v0; // offset 0x800CE1A0

extern struct SVECTOR *face_v1; // offset 0x800CE1A4

extern struct SVECTOR *face_v2; // offset 0x800CE1A8

extern struct SVECTOR *face_v01; // offset 0x800CE1AC

extern struct SVECTOR *face_v12; // offset 0x800CE1B0

extern struct SVECTOR *face_v20; // offset 0x800CE1B4

extern struct UVTYPE *face_uv0; // offset 0x800CE1B8

extern struct UVTYPE *face_uv1; // offset 0x800CE1BC

extern struct UVTYPE *face_uv2; // offset 0x800CE1C0

extern struct UVTYPE *face_uv01; // offset 0x800CE1C4

extern struct UVTYPE *face_uv12; // offset 0x800CE1C8

extern struct UVTYPE *face_uv20; // offset 0x800CE1CC

extern long modelDQP; // offset 0x800D0388

extern unsigned char *draw_stack; // offset 0x800D0384

extern struct SVECTOR shadow_vertices[11]; // offset 0x800D038C

static struct LightGroup default_lightgroup; // offset 0x800CE460

extern void *light_light; // offset 0x800D0D78

extern struct LightInfo *light_lightInfo; // offset 0x800D0D80

extern struct _Terrain *light_terrain; // offset 0x800D0D7C

extern char HashExtensions[7][4]; // offset 0x800CE4D0

static struct _LoadStatus loadStatus; // offset 0x800D0D84

extern int _ramsize; // offset 0x800CE558

extern int _stacksize; // offset 0x800CE55C

extern char mainOptionsInit; // offset 0x800CE560

extern short gEndGameNow; // offset 0x800CE562

extern int pcverify; // offset 0x800CE564

extern int nosound; // offset 0x800CE568

extern int nomusic; // offset 0x800CE56C

extern struct InterfaceItem InterfaceItems[6]; // offset 0x800CE570

extern long DoMainMenu; // offset 0x800CE6C0

extern long mainMenuMode; // offset 0x800CE6C4

extern long *mainMenuScreen; // offset 0x800CE6C8

extern long *controlsScreen; // offset 0x800CE6CC

extern short mainMenuFadeInTime; // offset 0x800CE6D0

extern short mainMenuFading; // offset 0x800CE6D2

extern struct GameTracker gameTrackerX; // offset 0x800D0FAC

extern struct DRAWENV draw[2]; // offset 0x800D0E6C

extern struct DISPENV disp[2]; // offset 0x800D0E40

extern struct BLK_FILL clearRect[2]; // offset 0x800D0F88

extern struct MainTracker mainTrackerX; // offset 0x800D121C

extern int devstation; // offset 0x800D0E68

extern unsigned long __timerEvent; // offset 0x800D0F84

extern short mainMenuTimeOut; // offset 0x800D0FA8

static int mainMenuSfx; // offset 0x800D0E1C

extern struct _ButtonTexture PauseButtons[4][2]; // offset 0x800D122C

extern struct _ButtonTexture BmenuLines[3][2]; // offset 0x800D0F24

extern struct _ButtonTexture BexitLine[2]; // offset 0x800D0E20

extern struct FontPos fontPos[72]; // offset 0x800C8500

extern char charMap[92][3]; // offset 0x800C8620

static struct font_color_t the_font_color_table[5]; // offset 0x800CE1D0

extern unsigned char fontTransTable[128]; // offset 0x800CE224

extern struct FontTracker fontTracker; // offset 0x800D05EC

extern struct _BlockVramEntry *FONT_vramBlock; // offset 0x800D05E4

extern unsigned short SpecialFogClut; // offset 0x800D05E8

static char fp_str[512]; // offset 0x800D03E4

extern long cameraMode; // offset 0x800CE2A4

extern long playerCameraMode; // offset 0x800CE2A8

extern struct Object *fontsObject; // offset 0x800CE2AC

extern struct _FXTracker *gFXT; // offset 0x800D0C44

extern unsigned long StackSave; // offset 0x800D0C54

static unsigned long(**gOt[2]); // offset 0x800D0C0C

extern char *primBase; // offset 0x800D0C5C

static struct _PrimPool(*primPool[2]); // offset 0x800D0C14

static struct _PolytopeList *gPolytopeList; // offset 0x800D0C1C

static struct _InstanceList *instanceList; // offset 0x800D0C20

static struct _InstancePool *instancePool; // offset 0x800D0C24

static struct _VertexPool *gVertexPool; // offset 0x800D0C28

static struct LightInfo *gLightInfo; // offset 0x800D0C2C

extern struct _FXTracker *fxTracker; // offset 0x800D0C58

static void *enemyPlanPool; // offset 0x800D0C30

static void *planningPool; // offset 0x800D0C34

static struct _ObjectTracker *GlobalObjects; // offset 0x800D0C38

extern short RENDER_currentStreamUnitID; // offset 0x800D0C4C

static short pause_redraw_flag; // offset 0x800D0C3C

static void *pause_redraw_prim; // offset 0x800D0C40

extern int InStreamUnit; // offset 0x800D0C48

extern unsigned long **hackOT; // offset 0x800D0C50

extern unsigned char dualshock_motors[2]; // offset 0x800C875C

extern unsigned char dualshock_align[6]; // offset 0x800C8760

static short align_flag; // offset 0x800CE358

static short dualshock_onflag; // offset 0x800CE35A

static int dualShock; // offset 0x800CE35C

extern unsigned short lastData[2]; // offset 0x800CE3A0

static int gpSaved; // offset 0x800CE3A4

extern int gamePadControllerOut; // offset 0x800D0D70

extern long gDummyCommand[2][2]; // offset 0x800D0D60

extern unsigned char controllerType[2]; // offset 0x800D0CC8

static int ignoreFind; // offset 0x800D0C64

extern struct ControllerPacket gpbuffer1; // offset 0x800D0CD0

extern struct ControllerPacket gpbuffer2; // offset 0x800D0D18

extern struct ControllerPacket readGPBuffer1; // offset 0x800D0CF4

extern struct ControllerPacket readGPBuffer2; // offset 0x800D0D3C

static long dualshock0_time; // offset 0x800D0C68

static long dualshock1_time; // offset 0x800D0C6C

extern unsigned short psxData[2]; // offset 0x800D0CCC

static long overrideData[2][5]; // offset 0x800D0C70

static long overrideCommand[2][5]; // offset 0x800D0CA0

extern int gSramFullAlarm; // offset 0x800CEA88

static int gSramFullMsgCnt; // offset 0x800CEA8C

static long objectOneShotTriggerTbl[3]; // offset 0x800CEA90

extern int gSramTotalUsed; // offset 0x800D1508

extern int gSramUsedBlocks; // offset 0x800D1504

extern int gSramTotalFree; // offset 0x800D150C

extern int gSramLargestFree; // offset 0x800D12BC

extern int gSramFreeBlocks; // offset 0x800D1500

extern struct SoundEffectChannel soundEffectChannelTbl[16]; // offset 0x800D12C0

extern struct MusicLoadInfo musicInfo; // offset 0x800D1510

extern char soundBuffer[13256]; // offset 0x800D5C08

extern struct LightInfo *sbsp_lightInfo; // offset 0x800D12AC

extern struct ObjectAccess objectAccess[28]; // offset 0x800C877C

extern struct ObjectFunc objectFunc[7]; // offset 0x800C885C

extern short identityMatrix[3][3]; // offset 0x800CE870

extern char(*selectMenuText[5]); // offset 0x800C8768

extern long gTimerEnabled; // offset 0x800CE8D4

extern long FRAC_BITS; // offset 0x800CEB3C

static struct _FXGeneralEffect *FX_GeneralEffectTracker; // offset 0x800CEB64

static struct _FXRibbon *FX_ConstrictRibbon; // offset 0x800CEB68

static short FX_ConstrictStage; // offset 0x800CEB6C

static struct _Instance *FX_ConstrictInstance; // offset 0x800CEB70

static short snow_amount; // offset 0x800CEB74

static short rain_amount; // offset 0x800CEB76

static short current_rain_fade; // offset 0x800CEB78

static struct _Instance *FX_reaver_instance; // offset 0x800CEB7C

static short windx; // offset 0x800CEBA4

static short windy; // offset 0x800CEBA6

static short wind_deg; // offset 0x800CEBA8

static short wind_speed; // offset 0x800CEBAA

extern long FX_ColorArray[6]; // offset 0x800CEBAC

static short Spiral_Number; // offset 0x800CEBC4

static short Spiral_Degrees; // offset 0x800CEBC6

static long Spiral_Current; // offset 0x800CEBC8

static long Spiral_Max; // offset 0x800CEBCC

static struct _Position FX_ConstrictPosition; // offset 0x800D1594

static struct _Position *FX_ConstrictPositionPtr; // offset 0x800D159C

static struct _FX_PRIM *FX_LastUsedPrim; // offset 0x800D15A0

static short FX_Frames; // offset 0x800D15A4

static short FX_TimeCount; // offset 0x800D15A6

static struct DVECTOR Spiral_Array[65]; // offset 0x800D15B4

static struct DVECTOR Spiral_OffsetP[64]; // offset 0x800D16C4

static struct DVECTOR Spiral_OffsetM[64]; // offset 0x800D17C4

static int Spiral_Glow_X; // offset 0x800D18C4

static int Spiral_Glow_Y; // offset 0x800D18C8

static int Spiral_Glow_Size; // offset 0x800D18CC

static int Spiral_Mod; // offset 0x800D18D0

extern struct _Normal gNormalList[244]; // offset 0x800C8970

extern short ecostable[3072]; // offset 0x800C9110

static long vmRealClock; // offset 0x800CEBD4

static long vmClock; // offset 0x800CEBD8

static struct NewMemTracker newMemTracker; // offset 0x800D18D4

static char midiDataByteCount[8]; // offset 0x800CED84

extern unsigned long aadGp; // offset 0x800CA910

static unsigned short aadHblanksPerUpdate[4]; // offset 0x800CECC0

static unsigned long aadUpdateRate[4]; // offset 0x800CECC8

extern struct AadMemoryStruct *aadMem; // offset 0x800CECD8

static int gDefragRequest; // offset 0x800CECDC

static unsigned long aadReverbModeSize[10]; // offset 0x800CED5C

static unsigned long __hblankEvent; // offset 0x800D18E8

static unsigned char *smfDataPtr; // offset 0x800D18EC

static unsigned long smfBytesLeft; // offset 0x800D18F0

static struct AadDynamicSfxLoadInfo *smfInfo; // offset 0x800D18F4

static struct AadProgramAtr aadDummySfxProgram; // offset 0x800CEF48

extern unsigned short aadPitchTable[85]; // offset 0x800CEF50

extern unsigned long aadStepsPerCent[85]; // offset 0x800CEFFC

extern short aadStepsPerSemitone[85]; // offset 0x800CF150

extern long CurrentWarpNumber; // offset 0x800CF1FC

extern struct WarpRoom WarpRoomArray[14]; // offset 0x800CF200

extern struct STracker StreamTracker; // offset 0x800D1920

extern struct _TFace *MORPH_SavedFace; // offset 0x800D1D20

extern struct Level *MORPH_SavedLevel; // offset 0x800D1910

extern short MORPH_Component[3]; // offset 0x800D1914

extern short MORPH_Track[2]; // offset 0x800D191C

static int s_zval; // offset 0x800D18F8

extern long RazielCommands[10]; // offset 0x800CF560

static int Pending; // offset 0x800CF588

static int Up; // offset 0x800CF58C

static int Down; // offset 0x800CF590

static struct _G2AnimAlphaTable_Type(*G2AlphaTables[7]); // offset 0x800CF594

static void *circWhere; // offset 0x800CF5B0

static char circBuf[4096]; // offset 0x800D2E2C

static int loadFromHead; // offset 0x800CF4E0

static int loadCanFail; // offset 0x800CF4E4

static int gCurDir; // offset 0x800CF4E8

static struct _LoadQueueEntry LoadQueue[40]; // offset 0x800D1D24

static struct _LoadQueueEntry *loadFree; // offset 0x800D2724

static struct _LoadQueueEntry *loadHead; // offset 0x800D2728

static struct _LoadQueueEntry *loadTail; // offset 0x800D272C

static int numLoads; // offset 0x800D2730

static short EventAbortLine; // offset 0x800CF534

static short EventJustRecievedTimer; // offset 0x800CF536

static long MoveCodeStreamExtra; // offset 0x800CF538

static long CurrentEventLine; // offset 0x800CF53C

static long EventCurrentEventIndex; // offset 0x800CF540

extern long WaterInUse; // offset 0x800CF544

extern long NumSignalsToReset; // offset 0x800CF548

extern long WaitingForVoiceNumber; // offset 0x800D2AF8

extern long WaitingToLoadSound; // offset 0x800D2A18

extern long WaitingToLoadSFX; // offset 0x800D2AF4

extern short MoviePlayed; // offset 0x800D2A6C

extern short MovieToPlay; // offset 0x800D2A70

static struct Event *currentEventInstance; // offset 0x800D2734

static struct ScriptPCode *currentActionScript; // offset 0x800D2738

static short *EventAbortedPosition; // offset 0x800D273C

extern long eventListNumInstances[20]; // offset 0x800D2A1C

extern struct _Instance(*eventListArray[20][10]); // offset 0x800D2B0C

static struct WaterLevelProcess WaterLevelArray[5]; // offset 0x800D2744

static struct Level *CurrentPuzzleLevel; // offset 0x800D27D0

static struct EventTimer eventTimerArray[24]; // offset 0x800D27D4

static long numActiveEventTimers; // offset 0x800D2A14

extern struct SignalResetStruct ResetSignalArray[16]; // offset 0x800D2A74

extern struct HintSystemStruct gHintSystem; // offset 0x800D2AFC

extern long VRAM_NeedToUpdateMorph; // offset 0x800CF5B4

extern short M_TrackClutUpdate; // offset 0x800D4804

extern struct _BlockVramEntry *openVramBlocks; // offset 0x800D482C

extern struct _BlockVramEntry *usedVramBlocks; // offset 0x800D4828

extern struct _BlockVramEntry vramBlockList[90]; // offset 0x800D3E2C

extern long numOfBlocksUsed; // offset 0x800D4808

extern struct _BlockVramEntry TerrainVramBlock; // offset 0x800D480C

static short FireReaverFlag; // offset 0x800D48B8

static short fx_going; // offset 0x800CF5CC

extern struct _FXBlastringEffect *fx_blastring; // offset 0x800CF5D0

static short HUD_Captured; // offset 0x800CF5D4

static short MANNA_Position; // offset 0x800D48BC

static short MANNA_Pos_vel; // offset 0x800D48BE

static short glyph_time; // offset 0x800D48C0

static short glyph_trigger; // offset 0x800D48C2

static short glyph_cost; // offset 0x800D48C4

static short HUD_Count; // offset 0x800D48C6

static short HUD_Count_Overall; // offset 0x800D48C8

static int blast_range; // offset 0x800D48CC

static int fx_radius_old; // offset 0x800D48D0

static int MANNA_Pickup_Time; // offset 0x800D48D4

static short HUD_Rotation; // offset 0x800D48D8

static short HUD_Rot_vel; // offset 0x800D48DA

static short HUD_Position; // offset 0x800D48DC

static short HUD_Pos_vel; // offset 0x800D48DE

static short HUD_State; // offset 0x800D48E0

static short HUD_Wait; // offset 0x800D48E2

static struct _SVector HUD_Cap_Pos; // offset 0x800D48E4

static struct _SVector HUD_Cap_Vel; // offset 0x800D48EC

static int warpDraw; // offset 0x800D48F4

static int glowdeg; // offset 0x800D48F8

extern int hud_warp_arrow_flash; // offset 0x800D48FC

extern struct _MonsterStateChoice HUMAN_StateChoiceTable[6]; // offset 0x800CA978

extern struct _MonsterFunctionTable HUMAN_FunctionTable; // offset 0x800CF5E0

static struct MissileGraphics MISSILE_objectTable[4]; // offset 0x800CA9C0

static struct _MonsterState DefaultStateTable[31]; // offset 0x800CAA20

static struct _MonsterFunctionTable DefaultFunctionTable; // offset 0x800CF68C

extern struct _MonsterStateChoice SLUAGH_StateChoiceTable[4]; // offset 0x800CAB18

extern struct _MonsterFunctionTable SLUAGH_FunctionTable; // offset 0x800CF6AC

extern struct _MonsterStateChoice SOUL_StateChoiceTable[7]; // offset 0x800CAB48

extern struct _MonsterFunctionTable SOUL_FunctionTable; // offset 0x800CF6D4

static int gNumMonsters; // offset 0x800CF62C

static int gNumSpectralMonsters; // offset 0x800CF630

static int gNumMaterialMonsters; // offset 0x800CF634

static struct RadarInfo radarDir[8]; // offset 0x800CF638

static unsigned char radarDirIndex[8]; // offset 0x800CF668

static struct _MonsterVars(*monsterSenseArray[40]); // offset 0x800D4900

static char monsterSensed[40]; // offset 0x800D49A0

static int lastSenseFrame; // offset 0x800D49C8

static struct burntTuneType burntTest; // offset 0x800CF674

static int _indexTable[16]; // offset 0x800CAC2C

static int _stepSizeTable[64]; // offset 0x800CAC6C

static struct _G2AnimChanStatusBlockPool_Type _chanStatusBlockPool; // offset 0x800D49CC

static struct _G2AnimSegValue_Type _segValues[80]; // offset 0x800D49DC

static struct _G2AnimControllerPool_Type _controllerPool; // offset 0x800D515C

static struct _G2AnimInterpStateBlockPool_Type _interpStateBlockPool; // offset 0x800D516C

extern struct _MonsterStateChoice VWRAITH_StateChoiceTable[7]; // offset 0x800CAB9C

extern struct _MonsterFunctionTable VWRAITH_FunctionTable; // offset 0x800CF6F4

extern struct _MonsterStateChoice WORSHIP_StateChoiceTable[5]; // offset 0x800CABF0

extern struct _MonsterFunctionTable WORSHIP_FunctionTable; // offset 0x800CF714

extern struct PoolManagementData *poolManagementData; // offset 0x800D51D0

static struct PoolManagementData poolManagementDataStorage; // offset 0x800D5184

static long timerArray[10]; // offset 0x800D51A4

static long timerIndex; // offset 0x800D51CC

static struct _fth directionList[6]; // offset 0x800CF75C

static struct __Force *ExternalForces; // offset 0x800D51D4

extern int LoopCounter; // offset 0x800CF774

static int WaterStatus; // offset 0x800CF778

static unsigned char PickupList[4]; // offset 0x800CF77C

static unsigned short cowlList[19]; // offset 0x800CF780

extern struct __razController controllerList[24]; // offset 0x800CF7A8

extern struct __CannedSound cannedSound[4]; // offset 0x800CF808

static int AlgoControlFlag; // offset 0x800CF858

static int ZoneDelta; // offset 0x800CF85C

extern struct __Idle **currentIdleList; // offset 0x800CF874

extern int currentIdleListCount; // offset 0x800CF878

extern int currentIdleCount; // offset 0x800CF87C

static int BlockCount; // offset 0x800CF880

static int LastBlock; // offset 0x800CF884

static struct __Player Raziel; // offset 0x800D5214

static struct RazielData *PlayerData; // offset 0x800D57D0

static struct _G2AnimInterpInfo_Type razInterpInfo[3]; // offset 0x800D57D4

static struct __FitPoint constrictData[32]; // offset 0x800D5804

static struct MATRIX TempMat; // offset 0x800D5884

static struct GameTracker *gameTracker; // offset 0x800D58A4

static long *PadData; // offset 0x800D58A8

static struct _G2SVector3_Type ExtraRotData; // offset 0x800D58AC

static struct _G2SVector3_Type *ExtraRot; // offset 0x800D58B4

extern int ControlFlag; // offset 0x800D59AC

static int PhysicsMode; // offset 0x800D5914

static struct __EngagedInstance EngagedList[15]; // offset 0x800D5924

static struct _Normal Norm; // offset 0x800D599C

extern int AutoFaceAngle; // offset 0x800D59A8

static int LastRC; // offset 0x800D59A4

extern struct _GlobalSaveTracker *GlobalSave; // offset 0x800CF8A8

static long numbufferedIntros; // offset 0x800CF8AC

static int the_header_size; // offset 0x800CF8B0

extern long SaveArraySize[10]; // offset 0x800CF8B4

static struct SavedBasic(*bufferSavedIntroArray[64]); // offset 0x800D59D0

extern char monVersion[12]; // offset 0x800CF95C

extern struct XAVoiceTracker voiceTracker; // offset 0x800D5AD4

static struct cinema_fn_table_t *the_cine_table; // offset 0x800CAD90

static struct _ObjectTracker *the_cine_tracker; // offset 0x800CAD94

extern int StCdIntrFlag; // offset 0x800D8FD0

static struct LocalizationHeader *LocalizationTable; // offset 0x800CF994

static char **LocalStrings; // offset 0x800CF998

extern struct XAVoiceListEntry *voiceList; // offset 0x800CF99C

static enum language_t the_language; // offset 0x800D5BFC

static char(*the_attract_movies[4]); // offset 0x800CADC8

static int MAIN_YPOS; // offset 0x800CFA48

static int PAUSE_YPOS; // offset 0x800CFA4C

static int MAIN_XPOS; // offset 0x800CFA50

static int MAIN_WIDTH; // offset 0x800CFA54

static int PAUSE_XPOS; // offset 0x800CFA58

static int PAUSE_WIDTH; // offset 0x800CFA5C

static int LINESKIP; // offset 0x800CFA60

static int ITEMSKIP; // offset 0x800CFA64

static int hack_reset_attract; // offset 0x800CFA68

static int StartGameFading; // offset 0x800CFA6C

static int hack_attract; // offset 0x800CFA70

static int hack_attract_movie; // offset 0x800CFA74

extern long *mainMenuScreen; // offset 0x4

static int hack_initialized; // offset 0x800CFB3C

static struct _ButtonTexture *FaceButtons; // offset 0x800D5C04

extern struct mcmenu_table_t the_mcmenu_table; // offset 0x24

extern struct memcard_t gMemcard; // offset 0x800D91D4

static struct UW_ScreenXY *ScreenMorphArray; // offset 0x800CF894

static long UW_angle; // offset 0x800D59B0

static long UW_scalex; // offset 0x800D59B4

static long UW_scalexInc; // offset 0x800D59B8

static long UW_angleInc; // offset 0x800D59BC

/* End external declarations */

#endif