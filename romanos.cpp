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

bool sintaxe_errada(string rom)
{
    for (int i=0; i<(int)rom.length()-1; i++)
    {int valor=0;
        if (rom[i]=='I')
        {
            if (rom[i+1]!='V' || rom[i+1]!='I' || rom[i+1]!='X')
            {
               return true;
            }
            for (int j=0;j<(int)rom.length();j++)
            {
                if (rom[j]==rom[i])
                {
                    valor++;
                }
            }
            if (valor>3)
            {
                return true;
            }
        
        }
        if (rom[i]=='V')
        {
            if (rom[-i+1]!='I')
            {
                return true;
            }
            for (int j=0;j<(int)rom.length();j++)
            {
                if (rom[j]==rom[i])
                {
                    valor++;
                }
            }
            if (valor>1)
            {
                return true;
            }
        }
        if (rom[i]=='X')
        {
            if (rom[i+1]=='D' || rom[i+1]=='M')
            {
            return true;
            }
            for (int j=0;j<(int)rom.length();j++)
            {
                if (rom[j]==rom[i])
                {
                    valor++;
                }
            }
            if (valor>3)
            {
                return true;
            }
            for (int k=i+2;k<(int)rom.length();k++)
            {
                if (rom[k]!='I' || rom[k]!='V')
                {
                    return true;
                }
            }
            
        }
        if (rom[i]=='L')
        {
            if (rom[i+1]!='V' || rom[i+1]!='I' || rom[i+1]!='X')
            {
                return true;
            }
            for (int j=0;j<(int)rom.length();j++)
            {
                if (rom[j]==rom[i])
                {
                    valor++;
                }
            }
            if (valor>1)
            {
                return true;
            }
        }
        if (rom[i]=='D')
        {
            if (rom[i+1]=='M' || rom[i+1]=='D')
        {
            return true;
        }
                    for (int j=0;j<(int)rom.length();j++)
            {
                if (rom[j]==rom[i])
                {
                    valor++;
                }
            }
            if (valor>1)
            {
                return true;
            }
        }
        if (rom[i]=='C')
        {
            for (int j=0;j<(int)rom.length();j++)
            {
                if (rom[j]==rom[i])
                {
                    valor++;
                }
            }
            if (valor>3)
            {
                return true;
            }
            for (int k=i+2;k<(int)rom.length()-1;k++)
            {
                if (rom[k]!='I' || rom[k]!='V' || rom[k]!='X')
                {
                    return true;
                }
            }
        }
        if (rom[i]=='M')
        {
            for (int j=0;j<(int)rom.length();j++)
            {
                if (rom[j]==rom[i])
                {
                    valor++;
                }
            }
            if (valor>3)
            {
                return true;
            }
        }
    }

    return false;
}


bool repetida_com_reducao(string rom)
{
  for (int i=1;i<(int)rom.length()-1;i++)
  {
    if (rom[i]=='X' && rom[i-1]=='I' && rom[i+1]=='X')
    { 
      return true;
    }
    if (rom[i]=='C' && rom[i-1]=='X' && rom[i+1]=='C')
    {
      return true;
    }
    if (rom[i]=='M' && rom[i-1]=='C' && rom[i+1]=='M')
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
    else if (sintaxe_errada(romano))
    {
      return -1;
    }

    if (repetida_com_reducao(romano))
    {
        return -1;
    }
  return 0;
}

