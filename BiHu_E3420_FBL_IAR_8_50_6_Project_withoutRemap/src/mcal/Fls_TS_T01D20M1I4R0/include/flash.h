/*
* SEMIDRIVE Copyright Statement
* Copyright (c) SEMIDRIVE. All rights reserved
*
* This software and all rights therein are owned by SEMIDRIVE, and are
* protected by copyright law and other relevant laws, regulations and
* protection. Without SEMIDRIVE's prior written consent and/or related rights,
* please do not use this software or any potion thereof in any form or by any
* means. You may not reproduce, modify or distribute this software except in
* compliance with the License. Unless required by applicable law or agreed to
* in writing, software distributed under the License is distributed on
* an "AS IS" basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
*
* You should have received a copy of the License along with this program.
* If not, see <http://www.semidrive.com/licenses/>.
*/

/*
* @file  flash.h
* @brief Semidrive. AUTOSAR 4.3.1 MCAL Fls plugins.
*/

#ifndef FLASH_API_H_
#define FLASH_API_H_

#ifdef __cplusplus
extern "C" {
#endif

enum flash_opt {
    FLASH_OPT_READ = 1,
    FLASH_OPT_WRITE,
    FLASH_OPT_ERASE,
    FLASH_OPT_MAX,
};

typedef uint64 flash_addr_t;

typedef uint64 flash_size_t;

enum flash_opt_result {
    FLASH_OPT_COMPLETE = 0,
    FLASH_OPT_FAILED,
    FLASH_OPT_PENDING,
    FLASH_OPT_INCONSISTENT,
    FLASH_OPT_INVALID,
    FLASH_OPT_RESULET_MAX,
};

struct flash_xfer_info {
    enum flash_opt opt_type;
    enum flash_opt_result opt_result;
    flash_addr_t addr;
    uint8 *buf;
    flash_size_t size;
};

typedef void (*flash_notification)(enum flash_opt type,
                                   enum flash_opt_result result);

#ifdef __cplusplus
}
#endif
#endif
