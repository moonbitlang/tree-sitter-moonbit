; Scopes
(source_file) @local.scope
(object) @local.scope
(argument_list) @local.scope

; Definitions
(assign_statement
  name: (identifier) @local.definition)

(import_item
  alias: (package_name) @local.definition)

; References
(identifier) @local.reference
