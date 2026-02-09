package tree_sitter_moonbit

// #cgo CFLAGS: -std=c11 -fPIC
// #include "../../src/parser.c"
// #if __has_include("../../src/scanner.c")
// #include "../../src/scanner.c"
// #endif
// #include "../../grammars/interface/src/parser.c"
// #include "../../grammars/package/src/parser.c"
import "C"

import "unsafe"

// Get the tree-sitter Language for this grammar.
func Language() unsafe.Pointer {
	return unsafe.Pointer(C.tree_sitter_moonbit())
}

// Get the tree-sitter Language for the MoonBit interface grammar.
func LanguageInterface() unsafe.Pointer {
	return unsafe.Pointer(C.tree_sitter_moonbit_interface())
}

// Get the tree-sitter Language for the MoonBit package grammar.
func LanguagePackage() unsafe.Pointer {
	return unsafe.Pointer(C.tree_sitter_moonbit_package())
}
