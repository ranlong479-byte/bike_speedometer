#include "lvgl.h"
#include "ui_private.h"

void ui_init_map(ui_element_t *ui)
{
    lv_obj_t* root = ui->gpx_tab.map.obj;
    lv_obj_add_style(root, &ui->style.container, 0);
}