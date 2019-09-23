#ifndef MEMCARD_H
#define MEMCARD_H

static struct MEMCARD_216fake gMcmenu; // offset 0x800D8FD4

extern struct memcard_t gMemcard; // offset 0x800D91D4

extern struct mcmenu_table_t the_mcmenu_table; // offset 0x24

struct mcpsx_t // hashcode: 0x79B44761 (dec: 2041857889)
{
	struct MEMCARD_2fake state;  // size=20, offset=0 //  hashcode: 0x80550B86 (dec: -2141910138), parent name: 'mcpsx_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MEMCARD_3fake params; // size=32, offset=20 //  hashcode: 0xCC71AACA (dec: -864965942), parent name: 'mcpsx_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *opaque;				 // size=0, offset=52 //  hashcode: 0xE26A467A (dec: -496351622), parent name: 'mcpsx_t', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct mcpsx_directory_t // hashcode: 0xED9CBF92 (dec: -308494446)
{
	char name[20]; // size=20, offset=0 //  hashcode: 0xF891676C (dec: -124688532), parent name: 'mcpsx_directory_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nbytes;	// size=0, offset=20 //  hashcode: 0xCFF1F8E8 (dec: -806225688), parent name: 'mcpsx_directory_t', parent hashcode: 0xFFFFFFFF (dec: -1)
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

struct MEMCARD_2fake // hashcode: 0xC2F368D5 (dec: -1024235307)
{
	enum mcpsx_mode_t mode; // size=4, offset=0 //  hashcode: 0xBAF9DF18 (dec: -1158029544), parent name: 'MEMCARD_2fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	enum mcpsx_func_t func; // size=4, offset=4 //  hashcode: 0x9DD9B629 (dec: -1646676439), parent name: 'MEMCARD_2fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	enum mcpsx_sync_t sync; // size=4, offset=8 //  hashcode: 0xBB3C1257 (dec: -1153691049), parent name: 'MEMCARD_2fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	enum mcpsx_err_t err;   // size=4, offset=12 //  hashcode: 0x69AA5B81 (dec: 1772772225), parent name: 'MEMCARD_2fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int observed;			// size=0, offset=16 //  hashcode: 0xC260BA81 (dec: -1033848191), parent name: 'MEMCARD_2fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_3fake // hashcode: 0x0379B572 (dec: 58307954)
{
	long channel;						 // size=0, offset=0 //  hashcode: 0x57AA83ED (dec: 1470792685), parent name: 'MEMCARD_3fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *filename;						 // size=0, offset=4 //  hashcode: 0xBE2711D7 (dec: -1104735785), parent name: 'MEMCARD_3fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *buffer;						 // size=0, offset=8 //  hashcode: 0xA4DD7100 (dec: -1528991488), parent name: 'MEMCARD_3fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long offset;						 // size=0, offset=12 //  hashcode: 0x6B45660D (dec: 1799710221), parent name: 'MEMCARD_3fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long nbytes;						 // size=0, offset=16 //  hashcode: 0xCDB9CA42 (dec: -843462078), parent name: 'MEMCARD_3fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long nblocks;						 // size=0, offset=20 //  hashcode: 0x8A24D9B1 (dec: -1977296463), parent name: 'MEMCARD_3fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct mcpsx_directory_t *directory; // size=24, offset=24 //  hashcode: 0xA38BD88C (dec: -1551116148), parent name: 'MEMCARD_3fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long *nfilesptr;					 // size=0, offset=28 //  hashcode: 0x9FA794C8 (dec: -1616407352), parent name: 'MEMCARD_3fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct mcard_t // hashcode: 0x55AF6CB2 (dec: 1437559986)
{
	struct MEMCARD_4fake state;  // size=16, offset=0 //  hashcode: 0x793E25D6 (dec: 2034116054), parent name: 'mcard_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MEMCARD_5fake params; // size=28, offset=16 //  hashcode: 0xB691564F (dec: -1231989169), parent name: 'mcard_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct mcpsx_t *mcpsx;		 // size=56, offset=44 //  hashcode: 0xD859EB48 (dec: -665195704), parent name: 'mcard_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *opaque;				 // size=0, offset=48 //  hashcode: 0x76CC0C61 (dec: 1993084001), parent name: 'mcard_t', parent hashcode: 0xFFFFFFFF (dec: -1)
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

struct MEMCARD_4fake // hashcode: 0x5DED9C3E (dec: 1575853118)
{
	enum mcpsx_err_t err;		// size=4, offset=0 //  hashcode: 0xC79402D9 (dec: -946601255), parent name: 'MEMCARD_4fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	enum state_t fsm;			// size=4, offset=4 //  hashcode: 0x30610224 (dec: 811663908), parent name: 'MEMCARD_4fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	enum mcard_status_t status; // size=4, offset=8 //  hashcode: 0x8B9A471C (dec: -1952823524), parent name: 'MEMCARD_4fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int not_exists;				// size=0, offset=12 //  hashcode: 0x629B2D32 (dec: 1654336818), parent name: 'MEMCARD_4fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_5fake // hashcode: 0xF66F9186 (dec: -160460410)
{
	long parameter;						 // size=0, offset=0 //  hashcode: 0x3F685EA4 (dec: 1063804580), parent name: 'MEMCARD_5fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long *nfilesptr;					 // size=0, offset=4 //  hashcode: 0xB2AA6AB3 (dec: -1297454413), parent name: 'MEMCARD_5fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct mcpsx_directory_t *directory; // size=24, offset=8 //  hashcode: 0xED7190B1 (dec: -311324495), parent name: 'MEMCARD_5fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *filename;						 // size=0, offset=12 //  hashcode: 0xB4B97436 (dec: -1262914506), parent name: 'MEMCARD_5fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *buffer;						 // size=0, offset=16 //  hashcode: 0x4A6B78C6 (dec: 1248557254), parent name: 'MEMCARD_5fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nbytes;							 // size=0, offset=20 //  hashcode: 0x3B8C8523 (dec: 999064867), parent name: 'MEMCARD_5fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nblocks;						 // size=0, offset=24 //  hashcode: 0x9973C2E9 (dec: -1720466711), parent name: 'MEMCARD_5fake', parent hashcode: 0xFFFFFFFF (dec: -1)
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

struct mcmenu_t // hashcode: 0xCDD1805D (dec: -841908131)
{
	struct MEMCARD_6fake state;  // size=20, offset=0 //  hashcode: 0x4560EE43 (dec: 1163980355), parent name: 'mcmenu_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MEMCARD_7fake params; // size=376, offset=20 //  hashcode: 0x83C9E4E4 (dec: -2083920668), parent name: 'mcmenu_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct mcard_t *mcard;		 // size=52, offset=396 //  hashcode: 0x97F8BDC3 (dec: -1745306173), parent name: 'mcmenu_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *opaque;				 // size=0, offset=400 //  hashcode: 0x759CFE30 (dec: 1973222960), parent name: 'mcmenu_t', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct mcmenu_table_t // hashcode: 0xB78C7C17 (dec: -1215529961)
{
	int (*data_size)();   // size=0, offset=0 //  hashcode: 0x49CFD417 (dec: 1238357015), parent name: 'mcmenu_table_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*initialize)(); // size=0, offset=4 //  hashcode: 0xB5DEA2E7 (dec: -1243700505), parent name: 'mcmenu_table_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*terminate)();  // size=0, offset=8 //  hashcode: 0xBBD6D0DB (dec: -1143549733), parent name: 'mcmenu_table_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*begin)();	  // size=0, offset=12 //  hashcode: 0xC36949B1 (dec: -1016510031), parent name: 'mcmenu_table_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	void (*end)();		  // size=0, offset=16 //  hashcode: 0xD8DF772E (dec: -656443602), parent name: 'mcmenu_table_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int (*set_buffer)();  // size=0, offset=20 //  hashcode: 0x85735F7F (dec: -2056036481), parent name: 'mcmenu_table_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int (*main)();		  // size=0, offset=24 //  hashcode: 0xF23309C0 (dec: -231536192), parent name: 'mcmenu_table_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	int (*pause)();		  // size=0, offset=28 //  hashcode: 0xF3F727F0 (dec: -201906192), parent name: 'mcmenu_table_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *versionID;	  // size=0, offset=32 //  hashcode: 0xCA07A07E (dec: -905469826), parent name: 'mcmenu_table_t', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_6fake // hashcode: 0x5972ED84 (dec: 1500704132)
{
	enum fsm_t fsm;				// size=4, offset=0 //  hashcode: 0xB4663DF7 (dec: -1268367881), parent name: 'MEMCARD_6fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	enum fsm_t fsm_prev;		// size=4, offset=4 //  hashcode: 0x5B0AB40F (dec: 1527428111), parent name: 'MEMCARD_6fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	enum mcard_status_t status; // size=4, offset=8 //  hashcode: 0x03BCDA4A (dec: 62708298), parent name: 'MEMCARD_6fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int running;				// size=0, offset=12 //  hashcode: 0xFF8B86E2 (dec: -7633182), parent name: 'MEMCARD_6fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int slot;					// size=0, offset=16 //  hashcode: 0x57F27549 (dec: 1475507529), parent name: 'MEMCARD_6fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_7fake // hashcode: 0x25F51C2D (dec: 636820525)
{
	int nblocks;							// size=0, offset=0 //  hashcode: 0x04A017CF (dec: 77600719), parent name: 'MEMCARD_7fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int nbytes;								// size=0, offset=4 //  hashcode: 0x015B3A8C (dec: 22755980), parent name: 'MEMCARD_7fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *buffer;							// size=0, offset=8 //  hashcode: 0x27ADF5F9 (dec: 665712121), parent name: 'MEMCARD_7fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct mcpsx_directory_t directory[15]; // size=360, offset=12 //  hashcode: 0xCF27E162 (dec: -819469982), parent name: 'MEMCARD_7fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long nfiles;							// size=0, offset=372 //  hashcode: 0x8417A1D5 (dec: -2078826027), parent name: 'MEMCARD_7fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_76fake // hashcode: 0x0E20DE5C (dec: 237035100)
{
	unsigned long (*function)(); // size=0, offset=0 //  hashcode: 0x0287D3D9 (dec: 42456025), parent name: 'MEMCARD_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *fnData;				 // size=0, offset=4 //  hashcode: 0x93FD0A7C (dec: -1812133252), parent name: 'MEMCARD_76fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_77fake // hashcode: 0x94251E54 (dec: -1809506732)
{
	struct _G2SVector3_Type base;   // size=6, offset=0 //  hashcode: 0x55D624C8 (dec: 1440097480), parent name: 'MEMCARD_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2SVector3_Type offset; // size=6, offset=6 //  hashcode: 0xA1664747 (dec: -1587132601), parent name: 'MEMCARD_77fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_78fake // hashcode: 0x7AA04274 (dec: 2057323124)
{
	struct _G2Quat_Type src;  // size=8, offset=0 //  hashcode: 0x1D1AACEA (dec: 488287466), parent name: 'MEMCARD_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _G2Quat_Type dest; // size=8, offset=8 //  hashcode: 0x4B75C824 (dec: 1266010148), parent name: 'MEMCARD_78fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MEMCARD_79fake // Hashcode: 0xCBE8E87E (dec: -873928578)
{
	struct MEMCARD_76fake callback; // size=8, offset=0
	struct MEMCARD_77fake vector;   // size=12, offset=0
	struct MEMCARD_78fake quat;		// size=16, offset=0
};

union MEMCARD_80fake // Hashcode: 0xCA90C9EC (dec: -896480788)
{
	long color;				// size=0, offset=0
	struct _RGBAColor rgba; // size=4, offset=0
};

union MEMCARD_81fake // Hashcode: 0xF97F02FB (dec: -109116677)
{
	long l;		// size=0, offset=0
	short s[2]; // size=4, offset=0
	char c[4];  // size=4, offset=0
};

struct MEMCARD_82fake // hashcode: 0xAC93A1D9 (dec: -1399610919)
{
	union MEMCARD_81fake size; // size=4, offset=0 //  hashcode: 0x02489ECF (dec: 38313679), parent name: 'MEMCARD_82fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_83fake // hashcode: 0x6DB3740D (dec: 1840477197)
{
	short x;				// size=0, offset=0 //  hashcode: 0xD19FA212 (dec: -778067438), parent name: 'MEMCARD_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;				// size=0, offset=2 //  hashcode: 0x54EB28E7 (dec: 1424697575), parent name: 'MEMCARD_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;				// size=0, offset=4 //  hashcode: 0x69804F85 (dec: 1770016645), parent name: 'MEMCARD_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short zrot;				// size=0, offset=6 //  hashcode: 0x723C2D72 (dec: 1916546418), parent name: 'MEMCARD_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector offset; // size=8, offset=8 //  hashcode: 0x1B7F07EE (dec: 461309934), parent name: 'MEMCARD_83fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_84fake // hashcode: 0xFBE56B42 (dec: -68850878)
{
	long index; // size=0, offset=0 //  hashcode: 0xA8A53F46 (dec: -1465565370), parent name: 'MEMCARD_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0x447D70B3 (dec: 1149071539), parent name: 'MEMCARD_84fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_85fake // hashcode: 0x81664843 (dec: -2124003261)
{
	long index; // size=0, offset=0 //  hashcode: 0xAE05C848 (dec: -1375352760), parent name: 'MEMCARD_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xD648FDD0 (dec: -699859504), parent name: 'MEMCARD_85fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_86fake // hashcode: 0xDF664EC7 (dec: -546943289)
{
	long index; // size=0, offset=0 //  hashcode: 0x60F101B9 (dec: 1626407353), parent name: 'MEMCARD_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value; // size=0, offset=4 //  hashcode: 0xABFB803E (dec: -1409580994), parent name: 'MEMCARD_86fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_87fake // hashcode: 0x87FA0D90 (dec: -2013655664)
{
	long time;  // size=0, offset=0 //  hashcode: 0x9089CA3C (dec: -1870017988), parent name: 'MEMCARD_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long scale; // size=0, offset=4 //  hashcode: 0xED717858 (dec: -311330728), parent name: 'MEMCARD_87fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_88fake // hashcode: 0x3C7CFE67 (dec: 1014824551)
{
	long action;   // size=0, offset=0 //  hashcode: 0x44D14F99 (dec: 1154568089), parent name: 'MEMCARD_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long value[2]; // size=8, offset=4 //  hashcode: 0x1E03D7D4 (dec: 503568340), parent name: 'MEMCARD_88fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_89fake // hashcode: 0x7E0038A5 (dec: 2113943717)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x4BEDE7C0 (dec: 1273882560), parent name: 'MEMCARD_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *data;  // size=0, offset=4 //  hashcode: 0xF3E7AD65 (dec: -202920603), parent name: 'MEMCARD_89fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_90fake // hashcode: 0x9435BB99 (dec: -1808417895)
{
	void *intro; // size=0, offset=0 //  hashcode: 0xD3AEB884 (dec: -743524220), parent name: 'MEMCARD_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long frame;  // size=0, offset=4 //  hashcode: 0x4E89D889 (dec: 1317656713), parent name: 'MEMCARD_90fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_91fake // hashcode: 0x7151A172 (dec: 1901175154)
{
	void *intro; // size=0, offset=0 //  hashcode: 0x8EEB6C94 (dec: -1897173868), parent name: 'MEMCARD_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long model;  // size=0, offset=4 //  hashcode: 0xCE6EF7AD (dec: -831588435), parent name: 'MEMCARD_91fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_92fake // hashcode: 0xA33291B2 (dec: -1556966990)
{
	unsigned char target;	 // size=0, offset=0 //  hashcode: 0xB7B0FC65 (dec: -1213137819), parent name: 'MEMCARD_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source1;	// size=0, offset=1 //  hashcode: 0x9D12885A (dec: -1659729830), parent name: 'MEMCARD_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char source2;	// size=0, offset=2 //  hashcode: 0xF0CFA9C6 (dec: -254826042), parent name: 'MEMCARD_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad;		  // size=0, offset=3 //  hashcode: 0x3B95120D (dec: 999625229), parent name: 'MEMCARD_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0xB1D04D90 (dec: -1311748720), parent name: 'MEMCARD_92fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_93fake // hashcode: 0x3F4B7C8F (dec: 1061911695)
{
	long timer;  // size=0, offset=0 //  hashcode: 0xF33A2E79 (dec: -214290823), parent name: 'MEMCARD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long action; // size=0, offset=4 //  hashcode: 0x878133A4 (dec: -2021575772), parent name: 'MEMCARD_93fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_94fake // hashcode: 0xB50A98DE (dec: -1257596706)
{
	short index;					// size=0, offset=0 //  hashcode: 0xECE0E417 (dec: -320805865), parent name: 'MEMCARD_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short z;						// size=0, offset=2 //  hashcode: 0xB3107C29 (dec: -1290765271), parent name: 'MEMCARD_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *upSignal;   // size=0, offset=4 //  hashcode: 0xB81CC3E6 (dec: -1206074394), parent name: 'MEMCARD_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSignal *downSignal; // size=0, offset=8 //  hashcode: 0x1FB7D222 (dec: 532140578), parent name: 'MEMCARD_94fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_95fake // hashcode: 0xA20E6F45 (dec: -1576112315)
{
	long currentnum; // size=0, offset=0 //  hashcode: 0x0BD395A9 (dec: 198415785), parent name: 'MEMCARD_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long streamID;   // size=0, offset=4 //  hashcode: 0x5A49ADA3 (dec: 1514778019), parent name: 'MEMCARD_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char toname[16]; // size=16, offset=8 //  hashcode: 0xE21741E3 (dec: -501792285), parent name: 'MEMCARD_95fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_96fake // hashcode: 0x6C8F2BAB (dec: 1821322155)
{
	char num;			   // size=0, offset=0 //  hashcode: 0x82BAF1A3 (dec: -2101677661), parent name: 'MEMCARD_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char vel;			   // size=0, offset=1 //  hashcode: 0xC66FC694 (dec: -965753196), parent name: 'MEMCARD_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short misc;			   // size=0, offset=2 //  hashcode: 0x44E932B7 (dec: 1156133559), parent name: 'MEMCARD_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char flags;			   // size=0, offset=4 //  hashcode: 0x39EFBC39 (dec: 972012601), parent name: 'MEMCARD_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char timeToLive;	   // size=0, offset=5 //  hashcode: 0x4D401E59 (dec: 1296047705), parent name: 'MEMCARD_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short dummy2;		   // size=0, offset=6 //  hashcode: 0x041914EF (dec: 68752623), parent name: 'MEMCARD_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Object *object; // size=0, offset=8 //  hashcode: 0x254157A7 (dec: 625039271), parent name: 'MEMCARD_96fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_97fake // hashcode: 0x508AD85B (dec: 1351276635)
{
	long index;  // size=0, offset=0 //  hashcode: 0xFB48DBF4 (dec: -79111180), parent name: 'MEMCARD_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x1A94715B (dec: 445935963), parent name: 'MEMCARD_97fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_98fake // hashcode: 0xB769A56D (dec: -1217813139)
{
	short type; // size=0, offset=0 //  hashcode: 0xBB59E301 (dec: -1151737087), parent name: 'MEMCARD_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time; // size=0, offset=2 //  hashcode: 0x985E851A (dec: -1738636006), parent name: 'MEMCARD_98fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_99fake // hashcode: 0xFC54BD6A (dec: -61555350)
{
	long time;   // size=0, offset=0 //  hashcode: 0xC063C57C (dec: -1067203204), parent name: 'MEMCARD_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	void *intro; // size=0, offset=4 //  hashcode: 0x8E5B5E1A (dec: -1906614758), parent name: 'MEMCARD_99fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_100fake // hashcode: 0xC1E796C4 (dec: -1041787196)
{
	void *intro;			  // size=0, offset=0 //  hashcode: 0xF3579051 (dec: -212365231), parent name: 'MEMCARD_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct Signal *gotoLabel; // size=0, offset=4 //  hashcode: 0x5E33D56A (dec: 1580455274), parent name: 'MEMCARD_100fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_101fake // hashcode: 0xB7F8DEA4 (dec: -1208426844)
{
	char world[9]; // size=9, offset=0 //  hashcode: 0x778B1EB8 (dec: 2005606072), parent name: 'MEMCARD_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char level[9]; // size=9, offset=9 //  hashcode: 0x029CB05D (dec: 43823197), parent name: 'MEMCARD_101fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_102fake // hashcode: 0x56CA1197 (dec: 1456083351)
{
	struct Signal *signal; // size=0, offset=0 //  hashcode: 0x8A3DD71F (dec: -1975658721), parent name: 'MEMCARD_102fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long times;			   // size=0, offset=4 //  hashcode: 0xC3D839C9 (dec: -1009239607), parent name: 'MEMCARD_102fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_103fake // hashcode: 0xE46F34C5 (dec: -462474043)
{
	unsigned char r;   // size=0, offset=0 //  hashcode: 0xBF2761ED (dec: -1087938067), parent name: 'MEMCARD_103fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char g;   // size=0, offset=1 //  hashcode: 0x4F694BFD (dec: 1332300797), parent name: 'MEMCARD_103fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char b;   // size=0, offset=2 //  hashcode: 0xE7D06604 (dec: -405772796), parent name: 'MEMCARD_103fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	unsigned char pad; // size=0, offset=3 //  hashcode: 0xA1DDF4F4 (dec: -1579289356), parent name: 'MEMCARD_103fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_104fake // hashcode: 0x4C0268BA (dec: 1275226298)
{
	short x;	 // size=0, offset=0 //  hashcode: 0x4B27B174 (dec: 1260892532), parent name: 'MEMCARD_104fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short y;	 // size=0, offset=2 //  hashcode: 0x468B1ED3 (dec: 1183522515), parent name: 'MEMCARD_104fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short time;  // size=0, offset=4 //  hashcode: 0xFFBD7FEF (dec: -4358161), parent name: 'MEMCARD_104fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short index; // size=0, offset=6 //  hashcode: 0x66ECD18C (dec: 1726796172), parent name: 'MEMCARD_104fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	char *text;  // size=0, offset=8 //  hashcode: 0x5CE28EDB (dec: 1558351579), parent name: 'MEMCARD_104fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MEMCARD_105fake // Hashcode: 0xE602FD88 (dec: -436011640)
{
	struct MEMCARD_82fake misc[3];		// size=12, offset=0
	struct _CameraKey *cameraKey;		// size=24, offset=0
	struct MEMCARD_83fake teleport;		// size=16, offset=0
	struct MEMCARD_84fake cameraValue;  // size=8, offset=0
	struct MEMCARD_85fake miscValue;	// size=8, offset=0
	struct MEMCARD_86fake logicValue;   // size=8, offset=0
	long timer;							// size=0, offset=0
	long times;							// size=0, offset=0
	long lightGroup;					// size=0, offset=0
	long farPlane;						// size=0, offset=0
	long cameraAdjust;					// size=0, offset=0
	long cameraMode;					// size=0, offset=0
	long cameraLock;					// size=0, offset=0
	long cameraUnlock;					// size=0, offset=0
	long cameraSmooth;					// size=0, offset=0
	long cameraTimer;					// size=0, offset=0
	struct MEMCARD_87fake cameraShake;  // size=8, offset=0
	long cameraSave;					// size=0, offset=0
	long cameraRestore;					// size=0, offset=0
	struct _BGObject *bgObject;			// size=24, offset=0
	long value[2];						// size=8, offset=0
	struct MEMCARD_88fake sound;		// size=12, offset=0
	void *intro;						// size=0, offset=0
	long deathZ;						// size=0, offset=0
	struct MEMCARD_89fake dsignal;		// size=8, offset=0
	void *mirror;						// size=0, offset=0
	long fogNear;						// size=0, offset=0
	long fogFar;						// size=0, offset=0
	struct MEMCARD_90fake gotoFrame;	// size=8, offset=0
	struct MEMCARD_91fake changeModel;  // size=8, offset=0
	void *vmObject;						// size=0, offset=0
	struct MEMCARD_92fake logic;		// size=8, offset=0
	void *callSignal;					// size=0, offset=0
	struct _SVector offset;				// size=8, offset=0
	struct Signal *gotoLabel;			// size=0, offset=0
	struct Signal *gosubLabel;			// size=0, offset=0
	struct MEMCARD_93fake control;		// size=8, offset=0
	struct MEMCARD_94fake zSignal;		// size=12, offset=0
	struct MEMCARD_95fake StreamLevel;  // size=24, offset=0
	struct MEMCARD_96fake shards;		// size=12, offset=0
	struct MEMCARD_97fake cameraSpline; // size=8, offset=0
	struct MEMCARD_98fake screenWipe;   // size=4, offset=0
	long voiceSitId;					// size=0, offset=0
	struct MEMCARD_99fake introFX;		// size=8, offset=0
	struct MEMCARD_100fake introActive; // size=8, offset=0
	struct MEMCARD_101fake levelChange; // size=18, offset=0
	long blendStart;					// size=0, offset=0
	struct MEMCARD_102fake setTimes;	// size=8, offset=0
	struct MEMCARD_103fake color;		// size=4, offset=0
	struct MEMCARD_104fake print;		// size=12, offset=0
	long slideAngle;					// size=0, offset=0
};

union MEMCARD_106fake // Hashcode: 0xA97273D3 (dec: -1452117037)
{
	struct _HSphere *hsphere; // size=20, offset=0
	struct _HBox *hbox;		  // size=28, offset=0
	struct _HFace *hface;	 // size=12, offset=0
};

union MEMCARD_111fake // Hashcode: 0x505197FF (dec: 1347524607)
{
	struct _VMOffset moveOffsets;		// size=6, offset=0
	struct _VMColorOffset colorOffsets; // size=3, offset=0
};

struct MEMCARD_113fake // hashcode: 0x9D1CF284 (dec: -1659047292)
{
	struct MultiSpline *posSpline;	// size=0, offset=0 //  hashcode: 0x01B23970 (dec: 28457328), parent name: 'MEMCARD_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MultiSpline *targetSpline; // size=0, offset=4 //  hashcode: 0xFE01D007 (dec: -33435641), parent name: 'MEMCARD_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector lastSplinePos;	// size=8, offset=8 //  hashcode: 0xE11C7B9B (dec: -518227045), parent name: 'MEMCARD_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short splinePointAhead;			  // size=0, offset=16 //  hashcode: 0x45C08E86 (dec: 1170247302), parent name: 'MEMCARD_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	short cinema_done;				  // size=0, offset=18 //  hashcode: 0xB5AE3884 (dec: -1246873468), parent name: 'MEMCARD_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_currkey;			  // size=0, offset=20 //  hashcode: 0x1D53DF10 (dec: 492035856), parent name: 'MEMCARD_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	int splinecam_helpkey;			  // size=0, offset=24 //  hashcode: 0x6B10E90C (dec: 1796270348), parent name: 'MEMCARD_113fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_114fake // hashcode: 0x78B33C73 (dec: 2025012339)
{
	struct _Position offset;   // size=6, offset=0 //  hashcode: 0x0420CBA1 (dec: 69258145), parent name: 'MEMCARD_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _Rotation rotation; // size=8, offset=6 //  hashcode: 0xEF87FD9D (dec: -276300387), parent name: 'MEMCARD_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long focusDistance;		   // size=0, offset=16 //  hashcode: 0x4613577E (dec: 1175672702), parent name: 'MEMCARD_114fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_115fake // hashcode: 0xF5DA440C (dec: -170245108)
{
	struct _TFace *tface;				 // size=12, offset=0 //  hashcode: 0x3CB8DC61 (dec: 1018748001), parent name: 'MEMCARD_115fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace;			 // size=12, offset=4 //  hashcode: 0x65BEE458 (dec: 1707009112), parent name: 'MEMCARD_115fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldTargetRot;		 // size=8, offset=8 //  hashcode: 0x02BF9DE0 (dec: 46112224), parent name: 'MEMCARD_115fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long timer;							 // size=0, offset=16 //  hashcode: 0x29D1DA7C (dec: 701618812), parent name: 'MEMCARD_115fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _SVector oldFocusInstancePos; // size=8, offset=20 //  hashcode: 0x07899EBD (dec: 126459581), parent name: 'MEMCARD_115fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_116fake // hashcode: 0xCEC9822E (dec: -825654738)
{
	long stopTimer;			 // size=0, offset=0 //  hashcode: 0x44475604 (dec: 1145525764), parent name: 'MEMCARD_116fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long stopHit;			 // size=0, offset=4 //  hashcode: 0x4B122CDA (dec: 1259482330), parent name: 'MEMCARD_116fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *tface;	// size=12, offset=8 //  hashcode: 0x39777EC0 (dec: 964132544), parent name: 'MEMCARD_116fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct _TFace *oldTFace; // size=12, offset=12 //  hashcode: 0xC21B5705 (dec: -1038395643), parent name: 'MEMCARD_116fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	long hit;				 // size=0, offset=16 //  hashcode: 0x769FA67B (dec: 1990174331), parent name: 'MEMCARD_116fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct MEMCARD_117fake // hashcode: 0x86F561E0 (dec: -2030738976)
{
	struct MEMCARD_113fake Cinematic; // size=28, offset=0 //  hashcode: 0x858B53B9 (dec: -2054466631), parent name: 'MEMCARD_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MEMCARD_114fake Idle;	  // size=20, offset=28 //  hashcode: 0x7DC5ABED (dec: 2110106605), parent name: 'MEMCARD_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MEMCARD_115fake Behind;	// size=28, offset=48 //  hashcode: 0xD869579E (dec: -664184930), parent name: 'MEMCARD_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct MEMCARD_116fake Follow;	// size=20, offset=76 //  hashcode: 0xF9A1F6BB (dec: -106826053), parent name: 'MEMCARD_117fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

struct memcard_t // hashcode: 0xAEC9A344 (dec: -1362517180)
{
	struct Object *object;		  // size=76, offset=0 //  hashcode: 0x52F053A5 (dec: 1391481765), parent name: 'memcard_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct mcmenu_table_t *table; // size=36, offset=4 //  hashcode: 0xA27783F8 (dec: -1569225736), parent name: 'memcard_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct mcmenu_t *mcmenu;	  // size=404, offset=8 //  hashcode: 0x6BCDC33C (dec: 1808646972), parent name: 'memcard_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	short running;				  // size=0, offset=12 //  hashcode: 0x4C561044 (dec: 1280708676), parent name: 'memcard_t', parent hashcode: 0xFFFFFFFF (dec: -1)
	short wrongVerison;			  // size=0, offset=14 //  hashcode: 0x652C8807 (dec: 1697417223), parent name: 'memcard_t', parent hashcode: 0xFFFFFFFF (dec: -1)
};

union MEMCARD_196fake // Hashcode: 0xF7F7C377 (dec: -134757513)
{
	struct _Instance *target;	 // size=616, offset=0
	struct _Position position;	// size=6, offset=0
	struct _Rotation direction;   // size=8, offset=0
	struct _Position throwVector; // size=6, offset=0
};

struct MEMCARD_216fake // hashcode: 0x1C10213E (dec: 470819134)
{
	struct mcmenu_t dummy1; // size=404, offset=0 //  hashcode: 0x94317DB6 (dec: -1808695882), parent name: 'MEMCARD_216fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct mcard_t dummy2;  // size=52, offset=404 //  hashcode: 0xE47D376E (dec: -461555858), parent name: 'MEMCARD_216fake', parent hashcode: 0xFFFFFFFF (dec: -1)
	struct mcpsx_t dummy3;  // size=56, offset=456 //  hashcode: 0x13EC5AA0 (dec: 334256800), parent name: 'MEMCARD_216fake', parent hashcode: 0xFFFFFFFF (dec: -1)
};

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

extern int MEMCARD_IsWrongVersion(struct memcard_t *memcard); // 0x800B9924

extern void load(struct memcard_t *memcard); // 0x800B9938

extern void unload(struct memcard_t *memcard); // 0x800B9A04

extern int memcard_data_size(); // 0x800B9A58

extern int memcard_initialize(struct memcard_t *memcard, void *gt, int nblocks, void *buffer, int nbytes); // 0x800B9A60

extern void memcard_end(struct memcard_t *memcard); // 0x800B9B20

extern int maybe_start(struct memcard_t *memcard); // 0x800B9B64

extern int memcard_main_menu(void *gt, int index); // 0x800B9BD0

extern int memcard_pause_menu(void *gt, int index); // 0x800B9C24

extern void *gt2mcmenu(void *gt); // 0x800B9C78

extern void memcard_pop(void *opaque); // 0x800B9C8C

extern void memcard_start(void *opaque); // 0x800B9CC8

extern void memcard_load(void *opaque); // 0x800B9D0C

extern void memcard_save(void *opaque); // 0x800B9D58

extern void memcard_item(void *opaque, TDRFuncPtr_memcard_item1fn fn, long parameter, long flags, char *text); // 0x800B9D78

typedef int (*TDRFuncPtr_memcard_item1fn)();

#endif
