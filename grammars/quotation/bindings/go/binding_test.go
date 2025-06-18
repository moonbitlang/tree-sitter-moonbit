package tree_sitter_moonbit_quotation_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_moonbit_quotation "github.com/moonbitlang/tree-sitter-moonbit/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_moonbit_quotation.Language())
	if language == nil {
		t.Errorf("Error loading Quoted MoonBit grammar")
	}
}
