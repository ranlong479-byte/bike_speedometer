#include "lvgl.h"
#include "ui_private.h"

typedef enum
{
    ITEM_TYPE_SWITCH,
    ITEM_TYPE_DROPDOWN,
    ITEM_TYPE_SLIDER,
} ui_settings_item_type_t;

lv_obj_t *ui_settings_add_section(lv_obj_t *tab, ui_element_t *ui, char *name)
{
    lv_obj_t *total_container = lv_obj_create(tab);
    lv_obj_set_size(total_container, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_add_style(total_container, &ui->style.container, LV_PART_MAIN);
    lv_obj_set_flex_flow(total_container, LV_FLEX_FLOW_COLUMN);

    lv_obj_t *label = lv_label_create(total_container);
    lv_label_set_text(label, name);

    lv_obj_t *container = lv_obj_create(total_container);
    lv_obj_set_width(container, LV_PCT(100));
    lv_obj_set_height(container, LV_SIZE_CONTENT);
    lv_obj_add_style(container, &ui->style.setting_section, LV_PART_MAIN);
    lv_obj_set_flex_flow(container, LV_FLEX_FLOW_COLUMN);

    return container;
}

lv_obj_t *ui_settings_add_item(lv_obj_t *section, ui_element_t *ui,
                               char *name, ui_settings_item_type_t type)
{
    lv_obj_t *container = lv_obj_create(section);
    lv_obj_set_size(container, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_add_style(container, &ui->style.setting_item, LV_PART_MAIN);

    lv_obj_t *label = lv_label_create(container);
    lv_label_set_text(label, name);
    lv_obj_align(label, LV_ALIGN_LEFT_MID, 0, 0);

    lv_obj_t *item = NULL;
    switch (type)
    {
    case ITEM_TYPE_SWITCH:
        item = lv_switch_create(container);
        break;
    case ITEM_TYPE_DROPDOWN:
        item = lv_dropdown_create(container);
        break;
    case ITEM_TYPE_SLIDER:
        item = lv_slider_create(container);
        break;
    default:
        break;
    }
    lv_obj_align(item, LV_ALIGN_RIGHT_MID, 0, 0);
    return item;
}

void ui_init_settings_tab(ui_element_t *ui)
{
    lv_obj_t *root = ui->settings_tab;
    // flex layout
    lv_obj_set_flex_flow(root, LV_FLEX_FLOW_COLUMN);
    lv_obj_add_style(root, &ui->style.container, 0);
    lv_obj_set_style_pad_all(root, 10, 0);
    lv_obj_set_scrollbar_mode(root, LV_SCROLLBAR_MODE_OFF);

    // creating visual section
    lv_obj_t *visual_section = ui_settings_add_section(root, ui, "Visual");
    lv_obj_t *dark_mode_item = ui_settings_add_item(visual_section, ui, "Dark Mode", ITEM_TYPE_SWITCH);
    lv_obj_t *big_font_item = ui_settings_add_item(visual_section, ui, "Big Font", ITEM_TYPE_SWITCH);
    lv_obj_t *big_font_item2 = ui_settings_add_item(visual_section, ui, "Big Font", ITEM_TYPE_SWITCH);
    lv_obj_t *big_font_item3 = ui_settings_add_item(visual_section, ui, "Big Font", ITEM_TYPE_SWITCH);
    lv_obj_t *big_font_item4 = ui_settings_add_item(visual_section, ui, "Big Font", ITEM_TYPE_SWITCH);
    lv_obj_t *big_font_item5 = ui_settings_add_item(visual_section, ui, "Big Font", ITEM_TYPE_SWITCH);
    lv_obj_t *big_font_item6 = ui_settings_add_item(visual_section, ui, "Big Font", ITEM_TYPE_SWITCH);
    lv_obj_t *big_font_item7 = ui_settings_add_item(visual_section, ui, "Big Font", ITEM_TYPE_SWITCH);

    // 
    lv_obj_t *system_section = ui_settings_add_section(root, ui, "System");
    lv_obj_t *language_item = ui_settings_add_item(system_section, ui, "Language", ITEM_TYPE_DROPDOWN);
}
