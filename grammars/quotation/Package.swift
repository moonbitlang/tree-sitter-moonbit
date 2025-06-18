// swift-tools-version:5.3

import Foundation
import PackageDescription

var sources = ["src/parser.c"]
if FileManager.default.fileExists(atPath: "src/scanner.c") {
    sources.append("src/scanner.c")
}

let package = Package(
    name: "TreeSitterMoonbitQuotation",
    products: [
        .library(name: "TreeSitterMoonbitQuotation", targets: ["TreeSitterMoonbitQuotation"]),
    ],
    dependencies: [
        .package(url: "https://github.com/tree-sitter/swift-tree-sitter", from: "0.8.0"),
    ],
    targets: [
        .target(
            name: "TreeSitterMoonbitQuotation",
            dependencies: [],
            path: ".",
            sources: sources,
            resources: [
                .copy("queries")
            ],
            publicHeadersPath: "bindings/swift",
            cSettings: [.headerSearchPath("src")]
        ),
        .testTarget(
            name: "TreeSitterMoonbitQuotationTests",
            dependencies: [
                "SwiftTreeSitter",
                "TreeSitterMoonbitQuotation",
            ],
            path: "bindings/swift/TreeSitterMoonbitQuotationTests"
        )
    ],
    cLanguageStandard: .c11
)
