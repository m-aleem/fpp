state machine M {
  action a: F32
  signal s1: F32
  signal s2: F64
  guard g
  initial enter S
  state S {
    initial enter T
    choice C { if g do { a } enter T else enter T }
    on s1 enter C
    on s2 enter C
    state T
  }
}
