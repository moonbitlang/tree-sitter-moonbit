; parameter

((parameters
  .
  (parameter) @parameter.inner
  .
  ","? @_end)
  (#make-range! "parameter.outer" @parameter.inner @_end))

((type_parameters
  .
  (type_identifier) @parameter.inner
  .
  ","? @_end)
  (#make-range! "parameter.outer" @parameter.inner @_end))

((trait_method_declaration
  (trait_method_parameter) @parameter.inner
  .
  ","? @_end)
  (#make-range! "parameter.outer" @parameter.inner @_end))

; argument

((apply_expression
  (argument) @parameter.inner
  .
  ","? @_end)
  (#make-range! "parameter.outer" @parameter.inner @_end))

((dot_apply_expression
  (argument) @parameter.inner
  .
  ","? @_end)
  (#make-range! "parameter.outer" @parameter.inner @_end))

((type_arguments
  (type) @parameter.inner
  .
  ","? @_end)
  (#make-range! "parameter.outer" @parameter.inner @_end))

((string_interpolation
  (interpolator (expression) @parameter.inner)
   @parameter.outer))

; block

((block_expression (_) @block.inner) @block.outer)

; function

((function_definition
  (external_source (_) @function.inner)
  .)
 @function.outer)

((function_definition
  (block_expression (_) @function.inner)
  .)
 @function.outer)

((test_definition
  (block_expression (_) @function.inner)
  .)
 @function.outer)

(trait_method_declaration) @function.outer

((impl_definition
  (block_expression (_) @function.inner)
  .)
 @function.outer)
