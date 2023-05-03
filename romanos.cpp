#include "romanos.hpp"
#include <bits/stdc++.h>

using namespace std;

bool letra_invalida(string rom)
{
    string letras = "MDCLXVI";
    
    for (int i = 0; i < (int)rom.length(); i++)
    {
        if (letras.find(rom[i])==string::npos)
        {
            return true;
        }
    }

    return false;
}


int romanos_para_decimal(string romano)
{
    if (letra_invalida(romano))
    {
      return -1;
    }
}
