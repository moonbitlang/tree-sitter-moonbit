;; Definitions

(predicate_definition name: (lowercase_identifier) @local.definition)
(logic_function_definition name: (lowercase_identifier) @local.definition)
(lemma_definition name: (lowercase_identifier) @local.definition)

(mbtp_parameter name: (lowercase_identifier) @local.definition)
(mbtp_quantified_term binder: (lowercase_identifier) @local.definition)
(mbtp_arrow_parameter (lowercase_identifier) @local.definition)
(mbtp_parameter_decl (lowercase_identifier) @local.definition)

;; References

(mbtp_identifier_expression (mbtp_value_path (identifier) @local.reference))

;; Scopes

[
  (structure)
  (predicate_definition)
  (logic_function_definition)
  (lemma_definition)
  (mbtp_logic_block_expression)
  (lemma_block_expression)
] @local.scope
