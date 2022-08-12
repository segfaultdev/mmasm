# mmasm: Motorola 6809 Modern ASseMbler

## Instruction list

- `mov` (old `tfr`, `ld*` or `st*`)
- `exg`
- `add`
- `adc`
- `sub`
- `sbc`
- `and`
- `or`
- `xor` (old `eor`)
- `not` (old `com`)
- `neg`
- `test` (old `tst` when register, old `bit` when register and immediate)
- `cmp`
- `call` (old `bsr` if relative, or `jsr` if absolute)
- `jmp` (old `bra` if relative, or `jmp` if absolute)
- `j*` (old `b*` if relative, cannot be absolute)
- `ret` (old `rts`)
- `iret` (old `rti`)
- `swi1`/`swi2`/`swi3` (old `swi`/`swi2`/`swi3`)
- `shl`/`shr` (old `lsl`/`lsr`)
- `sal`/`sar` (old `asl`/`asr`)
- `rol`/`ror`
- `sex`
- `daa`
- `nop`
- `mul`
- `andcc`
- `andcw` (old `cwai`)
- `orcc`
- `sync`
- `clr`
- `push` (old `pshu`)
- `pop` (old `popu`)
- `spush` (old `pshs`)
- `spop` (old `pops`)
- `inc`/`dec`

## Utilities for programming

- `func NAME(ARG_1:SIZE, ARG_2:SIZE, ...) CODE end`: makes a function with labels referring to the arguments and allocates space for locals defined with let
- `let NAME:SIZE`: allocates memory for a local variable
- `exit`: generates the appropiate `ret` instruction, alongside the code to clean the stack if any local variable was made

https://www.maddes.net/m6809pm/sections.htm
https://www.chibiakumas.com/6809/6809Cheatsheet.pdf
https://www.assemblytutorial.com/
https://ia801601.us.archive.org/13/items/bitsavers_motorolada_3224333/6809.pdf
https://robey.lag.net/2010/01/23/tiny-monospace-font.html
