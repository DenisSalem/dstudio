/*
 * Copyright 2019 Denis Salem
 *
 * This file is part of DStudio.
 *
 * DStudio is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * DStudio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with DStudio. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DSTUDIO_INTERACTIVE_LIST_H_INCLUDED
#define DSTUDIO_INTERACTIVE_LIST_H_INCLUDED

#include <semaphore.h>

#include "ui.h"

typedef struct UIInteractiveList_t {
    UIElements * lines;
    UIElements * shadows;
    unsigned int lines_number;
    unsigned int string_size;
    int window_offset;
    sem_t mutex;
    int cut_thread;
    int ready;
    int update;
} UIInteractiveList;

typedef struct UIInteractiveListSetting_t {
    GLfloat gl_x;
    GLfloat gl_y;
    GLfloat min_area_x;
    GLfloat max_area_x;
    GLfloat min_area_y;
    GLfloat max_area_y;
    GLfloat offset;
    GLfloat area_offset;
} UIInteractiveListSetting;

void configure_ui_interactive_list(
    UIElements * ui_elements,
    void * params
);

void init_interactive_list(
    UIInteractiveList * interactive_list,
    UIElements * lines,
    unsigned int lines_number,
    unsigned int string_size
);

void update_insteractive_list(
    int context_type,
    int offset,
    unsigned int max_lines_number,
    unsigned int lines_count,
    UIElements * lines,
    unsigned int string_size,
    void * contexts
);

void update_insteractive_list_shadow(
    int context_type,
    UIInteractiveList * interactive_list
);
#endif
