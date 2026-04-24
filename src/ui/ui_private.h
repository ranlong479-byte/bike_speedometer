#ifndef UI_PRIVATE_H
#define UI_PRIVATE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "lvgl.h"
    typedef struct
    {
        // style sheet
        struct
        {
            lv_style_t container;
            lv_style_t tab;
            lv_style_t tab_item;
            lv_style_t setting_section;
            lv_style_t setting_item;
        } style;

        // status_bar
        struct
        {
            lv_obj_t *obj;

            lv_obj_t *satellite_label;
            lv_obj_t *time_label;
            lv_obj_t *battery_label;
        } status_bar;

        // main_page
        lv_obj_t *main_tabview;
        struct
        {
            lv_obj_t *obj;
            struct
            {
                lv_obj_t *obj;
                lv_obj_t *map_img[4][4];
                lv_obj_t *map_scale_slider;
            } map;
            struct
            {
                lv_obj_t *obj;
                lv_obj_t *speed_label;
            } speed;
            struct
            {
                lv_obj_t *obj;
                lv_obj_t *distance_label;
            } distance;
        } gpx_tab;
        struct
        {
            lv_obj_t *obj;
            struct
            {
                lv_obj_t *obj;
                lv_obj_t *speed_label;
            } speed;
            struct
            {
                lv_obj_t *obj;
                lv_obj_t *distance_label;
            } distance;
            struct
            {
                lv_obj_t *obj;
                lv_obj_t *time_label;
            } time;
            struct
            {
                lv_obj_t *obj;
                lv_obj_t *power_label;
            } power;
            struct
            {
                lv_obj_t *obj;
                lv_obj_t *freq_label;
            } freq;
            struct
            {
                lv_obj_t *obj;
                lv_obj_t *slope_label;
            } slope;
            struct
            {
                lv_obj_t *obj;
                lv_obj_t *heartbeat_label;
            } heartbeat;
        } general_tab;
        lv_obj_t *settings_tab;
    } ui_element_t;

#ifdef __cplusplus
}
#endif

#endif