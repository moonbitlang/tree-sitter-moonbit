import XCTest
import SwiftTreeSitter
import TreeSitterMoonbitQuotation

final class TreeSitterMoonbitQuotationTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_moonbit_quotation())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Quoted MoonBit grammar")
    }
}
