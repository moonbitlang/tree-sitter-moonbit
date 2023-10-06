func test(x: Int64, y: Int64) {
  if (x == y) { print(".") } else { print("x") }
}

func test_and(x: Int64, y: Int64, z: Int64) {
  if (x.land(y) == z) { print(".") } else { print("x") }
}

func test_or(x: Int64, y: Int64, z: Int64) {
  if (x.lor(y) == z) { print(".") } else { print("x") }
}

func test_xor(x: Int64, y: Int64, z: Int64) {
  if (x.lxor(y) == z) { print(".") } else { print("x") }
}

func test_lsl(x: Int64, y: Int64, z: Int64) {
  if (x.lsl(y) == z) { print(".") } else { print("x") }
}

func test_lsr(x: Int64, y: Int64, z: Int64) {
  if (x.lsr(y) == z) { print(".") } else { print("x") }
}

func test_asr(x: Int64, y: Int64, z: Int64) {
  if (x.asr(y) == z) { print(".") } else { print("x") }
}

func test_clz(x: Int64, y: Int64) {
  if (x.clz() == y) { print(".") } else { print("x") }
}

func test_ctz(x: Int64, y: Int64) {
  if (x.ctz() == y) { print(".") } else { print("x") }
}

func test_popcnt(x: Int64, y: Int64) {
  if (x.popcnt() == y) { print(".") } else { print("x") }
}

func test_i32_clz(x: Int, y: Int) {
  if (x.clz() == y) { print(".") } else { print("x") }
}

func test_i32_ctz(x: Int, y: Int) {
  if (x.ctz() == y) { print(".") } else { print("x") }
}

func test_i32_popcnt(x: Int, y: Int) {
  if (x.popcnt() == y) { print(".") } else { print("x") }
}



func init {
  test_and(1L, 0L, 0L)
  test_and(0L, 1L, 0L)
  test_and(1L, 1L, 1L)
  test_and(0L, 0L, 0L)
  test_and(0x7fffffffffffffffL, 0x8000000000000000L, 0L)
  test_and(0x7fffffffffffffffL, -1L, 0x7fffffffffffffffL)
  test_and(0xf0f0ffffL, 0xfffff0f0L, 0xf0f0f0f0L)
  test_and(0xffffffffffffffffL, 0xffffffffffffffffL, 0xffffffffffffffffL)

  test(1L.land( 0L), 0L)
  test(0L.land( 1L), 0L)
  test(1L.land( 1L), 1L)
  test(0L.land( 0L), 0L)
  test(0x7fffffffffffffffL.land( 0x8000000000000000L), 0L)
  test(0x7fffffffffffffffL.land( -1L), 0x7fffffffffffffffL)
  test(0xf0f0ffffL.land( 0xfffff0f0L), 0xf0f0f0f0L)
  test(0xffffffffffffffffL.land( 0xffffffffffffffffL), 0xffffffffffffffffL)

  test_or(1L, 0L, 1L)
  test_or(0L, 1L, 1L)
  test_or(1L, 1L, 1L)
  test_or(0L, 0L, 0L)
  test_or(0x7fffffffffffffffL, 0x8000000000000000L, -1L)
  test_or(0x8000000000000000L, 0L, 0x8000000000000000L)
  test_or(0xf0f0ffffL, 0xfffff0f0L, 0xffffffffL)
  test_or(0xffffffffffffffffL, 0xffffffffffffffffL, 0xffffffffffffffffL)

  test(1L.lor( 0L), 1L)
  test(0L.lor( 1L), 1L)
  test(1L.lor( 1L), 1L)
  test(0L.lor( 0L), 0L)
  test(0x7fffffffffffffffL.lor( 0x8000000000000000L), -1L)
  test(0x8000000000000000L.lor( 0L), 0x8000000000000000L)
  test(0xf0f0ffffL.lor( 0xfffff0f0L), 0xffffffffL)
  test(0xffffffffffffffffL.lor( 0xffffffffffffffffL), 0xffffffffffffffffL)

  test_xor(1L, 0L, 1L)
  test_xor(0L, 1L, 1L)
  test_xor(1L, 1L, 0L)
  test_xor(0L, 0L, 0L)
  test_xor(0x7fffffffffffffffL, 0x8000000000000000L, -1L)
  test_xor(0x8000000000000000L, 0L, 0x8000000000000000L)
  test_xor(-1L, 0x8000000000000000L, 0x7fffffffffffffffL)
  test_xor(-1L, 0x7fffffffffffffffL, 0x8000000000000000L)
  test_xor(0xf0f0ffffL, 0xfffff0f0L, 0x0f0f0f0fL)
  test_xor(0xffffffffffffffffL, 0xffffffffffffffffL, 0L)

  test(1L.lxor( 0L), 1L)
  test(0L.lxor( 1L), 1L)
  test(1L.lxor( 1L), 0L)
  test(0L.lxor( 0L), 0L)
  test(0x7fffffffffffffffL.lxor( 0x8000000000000000L), -1L)
  test(0x8000000000000000L.lxor( 0L), 0x8000000000000000L)
  test((-1L).lxor( 0x8000000000000000L), 0x7fffffffffffffffL)
  test((-1L).lxor( 0x7fffffffffffffffL), 0x8000000000000000L)
  test(0xf0f0ffffL.lxor( 0xfffff0f0L), 0x0f0f0f0fL)
  test(0xffffffffffffffffL.lxor( 0xffffffffffffffffL), 0L)

  test_lsl( 1L, 1L, 2L)
  test_lsl( 1L, 0L, 1L)
  test_lsl( 0x7fffffffffffffffL, 1L, 0xfffffffffffffffeL)
  test_lsl( 0xffffffffffffffffL, 1L, 0xfffffffffffffffeL)
  test_lsl( 0x8000000000000000L, 1L, 0L)
  test_lsl( 0x4000000000000000L, 1L, 0x8000000000000000L)
  test_lsl( 1L, 63L, 0x8000000000000000L)
  test_lsl( 1L, 64L, 1L)
  test_lsl( 1L, 65L, 2L)
  test_lsl( 1L, -1L, 0x8000000000000000L)
  test_lsl( 1L, 0x7fffffffffffffffL, 0x8000000000000000L)

  test( 1L.lsl( 1L), 2L)
  test( 1L.lsl( 0L), 1L)
  test( 0x7fffffffffffffffL.lsl( 1L), 0xfffffffffffffffeL)
  test( 0xffffffffffffffffL.lsl( 1L), 0xfffffffffffffffeL)
  test( 0x8000000000000000L.lsl( 1L), 0L)
  test( 0x4000000000000000L.lsl( 1L), 0x8000000000000000L)
  test( 1L.lsl( 63L), 0x8000000000000000L)
  test( 1L.lsl( 64L), 1L)
  test( 1L.lsl( 65L), 2L)
  test( 1L.lsl( -1L), 0x8000000000000000L)
  test( 1L.lsl( 0x7fffffffffffffffL), 0x8000000000000000L)

  test_asr( 1L, 1L, 0L)
  test_asr( 1L, 0L, 1L)
  test_asr( -1L, 1L, -1L)
  test_asr( 0x7fffffffffffffffL, 1L, 0x3fffffffffffffffL)
  test_asr( 0x8000000000000000L, 1L, 0xc000000000000000L)
  test_asr( 0x4000000000000000L, 1L, 0x2000000000000000L)
  test_asr( 1L, 64L, 1L)
  test_asr( 1L, 65L, 0L)
  test_asr( 1L, -1L, 0L)
  test_asr( 1L, 0x7fffffffffffffffL, 0L)
  test_asr( 1L, 0x8000000000000000L, 1L)
  test_asr( 0x8000000000000000L, 63L, -1L)
  test_asr( -1L, 64L, -1L)
  test_asr( -1L, 65L, -1L)
  test_asr( -1L, -1L, -1L)
  test_asr( -1L, 0x7fffffffffffffffL, -1L)
  test_asr( -1L, 0x8000000000000000L, -1L)

  test( 1L.asr( 1L), 0L)
  test( 1L.asr( 0L), 1L)
  test( (-1L).asr( 1L), -1L)
  test( 0x7fffffffffffffffL.asr( 1L), 0x3fffffffffffffffL)
  test( 0x8000000000000000L.asr( 1L), 0xc000000000000000L)
  test( 0x4000000000000000L.asr( 1L), 0x2000000000000000L)
  test( 1L.asr( 64L), 1L)
  test( 1L.asr( 65L), 0L)
  test( 1L.asr (-1L), 0L)
  test( 1L.asr( 0x7fffffffffffffffL), 0L)
  test( 1L.asr( 0x8000000000000000L), 1L)
  test( 0x8000000000000000L.asr( 63L), -1L)
  test( (-1L).asr( 64L), -1L)
  test( (-1L).asr( 65L), -1L)
  test( (-1L).asr( -1L), -1L)
  test( (-1L).asr( 0x7fffffffffffffffL), -1L)
  test( (-1L).asr( 0x8000000000000000L), -1L)

  test_lsr( 1L, 1L, 0L)
  test_lsr( 1L, 0L, 1L)
  test_lsr( -1L, 1L, 0x7fffffffffffffffL)
  test_lsr( 0x7fffffffffffffffL, 1L, 0x3fffffffffffffffL)
  test_lsr( 0x8000000000000000L, 1L, 0x4000000000000000L)
  test_lsr( 0x4000000000000000L, 1L, 0x2000000000000000L)
  test_lsr( 1L, 64L, 1L)
  test_lsr( 1L, 65L, 0L)
  test_lsr( 1L, -1L, 0L)
  test_lsr( 1L, 0x7fffffffffffffffL, 0L)
  test_lsr( 1L, 0x8000000000000000L, 1L)
  test_lsr( 0x8000000000000000L, 63L, 1L)
  test_lsr( -1L, 64L, -1L)
  test_lsr( -1L, 65L, 0x7fffffffffffffffL)
  test_lsr( -1L, -1L, 1L)
  test_lsr( -1L, 0x7fffffffffffffffL, 1L)
  test_lsr( -1L, 0x8000000000000000L, -1L)

  test( 1L.lsr( 1L), 0L)
  test( 1L.lsr( 0L), 1L)
  test( (-1L).lsr( 1L), 0x7fffffffffffffffL)
  test( 0x7fffffffffffffffL.lsr( 1L), 0x3fffffffffffffffL)
  test( 0x8000000000000000L.lsr( 1L), 0x4000000000000000L)
  test( 0x4000000000000000L.lsr( 1L), 0x2000000000000000L)
  test( 1L.lsr( 64L), 1L)
  test( 1L.lsr( 65L), 0L)
  test( 1L.lsr( -1L), 0L)
  test( 1L.lsr( 0x7fffffffffffffffL), 0L)
  test( 1L.lsr( 0x8000000000000000L), 1L)
  test( 0x8000000000000000L.lsr( 63L), 1L)
  test( (-1L).lsr( 64L), -1L)
  test( (-1L).lsr( 65L), 0x7fffffffffffffffL)
  test( (-1L).lsr( -1L), 1L)
  test( (-1L).lsr( 0x7fffffffffffffffL), 1L)
  test( (-1L).lsr( 0x8000000000000000L), -1L)

  test_clz ( 0xffffffffffffffffL, 0L)
  test_clz ( 0L, 64L)
  test_clz ( 0x00008000L, 48L)
  test_clz ( 0xffL, 56L)
  test_clz ( 0x8000000000000000L, 0L)
  test_clz ( 1L, 63L)
  test_clz ( 2L, 62L)
  test_clz ( 0x7fffffffffffffffL, 1L)

  test_ctz ( -1L, 0L)
  test_ctz ( 0L, 64L)
  test_ctz ( 0x00008000L, 15L)
  test_ctz ( 0x00010000L, 16L)
  test_ctz ( 0x8000000000000000L, 63L)
  test_ctz ( 0x7fffffffffffffffL, 0L)

  test_popcnt ( -1L, 64L)
  test_popcnt ( 0L, 0L)
  test_popcnt ( 0x00008000L, 1L)
  test_popcnt ( 0x8000800080008000L, 4L)
  test_popcnt ( 0x7fffffffffffffffL, 63L)
  test_popcnt ( 0xAAAAAAAA55555555L, 32L)
  test_popcnt ( 0x99999999AAAAAAAAL, 32L)
  test_popcnt ( 0xDEADBEEFDEADBEEFL, 48L)

  test_i32_clz ( 0xffffffff, 0)
  test_i32_clz ( 0, 32)
  test_i32_clz ( 0x00008000, 16)
  test_i32_clz ( 0xff, 24)
  test_i32_clz ( 0x80000000, 0)
  test_i32_clz ( 1, 31)
  test_i32_clz ( 2, 30)
  test_i32_clz ( 0x7fffffff, 1)

  test_i32_ctz ( -1, 0)
  test_i32_ctz ( 0, 32)
  test_i32_ctz ( 0x00008000, 15)
  test_i32_ctz ( 0x00010000, 16)
  test_i32_ctz ( 0x80000000, 31)
  test_i32_ctz ( 0x7fffffff, 0)

  test_i32_popcnt ( -1, 32)
  test_i32_popcnt ( 0, 0)
  test_i32_popcnt ( 0x00008000, 1)
  test_i32_popcnt ( 0x80008000, 2)
  test_i32_popcnt ( 0x7fffffff, 31)
  test_i32_popcnt ( 0xAAAAAAAA, 16)
  test_i32_popcnt ( 0x55555555, 16)
  test_i32_popcnt ( 0xDEADBEEF, 24)


}
