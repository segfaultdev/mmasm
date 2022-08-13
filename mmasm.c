#include <stdlib.h>
#include <mmasm.h>
#include <stdio.h>

int mm_type(const char *word) {
  
}

mm_input_t mm_load(const char *path) {
  
}

mm_word_t mm_peek(mm_input_t *input) {
  if (input->offset >= input->count) return (mm_word_t){.type = mm_word_eof};
  return input->words[input->offset];
}

mm_word_t mm_take(mm_input_t *input) {
  if (input->offset >= input->count) return (mm_word_t){.type = mm_word_eof};
  return input->words[input->offset++];
}

int mm_expect(mm_input_t *input, int type, mm_word_t *save) {
  mm_word_t word = mm_peek(input);
  
  if (word.type == type) {
    if (word.type != mm_word_eof) input->offset++;
    if (save) *save = word;
    
    return 1;
  }
  
  return 0;
}

void mm_parse(mm_input_t *input, mm_output_t *output) {
  mm_label_t *locals = NULL;
  int local_count = 0, local_size = 0;
  
  while (!mm_expect(input, mm_word_eof, NULL)) {
    
  }
}
