#include "romanos.hpp"
#include <string>

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
    for (int i=0;i<(int)rom.length()-1;i++)
    {
        int valor=0;
        if (rom[i]=='I')
        {
            if (rom[i+1]=='V' || rom[i+1]=='X')
            {
                for (int j=0;j<i;j++)
                {
                    if (rom[i]==rom[j])
                    {
                        return true;
                    }
                }
                if (i!=(int)rom.length()-2)
                {
                    return true;
                }
            }
            //Ler a quantidade de Is;
            for (int k=0;k<(int)rom.length();k++)
            {
                if (rom[k]==rom[i])
                {
                    valor++;
                }
            }
            if (valor>3)
            {
                return true;
            }
            if (rom[i+1]!='I' && rom[i+1]!='V' && rom[i+1]!='X')
            {
                return true;
            }
        }
        if (rom[i]=='V')
        {
            for (int j=0; j<(int)rom.length();j++)
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
            if (rom[i+1]!='I')
            {
                return true;
            }
        }
        if (rom[i]=='X')
        {
            for (int j=i+1;j<(int)rom.length();j++)
            {
                if (rom[j]=='M' || rom[j]=='D')
                {
                    return true;
                }
                if (rom[j]=='C' || rom[j]=='L')
                {
                    if (j!=i+1)
                    {
                        return true;
                    }
                }
                if (rom[i+1]=='C' || rom[i+1]=='L')
                {
                    if (rom[j]=='X' && rom[j-1]!='I')
                    {
                        return true;
                    }
                }
            }
            for (int k=0;k<(int)rom.length();k++)
            {
                if (rom[k]==rom[i])
                {
                    valor++;
                }
            }
            if (valor>3)
            {
                return true;
            }
            for (int k=0;k>(int)rom.length();k++)
            {
                if (rom[i]==rom[k])
                {
                    if (valor==3 && rom[k-1]=='I')
                    {
                        valor--;
                    }
                    valor++;
                }
            }
            if (valor>3)
            {
                return true;
            }

        }
        if (rom[i]=='L')
        {
            for (int j=0; j<(int)rom.length();j++)
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
            for (int k=i;k<(int)rom.length();k++) 
            {
                if ( rom[k]=='M' || rom[k]=='D' || rom[k]=='C')
                {
                    return true;
                }
            }
        }
        if (rom[i]=='C')
        {
            for (int k=i+1;k<(int)rom.length();k++)
            {
                if (rom[k]=='M' || rom[k]=='D')
                {
                    if (k!=i+1) 
                    {
                        return true;
                    }
                }
                if (rom[i+1]=='M' || rom[i+1]=='D')
                {
                    if (rom[k]=='C' && rom[k-1]!='X')
                    {
                        return true;
                    }
                }
            }
            for (int j=0; j<(int)rom.length();j++)
            {
                if (rom[j]==rom[i])
                {
                    if (valor==3 && rom[j-1]=='X')
                    {
                        valor--;
                    }
                    valor++;
                }
            }
            if (valor>3)
            {
                return true;
            }
        }
        if(rom[i]=='D')
        {
            for (int j=0; j<(int)rom.length();j++)
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
        if(rom[i]=='M')
        {
            for (int k=i+1;k<(int)rom.length();k++)
            {
                if (rom[k]==rom[i] && !(rom[k-1]!='C' || rom[k-1]!='M'))
                {
                    return true;
                }
                if (k>1)
                {
                    if (rom[k]==rom[i] && rom[k-2]!='M')
                    {
                    return true;
                    }
                }
            }
            for (int j=0; j<(int)rom.length();j++)
            {
                if (rom[j]==rom[i])
                {
                    if (valor==3 && rom[j-1]=='C')
                    {
                        valor--;
                    }
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

int valor_decimal(string rom)
{
    int decimal=0;

    for (int i=0; i<(int)rom.length();i++)
    {
        if (rom[i]=='C')
        {
            if ((rom[i+1]=='D' || rom[i+1]=='M') && i!=(int)rom.length()-1)
            {
                decimal-=100;
            }
            else
            {
                decimal+=100;
            }
        }
        if (rom[i]=='X')
        {
            if ((rom[i+1]=='L' || rom[i+1]=='C') && i!=(int)rom.length()-1)
            {
                decimal-=10;
            }
             else
            {
                decimal+=10;
            }
        }
            if (rom[i]=='I')
        {
            if ((rom[i+1]=='V' || rom[i+1]=='X') && i!=(int)rom.length()-1)
            {
                decimal-=1;
            }
            else
            {
                decimal+=1;
            }
        }
        if (rom[i]=='M')
        {
            decimal+=1000;
        }
        if (rom[i]=='D')
        {
            decimal+=500;
        }
        if (rom[i]=='L')
        {
            decimal+=50;
        }
        if (rom[i]=='V')
        {
            decimal+=5;
        }
    }

    return decimal;
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

  return valor_decimal(romano);
}

