/*******************************************************************************
 *
 *  NetFPGA-10G http://www.netfpga.org
 *
 *  File:
 *        nf10_flash_lib.h
 *
 *  Project:
 *        configuration
 *
 *  Author:
 *        Muhammad Shahbaz
 *
 *  Description:
 *        For the Flash Controller Project.
 *
 *  Copyright notice:
 *        Copyright (C) 2010,2011 The Board of Trustees of The Leland Stanford
 *                                Junior University
 *
 *  Licence:
 *        This file is part of the NetFPGA 10G development base package.
 *
 *        This package is free software: you can redistribute it and/or modify
 *        it under the terms of the GNU Lesser General Public License as
 *        published by the Free Software Foundation, either version 3 of the
 *        License, or (at your option) any later version.
 *
 *        This package is distributed in the hope that it will be useful, but
 *        WITHOUT ANY WARRANTY; without even the implied warranty of
 *        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *        Lesser General Public License for more details.
 *
 *        You should have received a copy of the GNU Lesser General Public
 *        License along with the NetFPGA source package.  If not, see
 *        http://www.gnu.org/licenses/.
 *
 */

#ifndef _FLASH_LIB_H_
#define _FLASH_LIB_H_

#define	XFL_CONFIG_BASE_ADDR_A 	0x00000000
#define	XFL_CONFIG_BASE_ADDR_B 	0x00800000
#define	XFL_CONFIG_BLOCK_SIZE 	(64 * 1024)
#define	XFL_CONFIG_TOTAL_BLKS 	128
#define	XFL_CONFIG_TOTAL_SIZE 	(XFL_CONFIG_BLOCK_SIZE * XFL_CONFIG_TOTAL_BLKS)

enum {
	XFL_CMD_READ_ARRAY = 0xFF,
	XFL_CMD_READ_ELEC_SIG = 0x90,
	XFL_CMD_READ_STATUS_REG = 0x70,
	XFL_CMD_CLEAR_STATUS_REG = 0x50,
	XFL_CMD_WRITE_BUFFER_PROG = 0xE8,
	XFL_CMD_PROGRAM_SETUP = 0x40,
	XFL_CMD_BLOCK_ERASE_SETUP = 0x20,
	XFL_CMD_CONFIRM = 0xD0,
	XFL_CMD_SUSPEND = 0xB0,
	XFL_CMD_RESUME = 0xD0,
	XFL_STATUS_READY = 0x80,
	XFL_CMD_BLOCK_LOCK_SETUP = 0x60,
	XFL_CMD_BLOCK_LOCK_CONFIRM = 0x01,
};

enum {
	XFL_BASE_ADDR = 0x80000000,
	CFG_BASE_ADDR = 0x40000000,
};

/*************************************************************
  Function prototypes
 *************************************************************/
void Flash_Prog(char* bin_file, char flash_id);
void Flash_Wr_Binfile_B(unsigned int base_addr, char* bin_file);
void Unlock_Single_Block(unsigned int addr);
unsigned int Erase_Single_Block(unsigned int addr);
void Lock_Single_Block(unsigned int addr);
unsigned int Wr_Data_B(unsigned int addr, char data);
unsigned int Rd_Elec_Sig(unsigned int addr);
void Clr_Status_Reg(unsigned int addr);
void Set_Read_Array_Mode(unsigned int addr);
unsigned int Flash_Wt_Rdy(unsigned int addr);
char Rd_Cmd(unsigned int addr, char cmd_code);
void Wr_Cmd(unsigned int addr, char cmd_code);
void Wr_Byte(unsigned int addr, char data);
char Rd_Byte(unsigned int addr);

#endif