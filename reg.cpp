/*
 *  Interactive disassembler (IDA).
 *  HSVM module
 *
 */

#include "hs.hpp"
#include <diskio.hpp>

//--------------------------------------------------------------------------
ea_t intmem = BADADDR; // linear EA of the internal memory/registers segment
ea_t extmem = BADADDR; // linear EA of the external memory segment

//--------------------------------------------------------------------------
static const char *RegNames[] =
{
    "r0", "r1", "r2", "r3", "r4", "r5", "r6", "rip", "rbp", "rsp", "r7", "cs", "ds" 
};

//----------------------------------------------------------------------
typedef struct
{
  int off;
  const char *name;
  const char *cmt;
} entry_t;

static const char *shnames[] = { "HSVM", NULL };
static const char *lnames[]  = { "HSVM 1.4", NULL };

//--------------------------------------------------------------------------

static uchar retcode[]  = { 0xAF };   // ret
static uchar iretcode[] = { 0xBF };   // iret

static bytes_t retcodes[] = {
  { sizeof( retcode ),  retcode },
  { sizeof( iretcode ), iretcode },
  { 0, NULL }
};


//-----------------------------------------------------------------------
//      Processor Definition
//-----------------------------------------------------------------------
processor_t LPH =
{
  IDP_INTERFACE_VERSION,        // version
  0x37337,                      // id
  PRN_HEX,			// view in hex
  8,                            // 8 bits in a byte for code segments
  8,                            // 8 bits in a byte for other segments

  shnames,    // short processor names (null term)
  lnames,     // long processor names (null term)

  NULL,       // array of enabled assemblers

  NULL,     // Various messages:

  header,     // produce start of text file
  footer,     // produce end of text file

  segstart,   // produce start of segment
  segend,     // produce end of segment

  NULL,

  ana,
  emu,

  out,
  outop,
  NULL,    //intel_data,
  NULL,       // compare operands
  NULL,       // can have type

  qnumber(RegNames),    // Number of registers
  RegNames,             // Register names
  NULL,                 // get abstract register

  0,                    // Number of register files
  NULL,                 // Register file names
  NULL,                 // Register descriptions
  NULL,                 // Pointer to CPU registers

  rVcs,rVds,		// first seg reg, second seg reg
  0,                    // size of a segment register
  rVcs,rVds,		// number of cs reg, number of ds reg

  NULL,                 // No known code start sequences
  retcodes,

  HS_addr, HS_nop+1,	// int of first inst, int of last instr + 1
  Instructions,		// array of instructions
  NULL,                 // int  (*is_far_jump)(int icode);
  NULL,         // Translation function for offsets
  0,                    // int tbyte_size;  -- doesn't exist
  NULL,                 // int (*realcvt)(void *m, ushort *e, ushort swt);
  { 0, 0, 0, 0 },       // char real_width[4];
                        // number of symbols after decimal point
                        // 2byte float (0-does not exist)
                        // normal float
                        // normal double
                        // long double
  NULL,                 // int (*is_switch)(switch_info_t *si);
  NULL,                 // int32 (*gen_map_file)(FILE *fp);
  NULL,                 // ea_t (*extract_address)(ea_t ea,const char *string,int x);
  NULL,                 // int (*is_sp_based)(op_t &x); -- always, so leave it NULL
  NULL,                 // int (*create_func_frame)(func_t *pfn);
  NULL,                 // int (*get_frame_retsize(func_t *pfn)
  NULL,                 // void (*gen_stkvar_def)(char *buf,const member_t *mptr,int32 v);
  gen_spcdef,           // Generate text representation of an item in a special segment
  HS_nop,               // Icode of return instruction. It is ok to give any of possible return instructions
  NULL,                 // const char *(*set_idp_options)(const char *keyword,int value_type,const void *value);
  NULL,                 // int (*is_align_insn)(ea_t ea);
  NULL,                 // mvm_t *mvm;
};
