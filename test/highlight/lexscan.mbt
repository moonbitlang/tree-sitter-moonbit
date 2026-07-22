///|
fn scan(source : StringView) -> Unit {
  lexscan source with longest {
  // <- keyword
    re"[a-z]+" => ()
  }
}
