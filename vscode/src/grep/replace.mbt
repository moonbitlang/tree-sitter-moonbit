///|
priv enum Replace {
  Quote(String)
  Subst(String)
}

///|
type! ReplaceError {
  VariableNotFound(String)
  MismatchedType(expect~ : String, actual~ : String)
} derive(Show, ToJson)

///|
fn Replace::parse_identifier(
  source : @string.View,
  buffer : StringBuilder
) -> @string.View {
  loop source {
    ['a'..='z' | 'A'..='Z' | '_' | '0'..='9' as char, .. source] => {
      buffer.write_char(char)
      continue source
    }
    source => return source
  }
}

///|
fn Replace::parse_replaces(
  source : @string.View,
  replaces : Array[Replace]
) -> Unit {
  let buffer = StringBuilder::new()
  loop source {
    ['$', .. source] => {
      if not(buffer.is_empty()) {
        replaces.push(Replace::Quote(buffer.to_string()))
        buffer.reset()
      }
      let identifier = StringBuilder::new()
      let source = Replace::parse_identifier(source, identifier)
      replaces.push(Replace::Subst(identifier.to_string()))
      continue source
    }
    ['\\', '$', .. source] => {
      buffer.write_char('$')
      continue source
    }
    [char, .. source] => {
      buffer.write_char(char)
      continue source
    }
    [] => {
      if not(buffer.is_empty()) {
        replaces.push(Replace::Quote(buffer.to_string()))
        buffer.reset()
      }
      return
    }
  }
}

///|
fn Replace::parse(string : @string.View) -> Array[Replace] {
  let replaces = []
  Replace::parse_replaces(string, replaces)
  return replaces
}

///|
fn replace(
  captures : Map[@string.View, Array[Text]],
  replace : @string.View
) -> @string.View!ReplaceError {
  let replaces = Replace::parse(replace)
  let replaced = StringBuilder::new()
  for replace in replaces {
    match replace {
      Quote(string) => replaced.write_string(string)
      Subst(name) =>
        match captures.get(name) {
          None => raise VariableNotFound(name)
          Some([text]) =>
            for char in text.text {
              replaced.write_char(char)
            }
          Some(_) =>
            raise MismatchedType(expect="single node", actual="multiple nodes")
        }
    }
  }
  replaced.to_string()
}

///|
priv struct Text {
  range : @tree_sitter.Range
  text : @string.View
}

///|
impl ToJson for Text with to_json(self : Text) -> Json {
  {
    "range": {
      "start": {
        "row": self.range.start_point().row().to_json(),
        "column": self.range.start_point().column().to_json(),
        "byte": self.range.start_byte().to_json(),
      },
      "end": {
        "row": self.range.end_point().row().to_json(),
        "column": self.range.end_point().column().to_json(),
        "byte": self.range.end_byte().to_json(),
      },
    },
    "text": self.text.to_json(),
  }
}

///|
impl @json.FromJson for Text with from_json(
  self : Json,
  path : @json.JsonPath
) -> Text!@json.JsonDecodeError {
  match self {
    {
      "range": {
        "start": {
          "row": Number(start_row),
          "column": Number(start_column),
          "byte": Number(start_byte),
          ..
        },
        "end": {
          "row": Number(end_row),
          "column": Number(end_column),
          "byte": Number(end_byte),
          ..
        },
        ..
      },
      "text": String(text),
      ..
    } =>
      Text::{
        range: @tree_sitter.Range::new(
          @tree_sitter.Point::new(start_row.to_int(), start_column.to_int()),
          @tree_sitter.Point::new(end_row.to_int(), end_column.to_int()),
          start_byte.to_int(),
          end_byte.to_int(),
        ),
        text,
      }
    _ => raise @json.JsonDecodeError((path, "Invalid text"))
  }
}
