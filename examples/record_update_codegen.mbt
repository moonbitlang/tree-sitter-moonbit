struct poly_r[T, K, L] {
  pr1:T
  pr2:K
  pr3:L
}

struct r {
  r1:Int
  r2:Bool
  r3:Float64
}

struct nested_r {
  nr1:Int
  nr2:r
}

func update_poly_r_snd_check[T, K, L] (pr: poly_r[T, K, L], pr2: K) ->
     poly_r[T, K, L] {
  let ret : poly_r[T, K, L] = {..pr, pr2, }
  ret
}

func update_poly_r_snd_infer[T, K, L] (pr: poly_r[T, K, L], pr2: K) ->
     poly_r[T, K, L] {
  {..pr, pr2, }
}

let test:(Bool) -> Unit = fn(b) {
  if b { print("ok\n") } else { print("not ok\n") }
}

let side_eff : Ref[Int] = { val: 0 }
func make() -> r {
  side_eff.val = side_eff.val + 1
  { r1:114514, r2:false, r3:19.19 }
}

func init {
  let ra = { r1:893, r2:false, r3:46.49 }
  let rb_infer = {..ra, r1:894, }
  let rb_check : r = {..rb_infer, r1:895, }
  let nr = { nr1:16, nr2:{..rb_check, r2:true, } }
  let nr_check : nested_r = { nr1:16, nr2:{..rb_check, r2:true, } }
  let rx = {..make(), r1:999, }
  let ry = {..nr_check.nr2, r1:666, }
  test(side_eff.val == 1)
  test(rb_infer.r1 == 894)
  test(rb_check.r1 == 895)
  test(nr.nr2.r2)
  test(nr_check.nr2.r1 == 895)
}

