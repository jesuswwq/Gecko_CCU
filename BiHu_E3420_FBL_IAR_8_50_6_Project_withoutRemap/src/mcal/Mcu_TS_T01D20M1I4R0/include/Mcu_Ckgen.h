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

#ifndef MCU_CKGEN_H
#define MCU_CKGEN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"

#define SLICE_ID(x) (x)
#define PREDIV(x)   (x)
#define POSTDIV(x)  (x)
#define SLICE_SRC(x)    (x)
#define DIV(x)      (x)

#define DIV_MNPQ(m, n, p, q)    \
   ((((m) & 0xfu) << 0u) | (((n) & 0xfu) << 4u) \
    | (((p) & 0xfu) << 8u) | (((q) & 0xfu) << 12u))

/* avoid referring clkgen_reg.h */
/*
(FV_BUS_SLICE_SYNC_CTL_DIV_M_NUM(m) \
  | FV_BUS_SLICE_SYNC_CTL_DIV_N_NUM(n)\
  | FV_BUS_SLICE_SYNC_CTL_DIV_P_NUM(p)\
  | FV_BUS_SLICE_SYNC_CTL_DIV_Q_NUM(q))
*/

typedef enum {
    CKGEN_RUN_MODE,
    CKGEN_SLP_MODE,
    CKGEN_HIB_MODE,
} clock_mode;

#define CKGEN_PCG  1
#define CKGEN_BCG  2
#define CKGEN_CCG  3

typedef enum {
    IP_Slice,
    Bus_Slice,
    Core_Slice,
} slice_type;
#ifdef MCU_CKGEN_RESERVED_FUNCs
void ckgen_ip_slice_cfg(uint32 base, uint32 slice_id,
                        uint32 src_sel, uint32 div);
void ckgen_core_slice_cfg(uint32 base, uint32 slice_id, uint32 src_sel, uint32 div);
void ckgen_pcg_clk_on(uint32 base, uint32 id);
void ckgen_pcg_clk_off(uint32 base, uint32 id);
void ckgen_clk_ratio_sel(uint32 base, uint32 v);
void ckgen_cg_ctl(unsigned int base_addr, int cg_type, int mode, int index, int on_off,
                  int lp_mask);
#endif

void ckgen_bus_slice_cfg(uint32 base, uint32 slice_id,
                         uint32 src_sel, uint32 pre_divm, uint32 npq);


void ckgen_pll_dis(unsigned int mode, unsigned int on_off, unsigned int ckgen_sel, int dis_or_pd);
void ckgen_xtal_dis(unsigned int mode, unsigned int on_off, unsigned int ckgen_sel);
void ckgen_sf_clk_dis(unsigned int mode, unsigned int on_off);
#ifndef SEMIDRIVE_E3_LITE_SERIES
void ckgen_ap_clk_dis(unsigned int mode, unsigned int on_off);
#endif


#ifdef __cplusplus
}
#endif

#endif  /* ifndef _MCU_CKGEN_H_ */
