//
// Generated by dtk
// Translation Unit: d_com_inf_game.cpp
//

#include "d/d_com_inf_game.h"
#include "JSystem/JUtility/JUTAssert.h"
#include "MSL_C/string.h"
#include "SSystem/SComponent/c_phase.h"
#include "d/actor/d_a_player_link.h"
#include "d/d_com_lib_game.h"
#include "d/d_demo.h"
#include "d/d_flower.h"
#include "d/d_grass.h"
#include "d/d_item_data.h"
#include "d/d_magma.h"
#include "d/d_particle.h"
#include "d/d_tree.h"
#include "f_op/f_op_scene_mng.h"
#include "m_Do/m_Do_Reset.h"
#include "m_Do/m_Do_audio.h"

class J3DModel;
class daArrow_c {
public:
    static void setKeepType(u8);
};

class daShip_c : public fopAc_ac_c {
public:
};

dComIfG_inf_c g_dComIfG_gameInfo;

/* 80052134-800521A4       .text ct__14dComIfG_play_cFv */
void dComIfG_play_c::ct() {
    field_0x4841 = 0;
    mParticle = NULL;
    mDemo = NULL;
    mpMagmaPacket = NULL;
    mpGrassPacket = NULL;
    mpTreePacket = NULL;
    mpWoodPacket = NULL;
    mpFlowerPacket = NULL;
    mShipId = 0xFF;
    mShipRoomId = 0xFF;
    mIkadaShipBeforeRoomId = 0xFF;
    mIkadaShipId = 0xFF;
    mIkadaLinkPos.set(0.0f, 0.0f, 0.0f);
    mLkDArcIdx = -1;

    init();
}

/* 800521A4-800521D4       .text init__14dComIfG_play_cFv */
void dComIfG_play_c::init() {
    for (int i = 0; i < 1; i++) {
        mpPlayer[i] = NULL;
        mCurCamera[i] = -1;
    }

    for (int i = 0; i < 3; i++) {
        mpPlayerPtr[i] = NULL;
    }
}

/* 800521D4-80052400       .text itemInit__14dComIfG_play_cFv */
void dComIfG_play_c::itemInit() {
    field_0x48b8 = 0.0f;
    mItemLifeCount = 0.0f;
    mItemRupeeCount = 0;
    mAirMeter = 0;
    field_0x48c8 = 0;
    mNpcNameMessageID = 0;
    mItemNameMessageID = 0;
    mItemKeyNumCount = 0;
    mItemMaxLifeCount = 0;
    mItemMagicCount = 0;
    field_0x48da = 0;
    mItemMaxMagicCount = 0;
    field_0x48de = 0;
    mItemArrowNumCount = 0;
    field_0x48e2 = 0;
    mItemBombNumCount = 0;
    field_0x48e6 = 0;

    for (int i = 0; i < 4; i++) {
    }

    mMsgCountNumber = 0;
    field_0x491a = 0;
    field_0x491c = 0;
    field_0x491e = 0;
    field_0x4920 = 0;
    field_0x4922 = 0;
    mCurrHP = 0;
    mRupyCountDisplay = 0;
    field_0x4928 = 0;
    field_0x4929 = 0;
    field_0x492a = 0;
    mbCamOverrideFarPlane = 0;
    field_0x492c = 0;
    field_0x492d = 0;
    mCurrButtonBAction = 0;
    mCurrButtonAAction = 0;
    field_0x4930 = 0;
    field_0x4931 = 0;
    field_0x4932 = 0;

    for (int i = 0; i < 4; i++) {
        mEquippedItems[i] = 0;
        field_0x4937[i] = 0;
    }

    mMesgAnime = 0;
    mMesgAnimeTagInfo = 0;
    field_0x493d = 0;
    field_0x493e = 0;
    field_0x493f = 0;
    field_0x4940 = 0;
    field_0x4941 = 0;
    field_0x4942 = 0;

    if (dComIfGs_checkGetItem(TELESCOPE)) {
        field_0x4943 = 0;
    } else {
        field_0x4943 = 0x15;
    }

    field_0x4944 = 7;
    field_0x4945 = 0;
    field_0x4946 = 0;
    field_0x4947 = 0;
    field_0x4948 = 0;
    field_0x4949 = 0;

    for (int i = 0; i < 6; i++) {
        field_0x494a[i] = 0;
    }

    mTactMode = 0;
    field_0x4951 = 0;
    field_0x4952 = 0;
    field_0x4953 = 0;
    field_0x4954 = 0;
    field_0x4955 = 0;
    field_0x4956 = 0;
    mPlacenameIndex = 0;
    mPlacenameState = 0;
    field_0x4959 = 0;
    field_0x495a = 0;
    field_0x495b = 0;
    field_0x495c = 0;
    field_0x495d = 0;
    field_0x495e = 0;
    field_0x495f = 0;
    field_0x4960 = 0;
    field_0x4961 = 0;
    mHeapLockFlag = 0;
    field_0x4965 = 0;

    strcpy(field_0x4966, "\0");

    field_0x4977 = 0;
    field_0x4978 = 0;
    field_0x4979 = 0;
    field_0x497a = 0;
    field_0x4963 = dComIfGs_getOptVibration();
    daArrow_c::setKeepType(0);
    mMesgCameraTagInfo = 0;
    field_0x4984 = 0;

    for (int i = 0; i < 10; i++) {
        field_0x4988[i] = 0;
    }

    return;
}

/* 80052400-8005286C       .text getLayerNo__14dComIfG_play_cFi */
int dComIfG_play_c::getLayerNo(int i_roomNo) {
    int stageLayer = dComIfGp_getStartStageLayer();
    if (stageLayer < 0) {
        int layer = dKy_getdaytime_hour();
        if (dKy_checkEventNightStop()) {
            layer = 1;
        } else {
            layer = (layer >= 6 && layer < 18) ? 0 : 1;
        }

        if (strcmp(dComIfGp_getStartStageName(), "sea") == 0) {
            if (i_roomNo == 44) {
                if (dComIfGs_isEventBit(0x520)) {
                    return layer | 4;
                } else if (dComIfGs_isEventBit(0xE20)) {
                    return layer | 2;
                } else if (dComIfGs_isEventBit(0x101)) {
                    return 9;
                }
            } else if (i_roomNo == 11) {
                if (dComIfGs_isEventBit(0x2D01)) {
                    return layer | 4;
                } else if (dKy_checkEventNightStop()) {
                    return layer | 2;
                }
            } else if (i_roomNo == 1) {
                return dComIfGs_isEventBit(0x1820) ? 3 : 1;
            }
        } else if (strcmp(dComIfGp_getStartStageName(), "A_mori") == 0) {
            if (dComIfGs_isEventBit(0xF80)) {
                return layer | 2;
            }
        } else if (strcmp(dComIfGp_getStartStageName(), "Asoko") == 0) {
            if (dComIfGs_isEventBit(0x520)) {
                return layer | 2;
            }
        } else if (strcmp(dComIfGp_getStartStageName(), "Hyrule") == 0) {
            if (dComIfGs_getTriforceNum() == 8) {
                return layer | 4;
            } else if (dComIfGs_isEventBit(0x3280)) {
                return layer | 2;
            }
        } else if (strcmp(dComIfGp_getStartStageName(), "Hyroom") == 0) {
            if (dComIfGs_getTriforceNum() == 8 && !dComIfGs_isEventBit(0x2C01)) {
                return layer | 4;
            } else if (dComIfGs_isEventBit(0x3280)) {
                return layer | 2;
            } else if (dComIfGs_isEventBit(0x3B40)) {
                return layer | 6;
            }
        } else if (strcmp(dComIfGp_getStartStageName(), "kenroom") == 0) {
            if (dComIfGs_isEventBit(0x2C01) ||
                (dComIfGs_isEventBit(0x3802) && !dComIfGs_isEventBit(0x3280)))
            {
                return layer | 6;
            } else if (dComIfGs_getTriforceNum() == 8) {
                return layer | 4;
            } else if (dComIfGs_isEventBit(0x3802)) {
                return layer | 2;
            }
        } else if (strcmp(dComIfGp_getStartStageName(), "M2tower") == 0) {
            if (dComIfGs_isEventBit(0x2D01)) {
                return layer | 2;
            }
        } else if (strcmp(dComIfGp_getStartStageName(), "GanonK") == 0) {
            if (!dComIfGs_isEventBit(0x3B02)) {
                return 8;
            }
        } else if (strcmp(dComIfGp_getStartStageName(), "GTower") == 0) {
            if (!dComIfGs_isEventBit(0x4002)) {
                return 8;
            }
        }

        return layer;
    }

    return stageLayer;
}

/* 8005286C-800528F4       .text createParticle__14dComIfG_play_cFv */
void dComIfG_play_c::createParticle() {
    mParticle = new dPa_control_c();

    JUT_ASSERT(360, mParticle != 0);
}

/* 800528F4-8005297C       .text createDemo__14dComIfG_play_cFv */
void dComIfG_play_c::createDemo() {
    mDemo = new dDemo_manager_c();

    JUT_ASSERT(390, mDemo != 0);
}

/* 8005297C-800529B8       .text removeDemo__14dComIfG_play_cFv */
void dComIfG_play_c::removeDemo() {
    delete mDemo;
    mDemo = NULL;
}

/* 800529B8-800529DC       .text executeEvtManager__14dComIfG_play_cFv */
void dComIfG_play_c::executeEvtManager() {
    mEvtManager.runProc();
}

/* 800529DC-80052A30       .text createMagma__14dComIfG_play_cFv */
dMagma_packet_c* dComIfG_play_c::createMagma() {
    if (mpMagmaPacket == NULL) {
        mpMagmaPacket = new dMagma_packet_c();
    }

    return mpMagmaPacket;
}

/* 80052A30-80052A84       .text removeMagma__14dComIfG_play_cFv */
void dComIfG_play_c::removeMagma() {
    if (mpMagmaPacket != NULL) {
        delete mpMagmaPacket;
        mpMagmaPacket = NULL;
    }
}

/* 80052A84-80052AB0       .text executeMagma__14dComIfG_play_cFv */
void dComIfG_play_c::executeMagma() {
    if (mpMagmaPacket != NULL) {
        mpMagmaPacket->calc();
    }
}

/* 80052AB0-80052ADC       .text drawMagma__14dComIfG_play_cFv */
void dComIfG_play_c::drawMagma() {
    if (mpMagmaPacket != NULL) {
        mpMagmaPacket->update();
    }
}

/* 80052ADC-80052B34       .text createGrass__14dComIfG_play_cFv */
dGrass_packet_c* dComIfG_play_c::createGrass() {
    if (mpGrassPacket == NULL) {
        mpGrassPacket = new dGrass_packet_c();
    }

    return mpGrassPacket;
}

/* 80052B34-80052B88       .text removeGrass__14dComIfG_play_cFv */
void dComIfG_play_c::removeGrass() {
    if (mpGrassPacket != NULL) {
        delete mpGrassPacket;
        mpGrassPacket = NULL;
    }
}

/* 80052B88-80052C0C       .text __dt__15dGrass_packet_cFv */
dGrass_packet_c::~dGrass_packet_c() {}

/* 80052C0C-80052C48       .text __dt__13dGrass_data_cFv */
dGrass_data_c::~dGrass_data_c() {}

/* 80052C48-80052C74       .text executeGrass__14dComIfG_play_cFv */
void dComIfG_play_c::executeGrass() {
    if (mpGrassPacket != NULL) {
        mpGrassPacket->calc();
    }
}

/* 80052C74-80052CA0       .text drawGrass__14dComIfG_play_cFv */
void dComIfG_play_c::drawGrass() {
    if (mpGrassPacket != NULL) {
        mpGrassPacket->update();
    }
}

/* 80052CA0-80052CF4       .text createFlower__14dComIfG_play_cFv */
dFlower_packet_c* dComIfG_play_c::createFlower() {
    if (mpFlowerPacket == NULL) {
        mpFlowerPacket = new dFlower_packet_c();
    }

    return mpFlowerPacket;
}

/* 80052CF4-80052D48       .text removeFlower__14dComIfG_play_cFv */
void dComIfG_play_c::removeFlower() {
    if (mpFlowerPacket != NULL) {
        delete mpFlowerPacket;
        mpFlowerPacket = NULL;
    }
}

/* 80052D48-80052DCC       .text __dt__16dFlower_packet_cFv */
dFlower_packet_c::~dFlower_packet_c() {}

/* 80052DCC-80052E08       .text __dt__14dFlower_data_cFv */
dFlower_data_c::~dFlower_data_c() {}

/* 80052E08-80052E34       .text executeFlower__14dComIfG_play_cFv */
void dComIfG_play_c::executeFlower() {
    if (mpFlowerPacket != NULL) {
        mpFlowerPacket->calc();
    }
}

/* 80052E34-80052E60       .text drawFlower__14dComIfG_play_cFv */
void dComIfG_play_c::drawFlower() {
    if (mpFlowerPacket != NULL) {
        mpFlowerPacket->update();
    }
}

/* 80052E60-80052EB4       .text createTree__14dComIfG_play_cFv */
dTree_packet_c* dComIfG_play_c::createTree() {
    if (mpTreePacket == NULL) {
        mpTreePacket = new dTree_packet_c();
    }

    return mpTreePacket;
}

/* 80052EB4-80052F08       .text removeTree__14dComIfG_play_cFv */
void dComIfG_play_c::removeTree() {
    if (mpTreePacket != NULL) {
        delete mpTreePacket;
        mpTreePacket = NULL;
    }
}

/* 80052F08-80052FA4       .text __dt__14dTree_packet_cFv */
dTree_packet_c::~dTree_packet_c() {}

/* 80052FA4-80052FE0       .text __dt__12dTree_data_cFv */
dTree_data_c::~dTree_data_c() {}

/* 80052FE0-8005301C       .text __dt__11dTree_anm_cFv */
dTree_anm_c::~dTree_anm_c() {}

/* 8005301C-80053048       .text executeTree__14dComIfG_play_cFv */
void dComIfG_play_c::executeTree() {
    if (mpTreePacket != NULL) {
        mpTreePacket->calc();
    }
}

/* 80053048-80053074       .text drawTree__14dComIfG_play_cFv */
void dComIfG_play_c::drawTree() {
    if (mpTreePacket != NULL) {
        mpTreePacket->update();
    }
}

/* 80053074-800530CC       .text createWood__14dComIfG_play_cFv */
dWood::Packet_c* dComIfG_play_c::createWood() {
    if (mpWoodPacket == NULL) {
        mpWoodPacket = new dWood::Packet_c();
    }

    return mpWoodPacket;
}

/* 800530CC-80053120       .text removeWood__14dComIfG_play_cFv */
void dComIfG_play_c::removeWood() {
    if (mpWoodPacket != NULL) {
        delete mpWoodPacket;
        mpWoodPacket = NULL;
    }
}

/* 80053120-8005314C       .text executeWood__14dComIfG_play_cFv */
void dComIfG_play_c::executeWood() {
    if (mpWoodPacket != NULL) {
        mpWoodPacket->calc();
    }
}

/* 8005314C-80053178       .text drawWood__14dComIfG_play_cFv */
void dComIfG_play_c::drawWood() {
    if (mpWoodPacket != NULL) {
        mpWoodPacket->update();
    }
}

/* 80053178-800531A8       .text ct__13dComIfG_inf_cFv */
void dComIfG_inf_c::ct() {
    field_0x1d1c1 = 0xFF;
    play.ct();
}

/* 800531A8-8005326C       .text dComIfG_changeOpeningScene__FP11scene_classs */
// matches with stringbase offset
int dComIfG_changeOpeningScene(scene_class* i_scene, s16 i_procName) {
    dComIfGp_offEnableNextStage();

    dComIfGp_setNextStage("sea_T", 0, 44, 0, 0.0f, 0, 1, 0);
    mDoAud_setSceneName(dComIfGp_getNextStageName(), dComIfGp_getNextStageRoomNo(),
                        dComIfGp_getNextStageLayer());
    dComIfGs_setRestartRoomParam(0);

    fopScnM_ChangeReq(i_scene, i_procName, 0, 30);
    fopScnM_ReRequest(i_procName, 0);
    return 1;
}

/* 8005326C-800532D8       .text dComIfG_resetToOpening__FP11scene_class */
int dComIfG_resetToOpening(scene_class* i_scene) {
    if (!mDoRst::isReset()) {
        return 0;
    }

    dComIfG_changeOpeningScene(i_scene, 8);
    mDoAud_bgmStop(30);
    mDoAud_resetProcess();
    return 1;
}

/* 800532D8-80053330       .text phase_1__FPc */
// matches with stringbase
static int phase_1(char* i_arcName) {
    return !dComIfG_setObjectRes(i_arcName, (u8)0, NULL) ? cPhs_ERROR_e : cPhs_NEXT_e;
}

/* 80053330-80053388       .text phase_2__FPc */
static int phase_2(char* i_arcName) {
    int syncStatus = dComIfG_syncObjectRes(i_arcName);

    if (syncStatus < 0) {
        return cPhs_ERROR_e;
    } else {
        return syncStatus > 0 ? 0 : 2;
    }
}

/* 80053388-80053390       .text phase_3__FPc */
static int phase_3(char* i_arcName) {
    return cPhs_COMPLEATE_e;
}

/* 80053390-800533D0       .text dComIfG_resLoad__FP30request_of_phase_process_classPCc */
int dComIfG_resLoad(request_of_phase_process_class* i_phase, const char* i_arcName) {
    static int (*l_method[3])(void*) = {(int (*)(void*))phase_1, (int (*)(void*))phase_2,
                                        (int (*)(void*))phase_3};

    if (i_phase->id == cPhs_NEXT_e) {
        return cPhs_COMPLEATE_e;
    }

    return dComLbG_PhaseHandler(i_phase, l_method, (void*)i_arcName);
}

/* 800533D0-8005347C       .text dComIfG_resDelete__FP30request_of_phase_process_classPCc */
// matches with stringbase
int dComIfG_resDelete(request_of_phase_process_class* i_phase, const char* i_resName) {
    JUT_ASSERT(1048, i_phase->id != 1);

    if (i_phase->id == cPhs_NEXT_e) {
        dComIfG_deleteObjectRes(i_resName);
        i_phase->id = cPhs_INIT_e;
    }

    return 0;
}

/* 8005347C-800534C4       .text dComIfGp_getReverb__Fi */
s8 dComIfGp_getReverb(int param_0) {
    return dStage_roomRead_dt_c_GetReverbStage(*dComIfGp_getStageRoom(), param_0);
}

/* 800534C4-800535B8       .text dComIfGd_setSimpleShadow2__FP4cXyzffR13cBgS_PolyInfosfP9_GXTexObj
 */
int dComIfGd_setSimpleShadow2(cXyz* i_pos, f32 param_1, f32 param_2, cBgS_PolyInfo& i_floorPoly,
                              s16 i_angle, f32 param_5, GXTexObj* i_tex) {
    if (i_floorPoly.ChkSetInfo() && -1000000000.0f != param_1) {
        cM3dGPla* plane_p =
            dComIfG_Bgsp()->GetTriPla(i_floorPoly.GetBgIndex(), i_floorPoly.GetPolyIndex());

        return dComIfGd_setSimpleShadow(i_pos, param_1, param_2, &plane_p->mNormal, i_angle,
                                        param_5, i_tex);
    } else {
        return 0;
    }
}

/* 800535B8-80053678       .text dComIfGp_getShip__Fii */
dStage_Ship_data* dComIfGp_getShip(int i_roomNo, int param_1) {
    dStage_roomStatus_c* roomSt_p = dComIfGp_roomControl_getStatusRoomDt(i_roomNo);
    if (roomSt_p == NULL) {
        return NULL;
    }

    dStage_Ship_c* ship_p = roomSt_p->getShip();
    if (ship_p == NULL || ship_p->num <= 0 || param_1 == 0xFF) {
        return NULL;
    }

    dStage_Ship_data* data_p = ship_p->m_entries;
    if (data_p == NULL) {
        return NULL;
    }

    for (int i = 0; i < ship_p->num; i++) {
        if (param_1 == data_p->field_0xe) {
            return data_p;
        }

        data_p++;
    }

    return NULL;
}

/* 80053678-80053728       .text dComIfGp_getMapTrans__FiPfPfPs */
bool dComIfGp_getMapTrans(int i_roomNo, f32* o_transX, f32* o_transY, s16* o_angle) {
    dStage_Multi_c* multi_p = dComIfGp_getMulti();
    if (multi_p == NULL) {
        return false;
    }

    dStage_Mult_info* data_p = multi_p->m_entries;
    for (int i = 0; i < multi_p->num; i++) {
        if (i_roomNo == data_p->mRoomNo) {
            *o_transX = data_p->mTransX;
            *o_transY = data_p->mTransY;
            *o_angle = data_p->mAngle;
            return true;
        }
        data_p++;
    }

    return false;
}

/* 80053728-80053778       .text dComIfGp_getRoomCamera__Fi */
stage_camera_class* dComIfGp_getRoomCamera(int i_roomNo) {
    dStage_roomStatus_c* status = dComIfGp_roomControl_getStatusRoomDt(i_roomNo);

    if (status == NULL) {
        return NULL;
    }

    return status->getCamera();
}

/* 80053778-800537C8       .text dComIfGp_getRoomArrow__Fi */
stage_arrow_class* dComIfGp_getRoomArrow(int i_roomNo) {
    dStage_roomStatus_c* status = dComIfGp_roomControl_getStatusRoomDt(i_roomNo);

    if (status == NULL) {
        return NULL;
    }

    return status->getArrow();
}

/* 800537C8-8005388C       .text dComIfGp_setNextStage__FPCcsScScfUliSc */
void dComIfGp_setNextStage(const char* i_stageName, s16 i_point, s8 i_roomNo, s8 i_layer,
                           f32 i_lastSpeed, u32 i_lastMode, int i_setPoint, s8 i_wipe) {
    g_dComIfG_gameInfo.play.setNextStage(i_stageName, i_roomNo, i_point, i_layer, i_wipe);

    if (daPy_getPlayerLinkActorClass() != NULL) {
        u32 mode = daPy_getPlayerLinkActorClass()->mNoResetFlg1;

        if (mode & daPy_lk_c::daPyFlg1_EQUIP_DRAGON_SHIELD) {
            i_lastMode |= 0x8000;
        }

        i_lastMode |= daPy_getPlayerLinkActorClass()->field_0x354e << 16;

        if (mode & daPy_lk_c::daPyFlg1_UNK8000) {
            i_lastMode |= 0x4000;
        }
    }

    g_dComIfG_gameInfo.save.getRestart().setLastSceneInfo(i_lastSpeed, i_lastMode);
    if (i_setPoint) {
        dComIfGs_setStartPoint(i_point);
    }
}

/* 8005388C-80053918       .text dComIfGs_onStageTbox__Fii */
void dComIfGs_onStageTbox(int i_stageNo, int i_no) {
    stage_stag_info_class* stag_info = dComIfGp_getStageStagInfo();

    if (i_stageNo == dStage_stagInfo_GetSaveTbl(stag_info)) {
        dComIfGs_onTbox(i_no);
    }

    dComIfGs_onSaveTbox(i_stageNo, i_no);
}

/* 80053918-800539A8       .text dComIfGs_isStageTbox__Fii */
BOOL dComIfGs_isStageTbox(int i_stageNo, int i_no) {
    stage_stag_info_class* stag_info = dComIfGp_getStageStagInfo();

    if (i_stageNo == dStage_stagInfo_GetSaveTbl(stag_info)) {
        return dComIfGs_isTbox(i_no);
    } else {
        return dComIfGs_isSaveTbox(i_stageNo, i_no);
    }
}

/* 800539A8-80053A2C       .text dComIfGs_isStageBossEnemy__Fi */
BOOL dComIfGs_isStageBossEnemy(int i_stageNo) {
    stage_stag_info_class* stag_info = dComIfGp_getStageStagInfo();

    if (i_stageNo == dStage_stagInfo_GetSaveTbl(stag_info)) {
        return dComIfGs_isStageBossEnemy();
    } else {
        return g_dComIfG_gameInfo.save.getSavedata().getSave(i_stageNo).getBit().isStageBossEnemy();
    }
}

/* 80053A2C-80053AAC       .text dComIfGs_onStageLife__Fi */
void dComIfGs_onStageLife(int i_stageNo) {
    stage_stag_info_class* stag_info = dComIfGp_getStageStagInfo();

    if (i_stageNo == dStage_stagInfo_GetSaveTbl(stag_info)) {
        dComIfGs_onStageLife();
    }

    g_dComIfG_gameInfo.save.getSavedata().getSave(i_stageNo).getBit().onStageLife();
}

/* 80053AAC-80053B30       .text dComIfGs_isStageLife__Fi */
BOOL dComIfGs_isStageLife(int i_stageNo) {
    stage_stag_info_class* stag_info = dComIfGp_getStageStagInfo();

    if (i_stageNo == dStage_stagInfo_GetSaveTbl(stag_info)) {
        return dComIfGs_isStageLife();
    } else {
        return g_dComIfG_gameInfo.save.getSavedata().getSave(i_stageNo).getBit().isStageLife();
    }
}

/* 80053B30-80053F70       .text dComIfGs_checkGetItem__FUc */
u8 dComIfGs_checkGetItem(u8 i_itemNo) {
    u8 get_item = 0;

    switch (i_itemNo) {
    case TACT_SONG1:
        if (dComIfGs_isTact(0)) {
            get_item = 1;
        }
        break;
    case TACT_SONG2:
        if (dComIfGs_isTact(1)) {
            get_item = 1;
        }
        break;
    case TACT_SONG3:
        if (dComIfGs_isTact(2)) {
            get_item = 1;
        }
        break;
    case TACT_SONG4:
        if (dComIfGs_isTact(3)) {
            get_item = 1;
        }
        break;
    case TACT_SONG5:
        if (dComIfGs_isTact(4)) {
            get_item = 1;
        }
        break;
    case TACT_SONG6:
        if (dComIfGs_isTact(5)) {
            get_item = 1;
        }
        break;
    case TRIFORCE1:
        if (dComIfGs_isTriforce(0)) {
            get_item = 1;
        }
        break;
    case TRIFORCE2:
        if (dComIfGs_isTriforce(1)) {
            get_item = 1;
        }
        break;
    case TRIFORCE3:
        if (dComIfGs_isTriforce(2)) {
            get_item = 1;
        }
        break;
    case TRIFORCE4:
        if (dComIfGs_isTriforce(3)) {
            get_item = 1;
        }
        break;
    case TRIFORCE5:
        if (dComIfGs_isTriforce(4)) {
            get_item = 1;
        }
        break;
    case TRIFORCE6:
        if (dComIfGs_isTriforce(5)) {
            get_item = 1;
        }
        break;
    case TRIFORCE7:
        if (dComIfGs_isTriforce(6)) {
            get_item = 1;
        }
        break;
    case TRIFORCE8:
        if (dComIfGs_isTriforce(7)) {
            get_item = 1;
        }
        break;
    case PEARL1:
        if (dComIfGs_isSymbol(0)) {
            get_item = 1;
        }
        break;
    case PEARL2:
        if (dComIfGs_isSymbol(1)) {
            get_item = 1;
        }
        break;
    case PEARL3:
        if (dComIfGs_isSymbol(2)) {
            get_item = 1;
        }
        break;
    case PIRATES_OMAMORI:
        if (dComIfGs_isCollect(3, 0)) {
            get_item = 1;
        }
        break;
    case HEROS_OMAMORI:
        if (dComIfGs_isCollect(4, 0)) {
            get_item = 1;
        }
        break;
    default:
        for (int i = 0; i < 60; i++) {
            if (i_itemNo == dComIfGs_getItem(i)) {
                get_item++;
            }
        }

        for (int i = 0; i < 3; i++) {
            if (i_itemNo == dComIfGs_getSelectEquip(i)) {
                get_item++;
            }
        }

        if (i_itemNo >= 0xBF && i_itemNo <= NO_ITEM - 1 &&
            dComIfGs_isGetCollectMap(NO_ITEM - i_itemNo))
        {
            get_item++;
        }
        break;
    }

    return get_item;
}

/* 80053F70-80054578       .text dComIfGs_checkGetItemNum__FUc */
u8 dComIfGs_checkGetItemNum(u8 i_itemNo) {
    u8 get_item = 0;

    switch (i_itemNo) {
    case TACT_SONG1:
        if (dComIfGs_isTact(0)) {
            get_item = 1;
        }
        break;
    case TACT_SONG2:
        if (dComIfGs_isTact(1)) {
            get_item = 1;
        }
        break;
    case TACT_SONG3:
        if (dComIfGs_isTact(2)) {
            get_item = 1;
        }
        break;
    case TACT_SONG4:
        if (dComIfGs_isTact(3)) {
            get_item = 1;
        }
        break;
    case TACT_SONG5:
        if (dComIfGs_isTact(4)) {
            get_item = 1;
        }
        break;
    case TACT_SONG6:
        if (dComIfGs_isTact(5)) {
            get_item = 1;
        }
        break;
    case TRIFORCE1:
        if (dComIfGs_isTriforce(0)) {
            get_item = 1;
        }
        break;
    case TRIFORCE2:
        if (dComIfGs_isTriforce(1)) {
            get_item = 1;
        }
        break;
    case TRIFORCE3:
        if (dComIfGs_isTriforce(2)) {
            get_item = 1;
        }
        break;
    case TRIFORCE4:
        if (dComIfGs_isTriforce(3)) {
            get_item = 1;
        }
        break;
    case TRIFORCE5:
        if (dComIfGs_isTriforce(4)) {
            get_item = 1;
        }
        break;
    case TRIFORCE6:
        if (dComIfGs_isTriforce(5)) {
            get_item = 1;
        }
        break;
    case TRIFORCE7:
        if (dComIfGs_isTriforce(6)) {
            get_item = 1;
        }
        break;
    case TRIFORCE8:
        if (dComIfGs_isTriforce(7)) {
            get_item = 1;
        }
        break;
    case PEARL1:
        if (dComIfGs_isSymbol(0)) {
            get_item = 1;
        }
        break;
    case PEARL2:
        if (dComIfGs_isSymbol(1)) {
            get_item = 1;
        }
        break;
    case PEARL3:
        if (dComIfGs_isSymbol(2)) {
            get_item = 1;
        }
        break;
    case PIRATES_OMAMORI:
        if (dComIfGs_isCollect(3, 0)) {
            get_item = 1;
        }
        break;
    case HEROS_OMAMORI:
        if (dComIfGs_isCollect(4, 0)) {
            get_item = 1;
        }
        break;
    case BOW:
        if (dComIfGs_getItem(12)) {
            get_item = dComIfGs_getArrowNum();
        }
        break;
    case BOMB_BAG:
        if (dComIfGs_getItem(13)) {
            get_item = dComIfGs_getBombNum();
        }
        break;
    case SKULL_NECKLACE:
        for (int i = 0; i < 8; i++) {
            if (dComIfGs_getBeast(i) == SKULL_NECKLACE) {
                get_item = dComIfGs_getBeastNum(0);
            }
        }
        break;
    case BOKOBABA_SEED:
        for (int i = 0; i < 8; i++) {
            if (dComIfGs_getBeast(i) == BOKOBABA_SEED) {
                get_item = dComIfGs_getBeastNum(1);
            }
        }
        break;
    case GOLDEN_FEATHER:
        for (int i = 0; i < 8; i++) {
            if (dComIfGs_getBeast(i) == GOLDEN_FEATHER) {
                get_item = dComIfGs_getBeastNum(2);
            }
        }
        break;
    case BOKO_BELT:
        for (int i = 0; i < 8; i++) {
            if (dComIfGs_getBeast(i) == BOKO_BELT) {
                get_item = dComIfGs_getBeastNum(3);
            }
        }
        break;
    case RED_JELLY:
        for (int i = 0; i < 8; i++) {
            if (dComIfGs_getBeast(i) == RED_JELLY) {
                get_item = dComIfGs_getBeastNum(4);
            }
        }
        break;
    case GREEN_JELLY:
        for (int i = 0; i < 8; i++) {
            if (dComIfGs_getBeast(i) == GREEN_JELLY) {
                get_item = dComIfGs_getBeastNum(5);
            }
        }
        break;
    case BLUE_JELLY:
        for (int i = 0; i < 8; i++) {
            if (dComIfGs_getBeast(i) == BLUE_JELLY) {
                get_item = dComIfGs_getBeastNum(6);
            }
        }
        break;
    case PENDANT:
        for (int i = 0; i < 8; i++) {
            if (dComIfGs_getBeast(i) == PENDANT) {
                get_item = dComIfGs_getBeastNum(7);
            }
        }
        break;
    default:
        for (int i = 0; i < 60; i++) {
            if (i_itemNo == dComIfGs_getItem(i)) {
                get_item = 1;
            }
        }

        for (int i = 0; i < 3; i++) {
            if (i_itemNo == dComIfGs_getSelectEquip(i)) {
                get_item = 1;
            }
        }

        if (i_itemNo >= 0xBF && i_itemNo <= NO_ITEM - 1 &&
            dComIfGs_isGetCollectMap(NO_ITEM - i_itemNo))
        {
            get_item = 1;
        }
        break;
    }

    return get_item;
}

/* 80054578-8005468C       .text
 * dComIfGd_setShadow__FUlScP8J3DModelP4cXyzffffR13cBgS_PolyInfoP12dKy_tevstr_csfP9_GXTexObj */
int dComIfGd_setShadow(u32 id, s8 param_2, J3DModel* pModel, cXyz* pPos, f32 param_5, f32 param_6,
                       f32 y, f32 param_8, cBgS_PolyInfo& pFloorPoly, dKy_tevstr_c* param_10,
                       s16 rotY, f32 param_12, GXTexObj* pTexObj) {
    if (param_8 <= -1000000000.0f) {
        return 0;
    }

    int sid = dComIfGd_setRealShadow2(id, param_2, pModel, pPos, param_5, y - param_8, param_10);
    if (sid == 0) {
        cXyz i_pos(pPos->x, y, pPos->z);
        dComIfGd_setSimpleShadow2(&i_pos, param_8, param_6, pFloorPoly, rotY, param_12, pTexObj);
    }
    return sid;
}

static void dummy() {
    OSReport("0 <= cam_id && cam_id < mapc->num");
    OSReport("0 <= arrow_id && arrow_id < mapa->num");
    OSReport("0 <= room_cam_id && room_cam_id < pcam->num");
    OSReport("0 <= arrow_id && arrow_id < parr->num");
}

/* 8005468C-800547BC       .text getSceneList__Fi */
stage_scls_info_class* getSceneList(int i_no) {
    stage_scls_info_dummy_class* sclsInfo = dComIfGp_getStage().getSclsInfo();
    JUT_ASSERT(2132, sclsInfo != 0);

    JUT_ASSERT(2134, 0 <= i_no && i_no < sclsInfo->num);

    stage_scls_info_class* sclsData = sclsInfo->m_entries;
    JUT_ASSERT(2136, sclsData != 0);

    return &sclsData[i_no];
}

/* 800547BC-80054870       .text dComIfGd_getMeshSceneList__FR3Vec */
stage_scls_info_class* dComIfGd_getMeshSceneList(Vec& vec) {
    s32 x = (s32)((vec.x + 350000.0f) * 2e-05f);
    s32 z = (s32)((vec.z + 350000.0f) * 2e-05f);
    if (x < 0) {
        x = 0;
    } else if (13 < x) {
        x = 13;
    }
    if (z < 0) {
        z = 0;
    } else if (13 < z) {
        z = 13;
    }
    return getSceneList((x & 1) + ((x >> 1) + (z >> 1) * 7) * 4 + (z & 1) * 2);
}

/* 80054870-800548FC       .text dComIfGs_checkSeaLandingEvent__FSc */
BOOL dComIfGs_checkSeaLandingEvent(s8 i_roomNo) {
    struct landing_event {
        /* 0x0 */ s8 roomNo;
        /* 0x2 */ u16 event;
    };

    static landing_event l_landingEvent[] = {
        {1, 0x3040}, {4, 0x2E02}, {13, 0x902}, {23, 0xA02}, {41, 0xA20}, {45, 0x2E04},
    };

    landing_event* event_check = l_landingEvent;

    for (u32 i = 0; i < 6; i++) {
        if (i_roomNo == event_check->roomNo && !dComIfGs_isEventBit(event_check->event)) {
            return FALSE;
        }

        event_check++;
    }

    return TRUE;
}

/* 800548FC-80054C70       .text dComIfGs_setGameStartStage__Fv */
// NONMATCHING - one tiny reg swap
void dComIfGs_setGameStartStage() {
    struct check_data {
        /* 0x0 */ u8 mbHasEvent;
        /* 0x2 */ u16 mEvent;
        /* 0x4 */ char mStage[8];
        /* 0xC */ s8 mRoomNo;
        /* 0xD */ u8 mStartCode;
    };

    static check_data l_checkData[] = {
        {true, 0x2A08, "", 0, 0},          {true, 0xF80, "sea", 11, 128},
        {true, 0x801, "MajyuE", 0, 0},     {true, 0x808, "MajyuE", 0, 18},
        {true, 0x2401, "A_umikz", 0, 204}, {false, 0, "sea", 44, 128},
    };

    check_data* data_p = l_checkData;
    for (u32 i = 0; i < 5; i++) {
        if (data_p->mbHasEvent == true && dComIfGs_isEventBit(data_p->mEvent)) {
            break;
        }

        data_p++;
    }

    char stage_name[8];
    s8 room_no;
    u8 point;

    if (strcmp(data_p->mStage, "") != 0) {
        strcpy(stage_name, data_p->mStage);
        room_no = data_p->mRoomNo;
        point = data_p->mStartCode;
    } else {
        u32 stage_type = dStage_stagInfo_GetSTType(dComIfGp_getStageStagInfo());
        int save_tbl = dStage_stagInfo_GetSaveTbl(dComIfGp_getStageStagInfo());
        BOOL isNot_PShip = strcmp(dComIfGp_getStartStageName(), "PShip");

        if (!isNot_PShip) {
            strcpy(stage_name, "sea");
            room_no = dComIfGs_getEventReg(0xC3FF);
            point = dComIfGs_getEventReg(0x85FF);
            dKy_set_nexttime(120.0f);
        } else if (stage_type == 7) {
            daPy_lk_c* player_p = daPy_getPlayerLinkActorClass();
            point = player_p->field_0x3594;

            s8 temp_r3 = player_p->current.roomNo;
            room_no = temp_r3;

            stage_scls_info_class* scls_p;
            if (temp_r3 >= 0 && point != 0xFF && dComIfGs_checkSeaLandingEvent(room_no)) {
                strcpy(stage_name, dComIfGp_getStartStageName());
            } else {
                if (dComIfGp_getShipActor() != NULL) {
                    scls_p = dComIfGd_getMeshSceneList(dComIfGp_getShipActor()->current.pos);
                } else {
                    scls_p = dComIfGd_getMeshSceneList(player_p->current.pos);
                }

                strcpy(stage_name, scls_p->mStage);
                room_no = scls_p->mRoom;
                point = scls_p->mStart;
            }
        } else if (stage_type == 1 || stage_type == 6 || stage_type == 3 || stage_type == 8 || save_tbl == 9) {
            stage_scls_info_class* scls_p = getSceneList(0);
            strcpy(stage_name, scls_p->mStage);
            room_no = scls_p->mRoom;
            point = scls_p->mStart;
        } else if (save_tbl == 10) {
            cXyz ikada_pos;
            dComIfGp_getIkadaShipBeforePos(&ikada_pos);

            stage_scls_info_class* scls_p = dComIfGd_getMeshSceneList(ikada_pos);
            strcpy(stage_name, scls_p->mStage);
            room_no = scls_p->mRoom;
            point = scls_p->mStart;
        } else if (save_tbl == 11 || save_tbl == 12 || save_tbl == 13) {
            strcpy(stage_name, "sea");

            stage_map_info_class* mapInfo = dComIfGp_getStage().getMapInfo();
            JUT_ASSERT(2362, mapInfo != 0);

            room_no = 4 + dStage_mapInfo_GetOceanX(mapInfo) + ((dStage_mapInfo_GetOceanZ(mapInfo) + 3) * 7);
            point = 0;
        } else {
            strcpy(stage_name, "sea");
            room_no = 11;
            point = 0;
        }
    }

    g_dComIfG_gameInfo.save.getPlayer().getPlayerReturnPlace().set(stage_name, room_no, point);
}

/* 80054C70-80054CC0       .text dComIfGs_gameStart__Fv */
void dComIfGs_gameStart() {
    dComIfGp_offEnableNextStage();

    s8 roomNo = g_dComIfG_gameInfo.save.getPlayer().getPlayerReturnPlace().getRoomNo();
    s16 point = g_dComIfG_gameInfo.save.getPlayer().getPlayerReturnPlace().getPlayerStatus();
    char* name = g_dComIfG_gameInfo.save.getPlayer().getPlayerReturnPlace().getName();
    dComIfGp_setNextStage(name, point, roomNo, -1, 0.0f, 0, 1, 0);
}

/* 80054CC0-80054E9C       .text dComIfGs_copyPlayerRecollectionData__Fv */
void dComIfGs_copyPlayerRecollectionData() {
    /* Nonmatching */
    s32 tbl;
    u8 buf[0x70];

    if (dStage_stagInfo_GetSTType(dComIfGp_getStageStagInfo()) == 3) {
        if (dStage_stagInfo_GetSaveTbl(dComIfGp_getStageStagInfo()) == 3)
            tbl = 0;
        else if (dStage_stagInfo_GetSaveTbl(dComIfGp_getStageStagInfo()) == 4)
            tbl = 1;
        else if (dStage_stagInfo_GetSaveTbl(dComIfGp_getStageStagInfo()) == 6)
            tbl = 2;
        else if (dStage_stagInfo_GetSaveTbl(dComIfGp_getStageStagInfo()) == 7)
            tbl = 3;
        else
            return;
    } else {
        return;
    }

    memcpy(&buf[0x00], &g_dComIfG_gameInfo.save.getPlayer().getPlayerStatusA(), 0x18);
    memcpy(&buf[0x18], &g_dComIfG_gameInfo.save.getPlayer().getItem(), 0x15);
    memcpy(&buf[0x2D], &g_dComIfG_gameInfo.save.getPlayer().getItemRecord().field_0x2, 0x03);
    memcpy(&buf[0x30], &g_dComIfG_gameInfo.save.getPlayer().getItemMax().field_0x0, 0x03);
    memcpy(&buf[0x33], &g_dComIfG_gameInfo.save.getPlayer().getBagItem(), 0x18);
    memcpy(&buf[0x4B], &g_dComIfG_gameInfo.save.getPlayer().getBagItemRecord(), 0x18);
    memcpy(&buf[0x63], &g_dComIfG_gameInfo.save.getPlayer().getCollect(), 0x0D);
    memcpy(g_dComIfG_gameInfo.save.getPlayer().getpPlayerStatusC(tbl), buf, sizeof(buf));
}

/* 80054E9C-80055318       .text dComIfGs_setPlayerRecollectionData__Fv */
void dComIfGs_setPlayerRecollectionData() {
    /* Nonmatching */
}

/* 80055318-80055580       .text dComIfGs_revPlayerRecollectionData__Fv */
void dComIfGs_revPlayerRecollectionData() {
    /* Nonmatching */
}

/* 80055580-8005586C       .text dComIfGs_exchangePlayerRecollectionData__Fv */
void dComIfGs_exchangePlayerRecollectionData() {
    /* Nonmatching */
}

/* 8005586C-800559E8       .text dComIfGs_setSelectEquip__FiUc */
void dComIfGs_setSelectEquip(int i_type, u8 i_itemNo) {
    switch (i_type) {
    case 0:
        switch (i_itemNo) {
        case SWORD:
            dComIfGs_onCollect(i_type, 0);
            break;
        case MASTER_SWORD:
            dComIfGs_onCollect(i_type, 1);
            break;
        case LV3_SWORD:
            dComIfGs_onCollect(i_type, 2);
            break;
        case MASTER_SWORD_EX:
            dComIfGs_onCollect(i_type, 3);
            break;
        }
        break;
    case 1:
        switch (i_itemNo) {
        case SHIELD:
            dComIfGs_onCollect(i_type, 0);
            break;
        case MIRROR_SHIELD:
            dComIfGs_onCollect(i_type, 1);
            break;
        }
        break;
    case 2:
        if (i_itemNo == PWR_GROOVE) {
            dComIfGs_onCollect(i_type, 0);
        }
        break;
    }

    g_dComIfG_gameInfo.save.getPlayer().getPlayerStatusA().mSelectEquip[i_type] = i_itemNo;
}
