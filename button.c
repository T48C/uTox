#include "main.h"

void button_draw(BUTTON *b, int x, int y, int width, int height)
{
    RECT frame = {x, y, x + width, y + height};
    framerect(&frame, BLACK);

    RECT area = {x + 1, y + 1, x + width - 1, y + height - 1};
    fillrect(&area, b->mouseover ? BUTTON_AREA_HIGHLIGHT : BUTTON_AREA);

    setfont(FONT_BUTTON);
    setcolor(b->mouseover ? 0x222222 : 0x555555);

    drawtext(x + 5, y, b->text, b->text_length);
}

_Bool button_mmove(BUTTON *b, int x, int y, int dy, int width, int height)
{
    _Bool mouseover = inrect(x, y, 0, 0, width, height);
    if(mouseover != b->mouseover) {
        b->mouseover = mouseover;
        return 1;
    }

    return 0;
}

_Bool button_mdown(BUTTON *b)
{
    if(!b->mousedown) {
        b->mousedown = 1;
        return 1;
    }

    return 0;
}

_Bool button_mright(BUTTON *b)
{
    return 0;
}

_Bool button_mwheel(BUTTON *b, int height, double d)
{
    return 0;
}

_Bool button_mup(BUTTON *b)
{
    if(b->mousedown) {
        if(b->mouseover) {
            b->onpress();
        }

        b->mousedown = 0;
        return 1;
    }

    return 0;
}

_Bool button_mleave(BUTTON *b)
{
    if(b->mouseover) {
        b->mouseover = 0;
        return 1;
    }

    return 0;
}
