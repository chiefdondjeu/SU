(*
	I pledge my honor that I have not cheated, 
	and will not cheat, on this assignment
	
	Florent Dondjeu Tschoufack
	Cosc 422 - Assignment 2
	Mar 1,2021
*)

fun cardinality(l1:int list, l2:bool list) = 
	foldl (fn(l,n) => if l then n+1 else n) 0 l2;

(* 
	Notice:
	for all map() declared in all locals, create a list of integer that are in the set
*)

local (* elementOf*)
	fun map(F, []:int list, []:bool list) = nil:int list
	|	map(F, x, y) = if F(hd y) then hd x::map(F,tl x,tl y) else map(F,tl x,tl y)
in
	fun elementOf(n:int,(l1:int list, l2:bool list)) = 
		foldl ( fn(l,y) => if l=n then true else y) false (map((fn u => u), l1,l2))
end;

local (* subset *)
	fun map(F, []:int list, []:bool list) = nil:int list
	|	map(F, x, y) = if F(hd y) then hd x::map(F,tl x,tl y) else map(F,tl x,tl y)
in
	fun subset((l1:int list, l2:bool list), (m1, m2)) =
		foldl( fn(l,y) => if elementOf(l,(l1,l2)) andalso elementOf(l,(m1,m2)) then true else false) false (map((fn u => u), m1,m2))
end;

local (* equals *)
	fun map(F, []:int list, []:bool list) = []:int list
	|	map(F, x, y) = if F(hd y) then hd x::map(F,tl x,tl y) else map(F,tl x,tl y)

	fun card(x1,x2, y1, y2) =	(* checks that # elements are equal *)
		if cardinality(x1,x2) = cardinality(y1,y2) then true else false
in
	fun equals((l1:int list, l2:bool list), (m1:int list, m2:bool list)) =
		foldl( fn(l,y) => if elementOf(l,(l1,l2)) andalso card(l1,l2,m1,m2) then true else false) false (map((fn u => u), m1,m2))
end;

local (* union *)
	fun map(F, []:int list, []:bool list) = []:int list
	|	map(F, x, y) = if F(hd y) then hd x::map(F,tl x,tl y) else map(F,tl x,tl y)

	(* creates a bool list *)
	fun BList(x) = foldl( fn(l,ys)=> [true]@ys) [] x
in
	fun union((l1:int list, l2:bool list), (m1, m2)) = 
		( (map((fn u => u), l1,l2))@((map((fn u => u), m1,m2))), BList( ((map((fn u => u), l1,l2))@((map((fn u => u), m1,m2))) )) )
end;

local (* intersection *)
	fun map(F, []:int list, []:bool list) = []:int list
	|	map(F, x, y) = if F(hd y) then hd x::map(F,tl x,tl y) else map(F,tl x,tl y)

	(* create a intersect list of type int*)
	fun inter((l1:int list, l2:bool list), (m1, m2)) =
		foldl(fn(l,xs)=> if elementOf(l,(m1,m2)) then l::xs else xs) [] (map((fn u => u), l1,l2))

	(* creates a bool list *)
	fun BList(x) = foldl( fn(l,ys)=> [true]@ys) [] x
in
	fun intersection((l1:int list, l2:bool list), (m1, m2)) =
		( inter((l1,l2),(m1,m2)) , BList( (inter((l1,l2),(m1,m2)) )) )
end;

local (* complement *)
	fun map(F,[]:bool list) = []:bool list (* F negates bool variable *)
	|	map(F, x::xs) = F(x)::map(F,xs)
in
	fun complement(l1:int list, l2:bool list) = (l1, (map((fn x=> not x),l2)) )
end;

local (* cartesian *)
	fun map(F, []:int list, []:bool list) = []:int list
	|	map(F, x, y) = if F(hd y) then hd x::map(F,tl x,tl y) else map(F,tl x,tl y)

	fun pair(F, a, []:int list) = []
	|	pair(F, a,x) = F(a,hd x)::pair(F,a, tl x)

	(* creates a list of int pairs *)
	fun cart(j,k) = foldr(fn(l,ls)=> pair((fn(a,b) => (a,b)),l,k)@ls ) [] j
	
	(* creates a bool list *)
	fun BList(x) = foldl( fn(l,ys)=> [true]@ys) [] x
in
	fun cartesian((l1:int list, l2:bool list), (m1, m2)) = 
		( cart( (map((fn u => u), l1,l2)), (map((fn u => u), m1,m2)) ), BList( (cart( (map((fn u => u), l1,l2)), (map((fn u => u), m1,m2)) )) ) )
end
