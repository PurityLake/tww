#ifndef D_A_OBJ_PLANT_H
#define D_A_OBJ_PLANT_H

#include "d/d_bg_w.h"
#include "d/d_com_inf_game.h"
#include "f_op/f_op_actor.h"

class daObjPlant_c : public fopAc_ac_c {
public:
    inline s32 _create();
    inline BOOL _delete();
    inline BOOL _draw();
    inline BOOL _execute();

    BOOL CreateHeap();
    void CreateInit();
    void set_mtx();

public:
    /* Place member variables here */
    request_of_phase_process_class mPhs;
    J3DModel* mpModel;
    dBgW* mpBgW;
    Mtx mMtx;
    u8 field_0x2d0;
    u8 m2D0[0x2D4 - 0x2D1];
};

#endif /* D_A_OBJ_PLANT_H */
