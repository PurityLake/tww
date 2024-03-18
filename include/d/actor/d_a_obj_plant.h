#ifndef D_A_OBJ_PLANT_H
#define D_A_OBJ_PLANT_H

#include "d/d_bg_w.h"
#include "d/d_cc_d.h"
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
    /* 0x290 */ request_of_phase_process_class mPhs;
    /* 0x298 */ J3DModel* mpModel;
    /* 0x29C */ dCcD_Stts mStts;
    /* 0x2D8 */ dCcD_Cyl mCyl;
};

#endif /* D_A_OBJ_PLANT_H */
