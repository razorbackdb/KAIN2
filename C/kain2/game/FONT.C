#include "THISDUST.H"
#include "FONT.H"

// char @0x800C8620, len = 0x00000001
charMap = 0x00;
// _BlockVramEntry * @0x800D05E4, len = 0x00000004
FONT_vramBlock = null;
// FontPos[72] @0x800C8500, len = 0x00000120
fontPos =
	{
		// FontPos @0x800C8500, len = 0x00000004
		{
			// char @0x800C8500, len = 0x00000001
			.x = 0x00,
			// char @0x800C8501, len = 0x00000001
			.y = 0x00,
			// char @0x800C8502, len = 0x00000001
			.w = 0x0B,
			// char @0x800C8503, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C8504, len = 0x00000004
		{
			// char @0x800C8504, len = 0x00000001
			.x = 0x0B,
			// char @0x800C8505, len = 0x00000001
			.y = 0x00,
			// char @0x800C8506, len = 0x00000001
			.w = 0x08,
			// char @0x800C8507, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C8508, len = 0x00000004
		{
			// char @0x800C8508, len = 0x00000001
			.x = 0x14,
			// char @0x800C8509, len = 0x00000001
			.y = 0x00,
			// char @0x800C850A, len = 0x00000001
			.w = 0x08,
			// char @0x800C850B, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C850C, len = 0x00000004
		{
			// char @0x800C850C, len = 0x00000001
			.x = 0x1C,
			// char @0x800C850D, len = 0x00000001
			.y = 0x00,
			// char @0x800C850E, len = 0x00000001
			.w = 0x09,
			// char @0x800C850F, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C8510, len = 0x00000004
		{
			// char @0x800C8510, len = 0x00000001
			.x = 0x25,
			// char @0x800C8511, len = 0x00000001
			.y = 0x00,
			// char @0x800C8512, len = 0x00000001
			.w = 0x08,
			// char @0x800C8513, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C8514, len = 0x00000004
		{
			// char @0x800C8514, len = 0x00000001
			.x = 0x2D,
			// char @0x800C8515, len = 0x00000001
			.y = 0x00,
			// char @0x800C8516, len = 0x00000001
			.w = 0x08,
			// char @0x800C8517, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C8518, len = 0x00000004
		{
			// char @0x800C8518, len = 0x00000001
			.x = 0x35,
			// char @0x800C8519, len = 0x00000001
			.y = 0x00,
			// char @0x800C851A, len = 0x00000001
			.w = 0x0A,
			// char @0x800C851B, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C851C, len = 0x00000004
		{
			// char @0x800C851C, len = 0x00000001
			.x = 0x00,
			// char @0x800C851D, len = 0x00000001
			.y = 0x0C,
			// char @0x800C851E, len = 0x00000001
			.w = 0x09,
			// char @0x800C851F, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C8520, len = 0x00000004
		{
			// char @0x800C8520, len = 0x00000001
			.x = 0x09,
			// char @0x800C8521, len = 0x00000001
			.y = 0x0C,
			// char @0x800C8522, len = 0x00000001
			.w = 0x03,
			// char @0x800C8523, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C8524, len = 0x00000004
		{
			// char @0x800C8524, len = 0x00000001
			.x = 0x2A,
			// char @0x800C8525, len = 0x00000001
			.y = 0x0C,
			// char @0x800C8526, len = 0x00000001
			.w = 0x05,
			// char @0x800C8527, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C8528, len = 0x00000004
		{
			// char @0x800C8528, len = 0x00000001
			.x = 0x2F,
			// char @0x800C8529, len = 0x00000001
			.y = 0x0D,
			// char @0x800C852A, len = 0x00000001
			.w = 0x08,
			// char @0x800C852B, len = 0x00000001
			.h = 0x0B},
		// FontPos @0x800C852C, len = 0x00000004
		{
			// char @0x800C852C, len = 0x00000001
			.x = 0x01,
			// char @0x800C852D, len = 0x00000001
			.y = 0x6F,
			// char @0x800C852E, len = 0x00000001
			.w = 0x07,
			// char @0x800C852F, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C8530, len = 0x00000004
		{
			// char @0x800C8530, len = 0x00000001
			.x = 0x00,
			// char @0x800C8531, len = 0x00000001
			.y = 0x1A,
			// char @0x800C8532, len = 0x00000001
			.w = 0x0A,
			// char @0x800C8533, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C8534, len = 0x00000004
		{
			// char @0x800C8534, len = 0x00000001
			.x = 0x0B,
			// char @0x800C8535, len = 0x00000001
			.y = 0x1A,
			// char @0x800C8536, len = 0x00000001
			.w = 0x08,
			// char @0x800C8537, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C8538, len = 0x00000004
		{
			// char @0x800C8538, len = 0x00000001
			.x = 0x13,
			// char @0x800C8539, len = 0x00000001
			.y = 0x1A,
			// char @0x800C853A, len = 0x00000001
			.w = 0x0A,
			// char @0x800C853B, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C853C, len = 0x00000004
		{
			// char @0x800C853C, len = 0x00000001
			.x = 0x1D,
			// char @0x800C853D, len = 0x00000001
			.y = 0x1A,
			// char @0x800C853E, len = 0x00000001
			.w = 0x07,
			// char @0x800C853F, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C8540, len = 0x00000004
		{
			// char @0x800C8540, len = 0x00000001
			.x = 0x2E,
			// char @0x800C8541, len = 0x00000001
			.y = 0x1A,
			// char @0x800C8542, len = 0x00000001
			.w = 0x08,
			// char @0x800C8543, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C8544, len = 0x00000004
		{
			// char @0x800C8544, len = 0x00000001
			.x = 0x00,
			// char @0x800C8545, len = 0x00000001
			.y = 0x27,
			// char @0x800C8546, len = 0x00000001
			.w = 0x09,
			// char @0x800C8547, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C8548, len = 0x00000004
		{
			// char @0x800C8548, len = 0x00000001
			.x = 0x0A,
			// char @0x800C8549, len = 0x00000001
			.y = 0x27,
			// char @0x800C854A, len = 0x00000001
			.w = 0x09,
			// char @0x800C854B, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C854C, len = 0x00000004
		{
			// char @0x800C854C, len = 0x00000001
			.x = 0x13,
			// char @0x800C854D, len = 0x00000001
			.y = 0x27,
			// char @0x800C854E, len = 0x00000001
			.w = 0x08,
			// char @0x800C854F, len = 0x00000001
			.h = 0x0B},
		// FontPos @0x800C8550, len = 0x00000004
		{
			// char @0x800C8550, len = 0x00000001
			.x = 0x1B,
			// char @0x800C8551, len = 0x00000001
			.y = 0x27,
			// char @0x800C8552, len = 0x00000001
			.w = 0x09,
			// char @0x800C8553, len = 0x00000001
			.h = 0x0B},
		// FontPos @0x800C8554, len = 0x00000004
		{
			// char @0x800C8554, len = 0x00000001
			.x = 0x25,
			// char @0x800C8555, len = 0x00000001
			.y = 0x27,
			// char @0x800C8556, len = 0x00000001
			.w = 0x0A,
			// char @0x800C8557, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C8558, len = 0x00000004
		{
			// char @0x800C8558, len = 0x00000001
			.x = 0x2F,
			// char @0x800C8559, len = 0x00000001
			.y = 0x27,
			// char @0x800C855A, len = 0x00000001
			.w = 0x08,
			// char @0x800C855B, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C855C, len = 0x00000004
		{
			// char @0x800C855C, len = 0x00000001
			.x = 0x01,
			// char @0x800C855D, len = 0x00000001
			.y = 0x33,
			// char @0x800C855E, len = 0x00000001
			.w = 0x09,
			// char @0x800C855F, len = 0x00000001
			.h = 0x0D},
		// FontPos @0x800C8560, len = 0x00000004
		{
			// char @0x800C8560, len = 0x00000001
			.x = 0x0A,
			// char @0x800C8561, len = 0x00000001
			.y = 0x33,
			// char @0x800C8562, len = 0x00000001
			.w = 0x08,
			// char @0x800C8563, len = 0x00000001
			.h = 0x0D},
		// FontPos @0x800C8564, len = 0x00000004
		{
			// char @0x800C8564, len = 0x00000001
			.x = 0x12,
			// char @0x800C8565, len = 0x00000001
			.y = 0x33,
			// char @0x800C8566, len = 0x00000001
			.w = 0x08,
			// char @0x800C8567, len = 0x00000001
			.h = 0x0D},
		// FontPos @0x800C8568, len = 0x00000004
		{
			// char @0x800C8568, len = 0x00000001
			.x = 0x1B,
			// char @0x800C8569, len = 0x00000001
			.y = 0x33,
			// char @0x800C856A, len = 0x00000001
			.w = 0x07,
			// char @0x800C856B, len = 0x00000001
			.h = 0x0D},
		// FontPos @0x800C856C, len = 0x00000004
		{
			// char @0x800C856C, len = 0x00000001
			.x = 0x23,
			// char @0x800C856D, len = 0x00000001
			.y = 0x33,
			// char @0x800C856E, len = 0x00000001
			.w = 0x08,
			// char @0x800C856F, len = 0x00000001
			.h = 0x0D},
		// FontPos @0x800C8570, len = 0x00000004
		{
			// char @0x800C8570, len = 0x00000001
			.x = 0x2C,
			// char @0x800C8571, len = 0x00000001
			.y = 0x33,
			// char @0x800C8572, len = 0x00000001
			.w = 0x07,
			// char @0x800C8573, len = 0x00000001
			.h = 0x0D},
		// FontPos @0x800C8574, len = 0x00000004
		{
			// char @0x800C8574, len = 0x00000001
			.x = 0x34,
			// char @0x800C8575, len = 0x00000001
			.y = 0x33,
			// char @0x800C8576, len = 0x00000001
			.w = 0x07,
			// char @0x800C8577, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C8578, len = 0x00000004
		{
			// char @0x800C8578, len = 0x00000001
			.x = 0x0C,
			// char @0x800C8579, len = 0x00000001
			.y = 0x0C,
			// char @0x800C857A, len = 0x00000001
			.w = 0x08,
			// char @0x800C857B, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C857C, len = 0x00000004
		{
			// char @0x800C857C, len = 0x00000001
			.x = 0x14,
			// char @0x800C857D, len = 0x00000001
			.y = 0x0C,
			// char @0x800C857E, len = 0x00000001
			.w = 0x07,
			// char @0x800C857F, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C8580, len = 0x00000004
		{
			// char @0x800C8580, len = 0x00000001
			.x = 0x21,
			// char @0x800C8581, len = 0x00000001
			.y = 0x0C,
			// char @0x800C8582, len = 0x00000001
			.w = 0x07,
			// char @0x800C8583, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C8584, len = 0x00000004
		{
			// char @0x800C8584, len = 0x00000001
			.x = 0x3D,
			// char @0x800C8585, len = 0x00000001
			.y = 0x20,
			// char @0x800C8586, len = 0x00000001
			.w = 0x03,
			// char @0x800C8587, len = 0x00000001
			.h = 0x03},
		// FontPos @0x800C8588, len = 0x00000004
		{
			// char @0x800C8588, len = 0x00000001
			.x = 0x3D,
			// char @0x800C8589, len = 0x00000001
			.y = 0x33,
			// char @0x800C858A, len = 0x00000001
			.w = 0x02,
			// char @0x800C858B, len = 0x00000001
			.h = 0x0D},
		// FontPos @0x800C858C, len = 0x00000004
		{
			// char @0x800C858C, len = 0x00000001
			.x = 0x36,
			// char @0x800C858D, len = 0x00000001
			.y = 0x19,
			// char @0x800C858E, len = 0x00000001
			.w = 0x07,
			// char @0x800C858F, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C8590, len = 0x00000004
		{
			// char @0x800C8590, len = 0x00000001
			.x = 0x30,
			// char @0x800C8591, len = 0x00000001
			.y = 0x05,
			// char @0x800C8592, len = 0x00000001
			.w = 0x05,
			// char @0x800C8593, len = 0x00000001
			.h = 0x07},
		// FontPos @0x800C8594, len = 0x00000004
		{
			// char @0x800C8594, len = 0x00000001
			.x = 0x1B,
			// char @0x800C8595, len = 0x00000001
			.y = 0x0C,
			// char @0x800C8596, len = 0x00000001
			.w = 0x05,
			// char @0x800C8597, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C8598, len = 0x00000004
		{
			// char @0x800C8598, len = 0x00000001
			.x = 0x39,
			// char @0x800C8599, len = 0x00000001
			.y = 0x27,
			// char @0x800C859A, len = 0x00000001
			.w = 0x06,
			// char @0x800C859B, len = 0x00000001
			.h = 0x0B},
		// FontPos @0x800C859C, len = 0x00000004
		{
			// char @0x800C859C, len = 0x00000001
			.x = 0x3D,
			// char @0x800C859D, len = 0x00000001
			.y = 0x1A,
			// char @0x800C859E, len = 0x00000001
			.w = 0x03,
			// char @0x800C859F, len = 0x00000001
			.h = 0x0A},
		// FontPos @0x800C85A0, len = 0x00000004
		{
			// char @0x800C85A0, len = 0x00000001
			.x = 0x13,
			// char @0x800C85A1, len = 0x00000001
			.y = 0x1A,
			// char @0x800C85A2, len = 0x00000001
			.w = 0x05,
			// char @0x800C85A3, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C85A4, len = 0x00000004
		{
			// char @0x800C85A4, len = 0x00000001
			.x = 0x18,
			// char @0x800C85A5, len = 0x00000001
			.y = 0x1A,
			// char @0x800C85A6, len = 0x00000001
			.w = 0x05,
			// char @0x800C85A7, len = 0x00000001
			.h = 0x0B},
		// FontPos @0x800C85A8, len = 0x00000004
		{
			// char @0x800C85A8, len = 0x00000001
			.x = 0x10,
			// char @0x800C85A9, len = 0x00000001
			.y = 0x64,
			// char @0x800C85AA, len = 0x00000001
			.w = 0x07,
			// char @0x800C85AB, len = 0x00000001
			.h = 0x0A},
		// FontPos @0x800C85AC, len = 0x00000004
		{
			// char @0x800C85AC, len = 0x00000001
			.x = 0x31,
			// char @0x800C85AD, len = 0x00000001
			.y = 0x66,
			// char @0x800C85AE, len = 0x00000001
			.w = 0x08,
			// char @0x800C85AF, len = 0x00000001
			.h = 0x07},
		// FontPos @0x800C85B0, len = 0x00000004
		{
			// char @0x800C85B0, len = 0x00000001
			.x = 0x31,
			// char @0x800C85B1, len = 0x00000001
			.y = 0x25,
			// char @0x800C85B2, len = 0x00000001
			.w = 0x05,
			// char @0x800C85B3, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C85B4, len = 0x00000004
		{
			// char @0x800C85B4, len = 0x00000001
			.x = 0x20,
			// char @0x800C85B5, len = 0x00000001
			.y = 0x40,
			// char @0x800C85B6, len = 0x00000001
			.w = 0x07,
			// char @0x800C85B7, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C85B8, len = 0x00000004
		{
			// char @0x800C85B8, len = 0x00000001
			.x = 0x24,
			// char @0x800C85B9, len = 0x00000001
			.y = 0x19,
			// char @0x800C85BA, len = 0x00000001
			.w = 0x09,
			// char @0x800C85BB, len = 0x00000001
			.h = 0x05},
		// FontPos @0x800C85BC, len = 0x00000004
		{
			// char @0x800C85BC, len = 0x00000001
			.x = 0x14,
			// char @0x800C85BD, len = 0x00000001
			.y = 0x46,
			// char @0x800C85BE, len = 0x00000001
			.w = 0x05,
			// char @0x800C85BF, len = 0x00000001
			.h = 0x04},
		// FontPos @0x800C85C0, len = 0x00000004
		{
			// char @0x800C85C0, len = 0x00000001
			.x = 0x00,
			// char @0x800C85C1, len = 0x00000001
			.y = 0x40,
			// char @0x800C85C2, len = 0x00000001
			.w = 0x08,
			// char @0x800C85C3, len = 0x00000001
			.h = 0x0A},
		// FontPos @0x800C85C4, len = 0x00000004
		{
			// char @0x800C85C4, len = 0x00000001
			.x = 0x28,
			// char @0x800C85C5, len = 0x00000001
			.y = 0x40,
			// char @0x800C85C6, len = 0x00000001
			.w = 0x07,
			// char @0x800C85C7, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C85C8, len = 0x00000004
		{
			// char @0x800C85C8, len = 0x00000001
			.x = 0x3D,
			// char @0x800C85C9, len = 0x00000001
			.y = 0x33,
			// char @0x800C85CA, len = 0x00000001
			.w = 0x02,
			// char @0x800C85CB, len = 0x00000001
			.h = 0xF3},
		// FontPos @0x800C85CC, len = 0x00000004
		{
			// char @0x800C85CC, len = 0x00000001
			.x = 0x25,
			// char @0x800C85CD, len = 0x00000001
			.y = 0x1E,
			// char @0x800C85CE, len = 0x00000001
			.w = 0x08,
			// char @0x800C85CF, len = 0x00000001
			.h = 0x02},
		// FontPos @0x800C85D0, len = 0x00000004
		{
			// char @0x800C85D0, len = 0x00000001
			.x = 0x12,
			// char @0x800C85D1, len = 0x00000001
			.y = 0x40,
			// char @0x800C85D2, len = 0x00000001
			.w = 0x07,
			// char @0x800C85D3, len = 0x00000001
			.h = 0x04},
		// FontPos @0x800C85D4, len = 0x00000004
		{
			// char @0x800C85D4, len = 0x00000001
			.x = 0x0A,
			// char @0x800C85D5, len = 0x00000001
			.y = 0x40,
			// char @0x800C85D6, len = 0x00000001
			.w = 0x06,
			// char @0x800C85D7, len = 0x00000001
			.h = 0x05},
		// FontPos @0x800C85D8, len = 0x00000004
		{
			// char @0x800C85D8, len = 0x00000001
			.x = 0x0A,
			// char @0x800C85D9, len = 0x00000001
			.y = 0x46,
			// char @0x800C85DA, len = 0x00000001
			.w = 0x06,
			// char @0x800C85DB, len = 0x00000001
			.h = 0x05},
		// FontPos @0x800C85DC, len = 0x00000004
		{
			// char @0x800C85DC, len = 0x00000001
			.x = 0x24,
			// char @0x800C85DD, len = 0x00000001
			.y = 0x19,
			// char @0x800C85DE, len = 0x00000001
			.w = 0x08,
			// char @0x800C85DF, len = 0x00000001
			.h = 0x04},
		// FontPos @0x800C85E0, len = 0x00000004
		{
			// char @0x800C85E0, len = 0x00000001
			.x = 0x1B,
			// char @0x800C85E1, len = 0x00000001
			.y = 0x47,
			// char @0x800C85E2, len = 0x00000001
			.w = 0x05,
			// char @0x800C85E3, len = 0x00000001
			.h = 0x04},
		// FontPos @0x800C85E4, len = 0x00000004
		{
			// char @0x800C85E4, len = 0x00000001
			.x = 0x2F,
			// char @0x800C85E5, len = 0x00000001
			.y = 0x40,
			// char @0x800C85E6, len = 0x00000001
			.w = 0x0B,
			// char @0x800C85E7, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C85E8, len = 0x00000004
		{
			// char @0x800C85E8, len = 0x00000001
			.x = 0x00,
			// char @0x800C85E9, len = 0x00000001
			.y = 0x4D,
			// char @0x800C85EA, len = 0x00000001
			.w = 0x0C,
			// char @0x800C85EB, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C85EC, len = 0x00000004
		{
			// char @0x800C85EC, len = 0x00000001
			.x = 0x0C,
			// char @0x800C85ED, len = 0x00000001
			.y = 0x4D,
			// char @0x800C85EE, len = 0x00000001
			.w = 0x0C,
			// char @0x800C85EF, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C85F0, len = 0x00000004
		{
			// char @0x800C85F0, len = 0x00000001
			.x = 0x18,
			// char @0x800C85F1, len = 0x00000001
			.y = 0x4D,
			// char @0x800C85F2, len = 0x00000001
			.w = 0x0C,
			// char @0x800C85F3, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C85F4, len = 0x00000004
		{
			// char @0x800C85F4, len = 0x00000001
			.x = 0x24,
			// char @0x800C85F5, len = 0x00000001
			.y = 0x4D,
			// char @0x800C85F6, len = 0x00000001
			.w = 0x0C,
			// char @0x800C85F7, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C85F8, len = 0x00000004
		{
			// char @0x800C85F8, len = 0x00000001
			.x = 0x30,
			// char @0x800C85F9, len = 0x00000001
			.y = 0x4D,
			// char @0x800C85FA, len = 0x00000001
			.w = 0x0A,
			// char @0x800C85FB, len = 0x00000001
			.h = 0x0C},
		// FontPos @0x800C85FC, len = 0x00000004
		{
			// char @0x800C85FC, len = 0x00000001
			.x = 0x30,
			// char @0x800C85FD, len = 0x00000001
			.y = 0x4B,
			// char @0x800C85FE, len = 0x00000001
			.w = 0x0A,
			// char @0x800C85FF, len = 0x00000001
			.h = 0xF4},
		// FontPos @0x800C8600, len = 0x00000004
		{
			// char @0x800C8600, len = 0x00000001
			.x = 0x00,
			// char @0x800C8601, len = 0x00000001
			.y = 0x59,
			// char @0x800C8602, len = 0x00000001
			.w = 0x0C,
			// char @0x800C8603, len = 0x00000001
			.h = 0x0B},
		// FontPos @0x800C8604, len = 0x00000004
		{
			// char @0x800C8604, len = 0x00000001
			.x = 0x00,
			// char @0x800C8605, len = 0x00000001
			.y = 0x59,
			// char @0x800C8606, len = 0x00000001
			.w = 0xF4,
			// char @0x800C8607, len = 0x00000001
			.h = 0x0B},
		// FontPos @0x800C8608, len = 0x00000004
		{
			// char @0x800C8608, len = 0x00000001
			.x = 0x0D,
			// char @0x800C8609, len = 0x00000001
			.y = 0x59,
			// char @0x800C860A, len = 0x00000001
			.w = 0x0E,
			// char @0x800C860B, len = 0x00000001
			.h = 0x0B},
		// FontPos @0x800C860C, len = 0x00000004
		{
			// char @0x800C860C, len = 0x00000001
			.x = 0x1C,
			// char @0x800C860D, len = 0x00000001
			.y = 0x59,
			// char @0x800C860E, len = 0x00000001
			.w = 0x0E,
			// char @0x800C860F, len = 0x00000001
			.h = 0x0B},
		// FontPos @0x800C8610, len = 0x00000004
		{
			// char @0x800C8610, len = 0x00000001
			.x = 0x2B,
			// char @0x800C8611, len = 0x00000001
			.y = 0x59,
			// char @0x800C8612, len = 0x00000001
			.w = 0x0E,
			// char @0x800C8613, len = 0x00000001
			.h = 0x0B},
		// FontPos @0x800C8614, len = 0x00000004
		{
			// char @0x800C8614, len = 0x00000001
			.x = 0x01,
			// char @0x800C8615, len = 0x00000001
			.y = 0x64,
			// char @0x800C8616, len = 0x00000001
			.w = 0x0E,
			// char @0x800C8617, len = 0x00000001
			.h = 0x0B},
		// FontPos @0x800C8618, len = 0x00000004
		{
			// char @0x800C8618, len = 0x00000001
			.x = 0x1A,
			// char @0x800C8619, len = 0x00000001
			.y = 0x64,
			// char @0x800C861A, len = 0x00000001
			.w = 0x09,
			// char @0x800C861B, len = 0x00000001
			.h = 0x0B},
		// FontPos @0x800C861C, len = 0x00000004
		{
			// char @0x800C861C, len = 0x00000001
			.x = 0x24,
			// char @0x800C861D, len = 0x00000001
			.y = 0x64,
			// char @0x800C861E, len = 0x00000001
			.w = 0x0C,
			// char @0x800C861F, len = 0x00000001
			.h = 0x0B}};
// FontTracker @0x800D05EC, len = 0x00000620
fontTracker =
	{
		// FontChar[256] @0x800D05EC, len = 0x00000600
		.font_buffer =
			{
				// FontChar @0x800D05EC, len = 0x00000006
				{
					// short @0x800D05EC, len = 0x00000002
					.x = null,
					// short @0x800D05EE, len = 0x00000002
					.y = null,
					// char @0x800D05F0, len = 0x00000001
					.c = 0x00,
					// char @0x800D05F1, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D05F2, len = 0x00000006
				{
					// short @0x800D05F2, len = 0x00000002
					.x = null,
					// short @0x800D05F4, len = 0x00000002
					.y = null,
					// char @0x800D05F6, len = 0x00000001
					.c = 0x00,
					// char @0x800D05F7, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D05F8, len = 0x00000006
				{
					// short @0x800D05F8, len = 0x00000002
					.x = null,
					// short @0x800D05FA, len = 0x00000002
					.y = null,
					// char @0x800D05FC, len = 0x00000001
					.c = 0x00,
					// char @0x800D05FD, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D05FE, len = 0x00000006
				{
					// short @0x800D05FE, len = 0x00000002
					.x = null,
					// short @0x800D0600, len = 0x00000002
					.y = null,
					// char @0x800D0602, len = 0x00000001
					.c = 0x00,
					// char @0x800D0603, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0604, len = 0x00000006
				{
					// short @0x800D0604, len = 0x00000002
					.x = null,
					// short @0x800D0606, len = 0x00000002
					.y = null,
					// char @0x800D0608, len = 0x00000001
					.c = 0x00,
					// char @0x800D0609, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D060A, len = 0x00000006
				{
					// short @0x800D060A, len = 0x00000002
					.x = null,
					// short @0x800D060C, len = 0x00000002
					.y = null,
					// char @0x800D060E, len = 0x00000001
					.c = 0x00,
					// char @0x800D060F, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0610, len = 0x00000006
				{
					// short @0x800D0610, len = 0x00000002
					.x = null,
					// short @0x800D0612, len = 0x00000002
					.y = null,
					// char @0x800D0614, len = 0x00000001
					.c = 0x00,
					// char @0x800D0615, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0616, len = 0x00000006
				{
					// short @0x800D0616, len = 0x00000002
					.x = null,
					// short @0x800D0618, len = 0x00000002
					.y = null,
					// char @0x800D061A, len = 0x00000001
					.c = 0x00,
					// char @0x800D061B, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D061C, len = 0x00000006
				{
					// short @0x800D061C, len = 0x00000002
					.x = null,
					// short @0x800D061E, len = 0x00000002
					.y = null,
					// char @0x800D0620, len = 0x00000001
					.c = 0x00,
					// char @0x800D0621, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0622, len = 0x00000006
				{
					// short @0x800D0622, len = 0x00000002
					.x = null,
					// short @0x800D0624, len = 0x00000002
					.y = null,
					// char @0x800D0626, len = 0x00000001
					.c = 0x00,
					// char @0x800D0627, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0628, len = 0x00000006
				{
					// short @0x800D0628, len = 0x00000002
					.x = null,
					// short @0x800D062A, len = 0x00000002
					.y = null,
					// char @0x800D062C, len = 0x00000001
					.c = 0x00,
					// char @0x800D062D, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D062E, len = 0x00000006
				{
					// short @0x800D062E, len = 0x00000002
					.x = null,
					// short @0x800D0630, len = 0x00000002
					.y = null,
					// char @0x800D0632, len = 0x00000001
					.c = 0x00,
					// char @0x800D0633, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0634, len = 0x00000006
				{
					// short @0x800D0634, len = 0x00000002
					.x = null,
					// short @0x800D0636, len = 0x00000002
					.y = null,
					// char @0x800D0638, len = 0x00000001
					.c = 0x00,
					// char @0x800D0639, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D063A, len = 0x00000006
				{
					// short @0x800D063A, len = 0x00000002
					.x = null,
					// short @0x800D063C, len = 0x00000002
					.y = null,
					// char @0x800D063E, len = 0x00000001
					.c = 0x00,
					// char @0x800D063F, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0640, len = 0x00000006
				{
					// short @0x800D0640, len = 0x00000002
					.x = null,
					// short @0x800D0642, len = 0x00000002
					.y = null,
					// char @0x800D0644, len = 0x00000001
					.c = 0x00,
					// char @0x800D0645, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0646, len = 0x00000006
				{
					// short @0x800D0646, len = 0x00000002
					.x = null,
					// short @0x800D0648, len = 0x00000002
					.y = null,
					// char @0x800D064A, len = 0x00000001
					.c = 0x00,
					// char @0x800D064B, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D064C, len = 0x00000006
				{
					// short @0x800D064C, len = 0x00000002
					.x = null,
					// short @0x800D064E, len = 0x00000002
					.y = null,
					// char @0x800D0650, len = 0x00000001
					.c = 0x00,
					// char @0x800D0651, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0652, len = 0x00000006
				{
					// short @0x800D0652, len = 0x00000002
					.x = null,
					// short @0x800D0654, len = 0x00000002
					.y = null,
					// char @0x800D0656, len = 0x00000001
					.c = 0x00,
					// char @0x800D0657, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0658, len = 0x00000006
				{
					// short @0x800D0658, len = 0x00000002
					.x = null,
					// short @0x800D065A, len = 0x00000002
					.y = null,
					// char @0x800D065C, len = 0x00000001
					.c = 0x00,
					// char @0x800D065D, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D065E, len = 0x00000006
				{
					// short @0x800D065E, len = 0x00000002
					.x = null,
					// short @0x800D0660, len = 0x00000002
					.y = null,
					// char @0x800D0662, len = 0x00000001
					.c = 0x00,
					// char @0x800D0663, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0664, len = 0x00000006
				{
					// short @0x800D0664, len = 0x00000002
					.x = null,
					// short @0x800D0666, len = 0x00000002
					.y = null,
					// char @0x800D0668, len = 0x00000001
					.c = 0x00,
					// char @0x800D0669, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D066A, len = 0x00000006
				{
					// short @0x800D066A, len = 0x00000002
					.x = null,
					// short @0x800D066C, len = 0x00000002
					.y = null,
					// char @0x800D066E, len = 0x00000001
					.c = 0x00,
					// char @0x800D066F, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0670, len = 0x00000006
				{
					// short @0x800D0670, len = 0x00000002
					.x = null,
					// short @0x800D0672, len = 0x00000002
					.y = null,
					// char @0x800D0674, len = 0x00000001
					.c = 0x00,
					// char @0x800D0675, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0676, len = 0x00000006
				{
					// short @0x800D0676, len = 0x00000002
					.x = null,
					// short @0x800D0678, len = 0x00000002
					.y = null,
					// char @0x800D067A, len = 0x00000001
					.c = 0x00,
					// char @0x800D067B, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D067C, len = 0x00000006
				{
					// short @0x800D067C, len = 0x00000002
					.x = null,
					// short @0x800D067E, len = 0x00000002
					.y = null,
					// char @0x800D0680, len = 0x00000001
					.c = 0x00,
					// char @0x800D0681, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0682, len = 0x00000006
				{
					// short @0x800D0682, len = 0x00000002
					.x = null,
					// short @0x800D0684, len = 0x00000002
					.y = null,
					// char @0x800D0686, len = 0x00000001
					.c = 0x00,
					// char @0x800D0687, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0688, len = 0x00000006
				{
					// short @0x800D0688, len = 0x00000002
					.x = null,
					// short @0x800D068A, len = 0x00000002
					.y = null,
					// char @0x800D068C, len = 0x00000001
					.c = 0x00,
					// char @0x800D068D, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D068E, len = 0x00000006
				{
					// short @0x800D068E, len = 0x00000002
					.x = null,
					// short @0x800D0690, len = 0x00000002
					.y = null,
					// char @0x800D0692, len = 0x00000001
					.c = 0x00,
					// char @0x800D0693, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0694, len = 0x00000006
				{
					// short @0x800D0694, len = 0x00000002
					.x = null,
					// short @0x800D0696, len = 0x00000002
					.y = null,
					// char @0x800D0698, len = 0x00000001
					.c = 0x00,
					// char @0x800D0699, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D069A, len = 0x00000006
				{
					// short @0x800D069A, len = 0x00000002
					.x = null,
					// short @0x800D069C, len = 0x00000002
					.y = null,
					// char @0x800D069E, len = 0x00000001
					.c = 0x00,
					// char @0x800D069F, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D06A0, len = 0x00000006
				{
					// short @0x800D06A0, len = 0x00000002
					.x = null,
					// short @0x800D06A2, len = 0x00000002
					.y = null,
					// char @0x800D06A4, len = 0x00000001
					.c = 0x00,
					// char @0x800D06A5, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D06A6, len = 0x00000006
				{
					// short @0x800D06A6, len = 0x00000002
					.x = null,
					// short @0x800D06A8, len = 0x00000002
					.y = null,
					// char @0x800D06AA, len = 0x00000001
					.c = 0x00,
					// char @0x800D06AB, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D06AC, len = 0x00000006
				{
					// short @0x800D06AC, len = 0x00000002
					.x = null,
					// short @0x800D06AE, len = 0x00000002
					.y = null,
					// char @0x800D06B0, len = 0x00000001
					.c = 0x00,
					// char @0x800D06B1, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D06B2, len = 0x00000006
				{
					// short @0x800D06B2, len = 0x00000002
					.x = null,
					// short @0x800D06B4, len = 0x00000002
					.y = null,
					// char @0x800D06B6, len = 0x00000001
					.c = 0x00,
					// char @0x800D06B7, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D06B8, len = 0x00000006
				{
					// short @0x800D06B8, len = 0x00000002
					.x = null,
					// short @0x800D06BA, len = 0x00000002
					.y = null,
					// char @0x800D06BC, len = 0x00000001
					.c = 0x00,
					// char @0x800D06BD, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D06BE, len = 0x00000006
				{
					// short @0x800D06BE, len = 0x00000002
					.x = null,
					// short @0x800D06C0, len = 0x00000002
					.y = null,
					// char @0x800D06C2, len = 0x00000001
					.c = 0x00,
					// char @0x800D06C3, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D06C4, len = 0x00000006
				{
					// short @0x800D06C4, len = 0x00000002
					.x = null,
					// short @0x800D06C6, len = 0x00000002
					.y = null,
					// char @0x800D06C8, len = 0x00000001
					.c = 0x00,
					// char @0x800D06C9, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D06CA, len = 0x00000006
				{
					// short @0x800D06CA, len = 0x00000002
					.x = null,
					// short @0x800D06CC, len = 0x00000002
					.y = null,
					// char @0x800D06CE, len = 0x00000001
					.c = 0x00,
					// char @0x800D06CF, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D06D0, len = 0x00000006
				{
					// short @0x800D06D0, len = 0x00000002
					.x = null,
					// short @0x800D06D2, len = 0x00000002
					.y = null,
					// char @0x800D06D4, len = 0x00000001
					.c = 0x00,
					// char @0x800D06D5, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D06D6, len = 0x00000006
				{
					// short @0x800D06D6, len = 0x00000002
					.x = null,
					// short @0x800D06D8, len = 0x00000002
					.y = null,
					// char @0x800D06DA, len = 0x00000001
					.c = 0x00,
					// char @0x800D06DB, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D06DC, len = 0x00000006
				{
					// short @0x800D06DC, len = 0x00000002
					.x = null,
					// short @0x800D06DE, len = 0x00000002
					.y = null,
					// char @0x800D06E0, len = 0x00000001
					.c = 0x00,
					// char @0x800D06E1, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D06E2, len = 0x00000006
				{
					// short @0x800D06E2, len = 0x00000002
					.x = null,
					// short @0x800D06E4, len = 0x00000002
					.y = null,
					// char @0x800D06E6, len = 0x00000001
					.c = 0x00,
					// char @0x800D06E7, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D06E8, len = 0x00000006
				{
					// short @0x800D06E8, len = 0x00000002
					.x = null,
					// short @0x800D06EA, len = 0x00000002
					.y = null,
					// char @0x800D06EC, len = 0x00000001
					.c = 0x00,
					// char @0x800D06ED, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D06EE, len = 0x00000006
				{
					// short @0x800D06EE, len = 0x00000002
					.x = null,
					// short @0x800D06F0, len = 0x00000002
					.y = null,
					// char @0x800D06F2, len = 0x00000001
					.c = 0x00,
					// char @0x800D06F3, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D06F4, len = 0x00000006
				{
					// short @0x800D06F4, len = 0x00000002
					.x = null,
					// short @0x800D06F6, len = 0x00000002
					.y = null,
					// char @0x800D06F8, len = 0x00000001
					.c = 0x00,
					// char @0x800D06F9, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D06FA, len = 0x00000006
				{
					// short @0x800D06FA, len = 0x00000002
					.x = null,
					// short @0x800D06FC, len = 0x00000002
					.y = null,
					// char @0x800D06FE, len = 0x00000001
					.c = 0x00,
					// char @0x800D06FF, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0700, len = 0x00000006
				{
					// short @0x800D0700, len = 0x00000002
					.x = null,
					// short @0x800D0702, len = 0x00000002
					.y = null,
					// char @0x800D0704, len = 0x00000001
					.c = 0x00,
					// char @0x800D0705, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0706, len = 0x00000006
				{
					// short @0x800D0706, len = 0x00000002
					.x = null,
					// short @0x800D0708, len = 0x00000002
					.y = null,
					// char @0x800D070A, len = 0x00000001
					.c = 0x00,
					// char @0x800D070B, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D070C, len = 0x00000006
				{
					// short @0x800D070C, len = 0x00000002
					.x = null,
					// short @0x800D070E, len = 0x00000002
					.y = null,
					// char @0x800D0710, len = 0x00000001
					.c = 0x00,
					// char @0x800D0711, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0712, len = 0x00000006
				{
					// short @0x800D0712, len = 0x00000002
					.x = null,
					// short @0x800D0714, len = 0x00000002
					.y = null,
					// char @0x800D0716, len = 0x00000001
					.c = 0x00,
					// char @0x800D0717, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0718, len = 0x00000006
				{
					// short @0x800D0718, len = 0x00000002
					.x = null,
					// short @0x800D071A, len = 0x00000002
					.y = null,
					// char @0x800D071C, len = 0x00000001
					.c = 0x00,
					// char @0x800D071D, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D071E, len = 0x00000006
				{
					// short @0x800D071E, len = 0x00000002
					.x = null,
					// short @0x800D0720, len = 0x00000002
					.y = null,
					// char @0x800D0722, len = 0x00000001
					.c = 0x00,
					// char @0x800D0723, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0724, len = 0x00000006
				{
					// short @0x800D0724, len = 0x00000002
					.x = null,
					// short @0x800D0726, len = 0x00000002
					.y = null,
					// char @0x800D0728, len = 0x00000001
					.c = 0x00,
					// char @0x800D0729, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D072A, len = 0x00000006
				{
					// short @0x800D072A, len = 0x00000002
					.x = null,
					// short @0x800D072C, len = 0x00000002
					.y = null,
					// char @0x800D072E, len = 0x00000001
					.c = 0x00,
					// char @0x800D072F, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0730, len = 0x00000006
				{
					// short @0x800D0730, len = 0x00000002
					.x = null,
					// short @0x800D0732, len = 0x00000002
					.y = null,
					// char @0x800D0734, len = 0x00000001
					.c = 0x00,
					// char @0x800D0735, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0736, len = 0x00000006
				{
					// short @0x800D0736, len = 0x00000002
					.x = null,
					// short @0x800D0738, len = 0x00000002
					.y = null,
					// char @0x800D073A, len = 0x00000001
					.c = 0x00,
					// char @0x800D073B, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D073C, len = 0x00000006
				{
					// short @0x800D073C, len = 0x00000002
					.x = null,
					// short @0x800D073E, len = 0x00000002
					.y = null,
					// char @0x800D0740, len = 0x00000001
					.c = 0x00,
					// char @0x800D0741, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0742, len = 0x00000006
				{
					// short @0x800D0742, len = 0x00000002
					.x = null,
					// short @0x800D0744, len = 0x00000002
					.y = null,
					// char @0x800D0746, len = 0x00000001
					.c = 0x00,
					// char @0x800D0747, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0748, len = 0x00000006
				{
					// short @0x800D0748, len = 0x00000002
					.x = null,
					// short @0x800D074A, len = 0x00000002
					.y = null,
					// char @0x800D074C, len = 0x00000001
					.c = 0x00,
					// char @0x800D074D, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D074E, len = 0x00000006
				{
					// short @0x800D074E, len = 0x00000002
					.x = null,
					// short @0x800D0750, len = 0x00000002
					.y = null,
					// char @0x800D0752, len = 0x00000001
					.c = 0x00,
					// char @0x800D0753, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0754, len = 0x00000006
				{
					// short @0x800D0754, len = 0x00000002
					.x = null,
					// short @0x800D0756, len = 0x00000002
					.y = null,
					// char @0x800D0758, len = 0x00000001
					.c = 0x00,
					// char @0x800D0759, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D075A, len = 0x00000006
				{
					// short @0x800D075A, len = 0x00000002
					.x = null,
					// short @0x800D075C, len = 0x00000002
					.y = null,
					// char @0x800D075E, len = 0x00000001
					.c = 0x00,
					// char @0x800D075F, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0760, len = 0x00000006
				{
					// short @0x800D0760, len = 0x00000002
					.x = null,
					// short @0x800D0762, len = 0x00000002
					.y = null,
					// char @0x800D0764, len = 0x00000001
					.c = 0x00,
					// char @0x800D0765, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0766, len = 0x00000006
				{
					// short @0x800D0766, len = 0x00000002
					.x = null,
					// short @0x800D0768, len = 0x00000002
					.y = null,
					// char @0x800D076A, len = 0x00000001
					.c = 0x00,
					// char @0x800D076B, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D076C, len = 0x00000006
				{
					// short @0x800D076C, len = 0x00000002
					.x = null,
					// short @0x800D076E, len = 0x00000002
					.y = null,
					// char @0x800D0770, len = 0x00000001
					.c = 0x00,
					// char @0x800D0771, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0772, len = 0x00000006
				{
					// short @0x800D0772, len = 0x00000002
					.x = null,
					// short @0x800D0774, len = 0x00000002
					.y = null,
					// char @0x800D0776, len = 0x00000001
					.c = 0x00,
					// char @0x800D0777, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0778, len = 0x00000006
				{
					// short @0x800D0778, len = 0x00000002
					.x = null,
					// short @0x800D077A, len = 0x00000002
					.y = null,
					// char @0x800D077C, len = 0x00000001
					.c = 0x00,
					// char @0x800D077D, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D077E, len = 0x00000006
				{
					// short @0x800D077E, len = 0x00000002
					.x = null,
					// short @0x800D0780, len = 0x00000002
					.y = null,
					// char @0x800D0782, len = 0x00000001
					.c = 0x00,
					// char @0x800D0783, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0784, len = 0x00000006
				{
					// short @0x800D0784, len = 0x00000002
					.x = null,
					// short @0x800D0786, len = 0x00000002
					.y = null,
					// char @0x800D0788, len = 0x00000001
					.c = 0x00,
					// char @0x800D0789, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D078A, len = 0x00000006
				{
					// short @0x800D078A, len = 0x00000002
					.x = null,
					// short @0x800D078C, len = 0x00000002
					.y = null,
					// char @0x800D078E, len = 0x00000001
					.c = 0x00,
					// char @0x800D078F, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0790, len = 0x00000006
				{
					// short @0x800D0790, len = 0x00000002
					.x = null,
					// short @0x800D0792, len = 0x00000002
					.y = null,
					// char @0x800D0794, len = 0x00000001
					.c = 0x00,
					// char @0x800D0795, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0796, len = 0x00000006
				{
					// short @0x800D0796, len = 0x00000002
					.x = null,
					// short @0x800D0798, len = 0x00000002
					.y = null,
					// char @0x800D079A, len = 0x00000001
					.c = 0x00,
					// char @0x800D079B, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D079C, len = 0x00000006
				{
					// short @0x800D079C, len = 0x00000002
					.x = null,
					// short @0x800D079E, len = 0x00000002
					.y = null,
					// char @0x800D07A0, len = 0x00000001
					.c = 0x00,
					// char @0x800D07A1, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D07A2, len = 0x00000006
				{
					// short @0x800D07A2, len = 0x00000002
					.x = null,
					// short @0x800D07A4, len = 0x00000002
					.y = null,
					// char @0x800D07A6, len = 0x00000001
					.c = 0x00,
					// char @0x800D07A7, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D07A8, len = 0x00000006
				{
					// short @0x800D07A8, len = 0x00000002
					.x = null,
					// short @0x800D07AA, len = 0x00000002
					.y = null,
					// char @0x800D07AC, len = 0x00000001
					.c = 0x00,
					// char @0x800D07AD, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D07AE, len = 0x00000006
				{
					// short @0x800D07AE, len = 0x00000002
					.x = null,
					// short @0x800D07B0, len = 0x00000002
					.y = null,
					// char @0x800D07B2, len = 0x00000001
					.c = 0x00,
					// char @0x800D07B3, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D07B4, len = 0x00000006
				{
					// short @0x800D07B4, len = 0x00000002
					.x = null,
					// short @0x800D07B6, len = 0x00000002
					.y = null,
					// char @0x800D07B8, len = 0x00000001
					.c = 0x00,
					// char @0x800D07B9, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D07BA, len = 0x00000006
				{
					// short @0x800D07BA, len = 0x00000002
					.x = null,
					// short @0x800D07BC, len = 0x00000002
					.y = null,
					// char @0x800D07BE, len = 0x00000001
					.c = 0x00,
					// char @0x800D07BF, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D07C0, len = 0x00000006
				{
					// short @0x800D07C0, len = 0x00000002
					.x = null,
					// short @0x800D07C2, len = 0x00000002
					.y = null,
					// char @0x800D07C4, len = 0x00000001
					.c = 0x00,
					// char @0x800D07C5, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D07C6, len = 0x00000006
				{
					// short @0x800D07C6, len = 0x00000002
					.x = null,
					// short @0x800D07C8, len = 0x00000002
					.y = null,
					// char @0x800D07CA, len = 0x00000001
					.c = 0x00,
					// char @0x800D07CB, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D07CC, len = 0x00000006
				{
					// short @0x800D07CC, len = 0x00000002
					.x = null,
					// short @0x800D07CE, len = 0x00000002
					.y = null,
					// char @0x800D07D0, len = 0x00000001
					.c = 0x00,
					// char @0x800D07D1, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D07D2, len = 0x00000006
				{
					// short @0x800D07D2, len = 0x00000002
					.x = null,
					// short @0x800D07D4, len = 0x00000002
					.y = null,
					// char @0x800D07D6, len = 0x00000001
					.c = 0x00,
					// char @0x800D07D7, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D07D8, len = 0x00000006
				{
					// short @0x800D07D8, len = 0x00000002
					.x = null,
					// short @0x800D07DA, len = 0x00000002
					.y = null,
					// char @0x800D07DC, len = 0x00000001
					.c = 0x00,
					// char @0x800D07DD, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D07DE, len = 0x00000006
				{
					// short @0x800D07DE, len = 0x00000002
					.x = null,
					// short @0x800D07E0, len = 0x00000002
					.y = null,
					// char @0x800D07E2, len = 0x00000001
					.c = 0x00,
					// char @0x800D07E3, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D07E4, len = 0x00000006
				{
					// short @0x800D07E4, len = 0x00000002
					.x = null,
					// short @0x800D07E6, len = 0x00000002
					.y = null,
					// char @0x800D07E8, len = 0x00000001
					.c = 0x00,
					// char @0x800D07E9, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D07EA, len = 0x00000006
				{
					// short @0x800D07EA, len = 0x00000002
					.x = null,
					// short @0x800D07EC, len = 0x00000002
					.y = null,
					// char @0x800D07EE, len = 0x00000001
					.c = 0x00,
					// char @0x800D07EF, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D07F0, len = 0x00000006
				{
					// short @0x800D07F0, len = 0x00000002
					.x = null,
					// short @0x800D07F2, len = 0x00000002
					.y = null,
					// char @0x800D07F4, len = 0x00000001
					.c = 0x00,
					// char @0x800D07F5, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D07F6, len = 0x00000006
				{
					// short @0x800D07F6, len = 0x00000002
					.x = null,
					// short @0x800D07F8, len = 0x00000002
					.y = null,
					// char @0x800D07FA, len = 0x00000001
					.c = 0x00,
					// char @0x800D07FB, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D07FC, len = 0x00000006
				{
					// short @0x800D07FC, len = 0x00000002
					.x = null,
					// short @0x800D07FE, len = 0x00000002
					.y = null,
					// char @0x800D0800, len = 0x00000001
					.c = 0x00,
					// char @0x800D0801, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0802, len = 0x00000006
				{
					// short @0x800D0802, len = 0x00000002
					.x = null,
					// short @0x800D0804, len = 0x00000002
					.y = null,
					// char @0x800D0806, len = 0x00000001
					.c = 0x00,
					// char @0x800D0807, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0808, len = 0x00000006
				{
					// short @0x800D0808, len = 0x00000002
					.x = null,
					// short @0x800D080A, len = 0x00000002
					.y = null,
					// char @0x800D080C, len = 0x00000001
					.c = 0x00,
					// char @0x800D080D, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D080E, len = 0x00000006
				{
					// short @0x800D080E, len = 0x00000002
					.x = null,
					// short @0x800D0810, len = 0x00000002
					.y = null,
					// char @0x800D0812, len = 0x00000001
					.c = 0x00,
					// char @0x800D0813, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0814, len = 0x00000006
				{
					// short @0x800D0814, len = 0x00000002
					.x = null,
					// short @0x800D0816, len = 0x00000002
					.y = null,
					// char @0x800D0818, len = 0x00000001
					.c = 0x00,
					// char @0x800D0819, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D081A, len = 0x00000006
				{
					// short @0x800D081A, len = 0x00000002
					.x = null,
					// short @0x800D081C, len = 0x00000002
					.y = null,
					// char @0x800D081E, len = 0x00000001
					.c = 0x00,
					// char @0x800D081F, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0820, len = 0x00000006
				{
					// short @0x800D0820, len = 0x00000002
					.x = null,
					// short @0x800D0822, len = 0x00000002
					.y = null,
					// char @0x800D0824, len = 0x00000001
					.c = 0x00,
					// char @0x800D0825, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0826, len = 0x00000006
				{
					// short @0x800D0826, len = 0x00000002
					.x = null,
					// short @0x800D0828, len = 0x00000002
					.y = null,
					// char @0x800D082A, len = 0x00000001
					.c = 0x00,
					// char @0x800D082B, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D082C, len = 0x00000006
				{
					// short @0x800D082C, len = 0x00000002
					.x = null,
					// short @0x800D082E, len = 0x00000002
					.y = null,
					// char @0x800D0830, len = 0x00000001
					.c = 0x00,
					// char @0x800D0831, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0832, len = 0x00000006
				{
					// short @0x800D0832, len = 0x00000002
					.x = null,
					// short @0x800D0834, len = 0x00000002
					.y = null,
					// char @0x800D0836, len = 0x00000001
					.c = 0x00,
					// char @0x800D0837, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0838, len = 0x00000006
				{
					// short @0x800D0838, len = 0x00000002
					.x = null,
					// short @0x800D083A, len = 0x00000002
					.y = null,
					// char @0x800D083C, len = 0x00000001
					.c = 0x00,
					// char @0x800D083D, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D083E, len = 0x00000006
				{
					// short @0x800D083E, len = 0x00000002
					.x = null,
					// short @0x800D0840, len = 0x00000002
					.y = null,
					// char @0x800D0842, len = 0x00000001
					.c = 0x00,
					// char @0x800D0843, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0844, len = 0x00000006
				{
					// short @0x800D0844, len = 0x00000002
					.x = null,
					// short @0x800D0846, len = 0x00000002
					.y = null,
					// char @0x800D0848, len = 0x00000001
					.c = 0x00,
					// char @0x800D0849, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D084A, len = 0x00000006
				{
					// short @0x800D084A, len = 0x00000002
					.x = null,
					// short @0x800D084C, len = 0x00000002
					.y = null,
					// char @0x800D084E, len = 0x00000001
					.c = 0x00,
					// char @0x800D084F, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0850, len = 0x00000006
				{
					// short @0x800D0850, len = 0x00000002
					.x = null,
					// short @0x800D0852, len = 0x00000002
					.y = null,
					// char @0x800D0854, len = 0x00000001
					.c = 0x00,
					// char @0x800D0855, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0856, len = 0x00000006
				{
					// short @0x800D0856, len = 0x00000002
					.x = null,
					// short @0x800D0858, len = 0x00000002
					.y = null,
					// char @0x800D085A, len = 0x00000001
					.c = 0x00,
					// char @0x800D085B, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D085C, len = 0x00000006
				{
					// short @0x800D085C, len = 0x00000002
					.x = null,
					// short @0x800D085E, len = 0x00000002
					.y = null,
					// char @0x800D0860, len = 0x00000001
					.c = 0x00,
					// char @0x800D0861, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0862, len = 0x00000006
				{
					// short @0x800D0862, len = 0x00000002
					.x = null,
					// short @0x800D0864, len = 0x00000002
					.y = null,
					// char @0x800D0866, len = 0x00000001
					.c = 0x00,
					// char @0x800D0867, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0868, len = 0x00000006
				{
					// short @0x800D0868, len = 0x00000002
					.x = null,
					// short @0x800D086A, len = 0x00000002
					.y = null,
					// char @0x800D086C, len = 0x00000001
					.c = 0x00,
					// char @0x800D086D, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D086E, len = 0x00000006
				{
					// short @0x800D086E, len = 0x00000002
					.x = null,
					// short @0x800D0870, len = 0x00000002
					.y = null,
					// char @0x800D0872, len = 0x00000001
					.c = 0x00,
					// char @0x800D0873, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0874, len = 0x00000006
				{
					// short @0x800D0874, len = 0x00000002
					.x = null,
					// short @0x800D0876, len = 0x00000002
					.y = null,
					// char @0x800D0878, len = 0x00000001
					.c = 0x00,
					// char @0x800D0879, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D087A, len = 0x00000006
				{
					// short @0x800D087A, len = 0x00000002
					.x = null,
					// short @0x800D087C, len = 0x00000002
					.y = null,
					// char @0x800D087E, len = 0x00000001
					.c = 0x00,
					// char @0x800D087F, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0880, len = 0x00000006
				{
					// short @0x800D0880, len = 0x00000002
					.x = null,
					// short @0x800D0882, len = 0x00000002
					.y = null,
					// char @0x800D0884, len = 0x00000001
					.c = 0x00,
					// char @0x800D0885, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0886, len = 0x00000006
				{
					// short @0x800D0886, len = 0x00000002
					.x = null,
					// short @0x800D0888, len = 0x00000002
					.y = null,
					// char @0x800D088A, len = 0x00000001
					.c = 0x00,
					// char @0x800D088B, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D088C, len = 0x00000006
				{
					// short @0x800D088C, len = 0x00000002
					.x = null,
					// short @0x800D088E, len = 0x00000002
					.y = null,
					// char @0x800D0890, len = 0x00000001
					.c = 0x00,
					// char @0x800D0891, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0892, len = 0x00000006
				{
					// short @0x800D0892, len = 0x00000002
					.x = null,
					// short @0x800D0894, len = 0x00000002
					.y = null,
					// char @0x800D0896, len = 0x00000001
					.c = 0x00,
					// char @0x800D0897, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0898, len = 0x00000006
				{
					// short @0x800D0898, len = 0x00000002
					.x = null,
					// short @0x800D089A, len = 0x00000002
					.y = null,
					// char @0x800D089C, len = 0x00000001
					.c = 0x00,
					// char @0x800D089D, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D089E, len = 0x00000006
				{
					// short @0x800D089E, len = 0x00000002
					.x = null,
					// short @0x800D08A0, len = 0x00000002
					.y = null,
					// char @0x800D08A2, len = 0x00000001
					.c = 0x00,
					// char @0x800D08A3, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D08A4, len = 0x00000006
				{
					// short @0x800D08A4, len = 0x00000002
					.x = null,
					// short @0x800D08A6, len = 0x00000002
					.y = null,
					// char @0x800D08A8, len = 0x00000001
					.c = 0x00,
					// char @0x800D08A9, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D08AA, len = 0x00000006
				{
					// short @0x800D08AA, len = 0x00000002
					.x = null,
					// short @0x800D08AC, len = 0x00000002
					.y = null,
					// char @0x800D08AE, len = 0x00000001
					.c = 0x00,
					// char @0x800D08AF, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D08B0, len = 0x00000006
				{
					// short @0x800D08B0, len = 0x00000002
					.x = null,
					// short @0x800D08B2, len = 0x00000002
					.y = null,
					// char @0x800D08B4, len = 0x00000001
					.c = 0x00,
					// char @0x800D08B5, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D08B6, len = 0x00000006
				{
					// short @0x800D08B6, len = 0x00000002
					.x = null,
					// short @0x800D08B8, len = 0x00000002
					.y = null,
					// char @0x800D08BA, len = 0x00000001
					.c = 0x00,
					// char @0x800D08BB, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D08BC, len = 0x00000006
				{
					// short @0x800D08BC, len = 0x00000002
					.x = null,
					// short @0x800D08BE, len = 0x00000002
					.y = null,
					// char @0x800D08C0, len = 0x00000001
					.c = 0x00,
					// char @0x800D08C1, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D08C2, len = 0x00000006
				{
					// short @0x800D08C2, len = 0x00000002
					.x = null,
					// short @0x800D08C4, len = 0x00000002
					.y = null,
					// char @0x800D08C6, len = 0x00000001
					.c = 0x00,
					// char @0x800D08C7, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D08C8, len = 0x00000006
				{
					// short @0x800D08C8, len = 0x00000002
					.x = null,
					// short @0x800D08CA, len = 0x00000002
					.y = null,
					// char @0x800D08CC, len = 0x00000001
					.c = 0x00,
					// char @0x800D08CD, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D08CE, len = 0x00000006
				{
					// short @0x800D08CE, len = 0x00000002
					.x = null,
					// short @0x800D08D0, len = 0x00000002
					.y = null,
					// char @0x800D08D2, len = 0x00000001
					.c = 0x00,
					// char @0x800D08D3, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D08D4, len = 0x00000006
				{
					// short @0x800D08D4, len = 0x00000002
					.x = null,
					// short @0x800D08D6, len = 0x00000002
					.y = null,
					// char @0x800D08D8, len = 0x00000001
					.c = 0x00,
					// char @0x800D08D9, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D08DA, len = 0x00000006
				{
					// short @0x800D08DA, len = 0x00000002
					.x = null,
					// short @0x800D08DC, len = 0x00000002
					.y = null,
					// char @0x800D08DE, len = 0x00000001
					.c = 0x00,
					// char @0x800D08DF, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D08E0, len = 0x00000006
				{
					// short @0x800D08E0, len = 0x00000002
					.x = null,
					// short @0x800D08E2, len = 0x00000002
					.y = null,
					// char @0x800D08E4, len = 0x00000001
					.c = 0x00,
					// char @0x800D08E5, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D08E6, len = 0x00000006
				{
					// short @0x800D08E6, len = 0x00000002
					.x = null,
					// short @0x800D08E8, len = 0x00000002
					.y = null,
					// char @0x800D08EA, len = 0x00000001
					.c = 0x00,
					// char @0x800D08EB, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D08EC, len = 0x00000006
				{
					// short @0x800D08EC, len = 0x00000002
					.x = null,
					// short @0x800D08EE, len = 0x00000002
					.y = null,
					// char @0x800D08F0, len = 0x00000001
					.c = 0x00,
					// char @0x800D08F1, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D08F2, len = 0x00000006
				{
					// short @0x800D08F2, len = 0x00000002
					.x = null,
					// short @0x800D08F4, len = 0x00000002
					.y = null,
					// char @0x800D08F6, len = 0x00000001
					.c = 0x00,
					// char @0x800D08F7, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D08F8, len = 0x00000006
				{
					// short @0x800D08F8, len = 0x00000002
					.x = null,
					// short @0x800D08FA, len = 0x00000002
					.y = null,
					// char @0x800D08FC, len = 0x00000001
					.c = 0x00,
					// char @0x800D08FD, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D08FE, len = 0x00000006
				{
					// short @0x800D08FE, len = 0x00000002
					.x = null,
					// short @0x800D0900, len = 0x00000002
					.y = null,
					// char @0x800D0902, len = 0x00000001
					.c = 0x00,
					// char @0x800D0903, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0904, len = 0x00000006
				{
					// short @0x800D0904, len = 0x00000002
					.x = null,
					// short @0x800D0906, len = 0x00000002
					.y = null,
					// char @0x800D0908, len = 0x00000001
					.c = 0x00,
					// char @0x800D0909, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D090A, len = 0x00000006
				{
					// short @0x800D090A, len = 0x00000002
					.x = null,
					// short @0x800D090C, len = 0x00000002
					.y = null,
					// char @0x800D090E, len = 0x00000001
					.c = 0x00,
					// char @0x800D090F, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0910, len = 0x00000006
				{
					// short @0x800D0910, len = 0x00000002
					.x = null,
					// short @0x800D0912, len = 0x00000002
					.y = null,
					// char @0x800D0914, len = 0x00000001
					.c = 0x00,
					// char @0x800D0915, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0916, len = 0x00000006
				{
					// short @0x800D0916, len = 0x00000002
					.x = null,
					// short @0x800D0918, len = 0x00000002
					.y = null,
					// char @0x800D091A, len = 0x00000001
					.c = 0x00,
					// char @0x800D091B, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D091C, len = 0x00000006
				{
					// short @0x800D091C, len = 0x00000002
					.x = null,
					// short @0x800D091E, len = 0x00000002
					.y = null,
					// char @0x800D0920, len = 0x00000001
					.c = 0x00,
					// char @0x800D0921, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0922, len = 0x00000006
				{
					// short @0x800D0922, len = 0x00000002
					.x = null,
					// short @0x800D0924, len = 0x00000002
					.y = null,
					// char @0x800D0926, len = 0x00000001
					.c = 0x00,
					// char @0x800D0927, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0928, len = 0x00000006
				{
					// short @0x800D0928, len = 0x00000002
					.x = null,
					// short @0x800D092A, len = 0x00000002
					.y = null,
					// char @0x800D092C, len = 0x00000001
					.c = 0x00,
					// char @0x800D092D, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D092E, len = 0x00000006
				{
					// short @0x800D092E, len = 0x00000002
					.x = null,
					// short @0x800D0930, len = 0x00000002
					.y = null,
					// char @0x800D0932, len = 0x00000001
					.c = 0x00,
					// char @0x800D0933, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0934, len = 0x00000006
				{
					// short @0x800D0934, len = 0x00000002
					.x = null,
					// short @0x800D0936, len = 0x00000002
					.y = null,
					// char @0x800D0938, len = 0x00000001
					.c = 0x00,
					// char @0x800D0939, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D093A, len = 0x00000006
				{
					// short @0x800D093A, len = 0x00000002
					.x = null,
					// short @0x800D093C, len = 0x00000002
					.y = null,
					// char @0x800D093E, len = 0x00000001
					.c = 0x00,
					// char @0x800D093F, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0940, len = 0x00000006
				{
					// short @0x800D0940, len = 0x00000002
					.x = null,
					// short @0x800D0942, len = 0x00000002
					.y = null,
					// char @0x800D0944, len = 0x00000001
					.c = 0x00,
					// char @0x800D0945, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0946, len = 0x00000006
				{
					// short @0x800D0946, len = 0x00000002
					.x = null,
					// short @0x800D0948, len = 0x00000002
					.y = null,
					// char @0x800D094A, len = 0x00000001
					.c = 0x00,
					// char @0x800D094B, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D094C, len = 0x00000006
				{
					// short @0x800D094C, len = 0x00000002
					.x = null,
					// short @0x800D094E, len = 0x00000002
					.y = null,
					// char @0x800D0950, len = 0x00000001
					.c = 0x00,
					// char @0x800D0951, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0952, len = 0x00000006
				{
					// short @0x800D0952, len = 0x00000002
					.x = null,
					// short @0x800D0954, len = 0x00000002
					.y = null,
					// char @0x800D0956, len = 0x00000001
					.c = 0x00,
					// char @0x800D0957, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0958, len = 0x00000006
				{
					// short @0x800D0958, len = 0x00000002
					.x = null,
					// short @0x800D095A, len = 0x00000002
					.y = null,
					// char @0x800D095C, len = 0x00000001
					.c = 0x00,
					// char @0x800D095D, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D095E, len = 0x00000006
				{
					// short @0x800D095E, len = 0x00000002
					.x = null,
					// short @0x800D0960, len = 0x00000002
					.y = null,
					// char @0x800D0962, len = 0x00000001
					.c = 0x00,
					// char @0x800D0963, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0964, len = 0x00000006
				{
					// short @0x800D0964, len = 0x00000002
					.x = null,
					// short @0x800D0966, len = 0x00000002
					.y = null,
					// char @0x800D0968, len = 0x00000001
					.c = 0x00,
					// char @0x800D0969, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D096A, len = 0x00000006
				{
					// short @0x800D096A, len = 0x00000002
					.x = null,
					// short @0x800D096C, len = 0x00000002
					.y = null,
					// char @0x800D096E, len = 0x00000001
					.c = 0x00,
					// char @0x800D096F, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0970, len = 0x00000006
				{
					// short @0x800D0970, len = 0x00000002
					.x = null,
					// short @0x800D0972, len = 0x00000002
					.y = null,
					// char @0x800D0974, len = 0x00000001
					.c = 0x00,
					// char @0x800D0975, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0976, len = 0x00000006
				{
					// short @0x800D0976, len = 0x00000002
					.x = null,
					// short @0x800D0978, len = 0x00000002
					.y = null,
					// char @0x800D097A, len = 0x00000001
					.c = 0x00,
					// char @0x800D097B, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D097C, len = 0x00000006
				{
					// short @0x800D097C, len = 0x00000002
					.x = null,
					// short @0x800D097E, len = 0x00000002
					.y = null,
					// char @0x800D0980, len = 0x00000001
					.c = 0x00,
					// char @0x800D0981, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0982, len = 0x00000006
				{
					// short @0x800D0982, len = 0x00000002
					.x = null,
					// short @0x800D0984, len = 0x00000002
					.y = null,
					// char @0x800D0986, len = 0x00000001
					.c = 0x00,
					// char @0x800D0987, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0988, len = 0x00000006
				{
					// short @0x800D0988, len = 0x00000002
					.x = null,
					// short @0x800D098A, len = 0x00000002
					.y = null,
					// char @0x800D098C, len = 0x00000001
					.c = 0x00,
					// char @0x800D098D, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D098E, len = 0x00000006
				{
					// short @0x800D098E, len = 0x00000002
					.x = null,
					// short @0x800D0990, len = 0x00000002
					.y = null,
					// char @0x800D0992, len = 0x00000001
					.c = 0x00,
					// char @0x800D0993, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0994, len = 0x00000006
				{
					// short @0x800D0994, len = 0x00000002
					.x = null,
					// short @0x800D0996, len = 0x00000002
					.y = null,
					// char @0x800D0998, len = 0x00000001
					.c = 0x00,
					// char @0x800D0999, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D099A, len = 0x00000006
				{
					// short @0x800D099A, len = 0x00000002
					.x = null,
					// short @0x800D099C, len = 0x00000002
					.y = null,
					// char @0x800D099E, len = 0x00000001
					.c = 0x00,
					// char @0x800D099F, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D09A0, len = 0x00000006
				{
					// short @0x800D09A0, len = 0x00000002
					.x = null,
					// short @0x800D09A2, len = 0x00000002
					.y = null,
					// char @0x800D09A4, len = 0x00000001
					.c = 0x00,
					// char @0x800D09A5, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D09A6, len = 0x00000006
				{
					// short @0x800D09A6, len = 0x00000002
					.x = null,
					// short @0x800D09A8, len = 0x00000002
					.y = null,
					// char @0x800D09AA, len = 0x00000001
					.c = 0x00,
					// char @0x800D09AB, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D09AC, len = 0x00000006
				{
					// short @0x800D09AC, len = 0x00000002
					.x = null,
					// short @0x800D09AE, len = 0x00000002
					.y = null,
					// char @0x800D09B0, len = 0x00000001
					.c = 0x00,
					// char @0x800D09B1, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D09B2, len = 0x00000006
				{
					// short @0x800D09B2, len = 0x00000002
					.x = null,
					// short @0x800D09B4, len = 0x00000002
					.y = null,
					// char @0x800D09B6, len = 0x00000001
					.c = 0x00,
					// char @0x800D09B7, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D09B8, len = 0x00000006
				{
					// short @0x800D09B8, len = 0x00000002
					.x = null,
					// short @0x800D09BA, len = 0x00000002
					.y = null,
					// char @0x800D09BC, len = 0x00000001
					.c = 0x00,
					// char @0x800D09BD, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D09BE, len = 0x00000006
				{
					// short @0x800D09BE, len = 0x00000002
					.x = null,
					// short @0x800D09C0, len = 0x00000002
					.y = null,
					// char @0x800D09C2, len = 0x00000001
					.c = 0x00,
					// char @0x800D09C3, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D09C4, len = 0x00000006
				{
					// short @0x800D09C4, len = 0x00000002
					.x = null,
					// short @0x800D09C6, len = 0x00000002
					.y = null,
					// char @0x800D09C8, len = 0x00000001
					.c = 0x00,
					// char @0x800D09C9, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D09CA, len = 0x00000006
				{
					// short @0x800D09CA, len = 0x00000002
					.x = null,
					// short @0x800D09CC, len = 0x00000002
					.y = null,
					// char @0x800D09CE, len = 0x00000001
					.c = 0x00,
					// char @0x800D09CF, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D09D0, len = 0x00000006
				{
					// short @0x800D09D0, len = 0x00000002
					.x = null,
					// short @0x800D09D2, len = 0x00000002
					.y = null,
					// char @0x800D09D4, len = 0x00000001
					.c = 0x00,
					// char @0x800D09D5, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D09D6, len = 0x00000006
				{
					// short @0x800D09D6, len = 0x00000002
					.x = null,
					// short @0x800D09D8, len = 0x00000002
					.y = null,
					// char @0x800D09DA, len = 0x00000001
					.c = 0x00,
					// char @0x800D09DB, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D09DC, len = 0x00000006
				{
					// short @0x800D09DC, len = 0x00000002
					.x = null,
					// short @0x800D09DE, len = 0x00000002
					.y = null,
					// char @0x800D09E0, len = 0x00000001
					.c = 0x00,
					// char @0x800D09E1, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D09E2, len = 0x00000006
				{
					// short @0x800D09E2, len = 0x00000002
					.x = null,
					// short @0x800D09E4, len = 0x00000002
					.y = null,
					// char @0x800D09E6, len = 0x00000001
					.c = 0x00,
					// char @0x800D09E7, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D09E8, len = 0x00000006
				{
					// short @0x800D09E8, len = 0x00000002
					.x = null,
					// short @0x800D09EA, len = 0x00000002
					.y = null,
					// char @0x800D09EC, len = 0x00000001
					.c = 0x00,
					// char @0x800D09ED, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D09EE, len = 0x00000006
				{
					// short @0x800D09EE, len = 0x00000002
					.x = null,
					// short @0x800D09F0, len = 0x00000002
					.y = null,
					// char @0x800D09F2, len = 0x00000001
					.c = 0x00,
					// char @0x800D09F3, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D09F4, len = 0x00000006
				{
					// short @0x800D09F4, len = 0x00000002
					.x = null,
					// short @0x800D09F6, len = 0x00000002
					.y = null,
					// char @0x800D09F8, len = 0x00000001
					.c = 0x00,
					// char @0x800D09F9, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D09FA, len = 0x00000006
				{
					// short @0x800D09FA, len = 0x00000002
					.x = null,
					// short @0x800D09FC, len = 0x00000002
					.y = null,
					// char @0x800D09FE, len = 0x00000001
					.c = 0x00,
					// char @0x800D09FF, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A00, len = 0x00000006
				{
					// short @0x800D0A00, len = 0x00000002
					.x = null,
					// short @0x800D0A02, len = 0x00000002
					.y = null,
					// char @0x800D0A04, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A05, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A06, len = 0x00000006
				{
					// short @0x800D0A06, len = 0x00000002
					.x = null,
					// short @0x800D0A08, len = 0x00000002
					.y = null,
					// char @0x800D0A0A, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A0B, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A0C, len = 0x00000006
				{
					// short @0x800D0A0C, len = 0x00000002
					.x = null,
					// short @0x800D0A0E, len = 0x00000002
					.y = null,
					// char @0x800D0A10, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A11, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A12, len = 0x00000006
				{
					// short @0x800D0A12, len = 0x00000002
					.x = null,
					// short @0x800D0A14, len = 0x00000002
					.y = null,
					// char @0x800D0A16, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A17, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A18, len = 0x00000006
				{
					// short @0x800D0A18, len = 0x00000002
					.x = null,
					// short @0x800D0A1A, len = 0x00000002
					.y = null,
					// char @0x800D0A1C, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A1D, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A1E, len = 0x00000006
				{
					// short @0x800D0A1E, len = 0x00000002
					.x = null,
					// short @0x800D0A20, len = 0x00000002
					.y = null,
					// char @0x800D0A22, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A23, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A24, len = 0x00000006
				{
					// short @0x800D0A24, len = 0x00000002
					.x = null,
					// short @0x800D0A26, len = 0x00000002
					.y = null,
					// char @0x800D0A28, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A29, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A2A, len = 0x00000006
				{
					// short @0x800D0A2A, len = 0x00000002
					.x = null,
					// short @0x800D0A2C, len = 0x00000002
					.y = null,
					// char @0x800D0A2E, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A2F, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A30, len = 0x00000006
				{
					// short @0x800D0A30, len = 0x00000002
					.x = null,
					// short @0x800D0A32, len = 0x00000002
					.y = null,
					// char @0x800D0A34, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A35, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A36, len = 0x00000006
				{
					// short @0x800D0A36, len = 0x00000002
					.x = null,
					// short @0x800D0A38, len = 0x00000002
					.y = null,
					// char @0x800D0A3A, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A3B, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A3C, len = 0x00000006
				{
					// short @0x800D0A3C, len = 0x00000002
					.x = null,
					// short @0x800D0A3E, len = 0x00000002
					.y = null,
					// char @0x800D0A40, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A41, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A42, len = 0x00000006
				{
					// short @0x800D0A42, len = 0x00000002
					.x = null,
					// short @0x800D0A44, len = 0x00000002
					.y = null,
					// char @0x800D0A46, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A47, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A48, len = 0x00000006
				{
					// short @0x800D0A48, len = 0x00000002
					.x = null,
					// short @0x800D0A4A, len = 0x00000002
					.y = null,
					// char @0x800D0A4C, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A4D, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A4E, len = 0x00000006
				{
					// short @0x800D0A4E, len = 0x00000002
					.x = null,
					// short @0x800D0A50, len = 0x00000002
					.y = null,
					// char @0x800D0A52, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A53, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A54, len = 0x00000006
				{
					// short @0x800D0A54, len = 0x00000002
					.x = null,
					// short @0x800D0A56, len = 0x00000002
					.y = null,
					// char @0x800D0A58, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A59, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A5A, len = 0x00000006
				{
					// short @0x800D0A5A, len = 0x00000002
					.x = null,
					// short @0x800D0A5C, len = 0x00000002
					.y = null,
					// char @0x800D0A5E, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A5F, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A60, len = 0x00000006
				{
					// short @0x800D0A60, len = 0x00000002
					.x = null,
					// short @0x800D0A62, len = 0x00000002
					.y = null,
					// char @0x800D0A64, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A65, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A66, len = 0x00000006
				{
					// short @0x800D0A66, len = 0x00000002
					.x = null,
					// short @0x800D0A68, len = 0x00000002
					.y = null,
					// char @0x800D0A6A, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A6B, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A6C, len = 0x00000006
				{
					// short @0x800D0A6C, len = 0x00000002
					.x = null,
					// short @0x800D0A6E, len = 0x00000002
					.y = null,
					// char @0x800D0A70, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A71, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A72, len = 0x00000006
				{
					// short @0x800D0A72, len = 0x00000002
					.x = null,
					// short @0x800D0A74, len = 0x00000002
					.y = null,
					// char @0x800D0A76, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A77, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A78, len = 0x00000006
				{
					// short @0x800D0A78, len = 0x00000002
					.x = null,
					// short @0x800D0A7A, len = 0x00000002
					.y = null,
					// char @0x800D0A7C, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A7D, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A7E, len = 0x00000006
				{
					// short @0x800D0A7E, len = 0x00000002
					.x = null,
					// short @0x800D0A80, len = 0x00000002
					.y = null,
					// char @0x800D0A82, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A83, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A84, len = 0x00000006
				{
					// short @0x800D0A84, len = 0x00000002
					.x = null,
					// short @0x800D0A86, len = 0x00000002
					.y = null,
					// char @0x800D0A88, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A89, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A8A, len = 0x00000006
				{
					// short @0x800D0A8A, len = 0x00000002
					.x = null,
					// short @0x800D0A8C, len = 0x00000002
					.y = null,
					// char @0x800D0A8E, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A8F, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A90, len = 0x00000006
				{
					// short @0x800D0A90, len = 0x00000002
					.x = null,
					// short @0x800D0A92, len = 0x00000002
					.y = null,
					// char @0x800D0A94, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A95, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A96, len = 0x00000006
				{
					// short @0x800D0A96, len = 0x00000002
					.x = null,
					// short @0x800D0A98, len = 0x00000002
					.y = null,
					// char @0x800D0A9A, len = 0x00000001
					.c = 0x00,
					// char @0x800D0A9B, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0A9C, len = 0x00000006
				{
					// short @0x800D0A9C, len = 0x00000002
					.x = null,
					// short @0x800D0A9E, len = 0x00000002
					.y = null,
					// char @0x800D0AA0, len = 0x00000001
					.c = 0x00,
					// char @0x800D0AA1, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0AA2, len = 0x00000006
				{
					// short @0x800D0AA2, len = 0x00000002
					.x = null,
					// short @0x800D0AA4, len = 0x00000002
					.y = null,
					// char @0x800D0AA6, len = 0x00000001
					.c = 0x00,
					// char @0x800D0AA7, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0AA8, len = 0x00000006
				{
					// short @0x800D0AA8, len = 0x00000002
					.x = null,
					// short @0x800D0AAA, len = 0x00000002
					.y = null,
					// char @0x800D0AAC, len = 0x00000001
					.c = 0x00,
					// char @0x800D0AAD, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0AAE, len = 0x00000006
				{
					// short @0x800D0AAE, len = 0x00000002
					.x = null,
					// short @0x800D0AB0, len = 0x00000002
					.y = null,
					// char @0x800D0AB2, len = 0x00000001
					.c = 0x00,
					// char @0x800D0AB3, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0AB4, len = 0x00000006
				{
					// short @0x800D0AB4, len = 0x00000002
					.x = null,
					// short @0x800D0AB6, len = 0x00000002
					.y = null,
					// char @0x800D0AB8, len = 0x00000001
					.c = 0x00,
					// char @0x800D0AB9, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0ABA, len = 0x00000006
				{
					// short @0x800D0ABA, len = 0x00000002
					.x = null,
					// short @0x800D0ABC, len = 0x00000002
					.y = null,
					// char @0x800D0ABE, len = 0x00000001
					.c = 0x00,
					// char @0x800D0ABF, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0AC0, len = 0x00000006
				{
					// short @0x800D0AC0, len = 0x00000002
					.x = null,
					// short @0x800D0AC2, len = 0x00000002
					.y = null,
					// char @0x800D0AC4, len = 0x00000001
					.c = 0x00,
					// char @0x800D0AC5, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0AC6, len = 0x00000006
				{
					// short @0x800D0AC6, len = 0x00000002
					.x = null,
					// short @0x800D0AC8, len = 0x00000002
					.y = null,
					// char @0x800D0ACA, len = 0x00000001
					.c = 0x00,
					// char @0x800D0ACB, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0ACC, len = 0x00000006
				{
					// short @0x800D0ACC, len = 0x00000002
					.x = null,
					// short @0x800D0ACE, len = 0x00000002
					.y = null,
					// char @0x800D0AD0, len = 0x00000001
					.c = 0x00,
					// char @0x800D0AD1, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0AD2, len = 0x00000006
				{
					// short @0x800D0AD2, len = 0x00000002
					.x = null,
					// short @0x800D0AD4, len = 0x00000002
					.y = null,
					// char @0x800D0AD6, len = 0x00000001
					.c = 0x00,
					// char @0x800D0AD7, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0AD8, len = 0x00000006
				{
					// short @0x800D0AD8, len = 0x00000002
					.x = null,
					// short @0x800D0ADA, len = 0x00000002
					.y = null,
					// char @0x800D0ADC, len = 0x00000001
					.c = 0x00,
					// char @0x800D0ADD, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0ADE, len = 0x00000006
				{
					// short @0x800D0ADE, len = 0x00000002
					.x = null,
					// short @0x800D0AE0, len = 0x00000002
					.y = null,
					// char @0x800D0AE2, len = 0x00000001
					.c = 0x00,
					// char @0x800D0AE3, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0AE4, len = 0x00000006
				{
					// short @0x800D0AE4, len = 0x00000002
					.x = null,
					// short @0x800D0AE6, len = 0x00000002
					.y = null,
					// char @0x800D0AE8, len = 0x00000001
					.c = 0x00,
					// char @0x800D0AE9, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0AEA, len = 0x00000006
				{
					// short @0x800D0AEA, len = 0x00000002
					.x = null,
					// short @0x800D0AEC, len = 0x00000002
					.y = null,
					// char @0x800D0AEE, len = 0x00000001
					.c = 0x00,
					// char @0x800D0AEF, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0AF0, len = 0x00000006
				{
					// short @0x800D0AF0, len = 0x00000002
					.x = null,
					// short @0x800D0AF2, len = 0x00000002
					.y = null,
					// char @0x800D0AF4, len = 0x00000001
					.c = 0x00,
					// char @0x800D0AF5, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0AF6, len = 0x00000006
				{
					// short @0x800D0AF6, len = 0x00000002
					.x = null,
					// short @0x800D0AF8, len = 0x00000002
					.y = null,
					// char @0x800D0AFA, len = 0x00000001
					.c = 0x00,
					// char @0x800D0AFB, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0AFC, len = 0x00000006
				{
					// short @0x800D0AFC, len = 0x00000002
					.x = null,
					// short @0x800D0AFE, len = 0x00000002
					.y = null,
					// char @0x800D0B00, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B01, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B02, len = 0x00000006
				{
					// short @0x800D0B02, len = 0x00000002
					.x = null,
					// short @0x800D0B04, len = 0x00000002
					.y = null,
					// char @0x800D0B06, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B07, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B08, len = 0x00000006
				{
					// short @0x800D0B08, len = 0x00000002
					.x = null,
					// short @0x800D0B0A, len = 0x00000002
					.y = null,
					// char @0x800D0B0C, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B0D, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B0E, len = 0x00000006
				{
					// short @0x800D0B0E, len = 0x00000002
					.x = null,
					// short @0x800D0B10, len = 0x00000002
					.y = null,
					// char @0x800D0B12, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B13, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B14, len = 0x00000006
				{
					// short @0x800D0B14, len = 0x00000002
					.x = null,
					// short @0x800D0B16, len = 0x00000002
					.y = null,
					// char @0x800D0B18, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B19, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B1A, len = 0x00000006
				{
					// short @0x800D0B1A, len = 0x00000002
					.x = null,
					// short @0x800D0B1C, len = 0x00000002
					.y = null,
					// char @0x800D0B1E, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B1F, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B20, len = 0x00000006
				{
					// short @0x800D0B20, len = 0x00000002
					.x = null,
					// short @0x800D0B22, len = 0x00000002
					.y = null,
					// char @0x800D0B24, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B25, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B26, len = 0x00000006
				{
					// short @0x800D0B26, len = 0x00000002
					.x = null,
					// short @0x800D0B28, len = 0x00000002
					.y = null,
					// char @0x800D0B2A, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B2B, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B2C, len = 0x00000006
				{
					// short @0x800D0B2C, len = 0x00000002
					.x = null,
					// short @0x800D0B2E, len = 0x00000002
					.y = null,
					// char @0x800D0B30, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B31, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B32, len = 0x00000006
				{
					// short @0x800D0B32, len = 0x00000002
					.x = null,
					// short @0x800D0B34, len = 0x00000002
					.y = null,
					// char @0x800D0B36, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B37, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B38, len = 0x00000006
				{
					// short @0x800D0B38, len = 0x00000002
					.x = null,
					// short @0x800D0B3A, len = 0x00000002
					.y = null,
					// char @0x800D0B3C, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B3D, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B3E, len = 0x00000006
				{
					// short @0x800D0B3E, len = 0x00000002
					.x = null,
					// short @0x800D0B40, len = 0x00000002
					.y = null,
					// char @0x800D0B42, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B43, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B44, len = 0x00000006
				{
					// short @0x800D0B44, len = 0x00000002
					.x = null,
					// short @0x800D0B46, len = 0x00000002
					.y = null,
					// char @0x800D0B48, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B49, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B4A, len = 0x00000006
				{
					// short @0x800D0B4A, len = 0x00000002
					.x = null,
					// short @0x800D0B4C, len = 0x00000002
					.y = null,
					// char @0x800D0B4E, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B4F, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B50, len = 0x00000006
				{
					// short @0x800D0B50, len = 0x00000002
					.x = null,
					// short @0x800D0B52, len = 0x00000002
					.y = null,
					// char @0x800D0B54, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B55, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B56, len = 0x00000006
				{
					// short @0x800D0B56, len = 0x00000002
					.x = null,
					// short @0x800D0B58, len = 0x00000002
					.y = null,
					// char @0x800D0B5A, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B5B, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B5C, len = 0x00000006
				{
					// short @0x800D0B5C, len = 0x00000002
					.x = null,
					// short @0x800D0B5E, len = 0x00000002
					.y = null,
					// char @0x800D0B60, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B61, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B62, len = 0x00000006
				{
					// short @0x800D0B62, len = 0x00000002
					.x = null,
					// short @0x800D0B64, len = 0x00000002
					.y = null,
					// char @0x800D0B66, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B67, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B68, len = 0x00000006
				{
					// short @0x800D0B68, len = 0x00000002
					.x = null,
					// short @0x800D0B6A, len = 0x00000002
					.y = null,
					// char @0x800D0B6C, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B6D, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B6E, len = 0x00000006
				{
					// short @0x800D0B6E, len = 0x00000002
					.x = null,
					// short @0x800D0B70, len = 0x00000002
					.y = null,
					// char @0x800D0B72, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B73, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B74, len = 0x00000006
				{
					// short @0x800D0B74, len = 0x00000002
					.x = null,
					// short @0x800D0B76, len = 0x00000002
					.y = null,
					// char @0x800D0B78, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B79, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B7A, len = 0x00000006
				{
					// short @0x800D0B7A, len = 0x00000002
					.x = null,
					// short @0x800D0B7C, len = 0x00000002
					.y = null,
					// char @0x800D0B7E, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B7F, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B80, len = 0x00000006
				{
					// short @0x800D0B80, len = 0x00000002
					.x = null,
					// short @0x800D0B82, len = 0x00000002
					.y = null,
					// char @0x800D0B84, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B85, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B86, len = 0x00000006
				{
					// short @0x800D0B86, len = 0x00000002
					.x = null,
					// short @0x800D0B88, len = 0x00000002
					.y = null,
					// char @0x800D0B8A, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B8B, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B8C, len = 0x00000006
				{
					// short @0x800D0B8C, len = 0x00000002
					.x = null,
					// short @0x800D0B8E, len = 0x00000002
					.y = null,
					// char @0x800D0B90, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B91, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B92, len = 0x00000006
				{
					// short @0x800D0B92, len = 0x00000002
					.x = null,
					// short @0x800D0B94, len = 0x00000002
					.y = null,
					// char @0x800D0B96, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B97, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B98, len = 0x00000006
				{
					// short @0x800D0B98, len = 0x00000002
					.x = null,
					// short @0x800D0B9A, len = 0x00000002
					.y = null,
					// char @0x800D0B9C, len = 0x00000001
					.c = 0x00,
					// char @0x800D0B9D, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0B9E, len = 0x00000006
				{
					// short @0x800D0B9E, len = 0x00000002
					.x = null,
					// short @0x800D0BA0, len = 0x00000002
					.y = null,
					// char @0x800D0BA2, len = 0x00000001
					.c = 0x00,
					// char @0x800D0BA3, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0BA4, len = 0x00000006
				{
					// short @0x800D0BA4, len = 0x00000002
					.x = null,
					// short @0x800D0BA6, len = 0x00000002
					.y = null,
					// char @0x800D0BA8, len = 0x00000001
					.c = 0x00,
					// char @0x800D0BA9, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0BAA, len = 0x00000006
				{
					// short @0x800D0BAA, len = 0x00000002
					.x = null,
					// short @0x800D0BAC, len = 0x00000002
					.y = null,
					// char @0x800D0BAE, len = 0x00000001
					.c = 0x00,
					// char @0x800D0BAF, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0BB0, len = 0x00000006
				{
					// short @0x800D0BB0, len = 0x00000002
					.x = null,
					// short @0x800D0BB2, len = 0x00000002
					.y = null,
					// char @0x800D0BB4, len = 0x00000001
					.c = 0x00,
					// char @0x800D0BB5, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0BB6, len = 0x00000006
				{
					// short @0x800D0BB6, len = 0x00000002
					.x = null,
					// short @0x800D0BB8, len = 0x00000002
					.y = null,
					// char @0x800D0BBA, len = 0x00000001
					.c = 0x00,
					// char @0x800D0BBB, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0BBC, len = 0x00000006
				{
					// short @0x800D0BBC, len = 0x00000002
					.x = null,
					// short @0x800D0BBE, len = 0x00000002
					.y = null,
					// char @0x800D0BC0, len = 0x00000001
					.c = 0x00,
					// char @0x800D0BC1, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0BC2, len = 0x00000006
				{
					// short @0x800D0BC2, len = 0x00000002
					.x = null,
					// short @0x800D0BC4, len = 0x00000002
					.y = null,
					// char @0x800D0BC6, len = 0x00000001
					.c = 0x00,
					// char @0x800D0BC7, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0BC8, len = 0x00000006
				{
					// short @0x800D0BC8, len = 0x00000002
					.x = null,
					// short @0x800D0BCA, len = 0x00000002
					.y = null,
					// char @0x800D0BCC, len = 0x00000001
					.c = 0x00,
					// char @0x800D0BCD, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0BCE, len = 0x00000006
				{
					// short @0x800D0BCE, len = 0x00000002
					.x = null,
					// short @0x800D0BD0, len = 0x00000002
					.y = null,
					// char @0x800D0BD2, len = 0x00000001
					.c = 0x00,
					// char @0x800D0BD3, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0BD4, len = 0x00000006
				{
					// short @0x800D0BD4, len = 0x00000002
					.x = null,
					// short @0x800D0BD6, len = 0x00000002
					.y = null,
					// char @0x800D0BD8, len = 0x00000001
					.c = 0x00,
					// char @0x800D0BD9, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0BDA, len = 0x00000006
				{
					// short @0x800D0BDA, len = 0x00000002
					.x = null,
					// short @0x800D0BDC, len = 0x00000002
					.y = null,
					// char @0x800D0BDE, len = 0x00000001
					.c = 0x00,
					// char @0x800D0BDF, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0BE0, len = 0x00000006
				{
					// short @0x800D0BE0, len = 0x00000002
					.x = null,
					// short @0x800D0BE2, len = 0x00000002
					.y = null,
					// char @0x800D0BE4, len = 0x00000001
					.c = 0x00,
					// char @0x800D0BE5, len = 0x00000001
					.color = 0x00},
				// FontChar @0x800D0BE6, len = 0x00000006
				{
					// short @0x800D0BE6, len = 0x00000002
					.x = null,
					// short @0x800D0BE8, len = 0x00000002
					.y = null,
					// char @0x800D0BEA, len = 0x00000001
					.c = 0x00,
					// char @0x800D0BEB, len = 0x00000001
					.color = 0x00}},
		// long @0x800D0BEC, len = 0x00000004
		.font_xpos = null,
		// long @0x800D0BF0, len = 0x00000004
		.font_ypos = null,
		// long @0x800D0BF4, len = 0x00000004
		.font_buffIndex = null,
		// short @0x800D0BF8, len = 0x00000002
		.font_tpage = null,
		// short @0x800D0BFA, len = 0x00000002
		.font_clut = null,
		// short @0x800D0BFC, len = 0x00000002
		.font_vramU = null,
		// short @0x800D0BFE, len = 0x00000002
		.font_vramV = null,
		// short @0x800D0C00, len = 0x00000002
		.font_width = null,
		// short @0x800D0C02, len = 0x00000002
		.sprite_sort_push = null,
		// short @0x800D0C04, len = 0x00000002
		.font_vramX = null,
		// short @0x800D0C06, len = 0x00000002
		.font_vramY = null,
		// char @0x800D0C08, len = 0x00000001
		.color_global = 0x00,
		// char @0x800D0C09, len = 0x00000001
		.color_local = 0x00};
// uchar[128] @0x800CE224, len = 0x00000080
fontTransTable =
	{
		// uchar @0x800CE224, len = 0x00000001
		0x24,
		// uchar @0x800CE225, len = 0x00000001
		0x24,
		// uchar @0x800CE226, len = 0x00000001
		0x24,
		// uchar @0x800CE227, len = 0x00000001
		0x24,
		// uchar @0x800CE228, len = 0x00000001
		0x24,
		// uchar @0x800CE229, len = 0x00000001
		0x24,
		// uchar @0x800CE22A, len = 0x00000001
		0x24,
		// uchar @0x800CE22B, len = 0x00000001
		0x24,
		// uchar @0x800CE22C, len = 0x00000001
		0x24,
		// uchar @0x800CE22D, len = 0x00000001
		0x24,
		// uchar @0x800CE22E, len = 0x00000001
		0x24,
		// uchar @0x800CE22F, len = 0x00000001
		0x24,
		// uchar @0x800CE230, len = 0x00000001
		0x24,
		// uchar @0x800CE231, len = 0x00000001
		0x24,
		// uchar @0x800CE232, len = 0x00000001
		0x24,
		// uchar @0x800CE233, len = 0x00000001
		0x24,
		// uchar @0x800CE234, len = 0x00000001
		0x24,
		// uchar @0x800CE235, len = 0x00000001
		0x56,
		// uchar @0x800CE236, len = 0x00000001
		0x57,
		// uchar @0x800CE237, len = 0x00000001
		0x58,
		// uchar @0x800CE238, len = 0x00000001
		0x59,
		// uchar @0x800CE239, len = 0x00000001
		0x5A,
		// uchar @0x800CE23A, len = 0x00000001
		0x5B,
		// uchar @0x800CE23B, len = 0x00000001
		0x24,
		// uchar @0x800CE23C, len = 0x00000001
		0x24,
		// uchar @0x800CE23D, len = 0x00000001
		0x24,
		// uchar @0x800CE23E, len = 0x00000001
		0x24,
		// uchar @0x800CE23F, len = 0x00000001
		0x24,
		// uchar @0x800CE240, len = 0x00000001
		0x24,
		// uchar @0x800CE241, len = 0x00000001
		0x24,
		// uchar @0x800CE242, len = 0x00000001
		0x24,
		// uchar @0x800CE243, len = 0x00000001
		0x24,
		// uchar @0x800CE244, len = 0x00000001
		0x24,
		// uchar @0x800CE245, len = 0x00000001
		0x25,
		// uchar @0x800CE246, len = 0x00000001
		0x28,
		// uchar @0x800CE247, len = 0x00000001
		0x24,
		// uchar @0x800CE248, len = 0x00000001
		0x24,
		// uchar @0x800CE249, len = 0x00000001
		0x29,
		// uchar @0x800CE24A, len = 0x00000001
		0x24,
		// uchar @0x800CE24B, len = 0x00000001
		0x33,
		// uchar @0x800CE24C, len = 0x00000001
		0x2B,
		// uchar @0x800CE24D, len = 0x00000001
		0x2C,
		// uchar @0x800CE24E, len = 0x00000001
		0x2F,
		// uchar @0x800CE24F, len = 0x00000001
		0x2D,
		// uchar @0x800CE250, len = 0x00000001
		0x32,
		// uchar @0x800CE251, len = 0x00000001
		0x27,
		// uchar @0x800CE252, len = 0x00000001
		0x24,
		// uchar @0x800CE253, len = 0x00000001
		0x26,
		// uchar @0x800CE254, len = 0x00000001
		0x1A,
		// uchar @0x800CE255, len = 0x00000001
		0x1B,
		// uchar @0x800CE256, len = 0x00000001
		0x1C,
		// uchar @0x800CE257, len = 0x00000001
		0x1D,
		// uchar @0x800CE258, len = 0x00000001
		0x1E,
		// uchar @0x800CE259, len = 0x00000001
		0x1F,
		// uchar @0x800CE25A, len = 0x00000001
		0x20,
		// uchar @0x800CE25B, len = 0x00000001
		0x21,
		// uchar @0x800CE25C, len = 0x00000001
		0x22,
		// uchar @0x800CE25D, len = 0x00000001
		0x23,
		// uchar @0x800CE25E, len = 0x00000001
		0x2A,
		// uchar @0x800CE25F, len = 0x00000001
		0x24,
		// uchar @0x800CE260, len = 0x00000001
		0x55,
		// uchar @0x800CE261, len = 0x00000001
		0x2E,
		// uchar @0x800CE262, len = 0x00000001
		0x54,
		// uchar @0x800CE263, len = 0x00000001
		0x30,
		// uchar @0x800CE264, len = 0x00000001
		0x24,
		// uchar @0x800CE265, len = 0x00000001
		0x34,
		// uchar @0x800CE266, len = 0x00000001
		0x35,
		// uchar @0x800CE267, len = 0x00000001
		0x36,
		// uchar @0x800CE268, len = 0x00000001
		0x37,
		// uchar @0x800CE269, len = 0x00000001
		0x38,
		// uchar @0x800CE26A, len = 0x00000001
		0x39,
		// uchar @0x800CE26B, len = 0x00000001
		0x3A,
		// uchar @0x800CE26C, len = 0x00000001
		0x3B,
		// uchar @0x800CE26D, len = 0x00000001
		0x3C,
		// uchar @0x800CE26E, len = 0x00000001
		0x3D,
		// uchar @0x800CE26F, len = 0x00000001
		0x3E,
		// uchar @0x800CE270, len = 0x00000001
		0x3F,
		// uchar @0x800CE271, len = 0x00000001
		0x40,
		// uchar @0x800CE272, len = 0x00000001
		0x41,
		// uchar @0x800CE273, len = 0x00000001
		0x42,
		// uchar @0x800CE274, len = 0x00000001
		0x43,
		// uchar @0x800CE275, len = 0x00000001
		0x44,
		// uchar @0x800CE276, len = 0x00000001
		0x45,
		// uchar @0x800CE277, len = 0x00000001
		0x46,
		// uchar @0x800CE278, len = 0x00000001
		0x47,
		// uchar @0x800CE279, len = 0x00000001
		0x48,
		// uchar @0x800CE27A, len = 0x00000001
		0x49,
		// uchar @0x800CE27B, len = 0x00000001
		0x4A,
		// uchar @0x800CE27C, len = 0x00000001
		0x4B,
		// uchar @0x800CE27D, len = 0x00000001
		0x4C,
		// uchar @0x800CE27E, len = 0x00000001
		0x4D,
		// uchar @0x800CE27F, len = 0x00000001
		0x4E,
		// uchar @0x800CE280, len = 0x00000001
		0x24,
		// uchar @0x800CE281, len = 0x00000001
		0x4F,
		// uchar @0x800CE282, len = 0x00000001
		0x52,
		// uchar @0x800CE283, len = 0x00000001
		0x24,
		// uchar @0x800CE284, len = 0x00000001
		0x24,
		// uchar @0x800CE285, len = 0x00000001
		0x00,
		// uchar @0x800CE286, len = 0x00000001
		0x01,
		// uchar @0x800CE287, len = 0x00000001
		0x02,
		// uchar @0x800CE288, len = 0x00000001
		0x03,
		// uchar @0x800CE289, len = 0x00000001
		0x04,
		// uchar @0x800CE28A, len = 0x00000001
		0x05,
		// uchar @0x800CE28B, len = 0x00000001
		0x06,
		// uchar @0x800CE28C, len = 0x00000001
		0x07,
		// uchar @0x800CE28D, len = 0x00000001
		0x08,
		// uchar @0x800CE28E, len = 0x00000001
		0x09,
		// uchar @0x800CE28F, len = 0x00000001
		0x0A,
		// uchar @0x800CE290, len = 0x00000001
		0x0B,
		// uchar @0x800CE291, len = 0x00000001
		0x0C,
		// uchar @0x800CE292, len = 0x00000001
		0x0D,
		// uchar @0x800CE293, len = 0x00000001
		0x0E,
		// uchar @0x800CE294, len = 0x00000001
		0x0F,
		// uchar @0x800CE295, len = 0x00000001
		0x10,
		// uchar @0x800CE296, len = 0x00000001
		0x11,
		// uchar @0x800CE297, len = 0x00000001
		0x12,
		// uchar @0x800CE298, len = 0x00000001
		0x13,
		// uchar @0x800CE299, len = 0x00000001
		0x14,
		// uchar @0x800CE29A, len = 0x00000001
		0x15,
		// uchar @0x800CE29B, len = 0x00000001
		0x16,
		// uchar @0x800CE29C, len = 0x00000001
		0x17,
		// uchar @0x800CE29D, len = 0x00000001
		0x18,
		// uchar @0x800CE29E, len = 0x00000001
		0x19,
		// uchar @0x800CE29F, len = 0x00000001
		0x50,
		// uchar @0x800CE2A0, len = 0x00000001
		0x53,
		// uchar @0x800CE2A1, len = 0x00000001
		0x51,
		// uchar @0x800CE2A2, len = 0x00000001
		0x31,
		// uchar @0x800CE2A3, len = 0x00000001
		0x24};
// char @0x800D03E4, len = 0x00000001
fp_str = 0x00;
// font_color_t[5] @0x800CE1D0, len = 0x0000003C
the_font_color_table =
	{
		// font_color_t @0x800CE1D0, len = 0x0000000C
		{
			// int @0x800CE1D0, len = 0x00000004
			.r = 0x0,
			// int @0x800CE1D4, len = 0x00000004
			.g = 0x0,
			// int @0x800CE1D8, len = 0x00000004
			.b = 0x0},
		// font_color_t @0x800CE1DC, len = 0x0000000C
		{
			// int @0x800CE1DC, len = 0x00000004
			.r = 0x40,
			// int @0x800CE1E0, len = 0x00000004
			.g = 0x40,
			// int @0x800CE1E4, len = 0x00000004
			.b = 0x40},
		// font_color_t @0x800CE1E8, len = 0x0000000C
		{
			// int @0x800CE1E8, len = 0x00000004
			.r = 0x40,
			// int @0x800CE1EC, len = 0x00000004
			.g = 0x40,
			// int @0x800CE1F0, len = 0x00000004
			.b = 0xff},
		// font_color_t @0x800CE1F4, len = 0x0000000C
		{
			// int @0x800CE1F4, len = 0x00000004
			.r = 0x58,
			// int @0x800CE1F8, len = 0x00000004
			.g = 0x58,
			// int @0x800CE1FC, len = 0x00000004
			.b = 0x68},
		// font_color_t @0x800CE200, len = 0x0000000C
		{
			// int @0x800CE200, len = 0x00000004
			.r = 0xdc,
			// int @0x800CE204, len = 0x00000004
			.g = 0xdc,
			// int @0x800CE208, len = 0x00000004
			.b = 0x40}};
// decompiled code
// original method signature:
// void /*$ra*/ FONT_MakeSpecialFogClut(int x /*$a3*/, int y /*$a1*/)
// line 58, offset 0x8002cb74
/* begin block 1 */
// Start line: 59
// Start offset: 0x8002CB74
// Variables:
// 		int n; // $a0
// 		unsigned short cl[16]; // stack offset -48
// 		struct RECT myrect; // stack offset -16
/* end block 1 */
// End offset: 0x8002CB9C
// End Line: 69

/* begin block 2 */
// Start line: 116
/* end block 2 */
// End Line: 117

void FONT_MakeSpecialFogClut(int x, int y)

{
	undefined2 *puVar1;
	int iVar2;
	undefined2 local_30[15];
	undefined2 local_12;
	short local_10;
	undefined2 local_e;
	undefined2 local_c;
	undefined2 local_a;

	iVar2 = 0xf;
	puVar1 = &local_12;
	do
	{
		*puVar1 = 0x4210;
		iVar2 = iVar2 + -1;
		puVar1 = puVar1 + -1;
	} while (-1 < iVar2);
	local_c = 0x10;
	local_a = 1;
	SpecialFogClut = (ushort)(y << 6) | (ushort)(x >> 4) & 0x3f;
	local_30[0] = 0;
	local_10 = (short)x;
	local_e = (undefined2)y;
	DrawSync(0);
	LoadImage(&local_10, local_30);
	DrawSync(0);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ FONT_Init()
// line 91, offset 0x8002cbf8
/* begin block 1 */
// Start line: 92
// Start offset: 0x8002CBF8
// Variables:
// 		unsigned long *timAddr; // $s0
// 		short x; // stack offset -16
// 		short y; // stack offset -14
/* end block 1 */
// End offset: 0x8002CCE8
// End Line: 126

/* begin block 2 */
// Start line: 188
/* end block 2 */
// End Line: 189

/* WARNING: Unknown calling convention yet parameter storage is locked */

void FONT_Init(void)

{
	long *addr;
	ushort local_10;
	ushort local_e[3];

	FONT_vramBlock = VRAM_CheckVramSlot((short *)&local_10, (short *)local_e, 0x10, 0x80, 3, -1);
	if (FONT_vramBlock != (_BlockVramEntry *)0x0)
	{
		addr = LOAD_ReadFile(s__kain2_game_font_tim_800ce20c, '\x05');
		LOAD_LoadTIM(addr, (int)(short)local_10, (int)(short)local_e[0], (int)(short)local_10,
					 (int)(short)local_e[0] + 0x7e);
		MEMPACK_Free((char *)addr);
		fontTracker.sprite_sort_push = 0;
		fontTracker.font_tpage =
			(short)(local_e[0] & 0x100) >> 4 | (ushort)(((uint)local_10 & 0x3ff) >> 6) |
			(ushort)(((uint)local_e[0] & 0x200) << 2);
		fontTracker.font_clut = (local_e[0] + 0x7e) * 0x40 | (short)local_10 >> 4 & 0x3fU;
		fontTracker.font_vramX = local_10;
		fontTracker.font_vramY = local_e[0];
		fontTracker.font_vramV = local_e[0] & 0xff;
		fontTracker.font_vramU = (short)(((uint)local_10 & 0x3f) << 2);
		FONT_MakeSpecialFogClut((int)(short)local_10, (int)(short)local_e[0] + 0x7f);
	}
	fontTracker.font_xpos = 10;
	fontTracker.font_ypos = 0x10;
	fontTracker.font_buffIndex = 0;
	fontTracker.sprite_sort_push = 0;
	fontTracker.color_global = '\0';
	fontTracker.color_local = '\0';
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ FONT_ReloadFont()
// line 137, offset 0x8002cd18
/* begin block 1 */
// Start line: 138
// Start offset: 0x8002CD18
// Variables:
// 		unsigned long *timAddr; // $s0
/* end block 1 */
// End offset: 0x8002CD18
// End Line: 138

/* begin block 2 */
// Start line: 318
/* end block 2 */
// End Line: 319

/* WARNING: Unknown calling convention yet parameter storage is locked */

void FONT_ReloadFont(void)

{
	long *addr;

	addr = LOAD_ReadFile(s__kain2_game_font_tim_800ce20c, '\x05');
	LOAD_LoadTIM(addr, (int)fontTracker.font_vramX, (int)fontTracker.font_vramY,
				 (int)fontTracker.font_vramX, (int)fontTracker.font_vramY + 0x7e);
	MEMPACK_Free((char *)addr);
	FONT_MakeSpecialFogClut((int)fontTracker.font_vramX, (int)fontTracker.font_vramY + 0x7f);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ FONT_DrawChar(struct FontChar *fontChar /*$a0*/)
// line 149, offset 0x8002cd7c
/* begin block 1 */
// Start line: 150
// Start offset: 0x8002CD7C
// Variables:
// 		char c; // $v1
// 		long x; // $a1
// 		long y; // $a2
/* end block 1 */
// End offset: 0x8002CD7C
// End Line: 150

/* begin block 2 */
// Start line: 346
/* end block 2 */
// End Line: 347

void FONT_DrawChar(FontChar *fontChar)

{
	fontTracker.color_local = fontChar->color;
	FONT_DrawChar2D(fontChar->c, (int)fontChar->x, (int)fontChar->y);
	return;
}

// decompiled code
// original method signature:
// long /*$ra*/ FONT_Get2DImageIndex(unsigned char c /*$a0*/)
// line 471, offset 0x8002cdb0
/* begin block 1 */
// Start line: 994
/* end block 1 */
// End Line: 995

/* begin block 2 */
// Start line: 1059
/* end block 2 */
// End Line: 1060

long FONT_Get2DImageIndex(uchar c)

{
	return (uint)fontTransTable[(uint)c];
}

// decompiled code
// original method signature:
// void /*$ra*/ drawChar2DPoly(long fpi /*$a0*/, long x /*$s0*/, long y /*$a2*/)
// line 558, offset 0x8002cdc8
/* begin block 1 */
// Start line: 559
// Start offset: 0x8002CDC8
// Variables:
// 		unsigned long **drawOT; // $s1
// 		struct POLY_FT4 *textPoly; // $a3
// 		long xl; // $t8
// 		long xr; // $s0
// 		long yt; // $a0
// 		long yb; // $a2
// 		long w; // $a0
// 		long h; // $v0
// 		int u; // $v1
// 		int v; // $a0
// 		int u0; // $t3
// 		int v0; // $t2
// 		int u1; // $t5
// 		int v1; // $t1
// 		int u2; // $t7
// 		int v2; // $t0
// 		int u3; // $t6
// 		int v3; // $t4

/* begin block 1.1 */
// Start line: 606
// Start offset: 0x8002CE78
/* end block 1.1 */
// End offset: 0x8002CE88
// End Line: 615

/* begin block 1.2 */
// Start line: 618
// Start offset: 0x8002CE90
// Variables:
// 		int holdu; // $v0
// 		int holdv; // $v1
/* end block 1.2 */
// End offset: 0x8002CEC0
// End Line: 627

/* begin block 1.3 */
// Start line: 636
// Start offset: 0x8002CEEC
// Variables:
// 		struct font_color_t *color; // $v0
/* end block 1.3 */
// End offset: 0x8002CF2C
// End Line: 639
/* end block 1 */
// End offset: 0x8002CF2C
// End Line: 640

/* begin block 2 */
// Start line: 1116
/* end block 2 */
// End Line: 1117

void drawChar2DPoly(long fpi, long x, long y)

{
	char cVar1;
	char cVar2;
	short sVar3;
	ulong **ppuVar4;
	uint uVar5;
	short sVar6;
	short sVar7;
	ulong *puVar8;
	char cVar9;
	char cVar10;
	char cVar11;
	char cVar12;
	char cVar13;
	short sVar14;

	ppuVar4 = gameTrackerX.drawOT;
	cVar12 = fontPos[fpi].x;
	if (cVar12 < '\0')
	{
		cVar12 = -cVar12;
	}
	cVar11 = fontPos[fpi].y;
	if (cVar11 < '\0')
	{
		cVar11 = -cVar11;
	}
	cVar1 = fontPos[fpi].w;
	sVar14 = (short)cVar1;
	cVar2 = fontPos[fpi].h;
	sVar6 = (short)cVar2;
	cVar12 = cVar12 + (char)fontTracker.font_vramU;
	cVar11 = cVar11 + (char)fontTracker.font_vramV;
	if (cVar1 < '\0')
	{
		sVar14 = -(short)cVar1;
	}
	cVar13 = cVar12 + (char)sVar14;
	if (cVar2 < '\0')
	{
		sVar6 = -(short)cVar2;
	}
	cVar9 = cVar11 + (char)sVar6;
	sVar3 = (short)x;
	sVar6 = (short)y - (sVar6 + -0xc);
	puVar8 = (gameTrackerX.primPool)->nextPrim;
	sVar7 = (short)y + 0xc;
	cVar10 = cVar11;
	if (cVar2 < '\0')
	{
		cVar10 = cVar9;
		cVar9 = cVar11;
	}
	cVar11 = cVar12;
	if (cVar1 < '\0')
	{
		cVar11 = cVar13;
		cVar13 = cVar12;
	}
	*(undefined *)((int)puVar8 + 3) = 9;
	*(undefined *)((int)puVar8 + 7) = 0x2c;
	if (fontTracker.color_local == '\0')
	{
		*(undefined *)((int)puVar8 + 7) = 0x2d;
	}
	else
	{
		uVar5 = (uint)(byte)fontTracker.color_local;
		*(undefined *)((int)puVar8 + 7) = 0x2c;
		*(undefined *)(puVar8 + 1) = *(undefined *)&the_font_color_table[uVar5].r;
		*(undefined *)((int)puVar8 + 5) = *(undefined *)&the_font_color_table[uVar5].g;
		*(undefined *)((int)puVar8 + 6) = *(undefined *)&the_font_color_table[uVar5].b;
	}
	*(char *)(puVar8 + 3) = cVar11;
	*(char *)((int)puVar8 + 0xd) = cVar10;
	*(char *)(puVar8 + 5) = cVar13;
	*(char *)((int)puVar8 + 0x15) = cVar10;
	*(char *)(puVar8 + 7) = cVar11;
	*(char *)((int)puVar8 + 0x1d) = cVar9;
	*(char *)(puVar8 + 9) = cVar13;
	*(char *)((int)puVar8 + 0x25) = cVar9;
	*(short *)(puVar8 + 2) = sVar3;
	*(short *)((int)puVar8 + 10) = sVar6;
	*(short *)(puVar8 + 4) = sVar3 + sVar14;
	*(short *)((int)puVar8 + 0x12) = sVar6;
	*(short *)(puVar8 + 6) = sVar3;
	*(short *)((int)puVar8 + 0x1a) = sVar7;
	*(short *)(puVar8 + 8) = sVar3 + sVar14;
	*(short *)((int)puVar8 + 0x22) = sVar7;
	*(byte *)((int)puVar8 + 7) = *(byte *)((int)puVar8 + 7) & 0xfd;
	*(short *)((int)puVar8 + 0x16) = fontTracker.font_tpage;
	*(short *)((int)puVar8 + 0xe) = fontTracker.font_clut;
	*puVar8 = (uint)*ppuVar4 & 0xffffff | 0x9000000;
	*ppuVar4 = (ulong *)((uint)puVar8 & 0xffffff);
	(gameTrackerX.primPool)->nextPrim = puVar8 + 10;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ FONT_DrawChar2D(unsigned char c /*$fp*/, long x /*$s7*/, long y /*$s3*/)
// line 660, offset 0x8002cfc8
/* begin block 1 */
// Start line: 661
// Start offset: 0x8002CFC8
// Variables:
// 		long w; // $s0
// 		long h; // $s6
// 		long w1; // $a1
// 		long w2; // $s1
// 		long w3; // $s2
// 		long xoff; // $a1
// 		long yoff; // $a2
// 		int i1; // $a0
// 		int i2; // $s4
// 		int i3; // $s5
/* end block 1 */
// End offset: 0x8002D1CC
// End Line: 702

/* begin block 2 */
// Start line: 1438
/* end block 2 */
// End Line: 1439

/* begin block 3 */
// Start line: 1443
/* end block 3 */
// End Line: 1444

void FONT_DrawChar2D(uchar c, long x, long y)

{
	long y_00;
	int iVar1;
	int iVar2;
	int iVar3;
	int iVar4;
	int fpi;
	int iVar5;
	int fpi_00;
	int fpi_01;

	if ((gameTrackerX.primPool)->nextPrim <= (gameTrackerX.primPool)->lastPrim + -0xc)
	{
		y_00 = FONT_Get2DImageIndex(c);
		fpi_01 = y_00 * 3;
		fpi = (int)(&charMap)[fpi_01];
		fpi_00 = (int)(&CHAR_FFh_800c8621)[fpi_01];
		fpi_01 = (int)s__9_800c8622[fpi_01];
		if (fpi < 0)
		{
			iVar1 = 8;
		}
		else
		{
			iVar1 = (int)fontPos[fpi].w;
			if (iVar1 < 0)
			{
				iVar1 = -iVar1;
			}
		}
		iVar2 = iVar1;
		if ((-1 < fpi_00) && (iVar2 = (int)fontPos[fpi_00].w, iVar2 < 0))
		{
			iVar2 = -iVar2;
		}
		iVar3 = iVar1;
		if ((-1 < fpi_01) && (iVar3 = (int)fontPos[fpi_01].w, iVar3 < 0))
		{
			iVar3 = -iVar3;
		}
		if (iVar2 < iVar1)
		{
			iVar5 = iVar3;
			if (iVar3 < iVar1)
			{
				iVar5 = iVar1;
			}
		}
		else
		{
			iVar5 = iVar3;
			if (iVar3 < iVar2)
			{
				iVar5 = iVar2;
			}
		}
		if (fpi < 0)
		{
			iVar4 = 0xc;
		}
		else
		{
			iVar4 = (int)fontPos[fpi].h;
			if (iVar4 < 0)
			{
				iVar4 = -iVar4;
			}
		}
		if (-1 < fpi)
		{
			drawChar2DPoly(fpi, x + ((int)((iVar5 - iVar1) + ((uint)(iVar5 - iVar1) >> 0x1f)) >> 1), y);
		}
		y_00 = y;
		if (c == 'A')
		{
			y_00 = y + 2;
		}
		if (c == '\'')
		{
			y = y + 3;
		}
		if (-1 < fpi_00)
		{
			drawChar2DPoly(fpi_00, x + ((int)((iVar5 - iVar2) + ((uint)(iVar5 - iVar2) >> 0x1f)) >> 1), y_00);
		}
		if (-1 < fpi_01)
		{
			drawChar2DPoly(fpi_01, x + ((int)((iVar5 - iVar3) + ((uint)(iVar5 - iVar3) >> 0x1f)) >> 1),
						   (y + 1) - iVar4);
		}
	}
	return;
}

// decompiled code
// original method signature:
// long /*$ra*/ FONT_CharSpacing(char c /*$a0*/, long fontXSize /*$s0*/)
// line 704, offset 0x8002d1fc
/* begin block 1 */
// Start line: 705
// Start offset: 0x8002D1FC
// Variables:
// 		long index; // $a0
// 		long w; // $v1
// 		long w1; // $a2
// 		long w2; // $a1
// 		long w3; // $v1
// 		char i1; // $v1
// 		char i2; // $a3
// 		char i3; // $t1

/* begin block 1.1 */
// Start line: 717
// Start offset: 0x8002D230
// Variables:
// 		int holdw; // $a0
// 		int holdw2; // $a0
/* end block 1.1 */
// End offset: 0x8002D32C
// End Line: 741
/* end block 1 */
// End offset: 0x8002D330
// End Line: 746

/* begin block 2 */
// Start line: 1531
/* end block 2 */
// End Line: 1532

long FONT_CharSpacing(char c, long fontXSize)

{
	int iVar1;
	long lVar2;
	int iVar3;
	int iVar4;
	int iVar5;
	int iVar6;

	if ((c != ' ') && (lVar2 = FONT_Get2DImageIndex(c), lVar2 != -1))
	{
		iVar1 = lVar2 * 3;
		iVar3 = (int)(&charMap)[iVar1];
		iVar5 = (int)fontPos[iVar3].w;
		if (iVar5 < 0)
		{
			iVar5 = -iVar5;
		}
		if (fontPos[iVar3].x < '\0')
		{
			iVar5 = (int)fontPos[iVar3].h;
		}
		iVar3 = 8;
		if (-1 < (int)((uint)(byte)(&charMap)[iVar1] << 0x18))
		{
			iVar3 = iVar5;
		}
		iVar5 = (int)fontPos[(int)(&CHAR_FFh_800c8621)[iVar1]].w;
		if (iVar5 < 0)
		{
			iVar5 = -iVar5;
		}
		iVar6 = iVar3;
		if (-1 < (int)(&CHAR_FFh_800c8621)[iVar1])
		{
			iVar6 = iVar5;
		}
		iVar5 = (int)fontPos[(int)s__9_800c8622[iVar1]].w;
		if (iVar5 < 0)
		{
			iVar5 = -iVar5;
		}
		iVar4 = iVar3;
		if (-1 < (int)s__9_800c8622[iVar1])
		{
			iVar4 = iVar5;
		}
		if (iVar6 < iVar3)
		{
			iVar6 = iVar3;
		}
		fontXSize = iVar4 + 1;
		if (iVar4 < iVar6)
		{
			fontXSize = iVar6 + 1;
		}
	}
	return fontXSize;
}

// decompiled code
// original method signature:
// void /*$ra*/ FONT_AddCharToBuffer(char c /*$a3*/, long x /*$a1*/, long y /*$a2*/)
// line 1059, offset 0x8002d340
/* begin block 1 */
// Start line: 1060
// Start offset: 0x8002D340
// Variables:
// 		struct FontChar *fontChar; // $a0
/* end block 1 */
// End offset: 0x8002D3A4
// End Line: 1079

/* begin block 2 */
// Start line: 2118
/* end block 2 */
// End Line: 2119

void FONT_AddCharToBuffer(char c, long x, long y)

{
	long lVar1;

	lVar1 = fontTracker.font_buffIndex;
	if (fontTracker.font_buffIndex < 0xff)
	{
		if (c == '@')
		{
			fontTracker.font_buffer[fontTracker.font_buffIndex].x = (ushort)x & 0xff;
			fontTracker.font_buffer[lVar1].y = (ushort)y & 0xff;
		}
		else
		{
			fontTracker.font_buffer[fontTracker.font_buffIndex].x = (ushort)x;
			fontTracker.font_buffer[lVar1].y = (ushort)y;
		}
		fontTracker.font_buffer[lVar1].c = c;
		fontTracker.font_buffIndex = fontTracker.font_buffIndex + 1;
		fontTracker.font_buffer[lVar1].color = fontTracker.color_global;
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ FONT_Print(char *fmt /*stack 0*/)
// line 1096, offset 0x8002d3ac
/* begin block 1 */
// Start line: 1097
// Start offset: 0x8002D3AC
// Variables:
// 		char *hold; // $v1
// 		void *ap; // $s0
/* end block 1 */
// End offset: 0x8002D420
// End Line: 1111

/* begin block 2 */
// Start line: 2007
/* end block 2 */
// End Line: 2008

void FONT_Print(char *fmt)

{
	byte bVar1;
	char *pcVar2;
	undefined local_res4[12];

	vsprintf(&fp_str, fmt, local_res4);
	pcVar2 = &fp_str;
	bVar1 = fp_str;
	while (bVar1 != 0)
	{
		if ((uint)(byte)*pcVar2 - 0x41 < 0x1a)
		{
			*pcVar2 = *pcVar2 + 0x20;
		}
		pcVar2 = (char *)((byte *)pcVar2 + 1);
		bVar1 = *pcVar2;
	}
	FONT_VaReallyPrint(&fp_str, local_res4);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ FONT_Print2(char *fmt /*stack 0*/)
// line 1115, offset 0x8002d43c
/* begin block 1 */
// Start line: 1116
// Start offset: 0x8002D43C
// Variables:
// 		void *ap; // $s0
/* end block 1 */
// End offset: 0x8002D43C
// End Line: 1116

/* begin block 2 */
// Start line: 2060
/* end block 2 */
// End Line: 2061

void FONT_Print2(char *fmt)

{
	undefined local_res4[12];

	vsprintf(&fp_str, fmt, local_res4);
	FONT_VaReallyPrint(&fp_str, local_res4);
	return;
}

// decompiled code
// original method signature:
// int /*$ra*/ FONT_GetStringWidth(char *str /*$s3*/)
// line 1168, offset 0x8002d48c
/* begin block 1 */
// Start line: 1169
// Start offset: 0x8002D48C
// Variables:
// 		int w; // $s1
// 		int len; // $s2
// 		int i; // $s0
/* end block 1 */
// End offset: 0x8002D4E0
// End Line: 1176

/* begin block 2 */
// Start line: 2336
/* end block 2 */
// End Line: 2337

int FONT_GetStringWidth(char *str)

{
	size_t sVar1;
	char *pcVar2;
	long lVar3;
	int iVar4;
	int iVar5;

	sVar1 = strlen(str);
	iVar4 = 0;
	iVar5 = 0;
	pcVar2 = str;
	if (0 < (int)sVar1)
	{
		do
		{
			iVar4 = iVar4 + 1;
			lVar3 = FONT_CharSpacing(*pcVar2, 8);
			iVar5 = iVar5 + lVar3;
			pcVar2 = str + iVar4;
		} while (iVar4 < (int)sVar1);
	}
	return iVar5;
}

// decompiled code
// original method signature:
// void /*$ra*/ FONT_Flush()
// line 1212, offset 0x8002d500
/* begin block 1 */
// Start line: 1213
// Start offset: 0x8002D500
// Variables:
// 		long i; // $s1
// 		struct FontChar *fontChar; // $s0
/* end block 1 */
// End offset: 0x8002D574
// End Line: 1239

/* begin block 2 */
// Start line: 2424
/* end block 2 */
// End Line: 2425

/* WARNING: Unknown calling convention yet parameter storage is locked */

void FONT_Flush(void)

{
	FontTracker *fontChar;
	long lVar1;

	fontTracker.font_xpos = 10;
	fontTracker.font_ypos = 0x10;
	if (fontTracker.font_buffIndex != 0)
	{
		fontChar = &fontTracker;
		lVar1 = fontTracker.font_buffIndex;
		do
		{
			if ((*(char *)fontChar->font_buffer != ' ') && (*(char *)fontChar->font_buffer != '@'))
			{
				FONT_DrawChar((FontChar *)fontChar);
			}
			lVar1 = lVar1 + -1;
			fontChar = (FontTracker *)(fontChar->font_buffer + 1);
		} while (lVar1 != 0);
		fontTracker.font_buffIndex = 0;
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ FONT_SetCursor(short x /*$a0*/, short y /*$a1*/)
// line 1241, offset 0x8002d590
/* begin block 1 */
// Start line: 2263
/* end block 1 */
// End Line: 2264

/* begin block 2 */
// Start line: 2267
/* end block 2 */
// End Line: 2268

void FONT_SetCursor(short x, short y)

{
	fontTracker.font_xpos = (int)x;
	fontTracker.font_ypos = (int)y;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ FONT_VaReallyPrint(char *fmt /*$a0*/, void *ap /*$a1*/)
// line 1280, offset 0x8002d5b0
/* begin block 1 */
// Start line: 1281
// Start offset: 0x8002D5B0
// Variables:
// 		char *p; // $s2
// 		long *xpos; // $s3
// 		long *ypos; // $s4

/* begin block 1.1 */
// Start line: 1302
// Start offset: 0x8002D628
// Variables:
// 		unsigned char w; // $s0
// 		unsigned char h; // $s1
/* end block 1.1 */
// End offset: 0x8002D628
// End Line: 1304
/* end block 1 */
// End offset: 0x8002D710
// End Line: 1334

/* begin block 2 */
// Start line: 2560
/* end block 2 */
// End Line: 2561

void FONT_VaReallyPrint(char *fmt, void *ap)

{
	byte bVar1;
	byte bVar2;
	long lVar3;

	bVar1 = *fmt;
	do
	{
		if (bVar1 == 0)
		{
			return;
		}
		if (bVar1 == 10)
		{
			fontTracker.font_ypos = fontTracker.font_ypos + 0xc;
			fontTracker.font_xpos = (uint)bVar1;
		LAB_8002d6fc:
			fmt = (char *)((byte *)fmt + 1);
		}
		else
		{
			if (bVar1 != 0x40)
			{
				if (bVar1 == 0x24)
				{
					fontTracker.font_xpos = 10;
					fontTracker.font_ypos = 0x10;
				}
				else
				{
					if (bVar1 == 0xd)
					{
						fontTracker.font_xpos = 10;
					}
					else
					{
						if (bVar1 == 9)
						{
							fontTracker.font_xpos = fontTracker.font_xpos + 0x20;
						}
						else
						{
							if ((bVar1 == 0x20) || (bVar1 == 0x5f))
							{
								fontTracker.font_xpos = fontTracker.font_xpos + 8;
							}
							else
							{
								FONT_AddCharToBuffer(*fmt, fontTracker.font_xpos, fontTracker.font_ypos);
								lVar3 = FONT_CharSpacing(*fmt, 8);
								fontTracker.font_xpos = fontTracker.font_xpos + lVar3;
							}
						}
					}
				}
				goto LAB_8002d6fc;
			}
			bVar1 = ((byte *)fmt)[1];
			bVar2 = ((byte *)fmt)[2];
			FONT_AddCharToBuffer('@', fontTracker.font_xpos, fontTracker.font_ypos);
			FONT_AddCharToBuffer('@', (uint)bVar2 - 0x40 & 0xff, (uint)bVar1 - 0x40 & 0xff);
			fmt = (char *)((byte *)fmt + 3);
		}
		bVar1 = *fmt;
	} while (true);
}

// decompiled code
// original method signature:
// void /*$ra*/ FONT_FontPrintCentered(char *text /*$s1*/, long y /*$s0*/)
// line 1336, offset 0x8002d740
/* begin block 1 */
// Start line: 2495
/* end block 1 */
// End Line: 2496

void FONT_FontPrintCentered(char *text, long y)

{
	int iVar1;

	iVar1 = FONT_GetStringWidth(text);
	FONT_SetCursor((short)((uint)((0x100 - (iVar1 >> 1)) * 0x10000) >> 0x10), (short)y);
	FONT_Print2(text);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ FONT_SetColorIndex(int color /*$a0*/)
// line 1343, offset 0x8002d798
/* begin block 1 */
// Start line: 2509
/* end block 1 */
// End Line: 2510

/* begin block 2 */
// Start line: 2511
/* end block 2 */
// End Line: 2512

void FONT_SetColorIndex(int color)

{
	fontTracker.color_global = (char)color;
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ FONT_SetColorIndexCol(int color /*$a0*/, int r /*$a1*/, int g /*$a2*/, int b /*$a3*/)
// line 1349, offset 0x8002d7a4
/* begin block 1 */
// Start line: 1351
// Start offset: 0x8002D7A4
// Variables:
// 		struct font_color_t *fcol; // $v0
/* end block 1 */
// End offset: 0x8002D7A4
// End Line: 1354

/* begin block 2 */
// Start line: 2521
/* end block 2 */
// End Line: 2522

/* begin block 3 */
// Start line: 2522
/* end block 3 */
// End Line: 2523

/* begin block 4 */
// Start line: 2525
/* end block 4 */
// End Line: 2526

void FONT_SetColorIndexCol(int color, int r, int g, int b)

{
	the_font_color_table[color].r = r;
	the_font_color_table[color].g = g;
	the_font_color_table[color].b = b;
	return;
}
