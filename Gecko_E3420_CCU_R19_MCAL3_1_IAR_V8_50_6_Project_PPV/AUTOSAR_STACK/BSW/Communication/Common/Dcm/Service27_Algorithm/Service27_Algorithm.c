/*
 * Service27_Algorithm.c
 *
 *  Created on: 2023��11��24��
 *      Author: Admin
 */


#include "FreeRTimer.h"
#include "Service27_Algorithm.h"

uint8 XOR[4] = {0x6D,0x7A,0xA8,0x09};

void GenerateSeed(uint8* Seed,uint8* plastseed)
{
	uint32 seedtemp = 0;
	if(NULL_PTR == Seed)
	{
	}
	else
	{
	  /* random seed */
		seedtemp = Frt_ReadOutMS();
		seedtemp = ((seedtemp ^ 0x5a5a) << 16) | (seedtemp & 0xffff);
		if((0 == seedtemp) || (0xffffffff == seedtemp))
		{
			seedtemp = seedtemp ^ 0xaaaa;
		}
		Seed[0] = (uint8)((seedtemp >> 24) & 0xff);
		Seed[1] = (uint8)((seedtemp >> 16) & 0xff);
		Seed[2] = (uint8)((seedtemp >> 8) & 0xff);
		Seed[3] = (uint8)(seedtemp & 0xff);
		plastseed[0] = Seed[0];
		plastseed[1] = Seed[1];
		plastseed[2] = Seed[2];
		plastseed[3] = Seed[3];
    }

}

Std_ReturnType SeedToKeyLevel1(uint8 *Seed, uint8 *Key)
{
    uint8 i = 0;
    uint8 Cal[4];
    for ( i = 0; i < 4; i++)
    {
        Cal[i] = Seed[i] ^ XOR[i];
    }
    Key[0] = ((Cal[0]&0x0f)<<4)|(Cal[3]&0x0f);
    Key[1] = ((Cal[1]&0x0f)<<4)|((Cal[0]&0xf0)>>4);
    Key[2] = (Cal[2]&0xf0)|((Cal[1]&0xf0)>>4);
    Key[3] = ((Cal[3]&0x1E)<<3)|(Cal[2]&0x0f);

    return E_OK;
}

Std_ReturnType SeedToKeyLevel3(uint8 *Seed, uint8 *Key)
{
    uint8 i = 0;
    uint8 Cal[4];
    for ( i = 0; i < 4; i++)
    {
        Cal[i] = Seed[i] ^ XOR[i];
    }
    Key[0] = ((Cal[2]&0x1f)<<3)|(Cal[3]&0x07);
    Key[1] = ((Cal[0]&0x0f)<<4)|((Cal[1]&0xf0)>>4);
    Key[2] = (Cal[3]&0xf0)|((Cal[0]&0x3c)>>2);
    Key[4] = ((Cal[1]&0x3F)<<2)|(Cal[2]&0x03);

    return E_OK;
}

Std_ReturnType SeedToKeyLevel5(uint8 *Seed, uint8 *Key)
{
    uint8 i = 0;
    uint8 Cal[4];
    for ( i = 0; i < 4; i++)
    {
        Cal[i] = Seed[i] ^ XOR[i];
    }
    Key[0] = ((Cal[0]&0x3f)<<2)|(Cal[1]&0x03);
    Key[1] = ((Cal[1]&0x0f)<<4)|((Cal[2]&0xf0)>>4);
    Key[2] = (Cal[2]&0xf0)|((Cal[3]&0xf0)>>4);
    Key[3] = ((Cal[3]&0x1F)<<3)|(Cal[0]&0x07);

    return E_OK;
}


Std_ReturnType SeedToKeyLevel7(uint8 *Seed, uint8 *Key)
{
    uint8 i = 0;
    uint8 Cal[4];
    for ( i = 0; i < 4; i++)
    {
        Cal[i] = Seed[i] ^ XOR[i];
    }
    Key[0] = ((Cal[1]&0x0f)<<4)|(Cal[0]&0x0f);
    Key[1] = ((Cal[1]&0x0f)<<4)|((Cal[1]&0xf0)>>3);
    Key[2] = (Cal[1]&0xf0)|((Cal[2]&0xf1)>>4);
    Key[3] = ((Cal[1]&0x0E)<<3)|(Cal[3]&0x1f);

    return E_OK;
}