/*
 *  Interactive disassembler (IDA).
 *  HSVM module
 *
 */

#ifndef __INSTRS_HPP
#define __INSTRS_HPP

extern instruc_t Instructions[];

enum nameNum {
    HS_addr = 0x10, // Add registers 0x10
    HS_addi = 0x11, // Add immediate 0x11
    HS_subr = 0x12, // subs registers 0x12
    HS_subi = 0x13, // subs immediaate 0x13
    HS_mulr = 0x14, // muls registers 0x14
    HS_muli = 0x15,  // muls immediate 0x15
    HS_divr = 0x16, // divs registers 0x16
    HS_divi = 0x17, // divs immediate 0x17
    HS_modr = 0x18, // mods registers 0x18
    HS_modi = 0x19, // mods immediate 0x19
    HS_andr = 0x1a, // ands registers 0x1a
    HS_andi = 0x1b, // ands immediate 0x1b
    HS_orr = 0x1c, // ors registers 0x1c
    HS_ori = 0x1d, // ors immediate 0x1d
    HS_xorr = 0x1e, // xors registers 0x1e
    HS_xori = 0x1f, // xors immediate 0x1f
    HS_jmp = 0x20, //jmp 0x20
    HS_je = 0x21, //jmp flag == 0 0x21
    HS_jne = 0x22, //jmp flag != 0 0x22
    HS_jl = 0x23, //jmp flag < 0 0x23
    HS_jle = 0x24, //jmp flag <= 0 0x24
    HS_jg = 0x25, //jmp flag > 0 0x25
    HS_jge = 0x26, //jmp flag >= 0 0x26
    HS_call = 0x28, //call 0x28
    HS_ret = 0x29, //ret 0x29    
    HS_loadi = 0x30,  // loads from imm 0x30
    HS_loadr = 0x31, // loads from reg 0x31
    HS_loadbi = 0x32, // loads byte from imm 0x32
    HS_loadbr = 0x33, // loads byte from reg 0x33
    HS_stori = 0x34, // stores to imm 0x34
    HS_storr = 0x35, // stores to register 0x35
    HS_storbi = 0x36, // stores byte to imm 0x36
    HS_storbr = 0x37, // stores byte to reg 0x37
    HS_in = 0x40, //in 0x40
    HS_out = 0x41, //out 0x41
    HS_pushr = 0x42, // push register 0x42
    HS_pushi = 0x43, // push imm 0x43
    HS_pop = 0x44, //pop 0x44
    HS_movr = 0x51, //mov register 0x51
    HS_movi = 0x52, //mov imm 0x52
    HS_cmpr = 0x53, // compares registers 0x53
    HS_cmpi = 0x54, // compares reg/imm 0x54
    HS_hlt= 0x60, //hlt 0x60
    HS_syscall = 0x61, //syscall 0x61
    HS_nop = 0x90  //nop 0x90
};
#endif
