((comment)* @doc
 .
 (predicate_definition
  name: (lowercase_identifier) @name
 ) @definition.function
 (#strip! @doc "^//[/]?\\s*")
 (#set-adjacent! @doc @definition.function))

((comment)* @doc
 .
 (logic_function_definition
  name: (lowercase_identifier) @name
 ) @definition.function
 (#strip! @doc "^//[/]?\\s*")
 (#set-adjacent! @doc @definition.function))

((comment)* @doc
 .
 (lemma_definition
  name: (lowercase_identifier) @name
 ) @definition.function
 (#strip! @doc "^//[/]?\\s*")
 (#set-adjacent! @doc @definition.function))

(mbtp_identifier_expression (mbtp_value_path (identifier) @name)) @reference.call
