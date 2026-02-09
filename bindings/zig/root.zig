const testing = @import("std").testing;

const ts = @import("tree-sitter");
const Language = ts.Language;
const Parser = ts.Parser;

pub extern fn tree_sitter_moonbit() callconv(.C) *const Language;
pub extern fn tree_sitter_moonbit_interface() callconv(.C) *const Language;
pub extern fn tree_sitter_moonbit_package() callconv(.C) *const Language;

pub export fn language() *const Language {
    return tree_sitter_moonbit();
}

pub export fn language_interface() *const Language {
    return tree_sitter_moonbit_interface();
}

pub export fn language_package() *const Language {
    return tree_sitter_moonbit_package();
}

test "can load grammar" {
    const parser = Parser.create();
    defer parser.destroy();
    try testing.expectEqual(parser.setLanguage(language()), void{});
    try testing.expectEqual(parser.getLanguage(), tree_sitter_moonbit());
}

test "can load interface grammar" {
    const parser = Parser.create();
    defer parser.destroy();
    try testing.expectEqual(parser.setLanguage(language_interface()), void{});
    try testing.expectEqual(parser.getLanguage(), tree_sitter_moonbit_interface());
}

test "can load package grammar" {
    const parser = Parser.create();
    defer parser.destroy();
    try testing.expectEqual(parser.setLanguage(language_package()), void{});
    try testing.expectEqual(parser.getLanguage(), tree_sitter_moonbit_package());
}
