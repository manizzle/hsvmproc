#include <stdint.h>

//--------------------------------------------------------------------------
//      I N S T R U C T I O N
//--------------------------------------------------------------------------

// Structure to hold information about an instruction. This structure is
// filled by the analysis step of IDP and used by the emulation and
// conversion to text steps. The kernel uses this structure too.
// All structure fields except cs, ip, ea, Operand.n, Operand.flags
// are initialized to zero by the kernel. The rest should be filled
// by ana().

class insn_t
{
public:
// Current segment base paragraph. Initialized by the kernel.

  ea_t cs;                      // segment base (in paragraphs)


// Virtual address of the instruction (address within the segment)
// Initialized by the kernel.

  ea_t ip;                      // offset in the segment


// Linear address of the instruction.
// Initialized by the kernel.

  ea_t ea;                      // instruction start addresses


// Internal code of instruction. IDP should define its own instruction
// codes. These codes are usually defined in ins.hpp. The array of instruction
// names and features (ins.cpp) is accessed using this code.

  uint16 itype;                 // instruction code (see ins.hpp)
                                // only for canonical insns (not user defined!):
  inline bool is_canon_insn(void) const; // (see def in idp.hpp)
  inline uint32 get_canon_feature(void) const; // (see def in idp.hpp)
  inline const char *get_canon_mnem(void) const; // (see def in idp.hpp)

// Size of instruction in bytes.
// The analyzer should put here the actual size of the instruction.

  uint16 size;                  // instruction size in bytes


// Additinal information about the instruction.
// You may use these field as you want.

  union
  {
    uint16 auxpref;             // processor dependent field
    struct
    {
      uchar low;
      uchar high;
    } auxpref_chars;
  };
  char segpref;                 // processor dependent field
  char insnpref;                // processor dependent field

// Information about instruction operands.

#define UA_MAXOP        6
  op_t Operands[UA_MAXOP];

  #define Op1 Operands[0]
  #define Op2 Operands[1]
  #define Op3 Operands[2]
  #define Op4 Operands[3]
  #define Op5 Operands[4]
  #define Op6 Operands[5]

  char flags;                   // instruction flags
#define INSN_MACRO  0x01        // macro instruction
#define INSN_MODMAC 0x02        // macros: may modify the database
                                // to make room for the macro insn
  bool is_macro(void) const { return (flags & INSN_MACRO) != 0; }

};


int idaapi ana(void) {
    ulong instr;
    uint8_t op, b1, b2, b3;
    uint16_t b23;
    /* HSVM has 32bit instructions, 
       though not all bits are used */
    instr = ua_next_long(void);
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

    default:
        break;
    }
}
        
