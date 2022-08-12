#ifndef __MMASM_H__
#define __MMASH_H__

#include <stdint.h>

typedef struct mm_word_t mm_word_t;
typedef struct mm_input_t mm_input_t;

typedef struct mm_label_t mm_label_t;
typedef struct mm_empty_t mm_empty_t;
typedef struct mm_output_t mm_output_t;

enum {
  mm_word_null,
  mm_word_eof,
  
  mm_word_func,
  mm_word_end,
  
  mm_word_colon,
  mm_word_left_paren,
  mm_word_right_paren,
  mm_word_left_bracket,
  mm_word_right_bracket,
  
  mm_word_plus,
  mm_word_minus,
  
  mm_word_register,
  mm_word_number,
  mm_word_name,
};

struct mm_word_t {
  int type;
  
  union {
    int register_value;
    int32_t number_value;
    char name_value[32];
  };
};

struct mm_input_t {
  mm_word_t *words;
  int count, offset;
};

struct mm_label_t {
  char name[32];
  uint16_t addr;
};

struct mm_empty_t {
  int offset, size; // offset in tokens, size can be either 1 or 2
  uint16_t addr;
};

struct mm_output_t {
  uint8_t *data;
  int size;
  
  mm_label_t *labels;
  int label_count;
  
  mm_empty_t *empties;
  int empty_count;
};

int        mm_type(const char *word);
mm_input_t mm_load(const char *path);
mm_word_t  mm_peek(mm_input_t *input);
mm_word_t  mm_take(mm_input_t *input);
int        mm_expect(mm_input_t *input, int type, mm_word_t *save);

void mm_parse(mm_input_t *input, mm_output_t *output);

// stage 0: generate proper code, creating labels and references as found, and filling with 0 all references
// stage 1: go back to all references, parsing simple expressions and replacing the 0s with the results

#endif
