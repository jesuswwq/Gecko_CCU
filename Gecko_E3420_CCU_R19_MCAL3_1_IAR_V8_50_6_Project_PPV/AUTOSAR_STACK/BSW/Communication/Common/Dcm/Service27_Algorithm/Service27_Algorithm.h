/*
 * Service27_Algorithm.h
 *
 *  Created on: 2023��11��24��
 *      Author: Admin
 */

#ifndef SERVICE27_ALGORITHM_H_
#define SERVICE27_ALGORITHM_H_

#include "Std_Types.h"
#include "Service27_Algorithm.h"

extern void GenerateSeed(uint8* Seed,uint8* plastseed);

extern Std_ReturnType SeedToKeyLevel1(uint8 *Seed, uint8 *Key);

extern Std_ReturnType SeedToKeyLevel3(uint8 *Seed, uint8 *Key);

extern Std_ReturnType SeedToKeyLevel5(uint8 *Seed, uint8 *Key);

extern Std_ReturnType SeedToKeyLevel7(uint8 *Seed, uint8 *Key);

#endif /* SERVICE27_ALGORITHM_H_ */
