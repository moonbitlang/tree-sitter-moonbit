import XCTest
import SwiftTreeSitter
import TreeSitterMoonbit

final class TreeSitterMoonbitTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_moonbit())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Moonbit grammar")
    }
}
