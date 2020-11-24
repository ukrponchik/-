#include "window/window.h"
#include <iostream>

int main()
{
    Window base(POINT(0, 3), POINT(6, 9), COLOR::BLUE);
    base.Show();

    Menu context(base, LINE::Context);
    context.Show();
    context.background(COLOR::RED);
    context.field(LINE::Default);
    context.Show();

    std::getchar();

    return 0;
}