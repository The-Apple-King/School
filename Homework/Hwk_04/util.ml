
module type UtilS = sig
  val implode: char list -> string

  val explode: string -> char list

  val read_file: string -> char list

  val split_by: ('a -> bool) -> 'a list -> 'a list list

  val read_words: string -> string list
end

module UtilM : UtilS = struct

  let implode (cs: char list) : string =
    String.concat "" (List.map  (String.make 1) cs)

  let explode (s: string) : char list =
    let l = String.length s
    in
    let rec f i = 
      if i = l then [] else s.[i] :: f (i+1)
    in f 0

  let read_file (file_name: string) : char list =
    let ic = open_in file_name 
    in 
    let rec read_chars ic =
      try 
        let next_char = input_char ic
        in next_char :: read_chars ic
      with 
        _ -> [] 
    in read_chars ic

  let rec split (func: 'a -> bool) (wordlst: 'a list) (output: 'a list list) (temp: 'a list) = 
    match wordlst with
     | [] -> output
     (*final check adds last element if it is correct *)
     | x::[] -> if List.exists func wordlst then output @[temp] else output @[temp @  wordlst]
      (*checks if tests if func is true for x if it is then separate *)
     | x::rest -> if func x then split func rest (match temp with 
       | [] -> output
       |x::rest -> output @ [temp]) [] else split func rest output (temp@[x])

  let rec split_by (func: 'a -> bool) (wordlst: 'a list) : 'a list list = 
   split func wordlst [] []

  let read_words (file_name: string) : string list =
    let is_whitespace c = match c with
      | ' ' | '\t' | '\n' | '\r' -> true
      | _ -> false
    in
    List.map implode (split_by is_whitespace (read_file file_name))
end
