fn main() {
    let src_dir = std::path::Path::new("src");

    let mut c_config = cc::Build::new();
    c_config.std("c11").include(src_dir);

    #[cfg(target_env = "msvc")]
    c_config.flag("-utf-8");

    let parser_path = src_dir.join("parser.c");
    c_config.file(&parser_path);
    println!("cargo:rerun-if-changed={}", parser_path.to_str().unwrap());

    let scanner_path = src_dir.join("scanner.c");
    if scanner_path.exists() {
        c_config.file(&scanner_path);
        println!("cargo:rerun-if-changed={}", scanner_path.to_str().unwrap());
    }

    // Interface grammar
    let interface_src_dir = std::path::Path::new("grammars/interface/src");
    c_config.include(interface_src_dir);
    let interface_parser_path = interface_src_dir.join("parser.c");
    if interface_parser_path.exists() {
        c_config.file(&interface_parser_path);
        println!(
            "cargo:rerun-if-changed={}",
            interface_parser_path.to_str().unwrap()
        );
    }

    // Package grammar
    let package_src_dir = std::path::Path::new("grammars/package/src");
    c_config.include(package_src_dir);
    let package_parser_path = package_src_dir.join("parser.c");
    if package_parser_path.exists() {
        c_config.file(&package_parser_path);
        println!(
            "cargo:rerun-if-changed={}",
            package_parser_path.to_str().unwrap()
        );
    }

    c_config.compile("tree-sitter-moonbit");
}
