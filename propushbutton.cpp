#include "propushbutton.h"

void ProPushButton::myClicked()
{
    emit iChanged(this);
}

