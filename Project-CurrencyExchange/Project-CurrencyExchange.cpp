#include <iostream>
#include "clsLoginScreen.h"

int main()
{
    while (true)
    {
        if (!clsLoginScren::ShowLoginScreen())
        {
            break;
        }

    }
    system("pasue>0");
    return 0;

}