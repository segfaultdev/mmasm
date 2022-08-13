video:

- vga clock: 8 MHz
- framerate: 61.04 Hz
- 192 + 12 + 20 + 32 = 256 pixels per scanline
- 216 + 1 + 3 + 36 = 256 scanlines (each scanline is repeated once)
- 2 KiB of RAM for graphic data
- 2 KiB of RAM (1080 bytes used) for tilemap data
- 2 KiB of RAM (1080 bytes used) for attribute/color data
- tiles are 4x8, with a color depth of 2 bpp
- colors 0 and 3 are black and white, respectively
- color 1 can be chosen from an 8-color palette, while color 2 can be from that same palette but with a more saturated variation if specified (16 colors then)
- B1112222, where B is the blink flag, 1 is index for color 1 and 2 is the index for color 2, where the MSB indicates whether to use the light (1) or dark (0) variant

000: red / pink
001: brown / orange
010: dark yellow / yellow
011: dark green / green
100: dark cyan / cyan
101: blue / light blue
110: purple / light purple
111: dark gray / light gray

OPTION 1:
- 3x CY7C142-55PC
- leaves 100% of time for the CPU to write to memory

OPTION 2:
- use 3x regular 2 KiB RAM ICs, and only let the CPU edit it on X positions not multiple of 4 (1, 2 and 3 mod 4, but not 0) and fully while blanking
- leaves (24064 * 1.00 + 41472 * 0.75) / 65536 = 84.1797% of time for the CPU to write to memory

NEW IDEA: only 4 colors (black, blue, orange, white OR black, purple, lime, white), rearrangeable in color memory, with an 8-bit register that (when read) gives the current scanline and (when written) lets the programmer dim the 4 colors or swap between the two palettes

**ALSO: generate interrupt with ripple carry output signal of the Y counter**

use dual 74HC89s as a 16-byte memory, to store a memory map, allowing up to a 20-bit address but with 4 KiB pages


things to do:
- horizontal scrolling (two 7483s plus single 74573 for latching the X scroll, reading it will give the current scanline too!)
- page map, using two 7489s, mapped to the first page alongside two 2 KiB ROMS for characters and boot code
- 14-bit address multiplexer between video generator and CPU for the RAM, clearing the top 3 bits and setting MRDY to low whenever the video generator is accessing it
- 4-bit address multiplexer between page map, allowing CPU access when the virtual address (16-bit) is below 4096, and MMU access otherwise

breadboards:
- COUNT BOARD
- VSYNC BOARD
- LATCH + COLOR + MRDY BOARD
- VIDEO MULTIPLEXER BOARD
- RAM + FLASH BOARD
- MMU + PAGEMAP MULTIPLEXER BOARD
- CPU + ROM BOARD

virtual space:
0000 - EFFF -> pageable space
F000 - F00F -> page map (repeated for 2 KiB actually :D)
F800 - FFFF -> 2 KiB EEPROM

physical space:
00000 - 3FFFF -> up to 256 KiB of RAM
40000 - 7FFFF -> I/O space: keyboards, 76489s for audio, external hard drives, etc.
80000 - FFFFF -> built-in 512 KiB of flash storage (custom filesystem with 4 KiB pages?)

notes regarding the video address multiplexing:
- the computer only cares about the bus while E is high, so aligning MRDY to be in that low part would be nice but non-essential i think?
- 