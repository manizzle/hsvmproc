#include "hs.hpp"

int idaapi ana(void) {
    ulong instr;
    uint8_t op, b1, b2, b3;
    uint16_t b23;
    /* HSVM has 32bit instructions, 
       though not all bits are used */
    instr = ua_next_long();
    op = (*(uint8_t*)(&instr));
    b1 = (*((uint8_t*)(&instr)+1));
    b2 = (*((uint8_t*)(&instr)+2));
    b3 = (*((uint8_t*)(&instr)+3));
    b23 = (*((uint16_t*)(&instr)+1));
    switch (op) {
        
    case 0x10:
        // r0 = r1 + r2
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_reg;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.reg = b2;

        cmd.Op3.type = o_reg;
        cmd.Op3.offb = 3;
        cmd.Op3.offo = 3;
        cmd.Op3.dtyp = dt_word;
        cmd.Op2.reg = b3;

        break;
    case 0x11:
        // r0 = r0 + X
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_imm;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.value = b23;
        break;

    case 0x12:
        // r0 = r1 - r2
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_reg;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.reg = b2;

        cmd.Op3.type = o_reg;
        cmd.Op3.offb = 3;
        cmd.Op3.offo = 3;
        cmd.Op3.dtyp = dt_word;
        cmd.Op2.reg = b3;

        break;
    case 0x13:
        // r0 = r0 - X
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_imm;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.value = b23;
        break;

    case 0x14:
        // r0 = r1 * r2
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_reg;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.reg = b2;

        cmd.Op3.type = o_reg;
        cmd.Op3.offb = 3;
        cmd.Op3.offo = 3;
        cmd.Op3.dtyp = dt_word;
        cmd.Op2.reg = b3;

        break;

    case 0x15:
        // r0 = r0 * X
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_imm;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.value = b23;
        break;

    case 0x16:
        // r0 = r1 / r2
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_reg;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.reg = b2;

        cmd.Op3.type = o_reg;
        cmd.Op3.offb = 3;
        cmd.Op3.offo = 3;
        cmd.Op3.dtyp = dt_word;
        cmd.Op2.reg = b3;

        break;

    case 0x17:
        // r0 = r0 / X
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_imm;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.value = b23;
        break;

    case 0x18:
        // r0 = r1 % r2
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_reg;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.reg = b2;

        cmd.Op3.type = o_reg;
        cmd.Op3.offb = 3;
        cmd.Op3.offo = 3;
        cmd.Op3.dtyp = dt_word;
        cmd.Op2.reg = b3;

        break;

    case 0x19:
        // r0 = r0 % X
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_imm;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.value = b23;
        break;

    case 0x1a:
        // r0 = r1 & r2
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_reg;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.reg = b2;

        cmd.Op3.type = o_reg;
        cmd.Op3.offb = 3;
        cmd.Op3.offo = 3;
        cmd.Op3.dtyp = dt_word;
        cmd.Op2.reg = b3;

        break;

    case 0x1b:
        // r0 = r0 & X
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_imm;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.value = b23;
        break;

    case 0x1c:
        // r0 = r1 | r2
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_reg;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.reg = b2;

        cmd.Op3.type = o_reg;
        cmd.Op3.offb = 3;
        cmd.Op3.offo = 3;
        cmd.Op3.dtyp = dt_word;
        cmd.Op2.reg = b3;

        break;

    case 0x1d:
        // r0 = r0 | X
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_imm;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.value = b23;
        break;

    case 0x1e:
        // r0 = r1 ^ r2
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_reg;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.reg = b2;

        cmd.Op3.type = o_reg;
        cmd.Op3.offb = 3;
        cmd.Op3.offo = 3;
        cmd.Op3.dtyp = dt_word;
        cmd.Op2.reg = b3;

        break;

    case 0x1f:
        // r0 = r0 ^ X
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_imm;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.value = b23;
        break;

    case 0x20:
        // jmp imm
        cmd.itype = op;
        cmd.Op1.type = o_imm;
        cmd.Op1.offb = 2;
        cmd.Op1.offo = 2;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.value = b23;
        break;

    case 0x21:
        // je jmp flag == 0
        cmd.itype = op;
        cmd.Op1.type = o_imm;
        cmd.Op1.offb = 2;
        cmd.Op1.offo = 2;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.value = b23;
        break;

    case 0x22:
        // jne jmp flag != 0
        cmd.itype = op;
        cmd.Op1.type = o_imm;
        cmd.Op1.offb = 2;
        cmd.Op1.offo = 2;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.value = b23;
        break;

    case 0x23:
        // jl jmp flag < 0
        cmd.itype = op;
        cmd.Op1.type = o_imm;
        cmd.Op1.offb = 2;
        cmd.Op1.offo = 2;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.value = b23;
        break;

    case 0x24:
        // jle jmp flag <= 0
        cmd.itype = op;
        cmd.Op1.type = o_imm;
        cmd.Op1.offb = 2;
        cmd.Op1.offo = 2;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.value = b23;
        break;

    case 0x25:
        // jg jmp flag > 0
        cmd.itype = op;
        cmd.Op1.type = o_imm;
        cmd.Op1.offb = 2;
        cmd.Op1.offo = 2;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.value = b23;
        break;

    case 0x26:
        // jge jmp flag >= 0
        cmd.itype = op;
        cmd.Op1.type = o_imm;
        cmd.Op1.offb = 2;
        cmd.Op1.offo = 2;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.value = b23;
        break;

    case 0x28:
        // call imm
        cmd.itype = op;
        cmd.Op1.type = o_imm;
        cmd.Op1.offb = 2;
        cmd.Op1.offo = 2;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.value = b23;
        break;

    case 0x29:
        // ret
        cmd.itype = op;
        cmd.Op1.type = o_void;
        cmd.Op1.dtyp = dt_void;
        break;
        
    case 0x30:
        // loadi =  r0, imm : r0 = mem[imm]
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_imm;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.value = b23;
        break;

    case 0x31:
        // loadr = load  r0, r1 : r0 = mem[r1]
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_reg;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.reg = b2;
        break;

    case 0x32:
        // loadbi =  r0, imm : r0 = mem[imm] 0x00FF
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_imm;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.value = b23;
        break;

    case 0x33:
        // loadr = load  r0, r1 : r0 = mem[r1] & 0x00FF
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_reg;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.reg = b2;
        break;
        
    case 0x34:
        // stori immm, r0 : mem[imm] = r0
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_imm;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.value = b23;
        break;

    case 0x35:
        // storr  r0, r1 : mem[r0] = r1
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_reg;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.reg = b2;
        break;

    case 0x36:
        // storbi imm, r0 : mem[imm] = r0 & 0x00FF
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_imm;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.value = b23;
        break;

    case 0x37:
        // storbr r0, r1 : mem[r0] = r1 & 0x00FF
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_reg;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.reg = b2;
        break;

    case 0x40:
        // in = read into r0
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;
        break;
        
    case 0x41:
        // out = write out r0
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;
        break;

    case 0x42:
        // push r0 -> write to stack
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;        
        break;
        
    case 0x43:
        // push imm -> write to stack
        cmd.itype = op;
        cmd.Op1.type = o_imm;
        cmd.Op1.offb = 2;
        cmd.Op1.offo = 2;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.value = b23;        
        break;
        
    case 0x44:
        // pop r0 -> read from stack
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;        
        break;
        
    case 0x51:
        // mov r0, r1 -> r0 = r1
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_reg;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.reg = b2;
        break;
        
    case 0x52:
        // mov r0, imm -> r0 = imm
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_imm;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.value = b23;
        break;

    case 0x53:
        // cmpr r0, r1 -> flags = r0 - r1
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_reg;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.reg = b2;
        break;
        
    case 0x54:
        // cmpi r0, imm -> flags = r0 - imm
        cmd.itype = op;
        cmd.Op1.type = o_reg;
        cmd.Op1.offb = 1;
        cmd.Op1.offo = 1;
        cmd.Op1.dtyp = dt_word;
        cmd.Op1.reg = b1;

        cmd.Op2.type = o_imm;
        cmd.Op2.offb = 2;
        cmd.Op2.offo = 2;
        cmd.Op2.dtyp = dt_word;
        cmd.Op2.value = b23;
        break;

    case 0x60:
        // hlt
        cmd.itype = op;
        cmd.Op1.type = o_void;
        cmd.Op1.dtyp = dt_void;
        break;
        
    case 0x61:
        // syscall
        cmd.itype = op;
        cmd.Op1.type = o_void;
        cmd.Op1.dtyp = dt_void;
        break;

    case 0x90:
        // nop
        cmd.itype = op;
        cmd.Op1.type = o_void;
        cmd.Op1.dtyp = dt_void;
        break;

    default:
        break;
    }
    return sizeof(instr);
}
        
