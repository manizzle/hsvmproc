#include "hs.hpp"

//----------------------------------------------------------------------

inline void OutReg( int rgnum ) { out_register( ph.regNames[rgnum] ); }

//--------------------------------------------------------------------------

void idaapi header( void )
{
  gen_cmt_line( "Processor:        %s", inf.procName );
  gen_cmt_line( "Target assembler: %s", ash.name );
  gen_cmt_line( "Byte sex        : %s", inf.mf ? "Big endian" : "Little endian");
}

//--------------------------------------------------------------------------

void idaapi footer( void )
{
  char buf[MAXSTR];

  MakeNull();

  tag_addstr( buf, buf+sizeof(buf), COLOR_ASMDIR, ash.end );
  MakeLine(buf, inf.indent);

  gen_cmt_line( "end of file" );
}

//--------------------------------------------------------------------------

void idaapi segstart( ea_t ea )
{
  segment_t *Sarea = getseg( ea );

  char sname[MAXNAMELEN];
  get_segm_name(Sarea, sname, sizeof(sname));

  gen_cmt_line( COLSTR("segment %s", SCOLOR_AUTOCMT), sname );

  ea_t org = ea - get_segm_base( Sarea );
  if ( org != 0 )
  if ( org != 0 )
  {
    char buf[MAX_NUMBUF];
    btoa(buf, sizeof(buf), org);
    gen_cmt_line( "%s %s", ash.origin, buf);
  }
}

//--------------------------------------------------------------------------

void idaapi segend( ea_t ea )
{
  char sname[MAXNAMELEN];
  get_segm_name(getseg(ea-1), sname, sizeof(sname));
  gen_cmt_line("end of '%s'", sname);
}

//----------------------------------------------------------------------

void idaapi out( void )
{
  char buf[MAXSTR];

  init_output_buffer(buf, sizeof(buf));
  OutMnem();

  out_one_operand( 0 );

  if( cmd.Op2.type != o_void )
  {
    out_symbol( ',' );
    OutChar( ' ' );
    out_one_operand( 1 );
  }

  if( isVoid( cmd.ea, uFlag, 0 ) )    OutImmChar( cmd.Op1 );
  if( isVoid( cmd.ea, uFlag, 1 ) )    OutImmChar( cmd.Op2 );

  term_output_buffer();
  gl_comm = 1;
  MakeLine( buf );
}

//----------------------------------------------------------------------

bool idaapi outop( op_t &x )
{

  switch( x.type )
  {
    case o_imm:
      out_symbol( '#' );
      OutValue( x, OOFW_IMM );
      break;

    case o_reg:
      OutReg( x.reg );
      break;

    case o_displ:
      OutValue( x, OOF_ADDR | OOFW_IMM );  // x.addr
      out_symbol( '(' );
      OutReg( x.reg );
      out_symbol( ')' );
      break;

    case o_mem:
    case o_near:
      break;

    case o_void:
      return 0;

    default:
      warning( "out: %u: bad optype %d", cmd.ea, x.type );
  }

  return 1;
}

//--------------------------------------------------------------------------

static void out_equ( char *name, const char *equ, uchar off )
{
  char buf[MAXSTR];
  char *const end = buf + sizeof(buf);

  char *p = tag_addstr(buf, end, COLOR_DNAME, name);
  APPCHAR(p, end, ' ');
  p = tag_addstr(p, end, COLOR_KEYWORD, equ);
  APPCHAR(p, end, ' ');
  p = tag_on(p, end, COLOR_NUMBER);
  p += btoa(p, end-p, off);
  tag_off(p, end, COLOR_NUMBER);
  MakeLine(buf, 0);
}

//--------------------------------------------------------------------------
