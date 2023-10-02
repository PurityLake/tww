//
// Generated by dtk
// Translation Unit: d_a_obj_mknjd.cpp
//

#include "f_op/f_op_actor_mng.h"
#include "f_op/f_op_msg.h"
#include "f_op/f_op_draw_tag.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "JSystem/J3DGraphBase/J3DSys.h"
#include "JAZelAudio/JAIZelBasic.h"
#include "JAZelAudio/JAZelAudio_BGM.h"
#include "JAZelAudio/JAZelAudio_SE.h"
#include "d/d_procname.h"
#include "d/d_com_inf_game.h"
#include "d/d_bg_s_movebg_actor.h"
#include "d/d_bg_w.h"
#include "d/d_item_data.h"
#include "d/d_particle.h"
#include "d/actor/d_a_player.h"
#include "d/d_a_obj.h"
#include "m_Do/m_Do_ext.h"
#include "m_Do/m_Do_mtx.h"
#include "dolphin/types.h"


static const char* daObjMknjD_jointName[] = {
    "Hahen1",
    "Hahen2",
    "Hahen3",
    "Hahen4",
    "Hahen5",
    "Hahen6",
    "Hahen7",
    "Hahen8",
    "Hahen9",
    "Hahen10",
    "Hahen11",
    "Hahen12",
    "Hahen13",
    "Hahen14",
    "Hahen15",
    "Hahen16",
    "Hahen17",
    "Hahen18",
    "Hahen19",
    "Hahen20"
};

const char* daObjMknjD_EventName[] = {
    "MKNJD_D_DEMO",
    "MKNJD_K_DEMO",

    "MKNJD_D_CHECK",
    "MKNJD_K_CHECK",

    "MKNJD_D_ERROR",
    "MKNJD_K_ERROR",

    "MKNJD_D_LESSON",
    "MKNJD_K_LESSON",
};

static u16 joint_number_table[20];

namespace daObjMknjD {
    class Act_c : public dBgS_MoveBgActor {
    public:
        s32 Mthd_Create();
        s32 Mthd_Delete();

        s16 XyCheckCB(int);
        s16 XyEventCB(int);

        int CreateHeap();
        int Create();

        int Delete();

        void set_mtx();
        void init_mtx();

        void setGoal(int);
        void setPlayerAngle(int);
        u16 talk(int);
        void privateCut();
        bool daObjMknjD_break();

        int Execute(float(**)[3][4]);
        int Draw();

        static const char M_arcname[];
        static Mtx M_tmp_mtx;

        /* 0x02C8 */ cXyz mLeftHalfPos;
        /* 0x02D4 */ cXyz mRightHalfPos;

        /* 0x02E0 */ cXyz mShardPositions[0x14];
        /* 0x03D0 */ float mShardHeights[0x14];

        /* 0x0420 */ request_of_phase_process_class mPhs;

        /* 0x0428 */ J3DModel* mModel0;
        /* 0x042C */ J3DModel* mModel1;
        
        /* 0x0430 */ u16 m0430;
        /* 0x0432 */ u16 m0432;
        /* 0x0434 */ u16 m0434;
        /* 0x0438 */ u32 mBreakTimer;

        /* 0x043C */ u8 mModel0Alpha;
        /* 0x043D */ bool m043D;
        /* 0x043E */ bool m043E;
        /* 0x043F */ u8 m043F;

        /* 0x0440 */ JPABaseEmitter* mEmitter0;
        /* 0x0444 */ JPABaseEmitter* mEmitter1;
        /* 0x0448 */ JPABaseEmitter* mEmitter2;
        /* 0x044C */ JPABaseEmitter* mEmitter3;

        /* 0x0450 */ dPa_smokeEcallBack mSmokeCBs[4];

        /* 0x04D0 */ cXyz m04D0;
        
        /* 0x04DC */ s16 mCheckEventIdx;
        /* 0x04DE */ s16 mDemoEventIdx;
        /* 0x04E0 */ s16 mErrorEventIdx;
        /* 0x04E2 */ s16 mLessonEventIdx;
        
        /* 0x04E4 */ s8 mActionIdx;
        /* 0x04E5 */ u8 mTactMode;
        /* 0x04E6 */ u8 mGiveItemId;

        /* 0x04E8 */ cXyz mGoalPos;

        /* 0x04F4 */ u32 mMsgId;
        /* 0x04F8 */ u32 mMsgInstId;
        /* 0x04FC */ msg_class* mMsgPtr;

        /* 0x0500 */ s32 m0500;
        /* 0x0504 */ bool m0504;

        enum Prm_e {
            PRM_SWITCH_W = 0x08,
            PRM_SWITCH_S = 0x00,
        };

        inline int prm_get_swSave() { return daObj::PrmAbstract<Prm_e>(this, PRM_SWITCH_W, PRM_SWITCH_S); }
    };

    const char Act_c::M_arcname[] = "MknjD";

    static void manage_friend_draw(int);
    static void setMaterial(J3DMaterial*, u8);
}

/* 00000078-0000012C       .text nodeCallBackL__FP7J3DNodei */
u32 nodeCallBackL(J3DNode* i_node, int i_param2) {
    if (i_param2 == 0) {
        int jntNo = i_node->getJntNo();
        
        J3DModel* mdl = j3dSys.getModel();
        daObjMknjD::Act_c* actor = (daObjMknjD::Act_c*)mdl->getUserArea();

        if (actor != NULL) {
            mDoMtx_copy(mdl->getAnmMtx(jntNo), *calc_mtx);

            MtxTrans(actor->mLeftHalfPos.x, actor->mLeftHalfPos.y, actor->mLeftHalfPos.z, 1);

            mdl->setAnmMtx(jntNo, *calc_mtx);
            mDoMtx_copy(*calc_mtx, j3dSys.mCurrentMtx);
        }
    }

    return 1;
}

/* 0000012C-000001E0       .text nodeCallBackR__FP7J3DNodei */
u32 nodeCallBackR(J3DNode* i_node, int i_param2) {
    if (i_param2 == 0) {
        int jntNo = i_node->getJntNo();

        J3DModel* mdl = j3dSys.getModel();
        daObjMknjD::Act_c* actor = (daObjMknjD::Act_c*)mdl->getUserArea();

        if (actor != NULL) {
            mDoMtx_copy(mdl->getAnmMtx(jntNo), *calc_mtx);

            MtxTrans(actor->mRightHalfPos.x, actor->mRightHalfPos.y, actor->mRightHalfPos.z, 1);

            mdl->setAnmMtx(jntNo, *calc_mtx);
            mDoMtx_copy(*calc_mtx, j3dSys.mCurrentMtx);
        }
    }

    return 1;
}

/* 000001E0-000002B0       .text nodeCallBack_Hahen__FP7J3DNodei */
s32 nodeCallBack_Hahen(J3DNode* i_node, int i_param2) {
    if (i_param2 == 0) {
        int jntNo = i_node->getJntNo();
        u16 shardIdx = joint_number_table[jntNo - 1];

        J3DModel* mdl = j3dSys.getModel();
        daObjMknjD::Act_c* actor = (daObjMknjD::Act_c*)mdl->getUserArea();

        if (actor != NULL) {
            mDoMtx_copy(mdl->getAnmMtx(jntNo), *calc_mtx);

            MtxTrans(actor->mShardPositions[shardIdx].x, actor->mShardPositions[shardIdx].y, actor->mShardPositions[shardIdx].z, 1);

            mdl->setAnmMtx(jntNo, *calc_mtx);
            mDoMtx_copy(*calc_mtx, j3dSys.mCurrentMtx);
        }
    }

    return 1;
}

/* 000002B0-000002D0       .text daObjMknjD_XyCheckCB__FPvi */
static s16 daObjMknjD_XyCheckCB(void* i_this, int i_param2) {
    return static_cast<daObjMknjD::Act_c*>(i_this)->XyCheckCB(i_param2);
}

/* 000002D0-000002F0       .text daObjMknjD_XyEventCB__FPvi */
static s16 daObjMknjD_XyEventCB(void* i_this, int i_param2) {
    return static_cast<daObjMknjD::Act_c*>(i_this)->XyEventCB(i_param2);
}

/* 000002F0-00000314       .text XyCheckCB__Q210daObjMknjD5Act_cFi */
s16 daObjMknjD::Act_c::XyCheckCB(int i_itemIdx) {
    return dComIfGp_getSelectItem(i_itemIdx) == WIND_TACT ? 1 : 0;
}

/* 00000314-0000031C       .text XyEventCB__Q210daObjMknjD5Act_cFi */
s16 daObjMknjD::Act_c::XyEventCB(int) {
    return mLessonEventIdx;
}

/* 0000031C-00000620       .text CreateHeap__Q210daObjMknjD5Act_cFv */
int daObjMknjD::Act_c::CreateHeap() {
    /* Nonmatching */
    return 0;
}

/* 00000620-000008E8       .text Create__Q210daObjMknjD5Act_cFv */
int daObjMknjD::Act_c::Create() {
    /* Nonmatching */
    return 0;
}

/* 000008E8-00000A84       .text Mthd_Create__Q210daObjMknjD5Act_cFv */
s32 daObjMknjD::Act_c::Mthd_Create() {
    /* Nonmatching */
    return 0;
}

/* 00000B64-00000BDC       .text Delete__Q210daObjMknjD5Act_cFv */
int daObjMknjD::Act_c::Delete() {
    dComIfGp_getAttention().mFlags &= 0x7fffffff;

    for (int i = 0; i < 4; i++) {
        mSmokeCBs[i].end();
    }

    return 1;
}

/* 00000BDC-00000C34       .text Mthd_Delete__Q210daObjMknjD5Act_cFv */
s32 daObjMknjD::Act_c::Mthd_Delete() {
    int bgDeleteResult = MoveBGDelete();
    
    if (mBase.mUnk2 != 3) {
        dComIfG_resDelete(&mPhs, M_arcname);
    }

    return bgDeleteResult;
}

/* 00000C34-00000CC8       .text set_mtx__Q210daObjMknjD5Act_cFv */
void daObjMknjD::Act_c::set_mtx() {
    /* Nonmatching */
    mDoMtx_stack_c::transS(getPosition());
    mDoMtx_stack_c::ZXYrotM(shape_angle);

    mModel0->setBaseTRMtx(mDoMtx_stack_c::get());
    mModel1->setBaseTRMtx(mDoMtx_stack_c::get());

    mDoMtx_copy(mDoMtx_stack_c::get(), M_tmp_mtx);
}

/* 00000CC8-00000D28       .text init_mtx__Q210daObjMknjD5Act_cFv */
void daObjMknjD::Act_c::init_mtx() {
    /* Nonmatching */
    mModel0->setBaseScale(cXyz(1.0f, 1.0f, 1.0f));
    mModel1->setBaseScale(cXyz(1.0f, 1.0f, 1.0f));

    set_mtx();
}

/* 00000D28-00000E04       .text setGoal__Q210daObjMknjD5Act_cFi */
void daObjMknjD::Act_c::setGoal(int i_staffIdx) {
    /* Nonmatching */
    cXyz pos = *dComIfGp_evmng_getMyXyzP(i_staffIdx, "Posion");

    mDoMtx_stack_c::transS(getPosition());
    mDoMtx_YrotM(mDoMtx_stack_c::get(), current.angle.GetY());

    mDoMtx_stack_c::transM(pos);
    
    mDoMtx_multVecZero(mDoMtx_stack_c::get(), &pos);
    mGoalPos = pos;

    dComIfGp_evmng_setGoal(&mGoalPos);
}

/* 00000E04-00000E84       .text setPlayerAngle__Q210daObjMknjD5Act_cFi */
void daObjMknjD::Act_c::setPlayerAngle(int i_staffIdx) {
    /* Nonmatching */
    u32 angle = *dComIfGp_evmng_getMyIntegerP(i_staffIdx, "angle");
    daPy_py_c* player = (daPy_py_c*)dComIfGp_getPlayer(0);
    
    player->setPlayerPosAndAngle(
        player->getPositionP(),
        current.angle.y + (s16)angle
    );
}

/* 00000E84-00000F88       .text talk__Q210daObjMknjD5Act_cFi */
u16 daObjMknjD::Act_c::talk(int i_param1) {
    u32 msgMode = 0xFF;

    if (mMsgInstId == 0xFFFFFFFF) {
        if (i_param1 == 1) {
            u32 msgId;

            if (m0500 == 0) {
                g_dComIfG_gameInfo.play.mTactMode = mTactMode;
                msgId = 0x05B3;
            }
            else {
                msgId = 0x1901;
            }
            
            mMsgId = msgId;
        }

        mMsgInstId = fopMsgM_messageSet(mMsgId, this);
        mMsgPtr = NULL;
    }
    else {
        if (mMsgPtr) {
            msgMode = mMsgPtr->mMode;

            if (msgMode == 0x0E) {
                if (g_dComIfG_gameInfo.play.field_0x4949 != 0) {
                    m0504 = true;
                    fopMsgM_messageSendOn();
                }

                mMsgPtr->mMode = 0x10;
            }
            else if (msgMode == 0x12) {
                mMsgPtr->mMode = 0x13;
                mMsgInstId = 0xFFFFFFFF;
            }
        }
        else {
            mMsgPtr = fopMsgM_SearchByID(mMsgInstId);
        }
    }

    return msgMode;
}

#define ACT_SETGOAL 0
#define ACT_SETANGLE 1
#define ACT_WAIT 2
#define ACT_INPUT 3
#define ACT_BREAK 4
#define ACT_HIDE_LINK 5
#define ACT_DISP_LINK 6
#define ACT_LESSON 7
#define ACT_TACT 8

/* 00000F88-00001348       .text privateCut__Q210daObjMknjD5Act_cFv */
void daObjMknjD::Act_c::privateCut() {
    /* Nonmatching */
    static const char* cut_name_table[] = {
        "SETGOAL",
        "SETANGLE",
        "WAIT",
        "INPUT",
        "BREAK",
        "HIDE_LINK",
        "DISP_LINK",
        "LESSON",
        "TACT"
    };

    daPy_py_c* player = (daPy_py_c*)dComIfGp_getPlayer(0);

    int staffIdx = dComIfGp_evmng_getMyStaffId("MknjD", NULL, 0);
    if (staffIdx != -1) {
        mActionIdx = dComIfGp_evmng_getMyActIdx(staffIdx, cut_name_table, 9, 1, 0);

        if (mActionIdx == -1) {
            dComIfGp_evmng_cutEnd(staffIdx);
        }
        else {
            bool doCutEnd = false;
            
            if (dComIfGp_evmng_getIsAddvance(staffIdx)) {
                switch (mActionIdx) {
                    case ACT_SETGOAL:
                        setGoal(staffIdx);
                        break;
                    case ACT_SETANGLE:
                        setPlayerAngle(staffIdx);
                        break;
                    case ACT_BREAK:
                        mDoAud_seStart(JA_SE_READ_RIDDLE_1, NULL, 0, 0);

                        int switchId = prm_get_swSave();
                        fopAcM_onSwitch(this, switchId);

                        mBreakTimer = 0;

                        if (mpBgW != NULL) {
                            if (mpBgW->ChkUsed()) {
                                g_dComIfG_gameInfo.play.mBgS.Release(mpBgW);
                            }
                        }

                        break;
                    case ACT_HIDE_LINK:
                        player->onPlayerNoDraw();
                        break;
                    case ACT_DISP_LINK:
                        player->offPlayerNoDraw();
                        break;
                    case ACT_LESSON:
                        m0504 = false;
                        m0500 = 0;
                        mMsgInstId = 0xFFFFFFFF;
                        break;
                    case ACT_TACT:
                        break;
                }
            }

            switch (mActionIdx) {
                case ACT_SETGOAL:
                    doCutEnd = true;
                    break;
                case ACT_SETANGLE:
                    doCutEnd = true;
                    break;
                case ACT_INPUT:
                    if (talk(1) == 0x12) {
                        doCutEnd = true;
                    }
                    break;
                case ACT_WAIT:
                    doCutEnd = true;
                    break;
                case ACT_BREAK:
                    if (daObjMknjD_break() == true) {
                        if (strcmp(dComIfGp_getStartStageName(), "Ekaze") == 0 || strcmp(dComIfGp_getStartStageName(), "Edaichi") == 0) {
                            mDoAud_bgmStart(0x80000000 | JA_BGM_JABOO_CAVE);
                        }
                        else if (m043E == true) {
                            mDoAud_bgmStart(0x80000000 | JA_BGM_D_WIND);
                        }
                        else {
                            mDoAud_bgmStart(0x80000000 | JA_BGM_D_EARTH);
                        }

                        if (mSmokeCBs[2].getEmitter() != NULL) {
                            mSmokeCBs[2].end();
                        }
                        if (mSmokeCBs[3].getEmitter() != NULL) {
                            mSmokeCBs[3].end();
                        }

                        doCutEnd = true;
                    }
                    break;
                case ACT_LESSON:
                    u32 talkResult = talk(1);

                    if (talkResult == 0x12 || talkResult == 0x15) {
                        doCutEnd = true;
                    }
                    break;
                case ACT_TACT:
                    if (m0504 == false) {
                        doCutEnd = true;
                    }
                    else {
                        dComIfGp_event_onEventFlag(8);
                    }
                    break;
                default:
                    doCutEnd = true;
                    break;
            }

            if (doCutEnd) {
                dComIfGp_evmng_cutEnd(staffIdx);
            }
        }
    }
}

/* 00001348-00001400       .text manage_friend_draw__10daObjMknjDFi */
void daObjMknjD::manage_friend_draw(int i_param1) {
    u16 medliProc = PROC_NPC_MD;
    fopAc_ac_c* judgeResult = static_cast<fopAc_ac_c*>(fopAcIt_Judge(fpcSch_JudgeForPName, &medliProc));

    if (judgeResult != NULL) {
        if (i_param1 == 1) {
            u32 prio = fpcLf_GetPriority(judgeResult);
            fopDwTg_ToDrawQ(&judgeResult->mDwTg, prio);
        }
        else {
            fopDwTg_DrawQTo(&judgeResult->mDwTg);
        }
    }

    u16 makarProc = PROC_NPC_CB1;
    judgeResult = static_cast<fopAc_ac_c*>(fopAcIt_Judge(fpcSch_JudgeForPName, &makarProc));
    
    if (judgeResult != NULL) {
        if (i_param1 == 1) {
            u32 prio = fpcLf_GetPriority(judgeResult);
            fopDwTg_ToDrawQ(&judgeResult->mDwTg, prio);
        }
        else {
            fopDwTg_DrawQTo(&judgeResult->mDwTg);
        }
    }
}

/* 00001400-0000195C       .text daObjMknjD_break__Q210daObjMknjD5Act_cFv */
bool daObjMknjD::Act_c::daObjMknjD_break() {
    /* Nonmatching */
}

/* 0000195C-000020E0       .text Execute__Q210daObjMknjD5Act_cFPPA3_A4_f */
int daObjMknjD::Act_c::Execute(float(**)[3][4]) {
    /* Nonmatching */
    return 0;
}

/* 000020E0-000022FC       .text setMaterial__10daObjMknjDFP11J3DMaterialUc */
void daObjMknjD::setMaterial(J3DMaterial* i_mat, u8 i_alpha) {
    for (; i_mat != NULL; i_mat = i_mat->getNext()) {
        if (i_alpha == 0) {
            i_mat->getShape()->hide();
        }
        else {
            i_mat->getShape()->show();

            if (i_alpha == 0xFF) {
                i_mat->setMaterialMode(1);

                i_mat->getPEBlock()->getZMode()->setUpdateEnable(1);
                i_mat->getPEBlock()->getZMode()->setCompareEnable(1);

                i_mat->getPEBlock()->getBlend()->setType(0);
            }
            else {
                i_mat->setMaterialMode(1);

                i_mat->getPEBlock()->getZMode()->setUpdateEnable(0);
                i_mat->getPEBlock()->getZMode()->setCompareEnable(0);

                i_mat->getPEBlock()->getBlend()->setType(1);
                i_mat->getPEBlock()->getBlend()->setSrcFactor(4);
                i_mat->getPEBlock()->getBlend()->setDstFactor(5);
            }

            i_mat->getTevKColor(3)->a = i_alpha;
        }
    }
}

/* 000022FC-00002430       .text Draw__Q210daObjMknjD5Act_cFv */
int daObjMknjD::Act_c::Draw() {
    g_env_light.settingTevStruct(TEV_TYPE_BG0, getPositionP(), &mTevStr);
    g_env_light.setLightTevColorType(mModel1, &mTevStr);

    g_env_light.settingTevStruct(TEV_TYPE_BG0, getPositionP(), &mTevStr);
    g_env_light.setLightTevColorType(mModel0, &mTevStr);

    dComIfGd_setList();

    J3DModelData* mdlData = mModel0->getModelData();
    u16 jointCount = mdlData->getJointNum();
    for (u16 i = 0; i < jointCount; i++) {
        setMaterial(mdlData->getJointNodePointer(i)->getMesh(), mModel0Alpha);
    }

    dComIfGd_setListSky();

    mDoExt_modelUpdateDL(mModel0);
    if (m043D == true) {
        mDoExt_modelUpdateDL(mModel1);
    }

    dComIfGd_setListBG();

    return 1;
}

namespace daObjMknjD {
    namespace {
        /* 00002430-00002450       .text Mthd_Create__Q210daObjMknjD27@unnamed@d_a_obj_mknjd_cpp@FPv */
        s32 Mthd_Create(void* i_this) {
            return static_cast<Act_c*>(i_this)->Mthd_Create();
        }

        /* 00002450-00002470       .text Mthd_Delete__Q210daObjMknjD27@unnamed@d_a_obj_mknjd_cpp@FPv */
        s32 Mthd_Delete(void* i_this) {
            return static_cast<Act_c*>(i_this)->Mthd_Delete();
        }

        /* 00002470-00002490       .text Mthd_Execute__Q210daObjMknjD27@unnamed@d_a_obj_mknjd_cpp@FPv */
        s32 Mthd_Execute(void* i_this) {
            return static_cast<Act_c*>(i_this)->MoveBGExecute();
        }

        /* 00002490-000024BC       .text Mthd_Draw__Q210daObjMknjD27@unnamed@d_a_obj_mknjd_cpp@FPv */
        s32 Mthd_Draw(void* i_this) {
            return static_cast<Act_c*>(i_this)->Draw();
        }

        /* 000024BC-000024E8       .text Mthd_IsDelete__Q210daObjMknjD27@unnamed@d_a_obj_mknjd_cpp@FPv */
        s32 Mthd_IsDelete(void* i_this) {
            return static_cast<Act_c*>(i_this)->IsDelete();
        }

        static actor_method_class Mthd_Table = {
            (process_method_func)Mthd_Create,
            (process_method_func)Mthd_Delete,
            (process_method_func)Mthd_Execute,
            (process_method_func)Mthd_IsDelete,
            (process_method_func)Mthd_Draw,
        };
    }
}

extern actor_process_profile_definition g_profile_Obj_MknjD = {
    fpcLy_CURRENT_e,
    3,
    fpcPi_CURRENT_e,
    PROC_Obj_MknjD,
    &g_fpcLf_Method.mBase,
    sizeof(daObjMknjD::Act_c),
    0,
    0,
    &g_fopAc_Method.base,
    0x01C6,
    &daObjMknjD::Mthd_Table,
    0x00044100,
    fopAc_ACTOR_e,
    fopAc_CULLBOX_CUSTOM_e,
};
