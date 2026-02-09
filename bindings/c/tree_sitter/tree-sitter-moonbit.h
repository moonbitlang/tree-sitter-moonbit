#ifndef TREE_SITTER_MOONBIT_H_
#define TREE_SITTER_MOONBIT_H_

typedef struct TSLanguage TSLanguage;

#ifdef __cplusplus
extern "C" {
#endif

const TSLanguage *tree_sitter_moonbit(void);
const TSLanguage *tree_sitter_moonbit_interface(void);
const TSLanguage *tree_sitter_moonbit_package(void);

#ifdef __cplusplus
}
#endif

#endif // TREE_SITTER_MOONBIT_H_
