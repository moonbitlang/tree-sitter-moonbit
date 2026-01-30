; Assignment definitions
(assign_statement
  name: (identifier) @name) @definition.variable

; Apply statements (function-like)
(apply_statement
  name: (identifier) @name) @definition.function

; Import items
(import_item
  path: (string) @name
  alias: (package_name)? @name) @reference.module
