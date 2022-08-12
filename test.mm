func memcpy(dest:2, src:2, size:2)
  mov d, [dest]
  mov x, d
  mov d, [src]
  mov y, d
  clr a
.loop:
  mov b, [y+]
  mov [x+], b
  clr b
  dec [size, 1]
  sbb [size], b
  cmp [size], d
  jnz .loop
  exit
end
