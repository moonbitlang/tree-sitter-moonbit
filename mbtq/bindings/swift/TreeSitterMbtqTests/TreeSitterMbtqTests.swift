import XCTest
import SwiftTreeSitter
import TreeSitterMbtq

final class TreeSitterMbtqTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_mbtq())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Mbtq grammar")
    }
}
