void TouchArg(op_t &op, int isRead) {
    switch(op.type) {
    case o_imm:
        if (isOff(uFlag, op.n) && isRead) {
            ua_add_off_drefs(op, dr_0);
        }
        break;
    case o_displ:
        if (isOff(uFlag, op.n)) {
            ua_add_off_drefs(op, isRead ? dr_R : dr_W);
        }
        break;
    case o_mem:
        ua_add_dref(op.offb, op.addr, isRead ? dr_R : dr_W);
        break;
    case o_near:
        ua_add_cref(op.offb, op.addr, feature & CF_CALL ? fl_CN : fl_JN);
    default:
        break;
    }
}

int idaapi emu(void) {
    uint32 Feature = cmd.get_canon_feature();
    flow = ((Feature & CF_STOP) == 0);
    
    if (Feature & CF_USE1) TouchArg(cmd.Op1, 1);
    if (Feature & CF_USE2) TouchArg(cmd.Op2, 1);
    if (Feature & CF_CHG1) TouchArg(cmd.Op1, 0);
    if (Feature & CF_CHG2) TouchArg(cmd.Op2, 0);
    if (flow) ua_add_cref(0, cmd.ea+cmd.size, fl_F);
    return 1;
}
