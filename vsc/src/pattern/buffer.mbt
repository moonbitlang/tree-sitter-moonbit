///|
priv struct Buffer {
  buffer : StringBuilder
  mut length : Int
}

///|
fn Buffer::new() -> Buffer {
  Buffer::{ buffer: StringBuilder::new(), length: 0 }
}

///|
fn Buffer::write_char(self : Buffer, char : Char) -> Unit {
  self.buffer.write_char(char)
  self.length += 1
}

///|
fn Buffer::write_string(self : Buffer, str : String) -> Unit {
  self.buffer.write_string(str)
  self.length += str.length()
}

///|
fn Buffer::to_string(self : Buffer) -> String {
  self.buffer.to_string()
}

///|
fn Buffer::length(self : Buffer) -> Int {
  self.length
}
