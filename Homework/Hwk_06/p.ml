type'a tree = Tip of 'a
      | Split of 'a tree * 'a tree * 'a tree

let rec repaddmin tree =

      let rec ram tree ogtree =
  
      match tree with
  
          | Tip(x) -> Tip(x + min ogtree)
  
          | Split(a,b,c) -> Split(ram a ogtree) (ram b ogtree) (ram c ogtree) in
  
  match tree with
  | Tip(x) -> Tip(x+ min tree)
  | Split(a,b,c) -> Split(ram a tree) (ram b tree) (ram c tree)