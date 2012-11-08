/*
 *  Interactive disassembler (IDA).
 *  HSVM module
 *
 */

#include <ida.hpp>
#include <idp.hpp>
#include "ins.hpp"

instruc_t Instructions[] = {
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {"addr", CF_CHG1|CF_USE2|CF_USE3 }, // Add registers 0x10
    {"addi", CF_CHG1|CF_USE2}, // Add immediate 0x11
    {"subr", CF_CHG1|CF_USE2|CF_USE3 }, // subs registers 0x12
    {"subi", CF_CHG1|CF_USE2}, // subs immediate 0x13
    {"mulr", CF_CHG1|CF_USE2|CF_USE3 }, // muls registers 0x14
    {"muli", CF_CHG1|CF_USE2}, // muls immediate 0x15
    {"divr", CF_CHG1|CF_USE2|CF_USE3 }, // divs registers 0x16
    {"divi", CF_CHG1|CF_USE2}, // divs immediate 0x17
    {"modr", CF_CHG1|CF_USE2|CF_USE3 }, // mods registers 0x18
    {"modi", CF_CHG1|CF_USE2}, // mods immediate 0x19
    {"andr", CF_CHG1|CF_USE2|CF_USE3 }, // ands registers 0x1a
    {"andi", CF_CHG1|CF_USE2}, // ands immediate 0x1b
    {"orr", CF_CHG1|CF_USE2|CF_USE3 }, // ors registers 0x1c
    {"ori", CF_CHG1|CF_USE2}, // ors immediate 0x1d
    {"xorr", CF_CHG1|CF_USE2|CF_USE3 }, // xors registers 0x1e
    {"xori", CF_CHG1|CF_USE2}, // xors immediate 0x1f
    {"jmp", CF_USE1 | CF_STOP}, //jmp 0x20
    {"je", CF_USE1}, //jmp flag == 0 0x21
    {"jne", CF_USE1}, //jmp flag != 0 0x22
    {"jl", CF_USE1}, //jmp flag < 0 0x23
    {"jle", CF_USE1}, //jmp flag <= 0 0x24
    {"jg", CF_USE1}, //jmp flag > 0 0x25
    {"jge", CF_USE1}, //jmp flag >= 0 0x26
    {"call", CF_USE1 | CF_CALL}, //call 0x28
    {"ret", CF_STOP}, //ret 0x29
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {"loadi", CF_CHG1|CF_USE2}, // loads from imm 0x30
    {"loadr", CF_CHG1|CF_USE2}, // loads from reg 0x31
    {"loadbi", CF_CHG1|CF_USE2}, // loads byte from imm 0x32
    {"loadbr", CF_CHG1|CF_USE2}, // loads byte from reg 0x33
    {"stori", CF_USE1|CF_USE2}, // stores to imm 0x34
    {"storr", CF_USE1|CF_USE2}, // stores to register 0x35
    {"storbi", CF_USE1|CF_USE2}, // stores byte to imm 0x36
    {"storbr", CF_USE1|CF_USE2}, // stores byte to reg 0x37
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {"in", CF_CHG1}, //in 0x40
    {"out", CF_USE1}, //out 0x41
    {"pushr", CF_USE1|CF_USE2}, // push register 0x42
    {"pushi", CF_USE1|CF_USE2}, // push imm 0x43
    {"pop", CF_CHG1}, //pop 0x44
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {"movr", CF_CHG1|CF_USE2}, //mov register 0x51
    {"movi", CF_CHG1|CF_USE2}, //mov imm 0x52
    {"cmpr", CF_USE1|CF_USE2}, // compares registers 0x53
    {"cmpi", CF_USE1|CF_USE2}, // compares reg/imm 0x54
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {"hlt", 0}, //hlt 0x60
    {"syscall", 0}, //syscall 0x61
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, // 0x70
    {NULL, 0},
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0},
    {NULL, 0},
    {NULL, 0}, // 0x80
    {NULL, 0},
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0}, 
    {NULL, 0},
    {NULL, 0},
    {"nop", 0}, //nop 0x90

};    
