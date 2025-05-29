package tree_sitter_mbtq_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_mbtq "github.com/moonbitlang/tree-sitter-moonbit/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_mbtq.Language())
	if language == nil {
		t.Errorf("Error loading Mbtq grammar")
	}
}
