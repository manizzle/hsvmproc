#include "../idaidp.hpp"
#include "ins.hpp"
#include <srarea.hpp>
#include <stdint.h>
#include <idd.hpp>
#include <xref.hpp>

void idaapi header( void );
void idaapi footer( void );
void idaapi segstart( ea_t ea );
void idaapi segend( ea_t ea );
void idaapi out( void );
bool idaapi outop( op_t &x );
int idaapi ana(void);
int idaapi emu(void);
enum hs_regs {
    r_r0, 
    r_r1,
    r_r2,
    r_r3,
    r_r4,
    r_r5,
    r_r6,
    r_rip,
    r_rbp,
    r_rsp,
    r_r7,
    rVcs,
    rVds
};
