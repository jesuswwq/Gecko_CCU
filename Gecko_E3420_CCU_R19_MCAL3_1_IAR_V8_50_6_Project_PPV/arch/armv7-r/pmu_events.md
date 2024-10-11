# Performance Monitor Unit Event list

The event table is from ***Cortex™-R5 Technical Reference Manual***


EVNTBUSm,bit position|Description|CFLR update|Event Ref,value
--|:--:|--:|--:
-|Software increment. The register is incremented only on writes to the Software Increment Register. See c9, Software Increment Register n page 6-12.|-|0x00
[0]|Instruction cache miss.Each instruction fetch from normal Cacheable memory that causes a refill from the level 2 memory system generates this event. Accesses that do not cause a new cache refill, but are satisfied from refilling data of a previous miss are not counted. Where instruction fetches consist of multiple instructions, these accesses count as single events. CP15 cache maintenance operations do not count as events.|-|0x01
[1]|Data cache miss. Each data read from or write to normal Cacheable memory that causes a refill from the level 2 memory system generates this event. Accesses that do not cause a new cache refill, but are satisfied from refilling data of a previous miss are not counted. Each access to a cache line to normal Cacheable memory that causes a new linefill is counted, including the multiple transactions of an LDM and STM. Write-through writes that hit in the cache do not cause a linefill and so are not counted. CP15 cache maintenance operations do not count as events.|-|0x03
[2]|Data cache access. Each access to a cache line is counted including the multiple transactions of an LDM, STM, or other operations. CP15 cache maintenance operations do not count as events.|-|0x04
[3]|Data Read architecturally executed. This event occurs for every instruction that explicitly reads data, including SWP. |-|0x06
[4]|Data Write architecturally executed. This event occurs for every instruction that explicitly writes data, including SWP.|-|0x07
[5]|Instruction architecturally executeda.|-|0x08
[6]|Dual-issued pair of instructions architecturally executed.|-|0x5e
[7]|Exception taken. This event occurs on each exception taken.|-|0x09
[8]|Exception return architecturally executed. This event occurs on every exception return, for example, “RFE, MOVS PC, LDM Rn, {..,PC}^”.|-|0x0A
[9]|Change to Context ID executed.|-|0x0B
[10]|Software change of PC, except by an exception, architecturally executed.|-|0x0C
[11]|B immediate, BL immediate or BLX immediate instruction architecturally executed (taken or not taken).|-|0x0D
[12]|Procedure return architecturally executed, other than exception returns, for example, BZ Rm, "LDM Rn, {..,PC}".MOV PC, LR does not generate this event, because it is not predicted as a return.|-|0x0E
[13]|Unaligned access architecturally executed.This event occurs for each instruction that was to an unaligned address that eithertriggered an alignment fault, or would have done so if the SCTLR A-bit had been set.|-|0x0F
[14]|Branch mispredicted or not predicted.This event occurs for every pipeline flush caused by a branch.|-|0x10
-|Cycle count.|-|0x11
[15]|Branches or other change in program flow that could have been predicted by the branch prediction resources of the processor.|-|0x12
[16]|Stall because instruction buffer cannot deliver an instruction. This can indicate an instruction cache miss. This event occurs every cycle where the condition is present.|-|0x40
[17]|Stall because of a data dependency between instructions. This event occurs every cycle where the condition is present.|-|0x41
[18]|Data cache write-back. This event occurs once for each line that is written back from the cache.|-|0x42
[19]|External memory request. Examples of this are cache refill, Non-cacheable accesses, write-through writes, cache line evictions (write-back).|-|0x43
[20]|Stall because of LSU being busy. This event takes place each clock cycle where the condition is met. A high incidence of this event indicates the pipeline is often waiting for transactions to complete on the external bus.|-|0x44
[21]|Store buffer was forced to drain completely. Examples of this for Cortex-R5 are DMB, Strongly Ordered memory access, or similar events.|-|0x45
-|The number of cycles FIQ interrupts are disabled.|-|0x46
-|The number of cycles IRQ interrupts are disabled.|-|0x47
-|ETMEXTOUTm[0].|-|0x48
-|ETMEXTOUTm[1].|-|0x49
[22]|Instruction cache tag RAM parity or correctable ECC error.|Yes|0x4A
[23]|Instruction cache data RAM parity or correctable ECC error.|Yes|0x4B
[24]|Data cache tag or dirty RAM parity error or correctable ECC error, from data-side or ACP.|Yes|0x4C
[25]|Data cache data RAM parity error or correctable ECC error.|Yes|0x4D
[26]|TCM fatal ECC error reported from the prefetch unit.|-|0x4E
[27]|TCM fatal ECC error reported from the load/store unit.|-|0x4F
-|Store buffer merge.|-|0x50
-|LSU stall caused by full store buffer.|-|0x51
-|LSU stall caused by store queue full.|-|0x52
-|Integer divide instruction, SDIV or UDIV, executed.|-|0x53
-|Stall cycle caused by integer divide. This includes the single stall cycle required for all divide instructions to write their result into the register bank.|-|0x54
-|PLD instruction that initiates a linefill.|-|0x55
-|PLD instruction that did not initiate a linefill because of a resource shortage.|-|0x56
-|Non-cacheable access on AXI master bus.|-|0x57
[28]|Instruction cache access.This is an analog to event 0x04.|-|0x58
-|Store buffer operation has detected that two slots have data in same cache line but with different attributes.|-|0x59
[29]|Dual issue case A (branch).|-|0x5A
[30]|Dual issue case B1, B2, F2 (load/store), F2D.|-|0x5B
[31]|Dual issue other case.|-|0x5C
[32]|Double-precision floating point arithmetic or conversion instruction executed.|-|0x5D
[33]|Data cache data RAM fatal ECC error.|-|0x60
[34]|Data cache tag/dirty RAM fatal ECC error, from data-side or ACP.|-|0x61
[35]|Processor livelock because of hard errors or exception at exception vector.|-|0x62
[36]|Unused.|-|0x63
[37]|ATCM multi-bit ECC error.|-|0x64
[38]|B0TCM multi-bit ECC error.|-|0x65
[39]|B1TCM multi-bit ECC error.|-|0x66
[40]|ATCM single-bit ECC error.|-|0x67
[41]|B0TCM single-bit ECC error.|-|0x68
[42]|B1TCM single-bit ECC error.|-|0x69
[43]|TCM correctable ECC error reported by load/store unit.|Yes|0x6A
[44]|TCM correctable ECC error reported by prefetch unit.|Yes|0x6B
[45]|TCM fatal ECC error reported by AXI slave interface.|-|0x6C
[46]|TCM correctable ECC error reported by AXI slave interface.|Yes|0x6D
-|All correctable eventsb, OR of:0x4A ICache tag,0x4B ICache data,0x4C DCache tag/dirty,0x4D DCache data,0x6A LSU TCM,0x6B PFU TCM,0x6D AXI-S TCM,0x70 bus-ECC |Yes|0x6E
-|All fatal eventsb, OR of:0x60 DCache tag,0x61 DCache tag/dirty,0x4E PFU TCM,0x4F LSU TCM,0x6C AXI-S TCM,0x71 bus -ECC|-|0x6F
[47]|All correctable bus faultsb|-|0x70
[48]|All fatal bus faultsb|-|0x71
[49]|ACP D-Cache access, lookup or invalidate.|-|0x72
[50]|ACP D-Cache invalidate.|-|0x73
-|Cycle count|-|0xFF