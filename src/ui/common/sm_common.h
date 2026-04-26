#pragma once

#include "lvgl.h"

typedef struct
{
    /*GPS的数量*/
    lv_subject_t gps;
    /*运动状态*/
    lv_subject_t running_state;
    /*电池电量*/
    lv_subject_t battery_level;
}sm_sub_t;

void clear_default_style(lv_obj_t *obj);
