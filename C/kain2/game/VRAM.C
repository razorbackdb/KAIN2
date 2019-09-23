#include "THISDUST.H"
#include "VRAM.H"

// _BlockVramEntry * @0x800D482C, len = 0x00000004
openVramBlocks = null;
// _BlockVramEntry @0x800D480C, len = 0x0000001C
TerrainVramBlock =
	{
		// _BlockVramEntry * @0x800D480C, len = 0x00000004
		.next = null,
		// uchar @0x800D4810, len = 0x00000001
		.type = 0x00,
		// uchar @0x800D4811, len = 0x00000001
		.flags = 0x00,
		// short @0x800D4812, len = 0x00000002
		.time = null,
		// short @0x800D4814, len = 0x00000002
		.newX = null,
		// short @0x800D4816, len = 0x00000002
		.newY = null,
		// short @0x800D4818, len = 0x00000002
		.x = null,
		// short @0x800D481A, len = 0x00000002
		.y = null,
		// short @0x800D481C, len = 0x00000002
		.w = null,
		// short @0x800D481E, len = 0x00000002
		.h = null,
		// long @0x800D4820, len = 0x00000004
		.area = null,
		// DEBUG_256fake @0x800D4824, len = 0x00000004
		.udata =
			{
				// _StreamUnit * @0x800D4824, len = 0x00000004
				.streamUnit = null,
				// _ObjectTracker * @0x800D4824, len = 0x00000004
				.streamObject = null,
				// _ButtonTexture * @0x800D4824, len = 0x00000004
				.button = null}};
// _BlockVramEntry * @0x800D4828, len = 0x00000004
usedVramBlocks = null;
// _BlockVramEntry[90] @0x800D3E2C, len = 0x000009D8
vramBlockList =
	{
		// _BlockVramEntry @0x800D3E2C, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D3E2C, len = 0x00000004
			.next = null,
			// uchar @0x800D3E30, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D3E31, len = 0x00000001
			.flags = 0x00,
			// short @0x800D3E32, len = 0x00000002
			.time = null,
			// short @0x800D3E34, len = 0x00000002
			.newX = null,
			// short @0x800D3E36, len = 0x00000002
			.newY = null,
			// short @0x800D3E38, len = 0x00000002
			.x = null,
			// short @0x800D3E3A, len = 0x00000002
			.y = null,
			// short @0x800D3E3C, len = 0x00000002
			.w = null,
			// short @0x800D3E3E, len = 0x00000002
			.h = null,
			// long @0x800D3E40, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D3E44, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D3E44, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D3E44, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D3E44, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D3E48, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D3E48, len = 0x00000004
			.next = null,
			// uchar @0x800D3E4C, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D3E4D, len = 0x00000001
			.flags = 0x00,
			// short @0x800D3E4E, len = 0x00000002
			.time = null,
			// short @0x800D3E50, len = 0x00000002
			.newX = null,
			// short @0x800D3E52, len = 0x00000002
			.newY = null,
			// short @0x800D3E54, len = 0x00000002
			.x = null,
			// short @0x800D3E56, len = 0x00000002
			.y = null,
			// short @0x800D3E58, len = 0x00000002
			.w = null,
			// short @0x800D3E5A, len = 0x00000002
			.h = null,
			// long @0x800D3E5C, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D3E60, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D3E60, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D3E60, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D3E60, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D3E64, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D3E64, len = 0x00000004
			.next = null,
			// uchar @0x800D3E68, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D3E69, len = 0x00000001
			.flags = 0x00,
			// short @0x800D3E6A, len = 0x00000002
			.time = null,
			// short @0x800D3E6C, len = 0x00000002
			.newX = null,
			// short @0x800D3E6E, len = 0x00000002
			.newY = null,
			// short @0x800D3E70, len = 0x00000002
			.x = null,
			// short @0x800D3E72, len = 0x00000002
			.y = null,
			// short @0x800D3E74, len = 0x00000002
			.w = null,
			// short @0x800D3E76, len = 0x00000002
			.h = null,
			// long @0x800D3E78, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D3E7C, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D3E7C, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D3E7C, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D3E7C, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D3E80, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D3E80, len = 0x00000004
			.next = null,
			// uchar @0x800D3E84, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D3E85, len = 0x00000001
			.flags = 0x00,
			// short @0x800D3E86, len = 0x00000002
			.time = null,
			// short @0x800D3E88, len = 0x00000002
			.newX = null,
			// short @0x800D3E8A, len = 0x00000002
			.newY = null,
			// short @0x800D3E8C, len = 0x00000002
			.x = null,
			// short @0x800D3E8E, len = 0x00000002
			.y = null,
			// short @0x800D3E90, len = 0x00000002
			.w = null,
			// short @0x800D3E92, len = 0x00000002
			.h = null,
			// long @0x800D3E94, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D3E98, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D3E98, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D3E98, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D3E98, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D3E9C, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D3E9C, len = 0x00000004
			.next = null,
			// uchar @0x800D3EA0, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D3EA1, len = 0x00000001
			.flags = 0x00,
			// short @0x800D3EA2, len = 0x00000002
			.time = null,
			// short @0x800D3EA4, len = 0x00000002
			.newX = null,
			// short @0x800D3EA6, len = 0x00000002
			.newY = null,
			// short @0x800D3EA8, len = 0x00000002
			.x = null,
			// short @0x800D3EAA, len = 0x00000002
			.y = null,
			// short @0x800D3EAC, len = 0x00000002
			.w = null,
			// short @0x800D3EAE, len = 0x00000002
			.h = null,
			// long @0x800D3EB0, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D3EB4, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D3EB4, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D3EB4, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D3EB4, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D3EB8, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D3EB8, len = 0x00000004
			.next = null,
			// uchar @0x800D3EBC, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D3EBD, len = 0x00000001
			.flags = 0x00,
			// short @0x800D3EBE, len = 0x00000002
			.time = null,
			// short @0x800D3EC0, len = 0x00000002
			.newX = null,
			// short @0x800D3EC2, len = 0x00000002
			.newY = null,
			// short @0x800D3EC4, len = 0x00000002
			.x = null,
			// short @0x800D3EC6, len = 0x00000002
			.y = null,
			// short @0x800D3EC8, len = 0x00000002
			.w = null,
			// short @0x800D3ECA, len = 0x00000002
			.h = null,
			// long @0x800D3ECC, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D3ED0, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D3ED0, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D3ED0, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D3ED0, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D3ED4, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D3ED4, len = 0x00000004
			.next = null,
			// uchar @0x800D3ED8, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D3ED9, len = 0x00000001
			.flags = 0x00,
			// short @0x800D3EDA, len = 0x00000002
			.time = null,
			// short @0x800D3EDC, len = 0x00000002
			.newX = null,
			// short @0x800D3EDE, len = 0x00000002
			.newY = null,
			// short @0x800D3EE0, len = 0x00000002
			.x = null,
			// short @0x800D3EE2, len = 0x00000002
			.y = null,
			// short @0x800D3EE4, len = 0x00000002
			.w = null,
			// short @0x800D3EE6, len = 0x00000002
			.h = null,
			// long @0x800D3EE8, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D3EEC, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D3EEC, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D3EEC, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D3EEC, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D3EF0, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D3EF0, len = 0x00000004
			.next = null,
			// uchar @0x800D3EF4, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D3EF5, len = 0x00000001
			.flags = 0x00,
			// short @0x800D3EF6, len = 0x00000002
			.time = null,
			// short @0x800D3EF8, len = 0x00000002
			.newX = null,
			// short @0x800D3EFA, len = 0x00000002
			.newY = null,
			// short @0x800D3EFC, len = 0x00000002
			.x = null,
			// short @0x800D3EFE, len = 0x00000002
			.y = null,
			// short @0x800D3F00, len = 0x00000002
			.w = null,
			// short @0x800D3F02, len = 0x00000002
			.h = null,
			// long @0x800D3F04, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D3F08, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D3F08, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D3F08, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D3F08, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D3F0C, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D3F0C, len = 0x00000004
			.next = null,
			// uchar @0x800D3F10, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D3F11, len = 0x00000001
			.flags = 0x00,
			// short @0x800D3F12, len = 0x00000002
			.time = null,
			// short @0x800D3F14, len = 0x00000002
			.newX = null,
			// short @0x800D3F16, len = 0x00000002
			.newY = null,
			// short @0x800D3F18, len = 0x00000002
			.x = null,
			// short @0x800D3F1A, len = 0x00000002
			.y = null,
			// short @0x800D3F1C, len = 0x00000002
			.w = null,
			// short @0x800D3F1E, len = 0x00000002
			.h = null,
			// long @0x800D3F20, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D3F24, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D3F24, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D3F24, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D3F24, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D3F28, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D3F28, len = 0x00000004
			.next = null,
			// uchar @0x800D3F2C, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D3F2D, len = 0x00000001
			.flags = 0x00,
			// short @0x800D3F2E, len = 0x00000002
			.time = null,
			// short @0x800D3F30, len = 0x00000002
			.newX = null,
			// short @0x800D3F32, len = 0x00000002
			.newY = null,
			// short @0x800D3F34, len = 0x00000002
			.x = null,
			// short @0x800D3F36, len = 0x00000002
			.y = null,
			// short @0x800D3F38, len = 0x00000002
			.w = null,
			// short @0x800D3F3A, len = 0x00000002
			.h = null,
			// long @0x800D3F3C, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D3F40, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D3F40, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D3F40, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D3F40, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D3F44, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D3F44, len = 0x00000004
			.next = null,
			// uchar @0x800D3F48, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D3F49, len = 0x00000001
			.flags = 0x00,
			// short @0x800D3F4A, len = 0x00000002
			.time = null,
			// short @0x800D3F4C, len = 0x00000002
			.newX = null,
			// short @0x800D3F4E, len = 0x00000002
			.newY = null,
			// short @0x800D3F50, len = 0x00000002
			.x = null,
			// short @0x800D3F52, len = 0x00000002
			.y = null,
			// short @0x800D3F54, len = 0x00000002
			.w = null,
			// short @0x800D3F56, len = 0x00000002
			.h = null,
			// long @0x800D3F58, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D3F5C, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D3F5C, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D3F5C, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D3F5C, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D3F60, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D3F60, len = 0x00000004
			.next = null,
			// uchar @0x800D3F64, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D3F65, len = 0x00000001
			.flags = 0x00,
			// short @0x800D3F66, len = 0x00000002
			.time = null,
			// short @0x800D3F68, len = 0x00000002
			.newX = null,
			// short @0x800D3F6A, len = 0x00000002
			.newY = null,
			// short @0x800D3F6C, len = 0x00000002
			.x = null,
			// short @0x800D3F6E, len = 0x00000002
			.y = null,
			// short @0x800D3F70, len = 0x00000002
			.w = null,
			// short @0x800D3F72, len = 0x00000002
			.h = null,
			// long @0x800D3F74, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D3F78, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D3F78, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D3F78, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D3F78, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D3F7C, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D3F7C, len = 0x00000004
			.next = null,
			// uchar @0x800D3F80, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D3F81, len = 0x00000001
			.flags = 0x00,
			// short @0x800D3F82, len = 0x00000002
			.time = null,
			// short @0x800D3F84, len = 0x00000002
			.newX = null,
			// short @0x800D3F86, len = 0x00000002
			.newY = null,
			// short @0x800D3F88, len = 0x00000002
			.x = null,
			// short @0x800D3F8A, len = 0x00000002
			.y = null,
			// short @0x800D3F8C, len = 0x00000002
			.w = null,
			// short @0x800D3F8E, len = 0x00000002
			.h = null,
			// long @0x800D3F90, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D3F94, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D3F94, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D3F94, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D3F94, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D3F98, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D3F98, len = 0x00000004
			.next = null,
			// uchar @0x800D3F9C, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D3F9D, len = 0x00000001
			.flags = 0x00,
			// short @0x800D3F9E, len = 0x00000002
			.time = null,
			// short @0x800D3FA0, len = 0x00000002
			.newX = null,
			// short @0x800D3FA2, len = 0x00000002
			.newY = null,
			// short @0x800D3FA4, len = 0x00000002
			.x = null,
			// short @0x800D3FA6, len = 0x00000002
			.y = null,
			// short @0x800D3FA8, len = 0x00000002
			.w = null,
			// short @0x800D3FAA, len = 0x00000002
			.h = null,
			// long @0x800D3FAC, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D3FB0, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D3FB0, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D3FB0, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D3FB0, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D3FB4, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D3FB4, len = 0x00000004
			.next = null,
			// uchar @0x800D3FB8, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D3FB9, len = 0x00000001
			.flags = 0x00,
			// short @0x800D3FBA, len = 0x00000002
			.time = null,
			// short @0x800D3FBC, len = 0x00000002
			.newX = null,
			// short @0x800D3FBE, len = 0x00000002
			.newY = null,
			// short @0x800D3FC0, len = 0x00000002
			.x = null,
			// short @0x800D3FC2, len = 0x00000002
			.y = null,
			// short @0x800D3FC4, len = 0x00000002
			.w = null,
			// short @0x800D3FC6, len = 0x00000002
			.h = null,
			// long @0x800D3FC8, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D3FCC, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D3FCC, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D3FCC, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D3FCC, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D3FD0, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D3FD0, len = 0x00000004
			.next = null,
			// uchar @0x800D3FD4, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D3FD5, len = 0x00000001
			.flags = 0x00,
			// short @0x800D3FD6, len = 0x00000002
			.time = null,
			// short @0x800D3FD8, len = 0x00000002
			.newX = null,
			// short @0x800D3FDA, len = 0x00000002
			.newY = null,
			// short @0x800D3FDC, len = 0x00000002
			.x = null,
			// short @0x800D3FDE, len = 0x00000002
			.y = null,
			// short @0x800D3FE0, len = 0x00000002
			.w = null,
			// short @0x800D3FE2, len = 0x00000002
			.h = null,
			// long @0x800D3FE4, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D3FE8, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D3FE8, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D3FE8, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D3FE8, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D3FEC, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D3FEC, len = 0x00000004
			.next = null,
			// uchar @0x800D3FF0, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D3FF1, len = 0x00000001
			.flags = 0x00,
			// short @0x800D3FF2, len = 0x00000002
			.time = null,
			// short @0x800D3FF4, len = 0x00000002
			.newX = null,
			// short @0x800D3FF6, len = 0x00000002
			.newY = null,
			// short @0x800D3FF8, len = 0x00000002
			.x = null,
			// short @0x800D3FFA, len = 0x00000002
			.y = null,
			// short @0x800D3FFC, len = 0x00000002
			.w = null,
			// short @0x800D3FFE, len = 0x00000002
			.h = null,
			// long @0x800D4000, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4004, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4004, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4004, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4004, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4008, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4008, len = 0x00000004
			.next = null,
			// uchar @0x800D400C, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D400D, len = 0x00000001
			.flags = 0x00,
			// short @0x800D400E, len = 0x00000002
			.time = null,
			// short @0x800D4010, len = 0x00000002
			.newX = null,
			// short @0x800D4012, len = 0x00000002
			.newY = null,
			// short @0x800D4014, len = 0x00000002
			.x = null,
			// short @0x800D4016, len = 0x00000002
			.y = null,
			// short @0x800D4018, len = 0x00000002
			.w = null,
			// short @0x800D401A, len = 0x00000002
			.h = null,
			// long @0x800D401C, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4020, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4020, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4020, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4020, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4024, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4024, len = 0x00000004
			.next = null,
			// uchar @0x800D4028, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4029, len = 0x00000001
			.flags = 0x00,
			// short @0x800D402A, len = 0x00000002
			.time = null,
			// short @0x800D402C, len = 0x00000002
			.newX = null,
			// short @0x800D402E, len = 0x00000002
			.newY = null,
			// short @0x800D4030, len = 0x00000002
			.x = null,
			// short @0x800D4032, len = 0x00000002
			.y = null,
			// short @0x800D4034, len = 0x00000002
			.w = null,
			// short @0x800D4036, len = 0x00000002
			.h = null,
			// long @0x800D4038, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D403C, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D403C, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D403C, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D403C, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4040, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4040, len = 0x00000004
			.next = null,
			// uchar @0x800D4044, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4045, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4046, len = 0x00000002
			.time = null,
			// short @0x800D4048, len = 0x00000002
			.newX = null,
			// short @0x800D404A, len = 0x00000002
			.newY = null,
			// short @0x800D404C, len = 0x00000002
			.x = null,
			// short @0x800D404E, len = 0x00000002
			.y = null,
			// short @0x800D4050, len = 0x00000002
			.w = null,
			// short @0x800D4052, len = 0x00000002
			.h = null,
			// long @0x800D4054, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4058, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4058, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4058, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4058, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D405C, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D405C, len = 0x00000004
			.next = null,
			// uchar @0x800D4060, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4061, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4062, len = 0x00000002
			.time = null,
			// short @0x800D4064, len = 0x00000002
			.newX = null,
			// short @0x800D4066, len = 0x00000002
			.newY = null,
			// short @0x800D4068, len = 0x00000002
			.x = null,
			// short @0x800D406A, len = 0x00000002
			.y = null,
			// short @0x800D406C, len = 0x00000002
			.w = null,
			// short @0x800D406E, len = 0x00000002
			.h = null,
			// long @0x800D4070, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4074, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4074, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4074, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4074, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4078, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4078, len = 0x00000004
			.next = null,
			// uchar @0x800D407C, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D407D, len = 0x00000001
			.flags = 0x00,
			// short @0x800D407E, len = 0x00000002
			.time = null,
			// short @0x800D4080, len = 0x00000002
			.newX = null,
			// short @0x800D4082, len = 0x00000002
			.newY = null,
			// short @0x800D4084, len = 0x00000002
			.x = null,
			// short @0x800D4086, len = 0x00000002
			.y = null,
			// short @0x800D4088, len = 0x00000002
			.w = null,
			// short @0x800D408A, len = 0x00000002
			.h = null,
			// long @0x800D408C, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4090, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4090, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4090, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4090, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4094, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4094, len = 0x00000004
			.next = null,
			// uchar @0x800D4098, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4099, len = 0x00000001
			.flags = 0x00,
			// short @0x800D409A, len = 0x00000002
			.time = null,
			// short @0x800D409C, len = 0x00000002
			.newX = null,
			// short @0x800D409E, len = 0x00000002
			.newY = null,
			// short @0x800D40A0, len = 0x00000002
			.x = null,
			// short @0x800D40A2, len = 0x00000002
			.y = null,
			// short @0x800D40A4, len = 0x00000002
			.w = null,
			// short @0x800D40A6, len = 0x00000002
			.h = null,
			// long @0x800D40A8, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D40AC, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D40AC, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D40AC, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D40AC, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D40B0, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D40B0, len = 0x00000004
			.next = null,
			// uchar @0x800D40B4, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D40B5, len = 0x00000001
			.flags = 0x00,
			// short @0x800D40B6, len = 0x00000002
			.time = null,
			// short @0x800D40B8, len = 0x00000002
			.newX = null,
			// short @0x800D40BA, len = 0x00000002
			.newY = null,
			// short @0x800D40BC, len = 0x00000002
			.x = null,
			// short @0x800D40BE, len = 0x00000002
			.y = null,
			// short @0x800D40C0, len = 0x00000002
			.w = null,
			// short @0x800D40C2, len = 0x00000002
			.h = null,
			// long @0x800D40C4, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D40C8, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D40C8, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D40C8, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D40C8, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D40CC, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D40CC, len = 0x00000004
			.next = null,
			// uchar @0x800D40D0, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D40D1, len = 0x00000001
			.flags = 0x00,
			// short @0x800D40D2, len = 0x00000002
			.time = null,
			// short @0x800D40D4, len = 0x00000002
			.newX = null,
			// short @0x800D40D6, len = 0x00000002
			.newY = null,
			// short @0x800D40D8, len = 0x00000002
			.x = null,
			// short @0x800D40DA, len = 0x00000002
			.y = null,
			// short @0x800D40DC, len = 0x00000002
			.w = null,
			// short @0x800D40DE, len = 0x00000002
			.h = null,
			// long @0x800D40E0, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D40E4, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D40E4, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D40E4, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D40E4, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D40E8, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D40E8, len = 0x00000004
			.next = null,
			// uchar @0x800D40EC, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D40ED, len = 0x00000001
			.flags = 0x00,
			// short @0x800D40EE, len = 0x00000002
			.time = null,
			// short @0x800D40F0, len = 0x00000002
			.newX = null,
			// short @0x800D40F2, len = 0x00000002
			.newY = null,
			// short @0x800D40F4, len = 0x00000002
			.x = null,
			// short @0x800D40F6, len = 0x00000002
			.y = null,
			// short @0x800D40F8, len = 0x00000002
			.w = null,
			// short @0x800D40FA, len = 0x00000002
			.h = null,
			// long @0x800D40FC, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4100, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4100, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4100, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4100, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4104, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4104, len = 0x00000004
			.next = null,
			// uchar @0x800D4108, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4109, len = 0x00000001
			.flags = 0x00,
			// short @0x800D410A, len = 0x00000002
			.time = null,
			// short @0x800D410C, len = 0x00000002
			.newX = null,
			// short @0x800D410E, len = 0x00000002
			.newY = null,
			// short @0x800D4110, len = 0x00000002
			.x = null,
			// short @0x800D4112, len = 0x00000002
			.y = null,
			// short @0x800D4114, len = 0x00000002
			.w = null,
			// short @0x800D4116, len = 0x00000002
			.h = null,
			// long @0x800D4118, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D411C, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D411C, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D411C, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D411C, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4120, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4120, len = 0x00000004
			.next = null,
			// uchar @0x800D4124, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4125, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4126, len = 0x00000002
			.time = null,
			// short @0x800D4128, len = 0x00000002
			.newX = null,
			// short @0x800D412A, len = 0x00000002
			.newY = null,
			// short @0x800D412C, len = 0x00000002
			.x = null,
			// short @0x800D412E, len = 0x00000002
			.y = null,
			// short @0x800D4130, len = 0x00000002
			.w = null,
			// short @0x800D4132, len = 0x00000002
			.h = null,
			// long @0x800D4134, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4138, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4138, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4138, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4138, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D413C, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D413C, len = 0x00000004
			.next = null,
			// uchar @0x800D4140, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4141, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4142, len = 0x00000002
			.time = null,
			// short @0x800D4144, len = 0x00000002
			.newX = null,
			// short @0x800D4146, len = 0x00000002
			.newY = null,
			// short @0x800D4148, len = 0x00000002
			.x = null,
			// short @0x800D414A, len = 0x00000002
			.y = null,
			// short @0x800D414C, len = 0x00000002
			.w = null,
			// short @0x800D414E, len = 0x00000002
			.h = null,
			// long @0x800D4150, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4154, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4154, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4154, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4154, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4158, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4158, len = 0x00000004
			.next = null,
			// uchar @0x800D415C, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D415D, len = 0x00000001
			.flags = 0x00,
			// short @0x800D415E, len = 0x00000002
			.time = null,
			// short @0x800D4160, len = 0x00000002
			.newX = null,
			// short @0x800D4162, len = 0x00000002
			.newY = null,
			// short @0x800D4164, len = 0x00000002
			.x = null,
			// short @0x800D4166, len = 0x00000002
			.y = null,
			// short @0x800D4168, len = 0x00000002
			.w = null,
			// short @0x800D416A, len = 0x00000002
			.h = null,
			// long @0x800D416C, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4170, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4170, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4170, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4170, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4174, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4174, len = 0x00000004
			.next = null,
			// uchar @0x800D4178, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4179, len = 0x00000001
			.flags = 0x00,
			// short @0x800D417A, len = 0x00000002
			.time = null,
			// short @0x800D417C, len = 0x00000002
			.newX = null,
			// short @0x800D417E, len = 0x00000002
			.newY = null,
			// short @0x800D4180, len = 0x00000002
			.x = null,
			// short @0x800D4182, len = 0x00000002
			.y = null,
			// short @0x800D4184, len = 0x00000002
			.w = null,
			// short @0x800D4186, len = 0x00000002
			.h = null,
			// long @0x800D4188, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D418C, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D418C, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D418C, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D418C, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4190, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4190, len = 0x00000004
			.next = null,
			// uchar @0x800D4194, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4195, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4196, len = 0x00000002
			.time = null,
			// short @0x800D4198, len = 0x00000002
			.newX = null,
			// short @0x800D419A, len = 0x00000002
			.newY = null,
			// short @0x800D419C, len = 0x00000002
			.x = null,
			// short @0x800D419E, len = 0x00000002
			.y = null,
			// short @0x800D41A0, len = 0x00000002
			.w = null,
			// short @0x800D41A2, len = 0x00000002
			.h = null,
			// long @0x800D41A4, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D41A8, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D41A8, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D41A8, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D41A8, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D41AC, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D41AC, len = 0x00000004
			.next = null,
			// uchar @0x800D41B0, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D41B1, len = 0x00000001
			.flags = 0x00,
			// short @0x800D41B2, len = 0x00000002
			.time = null,
			// short @0x800D41B4, len = 0x00000002
			.newX = null,
			// short @0x800D41B6, len = 0x00000002
			.newY = null,
			// short @0x800D41B8, len = 0x00000002
			.x = null,
			// short @0x800D41BA, len = 0x00000002
			.y = null,
			// short @0x800D41BC, len = 0x00000002
			.w = null,
			// short @0x800D41BE, len = 0x00000002
			.h = null,
			// long @0x800D41C0, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D41C4, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D41C4, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D41C4, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D41C4, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D41C8, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D41C8, len = 0x00000004
			.next = null,
			// uchar @0x800D41CC, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D41CD, len = 0x00000001
			.flags = 0x00,
			// short @0x800D41CE, len = 0x00000002
			.time = null,
			// short @0x800D41D0, len = 0x00000002
			.newX = null,
			// short @0x800D41D2, len = 0x00000002
			.newY = null,
			// short @0x800D41D4, len = 0x00000002
			.x = null,
			// short @0x800D41D6, len = 0x00000002
			.y = null,
			// short @0x800D41D8, len = 0x00000002
			.w = null,
			// short @0x800D41DA, len = 0x00000002
			.h = null,
			// long @0x800D41DC, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D41E0, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D41E0, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D41E0, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D41E0, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D41E4, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D41E4, len = 0x00000004
			.next = null,
			// uchar @0x800D41E8, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D41E9, len = 0x00000001
			.flags = 0x00,
			// short @0x800D41EA, len = 0x00000002
			.time = null,
			// short @0x800D41EC, len = 0x00000002
			.newX = null,
			// short @0x800D41EE, len = 0x00000002
			.newY = null,
			// short @0x800D41F0, len = 0x00000002
			.x = null,
			// short @0x800D41F2, len = 0x00000002
			.y = null,
			// short @0x800D41F4, len = 0x00000002
			.w = null,
			// short @0x800D41F6, len = 0x00000002
			.h = null,
			// long @0x800D41F8, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D41FC, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D41FC, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D41FC, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D41FC, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4200, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4200, len = 0x00000004
			.next = null,
			// uchar @0x800D4204, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4205, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4206, len = 0x00000002
			.time = null,
			// short @0x800D4208, len = 0x00000002
			.newX = null,
			// short @0x800D420A, len = 0x00000002
			.newY = null,
			// short @0x800D420C, len = 0x00000002
			.x = null,
			// short @0x800D420E, len = 0x00000002
			.y = null,
			// short @0x800D4210, len = 0x00000002
			.w = null,
			// short @0x800D4212, len = 0x00000002
			.h = null,
			// long @0x800D4214, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4218, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4218, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4218, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4218, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D421C, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D421C, len = 0x00000004
			.next = null,
			// uchar @0x800D4220, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4221, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4222, len = 0x00000002
			.time = null,
			// short @0x800D4224, len = 0x00000002
			.newX = null,
			// short @0x800D4226, len = 0x00000002
			.newY = null,
			// short @0x800D4228, len = 0x00000002
			.x = null,
			// short @0x800D422A, len = 0x00000002
			.y = null,
			// short @0x800D422C, len = 0x00000002
			.w = null,
			// short @0x800D422E, len = 0x00000002
			.h = null,
			// long @0x800D4230, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4234, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4234, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4234, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4234, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4238, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4238, len = 0x00000004
			.next = null,
			// uchar @0x800D423C, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D423D, len = 0x00000001
			.flags = 0x00,
			// short @0x800D423E, len = 0x00000002
			.time = null,
			// short @0x800D4240, len = 0x00000002
			.newX = null,
			// short @0x800D4242, len = 0x00000002
			.newY = null,
			// short @0x800D4244, len = 0x00000002
			.x = null,
			// short @0x800D4246, len = 0x00000002
			.y = null,
			// short @0x800D4248, len = 0x00000002
			.w = null,
			// short @0x800D424A, len = 0x00000002
			.h = null,
			// long @0x800D424C, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4250, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4250, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4250, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4250, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4254, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4254, len = 0x00000004
			.next = null,
			// uchar @0x800D4258, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4259, len = 0x00000001
			.flags = 0x00,
			// short @0x800D425A, len = 0x00000002
			.time = null,
			// short @0x800D425C, len = 0x00000002
			.newX = null,
			// short @0x800D425E, len = 0x00000002
			.newY = null,
			// short @0x800D4260, len = 0x00000002
			.x = null,
			// short @0x800D4262, len = 0x00000002
			.y = null,
			// short @0x800D4264, len = 0x00000002
			.w = null,
			// short @0x800D4266, len = 0x00000002
			.h = null,
			// long @0x800D4268, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D426C, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D426C, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D426C, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D426C, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4270, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4270, len = 0x00000004
			.next = null,
			// uchar @0x800D4274, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4275, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4276, len = 0x00000002
			.time = null,
			// short @0x800D4278, len = 0x00000002
			.newX = null,
			// short @0x800D427A, len = 0x00000002
			.newY = null,
			// short @0x800D427C, len = 0x00000002
			.x = null,
			// short @0x800D427E, len = 0x00000002
			.y = null,
			// short @0x800D4280, len = 0x00000002
			.w = null,
			// short @0x800D4282, len = 0x00000002
			.h = null,
			// long @0x800D4284, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4288, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4288, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4288, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4288, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D428C, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D428C, len = 0x00000004
			.next = null,
			// uchar @0x800D4290, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4291, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4292, len = 0x00000002
			.time = null,
			// short @0x800D4294, len = 0x00000002
			.newX = null,
			// short @0x800D4296, len = 0x00000002
			.newY = null,
			// short @0x800D4298, len = 0x00000002
			.x = null,
			// short @0x800D429A, len = 0x00000002
			.y = null,
			// short @0x800D429C, len = 0x00000002
			.w = null,
			// short @0x800D429E, len = 0x00000002
			.h = null,
			// long @0x800D42A0, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D42A4, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D42A4, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D42A4, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D42A4, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D42A8, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D42A8, len = 0x00000004
			.next = null,
			// uchar @0x800D42AC, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D42AD, len = 0x00000001
			.flags = 0x00,
			// short @0x800D42AE, len = 0x00000002
			.time = null,
			// short @0x800D42B0, len = 0x00000002
			.newX = null,
			// short @0x800D42B2, len = 0x00000002
			.newY = null,
			// short @0x800D42B4, len = 0x00000002
			.x = null,
			// short @0x800D42B6, len = 0x00000002
			.y = null,
			// short @0x800D42B8, len = 0x00000002
			.w = null,
			// short @0x800D42BA, len = 0x00000002
			.h = null,
			// long @0x800D42BC, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D42C0, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D42C0, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D42C0, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D42C0, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D42C4, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D42C4, len = 0x00000004
			.next = null,
			// uchar @0x800D42C8, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D42C9, len = 0x00000001
			.flags = 0x00,
			// short @0x800D42CA, len = 0x00000002
			.time = null,
			// short @0x800D42CC, len = 0x00000002
			.newX = null,
			// short @0x800D42CE, len = 0x00000002
			.newY = null,
			// short @0x800D42D0, len = 0x00000002
			.x = null,
			// short @0x800D42D2, len = 0x00000002
			.y = null,
			// short @0x800D42D4, len = 0x00000002
			.w = null,
			// short @0x800D42D6, len = 0x00000002
			.h = null,
			// long @0x800D42D8, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D42DC, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D42DC, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D42DC, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D42DC, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D42E0, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D42E0, len = 0x00000004
			.next = null,
			// uchar @0x800D42E4, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D42E5, len = 0x00000001
			.flags = 0x00,
			// short @0x800D42E6, len = 0x00000002
			.time = null,
			// short @0x800D42E8, len = 0x00000002
			.newX = null,
			// short @0x800D42EA, len = 0x00000002
			.newY = null,
			// short @0x800D42EC, len = 0x00000002
			.x = null,
			// short @0x800D42EE, len = 0x00000002
			.y = null,
			// short @0x800D42F0, len = 0x00000002
			.w = null,
			// short @0x800D42F2, len = 0x00000002
			.h = null,
			// long @0x800D42F4, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D42F8, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D42F8, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D42F8, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D42F8, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D42FC, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D42FC, len = 0x00000004
			.next = null,
			// uchar @0x800D4300, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4301, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4302, len = 0x00000002
			.time = null,
			// short @0x800D4304, len = 0x00000002
			.newX = null,
			// short @0x800D4306, len = 0x00000002
			.newY = null,
			// short @0x800D4308, len = 0x00000002
			.x = null,
			// short @0x800D430A, len = 0x00000002
			.y = null,
			// short @0x800D430C, len = 0x00000002
			.w = null,
			// short @0x800D430E, len = 0x00000002
			.h = null,
			// long @0x800D4310, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4314, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4314, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4314, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4314, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4318, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4318, len = 0x00000004
			.next = null,
			// uchar @0x800D431C, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D431D, len = 0x00000001
			.flags = 0x00,
			// short @0x800D431E, len = 0x00000002
			.time = null,
			// short @0x800D4320, len = 0x00000002
			.newX = null,
			// short @0x800D4322, len = 0x00000002
			.newY = null,
			// short @0x800D4324, len = 0x00000002
			.x = null,
			// short @0x800D4326, len = 0x00000002
			.y = null,
			// short @0x800D4328, len = 0x00000002
			.w = null,
			// short @0x800D432A, len = 0x00000002
			.h = null,
			// long @0x800D432C, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4330, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4330, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4330, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4330, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4334, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4334, len = 0x00000004
			.next = null,
			// uchar @0x800D4338, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4339, len = 0x00000001
			.flags = 0x00,
			// short @0x800D433A, len = 0x00000002
			.time = null,
			// short @0x800D433C, len = 0x00000002
			.newX = null,
			// short @0x800D433E, len = 0x00000002
			.newY = null,
			// short @0x800D4340, len = 0x00000002
			.x = null,
			// short @0x800D4342, len = 0x00000002
			.y = null,
			// short @0x800D4344, len = 0x00000002
			.w = null,
			// short @0x800D4346, len = 0x00000002
			.h = null,
			// long @0x800D4348, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D434C, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D434C, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D434C, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D434C, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4350, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4350, len = 0x00000004
			.next = null,
			// uchar @0x800D4354, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4355, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4356, len = 0x00000002
			.time = null,
			// short @0x800D4358, len = 0x00000002
			.newX = null,
			// short @0x800D435A, len = 0x00000002
			.newY = null,
			// short @0x800D435C, len = 0x00000002
			.x = null,
			// short @0x800D435E, len = 0x00000002
			.y = null,
			// short @0x800D4360, len = 0x00000002
			.w = null,
			// short @0x800D4362, len = 0x00000002
			.h = null,
			// long @0x800D4364, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4368, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4368, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4368, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4368, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D436C, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D436C, len = 0x00000004
			.next = null,
			// uchar @0x800D4370, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4371, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4372, len = 0x00000002
			.time = null,
			// short @0x800D4374, len = 0x00000002
			.newX = null,
			// short @0x800D4376, len = 0x00000002
			.newY = null,
			// short @0x800D4378, len = 0x00000002
			.x = null,
			// short @0x800D437A, len = 0x00000002
			.y = null,
			// short @0x800D437C, len = 0x00000002
			.w = null,
			// short @0x800D437E, len = 0x00000002
			.h = null,
			// long @0x800D4380, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4384, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4384, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4384, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4384, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4388, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4388, len = 0x00000004
			.next = null,
			// uchar @0x800D438C, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D438D, len = 0x00000001
			.flags = 0x00,
			// short @0x800D438E, len = 0x00000002
			.time = null,
			// short @0x800D4390, len = 0x00000002
			.newX = null,
			// short @0x800D4392, len = 0x00000002
			.newY = null,
			// short @0x800D4394, len = 0x00000002
			.x = null,
			// short @0x800D4396, len = 0x00000002
			.y = null,
			// short @0x800D4398, len = 0x00000002
			.w = null,
			// short @0x800D439A, len = 0x00000002
			.h = null,
			// long @0x800D439C, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D43A0, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D43A0, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D43A0, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D43A0, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D43A4, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D43A4, len = 0x00000004
			.next = null,
			// uchar @0x800D43A8, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D43A9, len = 0x00000001
			.flags = 0x00,
			// short @0x800D43AA, len = 0x00000002
			.time = null,
			// short @0x800D43AC, len = 0x00000002
			.newX = null,
			// short @0x800D43AE, len = 0x00000002
			.newY = null,
			// short @0x800D43B0, len = 0x00000002
			.x = null,
			// short @0x800D43B2, len = 0x00000002
			.y = null,
			// short @0x800D43B4, len = 0x00000002
			.w = null,
			// short @0x800D43B6, len = 0x00000002
			.h = null,
			// long @0x800D43B8, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D43BC, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D43BC, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D43BC, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D43BC, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D43C0, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D43C0, len = 0x00000004
			.next = null,
			// uchar @0x800D43C4, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D43C5, len = 0x00000001
			.flags = 0x00,
			// short @0x800D43C6, len = 0x00000002
			.time = null,
			// short @0x800D43C8, len = 0x00000002
			.newX = null,
			// short @0x800D43CA, len = 0x00000002
			.newY = null,
			// short @0x800D43CC, len = 0x00000002
			.x = null,
			// short @0x800D43CE, len = 0x00000002
			.y = null,
			// short @0x800D43D0, len = 0x00000002
			.w = null,
			// short @0x800D43D2, len = 0x00000002
			.h = null,
			// long @0x800D43D4, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D43D8, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D43D8, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D43D8, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D43D8, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D43DC, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D43DC, len = 0x00000004
			.next = null,
			// uchar @0x800D43E0, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D43E1, len = 0x00000001
			.flags = 0x00,
			// short @0x800D43E2, len = 0x00000002
			.time = null,
			// short @0x800D43E4, len = 0x00000002
			.newX = null,
			// short @0x800D43E6, len = 0x00000002
			.newY = null,
			// short @0x800D43E8, len = 0x00000002
			.x = null,
			// short @0x800D43EA, len = 0x00000002
			.y = null,
			// short @0x800D43EC, len = 0x00000002
			.w = null,
			// short @0x800D43EE, len = 0x00000002
			.h = null,
			// long @0x800D43F0, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D43F4, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D43F4, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D43F4, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D43F4, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D43F8, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D43F8, len = 0x00000004
			.next = null,
			// uchar @0x800D43FC, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D43FD, len = 0x00000001
			.flags = 0x00,
			// short @0x800D43FE, len = 0x00000002
			.time = null,
			// short @0x800D4400, len = 0x00000002
			.newX = null,
			// short @0x800D4402, len = 0x00000002
			.newY = null,
			// short @0x800D4404, len = 0x00000002
			.x = null,
			// short @0x800D4406, len = 0x00000002
			.y = null,
			// short @0x800D4408, len = 0x00000002
			.w = null,
			// short @0x800D440A, len = 0x00000002
			.h = null,
			// long @0x800D440C, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4410, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4410, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4410, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4410, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4414, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4414, len = 0x00000004
			.next = null,
			// uchar @0x800D4418, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4419, len = 0x00000001
			.flags = 0x00,
			// short @0x800D441A, len = 0x00000002
			.time = null,
			// short @0x800D441C, len = 0x00000002
			.newX = null,
			// short @0x800D441E, len = 0x00000002
			.newY = null,
			// short @0x800D4420, len = 0x00000002
			.x = null,
			// short @0x800D4422, len = 0x00000002
			.y = null,
			// short @0x800D4424, len = 0x00000002
			.w = null,
			// short @0x800D4426, len = 0x00000002
			.h = null,
			// long @0x800D4428, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D442C, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D442C, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D442C, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D442C, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4430, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4430, len = 0x00000004
			.next = null,
			// uchar @0x800D4434, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4435, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4436, len = 0x00000002
			.time = null,
			// short @0x800D4438, len = 0x00000002
			.newX = null,
			// short @0x800D443A, len = 0x00000002
			.newY = null,
			// short @0x800D443C, len = 0x00000002
			.x = null,
			// short @0x800D443E, len = 0x00000002
			.y = null,
			// short @0x800D4440, len = 0x00000002
			.w = null,
			// short @0x800D4442, len = 0x00000002
			.h = null,
			// long @0x800D4444, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4448, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4448, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4448, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4448, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D444C, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D444C, len = 0x00000004
			.next = null,
			// uchar @0x800D4450, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4451, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4452, len = 0x00000002
			.time = null,
			// short @0x800D4454, len = 0x00000002
			.newX = null,
			// short @0x800D4456, len = 0x00000002
			.newY = null,
			// short @0x800D4458, len = 0x00000002
			.x = null,
			// short @0x800D445A, len = 0x00000002
			.y = null,
			// short @0x800D445C, len = 0x00000002
			.w = null,
			// short @0x800D445E, len = 0x00000002
			.h = null,
			// long @0x800D4460, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4464, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4464, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4464, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4464, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4468, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4468, len = 0x00000004
			.next = null,
			// uchar @0x800D446C, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D446D, len = 0x00000001
			.flags = 0x00,
			// short @0x800D446E, len = 0x00000002
			.time = null,
			// short @0x800D4470, len = 0x00000002
			.newX = null,
			// short @0x800D4472, len = 0x00000002
			.newY = null,
			// short @0x800D4474, len = 0x00000002
			.x = null,
			// short @0x800D4476, len = 0x00000002
			.y = null,
			// short @0x800D4478, len = 0x00000002
			.w = null,
			// short @0x800D447A, len = 0x00000002
			.h = null,
			// long @0x800D447C, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4480, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4480, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4480, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4480, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4484, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4484, len = 0x00000004
			.next = null,
			// uchar @0x800D4488, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4489, len = 0x00000001
			.flags = 0x00,
			// short @0x800D448A, len = 0x00000002
			.time = null,
			// short @0x800D448C, len = 0x00000002
			.newX = null,
			// short @0x800D448E, len = 0x00000002
			.newY = null,
			// short @0x800D4490, len = 0x00000002
			.x = null,
			// short @0x800D4492, len = 0x00000002
			.y = null,
			// short @0x800D4494, len = 0x00000002
			.w = null,
			// short @0x800D4496, len = 0x00000002
			.h = null,
			// long @0x800D4498, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D449C, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D449C, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D449C, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D449C, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D44A0, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D44A0, len = 0x00000004
			.next = null,
			// uchar @0x800D44A4, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D44A5, len = 0x00000001
			.flags = 0x00,
			// short @0x800D44A6, len = 0x00000002
			.time = null,
			// short @0x800D44A8, len = 0x00000002
			.newX = null,
			// short @0x800D44AA, len = 0x00000002
			.newY = null,
			// short @0x800D44AC, len = 0x00000002
			.x = null,
			// short @0x800D44AE, len = 0x00000002
			.y = null,
			// short @0x800D44B0, len = 0x00000002
			.w = null,
			// short @0x800D44B2, len = 0x00000002
			.h = null,
			// long @0x800D44B4, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D44B8, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D44B8, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D44B8, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D44B8, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D44BC, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D44BC, len = 0x00000004
			.next = null,
			// uchar @0x800D44C0, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D44C1, len = 0x00000001
			.flags = 0x00,
			// short @0x800D44C2, len = 0x00000002
			.time = null,
			// short @0x800D44C4, len = 0x00000002
			.newX = null,
			// short @0x800D44C6, len = 0x00000002
			.newY = null,
			// short @0x800D44C8, len = 0x00000002
			.x = null,
			// short @0x800D44CA, len = 0x00000002
			.y = null,
			// short @0x800D44CC, len = 0x00000002
			.w = null,
			// short @0x800D44CE, len = 0x00000002
			.h = null,
			// long @0x800D44D0, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D44D4, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D44D4, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D44D4, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D44D4, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D44D8, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D44D8, len = 0x00000004
			.next = null,
			// uchar @0x800D44DC, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D44DD, len = 0x00000001
			.flags = 0x00,
			// short @0x800D44DE, len = 0x00000002
			.time = null,
			// short @0x800D44E0, len = 0x00000002
			.newX = null,
			// short @0x800D44E2, len = 0x00000002
			.newY = null,
			// short @0x800D44E4, len = 0x00000002
			.x = null,
			// short @0x800D44E6, len = 0x00000002
			.y = null,
			// short @0x800D44E8, len = 0x00000002
			.w = null,
			// short @0x800D44EA, len = 0x00000002
			.h = null,
			// long @0x800D44EC, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D44F0, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D44F0, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D44F0, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D44F0, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D44F4, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D44F4, len = 0x00000004
			.next = null,
			// uchar @0x800D44F8, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D44F9, len = 0x00000001
			.flags = 0x00,
			// short @0x800D44FA, len = 0x00000002
			.time = null,
			// short @0x800D44FC, len = 0x00000002
			.newX = null,
			// short @0x800D44FE, len = 0x00000002
			.newY = null,
			// short @0x800D4500, len = 0x00000002
			.x = null,
			// short @0x800D4502, len = 0x00000002
			.y = null,
			// short @0x800D4504, len = 0x00000002
			.w = null,
			// short @0x800D4506, len = 0x00000002
			.h = null,
			// long @0x800D4508, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D450C, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D450C, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D450C, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D450C, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4510, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4510, len = 0x00000004
			.next = null,
			// uchar @0x800D4514, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4515, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4516, len = 0x00000002
			.time = null,
			// short @0x800D4518, len = 0x00000002
			.newX = null,
			// short @0x800D451A, len = 0x00000002
			.newY = null,
			// short @0x800D451C, len = 0x00000002
			.x = null,
			// short @0x800D451E, len = 0x00000002
			.y = null,
			// short @0x800D4520, len = 0x00000002
			.w = null,
			// short @0x800D4522, len = 0x00000002
			.h = null,
			// long @0x800D4524, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4528, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4528, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4528, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4528, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D452C, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D452C, len = 0x00000004
			.next = null,
			// uchar @0x800D4530, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4531, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4532, len = 0x00000002
			.time = null,
			// short @0x800D4534, len = 0x00000002
			.newX = null,
			// short @0x800D4536, len = 0x00000002
			.newY = null,
			// short @0x800D4538, len = 0x00000002
			.x = null,
			// short @0x800D453A, len = 0x00000002
			.y = null,
			// short @0x800D453C, len = 0x00000002
			.w = null,
			// short @0x800D453E, len = 0x00000002
			.h = null,
			// long @0x800D4540, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4544, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4544, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4544, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4544, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4548, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4548, len = 0x00000004
			.next = null,
			// uchar @0x800D454C, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D454D, len = 0x00000001
			.flags = 0x00,
			// short @0x800D454E, len = 0x00000002
			.time = null,
			// short @0x800D4550, len = 0x00000002
			.newX = null,
			// short @0x800D4552, len = 0x00000002
			.newY = null,
			// short @0x800D4554, len = 0x00000002
			.x = null,
			// short @0x800D4556, len = 0x00000002
			.y = null,
			// short @0x800D4558, len = 0x00000002
			.w = null,
			// short @0x800D455A, len = 0x00000002
			.h = null,
			// long @0x800D455C, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4560, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4560, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4560, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4560, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4564, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4564, len = 0x00000004
			.next = null,
			// uchar @0x800D4568, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4569, len = 0x00000001
			.flags = 0x00,
			// short @0x800D456A, len = 0x00000002
			.time = null,
			// short @0x800D456C, len = 0x00000002
			.newX = null,
			// short @0x800D456E, len = 0x00000002
			.newY = null,
			// short @0x800D4570, len = 0x00000002
			.x = null,
			// short @0x800D4572, len = 0x00000002
			.y = null,
			// short @0x800D4574, len = 0x00000002
			.w = null,
			// short @0x800D4576, len = 0x00000002
			.h = null,
			// long @0x800D4578, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D457C, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D457C, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D457C, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D457C, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4580, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4580, len = 0x00000004
			.next = null,
			// uchar @0x800D4584, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4585, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4586, len = 0x00000002
			.time = null,
			// short @0x800D4588, len = 0x00000002
			.newX = null,
			// short @0x800D458A, len = 0x00000002
			.newY = null,
			// short @0x800D458C, len = 0x00000002
			.x = null,
			// short @0x800D458E, len = 0x00000002
			.y = null,
			// short @0x800D4590, len = 0x00000002
			.w = null,
			// short @0x800D4592, len = 0x00000002
			.h = null,
			// long @0x800D4594, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4598, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4598, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4598, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4598, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D459C, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D459C, len = 0x00000004
			.next = null,
			// uchar @0x800D45A0, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D45A1, len = 0x00000001
			.flags = 0x00,
			// short @0x800D45A2, len = 0x00000002
			.time = null,
			// short @0x800D45A4, len = 0x00000002
			.newX = null,
			// short @0x800D45A6, len = 0x00000002
			.newY = null,
			// short @0x800D45A8, len = 0x00000002
			.x = null,
			// short @0x800D45AA, len = 0x00000002
			.y = null,
			// short @0x800D45AC, len = 0x00000002
			.w = null,
			// short @0x800D45AE, len = 0x00000002
			.h = null,
			// long @0x800D45B0, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D45B4, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D45B4, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D45B4, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D45B4, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D45B8, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D45B8, len = 0x00000004
			.next = null,
			// uchar @0x800D45BC, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D45BD, len = 0x00000001
			.flags = 0x00,
			// short @0x800D45BE, len = 0x00000002
			.time = null,
			// short @0x800D45C0, len = 0x00000002
			.newX = null,
			// short @0x800D45C2, len = 0x00000002
			.newY = null,
			// short @0x800D45C4, len = 0x00000002
			.x = null,
			// short @0x800D45C6, len = 0x00000002
			.y = null,
			// short @0x800D45C8, len = 0x00000002
			.w = null,
			// short @0x800D45CA, len = 0x00000002
			.h = null,
			// long @0x800D45CC, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D45D0, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D45D0, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D45D0, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D45D0, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D45D4, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D45D4, len = 0x00000004
			.next = null,
			// uchar @0x800D45D8, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D45D9, len = 0x00000001
			.flags = 0x00,
			// short @0x800D45DA, len = 0x00000002
			.time = null,
			// short @0x800D45DC, len = 0x00000002
			.newX = null,
			// short @0x800D45DE, len = 0x00000002
			.newY = null,
			// short @0x800D45E0, len = 0x00000002
			.x = null,
			// short @0x800D45E2, len = 0x00000002
			.y = null,
			// short @0x800D45E4, len = 0x00000002
			.w = null,
			// short @0x800D45E6, len = 0x00000002
			.h = null,
			// long @0x800D45E8, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D45EC, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D45EC, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D45EC, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D45EC, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D45F0, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D45F0, len = 0x00000004
			.next = null,
			// uchar @0x800D45F4, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D45F5, len = 0x00000001
			.flags = 0x00,
			// short @0x800D45F6, len = 0x00000002
			.time = null,
			// short @0x800D45F8, len = 0x00000002
			.newX = null,
			// short @0x800D45FA, len = 0x00000002
			.newY = null,
			// short @0x800D45FC, len = 0x00000002
			.x = null,
			// short @0x800D45FE, len = 0x00000002
			.y = null,
			// short @0x800D4600, len = 0x00000002
			.w = null,
			// short @0x800D4602, len = 0x00000002
			.h = null,
			// long @0x800D4604, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4608, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4608, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4608, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4608, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D460C, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D460C, len = 0x00000004
			.next = null,
			// uchar @0x800D4610, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4611, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4612, len = 0x00000002
			.time = null,
			// short @0x800D4614, len = 0x00000002
			.newX = null,
			// short @0x800D4616, len = 0x00000002
			.newY = null,
			// short @0x800D4618, len = 0x00000002
			.x = null,
			// short @0x800D461A, len = 0x00000002
			.y = null,
			// short @0x800D461C, len = 0x00000002
			.w = null,
			// short @0x800D461E, len = 0x00000002
			.h = null,
			// long @0x800D4620, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4624, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4624, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4624, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4624, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4628, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4628, len = 0x00000004
			.next = null,
			// uchar @0x800D462C, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D462D, len = 0x00000001
			.flags = 0x00,
			// short @0x800D462E, len = 0x00000002
			.time = null,
			// short @0x800D4630, len = 0x00000002
			.newX = null,
			// short @0x800D4632, len = 0x00000002
			.newY = null,
			// short @0x800D4634, len = 0x00000002
			.x = null,
			// short @0x800D4636, len = 0x00000002
			.y = null,
			// short @0x800D4638, len = 0x00000002
			.w = null,
			// short @0x800D463A, len = 0x00000002
			.h = null,
			// long @0x800D463C, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4640, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4640, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4640, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4640, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4644, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4644, len = 0x00000004
			.next = null,
			// uchar @0x800D4648, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4649, len = 0x00000001
			.flags = 0x00,
			// short @0x800D464A, len = 0x00000002
			.time = null,
			// short @0x800D464C, len = 0x00000002
			.newX = null,
			// short @0x800D464E, len = 0x00000002
			.newY = null,
			// short @0x800D4650, len = 0x00000002
			.x = null,
			// short @0x800D4652, len = 0x00000002
			.y = null,
			// short @0x800D4654, len = 0x00000002
			.w = null,
			// short @0x800D4656, len = 0x00000002
			.h = null,
			// long @0x800D4658, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D465C, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D465C, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D465C, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D465C, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4660, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4660, len = 0x00000004
			.next = null,
			// uchar @0x800D4664, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4665, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4666, len = 0x00000002
			.time = null,
			// short @0x800D4668, len = 0x00000002
			.newX = null,
			// short @0x800D466A, len = 0x00000002
			.newY = null,
			// short @0x800D466C, len = 0x00000002
			.x = null,
			// short @0x800D466E, len = 0x00000002
			.y = null,
			// short @0x800D4670, len = 0x00000002
			.w = null,
			// short @0x800D4672, len = 0x00000002
			.h = null,
			// long @0x800D4674, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4678, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4678, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4678, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4678, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D467C, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D467C, len = 0x00000004
			.next = null,
			// uchar @0x800D4680, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4681, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4682, len = 0x00000002
			.time = null,
			// short @0x800D4684, len = 0x00000002
			.newX = null,
			// short @0x800D4686, len = 0x00000002
			.newY = null,
			// short @0x800D4688, len = 0x00000002
			.x = null,
			// short @0x800D468A, len = 0x00000002
			.y = null,
			// short @0x800D468C, len = 0x00000002
			.w = null,
			// short @0x800D468E, len = 0x00000002
			.h = null,
			// long @0x800D4690, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4694, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4694, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4694, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4694, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4698, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4698, len = 0x00000004
			.next = null,
			// uchar @0x800D469C, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D469D, len = 0x00000001
			.flags = 0x00,
			// short @0x800D469E, len = 0x00000002
			.time = null,
			// short @0x800D46A0, len = 0x00000002
			.newX = null,
			// short @0x800D46A2, len = 0x00000002
			.newY = null,
			// short @0x800D46A4, len = 0x00000002
			.x = null,
			// short @0x800D46A6, len = 0x00000002
			.y = null,
			// short @0x800D46A8, len = 0x00000002
			.w = null,
			// short @0x800D46AA, len = 0x00000002
			.h = null,
			// long @0x800D46AC, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D46B0, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D46B0, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D46B0, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D46B0, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D46B4, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D46B4, len = 0x00000004
			.next = null,
			// uchar @0x800D46B8, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D46B9, len = 0x00000001
			.flags = 0x00,
			// short @0x800D46BA, len = 0x00000002
			.time = null,
			// short @0x800D46BC, len = 0x00000002
			.newX = null,
			// short @0x800D46BE, len = 0x00000002
			.newY = null,
			// short @0x800D46C0, len = 0x00000002
			.x = null,
			// short @0x800D46C2, len = 0x00000002
			.y = null,
			// short @0x800D46C4, len = 0x00000002
			.w = null,
			// short @0x800D46C6, len = 0x00000002
			.h = null,
			// long @0x800D46C8, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D46CC, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D46CC, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D46CC, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D46CC, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D46D0, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D46D0, len = 0x00000004
			.next = null,
			// uchar @0x800D46D4, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D46D5, len = 0x00000001
			.flags = 0x00,
			// short @0x800D46D6, len = 0x00000002
			.time = null,
			// short @0x800D46D8, len = 0x00000002
			.newX = null,
			// short @0x800D46DA, len = 0x00000002
			.newY = null,
			// short @0x800D46DC, len = 0x00000002
			.x = null,
			// short @0x800D46DE, len = 0x00000002
			.y = null,
			// short @0x800D46E0, len = 0x00000002
			.w = null,
			// short @0x800D46E2, len = 0x00000002
			.h = null,
			// long @0x800D46E4, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D46E8, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D46E8, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D46E8, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D46E8, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D46EC, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D46EC, len = 0x00000004
			.next = null,
			// uchar @0x800D46F0, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D46F1, len = 0x00000001
			.flags = 0x00,
			// short @0x800D46F2, len = 0x00000002
			.time = null,
			// short @0x800D46F4, len = 0x00000002
			.newX = null,
			// short @0x800D46F6, len = 0x00000002
			.newY = null,
			// short @0x800D46F8, len = 0x00000002
			.x = null,
			// short @0x800D46FA, len = 0x00000002
			.y = null,
			// short @0x800D46FC, len = 0x00000002
			.w = null,
			// short @0x800D46FE, len = 0x00000002
			.h = null,
			// long @0x800D4700, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4704, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4704, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4704, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4704, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4708, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4708, len = 0x00000004
			.next = null,
			// uchar @0x800D470C, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D470D, len = 0x00000001
			.flags = 0x00,
			// short @0x800D470E, len = 0x00000002
			.time = null,
			// short @0x800D4710, len = 0x00000002
			.newX = null,
			// short @0x800D4712, len = 0x00000002
			.newY = null,
			// short @0x800D4714, len = 0x00000002
			.x = null,
			// short @0x800D4716, len = 0x00000002
			.y = null,
			// short @0x800D4718, len = 0x00000002
			.w = null,
			// short @0x800D471A, len = 0x00000002
			.h = null,
			// long @0x800D471C, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4720, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4720, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4720, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4720, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4724, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4724, len = 0x00000004
			.next = null,
			// uchar @0x800D4728, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4729, len = 0x00000001
			.flags = 0x00,
			// short @0x800D472A, len = 0x00000002
			.time = null,
			// short @0x800D472C, len = 0x00000002
			.newX = null,
			// short @0x800D472E, len = 0x00000002
			.newY = null,
			// short @0x800D4730, len = 0x00000002
			.x = null,
			// short @0x800D4732, len = 0x00000002
			.y = null,
			// short @0x800D4734, len = 0x00000002
			.w = null,
			// short @0x800D4736, len = 0x00000002
			.h = null,
			// long @0x800D4738, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D473C, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D473C, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D473C, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D473C, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4740, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4740, len = 0x00000004
			.next = null,
			// uchar @0x800D4744, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4745, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4746, len = 0x00000002
			.time = null,
			// short @0x800D4748, len = 0x00000002
			.newX = null,
			// short @0x800D474A, len = 0x00000002
			.newY = null,
			// short @0x800D474C, len = 0x00000002
			.x = null,
			// short @0x800D474E, len = 0x00000002
			.y = null,
			// short @0x800D4750, len = 0x00000002
			.w = null,
			// short @0x800D4752, len = 0x00000002
			.h = null,
			// long @0x800D4754, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4758, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4758, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4758, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4758, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D475C, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D475C, len = 0x00000004
			.next = null,
			// uchar @0x800D4760, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4761, len = 0x00000001
			.flags = 0x00,
			// short @0x800D4762, len = 0x00000002
			.time = null,
			// short @0x800D4764, len = 0x00000002
			.newX = null,
			// short @0x800D4766, len = 0x00000002
			.newY = null,
			// short @0x800D4768, len = 0x00000002
			.x = null,
			// short @0x800D476A, len = 0x00000002
			.y = null,
			// short @0x800D476C, len = 0x00000002
			.w = null,
			// short @0x800D476E, len = 0x00000002
			.h = null,
			// long @0x800D4770, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4774, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4774, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4774, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4774, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4778, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4778, len = 0x00000004
			.next = null,
			// uchar @0x800D477C, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D477D, len = 0x00000001
			.flags = 0x00,
			// short @0x800D477E, len = 0x00000002
			.time = null,
			// short @0x800D4780, len = 0x00000002
			.newX = null,
			// short @0x800D4782, len = 0x00000002
			.newY = null,
			// short @0x800D4784, len = 0x00000002
			.x = null,
			// short @0x800D4786, len = 0x00000002
			.y = null,
			// short @0x800D4788, len = 0x00000002
			.w = null,
			// short @0x800D478A, len = 0x00000002
			.h = null,
			// long @0x800D478C, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4790, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4790, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4790, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4790, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D4794, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D4794, len = 0x00000004
			.next = null,
			// uchar @0x800D4798, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D4799, len = 0x00000001
			.flags = 0x00,
			// short @0x800D479A, len = 0x00000002
			.time = null,
			// short @0x800D479C, len = 0x00000002
			.newX = null,
			// short @0x800D479E, len = 0x00000002
			.newY = null,
			// short @0x800D47A0, len = 0x00000002
			.x = null,
			// short @0x800D47A2, len = 0x00000002
			.y = null,
			// short @0x800D47A4, len = 0x00000002
			.w = null,
			// short @0x800D47A6, len = 0x00000002
			.h = null,
			// long @0x800D47A8, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D47AC, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D47AC, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D47AC, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D47AC, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D47B0, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D47B0, len = 0x00000004
			.next = null,
			// uchar @0x800D47B4, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D47B5, len = 0x00000001
			.flags = 0x00,
			// short @0x800D47B6, len = 0x00000002
			.time = null,
			// short @0x800D47B8, len = 0x00000002
			.newX = null,
			// short @0x800D47BA, len = 0x00000002
			.newY = null,
			// short @0x800D47BC, len = 0x00000002
			.x = null,
			// short @0x800D47BE, len = 0x00000002
			.y = null,
			// short @0x800D47C0, len = 0x00000002
			.w = null,
			// short @0x800D47C2, len = 0x00000002
			.h = null,
			// long @0x800D47C4, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D47C8, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D47C8, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D47C8, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D47C8, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D47CC, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D47CC, len = 0x00000004
			.next = null,
			// uchar @0x800D47D0, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D47D1, len = 0x00000001
			.flags = 0x00,
			// short @0x800D47D2, len = 0x00000002
			.time = null,
			// short @0x800D47D4, len = 0x00000002
			.newX = null,
			// short @0x800D47D6, len = 0x00000002
			.newY = null,
			// short @0x800D47D8, len = 0x00000002
			.x = null,
			// short @0x800D47DA, len = 0x00000002
			.y = null,
			// short @0x800D47DC, len = 0x00000002
			.w = null,
			// short @0x800D47DE, len = 0x00000002
			.h = null,
			// long @0x800D47E0, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D47E4, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D47E4, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D47E4, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D47E4, len = 0x00000004
					.button = null}},
		// _BlockVramEntry @0x800D47E8, len = 0x0000001C
		{
			// _BlockVramEntry * @0x800D47E8, len = 0x00000004
			.next = null,
			// uchar @0x800D47EC, len = 0x00000001
			.type = 0x00,
			// uchar @0x800D47ED, len = 0x00000001
			.flags = 0x00,
			// short @0x800D47EE, len = 0x00000002
			.time = null,
			// short @0x800D47F0, len = 0x00000002
			.newX = null,
			// short @0x800D47F2, len = 0x00000002
			.newY = null,
			// short @0x800D47F4, len = 0x00000002
			.x = null,
			// short @0x800D47F6, len = 0x00000002
			.y = null,
			// short @0x800D47F8, len = 0x00000002
			.w = null,
			// short @0x800D47FA, len = 0x00000002
			.h = null,
			// long @0x800D47FC, len = 0x00000004
			.area = null,
			// DEBUG_256fake @0x800D4800, len = 0x00000004
			.udata =
				{
					// _StreamUnit * @0x800D4800, len = 0x00000004
					.streamUnit = null,
					// _ObjectTracker * @0x800D4800, len = 0x00000004
					.streamObject = null,
					// _ButtonTexture * @0x800D4800, len = 0x00000004
					.button = null}}};
// decompiled code
// original method signature:
// void /*$ra*/ VRAM_InitVramBlockCache()
// line 153, offset 0x800728d0
/* begin block 1 */
// Start line: 154
// Start offset: 0x800728D0
// Variables:
// 		int i; // $v1
/* end block 1 */
// End offset: 0x800728FC
// End Line: 179

/* begin block 2 */
// Start line: 228
/* end block 2 */
// End Line: 229

/* begin block 3 */
// Start line: 306
/* end block 3 */
// End Line: 307

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_InitVramBlockCache(void)

{
	int iVar1;
	int iVar2;

	iVar2 = 0x59;
	iVar1 = -0x7ff2b818;
	openVramBlocks = (_BlockVramEntry *)0x0;
	usedVramBlocks = (_BlockVramEntry *)0x0;
	numOfBlocksUsed = 0;
	do
	{
		*(undefined *)(iVar1 + 5) = 0;
		iVar2 = iVar2 + -1;
		iVar1 = iVar1 + -0x1c;
	} while (-1 < iVar2);
	VRAM_InsertFreeVram(0x200, 0x100, 0x200, 0x100, 1);
	VRAM_InitMorphPalettes();
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VRAM_EnableTerrainArea()
// line 184, offset 0x80072930
/* begin block 1 */
// Start line: 300
/* end block 1 */
// End Line: 301

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_EnableTerrainArea(void)

{
	VRAM_InsertFreeVram(0x200, 0, 0x200, 0x100, 0);
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VRAM_DisableTerrainArea()
// line 189, offset 0x80072960
/* begin block 1 */
// Start line: 311
/* end block 1 */
// End Line: 312

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_DisableTerrainArea(void)

{
	VRAM_DeleteFreeVram(0x200, 0, 0x200, 0x100);
	return;
}

// decompiled code
// original method signature:
// int /*$ra*/ VRAM_ConcatanateMemory(struct _BlockVramEntry *curBlock /*$s1*/)
// line 195, offset 0x8007298c
/* begin block 1 */
// Start line: 196
// Start offset: 0x8007298C
// Variables:
// 		struct _BlockVramEntry *nextBlock; // $s0
/* end block 1 */
// End offset: 0x80072B60
// End Line: 261

/* begin block 2 */
// Start line: 324
/* end block 2 */
// End Line: 325

int VRAM_ConcatanateMemory(_BlockVramEntry *curBlock)

{
	int iVar1;
	int iVar2;
	int iVar3;
	int iVar4;
	_BlockVramEntry *block;

	if (curBlock != (_BlockVramEntry *)0x0)
	{
		do
		{
			block = curBlock->next;
			while (block != (_BlockVramEntry *)0x0)
			{
				if ((curBlock->x == block->x) && (curBlock->w == block->w))
				{
					iVar2 = (uint)(ushort)curBlock->y << 0x10;
					iVar4 = iVar2 >> 0x10;
					iVar1 = (uint)(ushort)block->y << 0x10;
					iVar3 = iVar1 >> 0x10;
					if (iVar2 >> 0x18 == iVar1 >> 0x18)
					{
						if (iVar4 + (int)curBlock->h == iVar3)
						{
							curBlock->h = curBlock->h + block->h;
							goto LAB_80072ac4;
						}
						if (iVar3 + (int)block->h == iVar4)
						{
							block->h = block->h + curBlock->h;
							goto LAB_80072b28;
						}
					}
				}
				if ((curBlock->y == block->y) && (curBlock->h == block->h))
				{
					if (((int)curBlock->x + (int)curBlock->w == (int)block->x) &&
						(((curBlock->x & 0x3fU) == 0 || ((int)curBlock->w + (int)block->w < 0x41))))
					{
						curBlock->w = curBlock->w + block->w;
					LAB_80072ac4:
						VRAM_DeleteFreeBlock(block);
						block->flags = '\0';
						return 1;
					}
					if (((int)block->x + (int)block->w == (int)curBlock->x) &&
						(((block->x & 0x3fU) == 0 || ((int)curBlock->w + (int)block->w < 0x41))))
					{
						block->w = block->w + curBlock->w;
					LAB_80072b28:
						VRAM_DeleteFreeBlock(curBlock);
						curBlock->flags = '\0';
						return 1;
					}
				}
				block = block->next;
			}
			curBlock = curBlock->next;
		} while (curBlock != (_BlockVramEntry *)0x0);
	}
	return 0;
}

// decompiled code
// original method signature:
// void /*$ra*/ VRAM_GarbageCollect()
// line 263, offset 0x80072b74
/* begin block 1 */
// Start line: 463
/* end block 1 */
// End Line: 464

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_GarbageCollect(void)

{
	int iVar1;

	do
	{
		iVar1 = VRAM_ConcatanateMemory(openVramBlocks);
	} while (iVar1 == 1);
	return;
}

// decompiled code
// original method signature:
// int /*$ra*/ VRAM_InsertFreeBlock(struct _BlockVramEntry *block /*$a0*/)
// line 270, offset 0x80072ba8
/* begin block 1 */
// Start line: 271
// Start offset: 0x80072BA8
// Variables:
// 		struct _BlockVramEntry *next; // $v1
// 		struct _BlockVramEntry *prev; // $a1
/* end block 1 */
// End offset: 0x80072C28
// End Line: 301

/* begin block 2 */
// Start line: 478
/* end block 2 */
// End Line: 479

int VRAM_InsertFreeBlock(_BlockVramEntry *block)

{
	int iVar1;
	_BlockVramEntry *p_Var2;
	_BlockVramEntry *p_Var3;
	_BlockVramEntry *p_Var4;

	if (block == (_BlockVramEntry *)0x0)
	{
		iVar1 = 0;
	}
	else
	{
		p_Var3 = openVramBlocks;
		p_Var4 = (_BlockVramEntry *)0x0;
		if (openVramBlocks != (_BlockVramEntry *)0x0)
		{
			p_Var3 = openVramBlocks;
			p_Var4 = (_BlockVramEntry *)0x0;
			do
			{
				p_Var2 = p_Var3;
				p_Var3 = p_Var2;
				if (block->area <= p_Var2->area)
					break;
				p_Var3 = p_Var2->next;
				p_Var4 = p_Var2;
			} while (p_Var3 != (_BlockVramEntry *)0x0);
		}
		if (p_Var4 == (_BlockVramEntry *)0x0)
		{
			p_Var3 = block;
			block->next = openVramBlocks;
			openVramBlocks = p_Var3;
		}
		else
		{
			block->next = p_Var3;
			p_Var4->next = block;
		}
		VRAM_GarbageCollect();
		iVar1 = 1;
	}
	return iVar1;
}

// decompiled code
// original method signature:
// void /*$ra*/ VRAM_DeleteFreeBlock(struct _BlockVramEntry *block /*$a0*/)
// line 304, offset 0x80072c38
/* begin block 1 */
// Start line: 306
// Start offset: 0x80072C38
// Variables:
// 		struct _BlockVramEntry *next; // $v1
// 		struct _BlockVramEntry *prev; // $a1
/* end block 1 */
// End offset: 0x80072C98
// End Line: 330

/* begin block 2 */
// Start line: 547
/* end block 2 */
// End Line: 548

/* begin block 3 */
// Start line: 548
/* end block 3 */
// End Line: 549

/* begin block 4 */
// Start line: 549
/* end block 4 */
// End Line: 550

void VRAM_DeleteFreeBlock(_BlockVramEntry *block)

{
	_BlockVramEntry *p_Var1;
	_BlockVramEntry *p_Var2;
	_BlockVramEntry *p_Var3;

	p_Var3 = (_BlockVramEntry *)0x0;
	if (block != (_BlockVramEntry *)0x0)
	{
		p_Var2 = openVramBlocks;
		if (block != openVramBlocks)
		{
			do
			{
				p_Var1 = p_Var2;
				p_Var2 = p_Var1;
				if (p_Var1 == (_BlockVramEntry *)0x0)
					break;
				p_Var2 = p_Var1->next;
				p_Var3 = p_Var1;
			} while (block != p_Var2);
			if (block != p_Var2)
			{
				return;
			}
		}
		if (p_Var3 != (_BlockVramEntry *)0x0)
		{
			p_Var3->next = block->next;
			return;
		}
		openVramBlocks = block->next;
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VRAM_InsertUsedBlock(struct _BlockVramEntry *block /*$a0*/)
// line 333, offset 0x80072ca0
/* begin block 1 */
// Start line: 605
/* end block 1 */
// End Line: 606

/* begin block 2 */
// Start line: 606
/* end block 2 */
// End Line: 607

void VRAM_InsertUsedBlock(_BlockVramEntry *block)

{
	if (block != (_BlockVramEntry *)0x0)
	{
		if (usedVramBlocks == (_BlockVramEntry *)0x0)
		{
			usedVramBlocks = block;
			return;
		}
		block->next = usedVramBlocks;
		usedVramBlocks = block;
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VRAM_DeleteUsedBlock(struct _BlockVramEntry *block /*$a0*/)
// line 349, offset 0x80072cd4
/* begin block 1 */
// Start line: 351
// Start offset: 0x80072CD4
// Variables:
// 		struct _BlockVramEntry *next; // $v1
// 		struct _BlockVramEntry *prev; // $a1
/* end block 1 */
// End offset: 0x80072D30
// End Line: 372

/* begin block 2 */
// Start line: 637
/* end block 2 */
// End Line: 638

/* begin block 3 */
// Start line: 638
/* end block 3 */
// End Line: 639

/* begin block 4 */
// Start line: 640
/* end block 4 */
// End Line: 641

void VRAM_DeleteUsedBlock(_BlockVramEntry *block)

{
	_BlockVramEntry *p_Var1;
	_BlockVramEntry *p_Var2;
	_BlockVramEntry *p_Var3;

	p_Var3 = (_BlockVramEntry *)0x0;
	p_Var2 = usedVramBlocks;
	if (block != usedVramBlocks)
	{
		do
		{
			p_Var1 = p_Var2;
			p_Var2 = p_Var1;
			if (p_Var1 == (_BlockVramEntry *)0x0)
				break;
			p_Var2 = p_Var1->next;
			p_Var3 = p_Var1;
		} while (block != p_Var2);
		if (block != p_Var2)
		{
			return;
		}
	}
	if (p_Var3 != (_BlockVramEntry *)0x0)
	{
		p_Var3->next = block->next;
		return;
	}
	usedVramBlocks = block->next;
	return;
}

// decompiled code
// original method signature:
// struct _BlockVramEntry * /*$ra*/ VRAM_GetOpenBlock()
// line 374, offset 0x80072d38
/* begin block 1 */
// Start line: 376
// Start offset: 0x80072D38
// Variables:
// 		int i; // $a0
/* end block 1 */
// End offset: 0x80072D64
// End Line: 389

/* begin block 2 */
// Start line: 689
/* end block 2 */
// End Line: 690

/* begin block 3 */
// Start line: 690
/* end block 3 */
// End Line: 691

/* begin block 4 */
// Start line: 692
/* end block 4 */
// End Line: 693

/* WARNING: Unknown calling convention yet parameter storage is locked */

_BlockVramEntry *VRAM_GetOpenBlock(void)

{
	_BlockVramEntry *p_Var1;
	int iVar2;

	iVar2 = 0;
	p_Var1 = vramBlockList;
	do
	{
		iVar2 = iVar2 + 1;
		if (p_Var1->flags == '\0')
		{
			return p_Var1;
		}
		p_Var1 = p_Var1 + 1;
	} while (iVar2 < 0x5a);
	return (_BlockVramEntry *)0x0;
}

// decompiled code
// original method signature:
// int /*$ra*/ VRAM_DeleteFreeVram(short x /*$a0*/, short y /*$a1*/, short w /*$a2*/, short h /*$a3*/)
// line 391, offset 0x80072d6c
/* begin block 1 */
// Start line: 392
// Start offset: 0x80072D6C
// Variables:
// 		struct _BlockVramEntry *prev; // $t1
// 		struct _BlockVramEntry *vblock; // $a2
// 		struct _BlockVramEntry *nextVBlock; // $t0
// 		struct _BlockVramEntry (*blockLists[2]); // stack offset -24
// 		int i; // $t2
// 		int delCount; // $t3
/* end block 1 */
// End offset: 0x80072E88
// End Line: 427

/* begin block 2 */
// Start line: 727
/* end block 2 */
// End Line: 728

int VRAM_DeleteFreeVram(short x, short y, short w, short h)

{
	_BlockVramEntry *p_Var1;
	_BlockVramEntry *p_Var2;
	_BlockVramEntry *p_Var3;
	_BlockVramEntry *p_Var4;
	int iVar5;
	int iVar6;
	_BlockVramEntry **pp_Var7;
	_BlockVramEntry *local_18[4];

	pp_Var7 = local_18;
	iVar6 = 0;
	iVar5 = 0;
	do
	{
		if (*pp_Var7 != (_BlockVramEntry *)0x0)
		{
			p_Var1 = *pp_Var7;
			p_Var3 = (_BlockVramEntry *)0x0;
			do
			{
				p_Var2 = p_Var1->next;
				p_Var4 = p_Var1;
				if (((((int)x <= (int)p_Var1->x) &&
					  (p_Var4 = p_Var1, (int)p_Var1->x + (int)p_Var1->w <= (int)x + (int)w)) &&
					 (p_Var4 = p_Var1, (int)y <= (int)p_Var1->y)) &&
					(p_Var4 = p_Var1, (int)p_Var1->y + (int)p_Var1->h <= (int)y + (int)h))
				{
					p_Var1->flags = '\0';
					if (p_Var3 == (_BlockVramEntry *)0x0)
					{
						if (iVar5 == 0)
						{
							iVar6 = iVar6 + 1;
							p_Var4 = p_Var3;
							openVramBlocks = p_Var2;
						}
						else
						{
							iVar6 = iVar6 + 1;
							p_Var4 = p_Var3;
							usedVramBlocks = p_Var2;
						}
					}
					else
					{
						p_Var3->next = p_Var2;
						iVar6 = iVar6 + 1;
						p_Var4 = p_Var3;
					}
				}
				p_Var1 = p_Var2;
				p_Var3 = p_Var4;
			} while (p_Var2 != (_BlockVramEntry *)0x0);
		}
		iVar5 = iVar5 + 1;
		pp_Var7 = pp_Var7 + 1;
	} while (iVar5 < 2);
	return iVar6;
}

// decompiled code
// original method signature:
// int /*$ra*/ VRAM_InsertFreeVram(short x /*stack -48*/, short y /*stack -46*/, short w /*$s7*/, short h /*$fp*/, int flags /*stack 16*/)
// line 430, offset 0x80072e9c
/* begin block 1 */
// Start line: 431
// Start offset: 0x80072E9C
// Variables:
// 		struct _BlockVramEntry *useBlock; // $a0
/* end block 1 */
// End offset: 0x80072FFC
// End Line: 476

/* begin block 2 */
// Start line: 841
/* end block 2 */
// End Line: 842

int VRAM_InsertFreeVram(short x, short y, short w, short h, int flags)

{
	short sVar1;
	_BlockVramEntry *block;
	uchar uVar2;
	long lVar3;

	uVar2 = (uchar)flags;
	if (((x & 0x3fU) == 0) || ((int)w <= (int)(0x40 - ((uint)(ushort)x & 0x3f))))
	{
		block = VRAM_GetOpenBlock();
		lVar3 = (int)w * (int)h;
		block->next = (_BlockVramEntry *)0x0;
		block->flags = uVar2;
		block->time = 0;
		block->x = x;
		block->y = y;
		block->w = w;
		block->h = h;
	}
	else
	{
		block = VRAM_GetOpenBlock();
		sVar1 = (short)((uint)(ushort)x & 0x3f);
		block->w = 0x40 - sVar1;
		block->next = (_BlockVramEntry *)0x0;
		block->flags = uVar2;
		block->time = 0;
		block->x = x;
		block->y = y;
		block->h = h;
		block->area = (int)block->w * (int)h;
		VRAM_InsertFreeBlock(block);
		block = VRAM_GetOpenBlock();
		block->w = w + -0x40 + sVar1;
		lVar3 = (int)block->w * (int)h;
		block->next = (_BlockVramEntry *)0x0;
		block->flags = uVar2;
		block->time = 0;
		block->y = y;
		block->h = h;
		block->x = (x + 0x40) - sVar1;
	}
	block->area = lVar3;
	VRAM_InsertFreeBlock(block);
	return 1;
}

// decompiled code
// original method signature:
// struct _BlockVramEntry * /*$ra*/ VRAM_CheckVramSlot(short *x /*stack 0*/, short *y /*stack 4*/, short w /*$s7*/, short h /*$s6*/, int type /*stack 16*/, int startY /*stack 20*/)
// line 487, offset 0x80073030
/* begin block 1 */
// Start line: 488
// Start offset: 0x80073030
// Variables:
// 		struct _BlockVramEntry *vblock; // $s1
// 		short hldx; // $s3
// 		short hldy; // $s4
// 		short hldw; // $s0
// 		short hldh; // $s5
// 		long fits; // $s2
// 		long offset; // $s0
// 		int wdiff; // $t1
// 		int hdiff; // $v1
// 		struct _BlockVramEntry *vblockleft; // $t3
// 		long offsetleft; // $t2
// 		struct _BlockVramEntry *vblockright; // $s4
// 		long offsetright; // $s3

/* begin block 1.1 */
// Start line: 546
// Start offset: 0x80073170
// Variables:
// 		int newx; // $v0
/* end block 1.1 */
// End offset: 0x800731AC
// End Line: 553

/* begin block 1.2 */
// Start line: 570
// Start offset: 0x800731C4
/* end block 1.2 */
// End offset: 0x800731F4
// End Line: 590
/* end block 1 */
// End offset: 0x800733F8
// End Line: 741

/* begin block 2 */
// Start line: 997
/* end block 2 */
// End Line: 998

_BlockVramEntry *VRAM_CheckVramSlot(short *x, short *y, short w, short h, int type, int startY)

{
	undefined *puVar1;
	ushort x_00;
	int iVar2;
	ushort y_00;
	undefined *puVar3;
	short w_00;
	uint uVar4;
	int iVar5;
	ushort h_00;
	uint uVar6;
	int iVar7;
	int iVar8;
	undefined *puVar9;
	int iVar10;
	_BlockVramEntry *p_Var11;
	int iVar12;
	uint uVar13;
	_BlockVramEntry *block;
	int iVar14;
	short w_01;
	_BlockVramEntry *p_Var15;
	uint uVar16;

	uVar6 = (uint)(ushort)h;
	uVar4 = (uint)(ushort)w;
	iVar14 = 2;
	p_Var11 = (_BlockVramEntry *)0x0;
	iVar10 = 0;
	p_Var15 = (_BlockVramEntry *)0x0;
	_w_01 = 0;
	w_01 = 0;
	puVar1 = &DAT_0000270f;
	puVar9 = &DAT_0000270f;
	block = openVramBlocks;
	if (openVramBlocks != (_BlockVramEntry *)0x0)
	{
		iVar8 = (int)w;
		iVar7 = (int)h;
		iVar12 = (int)(short)startY;
		block = openVramBlocks;
		do
		{
			if ((int)block->w < iVar8)
			{
			LAB_800731f4:
				w_01 = (short)_w_01;
				if ((puVar9 == (undefined *)0x0) && (puVar1 == (undefined *)0x0))
					break;
			}
			else
			{
				puVar3 = (undefined *)((int)block->w - iVar8);
				if ((((int)block->h < iVar7) || ((int)puVar9 < (int)puVar3)) ||
					((iVar12 != -1 && (((int)block->y < iVar12 || (iVar12 + 0x100 <= (int)block->y))))))
					goto LAB_800731f4;
				if ((puVar3 != puVar9) || ((int)block->h - iVar7 < (int)puVar1))
				{
					x_00 = block->x;
					iVar5 = 0x40 - ((uint)x_00 & 0x3f);
					if ((x_00 & 0x3f) == 0)
					{
					LAB_80073150:
						iVar14 = 0;
						iVar10 = 0;
						puVar9 = (undefined *)((int)block->w - iVar8);
						puVar1 = (undefined *)((int)block->h - iVar7);
						p_Var11 = block;
					}
					else
					{
						if (iVar5 < iVar8)
						{
							if ((iVar14 != 0) && (iVar2 = (int)block->w, iVar8 <= iVar2 - iVar5))
							{
								iVar14 = 1;
								p_Var15 = block;
							LAB_800731e8:
								puVar9 = (undefined *)(iVar2 - iVar8);
								puVar1 = (undefined *)((int)block->h - iVar7);
								_w_01 = iVar5;
							}
						}
						else
						{
							if ((x_00 & 0xf) == 0)
								goto LAB_80073150;
							iVar5 = 0x10 - ((uint)x_00 & 0xf);
							if ((iVar8 <= (int)(0x40 - ((int)(short)x_00 + iVar5 & 0x3fU))) &&
								(iVar2 = (int)block->w, iVar8 <= iVar2 - iVar5))
							{
								iVar14 = 0;
								iVar10 = iVar5;
								p_Var11 = block;
								iVar5 = _w_01;
								goto LAB_800731e8;
							}
						}
					}
					goto LAB_800731f4;
				}
			}
			w_01 = (short)_w_01;
			block = block->next;
		} while (block != (_BlockVramEntry *)0x0);
	}
	if ((iVar14 == 0) && (block = p_Var11, iVar10 != 0))
	{
		w_00 = (short)iVar10;
		VRAM_InsertFreeVram(p_Var11->x, p_Var11->y, w_00, p_Var11->h, (uint)p_Var11->flags);
		p_Var11->x = p_Var11->x + w_00;
		p_Var11->w = p_Var11->w - w_00;
		block = p_Var11;
	}
	if (block == (_BlockVramEntry *)0x0)
	{
		if ((p_Var15 != (_BlockVramEntry *)0x0) && (iVar14 == 1))
		{
			iVar14 = 0;
			VRAM_InsertFreeVram(p_Var15->x, p_Var15->y, w_01, p_Var15->h, (uint)p_Var15->flags);
			p_Var15->x = p_Var15->x + w_01;
			p_Var15->w = p_Var15->w - w_01;
			block = p_Var15;
		}
		if (block == (_BlockVramEntry *)0x0)
		{
			return (_BlockVramEntry *)0x0;
		}
	}
	if (iVar14 == 0)
	{
		x_00 = block->x;
		y_00 = block->y;
		uVar13 = (uint)(ushort)block->w;
		h_00 = block->h;
		uVar16 = (uint)h_00;
		VRAM_DeleteFreeBlock(block);
		block->next = (_BlockVramEntry *)0x0;
		block->flags = '\x01';
		block->type = (uchar)type;
		block->w = w;
		block->h = h;
		VRAM_InsertUsedBlock(block);
		*x = block->x;
		*y = block->y;
		if (uVar13 << 0x10 == uVar4 << 0x10)
		{
			if (uVar16 << 0x10 == uVar6 << 0x10)
			{
				return block;
			}
			y_00 = (ushort)(((uint)y_00 + uVar6) * 0x10000 >> 0x10);
			h_00 = (ushort)((uVar16 - uVar6) * 0x10000 >> 0x10);
		}
		else
		{
			if (uVar16 << 0x10 == uVar6 << 0x10)
			{
				x_00 = (ushort)(((uint)x_00 + uVar4) * 0x10000 >> 0x10);
				w = (short)((uVar13 - uVar4) * 0x10000 >> 0x10);
			}
			else
			{
				VRAM_InsertFreeVram((short)(((uint)x_00 + uVar4) * 0x10000 >> 0x10), y_00,
									(short)((uVar13 - uVar4) * 0x10000 >> 0x10), h_00, 1);
				y_00 = (ushort)(((uint)y_00 + uVar6) * 0x10000 >> 0x10);
				h_00 = (ushort)((uVar16 - uVar6) * 0x10000 >> 0x10);
			}
		}
		VRAM_InsertFreeVram(x_00, y_00, w, h_00, 1);
	}
	return block;
}

// decompiled code
// original method signature:
// void /*$ra*/ VRAM_ClearVramBlock(struct _BlockVramEntry *block /*$s0*/)
// line 745, offset 0x8007342c
/* begin block 1 */
// Start line: 1593
/* end block 1 */
// End Line: 1594

void VRAM_ClearVramBlock(_BlockVramEntry *block)

{
	if (block != (_BlockVramEntry *)0x0)
	{
		VRAM_DeleteUsedBlock(block);
		VRAM_InsertFreeBlock(block);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ AdjustVramCoordsObject(int oldx /*$s3*/, int oldy /*$s1*/, int newx /*$a2*/, int newy /*$t7*/, struct Object *object /*stack 16*/)
// line 825, offset 0x80073460
/* begin block 1 */
// Start line: 826
// Start offset: 0x80073460
// Variables:
// 		struct TextureMT3 *texture; // $t1
// 		int oldclutxoffset; // $v0
// 		int oldclutyoffset; // $a0
// 		int newclut; // $a0
// 		int d; // $t4
// 		int oldtpagexoffset; // $v1
// 		int oldtpageyoffset; // $v0
// 		int newtpage; // $a3
// 		struct _Model *model; // $t3
// 		short diffy; // $s5
// 		short diffx; // $s6
/* end block 1 */
// End offset: 0x80073628
// End Line: 884

/* begin block 2 */
// Start line: 1753
/* end block 2 */
// End Line: 1754

void AdjustVramCoordsObject(int oldx, int oldy, int newx, int newy, Object *object)

{
	ushort uVar1;
	ushort uVar2;
	char cVar3;
	char cVar4;
	uint uVar5;
	TextureMT3 *pTVar6;
	ushort *puVar7;
	_Model *p_Var8;
	int iVar9;

	cVar3 = (char)newy - (char)oldy;
	iVar9 = 0;
	if (0 < object->numModels)
	{
		do
		{
			p_Var8 = object->modelList[iVar9];
			pTVar6 = p_Var8->startTextures;
			if ((pTVar6 != (TextureMT3 *)0x0) && (pTVar6 < p_Var8->endTextures))
			{
				puVar7 = &pTVar6->clut;
				do
				{
					uVar1 = puVar7[2];
					uVar5 = newy + (((uint)uVar1 & 0x10) * 0x10 - (oldy & 0xffffff00U));
					uVar2 = *puVar7;
					*(char *)((int)puVar7 + -1) = *(char *)((int)puVar7 + -1) + cVar3;
					*(char *)((int)puVar7 + 7) = *(char *)((int)puVar7 + 7) + cVar3;
					*(char *)((int)puVar7 + 3) = *(char *)((int)puVar7 + 3) + cVar3;
					cVar4 = (char)(((int)(((newx & 0x3fU) - (oldx & 0x3fU)) * 0x10000) >> 0x10) << (2 - ((uint)(uVar1 >> 7) & 3) & 0x1f));
					pTVar6->u0 = pTVar6->u0 + cVar4;
					pTVar6 = pTVar6 + 1;
					puVar7[2] = uVar1 & 0x1e0 |
								(ushort)((int)(uVar5 & 0x100) >> 4) |
								(ushort)((int)((newx & 0xffffffc0U) +
												   (((uint)uVar1 & 0xf) * 0x40 - (oldx & 0xffffffc0U)) &
											   0x3ff) >>
										 6) |
								(ushort)((uVar5 & 0x200) << 2);
					*puVar7 = ((short)newy + ((uVar2 >> 6) - (short)oldy)) * 0x40 |
							  (ushort)((int)((newx & 0xfffffff0U) +
											 (((uint)uVar2 & 0x3f) * 0x10 - (oldx & 0xfffffff0U))) >>
									   4) &
								  0x3f;
					*(char *)(puVar7 + 1) = *(char *)(puVar7 + 1) + cVar4;
					*(char *)(puVar7 + 3) = *(char *)(puVar7 + 3) + cVar4;
					puVar7 = puVar7 + 8;
				} while (pTVar6 < p_Var8->endTextures);
			}
			iVar9 = iVar9 + 1;
		} while (iVar9 < (int)object->numModels);
	}
	return;
}

// decompiled code
// original method signature:
// struct _BlockVramEntry * /*$ra*/ VRAM_InsertionSort(struct _BlockVramEntry *rootNode /*$a0*/, struct _BlockVramEntry *newBlock /*$a1*/, int pack_type /*$a2*/)
// line 922, offset 0x8007364c
/* begin block 1 */
// Start line: 925
// Start offset: 0x8007364C
// Variables:
// 		struct _BlockVramEntry *next; // $a3
// 		struct _BlockVramEntry *prev; // $t0
/* end block 1 */
// End offset: 0x800736FC
// End Line: 965

/* begin block 2 */
// Start line: 2127
/* end block 2 */
// End Line: 2128

/* begin block 3 */
// Start line: 2129
/* end block 3 */
// End Line: 2130

/* begin block 4 */
// Start line: 2131
/* end block 4 */
// End Line: 2132

_BlockVramEntry *
VRAM_InsertionSort(_BlockVramEntry *rootNode, _BlockVramEntry *newBlock, int pack_type)

{
	_BlockVramEntry *p_Var1;
	_BlockVramEntry *p_Var2;
	_BlockVramEntry *p_Var3;

	p_Var3 = (_BlockVramEntry *)0x0;
	p_Var1 = rootNode;
	if (pack_type == 0)
	{
		p_Var2 = rootNode;
		if (rootNode != (_BlockVramEntry *)0x0)
		{
			p_Var2 = rootNode;
			do
			{
				p_Var1 = p_Var2;
				p_Var2 = p_Var1;
				if (p_Var1->area <= newBlock->area)
					break;
				p_Var2 = p_Var1->next;
				p_Var3 = p_Var1;
			} while (p_Var2 != (_BlockVramEntry *)0x0);
		}
	}
	else
	{
		while (p_Var2 = p_Var1, p_Var2 != (_BlockVramEntry *)0x0)
		{
			if ((p_Var2->w <= newBlock->w) && ((newBlock->w != p_Var2->w || (p_Var2->h <= newBlock->h))))
				break;
			p_Var1 = p_Var2->next;
			p_Var3 = p_Var2;
		}
	}
	if (p_Var3 == (_BlockVramEntry *)0x0)
	{
		newBlock->next = rootNode;
		rootNode = newBlock;
	}
	else
	{
		newBlock->next = p_Var2;
		p_Var3->next = newBlock;
	}
	return rootNode;
}

// decompiled code
// original method signature:
// void /*$ra*/ VRAM_ClearVram()
// line 970, offset 0x80073704
/* begin block 1 */
// Start line: 971
// Start offset: 0x80073704
// Variables:
// 		struct _BlockVramEntry *vblock; // $a0
// 		struct _BlockVramEntry *next; // $s0
/* end block 1 */
// End offset: 0x80073730
// End Line: 981

/* begin block 2 */
// Start line: 2226
/* end block 2 */
// End Line: 2227

/* begin block 3 */
// Start line: 2229
/* end block 3 */
// End Line: 2230

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_ClearVram(void)

{
	_BlockVramEntry *block;
	_BlockVramEntry *p_Var1;

	block = usedVramBlocks;
	if (usedVramBlocks != (_BlockVramEntry *)0x0)
	{
		do
		{
			p_Var1 = block->next;
			VRAM_ClearVramBlock(block);
			block = p_Var1;
		} while (p_Var1 != (_BlockVramEntry *)0x0);
	}
	return;
}

// decompiled code
// original method signature:
// struct _BlockVramEntry * /*$ra*/ VRAM_RearrangeVramsLayer(long whichLayer /*stack 0*/, short *AddX /*stack 4*/, short *AddY /*stack 8*/, short AddW /*$fp*/, int AddH /*stack 16*/, int AddType /*stack 20*/, int AddStartY /*stack 24*/)
// line 991, offset 0x80073740
/* begin block 1 */
// Start line: 992
// Start offset: 0x80073740
// Variables:
// 		struct _BlockVramEntry *vblock; // $a0
// 		struct _BlockVramEntry *retvblock; // $s5
// 		struct _BlockVramEntry *sortedBlocks; // $s2
// 		struct _BlockVramEntry *curBlock; // $s0
// 		struct _BlockVramEntry (*savedVramBlocksPTR[48]); // stack offset -1624
// 		struct _BlockVramEntry savedVramBlocks[48]; // stack offset -1432
// 		struct RECT vramLoc; // stack offset -88
// 		long numBlocks; // $s3
// 		long d; // $s1
// 		int error_retry; // $s4
// 		int good_pack; // $s7
// 		int pack_type; // $s6
// 		short x; // stack offset -80
// 		short y; // stack offset -78
// 		short dispYPos; // stack offset -56

/* begin block 1.1 */
// Start line: 1052
// Start offset: 0x80073868
// Variables:
// 		int startY; // stack offset -48

/* begin block 1.1.1 */
// Start line: 1117
// Start offset: 0x80073A70
// Variables:
// 		int type; // $t0
/* end block 1.1.1 */
// End offset: 0x80073C08
// End Line: 1217
/* end block 1.1 */
// End offset: 0x80073D8C
// End Line: 1278
/* end block 1 */
// End offset: 0x80073D8C
// End Line: 1281

/* begin block 2 */
// Start line: 2271
/* end block 2 */
// End Line: 2272

/* begin block 3 */
// Start line: 2292
/* end block 3 */
// End Line: 2293

_BlockVramEntry *
VRAM_RearrangeVramsLayer(long whichLayer, short *AddX, short *AddY, short AddW, int AddH, int AddType, int AddStartY)

{
	byte bVar1;
	short sVar2;
	short sVar3;
	bool bVar4;
	bool bVar5;
	bool bVar6;
	int iVar7;
	_BlockVramEntry **pp_Var8;
	_BlockVramEntry *rootNode;
	_BlockVramEntry **pp_Var9;
	uint type;
	_BlockVramEntry *newBlock;
	_BlockVramEntry *p_Var10;
	undefined4 uVar11;
	long lVar12;
	_BlockVramEntry *p_Var13;
	undefined4 uVar14;
	undefined4 uVar15;
	int iVar16;
	int iVar17;
	_BlockVramEntry *block;
	_BlockVramEntry *local_658[48];
	undefined local_598[4];
	undefined local_594[4];
	undefined local_590[4];
	undefined local_58c[4];
	undefined local_588[8];
	undefined local_580[1320];
	short local_58;
	short local_56;
	short local_54;
	short local_52;
	ushort local_50;
	ushort local_4e[3];
	short local_48;
	short local_40;
	short local_38;
	undefined4 local_30;

	block = (_BlockVramEntry *)0x0;
	iVar16 = 0;
	local_48 = (short)AddType;
	local_40 = (short)AddStartY;
	if ((gameTrackerX.gameFlags & 0x8000000U) != 0)
	{
		GAMELOOP_Set_Pause_Redraw();
	}
	if (usedVramBlocks != (_BlockVramEntry *)0x0)
	{
		pp_Var9 = (_BlockVramEntry **)local_598;
		pp_Var8 = local_658;
		rootNode = usedVramBlocks;
		do
		{
			if (whichLayer == 0)
			{
				if (rootNode->y < 0x100)
				{
					*pp_Var8 = rootNode;
				LAB_8007380c:
					newBlock = *(_BlockVramEntry **)&rootNode->type;
					p_Var10 = *(_BlockVramEntry **)&rootNode->newX;
					p_Var13 = *(_BlockVramEntry **)&rootNode->x;
					*pp_Var9 = rootNode->next;
					pp_Var9[1] = newBlock;
					pp_Var9[2] = p_Var10;
					pp_Var9[3] = p_Var13;
					newBlock = (_BlockVramEntry *)rootNode->area;
					p_Var10 = (_BlockVramEntry *)rootNode->udata;
					pp_Var9[4] = *(_BlockVramEntry **)&rootNode->w;
					pp_Var9[5] = newBlock;
					pp_Var9[6] = p_Var10;
					pp_Var9 = pp_Var9 + 7;
					pp_Var8 = pp_Var8 + 1;
					iVar16 = iVar16 + 1;
				}
			}
			else
			{
				if (0xff < rootNode->y)
				{
					*pp_Var8 = rootNode;
					goto LAB_8007380c;
				}
			}
			rootNode = rootNode->next;
		} while (rootNode != (_BlockVramEntry *)0x0);
	}
	if (0 < iVar16)
	{
		if (whichLayer == 0)
		{
			local_30 = 0;
			local_56 = 0;
		}
		else
		{
			local_30 = 0x100;
			local_56 = 0x100;
		}
		local_54 = 0x200;
		local_58 = 0x200;
		local_52 = 0x100;
		do
		{
			do
			{
				iVar7 = CheckVolatile(gameTrackerX.drawTimerReturn);
			} while (iVar7 != 0);
			iVar7 = CheckVolatile(gameTrackerX.reqDisp);
		} while (iVar7 != 0);
		bVar6 = false;
		iVar7 = 0;
		rootNode = (_BlockVramEntry *)0x0;
		local_38 = (short)((gameTrackerX.gameData.asmData.dispPage ^ 1U) << 8);
		MoveImage((undefined4 *)&local_58, 0,
				  (int)((gameTrackerX.gameData.asmData.dispPage ^ 1U) << 0x18) >> 0x10);
		DrawSync(0);
		if (0 < iVar16)
		{
			pp_Var8 = local_658;
			iVar17 = 0;
			do
			{
				block = *pp_Var8;
				pp_Var8 = pp_Var8 + 1;
				VRAM_ClearVramBlock(block);
				sVar2 = *(short *)(local_598 + iVar17 + 0x10);
				sVar3 = *(short *)(local_598 + iVar17 + 0x12);
				iVar7 = iVar7 + 1;
				((_BlockVramEntry *)(local_598 + iVar17))->next = (_BlockVramEntry *)0x0;
				*(int *)(local_598 + iVar17 + 0x14) = (int)sVar2 * (int)sVar3;
				rootNode = VRAM_InsertionSort(rootNode, (_BlockVramEntry *)(local_598 + iVar17), 0);
				iVar17 = iVar17 + 0x1c;
			} while (iVar7 < iVar16);
		}
		if (AddX != (short *)0x0)
		{
			block = VRAM_CheckVramSlot(AddX, AddY, AddW, (short)AddH, (int)local_48, (int)local_40);
			pp_Var8 = local_658 + iVar16;
			iVar7 = iVar16 * 0x1c;
			newBlock = (_BlockVramEntry *)(local_598 + iVar7);
			*pp_Var8 = block;
			uVar11 = *(undefined4 *)&block->type;
			uVar14 = *(undefined4 *)&block->newX;
			uVar15 = *(undefined4 *)&block->x;
			newBlock->next = block->next;
			*(undefined4 *)(local_598 + iVar7 + 4) = uVar11;
			*(undefined4 *)(local_598 + iVar7 + 8) = uVar14;
			*(undefined4 *)(local_598 + iVar7 + 0xc) = uVar15;
			lVar12 = block->area;
			uVar11 = block->udata;
			*(undefined4 *)(local_598 + iVar7 + 0x10) = *(undefined4 *)&block->w;
			*(long *)(local_598 + iVar7 + 0x14) = lVar12;
			*(undefined4 *)(local_598 + iVar7 + 0x18) = uVar11;
			iVar16 = iVar16 + 1;
			VRAM_ClearVramBlock(*pp_Var8);
			sVar2 = *(short *)(local_598 + iVar7 + 0x10);
			sVar3 = *(short *)(local_598 + iVar7 + 0x12);
			newBlock->next = (_BlockVramEntry *)0x0;
			local_598[iVar7 + 4] = 5;
			*(int *)(local_598 + iVar7 + 0x14) = (int)sVar2 * (int)sVar3;
			rootNode = VRAM_InsertionSort(rootNode, newBlock, 0);
		}
		bVar4 = false;
		do
		{
			block = (_BlockVramEntry *)0x0;
			bVar5 = true;
			newBlock = rootNode;
			while (newBlock != (_BlockVramEntry *)0x0)
			{
				if (newBlock->type == '\x05')
				{
					if (!bVar4)
					{
						type = SEXT24(local_48);
						goto LAB_80073aa0;
					}
				}
				else
				{
					type = (uint)newBlock->type;
				LAB_80073aa0:
					local_50 = newBlock->x;
					local_4e[0] = newBlock->y;
					p_Var10 = VRAM_CheckVramSlot((short *)&local_50, (short *)local_4e, newBlock->w, newBlock->h,
												 type, (int)(short)local_30);
					if (newBlock->type == '\x05')
					{
						*AddX = local_50;
						*AddY = local_4e[0];
						block = p_Var10;
					}
					if (p_Var10 == (_BlockVramEntry *)0x0)
					{
						bVar5 = false;
						if (!bVar6)
						{
							bVar6 = true;
							VRAM_ClearVram();
							iVar7 = 0;
							rootNode = (_BlockVramEntry *)0x0;
							newBlock = (_BlockVramEntry *)local_598;
							if (0 < iVar16)
							{
								do
								{
									newBlock->next = (_BlockVramEntry *)0x0;
									rootNode = VRAM_InsertionSort(rootNode, newBlock, 1);
									iVar7 = iVar7 + 1;
									newBlock = newBlock + 1;
								} while (iVar7 < iVar16);
							}
							break;
						}
						if ((AddX != (short *)0x0) && (!bVar4))
						{
							bVar4 = true;
							VRAM_ClearVram();
							bVar6 = false;
							rootNode = (_BlockVramEntry *)0x0;
							iVar7 = 0;
							block = (_BlockVramEntry *)0x0;
							newBlock = (_BlockVramEntry *)local_598;
							if (0 < iVar16)
							{
								do
								{
									newBlock->next = (_BlockVramEntry *)0x0;
									rootNode = VRAM_InsertionSort(rootNode, newBlock, 0);
									iVar7 = iVar7 + 1;
									newBlock = newBlock + 1;
								} while (iVar7 < iVar16);
							}
							break;
						}
					}
					if (newBlock->type == '\x02')
					{
						*(_BlockVramEntry **)(newBlock->udata + 0x18) = p_Var10;
						p_Var10->udata = newBlock->udata;
					}
					newBlock->newX = local_50;
					newBlock->newY = local_4e[0];
				}
				newBlock = newBlock->next;
			}
		} while (!bVar5);
		while (rootNode != (_BlockVramEntry *)0x0)
		{
			local_54 = rootNode->w;
			local_52 = rootNode->h;
			local_58 = rootNode->x + -0x200;
			local_56 = local_38;
			if (whichLayer != 0)
			{
				local_56 = local_38 + -0x100;
			}
			local_56 = rootNode->y + local_56;
			local_50 = rootNode->newX;
			local_4e[0] = rootNode->newY;
			bVar1 = rootNode->type;
			if (bVar1 != 5)
			{
				MoveImage((undefined4 *)&local_58, (int)(short)local_50, (int)(short)local_4e[0]);
				DrawSync(0);
				bVar1 = rootNode->type;
			}
			if (bVar1 == 2)
			{
				AdjustVramCoordsObject((int)rootNode->x, (int)rootNode->y, (int)(short)local_50, (int)(short)local_4e[0],
									   *(Object **)(rootNode->udata + 0x10));
			}
			else
			{
				if ((2 < bVar1) && (bVar1 == 3))
				{
					fontTracker.font_tpage =
						(short)(local_4e[0] & 0x100) >> 4 | (ushort)(((uint)local_50 & 0x3ff) >> 6) |
						(ushort)(((uint)local_4e[0] & 0x200) << 2);
					fontTracker.font_vramU = (short)(((uint)local_50 & 0x3f) << 2);
					fontTracker.font_vramV = local_4e[0] & 0xff;
					fontTracker.font_vramX = local_50;
					SpecialFogClut = local_50 >> 4 & 0x3f;
					fontTracker.font_clut = (local_4e[0] + 0x7e) * 0x40 | SpecialFogClut;
					fontTracker.font_vramY = local_4e[0];
					SpecialFogClut = (local_4e[0] + 0x7f) * 0x40 | SpecialFogClut;
				}
			}
			rootNode = rootNode->next;
		}
	}
	DrawSync(0);
	return block;
}

// decompiled code
// original method signature:
// void /*$ra*/ VRAM_TransferBufferToVram(void *dataPtr /*$s3*/, long dataSize /*$s2*/, short status /*$s7*/, void *data1 /*$s0*/, void *data2 /*stack 16*/)
// line 1315, offset 0x80073dc8
/* begin block 1 */
// Start line: 1316
// Start offset: 0x80073DC8
// Variables:
// 		struct VramBuffer *vramControl; // $s1
// 		struct RECT rect; // stack offset -48
// 		long *nextOTag; // $s5
// 		long *drawTimerReturn; // $fp

/* begin block 1.1 */
// Start line: 1345
// Start offset: 0x80073E5C
/* end block 1.1 */
// End offset: 0x80073F10
// End Line: 1374

/* begin block 1.2 */
// Start line: 1379
// Start offset: 0x80073F18
/* end block 1.2 */
// End offset: 0x80073FBC
// End Line: 1399

/* begin block 1.3 */
// Start line: 1435
// Start offset: 0x80073FD8
/* end block 1.3 */
// End offset: 0x80073FEC
// End Line: 1438
/* end block 1 */
// End offset: 0x80074010
// End Line: 1450

/* begin block 2 */
// Start line: 2630
/* end block 2 */
// End Line: 2631

void VRAM_TransferBufferToVram(void *dataPtr, long dataSize, short status, void *data1, void *data2)

{
	short sVar1;
	long *plVar2;
	uint uVar3;
	int iVar4;
	short sVar5;
	size_t __n;
	int iVar6;
	short local_30;
	short local_2e;
	undefined2 local_2c;
	short local_2a;

	uVar3 = BreakDraw();
	DrawSync(0);
	plVar2 = gameTrackerX.drawTimerReturn;
	gameTrackerX.drawTimerReturn = (long *)0x0;
	if (data1 != (void *)0x0)
	{
		if ((*(uint *)data1 & 1) == 0)
		{
			*(uint *)data1 = *(uint *)data1 | 1;
			dataPtr = (void *)((int)dataPtr + 0x24);
			dataSize = dataSize - 0x24;
		}
		iVar4 = (int)*(short *)((int)data1 + 0xe);
		if (iVar4 != 0)
		{
			iVar6 = (int)*(short *)((int)data1 + 8) * 2 - (uint) * (ushort *)((int)data1 + 0xe);
			__n = iVar6 * 0x10000 >> 0x10;
			if (dataSize < (int)__n)
			{
				memcpy((void *)(*(int *)((int)data1 + 0x10) + iVar4), dataPtr, dataSize);
				sVar1 = (short)dataSize;
				dataSize = 0;
				*(short *)((int)data1 + 0xe) = *(short *)((int)data1 + 0xe) + sVar1;
			}
			else
			{
				memcpy((void *)(*(int *)((int)data1 + 0x10) + iVar4), dataPtr, __n);
				dataPtr = (void *)((int)dataPtr + __n);
				dataSize = dataSize - __n;
				local_30 = *(short *)((int)data1 + 4);
				*(short *)((int)data1 + 0xe) = *(short *)((int)data1 + 0xe) + (short)iVar6;
				local_2e = *(short *)((int)data1 + 6) + *(short *)((int)data1 + 0xc);
				local_2c = *(undefined2 *)((int)data1 + 8);
				local_2a = 1;
				*(short *)((int)data1 + 0xc) = *(short *)((int)data1 + 0xc) + 1;
				LoadImage(&local_30, *(undefined4 *)((int)data1 + 0x10));
				*(undefined2 *)((int)data1 + 0xe) = 0;
			}
		}
		if (0 < dataSize)
		{
			sVar1 = *(short *)((int)data1 + 8);
			iVar4 = dataSize / ((int)sVar1 << 1);
			local_30 = *(short *)((int)data1 + 4);
			local_2e = *(short *)((int)data1 + 6) + *(short *)((int)data1 + 0xc);
			local_2c = *(undefined2 *)((int)data1 + 8);
			sVar5 = (short)iVar4;
			local_2a = sVar5;
			LoadImage(&local_30, dataPtr);
			*(short *)((int)data1 + 0xc) = *(short *)((int)data1 + 0xc) + sVar5;
			iVar4 = (int)(short)(sVar1 * (short)((iVar4 << 0x10) >> 0xf));
			__n = dataSize - iVar4;
			if (0 < (int)__n)
			{
				memcpy((void *)(*(int *)((int)data1 + 0x10) + (int)*(short *)((int)data1 + 0xe)),
					   (void *)((int)dataPtr + iVar4), __n);
				*(short *)((int)data1 + 0xe) = *(short *)((int)data1 + 0xe) + (short)__n;
			}
		}
		if (((status == 1) && (data2 != (void *)0x0)) && (*(short *)((int)data2 + 0x14) == 4))
		{
			*(undefined2 *)((int)data2 + 0x14) = 2;
		}
	}
	DrawSync(0);
	gameTrackerX.drawTimerReturn = plVar2;
	if ((uVar3 != 0) && (gameTrackerX.drawTimerReturn = plVar2, uVar3 != 0xffffffff))
	{
		gameTrackerX.drawTimerReturn = plVar2;
		DrawOTag(uVar3);
	}
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VRAM_LoadReturn(void *dataPtr /*$a0*/, void *data1 /*$a1*/, void *data2 /*$a2*/)
// line 1455, offset 0x80074040
/* begin block 1 */
// Start line: 1456
// Start offset: 0x80074040
/* end block 1 */
// End offset: 0x80074040
// End Line: 1456

/* begin block 2 */
// Start line: 3339
/* end block 2 */
// End Line: 3340

void VRAM_LoadReturn(void *dataPtr, void *data1, void *data2)

{
	MEMPACK_Free((char *)data1);
	return;
}

// decompiled code
// original method signature:
// long /*$ra*/ VRAM_GetObjectVramSpace(struct VramSize *vramSize /*$v1*/, struct _ObjectTracker *objectTracker /*$s4*/)
// line 1461, offset 0x80074060
/* begin block 1 */
// Start line: 1462
// Start offset: 0x80074060
// Variables:
// 		struct RECT rect; // stack offset -32
// 		long result; // $s3
// 		struct _BlockVramEntry *lastVramBlockUsed; // $v0
/* end block 1 */
// End offset: 0x80074134
// End Line: 1505

/* begin block 2 */
// Start line: 3351
/* end block 2 */
// End Line: 3352

long VRAM_GetObjectVramSpace(VramSize *vramSize, _ObjectTracker *objectTracker)

{
	_BlockVramEntry *p_Var1;
	uint uVar2;
	short local_20;
	short local_1e;
	short local_1c;
	short local_1a;

	uVar2 = 1;
	local_20 = vramSize->x + 0x200;
	local_1e = vramSize->y;
	local_1c = vramSize->w;
	local_1a = vramSize->h;
	p_Var1 = VRAM_CheckVramSlot(&local_20, &local_1e, local_1c, local_1a, 2, 0x100);
	if (p_Var1 == (_BlockVramEntry *)0x0)
	{
		p_Var1 = VRAM_RearrangeVramsLayer(1, &local_20, &local_1e, local_1c, (int)local_1a, 2, 0x100);
		if (p_Var1 == (_BlockVramEntry *)0x0)
		{
			p_Var1 = VRAM_CheckVramSlot(&local_20, &local_1e, local_1c, local_1a, 2, 0x100);
			uVar2 = (uint)(p_Var1 != (_BlockVramEntry *)0x0);
		}
	}
	*(_BlockVramEntry **)&objectTracker->vramBlock = p_Var1;
	if (p_Var1 != (_BlockVramEntry *)0x0)
	{
		*(_ObjectTracker **)&p_Var1->udata = objectTracker;
	}
	return uVar2;
}

// decompiled code
// original method signature:
// void /*$ra*/ VRAM_InitMorphPalettes()
// line 1511, offset 0x80074158
/* begin block 1 */
// Start line: 3502
/* end block 1 */
// End Line: 3503

/* begin block 2 */
// Start line: 3509
/* end block 2 */
// End Line: 3510

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_InitMorphPalettes(void)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ VRAM_UpdateMorphPalettes()
// line 1545, offset 0x80074160
/* begin block 1 */
// Start line: 3570
/* end block 1 */
// End Line: 3571

/* begin block 2 */
// Start line: 3671
/* end block 2 */
// End Line: 3672

/* WARNING: Unknown calling convention yet parameter storage is locked */

void VRAM_UpdateMorphPalettes(void)

{
	return;
}

// decompiled code
// original method signature:
// void /*$ra*/ MORPH_ChangeAreaPalettes(long time /*$a0*/)
// line 1703, offset 0x80074168
/* begin block 1 */
// Start line: 3886
/* end block 1 */
// End Line: 3887

/* begin block 2 */
// Start line: 3912
/* end block 2 */
// End Line: 3913

void MORPH_ChangeAreaPalettes(long time)

{
	return;
}
