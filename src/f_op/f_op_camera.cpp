//
// Generated by dtk
// Translation Unit: f_op_camera.cpp
//

// Fakematch: These are supposed to be weak functions defined in d_a_player.h that wind up at the end of the
// f_op_actor_mng TU. But weak function ordering is currently broken, so to get f_op_actor_mng to match, we define them
// here (at the start of the *next* TU after f_op_actor_mng) so that they get placed into the correct spot in
// the DOL, even though this is an ugly hack and they're now in the wrong translation unit instead.
#include "d/actor/d_a_player.h"
void daPy_py_c::onFrollCrashFlg(u32) {}
u32 daPy_py_c::getGrabActorID() const { return -1; }

#include "f_op/f_op_camera.h"
#include "f_op/f_op_draw_tag.h"
#include "dolphin/types.h"
#include "d/d_meter.h"
#include "d/d_s_play.h"

/* 80029278-800292CC       .text fopCam_Draw__FP12camera_class */
s32 fopCam_Draw(camera_class* camera) {
    s32 cam_proc = 1;

    if (!dMenu_flag()) {
        cam_proc = fpcLf_DrawMethod(camera->mpMtd, camera);
    }
    return cam_proc;
}

/* 800292CC-80029328       .text fopCam_Execute__FP12camera_class */
s32 fopCam_Execute(camera_class* camera) {
    int ret;

    if (!dMenu_flag() && !dScnPly_ply_c::isPause()) {
        ret = fpcMtd_Execute((process_method_class*)camera->mpMtd, camera);
    }

    return ret;
}

/* 80029328-8002937C       .text fopCam_IsDelete__FP12camera_class */
s32 fopCam_IsDelete(camera_class* camera) {
    s32 ret = fpcMtd_IsDelete((process_method_class*)camera->mpMtd, camera);
    if (ret == 1)
        fopDwTg_DrawQTo(&camera->mDwTg);
    return ret;
}

/* 8002937C-800293D0       .text fopCam_Delete__FP12camera_class */
s32 fopCam_Delete(camera_class* camera) {
    s32 ret = fpcMtd_Delete((process_method_class*)camera->mpMtd, camera);
    if (ret == 1)
        fopDwTg_DrawQTo(&camera->mDwTg);
    return ret;
}

/* 800293D0-80029468       .text fopCam_Create__FPv */
s32 fopCam_Create(void* pProc) {
    camera_class* camera = (camera_class*)pProc;

    if (fpcM_IsFirstCreating(pProc)) {
        camera_process_profile_definition* profile =
            (camera_process_profile_definition*)fpcM_GetProfile(pProc);
        camera->mpMtd = profile->mSubMtd;

        fopDwTg_Init(&camera->mDwTg, camera);
        u32* append = (u32*)fpcM_GetAppend(camera);

        if (append) {
            fpcM_SetParam(camera, *append);
        }
    }

    s32 ret = fpcMtd_Create(&camera->mpMtd->mBase, camera);
    if (ret == cPhs_COMPLEATE_e) {
        s32 priority = fpcLf_GetPriority(camera);
        fopDwTg_ToDrawQ(&camera->mDwTg, priority);
    }

    return ret;
}

leafdraw_method_class g_fopCam_Method = {
    (process_method_func)fopCam_Create,
    (process_method_func)fopCam_Delete,
    (process_method_func)fopCam_Execute,
    (process_method_func)fopCam_IsDelete,
    (process_method_func)fopCam_Draw,
};
